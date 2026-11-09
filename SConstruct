#!/usr/bin/env python
import os

env = SConscript("godot-cpp/SConstruct")
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

# Force the file to be named exactly this
lib_name = "libtest.android.template_debug.arm64"
libpath = "build/" # <--- CHANGED TO BUILD FOLDER

library = env.SharedLibrary(
    target=os.path.join(libpath, lib_name),
    source=sources,
)
Default(library)
