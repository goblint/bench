#!/usr/bin/python3

import sys
from pathlib import Path
from enum import Enum
import re
import json


arg_paths = []
arg_defines = []
for arg in sys.argv[1:]:
    if arg.startswith("-D"):
        arg_defines.append(arg)
    else:
        arg_paths.append(arg)


module_path = Path(arg_paths[0])
print(module_path)
other_paths = list(map(Path, arg_paths[1:]))

module_init = None
module_exit = None

class DriverType(Enum):
    CHAR = 1
    BLOCK = 2

driver_type = None
driver_type_pci = False

with module_path.open() as module_file:
    for line in module_file:
        m = re.match(r"^ *module_init\(([^)]*)\)", line)
        if m:
            module_init = m.group(1)
        m = re.match(r"^ *module_exit\(([^)]*)\)", line)
        if m:
            module_exit = m.group(1)
        m = re.match(r"^ *#include(.*)", line)
        if m:
            include = m.group(1)
            if "<linux/miscdevice.h>" in include or "<linux/cdev.h>" in include:
                driver_type = DriverType.CHAR
            if "<linux/blkdev.h>" in include:
                driver_type = DriverType.BLOCK
            if "<linux/pci.h>" in include:
                driver_type_pci = True

assert module_init is not None
assert module_exit is not None
assert driver_type is not None


main_path = module_path.with_suffix(".main.c")
with main_path.open("w") as main_file:
    main_file.write(f"""#include <ddverify/ddverify.h>
#include "{module_path.name}"

int main() {{
    _ddv_module_init = {module_init};
    _ddv_module_exit = {module_exit};
    call_ddv();

    return 0;
}}
""")

model_path = Path("models/goblint")

# main program includes module itself
files = [main_path] + other_paths + sorted((model_path / "src").glob("**/*.c"))

# -m32 needed for size_t and pthread sizes to match
cppflags = ["-m32", "-D__KERNEL__", "-DMODULE"]
if driver_type == DriverType.CHAR:
    cppflags.append("-DDRIVER_TYPE_CHAR")
elif driver_type == DriverType.BLOCK:
    cppflags.append("-DDRIVER_TYPE_BLOCK")
if driver_type_pci: # no elif!
    cppflags.append("-DDRIVER_TYPE_PCI")
cppflags += arg_defines

goblint_conf = {
    "files": list(map(str, files)),
    "pre": {
        "includes": [str(model_path / "include")],
        "cppflags": cppflags
    },
    "ana": {
        "sv-comp": {
            "functions": True
        }
    },
    "sem": {
        "unknown_function": {
            "invalidate": {
                "globals": False
            },
            "spawn": False
        }
    }
}

conf_path = Path("goblint") / "conf" / (module_path.stem + ".json")
with open(conf_path, "w") as conf_file:
    json.dump(goblint_conf, conf_file, indent=4)
