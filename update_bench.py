#!/usr/bin/env python3
import os
import sys
import platform
import shutil
import subprocess
from datetime import datetime
import glob
import re
import json
import pickle


timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
# Change to script directory
os.chdir(os.path.dirname(__file__))

goblint = os.path.abspath("../analyzer/goblint")
if not os.path.exists(goblint):
    raise RuntimeError("Please run script from goblint dir!")

# Get goblint version
vrsn = subprocess.check_output([goblint, "--version"]).decode()

results = "bench_result"
os.makedirs(results, exist_ok=True)
testresults = os.path.abspath("bench_result") + "/"
theresultfile = os.path.join(testresults, "index.html")

bench = "./"
linux = os.path.join(bench, "linux/")

header = f"""<head>
  <title>Benchmarks on {platform.node()}</title>
  <style type="text/css">
    A:link {{text-decoration: none}}
    A:visited {{text-decoration: none}}
    A:active {{text-decoration: none}}
    A:hover {{text-decoration: underline}}
  </style>
</head>
"""

# Find available highlighter
def get_highlighter():
    HIGHLIGHTERS = ["code2html", "source-highlight", "pygmentize"]
    def make_command(executable):
        if executable == "code2html":
            return lambda f, o: f"code2html -l c -n {f} 2> /dev/null 1> {o}"
        elif executable == "source-highlight":
            return lambda f, o: f"source-highlight -n -i {f} -o {o}"
        elif executable == "pygmentize":
            return lambda f, o: f"pygmentize -O full,linenos=1 -o {o} {f}"
        else:
            return lambda f, o: f"cp {f} {o}"

    for name in HIGHLIGHTERS:
        for path in os.environ.get("PATH", "").split(":"):
            executable_path = os.path.join(path, name)
            if os.path.isfile(executable_path) and os.access(executable_path, os.X_OK):
                return make_command(name)

    # Default to copying the file if no highlighter is found
    return make_command(None)

def parse_benchmark_file():
    analyses = []
    projects = []
    skip_group = []

    with open(file, "r") as f:
        id = 0
        gname = None

        while True:
            line = f.readline()
            if line == "": # EOF
                break
            line = line.strip()
            if not line:
                continue
            if line.startswith("#"):
                continue
            if line.startswith("Group: "):
                gname = line[7:].strip()
                if "SKIP" in line:
                    skip_group.append(gname)
            elif ":" in line:
                a, b = map(str.strip, line.split(":", 1))
                analyses.append([a, b])
            else:
                name = line
                url = f.readline().strip()
                path = f.readline().strip()
                params = f.readline().strip()
                params = "" if params == "-" else params

                if url == "linux!":
                    params = f"--enable kernel {params}"
                    url = linuxroot + path
                    path = os.path.abspath(os.path.join(linux, path))
                else:
                    path = os.path.abspath(os.path.join(bench, path))

                size = f"{os.popen(f'wc -l {path}').read().split()[0]} lines"
                id += 1
                projects.append(Project(id, name, size, url, gname, path, params))
    return projects,analyses,skip_group

class Project:
    def __init__(self, id, name, size, url, group, path, params):
        self.id = id
        self.name = name
        self.size = size
        self.url = url
        self.group = group
        self.path = path
        self.params = params

    def to_html(self):
        return f'<td>{self.id}</td><td><a href="{self.url}">{self.name}</a></td>\n<td>{self.size}</td>\n'

    def generate_url(self):
        if self.url == "generate!":
            highlighter = get_highlighter()
            highlighter(self.path, os.path.join(testresults, self.name + ".html"))
            self.url = self.name + ".html"

    def __str__(self):
        return self.name

def print_html_file(i):
    with open(theresultfile, "w") as f:
        f.write("<html>\n")
        f.write(header)
        f.write("<body>\n")

        if i is not None:
            f.write(f"<p>Benchmarking in progress: {i}/{len(projects)} "
                    f"<progress value=\"{i}\" max=\"{len(projects)}\" /></p>\n")

        f.write("<table border=2 cellpadding=4 style=\"font-size: 90%\">\n")

        gname = ""
        for p in projects:
            if p.group != gname:
                gname = p.group
                f.write(f"<tr><th colspan={4 + len(analyses)}>{gname}</th></tr>\n")
                # if print_desc:
                #     f.write("<tr><th>#</th><th>Name</th><th>Description</th><th>Size</th>\n")
                # else:
                f.write("<tr><th>#</th><th>Name</th><th>Size</th>\n")
                for a in analyses:
                    aname = a[0]
                    f.write(f"<th>{aname}</th>\n")

            f.write("<tr>\n")
            f.write(p.to_html())

            for a in analyses:
                aname = a[0]
                outfile = os.path.basename(p.path).replace(os.path.splitext(p.path)[1], f".{aname}.txt")
                outpath = os.path.join(testresults, outfile)

                if os.path.exists(outpath):
                    with open(outpath, "r") as g:
                        lines = g.readlines()
                        def grep(pattern, lines):
                            import re
                            return [re.search(pattern, l) for l in lines if re.search(pattern, l)]

                        safely = next((int(m.group(1)) for m in grep(r"[^n]safe:\s*([0-9]*)", lines) if m), None)
                        vulner = next((int(m.group(1)) for m in grep(r"vulnerable:\s*([0-9]*)", lines) if m), None)
                        unsafe = next((int(m.group(1)) for m in grep(r"unsafe:\s*([0-9]*)", lines) if m), None)
                        uncalled = len([l for l in lines if "will never be called" in l and "__check" not in l])
                        timeout = next((m.group(1) for m in grep(r"^TIMEOUT\s*(.*) s.*$", lines) if m), None)

                        if not timeout:
                            dur = next((m.group(1) for m in grep(r"^Duration: (.*) s", lines) if m), None)
                            cod = next((m.group(1) for m in grep(r"^EXITCODE\s*(.*)$", lines) if m), None)

                            if dur and not cod:
                                thenumbers = (
                                    f"<font color=\"green\">{safely}</font>; "
                                    f"<font color=\"orange\">{vulner}</font> + "
                                    f"<font color=\"red\">{unsafe}</font>"
                                )
                                if uncalled > 0:
                                    thenumbers += f"; <font color=\"magenta\">{uncalled}</font>"
                                f.write(f"<td><a href=\"{outfile}.html\">{float(dur):.2f} s</a> ({thenumbers})</td>\n")
                            else:
                                f.write(f"<td><a href=\"{outfile}\">failed (code: {cod})</a></td>\n")
                        else:
                            f.write(f"<td><a href=\"{outfile}\">{timeout} s</a> (limit)</td>\n")
                else:
                    f.write("<td>N/A</td>\n")

            f.write("</tr>\n")

        f.write("</table>\n")
        f.write("<p style=\"font-size: 80%; white-space: pre-line\">\n")
        f.write(f"Last updated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S %z')}\n")
        f.write(vrsn)
        f.write("</p>\n")
        f.write("</body>\n")
        f.write("</html>\n")


# Command line parameters
timeout = 900
if len(sys.argv) > 1:
    timeout = int(sys.argv[1])
only = sys.argv[2] if len(sys.argv) > 2 else None
thegroup = None
if only == "group":
    only = None
    thegroup = sys.argv[3] if len(sys.argv) > 3 else None

# Processing the input file
file = "bench.txt"
linuxroot = "https://elixir.bootlin.com/linux/v4.0/source/"
if not os.path.exists(file):
    os.symlink("index/dd.txt", file)

shutil.copyfile(file, os.path.join(testresults, "bench.txt"))
projects, analyses, skip_group = parse_benchmark_file()



fileheader = f"""<html>
  <head>
    <title>Benchmarks on {os.uname().nodename}</title>
    <style type="text/css">
      body {{ white-space: pre; font-family: monospace }}
      a {{ color: inherit }}
    </style>
  </head>
  <body>
"""



# Analyse files
gname = ""
maxlen = max(len(a[0]) for a in analyses) + 1

def should_skip(project):
    if project.group in skip_group:
        return True
    if thegroup and project.group != thegroup:
        return True
    if only and project.name != only:
        return True
    return False


def remove_old_outfiles(basename):
    outfiles = glob.glob(os.path.join(testresults, basename + ".*"))
    for f in outfiles:
        os.remove(f)

class Result:
    def __init__(self, project, base, filename, cmd, analysis_name, analysis_params, start, end, output, status):
        self.project = project
        self.base = base
        self.filename = filename
        self.start = start
        self.cmd = cmd
        self.analysis_name = analysis_name
        self.analysis_params = analysis_params
        self.output_file = os.path.join(testresults, base + "." + analysis_name + ".txt")
        self.end = end
        self.duration = (end - start).total_seconds()
        self.status = status
        self.output = output

    def appended_output(self):
        appended = "\n=== APPENDED BY BENCHMARKING SCRIPT ===\n"
        appended += f"Analysis began: {self.start}\n"
        appended += f"Analysis ended: {self.end}\n"
        appended += f"Duration: {self.duration:.2f} s\n"
        appended += f"Goblint params: {' '.join(self.cmd)}\n"
        appended += vrsn + "\n"

        if self.status == 124:
            appended += f"TIMEOUT                    {timeout} s\n"
        elif self.status != 0:
            appended += f"EXITCODE                   {self.status}\n"

        return appended

    def dump_output(self):
        with open(self.output_file, "w") as f:
            f.write(self.output + self.appended_output())

    def print_status(self):
        if self.status == 0:
            print("-- Done")
        elif self.status == 124:
            print("-- Timeout")
        else:
            print("-- Failed")

    def proc_linux_res(self):
        with open(self.output_file, "r") as f, open(self.output_file + ".html", "w") as o:
            o.write(fileheader)
            for line in f:
                line = re.sub(rf"@({self.filename}:(\d+))", rf"@<a href=\" {self.project.url}#L\2\">\1</a>", line)
                if "race with" in line:
                    o.write(f'<font color="red">{line.strip()}</font>\n')
                else:
                    o.write(line)
            o.write("</body>\n</html>\n")

    def to_dict(self):
        """Convert the Result object to a dictionary for JSON serialization."""
        return {
            "project": str(self.project),  # Assuming `project` has a `__str__` method
            "base": self.base,
            "filename": self.filename,
            "cmd": self.cmd,
            "analysis_name": self.analysis_name,
            "analysis_params": self.analysis_params,
            "start": self.start.isoformat() if isinstance(self.start, datetime) else self.start,
            "end": self.end.isoformat() if isinstance(self.end, datetime) else self.end,
            "duration": self.duration,
            "status": self.status,
            "output": self.output,
            "output_file": self.output_file,
        }


projects = [p for p in projects if not should_skip(p)]
results = []

for p in projects:

    if p.group != gname:
        gname = p.group
        print(gname)

    filepath = p.path
    dirname = os.path.dirname(filepath)
    filename = os.path.basename(filepath)
    os.chdir(dirname)
    base = os.path.splitext(filename)[0]

    remove_old_outfiles(base)
    p.generate_url()

    print(f"Analysing {filename} ({p.id}/{len(projects)})")

    for analysis_name, analysis_parameters in analyses:
        print(f"  {analysis_name.ljust(maxlen)}", end="", flush=True)

        starttime = datetime.now()

        cmd = [
            goblint,
            "--set", "dbg.timeout", str(timeout),
            *analysis_parameters.split(),
            filename,
            *p.params.split(),
            "--enable", "allglobs",
            "--enable", "dbg.timing.enabled"
        ]

        subprocess_result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        endtime = datetime.now()
        project_result = Result(
            p,
            base,
            filename,
            cmd,
            analysis_name,
            analysis_parameters,
            starttime,
            endtime,
            subprocess_result.stdout,
            subprocess_result.returncode
        )

        project_result.dump_output()
        project_result.print_status()
        print_html_file(p.id)
        project_result.proc_linux_res()

        results.append(project_result)


print_html_file(None)
print()
print(f"Results: {theresultfile}")

json_path = os.path.join(testresults, "results.json")

print(f"Writing results to {json_path}")
with open(json_path, "w") as f:
    json.dump([r.to_dict() for r in results], f, indent=2)
# Make a copy of result.json with the current timestamp
shutil.copy(json_path, os.path.join(testresults, f"results_{timestamp}.json"))

pickle_path = os.path.join(testresults, "results.pickle")
print(f"Writing results to {pickle_path}.pickle")
with open(pickle_path, "wb") as f:
    pickle.dump(results, f)
# Make a copy of result.pickle with the current timestamp
shutil.copy(pickle_path, os.path.join(testresults, f"results_{timestamp}.pickle"))
print("Done.")
