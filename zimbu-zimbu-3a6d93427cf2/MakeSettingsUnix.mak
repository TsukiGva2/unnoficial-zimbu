# Zimbu Makefile settings for Unix and Mac.
#
# Copyright 2010 Bram Moolenaar  All Rights Reserved
# Licensed under the Apache License, Version 2.0.  See the LICENSE file or
# obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
#
###################################################################
# Change lines in this block to match your environment.

# Specify the C compiler to be used.
# clang is preferred, it is more than twice as fast as gcc.
# However, clang -O2 is buggy, it may cause a crash.
#COMPILER = clang
COMPILER = gcc
#COMPILER = $(CC)
#COMPILER = tcc    works for small test programs only

# Optional arguments for the compiler.
#CCARG = -Wall -Wno-unused -Wno-parentheses -g
CCARG = -Wall -Wno-unused -Wno-parentheses -Wno-parentheses-equality -g
#CCARG = -Wall -Wno-unused -Wno-parentheses -g -O2 -W -Wno-unused-parameter
#CCARG = -Wall -Wno-unused -Wno-sequence-point -g
#CCARG = -Wall -g -L/usr/lib/i386-linux-gnu

# When available use tcmalloc, it's much faster.
# It's detected by zimbuConfig.
#CCENDARG = -ltcmalloc_minimal

# Specify the command to copy a file, overwriting the destination.
COPY = cp -f

# Specify the command to copy a file, NOT overwriting the destination.
COPYN = cp -n

# Make a file readonly
READONLY = chmod -w

# Make a file writeable
WRITABLE = chmod +w

# Specify the command to concatenate several files into stdout.
CAT = cat

# Diff command that ignores CR-LF vs LF differences
DIFF = diff -a --strip-trailing-cr

# Command to measure the time a command runs.
TIME = time

# Specify the command to create a directory, silent when already existing.
MKDIR = mkdir -p

# Specify the command to use to unconditionally remove files.
RMCMD = rm -f

# Specify the command to rename a file.
RENAME = mv

# Comment out when posix threads and sockets are not available.
TESTMORE = test_more

# Put in front of executable in current directory.
CURDIR = ./

# Put after executable name.
EXE =

# Put after object file name.
OBJ = .o

# Default name for Node.js executable.  When not set zimbuConfig will attempt
# to find it.
# NODEJS = nodejs

# Default name for the JVM.
JAVA = java
