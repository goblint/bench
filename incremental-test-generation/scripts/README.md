# Scripts
This directory contains all the utility files required to generate incremental tests from the generated mutated files. Each script is briefly described below, and they are ordered according to their typical usage. Please use the `meta.yaml` files from the previous script calls.

# generate_programs.py
This script generates an empty `meta.yaml` file and, depending on the passed options, calls the different generator scripts to create mutated files in the `temp_dir` (`p_42.c`). It then adds the `___goblint_check()` function along with corresponding comments by calling `add_check.py` and `add_check_comments.py`.

# add_check.py
This script calls Goblint to add the `___goblint_check()` function to the C files in the `temp_dir` (`p_42_check.c`).

# add_check_comments.py
This script adds the corresponding `//UNKNOWN //SUCCESS` or `//SUCCESS` comments to all the Goblint checks (`___goblint_check()`) in the `temp_dir` (`p_42_check_unknown.c` / `p_42_check_success.c`).

# generate_tests.py
This script generates the test files for each mutation. A test consists of a source `.c` file, a `.patch` file containing the changes from the mutation, and a `.json` file with the Goblint options. Normally, a patch is the difference between the original program provided by the user (`p_0_check_success.c`) and the mutated program (`p_42_check_unknown.c`). For precision tests, the mutated program is only annotated with success Goblint checks (`p_42_check_success.c`). For mutations generated by a Git project, the patch is formed from the previous file to the current file.

# generate_mutations.py
This script uses the custom clang-tidy checks to generate mutations on a given program. Information's about the mutations are written to the `meta.yaml` file.
<br><br>
More information about the mutations can be found in this file: [Mutations](../clang-mutations/MUTATIONS.md)

# generate_ml.py
This script uses gpt-3.5-turbo with the api from openai. It generates mutations on a program by asking it how a previous version of the code could have looked like before some typical code changes were done by developers. Information about the mutations are written to the `meta.yaml` file.
<br><br>
You need to pass a `apikey.yaml` file with the following format:
```
organisation: (Found at https://platform.openai.com/account/org-settings)
api-key: (Found at https://platform.openai.com/account/api-keys)
```
You can specify `num_selected_lines` to tell the script how many consecutive lines should be sent together with the prompt. To many lines could lead to an error because of a too large request. To few lines may result in a bad mutation because of less context.
<br><br>
You can specify `interesting_lines` to guide the selection of the lines send with the request. The selection process works by selecting a random start line out of a set of lines. From the start line on the `num_selected_lines` are selected. When `interesting_lines` equals to `[]` all the lines (`[1, 2, 3, ..., MAX_LINE - NUM_SELECTED_LINES]`) are interesting lines. Alternatively you can pass specific lines (`[1, 42, 99]`). Note that when a line is larger then `(MAX_LINE - NUM_SELECTED_LINES)` it will be set to this value.

# generate_git.py
This script generates from a git repository per commit a cil file representing the whole project in a single c file. The differences between the commits are used as mutations. For passing a repository you need to specify a shell script containing all the needed information, and optionally you can give commands that should be executed before and after the default build commands (`cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON` / `bear -- make`).
<br><br>
You can find the template for the shell script with the information in the file `generate_git_build_USER_INFO_TEMPLATE.sh`:
```
#!/bin/bash

##############################################################
####################### USER VARIABLES #######################
##############################################################
# Variables
git_url=""          #e.g.: https://github.com/madler/zlib.git
use_cmake=true             # Choose either cmake or make
use_make=false             # Choose either cmake or make
path_to_build=""           #e.g.: "." (Relative path in repo)

# Functions before and after build
pre_build_commands() {
  :                        #e.g.: ./configure
}

post_build_commands() {
  :
}
##############################################################
####################### USER VARIABLES #######################
##############################################################

# Export variables so they can be used in the main script
export git_url
export use_cmake
export use_make
export path_to_build
export pre_build_commands
export post_build_commands
```

The script `generate_git_build.sh` interacts with these user shell scripts and can clone the repositories, build the repositories and provide the build path.
<br><br>
For not analyzing all the commits you can specify a start and end commit hash.