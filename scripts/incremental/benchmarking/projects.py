import os
import datetime

from dataclasses import dataclass

@dataclass
class ProjectConfig:
    url: str
    repo_name: str
    build_compdb: str
    conf_base: str
    conf_incrpost: str
    begin: datetime.datetime
    to: datetime.datetime
    diff_exclude: list[str]
    '''Files to analyze. If this list is not empty, the given files will be analyzed (not those in the compiledb)'''
    files: list[str]

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
    to            = datetime.datetime(2021,8,10), # minimal subset: datetime(2021,8,4)
    diff_exclude  = ["build", "doc", "examples", "tests", "zlibWrapper", "contrib"],
    files = None
)

projects = {"sqlite": sqlite, "zstd": zstd}
