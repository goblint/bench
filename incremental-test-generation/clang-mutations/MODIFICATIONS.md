# Creating the checks
 - When you cloned the Official Clang Repository you need to add the checks. Otherwise, you can skip this part.
 - Move to the directory `llvm-project/clang-tools-extra`

In this directory are the implementations of the checks with their corresponding `.cpp` and `.h` file. In the following we will use the **>>check-name<<** of each check. You can get it by the filename without the word "Check" at the end and changing the capital letters to small ones with a minus in front (e.g. the >>check-name<< of `RemoveFunctionBodyCheck.cpp` is `remove-function-body`). Repeat the following steps for all new checks.

 - Run `clang-tidy/add_new_check.py readability >>check-name<<`
 - Replace `./clang-tidy/readability/>>check-name<<.cpp` with the implementation in this directory
 - Replace `./clang-tidy/readability/>>check-name<<.h` with the header file in this directory

Now you have added all the check we need for the mutations.

# Adding the options
- Move to the directory `llvm-project/`
- For adding the new clang-tidy options `fix-warnings` and `quiet-return` replace the following files with the implementation in this directory:
- Replace `./clang-tools-extra/clang-tidy/ClangTidy.cpp`
- Replace `./clang-tools-extra/clang-tidy/ClangTidy.h`
- Replace `./clang-tools-extra/clang-tidy/tool/ClangTidyMain.cpp`
- Replcae `./clang-tools-extra/docs/clang-tidy/index.rst`
