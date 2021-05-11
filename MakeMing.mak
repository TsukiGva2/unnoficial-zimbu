# Zimbu Makefile for MingW on MS-Windows
#
# See Makecommon.mak for the targets.
#
# For thread support install the pthreads-win32 module from
#   ftp://sourceware.org/pub/pthreads-win32/dll-latest/
#   Copy the include/*.h files to your MingW "include" directory.
#   Copy lib/libpthreadGC2.a to your MingW "lib" directory.
#   Copy lib/pthreadGC2.dll to the Windows/system32 directory.
#
# The "diff" program can be obtained from
#    http://sourceforge.net/projects/unxutils/
# However, don't use the make.exe and sh.exe from there.
#
# Useful information about porting from Unix to MingW on MS-Windows:
#    http://gnuwin32.sourceforge.net/compile.html
#
# Copyright 2010 Bram Moolenaar  All Rights Reserved
# Licensed under the Apache License, Version 2.0.  See the LICENSE file or
# obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
#
###################################################################
# Change lines in MakeSettingsMing.mak to match your environment.
include MakeSettingsMing.mak

# The rest is common with Unix.
include Makecommon.mak
