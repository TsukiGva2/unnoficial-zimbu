# Zimbu makefile for Unix and Mac.
#
# Copyright 2014 Bram Moolenaar
# Licensed under the Apache License, Version 2.0.  See the LICENSE file or
# obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
#
###################################################################

include ../MakeSettingsUnix.mak

#THREAD_ARGS = --manage=none
# KEEP_UNUSED = --keepunused

# Use the normal compiler by default.  Use zimbu_test when the compiler has
# recent changes.
# ZIMBU = ../zimbu
ZIMBU = ../zimbu_test

zutdemo: doesnotexist
	$(ZIMBU) -v $(THREAD_ARGS) $(KEEP_UNUSED) --cc "$(COMPILER)" --ccarg="$(CCARG)" zutdemo.zu

# Needed to force building, ZUT files may have been changed.
doesnotexist:
