# Takes a file and generates the goblint checks
# Stores the file with an additional "_c"
# When there is a compilation error the process writes [META_EXCEPTION] into the metadata file for the given index

import argparse
import os
import subprocess
import sys
import yaml
from util import *


def add_check(file_path: str, index: int, goblint_path: str, meta_path: str, temp_dir: str):
    file_path_out = file_path.rsplit('.', 1)[0] + '_check.c'

    command = [
        goblint_path,
        "--enable",
        "trans.goblint-check",
        "--set",
        "trans.activated",
        '["assert"]',
        "--set",
        "trans.output",
        file_path_out,
        file_path
    ]

    result = subprocess.run(command, text=True, capture_output=True)

    compiling = result.returncode == 0

    with open(meta_path, 'r') as file:
        yaml_data = yaml.safe_load(file)
        yaml_data["p_" + str(index)][META_COMPILING] = compiling
    with open(meta_path, 'w') as file:
        yaml.safe_dump(yaml_data, file)

    if not compiling:
        print(f"{COLOR_RED}Error compiling program with index {index}.{COLOR_RESET}")
        if index == 0 and not yaml_data["p_0"][META_TYPE] == GenerateType.GIT.value:
            print(result.stdout)
            print(result.stdout)
            print(f"{COLOR_RED}The original program did not compile. Stopping program!{COLOR_RESET}")
            sys.exit(RETURN_ERROR)
        with open(meta_path, 'r') as file:
            yaml_data = yaml.safe_load(file)
        yaml_data[f"p_{index}"] = {
            META_TYPE: GenerateType.ML.value,
            META_EXCEPTION: result.stderr,
            META_COMPILING: False
        }
        with open(meta_path, 'w') as file:
            yaml.safe_dump(yaml_data, file)
        return False
    
    origninal_input_file = os.path.join(temp_dir, 'p_0.c')
    params = _get_params_from_file(origninal_input_file)
    _prepend_param_line(file_path_out, params)

    return True


def _get_params_from_file(filename):
    param_pattern = re.compile(r"\s*//.*PARAM\s*:\s*(.*)")

    with open(filename, 'r') as f:
        for line in f:
            match = param_pattern.match(line)
            if match:
                params = match.group(1).strip()
                return params

    return ""


def _prepend_param_line(file_path, params):
    with open(file_path, 'r') as f:
        lines = f.readlines()
    with open(file_path, 'w') as f:
        f.write(f'//PARAM: {params}\n')
        f.writelines(lines)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Generate __goblint_check() for a C file. When not compiling write [NOT COMPILING] in the meta file')

    # Add the required arguments
    parser.add_argument('file', help='Path to the C file')
    parser.add_argument('index', help='Index of the file (needed for meta data)')
    parser.add_argument('goblint', help='Path to the Goblint executable')
    parser.add_argument('meta', help='Path to the meta data file')
    parser.add_argument('temp', help='Path to the temp directory')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Call the process_file function with the provided arguments
    add_check(args.file, args.index, args.goblint, args.meta, args.temp)