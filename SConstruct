#!/usr/bin/env python
import os

env = SConscript("godot-cpp/SConstruct")
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

# Force the file to the root directory
lib_name = "libtest.android.template_debug.arm64"

library = env.SharedLibrary(
    target=lib_name,
    source=sources,
)
Default(library)
