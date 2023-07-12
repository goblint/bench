import argparse
import json
import subprocess
import sys

import questionary
import yaml

from util import *


# Generate test directory based on previously generated directory with mutated files
def generate_tests(temp_dir, target_dir, goblint_config, include_paths, precision_test, inplace: bool):
    # Check the name of the target_dir
    directory_name = os.path.basename(target_dir)
    if not inplace and not check_test_dir_name(directory_name):
        sys.exit(RETURN_ERROR)

    if os.path.exists(target_dir):
        print(f'{COLOR_RED}The test directory {target_dir} already exists.{COLOR_RESET}')
        if questionary.confirm('Replace the directory?', default=True).ask():
            shutil.rmtree(target_dir)
        else:
            sys.exit(RETURN_ERROR)
    os.makedirs(target_dir)

    # Place include files in temp directory
    include_paths_test = []
    for path in include_paths:
        include_path_new = os.path.join(target_dir, os.path.basename(path))
        include_paths_test.append(include_path_new)
        shutil.copy(path, include_path_new)

    # Read the meta.yaml
    meta_path = os.path.join(temp_dir, META_FILENAME)
    with open(meta_path, 'r') as file:
        yaml_data = yaml.safe_load(file)
    n = yaml_data[META_N]

    # store the paths to the test dirs
    inital_target_dir = target_dir
    test_paths = [target_dir]
    # count the tests to know when to create a new directory [0; 99]
    current_test_num = 1  # Skip num 0 to align program index with test number
    # store the directory number
    current_dir_num = int(directory_name[:2])
    # get the current values
    unchanged_count = 0
    compiling_programs = []
    if inplace and int(directory_name[:3]) != 100:
        print(f'{COLOR_RED}[ERROR] The directory number for temp files must be 100 but was {directory_name}{COLOR_RESET}')
        sys.exit(RETURN_ERROR)
    elif inplace:
        # For inplace test files store them with dir num 100 and rename them later when running to 99
        current_dir_num = 100
        inital_target_dir = os.path.join(os.path.dirname(target_dir), '99' + os.path.basename(target_dir)[3:])

    # loop threw all generated mutations
    for i in range(n + 1):
        # When too many tests create a new directory
        if current_test_num > 99:
            current_dir_num += 1

            # When the dir name is > 99 throw an error
            if not inplace and current_dir_num > 99:
                print(
                    f'{COLOR_RED}[ERROR] The directory number 100 is out of range. Consider starting with a lower than {directory_name} {COLOR_RESET}')
                sys.exit(RETURN_ERROR)

            # create the new dir
            group_name = re.match(r'\d+-(.*)', directory_name).group(1)
            target_dir = os.path.join(os.path.dirname(target_dir), f'{current_dir_num:02}-{group_name}')
            test_paths.append(target_dir)
            if os.path.exists(target_dir):
                print(f'{COLOR_RED}The test directory {target_dir} already exists.{COLOR_RESET}')
                if questionary.confirm('Replace the directory?', default=True).ask():
                    shutil.rmtree(target_dir)
                else:
                    sys.exit(RETURN_ERROR)
            os.mkdir(target_dir)

            # reset the test num
            current_test_num = 0

        # get the id of the current program
        current_program_id = f'p_{i}'

        # check if it compiled. When not skip it
        try:
            compilation_success = yaml_data[current_program_id][META_COMPILING]
        except:
            print(f'\r{COLOR_RED}Error test file {i} has no entry in the metadata file{COLOR_RESET}')
            sys.exit(RETURN_ERROR)
        if compilation_success:
            compiling_programs.append(i)
        else:
            print(f"\r{COLOR_YELLOW}Skipped test file {i} as it did not compile while generating the checks{COLOR_RESET}")
            continue
        if META_EXCEPTION in yaml_data[current_program_id]:
            print(
                f"\r{COLOR_YELLOW}Skipped test file {i} as an exception occurred in a previous step{COLOR_RESET}")
            continue

        # Skip the reference program as it is used for the patch
        generate_type = yaml_data[current_program_id][META_TYPE]
        if generate_type == GenerateType.INITAL.value:
            continue

        print(f"\rGenerating test files [{i}/{n}]", end='')

        # Determine the name for the test
        sub_type = yaml_data[current_program_id][META_SUB_TYPE]
        if generate_type == GenerateType.MUTATION.value:
            test_name = f'{_format_number(current_test_num)}-{generate_type}_{sub_type}_p_{_format_number(i)}'
        elif generate_type == GenerateType.ML.value:
            test_name = f'{_format_number(current_test_num)}-{generate_type}_p_{_format_number(i)}'

        # Select depending on generator the start and end file of at test
        if generate_type == GenerateType.MUTATION.value or generate_type == GenerateType.ML.value:
            inital_program_id = 'p_0'
            start_program = os.path.join(temp_dir, current_program_id + '_check_success.c')
            end_program = os.path.join(temp_dir, inital_program_id + '_check_nofail.c')
            end_program_precision = os.path.join(temp_dir, inital_program_id + '_check_notinprecise.c')
        else:
            print(f'\n{COLOR_RED}[ERROR] Trying to generate tests from unknown generator type{COLOR_RESET}')
            sys.exit(RETURN_ERROR)

        # Copy mutated code as the inital code
        shutil.copy2(start_program, os.path.join(target_dir, test_name + '.c'))
        # Create a patch file
        patch_path = os.path.join(target_dir, test_name + '.patch')
        command = 'diff -u {} {} > {}'.format(
            os.path.join(target_dir, test_name + '.c'),
            end_program_precision if precision_test else end_program,
            patch_path
        )
        result = subprocess.run(command, shell=True)
        if inplace:
            # For patch files keep the 99 for running inplace after renaming folder
            _fix_patch_file(patch_path, os.path.basename(inital_target_dir), test_name + '.c')
        else:
            _fix_patch_file(patch_path, os.path.basename(target_dir), test_name + '.c')
        if result.returncode in [0, 1]:
            if result.returncode == 0:
                print(f"\r{COLOR_YELLOW}[WARNING] There were no changes in the patch for test {i}{COLOR_RESET}")
                unchanged_count += 1
                yaml_data[current_program_id][META_DIFF] = False
            else:
                yaml_data[current_program_id][META_DIFF] = True
        else:
            raise Exception(f"Command failed with return code: {result.returncode}")

        # Create config file
        if goblint_config is None:
            # Create an empty config file
            data = {}
            with open(os.path.join(target_dir, test_name + '.json'), 'w') as f:
                json.dump(data, f)
        else:
            # Copy config file
            shutil.copy2(os.path.abspath(os.path.expanduser(goblint_config)),
                         os.path.join(target_dir, test_name + '.json'))

        # next test
        current_test_num += 1

    print(f"\r{COLOR_GREEN}Generating test files [DONE]{SPACE}{COLOR_RESET}")
    if unchanged_count > 0:
        print(f'{COLOR_YELLOW}There were {unchanged_count} patch files with no changes.{COLOR_RESET}')

    with open(meta_path, 'w') as file:
        yaml.safe_dump(yaml_data, file)

    # Return the list of generated directories
    return test_paths


# Change the paths in the patch file so the tester can apply the test correctly
def _fix_patch_file(patch_file, folder_name, file_name):
    with open(patch_file, 'r') as file:
        lines = file.readlines()

    with open(patch_file, 'w') as file:
        for line in lines:
            if line.startswith('---') or line.startswith('+++'):
                line = line.split(' ')[0] + " " + "tests/incremental/" + folder_name + "/" + file_name + "\n"
            file.write(line)


# Format the number with leading zeros as used in the tester
def _format_number(n):
    return str(n).zfill(2)


def main():
    parser = argparse.ArgumentParser(
        description='Generate Test files in the target directory based on the working directory')
    parser.add_argument('temp_dir', help='Path to the working directory')
    parser.add_argument('target_dir', help='Path to the target directory')
    parser.add_argument('-p', '--precision-test', action='store_true', help='Generate tests for precision')
    parser.add_argument('-c', '--goblint-config', help='Optional path to the goblint config file used for the tests (using no option creates an empty one)')
    parser.add_argument('-i', '--inplace', action='store_true', help='Generate test files for running in place')

    args = parser.parse_args()

    generate_tests(args.temp_dir, args.target_dir, args.goblint_config, args.precision_test, args.inplace)


if __name__ == '__main__':
    main()
