#!/bin/bash

color_red="\033[31m"
color_blue='\033[34m'
color_green='\033[32m'
color_yellow="\033[33m"
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

# Iterate over .c files in the directory
for file in "$dir"/*.c
do
    # Check if file contains "FAIL", "UNKNOWN", or "NOWARN"
    if grep -q "FAIL\|UNKNOWN\|NOWARN" "$file"; then
        printf "${color_yellow}[BATCH] Skipping file $file due to contained keywords (FAIL, UNKNOWN, NOWARN)${color_reset}\n"
        skipped_files+=("$file")
    else
        # Run the command with remaining arguments
        printf "${color_blue}[BATCH] Running file $file${color_reset}\n"
        ./RUN.sh -i "$file" "$@"

        # If RUN.sh returned != 0, ask for pressing enter to continue
        if [ $? -ne 0 ]; then
            printf "${color_red}[BATCH] Run for file $file returned non-zero value. Maybe a test failed.\n"
            if $confirm ; then
                printf "${color_blue}[BATCH] Press enter to continue...${color_reset}"
                read _
            fi
            error_files+=("$file")
        else
            success_files+=("$file")
        fi
    fi
done

printf "${color_green}[BATCH] Batch finished\n"

# Print all success files
if [ ${#success_files[@]} -ne 0 ]; then
    printf "${color_green}The following ${#success_files[@]} files were run succesfully with all tests passing:\n"
    for file in "${success_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print all skipped files
if [ ${#skipped_files[@]} -ne 0 ]; then
    printf "${color_yellow}The following ${#skipped_files[@]} files were skipped due to contained keywords (FAIL, UNKNOWN, NOWARN):\n"
    for file in "${skipped_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print all error files
if [ ${#error_files[@]} -ne 0 ]; then
    printf "${color_red}The following ${#error_files[@]} files produced a return code unequeal zero (Maybe some tests failed):\n"
    for file in "${error_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi
