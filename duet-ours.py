from subprocess import PIPE
import subprocess
import re
import csv
import timeit
import os

abspath = os.path.abspath(__file__)
dname = os.path.dirname(abspath)
os.chdir(dname)

# with open("index/traces-relational.txt") as f:
with open("index/traces-rel-toy.txt") as f:
    with open("traces-relational-duet-ours.csv", "w") as csvf:
        c = csv.writer(csvf)
        c.writerow(["Name", "#Successful", "#Failed"])
        for line in f:
            line = line.strip()


            if line.startswith("Group: "):
                c.writerow(["", "", ""])
                c.writerow([line, "", ""])
                continue

            # if not (line.startswith("pthread/") or line.startswith("svcomp/")):
            if not line.startswith("traces-rel-toy/"):
                continue

            print(line)
            start = timeit.default_timer()
            p = subprocess.run(["../duet/duet.exe", "-coarsen", "-inline", "-domain", "oct", line],stdout=PIPE, stderr=PIPE)
            # p = subprocess.run(["/home/simmo/Desktop/duet/duet/duet.exe", "-coarsen", "-inline", "-parameterized", "-domain", "polka", line], capture_output=True)
            # p = subprocess.run(["/home/simmo/Desktop/duet/duet/duet.exe", "-proofspace", "-inline", line], capture_output=True)
            end = timeit.default_timer()
            print(f"time: {end-start}s")

            if p.returncode == 0:
                out = p.stdout.decode("utf-8")
                print(out)
                errors = re.search(r"(\d+) errors total", out).group(1)
                safe = re.search(r"(\d+) safe assertions", out).group(1)
                print(f"{safe}; {errors}")
                c.writerow([line, safe, errors])
            else:
                print("error")
                print(p.stdout)
                print(p.stderr)
                c.writerow([line])
