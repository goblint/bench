import argparse
import json
import subprocess
import sys

import yaml

from util import *


# Takes a file and generates the goblint checks
# Adds a PARAM line
# Annotates extern goblint checks and dead code goblint checks with // NOWARN
# Stores the file with the appendix "_check"
# Write information to the meta.yaml file
def add_check(file_path, goblint_path, meta_path, params, index, enable_git):
    file_path_out = file_path.rsplit('.', 1)[0] + '_check.c'

    command = f'{goblint_path} {params.strip()} --enable trans.goblint-check --set trans.activated \'[\"assert\"]\' --set trans.output {file_path_out} {file_path}'
    result = subprocess.run(command, text=True, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    compiling = result.returncode == 0

    _write_compiling_result_to_meta(meta_path, index, compiling)

    if not compiling:
        print(f"\r{COLOR_RED}Error writing checks for program with index {index}.{COLOR_RESET}")
        # Check if program should be stopped
        if index == 0 and not enable_git:
            print(remove_ansi_escape_sequences(result.stdout))
            print(remove_ansi_escape_sequences(result.stderr))
            print(f"{COLOR_RED}The original program did not compile. Stopping program!{COLOR_RESET}")
            sys.exit(RETURN_ERROR)
        _write_exception_to_meta(meta_path, index, result.stderr)
        return False

    _prepend_param_line(file_path_out, params)
    # ALTERNATIVE _preserve_goblint_checks(file_path_out)
    _annotate_extern_check_definitions(file_path_out)
    _annotate_checks(goblint_path, file_path_out, params)

    return True


def _write_compiling_result_to_meta(meta_path, index, compiling):
    # Write compiling result to meta.yaml
    if meta_path is not None:
        with open(meta_path, 'r') as file:
            yaml_data = yaml.safe_load(file)
            yaml_data["p_" + str(index)][META_COMPILING] = compiling
        with open(meta_path, 'w') as file:
            yaml.safe_dump(yaml_data, file)


def _write_exception_to_meta(meta_path, index, exceptions_string):
    # Write compiling result and exceptions to meta.yaml
    if meta_path is not None:
        with open(meta_path, 'r') as file:
            yaml_data = yaml.safe_load(file)
        yaml_data[f"p_{index}"] = {
            META_TYPE: GenerateType.ML.value,
            META_EXCEPTION: exceptions_string,
            META_COMPILING: False
        }
        with open(meta_path, 'w') as file:
            yaml.safe_dump(yaml_data, file)

# Add //PARAM: line at the beginning of file
def _prepend_param_line(file_path, params):
    with open(file_path, 'r') as f:
        lines = f.readlines()
    with open(file_path, 'w') as f:
        f.write(f'//PARAM: {params}\n')
        f.writelines(lines)


# annotate extern void __goblint_check __goblint_assert with // NOWARN!
def _annotate_extern_check_definitions(file_path):
    with open(file_path, 'r') as file:
        contents = file.read()

    pattern = r'(extern void __goblint_(?:check|assert)\(.*\) ;)'
    matches = re.findall(pattern, contents)
    for match in matches:
        contents = contents.replace(match, match + ' // NOWARN! for extern definitions')

    pattern = r'(extern int \(.*__goblint_(?:check|assert)\)\(\) ;)'
    matches = re.findall(pattern, contents)
    for match in matches:
        contents = contents.replace(match, match + ' // NOWARN! for extern definitions')

    with open(file_path, 'w') as file:
        file.write(contents)


# transform __my_check_annotation to __goblint_check
def _preserve_goblint_checks(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    pattern = r'__my_check_annotation\((.*?), "(.*?)"\);'
    replacement = r'__goblint_check(\1); // \2'
    updated_content = re.sub(pattern, replacement, content)

    with open(file_path, 'w') as file:
        file.write(updated_content)


# annotates generated checks depending on the goblint analysis result
def _annotate_checks(goblint_path, file_path, params):
    # run the analysis
    command = f'{goblint_path} {params.strip()} --set result json-messages {file_path}'
    result = subprocess.run(command, text=True, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if result.returncode != 0:
        print(f"\n{COLOR_RED}Error compiling cil file.{COLOR_RESET}")
        print(result.stdout)
        print(result.stderr)
        sys.exit(RETURN_ERROR)

    # get the json data
    json_string = extract_json(result.stdout)
    if json_string is None:
        print(f"{COLOR_RED}No JSON found in the goblint output{COLOR_RESET}")
        print(result.stdout)
        print(result.stdout)
        sys.exit(RETURN_ERROR)
    json_data = json.loads(json_string)

    # search for lines which are marked as deadcode
    line_ranges_deadcode = []
    for message in json_data['messages']:
        for tag in message['tags']:
            if "Category" in tag and "Deadcode" in tag["Category"]:
                # Do not create when CWE Tag indicated that condition is always true
                if ("CWE" in tag and tag["CWE"] != 571) or not "CWE" in tag:
                    new_line_ranges = _get_line_ranges(message['multipiece'])
                    if new_line_ranges:
                        line_ranges_deadcode.append(new_line_ranges)

    # search for lines which are marked as successful asserts
    line_ranges_success = []
    for message in json_data['messages']:
        for tag in message['tags']:
            if "Category" in tag and "Assert" in tag["Category"]:
                if "severity" in message and message["severity"] == "Success":
                    new_line_ranges = _get_line_ranges(message['multipiece'])
                    if new_line_ranges:
                        line_ranges_success.append(new_line_ranges)


    # search for lines which are marked as unknown asserts
    line_ranges_unknown = []
    for message in json_data['messages']:
        for tag in message['tags']:
            if "Category" in tag and "Assert" in tag["Category"]:
                if "severity" in message and message["severity"] == "Warning":
                    new_line_ranges = _get_line_ranges(message['multipiece'])
                    if new_line_ranges:
                        line_ranges_unknown.append(new_line_ranges)

    # search for lines which are marked as failing asserts
    line_ranges_fail = []
    for message in json_data['messages']:
        for tag in message['tags']:
            if "Category" in tag and "Assert" in tag["Category"]:
                if "severity" in message and message["severity"] == "Error":
                    new_line_ranges = _get_line_ranges(message['multipiece'])
                    if new_line_ranges:
                        line_ranges_fail.append(new_line_ranges)

    # flatten the lists
    line_ranges_deadcode = [item for sublist in line_ranges_deadcode for item in sublist]
    line_ranges_success = [item for sublist in line_ranges_success for item in sublist]
    line_ranges_unknown = [item for sublist in line_ranges_unknown for item in sublist]
    line_ranges_fail = [item for sublist in line_ranges_fail for item in sublist]

    # remove unwanted checks
    _remove_deadcode_checks(line_ranges_deadcode, line_ranges_success, file_path)
    _remove_unknown_checks(line_ranges_unknown, file_path)
    _remove_failing_checks(line_ranges_fail, file_path)


# read line ranges from json multipiece element: (start, end)
def _get_line_ranges(multipiece):
    line_ranges = []
    if 'loc' in multipiece and multipiece['loc']:
        line_ranges.append((multipiece['loc']['line'], multipiece['loc']['endLine']))
    elif 'pieces' in multipiece:
        for piece in multipiece['pieces']:
            if piece['loc']:
                line_ranges.append((piece['loc']['line'], piece['loc']['endLine']))
    return line_ranges


# remove all __goblint_check in deadcode which are not annotated
def _remove_deadcode_checks(line_ranges_deadcode, line_ranges_success, file_path):
    pattern = r'\s*__goblint_check\((.*?)\);(?!//).*'

    with open(file_path, 'r') as f:
        lines = f.readlines()

    for i, line in enumerate(lines):
        # a line is considered if it is in line_ranges_deadcode and not in line_ranges_success
        if any(start <= i + 1 <= end for start, end in line_ranges_deadcode) and \
           not any(start <= i + 1 <= end for start, end in line_ranges_success):
            match = re.match(pattern, line)
            if match:
                lines[i] = f"; // [REMOVED_CHECK] generated check inside deadcode at line {i+1} removed: {match.group(1)}\n"

    with open(file_path, 'w') as f:
        f.writelines(lines)


# remove all __goblint_check which are unknown and not annotated
def _remove_unknown_checks(line_ranges_unknown, file_path):
    pattern = r'\s*__goblint_check\((.*?)\);(?!//).*'

    with open(file_path, 'r') as f:
        lines = f.readlines()

    for i, line in enumerate(lines):
        # a line is considered if it is in line_ranges_deadcode and not in line_ranges_success
        if any(start <= i + 1 <= end for start, end in line_ranges_unknown):
            match = re.match(pattern, line)
            if match:
                lines[i] = f"; // [REMOVED_CHECK] generated check which is unknown at line {i+1} removed: {match.group(1)}\n"

    with open(file_path, 'w') as f:
        f.writelines(lines)


# remove all __goblint_check which are failing and not annotated
def _remove_failing_checks(line_ranges_fail, file_path):
    pattern = r'\s*__goblint_check\((.*?)\);(?!//).*'

    with open(file_path, 'r') as f:
        lines = f.readlines()

    for i, line in enumerate(lines):
        # a line is considered if it is in line_ranges_fail and not in line_ranges_success
        if any(start <= i + 1 <= end for start, end in line_ranges_fail):
            match = re.search(pattern, line)
            if match:
                lines[i] = f"; // [REMOVED_CHECK] generated check which is failing at line {i+1} removed: {match.group(1)}\n"

    with open(file_path, 'w') as f:
        f.writelines(lines)



# get the json from the goblint terminal output
def extract_json(output):
    start_marker = "{\"files\":"
    end_marker = "]}"

    start_index = output.find(start_marker)
    if start_index == -1:
        return None

    end_index = output.rfind(end_marker)
    if end_index == -1:
        return None

    json_part = output[start_index:end_index + len(end_marker)]
    return json_part


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Generate __goblint_check() for a C file and stores it with appendix _check')

    # Add the required arguments
    parser.add_argument('file', help='Path to the C file')
    parser.add_argument('goblint', help='Path to the Goblint executable')
    parser.add_argument('params', help='Command line parameters for goblint test')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Call the process_file function with the provided arguments
    add_check(args.file, args.goblint, None, args.params, None, False)
