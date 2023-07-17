import os
import time
import yaml
import argparse

from meta import *
from util import *


def stats_append_meta(stats_path, path):
    if not os.path.exists(stats_path):
        with open(stats_path, 'w') as file:
            yaml.dump({}, file)
            
    validate_path(stats_path)
    validate_path(path)
    
    with open(path, 'r') as file:
        new_data = yaml.safe_load(file)

    with open(stats_path, 'r') as file:
        stats_data = yaml.safe_load(file)        
    current_time_millis = int(round(time.time() * 1000))
    stats_data[current_time_millis] = new_data
    with open(stats_path, 'w') as file:
        yaml.safe_dump(stats_data, file)


def stats_print(stats_path):
    validate_path(stats_path)
    print("\rLoading stats. Please wait...", end='')
    with open(stats_path, 'r') as file:
        stats_data = yaml.safe_load(file)

    print('\r', end='')
    print_separator()
    print(f'{COLOR_BLUE}STATISTICS:{COLOR_RESET}')
    print(f'{COLOR_GREY}The collected meta data can be found at {stats_path}{COLOR_RESET}')

    # Init collectors
    files_failed_tests = 0
    files_crash = 0
    crash_by_message = []
    mutations_by_type = []
    empty_diff_by_type = []
    exception_by_type = []
    exception_by_cause = []
    performance_by_measurement = []
    tokens = []

    for data in stats_data.values():
        # Collect data for each run
        files_failed_tests += stats_get_failed_tests(data)
        files_crash += stats_get_crash(data)
        crash_by_message = _merge_collector_with_type(crash_by_message, stats_get_crash_by_message(data))
        mutations_by_type = _merge_collector_with_type(mutations_by_type, stats_get_mutation_by_type_subtype(data))
        empty_diff_by_type = _merge_collector_with_type(empty_diff_by_type, stats_get_empty_diff_by_type_subtype(data))
        exception_by_type = _merge_collector_with_type(exception_by_type, stats_get_exception_by_type_subtype(data))
        exception_by_cause = _merge_collector_with_type(exception_by_cause, stats_get_exceptions_by_cause(data))
        performance_by_measurement.extend(stats_get_performance(data))
        tokens.extend(stats_get_tokens(data))

    performance_avg = _average_collector_with_type(performance_by_measurement)
    performance_max = _max_collector_with_type(performance_by_measurement)
    performance_min = _min_collector_with_type(performance_by_measurement)
    token_avg = _average_collector_with_type(tokens)
    token_max = _max_collector_with_type(tokens)
    token_min = _min_collector_with_type(tokens)

    # Print results
    input_files = _print_value(len(stats_data.values()), 'Number of input files')
    _print_value(files_failed_tests, 'Number of input files with failed test', tab=True)
    _print_value(files_crash, 'Number of input files with crashes', tab=True)
    if files_crash > 0:
        _print_collector_with_type(crash_by_message, 'Number of crashes by message', input_files)
    _print_collector_with_type(mutations_by_type, 'Number of mutations by type', input_files)
    _print_collector_with_type(empty_diff_by_type, 'Number of empty patch files by type', input_files)
    _print_collector_with_type(exception_by_type, 'Number of exceptions by type', input_files)
    _print_collector_with_type(exception_by_cause, 'Number of exceptions by cause', input_files)
    _print_collector_with_type(performance_avg, 'Average performance in ms', None)
    _print_collector_with_type(performance_max, 'Worst performance in ms', None)
    _print_collector_with_type(performance_min, 'Best performance in ms', None)
    if tokens:
        _print_collector_with_type(token_avg, 'Average tokens', None)
        _print_collector_with_type(token_max, 'Maximum tokens', None)
        _print_collector_with_type(token_min, 'Minimum tokens', None)
    print_separator()



def _merge_collector_with_type(current_collector: list[tuple[str, int]], new_tuples: list[tuple[str, int]]) -> list[tuple[str, int]]:
    current_dict = {k: v for k, v in current_collector}
    for k, v in new_tuples:
        if k in current_dict:
            current_dict[k] += v
        else:
            current_dict[k] = v
    unsorted_list = [(k, v) for k, v in current_dict.items()]
    return sorted(unsorted_list, key=lambda x: x[1], reverse=True)


def _average_collector_with_type(collector: list[tuple[str, float]]) -> list[tuple[str, float]]:
    sum_dict = {}
    count_dict = {}
    for k, v in collector:
        if k in sum_dict:
            sum_dict[k] += v
            count_dict[k] += 1
        else:
            sum_dict[k] = v
            count_dict[k] = 1
    average_dict = {k: sum_dict[k] // count_dict[k] for k in sum_dict}
    unsorted_list = [(k, v) for k, v in average_dict.items()]
    return sorted(unsorted_list, key=lambda x: x[1], reverse=True)


def _max_collector_with_type(collector: list[tuple[str, int]]) -> list[tuple[str, int]]:
    max_dict = {}
    for k, v in collector:
        if k in max_dict:
            max_dict[k] = max(max_dict[k], v)
        else:
            max_dict[k] = v
    unsorted_list = [(k, v) for k, v in max_dict.items()]
    return sorted(unsorted_list, key=lambda x: x[1], reverse=True)


def _min_collector_with_type(collector: list[tuple[str, int]]) -> list[tuple[str, int]]:
    max_dict = {}
    for k, v in collector:
        if k in max_dict:
            max_dict[k] = min(max_dict[k], v)
        else:
            max_dict[k] = v
    unsorted_list = [(k, v) for k, v in max_dict.items()]
    return sorted(unsorted_list, key=lambda x: x[1], reverse=True)


def _print_collector_with_type(collector: list[tuple[str, int]], title: str, avg_sum: int):
    print(f'{title}:')
    sum = 0
    for (k,v) in collector:
        if v == 0: continue
        print(f'\t{COLOR_YELLOW}{v}{COLOR_RESET} for {k}')
        sum += v
    if avg_sum is not None:
        print(f'\t{COLOR_GREY}-> {COLOR_YELLOW}{sum}{COLOR_RESET} in sum')
        print(f'\t{COLOR_GREY}-> {COLOR_YELLOW}{(sum/avg_sum):.4f}{COLOR_RESET} in average')
    return sum


def _print_value(value: int, title: str, tab=False):
    if tab:
        print('\t', end='')
    print(f'{title}: {COLOR_YELLOW}{value}{COLOR_RESET}')
    return value


def main():
    parser = argparse.ArgumentParser(description='Collects meta data of runs and prints statistics')
    parser.add_argument('stats_path', help='Path to the stats file')
    parser.add_argument('--append', action='append', help='Input File to attach to the stats file (Do not print stats, create stats file if not existing)')

    args = parser.parse_args()

    if args.append is not None:
        for path in args.append:
            stats_append_meta(args.stats_path, path)
    else:
        stats_print(args.stats_path)


if __name__ == "__main__":
    main()
