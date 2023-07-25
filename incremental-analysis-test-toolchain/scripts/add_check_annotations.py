import argparse
import re


# Adds annotations to the Goblint checks "__goblint_check(exp);" when there is no annotation yet.
# Stores the file with the appendix of the annotation name.
def add_check_annotations(file_path: str, annotation: str):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    modified_lines = []
    for line in lines:
        match = re.search(r'(__goblint_check\(.*?\);)(?!.*?//)', line)
        if match:
            modified_line = match.group(1)
            modified_line += f' // {str.upper(annotation)}'
            line = line.replace(match.group(1), modified_line)
        modified_lines.append(line)

    new_file_name = f"{file_path.rsplit('.', 1)[0]}_{str.lower(annotation)}.c"
    with open(new_file_name, 'w') as new_file:
        new_file.writelines(modified_lines)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("file", help="Path to the C file")
    parser.add_argument("annotation", help="Name of the annotation")
    args = parser.parse_args()

    add_check_annotations(args.file, args.annotation)
