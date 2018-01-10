# conditional extension compilation
Sometimes when you want to make a Python extension with C or C++ code you have a situation
where compilation of this code might be heavily dependent on hardware specific compiler flags or preprocessor options.
This often occurs when wrapping an external library that wasn't written with python in mind.

Generally speaking if you have the ability to compile on your own machine you can compile with something like `-march=native` and call it a day.
If however you cannot compile on the platform you are running on then you have to jump through some hoops.
This package seeks to figure out how to compile Python extensions for non native targets and help avoid hoops to jump through.
This way you can compile ahead of time then package up your binaries and run them on the platforms you built for without having to build on the target.

Note that there are 2 levels of compilation here one level to compile the library and another to create the Python CAPI that wraps that library.
