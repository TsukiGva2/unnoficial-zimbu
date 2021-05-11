# Zimbu makefile for the language spec.
#
# Copyright 2013 Bram Moolenaar  All Rights Reserved
# Licensed under the Apache License, Version 2.0.  See the LICENSE file or
# obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
#

# Make a copy of the file, so that we can edit it at the same time.
spec: zimbu.html zut.html

zimbu.html: zimbu.mkd
	cp zimbu.mkd zimbu.cpy
	vim -S markup2html.vim zimbu.cpy
	rm -f zimbu.cpy

zut.html: zut.mkd
	cp zut.mkd zut.cpy
	vim -S markup2html.vim zut.cpy
	rm -f zut.cpy
