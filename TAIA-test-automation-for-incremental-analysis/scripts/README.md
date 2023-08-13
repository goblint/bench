This directory contains all the files required to generate incremental tests from the provided input file. Each script is briefly described below.

# Main Script
The script [run_cli.py](./run_cli.py) processes the options from the terminal and asks the user interactively for the inputs if the information was not yet provided by the terminal options.

# Program Generator
The script  [generate_programs.py](./generate_programs.py) generates a new `temp` directory. Depending on the passed options the different generator scripts are called to create mutated files (`p_42.c`). It then adds the `___goblint_check()` function along with corresponding comments by calling `add_check.py` and `add_check_annotations.py`.

# Goblint Check Generator
The script  [add_check.py](./add_check.py) calls Goblint to add the `___goblint_check()` function to the C files in the `temp_dir` (`p_42_check.c`).

# Goblint Check Annotator
The script  [add_check_annotations.py](./add_check_annotations.py) adds annotations like `// NOFAIL`, `// SUCCESS` or `// NOTINPRECISE` to all the Goblint checks (`___goblint_check()`) in the `temp` directory (`p_42_check_nofail.c` / `p_42_check_success.c`), which have no annotation yet.

# Test Case Generator
The script  [generate_tests.py](./generate_tests.py) generates the test files for each mutation. A test consists of an initial `.c` file, a `.patch` file containing the changes from the mutation, and a `.json` file with the Goblint options. Normally, a patch is the difference between the initial program provided by the user (`p_0_check_success.c`) and the mutated program (`p_42_check_nofail.c`). For precision tests, the mutated program is only annotated with notinprecise Goblint checks (`p_42_check_notinprecise.c`).

# Test Case Executor
The script  [run_tests.py](./run_tests.py) copies the test directory into the incremental tester directory and executes the `update_suite.rb` script.

# Clang-Tidy Muation Generator
The script  [generate_clang_mutations.py](./generate_clang_mutations.py) uses the custom Clang-Tidy Checks to generate mutations on a given program. More information about the mutation operators can be found in [this file](../clang-mutations/MUTATIONS.md).

# AI Mutation Generator
The script  [generate_ai_mutations.py](./generate_ai_mutations.py) uses gpt-3.5-turbo with the api from openai. It generates mutations on a program by asking it how a previous version of the code could have looked like before some typical code changes were done by developers.
<br><br>
You need to pass a `apikey.yaml` file with the following format:
```
organisation: (Found at https://platform.openai.com/account/org-settings)
api-key: (Found at https://platform.openai.com/account/api-keys)
```
You can specify `num_selected_lines` to tell the script how many consecutive lines should be sent together with the prompt. To many lines could lead to an error because of a too large request. To few lines may result in a bad mutation because of less context.
<br><br>
You can specify `interesting_lines` to guide the selection of the lines send with the request. The selection process works by selecting a random start line out of a set of lines. From the start line on the `num_selected_lines` are selected. When `interesting_lines` equals to `[]` all the lines (`[1, 2, 3, ..., MAX_LINE - NUM_SELECTED_LINES]`) are interesting lines. Alternatively you can pass specific lines (`[1, 42, 99]`). Note that when a line is larger then `(MAX_LINE - NUM_SELECTED_LINES)` it will be set to this value.

# Utility Script
The script  [util.py](./util.py) contains useful constants and functions for all programs. This enables the developer to access and change the behaviour fast and easily.

# Meta Data Manager
The script [meta.py](./meta.py) contains functions for the collection of metadata.

# Statisitics Generator
The script [stats.py](./stats.py) collects metadata and calculates statistics, which will be printed to the terminal.