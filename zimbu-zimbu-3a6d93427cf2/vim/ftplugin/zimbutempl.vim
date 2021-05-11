" Vim ftplugin file
" Language:	Zimbu Templates
" Maintainer:	Bram Moolenaar
" Last Change:	2014 Nov 23

" Only do this when not done yet for this buffer
if exists("b:did_ftplugin")
  finish
endif

" For now it's handled like Zimbu
runtime! ftplugin/zimbu.vim

" vim: ts=8
