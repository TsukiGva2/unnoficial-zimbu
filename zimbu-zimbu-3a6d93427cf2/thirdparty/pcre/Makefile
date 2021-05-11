# This does not build PCRE, it only copies files.
#
# Since libraries are not very portable, especially to MS-Windows, for Zimbu we
# just get all the C code and build it into an object file: pcrelib.o
# This happens when running "make bootstrap".
#
# This Makefile assumes a PCRE source library in a subdirectory and copies the
# relevant files to this directory, so that not the whole PCRE source needs to
# be included.

PCRE_DIR = pcre-8.37

all: $(PCRE_DIR)/config.h
	# Copy the files we need for building.
	cp -f $(PCRE_DIR)/config.h .
	cp -f $(PCRE_DIR)/pcre_internal.h .
	cp -f $(PCRE_DIR)/ucp.h .
	#
	cp -f $(PCRE_DIR)/pcre_byte_order.c .
	cp -f $(PCRE_DIR)/pcre_chartables.c.dist pcre_chartables.c
	cp -f $(PCRE_DIR)/pcre_compile.c .
	cp -f $(PCRE_DIR)/pcre_config.c .
	cp -f $(PCRE_DIR)/pcre_dfa_exec.c .
	cp -f $(PCRE_DIR)/pcre_exec.c .
	cp -f $(PCRE_DIR)/pcre_fullinfo.c .
	cp -f $(PCRE_DIR)/pcre_get.c .
	cp -f $(PCRE_DIR)/pcre_globals.c .
	cp -f $(PCRE_DIR)/pcre_jit_compile.c .
	cp -f $(PCRE_DIR)/pcre_maketables.c .
	cp -f $(PCRE_DIR)/pcre_newline.c .
	cp -f $(PCRE_DIR)/pcre_ord2utf8.c .
	cp -f $(PCRE_DIR)/pcre_refcount.c .
	cp -f $(PCRE_DIR)/pcre_study.c .
	cp -f $(PCRE_DIR)/pcre_tables.c .
	cp -f $(PCRE_DIR)/pcre_ucd.c .
	cp -f $(PCRE_DIR)/pcre_valid_utf8.c .
	cp -f $(PCRE_DIR)/pcre_version.c .
	cp -f $(PCRE_DIR)/pcre_xclass.c .
	#
	# Copy the header file.
	cp -f $(PCRE_DIR)/pcre.h .
	#
	# Avoid compiler warnings.
	sed --in-place pcre_compile.c -e '/utf = utf;/d'
	#
	# Behave like with a static library.
	sed --in-place pcre.h -e '/PCRE_STATIC/i#define PCRE_STATIC'

$(PCRE_DIR)/config.h:
	# Run PCRE configure with the arguments needed for Zimbu.
	cd $(PCRE_DIR) && ./configure --enable-utf --disable-cpp

