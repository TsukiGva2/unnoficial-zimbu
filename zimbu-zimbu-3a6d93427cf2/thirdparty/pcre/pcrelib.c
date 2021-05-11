/*
 * This file is compiled into pcrelib.o and added to a Zimbu program that uses
 * regular expressions.  This is a workaround for the PCRE library not being
 * available everywhere.
 */

#include "config.h"

#include "pcre_byte_order.c"
#include "pcre_chartables.c"
#include "pcre_compile.c"
#undef NLBLOCK
#undef PSSTART
#undef PSEND
#include "pcre_config.c"
#include "pcre_dfa_exec.c"
#undef NLBLOCK
#undef PSSTART
#undef PSEND
#include "pcre_exec.c"
#include "pcre_fullinfo.c"
#include "pcre_get.c"
#include "pcre_globals.c"
#include "pcre_jit_compile.c"
#include "pcre_maketables.c"
#include "pcre_newline.c"
#include "pcre_ord2utf8.c"
#include "pcre_refcount.c"
#include "pcre_study.c"
#include "pcre_tables.c"
#include "pcre_ucd.c"
#include "pcre_valid_utf8.c"
#include "pcre_version.c"
#include "pcre_xclass.c"
