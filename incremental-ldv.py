from cProfile import run
from genericpath import isdir
import os
import shutil
import time
import sys
from pathlib import Path

path = "../bench-repos/regression-verification-tasks/regression-verification-tasks/"
ldv_bench_dir_name = "ldv-regression"
output_path = "../bench/" + ldv_bench_dir_name

set_output_path = "../bench/index/sets/ldv"


def get_suffix(file):
    suffix = file[12:]
    cut_off_index = suffix.find(".")
    suffix = suffix[:cut_off_index]
    return suffix

# Returns sequences of benchmarks in a directory as a dict of lists
def find_sequences(path):
    print(path)
    files = os.listdir(path)
    files.sort()
    filtered = []
    for file in files:
        if file.find(".cil") != -1:
            filtered.append(file)

    if files == []:
        print("empty files list")
        return {}

    benchmarks = {}

    for file in filtered:
        print("Looking at file " + file)
        suffix = get_suffix(file)

        lst = benchmarks.get(suffix)
        if lst == None:
            lst = [file]
        else:
            lst.append(file)
        benchmarks[suffix] = lst

    for start in benchmarks.keys():
        print("Start: " + start)
        for file in benchmarks.get(start):
            print("file:" + file)

    return benchmarks

def copy_file(input_file, input_dir):
    source = os.path.join(input_dir, input_file)
    input_dir_basename = os.path.basename(input_dir)
    destination_dir = os.path.join(output_path, input_dir_basename)

    output_file = input_file.replace(".cil", ".c")
    destination = os.path.join(destination_dir, output_file)
    if Path(destination).is_file():
        os.remove(destination)
    print("Copying file " + source + " to: " + destination)
    if not os.path.isdir(destination_dir):
        os.makedirs(destination_dir)
    shutil.copyfile(source, destination)

def diff_files_output_to(current, update, input_dir, output_path, firstfilename, index):
    input_dir_basename = os.path.basename(input_dir)
    destination_dir = os.path.join(output_path, input_dir_basename, current)
    current = os.path.join(input_dir, current)
    update = os.path.join(input_dir, update)

    index = "." + str(index).zfill(3)

    base_file_name = firstfilename.replace(".cil", "")
    output_path = os.path.join(output_path, base_file_name + index + ".patch")

    cmd = "diff " + current + " " + update + " >" + output_path
    # print("Executing: " + cmd)
    stream = os.popen(cmd)
    _ = stream.read()

def generate_sequence(dir, sequence):
    if sequence == []:
        return

    first = sequence[0]
    current = sequence.pop(0)

    copy_file(current, dir)

    i = 0

    for file in sequence:
        i = i + 1
        print("handling " + file)
        dir_basename = os.path.basename(dir)
        out_path = os.path.join(output_path, dir_basename)
        diff_files_output_to(current, file, dir, out_path, first, i)
        current = file


def generate_folder(dir):
    benchmarks = find_sequences(dir)
    if benchmarks == None:
        return

    for key in benchmarks:
        sequence = benchmarks.get(key)
        generate_sequence(dir, sequence)

def print_entry(file, dir_basename):
    basename = os.path.basename(file)
    suffix = get_suffix(basename)

    file = file.replace(".cil", ".c")
    file_path = os.path.join(ldv_bench_dir_name, dir_basename, file)
    print(suffix + ":")
    print("  info: " + suffix + ".c")
    print("  path: " + file_path)
    print("  param:\n")

def create_benchmark_file_for_folder(dir):
    benchmarks = find_sequences(dir)
    if benchmarks == None:
        return
    dir_basename = os.path.basename(dir)
    output_file = os.path.join(set_output_path, dir_basename + ".yaml")


    file_handle = open(output_file, "w")
    original_stdout = sys.stdout
    sys.stdout = file_handle

    for key in benchmarks:
        sequence = benchmarks.get(key)
        print_entry(sequence[0], dir_basename)

    sys.stdout = original_stdout

def generate_all_folders(path):
    folder_results = []

    if not os.path.isdir(set_output_path):
        os.makedirs(set_output_path)

    for dir in os.listdir(path):
        folder = os.path.join(path, dir)
        folder_result = generate_folder(folder)
        folder_results.append(folder_result)

        create_benchmark_file_for_folder(folder)
    return folder_results

generate_all_folders(path)
