# Zimbu Makefile for MingW on MS-Windows
#
# Copyright 2012 Bram Moolenaar
# Licensed under the Apache License, Version 2.0.  See the LICENSE file or
# obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
#
###################################################################

include ../MakeSettingsMing.mak

# Use the normal compiler by default.  Use zimbu_test when there are recent
# changes.
ZIMBU = ../zimbu
# ZIMBU = ../zimbu_test

zwtdemo: doesnotexist
	$(ZIMBU) -v $(TEST_ARGS) $(KEEP_UNUSED) --cc "$(COMPILER)" --ccarg="$(CCARG)" zwtdemo.zu

# Needed to force building, ZWT files may have been changed.
doesnotexist:
