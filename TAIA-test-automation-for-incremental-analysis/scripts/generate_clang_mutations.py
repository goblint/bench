import argparse
import json
import subprocess
import sys

from util import *
from meta import *


# Generates mutations with clang-tidy
def generate_clang_mutations(program_path, clang_tidy_path, analyzer_path, mutations, index):

    if mutations.rfb:
        index = _iterative_mutation_generation(program_path, clang_tidy_path, analyzer_path, mutations.rfb_s, index)
    if mutations.uoi:
        index = _iterative_mutation_generation(program_path, clang_tidy_path, analyzer_path, mutations.uoi_s, index)
    if mutations.ror:
        index = _iterative_mutation_generation(program_path, clang_tidy_path, analyzer_path, mutations.ror_s, index)
    if mutations.cr:
        index = _iterative_mutation_generation(program_path, clang_tidy_path, analyzer_path, mutations.cr_s, index)
    if mutations.rt:
        index = _iterative_mutation_generation(program_path, clang_tidy_path, analyzer_path, mutations.rt_s, index)
    if mutations.lcr:
        index = _iterative_mutation_generation(program_path, clang_tidy_path, analyzer_path, mutations.lcr_s, index)
    if mutations.ris:
        index = _iterative_mutation_generation(program_path, clang_tidy_path, analyzer_path, mutations.ris_s, index)

    meta_set_n(index)

    return index


def _iterative_mutation_generation(program_path, clang_tidy_path, analyzer_path, mutation_name, index):
    print_separator()
    print(f"[{GenerateType.CLANG.value}] {mutation_name}")
    # get line groups for knowing where the mutation could be applied
    line_groups = _get_line_groups(clang_tidy_path, analyzer_path, mutation_name, program_path)
    # apply only one mutation at a time
    for lines in line_groups:
        index += 1
        new_path = make_program_copy(program_path, index)
        if mutation_name == Operators().rt_s:
            # When Remove-Thread create wrapper for the thread function and then apply the mutations
            if len(lines) != 1:
                # Needed to prevent conflicts on generating wrappers
                print(
                    f"{COLOR_RED}ERROR When applying remove_thread there always should be exactly one line{COLOR_RESET}")
            function_name = _get_thread_function_name(clang_tidy_path, analyzer_path, lines, new_path, index)
            _wrap_thread_function(clang_tidy_path, analyzer_path, new_path, function_name, index)
        _apply_mutation(clang_tidy_path, analyzer_path, mutation_name, lines, new_path, index)
        meta_create_index(index, GenerateType.CLANG.value, mutation_name, lines)
    return index


# Returns a list of lists. The sub lists represent lines at which a single mutation should be applied
# Per default this is only one line (eg.: [[1], [42]] ). Multiple lines are needed for replacing all Macros
def _get_line_groups(clang_tidy_path, analyzer_path, mutation_name, program_path):
    program_path_temp = os.path.join(os.path.dirname(program_path), 'p_temp.c')
    shutil.copy(program_path, program_path_temp)

    # Execute all mutations to get the lines where the mutation is possible
    print(f"[CLANG][CHECK] Check mutation {mutation_name}", end='')
    command = f'{clang_tidy_path} -checks=-*,readability-{mutation_name} {program_path_temp} --quiet-return -- -I{os.path.dirname(program_path)} {include_options(analyzer_path, for_clang=True)}'
    result = subprocess.run(command, text=True, shell=True, capture_output=True)
    if result.returncode != 0:
        print('\n')
        print(result.stdout)
        print(result.stderr)
        print(f"{COLOR_RED}ERROR Running Clang (Line Groups){COLOR_RESET}")
        meta_crash_and_store(META_CRASH_MESSAGE_CLANG_LINE_GROUPS)
        sys.exit(RETURN_ERROR)

    # get the line groups from the output
    line_groups = []
    pattern = r":(\d+):.*\[readability-" + mutation_name + r"\]"
    macro_pattern = r"\[MACRO\]\[(.*?)\]"
    macro_lines = {}
    for line in result.stdout.splitlines():
        match = re.search(pattern, line)
        if match:
            macro_match = re.search(macro_pattern, line)
            if macro_match:
                # for macros add all macro occurrences to the line group
                macro_name = macro_match.group(1)
                line_number = int(match.group(1))
                if macro_name not in macro_lines:
                    macro_lines[macro_name] = [line_number]
                else:
                    macro_lines[macro_name].append(line_number)
            else:
                line_groups.append([int(match.group(1))])

    # add the line groups for macros
    for macro_name, lines in macro_lines.items():
        line_groups.append(lines)

    # Remove duplicate line groups
    line_groups = [list(x) for x in set(tuple(x) for x in line_groups)]

    os.remove(program_path_temp)

    print(f"\r[CLANG][CHECK] Mutation {mutation_name} can be applied to lines {line_groups}")
    return sorted(line_groups, key=lambda x: x[0])


def _apply_mutation(clang_tidy_path, analyzer_path, mutation_name, lines, program_path, index):
    lines_mapped = [[x, x] for x in lines]
    line_filter = [{"name": program_path, "lines": lines_mapped}]
    line_filter_json = json.dumps(line_filter)
    command = f'{clang_tidy_path} -checks=-*,readability-{mutation_name} --quiet-return --fix-warnings -line-filter="{line_filter_json}" {program_path} -- -I{os.path.dirname(program_path)} {include_options(analyzer_path, for_clang=True)}'
    result = subprocess.run(command, shell=True, text=True, capture_output=True)
    if result.returncode == 0:
        print(f"{COLOR_GREEN}[{index}] Finished mutation:{COLOR_RESET} {mutation_name} on lines {lines}")
    else:
        print(result.stdout)
        print(result.stderr)
        print(f"{COLOR_RED}ERROR Running Clang (Apply){COLOR_RESET}")
        meta_crash_and_store(META_CRASH_MESSAGE_CLANG_APPLY)
        sys.exit(RETURN_ERROR)


# Execute the check to find the name of the thread function (needed to generate a wrapper)
def _get_thread_function_name(clang_tidy_path, analyzer_path, lines, program_path, index):
    program_path_temp = os.path.join(os.path.dirname(program_path), 'p_temp.c')
    shutil.copy(program_path, program_path_temp)

    lines_mapped = [[x, x] for x in lines]
    line_filter = [{"name": program_path_temp, "lines": lines_mapped}]
    line_filter_json = json.dumps(line_filter)
    command = f'{clang_tidy_path} -checks=-*,readability-{Operators().rt_s} -line-filter="{line_filter_json}" {program_path_temp} --quiet-return -- -I{os.path.dirname(program_path)} {include_options(analyzer_path, for_clang=True)}'
    result = subprocess.run(command, text=True, shell=True, capture_output=True)
    print(f'[{index}][WRAP] Check function name for wrapping thread function', end='')
    if result.returncode != 0:
        print(result.stdout)
        print(result.stderr)
        print(f"{COLOR_RED}ERROR Running Clang (Get Function Name){COLOR_RESET}")
        meta_crash_and_store(META_CRASH_MESSAGE_CLANG_FUNCTION_NAME)
        sys.exit(RETURN_ERROR)

    function_name_pattern = r"\[FUNCTION_NAME\]\[(.*?)\]"
    function_name = None

    for line in result.stdout.splitlines():
        function_name_match = re.search(function_name_pattern, line)
        if function_name_match:
            function_name = function_name_match.group(1)
            break

    os.remove(program_path_temp)

    print(f'\r[{index}][WRAP RESULT] Found the thread function name {function_name}{SPACE}', end='')
    return function_name


# generate a wrapper for the thread function
def _wrap_thread_function(clang_tidy_path, analyzer_path, program_path, function_name, index):
    if function_name is None:
        print(f"\r{COLOR_YELLOW}[{index}][WRAP FIX] No function name was provided.{COLOR_RESET}")
        meta_crash_and_store('[WRAP FIX] No function name was provided.')
        sys.exit(RETURN_ERROR)

    check_options = {"CheckOptions": {"readability-remove-thread-wrapper.WrapFunctionName": function_name}}
    check_options_json = json.dumps(check_options)
    command = f'{clang_tidy_path} -checks=-*,readability-remove-thread-wrapper -config=\'{check_options_json}\' --fix-warnings --quiet-return {program_path} -- -I{os.path.dirname(program_path)} {include_options(analyzer_path, for_clang=True)}'
    result = subprocess.run(command, shell=True, text=True, capture_output=True)
    print(f"\r[{index}][WRAP FIX] Applied the wrapping of the thread function {function_name}{SPACE}")
    if result.returncode != 0:
        print(result.stdout)
        print(result.stderr)
        print(f"{COLOR_RED}ERROR Running Clang (Wrap){COLOR_RESET}")
        meta_crash_and_store(META_CRASH_MESSAGE_CLANG_WRAP)
        sys.exit(RETURN_ERROR)    


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate all possible mutations of a program.")
    parser.add_argument("program", help="Path to the C program")
    parser.add_argument("clang_tidy", help="Path to the modified clang-tidy executable")
    parser.add_argument("analyzer_path", help="Path to the Goblint analyzer")
    add_clang_options(parser)

    args = parser.parse_args()
    mutations = get_operators_from_args(args)
    generate_clang_mutations(args.program, args.clang_tidy, args.analyzer_path, mutations, 0)
