# Correctness Witness Validation by Abstract Interpretation
## Artifact

## Requirements
* VirtualBox.
* 2 CPU cores.
* 8 GB RAM.
* 7 GB disk space.
* ~45min.

## Layout
* `README.md`/`README.pdf` — this file.
* `LICENSE`.
* `unassume.ova` — VirtualBox virtual machine.

  In `/home/vagrant` contains:
  * `goblint/` ­— Goblint with unassume support, including source code.
  * `CPAchecker-2.2-unix/` — CPAchecker from SV-COMP 2023 archives.
  * `UAutomizer-linux/` — Ultimate Automizer from SV-COMP 2023 archives.
  * `eval-prec/` — precision evaluation (script, benchmarks, manual witnesses).
  * `eval-perf/` — performance evaluation (script, benchmarks, manual witnesses).
  * `results/` — results (initially empty).

* `results/` — evaluation results tables with data used for the paper.

## Reproduction
1. Import the virtual machine into VirtualBox.
2. Start the virtual machine and log in with username "vagrant" (not "Ubuntu"!) and password "vagrant".
3. Right click on the desktop and open Applications → Accessories → Terminal Emulator.

### Precision evaluation
1. Run `./eval-prec/run.sh` in the terminal emulator. This takes ~42min.
2. Run `firefox results/eval-prec/table-generator.table.html` to view the results.

   The HTML table contains the following status columns (cputime, walltime and memory can be ignored):
   1. Goblint w/o witness (true means verified).
   2. Goblint w/ manual witness (true means witness validated).
   3. Goblint w/ witness from CPAchecker (true means program verified with witness-guidance).
   4. Goblint w/ witness from CPAchecker (true means witness validated).
   5. Goblint w/ witness from UAutomizer (true means program verified with witness-guidance).
   6. Goblint w/ witness from UAutomizer (true means witness validated).

   Table 1 in the paper presents these results, except the rows are likely in a different order.

### Performance evaluation
1. Run `./eval-perf/run.sh` in the terminal emulator. This takes ~30s.
2. Run `firefox results/eval-perf/table-generator.table.html` to view the results.

   The HTML table contains the following relevant columns (others can be ignored):
   1. Goblint w/o witness, evals.
   2. Goblint w/o witness, cputime.
   3. Goblint w/ manual witness, evals.
   4. Goblint w/ manual witness, cputime.

   Table 2 in the paper presents these results, except the rows are likely in a different order.
