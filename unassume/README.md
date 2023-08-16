# Correctness Witness Validation by Abstract Interpretation
## Artifact

## Requirements
* VirtualBox.
* 2 CPU cores.
* 8 GB RAM.
* TODO GB disk space.
* TODO time.

## Layout
* `eval-prec/` — precision evaluation (script, benchmarks, witnesses).
* `eval-perf/` — performance evaluation (script, benchmarks, witnesses).
* `unassume.ova` — VirtualBox virtual machine.

  In `/home/vagrant` contains:
  * `goblint/` ­— Goblint with unassume support, including source code.
  * `CPAchecker-2.2-unix/` — CPAchecker from SV-COMP 2023 archives.
  * `UAutomizer-linux/` — Ultimate Automizer from SV-COMP 2023 archives.
  * `eval-prec/` — precision evaluation (same as above).
  * `eval-perf/` — performance evaluation (same as above).
  * `results/` — results (initially empty).

* `results/` — evaluation results tables with data used for the paper.
* `Vagrantfile` — Vagrant file used for generating above virtual machine.

## Reproduction
1. Import the virtual machine into VirtualBox.
2. Start the virtual machine and log in with username `vagrant` and password `vagrant`.
3. Run `startx` to start the graphical environment.
4. Open a terminal emulator, e.g. from dock at the bottom of the screen.

### Precision evaluation
1. Run `./eval-prec/run.sh` in the terminal emulator. This takes TODO time.
2. Run `firefox results/eval-prec/table-generator.table.html` to view the results.

   The HTML table contains the following status columns (cputime, walltime and memory can be ignored):
   1. Goblint w/o witness (true means verified).
   2. Goblint w/ manual witness (true means witness validated).
   3. Goblint w/ witness from CPAchecker (true means program verified with witness-guidance).
   4. Goblint w/ witness from CPAchecker (true means witness validated).
   5. Goblint w/ witness from UAutomizer (true means program verified with witness-guidance).
   6. Goblint w/ witness from UAutomizer (true means witness validated).

   Table 1 in the paper presents these results, except the rows are likely in a different order.


## Performance evaluation
1. Run `./eval-perf/run.sh` in the terminal emulator. This takes TODO time.
2. Run `firefox results/eval-perf/table-generator.table.html` to view the results.

   The HTML table contains the following relevant columns (others can be ignored):
   1. Goblint w/o witness, evals.
   2. Goblint w/o witness, cputime.
   3. Goblint w/ manual witness, evals.
   4. Goblint w/ manual witness, cputime.

   Table 2 in the paper presents these results, except the rows are likely in a different order.
