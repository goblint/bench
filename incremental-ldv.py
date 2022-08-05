from cProfile import run
import os
import shutil
import time
import sys
from pathlib import Path

path = "../bench-repos/regression-verification-tasks/regression-verification-tasks/"
html_out = "results.html"

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

class ConfigMapping:
    mappings: dict = {} # mapping from configs to FolderResults

    def __init__(self, mappings):
        self.mappings = mappings

class Configuration:
    config = ""
    name = ""

    def __init__(self, config, name):
        self.config = config
        self.name = name

    def config_by_index(self, index):
        return self.config

class IncrementalConfiguration(Configuration):
    save = " --enable incremental.save "
    load = " --enable incremental.load "

    def __init__(self, config, name):
        super().__init__(config, name)

    def config_by_index(self, index):
        if index == 0:
            return self.save + self.config
        else:
            return self.save + self.load + self.config

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
        suffix = file[12:]
        cut_off_index = suffix.find(".")
        suffix = suffix[:cut_off_index]

        lst = benchmarks.get(suffix)
        if lst == None:
            lst = [file]
        else:
            lst.append(file)
        benchmarks[suffix] = lst
    return benchmarks

def run_goblint(file, configuration, index):
    destination = "ldv.cil"
    if Path(destination).is_file():
        os.remove(destination)
    shutil.copyfile(file, destination)
    cmd = "timeout 1s ./goblint " + destination + " " + configuration.config_by_index(index)
    print("Running " + cmd + ", file: " + file)
    before = time.time()
    stream = os.popen(cmd)
    output = stream.read()
    diff = time.time() - before
    return Result(file, diff, configuration, output)

def benchmark_folder(dir, configuration: Configuration):
    dir = dir
    benchmarks = find_sequences(dir)

    if benchmarks == None:
        return

    sequences = []
    for key in benchmarks:
        i = 0
        seq = []
        for file in benchmarks.get(key):
            file = os.path.join(dir, file)
            result = run_goblint(file, configuration, i)
            i = i + 1
            seq.append(result)
        sequences.append(Sequence(seq))
    return FolderResult(dir, sequences)

def benchmark_all_folders(path, configuration: Configuration):
    folder_results = []
    for dir in os.listdir(path):
        folder = os.path.join(path, dir)
        folder_result = benchmark_folder(folder, configuration)
        folder_results.append(folder_result)
    return folder_results

def configurations():

    args = " ".join(sys.argv[1:])
    incremental = IncrementalConfiguration(args, "incremental")
    non_incremental = Configuration(args, "non-incremental")
    return [incremental, non_incremental]

def run_benchmarks(path):
    config_mapping = {}
    for conf in configurations():
        results = benchmark_all_folders(path, conf)
        config_mapping[conf.name] = results
    return ConfigMapping(config_mapping)

def create_config_mapping(config_mapping: ConfigMapping):
    mapping = {} # mapping from file names to results
    i = 0
    for conf in config_mapping.mappings:
        for folder in config_mapping.mappings[conf]:
            for folder_result in folder.sequences:
                for result in folder_result.results:
                    i = i + 1
                    if result == None:
                        continue
                    results_for_file = mapping.get(result.file)
                    if results_for_file == None:
                        results_for_file = [result]
                    else:
                        results_for_file.append(result)
                    mapping[result.file] = results_for_file
    return mapping


def print_entry(str):
    print("<td>" + str + "</td>")

def print_mapping(config_mapping: ConfigMapping, outfile):
    mapping = create_config_mapping(config_mapping)

    file_handle = open(outfile, "w")
    stdout = sys.stdout
    sys.stdout = file_handle
    print("<html>")
    print("<body>")

    print("<table>")
    print("<tr>")
    print_entry("filename")
    for conf in config_mapping.mappings:
        print_entry(conf)
    print("</tr>")

    for file in mapping:
        print("<tr>")
        filename = os.path.basename(file)
        print_entry(filename)
        for entry in mapping[file]:
            print("<td>")
            print("%.3f" % entry.runtime)
            print("</td>")
        print("</tr")
    print("</table")

    print("</body>")
    print("</html>")

    sys.stdout = stdout
    file_handle.close()

def run_and_print():
    config_mapping = run_benchmarks(path)
    print_mapping(config_mapping, html_out)

run_and_print()
