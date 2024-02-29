#!/bin/bash

# Check if the script is run from the correct location
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
CURRENT_DIR=$(pwd)
if [ "$SCRIPT_DIR" != "$CURRENT_DIR" ]; then
  echo "Script is NOT run from its own directory! Please change the directory to the location of the script."
  exit 1
fi

# Check for python imports
modules=("argparse" "datetime" "glob" "threading" "re" "json" "os" "subprocess" "sys" "yaml" "ast" "random" "time" "concurrent.futures" "multiprocessing" "openai" "questionary" "pathlib" "enum" "shutil")
for module in "${modules[@]}"
do
    python3 -c "import $module" &> /dev/null
    if [ $? -ne 0 ]; then
        echo "Python module '$module' is not installed."
        exit 1
    fi
done

# Check for other programs needed
ruby -h &> /dev/null
if [ $? -ne 0 ]; then
  echo "ruby is not installed."
  exit 1
fi

gcc --help &> /dev/null
if [ $? -ne 0 ]; then
  echo "gcc is not installed."
  exit 1
fi

curl --help &> /dev/null
if [ $? -ne 0 ]; then
  echo "curl is not installed."
  exit 1
fi

# Run cli
python3 ./scripts/run_cli.py "$@"