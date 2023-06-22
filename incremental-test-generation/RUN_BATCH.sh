#!/bin/bash

# Check if the script is run from the correct location
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
CURRENT_DIR=$(pwd)
if [ "$SCRIPT_DIR" != "$CURRENT_DIR" ]; then
  echo "Script is NOT run from its own directory! Please change the directory to the location of the script."
  exit -1
fi

color_grey="\033[90m"
color_red="\033[31m"
color_blue='\033[34m'
color_green='\033[32m'
color_yellow="\033[33m"
color_orange="\033[38;5;208m"
color_reset="\033[0m"
no_print=false

# Check for at least one argument
if [ $# -lt 1 ]; then
    printf "Usage: $0 <directory> [-y] [additional arguments...]\n"
    printf "<directory>: path to a directory with the .c files for the batch\n"
    printf "[--no-print]: Do not print the mutation generator output\n"
    printf "[additional arguments...]: Arguments passed to goblint to skip interactive cli.\n"
    printf "    -> Recommended: --enable-mutations --disable-precision --enable-running --disable-create-tests --enable-cfg --goblint-config {}\n"
    exit 1
fi

# Store directory and shift to get other arguments
dir=$1
shift

# Check if directory exists
if [ ! -d "$dir" ]; then
    printf "Directory $dir does not exist.\n"
    exit 1
fi

# Check for --no-print option
confirm=true
if [[ $1 == "--no-print" ]]; then
    no_print=true
    shift
fi

# Find .c files in subdirectories of the specified directory
files=$(find "$dir" -type f -name "*.c" | sort)
files_length=$(find "$dir" -type f -name "*.c" | wc -l)

# Iterate over the found files
index=0
for file in $files
do
    ((index=index+1))
    # Run the command with remaining arguments
    printf "${color_blue}[BATCH][${index}/${files_length}] Running file $file${color_reset}\n"
    if [ "$no_print" = true ]; then
        ./RUN.sh -i "$file" "$@" > /dev/null
    else
        ./RUN.sh -i "$file" "$@"
    fi

    # Check for different return values
    case $? in
        0)
            success_files+=("$file")
            ;;
        100)
            printf "${color_red}[BATCH] Test failed for file $file.\n"
            failed_files+=("$file")
            ;;
        101)
            printf "${color_red}[BATCH] Test failed (but only \"Expected *, but registered nothing\") for file $file.\n"
            failed_nothing_files+=("$file")
            ;;
        *)
            printf "${color_red}[BATCH] Exception during execution for file $file.\n"
            exception_files+=("$file")
            ;;
    esac
done

success_length=${#success_files[@]}
nothing_length=${#failed_nothing_files[@]}
failed_length=${#failed_files[@]}
exception_length=${#exception_files[@]}
printf "\n\n${color_green}[BATCH] Batch finished running $total_length input files \n\n"

# Print all success files
if [ ${#success_files[@]} -ne 0 ]; then
    printf "${color_green}The following $success_length files were run succesfully with all tests passing:\n"
    for file in "${success_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print all files for which the test failed (but only nothing)
if [ ${#failed_nothing_files[@]} -ne 0 ]; then
    printf "${color_orange}The following $nothing_length files failed the tests, but only \"Expected *, but registered nothing\":\n"
    for file in "${failed_nothing_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print all files for which the test failed
if [ ${#failed_files[@]} -ne 0 ]; then
    printf "${color_red}The following $failed_length files failed the tests:\n"
    for file in "${failed_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi


# Print all files for which an exception occurred during execution
if [ ${#exception_files[@]} -ne 0 ]; then
    printf "${color_red}The following $exception_length files experienced an exception during execution:\n"
    for file in "${exception_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print summary
printf "\n[BATCH] Batch finished! Here is the summary:\n"
printf "Total number of files: $files_length\n"
printf "Number of successfully run files: $success_length\n"
printf "Number of files that failed the tests, but only \"Expected *, but registered nothing\": $nothing_length\n"
printf "Number of files that failed the tests: $failed_length\n"
printf "Number of files that experienced an exception during execution: $exception_length\n"