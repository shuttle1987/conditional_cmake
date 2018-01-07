# conditional_cmake
Sometimes when you want to make a Python extension with C or C++ code you have a situation
where compilation of this code might be heavily dependent on compiler flags or preprocessor options.

This repo seeks to figure out how to conditionally compile extensions based on flags passed to the compiler.
