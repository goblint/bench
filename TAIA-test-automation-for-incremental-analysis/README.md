# Install Clang-Tidy with the mutation operators
Read [this](clang-mutations/README.md) for installing Clang-Tidy with the checks needed to generate mutations.

# The clang tidy mutation operators
Read [this](clang-mutations/MUTATIONS.md) to find out more about the different types of mutation operators.

# Sample files
In `samle-files/` you find some examples you can use as input to get started.

# Test Automation for Incremental Analysis (TAIA)
Run `./RUN.sh` to start the Command Line Interface. With `./RUN.sh -h` you can see the command line options.

# Run on regression tests
Default command for running on the regression tests:
`
./RUN_BATCH.sh YOUR_PATH_TO_GOBLINT/analyzer/tests/regression/ --default --no-print --statistics --ignore sample-files/ignore-files/regression-parsing-error.ignore --ignore sample-files/ignore-files/regression-exceptions.ignore --ignore sample-files/ignore-files/regression-gcc-error-input.ignore --include YOUR_PATH_TO_GOBLINT/analyzer/tests/regression/28-race_reach/racemacros.h
`

Run `./RUN_BATCH <directory> [additional arguments...]` for running all c files in the directory. For detailed information about the arguments run `./RUN_BATCH` without any arguments. The additional arguments are passed to Goblint to skip the interactive cli (Recommended: `--enable-clang --disable-precision --enable-running --disable-create-tests --enable-cfg --goblint-config {}` or in short `--default`). When there are arguments defined in the file by the `PARAM` keyword they are recognized and passed to the incremental tester. When running on the regression test `28-race_reach` you should add this include `--include YOUR_PATH_TO_GOBLINT/analyzer/tests/regression/28-race_reach/racemacros.h`. You can also ignore files using a `.ignore` file with all the paths seperated by a new line. It is recommended to ignore the files `--ignore sample-files/ignore-files/regression-parsing-error.ignore`, `--ignore sample-files/ignore-files/regression-exceptions.ignore` and `--ignore sample-files/ignore-files/regression-gcc-error-input.ignore`. Use `--no-print` to print only the status updates on input level. Use `--statistics` to collect the metadata of each run and calculate the statistics (decreases performance).

# Reprint the statistics
Run `python3 scripts/stats.py stats.yaml` to reprint the statistics collected in the yaml file.

# Implementation
To find out more about the implementation check out the `./scripts` directory and its [readme](./scripts/README.md) file.

# Thesis Automatic Generation of Test Cases for Incremental Static Analysis
The thesis about "Automatic Generation of Test Cases for Incremental Static Analysis" that resulted in the implementation of TAIA can be found [here](./Thesis-Automatic-Generation-of-Test-Cases-for-Incremental-Static-Analysis.pdf).