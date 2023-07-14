from add_check import add_check
from add_check_annotations import add_check_annotations
from generate_ml import *
from generate_mutations import *
from meta import *


# generates programs in the temp_dir
def generate_programs(source_path, temp_dir, clang_tidy_path, goblint_path, apikey_path, mutations, enable_mutations,
                      enable_ml, enable_precision, ml_count, ml_select, ml_interesting, ml_16k, include_paths):
    # Clean working directory
    if os.path.isdir(temp_dir):
        shutil.rmtree(temp_dir)
    os.makedirs(temp_dir)
    # Create Meta file
    meta_path = os.path.join(temp_dir, META_FILENAME)
    meta_create_file(meta_path, source_path)
    # Copy the source program into the temp dir
    program_path = os.path.join(temp_dir, 'p.c')
    shutil.copy2(source_path, program_path)
    program_0_path = os.path.join(temp_dir, 'p_0.c')
    shutil.copy2(source_path, program_0_path)
    # ALTERNATIVE Preserve the __goblint_check() annotations
    # ALTERNATIVE _preserve_goblint_check_annotations(program_0_path)
    # ALTERNATIVE To be added: Also preserve _goblint_assert() and assert()
    _remove_goblint_check_and_assertions(program_0_path)

    # Place include files in temp directory
    for path in include_paths:
        shutil.copy(path, os.path.join(temp_dir, os.path.basename(path)))

    index = 0
    if enable_mutations:
        index = generate_mutations(program_0_path, clang_tidy_path, meta_path, mutations)

    if enable_ml:
        index = generate_ml(program_0_path, apikey_path, meta_path, ml_count, ml_select, ml_interesting, ml_16k)

    # Add checks with annotations
    print_separator()
    params = _get_params_from_file(program_0_path)
    params = _fix_params(params)
    for i in range(index + 1):
        print(f"\r[{i}/{index}] Generating goblint checks...", end='')
        sys.stdout.flush()
        file_path = os.path.join(temp_dir, f"p_{i}.c")
        compiling = add_check(file_path, goblint_path, meta_path, params, i)
        if not compiling:
            print(f"\r{COLOR_YELLOW}[{i}/{index}] Program with mutation did not compile{COLOR_RESET}{SPACE}")
            continue
        file_path = os.path.join(temp_dir, f"p_{i}_check.c")
        # For the patched file generate NOFAIL / NOTINPRECISE annotations
        if i == 0:
            if enable_precision:
                add_check_annotations(file_path, 'NOTINPRECISE')
            else:
                add_check_annotations(file_path, 'NOFAIL')
        # For the inital file generate SUCCESS annotations
        if i != 0:
            add_check_annotations(file_path, 'SUCCESS')
    print(f"\r{COLOR_GREEN}Generating goblint checks [DONE]{SPACE}{COLOR_RESET}")


def _remove_goblint_check_and_assertions(program_0_path):
    with open(program_0_path, 'r') as f:
        lines = f.readlines()

    # Replace the lines containing the keywords with an empty statement
    keyword_list = ['assert(', '__goblint_check(', '__goblint_assert(']
    replaced_lines = [f'; // [REMOVED_CHECK] Removed assertions and checks from input program at line {i+1}\n' if any(keyword in line for keyword in keyword_list) else line for i, line in enumerate(lines)]

    with open(program_0_path, 'w') as f:
        f.writelines(replaced_lines)


def _fix_params(params):
    params_inital = params

    for regex in REGEX_PARAMETER_REMOVAL:
        params = re.sub(regex, '', params)
    
    if params_inital != params:
        print(f'{COLOR_YELLOW}[WARNING] Some parameters from the PARAM string in the input file (grey) were removed to avoid crashing the tester:{COLOR_RESET} {params} {COLOR_GREY}{params_inital}{COLOR_RESET}')

    # Always activate the analysis assert as it is needed for the update_suite ruby script to check the annotations
    params += ' --set ana.activated[+] assert'

    # Always use the top down solver as only for this the incremental analysis is implemented
    params += ' --set solver td3'
    
    return params


def _get_params_from_file(filename):
    param_pattern = re.compile(r"\s*//.*PARAM\s*:\s*(.*)")
    with open(filename, 'r') as f:
        for line in f:
            match = param_pattern.match(line)
            if match:
                params = match.group(1).strip()
                return params
    return ""


# ALTERNATIVE Transform __goblint_check to __my_check_annotation
def _preserve_goblint_check_annotations(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    transformed_content = re.sub(r'(__goblint_check\((.*?)\);) // (.*?)\n', r'__my_check_annotation(\2, "\3 was in the source program");\n', content)
    if transformed_content != content:
        transformed_content += '\n\nvoid __my_check_annotation(void* exp, const char* comment) {}\n'
        with open(file_path, 'w') as file:
            file.write(transformed_content)


def main():
    parser = argparse.ArgumentParser(description='Generate programs in the working directory')
    parser.add_argument('source_path', help='Path to the source program provided by the user')
    parser.add_argument('temp_dir', help='Path to the working directory')
    parser.add_argument('clang_tidy_path', help='Path to the modified clang-tidy executable')
    parser.add_argument('goblint_path', help='Path to the goblint executable')
    parser.add_argument('--apikey-path', help='Path to the API')
    parser.add_argument('--enable-mutations', action='store_true', help='Enable Mutations. When no mutation is selected all are activated.')
    parser.add_argument('--enable-ml', action='store_true', help='Enable ML')
    parser.add_argument('--enable-precision', action='store_true', help='Enable generation for precision tests')
    parser.add_argument('--ml-count', type=int, default=DEFAULT_ML_COUNT, help='Number of ML programs to generate')
    parser.add_argument('--ml-select', type=int, default=DEFAULT_ML_SELECT, help='Number of selected lines for ML')
    parser.add_argument('--ml-interesting', default="[]", help='Lines to randomly choose the start line for selection (Default are all lines)')
    parser.add_argument('--ml-16k', action='store_true', help='Use the 16k mode for ml')

    # Add mutation options
    add_mutation_options(parser)

    args = parser.parse_args()

    # At least one generator has to be enabled
    if not args.enable_mutations and not args.enable_ml:
        parser.error("At least one generator has to be enabled (--enable_mutations, --enable-ml)")

    # If all mutation options are false, set all to true
    mutations = get_mutations_from_args(args)
    non_str_attributes = [attr for attr in vars(mutations) if not attr.endswith('_s')]
    if all(getattr(mutations, attr) is False for attr in non_str_attributes):
        mutations = Mutations(True, True, True, True, True, True)

    # Check required parameters for optional features
    if args.enable_ml and not args.apikey_path:
        parser.error("--enable-ml requires --apikey-path")

    # Check ml interesting string
    if args.ml_interesting != "[]" and validate_interesting_lines(args.ml_interesting, None) is None:
        parser.error('Interesting lines invalid')

    generate_programs(args.source_path, args.temp_dir, args.clang_tidy_path, args.goblint_path, args.apikey_path,
                      mutations, args.enable_mutations, args.enable_ml, args.enable_precision, args.ml_count, args.ml_select,
                      args.ml_interesting, args.ml_16k, [])


if __name__ == '__main__':
    main()
