# Create the clang tidy checks
Read [this](clang-mutations/README.md) for creating the clang tidy checks needed to generate mutations.

# Sample files
In `samle-files/` you find some examples you can use as input to get started.

# Mutation Generator
Run `./RUN.sh` to start the Command Line Interface. With `-h` you can see the command line options for skipping the interactive user input.

# Run on regression tests
Run `./RUN_BATCH <directory> [additional arguments...]` for running all c files in the directory. The additional arguments are passed to goblint to skip the interactive cli (Recommended: `--enable-mutations --disable-precision --enable-running --disable-create-tests --enable-cfg --goblint-config {}`). When there are arguments defined in the file by the `PARAM` keyword they are recognized and passed to the incremental tester. When running on the regression test `28-race_reach` you should add this include `--include YOUR_PATH_TO_GOBLINT/analyzer/tests/regression/28-race_reach/racemacros.h`. You can also ignore files using a `.txt` file with all the paths seperated by a new line. It is recommended to ignore the files `--ignore sample-files/batch-ignore-files/regression-parsing-error.txt` and `--ignore sample-files/batch-ignore-files/regression-exceptions.txt`. Use `--no-print` to print only the status updates on input level. This results in the command:
```
./RUN_BATCH.sh YOUR_PATH_TO_GOBLINT/analyzer/tests/regression/ --ignore sample-files/batch-ignore-files/regression-parsing-error.txt --ignore sample-files/batch-ignore-files/regression-exceptions.txt -m -dp -er -dt -ec -c {} --include YOUR_PATH_TO_GOBLINT/analyzer/tests/regression/28-race_reach/racemacros.h
```