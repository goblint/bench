#!/usr/bin/python3

from pathlib import Path
import zipfile
import shutil


source_path = Path("linux-5.5-races-raw")
target_path = Path("linux-5.5-races")

target_path.mkdir(exist_ok=True)

for task_zip_path in source_path.glob("**/*.zip"):
    task_path = task_zip_path.relative_to(source_path).with_suffix("")
    print(task_path)

    (target_path / task_path).parent.mkdir(parents=True, exist_ok=True)

    with zipfile.ZipFile(task_zip_path) as task_zip:
        with task_zip.open("cil.i", mode="r") as task_source_file:
            task_target_path = target_path / (task_path.parent / (task_path.name + ".i"))
            with task_target_path.open("wb") as task_target_file:
                shutil.copyfileobj(task_source_file, task_target_file)

    task_def_path = target_path / (task_path.parent / (task_path.name + ".yml"))
    with task_def_path.open("w") as task_def_file:
        EXPECTED_VERDICT = {
            "Safes": "true",
            "Unknowns": "unknown",
            "Unsafes": "false",
        }
        expected_verdict = EXPECTED_VERDICT[task_path.parts[0]]
        task_def_file.write(rf"""format_version: '1.0'

input_files: '{task_path.name + ".i"}'

properties:
  - property_file: ../no-data-race.prp
    expected_verdict: {expected_verdict}
""")
