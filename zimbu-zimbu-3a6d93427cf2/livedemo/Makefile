# Zimbu live demo makefile for Unix.
#
# Copyright 2010 Bram Moolenaar
# Licensed under the Apache License, Version 2.0.  See the LICENSE file or
# obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
#
###################################################################

include ../MakeSettingsUnix.mak

# Use the normal compiler by default.  Use zimbu_test when there are recent
# changes.
ZIMBU = ../zimbu
# ZIMBU = ../zimbu_test

# Do not manage memory: we need threads but GC + threads doesn't work properly
# on MS-Windows yet.
THREAD_ARGS = --manage=none

livedemo: doesnotexist
	$(ZIMBU) -v $(THREAD_ARGS) --cc $(COMPILER) --ccarg="$(CCARG)" livedemo.zu

# Needed to force building, ZWT files may have been changed.
doesnotexist:
