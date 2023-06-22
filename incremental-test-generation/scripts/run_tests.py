import argparse
import os
import subprocess
import sys
import questionary

from util import *


def run_tests(test_dir, goblint_repo_dir, cfg):
    # When the directory has a starting number >99 rename it for in place running of the tests
    match = re.match(r'(\d+)-(.*)', os.path.basename(test_dir))
    if match:
        number, text = match.groups()
        number = int(number)
        if number > 99:
            number = 99
        new_name = f'{number}-{text}'
        os.rename(test_dir, os.path.join(os.path.dirname(test_dir), new_name))
        test_dir = os.path.join(os.path.dirname(test_dir), new_name)
    else:
        print(f"{COLOR_RED}[ERROR] The test directory had not the format number-text{COLOR_RESET}")

    # Check the name of the test_dir
    test_dir_name = os.path.basename(test_dir)
    if test_dir_name != "99-temp":
        print(f"{COLOR_RED}[ERROR] The test directory name has to be \'99-temp\'{COLOR_RESET}")
        sys.exit(RETURN_ERROR)

    incremental_tests_dir_abs = os.path.abspath(os.path.join(goblint_repo_dir, "tests", "incremental", test_dir_name))
    only_temp_file = os.path.basename(os.path.dirname(incremental_tests_dir_abs)) == 'incremental' and os.path.basename(incremental_tests_dir_abs) == '99-temp'
    if os.path.exists(incremental_tests_dir_abs):
        if not only_temp_file:       
            print(f'{COLOR_RED}The test directory {incremental_tests_dir_abs} already exists.{COLOR_RESET}')
        if only_temp_file or questionary.confirm('Replace the directory?', default=True).ask():
            shutil.rmtree(incremental_tests_dir_abs)
        else:
            sys.exit(RETURN_ERROR)
    shutil.copytree(test_dir, incremental_tests_dir_abs)

    ruby_path_abs = os.path.abspath(os.path.join(goblint_repo_dir, "scripts", "update_suite.rb"))
    original_dir = os.getcwd()
    os.chdir(goblint_repo_dir)
    command = f"{ruby_path_abs} group temp -i"
    if cfg:
        command += " -c"
    process = subprocess.Popen(command, stdout=subprocess.PIPE, shell=True)

    # Process is running, print the output including carriage returns
    line = ''
    only_nothing_errors = True
    while process.poll() is None:
        char = process.stdout.read(1).decode('utf-8', 'replace')
        if char == '\r' or char == '\n':
            if not re.match(r'.*Excellent: ignored check on .* is now passing!$', line):
                sys.stdout.write('\r' + line)
                sys.stdout.flush()
                if char == '\n':
                    print()
                    if only_nothing_errors:
                        match = re.search(r'registered (\w+)', _remove_ansi_escape_sequences(line))
                        if match and match.group(1) != 'nothing':
                            only_nothing_errors = False
            else:
                sys.stdout.write('\r' + ' ' * len(line))
            line = ''
        else:
            line += char

    # Process has finished, but there might be output left to read.
    while True:
        char = process.stdout.read(1).decode('utf-8', 'replace')
        if not char:
            break
        if char == '\r' or char == '\n':
            if not re.match(r'.*Excellent: ignored check on .* is now passing!$', line):
                sys.stdout.write('\r' + line)
                sys.stdout.flush()
                if char == '\n':
                    print()
                    if only_nothing_errors:
                        match = re.search(r'registered (\w+)', _remove_ansi_escape_sequences(line))
                        if match and match.group(1) != 'nothing':
                            only_nothing_errors = False
            else:
                sys.stdout.write('\r' + ' ' * len(line))
            line = ''
        else:
            line += char


    shutil.rmtree(incremental_tests_dir_abs)
    shutil.rmtree(test_dir)
    os.chdir(original_dir)

    process.wait()

    return process.returncode, only_nothing_errors


def _remove_ansi_escape_sequences(s):
    ansi_escape = re.compile(r'\x1B(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])')
    return ansi_escape.sub('', s)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Run the tests in the specified test directory with the ruby script from Goblint')
    parser.add_argument('program_path', help='Path to the input file of the user')
    parser.add_argument('test_dir', help='Path to the directory with the tests (WARNING Will be removed!)')
    parser.add_argument('goblint_repo_dir', help='Path to the Goblint repository')
    parser.add_argument('-c', '--cfg', action='store_true', help='Run with fine-grained cfg-based change detection')

    args = parser.parse_args()

    run_tests(args.program_path, args.test_dir, args.goblint_repo_dir, args.cfg)
