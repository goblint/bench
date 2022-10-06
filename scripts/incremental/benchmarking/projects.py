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

    def __init__(self, url, repo_name, build_compdb, conf_base, conf_incrpost, begin, to, diff_exclude, files):
        self.url = url
        self.repo_name = repo_name
        self.build_compdb = build_compdb
        self.conf_base = conf_base
        self.conf_incrpost = conf_incrpost
        self.begin = begin
        self.to = to
        self.diff_exclude = diff_exclude
        self.files = files

sqlite = ProjectConfig(
    url           = "https://github.com/sqlite/sqlite",
    repo_name     = "sqlite",
    build_compdb  = "../build/build_compdb_sqlite.sh",
    conf_base     = os.path.join("custom", "sqlite-minimal"), # very minimal: "zstd-minimal"
    conf_incrpost = os.path.join("custom", "sqlite-minimal"), #TODO: Use incremental postprocessing,
    begin         = datetime.datetime(2021,8,1),
    to            = datetime.datetime(2021,8,10), # minimal subset: datetime(2021,8,4)
    diff_exclude  = ["build", "doc", "examples", "tests", "zlibWrapper", "contrib"],
    files = ['sqlite3.c', 'sqlite3.h', 'sqlite3ext.h', 'shell.c']
)

zstd = ProjectConfig(
    url           = "https://github.com/facebook/zstd",
    repo_name     = "zstd",
    build_compdb  = "../build/build_compdb_zstd.sh",
    conf_base     = os.path.join("custom", "zstd-race-baseline"), # very minimal: "zstd-minimal"
    conf_incrpost = os.path.join("custom", "zstd-race-incrpostsolver"),
    begin         = datetime.datetime(2021,8,1), # very minimal: "zstd-minimal"
    to            = datetime.datetime(2021,10,10), # minimal subset: datetime(2021,8,4)
    diff_exclude  = ["build", "doc", "examples", "tests", "zlibWrapper", "contrib"],
    files = None
)

projects = {"sqlite": sqlite, "zstd": zstd}
