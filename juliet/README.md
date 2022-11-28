# Juliet Suite

Assuming goblint is located at `../../analyzer/goblint`, this script should work out of the box.
It downloads Juliet suite if not already available. By default it runs everything, but the result parsing only works for a few things...

For race detection, try `python3 juliet_summary.py C/testcases/CWE366_Race_Condition_Within_Thread`.

This simply runs the Juliet suite by executing commands for the positive and negative cases. These can also be called manually, such as:
* `goblint C/testcases/CWE366_Race_Condition_Within_Thread/CWE366_Race_Condition_Within_Thread__global_int_01.c C/testcasesupport/*.c -I C/testcasesupport --sets "mainfun[+]" CWE366_Race_Condition_Within_Thread__global_int_01_good`
* `goblint C/testcases/CWE366_Race_Condition_Within_Thread/CWE366_Race_Condition_Within_Thread__global_int_01.c C/testcasesupport/*.c -I C/testcasesupport --sets "mainfun[+]" CWE366_Race_Condition_Within_Thread__global_int_01_bad`

The script creates a summary table in this root directory, 
and the result files are stored inside `C/juliet_summary_fileoutputs/`.
