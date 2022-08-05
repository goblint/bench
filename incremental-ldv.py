from cProfile import run
import os
import shutil
from pathlib import Path

path = "../bench-repos/regression-verification-tasks/regression-verification-tasks/"
d = "drivers--auxdisplay--cfag12864b.ko"

def run_folder(path):
    files = os.listdir(path)
    files.sort()
    filtered = []
    for file in files:
        if file.endswith(".cil"):
            filtered.append(file)

    if files == []:
        return

    start_index = files[0][0:3]
    start_files = []
    for file in filtered:
        if file.startswith(start_index):
            start_files.append(file)
        else:
            break

    for file in start_files:
        print(file)

# Returns sequences of benchmarks in a directory as a dict of lists
def find_sequences(path):
    print(path)
    files = os.listdir(path)
    files.sort()
    filtered = []
    for file in files:
        if file.endswith(".cil"):
            filtered.append(file)

    if files == []:
        print("empty files list")
        return {}

    benchmarks = {}

    for file in filtered:
        suffix = file[12:]
        lst = benchmarks.get(suffix)
        if lst == None:
            lst = [file]
        else:
            lst.append(file)
        benchmarks[suffix] = lst
    return benchmarks

def run_goblint(file, configuration):
    destination = "ldv.cil"
    if Path(destination).is_file():
        os.remove(destination)
    shutil.copyfile(file, destination)
    cmd = "./goblint " + destination + " " + configuration
    stream = os.popen(cmd)
    output = stream.read()
    output

def benchmark(dir, benchmarks):
    for key in benchmarks:
        for file in benchmarks.get(key):
            file = os.path.join(dir, file)
            run_goblint(file, "")

def run_benchmarks(path):
    for dir in os.listdir(path):
        dir = path + dir
        seqs = find_sequences(dir)
        if seqs != None:
            benchmark(dir, seqs)

run_benchmarks(path)
