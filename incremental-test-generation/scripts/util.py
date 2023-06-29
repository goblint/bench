from enum import Enum
import os
import re
import shutil


class Mutations:
    def __init__(self, rfb=False, uoi=False, ror=False, cr=False, rt=False, lcr=False):
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


def get_mutations_from_args(args):
    return Mutations(args.remove_function_body, args.unary_operator_inversion,
                     args.relational_operator_replacement, args.constant_replacement,
                     args.remove_thread, args.logical_connector_replacement)


class GenerateType(Enum):
    SOURCE = 'SOURCE'
    MUTATION = 'MUTATION'
    ML = 'ML'
    GIT = 'GIT'


def remove_ansi_escape_sequences(s):
    if isinstance(s, bytes):
        s = s.decode('utf-8', 'ignore')
    ansi_escape = re.compile(r'\x1B(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])')
    return ansi_escape.sub('', s)


RETURN_SUCCESS = 0
RETURN_ERROR = -1
RETURN_TEST_FAILED = 100


COLOR_RED = '\033[31m'
COLOR_BLUE = '\033[34m'
COLOR_GREEN = '\033[32m'
COLOR_YELLOW = '\033[33m'
COLOR_GREY = '\033[90m'
COLOR_RESET = '\033[0m'


def print_separator():
    try:
        columns = os.get_terminal_size().columns
    except:
        columns = 20
    print(COLOR_BLUE + '─' * columns + COLOR_RESET)


SPACE = ' ' * 20


META_FILENAME = 'meta.yaml'
META_N = 'n'
META_COMPILING = 'compilation'
META_EXCEPTION = 'exception'
META_DIFF = 'diff'
META_TYPE = 'type'
META_SUB_TYPE = 'sub_type'
META_LINES = 'lines'
META_FAILURES = 'failures'
META_FAILURES_STD_OUT = 'stdout'
META_FAILURES_STD_ERR = 'stderr'


CONFIG_FILENAME = 'config.yaml'
CONFIG_GOBLINT = "goblint-path"
CONFIG_LLVM = "llvm-path"
CONFIG_LAST_INPUT_MUTATION = "last-input-mutation"
CONFIG_LAST_INPUT_GIT = "last-input-git"


APIKEY_FILENAME = 'api-key.yaml'
APIKEY_APIKEY = 'api-key'
APIKEY_ORGANISATION = 'organisation'


ML_MODEL = "gpt-3.5-turbo"
ML_MODEL_16K = "gpt-3.5-turbo-16k"
DEFAULT_ML_COUNT = 5
DEFAULT_ML_SELECT = 50
ML_WORKERS = 5


def make_program_copy(program_path, index):
    new_path = os.path.join(os.path.dirname(program_path), 'p_' + str(index) + '.c')
    shutil.copy2(program_path, new_path)
    return new_path


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
