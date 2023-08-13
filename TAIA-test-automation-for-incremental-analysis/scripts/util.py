from enum import Enum
import os
import re
import shutil
import sys


#######################################################################
######## Classes for clang tidy checks (change for new checks) ########
class Operators:
    def __init__(self, rfb=False, uoi=False, ror=False, cr=False, rt=False, lcr=False, ris=False):
        self.rfb = rfb
        self.rfb_s = "remove-function-body"
        self.uoi = uoi
        self.uoi_s = "unary-operator-inversion"
        self.ror = ror
        self.ror_s = "relational-operator-replacement"
        self.cr = cr
        self.cr_s = "constant-replacement"
        self.rt = rt
        self.rt_s = "remove-thread"
        self.lcr = lcr
        self.lcr_s = "logical-connector-replacement"
        self.ris = ris
        self.ris_s = "remove-if-statement"

######## Classes for clang tidy checks (change for new checks) ########
#######################################################################


#######################################################################
######################## Enums for mutators ###########################
class GenerateType(Enum):
    INPUT = 'INPUT'
    CLANG = 'CLANG'
    AI = 'OPENAI'
######################## Enums for mutators ###########################
#######################################################################


##### Return Codes Constants #####
RETURN_SUCCESS = 0
RETURN_ERROR = -1
RETURN_ERROR_GCC_INPUT = 101
RETURN_ERROR_GCC_CIL = 102
RETURN_TEST_FAILED = 100


##### Color constants and other #####
COLOR_RED = '\033[31m'
COLOR_BLUE = '\033[34m'
COLOR_GREEN = '\033[32m'
COLOR_YELLOW = '\033[33m'
COLOR_GREY = '\033[90m'
COLOR_RESET = '\033[0m'
SPACE = ' ' * 20


##### Config yaml constants #####
CONFIG_FILENAME = 'config.yaml'
CONFIG_GOBLINT = "goblint-path"
CONFIG_LLVM = "llvm-path"
CONFIG_LAST_INPUT_MUTATION = "last-input-mutation"


##### Api key yaml constants #####
APIKEY_FILENAME = 'api-key.yaml'
APIKEY_APIKEY = 'api-key'
APIKEY_ORGANISATION = 'organisation'


##### AI Constants #####
AI_MODEL = "gpt-3.5-turbo"
AI_MODEL_16K = "gpt-3.5-turbo-16k"
DEFAULT_AI_COUNT = 5
DEFAULT_AI_SELECT = 50
AI_WORKERS = 5


##### Helper Functions #####
def print_separator():
    try:
        columns = os.get_terminal_size().columns
    except:
        columns = 20
    print(COLOR_BLUE + '─' * columns + COLOR_RESET)


def remove_ansi_escape_sequences(s):
    if isinstance(s, bytes):
        s = s.decode('utf-8', 'ignore')
    ansi_escape = re.compile(r'\x1B(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])')
    return ansi_escape.sub('', s)


# Copy program into the temp directory with given index
def make_program_copy(program_path, index):
    new_path = os.path.join(os.path.dirname(program_path), 'p_' + str(index) + '.c')
    shutil.copy2(program_path, new_path)
    return new_path


# Check if directory name follows the naming convention of the Goblint Test Script
def check_test_dir_name(directory_name):
    if directory_name is None or not isinstance(directory_name, str):
        print(f"{COLOR_RED}[ERROR] Target Directory name {directory_name} is not a string{COLOR_RESET}")
        return False

    pattern = r"\d{2}-\w+"
    if not re.match(pattern, directory_name):
        print(
            f"{COLOR_RED}[ERROR] Target Directory name {directory_name} is not of the format 01-Name (\d{{2}}-\w+){COLOR_RESET}")
        return False
    return True


# Check if the path exists. When not stop the program.
def validate_path(path):
    path = os.path.abspath(os.path.expanduser(os.path.expandvars(path)))
    if not os.path.exists(path):
        print(f"\n{COLOR_RED}The path {path} does not exist.{COLOR_RESET}", file=sys.stderr)
        sys.exit(RETURN_ERROR)
    return path


# Get the default includes used by the Goblint Test Script for gcc and clang
def include_options(analyzer_path, for_clang=False):
    seperator = ' '
    if for_clang:
        seperator = ''
    return f'-I{seperator}{analyzer_path}/lib/linux/stub/include -I{seperator}{analyzer_path}/lib/libc/stub/include -I{seperator}{analyzer_path}/lib/goblint/runtime/include -I{seperator}{analyzer_path}/lib/sv-comp/stub/src -I{seperator}{analyzer_path}/lib/libc/stub/src'