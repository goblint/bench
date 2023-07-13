import yaml

from util import GenerateType


META_FILENAME = 'meta.yaml'
META_INPUT = 'input'
META_N = 'n'
META_TEST_FAILED = 'test_failed'
META_TEST_OUTPUT = 'test_output'
META_CRASH = 'crash'
META_CRASH_MESSAGE = 'crash_message'
META_EXCEPTION = 'exception'
META_EXCEPTION_CAUSE = 'exception_cause'
META_EXCEPTION_STD_OUT = 'exception_stdout'
META_EXCEPTION_STD_ERR = 'exception_stderr'
META_EMPTY_DIFF = 'empty_diff'
META_TYPE = 'type'
META_SUB_TYPE = 'subtype'
META_LINES = 'lines'

META_EXCEPTION_CAUSE_CREATE_CHECK = 'create_check'
META_EXCEPTION_CAUSE_ANNOTATE_CHECK = 'annotate_check'
META_EXCEPTION_CAUSE_ML = 'ml_request'

META_CRASH_MESSAGE_INITAL_NOT_COMPILE = 'inital_program_did_not_compile'
META_CRASH_MESSAGE_CLANG_LINE_GROUPS = 'exception_in_clang_line_groups'
META_CRASH_MESSAGE_CLANG_APPLY = 'exception_in_clang_apply'
META_CRASH_MESSAGE_CLANG_FUNCTION_NAME = 'exception_in_clang_function_name'
META_CRASH_MESSAGE_CLANG_WRAP = 'exception_in_clang_wrap'

def _meta_index(index):
    return f'p_{index}'

def _get_yaml_data(meta_path):
    if meta_path == None: return
    with open(meta_path, 'r') as file:
        return yaml.safe_load(file)
    
def _write_yaml_data(meta_path, data):
    if meta_path == None: return
    with open(meta_path, 'w') as file:
        yaml.safe_dump(data, file)

def meta_create_file(meta_path, source_path):
    if meta_path == None: return
    data = {META_N: 0, META_INPUT: source_path, _meta_index(0): {META_TYPE: GenerateType.INITAL.value}}
    _write_yaml_data(meta_path, data)

def meta_get_n(meta_path) -> int:
    if meta_path == None: return 0
    data = _get_yaml_data(meta_path)
    return data[META_N]

def meta_set_n(meta_path, n: int):
    if meta_path == None: return
    data =_get_yaml_data(meta_path)
    data[META_N] = n
    _write_yaml_data(meta_path, data)
    return n

def meta_create_index(meta_path, index, type, sub_type, lines):
    if meta_path == None: return
    data = _get_yaml_data(meta_path)
    data[_meta_index(index)] = {
        META_TYPE: type,
        META_SUB_TYPE: sub_type,
        META_LINES: lines
    }
    _write_yaml_data(meta_path, data)

def meta_exception(meta_path, index, cause, cmd_result_or_string):
    if meta_path == None: return
    if isinstance(cmd_result_or_string, str):
        stdout = cmd_result_or_string
        stderr = ''
    else:
        stdout = cmd_result_or_string.stdout
        stderr = cmd_result_or_string.stderr
    data = _get_yaml_data(meta_path)
    data[_meta_index(index)].update({
        META_EXCEPTION: True,
        META_EXCEPTION_CAUSE: cause,
        META_EXCEPTION_STD_OUT: stdout,
        META_EXCEPTION_STD_ERR: stderr
    })
    _write_yaml_data(meta_path, data)

def meta_exception_exists(meta_path, index) -> bool:
    if meta_path == None: return
    data = _get_yaml_data(meta_path)
    return data.get(_meta_index(index), {}).get(META_EXCEPTION, False)

def meta_get_type_and_subtype(meta_path, index) -> tuple[str, str]:
    if meta_path == None: return
    data = _get_yaml_data(meta_path)
    type = data.get(_meta_index(index), {}).get(META_TYPE, '')
    sub_type = data.get(_meta_index(index), {}).get(META_SUB_TYPE, '')
    return (type, sub_type)

def meta_empty_diff(meta_path, index):
    if meta_path == None: return
    data = _get_yaml_data(meta_path)
    data[_meta_index(index)][META_EMPTY_DIFF] = True
    _write_yaml_data(meta_path, data)

def meta_crash(meta_path, message):
    if meta_path == None: return
    data = _get_yaml_data(meta_path)
    data[META_CRASH] = True
    data[META_CRASH_MESSAGE] = message
    _write_yaml_data(meta_path, data)

def meta_test_failed(meta_path, output):
    if meta_path == None: return
    data = _get_yaml_data(meta_path)
    data[META_TEST_FAILED] = True
    data[META_TEST_OUTPUT] = output
    _write_yaml_data(meta_path, data)


# Collection of stats
def stats_get_mutation_by_type_subtype(data):
    return _stats_get_by_type_subtype(data, (lambda index: 1))


def stats_get_empty_diff_by_type_subtype(data):
    return _stats_get_by_type_subtype(data, (lambda index: 1 if data.get(_meta_index(index), {}).get(META_EMPTY_DIFF, False) else 0))


def _stats_get_by_type_subtype(data, lambda_function):
    n = data[META_N]
    mutation_types = []
    for index in range(1, n + 1):
        type = data.get(_meta_index(index), {}).get(META_TYPE, '')
        sub_type = data.get(_meta_index(index), {}).get(META_SUB_TYPE, '')
        if type == GenerateType.ML.value: # if type is ML set subtype to 'openai' as the subtype varies
            sub_type = 'openai'
        mutation_types.append((f'{type}-{sub_type}', lambda_function(index)))
    return mutation_types