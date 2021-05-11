# Zimbu Makefile settings for MingW on MS-Windows
#
# Copyright 2010 Bram Moolenaar  All Rights Reserved
# Licensed under the Apache License, Version 2.0.  See the LICENSE file or
# obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
#
###################################################################
# Change lines in this block to match your environment.
# NOTE: The defaults assume you are using the MinGw make program, which
# requires using Unix-like commands.  If you get an error for "cp" then you
# either need to install the MinGw MSYS tools or use copy.

# Specify the C compiler to be used.
COMPILER = gcc

# Optional arguments for the compiler
# "-g" causes errors, "-ggdb" appears to work.
# Using a bit more than 2Gbyte requires large-address-aware
CCARG = -Wall -Wno-unused -Wno-sequence-point -Wl,--large-address-aware -ggdb

# This should work for clang with MinGw libraries.
# COMPILER = clang
# CCARG = -Wall -Wno-unused -Wno-parentheses -Wno-parentheses-equality -ggdb

# Specify the command to copy a file, overwriting the destination.
# COPY = copy
COPY = cp -f

# Specify the command to copy a file, NOT overwriting the destination.
# COPYN = copy /-y
COPYN = cp -n

# Make a file readonly
READONLY = attrib +r

# Make a file writable
WRITABLE = attrib -r

# Specify the command to concatenate several files into stdout.
CAT = cat

# Diff command that ignores CR-LF vs LF differences
DIFF = diff -a --strip-trailing-cr

# Specify the command to create a directory, silent when already existing.
MKDIR = mkdir

# Specify the command to use to unconditionally remove files.
# RMCMD = del
RMCMD = rm

# Specify the command to rename a file.
RENAME = mv
#RENAME = cmd /c move

# Comment out when posix threads and sockets are not available.
TESTMORE = test_more

# Put in front of executable in current directory.
CURDIR = .\\

# Put after executable name.
EXE = .exe

# Put after object file name.
OBJ = .obj

# In sub-directories use this makefile
MAKEFILEARG = -f MakeMing.mak

# Default name for Node.js executable.  When not set zimbuConfig will attempt
# to find it.
# NODEJS = node

# Default name for the JVM.
JAVA = java
