import argparse
import json
import subprocess

import questionary

from meta import *
from util import *


# Generate test directory based on previously generated directory with mutated files
def generate_tests(temp_dir, target_dir, goblint_config, include_paths, precision_test, inplace: bool, enable_patch_stats):
    # Check the name of the target_dir
    directory_name = os.path.basename(target_dir)
    if not inplace and not check_test_dir_name(directory_name):
        meta_crash_and_store(META_CRASH_MESSAGE_CREATE_TEST_NAME)
        sys.exit(RETURN_ERROR)

    if os.path.exists(target_dir):
        print(f'{COLOR_RED}The test directory {target_dir} already exists.{COLOR_RESET}')
        if questionary.confirm('Replace the directory?', default=True).ask():
            shutil.rmtree(target_dir)
        else:
            meta_crash_and_store(META_CRASH_MESSAGE_CREATE_TEST_EXISTS)
            sys.exit(RETURN_ERROR)
    os.makedirs(target_dir)

    # Places include files in temp directory
    include_paths_test = []
    for path in include_paths:
        include_path_new = os.path.join(target_dir, os.path.basename(path))
        include_paths_test.append(include_path_new)
        shutil.copy(path, include_path_new)

    n = meta_get_n()

    # store the paths to the test dirs
    initial_target_dir = target_dir
    test_paths = [target_dir]
    # count the tests to know when to create a new directory [0; 99]
    current_test_num = 1  # Skip num 0 to align program index with test number
    # store the directory number
    current_dir_num = int(directory_name[:2])
    # get the current values
    unchanged_count = 0
    if inplace and int(directory_name[:3]) != 100:
        print(f'{COLOR_RED}[ERROR] The directory number for temp files must be 100 but was {directory_name}{COLOR_RESET}')
        meta_crash_and_store(META_CRASH_MESSAGE_CREATE_TEST_NAME)
        sys.exit(RETURN_ERROR)
    elif inplace:
        # For inplace test files store them with dir num 100 and rename them later when running to 99
        current_dir_num = 100
        initial_target_dir = os.path.join(os.path.dirname(target_dir), '99' + os.path.basename(target_dir)[3:])

    # loop threw all generated mutations
    for i in range(n + 1):
        # When too many tests create a new directory
        if current_test_num > 99:
            current_dir_num += 1

            # When the dir name is > 99 throw an error
            if not inplace and current_dir_num > 99:
                print(f'{COLOR_RED}[ERROR] The directory number 100 is out of range. Consider starting with a lower than {directory_name} {COLOR_RESET}')
                meta_crash_and_store(META_CRASH_MESSAGE_CREATE_TEST_MAX_EXCEEDED)
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
                    meta_crash_and_store(META_CRASH_MESSAGE_CREATE_TEST_EXISTS)
                    sys.exit(RETURN_ERROR)
            os.mkdir(target_dir)

            # reset the test num
            current_test_num = 0

        # Skip mutations with exceptions            
        if meta_exception_exists(i):
            print(f"\r{COLOR_YELLOW}Skipped test file {i} as an exception occurred in a previous step{COLOR_RESET}")
            continue

        # Get the type and subtype of the mutation
        (generate_type, generate_sub_type) = meta_get_type_and_subtype(i)

        # Skip the reference program as it is used for the patch
        if generate_type == GenerateType.INPUT.value:
            continue

        print(f"\rGenerating test files [{i}/{n}]", end='')

        # Determine the name for the test
        if generate_type == GenerateType.CLANG.value:
            test_name = f'{_format_number(current_test_num)}-{generate_type}_{generate_sub_type}_p_{_format_number(i)}'
        elif generate_type == GenerateType.AI.value:
            test_name = f'{_format_number(current_test_num)}-{generate_type}_p_{_format_number(i)}'

        # Select the start and end file of at test
        initial_program_id = 'p_0'
        current_program_id = f'p_{i}'
        start_program = os.path.join(temp_dir, current_program_id + '_check_success.c')
        end_program = os.path.join(temp_dir, initial_program_id + '_check_nofail.c')
        end_program_precision = os.path.join(temp_dir, initial_program_id + '_check_notinprecise.c')

        # Copy mutated code as the initial code
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
            _fix_patch_file(patch_path, os.path.basename(initial_target_dir), test_name + '.c')
        else:
            _fix_patch_file(patch_path, os.path.basename(target_dir), test_name + '.c')
        if result.returncode in [0, 1]:
            if result.returncode == 0:
                print(f"\r{COLOR_YELLOW}[WARNING] There were no changes in the patch for test {i}{COLOR_RESET}")
                unchanged_count += 1
                meta_diff_empty(i)
            elif enable_patch_stats:
                added_count = 0
                removed_count = 0
                with open(patch_path, 'r') as f:
                    for line in f:
                        if line[1:].lstrip().startswith('__goblint_check(') or line.startswith('+++') or line.startswith('---'):
                            continue
                        if line.startswith('+'):
                            added_count += 1
                        elif line.startswith('-'):
                            removed_count += 1
                meta_diff(added_count, removed_count, i)
        else:
            print(f"Creation of patch failed with return code: {result.returncode}")
            meta_crash_and_store(META_CRASH_MESSAGE_CREATE_TEST_PATCH)
            sys.exit(RETURN_ERROR)

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

    generate_tests(args.temp_dir, args.target_dir, args.goblint_config, [], args.precision_test, args.inplace, None)


if __name__ == '__main__':
    main()
