# Create Clang-Tidy Checks for mutations
In this document is described how you can create all the Clang-Tidy checks needed for generating the code mutations.

## Dependencies
For building Clang you need to install some dependencies:

 - `sudo apt install ninja-build`
 - `sudo apt install ccache`
 - `sudo apt install lld`

## Cloning the repository
 - There are two alternatives for getting the repository

RECOMENDED: You can clone the **Fork** with all the additional checks and options ready:
`git clone https://github.com/J2000A/llvm-project.git`

For creating all the checks and options by yourself clone the **Official Clang Repository**:
`git clone https://github.com/llvm/llvm-project.git` (Tested with Version 17.0.0)
Then you have to add the checks and options by yourself. You find a description of the needed modifications in [this file](MODIFICATIONS.md).

## Build
The first build can take a while (up to multiple hours). But you can increase the performance by changing the parallel compile and link jobs. For me using the value 5 for both of them got me the fastest results. When using too many jobs the memory becomes a bottleneck. You can check the memory status with `free -h --giga`.
Additionally, you may need to change the build target. Available targets are: AMDGPU, ARM, AVR, BPF, Hexagon, Lanai, LoongArch, Mips, MSP430, NVPTX, PowerPC, RISCV, Sparc, SystemZ, VE, WebAssembly, X86, XCore

 - Move to the directory `llvm-project/`
 - `mkdir build && cd build`
 - `cmake -G "Ninja" -DLLVM_CCACHE_BUILD=ON -DCMAKE_BUILD_TYPE=Release -DLLVM_USE_LINKER=lld -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" -DLLVM_TARGETS_TO_BUILD="X86" -DLLVM_PARALLEL_COMPILE_JOBS=5 -DLLVM_PARALLEL_LINK_JOBS=5 ../llvm`
 - `sudo ninja install`

## Running Clang-Tidy
We will use the **>>check-name<<** again as defined in "Creating the checks".

**Example:** Create the mutation "remove function body" on a file "test.c" in lines "4" and "14" when the function name is "foo":
`clang-tidy -checks=-*,readability-remove-function-body -fix --fix-errors -config="{CheckOptions: {readability-remove-function-body.RemoveOnlyFunctionName: 'foo'}}" -line filter='[{"name":"test.c","lines":[[4,4],[14,14]]}]' test.c --`

**The command consists of the following components:**
 - Clang-Tidy
`clang-tidy` The command itself.

 - General Options
 `-checks=-*,readability->>check-name<<` Deactivating all checks except >>check-name<<.
`-fix` Applying the mutations and fail in case of found compiler errors.
`--fix-warnings` Apply the mutation to warnings and ignore found compiler errors.
`--quiet-return` Return 0 instad of 1 in case of found compiler warnings and do quiet printing.
`-line filter='[{"name":"test.c","lines":[[4,4],[14,14]]}]'` Apply the mutations only on line 4 and 14.

 - Special Options
`-config="{CheckOptions: {readability-remove-function-body.RemoveOnlyFunctionName: 'foo1, foo2'}}"` Special option for the **remove-function-body** check to only remove the function body of functions named foo1 and foo2.

 - Filename
`test.c --` The filename.

## Mutations
You find more details about the different mutation operators in the [Mutations](MUTATIONS.md) file.

## Workflow
First run the check without the fix flag, but with `--quiet-return` to see where mutations are possible without applying them. Remember the lines where you actually want to apply the mutation. Make a copy of the input file that you will mutate. Then run the check again with `--fix-warnings` and `-line filter=...` on the copied file to apply only specific mutations and not all at ones.

## Develop new matchers
Use the clang querry tool in the [godbolt compiler](https://godbolt.org/) explorer with for example this input to try out your matchers for the clang-tidy checks.
```
enable output srcloc
m stmt(ifStmt())
```
