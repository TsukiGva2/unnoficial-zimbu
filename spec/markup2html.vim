" A simplified markup to HTML converter, specifically for the Zimbu language
" specification.
"
" This is written in Vim script, because we want to use Vim syntax
" highlighting for the code examples.
"
" NOTE: This is not fool-proof!  Check the generated HTML if it looks OK.
"
" Copyright 2013 Bram Moolenaar  All Rights Reserved.
" Licensed under the Apache License, Version 2.0.  See the LICENSE file or
" obtain a copy at: http://www.apache.org/licenses/LICENSE-2.0
"

" Process quicker, avoid sleeps.
set lazyredraw
set nomore
set noshowmode
set cmdheight=3
let g:html_no_progress = 1
let currentLine = line('.')

let inPara = 0
let didH3 = 0
let l = 1
let textBuf = bufnr('%')
let contents = []
let onclick = ''
let rationaleId = 0

" End a paragraph, if we are inside one.
func! EndPara()
  if g:inPara
    call append(g:l - 1, '</p>')
    let g:l = g:l + 1
    let g:inPara = 0
  endif
endfunc

" Turn a title into a name to use with <a>
func! Title2Name(title)
  let id = ''
  for i in range(strlen(a:title))
    let c = a:title[i]
    if c =~ '[a-zA-Z_]'
      let id .= c
    else
      let id .= '%' . char2nr(c)
    endif
  endfor
  return id
endfunc

func HtmlEscape(text)
  let r = substitute(a:text, '&', '\&amp;', 'g')
  let r = substitute(r, '<', '\&lt;', 'g')
  let r = substitute(r, '>', '\&gt;', 'g')
  return r
endfunc

" Turn the text in between [[ and ]] into a link
func! MakeLink(text)
  let link = substitute(a:text, '|.*', '', '')
  let text = substitute(a:text, '.*|', '', '')
  return '<a href="#' . Title2Name(link) . '">' . HtmlEscape(text) . '</a>'
endfunc

" Convert links and $$VAR items.
" Turn *bold* worlds into <b>bold<b>.
func! Process(text)
  " Escape < and & where they are clearly not HTML.
  let text = substitute(a:text, '&&', '\&amp;\&amp;', 'g')
  let text = substitute(text, '& ', '\&amp;', 'g')
  let text = substitute(text, '< ', '\&lt; ', 'g')
  let text = substitute(text, '<<<', '\&lt;\&lt;\&lt;', 'g')
  let text = substitute(text, '<<', '\&lt;\&lt;', 'g')
  let text = substitute(text, '<=', '\&lt;=', 'g')
  let text = substitute(text, '->', '-\&gt;', 'g')
  let text = substitute(text, '>>>', '\&gt;\&gt;\&gt;', 'g')
  let text = substitute(text, '>>', '\&gt;\&gt;', 'g')
  
  " word in *stars* is bold
  let text = substitute(text, ' \*\(\w\+\)\* ', ' <b>\1</b> ', 'g')

  if text =~ '\[\[[^]]*\]\]'
    let text = substitute(text, '\[\[\([^]]*\)\]\]', '\=MakeLink(submatch(1))', 'g')
  endif
  if text =~ '$$DOCS'
    let text = substitute(text, '$$DOCS', 'https://zimbu.googlecode.com/hg/docs', 'g')
  endif
  return text
endfunc

while l <= line('$')
  let text = getline(l)
  let nextText = getline(l + 1)

  " Drop Vim modeline.
  if text =~ '^vim:'
    exe l . "delete"
    continue
  endif

  " Check for h1 and h2 headers.
  let type = ''
  let name = ''
  if nextText =~ '^===' 
    let type = 'h1'
  elseif nextText =~ '^---'
    let type = 'h2'
  endif
  if type != ''
    if didH3
      call add(contents, '</div>')
      let didH3 = 0
    endif
    if l > 2
      call append(l - 1, '<hr>')
      let l = l + 1
    endif
    if text != 'Contents' && text != 'Zimbu Language Specification'
      let h2id = Title2Name(text)
      let name = '<a name="' . h2id . '"></a>'
      if type == 'h1'
	let cname = 'topItem'
      else
	let cname = 'contItem'
      endif
      call add(contents, '<div class="' . cname . '"><a href="#' . h2id . '">' . HtmlEscape(text) . '</a></div>')
    endif
    call EndPara()
    call setline(l, name . '<' . type . '>' . HtmlEscape(text) . '</' . type . '>')
    exe (l + 1) . 'delete'
    let l = l + 1
    continue
  endif

  " Check for lower level headers.
  let name = ''
  if text =~ '^### '
    let type = 'h3'
    let htext = substitute(text, '^##* ', '', '')
    let id = h2id . '_' . Title2Name(htext)
    let name = '<a name="' . id . '"></a>'
    if !didH3
      call add(contents, '<div class="contLead">')
      let didH3 = 1
    endif
    call add(contents, '<span class="contSub"><a href="#' . id . '">' . HtmlEscape(htext) . '</a></span>')
  elseif text =~ '^#### '
    let type = 'h4'
  elseif text =~ '^##### '
    let type = 'h5'
  endif
  if type != ''
    call EndPara()
    let text = substitute(text, '^##* ', '', '')
    let text = name . '<div' . onclick . '><' . type . '>' . HtmlEscape(text) . '</' . type . '>'
    if onclick != ''
      let text .= '<div class="openclose">click to open/close</div>'
    endif
    let text .= '</div>'
    if onclick != ''
      let text .= '<div' . onclick . ' style="display: none" id="r' . rationaleId . '">'
      let onclick = ''
    endif
    call setline(l, text)
    let l = l + 1
    continue
  endif

  " Check for simple list.
  if text =~ '^-  '
    call EndPara()
    call append(l - 1, '<ul>')
    let l = l + 1
    while 1
      " get here when "l" has a line starting with "-  ".
      let text = Process(getline(l))
      call setline(l, '<li>' . substitute(text, '^-\s*', '', ''))
      let done = 0
      while 1
	let l = l + 1
	if getline(l) =~ '^-  '
	  " Found a next line starting with "-  ".
	  break
	endif
	if getline(l) !~ '^\s'
	  " Found a next line not starting with white space, end of the list.
	  let done = 1
	  break
	endif
      endwhile
      call append(l - 1, '</li>')
      let l = l + 1
      if done
	break
      endif
    endwhile
    call append(l - 1, '</ul>')
    let l = l + 2
    continue
  endif

  " Check for numbered list.
  if text =~ '^1\. '
    call EndPara()
    call append(l - 1, '<ol>')
    let l = l + 1
    while 1
      " get here when "l" has a line starting with "1. " or "2. ".
      let text = Process(getline(l))
      call setline(l, '<li>' . substitute(text, '^[12].\s*', '', ''))
      let done = 0
      while 1
	let l = l + 1
	if getline(l) =~ '^2\. '
	  " Found a next line starting with "2. ".
	  break
	endif
	if getline(l) !~ '^\s'
	  " Found a next line not starting with white space, end of the list.
	  let done = 1
	  break
	endif
      endwhile
      call append(l - 1, '</li>')
      let l = l + 1
      if done
	break
      endif
    endwhile
    call append(l - 1, '</ol>')
    let l = l + 2
    continue
  endif

  if text =~ '^<zimbu'
    " Block with Zimbu code, apply syntax highlighting.
    let start = l
    let l = search('</zimbu', 'W')
    if l == 0
      break
    endif
    let lines = getline(start + 1, l - 1)
    new
    let zimbuBuf = bufnr('%')
    call append(0, lines)
    $delete
    setlocal ft=zimbu
    TOhtml
    %s/id='vimCodeElement'/class='vimCodeElement'/e
    let l1 = search('<body\>') + 1
    let l2 = search('</body>') - 1
    let html = getline(l1, l2)
    quit!
    exe bufwinnr(zimbuBuf) . 'wincmd w'
    quit!
    exe bufwinnr(textBuf) . 'wincmd w'
    exe start . ',' . l . 'delete'
    call append(start - 1, html)
    let l = start + len(html)
    continue
  endif

  if text =~ '^<rationale>'
    let rationaleId += 1
    if nextText =~ '^###'
      " Put the open/hide handling on the next header.
      call setline(l, '<div class="rationale">')
      let onclick = ' onclick="showHide(''r' . rationaleId . ''')"'
    else
      " Put the open/hide handling a header here.
      let text = '<div class="rationale">'
      let text .= '<div' . onclick . '>Rationale'
      let text .= '<span class="openclose">click to open/close</span></div>'
      let text .= '<div' . onclick . ' style="display: none" id="r' . rationaleId . '">'
      call setline(l, text)
    endif
    let l = l + 1
    continue
  endif
  if text =~ '^</rationale>'
    call setline(l, '</div></div>')
    let l = l + 1
    let onclick = ''
    continue
  endif

  if text =~ '^<'
    " Skip text between tags, e.g. <pre> ... </pre>
    " Does NOT handle nesting.
    call EndPara()
    let tag = substitute(text, '<\([a-z0]*\).*', '\1', '')
    if tag !=? "img"
      exe l
      let nl = search('</' . tag, 'W')
      if nl == 0
	break
      endif
      exe 'silent ' . (l + 1) . "," . (nl - 1) . 's/&/\&amp;/ge'
      exe 'silent ' . (l + 1) . "," . (nl - 1) . 's/</\&lt;/ge'
      exe 'silent ' . (l + 1) . "," . (nl - 1) . 's/>/\&gt;/ge'
      let l = nl
    endif
    let l = l + 1
    continue
  endif

  " Hyperlink: [[link|text]]
  " Replace $$DOCS
  " Replace *bold*
  let ntext = Process(text)
  if ntext != text
    let text = ntext
    call setline(l, text)
  endif

  if text =~ '^|+\=\*\= '
    " Table
    call EndPara()
    let border = text =~ '^|+' ? '1' : '0'
    let padding = border == 0 ? 0 : 3
    call append(l - 1, '<table cellpadding=' . padding . ' cellspacing=0 border=' . border . '>')
    let l = l + 1
    while 1
      let text = getline(l)
      if text !~ '^|+\=\*\= '
	break
      endif
      let text = Process(text)
      " Handle one row, starting with "^| " and ending in " |$"
      let rowclass = text =~ '^|+\=\* ' ? ' class="firstrow"' : ''
      let text = substitute(text, '|+\=\*\= ', '<tr' . rowclass . ' valign="top"><td class="firstcol">', '')
      while 1
	let text = substitute(text, ' | ', '</td><td class="col">', 'g')
	if text =~ ' |$'
	  break
	endif
	call setline(l, text)
	let l = l + 1
	let text = Process(getline(l))
      endwhile
      let text = substitute(text, ' |$', '</td></tr>', '')
      call setline(l, text)
      let l = l + 1
    endwhile

    call append(l - 1, '</td></tr></table>')
    let l = l + 1
    continue
  endif

  if text =~ '\S'
    " Non-empty line, start a paragraph.
    if !inPara
      call setline(l, '<p>' . text)
      let inPara = 1
    endif
  else
    " Empty line, end a paragraph.
    call EndPara()
  endif

  let l = l + 1
endwhile

call EndPara()

1
call search('Contents')
call append(line('.'), contents)

" Add header and footer.
0read header.html
$read footer.html

" Ignore swap file, might be looking at the output in another Vim.
silent! w! %:r.html
e!
exe currentLine
quit
