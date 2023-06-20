# Create the clang tidy checks
Read [this](clang-mutations/README.md) for creating the clang tidy checks needed to generate mutations.

# Sample files
In `samle-files/` you find some examples you can use as input to get started.

# Mutation Generator
Run `./RUN.sh` to start the Command Line Interface. With `-h` you can see the command line options for skipping the interactive user input.

# Run on regression tests
Run `./RUN_BATCH <directory> [-y] [additional arguments...]` for running all c files in the directory. Use `-y` to continue at failed tests automatically without asking the user. The additional arguments are passed to goblint to skip the interactive cli (Recommended: `--enable-mutations --disable-precision --enable-running --disable-create-tests --enable-cfg --goblint-config {}`). All files containing one of the keywords `FAIL, UNKNOWN, WARN, RACE, DEADLOCK, TODO, SKIP` is skipped as the existing goblint checks can not be represented as the comments for the goblint checks get lost during the mutation generation. When there are arguments defined in the file by the `PARAM` keyword they are recognized and passed to the incremental tester.