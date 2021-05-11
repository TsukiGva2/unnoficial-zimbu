/*
 * Generated from Zimbu file plugin/zut/pluginzut.zu
 */
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#if defined(__MINGW32__) || defined(_MSC_VER)
# define GC_SIG SIGABRT
# include <excpt.h>
#else
# define GC_SIG SIGUSR2
#endif
#include <sys/time.h>
#include <time.h>

/*
 * TYPEDEFS
 */

#ifdef __MINGW32__
# define ZINT_FORMAT "%I64d"
# define ZNAT_FORMAT "%I64u"
# define ZINT_XFORMAT "%I64x"
#else
# define ZINT_FORMAT "%lld"
# define ZNAT_FORMAT "%llu"
# define ZINT_XFORMAT "%llx"
#endif
#define ZFLOAT_FORMAT "%g"
typedef long long Ti; /* int */
typedef short Ti16; /* int16 */
typedef int Ti32; /* int32 */
typedef unsigned long long Tu; /* nat */
typedef unsigned char Tc; /* byte */
typedef unsigned short Tu16; /* nat16 */
typedef unsigned int Tu32; /* nat32 */
typedef double Tf; /* float */
typedef float Tf32; /* float32 */
typedef __INTPTR_TYPE__ Tip; /* int for pointer */
typedef long long Tbb; /* big BITS */

typedef int Tbs; /* small BITS */
typedef int Tb; /* bool */
typedef int Ts; /* status */
typedef int Te; /* enum */
typedef struct Zref__S Tr; /* object ref */
typedef struct Zobj__S To; /* object description */
typedef union {
 Ti ival;
 Tf fval;
 void *ptr;
} Tz; /* dyn value */
typedef struct Ztype__S Tt; /* type */
typedef struct Ztypeo__S Tto; /* type with To pointer */
#define ZOH_OFF 0
typedef struct ZforString__S Tfs; /* FOR in string */
typedef struct ZforList__S Tfl; /* FOR in list */
typedef struct ZforDict__S Tfd; /* FOR in dict */
typedef struct ZforRange__S Tfr; /* FOR in range */
typedef struct garray__S Tg; /* grow array */

typedef struct CArray__S Ta; /* array head */

typedef struct CListHead__S Tl; /* list head */

typedef unsigned long Zhashtype;
typedef struct CDictItem__S CDictItem;
typedef struct CDictHead__S Td;

/* including TIMEModule typedefs */
typedef struct Y2KX__S Y2KX; /* MTIMEModule.Values */
/* TIMEModule done */
/* including EModule typedefs */
typedef struct Ytlm__S Ytlm; /* MEModule.Exception */
typedef struct YEro__S YEro; /* MEModule.Exit */
typedef struct YKhn__S YKhn; /* MEModule.OutOfMemory */
typedef struct Y1uN__S Y1uN; /* MEModule.NilAccess */
typedef struct YAxe__S YAxe; /* MEModule.MemoryAccess */
typedef struct YVNj__S YVNj; /* MEModule.Init */
typedef struct Yalz__S Yalz; /* MEModule.BadValue */
typedef struct Yw3O__S Yw3O; /* MEModule.OutOfRange */
typedef struct Y2EX__S Y2EX; /* MEModule.KeyNotFound */
typedef struct YX0i__S YX0i; /* MEModule.KeyExists */
typedef struct YP_P__S YP_P; /* MEModule.IllegalByte */
typedef struct YzSI__S YzSI; /* MEModule.DivideByZero */
typedef struct YXKl__S YXKl; /* MEModule.IOError */
typedef struct YuDC__S YuDC; /* MEModule.WrongType */
typedef struct YrHq__S YrHq; /* MEModule.Internal */
/* EModule done */
/* including ZModule typedefs */
typedef struct YkxB__S YkxB; /* MZModule.Pos */
/* ZModule done */
/* including IOModule typedefs */
typedef struct Yw8L__S Yw8L; /* MIOModule.File */
typedef struct YjUM__S YjUM; /* MIOModule.StringWriter */
/* IOModule done */
/* including SETModule typedefs */
typedef struct Yhqr__S Yhqr; /* MSETModule.Set__t1 */
/* SETModule done */
/* including ARGModule typedefs */
typedef struct YnU5__S YnU5; /* MARGModule.Status */
typedef struct YuMQ__S YuMQ; /* MARGModule.Usage */
typedef struct Y86c__S Y86c; /* MARGModule.Bool */
typedef struct YJQu__S YJQu; /* MARGModule.Int */
typedef struct YzqH__S YzqH; /* MARGModule.String */
typedef struct Y_SI__S Y_SI; /* MARGModule.StringList */
/* ARGModule done */
/* including Input typedefs */
typedef struct YeYq__S YeYq; /* Input */
/* Input done */
/* including Token typedefs */
/* including zui typedefs */
/* including Proto typedefs */
typedef struct Ys_q__S Ys_q; /* MProto.E_ProduceError */
typedef struct YOEA__S YOEA; /* MProto.E_BinaryError */
typedef struct YqvM__S YqvM; /* MProto.FieldSpec */
typedef struct YLWE__S YLWE; /* MProto.Writer */
/* Proto done */
typedef struct Ysbp__S Ysbp; /* MZui.Position */
/* zui done */
typedef struct Yev8__S Yev8; /* Token */
/* Token done */
/* including TokenInput typedefs */
/* including Tokenizer typedefs */
/* including ZuiFile typedefs */
typedef struct YgKE__S YgKE; /* ZuiFile */
/* ZuiFile done */
typedef struct YsZx__S YsZx; /* MTokenizer.Node */
/* Tokenizer done */
typedef struct Y7Sj__S Y7Sj; /* TokenInput */
/* TokenInput done */
typedef struct Yihi__S Yihi; /* Import */
/*
 * STRUCTS
 */
/* IO.eof */
#define Y3QJ EOF


typedef struct {
 int line;
 int col;
} Tcpos;
typedef struct {
 Ti offset;
 Tc *fileName;
 Tc *methodName;
 Tcpos *table;
} Tcode;

void *Za(size_t size);
void *ZaNm(size_t size);
void *ZaNmi(size_t size);
void *Zran(void *op, size_t osize, size_t nsize);
void *ZranNm(void *op, size_t osize, size_t nsize);
void ZthrowOutOfMemory(Ti size);
char *emergencyAlloc = NULL;
size_t emergencyAllocUsed = 0;
void ZthrowDeadly(int nr);
Tc *ZnewString(Tc *p, Ti len);
void ZthrowCstringNil(char *text);
void ZthrowCstringBadValue(char *msg);
void ZthrowInternal(Tc *t);
Tc *Zenum2string(char **names, Te n);

char *ZgetCstring(Tc *s);
struct ZforString__S {
 Tc *ptr;
 Ti idx;
 Ti len;
};
struct ZforList__S {
 Tl *l;
 Ti i;
 Ti *keyp;
 void *valp;
};
struct ZforDict__S {
 Td *d;
 CDictItem *di;
 Ti todo;
 void *keyp;
 void *valp;
};
struct ZforRange__S {
 Ti idx;
 Ti step;
 Ti last;
};

void ZthrowObject(Tr *eo);
void ZthrowIobject(Tr eo);
struct garray__S {
 Tc *data;
 int used;
 int len;
};

struct Zref__S {
 void *ptr;
 Tc **table;
 int  type;
};
Tr trZero = {NULL,NULL,0};
struct Zobj__S {
 int off;
 Tt *type;
};

struct Ztype__S {
 int nr;
 Tc *name;
 void *ToString;
};
struct Ztypeo__S {
 int nr;
 Tc *name;
 void *ToString;
 char **names;
 To *to;
};
extern Tt bool__T;
extern Tt byte__T;
extern Tt byteString__T;
extern Tt float128__T;
extern Tt float32__T;
extern Tt float80__T;
extern Tt float__T;
extern Tt int16__T;
extern Tt int32__T;
extern Tt int8__T;
extern Tt int__T;
extern Tt nat16__T;
extern Tt nat32__T;
extern Tt nat__T;
extern Tt status__T;
extern Tt string__T;
extern Tt type__T;
extern Tt array__T;
extern Tt list__T;
extern Tt dict__T;
extern Tt iobj__T;

struct CArray__S {
 void *ptr;
 int dim;
 Ti size[3];
 Tt *itemType;
 int itemSize;
 int tosNr;
};
void ZfreeArray(Ta *head);
void ZArrayToStringGa(Ta *head, int useq, Tg *ga);
Ta *ZnewArray(Tt *itemType, int itemSize, Ti size);
struct CListHead__S {
 Tt *itemType;
 void **items;
 Ti empty;
 Ti space;
 Ti itemCount;
 int itemSize;
 int tosNr;
};
Tl *ZLa(Tl *head, Ti after, Tz val);
Tl *ZnewList(Tt *itemType, Ti size);
Tl *ZLap(Tl *head, Tz val);
void *ZListGetPtr(Tl *head, Ti idx);
void *ZListRemovePtrItem(Tl *head, Ti idx);
void ZListToStringGa(Tl *head, int useq, Tg *ga);
#define HT_INIT_SIZE 16
#define PERTURB_SHIFT 5

#define DTYPE_ORDERED 1 /* dict with list to keep order of items */

#define CDI_FLAG_USED 1
#define CDI_FLAG_DEL 2
struct CDictItem__S {
 Zhashtype hash;
 union {
  Tz key;
  Tr iokey;
 };
 union {
  Tz item;
  Tr ioitem;
 };
 CDictItem *lnext;
 CDictItem *lprev;
 int flags;
};

struct CDictHead__S {

 Zhashtype mask;
 Zhashtype used;
 Zhashtype extra;
 Zhashtype filled;
 int tosNr;
 int type;
 CDictItem *array;
 CDictItem smallArray[HT_INIT_SIZE];
 Tt *keyType;
 Tt *itemType;
 int (*eqfunc)(void *i, Tz *v);
 CDictItem *first;
 CDictItem *last;
};
void ZDictToStringGa(Td *d, int keyUseq, int itemUseq, Tg *ga);
YkxB *MZ__callerPos(void);

Tl *MZ__backtrace(Ti zkip, Ti limit);

YkxB *MZ__posnr2pos(YkxB *t, Ti pos);
typedef struct {
 char text[5];
} Zs5;
/* including TIMEModule structs */
typedef struct {
 char text[3];
} Zs3;
struct Y2KX__S {
 Ti Vusec;
 Ti Vsec;
 Ti Vmin;
 Ti Vhour;
 Ti Vday;
 Ti Vmonth;
 Ti Vyear;
 Ti VweekDay;
 Ti VyearDay;
 Te Vdst;
};
extern Tto Y2KX__T;
typedef struct {
 char text[8];
} Zs8;
/* TIMEModule done */
/* including EModule structs */
typedef struct {
 char text[4];
} Zs4;
typedef struct {
 char text[13];
} Zs13;
typedef struct {
 char text[11];
} Zs11;
typedef struct {
 char text[39];
} Zs39;
typedef struct {
 char text[12];
} Zs12;
struct Ytlm__S {
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Ytlm__T;
typedef struct {
 char text[7];
} Zs7;
struct YEro__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
 Ti Vvalue;
};
extern Tto YEro__T;
typedef struct {
 char text[6];
} Zs6;
typedef struct {
 char text[28];
} Zs28;
typedef struct {
 char text[9];
} Zs9;
struct YKhn__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YKhn__T;
struct Y1uN__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y1uN__T;
struct YAxe__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YAxe__T;
typedef struct {
 char text[14];
} Zs14;
struct YVNj__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YVNj__T;
struct Yalz__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yalz__T;
typedef struct {
 char text[10];
} Zs10;
struct Yw3O__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yw3O__T;
struct Y2EX__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y2EX__T;
typedef struct {
 char text[17];
} Zs17;
typedef struct {
 char text[18];
} Zs18;
struct YX0i__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YX0i__T;
typedef struct {
 char text[22];
} Zs22;
typedef struct {
 char text[23];
} Zs23;
struct YP_P__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YP_P__T;
struct YzSI__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YzSI__T;
struct YXKl__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YXKl__T;
typedef struct {
 char text[15];
} Zs15;
struct YuDC__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YuDC__T;
struct YrHq__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YrHq__T;
/* EModule done */
/* including ZModule structs */
typedef struct {
 char text[16];
} Zs16;
struct YkxB__S {
 Tc *Vfilename;
 Ti Vlnum;
 Ti Vcol;
 Tc *Vtext;
};
extern Tto YkxB__T;
/* ZModule done */
/* including IOModule structs */
typedef struct {
 char text[27];
} Zs27;
typedef struct {
 char text[30];
} Zs30;
typedef struct {
 char text[19];
} Zs19;
typedef struct {
 char text[53];
} Zs53;
struct Yw8L__S {
 FILE * Vfd;
 Tc *Vname;
};
extern Tto Yw8L__T;
typedef struct {
 char text[2];
} Zs2;
struct YjUM__S {
 Ti VsLen;
 Ta *Vs;
 Tc *Vx;
};
extern Tto YjUM__T;
/* IOModule done */
/* including LOGModule structs */
typedef struct {
 char text[45];
} Zs45;
/* LOGModule done */
/* including SETModule structs */
struct Yhqr__S {
 Td *Vdict;
};
extern Tto Yhqr__T;
/* SETModule done */
/* including ARGModule structs */
struct YnU5__S {
};
extern Tto YnU5__T;
typedef struct {
 char text[51];
} Zs51;
typedef struct {
 char text[56];
} Zs56;
typedef struct {
 char text[20];
} Zs20;
typedef struct {
 char text[29];
} Zs29;
typedef struct {
 char text[31];
} Zs31;
typedef struct {
 char text[43];
} Zs43;
typedef struct {
 char text[21];
} Zs21;
typedef struct {
 char text[24];
} Zs24;
struct YuMQ__S {
 Tc *Vtext;
};
extern Tto YuMQ__T;
typedef struct {
 char text[42];
} Zs42;
typedef struct {
 char text[50];
} Zs50;
typedef struct {
 char text[52];
} Zs52;
typedef struct {
 char text[32];
} Zs32;
struct Y86c__S {
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tb Vcurrent;
 Tb Vdefault;
};
extern Tto Y86c__T;
struct YJQu__S {
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Ti Vcurrent;
 Ti Vdefault;
 Tl *VtheValueList;
};
extern Tto YJQu__T;
struct YzqH__S {
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tc *Vcurrent;
 Tc *Vdefault;
 Tl *VtheValueList;
};
extern Tto YzqH__T;
struct Y_SI__S {
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tl *Vcurrent;
 Tl *Vdefault;
};
extern Tto Y_SI__T;
/* ARGModule done */
/* including Input structs */
typedef struct {
 char text[25];
} Zs25;
struct YeYq__S {
 Tr Vfd;
 Tc *Vtext;
 Ti VtextIdx;
 YkxB *Vpos;
 Ti VprevLineCol;
 Tl *VcharStack;
 Tc *Vindent;
 Tb VallowTabs;
 YjUM *VrecordWriter;
};
extern Tto YeYq__T;
/* Input done */
/* including Token structs */
/* including zui structs */
/* including Proto structs */
char *MProto__EType[] = {
 (char*)20,
 "unknown",
 "bool",
 "bytes",
 "enum",
 "fixed32",
 "fixed64",
 "float",
 "double",
 "group",
 "int",
 "int32",
 "int64",
 "message",
 "sfixed32",
 "sfixed64",
 "sint32",
 "sint64",
 "string",
 "uint32",
 "uint64",
};
char *MProto__EType__name(Te n) {
 return (n < 0 || n >= (Te)(size_t)MProto__EType[0]) ? "INVALID" : MProto__EType[n + 1];
};
struct Ys_q__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Ys_q__T;
struct YOEA__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YOEA__T;
struct YqvM__S {
 Tc *Vname;
 Ti Vnr;
 Te Vtype;
 Tb Vrepeated;
};
extern Tto YqvM__T;
struct YLWE__S {
 Tr Vwriter;
 Tc *Vindent;
 Tb VuseNr;
 Ti VderefId;
 Ti VderefIdSize;
 Ti VderefTime;
 Ti VderefTimeSize;
};
extern Tto YLWE__T;
typedef struct {
 char text[34];
} Zs34;
typedef struct {
 char text[38];
} Zs38;
/* Proto done */
struct Ysbp__S {
Ti VderefTime;
Ti VderefId;
Ti VderefTimeSize;
Ti VderefIdSize;
 Ti Vf_line;
 Tb Vhas_line;
 Ti Vf_column;
 Tb Vhas_column;
 Tc *Vf_filename;
};
extern Tto Ysbp__T;
/* zui done */
char *CToken__EType[] = {
 (char*)143,
 "unknown",
 "eof",
 "sep",
 "line_sep",
 "comment",
 "empty",
 "nil",
 "this",
 "parent",
 "false",
 "true",
 "ok",
 "fail",
 "stringLiteral",
 "stringExprStart",
 "char",
 "any",
 "var",
 "use",
 "get",
 "threeDots",
 "id",
 "import",
 "as",
 "options",
 "alias",
 "type",
 "copy_start",
 "copy_end",
 "module",
 "class",
 "shared",
 "static",
 "interface",
 "piece",
 "enum",
 "bits",
 "func",
 "proc",
 "lambda",
 "extends",
 "implements",
 "include",
 "inf",
 "ninf",
 "nan",
 "return",
 "exit",
 "throw",
 "try",
 "catch",
 "finally",
 "defer",
 "new",
 "ready",
 "c",
 "i",
 "build_if",
 "build_elseif",
 "build_else",
 "generate_if",
 "generate_elseif",
 "generate_else",
 "generate_error",
 "if",
 "elseif",
 "else",
 "ifnil",
 "while",
 "break",
 "continue",
 "proceed",
 "switch",
 "case",
 "default",
 "do",
 "until",
 "for",
 "in",
 "to",
 "upto",
 "step",
 "comma",
 "semicolon",
 "colon",
 "question",
 "colonnil",
 "dotnil",
 "at",
 "dot",
 "p_open",
 "p_close",
 "c_open",
 "c_close",
 "sq_open",
 "sq_o_open",
 "sq_close",
 "dollar",
 "minus",
 "minmin",
 "plus",
 "plusplus",
 "tilde",
 "star",
 "slash",
 "percent",
 "concat",
 "bit_or",
 "bit_xor",
 "amp",
 "rshift",
 "lshift",
 "assign",
 "minassign",
 "plusassign",
 "multassign",
 "divassign",
 "percentassign",
 "tildeassign",
 "andassign",
 "orassign",
 "xorassign",
 "stringassign",
 "lshiftassign",
 "rshiftassign",
 "isis",
 "gives",
 "notequal",
 "match",
 "nomatch",
 "and",
 "or",
 "not",
 "gt",
 "gte",
 "lt",
 "lte",
 "is",
 "isnot",
 "isa",
 "isnota",
 "html",
 "css",
};
char *CToken__EType__name(Te n) {
 return (n < 0 || n >= (Te)(size_t)CToken__EType[0]) ? "INVALID" : CToken__EType[n + 1];
};
struct Yev8__S {
 Te Vtype;
 Tc *Vvalue;
 Tb VhasComment;
 Tb VhasCommentFirst;
 Ysbp *VzuiPos;
};
extern Tto Yev8__T;
/* Token done */
/* including TokenInput structs */
/* including Tokenizer structs */
/* including ZuiFile structs */
struct YgKE__S {
};
extern Tto YgKE__T;
/* ZuiFile done */
typedef struct {
 char text[40];
} Zs40;
struct YsZx__S {
 Ta *Vchildren;
 Tc *Vvalue;
 Te Vtype;
 Tb VisKeyword;
};
extern Tto YsZx__T;
/* Tokenizer done */
struct Y7Sj__S {
 YeYq *Vinput;
 Tl *VtokenStack;
 Yhqr *VusedIdKeywords;
};
extern Tto Y7Sj__T;
/* TokenInput done */
struct Yihi__S {
 Tc *VfileName;
 Tb VusedAsController;
};
extern Tto Yihi__T;
typedef struct {
 char text[37];
} Zs37;
typedef struct {
 char text[35];
} Zs35;
typedef struct {
 char text[26];
} Zs26;
/*
 * DECLARE FUNCTIONS AND GLOBALS
 */
Zs5 ZNilString = {"\003NIL\000"};
/* including TIMEModule declarations */
Ti Y9Rj(); /* MTIMEModule.current */
Y2KX *YgaY(Y2KX *t); /* MTIMEModule__CValues.NEW */
Y2KX *YgaYb(Y2KX *t, Ti Ausec); /* MTIMEModule__CValues.NEW */
Tc *YYTs(Y2KX *t); /* MTIMEModule__CValues.ToString */
Zs3 YV = {"\001/\000"};
Zs5 Y6O7 = {"\00302d\000"};
Zs3 YG = {"\001 \000"};
Zs3 Y5 = {"\001:\000"};
To ToY2KX[11];
char *StrY2KX[];
Zs8 YeCO = {"\006Values\000"};
Tt MTIMEModule__EDst__T = {23, 0, 0};
/* TIMEModule done */
/* including EModule declarations */
Tc *YH0V(Ytlm *t); /* MEModule__CException.ToString */
void YxaJ(Ytlm *t, Tr Aw); /* MEModule__CException.writeTo */
Zs4 YFDa = {"\002: \000"};
Zs13 YHbP = {"\013Exception: \000"};
Zs11 YDGe = {"\011Exception\000"};
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw); /* MEModule__CException.writeTo */
Zs39 Y62e = {"\045\nStack backtrace (last called first):\000"};
Zs12 Yv6_ = {"\012\n(unknown)\000"};
Zs3 Yk = {"\001\n\000"};
To ToYtlm[4];
char *StrYtlm[];
Tc *Ydtua(YEro *t); /* MEModule__CExit.ToString */
void YXHSa(YEro *t, Tr Aw); /* MEModule__CExit.writeTo */
Zs7 YxJ1 = {"\005EXIT \000"};
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw); /* MEModule__CExit.writeTo__p1 */
To ToYEro[5];
char *StrYEro[];
Zs6 YJMo = {"\004Exit\000"};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit); /* MEModule__COutOfMemory.NEW */
Zs28 YIBz = {"\032Out of memory (allocating \000"};
Zs9 YDSH = {"\007 bytes)\000"};
Tc *YKhn__YwtA__YH0V(YKhn *t); /* MEModule__COutOfMemory.ToString__p2 */
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
Tc *YKhn__Ytlm_I_imt[14];
To ToYKhn[4];
char *StrYKhn[];
Zs13 Y9Fv = {"\013OutOfMemory\000"};
void Y1KV(Ti Asize); /* MEModule.throwOutOfMemorySize */
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg); /* MEModule__CNilAccess.NEW__p2 */
Tc *Y1uN__YwtA__YH0V(Y1uN *t); /* MEModule__CNilAccess.ToString__p2 */
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
Tc *Y1uN__Ytlm_I_imt[14];
To ToY1uN[4];
char *StrY1uN[];
Zs11 Y4wO = {"\011NilAccess\000"};
void YvdV(YkxB *Apos, Tc *Atext); /* MEModule.throwNil */
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg); /* MEModule__CMemoryAccess.NEW__p2 */
Tc *YAxe__YwtA__YH0V(YAxe *t); /* MEModule__CMemoryAccess.ToString__p2 */
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
Tc *YAxe__Ytlm_I_imt[14];
To ToYAxe[4];
char *StrYAxe[];
Zs14 Y4QW = {"\014MemoryAccess\000"};
void YE93(Ti Anr); /* MEModule.throwDeadly */
Zs13 YkfG = {"\013signal SEGV\000"};
Zs12 YoEx = {"\012signal FPE\000"};
Zs12 YQNH = {"\012signal BUS\000"};
Zs9 YpCZ = {"\007signal \000"};
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
Tc *YVNj__YwtA__YH0V(YVNj *t); /* MEModule__CInit.ToString__p2 */
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw); /* MEModule__CInit.writeTo__p2 */
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw); /* MEModule__CInit.writeTo__p2 */
Tc *YVNj__Ytlm_I_imt[14];
To ToYVNj[4];
char *StrYVNj[];
Zs6 Ysqt = {"\004Init\000"};
void Y3w6(Tc *Atext); /* MEModule.throwInit */
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg); /* MEModule__CBadValue.NEW__p2 */
Tc *Yalz__YwtA__YH0V(Yalz *t); /* MEModule__CBadValue.ToString__p2 */
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
Tc *Yalz__Ytlm_I_imt[14];
To ToYalz[4];
char *StrYalz[];
Zs10 YEZq = {"\010BadValue\000"};
void Yaez(Tc *Atext); /* MEModule.throwBadValue */
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg); /* MEModule__COutOfRange.NEW__p3 */
Tc *Yw3O__Yalz__YwtA__YH0V(Yw3O *t); /* MEModule__COutOfRange.ToString__p3 */
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
Tc *Yw3O__Ytlm_I_imt[14];
To ToYw3O[4];
char *StrYw3O[];
Zs12 YFK2 = {"\012OutOfRange\000"};
void Y6NT(Ti Aindex, Tc *Amsg); /* MEModule.throwOutOfRange */
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg); /* MEModule__CKeyNotFound.NEW__p3 */
Tc *Y2EX__Yalz__YwtA__YH0V(Y2EX *t); /* MEModule__CKeyNotFound.ToString__p3 */
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
Tc *Y2EX__Ytlm_I_imt[14];
To ToY2EX[4];
char *StrY2EX[];
Zs13 YRiW = {"\013KeyNotFound\000"};
void Yxmk(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyNotFound */
Zs17 Ym6C = {"\017Key not found: \000"};
void Y5LT(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyNotFound */
Zs18 YJ3Y = {"\020Key not found: \"\000"};
Zs3 YI = {"\001\"\000"};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
Tc *YX0i__Yalz__YwtA__YH0V(YX0i *t); /* MEModule__CKeyExists.ToString__p3 */
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
Tc *YX0i__Ytlm_I_imt[14];
To ToYX0i[4];
char *StrYX0i[];
Zs11 Y9_h = {"\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {"\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {"\025Key already exists: \"\000"};
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg); /* MEModule__CIllegalByte.NEW__p3 */
Tc *YP_P__Yalz__YwtA__YH0V(YP_P *t); /* MEModule__CIllegalByte.ToString__p3 */
void YP_P__Yalz__YwtA__YxaJ(YP_P *t, Tr Aw); /* MEModule__CIllegalByte.writeTo__p3 */
void YP_P__Yalz__YwtA__YxaJa(YP_P *t, Tb Averbose, Tr Aw); /* MEModule__CIllegalByte.writeTo__p3 */
Tc *YP_P__Ytlm_I_imt[14];
To ToYP_P[4];
char *StrYP_P[];
Zs13 Ydbm = {"\013IllegalByte\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
Tc *YzSI__Ylz1__YwtA__YH0V(YzSI *t); /* MEModule__CDivideByZero.ToString__p3 */
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
Tc *YzSI__Ytlm_I_imt[14];
To ToYzSI[4];
char *StrYzSI[];
Zs14 YxFl = {"\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
Tc *YXKl__YwtA__YH0V(YXKl *t); /* MEModule__CIOError.ToString__p2 */
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
Tc *YXKl__Ytlm_I_imt[14];
To ToYXKl[4];
char *StrYXKl[];
Zs9 YTj3 = {"\007IOError\000"};
YuDC *YdhH(YuDC *t); /* MEModule__CWrongType.NEW */
Zs15 Ynjz = {"\015Type mismatch\000"};
Tc *YuDC__YwtA__YH0V(YuDC *t); /* MEModule__CWrongType.ToString__p2 */
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
Tc *YuDC__Ytlm_I_imt[14];
To ToYuDC[4];
char *StrYuDC[];
Zs11 YCoZ = {"\011WrongType\000"};
void YTuG(Ti Apos); /* MEModule.throwWrongType */
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg); /* MEModule__CInternal.NEW__p2 */
Tc *YrHq__YwtA__YH0V(YrHq *t); /* MEModule__CInternal.ToString__p2 */
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
Tc *YrHq__Ytlm_I_imt[14];
To ToYrHq[4];
char *StrYrHq[];
Zs10 YVki = {"\010Internal\000"};
void YUSH(YkxB *Apos, Tc *Atext); /* MEModule.throwInternal */
void YxIS(Tr Ae); /* MEModule.unhandledException */
void YvL0(Tr Ae); /* MEModule.writeToStderr */
void YQar(Tr A0, Tb A1, Tr A2); /* Ytlm_I__MwriteTo_I__bool__Yw8L_I */
/* EModule done */
/* including ZModule declarations */
YkxB *Ypp_(YkxB *t, Tc *Afilename); /* MZModule__CPos.NEW */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
void YnS4(YkxB *t); /* MZModule__CPos.nextLine */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {"\016[unknown file]\000"};
Zs8 YBpY = {"\006 line \000"};
Zs7 Y8ES = {"\005 col \000"};
To ToYkxB[5];
char *StrYkxB[];
Zs5 YBCs = {"\003Pos\000"};
/* ZModule done */
/* including STRINGModule declarations */
Tc *YwOB(Tc *Athis); /* MSTRINGModule.trim */
/* STRINGModule done */
/* including IOModule declarations */
Ti Y3QJ__NOT = -1 /* MIOModule.eof */;
Tr Y59X = {NULL}; /* MIOModule.stdin */
Tr Yb0q = {NULL}; /* MIOModule.stdout */
Tr YeNQ = {NULL}; /* MIOModule.stderr */
Tr Yd89(); /* MIOModule.newStdin */
Tr Yvyt(); /* MIOModule.newStdout */
Tr YsM3(); /* MIOModule.newStderr */
Tc **YdXi__imtt[4];
Tc **Y8is__imtt[4];
Ti YFeQ(Yw8L *t); /* MIOModule__CFile.readByte */
Zs18 YQe8 = {"\020File is not open\000"};
Ti YAPp(Yw8L *t); /* MIOModule__CFile.readChar */
Zs27 YPHa = {"\031first byte out of range: \000"};
Zs30 YKzT = {"\034found EOF when getting byte \000"};
Zs7 Ymwv = {"\005byte \000"};
Zs15 YPfW = {"\015 out of range\000"};
Zs19 Y8Gn = {"\021overlong sequence\000"};
Ts YwHoa(Yw8L *t, Tc *Atext); /* MIOModule__CFile.write */
Ts YGmp(Yw8L *t); /* MIOModule__CFile.flush */
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber); /* MIOModule__CFile.write__p1 */
Ts Yw8L__Ydti(Yw8L *t, Ti Achar); /* MIOModule__CFile.writeChar__p1 */
Zs53 Yv8w = {"\063UTF-8 character must be in range 0 - 0x10ffff, got \000"};
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext); /* MIOModule__CFile.print__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__Yw8L_I_imt[38];
Tc *Yw8L__Y8is_I_imt[21];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[2];
char *StrYw8L[];
Zs6 YtTU = {"\004File\000"};
Tr YsGz(Tc *AfileName); /* MIOModule.fileReader */
Tr YiBk(Tc *AfileName, Tb Atruncate); /* MIOModule.fileWriter */
Ts Yvcu(Tc *Atext); /* MIOModule.write */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Ts Ye7fa(YjUM *t, Ti Abyte); /* MIOModule__CStringWriter.writeByte */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Zs2 Ya = {"\000\000"};
Ti Y6jW(YjUM *t); /* MIOModule__CStringWriter.remove */
void YXip(YjUM *t); /* MIOModule__CStringWriter.clear */
void Y3_a(YjUM *t); /* MIOModule__CStringWriter.truncate */
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Ts YjUM__Ydti(YjUM *t, Ti Achar); /* MIOModule__CStringWriter.writeChar__p1 */
Ts YjUM__YRt7(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.print__p1 */
Tc *YjUM__Y8is_I_imt[21];
Tc *YjUM__YdXi_imt[3];
To ToYjUM[4];
char *StrYjUM[];
Zs14 YE4c = {"\014StringWriter\000"};
Ti Yr30(Tc *Afname); /* MIOModule.tailIndex */
Tc *YKFh(Tc *Afname); /* MIOModule.tail */
int JIOModule(int round);
/* IOModule done */
/* including LOGModule declarations */
Zs3 YLa = {"\001d\000"};
Zs7 YGwH = {"\005debug\000"};
Zs12 YhpM = {"\012Debug mode\000"};
Y86c *YU8T = 0; /* MLOGModule.debugFlag */
Zs3 Y2a = {"\001v\000"};
Zs9 YUsn = {"\007verbose\000"};
Zs45 YSuP = {"\053Verbose messages, repeat for more verbosity\000"};
Y86c *YlUb = 0; /* MLOGModule.verboseFlag */
Tt MLOGModule__ELevel__T = {23, 0, 0};
Zs7 YuXA = {"\005Flags\000"};
Tt MLOGModule__BFlags__T = {25, ((Tc*)&YuXA), 0};
Td *Ytd2 = NULL; /* MLOGModule.counts */
Ti Yrpn = 0; /* MLOGModule.errorCount */
void YDli(Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.error */
void Y2oO(Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.internal */
Tc *YmaW = ((Tc*)&Ya) /* MLOGModule.extraLead */;
void Ygkj(Te Alevel, Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.log */
Zs11 YJ5p = {"\011INTERNAL \000"};
Zs11 Yyq1 = {"\011Warning: \000"};
Zs9 Y27a = {"\007ERROR: \000"};
Zs16 Y3l3 = {"\016SEVERE ERROR: \000"};
Zs15 YmM8 = {"\015FATAL ERROR: \000"};
Zs3 YU = {"\001.\000"};
Zs5 YwV7 = {"\00306d\000"};
void YwlF(Tr Aout); /* MLOGModule.reportStack */
Zs12 YDzC = {"\012Backtrace:\000"};
Ti YvW3 = 0; /* MLOGModule.lastFlush */
Ti YOwl = 300000 /* MLOGModule.flushInterval */;
void Y7LJ(); /* MLOGModule.flush */
Tr Yz2b = {NULL}; /* MLOGModule.logFile */
Tb YiAD = 1 /* MLOGModule.useTimeStamp */;
int JLOGModule(int round);
/* LOGModule done */
/* including SETModule declarations */
int Ypau__r = 0; /* MSETModule__CSet__t1.Ready */
Yhqr *Ypau(Yhqr *t); /* MSETModule__CSet__t1.Init */
Yhqr *Yh95(Yhqr *t); /* MSETModule__CSet__t1.NEW */
Tc *Yehh(Yhqr *t); /* MSETModule__CSet__t1.ToString */
Tb YyHa(Yhqr *t, Tc *Akey); /* MSETModule__CSet__t1.has */
Yhqr *Y63C(Yhqr *t, Tc *Akey); /* MSETModule__CSet__t1.set */
To ToYhqr[2];
char *StrYhqr[];
Zs9 Yehz = {"\007Set__t1\000"};
/* SETModule done */
/* including ARGModule declarations */
Tc *YzvW = NULL; /* MARGModule.rawName */
Tl *Y1p3 = NULL; /* MARGModule.rawArgs */
Tl *Y6fX = NULL; /* MARGModule.cleanArgs */
Tb YQpY = 0; /* MARGModule.stopFlag */
Tb YUBd = 0; /* MARGModule.disabled */
Tb YhUP = 0; /* MARGModule.disableGiveHelp */
Tb Y_kI = 0; /* MARGModule.disableCompactVal */
Ti YMLU = 1 /* MARGModule.exitVal */;
YuMQ *Yun4 = 0; /* MARGModule.theUsage */
int Ytu___r = 0; /* MARGModule.Ready */
Ts Ytu_(); /* MARGModule.Init */
Ti Yd2Z(); /* MARGModule.Size */
Tc *YtgL(Ti Aindex); /* MARGModule.get */
To ToYnU5[1];
char *StrYnU5[];
Zs8 Yr32 = {"\006Status\000"};
void YY8i(); /* MARGModule.initCheck */
Zs51 YeBP = {"\061Using command line flag before they are available\000"};
void YZH8(); /* MARGModule.init */
Zs56 Y7T_ = {"\066ARG.disable() used but command line flags were defined\000"};
Zs3 YT = {"\001-\000"};
Zs4 Y1ia = {"\002--\000"};
Zs6 YqzQ = {"\004help\000"};
Zs10 Y3via = {"\010morehelp\000"};
Zs10 Yll7 = {"\010helpmore\000"};
Zs4 YhZb = {"\002no\000"};
Zs20 YcW8 = {"\022Invalid argument: \000"};
Zs29 Y2hB = {"\033Unknown command line flag: \000"};
Zs31 YcLH = {"\035Duplicate command line flag: \000"};
Zs5 YjK7 = {"\003yes\000"};
Zs6 YsfP = {"\004true\000"};
Zs7 YvpX = {"\005false\000"};
Zs43 YHSJ = {"\051Expected 'yes', 'no', 'true' or 'false': \000"};
Zs19 Y6QK = {"\021Unexpected = in: \000"};
Zs28 Y_ju = {"\032Missing argument for flag \000"};
Zs29 YjTs = {"\033INTERNAL: unknown flag type\000"};
void YSUO(Tc *Amsg); /* MARGModule.error */
Zs22 YkFE = {"\024To list flags use: '\000"};
Zs10 Y15F = {"\010 --help'\000"};
void Yfj5(Tb Averbose); /* MARGModule.displayHelp */
Zs21 YaBy = {"\023Command line flags:\000"};
Zs13 YwXF = {"\013--morehelp \000"};
Zs24 YEcf = {"\026show more verbose help\000"};
Zs8 Yy2p = {"\006number\000"};
Zs8 YanE = {"\006string\000"};
Zs12 YDci = {"\012string ...\000"};
Zs6 YulU = {"\004 ...\000"};
Zs4 YVZ = {"\002 [\000"};
Zs3 YEa = {"\001]\000"};
Zs4 Yq_ = {"\002 {\000"};
Zs3 Y9a = {"\001}\000"};
Zs5 Y_y2 = {"\003...\000"};
Zs6 Y2yA = {"\004... \000"};
Zs13 Ym4c = {"\013Defined in \000"};
void YTlu(Tc *Alead, Ti AmaxLeadLen); /* MARGModule.writeLead */
Tc *YAMW(YuMQ *t); /* MARGModule__CUsage.get */
Zs5 YMtG = {"\003%0%\000"};
To ToYuMQ[2];
char *StrYuMQ[];
Zs7 Y6qT = {"\005Usage\000"};
Td *Y7be = NULL; /* MARGModule.shortFlags */
Td *YBQy = NULL; /* MARGModule.longFlags */
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc); /* MARGModule__CBool.NEW */
void YEqoa(Y86c *t); /* MARGModule__CBool.setToDefault */
Tb YHoR(Y86c *t); /* MARGModule__CBool.get */
Tb YuOS(Y86c *t); /* MARGModule__CBool.value */
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CBool.NEW__p1 */
Zs42 Yc_h = {"\050Adding command line flag after using one\000"};
Zs50 Y6pY = {"\060Command line flag must have a short or long name\000"};
Zs52 Y9CP = {"\062short command line flag name must be one character\000"};
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos); /* MARGModule__CBool.throwDuplicate__p1 */
Zs9 YbbH = {"\007unknown\000"};
Zs32 YtzG = {"\036Duplicate command line flag: '\000"};
Zs17 YDyy = {"\017' also used at \000"};
Ti Y86c__Ye9f(Y86c *t); /* MARGModule__CBool.presentCount__p1 */
Tc *Y86c__YuQR_I_imt[19];
To ToY86c[12];
char *StrY86c[];
Zs6 YZ1F = {"\004Bool\000"};
void Y49ga(YJQu *t); /* MARGModule__CInt.setToDefault */
To ToYJQu[13];
char *StrYJQu[];
Zs5 YzBa = {"\003Int\000"};
void YJaza(YzqH *t); /* MARGModule__CString.setToDefault */
To ToYzqH[13];
char *StrYzqH[];
Zs8 YDAE = {"\006String\000"};
void YSkKa(Y_SI *t); /* MARGModule__CStringList.setToDefault */
To ToY_SI[12];
char *StrY_SI[];
Zs12 Ygf5 = {"\012StringList\000"};
int JARGModule(int round);
/* ARGModule done */
/* including INTModule declarations */
Tb YBbQ(Ti Athis); /* MINTModule.isWhite */
/* INTModule done */
/* including Input declarations */
YeYq *YOdr(YeYq *t, Tr Afd, Tc *Afname, Tc *Aindent, Tb Arecord); /* CInput.NEW */
Ti YAit(YeYq *t); /* CInput.get */
Zs21 YrKy = {"\023found NUL character\000"};
Zs21 YemR = {"\023found Tab character\000"};
Zs25 Y3Pw = {"\027found control character\000"};
void YmK2(YeYq *t, Ti Ac); /* CInput.push */
Tc *YJ25(YeYq *t); /* CInput.getRecord */
To ToYeYq[10];
char *StrYeYq[];
Zs7 YVUW = {"\005Input\000"};
/* Input done */
/* including Token declarations */
/* including zui declarations */
/* including Proto declarations */
Tt MProto__EType__T = {23, 0, MProto__EType__name};
Tt MProto__EBinaryType__T = {23, 0, 0};
Ys_q *Ys_q__YwtA__YRHR(Ys_q *t, Tc *Amsg); /* MProto__CE_ProduceError.NEW__p2 */
Tc *Ys_q__YwtA__YH0V(Ys_q *t); /* MProto__CE_ProduceError.ToString__p2 */
void Ys_q__YwtA__YxaJa(Ys_q *t, Tb Averbose, Tr Aw); /* MProto__CE_ProduceError.writeTo__p2 */
void Ys_q__YwtA__YxaJ(Ys_q *t, Tr Aw); /* MProto__CE_ProduceError.writeTo__p2 */
Tc *Ys_q__Ytlm_I_imt[14];
To ToYs_q[4];
char *StrYs_q[];
Zs16 Y4sk = {"\016E_ProduceError\000"};
YOEA *YOEA__YwtA__YRHR(YOEA *t, Tc *Amsg); /* MProto__CE_BinaryError.NEW__p2 */
Tc *YOEA__YwtA__YH0V(YOEA *t); /* MProto__CE_BinaryError.ToString__p2 */
void YOEA__YwtA__YxaJa(YOEA *t, Tb Averbose, Tr Aw); /* MProto__CE_BinaryError.writeTo__p2 */
void YOEA__YwtA__YxaJ(YOEA *t, Tr Aw); /* MProto__CE_BinaryError.writeTo__p2 */
Tc *YOEA__Ytlm_I_imt[14];
To ToYOEA[4];
char *StrYOEA[];
Zs15 YtJ_ = {"\015E_BinaryError\000"};
YqvM *Ykww(YqvM *t, Tc *Aname, Ti Anr, Te Atype, Tb Arepeated); /* MProto__CFieldSpec.NEW */
To ToYqvM[5];
char *StrYqvM[];
Zs11 Y5d5 = {"\011FieldSpec\000"};
YLWE *YrCUb(YLWE *t, Tr Awriter, Tc *Aindent, Tb AuseNr); /* MProto__CWriter.NEW */
void YEV9(YLWE *t); /* MProto__CWriter.initDeref */
Ti YcTI = 0; /* MProto__CWriter__X.derefTime */
To ToYLWE[8];
char *StrYLWE[];
Zs8 YaKG = {"\006Writer\000"};
Td *YXCQ = NULL; /* MProto.proto2binary */
Td *YLwW = NULL; /* MProto.binaryTypeValues */
Ti YqNA = 3 /* MProto.kTypeBits */;
Ti Ybyp(YqvM *Afspec); /* MProto.getBinaryTagSize */
Ti YFN0(Tr Amsg, YLWE *AprotoWriter); /* MProto.binarySize */
Zs34 Ytvm = {"\040INTERNAL: type not implemented: \000"};
Ti YMrV(Tr At, Tr Amsg, YqvM *Afspec, YLWE *AprotoWriter); /* MProto.binaryMessageSize */
void YP8Z(Tr Amsg, YLWE *AprotoWriter); /* MProto.writeText */
Zs15 YvJi = {"\015# reference: \000"};
Zs4 YN2 = {"\002# \000"};
Zs9 Y0Eh = {"\007 size: \000"};
Zs9 Y8RH = {"\007 bytes\n\000"};
void YWEg(Tr Amsg, YqvM *Afspec, Ti Aidx, YLWE *AprotoWriter); /* MProto.writeOneTextField */
Zs5 YxR2 = {"\003.9g\000"};
Zs6 YmwIa = {"\004.17g\000"};
Zs6 YHoE = {"\004TRUE\000"};
Zs7 Y2cy = {"\005FALSE\000"};
Zs4 YQ0 = {"\002\"\n\000"};
Zs4 Ywhc = {"\002{\n\000"};
Zs4 YZY = {"\002  \000"};
Zs4 YJkc = {"\002}\n\000"};
Zs38 Y80t = {"\044INTERNAL: field type not supported: \000"};
void YeeB(Tr At, Ti AfieldNr, YLWE *AprotoWriter); /* MProto.writeMessageText */
void YeeBa(Tr At, Ti AfieldNr, Ti Aidx, YLWE *AprotoWriter); /* MProto.writeMessageText */
Ti YmeT(Ti Avalue); /* MProto.getVarIntSize */
int JProto(int round);
/* Proto done */
Ysbp *Y602(Ysbp *t); /* MZui__CPosition.NEW */
Tc *YIG1a(Ysbp *t); /* MZui__CPosition.name */
Zs10 YvfVb = {"\010Position\000"};
Ysbp *YGxQ(Ysbp *t, Ti Av); /* MZui__CPosition.setLine */
Ti YuDY(Ysbp *t); /* MZui__CPosition.getLine */
Tb YNbi(Ysbp *t); /* MZui__CPosition.hasLine */
Ysbp *Y6ET(Ysbp *t, Ti Av); /* MZui__CPosition.setColumn */
Ti Y3kb(Ysbp *t); /* MZui__CPosition.getColumn */
Tb Yyok(Ysbp *t); /* MZui__CPosition.hasColumn */
Ysbp *YMCx(Ysbp *t, Tc *Av); /* MZui__CPosition.setFilename */
Tc *Y5Hu(Ysbp *t); /* MZui__CPosition.getFilename */
Tb Yeqm(Ysbp *t); /* MZui__CPosition.hasFilename */
Ti YdPfa(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.intGet */
Tc *YKXxa(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.stringGet */
Tb YGVxa(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.hasField */
Tl *Yc_da(Ysbp *t); /* MZui__CPosition.fieldSpecs */
Zs6 Y4eu = {"\004line\000"};
Zs8 YzjB = {"\006column\000"};
Zs10 YV7Z = {"\010filename\000"};
Tl *YEoX = NULL; /* MZui__CPosition__X.fieldSpecs */
Ti Ysbp__Y0zD(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.enumGet__p1 */
Ti Ysbp__Y0zDa(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.enumGet__p1 */
Tc *Ysbp__YytN(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.enumNameGet__p1 */
Tc *Ysbp__YytNa(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.enumNameGet__p1 */
Ti Ysbp__YGR8a(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.intGet__p1 */
Ti32 Ysbp__YAAo(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.int32Get__p1 */
Ti32 Ysbp__YAAoa(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.int32Get__p1 */
Tu Ysbp__YRqV(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.uint64Get__p1 */
Tu Ysbp__YRqVa(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.uint64Get__p1 */
Tu32 Ysbp__Y0tE(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.uint32Get__p1 */
Tu32 Ysbp__Y0tEa(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.uint32Get__p1 */
Tf32 Ysbp__Yyt7(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.floatGet__p1 */
Tf32 Ysbp__Yyt7a(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.floatGet__p1 */
Tf Ysbp__Yybv(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.doubleGet__p1 */
Tf Ysbp__Yybva(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.doubleGet__p1 */
Tb Ysbp__YGfz(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.boolGet__p1 */
Tb Ysbp__YGfza(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.boolGet__p1 */
Tc *Ysbp__YsRaa(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.stringGet__p1 */
Tr Ysbp__Yo5y(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.messageGet__p1 */
Tr Ysbp__Yo5ya(Ysbp *t, Ti AfieldNr, Ti Aidx); /* MZui__CPosition.messageGet__p1 */
Ti Ysbp__YUDN(Ysbp *t, Ti AfieldNr); /* MZui__CPosition.size__p1 */
Tc *Ysbp__YC5i(Ysbp *t); /* MZui__CPosition.ToString__p1 */
Tc *Ysbp__YFL0_I_imt[54];
To ToYsbp[10];
char *StrYsbp[];
int Jzui(int round);
/* zui done */
YkxB *YWLf(Yev8 *t); /* CToken.zcPos */
void YdIu(Yev8 *t, Tc *Amsg); /* CToken.error */
Tt CToken__EType__T = {23, 0, CToken__EType__name};
To ToYev8[6];
char *StrYev8[];
Zs7 YVrE = {"\005Token\000"};
int JToken(int round);
/* Token done */
/* including TokenInput declarations */
/* including Tokenizer declarations */
/* including ZuiFile declarations */
Ysbp *YK9d(YkxB *Apos); /* CZuiFile__X.createPosition */
void YA4C(YkxB *Apos, Ysbp *Azpos); /* CZuiFile__X.copyPosition */
To ToYgKE[1];
char *StrYgKE[];
Zs9 YRzA = {"\007ZuiFile\000"};
/* ZuiFile done */
Tb YIA3(Ti Ac); /* MTokenizer.isIdChar */
Zs5 Yez2 = {"\003..=\000"};
Zs5 YzUC = {"\003<<=\000"};
Zs5 YC5H = {"\003>>=\000"};
Zs5 YD5H = {"\003>>>\000"};
Zs5 YyUC = {"\003<<<\000"};
Zs4 Y2_ = {"\002!=\000"};
Zs4 Y40 = {"\002!~\000"};
Zs4 Yhja = {"\002-=\000"};
Zs4 YNfa = {"\002++\000"};
Zs4 Y4fa = {"\002+=\000"};
Zs4 Ytea = {"\002*=\000"};
Zs4 Yuma = {"\002/=\000"};
Zs4 Ys6 = {"\002%=\000"};
Zs4 Y8mc = {"\002~=\000"};
Zs4 Y37 = {"\002&=\000"};
Zs4 YWjc = {"\002|=\000"};
Zs4 YQyb = {"\002^=\000"};
Zs4 YWIa = {"\002==\000"};
Zs4 YXIa = {"\002=>\000"};
Zs4 YYJa = {"\002=~\000"};
Zs4 YjHa = {"\002<<\000"};
Zs4 YyKa = {"\002>>\000"};
Zs4 YkHa = {"\002<=\000"};
Zs4 YxKa = {"\002>=\000"};
Zs4 YH7 = {"\002&&\000"};
Zs4 YWkc = {"\002||\000"};
Zs4 YEka = {"\002..\000"};
Zs4 Y5La = {"\002?:\000"};
Zs4 YULa = {"\002?.\000"};
Zs3 YH = {"\001!\000"};
Zs3 YK = {"\001$\000"};
Zs3 YL = {"\001%\000"};
Zs3 YM = {"\001&\000"};
Zs3 YO = {"\001(\000"};
Zs3 YP = {"\001)\000"};
Zs3 YQ = {"\001*\000"};
Zs3 YR = {"\001+\000"};
Zs3 YS = {"\001,\000"};
Zs3 Y6 = {"\001;\000"};
Zs3 Y7 = {"\001<\000"};
Zs3 Y8 = {"\001=\000"};
Zs3 Y9 = {"\001>\000"};
Zs3 Yba = {"\001@\000"};
Zs4 Ygbb = {"\002O[\000"};
Zs3 YCa = {"\001[\000"};
Zs3 YFa = {"\001^\000"};
Zs3 Y7a = {"\001{\000"};
Zs3 Y8a = {"\001|\000"};
Zs3 Yab = {"\001~\000"};
Zs3 Yaa = {"\001?\000"};
Td Y3rf = {}; /* MTokenizer.nonKeywords */
Zs7 Yu2V = {"\005ALIAS\000"};
Zs5 YBjQ = {"\003ARG\000"};
Zs4 YHPa = {"\002AS\000"};
Zs6 YjG6 = {"\004BITS\000"};
Zs5 YZOS = {"\003BOX\000"};
Zs7 YZzE = {"\005BREAK\000"};
Zs10 YOgo = {"\010BUILD_IF\000"};
Zs14 YwZW = {"\014BUILD_ELSEIF\000"};
Zs12 YCSN = {"\012BUILD_ELSE\000"};
Zs7 Ydl6 = {"\005BYTES\000"};
Zs12 YxBe = {"\012BYTESTRING\000"};
Zs3 Yea = {"\001C\000"};
Zs6 Y6FU = {"\004CASE\000"};
Zs7 YCun = {"\005CATCH\000"};
Zs9 YPQP = {"\007CHEADER\000"};
Zs7 YK2B = {"\005CHECK\000"};
Zs7 YMwW = {"\005CLASS\000"};
Zs10 Yn3A = {"\010CONTINUE\000"};
Zs5 YeuV = {"\003CSS\000"};
Zs9 YUlG = {"\007DEFAULT\000"};
Zs7 Yqcs = {"\005DEFER\000"};
Zs4 YrUa = {"\002DO\000"};
Zs3 Yga = {"\001E\000"};
Zs6 Yc7A = {"\004ELSE\000"};
Zs8 Y9jU = {"\006ELSEIF\000"};
Zs6 YnjG = {"\004ENUM\000"};
Zs6 YsI4 = {"\004EXIT\000"};
Zs9 YDN8 = {"\007EXTENDS\000"};
Zs6 Y8ag = {"\004FAIL\000"};
Zs9 YdbB = {"\007FINALLY\000"};
Zs5 Yz51 = {"\003FOR\000"};
Zs6 YqI4 = {"\004FUNC\000"};
Zs4 Y3Ya = {"\002GC\000"};
Zs15 Yuso = {"\015GENERATE_ELSE\000"};
Zs17 Ycx0 = {"\017GENERATE_ELSEIF\000"};
Zs16 Yf3i = {"\016GENERATE_ERROR\000"};
Zs13 Y1Ce = {"\013GENERATE_IF\000"};
Zs5 Yup4 = {"\003GET\000"};
Zs6 Yith = {"\004HTTP\000"};
Zs6 Y0hh = {"\004HTML\000"};
Zs3 Yka = {"\001I\000"};
Zs4 Yj1a = {"\002IF\000"};
Zs7 Y4UI = {"\005IFNIL\000"};
Zs12 Y4lO = {"\012IMPLEMENTS\000"};
Zs8 YML6 = {"\006IMPORT\000"};
Zs4 Yr1a = {"\002IN\000"};
Zs9 Ygis = {"\007INCLUDE\000"};
Zs5 YxM9 = {"\003INF\000"};
Zs5 YLM9 = {"\003INT\000"};
Zs11 Y0as = {"\011INTERFACE\000"};
Zs4 Ys1aa = {"\002IO\000"};
Zs4 Yw1a = {"\002IS\000"};
Zs5 YtU9 = {"\003ISA\000"};
Zs7 YCHh = {"\005ISNOT\000"};
Zs8 Y5nR = {"\006ISNOTA\000"};
Zs8 YAcL = {"\006LAMBDA\000"};
Zs5 YVvha = {"\003LOG\000"};
Zs8 YKxe = {"\006MODULE\000"};
Zs5 Yqim = {"\003NAN\000"};
Zs5 YZom = {"\003NEW\000"};
Zs6 Yizy = {"\004NINF\000"};
Zs4 Y0ab = {"\002OK\000"};
Zs9 Y2gz = {"\007OPTIONS\000"};
Zs8 YV4t = {"\006PARENT\000"};
Zs7 YNqR = {"\005PIECE\000"};
Zs6 YsNN = {"\004PIPE\000"};
Zs6 Y6T9 = {"\004PROC\000"};
Zs9 Ysa6 = {"\007PROCEED\000"};
Zs7 YgRl = {"\005PROTO\000"};
Zs8 YGD1 = {"\006RETURN\000"};
Zs5 YZXw = {"\003RPC\000"};
Zs8 YuOB = {"\006SHARED\000"};
Zs8 YuyE = {"\006STATIC\000"};
Zs6 Y4xB = {"\004STEP\000"};
Zs8 Yaof = {"\006STRING\000"};
Zs8 Y0Y5 = {"\006SWITCH\000"};
Zs5 YALz = {"\003SYS\000"};
Zs3 Yva = {"\001T\000"};
Zs6 Ytoe = {"\004THIS\000"};
Zs8 YVLC = {"\006THREAD\000"};
Zs7 YTJV = {"\005THROW\000"};
Zs6 YA3g = {"\004TIME\000"};
Zs5 YNVB = {"\003TIO\000"};
Zs4 Y5ib = {"\002TO\000"};
Zs5 Yn9B = {"\003TRY\000"};
Zs6 Y7fW = {"\004TYPE\000"};
Zs7 YexT = {"\005UNTIL\000"};
Zs5 YAKE = {"\003USE\000"};
Zs5 YRRGa = {"\003VAR\000"};
Zs10 YD2V = {"\010VARBYTES\000"};
Zs15 Y_r2 = {"\015VARBYTESTRING\000"};
Zs11 YRA8 = {"\011VARSTRING\000"};
Zs7 YHo2 = {"\005WHILE\000"};
Zs3 YBa = {"\001Z\000"};
Zs5 YDER = {"\003ZUT\000"};
Zs5 YQHR = {"\003ZWT\000"};
Td Y0sf = {}; /* MTokenizer.keywords */
YjUM Yc6N = {}; /* MTokenizer.tokenWriter */
Yev8 *Yx5t(Y7Sj *Ain); /* MTokenizer.get */
Zs22 YD4M = {"\024missing double quote\000"};
Zs27 YjHV = {"\031missing end of ''\" string\000"};
Zs40 YXk7 = {"\046Missing character betwee single quotes\000"};
Zs22 YYrm = {"\024missing single quote\000"};
Zs27 YtNZ = {"\031Unrecognized character: '\000"};
Zs3 YN = {"\001'\000"};
Zs25 Yl7Q = {"\027Unrecognized keyword: '\000"};
Zs34 Y_B2 = {"\040'__' is illegal in identifier: '\000"};
void YxBx(Ti Ac, Y7Sj *Ain, YjUM *Awriter); /* MTokenizer.controlChar */
Zs25 YVwa = {"\027Illegal octal character\000"};
Zs27 Y3ak = {"\031Illegal character after \\\000"};
Ti YHDu(Ti AcharCount, Y7Sj *Ain); /* MTokenizer.getHex */
Zs23 YnRg = {"\025Illegal hex character\000"};
void YfFo(Y7Sj *Ain, YjUM *Awriter); /* MTokenizer.getRawString */
YjUM Yl_6 = {}; /* MTokenizer.whiteWriter */
void YZTP(Y7Sj *Ain, Yev8 *Ares); /* MTokenizer.handleWhite */
Zs12 YWPM = {"\012missing */\000"};
To ToYsZx[5];
char *StrYsZx[];
Zs6 Y2N6 = {"\004Node\000"};
YsZx YXGF = {}; /* MTokenizer.root */
void Yfh4(Tc *Aname, Te Atype, Tb AisKeyword); /* MTokenizer.addNode */
Zs19 Yqcm = {"\021Duplicate token: \000"};
int YTyo__r = 0; /* MTokenizer.Ready */
Ts YTyo(); /* MTokenizer.Init */
Ts Ybdf(Y7Sj *Ain, Yev8 *Ares); /* MTokenizer.getNew */
Ts YY69(Y7Sj *Ain, YsZx *An, Yev8 *Ares); /* MTokenizer.deeper */
int JTokenizer(int round);
/* Tokenizer done */
Y7Sj *YUwt(Y7Sj *t, YeYq *Ainput); /* CTokenInput.NEW */
Ti YGBv(Y7Sj *t); /* CTokenInput.get */
void YPmF(Y7Sj *t, Ti Ac); /* CTokenInput.push */
Ti YHT_(Y7Sj *t); /* CTokenInput.peek */
Yev8 *Y_PN(Y7Sj *t); /* CTokenInput.getToken */
void YGzQ(Y7Sj *t); /* CTokenInput.emptyStack */
void Y5yp(Y7Sj *t, Tc *Amsg); /* CTokenInput.error */
To ToY7Sj[4];
char *StrY7Sj[];
Zs12 YnOq = {"\012TokenInput\000"};
int JTokenInput(int round);
/* TokenInput done */
Zs9 YZVC = {"\007Usage: \000"};
Zs24 Y3OJ = {"\026 infile.zut outfile.zu\000"};
Zs6 YaJI = {"\004.zut\000"};
Zs40 Y8iJ = {"\046ERROR: Input name must end in '.zut': \000"};
Zs5 YYv4 = {"\003.zu\000"};
Zs40 YIhh = {"\046ERROR: output name must end in '.zu': \000"};
Zs20 Yz0u = {"\022failed to process \000"};
To ToYihi[3];
char *StrYihi[];
Zs8 YeYv = {"\006Import\000"};
void YSxp(Y7Sj *Ain, Tr AoutFile); /* processFile */
Zs32 YER6 = {"\036# GENERATED FILE - DO NOT EDIT\000"};
Zs19 Y8qH = {"\021# generated from \000"};
Zs29 YRPM = {"\033Missing } to end the MODULE\000"};
Zs25 YqdO = {"\027Already inside a MODULE\000"};
Zs15 YE6i = {"\015Unexpected ID\000"};
Zs14 Yn76 = {"\014Unexpected @\000"};
Zs13 YFO4 = {"\013Unmatched }\000"};
Zs37 Y5Hp = {"\043CSS must come before the first HTML\000"};
Zs29 Ydne = {"\033can only have one CSS block\000"};
Zs22 YtoA = {"\024Unrecognized token: \000"};
Zs13 Yp_H = {"\013IMPORT \"../\000"};
Zs14 Y0ZC = {"\014 @javascript\000"};
void YVPe(Y7Sj *Ain, Td *Aimports); /* processImport */
void YG05(Yev8 *AhtmlToken, Y7Sj *Ain, Tb AhasCss, Td *Aimports, Tr Aout); /* processHtml */
Zs24 YF0E = {"\026Unexpected end of file\000"};
Zs23 YoYi = {"\025ZUT.Context context, \000"};
Zs9 YGNi = {"\007 string\000"};
Zs17 Y1dka = {"\017addCss(context)\000"};
Zs6 YW_j = {"\004    \000"};
Zs27 YUdu = {"\031IO.StringWriter w = NEW()\000"};
Zs25 YwZD = {"\027    RETURN w.ToString()\000"};
Zs5 YVet = {"\003  }\000"};
void Y467(Yev8 *AhtmlToken, Y7Sj *Ain, Tr Aout); /* processCss */
Zs34 Yj20 = {"\040PROC addCss(ZUT.Context context)\000"};
Zs25 YXdf = {"\027    IF context.hasCss(\"\000"};
Zs4 Yk1 = {"\002\")\000"};
Zs14 YmE4 = {"\014      RETURN\000"};
Zs7 Y6my = {"\005    }\000"};
Zs31 Y12v = {"\035    IO.StringWriter w = NEW()\000"};
Zs22 YwSQ = {"\024    context.addCss(\"\000"};
Zs18 Y4a0 = {"\020\", w.ToString())\000"};
Tc *Yakc(Y7Sj *Ain); /* getRecorded */
void YVTG(Y7Sj *Ain, Tr Aout, Td *Aimports, Yhqr *AactionsDone, Yhqr *AeventsDone); /* writeRecorded */
Zs16 YYRg = {"\016 zcontroller=\"\000"};
Zs12 Y4QS = {"\012 zaction=\"\000"};
Zs35 YHvt = {"\041    context.listen(ZUT.EventType.\000"};
Zs26 YDH6 = {"\030    ZUT.registerAction(\"\000"};
Zs6 YZ02 = {"\004\", \"\000"};
Zs27 Y7hl = {"\031Controller not imported: \000"};
Zs17 YBY8 = {"\017    w.write(''\"\000"};
Zs6 YIlR = {"\004\"'')\000"};
void YrDo(Y7Sj *Ain, Tr Aout); /* processStatement */
Zs14 YV20 = {"\014    w.write(\000"};
Zs3 YJ = {"\001#\000"};
Zs19 Y7yI = {"\021    w.write(\"# \")\000"};

Tt bool__T  = {21, 0, 0};
Tt byte__T  = {11, 0, 0};
Tt byteString__T = {201, 0, 0};
Tt float128__T  = {83, 0, 0};
Tt float32__T  = {81, 0, 0};
Tt float80__T  = {82, 0, 0};
Tt float__T  = {80, 0, 0};
Tt int16__T  = {2, 0, 0};
Tt int32__T  = {3, 0, 0};
Tt int8__T  = {1, 0, 0};
Tt int__T  = {0, 0, 0};
Tt nat16__T  = {12, 0, 0};
Tt nat32__T  = {13, 0, 0};
Tt nat__T  = {10, 0, 0};
Tt status__T  = {22, 0, 0};
Tt string__T = {200, 0, 0};
Tt type__T  = {101, 0, 0};
Tt array__T = {300, 0, 0};
Tt list__T = {301, 0, 0};
Tt dict__T = {302, 0, 0};
Tt iobj__T = {391, 0, 0};
int ZglobInit(int round);

typedef struct Zfo__S {
 int off;
 Tt  *type;
} Zfo;
typedef struct Zsf__S {
 volatile int pos;
 struct Zsf__S *prev;
 Zfo *frof;
} Zsf;
#define POS_MASK 0x3fffffff
typedef struct Senv__S {
 int tosNr;
} Tn; /* per-thread environemnt */

Zsf *topFrame = NULL;
int inZa = 0;
int ZaEntered = 0;

Tn Zenv = {0};

void beforeExit() {
}


Tc *Zstr(char *s) {
 return ZnewString((Tc*)s, strlen(s));
}

/* allocate memory */
void *Za(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (Za)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

/* allocate memory with offset */
#define ZaOff(size) (Za((size) + ZOH_OFF) + ZOH_OFF)
#define ZranOff(ptr, osize, nsize) (Zran((ptr) ? (void*)(ptr) - ZOH_OFF : NULL, (osize) + ZOH_OFF, (nsize) + ZOH_OFF) + ZOH_OFF)

/* allocate memory */
void *ZaNm(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNm)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

void *ZaNmi(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNmi)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

/* reallocate memory */
void *Zran(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 if (!inZa && !ZaEntered) {
  inZa = 1;
  p = realloc(op, nsize);
  inZa = 0;
  if (p == NULL) {
    ++ZaEntered;
    ZthrowOutOfMemory(nsize);
  }
  ZaEntered = 0;
  if (nsize > osize) memset(p + osize, 0, nsize - osize);
  return p;
 }
 p = Za(nsize);
 if (op)
  memmove(p + ZOH_OFF, op + ZOH_OFF, nsize > osize ? osize - ZOH_OFF : nsize - ZOH_OFF);
 if (nsize > osize) memset(p + osize, 0, nsize - osize);
 return p;
}

void *ZranNm(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 if (!inZa && !ZaEntered) {
  inZa = 1;
  p = realloc(op, nsize);
  inZa = 0;
  if (p == NULL) {
   ++ZaEntered;
   ZthrowOutOfMemory(nsize);
  }
  if (nsize > osize) memset(p + osize, 0, nsize - osize);
  return p;
 }
 p = ZaNm(nsize);
 if (op) memmove(p, op, nsize > osize ? osize : nsize);
 if (nsize > osize) memset(p + osize, 0, nsize - osize);
 return p;
}

void Zfree(void *p) {
 if (p) free(p);
}

Tc *ZnewStringInit(Ti len, Tc **pp) {
 Ti rlen = len;
 int i;
 int n = ZOH_OFF;
 Tc buf[20];
 Tc *res;
 buf[0] = (rlen & 127);
 rlen >>= 7;
 for (i = 1; rlen > 0; ++i)
 {
  buf[i] = (rlen & 127) + 128;
  rlen >>= 7;
 }
 res = Za(ZOH_OFF + len + i + 1);
 while (i > 0) res[n++] = buf[--i];
 *pp = res + n;
 return res;
}

Tc *ZnewString(Tc *p, Ti len) {
 Tc *pp;
 Tc *res = ZnewStringInit(len, &pp);
 memmove(pp, p, len);
 return res;
}
Tc Ydmy[]="Input.zu";
Tc YdPO[]="Token.zu";
Tc Y57c[]="TokenInput.zu";
Tc YqXi[]="Tokenizer.zu";
Tc Yg6g[]="ZUDIR/zui.zu";
Tc Y0CK[]="ZuiFile.zu";
Tc YCG4[]="lib/ARGModule.zu";
Tc Yt1T[]="lib/EModule.zu";
Tc YBRz[]="lib/INTModule.zu";
Tc Yay0[]="lib/IOModule.zu";
Tc Y76z[]="lib/LOGModule.zu";
Tc YxHL[]="lib/SETModule.zu";
Tc Yv00[]="lib/STRINGModule.zu";
Tc YyXk[]="lib/TIMEModule.zu";
Tc Y3zM[]="lib/ZModule.zu";
Tc Y_hM[]="plugin/proto/Message.zu";
Tc YxTh[]="plugin/proto/Proto.zu";
Tc YSHD[]="plugin/zut/pluginzut.zu";
Tc Y_VO[]="ARG.Bool.NEW/1()";
Tcpos ZcTbl3273[]={
{791,5},
{2,7},
{3,16},
{4,16},
{5,18},
};
Tc YImf[]="ARG.Bool.NEW__p1/1()";
Tcpos ZcTbl76644[]={
{637,5},
{1,7},
{2,9},
{4,7},
{6,9},
{8,7},
{9,20},
{11,7},
{12,19},
{14,12},
{18,7},
{19,20},
{20,19},
{23,7},
{24,9},
{25,11},
{27,9},
{29,7},
{30,9},
{31,11},
{33,9},
{34,11},
{36,9},
{38,12},
};
Tc YM2k[]="ARG.Bool.setToDefault/1()";
Tcpos ZcTbl38911[]={
{800,11},
{1,16},
};
Tc YgDO[]="ARG.Bool.throwDuplicate__p1/1()";
Tcpos ZcTbl75697[]={
{679,11},
{1,44},
{2,18},
{4,7},
};
Tc Y2cg[]="ARG.Bool.value()";
Tcpos ZcTbl61284[]={
{830,11},
{1,15},
};
Tc YPPv[]="ARG.Init()";
Tcpos ZcTbl66501[]={
{78,29},
};
Tc Ygzb[]="ARG.Int.setToDefault/1()";
Tcpos ZcTbl16350[]={
{865,11},
{1,16},
};
Tc YZNA[]="ARG.String.setToDefault/1()";
Tcpos ZcTbl86206[]={
{953,11},
{1,16},
};
Tc YRbs[]="ARG.StringList.setToDefault/1()";
Tcpos ZcTbl64478[]={
{1046,11},
{1,16},
};
Tc YEFE[]="ARG.Usage.get()";
Tcpos ZcTbl43000[]={
{600,11},
{1,23},
{2,7},
{3,17},
{5,49},
};
Tc YzK9[]="ARG.displayHelp()";
Tcpos ZcTbl29560[]={
{461,5},
{1,7},
{3,5},
{6,35},
{7,5},
{8,19},
{9,7},
{10,33},
{7,5},
{17,5},
{18,7},
{19,9},
{20,9},
{23,7},
{24,21},
{26,26},
{28,9},
{29,11},
{30,21},
{32,21},
{34,15},
{35,21},
{36,11},
{37,21},
{39,21},
{41,15},
{42,21},
{43,11},
{44,21},
{46,21},
{48,15},
{50,9},
{51,11},
{52,21},
{54,21},
{58,23},
{59,9},
{60,16},
{62,9},
{63,11},
{65,13},
{66,15},
{67,22},
{69,15},
{71,18},
{73,16},
{76,9},
{77,16},
{80,9},
{81,11},
{82,13},
{83,13},
{85,13},
{87,11},
{88,13},
{89,13},
{92,11},
{93,24},
{95,11},
{96,24},
{23,7},
{17,5},
{103,10},
};
Tc Yza4[]="ARG.error()";
Tcpos ZcTbl85295[]={
{449,5},
{1,5},
{2,7},
{4,5},
{5,7},
{7,10},
};
Tc Yh2v[]="ARG.init()";
Tcpos ZcTbl82533[]={
{259,5},
{1,7},
{3,20},
{4,19},
{6,7},
{7,9},
{9,7},
{10,9},
{9,7},
{12,7},
{13,9},
{12,7},
{16,17},
{17,22},
{19,7},
{20,9},
{22,16},
{26,22},
{27,9},
{28,11},
{29,11},
{30,21},
{33,11},
{34,21},
{39,13},
{40,37},
{41,15},
{44,17},
{48,34},
{49,15},
{50,23},
{51,26},
{54,20},
{57,15},
{58,22},
{59,17},
{60,19},
{62,30},
{63,27},
{66,26},
{72,37},
{75,34},
{76,15},
{77,23},
{78,26},
{80,17},
{82,24},
{83,19},
{86,21},
{88,23},
{89,36},
{89,36},
{90,37},
{91,32},
{92,28},
{93,33},
{96,47},
{98,29},
{99,32},
{80,17},
{105,15},
{106,17},
{107,27},
{108,22},
{111,13},
{112,15},
{113,17},
{116,15},
{117,17},
{119,15},
{120,15},
{121,30},
{121,30},
{122,17},
{123,19},
{124,35},
{125,40},
{126,35},
{128,21},
{131,33},
{133,27},
{134,17},
{135,19},
{137,36},
{137,36},
{138,31},
{139,17},
{140,19},
{139,17},
{144,17},
{146,24},
{147,19},
{148,21},
{150,25},
{152,17},
{153,31},
{153,31},
{154,19},
{156,35},
{157,21},
};
Tcpos ZcTbl82534[]={
{422,40},
{1,35},
{2,21},
{4,29},
{5,34},
{5,34},
{6,19},
{8,35},
{9,21},
{11,35},
{12,21},
{15,19},
{-144,7},
};
Tc YMnk[]="ARG.writeLead()";
Tcpos ZcTbl81798[]={
{569,5},
{2,5},
{3,7},
{2,5},
};
Tc Y5LR[]="E.BadValue.NEW__p2/2()";
Tcpos ZcTbl60593[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y0hW[]="E.BadValue.ToString__p2/2()";
Tcpos ZcTbl52701[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y9VX[]="E.BadValue.writeTo__p2/4()";
Tcpos ZcTbl46171[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y4u_[]="E.BadValue.writeTo__p2/5()";
Tcpos ZcTbl56372[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y_Qs[]="E.DivideByZero.NEW__p3/3()";
Tcpos ZcTbl73471[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yk5m[]="E.DivideByZero.ToString__p3/3()";
Tcpos ZcTbl17179[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YG80[]="E.DivideByZero.writeTo__p3/6()";
Tcpos ZcTbl44130[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YLzZ[]="E.DivideByZero.writeTo__p3/7()";
Tcpos ZcTbl54331[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YPz2[]="E.E_BinaryError.NEW__p2/2()";
Tcpos ZcTbl46312[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y5qz[]="E.E_BinaryError.ToString__p2/2()";
Tcpos ZcTbl32160[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Yu0r[]="E.E_BinaryError.writeTo__p2/4()";
Tcpos ZcTbl70530[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Yzrp[]="E.E_BinaryError.writeTo__p2/5()";
Tcpos ZcTbl80731[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YWEC[]="E.E_ProduceError.NEW__p2/2()";
Tcpos ZcTbl70833[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YfLf[]="E.E_ProduceError.ToString__p2/2()";
Tcpos ZcTbl68797[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Yuzo[]="E.E_ProduceError.writeTo__p2/4()";
Tcpos ZcTbl63483[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Yz_l[]="E.E_ProduceError.writeTo__p2/5()";
Tcpos ZcTbl73684[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y2Qj[]="E.Exception.ToString()";
Tcpos ZcTbl51535[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YgcH[]="E.Exception.writeTo()";
Tcpos ZcTbl49183[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YYT9[]="E.Exception.writeTo/1()";
Tcpos ZcTbl36491[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y0TG[]="E.Exit.ToString/1()";
Tcpos ZcTbl18934[]={
{182,11},
{1,27},
{2,7},
{3,16},
};
Tc YTjU[]="E.Exit.writeTo/2()";
Tcpos ZcTbl92163[]={
{191,11},
{1,7},
{2,9},
{3,9},
{5,7},
{6,7},
{7,7},
{8,9},
{9,9},
};
Tc Y9aV[]="E.Exit.writeTo__p1/3()";
Tcpos ZcTbl42983[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y9Cv[]="E.IOError.NEW__p2/2()";
Tcpos ZcTbl48299[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YVJp[]="E.IOError.ToString__p2/2()";
Tcpos ZcTbl79935[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y59h[]="E.IOError.writeTo__p2/4()";
Tcpos ZcTbl89685[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y0Jk[]="E.IOError.writeTo__p2/5()";
Tcpos ZcTbl99886[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y2NH[]="E.IllegalByte.NEW__p3/3()";
Tcpos ZcTbl45209[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y_Bo[]="E.IllegalByte.ToString__p3/3()";
Tcpos ZcTbl10045[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YALK[]="E.IllegalByte.writeTo__p3/6()";
Tcpos ZcTbl9948[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YFbI[]="E.IllegalByte.writeTo__p3/7()";
Tcpos ZcTbl20149[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Yp81[]="E.Init.NEW__p2/2()";
Tcpos ZcTbl53377[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yuz_[]="E.Init.NEW__p2/3()";
Tcpos ZcTbl63578[]={
{69,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YAwk[]="E.Init.ToString__p2/2()";
Tcpos ZcTbl89581[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YMF2[]="E.Init.writeTo__p2/4()";
Tcpos ZcTbl96107[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YR5_[]="E.Init.writeTo__p2/5()";
Tcpos ZcTbl6308[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YbzA[]="E.Internal.NEW__p2/2()";
Tcpos ZcTbl78082[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y8mE[]="E.Internal.ToString__p2/2()";
Tcpos ZcTbl27618[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YxLq[]="E.Internal.writeTo__p2/4()";
Tcpos ZcTbl412[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YCbo[]="E.Internal.writeTo__p2/5()";
Tcpos ZcTbl10613[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Ycb9[]="E.KeyExists.NEW__p3/3()";
Tcpos ZcTbl85000[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yoiq[]="E.KeyExists.ToString__p3/3()";
Tcpos ZcTbl52728[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y4SL[]="E.KeyExists.writeTo__p3/6()";
Tcpos ZcTbl14715[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y9iJ[]="E.KeyExists.writeTo__p3/7()";
Tcpos ZcTbl24916[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YAVe[]="E.KeyNotFound.NEW__p3/3()";
Tcpos ZcTbl29585[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YMB8[]="E.KeyNotFound.ToString__p3/3()";
Tcpos ZcTbl15669[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Ygil[]="E.KeyNotFound.writeTo__p3/6()";
Tcpos ZcTbl43124[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YlJi[]="E.KeyNotFound.writeTo__p3/7()";
Tcpos ZcTbl53325[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YF6S[]="E.MemoryAccess.NEW__p2/2()";
Tcpos ZcTbl73580[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YQJA[]="E.MemoryAccess.ToString__p2/2()";
Tcpos ZcTbl66036[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y4vu[]="E.MemoryAccess.writeTo__p2/4()";
Tcpos ZcTbl25958[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y_4w[]="E.MemoryAccess.writeTo__p2/5()";
Tcpos ZcTbl36159[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y1As[]="E.NilAccess.NEW__p2/2()";
Tcpos ZcTbl32086[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YN54b[]="E.NilAccess.ToString__p2/2()";
Tcpos ZcTbl26854[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YcIS[]="E.NilAccess.writeTo__p2/4()";
Tcpos ZcTbl35088[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y7gV[]="E.NilAccess.writeTo__p2/5()";
Tcpos ZcTbl45289[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YobA[]="E.OutOfMemory.NEW/3()";
Tcpos ZcTbl80644[]={
{262,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Ym8y[]="E.OutOfMemory.ToString__p2/2()";
Tcpos ZcTbl86699[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YoZS[]="E.OutOfMemory.writeTo__p2/4()";
Tcpos ZcTbl11217[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YtpQ[]="E.OutOfMemory.writeTo__p2/5()";
Tcpos ZcTbl21418[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y99g[]="E.OutOfRange.NEW__p3/3()";
Tcpos ZcTbl56381[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y0DD[]="E.OutOfRange.ToString__p3/3()";
Tcpos ZcTbl31729[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YqK0[]="E.OutOfRange.writeTo__p3/6()";
Tcpos ZcTbl52608[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Ylj3[]="E.OutOfRange.writeTo__p3/7()";
Tcpos ZcTbl62809[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YR5m[]="E.WrongType.NEW/1()";
Tcpos ZcTbl87235[]={
{514,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y0Td[]="E.WrongType.ToString__p2/2()";
Tcpos ZcTbl12896[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YlgI[]="E.WrongType.writeTo__p2/4()";
Tcpos ZcTbl86818[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YgQK[]="E.WrongType.writeTo__p2/5()";
Tcpos ZcTbl97019[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YEFs[]="E.unhandledException()";
Tcpos ZcTbl15718[]={
{609,23},
{0,23},
{0,23},
};
Tc YgcM[]="E.writeToStderr()";
Tcpos ZcTbl52386[]={
{629,5},
{1,5},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{2,5},
};
Tc YPV8[]="INT.isWhite()";
Tcpos ZcTbl36267[]={
{184,24},
};
Tc Ys1a[]="IO";
Tcpos ZcTbl7452[]={
{26,8},
{3,8},
{6,8},
};
Tc YskO[]="IO.File.flush()";
Tcpos ZcTbl60567[]={
{564,11},
{1,20},
{2,7},
{4,4},
{12,14},
};
Tc Yxlj[]="IO.File.print__p1/15()";
Tcpos ZcTbl82618[]={
{230,11},
{1,15},
};
Tc YJ7z[]="IO.File.print__p1/8()";
Tcpos ZcTbl66188[]={
{184,11},
{1,7},
{2,16},
{4,14},
};
Tc Y5P_[]="IO.File.readByte()";
Tcpos ZcTbl16053[]={
{253,11},
{1,7},
{2,9},
{6,4},
{17,14},
};
Tc YHCY[]="IO.File.readChar()";
Tcpos ZcTbl46631[]={
{275,11},
{1,16},
{2,7},
{4,9},
{5,15},
{6,13},
{7,27},
{8,15},
{9,13},
{10,27},
{11,15},
{12,13},
{14,11},
{16,9},
{17,21},
{18,11},
{19,13},
{20,30},
{21,13},
{23,13},
{16,9},
{25,9},
{27,15},
{28,17},
{31,15},
{32,17},
{35,15},
{36,17},
{40,14},
};
Tc Yj_J[]="IO.File.write/8()";
Tcpos ZcTbl94823[]={
{483,11},
{3,9},
{4,11},
{6,4},
{31,14},
};
Tc YwPx[]="IO.File.writeChar__p1/1()";
Tcpos ZcTbl88105[]={
{175,11},
{1,7},
{2,9},
{4,15},
};
Tc YGQL[]="IO.File.write__p1/9()";
Tcpos ZcTbl59819[]={
{129,11},
{1,15},
};
Tc YrJP[]="IO.StringWriter.ToString()";
Tcpos ZcTbl64531[]={
{1431,11},
{3,9},
{4,13},
{6,4},
{17,14},
};
Tc YB7r[]="IO.StringWriter.clear()";
Tcpos ZcTbl46072[]={
{1494,11},
{1,13},
{3,12},
};
Tc YYk7[]="IO.StringWriter.print__p1/8()";
Tcpos ZcTbl26760[]={
{184,11},
{1,7},
{2,16},
{4,14},
};
Tc YSa1[]="IO.StringWriter.remove()";
Tcpos ZcTbl58975[]={
{1453,11},
{1,7},
{2,16},
{6,11},
{7,19},
{8,9},
{9,21},
{10,21},
{11,11},
{12,23},
{13,23},
{14,13},
{16,25},
{17,25},
{18,17},
{22,17},
{26,15},
{36,14},
};
Tc Yijq[]="IO.StringWriter.truncate()";
Tcpos ZcTbl83443[]={
{1507,11},
{1,13},
};
Tc YCbR[]="IO.StringWriter.write/8()";
Tcpos ZcTbl89987[]={
{1359,11},
{1,37},
{3,9},
{4,14},
{5,11},
{6,17},
{8,11},
{10,13},
{12,11},
{13,17},
{24,14},
};
Tc Y35R[]="IO.StringWriter.writeByte/1()";
Tcpos ZcTbl38552[]={
{1388,11},
{2,9},
{3,14},
{4,26},
{6,11},
{8,21},
{9,19},
{19,14},
};
Tc Y1Ue[]="IO.StringWriter.writeChar__p1/1()";
Tcpos ZcTbl49285[]={
{175,11},
{1,7},
{2,9},
{4,15},
};
Tc YzQB[]="IO.StringWriter.write__p1/9()";
Tcpos ZcTbl72007[]={
{129,11},
{1,15},
};
Tc YTE3[]="IO.fileReader()";
Tcpos ZcTbl99838[]={
{926,4},
{5,9},
{6,4},
{16,12},
};
Tc Y5X7[]="IO.fileWriter()";
Tcpos ZcTbl81580[]={
{956,4},
{8,9},
{9,4},
{19,12},
};
Tc YN2v[]="IO.flush()";
Tcpos ZcTbl46761[]={
{1337,4},
{9,12},
};
Tc YNFk[]="IO.print()";
Tcpos ZcTbl1872[]={
{1227,37},
{1,4},
{13,12},
};
Tc Y_7a[]="IO.tail()";
Tcpos ZcTbl75905[]={
{2415,18},
};
Tc YU58[]="IO.tailIndex()";
Tcpos ZcTbl62213[]={
{2391,19},
{1,4},
{4,19},
{5,5},
{6,9},
{8,4},
{11,5},
{12,14},
{14,14},
};
Tc Y_pS[]="IO.write()";
Tcpos ZcTbl84870[]={
{1168,4},
{13,12},
};
Tc YOoa[]="Input.NEW()";
Tcpos ZcTbl44401[]={
{32,3},
{1,9},
{2,10},
{3,16},
{4,13},
{5,5},
{6,21},
};
Tc YHM2[]="Input.get()";
Tcpos ZcTbl19887[]={
{56,9},
{2,5},
{3,9},
{4,15},
{5,16},
{6,7},
{7,11},
{9,11},
{10,9},
{11,17},
{14,7},
{15,11},
{16,17},
{18,9},
{19,11},
{20,13},
{21,15},
{22,20},
{23,13},
{24,15},
{26,15},
{27,28},
{28,13},
{29,15},
{32,7},
{14,7},
{35,5},
{36,20},
{37,7},
{40,5},
{41,7},
{44,12},
};
Tc Y04k[]="Input.getRecord()";
Tcpos ZcTbl86594[]={
{120,9},
{1,30},
{2,5},
{3,12},
};
Tc Yq05[]="Input.push()";
Tcpos ZcTbl34047[]={
{104,9},
{1,5},
{2,7},
{3,7},
{4,18},
{5,18},
{7,17},
{9,7},
{10,9},
};
Tc YVvh[]="LOG";
Tcpos ZcTbl83326[]={
{21,14},
{2,14},
{50,20},
};
Tc YFIR[]="LOG.flush()";
Tcpos ZcTbl56555[]={
{226,5},
{1,5},
{2,7},
{4,15},
};
Tc Y8w5[]="LOG.reportStack()";
Tcpos ZcTbl84899[]={
{213,7},
{1,7},
{2,18},
{2,7},
{2,18},
{3,9},
{2,7},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{30,3},
{1,5},
{2,10},
{6,27},
{7,3},
{8,5},
{9,10},
{11,28},
{12,3},
{13,5},
{14,10},
{23,23},
{24,17},
{25,19},
{27,24},
{29,3},
{31,3},
{34,5},
{35,12},
{38,10},
};
Tc YrRv[]="Position.ToString__p1/1()";
Tcpos ZcTbl21197[]={
{159,9},
{1,30},
{2,32},
{3,5},
{4,19},
};
Tc YGr5[]="Position.boolGet__p1/2()";
Tcpos ZcTbl51288[]={
{95,9},
{1,12},
};
Tc YLS2[]="Position.boolGet__p1/3()";
Tcpos ZcTbl61489[]={
{98,9},
{1,12},
};
Tc YQdE[]="Position.doubleGet__p1/2()";
Tcpos ZcTbl86691[]={
{89,9},
{1,12},
};
Tc YLNG[]="Position.doubleGet__p1/3()";
Tcpos ZcTbl96892[]={
{92,9},
{1,12},
};
Tc YeMF[]="Position.enumGet__p1/2()";
Tcpos ZcTbl7937[]={
{45,9},
{1,12},
};
Tc Y9kI[]="Position.enumGet__p1/3()";
Tcpos ZcTbl18138[]={
{48,9},
{1,12},
};
Tc YDXq[]="Position.enumNameGet__p1/2()";
Tcpos ZcTbl79042[]={
{51,9},
{1,12},
};
Tc YIno[]="Position.enumNameGet__p1/3()";
Tcpos ZcTbl89243[]={
{54,9},
{1,12},
};
Tc Yezt[]="Position.floatGet__p1/2()";
Tcpos ZcTbl11238[]={
{82,9},
{1,12},
};
Tc Y97v[]="Position.floatGet__p1/3()";
Tcpos ZcTbl21439[]={
{85,9},
{1,12},
};
Tc YiuT[]="Position.int32Get__p1/2()";
Tcpos ZcTbl34848[]={
{63,9},
{1,12},
};
Tc Yd3V[]="Position.int32Get__p1/3()";
Tcpos ZcTbl45049[]={
{66,9},
{1,12},
};
Tc YpOc[]="Position.intGet__p1/3()";
Tcpos ZcTbl56060[]={
{60,9},
{1,12},
};
Tc YLxt[]="Position.messageGet__p1/2()";
Tcpos ZcTbl49865[]={
{131,9},
{1,12},
};
Tc YG6v[]="Position.messageGet__p1/3()";
Tcpos ZcTbl60066[]={
{134,9},
{1,12},
};
Tc YFRK[]="Position.size__p1/1()";
Tcpos ZcTbl44294[]={
{150,9},
{1,12},
};
Tc YnkC[]="Position.stringGet__p1/3()";
Tcpos ZcTbl68128[]={
{104,9},
{1,12},
};
Tc YJoo[]="Position.uint32Get__p1/2()";
Tcpos ZcTbl18609[]={
{75,9},
{1,12},
};
Tc YEYq[]="Position.uint32Get__p1/3()";
Tcpos ZcTbl28810[]={
{78,9},
{1,12},
};
Tc YVp4[]="Position.uint64Get__p1/2()";
Tcpos ZcTbl58974[]={
{69,9},
{1,12},
};
Tc Y_Q1[]="Position.uint64Get__p1/3()";
Tcpos ZcTbl69175[]={
{72,9},
{1,12},
};
Tc Y1Hw[]="Proto";
Tcpos ZcTbl30532[]={
{286,26},
{15,25},
};
Tc YlSz[]="Proto.FieldSpec.NEW()";
Tcpos ZcTbl13666[]={
{105,5},
{1,13},
{2,11},
{3,13},
{4,17},
};
Tc YnDn[]="Proto.Writer.NEW/2()";
Tcpos ZcTbl12469[]={
{156,5},
{1,15},
{2,15},
{3,14},
{5,7},
};
Tc YlQ3[]="Proto.Writer.initDeref()";
Tcpos ZcTbl32956[]={
{164,11},
{1,18},
{2,22},
};
Tc YGqq[]="Proto.binaryMessageSize()";
Tcpos ZcTbl37884[]={
{803,5},
{1,12},
{2,12},
{5,7},
{6,19},
{7,9},
{8,14},
{9,34},
{10,14},
{12,9},
{14,32},
{15,16},
{16,16},
{17,16},
{19,29},
{20,27},
{23,7},
{24,14},
{25,19},
{26,14},
{27,14},
{30,12},
};
Tc YI64[]="Proto.binarySize()";
Tcpos ZcTbl90679[]={
{681,5},
{1,7},
{2,25},
{3,9},
{4,11},
{7,20},
{8,20},
{11,20},
{12,20},
{15,20},
{16,27},
{17,20},
{20,20},
{21,27},
{22,20},
{25,20},
{26,20},
{29,20},
{30,20},
{33,20},
{34,20},
{37,20},
{38,34},
{39,27},
{40,20},
{43,28},
{44,20},
{45,20},
{48,35},
{49,20},
{52,15},
{3,9},
{57,9},
{58,11},
{61,20},
{62,20},
{65,20},
{66,20},
{69,20},
{70,27},
{71,20},
{74,20},
{75,27},
{76,20},
{79,20},
{80,20},
{83,20},
{84,20},
{87,20},
{88,20},
{91,20},
{92,34},
{93,27},
{94,20},
{97,28},
{98,20},
{99,20},
{102,35},
{103,20},
{106,15},
{0,5},
{112,12},
};
Tc Y6Nc[]="Proto.getBinaryTagSize()";
Tcpos ZcTbl49599[]={
{326,35},
{1,12},
};
Tc YAt_[]="Proto.getVarIntSize()";
Tcpos ZcTbl36994[]={
{1751,5},
{2,14},
{4,5},
{5,14},
{7,5},
{8,14},
{10,17},
{11,5},
{12,7},
{11,5},
{17,12},
};
Tc YufP[]="Proto.writeMessageText()";
Tcpos ZcTbl64912[]={
{982,21},
{1,5},
{2,7},
};
Tc YleD[]="Proto.writeMessageText/1()";
Tcpos ZcTbl71988[]={
{990,21},
{1,5},
{2,7},
};
Tc Yutk[]="Proto.writeOneTextField()";
Tcpos ZcTbl94729[]={
{867,38},
{1,5},
{2,7},
{4,5},
{5,7},
{7,5},
{8,5},
{12,9},
{13,13},
{15,13},
{17,9},
{20,9},
{21,13},
{23,13},
{25,9},
{28,9},
{29,13},
{31,13},
{33,9},
{36,9},
{37,13},
{39,13},
{41,9},
{44,9},
{45,13},
{47,13},
{49,9},
{52,9},
{53,13},
{55,13},
{57,9},
{60,9},
{61,13},
{63,13},
{65,9},
{68,9},
{69,13},
{71,13},
{73,9},
{75,9},
{77,11},
{78,15},
{80,15},
{82,11},
{85,9},
{86,16},
{88,16},
{90,9},
{92,9},
{93,37},
{94,9},
{95,30},
{97,9},
{98,11},
{100,11},
{102,28},
{103,9},
{104,11},
{106,9},
{108,9},
};
Tc Yw9e[]="Proto.writeText()";
Tcpos ZcTbl19299[]={
{841,5},
{1,7},
{3,5},
{4,7},
{7,21},
{8,19},
{9,7},
{11,7},
{12,9},
{13,23},
{14,11},
{15,13},
{14,11},
{17,20},
{18,11},
{11,7},
};
Tc YYkI[]="SET.Set__t1.Init()";
Tcpos ZcTbl89012[]={
{41,13},
};
Tc YjAA[]="SET.Set__t1.NEW()";
Tcpos ZcTbl21378[]={
{45,5},
};
Tc YqsZ[]="SET.Set__t1.ToString()";
Tcpos ZcTbl74198[]={
{77,11},
{1,27},
};
Tc YFAP[]="SET.Set__t1.has()";
Tcpos ZcTbl25860[]={
{88,11},
{1,20},
};
Tc Yrsv[]="SET.Set__t1.set()";
Tcpos ZcTbl21676[]={
{139,11},
{1,7},
{2,9},
{4,14},
};
Tc YtGw[]="STRING.trim()";
Tcpos ZcTbl32878[]={
{870,5},
{1,14},
{3,17},
{4,27},
{5,5},
{6,7},
{5,5},
{8,5},
{9,7},
{8,5},
{11,17},
};
Tc YQE_[]="TIME.Values.NEW()";
Tcpos ZcTbl5342[]={
{50,5},
{1,7},
};
Tc Y0DO[]="TIME.Values.NEW/2()";
Tcpos ZcTbl32939[]={
{64,5},
{2,4},
{23,13},
};
Tc YHWY[]="TIME.Values.ToString()";
Tcpos ZcTbl34818[]={
{111,11},
{1,27},
{2,7},
{3,7},
{4,7},
{5,7},
{6,7},
{7,7},
{8,7},
{9,7},
{10,7},
{11,7},
{12,7},
{13,16},
};
Tc YLwM[]="TIME.current()";
Tcpos ZcTbl50841[]={
{22,4},
{5,12},
};
Tc Yxgh[]="Token.error()";
Tcpos ZcTbl40374[]={
{28,9},
{1,5},
};
Tc YYG0[]="Token.zcPos()";
Tcpos ZcTbl52047[]={
{22,9},
{1,18},
};
Tc YwHH[]="TokenInput.NEW()";
Tcpos ZcTbl63886[]={
{27,3},
{1,12},
{2,17},
{3,21},
};
Tc YfrQ[]="TokenInput.emptyStack()";
Tcpos ZcTbl39789[]={
{109,9},
{1,5},
{2,29},
{3,7},
{4,9},
{3,7},
{1,5},
};
Tc YHjE[]="TokenInput.error()";
Tcpos ZcTbl54950[]={
{119,9},
{1,5},
};
Tc Yp4z[]="TokenInput.get()";
Tcpos ZcTbl39372[]={
{37,9},
{1,19},
};
Tc YEF1[]="TokenInput.getToken()";
Tcpos ZcTbl32257[]={
{85,9},
{1,5},
{2,26},
{4,22},
};
Tc YozJ[]="TokenInput.peek()";
Tcpos ZcTbl32309[]={
{47,9},
{1,14},
{2,5},
{3,12},
};
Tc YLKU[]="TokenInput.push()";
Tcpos ZcTbl92336[]={
{42,9},
{1,5},
};
Tc YcP2[]="Tokenizer";
Tcpos ZcTbl20555[]={
{27,24},
{61,24},
{165,20},
{438,20},
};
Tc Yuv2[]="Tokenizer.Init()";
Tcpos ZcTbl34882[]={
{571,11},
{1,5},
{2,7},
{1,5},
{4,5},
{5,7},
{4,5},
{8,12},
};
Tc YPve[]="Tokenizer.addNode()";
Tcpos ZcTbl34905[]={
{551,15},
{1,5},
{2,7},
{3,20},
{5,7},
{6,23},
{8,9},
{1,5},
{10,5},
{11,7},
{13,13},
{14,12},
{15,17},
};
Tc YZvS[]="Tokenizer.controlChar()";
Tcpos ZcTbl90889[]={
{372,5},
{2,9},
{4,9},
{6,9},
{8,9},
{10,9},
{12,9},
{14,9},
{16,9},
{18,9},
{20,9},
{26,19},
{27,9},
{28,23},
{29,11},
{30,13},
{31,13},
{32,13},
{35,13},
{27,9},
{37,9},
{40,9},
{43,9},
{46,9},
{48,9},
{49,9},
{50,9},
};
Tc YX0R[]="Tokenizer.deeper()";
Tcpos ZcTbl60003[]={
{611,16},
{1,5},
{2,19},
{3,7},
{4,9},
{5,11},
{6,20},
{9,9},
{11,20},
{12,21},
{13,18},
{17,5},
{18,12},
};
Tc Ysro[]="Tokenizer.get()";
Tcpos ZcTbl6038[]={
{198,18},
{3,16},
{4,5},
{5,5},
{6,14},
{9,5},
{10,5},
{11,7},
{12,9},
{14,14},
{17,16},
{18,5},
{20,7},
{21,7},
{22,16},
{24,7},
{27,20},
{28,11},
{29,15},
{30,13},
{33,13},
{34,15},
{35,15},
{38,13},
{39,17},
{40,15},
{41,17},
{44,15},
{46,26},
{49,15},
{51,15},
{28,11},
{57,13},
{58,11},
{59,15},
{60,13},
{63,24},
{64,15},
{65,29},
{66,19},
{67,17},
{68,21},
{69,19},
{70,23},
{71,21},
{74,21},
{75,23},
{77,19},
{78,21},
{80,17},
{81,19},
{84,17},
{64,15},
{88,15},
{89,17},
{92,20},
{93,11},
{94,13},
{96,13},
{97,15},
{98,15},
{99,17},
{101,13},
{103,13},
{104,11},
{105,13},
{110,11},
{111,13},
{114,13},
{115,22},
{117,13},
{120,15},
{121,29},
{122,17},
{123,17},
{127,15},
{128,17},
{117,13},
{130,13},
{133,38},
{134,21},
{136,27},
{137,27},
{138,35},
{139,11},
{140,15},
{141,13},
{142,24},
{144,13},
{146,24},
{148,13},
{149,32},
{139,11},
{152,11},
{153,13},
{155,11},
{156,13},
{159,20},
{163,5},
{164,17},
};
Tcpos ZcTbl6039[]={
{364,5},
{2,12},
};
Tc YiIo[]="Tokenizer.getHex()";
Tcpos ZcTbl44787[]={
{428,5},
{1,18},
{2,7},
{3,9},
{4,9},
{5,9},
{6,16},
{8,11},
{0,5},
{10,12},
};
Tc YQws[]="Tokenizer.getNew()";
Tcpos ZcTbl96992[]={
{583,17},
{1,5},
{3,16},
{4,14},
{6,5},
{7,22},
{8,7},
{9,9},
{10,11},
{11,20},
{14,9},
{16,20},
{17,21},
{18,18},
{23,5},
{24,12},
};
Tc YXf2[]="Tokenizer.getRawString()";
Tcpos ZcTbl90891[]={
{443,5},
{1,18},
{2,7},
{3,11},
{4,9},
{6,11},
{11,7},
{12,9},
{13,9},
{16,7},
{0,5},
};
Tc YRo0[]="Tokenizer.handleWhite()";
Tcpos ZcTbl38927[]={
{474,16},
{1,5},
{3,13},
{5,5},
{6,7},
{7,7},
{8,22},
{9,16},
{11,9},
{12,31},
{14,24},
{15,22},
{16,9},
{17,13},
{18,11},
{19,9},
{16,9},
{20,16},
{22,9},
{23,9},
{24,31},
{26,24},
{27,9},
{28,13},
{29,11},
{30,13},
{31,13},
{32,15},
{35,11},
{36,9},
{27,9},
{37,9},
{38,11},
{41,9},
{5,5},
{43,5},
{45,5},
{46,7},
{48,18},
{51,18},
{53,16},
{55,16},
{57,16},
{58,7},
{60,15},
{61,5},
};
Tc YLig[]="Tokenizer.isIdChar()";
Tcpos ZcTbl43917[]={
{21,9},
};
Tc Ym1t[]="Z.Pos.ToString()";
Tcpos ZcTbl18187[]={
{83,11},
{1,27},
{2,7},
{3,9},
{5,9},
{7,7},
{8,7},
{9,7},
{10,7},
{11,16},
};
Tc YzF7[]="Z.Pos.nextLine()";
Tcpos ZcTbl46868[]={
{59,11},
{1,12},
{2,12},
};
Tc Yc3k[]="Zui.Position";
Tcpos ZcTbl92887[]={
{11103,29},
};
Tc YcEv[]="Zui.Position.NEW()";
Tcpos ZcTbl6724[]={
{10951,5},
};
Tc YaaO[]="ZuiFile.copyPosition()";
Tcpos ZcTbl78335[]={
{130,7},
{1,7},
{2,7},
};
Tc Ya7y[]="ZuiFile.createPosition()";
Tcpos ZcTbl6228[]={
{118,7},
{1,16},
{3,27},
{4,7},
{5,7},
{6,7},
{7,14},
};
Tc YXgC[]="getRecorded()";
Tcpos ZcTbl72973[]={
{378,3},
{1,30},
{2,3},
{3,3},
{4,10},
};
Tc YGO7[]="processCss()";
Tcpos ZcTbl34913[]={
{318,3},
{2,3},
{3,3},
{4,3},
{5,3},
{7,3},
{10,3},
{13,3},
{14,16},
{15,5},
{17,9},
{18,9},
{20,9},
{22,9},
{24,9},
{27,11},
{28,11},
{29,15},
{30,13},
{28,11},
{34,11},
{37,9},
{38,9},
{40,5},
{43,5},
{44,7},
{45,14},
{46,18},
{48,18},
{13,3},
{52,3},
{54,3},
{55,3},
};
Tc YYom[]="processFile()";
Tcpos ZcTbl11080[]={
{78,3},
{1,3},
{2,3},
{10,34},
{12,19},
{12,19},
{14,3},
{15,22},
{16,5},
{17,7},
{18,9},
{23,5},
{28,9},
{31,9},
{34,13},
{37,9},
{38,11},
{40,11},
{42,9},
{43,22},
{46,9},
{47,11},
{48,26},
{50,11},
{54,15},
{55,9},
{57,11},
{59,11},
{63,9},
{64,24},
{66,11},
{70,9},
{71,11},
{73,9},
{74,11},
{76,9},
{77,16},
{80,18},
{81,9},
{84,9},
{14,3},
{88,3},
{91,5},
{92,7},
{93,7},
{94,9},
{96,7},
{91,5},
{100,5},
};
Tc Y0C9[]="processHtml()";
Tcpos ZcTbl78201[]={
{209,3},
{1,3},
{6,3},
{7,22},
{8,5},
{10,9},
{11,9},
{13,9},
{14,20},
{15,11},
{16,11},
{18,9},
{20,9},
{22,5},
{6,3},
{26,3},
{27,3},
{30,3},
{31,22},
{32,5},
{33,7},
{34,7},
{36,5},
{30,3},
{40,3},
{42,3},
{43,5},
{44,5},
{46,3},
{50,29},
{53,28},
{56,3},
{59,3},
{60,16},
{61,5},
{63,9},
{64,9},
{66,9},
{68,9},
{70,9},
{73,11},
{74,11},
{75,15},
{76,13},
{74,11},
{80,11},
{83,9},
{86,9},
{88,5},
{91,5},
{92,7},
{93,14},
{94,18},
{96,18},
{59,3},
{100,3},
{102,3},
{103,3},
};
Tc Y621[]="processImport()";
Tcpos ZcTbl14903[]={
{184,3},
{1,3},
{2,22},
{3,5},
{6,5},
{7,23},
{8,23},
{9,29},
{10,30},
{11,7},
{12,19},
{14,7},
{1,3},
{18,3},
};
Tc Y9Ks[]="processStatement()";
Tcpos ZcTbl90021[]={
{497,3},
{1,5},
{3,9},
{4,9},
{6,9},
{8,9},
{10,5},
{0,3},
{15,3},
{16,42},
{17,3},
{18,3},
{20,3},
{22,5},
{23,5},
{24,5},
{25,19},
{27,5},
{30,5},
{31,5},
};
Tc YfX1[]="writeRecorded()";
Tcpos ZcTbl79284[]={
{390,21},
{2,3},
{6,5},
{7,27},
{8,27},
{9,7},
{14,7},
{15,13},
{17,13},
{18,18},
{21,17},
{22,7},
{23,9},
{22,7},
{25,31},
{27,7},
{29,9},
{30,39},
{31,11},
{32,41},
{33,40},
{35,13},
{37,15},
{38,15},
{41,48},
{42,13},
{43,15},
{44,15},
{29,9},
{49,9},
{50,43},
{52,11},
{55,24},
{6,5},
{62,3},
{63,8},
{64,5},
{67,16},
{68,5},
{69,7},
{68,5},
{71,5},
{72,16},
{74,8},
{62,3},
{77,29},
{78,3},
{79,5},
{80,5},
{84,31},
{86,5},
{87,7},
{88,17},
{91,7},
{86,5},
{93,5},
{94,7},
{95,16},
{96,7},
{98,5},
};
Tcode ZcodeTable[]={
{412,Yt1T,YxLq,ZcTbl412},
{1872,Yay0,YNFk,ZcTbl1872},
{3273,YCG4,Y_VO,ZcTbl3273},
{5270,YSHD,Y9QD,ZcTbl5270},
{5342,YyXk,YQE_,ZcTbl5342},
{6038,YqXi,Ysro,ZcTbl6038},
{6039,YqXi,Ysro,ZcTbl6039},
{6228,Y0CK,Ya7y,ZcTbl6228},
{6308,Yt1T,YR5_,ZcTbl6308},
{6724,Yg6g,YcEv,ZcTbl6724},
{7452,Yay0,Ys1a,ZcTbl7452},
{7937,Y_hM,YeMF,ZcTbl7937},
{9948,Yt1T,YALK,ZcTbl9948},
{10045,Yt1T,Y_Bo,ZcTbl10045},
{10613,Yt1T,YCbo,ZcTbl10613},
{11080,YSHD,YYom,ZcTbl11080},
{11217,Yt1T,YoZS,ZcTbl11217},
{11238,Y_hM,Yezt,ZcTbl11238},
{12469,YxTh,YnDn,ZcTbl12469},
{12896,Yt1T,Y0Td,ZcTbl12896},
{13666,YxTh,YlSz,ZcTbl13666},
{14715,Yt1T,Y4SL,ZcTbl14715},
{14903,YSHD,Y621,ZcTbl14903},
{15669,Yt1T,YMB8,ZcTbl15669},
{15718,Yt1T,YEFs,ZcTbl15718},
{16053,Yay0,Y5P_,ZcTbl16053},
{16350,YCG4,Ygzb,ZcTbl16350},
{17179,Yt1T,Yk5m,ZcTbl17179},
{18138,Y_hM,Y9kI,ZcTbl18138},
{18187,Y3zM,Ym1t,ZcTbl18187},
{18609,Y_hM,YJoo,ZcTbl18609},
{18934,Yt1T,Y0TG,ZcTbl18934},
{19299,YxTh,Yw9e,ZcTbl19299},
{19887,Ydmy,YHM2,ZcTbl19887},
{20149,Yt1T,YFbI,ZcTbl20149},
{20555,YqXi,YcP2,ZcTbl20555},
{21197,Y_hM,YrRv,ZcTbl21197},
{21378,YxHL,YjAA,ZcTbl21378},
{21418,Yt1T,YtpQ,ZcTbl21418},
{21439,Y_hM,Y97v,ZcTbl21439},
{21676,YxHL,Yrsv,ZcTbl21676},
{24916,Yt1T,Y9iJ,ZcTbl24916},
{25860,YxHL,YFAP,ZcTbl25860},
{25958,Yt1T,Y4vu,ZcTbl25958},
{26760,Yay0,YYk7,ZcTbl26760},
{26854,Yt1T,YN54b,ZcTbl26854},
{27618,Yt1T,Y8mE,ZcTbl27618},
{28810,Y_hM,YEYq,ZcTbl28810},
{29560,YCG4,YzK9,ZcTbl29560},
{29585,Yt1T,YAVe,ZcTbl29585},
{30532,YxTh,Y1Hw,ZcTbl30532},
{31729,Yt1T,Y0DD,ZcTbl31729},
{32086,Yt1T,Y1As,ZcTbl32086},
{32160,Yt1T,Y5qz,ZcTbl32160},
{32257,Y57c,YEF1,ZcTbl32257},
{32309,Y57c,YozJ,ZcTbl32309},
{32878,Yv00,YtGw,ZcTbl32878},
{32939,YyXk,Y0DO,ZcTbl32939},
{32956,YxTh,YlQ3,ZcTbl32956},
{34047,Ydmy,Yq05,ZcTbl34047},
{34818,YyXk,YHWY,ZcTbl34818},
{34848,Y_hM,YiuT,ZcTbl34848},
{34882,YqXi,Yuv2,ZcTbl34882},
{34905,YqXi,YPve,ZcTbl34905},
{34913,YSHD,YGO7,ZcTbl34913},
{35088,Yt1T,YcIS,ZcTbl35088},
{36159,Yt1T,Y_4w,ZcTbl36159},
{36267,YBRz,YPV8,ZcTbl36267},
{36491,Yt1T,YYT9,ZcTbl36491},
{36994,YxTh,YAt_,ZcTbl36994},
{37884,YxTh,YGqq,ZcTbl37884},
{38552,Yay0,Y35R,ZcTbl38552},
{38911,YCG4,YM2k,ZcTbl38911},
{38927,YqXi,YRo0,ZcTbl38927},
{39372,Y57c,Yp4z,ZcTbl39372},
{39789,Y57c,YfrQ,ZcTbl39789},
{40374,YdPO,Yxgh,ZcTbl40374},
{42983,Yt1T,Y9aV,ZcTbl42983},
{43000,YCG4,YEFE,ZcTbl43000},
{43124,Yt1T,Ygil,ZcTbl43124},
{43917,YqXi,YLig,ZcTbl43917},
{44130,Yt1T,YG80,ZcTbl44130},
{44294,Y_hM,YFRK,ZcTbl44294},
{44401,Ydmy,YOoa,ZcTbl44401},
{44787,YqXi,YiIo,ZcTbl44787},
{45049,Y_hM,Yd3V,ZcTbl45049},
{45209,Yt1T,Y2NH,ZcTbl45209},
{45289,Yt1T,Y7gV,ZcTbl45289},
{46072,Yay0,YB7r,ZcTbl46072},
{46171,Yt1T,Y9VX,ZcTbl46171},
{46312,Yt1T,YPz2,ZcTbl46312},
{46631,Yay0,YHCY,ZcTbl46631},
{46761,Yay0,YN2v,ZcTbl46761},
{46868,Y3zM,YzF7,ZcTbl46868},
{48299,Yt1T,Y9Cv,ZcTbl48299},
{49183,Yt1T,YgcH,ZcTbl49183},
{49285,Yay0,Y1Ue,ZcTbl49285},
{49599,YxTh,Y6Nc,ZcTbl49599},
{49865,Y_hM,YLxt,ZcTbl49865},
{50841,YyXk,YLwM,ZcTbl50841},
{51288,Y_hM,YGr5,ZcTbl51288},
{51535,Yt1T,Y2Qj,ZcTbl51535},
{52047,YdPO,YYG0,ZcTbl52047},
{52386,Yt1T,YgcM,ZcTbl52386},
{52608,Yt1T,YqK0,ZcTbl52608},
{52701,Yt1T,Y0hW,ZcTbl52701},
{52728,Yt1T,Yoiq,ZcTbl52728},
{53325,Yt1T,YlJi,ZcTbl53325},
{53377,Yt1T,Yp81,ZcTbl53377},
{54331,Yt1T,YLzZ,ZcTbl54331},
{54950,Y57c,YHjE,ZcTbl54950},
{56060,Y_hM,YpOc,ZcTbl56060},
{56372,Yt1T,Y4u_,ZcTbl56372},
{56381,Yt1T,Y99g,ZcTbl56381},
{56555,Y76z,YFIR,ZcTbl56555},
{58974,Y_hM,YVp4,ZcTbl58974},
{58975,Yay0,YSa1,ZcTbl58975},
{59819,Yay0,YGQL,ZcTbl59819},
{60003,YqXi,YX0R,ZcTbl60003},
{60066,Y_hM,YG6v,ZcTbl60066},
{60567,Yay0,YskO,ZcTbl60567},
{60593,Yt1T,Y5LR,ZcTbl60593},
{61284,YCG4,Y2cg,ZcTbl61284},
{61489,Y_hM,YLS2,ZcTbl61489},
{62213,Yay0,YU58,ZcTbl62213},
{62809,Yt1T,Ylj3,ZcTbl62809},
{63483,Yt1T,Yuzo,ZcTbl63483},
{63578,Yt1T,Yuz_,ZcTbl63578},
{63886,Y57c,YwHH,ZcTbl63886},
{64478,YCG4,YRbs,ZcTbl64478},
{64531,Yay0,YrJP,ZcTbl64531},
{64912,YxTh,YufP,ZcTbl64912},
{66036,Yt1T,YQJA,ZcTbl66036},
{66188,Yay0,YJ7z,ZcTbl66188},
{66501,YCG4,YPPv,ZcTbl66501},
{68128,Y_hM,YnkC,ZcTbl68128},
{68797,Yt1T,YfLf,ZcTbl68797},
{69175,Y_hM,Y_Q1,ZcTbl69175},
{70530,Yt1T,Yu0r,ZcTbl70530},
{70833,Yt1T,YWEC,ZcTbl70833},
{71988,YxTh,YleD,ZcTbl71988},
{72007,Yay0,YzQB,ZcTbl72007},
{72973,YSHD,YXgC,ZcTbl72973},
{73471,Yt1T,Y_Qs,ZcTbl73471},
{73580,Yt1T,YF6S,ZcTbl73580},
{73684,Yt1T,Yz_l,ZcTbl73684},
{74198,YxHL,YqsZ,ZcTbl74198},
{75697,YCG4,YgDO,ZcTbl75697},
{75905,Yay0,Y_7a,ZcTbl75905},
{76644,YCG4,YImf,ZcTbl76644},
{78082,Yt1T,YbzA,ZcTbl78082},
{78201,YSHD,Y0C9,ZcTbl78201},
{78335,Y0CK,YaaO,ZcTbl78335},
{79042,Y_hM,YDXq,ZcTbl79042},
{79284,YSHD,YfX1,ZcTbl79284},
{79935,Yt1T,YVJp,ZcTbl79935},
{80644,Yt1T,YobA,ZcTbl80644},
{80731,Yt1T,Yzrp,ZcTbl80731},
{81580,Yay0,Y5X7,ZcTbl81580},
{81798,YCG4,YMnk,ZcTbl81798},
{82533,YCG4,Yh2v,ZcTbl82533},
{82534,YCG4,Yh2v,ZcTbl82534},
{82618,Yay0,Yxlj,ZcTbl82618},
{83326,Y76z,YVvh,ZcTbl83326},
{83443,Yay0,Yijq,ZcTbl83443},
{84870,Yay0,Y_pS,ZcTbl84870},
{84899,Y76z,Y8w5,ZcTbl84899},
{85000,Yt1T,Ycb9,ZcTbl85000},
{85295,YCG4,Yza4,ZcTbl85295},
{86206,YCG4,YZNA,ZcTbl86206},
{86594,Ydmy,Y04k,ZcTbl86594},
{86691,Y_hM,YQdE,ZcTbl86691},
{86699,Yt1T,Ym8y,ZcTbl86699},
{86818,Yt1T,YlgI,ZcTbl86818},
{87235,Yt1T,YR5m,ZcTbl87235},
{88105,Yay0,YwPx,ZcTbl88105},
{89012,YxHL,YYkI,ZcTbl89012},
{89243,Y_hM,YIno,ZcTbl89243},
{89581,Yt1T,YAwk,ZcTbl89581},
{89685,Yt1T,Y59h,ZcTbl89685},
{89987,Yay0,YCbR,ZcTbl89987},
{90021,YSHD,Y9Ks,ZcTbl90021},
{90679,YxTh,YI64,ZcTbl90679},
{90889,YqXi,YZvS,ZcTbl90889},
{90891,YqXi,YXf2,ZcTbl90891},
{92163,Yt1T,YTjU,ZcTbl92163},
{92336,Y57c,YLKU,ZcTbl92336},
{92887,Yg6g,Yc3k,ZcTbl92887},
{94729,YxTh,Yutk,ZcTbl94729},
{94823,Yay0,Yj_J,ZcTbl94823},
{96107,Yt1T,YMF2,ZcTbl96107},
{96892,Y_hM,YLNG,ZcTbl96892},
{96992,YqXi,YQws,ZcTbl96992},
{97019,Yt1T,YgQK,ZcTbl97019},
{99838,Yay0,YTE3,ZcTbl99838},
{99886,Yt1T,Y0Jk,ZcTbl99886},
};

#ifdef SIGSEGV
void Zdeadly(int nr) {
 ZthrowDeadly(nr);
}
#endif

void ZthreadGC() {
}
Ti ZstringSizePtr(Tc *s, Tc **dp) {
 Tc *p;
 Ti len;
 p = s + ZOH_OFF;
 if ((*p & 0x80) == 0) {  /* be quick for short string */
  *dp = p + 1;
  return *p;
 }
 len = *p & 0x7f;
 ++p;
 while ((*p & 0x80) != 0) {
  len = (len << 7) + (*p & 0x7f);
  ++p;
 }
 *dp = p + 1;
 return (len << 7) + *p;
}

void ZthrowCstringNil(char *text) {
 YvdV(NULL, Zstr(text));
}

void ZthrowThisNil() {
 YvdV(NULL, Zstr("THIS is NIL"));
}

void ZthrowCstringInit(char *text) {
 Y3w6(Zstr(text));
}

void ZthrowOutOfMemory(Ti size) {
 Y1KV(size);
}

void ZthrowCstringOutOfRange(Ti i, char *text) {
 Y6NT(i, Zstr(text));
}

void ZthrowCstringBadValue(char *msg) {
 Yaez(Zstr(msg));
}

void ZthrowDeadly(int nr) {
 YE93((Ti)nr);
}

void ZthrowInternal(Tc *text) {
 YUSH(NULL, text);
}

Tc *ZintAsString(Ti n) {
 if (n < 0 || n > 0x10fffff)
  ZthrowCstringBadValue("asString(): Character must be in range 0 - 0x10ffff");
 if (n <= 0x7f) {
  Tc *p = Za(ZOH_OFF + 3);
  p[ZOH_OFF] = 1;
  p[ZOH_OFF + 1] = n;
  p[ZOH_OFF + 2] = 0;
  return p;
 }
 if (n <= 0x7ff) {
  Tc *p = Za(ZOH_OFF + 4);
  p[ZOH_OFF] = 2;
  p[ZOH_OFF + 1] = 0xc0 + ((unsigned)n >> 6);
  p[ZOH_OFF + 2] = 0x80 + (n & 0x3f);
  p[ZOH_OFF + 3] = 0;
  return p;
 }
 if (n <= 0xffff) {
  Tc *p = Za(ZOH_OFF + 5);
  p[ZOH_OFF] = 3;
  p[ZOH_OFF + 1] = 0xe0 + ((unsigned)n >> 12);
  p[ZOH_OFF + 2] = 0x80 + (((unsigned)n >> 6) & 0x3f);
  p[ZOH_OFF + 3] = 0x80 + (n & 0x3f);
  p[ZOH_OFF + 4] = 0;
  return p;
 }
 Tc *p = Za(ZOH_OFF + 6);
 p[ZOH_OFF] = 4;
 p[ZOH_OFF + 1] = 0xf0 + ((unsigned)n >> 18);
 p[ZOH_OFF + 2] = 0x80 + (((unsigned)n >> 12) & 0x3f);
 p[ZOH_OFF + 3] = 0x80 + (((unsigned)n >> 6) & 0x3f);
 p[ZOH_OFF + 4] = 0x80 + (n & 0xef);
 p[ZOH_OFF + 5] = 0;
 return p;
}

int Zchar2stringBuf(Ti n, Tc *buf) {
 if (n < 0 || n > 0x10fffff)
  ZthrowCstringBadValue("asString(): Character must be in range 0 - 0x10ffff");
 if (n <= 0x7f) {
  buf[0] = n;
  buf[1] = 0;
  return 1;
 }
 if (n <= 0x7ff) {
  buf[0] = 0xc0 + ((unsigned)n >> 6);
  buf[1] = 0x80 + (n & 0x3f);
  buf[2] = 0;
  return 2;
 }
 if (n <= 0xffff) {
  buf[0] = 0xe0 + ((unsigned)n >> 12);
  buf[1] = 0x80 + (((unsigned)n >> 6) & 0x3f);
  buf[2] = 0x80 + (n & 0x3f);
  buf[3] = 0;
  return 3;
 }
 buf[0] = 0xf0 + ((unsigned)n >> 18);
 buf[1] = 0x80 + (((unsigned)n >> 12) & 0x3f);
 buf[2] = 0x80 + (((unsigned)n >> 6) & 0x3f);
 buf[3] = 0x80 + (n & 0xef);
 buf[4] = 0;
 return 4;
}

/* concat string */
Tc *ZcS(Tc *l, Tc *ri) {
 Tc *l_p;
 Ti l_len;
 Tc *r_p;
 Ti r_len;
 Ti len;
 Tc *pp;
 Tc *r;
 if (l == NULL) {l_len = 3; l_p = (Tc*)"NIL";}
 else l_len = ZstringSizePtr(l, &l_p);
 if (ri == NULL) {r_len = 3; r_p = (Tc*)"NIL";}
 else r_len = ZstringSizePtr(ri, &r_p);
 len = l_len + r_len;
 r = ZnewStringInit(len, &pp);
 memmove(pp, l_p, l_len);
 memmove(pp + l_len, r_p, r_len);
 return r;
}

/* concat string */
Tc *ZcS3(Tc *s1, Tc *s2, Tc *s3) {
 Tc *p1;
 Ti len1;
 Tc *p2;
 Ti len2;
 Tc *p3;
 Ti len3;
 Ti len;
 Tc *pp;
 Tc *r;
 if (s1 == NULL) {len1 = 3; p1 = (Tc*)"NIL";}
 else len1 = ZstringSizePtr(s1, &p1);
 if (s2 == NULL) {len2 = 3; p2 = (Tc*)"NIL";}
 else len2 = ZstringSizePtr(s2, &p2);
 if (s3 == NULL) {len3 = 3; p3 = (Tc*)"NIL";}
 else len3 = ZstringSizePtr(s3, &p3);
 len = len1 + len2 + len3;
 r = ZnewStringInit(len, &pp);
 memmove(pp, p1, len1);
 memmove(pp + len1, p2, len2);
 memmove(pp + len1 + len2, p3, len3);
 return r;
}

/* concat string */
Tc *ZcS5(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5) {
 Tc *p1;
 Ti len1;
 Tc *p2;
 Ti len2;
 Tc *p3;
 Ti len3;
 Tc *p4;
 Ti len4;
 Tc *p5;
 Ti len5;
 Ti len;
 Tc *pp;
 Tc *r;
 if (s1 == NULL) {len1 = 3; p1 = (Tc*)"NIL";}
 else len1 = ZstringSizePtr(s1, &p1);
 if (s2 == NULL) {len2 = 3; p2 = (Tc*)"NIL";}
 else len2 = ZstringSizePtr(s2, &p2);
 if (s3 == NULL) {len3 = 3; p3 = (Tc*)"NIL";}
 else len3 = ZstringSizePtr(s3, &p3);
 if (s4 == NULL) {len4 = 3; p4 = (Tc*)"NIL";}
 else len4 = ZstringSizePtr(s4, &p4);
 if (s5 == (Tc*)1) len5 = 0;
 else if (s5 == NULL) {len5 = 3; p5 = (Tc*)"NIL";}
 else len5 = ZstringSizePtr(s5, &p5);
 len = len1 + len2 + len3 + len4 + len5;
 r = ZnewStringInit(len, &pp);
 memmove(pp, p1, len1);
 memmove(pp + len1, p2, len2);
 memmove(pp + len1 + len2, p3, len3);
 memmove(pp + len1 + len2 + len3, p4, len4);
 if (s5 != (Tc*)1) memmove(pp + len1 + len2 + len3 + len4, p5, len5);
 return r;
}

/* concat string */
Tc *ZcS8(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5, Tc *s6, Tc *s7, Tc *s8) {
 Tc *p[8];
 Ti len[8];
 Ti totlen = 0;
 Tc *pp;
 Tc *r;
 int i;
 if (s1 == NULL) {len[0] = 3; p[0] = (Tc*)"NIL";}
 else len[0] = ZstringSizePtr(s1, &p[0]);
 if (s2 == NULL) {len[1] = 3; p[1] = (Tc*)"NIL";}
 else len[1] = ZstringSizePtr(s2, &p[1]);
 if (s3 == NULL) {len[2] = 3; p[2] = (Tc*)"NIL";}
 else len[2] = ZstringSizePtr(s3, &p[2]);
 if (s4 == NULL) {len[3] = 3; p[3] = (Tc*)"NIL";}
 else len[3] = ZstringSizePtr(s4, &p[3]);
 if (s5 == NULL) {len[4] = 3; p[4] = (Tc*)"NIL";}
 else len[4] = ZstringSizePtr(s5, &p[4]);
 if (s6 == NULL) {len[5] = 3; p[5] = (Tc*)"NIL";}
 else len[5] = ZstringSizePtr(s6, &p[5]);
 if (s7 == (Tc*)1) len[6] = 0;
 else if (s7 == NULL) {len[6] = 3; p[6] = (Tc*)"NIL";}
 else len[6] = ZstringSizePtr(s7, &p[6]);
 if (s8 == (Tc*)1) len[7] = 0;
 else if (s8 == NULL) {len[7] = 3; p[7] = (Tc*)"NIL";}
 else len[7] = ZstringSizePtr(s8, &p[7]);
 for (i = 0; i < 8; ++i) totlen += len[i];
 r = ZnewStringInit(totlen, &pp);
 totlen = 0;
 for (i = 0; i < 8; ++i) {
  memmove(pp + totlen, p[i], len[i]);
  totlen += len[i];
 }
 return r;
}

Tr Zao(void *ptr, Tc **table, Ti type) {
 Tr tr;
 tr.ptr = ptr;
 tr.table = table;
 tr.type = type;
 return tr;
}

/* fill not-allocated object reference */
Tr *Znao(Tr *p, void *ptr, Tc **table, Ti type) {
 p->ptr = ptr;
 p->table = table;
 p->type = type;
 return p;
}

Tr ZconvertZioref(Tr orig, Tc ***table, int type, int maxType, Ti pos) {
 Tr p;
 if (orig.ptr == NULL) p.ptr = NULL;
 else {
  if (orig.type < type || orig.type >= maxType) YTuG(pos);
  p.ptr = orig.ptr;
  p.type = orig.type - type;
  p.table = table[p.type];
 }
 return p;
}

void *Zio(int type, Ti pos, Tr *p) {
 void *r;
 if (p == NULL || p->ptr == NULL) r = NULL;
 else {
  if (p->type != type) YTuG(pos);
  r = p->ptr;
 }
 return r;
}

void *Znio(int type, Ti pos, Tr tr) {
 void *r;
 if (tr.ptr == NULL) r = NULL;
 else {
  if (tr.type != type) YTuG(pos);
  r = tr.ptr;
 }
 return r;
}

void Zexit(YkxB *pos, Ti val) {
 beforeExit();
 exit((int)val);
}

Tt *ZiobjType(Tr *p) {
 if (p == NULL) ZthrowCstringNil("using Type() on NIL");
 return (Tt *)(p->table[0]);
}

void *ZnoAllocClear(size_t len, void *p, void *(*init)(void*)) {
 memset(p, 0, len);
 if (init) init(p);
 return p;
}

Ti ZChar2ByteIdx(Tc *p, Ti len, Ti charIdx) {
 Ti idx = 0;
 Ti count = 0;
 while (count < charIdx) {
  if (idx == len) break;
  ++idx;
  if ((p[idx - 1] & 0x80) != 0) {
    while ((p[idx] & 0xc0) == 0x80)
      ++idx;
  }
  ++count;
 }
 return idx;
}

Ti ZfromChar(Tc *p) {
 if (*p <= 0x7f)
  return *p;
 if ((*p & 0xe0) == 0xc0)
  return ((p[0] & 0x1f) << 6) + (p[1] & 0x3f);
 if  ((*p & 0xf0) == 0xe0)
  return ((p[0] & 0x0f) << 12) + ((p[1] & 0x3f) << 6) + (p[2] & 0x3f);
 return ((p[0] & 0x07) << 18) + ((p[1] & 0x3f) << 12) + ((p[2] & 0x3f) << 6) + (p[3] & 0x3f);
}

Ti ZstringGetChar(Tc *sv, Ti idx) {
 Ti i;
 Tc *p;
 Ti len;
 Ti r;
 if (sv == NULL) ZthrowCstringNil("using [] on NIL");
 if (idx < 0) ZthrowCstringOutOfRange(idx, "using negative index");
 len = ZstringSizePtr(sv, &p);
 i = ZChar2ByteIdx(p, len, idx);
 if (i >= len) ZthrowCstringOutOfRange(idx, "index too big");
 r = ZfromChar(p + i);
 return r;
}

Ti Zutf8size(Tc *sp, Ti len) {
 Tc *p = (Tc*)sp;
 Tc *pend = p + len;
 Ti clen = 0;
 while (p < pend) {
  if ((*p & 0xc0) != 0x80) ++clen;
  ++p;
 }
 return clen;
}

Ti ZstringSize(Tc *s) {
 Tc *p;
 Ti r;
 Ti len;
 if (s == NULL) return 0;
 len = ZstringSizePtr(s, &p);
 r = Zutf8size(p, len);
 return r;
}

Ti ZbyteStringSize(Tc *s) {
 Tc *p;
 Ti len;
 if (s == NULL) return 0;
 p = s + ZOH_OFF;
 if ((*p & 0x80) == 0) {
  return *p;  /* be quick for short string */
 }
 len = *p & 0x7f;
 ++p;
 while ((*p & 0x80) != 0) {
  len = (len << 7) + (*p & 0x7f);
  ++p;
 }
 return (len << 7) + *p;
}

Tc *Zint2string(Ti n) {
 char buf[30];
 char *p;
 int len;
 sprintf(buf, ZINT_FORMAT, n);
 len = (int)strlen(buf);
 p = Za(ZOH_OFF + len + 2);
 p[ZOH_OFF] = len;
 strcpy(p + ZOH_OFF + 1, buf);
 return (Tc*)p;
}

Tc *ZintFormat(Tc *fmt, Ti n) {
 char fmtbuf[100];
 char buf[100];
 char *p;
 int len;
 int c;
 Tc *fmtp;
 if (fmt == NULL) ZthrowCstringNil("ToString(): format is NIL");
 if (ZstringSizePtr(fmt, &fmtp) > 90) {
  ZthrowCstringBadValue("ToString(): format too long");
 }
 c = fmtp[strlen((char*)fmtp) - 1];
 if (c != 'd' && c != 'x') {
  ZthrowCstringBadValue("ToString(): format must end in 'd' or 'x'");
 }
 sprintf(fmtbuf, "%%%s", fmtp);
 strcpy(fmtbuf + strlen(fmtbuf) - 1, (c == 'd' ? ZINT_FORMAT : ZINT_XFORMAT) + 1);
 sprintf(buf, fmtbuf, n);
 len = (int)strlen(buf);
 p = Za(ZOH_OFF + len + 2);
 p[ZOH_OFF] = len;
 strcpy(p + ZOH_OFF + 1, buf);
 return (Tc*)p;
}

#ifdef __MINGW32__
void ZcorrFloatStr(char *buf, char *fmt) {
 size_t len = strlen(buf);
 if (len > 5 && buf[len - 3] == '0' && (buf[len - 5] == 'e' || buf[len - 5] == 'E')) {
  if (fmt != NULL && isdigit(fmt[1]) && strchr(fmt, '.') > 0 && atoi(fmt + 1) >= strlen(buf)) {
   memcpy(buf + 1, buf, len - 2);
   buf[0] = ' ';
  } else {
   buf[len - 3] = buf[len - 2];
   buf[len - 2] = buf[len - 1];
   buf[len - 1] = 0;
  }
 } else if (strcmp(buf, "1.#INF") == 0) {
  strcpy(buf, "inf");
 } else if (strcmp(buf, "-1.#INF") == 0) {
  strcpy(buf, "-inf");
 } else if (strcmp(buf, "1.#QNAN") == 0) {
  strcpy(buf, "nan");
 }
}
#endif

Tc *ZfloatFormat(Tc *fmt, Tf n) {
 char fmtbuf[100];
 char buf[100];
 char *p;
 int len;
 Tc *fmtp;
 if (fmt == NULL) ZthrowCstringNil("ToString(): format is NIL");
 if (ZstringSizePtr(fmt, &fmtp) > 90) {
  ZthrowCstringBadValue("ToString(): format too long");
 }
 sprintf(fmtbuf, "%%%s", fmtp);
#ifdef __MINGW32__
 len = (int)strlen(fmtbuf);
 if (fmtbuf[len - 1] == 'F')
  fmtbuf[len - 1] = 'f';
#endif
 sprintf(buf, fmtbuf, n);
#ifdef __MINGW32__
 ZcorrFloatStr(buf, fmtbuf);
#endif
 len = (int)strlen(buf);
 p = Za(ZOH_OFF + len + 2);
 p[ZOH_OFF] = len;
 strcpy(p + ZOH_OFF + 1, buf);
 return (Tc*)p;
}

Tc *Zenum2string(char **names, Te n) {
 return Zstr((n < 0 || n >= (Te)(size_t)names[0]) ? "INVALID" : names[n + 1]);
}

char *ZgetCstring(Tc *s) {
 Tc *p;
 if (s == NULL) return NULL;
 p = s + ZOH_OFF;
 while ((*p & 0x80) != 0) ++p;
 return (char *)p + 1;
}

void ZforStringNew(Tc *p, Tfs *s) {
 s->len = p == NULL ? 0 : ZstringSizePtr(p, &(s->ptr));
 s->idx = 0;
}
void ZforStringGetInt(Tfs *s, Ti *p) {
 if (s->idx >= s->len) *p = 0;
 else *p = ZfromChar(s->ptr + s->idx);
}
int ZforStringContInt(Tfs *s) {
return s->idx < s->len;
}
void ZforStringNextInt(Tfs *s, Ti *p) {
 if (s->idx < s->len) {
  ++(s->idx);
  while ((s->ptr[s->idx] & 0xc0) == 0x80) ++(s->idx);
 }
 ZforStringGetInt(s, p);
}

void ZforRangeNew(Ti start, Ti last, int until, Ti step, Tfr *s) {
 s->idx = start;
 if (until)
  s->last = last - (step > 0 ? 1 : -1);
 else
  s->last = last;
 s->step = step;
}
void ZforRangeGetInt(Tfr *s, Ti *p) {
 *p = s->idx;
}
int ZforRangeContInt(Tfr *s) {
 return s->step > 0 ? (s->idx <= s->last) : (s->idx >= s->last);
}
void ZforRangeNextInt(Tfr *s, Ti *p) {
 s->idx += s->step;
 ZforRangeGetInt(s, p);
}

void ZthrowIobject(Tr eo) {
 YxIS(eo);
}
void ga_append(Tg *ga, char *str) {
 int len = (int)strlen(str);
 if (ga->data == NULL || ga->used + len >= ga->len) {
  int newLen = ga->used + len + 200;
  Tc *newData = ZaOff(newLen);
  if (ga->data != NULL) {
    memmove(newData, ga->data, ga->used);
    Zfree(ga->data - ZOH_OFF);
  }
  ga->data = newData;
  ga->len = newLen;
 }
 strcpy((char *)ga->data + ga->used, str);
 ga->used += len;
}

int ZstringCmp(Tc *s1, Tc *s2) {
 Tc *p1;
 Tc *p2;
 Ti len1;
 Ti len2;
 int r;
 if (s1 == NULL || s2 == NULL) {
  if (s1 == NULL && s2 == NULL) r = 0;
  else r = 1;
  goto end;
 }
 if (s1[ZOH_OFF] != s2[ZOH_OFF]) {
  r = 1;
  goto end;
 }
 len1 = ZstringSizePtr(s1, &p1);
 len2 = ZstringSizePtr(s2, &p2);
 if (len1 == len2) {
  r = memcmp(p1, p2, len1);
  goto end;
 }
 r = 1;
end:
 return r;
}

Ti ZChar2ByteIdxEnd(Tc *p, Ti len, Ti charIdx) {
 Ti idx = len;
 Ti count = 0;
 while (count < charIdx) {
  if (idx == 0) return -1;
  --idx;
  while (idx > 0 && (p[idx] & 0xc0) == 0x80)
    --idx;
  ++count;
 }
 return idx;
}

Ti ZstringFindLen(Tc *big, Ti biglen, Tc *small, Ti smalllen) {
 Ti i;
 Ti ci = 0;
 for (i = 0; i <= biglen - smalllen; ++ci) {
  if (memcmp(big + i, small, smalllen) == 0)
   return ci;
  ++i;
  while ((big[i] & 0xc0) == 0x80 && i < biglen)
   ++i;
 }
 return -1;
}

Ti ZstringFind(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Ti r;
 if (big == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  if (small == NULL) ZthrowCstringNil("using find() with NIL argument");
  biglen = ZstringSizePtr(big, &bigp);
  smalllen = ZstringSizePtr(small, &smallp);
  r = ZstringFindLen(bigp, biglen, smallp, smalllen);
 }
 return r;
}

Ti ZstringFind2(Tc *big, Tc *small, long start, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Ti r;
 Ti i = start;
 if (big == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  if (small == NULL) ZthrowCstringNil("using find() with NIL argument");
  biglen = ZstringSizePtr(big, &bigp);
  while (biglen > 0 && i > 0) {
   --i;
   while (biglen > 1 && (*bigp & 0xc0) == 0x80) {
    ++bigp;
    --biglen;
   }
   ++bigp;
   --biglen;
  }
  if (i == 0) {
   smalllen = ZstringSizePtr(small, &smallp);
   r = ZstringFindLen(bigp, biglen, smallp, smalllen);
   if (r >= 0) r += start;
  } else {
   r = -1;
  }
 }
 return r;
}

Ti ZptrFindChar2(Tc *s, Ti slen, Ti c, Ti low) {
 Tc *p = s;
 Ti idx = 0;
 Ti len;
 Tc buf[5];
 int charlen;
 int clen = Zchar2stringBuf(c, buf);
 for (len = slen; len > 0; len -= charlen) {
  for (charlen = 1; (p[charlen] & 0xc0) == 0x80; ++charlen)
   ;
  if (charlen == clen && memcmp(buf, p, charlen) == 0 && idx >= low) {
   return idx;
  }
  p += charlen;
  ++idx;
 }
 return -1;
}

Ti ZstringFindChar2(Tc *s, Ti c, Ti low, int dn) {
 Tc *p;
 int len;
 Ti r;
 if (s == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  len = ZstringSizePtr(s, &p);
  r = ZptrFindChar2(p, len, c, low);
 }
 return r;
}

Ti ZstringFindChar(Tc *s, Ti c, int dn) {
 return ZstringFindChar2(s, c, 0, dn);
}

Tb ZstringStartsWith(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Tb r = 0;
 if (big == NULL) {
  if (dn) goto end;
  ZthrowCstringNil("using startsWith() on NIL");
 }
 if (small == NULL) ZthrowCstringNil("using startsWith() with NIL argument");
 biglen = ZstringSizePtr(big, &bigp);
 smalllen = ZstringSizePtr(small, &smallp);
 if (smalllen <= biglen) r = memcmp(bigp, smallp, smalllen) == 0;
end:
 return r;
}

Tb ZstringEndsWith(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Tb r = 0;
 if (big == NULL) {
  if (dn) goto end;
  ZthrowCstringNil("using endsWith() on NIL");
 }
 if (small == NULL) ZthrowCstringNil("using endsWith() with NIL argument");
 biglen = ZstringSizePtr(big, &bigp);
 smalllen = ZstringSizePtr(small, &smallp);
 if (smalllen <= biglen) r = memcmp(bigp + biglen - smalllen, smallp, smalllen) == 0;
end:
 return r;
}

Ti ZptrFindLastChar2(Tc *s, Ti slen, Ti c, Ti high) {
 Tc *p = s;
 Ti idx = 0;
 Ti best = -1;
 Ti len;
 Tc buf[5];
 int charlen;
 int clen = Zchar2stringBuf(c, buf);
 for (len = slen; len > 0 && idx <= high; len -= charlen) {
  for (charlen = 1; (p[charlen] & 0xc0) == 0x80; ++charlen)
   ;
  if (charlen == clen && memcmp(buf, p, charlen) == 0)
   best = idx;
  p += charlen;
  ++idx;
 }
 return best;
}

Ti ZstringFindLastChar(Tc *s, Ti c, int dn) {
 Tc *p;
 int len;
 Ti r;
 if (s == NULL) {
  if (!dn) ZthrowCstringNil("using findLast() on NIL");
  r = -1;
 } else {
  len = ZstringSizePtr(s, &p);
  r = ZptrFindLastChar2(p, len, c, len);
 }
 return r;
}

Tl *ZstringSplitLen(Tc *pss, Ti len, Tc *m) {
 Tl *head = ZnewList(&string__T, 0);
 if (len > 0) {
  Tc *mp;
  Ti mlen = ZstringSizePtr(m, &mp);
  Tc *ps;
  Tc *pe;

  for (ps = pss; ; ps = pe + mlen) {
   int nlen;
   /* TODO: handle NULL byteString */
   pe = (Tc*)strstr((char *)ps, (char *)mp);
   if (pe == NULL) {
    nlen = len - (ps - pss);
   } else {
    nlen = pe - ps;
   }
   ZLa(head, -1, (Tz)(void*)ZnewString(ps, nlen));
   if (pe == NULL) break;
  }
 }
 return head;
}

Tl *ZstringSplit(Tc *b, Tc *m, int dn) {
 Tc *p;
 Ti len;
 Tl *r;
 if (b == NULL) {
  if (!dn) ZthrowCstringNil("using split() on NIL");
  r = NULL;
 } else {
  if (m == NULL) ZthrowCstringNil("split() argument is NIL");
  len = ZstringSizePtr(b, &p);
  r = ZstringSplitLen(p, len, m);
 }
 return r;
}

Tc *ZstringSlice(Tc *sv, Ti start, Ti end, int dn) {
 Ti is;
 Ti ie;
 Tc *p;
 Ti len;
 Tc *r;
 if (sv == NULL) {
  if (dn) return NULL;
  ZthrowCstringNil("using slice() on NIL");
 }
 len = ZstringSizePtr(sv, &p);
 is = start < 0 ? ZChar2ByteIdxEnd(p, len, -start) : ZChar2ByteIdx(p, len, start);
 ie = end < 0 ? ZChar2ByteIdxEnd(p, len, -end - 1) - 1 : ZChar2ByteIdx(p, len, end + 1) - 1;
 if (is < 0)
  is = 0;
 if (ie < 0 || ie < is) r = ZnewString((Tc*)"", 0);
 else r = ZnewString(p + is,  ie - is + 1);
 return r;
}

Ti ZptrToInt(Tc *s, int t, Ti def) {
 Ti r;
 char *p = (char*)s;
 if ((*p < '0' || *p > '9') && *p != '-') {
  if (t == 1) ZthrowCstringBadValue("toInt(): argument does not start with a digit or -");
  return def;
 }
 sscanf(p, ZINT_FORMAT, &r);
 return r;
}

Ti ZptrHexToInt(Tc *s, int t, Ti def) {
 Ti r;
 char *p = (char *)s;
 if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) p += 2;
 if ((*p < '0' || *p > '9') && (*p < 'a' || *p > 'f') && (*p < 'A' || *p > 'F')) {
  if (t == 1) ZthrowCstringBadValue("hexToInt(): argument does not start with a hex digit");
  return def;
 }
 sscanf(p, ZINT_XFORMAT, &r);
 return r;
}

Ti ZstringToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using toInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrToInt(s, t, def);
 return r;
}

Ti ZstringHexToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using hexToInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrHexToInt(s, t, def);
 return r;
}

void ZitemToString(Tt *type, int useq, Tz val, Tg *ga);

void ZobjectToString(Tto *typearg, void *ptrarg, Tg *ga) {
 Tto *type = typearg;
 void *ptr = ptrarg;
 To *to;
 int cnt;
 if (type == NULL && ptr != NULL) {
  type = ((Tto*)ZiobjType(ptr));
  ptr = ((Tr*)ptr)->ptr;
 }
 if (ptr == NULL ) {
  ga_append(ga, "{NIL}");
 } else {
  int i;
  int first = 1;
  if (type->ToString != NULL) {
   Tc *p = ((Tc * (*)(void *))type->ToString)(ptr);
   ga_append(ga, ZgetCstring(p));
   return;
  }
  to = type->to;
  ga_append(ga, "{");
  cnt = to[0].off;
  for (i = 1; i <= cnt; ++i) {
   Tz val;
   void *vptr = ptr + to[i].off;

   if (!first) ga_append(ga, ", ");
   first = 0;
   ga_append(ga, type->names[i - 1]);
   ga_append(ga, ": ");
   switch (to[i].type->nr) {
    case 0:
    case 24:
    case 25:
     val = (Tz)*((Ti*)vptr); break;
    case 10:
     val = (Tz)(Ti)*((Tu*)vptr); break;
    case 1:
     val = (Tz)(Ti)*((char*)vptr); break;
    case 11:
     val = (Tz)(Ti)*((Tc*)vptr); break;
    case 2:
     val = (Tz)(Ti)*((Ti16*)vptr); break;
    case 12:
     val = (Tz)(Ti)*((Tu16*)vptr); break;
    case 3:
     val = (Tz)(Ti)*((Ti32*)vptr); break;
    case 13:
     val = (Tz)(Ti)*((Tu32*)vptr); break;
    case 21:
    case 22:
    case 23:
     val = (Tz)(Ti)*((int*)vptr); break;
    case 80:
    case 82:
    case 83:
     val = (Tz)*((Tf*)vptr); break;
    case 81:
     val = (Tz)(Tf)*((Tf32*)vptr); break;
    default:
     val = (Tz)*(((void**)vptr)); break;
   }
   ZitemToString(to[i].type, 1, val, ga);
  }
  ga_append(ga, "}");
 }
}

Tc *ZobjectToStringval(Tto *type, void *ptr) {
 Tg ga;
 Tc *r;
 ga.data = NULL;
 ga.used = 0;
 ++(&Zenv)->tosNr;
 ZobjectToString(type, ptr, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree(ga.data - ZOH_OFF);
 return r;
}
Tc *ZiobjectToStringval(Tr tr) {
 Tg ga;
 Tc *r;
 ga.data = NULL;
 ga.used = 0;
 ++(&Zenv)->tosNr;
 ZobjectToString((Tto*)tr.table[0], tr.ptr, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree(ga.data - ZOH_OFF);
 return r;
}

void ZitemToString(Tt *type, int useq, Tz val, Tg *ga) {
 char buf[30];
 if (type->nr < 100) {
  switch (type->nr) {
   case 0:
   case 1:
   case 2:
   case 3:
   case 25:
    sprintf(buf, ZINT_FORMAT, val.ival);
    ga_append(ga, buf);
    break;
   case 10:
    sprintf(buf, ZNAT_FORMAT, (Tu)val.ival);
    ga_append(ga, buf);
    break;
   case 11:
    sprintf(buf, ZNAT_FORMAT, (Tu)(Tc)val.ival);
    ga_append(ga, buf);
    break;
   case 12:
    sprintf(buf, ZNAT_FORMAT, (Tu)(Tu16)val.ival);
    ga_append(ga, buf);
    break;
   case 13:
    sprintf(buf, ZNAT_FORMAT, (Tu)(Tu32)val.ival);
    ga_append(ga, buf);
    break;
   case 21: ga_append(ga, val.ival ? "TRUE" : "FALSE"); break;
   case 22: ga_append(ga, val.ival ? "OK" : "FAIL"); break;
   case 23:
    if (type->ToString == NULL) {
     ga_append(ga, "-enum");
     if (type->name) {
      ga_append(ga, " ");
      ga_append(ga, ZgetCstring(type->name));
     }
     ga_append(ga, "-");
    } else {
     ga_append(ga, ((char * (*)(Te))type->ToString)(val.ival));
    }
    break;
   case 80:
   case 81:
   case 82:
   case 83:
    sprintf(buf, ZFLOAT_FORMAT, val.fval);
#ifdef __MINGW32__
    ZcorrFloatStr(buf, NULL);
#endif
    ga_append(ga, buf);
    break;
  }
 } else {
  void *ptr = val.ptr;
  if (ptr == NULL) ga_append(ga, "NIL");
  else switch (type->nr) {
   case 200:
   case 201: {
     Tc *p;
     (void)ZstringSizePtr(ptr, &p);
     if (useq) ga_append(ga, "\"");
     ga_append(ga, (char *)p);
     if (useq) ga_append(ga, "\"");
    }
    break;
   case 300:
    ZArrayToStringGa((Ta *)ptr, 1, ga);
    break;
   case 301:
    ZListToStringGa((Tl *)ptr, 1, ga);
    break;
   case 302:
    ZDictToStringGa((Td *)ptr, 1, 1, ga);
    break;
   case 310:
    ga_append(ga, "-varString-");
    break;
   case 311:
    ga_append(ga, "-varByteString-");
    break;
   case 320:
    if (type->ToString == NULL) ga_append(ga, "-tuple-");
    else {
     Tc *p = ((Tc * (*)(void *))type->ToString)(ptr);
     ga_append(ga, ZgetCstring(p));
    }
    break;
   case 330:
    ga_append(ga, "-proc/func-");
    break;
   case 390:
    ZobjectToString(((Tto*)type), ptr, ga);
    break;
   case 391:
    ZobjectToString((Tto*)((Tr*)ptr)->table[0], ((Tr*)ptr)->ptr, ga);
    break;
  }
 }
}

int ZcopyItems(Tt *toType, int toSize, void *toPtr, Ti toOff, Tt *fromType, int fromSize, void *fromPtr, Ti fromOff, Ti len) {
 Ti i;
 if (toType == fromType || (toType->nr >= 100 && fromType->nr >= 100)) {
  memmove((char*)toPtr + toOff * toSize, (char*)fromPtr + fromOff * fromSize, len * toSize);
  return 1;
 }
 if (fromType->nr >= 100 || toType->nr >= 100) return 0;
 for (i = 0; i < len; ++i) {
  Ti iv;
  Tf fv;
  switch (fromType->nr) {
   case 0:
   case 24:
   case 25:
    iv = ((Ti*)fromPtr)[fromOff + i]; fv = iv; break;
   case 1:
    iv = ((char*)fromPtr)[fromOff + i]; fv = iv; break;
   case 2:
    iv = ((Ti16*)fromPtr)[fromOff + i]; fv = iv; break;
   case 3:
    iv = ((Ti32*)fromPtr)[fromOff + i]; fv = iv; break;
   case 10:
    iv = ((Tu*)fromPtr)[fromOff + i]; fv = iv; break;
   case 11:
    iv = ((Tc*)fromPtr)[fromOff + i]; fv = iv; break;
   case 12:
    iv = ((Tu16*)fromPtr)[fromOff + i]; fv = iv; break;
   case 13:
    iv = ((Tu32*)fromPtr)[fromOff + i]; fv = iv; break;
   case 21:
   case 22:
   case 23:
    iv = ((int*)fromPtr)[fromOff + i]; fv = iv; break;
   case 80:
   case 82:
   case 83:
    fv = ((Tf*)fromPtr)[fromOff + i]; iv = fv; break;
   case 81:
    fv = ((Tf32*)fromPtr)[fromOff + i]; iv = fv; break;
  }
  switch (toType->nr) {
   case 0:
   case 10:
   case 24:
   case 25:
    ((Ti*)toPtr)[toOff + i] = iv; break;
   case 1:
   case 11:
    ((char*)toPtr)[toOff + i] = iv; break;
   case 2:
   case 12:
    ((Ti16*)toPtr)[toOff + i] = iv; break;
   case 3:
   case 13:
    ((Ti32*)toPtr)[toOff + i] = iv; break;
   case 21:
   case 22:
   case 23:
    ((int*)toPtr)[toOff + i] = iv; break;
   case 80:
   case 82:
   case 83:
    ((Tf*)toPtr)[toOff + i] = fv; break;
   case 81:
    ((Tf32*)toPtr)[toOff + i] = fv; break;
  }
 }
 return 1;
}
void ZfreeArray(Ta *head) {
 Ti i;
 Ti d;
 if (head == NULL) return;
 if (head->ptr && head->ptr != head + 1) {
  Zfree(head->ptr - ZOH_OFF);
 }
 Zfree(head);
}

Ta *ZArrayInit(Ta *head, Tt *itemType, int itemSize, Ti size) {
 head->ptr = ZaOff(itemSize * size);
 head->dim = 1;
 head->size[0] = size;
 head->itemType = itemType;
 head->itemSize = itemSize;
 return head;
}

Ta *ZnewArray(Tt *itemType, int itemSize, Ti size) {
 Ta *head;
 size_t extra = size * itemSize;
 if (extra > 100) extra = 0;
 head = Za(sizeof(Ta) + extra);
 if (extra == 0) {
  head->ptr = ZaOff(itemSize * size);
 } else head->ptr = head + 1;
 head->dim = 1;
 head->size[0] = size;
 head->itemType = itemType;
 head->itemSize = itemSize;
 return head;
}

Ti ZArraySize(Ta *head) {
 Ti r;
 if (head == NULL) r = 0;
 else r = head->size[0];
 return r;
}

void *ZarrayPtr(Ta *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("using [] on NIL array");
 if (idx < 0 || idx >= head->size[0]) ZthrowCstringOutOfRange(idx, "array index out of bounds");
 return head->ptr + idx * head->itemSize;
}

Ta *Zas(Ta *head, void *vals, int type, Ti offset) {
 int len;
 int i;
 if (head == NULL) ZthrowCstringNil("Invoking set() on NIL array");
 if (type == 0) {
  /* vals is a byteString */
  Tc *p;
  len = ZstringSizePtr(vals, &p);
  if (len > head->size[0] - offset) len = head->size[0] - offset;
  if (head->itemSize == 1) {
   memmove(((Tc*)head->ptr) + offset, p, len);
  } else if (head->itemSize == sizeof(Te)) {
   for (i = 0; i < len; ++i) ((Te*)head->ptr)[i + offset] = p[i];
  } else {
   for (i = 0; i < len; ++i) ((Ti*)head->ptr)[i + offset] = p[i];
  }
 } else if (type == 1) {
  /* vals is an array */
  Ta *from = vals;
  len = from->size[0];
  if (len > head->size[0] - offset) len = head->size[0] - offset;
  ZcopyItems(head->itemType, head->itemSize, head->ptr, offset, from->itemType, from->itemSize, from->ptr, 0, len);

 } else {
  /* vals is a list */
  Tl *from = (Tl*)vals;
  Ti count = from->itemCount;
  if (count > offset + head->size[0]) count = offset + head->size[0];
  ZcopyItems(head->itemType, head->itemSize, head->ptr, offset, from->itemType, from->itemSize, from->items, from->empty, count);
 }
 return head;
}

Ta *ZarrayResize(Ta *head, int bytes, Ti size) {
 if (head == NULL) ZthrowCstringNil("Invoking resize() on NIL array");
 if (head->ptr == head + 1) {
  head->ptr = ZaOff(bytes * size);
  memmove(head->ptr, head + 1, size > head->size[0] ? bytes * head->size[0] : bytes * size);
 } else head->ptr = ZranOff(head->ptr, bytes * head->size[0], bytes * size);
 head->size[0] = size;
 return head;
}

void ZArrayToStringGa(Ta *head, int useq, Tg *ga) {
 int i;
 Tn *e = (&Zenv);
 ga_append(ga, "[");
 if (head->tosNr == e->tosNr) {
  ga_append(ga, "recursive-array");
 } else {
  head->tosNr = e->tosNr;
  for (i = 0; i < head->size[0]; ++i) {
   Tz v;
   if (i > 0) ga_append(ga, ", ");
   if (head->itemType == &iobj__T) {
    Tr *tr = (Tr*)head->ptr + i;
    if (tr->ptr == NULL) ZobjectToString(NULL, NULL, ga);
    else ZitemToString((Tt*)(tr->table[0]), useq, (Tz)tr->ptr, ga);
   } else {
    if (head->itemSize == 1) {
     v.ival = ((Tc*)head->ptr)[i];
    } else if (head->itemType->nr >= 100) {
     v.ptr = ((char**)head->ptr)[i];
    } else if (head->itemSize == sizeof(Te)) {
     v.ival = ((Te*)head->ptr)[i];
    } else {
     v.ival = ((Ti*)head->ptr)[i];
    }
    ZitemToString(head->itemType, useq, v, ga);
   }
  }
  head->tosNr = 0;
 }
 ga_append(ga, "]");
}

Tc *ZarrayToString(Ta *head, int useq) {
 Tg ga;
 Tc *r;
 if (head == NULL) return (Tc*)&ZNilString;
 ++(&Zenv)->tosNr;
 ga.data = NULL;
 ga.used = 0;
 ZArrayToStringGa(head, useq, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree(ga.data - ZOH_OFF);
 return r;
}

Ti ZListFindIdx(Tl *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("Accessing NIL list");
 if (idx < 0) {
  Ti n = head->itemCount + idx;
  if (n < 0) return n;
  return n + head->empty;
 }
 if (idx >= head->itemCount) return -1;
 return idx + head->empty;
}

void ZListSetType(Tl* head, Tt *itemType) {
 head->itemType = itemType;
 if (itemType == NULL) ZthrowCstringNil("Creating list without type");
 switch (itemType->nr) {
  case 0:
  case 10:
  case 80:
  case 82:
  case 83:
  case 24:
  case 25:
   head->itemSize = 8; break;
  case 1:
  case 11:
   head->itemSize = 1; break;
  case 12:
  case 2:
   head->itemSize = 2; break;
  case 3:
  case 13:
  case 81:
   head->itemSize = 4; break;
  case 21:
  case 22:
  case 23:
   head->itemSize = sizeof(int); break;
  case 391:
   head->itemSize = sizeof(Tr); break;
  default:
   head->itemSize = sizeof(void*); break;
 }
}

Tl *ZnewList(Tt *itemType, Ti size) {
 int alloc = size > ((itemType->nr == 1 || itemType->nr == 11) ? 64 : 8);
 int extraSize = itemType != NULL && itemType->nr == 391 ? 8 * sizeof(Tr) : 64;
 Tl *head = Za(sizeof(Tl) + (alloc ? 0 : extraSize));
 ZListSetType(head, itemType);
 if (alloc) {
  head->items = ZaOff(head->itemSize * size);
  head->space = size;
 } else {
  head->items = (void**)(head + 1);
  head->space = extraSize / head->itemSize;
 }
 return head;
}
void ZListitemToString(Tl *head, int useq, Ti n, Tg *ga) {
 switch (head->itemType->nr) {
  case 0:
  case 10:
  case 24:
  case 25:
   ZitemToString(head->itemType, useq, (Tz)((Ti*)head->items)[n], ga);
   break;
  case 1:
  case 11:
   ZitemToString(head->itemType, useq, (Tz)(Ti)((char*)head->items)[n], ga);
   break;
  case 12:
  case 2:
   ZitemToString(head->itemType, useq, (Tz)(Ti)((Ti16*)head->items)[n], ga);
   break;
  case 3:
  case 13:
   ZitemToString(head->itemType, useq, (Tz)(Ti)((Ti32*)head->items)[n], ga);
   break;
  case 21:
  case 22:
  case 23:
   ZitemToString(head->itemType, useq, (Tz)(Ti)((int*)head->items)[n], ga);
   break;
  case 80:
  case 82:
  case 83:
   ZitemToString(head->itemType, useq, (Tz)((Tf*)head->items)[n], ga);
   break;
  case 81:
   ZitemToString(head->itemType, useq, (Tz)(Tf)((Tf32*)head->items)[n], ga);
   break;
  case 391:
   {
    Tr *tr = (Tr*)head->items + n;
    ZitemToString((Tt*)(tr->table[0]), useq, (Tz)tr->ptr, ga);
    break;
   }
  default:
   ZitemToString(head->itemType, useq, (Tz)head->items[n], ga);
   break;
 }
}

void ZListToStringGa(Tl *head, int useq, Tg *ga) {
 Ti n = head->empty;
 Ti tot = head->empty + head->itemCount;
 int itemType = head->itemType->nr;
 Tn *e = (&Zenv);
 ga_append(ga, "[");
 if (head->itemCount) {
  if (head->tosNr == e->tosNr) {
   ga_append(ga, "recursive-list");
  } else {
   head->tosNr = e->tosNr;
   for (;;) {
    ZListitemToString(head, useq, n, ga);
    if (++n == tot) break;
    ga_append(ga, ", ");
   }
   head->tosNr = 0;
  }
 }
 ga_append(ga, "]");
}

Tc *ZListToString(Tl *head, int useq) {
 Tg ga;
 Tc *r;
 if (head == NULL) return (Tc*)&ZNilString;
 ++(&Zenv)->tosNr;
 ga.data = NULL;
 ga.used = 0;
 ZListToStringGa(head, useq, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree(ga.data - ZOH_OFF);
 return r;
}

void ZListGrow(Tl *head, Ti count) {
 Ti newsize = head->empty + head->itemCount + count;
 if (newsize <= head->space) return;
 if (newsize < 100) {
  newsize += (newsize >> 2) + 7;
 } else {
  newsize += newsize >> 3;
 }
 if (head->items == (void**)(head + 1)) {
  head->items = ZaOff(head->itemSize * newsize);
  memmove(head->items, head + 1, head->itemSize * head->itemCount);
 } else {
  head->items = ZranOff(head->items, head->itemSize * head->space, head->itemSize * newsize);
 }
 head->space = newsize;
}

Tl *ZLa(Tl *head, Ti after, Tz val) {
 Ti nAfter;
 Ti idx;
 Ti len;
 if (head == NULL) ZthrowCstringNil("Attempt to append to NIL list");
 ZListGrow(head, 1);
 if (after < 0) {
  nAfter = head->itemCount + after;
  if (nAfter < 0) nAfter = -1;
 } else {
  nAfter = after;
  if (nAfter >= head->itemCount) nAfter = head->itemCount - 1;
 }
 idx = nAfter + head->empty + 1;
 len = head->itemCount - nAfter - 1;
 switch (head->itemType->nr) {
  case 0:
  case 10:
  case 24:
  case 25:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti*)head->items) + idx + 1, ((Ti*)head->items) + idx, head->itemSize * len);
   ((Ti*)head->items)[idx] = val.ival;
   break;
  case 1:
  case 11:
   if (len > 0 && idx >= head->empty)
    memmove(((char*)head->items) + idx + 1, ((char*)head->items) + idx, head->itemSize * len);
   ((char*)head->items)[idx] = val.ival;
   break;
  case 12:
  case 2:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti16*)head->items) + idx + 1, ((Ti16*)head->items) + idx, head->itemSize * len);
   ((Ti16*)head->items)[idx] = val.ival;
   break;
  case 3:
  case 13:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti32*)head->items) + idx + 1, ((Ti32*)head->items) + idx, head->itemSize * len);
   ((Ti32*)head->items)[idx] = val.ival;
   break;
  case 21:
  case 22:
  case 23:
   if (len > 0 && idx >= head->empty)
    memmove(((int*)head->items) + idx + 1, ((int*)head->items) + idx, head->itemSize * len);
   ((int*)head->items)[idx] = val.ival;
   break;
  case 80:
  case 82:
  case 83:
   if (len > 0 && idx >= head->empty)
    memmove(((Tf*)head->items) + idx + 1, ((Tf*)head->items) + idx, head->itemSize * len);
   ((Tf*)head->items)[idx] = val.fval;
   break;
  case 81:
   if (len > 0 && idx >= head->empty)
    memmove(((Tf32*)head->items) + idx + 1, ((Tf32*)head->items) + idx, head->itemSize * len);
   ((Tf32*)head->items)[idx] = val.fval;
   break;
  default:
   if (len > 0 && idx >= head->empty)
    memmove(head->items + idx + 1, head->items + idx, head->itemSize * len);
   head->items[idx] = val.ptr;
   break;
 }
 ++head->itemCount;
 return head;
}
Tl *ZLap(Tl *head, Tz val) {
 return ZLa(head, -1, val);
}

Tl *ZLaIobj(Tl *head, Ti after, Tr val) {
 Ti nAfter;
 Ti idx;
 Ti len;
 if (head == NULL) ZthrowCstringNil("Attempt to append to NIL list");
 ZListGrow(head, 1);
 if (after < 0) {
  nAfter = head->itemCount + after;
  if (nAfter < 0) nAfter = -1;
 } else {
  nAfter = after;
  if (nAfter >= head->itemCount) nAfter = head->itemCount - 1;
 }
 idx = nAfter + head->empty + 1;
 len = head->itemCount - nAfter - 1;
 if (len > 0 && idx >= head->empty)
  memmove((Tr*)head->items + idx + 1, (Tr*)head->items + idx, head->itemSize * len);
 ((Tr*)head->items)[idx] = val;
 ++head->itemCount;
 return head;
}
Tl *ZLapIobj(Tl *head, Tr val) {
 return ZLaIobj(head, -1, val);
}
Ti ZListSize(Tl *head) {
 if (head == NULL) return 0;
 return head->itemCount;
}

Ti ZListGetInt(Tl *head, Ti idx) {
 Ti r;
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  switch (head->itemType->nr) {
   case 0:
   case 24:
   case 25:
    r = ((Ti*)head->items)[n]; break;
   case 10:
    r = (Ti)((Tu*)head->items)[n]; break;
   case 1:
    r = ((char*)head->items)[n]; break;
   case 11:
    r = (Ti)((Tc*)head->items)[n]; break;
   case 2:
    r = ((Ti16*)head->items)[n]; break;
   case 12:
    r = (Ti)((Tu16*)head->items)[n]; break;
   case 3:
    r = ((Ti32*)head->items)[n]; break;
   case 13:
    r = (Ti)((Tu32*)head->items)[n]; break;
   case 21:
   case 22:
   case 23:
    r = ((int*)head->items)[n]; break;
  }
 } else r = 0;
 return r;
}

Tf ZListGetFloat(Tl *head, Ti idx) {
 Tf r;
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  switch (head->itemType->nr) {
   case 80:
   case 82:
   case 83:
    r = ((Tf*)head->items)[n]; break;
   case 81:
    r = (Tf)((Tf32*)head->items)[n]; break;
  }
 } else r = 0;
 return r;
}

void *ZListGetPtr(Tl *head, Ti idx) {
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) return head->items[n];
 return NULL;
}

Ti ZListRemoveIntItem(Tl *head, Ti idx) {
 Ti r = 0;
 if (head == NULL) ZthrowCstringNil("Invoking remove() on NIL list");
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  Ti len = head->itemCount - (n - head->empty) - 1;
  switch (head->itemType->nr) {
   case 0:
   case 10:
   case 24:
   case 25:
    r = ((Ti*)head->items)[n]; break;
   case 1:
   case 11:
    r = ((char*)head->items)[n]; break;
   case 12:
   case 2:
    r = ((Ti16*)head->items)[n]; break;
   case 3:
   case 13:
    r = ((Ti32*)head->items)[n]; break;
   case 21:
   case 22:
   case 23:
    r = ((int*)head->items)[n]; break;
  }
  if (len > 0)
   memmove((char*)head->items + n * head->itemSize, (char*)head->items + (n + 1) * head->itemSize, len * head->itemSize);
  head->itemCount--;
  // ZListShrink(head);
 }
 return r;
}

void *ZListRemovePtrItem(Tl *head, Ti idx) {
 void *r = NULL;
 if (head == NULL) ZthrowCstringNil("Invoking remove() on NIL list");
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  Ti len = head->itemCount - (n - head->empty) - 1;
  r = head->items[n];
  if (len > 0)
   memmove(head->items + n, head->items + n + 1, len * sizeof(void*));
  head->itemCount--;
  // ZListShrink(head);
 }
 return r;
}

static int stringCmp(const void *p1, const void *p2) {
 Tc *p1p;
 Tc *p2p;
 Ti len1 = ZstringSizePtr(*(Tc **)p1, &p1p);
 Ti len2 = ZstringSizePtr(*(Tc **)p2, &p2p);
 size_t len = len1 < len2 ? len1 : len2;
 int r = memcmp(p1p, p2p, len);
 if (r == 0) return len1 - len2;
 return r;
}
static int stringCmpR(const void *p1, const void *p2) {
 Tc *p1p;
 Tc *p2p;
 Ti len1 = ZstringSizePtr(*(Tc **)p1, &p1p);
 Ti len2 = ZstringSizePtr(*(Tc **)p2, &p2p);
 size_t len = len1 < len2 ? len1 : len2;
 int r = memcmp(p2p, p1p, len);
 if (r == 0) return len2 - len1;
 return r;
}
Tl *ZstringListSort(Tl *head, int asc) {
 int i = 0;
 if (head == NULL) ZthrowCstringNil("Invoking sort() on NIL list");
 qsort(head->items + head->empty, head->itemCount, sizeof(Tc*), asc ? stringCmp : stringCmpR);
 return head;
}

int ZforListIntCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(Ti*)tfl->valp = ZListGetInt(l, i);
 ++tfl->i;
 return 1;
}

int ZforListPtrCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(char**)tfl->valp = l->items[i + l->empty];
 ++tfl->i;
 return 1;
}

int ZDeqNr(Tz *l, Tz *r) {
 return l->ival == r->ival;
}
int ZDeqFloat(Tz *l, Tz *r) {
 return l->fval == r->fval;
}
int ZDeqStr(Tz *l, Tz *r) {
 Tc *p1;
 Tc *p2;
 Ti len1;
 Ti len2;
 if (r->ptr != NULL) {
  len1 = ZstringSizePtr(l->ptr, &p1);
  len2 = ZstringSizePtr(r->ptr, &p2);
  if (len1 == len2) return memcmp(p1, p2, len1) == 0;
 }
 return 0;
}
int ZDeqRef(Tz *l, Tz *r) {
 return l->ptr == r->ptr;
}
int ZDeqIobj(Tr *l, Tz *r) {
 return l->ptr == ((Tr*)r->ptr)->ptr;
}

Td *ZDictHead(Td *d, Tt *keyType, Tt *itemType, Tb ordered) {
 d->array = d->smallArray;
 d->mask = HT_INIT_SIZE - 1;
 d->keyType = keyType;
 d->itemType = itemType;
 if (itemType == NULL) ZthrowCstringNil("Creating dict without item type");
 if (keyType == NULL) ZthrowCstringNil("Creating dict without key type");
 if (ordered) d->type = DTYPE_ORDERED;
 if (keyType->nr < 80) d->eqfunc = (int (*)(void*, Tz*))ZDeqNr;
 else if (keyType->nr < 100) d->eqfunc = (int (*)(void*, Tz*))ZDeqFloat;
 else if (keyType == &iobj__T) d->eqfunc = (int (*)(void*, Tz*))ZDeqIobj;
 else if (keyType == &string__T || keyType == &byteString__T) d->eqfunc = (int (*)(void*, Tz*))ZDeqStr;
 else d->eqfunc = (int (*)(void*, Tz*))ZDeqRef;
 return d;
}
Td *ZDictInit(Td *d, Tt *keyType, Tt *itemType, Tb ordered) {
 memset(d, 0, sizeof(Td));
 ZDictHead(d, keyType, itemType, ordered);
 return d;
}
Td *ZnewDict(Tt *keyType, Tt *itemType, Tb ordered) {
 return ZDictHead(Za(sizeof(Td)), keyType, itemType, ordered);
}

Zhashtype ZDictHash(Tt *keyType, Tz key) {
 Zhashtype hash;
 void *ptr;
 if (keyType->nr < 80) return (Zhashtype)key.ival;
 if (keyType->nr < 100) return (Zhashtype)key.fval;
 if (keyType == &iobj__T) {
  ptr = ((Tr*)key.ptr)->ptr;
 } else {
  ptr = key.ptr;
 }
 if (ptr == NULL) ZthrowCstringNil("dict key is NIL");
 if (keyType == &string__T || keyType == &byteString__T) {
  Tc *p;
  int l = ZstringSizePtr(key.ptr, &p);
  if (l == 0) {
   hash = 0;
  } else {
   hash = *p;
   while (--l > 0) {
    hash = hash * 101 + *++p;
   }
  }
 } else {
  Tip k = (Tip)ptr;
  int l = sizeof(Tc*);
  hash = k & 0xff;
  while (--l > 0) {
   k >>= 8;
   hash = hash * 101 + (k & 0xff);
  }
 }
 return hash;
}

void ZthrowIntKeyNotFound(Tz key, Tc *msg) {
  Yxmk(key.ival, msg);
}

void ZthrowStringKeyNotFound(Tz key, Tc *msg) {
  Y5LT(key.ptr, msg);
}

void ZthrowIntKeyExists(Tz key, Tc *msg) {
  YL9Z(key.ival, msg);
}
void ZthrowStringKeyExists(Tz key, Tc *msg) {
  YEeX(key.ptr, msg);
}

/* #define DICT_DEBUG 1 */

CDictItem *ZDictLookup(Td *d, Tz key, Zhashtype hash)
{
 Zhashtype  perturb;
 CDictItem  *freeitem;
 int        idx = (int)(hash & d->mask);
 CDictItem  *di = &d->array[idx];
 if (di->flags == 0) return di;
 if (di->flags == CDI_FLAG_DEL) freeitem = di;
 else if (di->hash == hash && d->keyType == &iobj__T ? d->eqfunc(&di->iokey, &key) : d->eqfunc(&di->key, &key)) {
  return di;
 } else {
  freeitem = NULL;
 }

 for (perturb = hash; ; perturb >>= PERTURB_SHIFT)
 {
  idx = (int)((idx << 2) + idx + perturb + 1);
  di = &d->array[idx & d->mask];
  if (di->flags == 0) return freeitem == NULL ? di : freeitem;
  if (di->hash == hash && di->flags != CDI_FLAG_DEL && d->keyType == &iobj__T ? d->eqfunc(&di->iokey, &key) : d->eqfunc(&di->key, &key)) return di;
  if (di->flags == CDI_FLAG_DEL && freeitem == NULL) freeitem = di;
 }
}

void ZDictResize(Td *d, int minitems) {
 CDictItem temparray[HT_INIT_SIZE];
 CDictItem *oldarray, *newarray;
 CDictItem *olditem, *newitem, *nextitem;
 int newi;
 int todo;
 Zhashtype oldsize, newsize;
 Zhashtype minsize;
 Zhashtype newmask;
 Zhashtype perturb;

#ifdef DICT_DEBUG
 printf("size: %lu, filled: %lu, used: %lu\n",
           d->mask + 1, d->filled, d->used);
#endif

 if (minitems == 0) {
  if (d->filled < HT_INIT_SIZE - 1 && d->array == d->smallArray) {
#ifdef DICT_DEBUG
   printf("small array not full\n");
#endif
   return;
  }
  oldsize = d->mask + 1;
  if (d->filled * 3 < oldsize * 2 && d->used > oldsize / 5) {
#ifdef DICT_DEBUG
   printf("size OK\n");
#endif
   return;
  }
  if (d->used > 1000) minsize = d->used * 2;
  else minsize = d->used * 4;
 } else {
  if ((Zhashtype)minitems < d->used) minitems = (int)d->used;
  minsize = minitems * 3 / 2;
 }

 newsize = HT_INIT_SIZE;
 while (newsize < minsize) {
  newsize <<= 1;
  if (newsize == 0) {
   ZthrowInternal(Zstr("ZDictResize"));
   return;
  }
 }

#ifdef DICT_DEBUG
 printf("resizing from %lu to %lu\n", d->mask + 1, newsize);
#endif

 if (newsize == HT_INIT_SIZE) {
  newarray = d->smallArray;
  if (d->array == newarray) {
   memmove(temparray, newarray, sizeof(temparray));
   oldarray = temparray;
  } else
   oldarray = d->array;
  memset(newarray, 0, (size_t)(sizeof(CDictItem) * newsize));
 } else {
  newarray = (CDictItem *)ZaOff((sizeof(CDictItem) * newsize));
  oldarray = d->array;
 }

 newmask = newsize - 1;
 todo = (int)d->used;
 for (olditem = oldarray; todo > 0; ++olditem)
  if (olditem->flags & CDI_FLAG_USED) {
   newi = (int)(olditem->hash & newmask);
   newitem = &newarray[newi];
   if (newitem->flags != 0)
    for (perturb = olditem->hash; ; perturb >>= PERTURB_SHIFT) {
     newi = (int)((newi << 2) + newi + perturb + 1);
     newitem = &newarray[newi & newmask];
     if (newitem->flags == 0) break;
    }
   *newitem = *olditem;
   if (d->type & DTYPE_ORDERED) {
    olditem->lprev = newitem;
   }
   --todo;
  }
 if ((d->type & DTYPE_ORDERED) && d->first) {
  olditem = d->first;
  newitem = olditem->lprev;
  newitem->lprev = NULL;
  d->first = newitem;
  while (olditem->lnext) {
   olditem = olditem->lnext;
   nextitem = olditem->lprev;
   newitem->lnext = nextitem;
   newitem->lnext->lprev = newitem;
   newitem = nextitem;
  }
  newitem->lnext = NULL;
  d->last = newitem;
 }

 if (d->array != d->smallArray) Zfree((void*)d->array - ZOH_OFF);
 d->array = newarray;
 d->mask = newmask;
 d->filled = d->used;
}

/* "ow" is the overwrite flag.  When zero it's not allowed to overwrite an
 * existing entry. */
Td *ZDictAdd(int ow, Td *d, Tz key, Tz value) {
 Zhashtype hash = ZDictHash(d->keyType, key);
 CDictItem *di = ZDictLookup(d, key, hash);
#ifdef DICT_DEBUG
 if (d->keyType->nr >= 100)
   printf("Adding item %s\n", (Tc*)key.ptr);
 else
   printf("Adding item %lld\n", key.ival);
 if (key.ptr != NULL
     && (strcmp(key.ptr, "ENUM") == 0
         || strcmp(key.ptr, "Equal") == 0
         || strcmp(key.ptr, "EXIT") == 0))
   dumpdict(d);
#endif
 if (di->flags == 0 || di->flags == CDI_FLAG_DEL || ow) {
  if (di->flags == 0 || di->flags == CDI_FLAG_DEL) {
   ++d->used;
   if (di->flags == 0)
    ++d->filled;
  }
  di->hash = hash;
  if (d->keyType->nr == 391) {
   di->iokey = *(Tr*)key.ptr;
  } else if (d->keyType->nr >= 100) {
   if (di->flags == 0 || di->flags == CDI_FLAG_DEL) {
    di->key = key;
   }
  } else di->key = key;
  if (d->itemType->nr == 391)
   di->ioitem = *(Tr*)value.ptr;
  else
   di->item = value;
  di->flags = CDI_FLAG_USED;
  if (d->type & DTYPE_ORDERED) {
   di->lprev = d->last;
   if (d->last) d->last->lnext = di;
   else d->first = di;
   d->last = di;
   di->lnext = NULL;
  }

  ZDictResize(d, 0);
 } else {
  if (d->keyType->nr >= 100) ZthrowStringKeyExists(key, Zstr("dict.add(): "));
  ZthrowIntKeyExists(key, Zstr("dict.add(): "));
 }
 return d;
}
Td *ZDictAddIobjTz(int ow, Td *d, Tr key, Tz value) {
 return ZDictAdd(ow, d, (Tz)(void*)&key, value);
}
Td *ZDictAddTzIobj(int ow, Td *d, Tz key, Tr value) {
 return ZDictAdd(ow, d, key, (Tz)(void*)&value);
}
Td *ZDictAddIobjIobj(int ow, Td *d, Tr key, Tr value) {
 return ZDictAdd(ow, d, (Tz)(void*)&key, (Tz)(void*)&value);
}

#ifdef DICT_DEBUG
dumpdict(Td *d)
{
 int        todo = (int)d->used;
 CDictItem  *item;
 int        idx = 0;

 for (item = d->array; todo > 0; ++item) {
  if (item->flags & CDI_FLAG_USED) {
   printf("%2d: %s\n", idx, (Tc*)item->key.ptr);
   --todo;
  } else if (item->flags == 0) {
   printf("%2d: unused\n", idx);
  } else if (item->flags == CDI_FLAG_DEL) {
   printf("%2d: deleted\n", idx);
  } else {
   printf("%2d: invalid flags: %d\n", idx, item->flags);
  }
  ++idx;
 }
}
#endif


CDictItem *ZDictFind(Td *d, Tz key) {
 Zhashtype  hash = ZDictHash(d->keyType, key);
 CDictItem  *di = ZDictLookup(d, key, hash);
 if (di->flags & CDI_FLAG_USED) return di;
 return NULL;
}

Tr *ZDictGetIobjP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  static Tr dummy = {0, 0, 0};
  ZDictAdd(1, d, key, (Tz)(void*)&dummy);
  di = ZDictFind(d, key);
 }
 return &di->ioitem;
}

Tr ZDictGetIobj(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->ioitem;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return trZero;
}

Tr ZDictGetIobjDef(Td *d, Tz key, Tr def) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) return di->ioitem;
 return def;
}

void *ZDictGetPtr(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->item.ptr;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return NULL;
}

Ti *ZDictGetIntP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  ZDictAdd(1, d, key, (Tz)(Ti)0);
  di = ZDictFind(d, key);
 }
 return &di->item.ival;
}

Ti ZDictGetInt(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->item.ival;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return 0;
}

Tb ZDictHas(Td *d, Tz key) {
 return (ZDictFind(d, key) != NULL);
}
Tb ZDictHasIobj(Td *d, Tr key) {
 return (ZDictFind(d, (Tz)(void*)&key) != NULL);
}
void ZDiToString(Td *d, int keyUseq, int itemUseq, CDictItem *di, Tg *ga) {
 if (d->keyType == &iobj__T)
  ZitemToString((Tt*)(di->iokey.table[0]), keyUseq, (Tz)di->iokey.ptr, ga);
 else
  ZitemToString(d->keyType, keyUseq, di->key, ga);
 ga_append(ga, ": ");
 if (d->itemType == &iobj__T)
  ZitemToString((Tt*)(di->ioitem.table[0]), keyUseq, (Tz)di->ioitem.ptr, ga);
 else
  ZitemToString(d->itemType, itemUseq, di->item, ga);
}

void ZDictToStringGa(Td *d, int keyUseq, int itemUseq, Tg *ga) {
 int first = 1;
 int todo = d->used;
 Tn *e = (&Zenv);
 CDictItem *di;
 ga_append(ga, "[");
 if (todo == 0) {
  ga_append(ga, ":");  /* empty dictionary: [:] */
 } else if (e->tosNr == d->tosNr) {
  ga_append(ga, "recursive-dict");
 } else {
  d->tosNr = e->tosNr;
  if (d->type & DTYPE_ORDERED) {
   for (di = d->first; di; di = di->lnext) {
    if (first == 0) ga_append(ga, ", "); else first = 0;
    ZDiToString(d, keyUseq, itemUseq, di, ga);
   }
  } else {
   for (di = d->array; todo > 0; ++di) {
    if (di->flags & CDI_FLAG_USED) {
     --todo;
     if (first == 0) ga_append(ga, ", "); else first = 0;
     ZDiToString(d, keyUseq, itemUseq,di, ga);
    }
   }
  }
  d->tosNr = 0;
 }
 ga_append(ga, "]");
}

Tc *ZDictToString(Td *d, int keyUseq, int itemUseq) {
 Tg ga;
 Tc *r;
 if (d == NULL) return (Tc*)&ZNilString;
 ++(&Zenv)->tosNr;
 ga.data = NULL;
 ga.used = 0;
 ZDictToStringGa(d, keyUseq, itemUseq, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree((void*)ga.data - ZOH_OFF);
 return r;
}

Tl *ZDictKeys(Td *d, int dn) {
 Tl *l;
 int todo;
 CDictItem *di;
 if (d == NULL) {
  if (dn) return NULL;
  ZthrowCstringNil("Invoking keys() on NIL dict");
 }
 l = ZnewList(d->keyType, d->used);
 if (d->type & DTYPE_ORDERED) {
  if (d->keyType == &iobj__T)
   for (di = d->first; di; di = di->lnext) {
    ZLaIobj(l, -1, di->iokey);
   }
  else
   for (di = d->first; di; di = di->lnext) {
    ZLa(l, -1, di->key);
   }
 } else {
  todo = d->used;
  for (di = d->array; todo > 0; ++di) {
   if (di->flags & CDI_FLAG_USED) {
    --todo;
    if (d->keyType == &iobj__T)
     ZLaIobj(l, -1, di->iokey);
    else
     ZLa(l, -1, di->key);
   }
  }
 }
 return l;
}

void ZforDictGet(Tfd *tfd) {
 Td *d = tfd->d;
 CDictItem *di = tfd->di;
 if (di) {
  if (tfd->keyp) {
   if (d->keyType == &iobj__T)
    *(Tr*)tfd->keyp = di->iokey;
   else if (d->keyType->nr < 80)
    *(Ti*)tfd->keyp = di->key.ival;
   else if (d->keyType->nr < 100)
    *(Tf*)tfd->keyp = di->key.fval;
   else
    *(char**)tfd->keyp = di->key.ptr;
  }
  if (d->itemType == &iobj__T)
   *(Tr*)tfd->valp = di->ioitem;
  else if (d->itemType->nr < 80)
   *(Ti*)tfd->valp = di->item.ival;
  else if (d->itemType->nr < 100)
   *(Tf*)tfd->valp = di->item.fval;
  else
   *(char**)tfd->valp = di->item.ptr;
 }
}

void ZforDictStart(Tfd *tfd) {
 Td *d = tfd->d;
 if (d != NULL && d->used) {
  if (d->type & DTYPE_ORDERED) {
   tfd->di = d->first;
  } else {
   CDictItem *di = d->array;
   while ((di->flags & CDI_FLAG_USED) == 0) ++di;
   tfd->di = di;
   tfd->todo = d->used - 1;
  }
  ZforDictGet(tfd);
 } else {
  tfd->di = NULL;
 }
}

int ZforDictCont(Tfd *tfd) {
 return tfd->di != NULL;
}

void ZforDictNext(Tfd *tfd) {
 Td *d = tfd->d;
 if (d->type & DTYPE_ORDERED) {
  tfd->di = tfd->di->lnext;
 } else if (tfd->todo > 0) {
  CDictItem *di = tfd->di + 1;
  while ((di->flags & CDI_FLAG_USED) == 0) ++di;
  tfd->di = di;
  --tfd->todo;
 } else {
  tfd->di = NULL;
 }
 ZforDictGet(tfd);
}


Ti ZDictSize(Td *d) {
 if (d == NULL) return 0;
 return d->used;
}

Tcode *ZtableIndex(Ti pos100) {
 Ti pos = pos100 / 100;
 int l = 0;
 int h = sizeof(ZcodeTable)/sizeof(Tcode) - 1;
 int m;
 while (l <= h) {
  m = (l + h) / 2;
  if (ZcodeTable[m].offset == pos) break;
  if (ZcodeTable[m].offset < pos) l = m + 1;
  else h = m - 1;
 }
 return &ZcodeTable[m];
}
YkxB *MZ__callerPos(void) {
 Tcode *p;
 Zsf *tf = topFrame;
 if (tf == NULL) return NULL;
 tf = tf->prev == NULL ? tf : tf->prev;
 while (1) {
  if (tf == NULL) return NULL;
  if (tf->pos & POS_MASK) {
   p = ZtableIndex(tf->pos & POS_MASK);
   if (p->fileName) {
    return MZ__posnr2pos(NULL, tf->pos & POS_MASK);
   }
  }
  tf = tf->prev;
 }
}

Tl *MZ__backtrace(Ti skip, Ti limit) {
 Tl *head = ZnewList((Tt*)&YkxB__T, 0);
 int done = 0;
 Zsf *tf = topFrame;
 if (skip > 0) {
  int i;
  for (i = 0; i < skip && tf != NULL; ++i) tf = tf->prev;
 }
 while (tf != NULL) {
  if (tf->pos & POS_MASK) {
   YkxB *item = Za(sizeof(YkxB));
   if (limit >= 0 && done >= limit) {
    item->Vfilename = Zstr("truncated");
    ZLa(head, -1, (Tz)(void*)item);
    break;
   }
   MZ__posnr2pos(item, tf->pos & POS_MASK);
   ZLa(head, -1, (Tz)(void*)item);
   ++done;
  }
  tf = tf->prev;
 }
 return head;
}

YkxB *MZ__posnr2pos(YkxB *t, Ti pos) {
 int i;
 Tcode *p;
 Tcpos *pp;
 if (t == NULL) t = Za(sizeof(YkxB));
 p = ZtableIndex(pos);
 i = pos - p->offset * 100;
 pp = &p->table[i];
 t->Vfilename = Zstr((char*)p->fileName);
 t->Vtext = Zstr((char*)p->methodName);
 t->Vlnum = pp->line;
 if (i) t->Vlnum += p->table[0].line;
 t->Vcol = pp->col;
 return t;
}
/*
 * FUNCTION BODIES
 */
/* including TIMEModule bodies */
Ti Y9Rj() {
 Ti Vusec;
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vusec = 0;
 sf.pos=5084100;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    Vusec = (Ti)tv.tv_sec * 1000000 + (Ti)tv.tv_usec;
 sf.pos=5084101;
 r = Vusec;
 topFrame = sf.prev;
 return r;
}
Y2KX *YgaY(Y2KX *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=534200; t = Za(sizeof(Y2KX));}
 sf.pos=534201;
 YgaYb(t, Y9Rj());
 topFrame = sf.prev;
 return t;
}
Y2KX *YgaYb(Y2KX *t, Ti Ausec) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3293900; t = Za(sizeof(Y2KX));}
 sf.pos=3293901;
  time_t tt = Ausec / 1000000;
  struct tm tms;
  struct tm *tmsp;
#ifdef __MINGW32__
  tmsp = localtime(&tt);
  if (tmsp) tms = *tmsp;
#else
  localtime_r(&tt, &tms);
#endif
  t->Vsec = tms.tm_sec;
  t->Vmin = tms.tm_min;
  t->Vhour = tms.tm_hour;
  t->Vday = tms.tm_mday;
  t->Vmonth = tms.tm_mon + 1;
  t->Vyear = tms.tm_year + 1900;
  t->VweekDay = tms.tm_wday + 1;
  t->VyearDay = tms.tm_yday + 1;
  if (tms.tm_isdst > 0) t->Vdst = 2;
  else if (tms.tm_isdst == 0) t->Vdst = 1;
 sf.pos=3293902;
 t->Vusec = (Ausec % 1000000);
 topFrame = sf.prev;
 return t;
}
Tc *YYTs(Y2KX *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3481800;
  ZthrowThisNil();
 }
 sf.pos=3481801;
 Vw = Za(sizeof(YjUM));
 sf.pos=3481802;
 YjUM__YHhZb(Vw, t->Vyear);
 sf.pos=3481803;
 YJqza(Vw, ((Tc*)&YV));
 sf.pos=3481804;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vmonth));
 sf.pos=3481805;
 YJqza(Vw, ((Tc*)&YV));
 sf.pos=3481806;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vday));
 sf.pos=3481807;
 YJqza(Vw, ((Tc*)&YG));
 sf.pos=3481808;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vhour));
 sf.pos=3481809;
 YJqza(Vw, ((Tc*)&Y5));
 sf.pos=3481810;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vmin));
 sf.pos=3481811;
 YJqza(Vw, ((Tc*)&Y5));
 sf.pos=3481812;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vsec));
 sf.pos=3481813;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
To ToY2KX[] = {
 {10, 0},
 {0, (Tt*)&int__T}, /* usec */
 {0, (Tt*)&int__T}, /* sec */
 {0, (Tt*)&int__T}, /* min */
 {0, (Tt*)&int__T}, /* hour */
 {0, (Tt*)&int__T}, /* day */
 {0, (Tt*)&int__T}, /* month */
 {0, (Tt*)&int__T}, /* year */
 {0, (Tt*)&int__T}, /* weekDay */
 {0, (Tt*)&int__T}, /* yearDay */
 {0, (Tt*)&MTIMEModule__EDst__T}, /* dst */
};
char *StrY2KX[] = {
 "usec",
 "sec",
 "min",
 "hour",
 "day",
 "month",
 "year",
 "weekDay",
 "yearDay",
 "dst",
};
Tto Y2KX__T = {390, (Tc*)&YeCO, YYTs, StrY2KX, ToY2KX};
/* TIMEModule done */
/* including EModule bodies */
Tc *YH0V(Ytlm *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5153500;
  ZthrowThisNil();
 }
 sf.pos=5153501;
 Vw = Za(sizeof(YjUM));
 sf.pos=5153502;
 YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5153503;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YxaJ(Ytlm *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4918300;
  ZthrowThisNil();
 }
 sf.pos=4918301;
 if ((t->Vpos != NULL))
 {
  sf.pos=4918302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4918303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4918304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4918305;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4918306;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4918307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3649100;
  ZthrowThisNil();
 }
 sf.pos=3649101;
 YxaJ(t, Aw);
 sf.pos=3649102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=3649103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3649104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3649105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=3649106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=3649107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=3649108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3649109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=3649110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=3649111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3649112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
To ToYtlm[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYtlm[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Ytlm__T = {390, (Tc*)&YDGe, YH0V, StrYtlm, ToYtlm};
Tc *Ydtua(YEro *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1893400;
  ZthrowThisNil();
 }
 sf.pos=1893401;
 Vw = Za(sizeof(YjUM));
 sf.pos=1893402;
 YXHSa(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1893403;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YXHSa(YEro *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9216300;
  ZthrowThisNil();
 }
 sf.pos=9216301;
 if ((t->Vpos != NULL))
 {
  sf.pos=9216302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9216303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9216304;
 ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YxJ1));
 sf.pos=9216305;
 ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Zint2string(t->Vvalue));
 sf.pos=9216306;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9216307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
  sf.pos=9216308;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 topFrame = sf.prev;
 return;
}
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4298300;
  ZthrowThisNil();
 }
 sf.pos=4298301;
 YXHSa(t, Aw);
 sf.pos=4298302;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=4298303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4298304;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4298305;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=4298306;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=4298307;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=4298308;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4298309;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=4298310;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=4298311;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4298312;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
To ToYEro[] = {
 {4, 0},
 {0, (Tt*)&int__T}, /* value */
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYEro[] = {
 "value",
 "message",
 "pos",
 "backtrace",
};
Tto YEro__T = {390, (Tc*)&YJMo, Ydtua, StrYEro, ToYEro};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8064400; t = Za(sizeof(YKhn));}
 sf.pos=8064401;
 t->Vmessage = ZcS3(((Tc*)&YIBz), Zint2string(Asize), ((Tc*)&YDSH));
 sf.pos=8064402;
 t->Vpos = MZ__callerPos();
 sf.pos=8064403;
 t->Vbacktrace = (sf.pos=8064404, MZ__backtrace(1, Alimit));
 topFrame = sf.prev;
 return t;
}
Tc *YKhn__YwtA__YH0V(YKhn *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8669900;
  ZthrowThisNil();
 }
 sf.pos=8669901;
 Vw = Za(sizeof(YjUM));
 sf.pos=8669902;
 YKhn__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8669903;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1121700;
  ZthrowThisNil();
 }
 sf.pos=1121701;
 YKhn__YwtA__YxaJ(t, Aw);
 sf.pos=1121702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1121703;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=1121704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1121705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1121706;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1121707;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1121708;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=1121709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1121710;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1121711;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=1121712;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2141800;
  ZthrowThisNil();
 }
 sf.pos=2141801;
 if ((t->Vpos != NULL))
 {
  sf.pos=2141802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=2141803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=2141804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=2141805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=2141806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=2141807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YKhn__Ytlm_I_imt[] = {
 (Tc*)&YKhn__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHRa */
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHR */
 (Tc*)YKhn__YwtA__YH0V, /* MEModule__COutOfMemory.ToString - YKhn__YwtA__YH0V */
 (Tc*)YKhn__YwtA__YxaJa, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJa */
 (Tc*)YKhn__YwtA__YxaJ, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJ */
 (Tc*)0, /* MEModule__COutOfMemory.toString - YKhn__YwtA__Yoww */
 (Tc*)0, /* MEModule__COutOfMemory.getMessage - YKhn__YwtA__YCzX */
 (Tc*)0, /* MEModule__COutOfMemory.getPos - YKhn__YwtA__YvCK */
 (Tc*)0, /* MEModule__COutOfMemory.getBacktrace - YKhn__YwtA__Y4bq */
 (Tc*)0, /* Init - YKhna */
};
To ToYKhn[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYKhn[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YKhn__T = {390, (Tc*)&Y9Fv, YKhn__YwtA__YH0V, StrYKhn, ToYKhn};
void Y1KV(Ti Asize) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YDNob(NULL, Asize, 30), YKhn__Ytlm_I_imt, 4);
 ZthrowIobject(ex);
}
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3208600; t = Za(sizeof(Y1uN));}
 sf.pos=3208601;
 t->Vmessage = Amsg;
 sf.pos=3208602;
 t->Vpos = MZ__callerPos();
 sf.pos=3208603;
 t->Vbacktrace = (sf.pos=3208604, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Y1uN__YwtA__YH0V(Y1uN *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2685400;
  ZthrowThisNil();
 }
 sf.pos=2685401;
 Vw = Za(sizeof(YjUM));
 sf.pos=2685402;
 Y1uN__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=2685403;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3508800;
  ZthrowThisNil();
 }
 sf.pos=3508801;
 Y1uN__YwtA__YxaJ(t, Aw);
 sf.pos=3508802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=3508803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3508804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3508805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=3508806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=3508807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=3508808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3508809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=3508810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=3508811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3508812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4528900;
  ZthrowThisNil();
 }
 sf.pos=4528901;
 if ((t->Vpos != NULL))
 {
  sf.pos=4528902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4528903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4528904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4528905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4528906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4528907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *Y1uN__Ytlm_I_imt[] = {
 (Tc*)&Y1uN__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHRa */
 (Tc*)Y1uN__YwtA__YRHR, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHR */
 (Tc*)Y1uN__YwtA__YH0V, /* MEModule__CNilAccess.ToString - Y1uN__YwtA__YH0V */
 (Tc*)Y1uN__YwtA__YxaJa, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJa */
 (Tc*)Y1uN__YwtA__YxaJ, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CNilAccess.toString - Y1uN__YwtA__Yoww */
 (Tc*)0, /* MEModule__CNilAccess.getMessage - Y1uN__YwtA__YCzX */
 (Tc*)0, /* MEModule__CNilAccess.getPos - Y1uN__YwtA__YvCK */
 (Tc*)0, /* MEModule__CNilAccess.getBacktrace - Y1uN__YwtA__Y4bq */
 (Tc*)0, /* Init - Y1uNa */
};
To ToY1uN[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrY1uN[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Y1uN__T = {390, (Tc*)&Y4wO, Y1uN__YwtA__YH0V, StrY1uN, ToY1uN};
void YvdV(YkxB *Apos, Tc *Atext) {
 Tr ex;
 Y1uN *Ve = 0;
 Tr t0 = {NULL};
 Ve = Y1uN__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 *Znao(&ex, Ve, Y1uN__Ytlm_I_imt, 5);
 ZthrowIobject(ex);
}
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7358000; t = Za(sizeof(YAxe));}
 sf.pos=7358001;
 t->Vmessage = Amsg;
 sf.pos=7358002;
 t->Vpos = MZ__callerPos();
 sf.pos=7358003;
 t->Vbacktrace = (sf.pos=7358004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YAxe__YwtA__YH0V(YAxe *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6603600;
  ZthrowThisNil();
 }
 sf.pos=6603601;
 Vw = Za(sizeof(YjUM));
 sf.pos=6603602;
 YAxe__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6603603;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2595800;
  ZthrowThisNil();
 }
 sf.pos=2595801;
 YAxe__YwtA__YxaJ(t, Aw);
 sf.pos=2595802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2595803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2595804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2595805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2595806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2595807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2595808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2595809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2595810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2595811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2595812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3615900;
  ZthrowThisNil();
 }
 sf.pos=3615901;
 if ((t->Vpos != NULL))
 {
  sf.pos=3615902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=3615903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=3615904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=3615905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=3615906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=3615907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YAxe__Ytlm_I_imt[] = {
 (Tc*)&YAxe__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHRa */
 (Tc*)YAxe__YwtA__YRHR, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHR */
 (Tc*)YAxe__YwtA__YH0V, /* MEModule__CMemoryAccess.ToString - YAxe__YwtA__YH0V */
 (Tc*)YAxe__YwtA__YxaJa, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJa */
 (Tc*)YAxe__YwtA__YxaJ, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CMemoryAccess.toString - YAxe__YwtA__Yoww */
 (Tc*)0, /* MEModule__CMemoryAccess.getMessage - YAxe__YwtA__YCzX */
 (Tc*)0, /* MEModule__CMemoryAccess.getPos - YAxe__YwtA__YvCK */
 (Tc*)0, /* MEModule__CMemoryAccess.getBacktrace - YAxe__YwtA__Y4bq */
 (Tc*)0, /* Init - YAxea */
};
To ToYAxe[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYAxe[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YAxe__T = {390, (Tc*)&Y4QW, YAxe__YwtA__YH0V, StrYAxe, ToYAxe};
void YE93(Ti Anr) {
 Tr ex;
 Tr t0 = {NULL};
 if ((Anr == 11))
 {
  Tr ex;
  *Znao(&ex, YAxe__YwtA__YRHR(NULL, ((Tc*)&YkfG)), YAxe__Ytlm_I_imt, 6);
  ZthrowIobject(ex);
 }
 if ((Anr == 8))
 {
  Tr ex;
  *Znao(&ex, YzSI__Ylz1__YwtA__YRHR(NULL, ((Tc*)&YoEx)), YzSI__Ytlm_I_imt, 17);
  ZthrowIobject(ex);
 }
 if ((Anr == 7))
 {
  Tr ex;
  *Znao(&ex, YAxe__YwtA__YRHR(NULL, ((Tc*)&YQNH)), YAxe__Ytlm_I_imt, 6);
  ZthrowIobject(ex);
 }
 *Znao(&ex, YAxe__YwtA__YRHR(NULL, ZcS(((Tc*)&YpCZ), Zint2string(Anr))), YAxe__Ytlm_I_imt, 6);
 ZthrowIobject(ex);
}
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6357800; t = Za(sizeof(YVNj));}
 sf.pos=6357801;
 t->Vmessage = Amsg;
 sf.pos=6357802;
 t->Vpos = Apos;
 sf.pos=6357803;
 t->Vbacktrace = (sf.pos=6357804, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=5337700; t = Za(sizeof(YVNj));}
 sf.pos=5337701;
 t->Vmessage = Amsg;
 sf.pos=5337702;
 t->Vpos = MZ__callerPos();
 sf.pos=5337703;
 t->Vbacktrace = (sf.pos=5337704, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YVNj__YwtA__YH0V(YVNj *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8958100;
  ZthrowThisNil();
 }
 sf.pos=8958101;
 Vw = Za(sizeof(YjUM));
 sf.pos=8958102;
 YVNj__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8958103;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9610700;
  ZthrowThisNil();
 }
 sf.pos=9610701;
 YVNj__YwtA__YxaJ(t, Aw);
 sf.pos=9610702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=9610703;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=9610704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=9610705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=9610706;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=9610707;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=9610708;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=9610709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=9610710;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=9610711;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=9610712;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=630800;
  ZthrowThisNil();
 }
 sf.pos=630801;
 if ((t->Vpos != NULL))
 {
  sf.pos=630802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=630803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=630804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=630805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=630806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=630807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YVNj__Ytlm_I_imt[] = {
 (Tc*)&YVNj__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YVNj__YwtA__YRHRa, /* MEModule__CInit.NEW - YVNj__YwtA__YRHRa */
 (Tc*)YVNj__YwtA__YRHR, /* MEModule__CInit.NEW - YVNj__YwtA__YRHR */
 (Tc*)YVNj__YwtA__YH0V, /* MEModule__CInit.ToString - YVNj__YwtA__YH0V */
 (Tc*)YVNj__YwtA__YxaJa, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJa */
 (Tc*)YVNj__YwtA__YxaJ, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CInit.toString - YVNj__YwtA__Yoww */
 (Tc*)0, /* MEModule__CInit.getMessage - YVNj__YwtA__YCzX */
 (Tc*)0, /* MEModule__CInit.getPos - YVNj__YwtA__YvCK */
 (Tc*)0, /* MEModule__CInit.getBacktrace - YVNj__YwtA__Y4bq */
 (Tc*)0, /* Init - YVNja */
};
To ToYVNj[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYVNj[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YVNj__T = {390, (Tc*)&Ysqt, YVNj__YwtA__YH0V, StrYVNj, ToYVNj};
void Y3w6(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YVNj__YwtA__YRHR(NULL, Atext), YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6059300; t = Za(sizeof(Yalz));}
 sf.pos=6059301;
 t->Vmessage = Amsg;
 sf.pos=6059302;
 t->Vpos = MZ__callerPos();
 sf.pos=6059303;
 t->Vbacktrace = (sf.pos=6059304, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Yalz__YwtA__YH0V(Yalz *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5270100;
  ZthrowThisNil();
 }
 sf.pos=5270101;
 Vw = Za(sizeof(YjUM));
 sf.pos=5270102;
 Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5270103;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4617100;
  ZthrowThisNil();
 }
 sf.pos=4617101;
 Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=4617102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=4617103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4617104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4617105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=4617106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=4617107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=4617108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4617109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=4617110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=4617111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4617112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5637200;
  ZthrowThisNil();
 }
 sf.pos=5637201;
 if ((t->Vpos != NULL))
 {
  sf.pos=5637202;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=5637203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5637204;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=5637205;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=5637206;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=5637207;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *Yalz__Ytlm_I_imt[] = {
 (Tc*)&Yalz__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHRa */
 (Tc*)Yalz__YwtA__YRHR, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHR */
 (Tc*)Yalz__YwtA__YH0V, /* MEModule__CBadValue.ToString - Yalz__YwtA__YH0V */
 (Tc*)Yalz__YwtA__YxaJa, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJa */
 (Tc*)Yalz__YwtA__YxaJ, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CBadValue.toString - Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CBadValue.getMessage - Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CBadValue.getPos - Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CBadValue.getBacktrace - Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Yalza */
};
To ToYalz[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYalz[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Yalz__T = {390, (Tc*)&YEZq, Yalz__YwtA__YH0V, StrYalz, ToYalz};
void Yaez(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yalz__YwtA__YRHR(NULL, Atext), Yalz__Ytlm_I_imt, 10);
 ZthrowIobject(ex);
}
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=5638100; t = Za(sizeof(Yw3O));}
 sf.pos=5638101;
 t->Vmessage = Amsg;
 sf.pos=5638102;
 t->Vpos = MZ__callerPos();
 sf.pos=5638103;
 t->Vbacktrace = (sf.pos=5638104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Yw3O__Yalz__YwtA__YH0V(Yw3O *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3172900;
  ZthrowThisNil();
 }
 sf.pos=3172901;
 Vw = Za(sizeof(YjUM));
 sf.pos=3172902;
 Yw3O__Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=3172903;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5260800;
  ZthrowThisNil();
 }
 sf.pos=5260801;
 if ((t->Vpos != NULL))
 {
  sf.pos=5260802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=5260803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5260804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=5260805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=5260806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=5260807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6280900;
  ZthrowThisNil();
 }
 sf.pos=6280901;
 Yw3O__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=6280902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=6280903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=6280904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=6280905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=6280906;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=6280907;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=6280908;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=6280909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=6280910;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=6280911;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=6280912;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *Yw3O__Ytlm_I_imt[] = {
 (Tc*)&Yw3O__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHRa */
 (Tc*)Yw3O__Yalz__YwtA__YRHR, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHR */
 (Tc*)Yw3O__Yalz__YwtA__YH0V, /* MEModule__COutOfRange.ToString - Yw3O__Yalz__YwtA__YH0V */
 (Tc*)Yw3O__Yalz__YwtA__YxaJa, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJa */
 (Tc*)Yw3O__Yalz__YwtA__YxaJ, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__COutOfRange.toString - Yw3O__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__COutOfRange.getMessage - Yw3O__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__COutOfRange.getPos - Yw3O__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__COutOfRange.getBacktrace - Yw3O__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Yw3Oa */
};
To ToYw3O[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYw3O[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Yw3O__T = {390, (Tc*)&YFK2, Yw3O__Yalz__YwtA__YH0V, StrYw3O, ToYw3O};
void Y6NT(Ti Aindex, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&YFDa), Zint2string(Aindex))), Yw3O__Ytlm_I_imt, 11);
 ZthrowIobject(ex);
}
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=2958500; t = Za(sizeof(Y2EX));}
 sf.pos=2958501;
 t->Vmessage = Amsg;
 sf.pos=2958502;
 t->Vpos = MZ__callerPos();
 sf.pos=2958503;
 t->Vbacktrace = (sf.pos=2958504, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Y2EX__Yalz__YwtA__YH0V(Y2EX *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1566900;
  ZthrowThisNil();
 }
 sf.pos=1566901;
 Vw = Za(sizeof(YjUM));
 sf.pos=1566902;
 Y2EX__Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1566903;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4312400;
  ZthrowThisNil();
 }
 sf.pos=4312401;
 if ((t->Vpos != NULL))
 {
  sf.pos=4312402;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4312403;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4312404;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4312405;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4312406;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4312407;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5332500;
  ZthrowThisNil();
 }
 sf.pos=5332501;
 Y2EX__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=5332502;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=5332503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5332504;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5332505;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=5332506;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=5332507;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=5332508;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5332509;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=5332510;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=5332511;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5332512;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *Y2EX__Ytlm_I_imt[] = {
 (Tc*)&Y2EX__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHRa */
 (Tc*)Y2EX__Yalz__YwtA__YRHR, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHR */
 (Tc*)Y2EX__Yalz__YwtA__YH0V, /* MEModule__CKeyNotFound.ToString - Y2EX__Yalz__YwtA__YH0V */
 (Tc*)Y2EX__Yalz__YwtA__YxaJa, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJa */
 (Tc*)Y2EX__Yalz__YwtA__YxaJ, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CKeyNotFound.toString - Y2EX__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CKeyNotFound.getMessage - Y2EX__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CKeyNotFound.getPos - Y2EX__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CKeyNotFound.getBacktrace - Y2EX__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Y2EXa */
};
To ToY2EX[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrY2EX[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Y2EX__T = {390, (Tc*)&YRiW, Y2EX__Yalz__YwtA__YH0V, StrY2EX, ToY2EX};
void Yxmk(Ti Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Y2EX__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Ym6C), Zint2string(Akey))), Y2EX__Ytlm_I_imt, 12);
 ZthrowIobject(ex);
}
void Y5LT(Tc *Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Y2EX__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YJ3Y), Akey, ((Tc*)&YI), (Tc*)1)), Y2EX__Ytlm_I_imt, 12);
 ZthrowIobject(ex);
}
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8500000; t = Za(sizeof(YX0i));}
 sf.pos=8500001;
 t->Vmessage = Amsg;
 sf.pos=8500002;
 t->Vpos = MZ__callerPos();
 sf.pos=8500003;
 t->Vbacktrace = (sf.pos=8500004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YX0i__Yalz__YwtA__YH0V(YX0i *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5272800;
  ZthrowThisNil();
 }
 sf.pos=5272801;
 Vw = Za(sizeof(YjUM));
 sf.pos=5272802;
 YX0i__Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5272803;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1471500;
  ZthrowThisNil();
 }
 sf.pos=1471501;
 if ((t->Vpos != NULL))
 {
  sf.pos=1471502;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1471503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1471504;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1471505;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1471506;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1471507;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2491600;
  ZthrowThisNil();
 }
 sf.pos=2491601;
 YX0i__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=2491602;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2491603;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2491604;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2491605;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2491606;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2491607;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2491608;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2491609;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2491610;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2491611;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2491612;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YX0i__Ytlm_I_imt[] = {
 (Tc*)&YX0i__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHRa */
 (Tc*)YX0i__Yalz__YwtA__YRHR, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHR */
 (Tc*)YX0i__Yalz__YwtA__YH0V, /* MEModule__CKeyExists.ToString - YX0i__Yalz__YwtA__YH0V */
 (Tc*)YX0i__Yalz__YwtA__YxaJa, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJa */
 (Tc*)YX0i__Yalz__YwtA__YxaJ, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CKeyExists.toString - YX0i__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CKeyExists.getMessage - YX0i__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CKeyExists.getPos - YX0i__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CKeyExists.getBacktrace - YX0i__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - YX0ia */
};
To ToYX0i[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYX0i[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YX0i__T = {390, (Tc*)&Y9_h, YX0i__Yalz__YwtA__YH0V, StrYX0i, ToYX0i};
void YL9Z(Ti Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YX0i__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Y9qa), Zint2string(Akey))), YX0i__Ytlm_I_imt, 14);
 ZthrowIobject(ex);
}
void YEeX(Tc *Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YX0i__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YMKM), Akey, ((Tc*)&YI), (Tc*)1)), YX0i__Ytlm_I_imt, 14);
 ZthrowIobject(ex);
}
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4520900; t = Za(sizeof(YP_P));}
 sf.pos=4520901;
 t->Vmessage = Amsg;
 sf.pos=4520902;
 t->Vpos = MZ__callerPos();
 sf.pos=4520903;
 t->Vbacktrace = (sf.pos=4520904, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YP_P__Yalz__YwtA__YH0V(YP_P *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1004500;
  ZthrowThisNil();
 }
 sf.pos=1004501;
 Vw = Za(sizeof(YjUM));
 sf.pos=1004502;
 YP_P__Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1004503;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YP_P__Yalz__YwtA__YxaJ(YP_P *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=994800;
  ZthrowThisNil();
 }
 sf.pos=994801;
 if ((t->Vpos != NULL))
 {
  sf.pos=994802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=994803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=994804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=994805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=994806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=994807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void YP_P__Yalz__YwtA__YxaJa(YP_P *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2014900;
  ZthrowThisNil();
 }
 sf.pos=2014901;
 YP_P__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=2014902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2014903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2014904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2014905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2014906;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2014907;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2014908;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2014909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2014910;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2014911;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2014912;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YP_P__Ytlm_I_imt[] = {
 (Tc*)&YP_P__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CIllegalByte.NEW - YP_P__Yalz__YwtA__YRHRa */
 (Tc*)YP_P__Yalz__YwtA__YRHR, /* MEModule__CIllegalByte.NEW - YP_P__Yalz__YwtA__YRHR */
 (Tc*)YP_P__Yalz__YwtA__YH0V, /* MEModule__CIllegalByte.ToString - YP_P__Yalz__YwtA__YH0V */
 (Tc*)YP_P__Yalz__YwtA__YxaJa, /* MEModule__CIllegalByte.writeTo - YP_P__Yalz__YwtA__YxaJa */
 (Tc*)YP_P__Yalz__YwtA__YxaJ, /* MEModule__CIllegalByte.writeTo - YP_P__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CIllegalByte.toString - YP_P__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CIllegalByte.getMessage - YP_P__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CIllegalByte.getPos - YP_P__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CIllegalByte.getBacktrace - YP_P__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - YP_Pa */
};
To ToYP_P[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYP_P[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YP_P__T = {390, (Tc*)&Ydbm, YP_P__Yalz__YwtA__YH0V, StrYP_P, ToYP_P};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7347100; t = Za(sizeof(YzSI));}
 sf.pos=7347101;
 t->Vmessage = Amsg;
 sf.pos=7347102;
 t->Vpos = MZ__callerPos();
 sf.pos=7347103;
 t->Vbacktrace = (sf.pos=7347104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YzSI__Ylz1__YwtA__YH0V(YzSI *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1717900;
  ZthrowThisNil();
 }
 sf.pos=1717901;
 Vw = Za(sizeof(YjUM));
 sf.pos=1717902;
 YzSI__Ylz1__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1717903;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4413000;
  ZthrowThisNil();
 }
 sf.pos=4413001;
 if ((t->Vpos != NULL))
 {
  sf.pos=4413002;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4413003;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4413004;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4413005;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4413006;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4413007;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5433100;
  ZthrowThisNil();
 }
 sf.pos=5433101;
 YzSI__Ylz1__YwtA__YxaJ(t, Aw);
 sf.pos=5433102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=5433103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5433104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5433105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=5433106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=5433107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=5433108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5433109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=5433110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=5433111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5433112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YzSI__Ytlm_I_imt[] = {
 (Tc*)&YzSI__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHRa */
 (Tc*)YzSI__Ylz1__YwtA__YRHR, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHR */
 (Tc*)YzSI__Ylz1__YwtA__YH0V, /* MEModule__CDivideByZero.ToString - YzSI__Ylz1__YwtA__YH0V */
 (Tc*)YzSI__Ylz1__YwtA__YxaJa, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJa */
 (Tc*)YzSI__Ylz1__YwtA__YxaJ, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CDivideByZero.toString - YzSI__Ylz1__YwtA__Yoww */
 (Tc*)0, /* MEModule__CDivideByZero.getMessage - YzSI__Ylz1__YwtA__YCzX */
 (Tc*)0, /* MEModule__CDivideByZero.getPos - YzSI__Ylz1__YwtA__YvCK */
 (Tc*)0, /* MEModule__CDivideByZero.getBacktrace - YzSI__Ylz1__YwtA__Y4bq */
 (Tc*)0, /* Init - YzSIa */
};
To ToYzSI[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYzSI[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YzSI__T = {390, (Tc*)&YxFl, YzSI__Ylz1__YwtA__YH0V, StrYzSI, ToYzSI};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4829900; t = Za(sizeof(YXKl));}
 sf.pos=4829901;
 t->Vmessage = Amsg;
 sf.pos=4829902;
 t->Vpos = MZ__callerPos();
 sf.pos=4829903;
 t->Vbacktrace = (sf.pos=4829904, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YXKl__YwtA__YH0V(YXKl *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7993500;
  ZthrowThisNil();
 }
 sf.pos=7993501;
 Vw = Za(sizeof(YjUM));
 sf.pos=7993502;
 YXKl__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=7993503;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8968500;
  ZthrowThisNil();
 }
 sf.pos=8968501;
 YXKl__YwtA__YxaJ(t, Aw);
 sf.pos=8968502;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=8968503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=8968504;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=8968505;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=8968506;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=8968507;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=8968508;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=8968509;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=8968510;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=8968511;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=8968512;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9988600;
  ZthrowThisNil();
 }
 sf.pos=9988601;
 if ((t->Vpos != NULL))
 {
  sf.pos=9988602;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9988603;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9988604;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9988605;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=9988606;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=9988607;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YXKl__Ytlm_I_imt[] = {
 (Tc*)&YXKl__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHRa */
 (Tc*)YXKl__YwtA__YRHR, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHR */
 (Tc*)YXKl__YwtA__YH0V, /* MEModule__CIOError.ToString - YXKl__YwtA__YH0V */
 (Tc*)YXKl__YwtA__YxaJa, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJa */
 (Tc*)YXKl__YwtA__YxaJ, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CIOError.toString - YXKl__YwtA__Yoww */
 (Tc*)0, /* MEModule__CIOError.getMessage - YXKl__YwtA__YCzX */
 (Tc*)0, /* MEModule__CIOError.getPos - YXKl__YwtA__YvCK */
 (Tc*)0, /* MEModule__CIOError.getBacktrace - YXKl__YwtA__Y4bq */
 (Tc*)0, /* Init - YXKla */
};
To ToYXKl[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYXKl[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YXKl__T = {390, (Tc*)&YTj3, YXKl__YwtA__YH0V, StrYXKl, ToYXKl};
YuDC *YdhH(YuDC *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8723500; t = Za(sizeof(YuDC));}
 sf.pos=8723501;
 t->Vmessage = ((Tc*)&Ynjz);
 sf.pos=8723502;
 t->Vpos = MZ__callerPos();
 sf.pos=8723503;
 t->Vbacktrace = (sf.pos=8723504, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YuDC__YwtA__YH0V(YuDC *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1289600;
  ZthrowThisNil();
 }
 sf.pos=1289601;
 Vw = Za(sizeof(YjUM));
 sf.pos=1289602;
 YuDC__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1289603;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8681800;
  ZthrowThisNil();
 }
 sf.pos=8681801;
 YuDC__YwtA__YxaJ(t, Aw);
 sf.pos=8681802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=8681803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=8681804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=8681805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=8681806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=8681807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=8681808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=8681809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=8681810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=8681811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=8681812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9701900;
  ZthrowThisNil();
 }
 sf.pos=9701901;
 if ((t->Vpos != NULL))
 {
  sf.pos=9701902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9701903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9701904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9701905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=9701906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=9701907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YuDC__Ytlm_I_imt[] = {
 (Tc*)&YuDC__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHRa */
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHR */
 (Tc*)YuDC__YwtA__YH0V, /* MEModule__CWrongType.ToString - YuDC__YwtA__YH0V */
 (Tc*)YuDC__YwtA__YxaJa, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJa */
 (Tc*)YuDC__YwtA__YxaJ, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CWrongType.toString - YuDC__YwtA__Yoww */
 (Tc*)0, /* MEModule__CWrongType.getMessage - YuDC__YwtA__YCzX */
 (Tc*)0, /* MEModule__CWrongType.getPos - YuDC__YwtA__YvCK */
 (Tc*)0, /* MEModule__CWrongType.getBacktrace - YuDC__YwtA__Y4bq */
 (Tc*)0, /* Init - YuDCa */
};
To ToYuDC[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYuDC[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YuDC__T = {390, (Tc*)&YCoZ, YuDC__YwtA__YH0V, StrYuDC, ToYuDC};
void YTuG(Ti Apos) {
 Tr ex;
 YuDC *Ve = 0;
 Tr t0 = {NULL};
 Ve = YdhH(NULL);
 Ve->Vpos = MZ__posnr2pos(NULL, Apos);
 *Znao(&ex, Ve, YuDC__Ytlm_I_imt, 24);
 ZthrowIobject(ex);
}
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7808200; t = Za(sizeof(YrHq));}
 sf.pos=7808201;
 t->Vmessage = Amsg;
 sf.pos=7808202;
 t->Vpos = MZ__callerPos();
 sf.pos=7808203;
 t->Vbacktrace = (sf.pos=7808204, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YrHq__YwtA__YH0V(YrHq *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2761800;
  ZthrowThisNil();
 }
 sf.pos=2761801;
 Vw = Za(sizeof(YjUM));
 sf.pos=2761802;
 YrHq__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=2761803;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=41200;
  ZthrowThisNil();
 }
 sf.pos=41201;
 YrHq__YwtA__YxaJ(t, Aw);
 sf.pos=41202;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=41203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=41204;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=41205;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=41206;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=41207;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=41208;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=41209;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=41210;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=41211;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=41212;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1061300;
  ZthrowThisNil();
 }
 sf.pos=1061301;
 if ((t->Vpos != NULL))
 {
  sf.pos=1061302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1061303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1061304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1061305;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1061306;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1061307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YrHq__Ytlm_I_imt[] = {
 (Tc*)&YrHq__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHRa */
 (Tc*)YrHq__YwtA__YRHR, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHR */
 (Tc*)YrHq__YwtA__YH0V, /* MEModule__CInternal.ToString - YrHq__YwtA__YH0V */
 (Tc*)YrHq__YwtA__YxaJa, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJa */
 (Tc*)YrHq__YwtA__YxaJ, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CInternal.toString - YrHq__YwtA__Yoww */
 (Tc*)0, /* MEModule__CInternal.getMessage - YrHq__YwtA__YCzX */
 (Tc*)0, /* MEModule__CInternal.getPos - YrHq__YwtA__YvCK */
 (Tc*)0, /* MEModule__CInternal.getBacktrace - YrHq__YwtA__Y4bq */
 (Tc*)0, /* Init - YrHqa */
};
To ToYrHq[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYrHq[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YrHq__T = {390, (Tc*)&YVki, YrHq__YwtA__YH0V, StrYrHq, ToYrHq};
void YUSH(YkxB *Apos, Tc *Atext) {
 Tr ex;
 YrHq *Ve = 0;
 Tr t0 = {NULL};
 Ve = YrHq__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 *Znao(&ex, Ve, YrHq__Ytlm_I_imt, 26);
 ZthrowIobject(ex);
}
void YxIS(Tr Ae) {
      static int entered = 0;
      int didEnter = entered;
      entered = 1;
 if ((Ae).type == 1)
 {
  Ti VexitVal;
  VexitVal = ((YEro *)Znio(1, 1571802, (Ae)))->Vvalue;
  if (!didEnter) beforeExit();
  exit(VexitVal);
 }
 else
 {
  YvL0(Ae);
  if (!didEnter) beforeExit();
  exit(1);
 }
 return;
}
void YvL0(Tr Ae) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5238600;
 Ylxt();
 sf.pos=5238601;
 YQar(Ae, 1, YeNQ);
 sf.pos=5238619;
 ((Ts (*)(void*))(YeNQ.table[18]))(YeNQ.ptr);
 topFrame = sf.prev;
 return;
}
void YQar(Tr A0, Tb A1, Tr A2) {
 if (A0.ptr == NULL) ZthrowCstringNil("writeTo: object is NIL, cannot select method to invoke");
 if (A2.ptr == NULL) ZthrowCstringNil("writeTo: argument 2 is NIL, cannot select method to invoke");
 switch (A0.type) {
  case 0:
   YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238602)); return;
  case 1:
   YEro__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238603)); return;
  case 2:
   return;
  case 3:
   return;
  case 4:
   YKhn__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238604)); return;
  case 5:
   Y1uN__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238605)); return;
  case 6:
   YAxe__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238606)); return;
  case 7:
   YVNj__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238607)); return;
  case 8:
   return;
  case 9:
   return;
  case 10:
   Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238608)); return;
  case 11:
   Yw3O__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238609)); return;
  case 12:
   Y2EX__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238610)); return;
  case 13:
   return;
  case 14:
   YX0i__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238611)); return;
  case 15:
   YP_P__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238612)); return;
  case 16:
   return;
  case 17:
   YzSI__Ylz1__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238613)); return;
  case 18:
   return;
  case 19:
   YXKl__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238614)); return;
  case 20:
   return;
  case 21:
   return;
  case 22:
   return;
  case 23:
   return;
  case 24:
   YuDC__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238615)); return;
  case 25:
   return;
  case 26:
   YrHq__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238616)); return;
  case 27:
   return;
  case 28:
   return;
  case 29:
   Ys_q__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238617)); return;
  case 30:
   YOEA__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238618)); return;
  case 31:
   return;
 }
 ZthrowCstringBadValue("writeTo: cannot select method to invoke");
 return;
}
/* EModule done */
/* including ZModule bodies */
YkxB *Ypp_(YkxB *t, Tc *Afilename) {
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = 1;
 t->Vcol = 1;
 return t;
}
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) {
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 return t;
}
void YnS4(YkxB *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4686800;
  ZthrowThisNil();
 }
 sf.pos=4686801;
 ++(t->Vlnum);
 sf.pos=4686802;
 t->Vcol = 1;
 topFrame = sf.prev;
 return;
}
Tc *YpI_(YkxB *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1818700;
  ZthrowThisNil();
 }
 sf.pos=1818701;
 Vw = Za(sizeof(YjUM));
 sf.pos=1818702;
 if ((t->Vfilename == NULL))
 {
  sf.pos=1818703;
  YJqza(Vw, ((Tc*)&YKo1));
 }
 else
 {
  sf.pos=1818704;
  YJqza(Vw, t->Vfilename);
 }
 sf.pos=1818705;
 YJqza(Vw, ((Tc*)&YBpY));
 sf.pos=1818706;
 YjUM__YHhZb(Vw, t->Vlnum);
 sf.pos=1818707;
 YJqza(Vw, ((Tc*)&Y8ES));
 sf.pos=1818708;
 YjUM__YHhZb(Vw, t->Vcol);
 sf.pos=1818709;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
To ToYkxB[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* filename */
 {0, (Tt*)&int__T}, /* lnum */
 {0, (Tt*)&int__T}, /* col */
 {0, (Tt*)&string__T}, /* text */
};
char *StrYkxB[] = {
 "filename",
 "lnum",
 "col",
 "text",
};
Tto YkxB__T = {390, (Tc*)&YBCs, YpI_, StrYkxB, ToYkxB};
/* ZModule done */
/* including STRINGModule bodies */
Tc *YwOB(Tc *Athis) {
 Ti Vstart;
 Ti Vend;
 Zsf sf;
 Tc *r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3287800;
 if (Athis == NULL)
 {
  sf.pos=3287801;
  r = NULL;
  rt = 1;
  goto YMwG;
 }
 sf.pos=3287802;
 Vstart = 0;
 sf.pos=3287803;
 Vend = (ZstringSize(Athis) - 1);
 sf.pos=3287804;
 while (((Vstart <= Vend) && YBbQ(ZstringGetChar(Athis, Vstart))))
 {
  sf.pos=3287805;
  ++(Vstart);
 sf.pos=3287806;
 }
 sf.pos=3287807;
 while (((Vend > Vstart) && YBbQ(ZstringGetChar(Athis, Vend))))
 {
  sf.pos=3287808;
  --(Vend);
 sf.pos=3287809;
 }
 sf.pos=3287810;
 r = ZstringSlice(Athis, Vstart, Vend, 0);
YMwG:
 topFrame = sf.prev;
 return r;
}
/* STRINGModule done */
/* including IOModule bodies */
Tr Yd89() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdin;
 r = Vfile;
 return r;
}
Tr Yvyt() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdout;
 r = Vfile;
 return r;
}
Tr YsM3() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stderr;
 r = Vfile;
 return r;
}
Tc **YdXi__imtt[] = {
  Yw8L__YdXi_imt,
    0,
  YjUM__YdXi_imt,
    0,
};
Tc **Y8is__imtt[] = {
  Yw8L__Y8is_I_imt,
    0,
  YjUM__Y8is_I_imt,
    0,
};
Ti YFeQ(Yw8L *t) {
 Ti Vb;
 Zsf sf;
 Ti r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1605300;
  ZthrowThisNil();
 }
 sf.pos=1605301;
 if ((t->Vfd == NULL))
 {
  Tr ex;
  sf.pos=1605302;
  *Znao(&ex, YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8)), YXKl__Ytlm_I_imt, 19);
  ZthrowIobject(ex);
 }
 Vb = 0;
 sf.pos=1605303;
 Vb = fgetc(t->Vfd);
 sf.pos=1605304;
 r = Vb;
 topFrame = sf.prev;
 return r;
}
Ti YAPp(Yw8L *t) {
 Ti Vc;
 Zsf sf;
 Ti r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4663100;
  ZthrowThisNil();
 }
 sf.pos=4663101;
 Vc = YFeQ(t);
 sf.pos=4663102;
 if (((Vc != Y3QJ) && (Vc >= 128)))
 {
  Ti Vlen;
  Vlen = 0;
  sf.pos=4663103;
  if ((((Vc & 224)) == 192))
  {
   sf.pos=4663104;
   Vlen = 2;
   sf.pos=4663105;
   Vc = (Vc & 31);
  }
  else {
  sf.pos=4663106;
 if ((((Vc & 240)) == 224))
  {
   sf.pos=4663107;
   Vlen = 3;
   sf.pos=4663108;
   Vc = (Vc & 15);
  }
  else {
  sf.pos=4663109;
 if ((((Vc & 248)) == 240))
  {
   sf.pos=4663110;
   Vlen = 4;
   sf.pos=4663111;
   Vc = (Vc & 7);
  }
  else
  {
   Tr ex;
   sf.pos=4663112;
   *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&YPHa), Zint2string(Vc))), YP_P__Ytlm_I_imt, 15);
   ZthrowIobject(ex);
  }
  }}
  sf.pos=4663113;
  {
   Ti Vnr;
   Tfr Zf2;
   ZforRangeNew(2, Vlen, 0, 1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vnr); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vnr)) {
   Ti Vc2;
   sf.pos=4663114;
   Vc2 = YFeQ(t);
   sf.pos=4663115;
   if ((Vc2 == Y3QJ))
   {
    Tr ex;
    sf.pos=4663116;
    *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&YKzT), Zint2string(Vnr))), YP_P__Ytlm_I_imt, 15);
    ZthrowIobject(ex);
   }
   else {
   sf.pos=4663117;
 if ((((Vc2 & 192)) != 128))
   {
    Tr ex;
    sf.pos=4663118;
    *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ZcS3(((Tc*)&Ymwv), Zint2string(Vnr), ((Tc*)&YPfW))), YP_P__Ytlm_I_imt, 15);
    ZthrowIobject(ex);
   }
   }
   sf.pos=4663119;
   Vc = (((Vc << 6)) + ((Vc2 & 63)));
   sf.pos=4663120;
   }
  }
  sf.pos=4663121;
  switch (Vlen)
  {
  case 2:
   {
    sf.pos=4663122;
    if ((Vc <= 127))
    {
     Tr ex;
     sf.pos=4663123;
     *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn)), YP_P__Ytlm_I_imt, 15);
     ZthrowIobject(ex);
    }
     break;
   }
  case 3:
   {
    sf.pos=4663124;
    if ((Vc <= 2047))
    {
     Tr ex;
     sf.pos=4663125;
     *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn)), YP_P__Ytlm_I_imt, 15);
     ZthrowIobject(ex);
    }
     break;
   }
  case 4:
   {
    sf.pos=4663126;
    if ((Vc <= 65535))
    {
     Tr ex;
     sf.pos=4663127;
     *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn)), YP_P__Ytlm_I_imt, 15);
     ZthrowIobject(ex);
    }
     break;
   }
  }
 }
 sf.pos=4663128;
 r = Vc;
 topFrame = sf.prev;
 return r;
}
Ts YwHoa(Yw8L *t, Tc *Atext) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9482300;
  ZthrowThisNil();
 }
 Vret = 0;
 sf.pos=9482301;
 if ((t->Vfd == NULL))
 {
  Tr ex;
  sf.pos=9482302;
  *Znao(&ex, YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8)), YXKl__Ytlm_I_imt, 19);
  ZthrowIobject(ex);
 }
 sf.pos=9482303;
 {
  Tc *p;
  Ti len = ZstringSizePtr(Atext, &p);
  if (len == 0 || fwrite(p, (size_t)len, (size_t)1, t->Vfd) == 1)
   Vret = 1;
  else
   Vret = 0;
  }
 sf.pos=9482304;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts YGmp(Yw8L *t) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6056700;
  ZthrowThisNil();
 }
 sf.pos=6056701;
 Vret = 0;
 sf.pos=6056702;
 if ((t->Vfd != NULL))
 {
  sf.pos=6056703;
 if (fflush(t->Vfd) == 0)
  Vret = 1;
 else
  Vret = 0;
 }
 sf.pos=6056704;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5981900;
  ZthrowThisNil();
 }
 sf.pos=5981901;
 r = YwHoa(t, Zint2string(Anumber));
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__Ydti(Yw8L *t, Ti Achar) {
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8810500;
  ZthrowThisNil();
 }
 sf.pos=8810501;
 if (((Achar < 0) || (Achar > 1114111)))
 {
  Tr ex;
  sf.pos=8810502;
  *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&Yv8w), Zint2string(Achar))), Yw3O__Ytlm_I_imt, 11);
  ZthrowIobject(ex);
 }
 sf.pos=8810503;
 r = YwHoa(t, ZintAsString(Achar));
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext) {
 Zsf sf;
 Ts r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6618800;
  ZthrowThisNil();
 }
 sf.pos=6618801;
 if (((YwHoa(t, Atext) == 1) && (YwHoa(t, ((Tc*)&Yk)) == 1)))
 {
  sf.pos=6618802;
  r = 1;
  rt = 1;
  goto Y7Vd;
 }
 sf.pos=6618803;
 r = 0;
Y7Vd:
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YRt7g(Yw8L *t) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8261800;
  ZthrowThisNil();
 }
 sf.pos=8261801;
 r = YwHoa(t, ((Tc*)&Yk));
 topFrame = sf.prev;
 return r;
}
Tc *Yw8L__Yw8L_I_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZa */
 (Tc*)Yw8L__YHhZb, /* MIOModule__CFile.write - Yw8L__YHhZb */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZc */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZd */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZe */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZf */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZg */
 (Tc*)0, /* MIOModule__CFile.writeByte - YvfVa */
 (Tc*)Yw8L__Ydti, /* MIOModule__CFile.writeChar - Yw8L__Ydti */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7a */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7b */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7c */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7d */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7e */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7f */
 (Tc*)Yw8L__YRt7g, /* MIOModule__CFile.print - Yw8L__YRt7g */
 (Tc*)0, /* MIOModule__CFile.format - Yw8L__YTPv */
 (Tc*)0,
 (Tc*)0,
 (Tc*)YFeQ, /* MIOModule__CFile.readByte - YFeQ */
 (Tc*)YAPp, /* MIOModule__CFile.readChar - YAPp */
 (Tc*)0, /* MIOModule__CFile.readAll - Yyuma */
 (Tc*)0, /* MIOModule__CFile.readAll - Yyum */
 (Tc*)0, /* MIOModule__CFile.readAllBytes - YVfz */
 (Tc*)0, /* MIOModule__CFile.readLine - YaEh */
 (Tc*)0, /* MIOModule__CFile.readLineRaw - Yn2l */
 (Tc*)0, /* MIOModule__CFile.readAllLines - YCm1a */
 (Tc*)0, /* MIOModule__CFile.readAllLines - YCm1 */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWFa */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWF */
 (Tc*)0, /* MIOModule__CFile.writeAllLines - YZFx */
 (Tc*)YGmp, /* MIOModule__CFile.flush - YGmp */
 (Tc*)0, /* MIOModule__CFile.close - YrF8 */
 (Tc*)0, /* MIOModule__CFile.Finish - YSo_ */
 (Tc*)0, /* Init - Yw8La */
};
Tc *Yw8L__Y8is_I_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZg */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZf */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZe */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZd */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZc */
 (Tc*)Yw8L__YHhZb, /* MIOModule__CFile.write - Yw8L__YHhZb */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZa */
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)0, /* MIOModule__CFile.writeByte - YvfVa */
 (Tc*)Yw8L__Ydti, /* MIOModule__CFile.writeChar - Yw8L__Ydti */
 (Tc*)Yw8L__YRt7g, /* MIOModule__CFile.print - Yw8L__YRt7g */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7f */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7e */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7d */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7c */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7b */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7a */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
 (Tc*)0, /* MIOModule__CFile.format - Yw8L__YTPv */
 (Tc*)0, /* Init - Yw8La */
};
Tc *Yw8L__YdXi_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
};
To ToYw8L[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* name */
};
char *StrYw8L[] = {
 "name",
};
Tto Yw8L__T = {390, (Tc*)&YtTU, 0, StrYw8L, ToYw8L};
Tr YsGz(Tc *AfileName) {
 Zsf sf;
 Tr r = {NULL};
 Tr Vfile = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9983800;
 {
  int fnr = open(ZgetCstring(AfileName), O_RDONLY);
  if (fnr >= 0) {
 sf.pos=9983801;
 Vfile = *Znao(&Vfile, Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 sf.pos=9983802;
   (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = fdopen(fnr, "r");
  }
 }
 sf.pos=9983803;
 r = Vfile;
 topFrame = sf.prev;
 return r;
}
Tr YiBk(Tc *AfileName, Tb Atruncate) {
 Zsf sf;
 Tr r = {NULL};
 Tr Vfile = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8158000;
 {
  int flags = O_WRONLY|O_CREAT;
  if (Atruncate) flags |= O_TRUNC;
  int fnr = open(ZgetCstring(AfileName), flags, 0666);
  if (fnr >= 0) {
   if (!Atruncate) lseek(fnr, 0, SEEK_END);
 sf.pos=8158001;
 Vfile = *Znao(&Vfile, Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 sf.pos=8158002;
   (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = fdopen(fnr, "w");
  }
 }
 sf.pos=8158003;
 r = Vfile;
 topFrame = sf.prev;
 return r;
}
Ts Yvcu(Tc *Atext) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vret = 0;
 sf.pos=8487000;
 {
  Tc *p;
  Ti len = ZstringSizePtr(Atext, &p);
  if (len == 0 || fwrite(p, (size_t)len, (size_t)1, stdout) == 1)
   Vret = 1;
  else
   Vret = 0;
 }
 sf.pos=8487001;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts Yl0k(Tc *Atext) {
 Ts Vret;
 Ti Vlen;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vret = 0;
 sf.pos=187200;
 Vlen = ZbyteStringSize(Atext);
 sf.pos=187201;
 if ((Vlen == 0 || fwrite(ZgetCstring(Atext), (size_t)Vlen, 1, stdout) == 1) && fputc('\n', stdout) >= 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=187202;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts Ylxt() {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vret = 0;
 sf.pos=4676100;
 if (fflush(stdout) == 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=4676101;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts YJqza(YjUM *t, Tc *Atext) {
 Ti Vlen;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8998700;
  ZthrowThisNil();
 }
 sf.pos=8998701;
 Vlen = ZbyteStringSize(Atext);
 sf.pos=8998702;
 if ((t->Vs == NULL))
 {
  sf.pos=8998703;
  t->Vs = ZnewArray((Tt*)&byte__T, sizeof(Tc), (Vlen + 30));
  sf.pos=8998704;
  Zas(t->Vs, Atext, 0, 0);
  sf.pos=8998705;
  t->VsLen = Vlen;
 }
 else
 {
  sf.pos=8998706;
  if ((((t->VsLen + Vlen) + 1) >= ZArraySize(t->Vs)))
  {
   sf.pos=8998707;
   ZarrayResize(t->Vs, sizeof(Tc), (((ZArraySize(t->Vs) + (ZArraySize(t->Vs) / 8)) + Vlen) + 50)) ;
  }
  sf.pos=8998708;
  Zas(t->Vs, Atext, 0, t->VsLen);
  sf.pos=8998709;
  t->VsLen += Vlen;
 }
 sf.pos=8998710;
 r = 1;
 topFrame = sf.prev;
 return r;
}
Ts Ye7fa(YjUM *t, Ti Abyte) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3855200;
  ZthrowThisNil();
 }
 sf.pos=3855201;
 if ((t->Vs == NULL))
 {
  sf.pos=3855202;
  t->Vs = ZnewArray((Tt*)&byte__T, sizeof(Tc), 30);
 }
 else {
 sf.pos=3855203;
 if (((t->VsLen + 2) >= ZArraySize(t->Vs)))
 {
  sf.pos=3855204;
  ZarrayResize(t->Vs, sizeof(Tc), ((ZArraySize(t->Vs) + (ZArraySize(t->Vs) / 8)) + 50)) ;
 }
 }
 sf.pos=3855205;
 (*(Tc*)ZarrayPtr(t->Vs, (t->VsLen)++)) = Abyte;
 sf.pos=3855206;
 (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
 sf.pos=3855207;
 r = 1;
 topFrame = sf.prev;
 return r;
}
Tc *YbNW(YjUM *t) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vr = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6453100;
  ZthrowThisNil();
 }
 sf.pos=6453101;
 if ((t->Vs == NULL))
 {
  sf.pos=6453102;
  Vr = ((Tc*)&Ya);
 }
 else
 {
  sf.pos=6453103;
  Vr = ZnewString(t->Vs->ptr, t->VsLen);
 }
 sf.pos=6453104;
 r = Vr;
 topFrame = sf.prev;
 return r;
}
Ti Y6jW(YjUM *t) {
 Ti Vc;
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5897500;
  ZthrowThisNil();
 }
 sf.pos=5897501;
 if ((t->VsLen == 0))
 {
  sf.pos=5897502;
  r = Y3QJ;
  rt = 1;
  goto Ykjg;
 }
 Vc = 0;
 sf.pos=5897503;
 Vc = (*(Tc*)ZarrayPtr(t->Vs, --(t->VsLen)));
 sf.pos=5897504;
 (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
 sf.pos=5897505;
 if (((((Vc & 192)) == 128) && (t->VsLen > 0)))
 {
  Ti Vc2;
  sf.pos=5897506;
  Vc2 = (*(Tc*)ZarrayPtr(t->Vs, --(t->VsLen)));
  sf.pos=5897507;
  (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
  sf.pos=5897508;
  if (((((Vc2 & 192)) == 128) && (t->VsLen > 0)))
  {
   Ti Vc3;
   sf.pos=5897509;
   Vc3 = (*(Tc*)ZarrayPtr(t->Vs, --(t->VsLen)));
   sf.pos=5897510;
   (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
   sf.pos=5897511;
   if (((((Vc3 & 192)) == 128) && (t->VsLen > 0)))
   {
    Ti Vc4;
    sf.pos=5897512;
    Vc4 = (*(Tc*)ZarrayPtr(t->Vs, --(t->VsLen)));
    sf.pos=5897513;
    (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
    sf.pos=5897514;
    Vc = (((((((Vc4 & 7)) << 18)) + ((((Vc3 & 63)) << 12))) + ((((Vc2 & 63)) << 6))) + ((Vc & 63)));
   }
   else
   {
    sf.pos=5897515;
    Vc = ((((((Vc3 & 15)) << 12)) + ((((Vc2 & 63)) << 6))) + ((Vc & 63)));
   }
  }
  else
  {
   sf.pos=5897516;
   Vc = (((((Vc2 & 31)) << 6)) + ((Vc & 63)));
  }
 }
 sf.pos=5897517;
 r = Vc;
Ykjg:
 topFrame = sf.prev;
 return r;
}
void YXip(YjUM *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4607200;
  ZthrowThisNil();
 }
 sf.pos=4607201;
 t->VsLen = 0;
 sf.pos=4607202;
 t->Vs = NULL;
 topFrame = sf.prev;
 return;
}
void Y3_a(YjUM *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8344300;
  ZthrowThisNil();
 }
 sf.pos=8344301;
 t->VsLen = 0;
 topFrame = sf.prev;
 return;
}
Ts YjUM__YHhZb(YjUM *t, Ti Anumber) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7200700;
  ZthrowThisNil();
 }
 sf.pos=7200701;
 r = YJqza(t, Zint2string(Anumber));
 topFrame = sf.prev;
 return r;
}
Ts YjUM__Ydti(YjUM *t, Ti Achar) {
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4928500;
  ZthrowThisNil();
 }
 sf.pos=4928501;
 if (((Achar < 0) || (Achar > 1114111)))
 {
  Tr ex;
  sf.pos=4928502;
  *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&Yv8w), Zint2string(Achar))), Yw3O__Ytlm_I_imt, 11);
  ZthrowIobject(ex);
 }
 sf.pos=4928503;
 r = YJqza(t, ZintAsString(Achar));
 topFrame = sf.prev;
 return r;
}
Ts YjUM__YRt7(YjUM *t, Tc *Atext) {
 Zsf sf;
 Ts r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2676000;
  ZthrowThisNil();
 }
 sf.pos=2676001;
 if (((YJqza(t, Atext) == 1) && (YJqza(t, ((Tc*)&Yk)) == 1)))
 {
  sf.pos=2676002;
  r = 1;
  rt = 1;
  goto Yvkn;
 }
 sf.pos=2676003;
 r = 0;
Yvkn:
 topFrame = sf.prev;
 return r;
}
Tc *YjUM__Y8is_I_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZg */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZf */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZe */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZd */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZc */
 (Tc*)YjUM__YHhZb, /* MIOModule__CStringWriter.write - YjUM__YHhZb */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZa */
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)Ye7fa, /* MIOModule__CStringWriter.writeByte - Ye7fa */
 (Tc*)YjUM__Ydti, /* MIOModule__CStringWriter.writeChar - YjUM__Ydti */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7g */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7f */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7e */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7d */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7c */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7b */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7a */
 (Tc*)YjUM__YRt7, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
 (Tc*)0, /* MIOModule__CStringWriter.format - YjUM__YTPv */
 (Tc*)0, /* Init - YjUMa */
};
Tc *YjUM__YdXi_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)YjUM__YRt7, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
};
To ToYjUM[] = {
 {3, 0},
 {0, (Tt*)&int__T}, /* sLen */
 {0, (Tt*)&array__T}, /* s */
 {0, (Tt*)&string__T}, /* x */
};
char *StrYjUM[] = {
 "sLen",
 "s",
 "x",
};
Tto YjUM__T = {390, (Tc*)&YE4c, YbNW, StrYjUM, ToYjUM};
Ti Yr30(Tc *Afname) {
 Ti Vi;
 Ti Vj;
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6221300;
 Vi = ZstringFindLastChar(Afname, 47, 0);
 sf.pos=6221301;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=6221302;
 Vj = ZstringFindLastChar(Afname, 92, 0);
 sf.pos=6221303;
 if ((Vj > Vi))
 {
  sf.pos=6221304;
  Vi = Vj;
 }
 sf.pos=6221305;
#endif
 sf.pos=6221306;
 if ((Vi < 0))
 {
  sf.pos=6221307;
  r = 0;
  rt = 1;
  goto YnSW;
 }
 sf.pos=6221308;
 r = (Vi + 1);
YnSW:
 topFrame = sf.prev;
 return r;
}
Tc *YKFh(Tc *Afname) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7590500;
 r = ZstringSlice(Afname, Yr30(Afname), -1, 0);
 topFrame = sf.prev;
 return r;
}
int JIOModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
  if (round == 0) {
   sf.pos=745200;
   Y59X = Yd89();
   sf.pos=745201;
   Yb0q = Yvyt();
   sf.pos=745202;
   YeNQ = YsM3();
  }
  topFrame = sf.prev;
 }
 return done;
}
/* IOModule done */
/* including LOGModule bodies */
void YDli(Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 Ygkj(5, Amsg, Apos, Aflags);
 return;
}
void Y2oO(Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 Ygkj(5, Amsg, Apos, (Aflags + 2));
 return;
}
void Ygkj(Te Alevel, Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 YjUM *Vw = 0;
 Tc *VwholeMsg = NULL;
 Y2KX *Vtv = 0;
 Tr t0 = {NULL};
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 int rt = 0;
 if ((((((Alevel == 0) && !(YuOS(YU8T)))) || (((Alevel == 1) && (Y86c__Ye9f(YlUb) < 2)))) || (((Alevel == 2) && (Y86c__Ye9f(YlUb) < 1)))))
 {
  rt = 1;
  goto YbRZ;
 }
 ++(*ZDictGetIntP(Ytd2, (Tz)(Ti)Alevel));
 Vw = Za(sizeof(YjUM));
 if ((Apos != NULL))
 {
  YJqza(Vw, YpI_(Apos));
  YJqza(Vw, ((Tc*)&YFDa));
 }
 if ((((Aflags) & 2) >> 1))
 {
  YJqza(Vw, ((Tc*)&YJ5p));
 }
 switch (Alevel)
 {
 case 4:
  {
   YJqza(Vw, ((Tc*)&Yyq1));
    break;
  }
 case 5:
  {
   YJqza(Vw, ((Tc*)&Y27a));
    break;
  }
 case 6:
  {
   YJqza(Vw, ((Tc*)&Y3l3));
    break;
  }
 case 7:
  {
   YJqza(Vw, ((Tc*)&YmM8));
    break;
  }
 }
 YJqza(Vw, YmaW);
 YJqza(Vw, Amsg);
 if ((((Aflags) & 1)))
 {
  YwlF(*Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 }
 if (!((((Aflags) & 4) >> 2)))
 {
  YJqza(Vw, ((Tc*)&Yk));
 }
 VwholeMsg = YbNW(Vw);
 Yvcu(VwholeMsg);
 if ((((Yz2b).ptr) != NULL))
 {
  if (YiAD)
  {
   Vtv = YgaY(NULL);
   ((Ts (*)(void*, Tc*))(Yz2b.table[1]))(Yz2b.ptr, ZcS5(YYTs(Vtv), ((Tc*)&YU), (t1 = ZintFormat(((Tc*)&YwV7), Vtv->Vusec)), ((Tc*)&YG), (Tc*)1));
  }
  ((Ts (*)(void*, Tc*))(Yz2b.table[1]))(Yz2b.ptr, VwholeMsg);
 }
 if ((Alevel >= 5))
 {
  ++(Yrpn);
  Y7LJ();
 }
 else {
 if (((Y9Rj() - YvW3) > YOwl))
 {
  Y7LJ();
 }
 }
 if ((Alevel == 7))
 {
  Zexit(NULL, 10);
 }
YbRZ:
 return;
}
void YwlF(Tr Aout) {
 Zsf sf;
 Tl *Zf1 = NULL;
 YkxB *Vp = 0;
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8489900;
 ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ((Tc*)&Ya));
 sf.pos=8489901;
 ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ((Tc*)&YDzC));
 sf.pos=8489903;
 {
  Tfl Zf1i;
  Zf1 = (sf.pos=8489904, MZ__backtrace(0, -1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vp;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8489905;
  ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ZcS3(YpI_(Vp), ((Tc*)&YFDa), (t0 = Vp->Vtext)));
  sf.pos=8489906;
  }
 }
 topFrame = sf.prev;
 return;
}
void Y7LJ() {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5655500;
 Ylxt();
 sf.pos=5655501;
 if ((((Yz2b).ptr) != NULL))
 {
  sf.pos=5655502;
  ((Ts (*)(void*))(Yz2b.table[34]))(Yz2b.ptr);
 }
 sf.pos=5655503;
 YvW3 = Y9Rj();
 topFrame = sf.prev;
 return;
}
int JLOGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 if (round == 0) {
   sf.pos=8332600;
   YU8T = YttT(NULL, ((Tc*)&YLa), ((Tc*)&YGwH), 0, ((Tc*)&YhpM));
   sf.pos=8332601;
   YlUb = YttT(NULL, ((Tc*)&Y2a), ((Tc*)&YUsn), 0, ((Tc*)&YSuP));
  }
  if (round == 0) {
   sf.pos=8332602;
   Ytd2 = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MLOGModule__ELevel__T, (Tt*)&int__T, 0), (Tz)(Ti)0, (Tz)(Ti)0), (Tz)(Ti)1, (Tz)(Ti)0), (Tz)(Ti)2, (Tz)(Ti)0), (Tz)(Ti)3, (Tz)(Ti)0), (Tz)(Ti)4, (Tz)(Ti)0), (Tz)(Ti)5, (Tz)(Ti)0), (Tz)(Ti)6, (Tz)(Ti)0), (Tz)(Ti)7, (Tz)(Ti)0);
  }
  topFrame = sf.prev;
 }
 return done;
}
/* LOGModule done */
/* including SETModule bodies */
Yhqr *Ypau(Yhqr *t) {
 Zsf sf;
 if (t == NULL) t = Za(sizeof(Yhqr));
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8901200;
 t->Vdict = ZnewDict((Tt*)&string__T, (Tt*)&bool__T, 0);
 topFrame = sf.prev;
 return t;
}
Yhqr *Yh95(Yhqr *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=2137800; t = Ypau(NULL);}
 topFrame = sf.prev;
 return t;
}
Tc *Yehh(Yhqr *t) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7419800;
  ZthrowThisNil();
 }
 sf.pos=7419801;
 r = ZListToString(ZDictKeys(t->Vdict, 0), 1);
 topFrame = sf.prev;
 return r;
}
Tb YyHa(Yhqr *t, Tc *Akey) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2586000;
  ZthrowThisNil();
 }
 sf.pos=2586001;
 r = ZDictHas(t->Vdict, (Tz)(void*)Akey);
 topFrame = sf.prev;
 return r;
}
Yhqr *Y63C(Yhqr *t, Tc *Akey) {
 Zsf sf;
 Yhqr *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2167600;
  ZthrowThisNil();
 }
 sf.pos=2167601;
 if (!(ZDictHas(t->Vdict, (Tz)(void*)Akey)))
 {
  sf.pos=2167602;
  ZDictAdd(0, t->Vdict, (Tz)(void*)Akey, (Tz)(Ti)1);
 }
 sf.pos=2167603;
 r = t;
 topFrame = sf.prev;
 return r;
}
To ToYhqr[] = {
 {1, 0},
 {0, (Tt*)&dict__T}, /* dict */
};
char *StrYhqr[] = {
 "dict",
};
Tto Yhqr__T = {390, (Tc*)&Yehz, Yehh, StrYhqr, ToYhqr};
/* SETModule done */
/* including ARGModule bodies */
Ts Ytu_() {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6650100;
 r = (((Y6fX == NULL)) ? (0) : (1));
 topFrame = sf.prev;
 return r;
}
Ti Yd2Z() {
 Ti r = 0;
 YY8i();
 r = ZListSize(Y6fX);
 return r;
}
Tc *YtgL(Ti Aindex) {
 Tc *r = 0;
 int rt = 0;
 YY8i();
 if (((Aindex < 0) || (Aindex >= ZListSize(Y6fX))))
 {
  r = NULL;
  rt = 1;
  goto YJ1M;
 }
 r = ((Tc *)ZListGetPtr(Y6fX, Aindex));
YJ1M:
 return r;
}
To ToYnU5[] = {
 {0, 0},
};
char *StrYnU5[] = {
};
Tto YnU5__T = {390, (Tc*)&Yr32, 0, StrYnU5, ToYnU5};
void YY8i() {
 Tr t0 = {NULL};
 if ((Y6fX == NULL))
 {
  Tr ex;
  *Znao(&ex, YVNj__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YeBP)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 return;
}
void YZH8() {
 Zsf sf;
 Tc *Varg = NULL;
 Tc *Vvalue = NULL;
 Tc *Vflagname = NULL;
 Tc *Vflagname1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vk = NULL;
 Tl *Zf21 = NULL;
 Tc *Vk1 = NULL;
 Tr Vflag = {NULL};
 Y86c *Vbflag = 0;
 Y86c *Vbflag1 = 0;
 Y_SI *Vsflag = 0;
 YJQu *Viflag = 0;
 YzqH *Vsflag1 = 0;
 Tr t0 = {NULL};
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8253300;
 if ((Y6fX == NULL))
 {
  Tb VdoFlags;
  Tb Vskip;
  sf.pos=8253301;
  if ((Y7be == NULL))
  {
   sf.pos=8253302;
   Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
   sf.pos=8253303;
   YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  }
  sf.pos=8253304;
  if ((YUBd && (((ZDictSize(Y7be) > 0) || (ZDictSize(YBQy) > 0)))))
  {
   Tr ex;
   sf.pos=8253305;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y7T_)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=8253306;
  {
   Tfl Zf2i;
   Zf2 = ZDictKeys(Y7be, 0);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vk;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Tr YXyJ = {NULL};
   sf.pos=8253307;
   (YXyJ = ZDictGetIobj(Y7be, (Tz)(void*)Vk), ((void (*)(void*))(YXyJ.table[17]))(YXyJ.ptr));
   sf.pos=8253308;
   }
  }
  sf.pos=8253309;
  {
   Tfl Zf21i;
   Zf21 = ZDictKeys(YBQy, 0);
   Zf21i.l = Zf21;
   Zf21i.valp = (void*)&Vk1;
   Zf21i.i = 0;
   for (; ZforListPtrCont(&Zf21i); ) {
   Tr YWyJ = {NULL};
   sf.pos=8253310;
   (YWyJ = ZDictGetIobj(YBQy, (Tz)(void*)Vk1), ((void (*)(void*))(YWyJ.table[17]))(YWyJ.ptr));
   sf.pos=8253311;
   }
  }
  sf.pos=8253312;
  Y6fX = ZnewList((Tt*)&string__T, 0);
  sf.pos=8253313;
  VdoFlags = !(YUBd);
  Vskip = 0;
  sf.pos=8253314;
  {
   Ti Vi;
   Tfr Zf2;
   ZforRangeNew(0, (ZListSize(Y1p3) - 1), 0, 1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vi); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vi)) {
   sf.pos=8253315;
   if (Vskip)
   {
    sf.pos=8253316;
    Vskip = 0;
    rt = 4;
    if (rt) goto YgsM;
   }
   sf.pos=8253317;
   Varg = ((Tc *)ZListGetPtr(Y1p3, Vi));
   sf.pos=8253318;
   if (((!(VdoFlags) || (ZstringGetChar(Varg, 0) != 45)) || (ZstringCmp(Varg, ((Tc*)&YT)) == 0)))
   {
    sf.pos=8253319;
    ZLap((Tl*)Y6fX, (Tz)(void*)Varg);
    sf.pos=8253320;
    if (YQpY)
    {
     sf.pos=8253321;
     VdoFlags = 0;
    }
   }
   else
   {
    sf.pos=8253322;
    if ((ZstringCmp(Varg, ((Tc*)&Y1ia)) == 0))
    {
     sf.pos=8253323;
     VdoFlags = 0;
    }
    else
    {
     Vflag.ptr = NULL;
     Vvalue = NULL;
     sf.pos=8253324;
     if ((ZstringCmp(ZstringSlice(Varg, 0, 1, 0), ((Tc*)&Y1ia)) == 0))
     {
      Ti Vidx;
      sf.pos=8253325;
      Vflagname = ZstringSlice(Varg, 2, -1, 0);
      sf.pos=8253326;
      if ((!(YhUP) && ((((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) == 0) || (ZstringCmp(Vflagname, ((Tc*)&Y3via)) == 0)) || (ZstringCmp(Vflagname, ((Tc*)&Yll7)) == 0)))))
      {
       sf.pos=8253327;
       Yfj5((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) != 0));
      }
      sf.pos=8253328;
      Vidx = ZstringFindChar(Vflagname, 61, 0);
      sf.pos=8253329;
      if ((Vidx > 0))
      {
       sf.pos=8253330;
       Vvalue = ZstringSlice(Vflagname, (Vidx + 1), -1, 0);
       sf.pos=8253331;
       Vflagname = ZstringSlice(Vflagname, 0, (Vidx - 1), 0);
      }
      sf.pos=8253332;
      Vflag = ZDictGetIobjDef(YBQy, (Tz)(void*)Vflagname, trZero);
      sf.pos=8253333;
      if (((((Vflag).ptr) == NULL) && (ZstringCmp(ZstringSlice(Vflagname, 0, 1, 0), ((Tc*)&YhZb)) == 0)))
      {
       sf.pos=8253334;
       Vflag = ZDictGetIobjDef(YBQy, (Tz)(void*)ZstringSlice(Vflagname, 2, -1, 0), trZero);
       sf.pos=8253335;
       if ((((Vflag).ptr) != NULL))
       {
        sf.pos=8253336;
        if ((Vflag).type == 0)
        {
         sf.pos=8253337;
         Vflagname = ZstringSlice(Vflagname, 2, -1, 0);
         sf.pos=8253338;
         Vvalue = ((Tc*)&YhZb);
        }
        else
        {
         sf.pos=8253339;
         Vflag = trZero;
        }
       }
      }
     }
     else
     {
      Ti Vidx;
      sf.pos=8253340;
      Vflagname1 = ZstringSlice(Varg, 1, -1, 0);
      sf.pos=8253341;
      Vidx = ZstringFindChar(Vflagname1, 61, 0);
      sf.pos=8253342;
      if ((Vidx > 0))
      {
       sf.pos=8253343;
       Vvalue = ZstringSlice(Vflagname1, (Vidx + 1), -1, 0);
       sf.pos=8253344;
       Vflagname1 = ZstringSlice(Vflagname1, 0, (Vidx - 1), 0);
      }
      else
      {
       sf.pos=8253345;
       while ((ZstringSize(Vflagname1) > 1))
       {
        sf.pos=8253346;
        Vflag = ZDictGetIobjDef(Y7be, (Tz)(void*)ZstringSlice(Vflagname1, 0, 0, 0), trZero);
        sf.pos=8253347;
        if ((((Vflag).ptr) == NULL))
        {
         rt = 2;
         goto Yy70;
        }
        else
        {
         sf.pos=8253348;
         if ((Vflag).type == 0)
         {
          sf.pos=8253349;
          ++((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])));
          sf.pos=8253351;
          Vbflag = ((Y86c *)Znio(0, 8253350, (Vflag)));
          sf.pos=8253352;
          Vbflag->Vcurrent = !(Vbflag->Vdefault);
          sf.pos=8253353;
          Vflagname1 = ZstringSlice(Vflagname1, 1, -1, 0);
          sf.pos=8253354;
          Vflag = trZero;
         }
         else {
         sf.pos=8253355;
 if ((Vflag).type == 3)
         {
          rt = 2;
          goto YuBh;
         }
         else {
         sf.pos=8253356;
 if ((!(Y_kI) && !((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[7])))))
         {
          sf.pos=8253357;
          Vvalue = ZstringSlice(Vflagname1, 1, -1, 0);
          sf.pos=8253358;
          Vflagname1 = ZstringSlice(Vflagname1, 0, 0, 0);
         }
         }}
YuBh:
         if (rt) goto Yy70;
        }
Yy70:
        if (rt == 2) { rt &= 1; break; }
       sf.pos=8253359;
       }
      }
      sf.pos=8253360;
      if ((ZstringSize(Vflagname1) != 1))
      {
       sf.pos=8253361;
       YSUO(ZcS(((Tc*)&YcW8), Varg));
      }
      else {
      sf.pos=8253362;
 if ((((Vflag).ptr) == NULL))
      {
       sf.pos=8253363;
       Vflag = ZDictGetIobjDef(Y7be, (Tz)(void*)Vflagname1, trZero);
      }
      }
     }
     sf.pos=8253364;
     if ((((Vflag).ptr) == NULL))
     {
      sf.pos=8253365;
      if (!(YUBd))
      {
       sf.pos=8253366;
       YSUO(ZcS(((Tc*)&Y2hB), Varg));
      }
     }
     else
     {
      sf.pos=8253367;
      if ((((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])) > 0) && !((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[6])))))
      {
       sf.pos=8253368;
       YSUO(ZcS(((Tc*)&YcLH), Varg));
      }
      sf.pos=8253369;
      ++((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])));
      sf.pos=8253370;
      if ((Vflag).type == 0)
      {
       sf.pos=8253372;
       Vbflag1 = ((Y86c *)Znio(0, 8253371, (Vflag)));
       sf.pos=8253373;
       if ((Vvalue != NULL))
       {
        sf.pos=8253374;
        if (((ZstringCmp(Vvalue, ((Tc*)&YjK7)) == 0) || (ZstringCmp(Vvalue, ((Tc*)&YsfP)) == 0)))
        {
         sf.pos=8253375;
         Vbflag1->Vcurrent = 1;
        }
        else {
        sf.pos=8253376;
 if (((ZstringCmp(Vvalue, ((Tc*)&YhZb)) == 0) || (ZstringCmp(Vvalue, ((Tc*)&YvpX)) == 0)))
        {
         sf.pos=8253377;
         Vbflag1->Vcurrent = 0;
        }
        else
        {
         sf.pos=8253378;
         YSUO(ZcS(((Tc*)&YHSJ), Varg));
        }
        }
       }
       else
       {
        sf.pos=8253379;
        Vbflag1->Vcurrent = !(Vbflag1->Vdefault);
       }
      }
      else {
      sf.pos=8253380;
 if ((Vflag).type == 3)
      {
       sf.pos=8253381;
       if ((Vvalue != NULL))
       {
        sf.pos=8253382;
        YSUO(ZcS(((Tc*)&Y6QK), Varg));
       }
       sf.pos=8253384;
       Vsflag = ((Y_SI *)Znio(3, 8253383, (Vflag)));
       sf.pos=8253385;
       Vsflag->Vcurrent = ZnewList((Tt*)&string__T, 0);
       sf.pos=8253386;
       {
        Ti Vj;
        Tfr Zf7;
        ZforRangeNew((Vi + 1), (ZListSize(Y1p3) - 1), 0, 1, &Zf7);
        for (ZforRangeGetInt(&Zf7, &Vj); ZforRangeContInt(&Zf7); ZforRangeNextInt(&Zf7, &Vj)) {
        sf.pos=8253387;
        ZLap((Tl*)Vsflag->Vcurrent, (Tz)(void*)((Tc *)ZListGetPtr(Y1p3, Vj)));
        sf.pos=8253388;
        }
       }
       rt = 2;
       goto YxuQ;
      }
      else
      {
       sf.pos=8253389;
       if ((!((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[8]))) && (Vvalue == NULL)))
       {
        sf.pos=8253390;
        Vskip = 1;
        sf.pos=8253391;
        if ((Vi == (ZListSize(Y1p3) - 1)))
        {
         sf.pos=8253392;
         YSUO(ZcS(((Tc*)&Y_ju), Varg));
        }
        sf.pos=8253393;
        Vvalue = ((Tc *)ZListGetPtr(Y1p3, (Vi + 1)));
       }
       sf.pos=8253394;
       if ((Vflag).type == 1)
       {
        sf.pos=8253396;
        Viflag = ((YJQu *)Znio(1, 8253395, (Vflag)));
        sf.pos=8253397;
        if ((Vvalue == NULL))
        {
         sf.pos=8253398;
         Viflag->Vcurrent = Viflag->Vdefault;
         sf.pos=8253399;
         ZLap((Tl*)Viflag->VtheValueList, (Tz)(Ti)Viflag->Vdefault);
        }
        else
        {
         Ti VintVal;
         sf.pos=8253400;
         VintVal = ZstringToInt(Vvalue, 1, 0);
         sf.pos=8253401;
         Viflag->Vcurrent = VintVal;
         sf.pos=8253402;
         ZLap((Tl*)Viflag->VtheValueList, (Tz)(Ti)VintVal);
        }
       }
       else {
       sf.pos=8253403;
 if ((Vflag).type == 2)
       {
        sf.pos=8253405;
        Vsflag1 = ((YzqH *)Znio(2, 8253404, (Vflag)));
        sf.pos=8253406;
        if ((Vvalue == NULL))
        {
         sf.pos=8253407;
         Vsflag1->Vcurrent = Vsflag1->Vdefault;
         sf.pos=8253408;
         ZLap((Tl*)Vsflag1->VtheValueList, (Tz)(void*)Vsflag1->Vdefault);
        }
        else
        {
         sf.pos=8253409;
         Vsflag1->Vcurrent = Vvalue;
         sf.pos=8253410;
         ZLap((Tl*)Vsflag1->VtheValueList, (Tz)(void*)Vvalue);
        }
       }
       else
       {
        Tr ex;
        sf.pos=8253411;
        *Znao(&ex, YrHq__YwtA__YRHR(NULL, ((Tc*)&YjTs)), YrHq__Ytlm_I_imt, 26);
        ZthrowIobject(ex);
       }
       }
      }
      }
YxuQ:
      if (rt) goto YdgD;
     }
YdgD:
     if (rt) goto YOd6;
    }
YOd6:
    if (rt) goto YgsM;
   }
YgsM:
   if (rt == 2) { rt &= 1; break; }
   if (rt == 4) { rt &= 1; continue; }
   sf.pos=8253412;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YSUO(Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8529500;
 ((Ts (*)(void*, Tc*))(YeNQ.table[11]))(YeNQ.ptr, Amsg);
 sf.pos=8529501;
 if ((Yun4 != NULL))
 {
  sf.pos=8529502;
  Yl0k(YAMW(Yun4));
 }
 sf.pos=8529503;
 if (!(YhUP))
 {
  sf.pos=8529504;
  ((Ts (*)(void*, Tc*))(YeNQ.table[11]))(YeNQ.ptr, ZcS3(((Tc*)&YkFE), YzvW, ((Tc*)&Y15F)));
 }
 sf.pos=8529505;
 Zexit(NULL, 1);
 topFrame = sf.prev;
 return;
}
void Yfj5(Tb Averbose) {
 Ti VmaxLeadLen;
 Zsf sf;
 Td *VallFlags = NULL;
 Tl *Zf1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vkey = NULL;
 Tc *VargText = NULL;
 Tc *Vlead = NULL;
 Tl *Zf11 = NULL;
 Tc *Vkey1 = NULL;
 Tr Vflag = {NULL};
 Tr Vflag1 = {NULL};
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2956000;
 if ((Yun4 != NULL))
 {
  sf.pos=2956001;
  Yl0k(YAMW(Yun4));
 }
 sf.pos=2956002;
 Yl0k(((Tc*)&YaBy));
 sf.pos=2956003;
 VallFlags = Y7be;
 sf.pos=2956004;
 {
  Tfl Zf11i;
  Zf11 = ZDictKeys(YBQy, 0);
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vkey1;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=2956005;
  Vflag = ZDictGetIobj(YBQy, (Tz)(void*)Vkey1);
  sf.pos=2956006;
  if (((*(Tc**)(Vflag.ptr + (size_t)Vflag.table[1])) == NULL))
  {
   sf.pos=2956007;
   *ZDictGetIobjP(VallFlags, (Tz)(void*)(*(Tc**)(Vflag.ptr + (size_t)Vflag.table[2]))) = Vflag;
  }
  sf.pos=2956008;
  }
 }
 VmaxLeadLen = 0;
 sf.pos=2956009;
 {
  Ti Vdisplay;
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&bool__T, 2), ZLap((Tl*)t0, (Tz)(Ti)0), ZLap((Tl*)t0, (Tz)(Ti)1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdisplay;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=2956010;
  if (Vdisplay)
  {
   sf.pos=2956011;
   YTlu(((Tc*)&YwXF), VmaxLeadLen);
   sf.pos=2956012;
   Yl0k(((Tc*)&YEcf));
  }
  sf.pos=2956013;
  {
   Tfl Zf2i;
   Zf2 = ZstringListSort(ZDictKeys(VallFlags, 0), 1);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vkey;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Tb Vopt;
   sf.pos=2956014;
   Vflag1 = ZDictGetIobj(VallFlags, (Tz)(void*)Vkey);
   sf.pos=2956015;
   VargText = ((Tc*)&Ya);
   Vopt = 0;
   sf.pos=2956016;
   if ((Vflag1).type == 1)
   {
    sf.pos=2956017;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956018;
     VargText = ((Tc*)&Yy2p);
    }
    else
    {
     sf.pos=2956019;
     VargText = (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4]));
    }
    sf.pos=2956020;
    Vopt = (*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[8]));
   }
   else {
   sf.pos=2956021;
 if ((Vflag1).type == 2)
   {
    sf.pos=2956022;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956023;
     VargText = ((Tc*)&YanE);
    }
    else
    {
     sf.pos=2956024;
     VargText = (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4]));
    }
    sf.pos=2956025;
    Vopt = (*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[8]));
   }
   else {
   sf.pos=2956026;
 if ((Vflag1).type == 3)
   {
    sf.pos=2956027;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956028;
     VargText = ((Tc*)&YDci);
    }
    else
    {
     sf.pos=2956029;
     VargText = ZcS((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])), ((Tc*)&YulU));
    }
    sf.pos=2956030;
    Vopt = 1;
   }
   }}
   sf.pos=2956031;
   if ((ZbyteStringSize(VargText) != 0))
   {
    sf.pos=2956032;
    if (Vopt)
    {
     sf.pos=2956033;
     VargText = ZcS3(((Tc*)&YVZ), VargText, ((Tc*)&YEa));
    }
    else
    {
     sf.pos=2956034;
     VargText = ZcS3(((Tc*)&Yq_), VargText, ((Tc*)&Y9a));
    }
   }
   sf.pos=2956035;
   Vlead = ((Tc*)&Ya);
   sf.pos=2956036;
   if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[1])) != NULL))
   {
    sf.pos=2956037;
    Vlead = ZcS5(((Tc*)&YT), (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[1])), VargText, ((Tc*)&YG), (Tc*)1);
   }
   sf.pos=2956038;
   if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[2])) != NULL))
   {
    sf.pos=2956039;
    if (((ZbyteStringSize(Vlead) != 0) && (ZbyteStringSize(VargText) != 0)))
    {
     sf.pos=2956040;
     if (Vdisplay)
     {
      sf.pos=2956041;
      if ((*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[6])))
      {
       sf.pos=2956042;
       Vlead =  ZcS(Vlead, ((Tc*)&Y_y2));
      }
      sf.pos=2956043;
      Yl0k(Vlead);
     }
     sf.pos=2956044;
     Vlead = ((Tc*)&Ya);
    }
    sf.pos=2956045;
    Vlead =  ZcS(Vlead, ZcS5(((Tc*)&Y1ia), (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[2])), VargText, ((Tc*)&YG), (Tc*)1));
   }
   sf.pos=2956046;
   if ((*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[6])))
   {
    sf.pos=2956047;
    Vlead =  ZcS(Vlead, ((Tc*)&Y2yA));
   }
   sf.pos=2956048;
   if (Vdisplay)
   {
    sf.pos=2956049;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[3])) != NULL))
    {
     sf.pos=2956050;
     YTlu(Vlead, VmaxLeadLen);
     sf.pos=2956051;
     Yl0k((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[3])));
    }
    else
    {
     sf.pos=2956052;
     Yl0k(Vlead);
    }
    sf.pos=2956053;
    if (Averbose)
    {
     sf.pos=2956054;
     YTlu(((Tc*)&Ya), VmaxLeadLen);
     sf.pos=2956055;
     Yl0k(ZcS(((Tc*)&Ym4c), YpI_((*(YkxB**)(Vflag1.ptr + (size_t)Vflag1.table[9])))));
    }
   }
   else
   {
    sf.pos=2956056;
    if ((VmaxLeadLen < ZstringSize(Vlead)))
    {
     sf.pos=2956057;
     VmaxLeadLen = ZstringSize(Vlead);
    }
    sf.pos=2956058;
    if ((VmaxLeadLen > 30))
    {
     sf.pos=2956059;
     VmaxLeadLen = 30;
     rt = 2;
     goto YAEw;
    }
YAEw:
    if (rt) goto Yfan;
   }
Yfan:
   if (rt == 2) { rt &= 1; break; }
   sf.pos=2956060;
   }
  }
  sf.pos=2956061;
  }
 }
 sf.pos=2956062;
 Zexit(NULL, YMLU);
 topFrame = sf.prev;
 return;
}
void YTlu(Tc *Alead, Ti AmaxLeadLen) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8179800;
 Yvcu(Alead);
 sf.pos=8179801;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(ZstringSize(Alead), AmaxLeadLen, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=8179802;
  Yvcu(((Tc*)&YG));
  sf.pos=8179803;
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YAMW(YuMQ *t) {
 Ti Vidx;
 Zsf sf;
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4300000;
  ZthrowThisNil();
 }
 sf.pos=4300001;
 Vidx = ZstringFind(t->Vtext, ((Tc*)&YMtG), 0);
 sf.pos=4300002;
 if ((Vidx < 0))
 {
  sf.pos=4300003;
  r = t->Vtext;
  rt = 1;
  goto YZtK;
 }
 sf.pos=4300004;
 r = ZcS3(ZstringSlice(t->Vtext, 0, (Vidx - 1), 0), YzvW, (t0 = ZstringSlice(t->Vtext, (Vidx + 3), -1, 0)));
YZtK:
 topFrame = sf.prev;
 return r;
}
To ToYuMQ[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* text */
};
char *StrYuMQ[] = {
 "text",
};
Tto YuMQ__T = {390, (Tc*)&Y6qT, 0, StrYuMQ, ToYuMQ};
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=327300; t = Za(sizeof(Y86c));}
 sf.pos=327301;
 Y86c__YcLu(t, AshortName, AlongName, Adoc, MZ__callerPos());
 sf.pos=327302;
 t->Vcurrent = Adefault;
 sf.pos=327303;
 t->Vdefault = Adefault;
 sf.pos=327304;
 t->VcanRepeat = 1;
 topFrame = sf.prev;
 return t;
}
void YEqoa(Y86c *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3891100;
  ZthrowThisNil();
 }
 sf.pos=3891101;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
Tb YHoR(Y86c *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->Vcurrent;
 return r;
}
Tb YuOS(Y86c *t) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6128400;
  ZthrowThisNil();
 }
 sf.pos=6128401;
 r = YHoR(t);
 topFrame = sf.prev;
 return r;
}
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) {
 Zsf sf;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7664400; t = Za(sizeof(Y86c));}
 sf.pos=7664401;
 if ((Y6fX != NULL))
 {
  Tr ex;
  sf.pos=7664402;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Yc_h)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=7664403;
 if (((((AshortName == NULL) || (ZbyteStringSize(AshortName) == 0))) && (((AlongName == NULL) || (ZbyteStringSize(AlongName) == 0)))))
 {
  Tr ex;
  sf.pos=7664404;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y6pY)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=7664405;
 if ((ZbyteStringSize(AshortName) != 0))
 {
  sf.pos=7664406;
  t->VshortName = AshortName;
 }
 sf.pos=7664407;
 if ((ZbyteStringSize(AlongName) != 0))
 {
  sf.pos=7664408;
  t->VlongName = AlongName;
 }
 sf.pos=7664409;
 t->Vdoc = Adoc;
 sf.pos=7664410;
 if ((Y7be == NULL))
 {
  sf.pos=7664411;
  Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  sf.pos=7664412;
  YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
 }
 sf.pos=7664413;
 if (((AlongName != NULL) && (ZbyteStringSize(AlongName) != 0)))
 {
  sf.pos=7664414;
  if (ZDictHas(YBQy, (Tz)(void*)AlongName))
  {
   sf.pos=7664415;
   Y86c__YofP(t, AlongName, ZDictGetIobj(YBQy, (Tz)(void*)AlongName), Apos);
  }
  sf.pos=7664416;
  ZDictAddTzIobj(0, YBQy, (Tz)(void*)AlongName, *Znao(&t0, t, Y86c__YuQR_I_imt, 0));
 }
 sf.pos=7664417;
 if (((AshortName != NULL) && (ZbyteStringSize(AshortName) != 0)))
 {
  sf.pos=7664418;
  if ((ZstringSize(AshortName) > 1))
  {
   Tr ex;
   sf.pos=7664419;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y9CP)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=7664420;
  if (ZDictHas(Y7be, (Tz)(void*)AshortName))
  {
   sf.pos=7664421;
   Y86c__YofP(t, AshortName, ZDictGetIobj(Y7be, (Tz)(void*)AshortName), Apos);
  }
  sf.pos=7664422;
  ZDictAddTzIobj(0, Y7be, (Tz)(void*)AshortName, *Znao(&t0, t, Y86c__YuQR_I_imt, 0));
 }
 sf.pos=7664423;
 t->Vpos = Apos;
 topFrame = sf.prev;
 return t;
}
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos) {
 void *Y_CE = NULL;
 void *p1;
 Tr ex;
 Zsf sf;
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7569700;
  ZthrowThisNil();
 }
 sf.pos=7569701;
 VonePos = ((p1 = ((Y_CE = (*(YkxB**)(Aflag.ptr + (size_t)Aflag.table[9])), Y_CE == NULL ? NULL : YpI_(Y_CE)))) == NULL ? (((Tc*)&YbbH)) : p1);
 sf.pos=7569702;
 Ve = YVNj__YwtA__YRHRa(NULL, Apos, ZcS5(((Tc*)&YtzG), Aname, ((Tc*)&YDyy), VonePos, (Tc*)1));
 sf.pos=7569703;
 *Znao(&ex, Ve, YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Ti Y86c__Ye9f(Y86c *t) {
 Ti r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->VsetCount;
 return r;
}
Tc *Y86c__YuQR_I_imt[] = {
 (Tc*)&Y86c__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)Y86c__YcLu, /* MARGModule__CBool.NEW - Y86c__YcLu */
 (Tc*)Y86c__YofP, /* MARGModule__CBool.throwDuplicate - Y86c__YofP */
 (Tc*)0, /* MARGModule__CBool.setArgName - Y86c__Y836 */
 (Tc*)0, /* MARGModule__CBool.disableCompact - Y86c__YJbb */
 (Tc*)0, /* MARGModule__CBool.optionalArg - Y86c__YxuH */
 (Tc*)Y86c__Ye9f, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
 (Tc*)0, /* MARGModule__CBool.present - Y86c__Y8Dq */
 (Tc*)YEqoa, /* MARGModule__CBool.setToDefault - YEqoa */
 (Tc*)0, /* Init - Y86ca */
};
To ToY86c[] = {
 {11, 0},
 {0, (Tt*)&bool__T}, /* current */
 {0, (Tt*)&bool__T}, /* default */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&int__T}, /* setCount */
 {0, (Tt*)&bool__T}, /* canRepeat */
 {0, (Tt*)&bool__T}, /* noCompactVal */
 {0, (Tt*)&bool__T}, /* argOpt */
 {0, (Tt*)&YkxB__T}, /* pos */
};
char *StrY86c[] = {
 "current",
 "default",
 "shortName",
 "longName",
 "doc",
 "argName",
 "setCount",
 "canRepeat",
 "noCompactVal",
 "argOpt",
 "pos",
};
Tto Y86c__T = {390, (Tc*)&YZ1F, 0, StrY86c, ToY86c};
void Y49ga(YJQu *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1635000;
  ZthrowThisNil();
 }
 sf.pos=1635001;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToYJQu[] = {
 {12, 0},
 {0, (Tt*)&int__T}, /* current */
 {0, (Tt*)&int__T}, /* default */
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&int__T}, /* setCount */
 {0, (Tt*)&bool__T}, /* canRepeat */
 {0, (Tt*)&bool__T}, /* noCompactVal */
 {0, (Tt*)&bool__T}, /* argOpt */
 {0, (Tt*)&YkxB__T}, /* pos */
};
char *StrYJQu[] = {
 "current",
 "default",
 "theValueList",
 "shortName",
 "longName",
 "doc",
 "argName",
 "setCount",
 "canRepeat",
 "noCompactVal",
 "argOpt",
 "pos",
};
Tto YJQu__T = {390, (Tc*)&YzBa, 0, StrYJQu, ToYJQu};
void YJaza(YzqH *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8620600;
  ZthrowThisNil();
 }
 sf.pos=8620601;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToYzqH[] = {
 {12, 0},
 {0, (Tt*)&string__T}, /* current */
 {0, (Tt*)&string__T}, /* default */
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&int__T}, /* setCount */
 {0, (Tt*)&bool__T}, /* canRepeat */
 {0, (Tt*)&bool__T}, /* noCompactVal */
 {0, (Tt*)&bool__T}, /* argOpt */
 {0, (Tt*)&YkxB__T}, /* pos */
};
char *StrYzqH[] = {
 "current",
 "default",
 "theValueList",
 "shortName",
 "longName",
 "doc",
 "argName",
 "setCount",
 "canRepeat",
 "noCompactVal",
 "argOpt",
 "pos",
};
Tto YzqH__T = {390, (Tc*)&YDAE, 0, StrYzqH, ToYzqH};
void YSkKa(Y_SI *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6447800;
  ZthrowThisNil();
 }
 sf.pos=6447801;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToY_SI[] = {
 {11, 0},
 {0, (Tt*)&list__T}, /* current */
 {0, (Tt*)&list__T}, /* default */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&int__T}, /* setCount */
 {0, (Tt*)&bool__T}, /* canRepeat */
 {0, (Tt*)&bool__T}, /* noCompactVal */
 {0, (Tt*)&bool__T}, /* argOpt */
 {0, (Tt*)&YkxB__T}, /* pos */
};
char *StrY_SI[] = {
 "current",
 "default",
 "shortName",
 "longName",
 "doc",
 "argName",
 "setCount",
 "canRepeat",
 "noCompactVal",
 "argOpt",
 "pos",
};
Tto Y_SI__T = {390, (Tc*)&Ygf5, 0, StrY_SI, ToY_SI};
int JARGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
  if (round == 0) {
  done = 0;
  } else if (round > 2001) {
    if (Ytu___r == 0) {
      Ytu___r = Ytu_();
      done &= Ytu___r;
    }
  }
  topFrame = sf.prev;
 }
 return done;
}
/* ARGModule done */
/* including INTModule bodies */
Tb YBbQ(Ti Athis) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3626700;
 r = ((Athis <= 32) || (((Athis >= 127) && (Athis <= 160))));
 topFrame = sf.prev;
 return r;
}
/* INTModule done */
/* including Input bodies */
YeYq *YOdr(YeYq *t, Tr Afd, Tc *Afname, Tc *Aindent, Tb Arecord) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4440100; t = Za(sizeof(YeYq));}
 sf.pos=4440101;
 t->Vfd = Afd;
 sf.pos=4440102;
 t->Vpos = Ypp_(NULL, Afname);
 sf.pos=4440103;
 t->VcharStack = ZnewList((Tt*)&int__T, 0);
 sf.pos=4440104;
 t->Vindent = Aindent;
 sf.pos=4440105;
 if (Arecord)
 {
  sf.pos=4440106;
  t->VrecordWriter = Za(sizeof(YjUM));
 }
 topFrame = sf.prev;
 return t;
}
Ti YAit(YeYq *t) {
 Ti Vc;
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1988700;
  ZthrowThisNil();
 }
 Vc = 0;
 sf.pos=1988701;
 if ((ZListSize(t->VcharStack) > 0))
 {
  sf.pos=1988702;
  Vc = ZListRemoveIntItem((Tl*)t->VcharStack, -1);
  sf.pos=1988703;
  ++(t->Vpos->Vcol);
 }
 else {
 sf.pos=1988704;
 if ((((t->Vfd).ptr) == NULL))
 {
  sf.pos=1988705;
  if ((t->VtextIdx >= ZstringSize(t->Vtext)))
  {
   sf.pos=1988706;
   Vc = Y3QJ;
  }
  else
  {
   sf.pos=1988707;
   Vc = ZstringGetChar(t->Vtext, t->VtextIdx);
   sf.pos=1988708;
   ++(t->VtextIdx);
   sf.pos=1988709;
   ++(t->Vpos->Vcol);
  }
 }
 else
 {
  sf.pos=1988710;
  for (;;)
  {
   sf.pos=1988711;
   Vc = ((Ti (*)(void*))(t->Vfd.table[23]))(t->Vfd.ptr);
   sf.pos=1988712;
   ++(t->Vpos->Vcol);
   sf.pos=1988713;
   if (((((Vc >= 0) && (Vc <= 31))) || (((Vc >= 127) && (Vc <= 160)))))
   {
    sf.pos=1988714;
    if ((Vc == 0))
    {
     sf.pos=1988715;
     YDli(((Tc*)&YrKy), t->Vpos, 0);
     sf.pos=1988716;
     Vc = 32;
    }
    else {
    sf.pos=1988717;
 if ((Vc == 9))
    {
     sf.pos=1988718;
     if (!(t->VallowTabs))
     {
      sf.pos=1988719;
      YDli(((Tc*)&YemR), t->Vpos, 0);
     }
     sf.pos=1988720;
     Vc = 32;
    }
    else {
    sf.pos=1988721;
 if (((Vc != 13) && (Vc != 10)))
    {
     sf.pos=1988722;
     YDli(((Tc*)&Y3Pw), t->Vpos, 0);
     sf.pos=1988723;
     Vc = 32;
    }
    }}
   }
   sf.pos=1988724;
   if (((Vc != 13) && (Vc != 65279))) break;
  sf.pos=1988725;
  }
 }
 }
 sf.pos=1988726;
 if ((Vc == 10))
 {
  sf.pos=1988727;
  t->VprevLineCol = t->Vpos->Vcol;
  sf.pos=1988728;
  YnS4(t->Vpos);
 }
 sf.pos=1988729;
 if (((t->VrecordWriter != NULL) && (Vc != Y3QJ)))
 {
  sf.pos=1988730;
  YjUM__Ydti(t->VrecordWriter, Vc);
 }
 sf.pos=1988731;
 r = Vc;
 topFrame = sf.prev;
 return r;
}
void YmK2(YeYq *t, Ti Ac) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3404700;
  ZthrowThisNil();
 }
 sf.pos=3404701;
 if ((Ac != Y3QJ))
 {
  sf.pos=3404702;
  ZLap((Tl*)t->VcharStack, (Tz)(Ti)Ac);
  sf.pos=3404703;
  if ((Ac == 10))
  {
   sf.pos=3404704;
   t->Vpos->Vcol = t->VprevLineCol;
   sf.pos=3404705;
   --(t->Vpos->Vlnum);
  }
  else
  {
   sf.pos=3404706;
   --(t->Vpos->Vcol);
  }
  sf.pos=3404707;
  if ((t->VrecordWriter != NULL))
  {
   sf.pos=3404708;
   Y6jW(t->VrecordWriter);
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YJ25(YeYq *t) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vs = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8659400;
  ZthrowThisNil();
 }
 sf.pos=8659401;
 Vs = YbNW(t->VrecordWriter);
 sf.pos=8659402;
 YXip(t->VrecordWriter);
 sf.pos=8659403;
 r = Vs;
 topFrame = sf.prev;
 return r;
}
To ToYeYq[] = {
 {9, 0},
 {0, (Tt*)&iobj__T}, /* fd */
 {0, (Tt*)&string__T}, /* text */
 {0, (Tt*)&int__T}, /* textIdx */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&int__T}, /* prevLineCol */
 {0, (Tt*)&list__T}, /* charStack */
 {0, (Tt*)&string__T}, /* indent */
 {0, (Tt*)&bool__T}, /* allowTabs */
 {0, (Tt*)&YjUM__T}, /* recordWriter */
};
char *StrYeYq[] = {
 "fd",
 "text",
 "textIdx",
 "pos",
 "prevLineCol",
 "charStack",
 "indent",
 "allowTabs",
 "recordWriter",
};
Tto YeYq__T = {390, (Tc*)&YVUW, 0, StrYeYq, ToYeYq};
/* Input done */
/* including Token bodies */
/* including zui bodies */
/* including Proto bodies */
Ys_q *Ys_q__YwtA__YRHR(Ys_q *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7083300; t = Za(sizeof(Ys_q));}
 sf.pos=7083301;
 t->Vmessage = Amsg;
 sf.pos=7083302;
 t->Vpos = MZ__callerPos();
 sf.pos=7083303;
 t->Vbacktrace = (sf.pos=7083304, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Ys_q__YwtA__YH0V(Ys_q *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6879700;
  ZthrowThisNil();
 }
 sf.pos=6879701;
 Vw = Za(sizeof(YjUM));
 sf.pos=6879702;
 Ys_q__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6879703;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Ys_q__YwtA__YxaJa(Ys_q *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6348300;
  ZthrowThisNil();
 }
 sf.pos=6348301;
 Ys_q__YwtA__YxaJ(t, Aw);
 sf.pos=6348302;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=6348303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=6348304;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=6348305;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=6348306;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=6348307;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=6348308;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=6348309;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=6348310;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=6348311;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=6348312;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void Ys_q__YwtA__YxaJ(Ys_q *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7368400;
  ZthrowThisNil();
 }
 sf.pos=7368401;
 if ((t->Vpos != NULL))
 {
  sf.pos=7368402;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=7368403;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=7368404;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=7368405;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=7368406;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=7368407;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *Ys_q__Ytlm_I_imt[] = {
 (Tc*)&Ys_q__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MProto__CE_ProduceError.NEW - Ys_q__YwtA__YRHRa */
 (Tc*)Ys_q__YwtA__YRHR, /* MProto__CE_ProduceError.NEW - Ys_q__YwtA__YRHR */
 (Tc*)Ys_q__YwtA__YH0V, /* MProto__CE_ProduceError.ToString - Ys_q__YwtA__YH0V */
 (Tc*)Ys_q__YwtA__YxaJa, /* MProto__CE_ProduceError.writeTo - Ys_q__YwtA__YxaJa */
 (Tc*)Ys_q__YwtA__YxaJ, /* MProto__CE_ProduceError.writeTo - Ys_q__YwtA__YxaJ */
 (Tc*)0, /* MProto__CE_ProduceError.toString - Ys_q__YwtA__Yoww */
 (Tc*)0, /* MProto__CE_ProduceError.getMessage - Ys_q__YwtA__YCzX */
 (Tc*)0, /* MProto__CE_ProduceError.getPos - Ys_q__YwtA__YvCK */
 (Tc*)0, /* MProto__CE_ProduceError.getBacktrace - Ys_q__YwtA__Y4bq */
 (Tc*)0, /* Init - Ys_qa */
};
To ToYs_q[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYs_q[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Ys_q__T = {390, (Tc*)&Y4sk, Ys_q__YwtA__YH0V, StrYs_q, ToYs_q};
YOEA *YOEA__YwtA__YRHR(YOEA *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4631200; t = Za(sizeof(YOEA));}
 sf.pos=4631201;
 t->Vmessage = Amsg;
 sf.pos=4631202;
 t->Vpos = MZ__callerPos();
 sf.pos=4631203;
 t->Vbacktrace = (sf.pos=4631204, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YOEA__YwtA__YH0V(YOEA *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3216000;
  ZthrowThisNil();
 }
 sf.pos=3216001;
 Vw = Za(sizeof(YjUM));
 sf.pos=3216002;
 YOEA__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=3216003;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YOEA__YwtA__YxaJa(YOEA *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7053000;
  ZthrowThisNil();
 }
 sf.pos=7053001;
 YOEA__YwtA__YxaJ(t, Aw);
 sf.pos=7053002;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=7053003;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=7053004;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=7053005;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=7053006;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=7053007;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=7053008;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=7053009;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=7053010;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=7053011;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=7053012;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YOEA__YwtA__YxaJ(YOEA *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8073100;
  ZthrowThisNil();
 }
 sf.pos=8073101;
 if ((t->Vpos != NULL))
 {
  sf.pos=8073102;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=8073103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=8073104;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=8073105;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=8073106;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=8073107;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YOEA__Ytlm_I_imt[] = {
 (Tc*)&YOEA__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MProto__CE_BinaryError.NEW - YOEA__YwtA__YRHRa */
 (Tc*)YOEA__YwtA__YRHR, /* MProto__CE_BinaryError.NEW - YOEA__YwtA__YRHR */
 (Tc*)YOEA__YwtA__YH0V, /* MProto__CE_BinaryError.ToString - YOEA__YwtA__YH0V */
 (Tc*)YOEA__YwtA__YxaJa, /* MProto__CE_BinaryError.writeTo - YOEA__YwtA__YxaJa */
 (Tc*)YOEA__YwtA__YxaJ, /* MProto__CE_BinaryError.writeTo - YOEA__YwtA__YxaJ */
 (Tc*)0, /* MProto__CE_BinaryError.toString - YOEA__YwtA__Yoww */
 (Tc*)0, /* MProto__CE_BinaryError.getMessage - YOEA__YwtA__YCzX */
 (Tc*)0, /* MProto__CE_BinaryError.getPos - YOEA__YwtA__YvCK */
 (Tc*)0, /* MProto__CE_BinaryError.getBacktrace - YOEA__YwtA__Y4bq */
 (Tc*)0, /* Init - YOEAa */
};
To ToYOEA[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYOEA[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YOEA__T = {390, (Tc*)&YtJ_, YOEA__YwtA__YH0V, StrYOEA, ToYOEA};
YqvM *Ykww(YqvM *t, Tc *Aname, Ti Anr, Te Atype, Tb Arepeated) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1366600; t = Za(sizeof(YqvM));}
 sf.pos=1366601;
 t->Vname = Aname;
 sf.pos=1366602;
 t->Vnr = Anr;
 sf.pos=1366603;
 t->Vtype = Atype;
 sf.pos=1366604;
 t->Vrepeated = Arepeated;
 topFrame = sf.prev;
 return t;
}
To ToYqvM[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&int__T}, /* nr */
 {0, (Tt*)&MProto__EType__T}, /* type */
 {0, (Tt*)&bool__T}, /* repeated */
};
char *StrYqvM[] = {
 "name",
 "nr",
 "type",
 "repeated",
};
Tto YqvM__T = {390, (Tc*)&Y5d5, 0, StrYqvM, ToYqvM};
YLWE *YrCUb(YLWE *t, Tr Awriter, Tc *Aindent, Tb AuseNr) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1246900; t = Za(sizeof(YLWE));}
 sf.pos=1246901;
 t->Vwriter = Awriter;
 sf.pos=1246902;
 t->Vindent = Aindent;
 sf.pos=1246903;
 t->VuseNr = AuseNr;
 sf.pos=1246904;
 YEV9(t);
 topFrame = sf.prev;
 return t;
}
void YEV9(YLWE *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3295600;
  ZthrowThisNil();
 }
 sf.pos=3295601;
 t->VderefTime = ++(YcTI);
 sf.pos=3295602;
 t->VderefTimeSize = t->VderefTime;
 topFrame = sf.prev;
 return;
}
To ToYLWE[] = {
 {7, 0},
 {0, (Tt*)&iobj__T}, /* writer */
 {0, (Tt*)&string__T}, /* indent */
 {0, (Tt*)&bool__T}, /* useNr */
 {0, (Tt*)&int__T}, /* derefId */
 {0, (Tt*)&int__T}, /* derefIdSize */
 {0, (Tt*)&int__T}, /* derefTime */
 {0, (Tt*)&int__T}, /* derefTimeSize */
};
char *StrYLWE[] = {
 "writer",
 "indent",
 "useNr",
 "derefId",
 "derefIdSize",
 "derefTime",
 "derefTimeSize",
};
Tto YLWE__T = {390, (Tc*)&YaKG, 0, StrYLWE, ToYLWE};
Ti Ybyp(YqvM *Afspec) {
 Ti Vtag;
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4959900;
 Vtag = (((Afspec->Vnr << YqNA)) + ZDictGetInt(YLwW, (Tz)(Ti)ZDictGetInt(YXCQ, (Tz)(Ti)Afspec->Vtype)));
 sf.pos=4959901;
 r = YmeT(Vtag);
 topFrame = sf.prev;
 return r;
}
Ti YFN0(Tr Amsg, YLWE *AprotoWriter) {
 Ti Vsize;
 Zsf sf;
 Ti r = 0;
 Tl *Zf1 = NULL;
 Tc *Vs = NULL;
 Tr Vother = {NULL};
 Tc *Vs1 = NULL;
 Tr Vother1 = {NULL};
 YqvM *Vfspec = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vsize = 0;
 sf.pos=9067900;
 {
  Tfl Zf1i;
  Zf1 = ((Tl* (*)(void*))(Amsg.table[43]))(Amsg.ptr);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vfspec;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=9067901;
  if (Vfspec->Vrepeated)
  {
   Ti Vcount;
   sf.pos=9067902;
   Vcount = ((Ti (*)(void*, Ti))(Amsg.table[42]))(Amsg.ptr, Vfspec->Vnr);
   sf.pos=9067903;
   {
    Ti Vi;
    Tfr Zf3;
    ZforRangeNew(0, Vcount, 1, 1, &Zf3);
    for (ZforRangeGetInt(&Zf3, &Vi); ZforRangeContInt(&Zf3); ZforRangeNextInt(&Zf3, &Vi)) {
    sf.pos=9067904;
    switch (Vfspec->Vtype)
    {
    case 9:
    case 11:
     {
      sf.pos=9067905;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067906;
      Vsize += YmeT(((Ti (*)(void*, Ti, Ti))(Amsg.table[11]))(Amsg.ptr, Vfspec->Vnr, Vi));
       break;
     }
    case 10:
     {
      sf.pos=9067907;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067908;
      Vsize += YmeT(((Ti32 (*)(void*, Ti, Ti))(Amsg.table[13]))(Amsg.ptr, Vfspec->Vnr, Vi));
       break;
     }
    case 19:
     {
      Ti Vv;
      sf.pos=9067909;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067910;
      Vv = ((Tu (*)(void*, Ti, Ti))(Amsg.table[15]))(Amsg.ptr, Vfspec->Vnr, Vi);
      sf.pos=9067911;
      Vsize += YmeT(Vv);
       break;
     }
    case 18:
     {
      Ti Vv;
      sf.pos=9067912;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067913;
      Vv = ((Tu32 (*)(void*, Ti, Ti))(Amsg.table[17]))(Amsg.ptr, Vfspec->Vnr, Vi);
      sf.pos=9067914;
      Vsize += YmeT(Vv);
       break;
     }
    case 6:
     {
      sf.pos=9067915;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067916;
      Vsize += 4;
       break;
     }
    case 7:
     {
      sf.pos=9067917;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067918;
      Vsize += 8;
       break;
     }
    case 1:
     {
      sf.pos=9067919;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067920;
      Vsize += 1;
       break;
     }
    case 17:
     {
      Ti Vlen;
      sf.pos=9067921;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067922;
      Vs = ((Tc* (*)(void*, Ti, Ti))(Amsg.table[25]))(Amsg.ptr, Vfspec->Vnr, Vi);
      sf.pos=9067923;
      Vlen = ZbyteStringSize(Vs);
      sf.pos=9067924;
      Vsize += (YmeT(Vlen) + Vlen);
       break;
     }
    case 3:
     {
      Ti Vnr;
      sf.pos=9067925;
      Vnr = ((Ti (*)(void*, Ti, Ti))(Amsg.table[7]))(Amsg.ptr, Vfspec->Vnr, Vi);
      sf.pos=9067926;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067927;
      Vsize += YmeT((((Vnr < 0)) ? (0) : (Vnr)));
       break;
     }
    case 12:
     {
      sf.pos=9067928;
      Vother = ((Tr (*)(void*, Ti, Ti))(Amsg.table[37]))(Amsg.ptr, Vfspec->Vnr, Vi);
      sf.pos=9067929;
      Vsize += YMrV(Amsg, Vother, Vfspec, AprotoWriter);
       break;
     }
    default:
     {
      Tr ex;
      sf.pos=9067930;
      *Znao(&ex, YOEA__YwtA__YRHR(NULL, ZcS(((Tc*)&Ytvm), Zenum2string(MProto__EType, Vfspec->Vtype))), YOEA__Ytlm_I_imt, 30);
      ZthrowIobject(ex);
     }
    }
    sf.pos=9067931;
    }
   }
  }
  else
  {
   sf.pos=9067932;
   if (((Tb (*)(void*, Ti))(Amsg.table[5]))(Amsg.ptr, Vfspec->Vnr))
   {
    sf.pos=9067933;
    switch (Vfspec->Vtype)
    {
    case 9:
    case 11:
     {
      sf.pos=9067934;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067935;
      Vsize += YmeT(((Ti (*)(void*, Ti))(Amsg.table[12]))(Amsg.ptr, Vfspec->Vnr));
       break;
     }
    case 10:
     {
      sf.pos=9067936;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067937;
      Vsize += YmeT(((Ti32 (*)(void*, Ti))(Amsg.table[14]))(Amsg.ptr, Vfspec->Vnr));
       break;
     }
    case 19:
     {
      Ti Vv;
      sf.pos=9067938;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067939;
      Vv = ((Tu (*)(void*, Ti))(Amsg.table[16]))(Amsg.ptr, Vfspec->Vnr);
      sf.pos=9067940;
      Vsize += YmeT(Vv);
       break;
     }
    case 18:
     {
      Ti Vv;
      sf.pos=9067941;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067942;
      Vv = ((Tu32 (*)(void*, Ti))(Amsg.table[18]))(Amsg.ptr, Vfspec->Vnr);
      sf.pos=9067943;
      Vsize += YmeT(Vv);
       break;
     }
    case 6:
     {
      sf.pos=9067944;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067945;
      Vsize += 4;
       break;
     }
    case 7:
     {
      sf.pos=9067946;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067947;
      Vsize += 8;
       break;
     }
    case 1:
     {
      sf.pos=9067948;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067949;
      Vsize += 1;
       break;
     }
    case 17:
     {
      Ti Vlen;
      sf.pos=9067950;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067951;
      Vs1 = ((Tc* (*)(void*, Ti))(Amsg.table[26]))(Amsg.ptr, Vfspec->Vnr);
      sf.pos=9067952;
      Vlen = ZbyteStringSize(Vs1);
      sf.pos=9067953;
      Vsize += (YmeT(Vlen) + Vlen);
       break;
     }
    case 3:
     {
      Ti Vnr;
      sf.pos=9067954;
      Vnr = ((Ti (*)(void*, Ti))(Amsg.table[8]))(Amsg.ptr, Vfspec->Vnr);
      sf.pos=9067955;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067956;
      Vsize += YmeT((((Vnr < 0)) ? (0) : (Vnr)));
       break;
     }
    case 12:
     {
      sf.pos=9067957;
      Vother1 = ((Tr (*)(void*, Ti))(Amsg.table[38]))(Amsg.ptr, Vfspec->Vnr);
      sf.pos=9067958;
      Vsize += YMrV(Amsg, Vother1, Vfspec, AprotoWriter);
       break;
     }
    default:
     {
      Tr ex;
      sf.pos=9067959;
      *Znao(&ex, YOEA__YwtA__YRHR(NULL, ZcS(((Tc*)&Ytvm), Zenum2string(MProto__EType, Vfspec->Vtype))), YOEA__Ytlm_I_imt, 30);
      ZthrowIobject(ex);
     }
    }
   }
  }
  sf.pos=9067960;
  }
 }
 sf.pos=9067961;
 r = Vsize;
 topFrame = sf.prev;
 return r;
}
Ti YMrV(Tr At, Tr Amsg, YqvM *Afspec, YLWE *AprotoWriter) {
 Ti Vsize;
 Zsf sf;
 Ti r = 0;
 YqvM *VintFspec = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vsize = 0;
 sf.pos=3788400;
 if ((((Amsg).ptr) == NULL))
 {
  sf.pos=3788401;
  Vsize = Ybyp(Afspec);
  sf.pos=3788402;
  Vsize += YmeT(0);
 }
 else
 {
  Tb Vdone;
  Vdone = 0;
  sf.pos=3788403;
  if (((AprotoWriter != NULL) && (AprotoWriter->VderefTime != 0)))
  {
   Ti Vid;
   sf.pos=3788404;
   Vid = -1;
   sf.pos=3788405;
   if (((*(Ti*)(Amsg.ptr + (size_t)Amsg.table[1])) == AprotoWriter->VderefTime))
   {
    sf.pos=3788406;
    Vid = (*(Ti*)(Amsg.ptr + (size_t)Amsg.table[2]));
   }
   else {
   sf.pos=3788407;
 if (((*(Ti*)(Amsg.ptr + (size_t)Amsg.table[3])) == AprotoWriter->VderefTimeSize))
   {
    sf.pos=3788408;
    Vid = (*(Ti*)(Amsg.ptr + (size_t)Amsg.table[4]));
   }
   }
   sf.pos=3788409;
   if ((Vid >= 0))
   {
    sf.pos=3788410;
    VintFspec = Ykww(NULL, NULL, Afspec->Vnr, 9, 0);
    sf.pos=3788411;
    Vsize += Ybyp(VintFspec);
    sf.pos=3788412;
    Vsize += YmeT(Vid);
    sf.pos=3788413;
    Vdone = 1;
   }
   else
   {
    sf.pos=3788414;
    (*(Ti*)(Amsg.ptr + (size_t)Amsg.table[3])) = AprotoWriter->VderefTimeSize;
    sf.pos=3788415;
    (*(Ti*)(Amsg.ptr + (size_t)Amsg.table[4])) = ++(AprotoWriter->VderefIdSize);
   }
  }
  sf.pos=3788416;
  if (!(Vdone))
  {
   Ti Vlen;
   sf.pos=3788417;
   Vsize += Ybyp(Afspec);
   sf.pos=3788418;
   Vlen = YFN0(Amsg, AprotoWriter);
   sf.pos=3788419;
   Vsize += YmeT(Vlen);
   sf.pos=3788420;
   Vsize += Vlen;
  }
 }
 sf.pos=3788421;
 r = Vsize;
 topFrame = sf.prev;
 return r;
}
void YP8Z(Tr Amsg, YLWE *AprotoWriter) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YqvM *Vfspec = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1929900;
 if ((AprotoWriter->Vindent != NULL))
 {
  Tr YCSo = {NULL};
  sf.pos=1929901;
  (YCSo = AprotoWriter->Vwriter, ((Ts (*)(void*, Tc*))(YCSo.table[1]))(YCSo.ptr, AprotoWriter->Vindent));
 }
 sf.pos=1929902;
 if (((*(Ti*)(Amsg.ptr + (size_t)Amsg.table[1])) == AprotoWriter->VderefTime))
 {
  Tr YDSo = {NULL};
  sf.pos=1929903;
  (YDSo = AprotoWriter->Vwriter, ((Ts (*)(void*, Tc*))(YDSo.table[1]))(YDSo.ptr, ZcS5(((Tc*)&YvJi), ((Tc* (*)(void*))(Amsg.table[6]))(Amsg.ptr), ((Tc*)&YT), (t0 = Zint2string((*(Ti*)(Amsg.ptr + (size_t)Amsg.table[2])))), ((Tc*)&Yk))));
 }
 else
 {
  Tr YESo = {NULL};
  sf.pos=1929904;
  (*(Ti*)(Amsg.ptr + (size_t)Amsg.table[1])) = AprotoWriter->VderefTime;
  sf.pos=1929905;
  (*(Ti*)(Amsg.ptr + (size_t)Amsg.table[2])) = ++(AprotoWriter->VderefId);
  sf.pos=1929906;
  (YESo = AprotoWriter->Vwriter, ((Ts (*)(void*, Tc*))(YESo.table[1]))(YESo.ptr, ZcS8(((Tc*)&YN2), ((Tc* (*)(void*))(Amsg.table[6]))(Amsg.ptr), ((Tc*)&YT), (t0 = Zint2string((*(Ti*)(Amsg.ptr + (size_t)Amsg.table[2])))), ((Tc*)&Y0Eh), (t1 = Zint2string(YFN0(Amsg, AprotoWriter))), ((Tc*)&Y8RH), (Tc*)1)));
  sf.pos=1929907;
  {
   Tfl Zf2i;
   Zf2 = ((Tl* (*)(void*))(Amsg.table[43]))(Amsg.ptr);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vfspec;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1929908;
   if (Vfspec->Vrepeated)
   {
    Ti Vn;
    sf.pos=1929909;
    Vn = ((Ti (*)(void*, Ti))(Amsg.table[42]))(Amsg.ptr, Vfspec->Vnr);
    sf.pos=1929910;
    {
     Ti Vi;
     Tfr Zf4;
     ZforRangeNew(0, Vn, 1, 1, &Zf4);
     for (ZforRangeGetInt(&Zf4, &Vi); ZforRangeContInt(&Zf4); ZforRangeNextInt(&Zf4, &Vi)) {
     sf.pos=1929911;
     YWEg(Amsg, Vfspec, Vi, AprotoWriter);
     sf.pos=1929912;
     }
    }
   }
   else {
   sf.pos=1929913;
 if (((Tb (*)(void*, Ti))(Amsg.table[5]))(Amsg.ptr, Vfspec->Vnr))
   {
    sf.pos=1929914;
    YWEg(Amsg, Vfspec, -1, AprotoWriter);
   }
   }
   sf.pos=1929915;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YWEg(Tr Amsg, YqvM *Afspec, Ti Aidx, YLWE *AprotoWriter) {
 Zsf sf;
 Tr Vwriter = {NULL};
 Tc *Vv = NULL;
 Tc *Vname = NULL;
 Tc *Vindent = NULL;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9472900;
 Vwriter = AprotoWriter->Vwriter;
 sf.pos=9472901;
 if ((AprotoWriter->Vindent != NULL))
 {
  sf.pos=9472902;
  ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, AprotoWriter->Vindent);
 }
 sf.pos=9472903;
 if (AprotoWriter->VuseNr)
 {
  sf.pos=9472904;
  ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(Afspec->Vnr), ((Tc*)&YT)));
 }
 sf.pos=9472905;
 ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Afspec->Vname, ((Tc*)&YFDa)));
 sf.pos=9472906;
 switch (Afspec->Vtype)
 {
 case 9:
 case 11:
  {
   Ti Vv;
   Vv = 0;
   sf.pos=9472907;
   if ((Aidx >= 0))
   {
    sf.pos=9472908;
    Vv = ((Ti (*)(void*, Ti, Ti))(Amsg.table[11]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472909;
    Vv = ((Ti (*)(void*, Ti))(Amsg.table[12]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472910;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(Vv), ((Tc*)&Yk)));
    break;
  }
 case 10:
  {
   Ti Vv;
   Vv = 0;
   sf.pos=9472911;
   if ((Aidx >= 0))
   {
    sf.pos=9472912;
    Vv = ((Ti32 (*)(void*, Ti, Ti))(Amsg.table[13]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472913;
    Vv = ((Ti32 (*)(void*, Ti))(Amsg.table[14]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472914;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(Vv), ((Tc*)&Yk)));
    break;
  }
 case 19:
  {
   Ti Vv;
   Vv = 0;
   sf.pos=9472915;
   if ((Aidx >= 0))
   {
    sf.pos=9472916;
    Vv = ((Tu (*)(void*, Ti, Ti))(Amsg.table[15]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472917;
    Vv = ((Tu (*)(void*, Ti))(Amsg.table[16]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472918;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(Vv), ((Tc*)&Yk)));
    break;
  }
 case 18:
  {
   Ti Vv;
   Vv = 0;
   sf.pos=9472919;
   if ((Aidx >= 0))
   {
    sf.pos=9472920;
    Vv = ((Tu32 (*)(void*, Ti, Ti))(Amsg.table[17]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472921;
    Vv = ((Tu32 (*)(void*, Ti))(Amsg.table[18]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472922;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(Vv), ((Tc*)&Yk)));
    break;
  }
 case 6:
  {
   Tf32 Vf;
   Vf = 0;
   sf.pos=9472923;
   if ((Aidx >= 0))
   {
    sf.pos=9472924;
    Vf = ((Tf32 (*)(void*, Ti, Ti))(Amsg.table[19]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472925;
    Vf = ((Tf32 (*)(void*, Ti))(Amsg.table[20]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472926;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(ZfloatFormat(((Tc*)&YxR2), Vf), ((Tc*)&Yk)));
    break;
  }
 case 7:
  {
   Tf Vf;
   Vf = 0;
   sf.pos=9472927;
   if ((Aidx >= 0))
   {
    sf.pos=9472928;
    Vf = ((Tf (*)(void*, Ti, Ti))(Amsg.table[21]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472929;
    Vf = ((Tf (*)(void*, Ti))(Amsg.table[22]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472930;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(ZfloatFormat(((Tc*)&YmwIa), Vf), ((Tc*)&Yk)));
    break;
  }
 case 1:
  {
   Tb Vv;
   Vv = 0;
   sf.pos=9472931;
   if ((Aidx >= 0))
   {
    sf.pos=9472932;
    Vv = ((Tb (*)(void*, Ti, Ti))(Amsg.table[23]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472933;
    Vv = ((Tb (*)(void*, Ti))(Amsg.table[24]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472934;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS((((Vv) ? (((Tc*)&YHoE)) : (((Tc*)&Y2cy)))), ((Tc*)&Yk)));
    break;
  }
 case 17:
  {
   sf.pos=9472935;
   if ((Aidx >= 0))
   {
    sf.pos=9472936;
    Vv = ((Tc* (*)(void*, Ti, Ti))(Amsg.table[25]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472937;
    Vv = ((Tc* (*)(void*, Ti))(Amsg.table[26]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472938;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS3(((Tc*)&YI), Vv, ((Tc*)&YQ0)));
    break;
  }
 case 3:
  {
   sf.pos=9472939;
   if (AprotoWriter->VuseNr)
   {
    Ti Vv;
    Vv = 0;
    sf.pos=9472940;
    if ((Aidx >= 0))
    {
     sf.pos=9472941;
     Vv = ((Ti (*)(void*, Ti, Ti))(Amsg.table[7]))(Amsg.ptr, Afspec->Vnr, Aidx);
    }
    else
    {
     sf.pos=9472942;
     Vv = ((Ti (*)(void*, Ti))(Amsg.table[8]))(Amsg.ptr, Afspec->Vnr);
    }
    sf.pos=9472943;
    ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(Vv), ((Tc*)&YT)));
   }
   sf.pos=9472944;
   if ((Aidx >= 0))
   {
    sf.pos=9472945;
    Vname = ((Tc* (*)(void*, Ti, Ti))(Amsg.table[9]))(Amsg.ptr, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472946;
    Vname = ((Tc* (*)(void*, Ti))(Amsg.table[10]))(Amsg.ptr, Afspec->Vnr);
   }
   sf.pos=9472947;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Vname, ((Tc*)&Yk)));
    break;
  }
 case 12:
  {
   sf.pos=9472948;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&Ywhc));
   sf.pos=9472949;
   Vindent = AprotoWriter->Vindent;
   sf.pos=9472950;
   if ((Vindent != NULL))
   {
    sf.pos=9472951;
    AprotoWriter->Vindent = ZcS(Vindent, ((Tc*)&YZY));
   }
   sf.pos=9472952;
   if ((Aidx >= 0))
   {
    sf.pos=9472953;
    YeeBa(Amsg, Afspec->Vnr, Aidx, AprotoWriter);
   }
   else
   {
    sf.pos=9472954;
    YeeB(Amsg, Afspec->Vnr, AprotoWriter);
   }
   sf.pos=9472955;
   AprotoWriter->Vindent = Vindent;
   sf.pos=9472956;
   if ((Vindent != NULL))
   {
    sf.pos=9472957;
    ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, Vindent);
   }
   sf.pos=9472958;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YJkc));
    break;
  }
 default:
  {
   Tr ex;
   sf.pos=9472959;
   *Znao(&ex, Ys_q__YwtA__YRHR(NULL, ZcS(((Tc*)&Y80t), Zenum2string(MProto__EType, Afspec->Vtype))), Ys_q__Ytlm_I_imt, 29);
   ZthrowIobject(ex);
  }
 }
 topFrame = sf.prev;
 return;
}
void YeeB(Tr At, Ti AfieldNr, YLWE *AprotoWriter) {
 Zsf sf;
 Tr Vmsg = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6491200;
 Vmsg = ((Tr (*)(void*, Ti))(At.table[38]))(At.ptr, AfieldNr);
 sf.pos=6491201;
 if ((((Vmsg).ptr) != NULL))
 {
  sf.pos=6491202;
  YP8Z(Vmsg, AprotoWriter);
 }
 topFrame = sf.prev;
 return;
}
void YeeBa(Tr At, Ti AfieldNr, Ti Aidx, YLWE *AprotoWriter) {
 Zsf sf;
 Tr Vmsg = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7198800;
 Vmsg = ((Tr (*)(void*, Ti, Ti))(At.table[37]))(At.ptr, AfieldNr, Aidx);
 sf.pos=7198801;
 if ((((Vmsg).ptr) != NULL))
 {
  sf.pos=7198802;
  YP8Z(Vmsg, AprotoWriter);
 }
 topFrame = sf.prev;
 return;
}
Ti YmeT(Ti Avalue) {
 Ti Vbytes;
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3699400;
 if ((Avalue < 0))
 {
  sf.pos=3699401;
  r = 10;
  rt = 1;
  goto Yn2E;
 }
 sf.pos=3699402;
 if ((Avalue < 128))
 {
  sf.pos=3699403;
  r = 1;
  rt = 1;
  goto Yn2E;
 }
 sf.pos=3699404;
 if ((Avalue < 16384))
 {
  sf.pos=3699405;
  r = 2;
  rt = 1;
  goto Yn2E;
 }
 sf.pos=3699406;
 Vbytes = 3;
 sf.pos=3699407;
 while ((Avalue >= ((1 << ((Vbytes * 7))))))
 {
  sf.pos=3699408;
  if ((++(Vbytes) == 10))
  {
   rt = 2;
   goto YDo3;
  }
YDo3:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=3699409;
 }
 sf.pos=3699410;
 r = Vbytes;
Yn2E:
 topFrame = sf.prev;
 return r;
}
int JProto(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 if (round == 2001) {
   sf.pos=3053200;
   YXCQ = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MProto__EType__T, (Tt*)&MProto__EBinaryType__T, 0), (Tz)(Ti)1, (Tz)(Ti)0), (Tz)(Ti)9, (Tz)(Ti)0), (Tz)(Ti)11, (Tz)(Ti)0), (Tz)(Ti)10, (Tz)(Ti)0), (Tz)(Ti)19, (Tz)(Ti)0), (Tz)(Ti)18, (Tz)(Ti)0), (Tz)(Ti)17, (Tz)(Ti)2), (Tz)(Ti)3, (Tz)(Ti)0), (Tz)(Ti)12, (Tz)(Ti)2), (Tz)(Ti)6, (Tz)(Ti)5), (Tz)(Ti)7, (Tz)(Ti)1);
   sf.pos=3053201;
   YLwW = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MProto__EBinaryType__T, (Tt*)&int__T, 0), (Tz)(Ti)0, (Tz)(Ti)0), (Tz)(Ti)1, (Tz)(Ti)1), (Tz)(Ti)2, (Tz)(Ti)2), (Tz)(Ti)3, (Tz)(Ti)3), (Tz)(Ti)4, (Tz)(Ti)4), (Tz)(Ti)5, (Tz)(Ti)5);
  }
  topFrame = sf.prev;
 }
 return done;
}
/* Proto done */
Ysbp *Y602(Ysbp *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=672400; t = Za(sizeof(Ysbp));}
 topFrame = sf.prev;
 return t;
}
Tc *YIG1a(Ysbp *t) {
 Tc *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((Tc*)&YvfVb);
 return r;
}
Ysbp *YGxQ(Ysbp *t, Ti Av) {
 Ysbp *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_line = Av;
 t->Vhas_line = 1;
 r = t;
 return r;
}
Ti YuDY(Ysbp *t) {
 Ti r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (!(t->Vhas_line))
 {
  r = 0;
  rt = 1;
  goto YxeV;
 }
 r = t->Vf_line;
YxeV:
 return r;
}
Tb YNbi(Ysbp *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vhas_line;
 return r;
}
Ysbp *Y6ET(Ysbp *t, Ti Av) {
 Ysbp *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_column = Av;
 t->Vhas_column = 1;
 r = t;
 return r;
}
Ti Y3kb(Ysbp *t) {
 Ti r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (!(t->Vhas_column))
 {
  r = 0;
  rt = 1;
  goto YQm6a;
 }
 r = t->Vf_column;
YQm6a:
 return r;
}
Tb Yyok(Ysbp *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vhas_column;
 return r;
}
Ysbp *YMCx(Ysbp *t, Tc *Av) {
 Ysbp *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_filename = Av;
 r = t;
 return r;
}
Tc *Y5Hu(Ysbp *t) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_filename == NULL))
 {
  r = ((Tc*)&Ya);
  rt = 1;
  goto YoMJ;
 }
 r = t->Vf_filename;
YoMJ:
 return r;
}
Tb Yeqm(Ysbp *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_filename != NULL);
 return r;
}
Ti YdPfa(Ysbp *t, Ti AfieldNr) {
 Ti r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   r = t->Vf_line;
   rt = 1;
   goto Y0Z0;
  }
 case 2:
  {
   r = t->Vf_column;
   rt = 1;
   goto Y0Z0;
  }
Y0Z0:
  if (rt) goto Y7s4;
 }
 r = 0;
Y7s4:
 return r;
}
Tc *YKXxa(Ysbp *t, Ti AfieldNr) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 3:
  {
   r = t->Vf_filename;
   rt = 1;
   goto YnQv;
  }
YnQv:
  if (rt) goto YHZA;
 }
 r = ((Tc*)&Ya);
YHZA:
 return r;
}
Tb YGVxa(Ysbp *t, Ti AfieldNr) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   r = YNbi(t);
   rt = 1;
   goto YOGr;
  }
 case 2:
  {
   r = Yyok(t);
   rt = 1;
   goto YOGr;
  }
 case 3:
  {
   r = Yeqm(t);
   rt = 1;
   goto YOGr;
  }
YOGr:
  if (rt) goto YMHx;
 }
 r = 0;
YMHx:
 return r;
}
Tl *Yc_da(Ysbp *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = YEoX;
 return r;
}
Ti Ysbp__Y0zD(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=793700;
  ZthrowThisNil();
 }
 sf.pos=793701;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Ti Ysbp__Y0zDa(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1813800;
  ZthrowThisNil();
 }
 sf.pos=1813801;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tc *Ysbp__YytN(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7904200;
  ZthrowThisNil();
 }
 sf.pos=7904201;
 r = ((Tc*)&Ya);
 topFrame = sf.prev;
 return r;
}
Tc *Ysbp__YytNa(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8924300;
  ZthrowThisNil();
 }
 sf.pos=8924301;
 r = ((Tc*)&Ya);
 topFrame = sf.prev;
 return r;
}
Ti Ysbp__YGR8a(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5606000;
  ZthrowThisNil();
 }
 sf.pos=5606001;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Ti32 Ysbp__YAAo(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Ti32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3484800;
  ZthrowThisNil();
 }
 sf.pos=3484801;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Ti32 Ysbp__YAAoa(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Ti32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4504900;
  ZthrowThisNil();
 }
 sf.pos=4504901;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tu Ysbp__YRqV(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Tu r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5897400;
  ZthrowThisNil();
 }
 sf.pos=5897401;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tu Ysbp__YRqVa(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tu r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6917500;
  ZthrowThisNil();
 }
 sf.pos=6917501;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tu32 Ysbp__Y0tE(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Tu32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1860900;
  ZthrowThisNil();
 }
 sf.pos=1860901;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tu32 Ysbp__Y0tEa(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tu32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2881000;
  ZthrowThisNil();
 }
 sf.pos=2881001;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tf32 Ysbp__Yyt7(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Tf32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1123800;
  ZthrowThisNil();
 }
 sf.pos=1123801;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tf32 Ysbp__Yyt7a(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tf32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2143900;
  ZthrowThisNil();
 }
 sf.pos=2143901;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tf Ysbp__Yybv(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Tf r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8669100;
  ZthrowThisNil();
 }
 sf.pos=8669101;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tf Ysbp__Yybva(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tf r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9689200;
  ZthrowThisNil();
 }
 sf.pos=9689201;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tb Ysbp__YGfz(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5128800;
  ZthrowThisNil();
 }
 sf.pos=5128801;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tb Ysbp__YGfza(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6148900;
  ZthrowThisNil();
 }
 sf.pos=6148901;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tc *Ysbp__YsRaa(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6812800;
  ZthrowThisNil();
 }
 sf.pos=6812801;
 r = ((Tc*)&Ya);
 topFrame = sf.prev;
 return r;
}
Tr Ysbp__Yo5y(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Tr r = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4986500;
  ZthrowThisNil();
 }
 sf.pos=4986501;
 r = trZero;
 topFrame = sf.prev;
 return r;
}
Tr Ysbp__Yo5ya(Ysbp *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tr r = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6006600;
  ZthrowThisNil();
 }
 sf.pos=6006601;
 r = trZero;
 topFrame = sf.prev;
 return r;
}
Ti Ysbp__YUDN(Ysbp *t, Ti AfieldNr) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4429400;
  ZthrowThisNil();
 }
 sf.pos=4429401;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tc *Ysbp__YC5i(Ysbp *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vwriter = 0;
 YLWE *VprotoWriter = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2119700;
  ZthrowThisNil();
 }
 sf.pos=2119701;
 Vwriter = Za(sizeof(YjUM));
 sf.pos=2119702;
 VprotoWriter = YrCUb(NULL, *Znao(&t0, Vwriter, YjUM__YdXi_imt, 2), ((Tc*)&Ya), 0);
 sf.pos=2119703;
 YP8Z(*Znao(&t0, t, Ysbp__YFL0_I_imt, 31), VprotoWriter);
 sf.pos=2119704;
 r = YbNW(Vwriter);
 topFrame = sf.prev;
 return r;
}
Tc *Ysbp__YFL0_I_imt[] = {
 (Tc*)&Ysbp__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YGVxa, /* MZui__CPosition.hasField - YGVxa */
 (Tc*)YIG1a, /* MZui__CPosition.name - YIG1a */
 (Tc*)Ysbp__Y0zDa, /* MZui__CPosition.enumGet - Ysbp__Y0zDa */
 (Tc*)Ysbp__Y0zD, /* MZui__CPosition.enumGet - Ysbp__Y0zD */
 (Tc*)Ysbp__YytNa, /* MZui__CPosition.enumNameGet - Ysbp__YytNa */
 (Tc*)Ysbp__YytN, /* MZui__CPosition.enumNameGet - Ysbp__YytN */
 (Tc*)Ysbp__YGR8a, /* MZui__CPosition.intGet - Ysbp__YGR8a */
 (Tc*)YdPfa, /* MZui__CPosition.intGet - YdPfa */
 (Tc*)Ysbp__YAAoa, /* MZui__CPosition.int32Get - Ysbp__YAAoa */
 (Tc*)Ysbp__YAAo, /* MZui__CPosition.int32Get - Ysbp__YAAo */
 (Tc*)Ysbp__YRqVa, /* MZui__CPosition.uint64Get - Ysbp__YRqVa */
 (Tc*)Ysbp__YRqV, /* MZui__CPosition.uint64Get - Ysbp__YRqV */
 (Tc*)Ysbp__Y0tEa, /* MZui__CPosition.uint32Get - Ysbp__Y0tEa */
 (Tc*)Ysbp__Y0tE, /* MZui__CPosition.uint32Get - Ysbp__Y0tE */
 (Tc*)Ysbp__Yyt7a, /* MZui__CPosition.floatGet - Ysbp__Yyt7a */
 (Tc*)Ysbp__Yyt7, /* MZui__CPosition.floatGet - Ysbp__Yyt7 */
 (Tc*)Ysbp__Yybva, /* MZui__CPosition.doubleGet - Ysbp__Yybva */
 (Tc*)Ysbp__Yybv, /* MZui__CPosition.doubleGet - Ysbp__Yybv */
 (Tc*)Ysbp__YGfza, /* MZui__CPosition.boolGet - Ysbp__YGfza */
 (Tc*)Ysbp__YGfz, /* MZui__CPosition.boolGet - Ysbp__YGfz */
 (Tc*)Ysbp__YsRaa, /* MZui__CPosition.stringGet - Ysbp__YsRaa */
 (Tc*)YKXxa, /* MZui__CPosition.stringGet - YKXxa */
 (Tc*)0, /* MZui__CPosition.enumSet - Ysbp__Y3p7 */
 (Tc*)0, /* MZui__CPosition.enumNameSet - Ysbp__YBjh */
 (Tc*)0, /* MZui__CPosition.intSet - YaZLa */
 (Tc*)0, /* MZui__CPosition.int32Set - Ysbp__YDqT */
 (Tc*)0, /* MZui__CPosition.uint64Set - Ysbp__YOAq */
 (Tc*)0, /* MZui__CPosition.uint32Set - Ysbp__YYD9 */
 (Tc*)0, /* MZui__CPosition.floatSet - Ysbp__YBjC */
 (Tc*)0, /* MZui__CPosition.doubleSet - Ysbp__Yvl0 */
 (Tc*)0, /* MZui__CPosition.boolSet - Ysbp__YJ52 */
 (Tc*)0, /* MZui__CPosition.stringSet - YNN1a */
 (Tc*)Ysbp__Yo5ya, /* MZui__CPosition.messageGet - Ysbp__Yo5ya */
 (Tc*)Ysbp__Yo5y, /* MZui__CPosition.messageGet - Ysbp__Yo5y */
 (Tc*)0, /* MZui__CPosition.messageSet - Ysbp__YrW2 */
 (Tc*)0, /* MZui__CPosition.messageAdd - Ysbp__Y0Dj */
 (Tc*)0, /* MZui__CPosition.mergeMessageFromReader - Ysbp__Ymza */
 (Tc*)Ysbp__YUDN, /* MZui__CPosition.size - Ysbp__YUDN */
 (Tc*)Yc_da, /* MZui__CPosition.fieldSpecs - Yc_da */
 (Tc*)Ysbp__YC5i, /* MZui__CPosition.ToString - Ysbp__YC5i */
 (Tc*)0, /* MZui__CPosition.toString - Ysbp__YVAI */
 (Tc*)0, /* MZui__CPosition.writeText - Ysbp__Yr3ca */
 (Tc*)0, /* MZui__CPosition.writeText - Ysbp__Yr3c */
 (Tc*)0, /* MZui__CPosition.Equal - Ysbp__YYdF */
 (Tc*)0, /* MZui__CPosition.writeBinary - Ysbp__YpSR */
 (Tc*)0, /* MZui__CPosition.writeBinaryDeref - Ysbp__Yz9e */
 (Tc*)0, /* MZui__CPosition.writeJson - Ysbp__YVaR */
 (Tc*)0, /* MZui__CPosition.writeJsonDeref - Ysbp__YgZk */
 (Tc*)0, /* Init - Ysbpa */
};
To ToYsbp[] = {
 {9, 0},
 {0, (Tt*)&int__T}, /* f_line */
 {0, (Tt*)&bool__T}, /* has_line */
 {0, (Tt*)&int__T}, /* f_column */
 {0, (Tt*)&bool__T}, /* has_column */
 {0, (Tt*)&string__T}, /* f_filename */
 {0, (Tt*)&int__T}, /* derefTime */
 {0, (Tt*)&int__T}, /* derefId */
 {0, (Tt*)&int__T}, /* derefTimeSize */
 {0, (Tt*)&int__T}, /* derefIdSize */
};
char *StrYsbp[] = {
 "f_line",
 "has_line",
 "f_column",
 "has_column",
 "f_filename",
 "derefTime",
 "derefId",
 "derefTimeSize",
 "derefIdSize",
};
Tto Ysbp__T = {390, (Tc*)&YvfVb, Ysbp__YC5i, StrYsbp, ToYsbp};
int Jzui(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 done &= JProto(round);
 if (round == 2001) {
   sf.pos=9288700;
   YEoX = ZnewList((Tt*)&YqvM__T, 3); ZLap((Tl*)YEoX, (Tz)(void*)Ykww(NULL, ((Tc*)&Y4eu), 1, 11, 0)); ZLap((Tl*)YEoX, (Tz)(void*)Ykww(NULL, ((Tc*)&YzjB), 2, 11, 0)); ZLap((Tl*)YEoX, (Tz)(void*)Ykww(NULL, ((Tc*)&YV7Z), 3, 17, 0));
  }
  topFrame = sf.prev;
 }
 return done;
}
/* zui done */
YkxB *YWLf(Yev8 *t) {
 Zsf sf;
 YkxB *r = 0;
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5204700;
  ZthrowThisNil();
 }
 sf.pos=5204701;
 r = Ypp_a(NULL, (t0 = Y5Hu(t->VzuiPos)), YuDY(t->VzuiPos), Y3kb(t->VzuiPos));
 topFrame = sf.prev;
 return r;
}
void YdIu(Yev8 *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4037400;
  ZthrowThisNil();
 }
 sf.pos=4037401;
 YDli(Amsg, YWLf(t), 0);
 topFrame = sf.prev;
 return;
}
To ToYev8[] = {
 {5, 0},
 {0, (Tt*)&CToken__EType__T}, /* type */
 {0, (Tt*)&string__T}, /* value */
 {0, (Tt*)&bool__T}, /* hasComment */
 {0, (Tt*)&bool__T}, /* hasCommentFirst */
 {0, (Tt*)&Ysbp__T}, /* zuiPos */
};
char *StrYev8[] = {
 "type",
 "value",
 "hasComment",
 "hasCommentFirst",
 "zuiPos",
};
Tto Yev8__T = {390, (Tc*)&YVrE, 0, StrYev8, ToYev8};
int JToken(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 done &= Jzui(round);
 if (round == 2001) {
  }
  topFrame = sf.prev;
 }
 return done;
}
/* Token done */
/* including TokenInput bodies */
/* including Tokenizer bodies */
/* including ZuiFile bodies */
Ysbp *YK9d(YkxB *Apos) {
 Zsf sf;
 Ysbp *r = 0;
 Ysbp *Vzpos = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=622800;
 if ((Apos == NULL))
 {
  sf.pos=622801;
  r = NULL;
  rt = 1;
  goto YPIH;
 }
 sf.pos=622802;
 Vzpos = Y602(NULL);
 sf.pos=622803;
 YGxQ(Vzpos, Apos->Vlnum);
 sf.pos=622804;
 Y6ET(Vzpos, Apos->Vcol);
 sf.pos=622805;
 YMCx(Vzpos, Apos->Vfilename);
 sf.pos=622806;
 r = Vzpos;
YPIH:
 topFrame = sf.prev;
 return r;
}
void YA4C(YkxB *Apos, Ysbp *Azpos) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7833500;
 YGxQ(Azpos, Apos->Vlnum);
 sf.pos=7833501;
 Y6ET(Azpos, Apos->Vcol);
 sf.pos=7833502;
 YMCx(Azpos, Apos->Vfilename);
 topFrame = sf.prev;
 return;
}
To ToYgKE[] = {
 {0, 0},
};
char *StrYgKE[] = {
};
Tto YgKE__T = {390, (Tc*)&YRzA, 0, StrYgKE, ToYgKE};
/* ZuiFile done */
Tb YIA3(Ti Ac) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4391700;
 r = ((((((Ac >= 97) && (Ac <= 122))) || (((Ac >= 65) && (Ac <= 90)))) || (((Ac >= 48) && (Ac <= 57)))) || (Ac == 95));
 topFrame = sf.prev;
 return r;
}
Yev8 *Yx5t(Y7Sj *Ain) {
 Ti Vc;
 Zsf sf;
 Yev8 *r = 0;
 Yev8 *Vres = 0;
 Tc *Vname = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=603800;
 Vres = Za(sizeof(Yev8));
 sf.pos=603801;
 Vres->VzuiPos = YK9d(Ain->Vinput->Vpos);
 sf.pos=603802;
 YZTP(Ain, Vres);
 sf.pos=603803;
 if ((Vres->Vtype != 5))
 {
  sf.pos=603804;
  r = Vres;
  rt = 1;
  goto YqMK;
 }
 sf.pos=603805;
 YA4C(Ain->Vinput->Vpos, Vres->VzuiPos);
 sf.pos=603806;
 if ((Ybdf(Ain, Vres) == 1))
 {
  sf.pos=603807;
  if (((Vres->Vtype == 21) || (Vres->Vtype == 56)))
  {
   sf.pos=603808;
   Y63C(Ain->VusedIdKeywords, Vres->Vvalue);
  }
  sf.pos=603809;
  r = Vres;
  rt = 1;
  goto YqMK;
 }
 sf.pos=603810;
 Vc = YGBv(Ain);
 sf.pos=603811;
 if (((Vc == 82) && (YHT_(Ain) == 34)))
 {
  sf.pos=603812;
  YGBv(Ain);
  sf.pos=603813;
  YfFo(Ain, (&Yc6N));
  sf.pos=603814;
  Vres->Vtype = 13;
 }
 else
 {
  sf.pos=603815;
  switch (Vc)
  {
  case 34:
   {
    sf.pos=603816;
    Vres->Vtype = 13;
    sf.pos=603817;
    while (1)
    {
     sf.pos=603818;
     Vc = YGBv(Ain);
     sf.pos=603819;
     if ((Vc == 34))
     {
      rt = 2;
      goto YAns;
     }
     sf.pos=603820;
     if (((Vc == 10) || (Vc == Y3QJ)))
     {
      sf.pos=603821;
      YPmF(Ain, Vc);
      sf.pos=603822;
      Y5yp(Ain, ((Tc*)&YD4M));
      rt = 2;
      goto YAns;
     }
     sf.pos=603823;
     if ((Vc == 92))
     {
      sf.pos=603824;
      Vc = YGBv(Ain);
      sf.pos=603825;
      if (((Vc == 10) || (Vc == Y3QJ)))
      {
       sf.pos=603826;
       Y5yp(Ain, ((Tc*)&YD4M));
       rt = 2;
       goto Y3Ye;
      }
      sf.pos=603827;
      if ((Vc == 40))
      {
       sf.pos=603828;
       Vres->Vtype = 14;
       rt = 2;
       goto Y3Ye;
      }
      sf.pos=603829;
      YxBx(Vc, Ain, (&Yc6N));
Y3Ye:
      if (rt) goto YAns;
     }
     else
     {
      sf.pos=603830;
      YjUM__Ydti((&Yc6N), Vc);
     }
YAns:
     if (rt == 2) { rt &= 1; break; }
    sf.pos=603831;
    }
     break;
   }
  case 39:
   {
    sf.pos=603832;
    Vc = YGBv(Ain);
    sf.pos=603833;
    if ((Vc == 39))
    {
     sf.pos=603834;
     Vc = YGBv(Ain);
     sf.pos=603835;
     if (((Vc == 39) || (Vc == 34)))
     {
      sf.pos=603836;
      Vres->Vtype = 13;
      sf.pos=603837;
      while (1)
      {
       Ti Vnc;
       sf.pos=603838;
       Vnc = YGBv(Ain);
       sf.pos=603839;
       Vc = Vnc;
       sf.pos=603840;
       if (((Vc == 39) || (Vc == 34)))
       {
        sf.pos=603841;
        Vc = YGBv(Ain);
        sf.pos=603842;
        if ((Vc == 39))
        {
         sf.pos=603843;
         Vc = YGBv(Ain);
         sf.pos=603844;
         if ((Vc == 39))
         {
          rt = 2;
          goto YCmf;
         }
         sf.pos=603845;
         YPmF(Ain, Vc);
         sf.pos=603846;
         Vc = 39;
YCmf:
         if (rt) goto Ydgn;
        }
        sf.pos=603847;
        YPmF(Ain, Vc);
        sf.pos=603848;
        Vc = Vnc;
Ydgn:
        if (rt) goto YCkF;
       }
       sf.pos=603849;
       if ((Vc == Y3QJ))
       {
        sf.pos=603850;
        Y5yp(Ain, ((Tc*)&YjHV));
        rt = 2;
        goto YCkF;
       }
       sf.pos=603851;
       YjUM__Ydti((&Yc6N), Vc);
YCkF:
       if (rt == 2) { rt &= 1; break; }
      sf.pos=603852;
      }
      rt = 2;
      goto YbmY;
     }
     else
     {
      sf.pos=603853;
      YPmF(Ain, Vc);
      sf.pos=603854;
      Vc = 39;
     }
YbmY:
     if (rt) goto Yduz;
    }
    sf.pos=603855;
    Vres->Vtype = 15;
    sf.pos=603856;
    if ((Vc == 92))
    {
     sf.pos=603857;
     YxBx(YGBv(Ain), Ain, (&Yc6N));
    }
    else
    {
     sf.pos=603858;
     if ((Vc == 39))
     {
      sf.pos=603859;
      YPmF(Ain, Vc);
      sf.pos=603860;
      Y5yp(Ain, ((Tc*)&YXk7));
      sf.pos=603861;
      Vc = 0;
     }
     sf.pos=603862;
     YjUM__Ydti((&Yc6N), Vc);
    }
    sf.pos=603863;
    Vc = YGBv(Ain);
    sf.pos=603864;
    if ((Vc != 39))
    {
     sf.pos=603865;
     Y5yp(Ain, ((Tc*)&YYrm));
    }
Yduz:
    if (rt == 2) { rt &= 1; break; }
     break;
   }
  default:
   {
    Tb VallUpper;
    Tb VnonDigit;
    Tb VdoubleUnderscore;
    sf.pos=603866;
    if (!(YIA3(Vc)))
    {
     sf.pos=603867;
     Y5yp(Ain, ZcS3(((Tc*)&YtNZ), ZintAsString(Vc), ((Tc*)&YN)));
    }
    else
    {
     Tb Vnumber;
     Vnumber = 0;
     sf.pos=603868;
     if (((Vc >= 48) && (Vc <= 57)))
     {
      sf.pos=603869;
      Vnumber = 1;
     }
     sf.pos=603870;
     while ((YIA3(Vc) || ((Vnumber && (((((Vc == 39) || (Vc == 95)) || (Vc == 46)) || (Vc == 45)))))))
     {
      sf.pos=603871;
      if ((Vc == 46))
      {
       Ti Vnc;
       sf.pos=603872;
       Vnc = YGBv(Ain);
       sf.pos=603873;
       YPmF(Ain, Vnc);
       sf.pos=603874;
       if (!(isdigit(Vnc)))
       {
        rt = 2;
        goto YuS9;
       }
YuS9:
       if (rt) goto YfVV;
      }
      sf.pos=603875;
      YjUM__Ydti((&Yc6N), Vc);
      sf.pos=603876;
      Vc = YGBv(Ain);
YfVV:
      if (rt == 2) { rt &= 1; break; }
     sf.pos=603877;
     }
     sf.pos=603878;
     YPmF(Ain, Vc);
    }
    sf.pos=603879;
    Vname = YbNW((&Yc6N));
    sf.pos=603880;
    Vres->Vvalue = Vname;
    sf.pos=603881;
    VallUpper = 1;
    sf.pos=603882;
    VnonDigit = 0;
    sf.pos=603883;
    VdoubleUnderscore = 0;
    sf.pos=603884;
    {
     Ti Vi;
     Tfr Zf4;
     ZforRangeNew(0, ZstringSize(Vname), 1, 1, &Zf4);
     for (ZforRangeGetInt(&Zf4, &Vi); ZforRangeContInt(&Zf4); ZforRangeNextInt(&Zf4, &Vi)) {
     sf.pos=603885;
     Vc = ZstringGetChar(Vname, Vi);
     sf.pos=603886;
     if (!((((((Vc >= 48) && (Vc <= 57)) && (Vc != 39)) && (Vc != 95)))))
     {
      sf.pos=603887;
      VnonDigit = 1;
     }
     sf.pos=603888;
     if (!(((((((Vc >= 65) && (Vc <= 90))) || (Vc == 95)) || (((Vc >= 48) && (Vc <= 57)))))))
     {
      sf.pos=603889;
      VallUpper = 0;
     }
     sf.pos=603890;
     if ((((Vc == 95) && ((Vi + 1) < ZstringSize(Vname))) && (ZstringGetChar(Vname, (Vi + 1)) == 95)))
     {
      sf.pos=603891;
      VdoubleUnderscore = 1;
     }
     sf.pos=603892;
     }
    }
    sf.pos=603893;
    if ((VallUpper && VnonDigit))
    {
     sf.pos=603894;
     YdIu(Vres, ZcS3(((Tc*)&Yl7Q), Vname, ((Tc*)&YN)));
    }
    sf.pos=603895;
    if (VdoubleUnderscore)
    {
     sf.pos=603896;
     YdIu(Vres, ZcS3(((Tc*)&Y_B2), Vname, ((Tc*)&YN)));
    }
    sf.pos=603897;
    Vres->Vtype = 21;
     break;
   }
   if (rt) goto YSTp;
  }
YSTp:
  ;
 }
 sf.pos=603898;
 if ((Vres->Vvalue == NULL))
 {
  sf.pos=603899;
  Vres->Vvalue = YbNW((&Yc6N));
 }
 sf.pos=603900;
 Y3_a((&Yc6N));
 sf.pos=603901;
 r = Vres;
YqMK:
 topFrame = sf.prev;
 return r;
}
void YxBx(Ti Ac, Y7Sj *Ain, YjUM *Awriter) {
 Zsf sf;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9088900;
 switch (Ac)
 {
 case 92:
  {
   sf.pos=9088901;
   YjUM__Ydti(Awriter, 92);
    break;
  }
 case 39:
  {
   sf.pos=9088902;
   YjUM__Ydti(Awriter, 39);
    break;
  }
 case 34:
  {
   sf.pos=9088903;
   YjUM__Ydti(Awriter, 34);
    break;
  }
 case 97:
  {
   sf.pos=9088904;
   YjUM__Ydti(Awriter, 7);
    break;
  }
 case 98:
  {
   sf.pos=9088905;
   YjUM__Ydti(Awriter, 8);
    break;
  }
 case 102:
  {
   sf.pos=9088906;
   YjUM__Ydti(Awriter, 14);
    break;
  }
 case 110:
  {
   sf.pos=9088907;
   YjUM__Ydti(Awriter, 10);
    break;
  }
 case 114:
  {
   sf.pos=9088908;
   YjUM__Ydti(Awriter, 13);
    break;
  }
 case 116:
  {
   sf.pos=9088909;
   YjUM__Ydti(Awriter, 9);
    break;
  }
 case 118:
  {
   sf.pos=9088910;
   YjUM__Ydti(Awriter, 11);
    break;
  }
 case 48:
 case 49:
 case 50:
 case 51:
  {
   Ti Vn;
   sf.pos=9088911;
   Vn = (Ac - 48);
   sf.pos=9088912;
   {
    Ti Vi;
    Tfr Zf3;
    ZforRangeNew(1, 2, 0, 1, &Zf3);
    for (ZforRangeGetInt(&Zf3, &Vi); ZforRangeContInt(&Zf3); ZforRangeNextInt(&Zf3, &Vi)) {
    Ti Voc;
    sf.pos=9088913;
    Voc = YGBv(Ain);
    sf.pos=9088914;
    if (((Voc < 48) || (Voc > 55)))
    {
     sf.pos=9088915;
     YPmF(Ain, Voc);
     sf.pos=9088916;
     Y5yp(Ain, ((Tc*)&YVwa));
     sf.pos=9088917;
     YGBv(Ain);
     rt = 2;
     goto Yoj7;
    }
    sf.pos=9088918;
    Vn = (((Vn << 3)) + ((Voc - 48)));
Yoj7:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=9088919;
    }
   }
   sf.pos=9088920;
   Ye7fa(Awriter, Vn);
    break;
  }
 case 120:
  {
   sf.pos=9088921;
   Ye7fa(Awriter, YHDu(2, Ain));
    break;
  }
 case 117:
  {
   sf.pos=9088922;
   YjUM__Ydti(Awriter, YHDu(4, Ain));
    break;
  }
 case 85:
  {
   sf.pos=9088923;
   YjUM__Ydti(Awriter, YHDu(8, Ain));
    break;
  }
 default:
  {
   sf.pos=9088924;
   YPmF(Ain, Ac);
   sf.pos=9088925;
   Y5yp(Ain, ((Tc*)&Y3ak));
   sf.pos=9088926;
   YGBv(Ain);
    break;
  }
 }
 topFrame = sf.prev;
 return;
}
Ti YHDu(Ti AcharCount, Y7Sj *Ain) {
 Ti Vres;
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vres = 0;
 sf.pos=4478700;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(1, AcharCount, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  Ti Vc;
  sf.pos=4478701;
  Vc = YGBv(Ain);
  sf.pos=4478702;
  if (!(isxdigit(Vc)))
  {
   sf.pos=4478703;
   YPmF(Ain, Vc);
   sf.pos=4478704;
   Y5yp(Ain, ((Tc*)&YnRg));
   sf.pos=4478705;
   YGBv(Ain);
   sf.pos=4478706;
   r = 0;
   rt = 1;
   goto Yr0H;
  }
  sf.pos=4478707;
  Vres = (((Vres << 4)) + ZstringHexToInt(ZintAsString(Vc), 1, 0));
Yr0H:
  if (rt) goto YriQ;
  sf.pos=4478708;
  }
 }
 sf.pos=4478709;
 r = Vres;
YriQ:
 topFrame = sf.prev;
 return r;
}
void YfFo(Y7Sj *Ain, YjUM *Awriter) {
 Ti Vi;
 Zsf sf;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vi = 0;
 sf.pos=9089100;
 while (1)
 {
  Ti Vc;
  sf.pos=9089101;
  Vc = YGBv(Ain);
  sf.pos=9089102;
  if ((Vc == 34))
  {
   sf.pos=9089103;
   Vc = YGBv(Ain);
   sf.pos=9089104;
   if ((Vc != 34))
   {
    sf.pos=9089105;
    YPmF(Ain, Vc);
    rt = 2;
    goto Y4k2;
   }
Y4k2:
   if (rt) goto YueL;
  }
  sf.pos=9089106;
  if (((Vc == 10) || (Vc == Y3QJ)))
  {
   sf.pos=9089107;
   YPmF(Ain, Vc);
   sf.pos=9089108;
   Y5yp(Ain, ((Tc*)&YD4M));
   rt = 2;
   goto YueL;
  }
  sf.pos=9089109;
  YJqza(Awriter, ZintAsString(Vc));
YueL:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9089110;
 }
 topFrame = sf.prev;
 return;
}
void YZTP(Y7Sj *Ain, Yev8 *Ares) {
 Tb VisSep;
 Tb VhasLineBreak;
 Ti Vc;
 Zsf sf;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 VisSep = 0;
 VhasLineBreak = 0;
 sf.pos=3892700;
 Vc = YGBv(Ain);
 sf.pos=3892701;
 if (((Vc == 32) || (Vc == 10)))
 {
  sf.pos=3892702;
  VisSep = 1;
 }
 sf.pos=3892703;
 while (((((Vc == 35) || (((Vc == 47) && (YHT_(Ain) == 42)))) || (Vc == 32)) || (Vc == 10)))
 {
  sf.pos=3892704;
  YjUM__Ydti((&Yl_6), Vc);
  sf.pos=3892705;
  if ((Vc == 10))
  {
   sf.pos=3892706;
   VhasLineBreak = 1;
  }
  else {
  sf.pos=3892707;
 if ((Vc == 35))
  {
   sf.pos=3892708;
   if (!(Ares->VhasComment))
   {
    sf.pos=3892709;
    Ares->VhasCommentFirst = !(VhasLineBreak);
   }
   sf.pos=3892710;
   Ares->VhasComment = 1;
   sf.pos=3892711;
   VhasLineBreak = 1;
   sf.pos=3892712;
   for (;;)
   {
    sf.pos=3892713;
    Vc = YGBv(Ain);
    sf.pos=3892714;
    YjUM__Ydti((&Yl_6), Vc);
    sf.pos=3892715;
    if (((Vc == Y3QJ) || (Vc == 10))) break;
   sf.pos=3892716;
   }
  }
  else {
  sf.pos=3892717;
 if ((Vc == 47))
  {
   sf.pos=3892718;
   YjUM__Ydti((&Yl_6), YGBv(Ain));
   sf.pos=3892719;
   if (!(Ares->VhasComment))
   {
    sf.pos=3892720;
    Ares->VhasCommentFirst = !(VhasLineBreak);
   }
   sf.pos=3892721;
   Ares->VhasComment = 1;
   sf.pos=3892722;
   for (;;)
   {
    sf.pos=3892723;
    Vc = YGBv(Ain);
    sf.pos=3892724;
    if ((Vc == 10))
    {
     sf.pos=3892725;
     YPmF(Ain, Vc);
     sf.pos=3892726;
     Y5yp(Ain, ((Tc*)&YWPM));
     sf.pos=3892727;
     Vc = Y3QJ;
     rt = 2;
     goto YaVe;
    }
    sf.pos=3892728;
    YjUM__Ydti((&Yl_6), Vc);
    sf.pos=3892729;
    if (((Vc == Y3QJ) || (((Vc == 42) && (YHT_(Ain) == 47))))) break;
YaVe:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=3892730;
   }
   sf.pos=3892731;
   if ((Vc != Y3QJ))
   {
    sf.pos=3892732;
    YjUM__Ydti((&Yl_6), YGBv(Ain));
   }
  }
  }}
  sf.pos=3892733;
  Vc = YGBv(Ain);
 sf.pos=3892734;
 }
 sf.pos=3892735;
 YPmF(Ain, Vc);
 sf.pos=3892736;
 if (VisSep)
 {
  sf.pos=3892737;
  if (VhasLineBreak)
  {
   sf.pos=3892738;
   Ares->Vtype = 3;
  }
  else
  {
   sf.pos=3892739;
   Ares->Vtype = 2;
  }
 }
 else {
 sf.pos=3892740;
 if (Ares->VhasComment)
 {
  sf.pos=3892741;
  Ares->Vtype = 4;
 }
 else
 {
  sf.pos=3892742;
  Ares->Vtype = 5;
  sf.pos=3892743;
  rt = 1;
  goto YBbM;
 }
 }
 sf.pos=3892744;
 Ares->Vvalue = YbNW((&Yl_6));
 sf.pos=3892745;
 Y3_a((&Yl_6));
YBbM:
 topFrame = sf.prev;
 return;
}
To ToYsZx[] = {
 {4, 0},
 {0, (Tt*)&array__T}, /* children */
 {0, (Tt*)&string__T}, /* value */
 {0, (Tt*)&CToken__EType__T}, /* type */
 {0, (Tt*)&bool__T}, /* isKeyword */
};
char *StrYsZx[] = {
 "children",
 "value",
 "type",
 "isKeyword",
};
Tto YsZx__T = {390, (Tc*)&Y2N6, 0, StrYsZx, ToYsZx};
void Yfh4(Tc *Aname, Te Atype, Tb AisKeyword) {
 Zsf sf;
 YsZx *Vn = 0;
 Tc *Zf1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3490500;
 Vn = (&YXGF);
 sf.pos=3490501;
 {
  Ti Vc;
  Tfs iZf1;
  Zf1 = Aname;
  ZforStringNew(Zf1, &iZf1);
  for (ZforStringGetInt(&iZf1, &Vc); ZforStringContInt(&iZf1); ZforStringNextInt(&iZf1, &Vc)) {
  sf.pos=3490502;
  if ((Vn->Vchildren == NULL))
  {
   sf.pos=3490503;
   Vn->Vchildren = ZnewArray((Tt*)&YsZx__T, sizeof(YsZx*), 128);
  }
  sf.pos=3490504;
  if (((*(YsZx**)ZarrayPtr(Vn->Vchildren, Vc)) == NULL))
  {
   sf.pos=3490505;
   (*(YsZx**)ZarrayPtr(Vn->Vchildren, Vc)) = Za(sizeof(YsZx));
  }
  sf.pos=3490506;
  Vn = (*(YsZx**)ZarrayPtr(Vn->Vchildren, Vc));
  sf.pos=3490507;
  }
 }
 sf.pos=3490508;
 if ((Vn->Vvalue != NULL))
 {
  sf.pos=3490509;
  Y2oO(ZcS(((Tc*)&Yqcm), Aname), NULL, 0);
 }
 sf.pos=3490510;
 Vn->Vvalue = Aname;
 sf.pos=3490511;
 Vn->Vtype = Atype;
 sf.pos=3490512;
 Vn->VisKeyword = AisKeyword;
 topFrame = sf.prev;
 return;
}
Ts YTyo() {
 Zsf sf;
 Ts r = 0;
 Tl *Zf1 = NULL;
 Tc *Vkey = NULL;
 Tl *Zf11 = NULL;
 Tc *Vkey1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3488200;
 ZnoAllocClear(sizeof(YsZx), &YXGF, NULL);
 sf.pos=3488201;
 {
  Tfl Zf1i;
  Zf1 = ZDictKeys((&Y3rf), 0);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vkey;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=3488202;
  Yfh4(Vkey, ZDictGetInt((&Y3rf), (Tz)(void*)Vkey), 0);
  sf.pos=3488203;
  }
 }
 sf.pos=3488204;
 {
  Tfl Zf11i;
  Zf11 = ZDictKeys((&Y0sf), 0);
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vkey1;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=3488205;
  Yfh4(Vkey1, ZDictGetInt((&Y0sf), (Tz)(void*)Vkey1), 1);
  sf.pos=3488206;
  }
 }
 sf.pos=3488207;
 r = 1;
 topFrame = sf.prev;
 return r;
}
Ts Ybdf(Y7Sj *Ain, Yev8 *Ares) {
 Ti Vc1;
 Zsf sf;
 Ts r = 0;
 YsZx *Vn = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9699200;
 Vc1 = YGBv(Ain);
 sf.pos=9699201;
 if ((Vc1 == Y3QJ))
 {
  sf.pos=9699202;
  Ares->Vtype = 1;
  sf.pos=9699203;
  r = 1;
  rt = 1;
  goto Yfhb;
 }
 sf.pos=9699204;
 if ((Vc1 < 128))
 {
  sf.pos=9699205;
  Vn = (*(YsZx**)ZarrayPtr((&YXGF)->Vchildren, Vc1));
  sf.pos=9699206;
  if ((Vn != NULL))
  {
   sf.pos=9699207;
   if ((Vn->Vchildren != NULL))
   {
    sf.pos=9699208;
    if ((YY69(Ain, Vn, Ares) == 1))
    {
     sf.pos=9699209;
     r = 1;
     rt = 1;
     goto YSwi;
    }
YSwi:
    if (rt) goto Yc4Z;
   }
   sf.pos=9699210;
   if (((Vn->Vvalue != NULL) && ((!(Vn->VisKeyword) || !(YIA3(YHT_(Ain)))))))
   {
    sf.pos=9699211;
    Ares->Vtype = Vn->Vtype;
    sf.pos=9699212;
    Ares->Vvalue = Vn->Vvalue;
    sf.pos=9699213;
    r = 1;
    rt = 1;
    goto Yc4Z;
   }
Yc4Z:
   if (rt) goto Ysx1;
  }
Ysx1:
  if (rt) goto Yfhb;
 }
 sf.pos=9699214;
 YPmF(Ain, Vc1);
 sf.pos=9699215;
 r = 0;
Yfhb:
 topFrame = sf.prev;
 return r;
}
Ts YY69(Y7Sj *Ain, YsZx *An, Yev8 *Ares) {
 Ti Vc;
 Zsf sf;
 Ts r = 0;
 YsZx *Vn2 = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6000300;
 Vc = YGBv(Ain);
 sf.pos=6000301;
 if (((Vc > 0) && (Vc < 128)))
 {
  sf.pos=6000302;
  Vn2 = (*(YsZx**)ZarrayPtr(An->Vchildren, Vc));
  sf.pos=6000303;
  if ((Vn2 != NULL))
  {
   sf.pos=6000304;
   if ((Vn2->Vchildren != NULL))
   {
    sf.pos=6000305;
    if ((YY69(Ain, Vn2, Ares) == 1))
    {
     sf.pos=6000306;
     r = 1;
     rt = 1;
     goto YeiW;
    }
YeiW:
    if (rt) goto YyJq;
   }
   sf.pos=6000307;
   if (((Vn2->Vvalue != NULL) && ((!(Vn2->VisKeyword) || !(YIA3(YHT_(Ain)))))))
   {
    sf.pos=6000308;
    Ares->Vtype = Vn2->Vtype;
    sf.pos=6000309;
    Ares->Vvalue = Vn2->Vvalue;
    sf.pos=6000310;
    r = 1;
    rt = 1;
    goto YyJq;
   }
YyJq:
   if (rt) goto Yyxk;
  }
Yyxk:
  if (rt) goto Ykt8;
 }
 sf.pos=6000311;
 YPmF(Ain, Vc);
 sf.pos=6000312;
 r = 0;
Ykt8:
 topFrame = sf.prev;
 return r;
}
int JTokenizer(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 if (round == 2001) {
   sf.pos=2055500;
   ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictInit(&Y3rf, (Tt*)&string__T, (Tt*)&CToken__EType__T, 0), (Tz)(void*)((Tc*)&Y_y2), (Tz)(Ti)20), (Tz)(void*)((Tc*)&Yez2), (Tz)(Ti)122), (Tz)(void*)((Tc*)&YzUC), (Tz)(Ti)123), (Tz)(void*)((Tc*)&YC5H), (Tz)(Ti)124), (Tz)(void*)((Tc*)&YD5H), (Tz)(Ti)27), (Tz)(void*)((Tc*)&YyUC), (Tz)(Ti)28), (Tz)(void*)((Tc*)&Y2_), (Tz)(Ti)127), (Tz)(void*)((Tc*)&Y40), (Tz)(Ti)129), (Tz)(void*)((Tc*)&Y1ia), (Tz)(Ti)99), (Tz)(void*)((Tc*)&Yhja), (Tz)(Ti)113), (Tz)(void*)((Tc*)&YNfa), (Tz)(Ti)101), (Tz)(void*)((Tc*)&Y4fa), (Tz)(Ti)114), (Tz)(void*)((Tc*)&Ytea), (Tz)(Ti)115), (Tz)(void*)((Tc*)&Yuma), (Tz)(Ti)116), (Tz)(void*)((Tc*)&Ys6), (Tz)(Ti)117), (Tz)(void*)((Tc*)&Y8mc), (Tz)(Ti)118), (Tz)(void*)((Tc*)&Y37), (Tz)(Ti)119), (Tz)(void*)((Tc*)&YWjc), (Tz)(Ti)120), (Tz)(void*)((Tc*)&YQyb), (Tz)(Ti)121), (Tz)(void*)((Tc*)&YWIa), (Tz)(Ti)125), (Tz)(void*)((Tc*)&YXIa), (Tz)(Ti)126), (Tz)(void*)((Tc*)&YYJa), (Tz)(Ti)128), (Tz)(void*)((Tc*)&YjHa), (Tz)(Ti)111), (Tz)(void*)((Tc*)&YyKa), (Tz)(Ti)110), (Tz)(void*)((Tc*)&YkHa), (Tz)(Ti)136), (Tz)(void*)((Tc*)&YxKa), (Tz)(Ti)134), (Tz)(void*)((Tc*)&YH7), (Tz)(Ti)130), (Tz)(void*)((Tc*)&YWkc), (Tz)(Ti)131), (Tz)(void*)((Tc*)&YEka), (Tz)(Ti)106), (Tz)(void*)((Tc*)&Y5La), (Tz)(Ti)86), (Tz)(void*)((Tc*)&YULa), (Tz)(Ti)87), (Tz)(void*)((Tc*)&YH), (Tz)(Ti)132), (Tz)(void*)((Tc*)&YK), (Tz)(Ti)97), (Tz)(void*)((Tc*)&YL), (Tz)(Ti)105), (Tz)(void*)((Tc*)&YM), (Tz)(Ti)109), (Tz)(void*)((Tc*)&YO), (Tz)(Ti)90), (Tz)(void*)((Tc*)&YP), (Tz)(Ti)91), (Tz)(void*)((Tc*)&YQ), (Tz)(Ti)103), (Tz)(void*)((Tc*)&YR), (Tz)(Ti)100), (Tz)(void*)((Tc*)&YS), (Tz)(Ti)82), (Tz)(void*)((Tc*)&YT), (Tz)(Ti)98), (Tz)(void*)((Tc*)&YU), (Tz)(Ti)89), (Tz)(void*)((Tc*)&YV), (Tz)(Ti)104), (Tz)(void*)((Tc*)&Y5), (Tz)(Ti)84), (Tz)(void*)((Tc*)&Y6), (Tz)(Ti)83), (Tz)(void*)((Tc*)&Y7), (Tz)(Ti)135), (Tz)(void*)((Tc*)&Y8), (Tz)(Ti)112), (Tz)(void*)((Tc*)&Y9), (Tz)(Ti)133), (Tz)(void*)((Tc*)&Yba), (Tz)(Ti)88), (Tz)(void*)((Tc*)&Ygbb), (Tz)(Ti)95), (Tz)(void*)((Tc*)&YCa), (Tz)(Ti)94), (Tz)(void*)((Tc*)&YEa), (Tz)(Ti)96), (Tz)(void*)((Tc*)&YFa), (Tz)(Ti)108), (Tz)(void*)((Tc*)&Y7a), (Tz)(Ti)92), (Tz)(void*)((Tc*)&Y8a), (Tz)(Ti)107), (Tz)(void*)((Tc*)&Y9a), (Tz)(Ti)93), (Tz)(void*)((Tc*)&Yab), (Tz)(Ti)102), (Tz)(void*)((Tc*)&Yaa), (Tz)(Ti)85);
   sf.pos=2055501;
   ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictInit(&Y0sf, (Tt*)&string__T, (Tt*)&CToken__EType__T, 0), (Tz)(void*)((Tc*)&Yu2V), (Tz)(Ti)25), (Tz)(void*)((Tc*)&YBjQ), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YHPa), (Tz)(Ti)23), (Tz)(void*)((Tc*)&YjG6), (Tz)(Ti)36), (Tz)(void*)((Tc*)&YZOS), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YZzE), (Tz)(Ti)69), (Tz)(void*)((Tc*)&YOgo), (Tz)(Ti)57), (Tz)(void*)((Tc*)&YwZW), (Tz)(Ti)58), (Tz)(void*)((Tc*)&YCSN), (Tz)(Ti)59), (Tz)(void*)((Tc*)&Ydl6), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YxBe), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yea), (Tz)(Ti)55), (Tz)(void*)((Tc*)&Y6FU), (Tz)(Ti)73), (Tz)(void*)((Tc*)&YCun), (Tz)(Ti)50), (Tz)(void*)((Tc*)&YPQP), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YK2B), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YMwW), (Tz)(Ti)30), (Tz)(void*)((Tc*)&Yn3A), (Tz)(Ti)70), (Tz)(void*)((Tc*)&YeuV), (Tz)(Ti)142), (Tz)(void*)((Tc*)&YUlG), (Tz)(Ti)74), (Tz)(void*)((Tc*)&Yqcs), (Tz)(Ti)52), (Tz)(void*)((Tc*)&YrUa), (Tz)(Ti)75), (Tz)(void*)((Tc*)&Yga), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yc7A), (Tz)(Ti)66), (Tz)(void*)((Tc*)&Y9jU), (Tz)(Ti)65), (Tz)(void*)((Tc*)&YnjG), (Tz)(Ti)35), (Tz)(void*)((Tc*)&YsI4), (Tz)(Ti)47), (Tz)(void*)((Tc*)&YDN8), (Tz)(Ti)40), (Tz)(void*)((Tc*)&Y8ag), (Tz)(Ti)12), (Tz)(void*)((Tc*)&Y2cy), (Tz)(Ti)9), (Tz)(void*)((Tc*)&YdbB), (Tz)(Ti)51), (Tz)(void*)((Tc*)&Yz51), (Tz)(Ti)77), (Tz)(void*)((Tc*)&YqI4), (Tz)(Ti)37), (Tz)(void*)((Tc*)&Y3Ya), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yuso), (Tz)(Ti)62), (Tz)(void*)((Tc*)&Ycx0), (Tz)(Ti)61), (Tz)(void*)((Tc*)&Yf3i), (Tz)(Ti)63), (Tz)(void*)((Tc*)&Y1Ce), (Tz)(Ti)60), (Tz)(void*)((Tc*)&Yup4), (Tz)(Ti)19), (Tz)(void*)((Tc*)&Yith), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y0hh), (Tz)(Ti)141), (Tz)(void*)((Tc*)&Yka), (Tz)(Ti)56), (Tz)(void*)((Tc*)&Yj1a), (Tz)(Ti)64), (Tz)(void*)((Tc*)&Y4UI), (Tz)(Ti)67), (Tz)(void*)((Tc*)&Y4lO), (Tz)(Ti)41), (Tz)(void*)((Tc*)&YML6), (Tz)(Ti)22), (Tz)(void*)((Tc*)&Yr1a), (Tz)(Ti)78), (Tz)(void*)((Tc*)&Ygis), (Tz)(Ti)42), (Tz)(void*)((Tc*)&YxM9), (Tz)(Ti)43), (Tz)(void*)((Tc*)&YLM9), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y0as), (Tz)(Ti)33), (Tz)(void*)((Tc*)&Ys1aa), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yw1a), (Tz)(Ti)137), (Tz)(void*)((Tc*)&YtU9), (Tz)(Ti)139), (Tz)(void*)((Tc*)&YCHh), (Tz)(Ti)138), (Tz)(void*)((Tc*)&Y5nR), (Tz)(Ti)140), (Tz)(void*)((Tc*)&YAcL), (Tz)(Ti)39), (Tz)(void*)((Tc*)&YVvha), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YKxe), (Tz)(Ti)29), (Tz)(void*)((Tc*)&Yqim), (Tz)(Ti)45), (Tz)(void*)((Tc*)&YZom), (Tz)(Ti)53), (Tz)(void*)((Tc*)&ZNilString), (Tz)(Ti)6), (Tz)(void*)((Tc*)&Yizy), (Tz)(Ti)44), (Tz)(void*)((Tc*)&Y0ab), (Tz)(Ti)11), (Tz)(void*)((Tc*)&Y2gz), (Tz)(Ti)24), (Tz)(void*)((Tc*)&YV4t), (Tz)(Ti)8), (Tz)(void*)((Tc*)&YNqR), (Tz)(Ti)34), (Tz)(void*)((Tc*)&YsNN), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y6T9), (Tz)(Ti)38), (Tz)(void*)((Tc*)&Ysa6), (Tz)(Ti)71), (Tz)(void*)((Tc*)&YgRl), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YGD1), (Tz)(Ti)46), (Tz)(void*)((Tc*)&YZXw), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YuOB), (Tz)(Ti)31), (Tz)(void*)((Tc*)&YuyE), (Tz)(Ti)32), (Tz)(void*)((Tc*)&Y4xB), (Tz)(Ti)81), (Tz)(void*)((Tc*)&Yaof), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y0Y5), (Tz)(Ti)72), (Tz)(void*)((Tc*)&YALz), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yva), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Ytoe), (Tz)(Ti)7), (Tz)(void*)((Tc*)&YVLC), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YTJV), (Tz)(Ti)48), (Tz)(void*)((Tc*)&YA3g), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YNVB), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y5ib), (Tz)(Ti)79), (Tz)(void*)((Tc*)&YHoE), (Tz)(Ti)10), (Tz)(void*)((Tc*)&Yn9B), (Tz)(Ti)49), (Tz)(void*)((Tc*)&Y7fW), (Tz)(Ti)26), (Tz)(void*)((Tc*)&YexT), (Tz)(Ti)76), (Tz)(void*)((Tc*)&YAKE), (Tz)(Ti)18), (Tz)(void*)((Tc*)&YRRGa), (Tz)(Ti)17), (Tz)(void*)((Tc*)&YD2V), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y_r2), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YRA8), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YHo2), (Tz)(Ti)68), (Tz)(void*)((Tc*)&YBa), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YDER), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YQHR), (Tz)(Ti)21);
   sf.pos=2055502;
   ZnoAllocClear(sizeof(YjUM), &Yc6N, NULL);
   sf.pos=2055503;
   ZnoAllocClear(sizeof(YjUM), &Yl_6, NULL);
  done = 0;
  } else if (round > 2001) {
    if (YTyo__r == 0) {
      YTyo__r = YTyo();
      done &= YTyo__r;
    }
  }
  topFrame = sf.prev;
 }
 return done;
}
/* Tokenizer done */
Y7Sj *YUwt(Y7Sj *t, YeYq *Ainput) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6388600; t = Za(sizeof(Y7Sj));}
 sf.pos=6388601;
 t->Vinput = Ainput;
 sf.pos=6388602;
 t->VtokenStack = ZnewList((Tt*)&Yev8__T, 0);
 sf.pos=6388603;
 t->VusedIdKeywords = Yh95(NULL);
 topFrame = sf.prev;
 return t;
}
Ti YGBv(Y7Sj *t) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3937200;
  ZthrowThisNil();
 }
 sf.pos=3937201;
 r = YAit(t->Vinput);
 topFrame = sf.prev;
 return r;
}
void YPmF(Y7Sj *t, Ti Ac) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9233600;
  ZthrowThisNil();
 }
 sf.pos=9233601;
 YmK2(t->Vinput, Ac);
 topFrame = sf.prev;
 return;
}
Ti YHT_(Y7Sj *t) {
 Ti Vc;
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3230900;
  ZthrowThisNil();
 }
 sf.pos=3230901;
 Vc = YGBv(t);
 sf.pos=3230902;
 YPmF(t, Vc);
 sf.pos=3230903;
 r = Vc;
 topFrame = sf.prev;
 return r;
}
Yev8 *Y_PN(Y7Sj *t) {
 Zsf sf;
 Yev8 *r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3225700;
  ZthrowThisNil();
 }
 sf.pos=3225701;
 if ((ZListSize(t->VtokenStack) > 0))
 {
  sf.pos=3225702;
  r = ZListRemovePtrItem((Tl*)t->VtokenStack, -1);
  rt = 1;
  goto YNOF;
 }
 sf.pos=3225703;
 r = Yx5t(t);
YNOF:
 topFrame = sf.prev;
 return r;
}
void YGzQ(Y7Sj *t) {
 Zsf sf;
 Yev8 *Vt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3978900;
  ZthrowThisNil();
 }
 sf.pos=3978901;
 while ((ZListSize(t->VtokenStack) > 0))
 {
  sf.pos=3978902;
  Vt = ZListRemovePtrItem((Tl*)t->VtokenStack, -1);
  sf.pos=3978903;
  {
   Ti Vi;
   Tfr Zf2;
   ZforRangeNew((ZstringSize(Vt->Vvalue) - 1), 0, 0, -1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vi); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vi)) {
   sf.pos=3978904;
   YPmF(t, ZstringGetChar(Vt->Vvalue, Vi));
   sf.pos=3978905;
   }
  }
 sf.pos=3978906;
 }
 topFrame = sf.prev;
 return;
}
void Y5yp(Y7Sj *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5495000;
  ZthrowThisNil();
 }
 sf.pos=5495001;
 YDli(Amsg, t->Vinput->Vpos, 0);
 topFrame = sf.prev;
 return;
}
To ToY7Sj[] = {
 {3, 0},
 {0, (Tt*)&YeYq__T}, /* input */
 {0, (Tt*)&list__T}, /* tokenStack */
 {0, (Tt*)&Yhqr__T}, /* usedIdKeywords */
};
char *StrY7Sj[] = {
 "input",
 "tokenStack",
 "usedIdKeywords",
};
Tto Y7Sj__T = {390, (Tc*)&YnOq, 0, StrY7Sj, ToY7Sj};
int JTokenInput(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 done &= JTokenizer(round);
 if (round == 2001) {
  }
  topFrame = sf.prev;
 }
 return done;
}
/* TokenInput done */
To ToYihi[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* fileName */
 {0, (Tt*)&bool__T}, /* usedAsController */
};
char *StrYihi[] = {
 "fileName",
 "usedAsController",
};
Tto Yihi__T = {390, (Tc*)&YeYv, 0, StrYihi, ToYihi};
void YSxp(Y7Sj *Ain, Tr AoutFile) {
 Tb VinsideModule;
 Tb VseenModuleName;
 Tb VseenHtml;
 Tb VhasCss;
 Zsf sf;
 Td *Vimports = NULL;
 Tr Vout = {NULL};
 Yev8 *Vtoken = 0;
 Td *Zf2 = NULL;
 Yihi *Vimport = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1108000;
 ((Ts (*)(void*, Tc*))(AoutFile.table[11]))(AoutFile.ptr, ((Tc*)&YER6));
 sf.pos=1108001;
 ((Ts (*)(void*, Tc*))(AoutFile.table[11]))(AoutFile.ptr, ZcS(((Tc*)&Y8qH), Ain->Vinput->Vpos->Vfilename));
 sf.pos=1108002;
 ((Ts (*)(void*))(AoutFile.table[18]))(AoutFile.ptr);
 VinsideModule = 0;
 VseenModuleName = 0;
 VseenHtml = 0;
 VhasCss = 0;
 sf.pos=1108003;
 Vimports = ZnewDict((Tt*)&string__T, (Tt*)&Yihi__T, 0);
 sf.pos=1108005;
 Vout = ZconvertZioref(AoutFile, Y8is__imtt, 0, 99999, 1108004);
 sf.pos=1108006;
 while (1)
 {
  sf.pos=1108007;
  Vtoken = Y_PN(Ain);
  sf.pos=1108008;
  if ((Vtoken->Vtype == 1))
  {
   sf.pos=1108009;
   if (VinsideModule)
   {
    sf.pos=1108010;
    Y5yp(Ain, ((Tc*)&YRPM));
   }
   rt = 2;
   goto Ytgb;
  }
  sf.pos=1108011;
  switch (Vtoken->Vtype)
  {
  case 4:
  case 2:
  case 3:
   {
    sf.pos=1108012;
    ((Ts (*)(void*, Tc*))(Vout.table[8]))(Vout.ptr, YJ25(Ain->Vinput));
     break;
   }
  case 22:
   {
    sf.pos=1108013;
    YVPe(Ain, Vimports);
    sf.pos=1108014;
    Vout = *Znao(&Vout, Za(sizeof(YjUM)), YjUM__Y8is_I_imt, 2);
     break;
   }
  case 29:
   {
    sf.pos=1108015;
    if (VinsideModule)
    {
     sf.pos=1108016;
     Y5yp(Ain, ((Tc*)&YqdO));
     sf.pos=1108017;
     rt = 1;
     goto YHy7;
    }
    sf.pos=1108018;
    ((Ts (*)(void*, Tc*))(Vout.table[8]))(Vout.ptr, YJ25(Ain->Vinput));
    sf.pos=1108019;
    VinsideModule = 1;
YHy7:
    if (rt) goto YwwX;
     break;
   }
  case 21:
   {
    sf.pos=1108020;
    if ((VinsideModule && !(VseenModuleName)))
    {
     sf.pos=1108021;
     ((Ts (*)(void*, Tc*))(Vout.table[8]))(Vout.ptr, YJ25(Ain->Vinput));
     sf.pos=1108022;
     VseenModuleName = 1;
    }
    else
    {
     sf.pos=1108023;
     Y5yp(Ain, ((Tc*)&YE6i));
    }
     break;
   }
  case 88:
   {
    sf.pos=1108024;
    Vtoken = Y_PN(Ain);
    sf.pos=1108025;
    if ((Vtoken->Vtype == 21))
    {
     sf.pos=1108026;
     ((Ts (*)(void*, Tc*))(Vout.table[8]))(Vout.ptr, YJ25(Ain->Vinput));
    }
    else
    {
     sf.pos=1108027;
     Y5yp(Ain, ((Tc*)&Yn76));
    }
     break;
   }
  case 93:
   {
    sf.pos=1108028;
    if (VinsideModule)
    {
     sf.pos=1108029;
     VinsideModule = 0;
    }
    else
    {
     sf.pos=1108030;
     Y5yp(Ain, ((Tc*)&YFO4));
    }
     break;
   }
  case 142:
   {
    sf.pos=1108031;
    if (VseenHtml)
    {
     sf.pos=1108032;
     Y5yp(Ain, ((Tc*)&Y5Hp));
    }
    sf.pos=1108033;
    if (VhasCss)
    {
     sf.pos=1108034;
     Y5yp(Ain, ((Tc*)&Ydne));
    }
    sf.pos=1108035;
    Y467(Vtoken, Ain, Vout);
    sf.pos=1108036;
    VhasCss = 1;
     break;
   }
  case 141:
   {
    sf.pos=1108037;
    VseenHtml = 1;
    sf.pos=1108038;
    YG05(Vtoken, Ain, VhasCss, Vimports, Vout);
     break;
   }
  default:
   {
    sf.pos=1108039;
    Y5yp(Ain, ZcS(((Tc*)&YtoA), Zenum2string(CToken__EType, Vtoken->Vtype)));
     break;
   }
YwwX:
   if (rt) goto Ytgb;
  }
Ytgb:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YX9oa;
 sf.pos=1108040;
 }
 sf.pos=1108041;
 if ((((Vout).ptr) != ((AoutFile).ptr)))
 {
  sf.pos=1108042;
  {
   Tfd Zf2i;
   Zf2 = Vimports;
   Zf2i.d = Zf2;
   Zf2i.keyp = NULL;
   Zf2i.valp = (void*)&Vimport;
   for (ZforDictStart(&Zf2i); ZforDictCont(&Zf2i); ZforDictNext(&Zf2i)) {
   sf.pos=1108043;
   ((Ts (*)(void*, Tc*))(AoutFile.table[1]))(AoutFile.ptr, ZcS3(((Tc*)&Yp_H), Vimport->VfileName, ((Tc*)&YI)));
   sf.pos=1108044;
   if (Vimport->VusedAsController)
   {
    sf.pos=1108045;
    ((Ts (*)(void*, Tc*))(AoutFile.table[1]))(AoutFile.ptr, ((Tc*)&Y0ZC));
   }
   sf.pos=1108046;
   ((Ts (*)(void*, Tc*))(AoutFile.table[1]))(AoutFile.ptr, ((Tc*)&Yk));
   sf.pos=1108047;
   }
  }
  sf.pos=1108048;
  ((Ts (*)(void*, Tc*))(AoutFile.table[1]))(AoutFile.ptr, ZiobjectToStringval(Vout));
 }
YX9oa:
 topFrame = sf.prev;
 return;
}
void YVPe(Y7Sj *Ain, Td *Aimports) {
 Zsf sf;
 Yev8 *Vtoken = 0;
 Yihi *Vimport = 0;
 Tc *VshortName = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1490300;
 YJ25(Ain->Vinput);
 sf.pos=1490301;
 while (1)
 {
  sf.pos=1490302;
  Vtoken = Y_PN(Ain);
  sf.pos=1490303;
  if ((Vtoken->Vtype == 1))
  {
   rt = 2;
   goto YEFM;
  }
  sf.pos=1490304;
  if ((Vtoken->Vtype == 13))
  {
   Ti VdotIdx;
   sf.pos=1490305;
   Vimport = Za(sizeof(Yihi));
   sf.pos=1490306;
   Vimport->VfileName = Vtoken->Vvalue;
   sf.pos=1490307;
   VshortName = YKFh(Vtoken->Vvalue);
   sf.pos=1490308;
   VdotIdx = ZstringFind(VshortName, ((Tc*)&YU), 0);
   sf.pos=1490309;
   if ((VdotIdx > 0))
   {
    sf.pos=1490310;
    VshortName = ZstringSlice(VshortName, 0, (VdotIdx - 1), 0);
   }
   sf.pos=1490311;
   ZDictAdd(1, Aimports, (Tz)(void*)VshortName, (Tz)(void*)Vimport);
   rt = 2;
   goto YEFM;
  }
YEFM:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=1490312;
 }
 sf.pos=1490313;
 YJ25(Ain->Vinput);
 topFrame = sf.prev;
 return;
}
void YG05(Yev8 *AhtmlToken, Y7Sj *Ain, Tb AhasCss, Td *Aimports, Tr Aout) {
 Tb VhadParen;
 Ti Vparens;
 Ti VcurlyDepth;
 Ti VspaceCount;
 Zsf sf;
 Yev8 *Vtoken = 0;
 Yev8 *Vtoken1 = 0;
 Yhqr *VactionsDone = 0;
 Yhqr *VeventsDone = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7820100;
 ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, ((Tc*)&YqI4));
 sf.pos=7820101;
 YJ25(Ain->Vinput);
 VhadParen = 0;
 Vparens = 0;
 sf.pos=7820102;
 while (1)
 {
  sf.pos=7820103;
  Vtoken = Y_PN(Ain);
  sf.pos=7820104;
  switch (Vtoken->Vtype)
  {
  case 1:
   {
    sf.pos=7820105;
    Y5yp(Ain, ((Tc*)&YF0E));
    sf.pos=7820106;
    rt = 1;
    goto YzhP;
   }
  case 90:
   {
    sf.pos=7820107;
    if (!(VhadParen))
    {
     sf.pos=7820108;
     VhadParen = 1;
     sf.pos=7820109;
     ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, YJ25(Ain->Vinput));
     sf.pos=7820110;
     ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, ((Tc*)&YoYi));
    }
    sf.pos=7820111;
    ++(Vparens);
     break;
   }
  case 91:
   {
    sf.pos=7820112;
    --(Vparens);
     break;
   }
YzhP:
   if (rt) goto YwOy;
  }
  sf.pos=7820113;
  if ((VhadParen && (Vparens == 0)))
  {
   rt = 2;
   goto YwOy;
  }
YwOy:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto Yr1ca;
 sf.pos=7820114;
 }
 sf.pos=7820115;
 ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, YJ25(Ain->Vinput));
 sf.pos=7820116;
 ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, ((Tc*)&YGNi));
 sf.pos=7820117;
 while (1)
 {
  sf.pos=7820118;
  Vtoken1 = Y_PN(Ain);
  sf.pos=7820119;
  if ((Vtoken1->Vtype == 1))
  {
   sf.pos=7820120;
   Y5yp(Ain, ((Tc*)&YF0E));
   sf.pos=7820121;
   rt = 1;
   goto Yzmf;
  }
  sf.pos=7820122;
  if ((Vtoken1->Vtype == 3))
  {
   rt = 2;
   goto Yzmf;
  }
Yzmf:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto Yr1ca;
 sf.pos=7820123;
 }
 sf.pos=7820124;
 ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, YJ25(Ain->Vinput));
 sf.pos=7820125;
 if (AhasCss)
 {
  sf.pos=7820126;
  ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&Y1dka));
  sf.pos=7820127;
  ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, ((Tc*)&YW_j));
 }
 sf.pos=7820128;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&YUdu));
 sf.pos=7820129;
 VactionsDone = Yh95(NULL);
 sf.pos=7820130;
 VeventsDone = Yh95(NULL);
 sf.pos=7820131;
 YGzQ(Ain);
 VcurlyDepth = 0;
 VspaceCount = 0;
 sf.pos=7820132;
 while (1)
 {
  Ti Vc;
  sf.pos=7820133;
  Vc = YGBv(Ain);
  sf.pos=7820134;
  switch (Vc)
  {
  case Y3QJ:
   {
    sf.pos=7820135;
    Y5yp(Ain, ((Tc*)&YF0E));
    sf.pos=7820136;
    rt = 1;
    goto Yvxd;
   }
  case 123:
   {
    sf.pos=7820137;
    ++(VcurlyDepth);
     break;
   }
  case 125:
   {
    sf.pos=7820138;
    --(VcurlyDepth);
     break;
   }
  case 35:
   {
    sf.pos=7820139;
    if ((VspaceCount >= 2))
    {
     sf.pos=7820140;
     YVTG(Ain, Aout, Aimports, VactionsDone, VeventsDone);
     sf.pos=7820141;
     while (1)
     {
      sf.pos=7820142;
      Vc = YGBv(Ain);
      sf.pos=7820143;
      if (((Vc == 10) || (Vc == Y3QJ)))
      {
       rt = 2;
       goto Y5dZ;
      }
Y5dZ:
      if (rt == 2) { rt &= 1; break; }
     sf.pos=7820144;
     }
     sf.pos=7820145;
     Yakc(Ain);
    }
     break;
   }
  case 91:
   {
    sf.pos=7820146;
    YVTG(Ain, Aout, Aimports, VactionsDone, VeventsDone);
    sf.pos=7820147;
    YrDo(Ain, Aout);
     break;
   }
Yvxd:
   if (rt) goto YfsD;
  }
  sf.pos=7820148;
  if ((VcurlyDepth == -1))
  {
   rt = 2;
   goto YfsD;
  }
  sf.pos=7820149;
  if ((Vc == 32))
  {
   sf.pos=7820150;
   ++(VspaceCount);
  }
  else {
  sf.pos=7820151;
 if ((Vc == 10))
  {
   sf.pos=7820152;
   VspaceCount = 2;
  }
  else
  {
   sf.pos=7820153;
   VspaceCount = 0;
  }
  }
YfsD:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto Yr1ca;
 sf.pos=7820154;
 }
 sf.pos=7820155;
 YVTG(Ain, Aout, NULL, NULL, NULL);
 sf.pos=7820156;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&YwZD));
 sf.pos=7820157;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&YVet));
Yr1ca:
 topFrame = sf.prev;
 return;
}
void Y467(Yev8 *AhtmlToken, Y7Sj *Ain, Tr Aout) {
 Ti VcurlyDepth;
 Ti VspaceCount;
 Zsf sf;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3491300;
 YJ25(Ain->Vinput);
 sf.pos=3491301;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&Yj20));
 sf.pos=3491302;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ZcS3(((Tc*)&YXdf), Ain->Vinput->Vpos->Vfilename, ((Tc*)&Yk1)));
 sf.pos=3491303;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&YmE4));
 sf.pos=3491304;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&Y6my));
 sf.pos=3491305;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&Y12v));
 sf.pos=3491306;
 YGzQ(Ain);
 VcurlyDepth = 0;
 VspaceCount = 0;
 sf.pos=3491307;
 while (1)
 {
  Ti Vc;
  sf.pos=3491308;
  Vc = YGBv(Ain);
  sf.pos=3491309;
  switch (Vc)
  {
  case Y3QJ:
   {
    sf.pos=3491310;
    Y5yp(Ain, ((Tc*)&YF0E));
    sf.pos=3491311;
    rt = 1;
    goto YzbK;
   }
  case 123:
   {
    sf.pos=3491312;
    ++(VcurlyDepth);
     break;
   }
  case 125:
   {
    sf.pos=3491313;
    --(VcurlyDepth);
     break;
   }
  case 35:
   {
    sf.pos=3491314;
    if ((VspaceCount >= 2))
    {
     sf.pos=3491315;
     YVTG(Ain, Aout, NULL, NULL, NULL);
     sf.pos=3491316;
     while (1)
     {
      sf.pos=3491317;
      Vc = YGBv(Ain);
      sf.pos=3491318;
      if (((Vc == 10) || (Vc == Y3QJ)))
      {
       rt = 2;
       goto YuWS;
      }
YuWS:
      if (rt == 2) { rt &= 1; break; }
     sf.pos=3491319;
     }
     sf.pos=3491320;
     Yakc(Ain);
    }
     break;
   }
  case 91:
   {
    sf.pos=3491321;
    YVTG(Ain, Aout, NULL, NULL, NULL);
    sf.pos=3491322;
    YrDo(Ain, Aout);
     break;
   }
YzbK:
   if (rt) goto YDlX;
  }
  sf.pos=3491323;
  if ((VcurlyDepth == -1))
  {
   rt = 2;
   goto YDlX;
  }
  sf.pos=3491324;
  if ((Vc == 32))
  {
   sf.pos=3491325;
   ++(VspaceCount);
  }
  else {
  sf.pos=3491326;
 if ((Vc == 10))
  {
   sf.pos=3491327;
   VspaceCount = 2;
  }
  else
  {
   sf.pos=3491328;
   VspaceCount = 0;
  }
  }
YDlX:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YTt6a;
 sf.pos=3491329;
 }
 sf.pos=3491330;
 YVTG(Ain, Aout, NULL, NULL, NULL);
 sf.pos=3491331;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ZcS3(((Tc*)&YwSQ), Ain->Vinput->Vpos->Vfilename, ((Tc*)&Y4a0)));
 sf.pos=3491332;
 ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&YVet));
YTt6a:
 topFrame = sf.prev;
 return;
}
Tc *Yakc(Y7Sj *Ain) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vrecorded = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7297300;
 YmK2(Ain->Vinput, 32);
 sf.pos=7297301;
 Vrecorded = YJ25(Ain->Vinput);
 sf.pos=7297302;
 YAit(Ain->Vinput);
 sf.pos=7297303;
 YJ25(Ain->Vinput);
 sf.pos=7297304;
 r = Vrecorded;
 topFrame = sf.prev;
 return r;
}
void YVTG(Y7Sj *Ain, Tr Aout, Td *Aimports, Yhqr *AactionsDone, Yhqr *AeventsDone) {
 Ti Vnl;
 Zsf sf;
 Tc *Vrecorded = NULL;
 Tc *VlastController = NULL;
 Tc *Vvalue = NULL;
 Tl *Zf4 = NULL;
 Tc *Vaction = NULL;
 Tl *Vparts = NULL;
 Tc *VeventName = NULL;
 Tc *VfuncName = NULL;
 Tc *Vkey = NULL;
 Tc *Vtrimmed = NULL;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7928400;
 Vrecorded = Yakc(Ain);
 sf.pos=7928401;
 if ((Aimports != NULL))
 {
  Ti Vidx;
  Vidx = 0;
  sf.pos=7928402;
  while (1)
  {
   Ti Vcidx;
   Ti Vaidx;
   Tb VisAction;
   Ti Vend;
   sf.pos=7928403;
   Vcidx = ZstringFind2(Vrecorded, ((Tc*)&YYRg), Vidx, 0);
   sf.pos=7928404;
   Vaidx = ZstringFind2(Vrecorded, ((Tc*)&Y4QS), Vidx, 0);
   sf.pos=7928405;
   if (((Vcidx < 0) && (Vaidx < 0)))
   {
    rt = 2;
    goto YVUq;
   }
   VisAction = 0;
   sf.pos=7928406;
   if (((Vcidx >= 0) && (Vcidx < Vaidx)))
   {
    sf.pos=7928407;
    Vidx = (Vcidx + 14);
   }
   else
   {
    sf.pos=7928408;
    Vidx = (Vaidx + 10);
    sf.pos=7928409;
    VisAction = 1;
   }
   sf.pos=7928410;
   Vend = Vidx;
   sf.pos=7928411;
   while (((Vend < ZstringSize(Vrecorded)) && (ZstringGetChar(Vrecorded, Vend) != 34)))
   {
    sf.pos=7928412;
    ++(Vend);
   sf.pos=7928413;
   }
   sf.pos=7928414;
   Vvalue = ZstringSlice(Vrecorded, Vidx, (Vend - 1), 0);
   sf.pos=7928415;
   if (VisAction)
   {
    sf.pos=7928416;
    {
     Tfl Zf4i;
     Zf4 = ZstringSplit(Vvalue, ((Tc*)&YS), 0);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Vaction;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=7928417;
     Vparts = ZstringSplit(Vaction, ((Tc*)&Y5), 0);
     sf.pos=7928418;
     if ((ZListSize(Vparts) == 2))
     {
      sf.pos=7928419;
      VeventName = YwOB(((Tc *)ZListGetPtr(Vparts, 0)));
      sf.pos=7928420;
      VfuncName = YwOB(((Tc *)ZListGetPtr(Vparts, 1)));
      sf.pos=7928421;
      if (!(YyHa(AeventsDone, VeventName)))
      {
       sf.pos=7928422;
       ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ZcS3(((Tc*)&YHvt), VeventName, ((Tc*)&YP)));
       sf.pos=7928423;
       Y63C(AactionsDone, VeventName);
      }
      sf.pos=7928424;
      Vkey = ZcS3(VlastController, ((Tc*)&YV), VfuncName);
      sf.pos=7928425;
      if (!(YyHa(AactionsDone, Vkey)))
      {
       sf.pos=7928426;
       ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ZcS5(((Tc*)&YDH6), VlastController, ((Tc*)&YZ02), (t0 = VfuncName), ((Tc*)&Yk1)));
       sf.pos=7928427;
       Y63C(AactionsDone, Vkey);
      }
     }
     sf.pos=7928428;
     }
    }
   }
   else
   {
    sf.pos=7928429;
    if (ZDictHas(Aimports, (Tz)(void*)Vvalue))
    {
     sf.pos=7928430;
     ((Yihi *)ZDictGetPtr(Aimports, (Tz)(void*)Vvalue))->VusedAsController = 1;
    }
    else
    {
     sf.pos=7928431;
     YDli(ZcS(((Tc*)&Y7hl), Vvalue), NULL, 0);
    }
    sf.pos=7928432;
    VlastController = Vvalue;
   }
YVUq:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=7928433;
  }
 }
 Vnl = 0;
 sf.pos=7928434;
 while (1)
 {
  Ti Vi;
  sf.pos=7928435;
  Vnl = ZstringFindChar2(Vrecorded, 10, Vnl, 0);
  sf.pos=7928436;
  if ((Vnl < 0))
  {
   rt = 2;
   goto YpSL;
  }
  sf.pos=7928437;
  Vi = (Vnl + 1);
  sf.pos=7928438;
  while (((Vi < ZstringSize(Vrecorded)) && YBbQ(ZstringGetChar(Vrecorded, Vi))))
  {
   sf.pos=7928439;
   ++(Vi);
  sf.pos=7928440;
  }
  sf.pos=7928441;
  if ((Vi > (Vnl + 1)))
  {
   sf.pos=7928442;
   Vrecorded = ZcS((t1 = ZstringSlice(Vrecorded, 0, Vnl, 0)), (t0 = ZstringSlice(Vrecorded, Vi, -1, 0)));
  }
  sf.pos=7928443;
  Vnl = (Vnl + 1);
YpSL:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=7928444;
 }
 sf.pos=7928445;
 Vtrimmed = YwOB(Vrecorded);
 sf.pos=7928446;
 if ((ZstringSize(Vtrimmed) > 0))
 {
  Ti Vend;
  Tb VfoundNL;
  sf.pos=7928447;
  ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, ((Tc*)&YBY8));
  sf.pos=7928448;
  ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, Vtrimmed);
  sf.pos=7928449;
  Vend = (ZstringSize(Vrecorded) - 1);
  VfoundNL = 0;
  sf.pos=7928450;
  while (((Vend >= 0) && YBbQ(ZstringGetChar(Vrecorded, Vend))))
  {
   sf.pos=7928451;
   if ((ZstringGetChar(Vrecorded, Vend) == 10))
   {
    sf.pos=7928452;
    VfoundNL = 1;
    rt = 2;
    goto Y3eF;
   }
   sf.pos=7928453;
   --(Vend);
Y3eF:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=7928454;
  }
  sf.pos=7928455;
  if (VfoundNL)
  {
   sf.pos=7928456;
   ((Ts (*)(void*, Ti))(Aout.table[10]))(Aout.ptr, 10);
  }
  else {
  sf.pos=7928457;
 if ((Vend < (ZstringSize(Vrecorded) - 1)))
  {
   sf.pos=7928458;
   ((Ts (*)(void*, Ti))(Aout.table[10]))(Aout.ptr, 32);
  }
  }
  sf.pos=7928459;
  ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&YIlR));
 }
 topFrame = sf.prev;
 return;
}
void YrDo(Y7Sj *Ain, Tr Aout) {
 Ti VsquareDepth;
 Zsf sf;
 Tc *VstmtText = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 VsquareDepth = 0;
 sf.pos=9002100;
 while (1)
 {
  sf.pos=9002101;
  switch (YGBv(Ain))
  {
  case Y3QJ:
   {
    sf.pos=9002102;
    Y5yp(Ain, ((Tc*)&YF0E));
    sf.pos=9002103;
    rt = 1;
    goto YCSm;
   }
  case 91:
   {
    sf.pos=9002104;
    ++(VsquareDepth);
     break;
   }
  case 93:
   {
    sf.pos=9002105;
    --(VsquareDepth);
     break;
   }
YCSm:
   if (rt) goto YoZH;
  }
  sf.pos=9002106;
  if ((VsquareDepth == -1))
  {
   rt = 2;
   goto YoZH;
  }
YoZH:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YSRWa;
 sf.pos=9002107;
 }
 sf.pos=9002108;
 YmK2(Ain->Vinput, 32);
 sf.pos=9002109;
 VstmtText = YwOB(YJ25(Ain->Vinput));
 sf.pos=9002110;
 YAit(Ain->Vinput);
 sf.pos=9002111;
 YJ25(Ain->Vinput);
 sf.pos=9002112;
 if (ZstringStartsWith(VstmtText, ((Tc*)&Y8), 0))
 {
  sf.pos=9002113;
  ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, ((Tc*)&YV20));
  sf.pos=9002114;
  ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, ZstringSlice(VstmtText, 1, -1, 0));
  sf.pos=9002115;
  ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&YP));
 }
 else {
 sf.pos=9002116;
 if ((ZstringCmp(VstmtText, ((Tc*)&YJ)) == 0))
 {
  sf.pos=9002117;
  ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, ((Tc*)&Y7yI));
 }
 else
 {
  sf.pos=9002118;
  ((Ts (*)(void*, Tc*))(Aout.table[8]))(Aout.ptr, ((Tc*)&YW_j));
  sf.pos=9002119;
  ((Ts (*)(void*, Tc*))(Aout.table[18]))(Aout.ptr, VstmtText);
 }
 }
YSRWa:
 topFrame = sf.prev;
 return;
}
/*
 * INIT IMT
 */
void ZimtInit(void) {
 {
  Y2KX *p = 0;
  ToY2KX[1].off = (int)((Tc*)&p->Vusec - (Tc*)p);
  ToY2KX[2].off = (int)((Tc*)&p->Vsec - (Tc*)p);
  ToY2KX[3].off = (int)((Tc*)&p->Vmin - (Tc*)p);
  ToY2KX[4].off = (int)((Tc*)&p->Vhour - (Tc*)p);
  ToY2KX[5].off = (int)((Tc*)&p->Vday - (Tc*)p);
  ToY2KX[6].off = (int)((Tc*)&p->Vmonth - (Tc*)p);
  ToY2KX[7].off = (int)((Tc*)&p->Vyear - (Tc*)p);
  ToY2KX[8].off = (int)((Tc*)&p->VweekDay - (Tc*)p);
  ToY2KX[9].off = (int)((Tc*)&p->VyearDay - (Tc*)p);
  ToY2KX[10].off = (int)((Tc*)&p->Vdst - (Tc*)p);
 }
 {
  Ytlm *p = 0;
  ToYtlm[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtlm[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtlm[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YEro *p = 0;
  ToYEro[1].off = (int)((Tc*)&p->Vvalue - (Tc*)p);
  ToYEro[2].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYEro[3].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYEro[4].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YKhn *p = 0;
  YKhn__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YKhn__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YKhn__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYKhn[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYKhn[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYKhn[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y1uN *p = 0;
  Y1uN__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y1uN__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y1uN__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY1uN[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY1uN[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY1uN[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YAxe *p = 0;
  YAxe__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YAxe__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YAxe__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYAxe[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYAxe[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYAxe[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YVNj *p = 0;
  YVNj__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YVNj__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YVNj__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYVNj[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYVNj[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYVNj[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yalz *p = 0;
  Yalz__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yalz__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yalz__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYalz[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYalz[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYalz[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yw3O *p = 0;
  Yw3O__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yw3O__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yw3O__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYw3O[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYw3O[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYw3O[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y2EX *p = 0;
  Y2EX__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y2EX__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y2EX__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY2EX[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY2EX[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY2EX[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YX0i *p = 0;
  YX0i__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YX0i__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YX0i__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYX0i[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYX0i[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYX0i[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YP_P *p = 0;
  YP_P__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YP_P__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YP_P__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYP_P[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYP_P[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYP_P[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YzSI *p = 0;
  YzSI__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YzSI__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YzSI__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYzSI[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYzSI[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYzSI[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YXKl *p = 0;
  YXKl__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YXKl__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YXKl__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYXKl[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYXKl[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYXKl[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YuDC *p = 0;
  YuDC__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YuDC__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YuDC__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYuDC[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYuDC[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYuDC[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YrHq *p = 0;
  YrHq__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YrHq__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YrHq__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYrHq[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYrHq[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYrHq[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YkxB *p = 0;
  ToYkxB[1].off = (int)((Tc*)&p->Vfilename - (Tc*)p);
  ToYkxB[2].off = (int)((Tc*)&p->Vlnum - (Tc*)p);
  ToYkxB[3].off = (int)((Tc*)&p->Vcol - (Tc*)p);
  ToYkxB[4].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Yw8L *p = 0;
  Yw8L__Yw8L_I_imt[20] = (Tc*)((Tc*)&p->Vfd - (Tc*)p);
  Yw8L__Yw8L_I_imt[21] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYw8L[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
 }
 {
  YjUM *p = 0;
  ToYjUM[1].off = (int)((Tc*)&p->VsLen - (Tc*)p);
  ToYjUM[2].off = (int)((Tc*)&p->Vs - (Tc*)p);
  ToYjUM[3].off = (int)((Tc*)&p->Vx - (Tc*)p);
 }
 {
  Yhqr *p = 0;
  ToYhqr[1].off = (int)((Tc*)&p->Vdict - (Tc*)p);
 }
 {
  YuMQ *p = 0;
  ToYuMQ[1].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Y86c *p = 0;
  Y86c__YuQR_I_imt[1] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  Y86c__YuQR_I_imt[2] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  Y86c__YuQR_I_imt[3] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  Y86c__YuQR_I_imt[4] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  Y86c__YuQR_I_imt[5] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  Y86c__YuQR_I_imt[6] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  Y86c__YuQR_I_imt[7] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  Y86c__YuQR_I_imt[8] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  Y86c__YuQR_I_imt[9] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  ToY86c[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToY86c[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY86c[3].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY86c[4].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY86c[5].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY86c[6].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY86c[7].off = (int)((Tc*)&p->VsetCount - (Tc*)p);
  ToY86c[8].off = (int)((Tc*)&p->VcanRepeat - (Tc*)p);
  ToY86c[9].off = (int)((Tc*)&p->VnoCompactVal - (Tc*)p);
  ToY86c[10].off = (int)((Tc*)&p->VargOpt - (Tc*)p);
  ToY86c[11].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YJQu *p = 0;
  ToYJQu[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToYJQu[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToYJQu[3].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYJQu[4].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYJQu[5].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYJQu[6].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYJQu[7].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYJQu[8].off = (int)((Tc*)&p->VsetCount - (Tc*)p);
  ToYJQu[9].off = (int)((Tc*)&p->VcanRepeat - (Tc*)p);
  ToYJQu[10].off = (int)((Tc*)&p->VnoCompactVal - (Tc*)p);
  ToYJQu[11].off = (int)((Tc*)&p->VargOpt - (Tc*)p);
  ToYJQu[12].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YzqH *p = 0;
  ToYzqH[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToYzqH[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToYzqH[3].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYzqH[4].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYzqH[5].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYzqH[6].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYzqH[7].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYzqH[8].off = (int)((Tc*)&p->VsetCount - (Tc*)p);
  ToYzqH[9].off = (int)((Tc*)&p->VcanRepeat - (Tc*)p);
  ToYzqH[10].off = (int)((Tc*)&p->VnoCompactVal - (Tc*)p);
  ToYzqH[11].off = (int)((Tc*)&p->VargOpt - (Tc*)p);
  ToYzqH[12].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Y_SI *p = 0;
  ToY_SI[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToY_SI[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY_SI[3].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY_SI[4].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY_SI[5].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY_SI[6].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY_SI[7].off = (int)((Tc*)&p->VsetCount - (Tc*)p);
  ToY_SI[8].off = (int)((Tc*)&p->VcanRepeat - (Tc*)p);
  ToY_SI[9].off = (int)((Tc*)&p->VnoCompactVal - (Tc*)p);
  ToY_SI[10].off = (int)((Tc*)&p->VargOpt - (Tc*)p);
  ToY_SI[11].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YeYq *p = 0;
  ToYeYq[1].off = (int)((Tc*)&p->Vfd - (Tc*)p);
  ToYeYq[2].off = (int)((Tc*)&p->Vtext - (Tc*)p);
  ToYeYq[3].off = (int)((Tc*)&p->VtextIdx - (Tc*)p);
  ToYeYq[4].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYeYq[5].off = (int)((Tc*)&p->VprevLineCol - (Tc*)p);
  ToYeYq[6].off = (int)((Tc*)&p->VcharStack - (Tc*)p);
  ToYeYq[7].off = (int)((Tc*)&p->Vindent - (Tc*)p);
  ToYeYq[8].off = (int)((Tc*)&p->VallowTabs - (Tc*)p);
  ToYeYq[9].off = (int)((Tc*)&p->VrecordWriter - (Tc*)p);
 }
 {
  Ys_q *p = 0;
  Ys_q__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Ys_q__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Ys_q__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYs_q[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYs_q[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYs_q[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YOEA *p = 0;
  YOEA__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YOEA__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YOEA__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYOEA[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYOEA[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYOEA[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YqvM *p = 0;
  ToYqvM[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYqvM[2].off = (int)((Tc*)&p->Vnr - (Tc*)p);
  ToYqvM[3].off = (int)((Tc*)&p->Vtype - (Tc*)p);
  ToYqvM[4].off = (int)((Tc*)&p->Vrepeated - (Tc*)p);
 }
 {
  YLWE *p = 0;
  ToYLWE[1].off = (int)((Tc*)&p->Vwriter - (Tc*)p);
  ToYLWE[2].off = (int)((Tc*)&p->Vindent - (Tc*)p);
  ToYLWE[3].off = (int)((Tc*)&p->VuseNr - (Tc*)p);
  ToYLWE[4].off = (int)((Tc*)&p->VderefId - (Tc*)p);
  ToYLWE[5].off = (int)((Tc*)&p->VderefIdSize - (Tc*)p);
  ToYLWE[6].off = (int)((Tc*)&p->VderefTime - (Tc*)p);
  ToYLWE[7].off = (int)((Tc*)&p->VderefTimeSize - (Tc*)p);
 }
 {
  Ysbp *p = 0;
  Ysbp__YFL0_I_imt[1] = (Tc*)((Tc*)&p->VderefTime - (Tc*)p);
  Ysbp__YFL0_I_imt[2] = (Tc*)((Tc*)&p->VderefId - (Tc*)p);
  Ysbp__YFL0_I_imt[3] = (Tc*)((Tc*)&p->VderefTimeSize - (Tc*)p);
  Ysbp__YFL0_I_imt[4] = (Tc*)((Tc*)&p->VderefIdSize - (Tc*)p);
  ToYsbp[1].off = (int)((Tc*)&p->Vf_line - (Tc*)p);
  ToYsbp[2].off = (int)((Tc*)&p->Vhas_line - (Tc*)p);
  ToYsbp[3].off = (int)((Tc*)&p->Vf_column - (Tc*)p);
  ToYsbp[4].off = (int)((Tc*)&p->Vhas_column - (Tc*)p);
  ToYsbp[5].off = (int)((Tc*)&p->Vf_filename - (Tc*)p);
  ToYsbp[6].off = (int)((Tc*)&p->VderefTime - (Tc*)p);
  ToYsbp[7].off = (int)((Tc*)&p->VderefId - (Tc*)p);
  ToYsbp[8].off = (int)((Tc*)&p->VderefTimeSize - (Tc*)p);
  ToYsbp[9].off = (int)((Tc*)&p->VderefIdSize - (Tc*)p);
 }
 {
  Yev8 *p = 0;
  ToYev8[1].off = (int)((Tc*)&p->Vtype - (Tc*)p);
  ToYev8[2].off = (int)((Tc*)&p->Vvalue - (Tc*)p);
  ToYev8[3].off = (int)((Tc*)&p->VhasComment - (Tc*)p);
  ToYev8[4].off = (int)((Tc*)&p->VhasCommentFirst - (Tc*)p);
  ToYev8[5].off = (int)((Tc*)&p->VzuiPos - (Tc*)p);
 }
 {
  YsZx *p = 0;
  ToYsZx[1].off = (int)((Tc*)&p->Vchildren - (Tc*)p);
  ToYsZx[2].off = (int)((Tc*)&p->Vvalue - (Tc*)p);
  ToYsZx[3].off = (int)((Tc*)&p->Vtype - (Tc*)p);
  ToYsZx[4].off = (int)((Tc*)&p->VisKeyword - (Tc*)p);
 }
 {
  Y7Sj *p = 0;
  ToY7Sj[1].off = (int)((Tc*)&p->Vinput - (Tc*)p);
  ToY7Sj[2].off = (int)((Tc*)&p->VtokenStack - (Tc*)p);
  ToY7Sj[3].off = (int)((Tc*)&p->VusedIdKeywords - (Tc*)p);
 }
 {
  Yihi *p = 0;
  ToYihi[1].off = (int)((Tc*)&p->VfileName - (Tc*)p);
  ToYihi[2].off = (int)((Tc*)&p->VusedAsController - (Tc*)p);
 }
}

/*
 * INIT GLOBALS
 */
int ZglobInit(int round) {
 int done = 1;
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 sf.frof = NULL;
 topFrame = &sf;
 done &= JIOModule(round);
 done &= JLOGModule(round);
 done &= JARGModule(round);
 done &= JToken(round);
 done &= JTokenInput(round);
 if (round == 2001) {
 }
 topFrame = sf.prev;
 return done;
}

/*
 * MAIN
 */

#if defined(__MINGW32__) || defined(_MSC_VER)
# define CATCH_SIG(sig, func) signal(sig, func)
  typedef struct SEH_EXCEPTION_REGISTRATION_S SEH_EXCEPTION_REGISTRATION;
  struct SEH_EXCEPTION_REGISTRATION_S
  {
    SEH_EXCEPTION_REGISTRATION *prev;
    PEXCEPTION_HANDLER handler;
  };
  static EXCEPTION_DISPOSITION exception_handler(PEXCEPTION_RECORD pRecord, SEH_EXCEPTION_REGISTRATION *pReg, PCONTEXT pContext, PEXCEPTION_RECORD pRecord2) {
   Zdeadly(11);
   return ExceptionContinueSearch;
  }
#else
# define CATCH_SIG(sig, func) catch_sig(sig, func)
void catch_sig(int sig, void *func) {
 struct sigaction act;
 act.sa_handler = func;
 sigemptyset(&act.sa_mask);
 act.sa_flags = SA_NODEFER;
 sigaction(sig, &act, NULL);
}
#endif

int Fmain(void);
int main(int argc, char **argv) {
 int r = 0;
 int round = 0;
#if defined(__MINGW32__) || defined(_MSC_VER)
 SEH_EXCEPTION_REGISTRATION seh_er;
 seh_er.handler = (PEXCEPTION_HANDLER)(exception_handler);
 asm volatile ("movl %%fs:0, %0" : "=r" (seh_er.prev));
 asm volatile ("movl %0, %%fs:0" : : "r" (&seh_er));
#else
# ifdef SIGSEGV
 CATCH_SIG(SIGSEGV, Zdeadly);
# endif
# ifdef SIGBUS
 CATCH_SIG(SIGBUS, Zdeadly);
# endif
# ifdef SIGFPE
 CATCH_SIG(SIGFPE, Zdeadly);
# endif
#endif
#if defined(__MINGW32__) || defined(_MSC_VER)
# ifdef __MINGW32__
 _fmode = _O_BINARY;
# else
 _set_fmode(_O_BINARY);
# endif
 _setmode(_fileno(stdin), _O_BINARY);
 _setmode(_fileno(stdout), _O_BINARY);
 _setmode(_fileno(stderr), _O_BINARY);
#endif
 emergencyAlloc = malloc(16384);
 ZimtInit();
 ZglobInit(round++);
 YzvW = Zstr(argv[0]);
 Y1p3 = ZnewList(&string__T, 0);
 {
  int i;
  for (i = 1; i < argc; ++i) {
   ZLa(Y1p3, -1, (Tz)(void*)Zstr(argv[i]));
  }
 }

 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 1002) ZthrowCstringInit("Early initialization not done within 1000 rounds");
 }
 YZH8();

 round = 2001;
 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 3002) ZthrowCstringInit("Initialization not done within 1000 rounds");
 }
 r = Fmain();
 beforeExit();
 if (topFrame != NULL) fprintf(stderr, "INTERNAL: topFrame not NULL\n");
 return r;
}


int Fmain(void) {
 Zsf sf;
 Ti r = 0;
 Tc *VinFileName = NULL;
 Tc *VoutFileName = NULL;
 Tr VinFile = {NULL};
 YeYq *Vinput = 0;
 Y7Sj *Vin = 0;
 Tr VoutFile = {NULL};
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 r = 0;
 sf.pos=527000;
 if ((Yd2Z() != 2))
 {
  sf.pos=527001;
  Yl0k(ZcS3(((Tc*)&YZVC), YzvW, ((Tc*)&Y3OJ)));
  sf.pos=527002;
  Zexit(NULL, 1);
  return 0;
 }
 sf.pos=527003;
 VinFileName = YtgL(0);
 sf.pos=527004;
 if (!(ZstringEndsWith(VinFileName, ((Tc*)&YaJI), 0)))
 {
  sf.pos=527005;
  Yl0k(ZcS(((Tc*)&Y8iJ), VinFileName));
  sf.pos=527006;
  Zexit(NULL, 1);
  return 0;
 }
 sf.pos=527007;
 VoutFileName = YtgL(1);
 sf.pos=527008;
 if (!(ZstringEndsWith(VoutFileName, ((Tc*)&YYv4), 0)))
 {
  sf.pos=527009;
  Yl0k(ZcS(((Tc*)&YIhh), VoutFileName));
  sf.pos=527010;
  Zexit(NULL, 1);
  return 0;
 }
 sf.pos=527011;
 VinFile = YsGz(VinFileName);
 sf.pos=527012;
 Vinput = YOdr(NULL, VinFile, VinFileName, ((Tc*)&Ya), 1);
 sf.pos=527013;
 Vin = YUwt(NULL, Vinput);
 sf.pos=527014;
 VoutFile = YiBk(VoutFileName, 1);
 sf.pos=527015;
 YSxp(Vin, VoutFile);
 sf.pos=527016;
 if ((Yrpn > 0))
 {
  sf.pos=527017;
  ((Ts (*)(void*, Tc*))(VoutFile.table[1]))(VoutFile.ptr, ZcS(((Tc*)&Yz0u), VinFileName));
  sf.pos=527018;
  r = 1;
  rt = 1;
  goto YtK3;
 }
 sf.pos=527019;
 r = 0;
YtK3:
 topFrame = sf.prev;
 return r;
}
