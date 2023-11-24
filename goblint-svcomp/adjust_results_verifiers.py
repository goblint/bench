#!/usr/bin/env python3

# This file is part of BenchExec, a framework for reliable benchmarking:
# https://github.com/sosy-lab/benchexec
#
# SPDX-FileCopyrightText: 2007-2020 Dirk Beyer <https://www.sosy-lab.org>
#
# SPDX-License-Identifier: Apache-2.0

import sys

import argparse
from decimal import Decimal, InvalidOperation
import os
import io
from xml.etree import ElementTree
import bz2

from benchexec import result
from benchexec import tablegenerator
from benchexec.util import print_decimal

sys.dont_write_bytecode = True  # prevent creation of .pyc files


def parse_args(argv):
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "resultsXML",
        metavar="results-xml",
        help="XML-file containing the verification results.",
    )
    parser.add_argument(
        "validatorLinterXML",
        nargs="*",
        metavar="validator-linter-xml",
        help="Any number of XML-files containing validator or linter results.",
    )
    parser.add_argument(
        "--no-overwrite-status-true",
        action="store_true",
        help="Do not overwrite true results with results from validation.",
    )
    parser.add_argument(
        "-o",
        "--outputpath",
        metavar="OUT_PATH",
        help="Directory in which the generated output files will be placed.",
    )
    return parser.parse_args(argv)


def xml_to_string(elem, qualified_name=None, public_id=None, system_id=None):
    """
    Return a pretty-printed XML string for the Element.
    Also allows setting a document type.
    """
    from xml.dom import minidom

    rough_string = ElementTree.tostring(elem, "utf-8")
    reparsed = minidom.parseString(rough_string)
    if qualified_name is not None:
        doctype = minidom.DOMImplementation().createDocumentType(
            qualified_name, public_id, system_id
        )
        reparsed.insertBefore(doctype, reparsed.documentElement)
    return reparsed.toprettyxml(indent="  ")


def get_runs(validator_linter_xml):
    runs = {}
    for run in validator_linter_xml.findall("run"):
        name = run.get("name")
        runs[name] = run
    return runs


def get_validator_linter_result(validator_linter_run, verification_run):
    if validator_linter_run is None:
        # If there is no run result, then this is an error of the verifier.
        return "validation run missing", result.CATEGORY_ERROR

    status_from_validation = validator_linter_run.find('column[@title="status"]').get(
        "value"
    )
    try:
        status_from_verification = verification_run.find('column[@title="status"]').get(
            "value"
        )
        category_from_verification = verification_run.find(
            'column[@title="category"]'
        ).get("value")
    except AttributeError:
        status_from_verification = "not found"
        category_from_verification = "not found"

    # If the result from witness validation matches the result from verification,
    # then leave status and category as is.
    if status_from_validation == status_from_verification:
        return status_from_verification, category_from_verification
    # The following three errors are reported by witness linter.
    # 1) An invalid witness counts as error of the verifier.
    if status_from_validation == "ERROR (invalid witness syntax)":
        return (
            f"witness invalid ({status_from_verification})",
            result.CATEGORY_ERROR,
        )
    # 2) A missing witness counts as error of the verifier.
    if status_from_validation == "ERROR (witness does not exist)":
        return (
            f"witness missing ({status_from_verification})",
            result.CATEGORY_ERROR,
        )
    # 3) A mismatch of the witness type counts as error of the verifier.
    if status_from_validation == "ERROR (unexpected witness type)":
        return (
            f"witness-type mismatch ({status_from_verification})",
            result.CATEGORY_ERROR,
        )
    # 4) A mismatch of the witness version counts as error of the verifier.
    if status_from_validation == "ERROR (unexpected witness version)":
        return (
            f"witness-version mismatch ({status_from_verification})",
            result.CATEGORY_ERROR,
        )

    # Other unconfirmed results count as CATEGORY_CORRECT_UNCONFIRMED.
    if category_from_verification == result.CATEGORY_CORRECT:
        return status_from_verification, result.CATEGORY_CORRECT_UNCONFIRMED

    # Anything else counts as invalid.
    return f"result invalid ({status_from_verification})", result.CATEGORY_ERROR


def get_validation_result(
    verification_run,
    validator_sets,
    linter_sets,
    status_from_verification,
    category_from_verification,
):
    status_wit, category_wit = None, None
    name = verification_run.get("name")

    # For verification only, not for test-case generation
    for linter_set in linter_sets:
        linter_run = linter_set.get(name)
        if linter_run is None:
            continue
        status_wit_new, category_wit_new = get_validator_linter_result(
            linter_run, verification_run
        )
        # Previous linter has found the witness to be good, so we do not change the verdict.
        if category_wit is not None and category_wit != result.CATEGORY_ERROR:
            continue
        status_wit, category_wit = (status_wit_new, category_wit_new)

    # If there is at least one witness linter, and all witness linters report an error on the witness,
    # then the result of the verifier must not be counted.
    if category_wit == result.CATEGORY_ERROR:
        return (
            status_wit,
            category_wit,
            status_from_verification,
            category_from_verification,
        )

    for validator_set in validator_sets:
        validation_run = validator_set.get(name)
        if validation_run is None:
            continue
        # copy data from validator or linter run
        if verification_run.get("properties") == "coverage-error-call":
            status_from_validation = validation_run.find('column[@title="status"]').get(
                "value"
            )
            if status_from_validation == "true":
                status_wit, category_wit = (
                    status_from_verification,
                    result.CATEGORY_CORRECT,
                )
                category_from_verification = result.CATEGORY_CORRECT
                score_column = ElementTree.Element("column", title="score", value="1")
                verification_run.append(score_column)
        elif verification_run.get("properties") == "coverage-branches":
            try:
                coverage_value = (
                    validation_run.find('column[@title="branches_covered"]')
                    .get("value")
                    .replace("%", "")
                )
            except AttributeError:
                coverage_value = "0.00"
            status_wit, category_wit = (
                status_from_verification,
                result.CATEGORY_CORRECT,
            )
            category_from_verification = result.CATEGORY_CORRECT
            try:
                coverage_percentage = Decimal(coverage_value) / 100
            except InvalidOperation:
                continue
            score_column = ElementTree.Element(
                "column",
                title="score",
                value=print_decimal(coverage_percentage),
            )
            verification_run.append(score_column)
        else:
            # For verification
            status_wit_new, category_wit_new = get_validator_linter_result(
                validation_run, verification_run
            )
            if (
                category_wit is None
                or not category_wit.startswith(result.CATEGORY_CORRECT)
                or category_wit_new == result.CATEGORY_CORRECT
            ):
                status_wit, category_wit = (status_wit_new, category_wit_new)
    return (
        status_wit,
        category_wit,
        status_from_verification,
        category_from_verification,
    )


def adjust_status_category(result_xml, validator_sets, linter_sets, overwrite_status):
    for run in result_xml.findall("run"):
        try:
            status_from_verification = run.find('column[@title="status"]').get("value")
        except AttributeError:
            status_from_verification = "not found"
        try:
            category_from_verification = run.find('column[@title="category"]').get(
                "value"
            )
        except AttributeError:
            category_from_verification = "not found"
        (
            statusWit,
            categoryWit,
            status_from_verification,
            category_from_verification,
        ) = get_validation_result(
            run,
            validator_sets,
            linter_sets,
            status_from_verification,
            category_from_verification,
        )
        # Overwrite status with status from validator or linter
        if (
            (
                overwrite_status
                or result.RESULT_CLASS_FALSE
                == result.get_result_classification(status_from_verification)
            )
            and "correct" == category_from_verification
            and statusWit is not None
            and categoryWit is not None
        ):
            try:
                run.find('column[@title="status"]').set("value", statusWit)
            except AttributeError:
                status_column = ElementTree.Element(
                    "column", title="status", value=statusWit
                )
                run.append(status_column)
            try:
                run.find('column[@title="category"]').set("value", categoryWit)
            except AttributeError:
                category_column = ElementTree.Element(
                    "column", title="category", value=categoryWit
                )
                run.append(category_column)
        # Clean-up an entry that can be inferred by table-generator automatically, avoids path confusion
        del run.attrib["logfile"]


def main(argv=None):
    if argv is None:
        argv = sys.argv[1:]
    args = parse_args(argv)
    result_file = args.resultsXML
    validator_linter_files = args.validatorLinterXML
    overwrite_status = not args.no_overwrite_status_true
    out_dir = args.outputpath
    assert validator_linter_files or not overwrite_status

    if not os.path.exists(result_file) or not os.path.isfile(result_file):
        sys.exit(f"File {result_file!r} does not exist.")
    result_xml = tablegenerator.parse_results_file(result_file)
    validator_sets = []
    linter_sets = []
    for validator_linter_file in validator_linter_files:
        if not os.path.exists(validator_linter_file) or not os.path.isfile(
            validator_linter_file
        ):
            sys.exit(f"File {validator_linter_file!r} does not exist.")
        results_xml = tablegenerator.parse_results_file(validator_linter_file)
        if results_xml.get("tool") == "witnesslint":
            linter_sets.append(get_runs(results_xml))
        else:
            validator_sets.append(get_runs(results_xml))

    adjust_status_category(result_xml, validator_sets, linter_sets, overwrite_status)

    filename = result_file + ".fixed.xml.bz2"
    if out_dir is not None:
        outfile = os.path.join(out_dir, os.path.basename(filename))
    else:
        outfile = filename
    if os.path.dirname(outfile) != "":
        os.makedirs(os.path.dirname(outfile), exist_ok=True)
    print("    " + outfile)
    with io.TextIOWrapper(bz2.BZ2File(outfile, "wb"), encoding="utf-8") as xml_file:
        xml_file.write(
            xml_to_string(result_xml).replace("    \n", "").replace("  \n", "")
        )


if __name__ == "__main__":
    sys.exit(main())
