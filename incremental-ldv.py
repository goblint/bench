from cProfile import run
import os
import shutil
import time
from pathlib import Path

path = "../bench-repos/regression-verification-tasks/regression-verification-tasks/"

class Result:
    file = ""
    runtime = 0
    configuration = None
    output = ""

    def __init__(self, file, runtime, configuration, output):
        self.file = file
        self.runtime = runtime
        self.configuration = configuration
        self.output = output

# results for a sequence of commits
class Sequence:
    results = []

    def __init__(self, results):
        self.results = results

class FolderResult:
    folder = ""
    sequences = []

    def __init__(self, folder, sequences):
        self.folder = folder
        self.sequences = sequences

class ConfigMappings:
    mappings = {} # mapping from configs to FolderResults

    def __init__(self, mappings):
        self.mappings = mappings

class Configuration:
    config = ""
    name = ""

    def __init__(self, config, name):
        self.config = config
        self.name = name

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
    cmd = "./goblint " + destination + " " + configuration.config
    before = time.time_ns()
    stream = os.popen(cmd)
    diff = time.time_ns() - before
    output = stream.read()
    Result(file, diff, configuration, output)

def benchmark_folder(dir, configuration: Configuration):
    dir = dir
    benchmarks = find_sequences(dir)

    if benchmarks == None:
        return

    sequences = []
    for key in benchmarks:
        seq = []
        for file in benchmarks.get(key):
            file = os.path.join(dir, file)
            result = run_goblint(file, configuration)
        seq.append(result)
        sequences.append(Sequence(seq))
    return FolderResult(dir, sequences)

def benchmark_all_folders(path, configuration: Configuration):
    folder_results = []
    for dir in os.listdir(path):
        path = os.path.join(path, dir)
        folder_result = benchmark_folder(path, configuration)
        folder_results.append(folder_result)
    return folder_result

def configurations():
    incremental = Configuration("--enable incremental.save --enable incremental.load", "incremental")
    non_incremental = Configuration("", "non-incremental")
    return [incremental, non_incremental]

def run_benchmarks(path):
    config_mapping = {}
    for conf in configurations():
        results = benchmark_all_folders(path, conf)
        config_mapping[conf.name] = results
    return ConfigMappings(config_mapping)

run_benchmarks(path)
