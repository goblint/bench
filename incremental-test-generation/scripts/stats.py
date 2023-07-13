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
    with open(stats_path, 'r') as file:
        stats_data = yaml.safe_load(file)

    print_separator()
    print(f'{COLOR_BLUE}STATISTICS:{COLOR_RESET}')
    print(f'{COLOR_GREY}The collected meta data can be found at {stats_path}{COLOR_RESET}')

    # Init collectors
    mutations_by_type = []
    empty_diff_by_type = []

    for data in stats_data.values():
        # Collect data for each run
        mutations_by_type = _merge_collector_with_type(mutations_by_type, stats_get_mutation_by_type_subtype(data))
        empty_diff_by_type = _merge_collector_with_type(empty_diff_by_type, stats_get_empty_diff_by_type_subtype(data))

    # Print results
    _print_collector_with_type(mutations_by_type, 'Number of mutations by type')
    _print_collector_with_type(empty_diff_by_type, 'Number of empty patch files by type')



def _merge_collector_with_type(current_collector: list[tuple[str, int]], new_tuples: list[tuple[str, int]]) -> list[tuple[str, int]]:
    current_dict = {k: v for k, v in current_collector}
    for k, v in new_tuples:
        if k in current_dict:
            current_dict[k] += v
        else:
            current_dict[k] = v
    unsorted_list = [(k, v) for k, v in current_dict.items()]
    return sorted(unsorted_list, key=lambda x: x[1], reverse=True)


def _print_collector_with_type(collector: list[tuple[str, int]], title: str):
    print(f'{title}:')
    sum = 0
    for (k,v) in collector:
        if v == 0: continue
        print(f'\t{COLOR_YELLOW}{v}{COLOR_RESET} for {k}')
        sum += v
    print(f'\t{COLOR_YELLOW}{sum}{COLOR_RESET} in sum')


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
