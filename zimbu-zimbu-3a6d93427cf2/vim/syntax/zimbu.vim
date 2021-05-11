" Vim syntax file
" Language:	Zimbu
" Maintainer:	Bram Moolenaar
" Last Change:	2014 Nov 23

if exists("b:current_syntax")
  finish
endif

syn include @CCode syntax/c.vim
unlet b:current_syntax
syn include @HtmlCode syntax/html.vim
unlet b:current_syntax
syn include @CssCode syntax/css.vim
syn case match
syn include @JavascriptCode syntax/javascript.vim

syn keyword zimbuTodo		TODO FIXME XXX contained
syn match   zimbuNoBar          "|" contained
syn match   zimbuParam  	"|[^| ]\+|" contained contains=zimbuNoBar
syn match   zimbuNoBacktick     "`" contained
syn match   zimbuCode  		"`[^`]\+`" contained contains=zimbuNoBacktick
syn match   zimbuComment	"#.*$" contains=zimbuTodo,zimbuParam,zimbuCode,@Spell
syn match   zimbuComment	"/\*.\{-}\*/" contains=zimbuTodo,zimbuParam,zimbuCode,@Spell

syn match   zimbuChar	"'\\\=.'"
syn match   zimbuChar	"'\\x..'"
syn match   zimbuChar	"'\\u....'"
syn match   zimbuChar	"'\\U........'"

syn keyword zimbuBasicType	bool status
syn keyword zimbuBasicType	int1 int2 int3 int4 int5 int6 int7
syn keyword zimbuBasicType	int9 int10 int11 int12 int13 int14 int15
syn keyword zimbuBasicType	int int8 int16 int32 int64 bigInt
syn keyword zimbuBasicType	nat nat8 byte nat16 nat32 nat64 bigNat
syn keyword zimbuBasicType	nat1 nat2 nat3 nat4 nat5 nat6 nat7
syn keyword zimbuBasicType	nat9 nat10 nat11 nat12 nat13 nat14 nat15
syn keyword zimbuBasicType	float float32 float64 float80 float128
syn keyword zimbuBasicType	fixed1 fixed2 fixed3 fixed4 fixed5 fixed6
syn keyword zimbuBasicType	fixed7 fixed8 fixed9 fixed10 fixed11 fixed12
syn keyword zimbuBasicType	fixed13 fixed14 fixed15

syn keyword zimbuCompType	string varString
syn keyword zimbuCompType	byteString varByteString
syn keyword zimbuCompType	tuple array list dict dictList set callback
syn keyword zimbuCompType	sortedList multiDict multiDictList multiSet
syn keyword zimbuCompType	complex complex32 complex64 complex80 complex128
syn keyword zimbuCompType	proc func def thread evalThread lock cond pipe
syn keyword zimbuCompType	regex

syn keyword zimbuType   VAR dyn type USE GET
syn match zimbuType	"IO.File"
syn match zimbuType	"IO.Stat"

syn cluster zimbuTypeCluster contains=zimbuBasicType,zimbuCompType,zimbuType,zimbuModule

syn keyword zimbuStatement IF ELSE ELSEIF IFNIL WHILE REPEAT FOR IN TO STEP
syn keyword zimbuStatement DO UNTIL SWITCH WITH
syn keyword zimbuStatement TRY CATCH FINALLY
syn keyword zimbuStatement GENERATE_IF GENERATE_ELSE GENERATE_ELSEIF
syn keyword zimbuStatement GENERATE_ERROR
syn keyword zimbuStatement BUILD_IF BUILD_ELSE BUILD_ELSEIF
syn keyword zimbuStatement CASE MATCH DEFAULT FINAL ABSTRACT VIRTUAL DEFINE
syn keyword zimbuStatement REPLACE PARENT LOCAL
syn keyword zimbuStatement IMPLEMENTS EXTENDS AUGMENTS GROWS
syn keyword zimbuStatement PART ALIAS TYPE CONNECT WRAP
syn keyword zimbuStatement BREAK CONTINUE PROCEED
syn keyword zimbuStatement RETURN EXIT THROW DEFER
syn keyword zimbuStatement IMPORT AS OPTIONS MAIN
syn keyword zimbuStatement INTERFACE PIECE INCLUDE MODULE ENUM BITS
syn keyword zimbuStatement SHARED STATIC
syn keyword zimbuStatement LAMBDA
syn match zimbuStatement "\<\(FUNC\|PROC\|DEF\)\>"
syn match zimbuStatement "\<CLASS\>"
syn match zimbuStatement "}"

syn match zimbuAttribute "@backtrace=no\>"
syn match zimbuAttribute "@backtrace=yes\>"
syn match zimbuAttribute "@abstract\>"
syn match zimbuAttribute "@earlyInit\>"
syn match zimbuAttribute "@default\>"
syn match zimbuAttribute "@define\>"
syn match zimbuAttribute "@replace\>"
syn match zimbuAttribute "@final\>"
syn match zimbuAttribute "@primitive\>"
syn match zimbuAttribute "@javascript\>"
syn match zimbuAttribute "@notOnExit\>"

syn match zimbuAttribute "@test\>"
syn match zimbuAttribute "@testOnly\>"

syn match zimbuAttribute "@private\>"
syn match zimbuAttribute "@protected\>"
syn match zimbuAttribute "@public\>"
syn match zimbuAttribute "@local\>"
syn match zimbuAttribute "@file\>"
syn match zimbuAttribute "@directory\>"
syn match zimbuAttribute "@read=private\>"
syn match zimbuAttribute "@read=protected\>"
syn match zimbuAttribute "@read=public\>"
syn match zimbuAttribute "@read=file\>"
syn match zimbuAttribute "@read=directory\>"
syn match zimbuAttribute "@items=private\>"
syn match zimbuAttribute "@items=protected\>"
syn match zimbuAttribute "@items=public\>"
syn match zimbuAttribute "@items=file\>"
syn match zimbuAttribute "@items=directory\>"

" Exception names
syn match zimbuException "\<E\."  " must be first
syn match zimbuException "\<E\.Exception\>"
syn match zimbuException "\<E\.Exit\>"
syn match zimbuException "\<E\.Interrupt\>"
syn match zimbuException "\<E\.TimeOut\>"
syn match zimbuException "\<E\.Error\>"
syn match zimbuException "\<E\.OutOfMemory\>"
syn match zimbuException "\<E\.NilAccess\>"
syn match zimbuException "\<E\.MemoryAccess\>"
syn match zimbuException "\<E\.Init\>"
syn match zimbuException "\<E\.Check\>"
syn match zimbuException "\<E\.Unsupported\>"
syn match zimbuException "\<E\.BadValue\>"
syn match zimbuException "\<E\.OutOfRange\>"
syn match zimbuException "\<E\.KeyNotFound\>"
syn match zimbuException "\<E\.ItemNotFound\>"
syn match zimbuException "\<E\.KeyExists\>"
syn match zimbuException "\<E\.IllegalByte\>"
syn match zimbuException "\<E\.Arithmetic\>"
syn match zimbuException "\<E\.DivideByZero\>"
syn match zimbuException "\<E\.Overflow\>"
syn match zimbuException "\<E\.IOError\>"
syn match zimbuException "\<E\.FileNotFound\>"
syn match zimbuException "\<E\.AccessDenied\>"
syn match zimbuException "\<E\.Pipe\>"
syn match zimbuException "\<E\.Dyn\>"
syn match zimbuException "\<E\.WrongType\>"
syn match zimbuException "\<E\.Thread\>"
syn match zimbuException "\<E\.Internal\>"

syn keyword zimbuMethod NEW EQUAL COPY COMPARE SIZE GET SET INIT EARLYINIT

syn keyword zimbuOperator IS ISNOT ISA ISNOTA

syn keyword zimbuModule  ARG CHECK CTX GC IO LOG PROTO SYS TEST HTTP ZC ZUT ZWT T TIME THREAD RE

syn match zimbuImport  "\.\zsPROTO"
syn match zimbuImport  "\.\zsCHEADER"

"syn match zimbuString  +"\([^"\\]\|\\.\)*\("\|$\)+ contains=zimbuStringExpr
syn region zimbuString  start=+"+  skip=+[^"\\]\|\\.+ end=+"\|$+ contains=zimbuStringExpr
syn match zimbuString  +R"\([^"]\|""\)*\("\|$\)+
syn region zimbuLongString  start=+''"+ end=+"''+
syn match zimbuStringExpr +\\([^)]*)+hs=s+2,he=e-1 contained contains=zimbuString,zimbuParenPairOuter
syn region zimbuParenPairOuter  start=+(+ms=s+1  end=+)+me=e-1 contained contains=zimbuString,zimbuParenPair
syn region zimbuParenPair  start=+(+  end=+)+ contained contains=zimbuString,zimbuParenPair

syn keyword zimbuFixed  TRUE FALSE NIL THIS THISTYPE FAIL OK
syn keyword zimbuError  NULL

" trailing whitespace
syn match   zimbuSpaceError   display excludenl "\S\s\+$"ms=s+1
" mixed tabs and spaces
syn match   zimbuSpaceError   display " \+\t"
syn match   zimbuSpaceError   display "\t\+ "

syn match zimbuUses contained "\<uses([a-zA-Z0-9_ ,]*)"
syn match zimbuBlockgc contained "blockgc"
syn match zimbuBlockComment contained " #.*"

" For ZUT: HTML template
syn match zimbuHtmlStart "\<TEMPLATE [a-zA-Z0-9_]\+(\_[^)]*).*\<ZUT.Html\>.*" nextgroup=zimbuHtml skipnl contains=zimbuAttribute,zimbuTemplateKeyword,@zimbuTypeCluster
syn match zimbuTemplateKeyword "TEMPLATE" contained
syn region zimbuHtml start="." end="\ze}" contained contains=@HtmlCode,zimbuInZut,zimbuZutComment

" For ZUT: Attributes template
syn match zimbuAttributesStart "\<TEMPLATE [a-zA-Z0-9_]\+(\_[^)]*).*\<ZUT.Attributes\>.*" nextgroup=zimbuAttributes skipnl contains=zimbuAttribute,zimbuTemplateKeyword,@zimbuTypeCluster
syn region zimbuAttributes start="." end="\ze}" contained contains=@HtmlCode,zimbuInZut,zimbuZutComment

" For ZUT: Javascript template
syn match zimbuJavascriptStart "\<TEMPLATE [a-zA-Z0-9_]\+(\_[^)]*).*\<ZUT.Javascript\>.*" nextgroup=zimbuJavascript skipnl contains=zimbuAttribute,zimbuTemplateKeyword,@zimbuTypeCluster
syn region zimbuJavascript start="." end="\ze}" contained contains=@JavascriptCode,zimbuInZut,zimbuZutComment

" For ZUT: Url template
syn match zimbuUrlStart "\<TEMPLATE [a-zA-Z0-9_]\+(\_[^)]*).*\<ZUT.Url\>.*" nextgroup=zimbuUrl skipnl contains=zimbuAttribute,zimbuTemplateKeyword,@zimbuTypeCluster
syn region zimbuUrl start="." end="\ze}" contained contains=zimbuInZut,zimbuZutComment

" For ZUT: Text template
syn match zimbuTextStart "\<TEMPLATE [a-zA-Z0-9_]\+(\_[^)]*).*\<string\>.*" nextgroup=zimbuText skipnl contains=zimbuAttribute,zimbuTemplateKeyword,@zimbuTypeCluster
syn region zimbuText start="." end="\ze}" contained contains=zimbuInZut,zimbuZutComment

" For ZUT: Css template
syn match zimbuCssStart "\<TEMPLATE [a-zA-Z0-9_]\+(\_[^)]*).*\<ZUT.Css\>.*" nextgroup=zimbuCss skipnl contains=zimbuAttribute,zimbuTemplateKeyword,@zimbuTypeCluster
syn region zimbuCss start="." end="\ze}" contained contains=@CssCode,zimbuInZut,zimbuZutComment

" For ZUT: nameless Css template
syn match zimbuCssKeyword "\<CSS\>"
syn match zimbuCssBlockStart "\<CSS\>\s*\(#.*\)\=$" nextgroup=zimbuCss skipnl contains=zimbuCssKeyword

syn match zimbuZutComment contained "  # .*" containedin=cssDefinition,htmlHead,cssStyle
syn match zimbuZutComment contained "^ \=# .*" containedin=cssDefinition,htmlHead,cssStyle

syn region zimbuInZut matchgroup=zimbuHtmlBrackets start="[[]=\?" end="]" contains=TOP, contained keepend containedin=cssDefinition,cssAttrRegion


syn region zimbuCregion matchgroup=zimbuCblock start="^>>>" end="^<<<.*" contains=@CCode,zimbuUses,zimbuBlockgc,zimbuBlockComment keepend

" Assume long strings and C regions don't take more than 200 lines.
syn sync minlines=200

" When we find the start of a long string, without a # or " before it, we are
" sure to be inside a long string.
syn sync match zimbuLongStringSync grouphere zimbuLongString +^[^"#]*''\"+

hi def link zimbuBasicType	Type
hi def link zimbuCompType	Type
hi def link zimbuType		Type
hi def link zimbuTemplateKeyword	Statement
hi def link zimbuAttributesKeyword	Statement
hi def link zimbuCssKeyword	Statement
hi def link zimbuStatement	Statement
hi def link zimbuOperator	Statement
hi def link zimbuMethod		PreProc
hi def link zimbuModule		PreProc
hi def link zimbuImport		PreProc
hi def link zimbuUses		PreProc
hi def link zimbuBlockgc	PreProc
hi def link zimbuAttribute	PreProc
hi def link zimbuException	PreProc
hi def link zimbuString		Constant
hi def link zimbuLongString	Special
hi def link zimbuChar		Constant
hi def link zimbuFixed		Constant
hi def link zimbuComment	Comment
hi def link zimbuCommentStart	zimbuComment
hi def link zimbuBlockComment	Comment
hi def link zimbuZutComment	Comment
hi def link zimbuCblock		Comment
hi def link zimbuTodo		Todo
hi def link zimbuParam		Constant
hi def link zimbuCode		Statement
hi def link zimbuNoBar		Ignore
hi def link zimbuNoBacktick	Ignore
hi def link zimbuSpaceError	Error
hi def link zimbuError		Error
hi def link zimbuHtmlBrackets	PreProc

let b:current_syntax = "zimbu"

" vim: ts=8
