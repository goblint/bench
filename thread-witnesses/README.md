# Thread-Modular Correctness Witnesses and their Validation
## An Abstract Interpretation Perspective

### Layout
* `autoactive/plain` — programs and GraphML witnesses from AutoActive artifact.
* `autoactive/generated_yaml` — converted YAML witnesses.
* `bench` — this repository.
* `benchexec` — BenchExec version.
* `CPAchecker-2.2-unix` — CPAchecker from SV-COMP 2023 archives.
* `ourtool` — our tool, including source code. **NB! Although git authorship has been stripped, the contents of this directory do reveal the unanonymized tool name.**
* `results` — results directory for scripts.
* `sv-benchmarks` — SV-COMP 2022 benchmarks, at least ReachSafety-Loops.
* `UAutomizer-linux` — Ultimate Automizer from SV-COMP 2023 archives.

### Scripts
* `./st-same/run.sh` — single-threaded programs, same-framework.
* `./st-cross/witnessToYaml.sh` — convert single-threaded cross-framework witnesses from GraphML to YAML (very slow!).
* `./st-cross/run.sh` — single-threaded programs, cross-framework.
* `./st-lit/run.sh` — single-threaded programs from literature.
* `./mt/run.sh` — multi-threaded programs, same- and cross-framework.
