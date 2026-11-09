#!/usr/bin/env python
import os

env = SConscript("godot-cpp/SConstruct")
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

lib_name = "libtest.android.template_debug.arm64"
libpath = "bin/"

library = env.SharedLibrary(
    target=os.path.join(libpath, lib_name),
    source=sources,
)
Default(library)
