# Takes a file and generates the goblint checks
# Stores the file with an additional "_c"
# When there is a compilation error the process writes [META_EXCEPTION] into the metadata file for the given index

import argparse
import json
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

    result = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    compiling = result.returncode == 0

    with open(meta_path, 'r') as file:
        yaml_data = yaml.safe_load(file)
        yaml_data["p_" + str(index)][META_COMPILING] = compiling
    with open(meta_path, 'w') as file:
        yaml.safe_dump(yaml_data, file)

    if not compiling:
        print(f"\n{COLOR_RED}Error compiling program with index {index}.{COLOR_RESET}")
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
    _mark_extern_check_definitions(file_path_out)
    _mark_generated_checks(goblint_path, file_path_out, index)
    _preserve_goblint_checks(file_path_out)

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


def _mark_extern_check_definitions(file_path):
    with open(file_path, 'r') as file:
        contents = file.read()

    pattern = r'(extern void __goblint_(?:check|assert)\(int exp \) ;)'
    matches = re.findall(pattern, contents)
    for match in matches:
        contents = contents.replace(match, match + ' // NOWARN for extern definitions')

    with open(file_path, 'w') as file:
        file.write(contents)


def _preserve_goblint_checks(file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    pattern = r'__goblint_check_comment\((.*?), "(.*?)"\);'
    replacement = r'__goblint_check(\1); // \2'
    updated_content = re.sub(pattern, replacement, content)

    with open(file_path, 'w') as file:
        file.write(updated_content)


def _mark_generated_checks(goblint_path, file_path, index):
    command = [
        goblint_path,
        "--set",
        "result",
        "json-messages",
        file_path
    ]

    result = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    if result.returncode != 0:
        print(f"\n{COLOR_RED}Error compiling cil file with index {index}.{COLOR_RESET}")
        print(result.stdout)
        print(result.stdout)
        sys.exit(RETURN_ERROR)

    json_string = extract_json(result.stdout)
    if json_string is None:
        print(f"{COLOR_RED}No JSON found in the goblint output{COLOR_RESET}")
        print(result.stdout)
        print(result.stdout)
        sys.exit(RETURN_ERROR)
    
    json_data = json.loads(json_string)
    line_ranges = []
    for message in json_data['messages']:
        for tag in message['tags']:
            if "Category" in tag and "Deadcode" in tag["Category"]:
                new_line_ranges = _get_line_ranges(message['multipiece'])
                if new_line_ranges != []:
                    line_ranges.append(new_line_ranges)
    
    # Flatten the list
    line_ranges = [item for sublist in line_ranges for item in sublist]
    _mark_deadcode_checks(line_ranges, file_path)


def _get_line_ranges(multipiece):
    line_ranges = []
    if 'loc' in multipiece and multipiece['loc']:
        line_ranges.append((multipiece['loc']['line'], multipiece['loc']['endLine']))
    elif 'pieces' in multipiece:
        for piece in multipiece['pieces']:
            if piece['loc']:
                line_ranges.append((piece['loc']['line'], piece['loc']['endLine']))
    return line_ranges



def _mark_deadcode_checks(line_ranges, file_path):
    pattern = r'\s*__goblint_check\(.*\);(?!//).*'

    with open(file_path, 'r') as f:
        lines = f.readlines()

    for i, line in enumerate(lines):
        if any(start <= i+1 <= end for start, end in line_ranges):
            if re.match(pattern, line):
                lines[i] = line.rstrip('\n') + " // NOWARN! generated for deadcode\n"
    
    with open(file_path, 'w') as f:
        f.writelines(lines)


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
