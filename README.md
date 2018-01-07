# conditional_cmake
Sometimes when you want to make a Python extension with C or C++ code you have a situation
where compilation of this code might be heavily dependent on compiler flags or preprocessor options.
This often occurs when wrapping an external library that wasn't written with python in mind.

This repo seeks to figure out how to conditionally compile extensions based on flags passed to the compiler.

Note that there are 2 levels of compilation here one level to compile the library and another to create the Python CAPI that wraps that library.
