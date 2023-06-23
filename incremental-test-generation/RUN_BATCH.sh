#!/bin/bash

# Check if the script is run from the correct location
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
CURRENT_DIR=$(pwd)
if [ "$SCRIPT_DIR" != "$CURRENT_DIR" ]; then
  echo "Script is NOT run from its own directory! Please change the directory to the location of the script."
  exit -1
fi

# Check if realpath is available
if ! command -v realpath &> /dev/null; then
    echo "realpath command is not available. Please install it."
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
ignore_file=""

# Check for at least one argument
if [ $# -lt 1 ]; then
    printf "Usage: $0 <directory> [--no-print] [--ignore <file_path>] [additional arguments...]\n"
    printf "Please order the arguments and options as stated above"
    printf "<directory>: path to a directory with the .c files for the batch\n"
    printf "[--no-print]: Do not print the mutation generator output\n"
    printf "[--ignore <file_path>] : path to file containing paths to be ignored, separated by newlines\n"
    printf "[additional arguments...]: Arguments passed to goblint to skip interactive cli.\n"
    printf "    -> Recommended: --enable-mutations --disable-precision --enable-running --disable-create-tests --enable-cfg --goblint-config {}\n"
    printf "       or in short: -m -dp -er -dt -ec -c {}\n"
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
if [[ $1 == "--no-print" ]]; then
    no_print=true
    shift
fi

# Check for --ignore option
if [[ $1 == "--ignore" ]]; then
    ignore_file=$2
    shift 2
fi

# Normalize paths in ignore file
if [ -n "$ignore_file" ]; then
    ignore_list=$(
        while IFS= read -r line; do
            realpath "$line" 2>/dev/null
        done < "$ignore_file"
    )
fi

# Find .c files in subdirectories of the specified directory
files=$(find "$dir" -type f -name "*.c" | sort)
files_length=$(find "$dir" -type f -name "*.c" | wc -l)

# Iterate over the found files
index=0
for file in $files
do
    ((index=index+1))

    # Check if the file should be ignored
    file_realpath=$(realpath "$file")
    if [[ $ignore_list =~ $file_realpath ]]; then
        printf "${color_yellow}[BATCH][${index}/${files_length}] Ignoring file $file${color_reset}\n"
        ignored_files+=("$file")
        continue
    fi

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
            printf "${color_red}[BATCH] Test failed for file $file\n"
            failed_files+=("$file")
            ;;
        *)
            printf "${color_red}[BATCH] Exception during execution for file $file\n"
            exception_files+=("$file")
            ;;
    esac
done

ignored_length=${#ignored_files[@]}
skipped_length=${#skipped_files[@]}
success_length=${#success_files[@]}
failed_length=${#failed_files[@]}
exception_length=${#exception_files[@]}
printf "\n\n${color_green}[BATCH] Batch finished running $files_length input files${color_reset}\n\n"

# Print all ignored files
if [ ${#ignored_files[@]} -ne 0 ]; then
    printf "${color_yellow}The following $ignored_length files were ignored:\n"
    for file in "${ignored_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print all success files
if [ ${#success_files[@]} -ne 0 ]; then
    printf "${color_green}The following $success_length files were run succesfully with all tests passing:\n"
    for file in "${success_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print all files for which the test failed
if [ ${#failed_files[@]} -ne 0 ]; then
    printf "${color_orange}The following $failed_length files failed the tests:\n"
    for file in "${failed_files[@]}"; do
        printf "$file"
        # Check if the first line of the file contains "SKIP"
        first_line=$(head -n 1 "$file")
        if [[ $first_line == *"SKIP"* ]]; then
            printf "${color_yellow} (Contained SKIP keyword in first line)${color_orange}\n"
        else
            printf "\n"
        fi
    done
    printf "${color_reset}\n"
fi


# Print all files for which an exception occurred during execution
if [ ${#exception_files[@]} -ne 0 ]; then
    printf "${color_red}The following $exception_length files experienced an exception during execution:\n"
    for file in "${exception_files[@]}"; do
        printf "$file"
        # Check if the first line of the file contains "SKIP"
        first_line=$(head -n 1 "$file")
        if [[ $first_line == *"SKIP"* ]]; then
            printf "${color_yellow} (Contained SKIP keyword in first line)${color_orange}\n"
        else
            printf "\n"
        fi
    done
    printf "${color_reset}\n"
fi

# Print summary
printf "\n[BATCH] Summary:\n"
printf "Total number of executed files: $files_length\n"

if [ "$ignored_length" -eq 0 ]; then color=${color_grey}; else color=${color_yellow}; fi
printf "${color}Number of ignored files: $ignored_length\n"

if [ "$success_length" -eq 0 ]; then color=${color_grey}; else color=${color_green}; fi
printf "${color}Number of successfully executed files: $success_length\n"

if [ "$skipped_length" -eq 0 ]; then color=${color_grey}; else color=${color_blue}; fi
printf "${color}Number of skipped files: $skipped_length\n"

if [ "$failed_length" -eq 0 ]; then color=${color_grey}; else color=${color_orange}; fi
printf "${color}Number of files that failed the tests: $failed_length\n"

if [ "$exception_length" -eq 0 ]; then color=${color_grey}; else color=${color_red}; fi
printf "${color}Number of files that experienced an exception during execution: $exception_length\n"