import argparse
import re


# Adds "//TODO" or "//SUCCESS" to the Goblint checks "__goblint_check(exp);" when there is no comment yet.
# Stores the file with the appendix _success / _todo.
def add_check_annotations(file_path: str, todo_instead_of_success: bool):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    modified_lines = []
    for line in lines:
        match = re.search(r'(__goblint_check\(.*?\);)(?!.*?//)', line)
        if match:
            modified_line = match.group(1)
            if todo_instead_of_success:
                modified_line += ' // TODO'
            else:
                modified_line += ' // SUCCESS'
            line = line.replace(match.group(1), modified_line)
        modified_lines.append(line)

    new_file_name = file_path.rsplit('.', 1)[0] + ('_todo.c' if todo_instead_of_success else '_success.c')
    with open(new_file_name, 'w') as new_file:
        new_file.writelines(modified_lines)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file", help="Path to the C file")
    parser.add_argument("-t", "--todo", action="store_true", help="Option for // TODO")
    parser.add_argument("-s", "--success", action="store_true", help="Option for // SUCCESS")
    args = parser.parse_args()

    if not (args.todo or args.success):
        parser.error("Error: Invalid option. Provide -t for \"//TODO\" or -s for \"//SUCCESS\".")

    add_check_annotations(args.file, args.todo)
