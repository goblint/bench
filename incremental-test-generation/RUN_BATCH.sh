#!/bin/bash

# Check if the script is run from the correct location
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
CURRENT_DIR=$(pwd)
if [ "$SCRIPT_DIR" != "$CURRENT_DIR" ]; then
  echo "Script is NOT run from its own directory! Please change the directory to the location of the script."
  exit 1
fi

# Check if realpath is available
if ! command -v realpath &> /dev/null; then
    echo "realpath command is not available. Please install it."
    exit 1
fi

color_grey="\033[90m"
color_red="\033[31m"
color_blue='\033[34m'
color_green='\033[32m'
color_yellow="\033[33m"
color_orange="\033[38;5;208m"
color_reset="\033[0m"

no_print=false
ignore_files=()

# Check for at least one argument
if [ $# -lt 1 ]; then
    printf "Usage: $0 <directory> [--no-print] [--statistics] [--ignore <file_path>]* [additional arguments...]\n"
    printf "Please order the arguments and options as stated above"
    printf "<directory>: path to a directory with the .c files for the batch\n"
    printf "[--no-print]: Do not print the mutation generator output\n"
    printf "[--ignore <file_path>]* : paths to files containing paths to be ignored, separated by newlines\n"
    printf "[additional arguments...]: Arguments passed to Goblint to skip interactive cli.\n"
    printf "    -> Recommended: --enable-clang --disable-precision --enable-running --disable-create-tests --enable-cfg --Goblint-config {}\n"
    printf "       or in short: --default\n"
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

# Check for --statistics option
if [[ $1 == "--statistics" ]]; then
    statistics=true
    shift
fi

# Check for --ignore options and store ignore files in an array
while [[ $1 == "--ignore" ]]; do
    ignore_files+=($2)
    shift 2
done

# Get statistics path
timestamp=$(date "+%Y-%m-%d-%H-%M-%S")
statistics_path=./out/stats-${timestamp}.yaml

# Normalize paths in ignore files
ignore_patterns=()
for ignore_file in "${ignore_files[@]}"; do
    while IFS= read -r line; do
        ignore_patterns+=("$(realpath "$line" 2>/dev/null)")
    done < "$ignore_file"
done

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
    for pattern in "${ignore_patterns[@]}"; do
        if [[ "$file_realpath" == $pattern ]]; then
            printf "${color_grey}[BATCH][${index}/${files_length}] Ignoring file $file${color_reset}\n"
            ignored_files+=("$file")
            continue 2
        fi
    done

    # Run the command with remaining arguments
    printf "${color_blue}[BATCH][${index}/${files_length}] Running file $file${color_reset}"
    if [ "$no_print" = true ]; then
        ./RUN.sh -i "$file" "$@" > /dev/null
    else
        printf "\n"
        ./RUN.sh -i "$file" "$@"
    fi

    # Check for different return values
    case $? in
        0)
            printf "$\r${color_green}[BATCH][${index}/${files_length}] Test succeeded for file $file"
            success_files+=("$file")
            ;;
        100)
            printf "$\r${color_orange}[BATCH][${index}/${files_length}] Test failed for file $file"
            failed_files+=("$file")
            ;;
        *)
            printf "$\r${color_red}[BATCH][${index}/${files_length}] Exception during execution for file $file"
            exception_files+=("$file")
            ;;
    esac
    printf "${color_reset}\n"

    # Append the meta file to the statistics
    printf "${color_grey}Update statistics...${color_reset}"
    if [ "$statistics" = true ]; then
        python3 ./scripts/stats.py $statistics_path --append ./temp/meta.yaml
    fi
    printf "\r"
    
done

ignored_length=${#ignored_files[@]}
success_length=${#success_files[@]}
failed_length=${#failed_files[@]}
exception_length=${#exception_files[@]}
printf "\n\n${color_blue}[BATCH] Batch finished running $files_length input files${color_reset}\n\n"

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
    printf "${color_green}The following $success_length files were run successfully with all tests passing:\n"
    for file in "${success_files[@]}"; do
        printf "$file\n"
    done
    printf "${color_reset}\n"
fi

# Print all files for which the test failed
if [ ${#failed_files[@]} -ne 0 ]; then
    printf "${color_orange}The following $failed_length files failed the tests:\n"
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
printf "\n[BATCH] Summary:\n"
printf "Total number of input files: $files_length\n"

if [ "$ignored_length" -eq 0 ]; then color=${color_grey}; else color=${color_yellow}; fi
printf "${color}Number of ignored files: $ignored_length\n"

if [ "$success_length" -eq 0 ]; then color=${color_grey}; else color=${color_green}; fi
printf "${color}Number of successfully executed files: $success_length\n"

if [ "$failed_length" -eq 0 ]; then color=${color_grey}; else color=${color_orange}; fi
printf "${color}Number of files that failed the tests: $failed_length\n"

if [ "$exception_length" -eq 0 ]; then color=${color_grey}; else color=${color_red}; fi
printf "${color}Number of files that experienced an exception during execution: $exception_length\n"

printf $color_reset

# Print statistics
if [ "$statistics" = true ]; then
    python3 ./scripts/stats.py $statistics_path
fi
