#!/usr/bin/env python
import os
import sys

# The name of your final library
env = SConscript("godot-cpp/SConstruct")

# Tell SCons where to put the final .so file
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

# Build the shared library
library = env.SharedLibrary(
    "demo/bin/libtest{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources,
)

Default(library)
