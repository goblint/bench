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

    # Init collectors
    number_of_mutations = 0

    for data in stats_data.values():
        # Collect data for each run
        number_of_mutations += stats_get_n(data)

    print_separator()
    print(f'{COLOR_BLUE}STATISTICS:{COLOR_RESET}')
    print(f'{COLOR_GREY}The collected meta data can be found at {stats_path}{COLOR_RESET}')

    # Print results
    print(f"Total number of mutations: {number_of_mutations}")   


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
