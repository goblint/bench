from add_check import add_check
from add_check_annotations import add_check_annotations
from generate_git import *
from generate_ml import *
from generate_mutations import *


# generates programs in the temp_dir
def generate_programs(source_path, temp_dir, clang_tidy_path, goblint_path, apikey_path, mutations, enable_mutations,
                      enable_ml, enable_git, enable_precision, ml_count, ml_select, ml_interesting, ml_16k, git_start, git_end, include_paths):
    # Clean working directory
    if os.path.isdir(temp_dir):
        shutil.rmtree(temp_dir)
    os.makedirs(temp_dir)
    # Create Meta file
    meta_path = os.path.join(temp_dir, META_FILENAME)
    with open(meta_path, 'w') as outfile:
        yaml.dump({'n': 0, 'p_0': {META_TYPE: GenerateType.SOURCE.value}}, outfile)
    # Copy the source program into the temp dir
    program_path = os.path.join(temp_dir, 'p.c' if not enable_git else 'p.sh')
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

    if enable_git:
        index = generate_git(goblint_path, temp_dir, meta_path, program_0_path, git_start, git_end)

    # Add checks with annotations
    print_seperator()
    if enable_git:
        print('Generating goblint checks. This may take a while...')
    params = get_params_from_file(program_0_path)
    params = fix_params(params)
    for i in range(index + 1):
        print(f"\r[{i}/{index}] Generating goblint checks...", end='')
        sys.stdout.flush()
        file_path = os.path.join(temp_dir, f"p_{i}.c")
        compiling = add_check(file_path, goblint_path, meta_path, params, i, enable_git)
        if not compiling:
            continue
        file_path = os.path.join(temp_dir, f"p_{i}_check.c")
        # For the patched file generate NOFAIL annotations
        if i == 0 or enable_git:
            add_check_annotations(file_path, nofail_instead_of_success=True)
        # For the source file generate SUCCESS annotations
        if i != 0 or enable_precision or enable_git:
            add_check_annotations(file_path, nofail_instead_of_success=False)
    print(f"\r{COLOR_GREEN}Generating goblint checks [DONE]{SPACE}{COLOR_RESET}")

    # Check how many and which files were not compiling
    print_seperator()
    print("Check if the files compiled...", end='')
    with open(meta_path, 'r') as file:
        yaml_data = yaml.safe_load(file)
    failed_count = 0
    failed_compilation_keys = []
    for key, value in yaml_data.items():
        if isinstance(value, dict) and META_COMPILING in value and value[META_COMPILING] is False:
            failed_count += 1
            failed_compilation_keys.append(key)
    if failed_count == 0:
        print(f"\r{COLOR_GREEN}All files compiled successfully{COLOR_RESET}")
    else:
        print(f"\r{COLOR_RED}There were {failed_count} files not compiling (stderr written to {temp_dir}/meta.yaml):{COLOR_RESET} {failed_compilation_keys}")


# Remove all goblint checks and assertions
def _remove_goblint_check_and_assertions(program_0_path):
    with open(program_0_path, 'r') as f:
        lines = f.readlines()

    # Replace the lines containing the keywords with '; // <old line>'
    replaced_lines = ['; // ' + line if any(keyword in line for keyword in ['assert(', '__goblint_check(', '__goblint_assert(']) else line for line in lines]

    with open(program_0_path, 'w') as f:
        f.writelines(replaced_lines)


# Transform __goblint_check to __my_check_annotation
#TODO Extend to goblint_assert() and assert()
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
    parser.add_argument('source_path', help='Path to the original program or git sh file provided by the user')
    parser.add_argument('temp_dir', help='Path to the working directory')
    parser.add_argument('clang_tidy_path', help='Path to the modified clang-tidy executable')
    parser.add_argument('goblint_path', help='Path to the goblint executable')
    parser.add_argument('--apikey-path', help='Path to the API')
    parser.add_argument('--enable-mutations', action='store_true', help='Enable Mutations. When no mutation is selected all are activated.')
    parser.add_argument('--enable-ml', action='store_true', help='Enable ML')
    parser.add_argument('--enable-git', action='store_true', help='Enable Git')
    parser.add_argument('--enable-precision', action='store_true', help='Enable generation for precision tests')
    parser.add_argument('--ml-count', type=int, default=DEFAULT_ML_COUNT, help='Number of ML programs to generate')
    parser.add_argument('--ml-select', type=int, default=DEFAULT_ML_SELECT, help='Number of selected lines for ML')
    parser.add_argument('--ml-interesting', default="[]", help='Lines to randomly choose the start line for selection (Default are all lines)')
    parser.add_argument('--ml-16k', action='store_true', help='Use the 16k mode for ml')
    parser.add_argument('--git-start', help='The starting commit hash for git generation')
    parser.add_argument('--git-end', help='The ending commit hash for git generation')

    # Add mutation options
    add_mutation_options(parser)

    args = parser.parse_args()

    # At least one generator has to be enabled
    if not args.enable_mutations and not args.enable_ml and not args.enable_git:
        parser.error("At least one generator has to be enabled (--enable_mutations, --enable-ml, --enable-git)")

    # If using git, only git can be used
    if args.enable_git and (args.enable_ml or args.enable_mutations):
        parser.error("--enable-git cannot be used with --enable-ml or --enable-mutations")

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
        sys.exit(RETURN_ERROR)

    # Check git commit hashes
    git_start_commit = args.git_start
    git_end_commit = args.git_end
    if (git_start_commit is None and git_end_commit is not None) or (git_start_commit is not None and git_end_commit is None):
        parser.error('[ERROR] Give a git start commit hash AND a end commit hash')

    generate_programs(args.source_path, args.temp_dir, args.clang_tidy_path, args.goblint_path, args.apikey_path,
                      mutations, args.enable_mutations, args.enable_ml, args.enable_git, args.enable_precision, args.ml_count, args.ml_select,
                      args.ml_interesting, args.ml_16k, args.git_start, args.git_end, [])


if __name__ == '__main__':
    main()
