if exists("did_load_filetypes")
  finish
endif
augroup filetypedetect
	au! BufNewFile,BufRead *.zu     setf zimbu
augroup END
