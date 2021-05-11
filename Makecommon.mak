# Zimbu makefile, common for all systems
#
# Copyright 2010 Bram Moolenaar  All Rights Reserved
# Licensed under the Apache License, Version 2.0.  See the LICENSE file or
# obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
#
###################################################################
# The main build targets:
#
# make bootstrap     builds zimbu from C source files
# make update        fetches new version and builds
# make               builds zimbu_test
# make test          builds zimbu_test and runs various tests
# make all           runs the tests and builds example programs
# make examples      builds example programs
# make installvim    installs the Vim runtime files to ~/.vim
# make zimbu         builds zimbu from Zimbu source files
# make docs          builds zimbu documentation
# make spec          builds the language specification
# make tags          builds the tags file

# Some more targets:
# make package       create the archive to be uploaded
# make push          push new version to Mercurial repository

###################################################################

# Use by both zimbu.zu and zimbu2c.zu
SHARED_SOURCES = \
	lib/ARGLoader.zu \
	lib/ARGModule.zu \
	lib/IOLoader.zu \
	lib/IOModule.zu \
	lib/LOGModule.zu \
	Config.zu

# Used by zimbu.zu only
MAIN_SOURCES = \
	zimbu.zu

# Used by zimbu2c.zu only
COMP_SOURCES = \
	Annotator.zu \
	ArrayStuff.zu \
	BitsType.zu \
	BitsValueType.zu \
	BlockScope.zu \
	Builtin.zu \
	CallbackType.zu \
	ClassRefType.zu \
	ClassScope.zu \
	ClassType.zu \
	CodeProperties.zu \
	CodeTable.zu \
	ContainerStuff.zu \
	ContainerType.zu \
	Conversion.zu \
	Debug.zu \
	DeclStore.zu \
	Declaration.zu \
	DictStuff.zu \
	EnumType.zu \
	EnumValueType.zu \
	ExprArg.zu \
	ExprEval.zu \
	FileScope.zu \
	ForLoopInfo.zu \
	Generate.zu \
	Input.zu \
	ListStuff.zu \
	MainFile.zu \
	ManageMemory.zu \
	MethodRefType.zu \
	MethodScope.zu \
	MethodType.zu \
	ModuleScope.zu \
	ModuleType.zu \
	MultipleType.zu \
	NoAllocType.zu \
	Output.zu \
	Parse.zu \
	Pos.zu \
	ReferenceType.zu \
	Resolve.zu \
	SContext.zu \
	Scope.zu \
	SharedScope.zu \
	SwitchScope.zu \
	SymUse.zu \
	TargetLang.zu \
	Template.zu \
	Token.zu \
	TokenInput.zu \
	Tokenizer.zu \
	TopScope.zu \
	TryScope.zu \
	TupleType.zu \
	Type.zu \
	TypedefType.zu \
	UsedFile.zu \
	Util.zu \
	ValueType.zu \
	Visibility.zu \
	WriteCommon.zu \
	ZimbuFile.zu \
	ZuiCodeBlockExt.zu \
	ZuiDeclarationExt.zu \
	ZuiExpressionExt.zu \
	ZuiExt.zu \
	ZuiFile.zu \
	ZuiForStatementExt.zu \
	ZuiImportExt.zu \
	ZuiMethodCallExt.zu \
	ZuiMethodTypeExt.zu \
	ZuiStatementExt.zu \
	ZuiTryStatementExt.zu \
	ZuiTypeExt.zu \
	genC/WriteArrayC.zu \
	genC/WriteC.zu \
	genC/WriteDictC.zu \
	genC/WriteIMT.zu \
	genC/WriteListC.zu \
	genC/ZuiWriteC.zu \
	genJS/WriteArrayJS.zu \
	genJS/WriteDictJS.zu \
	genJS/WriteJS.zu \
	genJS/WriteListJS.zu \
	lib/BYTELoader.zu \
	lib/BYTEModule.zu \
	lib/BYTESTRINGLoader.zu \
	lib/BYTESTRINGModule.zu \
	lib/CHECKLoader.zu \
	lib/CHECKModule.zu \
	lib/DYNLoader.zu \
	lib/ELoader.zu \
	lib/FLOATLoader.zu \
	lib/FLOATModule.zu \
	lib/GCLoader.zu \
	lib/GCModule.zu \
	lib/HTTPLoader.zu \
	lib/INT16Loader.zu \
	lib/INT16Module.zu \
	lib/INT32Loader.zu \
	lib/INT32Module.zu \
	lib/INT8Loader.zu \
	lib/INT8Module.zu \
	lib/INTLoader.zu \
	lib/INTModule.zu \
	lib/MULTIDICTLoader.zu \
	lib/MULTIDICTModule.zu \
	lib/NAT16Loader.zu \
	lib/NAT16Module.zu \
	lib/NAT32Loader.zu \
	lib/NAT32Module.zu \
	lib/NATLoader.zu \
	lib/NATModule.zu \
	lib/PIPELoader.zu \
	lib/RPCLoader.zu \
	lib/SETLoader.zu \
	lib/SORTEDLISTLoader.zu \
	lib/STRINGLoader.zu \
	lib/STRINGModule.zu \
	lib/SYSLoader.zu \
	lib/THREADLoader.zu \
	lib/TIMELoader.zu \
	lib/TModule.zu \
	lib/TYPELoader.zu \
	lib/VARBYTESTRINGLoader.zu \
	lib/VARBYTESTRINGModule.zu \
	lib/VARSTRINGLoader.zu \
	lib/VARSTRINGModule.zu \
	lib/ZLoader.zu \
	lib/ZModule.zu \
	lib/ZUTLoader.zu \
	lib/ZWTLoader.zu \
	zui.proto \
	zimbu2c.zu

INPUT_FILES = \
	zimbuConfig.out


# Files to generate documentation for.  Should only be toplevel runtime
# modules.
DOCINPUT = \
	lib/ARGModule.zu \
	lib/ARRAYModule.zu \
	lib/BOOLModule.zu \
	lib/BOXModule.zu \
	lib/BYTESTRINGModule.zu \
	lib/CHECKModule.zu \
	lib/DICTModule.zu \
	lib/DYNModule.zu \
	lib/EModule.zu \
	lib/FLOAT32Module.zu \
	lib/FLOATModule.zu \
	lib/FLOAT80Module.zu \
	lib/FLOAT128Module.zu \
	lib/GCModule.zu \
	lib/HTTPModule.zu \
	lib/IModule.zu \
	lib/INTModule.zu \
	lib/INT8Module.zu \
	lib/INT16Module.zu \
	lib/INT32Module.zu \
	lib/NATModule.zu \
	lib/BYTEModule.zu \
	lib/NAT16Module.zu \
	lib/NAT32Module.zu \
	lib/IOModule.zu \
	lib/LISTModule.zu \
	lib/LOGModule.zu \
	lib/MULTIDICTModule.zu \
	lib/MULTISETModule.zu \
	lib/PIPEModule.zu \
	lib/RPCModule.zu \
	lib/SETModule.zu \
	lib/SORTEDLISTModule.zu \
	lib/STATUSModule.zu \
	lib/STRINGModule.zu \
	lib/SYSModule.zu \
	lib/TIOModule.zu \
	lib/TModule.zu \
	lib/THREADModule.zu \
	lib/TIMEModule.zu \
	lib/TYPEModule.zu \
	lib/TUPLEModule.zu \
	lib/VARBYTESTRINGModule.zu \
	lib/VARSTRINGModule.zu \
	lib/ZModule.zu \
	lib/ZUTModule.zu \
	lib/zwt/BaseModule.zu \
	lib/zwt/ButtonModule.zu \
	lib/zwt/CodeModule.zu \
	lib/zwt/DialogModule.zu \
	lib/zwt/DropdownModule.zu \
	lib/zwt/EventModule.zu \
	lib/zwt/InputModule.zu \
	lib/zwt/LabelModule.zu \
	lib/zwt/MenuModule.zu \
	lib/zwt/PanelModule.zu \
	lib/zwt/StyleModule.zu \
	lib/zwt/TableModule.zu \
	lib/zwt/TextareaModule.zu \
	lib/ZWTModule.zu


PLUGINS = \
	pluginproto$(EXE) \
	pluginzut$(EXE)

PLUGINPROTO_SRC = \
	plugin/proto/EnumItem.zu \
	plugin/proto/FieldItem.zu \
	plugin/proto/I_ItemFinder.zu \
	plugin/proto/I_ProtoItem.zu \
	plugin/proto/Message.zu \
	plugin/proto/MessageItem.zu \
	plugin/proto/ParseProto.zu \
	plugin/proto/Proto.zu \
	plugin/proto/ProtoFile.zu \
	plugin/proto/RpcItem.zu \
	plugin/proto/ServiceItem.zu \
	plugin/proto/PToken.zu \
	plugin/proto/PTokenInput.zu \
	plugin/proto/PTokenize.zu \
	plugin/proto/WriteZimbu.zu \
	plugin/proto/pluginproto.zu

PROTOTRYOUT_SRC = \
	prototryout.zu \
	zwtdemo/addressbook.proto

PLUGINZUT_SRC = \
	plugin/zut/pluginzut.zu


# Uncomment to build with unused symbols generated.
# KEEP_UNUSED = --keepunused

# Arguments for when running ./zimbu
#BUILD_ARGS = --manage=none --portable
#BUILD_ARGS = --manage=linked
BUILD_ARGS = --manage=linked --portable
#BUILD_ARGS = --manage=linked --portable --exitclean
#BUILD_ARGS = --manage=linked --exitclean
#BUILD_ARGS = --manage=default

# Arguments for when running ./zimbu_test and ./zimbu_test_test
#TEST_ARGS = --manage=none
#TEST_ARGS = --manage=none --portable
#TEST_ARGS = --manage=linked
#TEST_ARGS = --manage=linked --portable
#TEST_ARGS = --manage=linked --portable --exitclean
TEST_ARGS = --manage=linked --exitclean
#TEST_ARGS = --manage=default

# Like TEST_ARGS but for building with threads.
#THREAD_ARGS = --manage=none
#THREAD_ARGS = --manage=linked
THREAD_ARGS = --manage=linked --exitclean
#THREAD_ARGS = --manage=default

# Extra arguments not in TEST_ARGS for compiling testje.zu
#TESTJE_ARGS = --manage=none
#TESTJE_ARGS = --manage=linked
TESTJE_ARGS = --manage=linked --exitclean
#TESTJE_ARGS = --manage=default
#TESTJE_ARGS = $(TEST_ARGS)

COMPILER_ARGS = --cc "$(COMPILER)" --ccarg "$(CCARG)" --ccendarg "$(CCENDARG)"
COMPILER_TIME_ARGS = --cc "$(TIME) $(COMPILER)" --ccarg "$(CCARG)" --ccendarg "$(CCENDARG)"
COMPILER_PROF_ARGS = --cc "gcc" --ccarg "-Wno-parentheses-equality -g -pg" --ccendarg "$(CCENDARG)"

# Default target: test building the new version using the tested version.
build_zimbu_test: zimbu_test$(EXE) zimbu_test2c$(EXE)

zimbu_test$(EXE): $(SHARED_SOURCES) $(MAIN_SOURCES) $(INPUT_FILES)
	$(COPY) zimbu.zu zimbu_test.zu
	$(CURDIR)zimbu -v $(BUILD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) zimbu_test.zu

zimbu_test2c$(EXE): $(SHARED_SOURCES) $(COMP_SOURCES) $(INPUT_FILES)
	$(COPY) zimbu2c.zu zimbu_test2c.zu
	$(CURDIR)zimbu -v $(BUILD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) zimbu_test2c.zu

# Pack up the sources and generated C files to move elsewhere.
# NOTE: depends on zimbu_test and uses zimbu_test_test.c, because depending on
# zimbu may break the compiler and zimbu.c may be out of sync with the other C
# files.
# Best is to do "make zimbu" though (after testing!).
prepare: copyvimfiles
	$(COPY) zimbu_test_test.c zimbu.c
	$(COPY) zimbu_test_test2c.c zimbu2c.c

# This copies the files in ~/.vim to here.  Use only when they are newer!
copyvimfiles:
	$(COPY) ~/.vim/syntax/zimbu.vim vim/syntax
	$(COPY) ~/.vim/indent/zimbu.vim vim/indent
	$(COPY) ~/.vim/ftplugin/zimbu.vim vim/ftplugin

# Copy the Vim files from here to ~/.vim.
installvim:
	-$(MKDIR) ~/.vim
	-$(MKDIR) ~/.vim/syntax
	$(COPY) vim/syntax/zimbu.vim ~/.vim/syntax/zimbu.vim
	-$(MKDIR) ~/.vim/indent
	$(COPY) vim/indent/zimbu.vim ~/.vim/indent/zimbu.vim
	-$(MKDIR) ~/.vim/ftplugin
	$(COPY) vim/ftplugin/zimbu.vim ~/.vim/ftplugin/zimbu.vim
	$(COPYN) vim/filetype.vim ~/.vim/filetype.vim

# Push the current commit to the Google Code site.
# Only works if you have permission and have setup your password.
# Do "hg commit" before this.
push:
	hg push https://zimbu.googlecode.com/hg/

package: prepare build_zimbu_test
	dir=`date +zimbu_%Y_%m_%d`; mkdir $$dir; \
	    tar cf - \
		*.zu lib/*.zu lib/zwt/*.zu zimbush \
		plugin/proto/*.zu \
		*.proto \
		book \
		pages/*.html \
		docs/*.html \
		testdir/*.zu testdir/subdir/*.zu test.ok testmore.ok \
		zimbu.c zimbu2c.c ZUDIR/*.c ZUDIR/*.h \
		lib/ZUDIR/*.c lib/ZUDIR/*.h \
		*.txt Makefile *.mak README lib/README LICENSE \
		vim/*/zimbu.vim vim/filetype.vim \
		| tar xf - -C $$dir; \
	   tar cvfz $$dir.tgz $$dir; \
	   rm -r $$dir

# When on a new system: Build Zimbu from the C files.
# Builds and runs zimbuConfig to generate zimbuConfig.out.
# Also build pluginproto, the compiler depends on it for IMPORT.PROTO.
# Also build pluginzut, just for convenience.
bootstrap:
	$(COMPILER) $(CCARG) -o zimbuConfig$(EXE) zimbuConfig.c
	$(CURDIR)zimbuConfig$(EXE)
	$(COMPILER) $(CCARG) -o zimbu$(EXE) zimbu.c
	$(COMPILER) $(CCARG) -o zimbu2c$(EXE) zimbu2c.c
	$(COMPILER) $(CCARG) -o pluginproto$(EXE) plugin/proto/pluginproto.c
	$(COMPILER) $(CCARG) -o pluginzut$(EXE) plugin/zut/pluginzut.c

# Update the files from Mercurial.  This may overwrite local changes!
# Then build the new compiler from the C files.
# Restart make, because this Makefile may also have been updated with new
# bootstrap commands.
update: fetchfiles
	$(MAKE) $(MAKEFILEARG) bootstrap

fetchfiles:
	hg pull
	hg update

# Build ALL targets that should build, except for the tests.  Used to verify
# compiler changes.
# livedemo is last, it currently fails on MS-Windows.
all: zimbuConfigAlways \
	examples \
	prototryout$(EXE) \
	zuidump \
	zutdemo \
	zwtdemo \
	testrun \
	zuidump \
	$(PLUGINS) \
	spec \
	docs \
	livedemo

# Test building testprog and verify its output
test: test_testprog \
	test_test_testprog \
	$(TESTMORE) \
	test_testnomanage \
	zimbuConfigTest

# Run the compiler and the testprog under valgrind.
# When using --manage=linked also add --exitclean to avoid false warnings.
testvalgrind: test_testprog_valgrind test_test_testprog_valgrind

# More tests, those that require socket and thread library.
test_more: test_testmore test_testmore_zimbu

# Test building and running a set of programs in testdir/progs/,
# testdir/progsbad/ and testdir/progsfail/.
testrun: testrunner
	./testrunner '$(CURDIR)zimbu_test $(THREAD_ARGS) $(COMPILER_ARGS)'

testrunner: testrunner.zu build_zimbu_test
	$(CURDIR)zimbu_test $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testrunner.zu

# Small program that filters the test output for things that are different but
# OK.  Mainly because output changes depending on the compiler.
fixtestout: fixtestout.zu
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) fixtestout.zu

# Test that the new version can build and run the test program
# NOTE: Does not depend on pluginproto, because if there is a problem and
# building it fails we end up without a working compiler!
test_testprog: build_zimbu_test fixtestout
	@echo
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testprog.zu
	@echo
	-$(CURDIR)testprog argone -x argtwo -- -a > test.out
	$(CURDIR)fixtestout test.out
	$(DIFF) test.ok test.out

# Test that the new version can build and run the test program with threads.
test_testmore: build_zimbu_test
	@echo
	$(CURDIR)zimbu_test -v $(THREAD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testmore.zu
	@echo
	$(CURDIR)testmore > testmore.out
	cat testmore.out
	$(DIFF) testmore.ok testmore.out

# Test that the new version can build itself
zimbu_test_test$(EXE): build_zimbu_test
	@echo
	$(COPY) zimbu.zu zimbu_test_test.zu
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) zimbu_test_test.zu
	$(COPY) zimbu2c.zu zimbu_test_test2c.zu
	$(TIME) $(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_TIME_ARGS) zimbu_test_test2c.zu

# Test that the version that build itself can build and run the test program
test_test_testprog: zimbu_test_test$(EXE)
	@echo
	$(CURDIR)zimbu_test_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testprog.zu
	@echo
	-$(CURDIR)testprog argone -x argtwo -- -a > test.out
	$(CURDIR)fixtestout test.out
	$(DIFF) test.ok test.out

# Test that the version that build itself can build and run the test program
test_testmore_zimbu: zimbu_test_test$(EXE)
	@echo
	$(CURDIR)zimbu_test_test -v $(THREAD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testmore.zu
	@echo
	$(CURDIR)testmore > testmore.out
	cat testmore.out
	$(DIFF) testmore.ok testmore.out

# Build zimbu_test for profiling, then run it to build zimbu_test_test2c.
# Does not work with clang, switch to gcc.
# Output can be viewed with "gprof zimbu_test2c gmon.out".
# This is very slow!
profile:
	$(COPY) zimbu2c.zu zimbu_test2c.zu
	$(CURDIR)zimbu -v $(BUILD_ARGS) $(KEEP_UNUSED) $(COMPILER_PROF_ARGS) zimbu_test2c.zu
	$(COPY) zimbu2c.zu zimbu_test_test2c.zu
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) zimbu_test_test2c.zu

# Coverage: Compile testje.zu with special arguments and run gcov to collect
# information
# Does not work with clang, switch to gcc.
coverage: build_zimbu_test
	$(CURDIR)zimbu_test -v $(TESTJE_ARGS) $(KEEP_UNUSED) \
		--cc "gcc" \
		--ccarg "$(CCARG) -fprofile-arcs -ftest-coverage" \
		--ccendarg "$(CCENDARG)" \
		testje.zu
	$(CURDIR)testje
	$(COPY) ZUDIR/testje.c testje.c
	gcov testje.c

# Note: for memory profiling:
# - Build with the -g flag, so that symbols are included.
# - Run with "valgrind --tool=massif --massif-out-file=massif.out ./zimbu_test testprog.zu"
# - View the output with ms_print massif.out
# More info: http://valgrind.org/docs/manual/ms-manual.html
VALGRIND = valgrind --log-file=valgrind.log --leak-check=full --num-callers=30
VALGRIND2 = valgrind --log-file=valgrind2.log --leak-check=full --num-callers=30
VALGRIND3 = valgrind --log-file=valgrind3.log --leak-check=full --num-callers=30
VALGRIND4 = valgrind --log-file=valgrind4.log --leak-check=full --num-callers=30
VALGRIND5 = valgrind --log-file=valgrind5.log --leak-check=full --num-callers=30

# Only do this when "make test" succeeded!
# Write the output to another name, can't overwrite zimbu.exe while it is being
# executed on MS-Windows.
zimbu: zimbu2c $(SHARED_SOURCES) $(MAIN_SOURCES) $(INPUT_FILES)
	$(CURDIR)zimbu -o new_zimbu$(EXE) $(BUILD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) zimbu.zu
	$(RMCMD) zimbu$(EXE)
	$(RENAME) new_zimbu$(EXE) zimbu$(EXE)
	$(RMCMD) zimbu.c
	$(RENAME) ZUDIR/zimbu.c zimbu.c

zimbu2c: $(SHARED_SOURCES) $(COMP_SOURCES) $(INPUT_FILES)
	$(CURDIR)zimbu -o new_zimbu2c$(EXE) $(BUILD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) zimbu2c.zu
	$(RMCMD) zimbu2c$(EXE)
	$(RENAME) new_zimbu2c$(EXE) zimbu2c$(EXE)
	$(RMCMD) zimbu2c.c
	$(RENAME) ZUDIR/zimbu2c.c zimbu2c.c

# Test that a simple program compiles without managing memory.
test_testnomanage: build_zimbu_test
	$(CURDIR)zimbu_test --manage=none $(KEEP_UNUSED) $(COMPILER_ARGS) testdir/testnomanage.zu -o testnomanage$(EXE)
	@echo
	$(CURDIR)testnomanage$(EXE) -x right >testnomanage.out
	cat testnomanage.out
	$(DIFF) testnomanage.ok testnomanage.out

# The config program
zimbuConfig: zimbuConfig.zu zimbuConfig.proto
	$(MAKE) $(MAKEFILEARG) zimbuConfigAlways

zimbuConfigAlways:
	$(CURDIR)zimbu --manage=none --portable $(KEEP_UNUSED) $(COMPILER_ARGS) zimbuConfig.zu
	$(RMCMD) zimbuConfig.c
	$(RENAME) ZUDIR/zimbuConfig.c zimbuConfig.c

zimbuConfig.out: zimbuConfig
	$(CURDIR)zimbuConfig

zimbuConfigTest: build_zimbu_test
	$(CURDIR)zimbu_test --manage=none --portable $(KEEP_UNUSED) $(COMPILER_ARGS) zimbuConfig.zu -o zimbuConfigTest$(EXE)

# The documentation generation program: Zudocu
zudocu: zudocu.zu build_zimbu_test
	$(CURDIR)zimbu_test $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) -v zudocu.zu

livedemo: doesnotexist
	cd livedemo; make $(MAKEFILEARG)

zwtdemo: doesnotexist
	cd zwtdemo; make $(MAKEFILEARG)

zutdemo: doesnotexist
	cd zutdemo; make $(MAKEFILEARG)

docs: $(DOCINPUT) zudocu
	$(RMCMD) docs/*.html
	$(CURDIR)zudocu $(DOCINPUT) docs

spec: doesnotexist
	cd spec; make $(MAKEFILEARG)

# A few example programs

examples: echo copy animal hello testserver

echo: echo.zu build_zimbu_test
	$(CURDIR)zimbu_test $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) echo.zu

copy: copy.zu build_zimbu_test
	$(CURDIR)zimbu_test $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) copy.zu

animal: animal.zu build_zimbu_test
	$(CURDIR)zimbu_test $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) animal.zu

hello: hello.zu build_zimbu_test
	$(CURDIR)zimbu_test $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) hello.zu

testserver: testserver.zu build_zimbu_test
	$(CURDIR)zimbu_test -v $(THREAD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testserver.zu

testje: testje.zu build_zimbu_test
	$(CURDIR)zimbu_test -v $(TESTJE_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testje.zu

testje2: testje.zu zimbu_test_test$(EXE)
	$(CURDIR)zimbu_test_test -v $(TESTJE_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testje.zu

zuiclean cleanzui:
	$(RMCMD) ZUDIR/*.zui testdir/ZUDIR/*.zui lib/ZUDIR/*.zui
	
clean:
	$(RMCMD) testdir/ZUDIR/*
	$(RMCMD) testdir/subdir/ZUDIR/*
	$(RMCMD) plugin/proto/ZUDIR/*
	$(RMCMD) lib/ZUDIR/*
	$(RMCMD) lib/zwt/ZUDIR/*
	$(RMCMD) ZUDIR/*
	$(RMCMD) livedemo/ZUDIR/*
	$(RMCMD) *.eca
	$(RMCMD) testdir/progs/*.c
	$(RMCMD) testdir/progs/*.out
	$(RMCMD) testdir/progs/*.build
	$(RMCMD) testdir/progs/*[a-zA-Z][a-zA-Z][a-zA-Z]
	$(RMCMD) testdir/progs/*[a-zA-Z][a-zA-Z][0-9]
	$(RMCMD) testdir/progsbad/*.c
	$(RMCMD) testdir/progsbad/*.out
	$(RMCMD) testdir/progsbad/*.build
	$(RMCMD) testdir/progsfail/*.c
	$(RMCMD) testdir/progsfail/*.out
	$(RMCMD) testdir/progsfail/*.build
	$(RMCMD) testdir/progsfail/*[a-zA-Z][a-zA-Z][a-zA-Z]
	$(RMCMD) testrunner
	$(RMCMD) testrunner.c
	$(RMCMD) core
	$(RMCMD) test.out testmore.out
	$(RMCMD) animal animal.c
	$(RMCMD) copy copy.c
	$(RMCMD) echo echo.c
	$(RMCMD) fixtestout fixtestout.c
	$(RMCMD) testje testje.c
	$(RMCMD) testprog testprog.c
	$(RMCMD) testmore testmore.c
	$(RMCMD) testzui testzui.c
	$(RMCMD) zuidump zuidump.c
	$(RMCMD) testserver testserver.c
	$(RMCMD) pipedemo pipedemo.c
	$(RMCMD) hello hello.c
	$(RMCMD) prototryout.c
	$(RMCMD) prototryout
	$(RMCMD) newbook
	$(RMCMD) zimbu_test zimbu_test.c
	$(RMCMD) zimbu_test.zu
	$(RMCMD) zimbu_test_test zimbu_test_test.c zimbu_test_test.zu
	$(RMCMD) zimbu_test2c zimbu_test2c.c
	$(RMCMD) zimbu_test2c.zu
	$(RMCMD) zimbu_test_test2c zimbu_test_test2c.c zimbu_test_test2c.zu
	$(RMCMD) zimbuConfig.out
	$(RMCMD) zudocu zudocu.c
	$(RMCMD) zwtdemo/zwtdemo zwtdemo/ZUDIR/zwtdemo.c
	$(RMCMD) zutdemo/zutdemo zutdemo/ZUDIR/zutdemo.c
	$(RMCMD) livedemo/livedemo livedemo/livedemo.c
	$(RMCMD) livedemo/demo livedemo/demo.c
	$(RMCMD) livedemo/demo.zu livedemo/demo.out livedemo/demo.comp
	$(RMCMD) performance/True.class
	$(RMCMD) performance/measure performance/measure.c
	$(RMCMD) performance/true_c
	$(RMCMD) performance/true_python.pyc
	$(RMCMD) performance/true_zimbu performance/true_zimbu.c
	$(RMCMD) performance/true_go
	$(RMCMD) performance/true_go.8
	$(RMCMD) performance/citycount performance/citycount.c
	$(RMCMD) performance/worldcitiespop.txt
	$(RMCMD) performance/pi performance/pi.c

# Test producing and reading .zui files.
testzui: testdir/testzui.zu testdir/TestSome.zu build_zimbu_test
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) --zui $(COMPILER_ARGS) testdir/testzui.zu

zuidump: zuidump.zu zui.proto build_zimbu_test
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) zuidump.zu

runtestje: testje
	$(CURDIR)testje

runtestjevalgrind: testje
	-$(VALGRIND) $(CURDIR)testje

runtestje2: testje2
	$(CURDIR)testje

runtestje2valgrind: testje2
	-$(VALGRIND) $(CURDIR)testje

valgrindtestje: build_zimbu_test
	$(CURDIR)zimbu_test -v $(TESTJE_ARGS)  $(KEEP_UNUSED) \
		--zimbu="$(VALGRIND2) ./zimbu_test2c" \
		$(COMPILER_ARGS) testje.zu
	-$(VALGRIND) $(CURDIR)testje

# Test that the new version can build the test program and run the test program
# without leaks.
test_testprog_valgrind: build_zimbu_test
	@echo
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testprog.zu
	@echo
	-$(VALGRIND) $(CURDIR)testprog argone -x argtwo -- -a > test.out
	$(CURDIR)fixtestout test.out
	$(DIFF) test.ok test.out

# Test that zimbu_test runs clean under valgrind.
valgrind_zimbu_test: build_zimbu_test
	@echo
	-$(VALGRIND2) $(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) \
		--zimbu="$(VALGRIND3) ./zimbu_test2c" \
		$(COMPILER_ARGS) testprog.zu
	@echo
	-$(VALGRIND4) $(CURDIR)testprog argone -x argtwo -- -a > test.out
	$(CURDIR)fixtestout test.out
	$(DIFF) test.ok test.out

# Test that the version that build itself can build the test program without
# leaks and run the test program without leaks.
test_test_testprog_valgrind: zimbu_test_test$(EXE)
	@echo
	-$(VALGRIND2) $(CURDIR)zimbu_test_test -v $(TEST_ARGS) $(KEEP_UNUSED) \
		--zimbu="$(VALGRIND3) ./zimbu_test_test2c" \
		$(COMPILER_ARGS) testprog.zu
	@echo
	-$(VALGRIND4) $(CURDIR)testprog argone -x argtwo -- -a > test.out
	$(CURDIR)fixtestout test.out
	$(DIFF) test.ok test.out

# Build testje.zu with zimbu_test_test under valgrind.
testjevalgrind: zimbu_test_test$(EXE)
	@echo
	-$(VALGRIND2) $(CURDIR)zimbu_test_test -v $(TESTJE_ARGS) $(KEEP_UNUSED) \
		--zimbu="$(VALGRIND3) ./zimbu_test_test2c" \
		$(COMPILER_ARGS) testje.zu
	@echo
	-$(VALGRIND4) $(CURDIR)testje

# Test that the new version can build and run the test program with threads.
testmorevalgrind: build_zimbu_test
	@echo
	$(CURDIR)zimbu_test -v $(THREAD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) testmore.zu
	@echo
	-$(VALGRIND) $(CURDIR)testmore > testmore.out
	cat testmore.out
	$(DIFF) testmore.ok testmore.out

pipedemo: pipedemo.zu build_zimbu_test
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) pipedemo.zu

tags: $(SHARED_SOURCES) $(MAIN_SOURCES) $(COMP_SOURCES)
	ctags \
		--langdef=zimbu \
		--langmap=zimbu:.zu \
		'--regex-zimbu=/^ *FUNC +\$$?([^(]+)\(/\1/' \
		'--regex-zimbu=/^ *PROC +\$$?([^(]+)/\1/' \
		'--regex-zimbu=/^ *ENUM +([^ ]+)/\1/' \
		'--regex-zimbu=/^ *BITS +([^ ]+)/\1/' \
		'--regex-zimbu=/^ *CLASS +([^ ]+)/\1/' \
		'--regex-zimbu=/^ *MODULE +([^ ]+)/\1/' \
		'--regex-zimbu=/^ *[a-zA-Z][a-z_]+ +\$$?([a-zA-Z][^ ]+)/\1/' \
		'--regex-zimbu=/^ *list<[a-zA-Z_]+> +\$$?([a-zA-Z][^ ]+)/\1/' \
		'--regex-zimbu=/^ *dict<[a-zA-Z_, ]+> +\$$?([a-zA-Z][^ ]+)/\1/' \
		$(SHARED_SOURCES) $(MAIN_SOURCES) $(COMP_SOURCES)


# Use BUILD_ARGS for pluginproto, since pluginproto.c is distributed.
pluginproto$(EXE): $(PLUGINPROTO_SRC) build_zimbu_test
	$(CURDIR)zimbu_test -v $(BUILD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) -o pluginproto$(EXE) plugin/proto/pluginproto.zu
	$(RMCMD) plugin/proto/pluginproto.c
	$(RENAME) plugin/proto/ZUDIR/pluginproto.c plugin/proto/pluginproto.c

prototryout$(EXE): $(PROTOTRYOUT_SRC) build_zimbu_test pluginproto$(EXE)
	$(CURDIR)zimbu_test -v $(TEST_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) -o prototryout$(EXE) prototryout.zu

runprototryout: prototryout
	$(CURDIR)prototryout
backup: doesnotexist
	-mkdir backup/`date "+%Y-%m-%d-%H:%M"`
	cp -r zimbu zimbu2c *.zu *.txt Makefile *.mak lib plugin testdir test.ok backup/`date "+%Y-%m-%d-%H:%M"`


# Use BUILD_ARGS for pluginzut, since pluginzut.c is distributed.
pluginzut$(EXE): $(PLUGINZUT_SRC) build_zimbu_test
	$(CURDIR)zimbu_test -v $(BUILD_ARGS) $(KEEP_UNUSED) $(COMPILER_ARGS) -o pluginzut$(EXE) plugin/zut/pluginzut.zu
	$(RMCMD) plugin/zut/pluginzut.c
	$(RENAME) plugin/zut/ZUDIR/pluginzut.c plugin/zut/pluginzut.c


# Needed because "backup" exists as a directory.
doesnotexist:
