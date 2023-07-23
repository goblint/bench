import os
import sys
import math
import shutil
from pathlib import Path
import subprocess
from pydriller import Git
import re
import pandas
import json
import numpy as np
import brokenaxes
import matplotlib as mpl
import matplotlib.ticker as mticker

mpl.use("pgf")
mpl.rcParams.update({
    "pgf.texsystem": "pdflatex",
    'pgf.rcfonts': False,
    'text.usetex': True,
    'font.family': 'serif',
    'font.size': 6,
    'axes.titlesize': 6,
    'legend.fontsize': 6,
    'figure.titlesize': 7,
    'figure.dpi': 300,
    'xtick.labelsize': 6,
    'ytick.labelsize': 6,

})
import matplotlib.pyplot as plt
from matplotlib.ticker import ScalarFormatter

runtime_prefix = "Runtime"
analysis_prefix = "Analysis"
solving_prefix = "Solving"

header_parent = " for parent commit (non-incremental)"
header_non_incr_child = " for commit (non-incremental)"
header_incr_child = " for commit (incremental)"
header_incr_posts_child = " for commit (incremental + incr postsolver)"
header_incr_posts_rel_child = " for commit (incremental + incr postsolver + reluctant)"

runtime_header_parent = runtime_prefix + header_parent
runtime_header_non_incr_child = runtime_prefix + header_non_incr_child
runtime_header_incr_child = runtime_prefix + header_incr_child
runtime_header_incr_posts_child = runtime_prefix + header_incr_posts_child
runtime_header_incr_posts_rel_child = runtime_prefix + header_incr_posts_rel_child

cpu_prefix = "CPU_"

cpu_runtime_header_parent = cpu_prefix + runtime_header_parent
cpu_runtime_header_non_incr_child = cpu_prefix + runtime_header_non_incr_child
cpu_runtime_header_incr_child = cpu_prefix + runtime_header_incr_child
cpu_runtime_header_incr_posts_child = cpu_prefix + runtime_header_incr_posts_child
cpu_runtime_header_incr_posts_rel_child = cpu_prefix + runtime_header_incr_posts_rel_child

analysis_header_parent = analysis_prefix + header_parent
analysis_header_non_incr_child = analysis_prefix + header_non_incr_child
analysis_header_incr_child = analysis_prefix + header_incr_child
analysis_header_incr_posts_child = analysis_prefix + header_incr_posts_child
analysis_header_incr_posts_rel_child = analysis_prefix + header_incr_posts_rel_child

solving_header_parent = solving_prefix + header_parent
solving_header_non_incr_child = solving_prefix + header_non_incr_child
solving_header_incr_child = solving_prefix + header_incr_child
solving_header_incr_posts_child = solving_prefix + header_incr_posts_child
solving_header_incr_posts_rel_child = solving_prefix + header_incr_posts_rel_child

preparelog = "prepare.log"
analyzerlog = "analyzer.log"
compare_runs_suffixes = ["incr", "incr_post", "incr_rel_post"]

def comparelog_with_suffix (suffix):
    return "compare_" +suffix + ".log"

def reset_incremental_data(incr_data_dir):
    if os.path.exists(incr_data_dir) and os.path.isdir(incr_data_dir):
        shutil.rmtree(incr_data_dir)

def analyze_commit(analyzer_dir, gr : Git, repo_path, build_compdb, commit_hash, outdir, conf, extra_options, files):

    gr.checkout(commit_hash)
    conf_path = conf

    # Creat the analyze command
    file_list = []
    if files:
        def append_to_repo_path(file):
            return os.path.join(repo_path, file)
        file_list = list(map(append_to_repo_path, files))

    analyze_command = [os.path.join(analyzer_dir, 'goblint'), '--conf', conf_path, *file_list, *extra_options]
    # If the list of files was empty, we pass the repo_path to goblint
    if not files:
        analyze_command.append(repo_path)

    # print configuration and analyze command
    with open(outdir+'/config.out', "a+") as file:
        with open(conf_path, "r") as c:
            file.write("config: " + c.read())
            file.write("\n")
            file.write("added options:\n")
            for o in extra_options:
                file.write(o + " ")
            file.write("\n\n")

            file.write("analyze command:\n")
            for c in analyze_command:
                file.write(c + " ")
            file.write("\n\n")

            file.write("Commit hash:\n" + commit_hash + "\n")
            file.close()

    script_path = os.path.abspath(os.path.dirname(__file__))

    # Prepare the repo
    if build_compdb != None:
        prepare_command = ['sh', os.path.join(script_path, build_compdb)]
        with open(os.path.join(outdir, preparelog), "w+") as outfile:
            subprocess.run(prepare_command, cwd = gr.path, check=True, stdout=outfile, stderr=subprocess.STDOUT)
            outfile.close()

    # Run the analysis
    with open(os.path.join(outdir, analyzerlog), "w+") as outfile:
        subprocess.run(analyze_command, check=True, stdout=outfile, stderr=subprocess.STDOUT)
        outfile.close()

def compare_runs(analyzer_dir, dummy_c_file, outdir, log_suffix, conf, compare_data_1, compare_data_2):
    options = ['--conf', conf, '--disable', 'warn.warning', '--disable', 'warn.race', '--disable', 'dbg.compare_runs.diff', '--disable', 'dbg.compare_runs.eqsys', '--enable', 'dbg.compare_runs.node', '--compare_runs', compare_data_1, compare_data_2]
    analyze_command = [os.path.join(analyzer_dir, 'goblint'), *options, dummy_c_file]
    with open(os.path.join(outdir, comparelog_with_suffix(log_suffix)), "w+") as outfile:
        subprocess.run(analyze_command, check=True, stdout=outfile, stderr=subprocess.STDOUT)
        outfile.close()

def calculateRelCLOC(repo_path, commit, diff_exclude):
    diff_exclude = list(map(lambda x: os.path.join(repo_path, x), diff_exclude))
    relcloc = 0
    for f in commit.modified_files:
        _, extension = os.path.splitext(f.filename)
        if not (extension == ".h" or extension == ".c"):
            continue
        filepath = f.new_path
        if filepath is None:
            filepath = f.old_path
        parents = Path(filepath).parents
        parents = list(map(lambda x: os.path.join(repo_path, x), parents))
        if any(dir in parents for dir in diff_exclude):
            continue
        relcloc = relcloc + f.added_lines + f.deleted_lines
    return relcloc

def find_line(pattern, log):
    with open (log, 'r') as file:
        for line in file:
            m = re.search(pattern, line)
            if m:
                file.close()
                return m.groupdict()
        return None

def extract_from_analyzer_log(log):
    # First comes the cpu time (which is ignored); we look at the walltime.
    runtime_pattern = 'Default[ ]+(?P<CPU_runtime>[0-9\.]+)s[ ]+(?P<runtime>[0-9\.]+)s'
    analysis_time_pattern = 'analysis[ ]+(?P<CPU_analysis_time>[0-9\.]+)s[ ]+(?P<analysis_time>[0-9\.]+)s'
    solving_time_pattern = 'solving[ ]+(?P<CPU_solving_time>[0-9\.]+)s[ ]+(?P<solving_time>[0-9\.]+)s'
    change_info_pattern = 'change_info = { unchanged = (?P<unchanged>[0-9]*); changed = (?P<changed>[0-9]*) \\(with unchangedHeader = (?P<changed_unchanged_header>[0-9]*)\\); added = (?P<added>[0-9]*); removed = (?P<removed>[0-9]*) }'

    runtime = find_line(runtime_pattern, log)

    analysis_time = find_line(analysis_time_pattern, log)
    solving_time = find_line(solving_time_pattern, log)
    ch = find_line(change_info_pattern, log) or {"unchanged": 0, "changed": 0, "added": 0, "removed": 0}
    d = dict(list(runtime.items()) + list(analysis_time.items()) + list(solving_time.items()) + list(ch.items()))
    with open(log, "r") as file:
        num_racewarnings = file.read().count('[Warning][Race]')
        d["race_warnings"] = num_racewarnings
        file.close()
    return d

def extract_precision_from_compare_log(log):
    pattern = "equal: (?P<equal>[0-9]+), more precise: (?P<moreprec>[0-9]+), less precise: (?P<lessprec>[0-9]+), incomparable: (?P<incomp>[0-9]+), total: (?P<total>[0-9]+)"
    precision = find_line(pattern, log)
    return {k: int(v) for k,v in precision.items()} if precision else None

def precision_result_file_name_with_suffix(suffix):
    result_file_name = "results_" + suffix + ".json"
    return result_file_name

def barplot(df, figure_dir, outfile, figsize=None, colors=None):
    df.plot.bar(rot=0, width=0.7, figsize=figsize, color=colors)
    plt.xticks(rotation=45, ha='right', rotation_mode='anchor')
    plt.xlabel('Commit')
    plt.tight_layout()

    outfile = os.path.join(figure_dir, outfile)
    plt.savefig(outfile)

def get_cleaned_filtered_data(result_csv_file, changed_loc_filter, filterRelCLOC=False,  filterDetectedChanges=False):
    df = pandas.read_csv(result_csv_file, index_col='Commit', sep=";")
    df = df.loc[:, ~df.columns.str.contains('^Unnamed')]

    # clean dataset (remove all rows for which any of the runtime entries is 0 which means that the respective analysis
    # run failed)
    df = df[(df[runtime_header_parent] != 0)]
    df = df[changed_loc_filter(df["Relevant changed LOC"])]
    if filterRelCLOC:
        df = df[df["Relevant changed LOC"] > 0]
    if filterDetectedChanges:
        df = df[df["Changed/Added/Removed functions"] > 0]
    return df

def get_data_from_json(result_file):
    with open(result_file) as f:
        d = json.load(f)
    df=pandas.json_normalize(d['seq_summary'])
    return df

def create_cum_data(dataFrame, num_bins, relColumns):
    min = dataFrame[relColumns].min().min()
    max = dataFrame[relColumns].max().max()
    bins = np.linspace(min,max,num=num_bins+1)
    data = []
    base = []
    for c in relColumns:
        valuesc, basec = np.histogram(dataFrame.loc[:,c], bins=bins)
        base = basec
        cum = np.cumsum(valuesc, dtype=float)
        cum[cum==0] = np.nan

        # If there is a tail of values that are the same, set the ones after its first occurrence to NaN.
        # In the resulting graph, this avoids the artefact that all the lines go up to the largest y-value of any line.
        last = len(cum) - 1
        last_value = cum[last]
        for i in range(last - 1 , 0, -1):
            if cum[i] == last_value:
                cum[i + 1] = np.nan
            else:
                break

        data = data + [cum]
    return data, base[:-1]

def largest_power_of_two_smaller(x):
    p = math.floor(math.log2(x)) - 1
    p = max(1, p)
    2 ** p

def cummulative_distr_plot(data_sets, base, figure_dir, outfile, figsize=None, title=None, logscale=False):
    if figsize:
        plt.figure(figsize=figsize)
    else:
        plt.figure()
    min = sys.maxsize

    linestyle_tuple = [
        "solid",
        "--",
        (0, (10, 1)), # long dash
        (0, (3, 1, 1, 1)) # dash dots
    ]
    for d in data_sets:
        min_d = d["values"].min()
        if min_d < min:
            min = min_d
        plt.plot(d["values"], base, linestyle=linestyle_tuple.pop(0), label=d["label"])
    plt.xlabel('Number of Commits')
    if logscale:
        plt.ylabel('Runtime in s ($log_{2}$ scale)')
        plt.yscale('log', base=2)
        plt.gca().yaxis.set_major_formatter(ScalarFormatter())
        plt.xlim(left=0)
        plt.ylim(bottom=largest_power_of_two_smaller(min))
        #plt.yticks(np.arange(100,1500,100))
    else:
        plt.ylabel('Runtime in s')
    plt.tight_layout()
    plt.legend()
    plt.title(title)

    outfile = os.path.join(figure_dir, outfile)
    plt.savefig(outfile)

def hist_plot(data, step, title, xlabel, ylabel, outfile, size, xlim_left=None, xlim_right=None, cutoffs=None):
    min = data.min()
    max = data.max()
    min = min//step
    max = max//step + 1
    bins = np.arange(min*step,(max+1)*step,step)

    if cutoffs:
        plt.figure()
        bax = brokenaxes.brokenaxes(ylims=cutoffs, hspace=0.05, left = 0.18, bottom = 0.16)
        bax.hist(data, bins, histtype='bar')
        plt.xlabel(xlabel, labelpad=0)
        plt.ylabel(ylabel, labelpad=0)
        if title: plt.title(title)
        plt.savefig(outfile, bbox_inches='tight')
    else:
        fig = plt.figure()
        width, height = size
        fig.set_size_inches(w=width, h=height)
        plt.hist(data, bins)
        if xlim_left:
            plt.xlim(left=xlim_left, right=xlim_right)
        else:
            plt.xlim(right=xlim_right)
        if xlabel: plt.xlabel(xlabel)
        if ylabel: plt.ylabel(ylabel)
        if title: plt.title(title)
        plt.tight_layout(pad=0.4)
        plt.savefig(outfile)

def hist_subplots(ax, data, step):
    min = data.min()
    max = data.max()
    min = min//step
    max = max//step + 1
    bins = np.arange(min*step,(max+1)*step,step)
    ax.hist(data, bins)

def four_hist_subplots(data, title, xlabel, ylabel, outfile):
    step = 0.01
    fig, ((ax1,ax2),(ax3,ax4)) = plt.subplots(2,2,tight_layout=True)
    for i, ax in enumerate([ax1,ax2,ax3,ax4]):
        hist_subplots(ax, data, step)
        ax.title.set_text(title[i])
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.tight_layout()
    fig.savefig(outfile)

def scatter_plot(data, xlabel, ylabel, outfile, size):
    fig = plt.figure()
    width, height = size
    fig.set_size_inches(w=width, h=height)
    colors=['red','azure','blue','brown','chartreuse','chocolate','darkblue','darkgreen','seagreen','green','indigo','orangered','orange','coral','olive','mediumseagreen','grey','teal']
    #markers = ['x','+','o','s','p','*','D','d','v','^','<','>','1','2','3','4','H','P']
    linestyles = ['dashed']
    for i, (x, y) in enumerate(data):
        plt.plot(x,y, marker='x', linewidth=0.4, markersize=1, alpha=0.85, color=colors[i % len(colors)], linestyle=linestyles[i % len(linestyles)])
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.gca().xaxis.set_major_locator(mticker.MultipleLocator(1))
    # plt.xticks([1,2,5,10,15])
    plt.ylim(bottom=-0.005, top=0.3)
    plt.tight_layout(pad=0.4)
    plt.savefig(outfile)

def box_plot(data, x, xlabel, ylabel, outfile, size):
    fig = plt.figure()
    width, height = size
    fig.set_size_inches(w=width, h=height)
    plt.boxplot(data, flierprops=dict(markersize=3), positions=x)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.tight_layout(pad=0.4)
    plt.savefig(outfile)
    print(outfile)
