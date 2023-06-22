import argparse
import subprocess
import sys

from util import *


# Run the tests
# The test_dir must be in the format xxx-tmp where xxx is a number >= 100
def run_tests(test_dir, goblint_repo_dir, cfg):
    # Change the number of the test directory to 99 for in place testing
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

    # Check the group name of the test_dir
    test_dir_name = os.path.basename(test_dir)
    if test_dir_name != "99-temp":
        print(f"{COLOR_RED}[ERROR] The test directory name has to be \'99-temp\'{COLOR_RESET}")
        sys.exit(RETURN_ERROR)

    # Copy the test file to the incremental tester
    incremental_tests_dir_abs = os.path.abspath(os.path.join(goblint_repo_dir, "tests", "incremental", test_dir_name))
    if os.path.exists(incremental_tests_dir_abs):
        shutil.rmtree(incremental_tests_dir_abs)
    shutil.copytree(test_dir, incremental_tests_dir_abs)

    # Start running the tester
    ruby_path_abs = os.path.abspath(os.path.join(goblint_repo_dir, "scripts", "update_suite.rb"))
    original_dir = os.getcwd()
    os.chdir(goblint_repo_dir)
    command = f"{ruby_path_abs} group temp -i"
    if cfg:
        command += " -c"
    process = subprocess.Popen(command, stdout=subprocess.PIPE, shell=True)

    # Process is running, print the output including carriage returns
    line = ''
    while process.poll() is None:
        char = process.stdout.read(1).decode('utf-8', 'replace')
        line = _print_char_to_line(char, line)

    # Process has finished, but there might be output left to read.
    while True:
        char = process.stdout.read(1).decode('utf-8', 'replace')
        if not char:
            break
        line = _print_char_to_line(char, line)

    # Wait for process to finish
    process.wait()

    # Cleanup
    shutil.rmtree(incremental_tests_dir_abs)
    shutil.rmtree(test_dir)
    os.chdir(original_dir)

    return process.returncode


def _remove_ansi_escape_sequences(s):
    ansi_escape = re.compile(r'\x1B(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])')
    return ansi_escape.sub('', s)


def _print_char_to_line(char, line):
    if char == '\r' or char == '\n':
        if not re.match(r'.*Excellent: ignored check on .* is now passing!$', line):
            sys.stdout.write('\r' + line)
            sys.stdout.flush()
            if char == '\n':
                print()
        else:
            sys.stdout.write('\r' + ' ' * len(line))
        line = ''
    else:
        line += char
    return line


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Run the tests in the specified test directory with the ruby script from Goblint')
    parser.add_argument('test_dir', help='Path to the directory with the tests (WARNING Will be removed!)')
    parser.add_argument('goblint_repo_dir', help='Path to the Goblint repository')
    parser.add_argument('-c', '--cfg', action='store_true', help='Run with fine-grained cfg-based change detection')

    args = parser.parse_args()

    run_tests(args.test_dir, args.goblint_repo_dir, args.cfg)
