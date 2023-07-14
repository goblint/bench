from enum import Enum
import os
import re
import shutil
import sys


######################################################################
##### Classes and Functions for generating new clang tidy checks #####
class Mutations:
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


def get_default_mutations():
    return Mutations(rfb=True, uoi=True, ror=True, cr=True, rt=True, lcr=True, ris=True)


def add_mutation_options(parser):
    parser.add_argument("-rfb", "--remove-function-body", action="store_true",
                        help="Option for \"remove function body\" mutation")
    parser.add_argument("-uoi", "--unary-operator-inversion", action="store_true",
                        help="Option for \"unary operator inversion\" mutation")
    parser.add_argument("-ror", "--relational-operator-replacement", action="store_true",
                        help="Option for \"relational operator replacement\" mutation")
    parser.add_argument("-cr", "--constant-replacement", action="store_true",
                        help="Option for \"constant replacement\" mutation")
    parser.add_argument("-rt", "--remove-thread", action="store_true", help="Option for \"remove thread\" mutation")
    parser.add_argument("-lcr", "--logical-connector-replacement", action="store_true",
                        help="Option for \"logical connector replacement\" mutation")
    parser.add_argument("-ris", "--remove-if-statement", action="store_true",
                        help="Option for \"remove if statement\" mutation")


def get_mutations_from_args(args):
    return Mutations(args.remove_function_body, args.unary_operator_inversion,
                     args.relational_operator_replacement, args.constant_replacement,
                     args.remove_thread, args.logical_connector_replacement, args.remove_if_statement)


def check_for_mutation_selection_without_enabling_mutation(parser, args):
    if (args.remove_function_body or args.unary_operator_inversion or args.relational_operator_replacement \
                or args.constant_replacement or args.remove_thread or args.logical_connector_replacement or args.remove_if_statement) \
                and not args.enable_mutations:
            parser.error("Setting single mutations only takes affect when also the mutation was enabled by the command line (-m)!")


def interactivelyAskForMutations(questionary):
    selected_mutations = questionary.checkbox(
        'Select one or more mutation types:',
        choices=[
            questionary.Choice('remove-function-body (RFB)', checked=True),
            questionary.Choice('unary-operator-inversion (UOI)', checked=True),
            questionary.Choice('relational-operator-replacement (ROR)', checked=True),
            questionary.Choice('constant-replacement (CR)', checked=True),
            questionary.Choice('remove-thread (RT)', checked=True),
            questionary.Choice('logical-connector-replacement (LCR)', checked=True),
            questionary.Choice('remove-if-statement (RIS)', checked=True)
        ]).ask()
    mutations = Mutations(
        rfb='remove-function-body (RFB)' in selected_mutations,
        uoi='unary-operator-inversion (UOI)' in selected_mutations,
        ror='relational-operator-replacement (ROR)' in selected_mutations,
        cr='constant-replacement (CR)' in selected_mutations,
        rt='remove-thread (RT)' in selected_mutations,
        lcr='logical-connector-replacement (LCR)' in selected_mutations,
        ris='remove-if-statement (RIS)' in selected_mutations
    )
    return mutations


def getMutationDescriptionsForML():
 return "Removal of function bodies, Inversion of if statements, Switching <= with < and >= with >, Replacing constants unequal 0 with 1, Replace pthread calls with function calls, Switching && with ||, Removal of if statements with no else part"


##### Classes and Functions for generating new clang tidy checks #####
######################################################################


######################################################################
############### Regex strings for removing parameters ################
REGEX_PARAMETER_REMOVAL = [
    # Do not use witness options as the witness information can not be used for the incremental analysis
    r'--set [\'"]*ana\.activated\[\+\][\'"]* [\'"]*unassume[\'"]*',
    r'--set [\'"]*witness\.yaml\.validate[\'"]* \S*',
    r'--set [\'"]*witness\.yaml\.unassume[\'"]* \S*',
    # Do not use autotune as it might change analyses that must not be changes during incremental analysis
    r'--enable [\'"]*ana\.autotune\.enabled[\'"]*',
    # Do not disable warn asserts as then the update_suite ruby script can't check the annotations
    r'--disable [\'"]*warn\.assert[\'"]*',
    # Do not use transformation assert as it interferes with the checks generated for the tester
    r'--set [\'"]*trans\.activated\[\+\][\'"]* [\'"]*assert[\'"]*',
    # Remove apron and affeq as there is no marshalling for incremental analysis supported (https://github.com/goblint/analyzer/issues/558#issuecomment-1479475503)
    r'--set [\'"]*ana\.activated\[\+\][\'"]* [\'"]*apron[\'"]*',
    r'--set [\'"]*ana\.activated\[\+\][\'"]* [\'"]*affeq[\'"]*',
    # Remove file analysis as these programs usally depend on external files which may not be accesible
    r'--set [\'"]*ana\.activated\[\+\][\'"]* [\'"]*file[\'"]*',
    # Optimisations activate the compiler flags which cause problems with the incremental analysis
    r'--set [\'"]*pre\.cppflags\[\+\][\'"]* [\'"]*-O1[\'"]*',
    r'--set [\'"]*pre\.cppflags\[\+\][\'"]* [\'"]*-O2[\'"]*',
    r'--set [\'"]*pre\.cppflags\[\+\][\'"]* [\'"]*-O3[\'"]*'
]
############### Regex strings for removing parameters ################
######################################################################


##### Enums #####
class GenerateType(Enum):
    INITAL = 'INITAL'
    CLANG = 'CLANG'
    ML = 'ML'


##### Return Codesconstants #####
RETURN_SUCCESS = 0
RETURN_ERROR = -1
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


##### ML Constants #####
ML_MODEL = "gpt-3.5-turbo"
ML_MODEL_16K = "gpt-3.5-turbo-16k"
DEFAULT_ML_COUNT = 5
DEFAULT_ML_SELECT = 50
ML_WORKERS = 5


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


def validate_path(path):
    path = os.path.abspath(os.path.expanduser(os.path.expandvars(path)))
    if not os.path.exists(path):
        print(f"{COLOR_RED}The path {path} does not exist.{COLOR_RESET}")
        sys.exit(RETURN_ERROR)
    return path
