import argparse
import re


# Adds "//NOFAIL" or "//SUCCESS" to the Goblint checks "__goblint_check(exp);" when there is no annotation yet.
# Stores the file with the appendix _success / _nofail.
def add_check_annotations(file_path: str, nofail_instead_of_success: bool):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    modified_lines = []
    for line in lines:
        match = re.search(r'(__goblint_check\(.*?\);)(?!.*?//)', line)
        if match:
            modified_line = match.group(1)
            if nofail_instead_of_success:
                modified_line += ' // NOFAIL'
            else:
                modified_line += ' // SUCCESS'
            line = line.replace(match.group(1), modified_line)
        modified_lines.append(line)

    new_file_name = file_path.rsplit('.', 1)[0] + ('_nofail.c' if nofail_instead_of_success else '_success.c')
    with open(new_file_name, 'w') as new_file:
        new_file.writelines(modified_lines)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file", help="Path to the C file")
    parser.add_argument("-n", "--nofail", action="store_true", help="Option for // NOFAIL")
    parser.add_argument("-s", "--success", action="store_true", help="Option for // SUCCESS")
    args = parser.parse_args()

    if not (args.nofail or args.success):
        parser.error("Error: Invalid option. Provide -t for \"//NOFAIL\" or -s for \"//SUCCESS\".")

    add_check_annotations(args.file, args.nofail)
