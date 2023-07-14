#!/bin/bash

# Check if the script is run from the correct location
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
CURRENT_DIR=$(pwd)
if [ "$SCRIPT_DIR" != "$CURRENT_DIR" ]; then
  echo "Script is NOT run from its own directory! Please change the directory to the location of the script."
  exit 1
fi

# Check for python imports
modules=("argparse" "datetime" "glob" "threading" "re" "json" "os" "subprocess" "sys" "yaml" "pydriller" "ast" "random" "time" "concurrent.futures" "multiprocessing" "openai" "questionary" "pathlib" "enum" "shutil")
for module in "${modules[@]}"
do
    python3 -c "import $module" &> /dev/null
    if [ $? -ne 0 ]; then
        echo "Python module '$module' is not installed."
        exit 1
    fi
done

# Run cli
python3 ./scripts/run_cli.py "$@"