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
confirm=true

# Check for at least one argument
if [ $# -lt 1 ]; then
    printf "Usage: $0 <directory> [-y] [additional arguments...]\n"
    printf "<directory>: path to a directory with the .c files for the batch\n"
    printf "[-y]: continue at failed tests automatically without asking the user\n"
    printf "[additional arguments...]: Arguments passed to goblint to skip interactive cli. Recommended: -m -dp -er -dt -ec -c {}\n"
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

# Check for -y option
confirm=true
if [[ $1 == "-y" ]]; then
    confirm=false
    shift
fi

# Find .c files in subdirectories of the specified directory
files=$(find "$dir" -type f -name "*.c")

# Iterate over the found files
for file in $files
do
    # Check if file contains keywords
    if grep -q "FAIL\|UNKNOWN\|WARN\|RACE\|DEADLOCK" "$file"; then
        printf "${color_yellow}[BATCH] Skipping file $file due to contained keywords (FAIL, UNKNOWN, WARN, RACE, DEADLOCK)${color_reset}\n"
        skipped_files+=("$file")
    else
        # Run the command with remaining arguments
        printf "${color_blue}[BATCH] Running file $file${color_reset}\n"
        ./RUN.sh -i "$file" "$@"

        # Check for different return values
        case $? in
            0)
                success_files+=("$file")
                ;;
            100)
                printf "${color_red}[BATCH] Test failed for file $file.\n"
                failed_files+=("$file")
                if $confirm ; then
                    printf "${color_blue}[BATCH] Press enter to continue...${color_reset}"
                    read _
                fi
                ;;
            101)
                printf "${color_red}[BATCH] Test failed (but only \"Expected *, but registered nothing\") for file $file.\n"
                failed_nothing_files+=("$file")
                if $confirm ; then
                    printf "${color_blue}[BATCH] Press enter to continue...${color_reset}"
                    read _
                fi
                ;;
            *)
                printf "${color_red}[BATCH] Exception during execution for file $file.\n"
                exception_files+=("$file")
                if $confirm ; then
                    printf "${color_blue}[BATCH] Press enter to continue...${color_reset}"
                    read _
                fi
                ;;
        esac
    fi
done

success_length=${#success_files[@]}
skipped_length=${#skipped_files[@]}
error_length=${#error_files[@]}
total_length=$((success_length + skipped_length + error_length))
printf "\n\n${color_green}[BATCH] Batch finished running $total_length input files \n\n"

# Print all skipped files
if [ ${#skipped_files[@]} -ne 0 ]; then
    printf "${color_grey}The following $skipped_length files were skipped due to contained keywords (FAIL, UNKNOWN, WARN, RACE, DEADLOCK):\n"
    for file in "${skipped_files[@]}"; do
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

# Print all files for which the test failed (but only nothing)
if [ ${#failed_nothing_files[@]} -ne 0 ]; then
    printf "${color_orange}The following files failed the tests, but only \"Expected *, but registered nothing\":\n"
    for file in "${failed_nothing_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print all files for which the test failed
if [ ${#failed_files[@]} -ne 0 ]; then
    printf "${color_red}The following files failed the tests:\n"
    for file in "${failed_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi


# Print all files for which an exception occurred during execution
if [ ${#exception_files[@]} -ne 0 ]; then
    printf "${color_red}The following files experienced an exception during execution:\n"
    for file in "${exception_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi