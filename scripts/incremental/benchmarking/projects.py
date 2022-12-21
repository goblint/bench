import os
import datetime

class ProjectConfig:
    url: str
    repo_name: str
    build_compdb: str
    conf_base: str
    conf_incrpost: str
    begin: datetime.datetime
    to: datetime.datetime
    diff_exclude: list # list[str]
    '''Files to analyze. If this list is not empty, the given files will be analyzed (not those in the compiledb)'''
    files: list # list[str]
    branch: str

    def __init__(self, url, repo_name, build_compdb, conf_base, conf_incrpost, begin, to, diff_exclude, files, branch):
        self.url = url
        self.repo_name = repo_name
        self.build_compdb = build_compdb
        self.conf_base = conf_base
        self.conf_incrpost = conf_incrpost
        self.begin = begin
        self.to = to
        self.diff_exclude = diff_exclude
        self.files = files
        self.branch = branch

sqlite = ProjectConfig(
    url           = "https://github.com/sqlite/sqlite",
    repo_name     = "sqlite",
    build_compdb  = "../build/build_compdb_sqlite.sh",
    conf_base     = os.path.join("custom", "sqlite-minimal"), # very minimal: "zstd-minimal"
    conf_incrpost = os.path.join("custom", "sqlite-minimal-incrpostsolver"),
    begin         = datetime.datetime(2021,8,1),
    to            = datetime.datetime(2021,8,10), # minimal subset: datetime(2021,8,4)
    diff_exclude  = ["build", "doc", "examples", "tests", "zlibWrapper", "contrib"],
    files = ['sqlite3.c', 'sqlite3.h', 'sqlite3ext.h', 'shell.c'],
    branch = "master"
)

zstd = ProjectConfig(
    url           = "https://github.com/facebook/zstd",
    repo_name     = "zstd",
    build_compdb  = "../build/build_compdb_zstd.sh",
    conf_base     = os.path.join("custom", "zstd-race"), # very minimal: "zstd-minimal"
    conf_incrpost = os.path.join("custom", "zstd-race-incrpostsolver"),
    begin         = datetime.datetime(2021,8,1), # very minimal: "zstd-minimal"
    to            = datetime.datetime(2022,2,1), # minimal subset: datetime(2021,8,4)
    diff_exclude  = ["build", "doc", "examples", "tests", "zlibWrapper", "contrib"],
    files = None,
    branch = "dev"
)

figlet = ProjectConfig(
    url           = "https://github.com/cmatsuoka/figlet",
    repo_name     = "figlet",
    build_compdb  = None,
    conf_base     = os.path.join("custom", "figlet"),
    conf_incrpost = os.path.join("custom", "figlet-incrpostsolver"),
    begin         = datetime.datetime(2010,1,1),
    to            = datetime.datetime(2022,10,10),
    diff_exclude  = [],
    files = ['Makefile'],
    branch = "master"
)

chrony = ProjectConfig(
    # Official repo is at https://git.tuxfamily.org/chrony/chrony.git,
    # but does not allow multiple parallel clones. So use mirror on GitHub.
    url="https://github.com/mlichvar/chrony.git",
    repo_name="chrony",
    build_compdb="../build/build_compdb_chrony.sh",
    conf_base=os.path.join("custom", "chrony"),
    conf_incrpost=os.path.join("custom", "chrony-incrpostsolver"),
    begin=datetime.datetime(2020, 1, 1),
    to=datetime.datetime(2022, 10, 10),
    diff_exclude=[],
    files=None,
    branch = "master"
)

projects = {"sqlite": sqlite, "chrony": chrony, "figlet": figlet, "zstd": zstd}
