/*
 * Generated from Zimbu file zimbuConfig.zu
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
typedef struct ZforList__S Tfl; /* FOR in list */
typedef struct ZforRange__S Tfr; /* FOR in range */

typedef struct CArray__S Ta; /* array head */

typedef struct CListHead__S Tl; /* list head */

typedef unsigned long Zhashtype;
typedef struct CDictItem__S CDictItem;
typedef struct CDictHead__S Td;

/* including EModule typedefs */
typedef struct Ytlm__S Ytlm; /* MEModule.Exception */
typedef struct YEro__S YEro; /* MEModule.Exit */
typedef struct YKhn__S YKhn; /* MEModule.OutOfMemory */
typedef struct Y1uN__S Y1uN; /* MEModule.NilAccess */
typedef struct YAxe__S YAxe; /* MEModule.MemoryAccess */
typedef struct YVNj__S YVNj; /* MEModule.Init */
typedef struct Yalz__S Yalz; /* MEModule.BadValue */
typedef struct Y2EX__S Y2EX; /* MEModule.KeyNotFound */
typedef struct YX0i__S YX0i; /* MEModule.KeyExists */
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
/* including zimbuConfig typedefs */
/* including Proto typedefs */
typedef struct Ys_q__S Ys_q; /* MProto.E_ProduceError */
typedef struct YOEA__S YOEA; /* MProto.E_BinaryError */
typedef struct YqvM__S YqvM; /* MProto.FieldSpec */
typedef struct YLWE__S YLWE; /* MProto.Writer */
/* Proto done */
typedef struct YNdL__S YNdL; /* MZimbu.Config */
/* zimbuConfig done */
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
struct ZforList__S {
 Tl *l;
 Ti i;
 Ti *keyp;
 void *valp;
};
struct ZforRange__S {
 Ti idx;
 Ti step;
 Ti last;
};

void ZthrowObject(Tr *eo);
void ZthrowIobject(Tr eo);

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
YkxB *MZ__callerPos(void);

Tl *MZ__backtrace(Ti zkip, Ti limit);

YkxB *MZ__posnr2pos(YkxB *t, Ti pos);
typedef struct {
 char text[5];
} Zs5;
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
typedef struct {
 char text[3];
} Zs3;
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
typedef struct {
 char text[8];
} Zs8;
struct YkxB__S {
 Tc *Vfilename;
 Ti Vlnum;
 Ti Vcol;
 Tc *Vtext;
};
extern Tto YkxB__T;
/* ZModule done */
/* including IOModule structs */
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
/* including zimbuConfig structs */
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
struct YNdL__S {
Ti VderefTime;
Ti VderefId;
Ti VderefTimeSize;
Ti VderefIdSize;
 Tc *Vf_mallocArg;
 Tc *Vf_threadArg;
 Tc *Vf_socketArg;
 Tc *Vf_mathArg;
 Ti Vf_haveResolve;
 Ti Vf_haveFork;
 Tc *Vf_exeSuffix;
 Tc *Vf_exePrefix;
 Ti Vf_haveSigaction;
 Ti Vf_gcWithThreads;
 Tc *Vf_int16Name;
 Tc *Vf_int32Name;
 Tc *Vf_int64Name;
 Tc *Vf_nat16Name;
 Tc *Vf_nat32Name;
 Tc *Vf_nat64Name;
 Tc *Vf_floatName;
 Tc *Vf_float32Name;
 Tc *Vf_intPtrName;
 Tc *Vf_printIntFormat;
 Tc *Vf_printNatFormat;
 Tc *Vf_scanfHexFormat;
 Ti Vf_isMingw;
};
extern Tto YNdL__T;
/* zimbuConfig done */
typedef struct {
 char text[25];
} Zs25;
typedef struct {
 char text[27];
} Zs27;
typedef struct {
 char text[36];
} Zs36;
typedef struct {
 char text[68];
} Zs68;
typedef struct {
 char text[32];
} Zs32;
typedef struct {
 char text[20];
} Zs20;
/*
 * DECLARE FUNCTIONS AND GLOBALS
 */
Zs5 ZNilString = {"\003NIL\000"};
/* including EModule declarations */
void YxaJ(Ytlm *t, Tr Aw); /* MEModule__CException.writeTo */
Zs4 YFDa = {"\002: \000"};
Zs13 YHbP = {"\013Exception: \000"};
Zs11 YDGe = {"\011Exception\000"};
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw); /* MEModule__CException.writeTo */
Zs39 Y62e = {"\045\nStack backtrace (last called first):\000"};
Zs12 Yv6_ = {"\012\n(unknown)\000"};
Zs3 Yk = {"\001\n\000"};
To ToYtlm[4];
void YXHSa(YEro *t, Tr Aw); /* MEModule__CExit.writeTo */
Zs7 YxJ1 = {"\005EXIT \000"};
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw); /* MEModule__CExit.writeTo__p1 */
To ToYEro[4];
Zs6 YJMo = {"\004Exit\000"};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit); /* MEModule__COutOfMemory.NEW */
Zs28 YIBz = {"\032Out of memory (allocating \000"};
Zs9 YDSH = {"\007 bytes)\000"};
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
Tc *YKhn__Ytlm_I_imt[14];
To ToYKhn[4];
Zs13 Y9Fv = {"\013OutOfMemory\000"};
void Y1KV(Ti Asize); /* MEModule.throwOutOfMemorySize */
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg); /* MEModule__CNilAccess.NEW__p2 */
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
Tc *Y1uN__Ytlm_I_imt[14];
To ToY1uN[4];
Zs11 Y4wO = {"\011NilAccess\000"};
void YvdV(YkxB *Apos, Tc *Atext); /* MEModule.throwNil */
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg); /* MEModule__CMemoryAccess.NEW__p2 */
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
Tc *YAxe__Ytlm_I_imt[14];
To ToYAxe[4];
Zs14 Y4QW = {"\014MemoryAccess\000"};
void YE93(Ti Anr); /* MEModule.throwDeadly */
Zs13 YkfG = {"\013signal SEGV\000"};
Zs12 YoEx = {"\012signal FPE\000"};
Zs12 YQNH = {"\012signal BUS\000"};
Zs9 YpCZ = {"\007signal \000"};
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw); /* MEModule__CInit.writeTo__p2 */
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw); /* MEModule__CInit.writeTo__p2 */
Tc *YVNj__Ytlm_I_imt[14];
To ToYVNj[4];
Zs6 Ysqt = {"\004Init\000"};
void Y3w6(Tc *Atext); /* MEModule.throwInit */
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg); /* MEModule__CBadValue.NEW__p2 */
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
Tc *Yalz__Ytlm_I_imt[14];
To ToYalz[4];
Zs10 YEZq = {"\010BadValue\000"};
void Yaez(Tc *Atext); /* MEModule.throwBadValue */
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg); /* MEModule__CKeyNotFound.NEW__p3 */
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
Tc *Y2EX__Ytlm_I_imt[14];
To ToY2EX[4];
Zs13 YRiW = {"\013KeyNotFound\000"};
void Yxmk(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyNotFound */
Zs17 Ym6C = {"\017Key not found: \000"};
void Y5LT(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyNotFound */
Zs18 YJ3Y = {"\020Key not found: \"\000"};
Zs3 YI = {"\001\"\000"};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
Tc *YX0i__Ytlm_I_imt[14];
To ToYX0i[4];
Zs11 Y9_h = {"\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {"\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {"\025Key already exists: \"\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
Tc *YzSI__Ytlm_I_imt[14];
To ToYzSI[4];
Zs14 YxFl = {"\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
Tc *YXKl__Ytlm_I_imt[14];
To ToYXKl[4];
Zs9 YTj3 = {"\007IOError\000"};
YuDC *YdhH(YuDC *t); /* MEModule__CWrongType.NEW */
Zs15 Ynjz = {"\015Type mismatch\000"};
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
Tc *YuDC__Ytlm_I_imt[14];
To ToYuDC[4];
Zs11 YCoZ = {"\011WrongType\000"};
void YTuG(Ti Apos); /* MEModule.throwWrongType */
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg); /* MEModule__CInternal.NEW__p2 */
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
Tc *YrHq__Ytlm_I_imt[14];
To ToYrHq[4];
Zs10 YVki = {"\010Internal\000"};
void YUSH(YkxB *Apos, Tc *Atext); /* MEModule.throwInternal */
void YxIS(Tr Ae); /* MEModule.unhandledException */
void YvL0(Tr Ae); /* MEModule.writeToStderr */
void YQar(Tr A0, Tb A1, Tr A2); /* Ytlm_I__MwriteTo_I__bool__Yw8L_I */
/* EModule done */
/* including ZModule declarations */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {"\016[unknown file]\000"};
Zs8 YBpY = {"\006 line \000"};
Zs7 Y8ES = {"\005 col \000"};
To ToYkxB[3];
Zs5 YBCs = {"\003Pos\000"};
/* ZModule done */
/* including IOModule declarations */
Tr Y59X = {NULL}; /* MIOModule.stdin */
Tr Yb0q = {NULL}; /* MIOModule.stdout */
Tr YeNQ = {NULL}; /* MIOModule.stderr */
Tr Yd89(); /* MIOModule.newStdin */
Tr Yvyt(); /* MIOModule.newStdout */
Tr YsM3(); /* MIOModule.newStderr */
Tc **YdXi__imtt[4];
Ts YwHoa(Yw8L *t, Tc *Atext); /* MIOModule__CFile.write */
Zs18 YQe8 = {"\020File is not open\000"};
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber); /* MIOModule__CFile.write__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__Yw8L_I_imt[38];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[2];
Zs6 YtTU = {"\004File\000"};
Tr YiBk(Tc *AfileName, Tb Atruncate); /* MIOModule.fileWriter */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Zs2 Ya = {"\000\000"};
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Tc *YjUM__YdXi_imt[3];
To ToYjUM[3];
Zs14 YE4c = {"\014StringWriter\000"};
Tb Y0YB(Tc *Aname); /* MIOModule.isReadable */
int JIOModule(int round);
/* IOModule done */
/* including zimbuConfig declarations */
/* including Proto declarations */
Tt MProto__EType__T = {23, 0, MProto__EType__name};
Tt MProto__EBinaryType__T = {23, 0, 0};
Ys_q *Ys_q__YwtA__YRHR(Ys_q *t, Tc *Amsg); /* MProto__CE_ProduceError.NEW__p2 */
void Ys_q__YwtA__YxaJa(Ys_q *t, Tb Averbose, Tr Aw); /* MProto__CE_ProduceError.writeTo__p2 */
void Ys_q__YwtA__YxaJ(Ys_q *t, Tr Aw); /* MProto__CE_ProduceError.writeTo__p2 */
Tc *Ys_q__Ytlm_I_imt[14];
To ToYs_q[4];
Zs16 Y4sk = {"\016E_ProduceError\000"};
YOEA *YOEA__YwtA__YRHR(YOEA *t, Tc *Amsg); /* MProto__CE_BinaryError.NEW__p2 */
void YOEA__YwtA__YxaJa(YOEA *t, Tb Averbose, Tr Aw); /* MProto__CE_BinaryError.writeTo__p2 */
void YOEA__YwtA__YxaJ(YOEA *t, Tr Aw); /* MProto__CE_BinaryError.writeTo__p2 */
Tc *YOEA__Ytlm_I_imt[14];
To ToYOEA[4];
Zs15 YtJ_ = {"\015E_BinaryError\000"};
YqvM *Ykww(YqvM *t, Tc *Aname, Ti Anr, Te Atype, Tb Arepeated); /* MProto__CFieldSpec.NEW */
To ToYqvM[2];
Zs11 Y5d5 = {"\011FieldSpec\000"};
YLWE *YrCUb(YLWE *t, Tr Awriter, Tc *Aindent, Tb AuseNr); /* MProto__CWriter.NEW */
void YEV9(YLWE *t); /* MProto__CWriter.initDeref */
Ti YcTI = 0; /* MProto__CWriter__X.derefTime */
To ToYLWE[3];
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
Zs3 YT = {"\001-\000"};
Zs4 YN2 = {"\002# \000"};
Zs9 Y0Eh = {"\007 size: \000"};
Zs9 Y8RH = {"\007 bytes\n\000"};
void YWEg(Tr Amsg, YqvM *Afspec, Ti Aidx, YLWE *AprotoWriter); /* MProto.writeOneTextField */
Zs5 YxR2 = {"\003.9g\000"};
Zs6 YmwI = {"\004.17g\000"};
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
YNdL *YA_Z(YNdL *t); /* MZimbu__CConfig.NEW */
Tc *Ykvoa(YNdL *t); /* MZimbu__CConfig.name */
Zs8 YF2d = {"\006Config\000"};
YNdL *YrF2(YNdL *t, Tc *Av); /* MZimbu__CConfig.setMallocArg */
Tb Y8zW(YNdL *t); /* MZimbu__CConfig.hasMallocArg */
YNdL *YOPG(YNdL *t, Tc *Av); /* MZimbu__CConfig.setThreadArg */
Tb YvKz(YNdL *t); /* MZimbu__CConfig.hasThreadArg */
YNdL *YWoP(YNdL *t, Tc *Av); /* MZimbu__CConfig.setSocketArg */
Tb YDjI(YNdL *t); /* MZimbu__CConfig.hasSocketArg */
YNdL *Yjrt(YNdL *t, Tc *Av); /* MZimbu__CConfig.setMathArg */
Tb Y8om(YNdL *t); /* MZimbu__CConfig.hasMathArg */
YNdL *Yqt5(YNdL *t, Tb Av); /* MZimbu__CConfig.setHaveResolve */
Tb Y3Lr(YNdL *t); /* MZimbu__CConfig.hasHaveResolve */
YNdL *YBhB(YNdL *t, Tb Av); /* MZimbu__CConfig.setHaveFork */
Tb YcPw(YNdL *t); /* MZimbu__CConfig.hasHaveFork */
YNdL *YNXX(YNdL *t, Tc *Av); /* MZimbu__CConfig.setExeSuffix */
Tb YuSQ(YNdL *t); /* MZimbu__CConfig.hasExeSuffix */
YNdL *YcU3(YNdL *t, Tc *Av); /* MZimbu__CConfig.setExePrefix */
Tb YUOX(YNdL *t); /* MZimbu__CConfig.hasExePrefix */
YNdL *Y118(YNdL *t, Tb Av); /* MZimbu__CConfig.setHaveSigaction */
Tb YJrk(YNdL *t); /* MZimbu__CConfig.hasHaveSigaction */
YNdL *YEDn(YNdL *t, Tb Av); /* MZimbu__CConfig.setGcWithThreads */
Tb Yo45(YNdL *t); /* MZimbu__CConfig.hasGcWithThreads */
YNdL *YIIX(YNdL *t, Tc *Av); /* MZimbu__CConfig.setInt16Name */
Tb YpDQ(YNdL *t); /* MZimbu__CConfig.hasInt16Name */
YNdL *Y8TB(YNdL *t, Tc *Av); /* MZimbu__CConfig.setInt32Name */
Tb YQOu(YNdL *t); /* MZimbu__CConfig.hasInt32Name */
YNdL *Y6PM(YNdL *t, Tc *Av); /* MZimbu__CConfig.setInt64Name */
Tb YOKF(YNdL *t); /* MZimbu__CConfig.hasInt64Name */
YNdL *YXzR(YNdL *t, Tc *Av); /* MZimbu__CConfig.setNat16Name */
Tb YEuK(YNdL *t); /* MZimbu__CConfig.hasNat16Name */
YNdL *YnLv(YNdL *t, Tc *Av); /* MZimbu__CConfig.setNat32Name */
Tb Y4Fo(YNdL *t); /* MZimbu__CConfig.hasNat32Name */
YNdL *YlHG(YNdL *t, Tc *Av); /* MZimbu__CConfig.setNat64Name */
Tb Y2Bz(YNdL *t); /* MZimbu__CConfig.hasNat64Name */
YNdL *Yla2(YNdL *t, Tc *Av); /* MZimbu__CConfig.setFloatName */
Tb Y24V(YNdL *t); /* MZimbu__CConfig.hasFloatName */
YNdL *YI4N(YNdL *t, Tc *Av); /* MZimbu__CConfig.setFloat32Name */
Tb YftC(YNdL *t); /* MZimbu__CConfig.hasFloat32Name */
YNdL *YJ6V(YNdL *t, Tc *Av); /* MZimbu__CConfig.setIntPtrName */
Tb YTxb(YNdL *t); /* MZimbu__CConfig.hasIntPtrName */
YNdL *YUld(YNdL *t, Tc *Av); /* MZimbu__CConfig.setPrintIntFormat */
Tb YlFq(YNdL *t); /* MZimbu__CConfig.hasPrintIntFormat */
YNdL *Y8c7(YNdL *t, Tc *Av); /* MZimbu__CConfig.setPrintNatFormat */
Tb Y6Nw(YNdL *t); /* MZimbu__CConfig.hasPrintNatFormat */
YNdL *YRMv(YNdL *t, Tc *Av); /* MZimbu__CConfig.setScanfHexFormat */
Tb Yoe8(YNdL *t); /* MZimbu__CConfig.hasScanfHexFormat */
YNdL *YeB5(YNdL *t, Tb Av); /* MZimbu__CConfig.setIsMingw */
Tb YdfK(YNdL *t); /* MZimbu__CConfig.hasIsMingw */
Tb YFKUa(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.boolGet */
Tc *Yxv3a(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.stringGet */
Tb YlZca(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.hasField */
Tl *Yozoa(YNdL *t); /* MZimbu__CConfig.fieldSpecs */
Zs11 Y1i0 = {"\011mallocArg\000"};
Zs11 YF8m = {"\011threadArg\000"};
Zs11 Yxze = {"\011socketArg\000"};
Zs9 YdV8 = {"\007mathArg\000"};
Zs13 Yefj = {"\013haveResolve\000"};
Zs10 YqSF = {"\010haveFork\000"};
Zs11 YG05 = {"\011exeSuffix\000"};
Zs11 Yg4Z = {"\011exePrefix\000"};
Zs15 YUN3 = {"\015haveSigaction\000"};
Zs15 Yeai = {"\015gcWithThreads\000"};
Zs11 YLf6 = {"\011int16Name\000"};
Zs11 Yk4r = {"\011int32Name\000"};
Zs11 Ym8g = {"\011int64Name\000"};
Zs11 Ywoc = {"\011nat16Name\000"};
Zs11 Y5cy = {"\011nat32Name\000"};
Zs11 Y7gn = {"\011nat64Name\000"};
Zs11 Y7N0 = {"\011floatName\000"};
Zs13 Y4ZK = {"\013float32Name\000"};
Zs12 YlnY = {"\012intPtrName\000"};
Zs16 YMLF = {"\016printIntFormat\000"};
Zs16 YxUL = {"\016printNatFormat\000"};
Zs16 YPkn = {"\016scanfHexFormat\000"};
Zs9 Y83L = {"\007isMingw\000"};
Tl *YR6X = NULL; /* MZimbu__CConfig__X.fieldSpecs */
Ti YNdL__Y0zD(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.enumGet__p1 */
Ti YNdL__Y0zDa(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.enumGet__p1 */
Tc *YNdL__YytN(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.enumNameGet__p1 */
Tc *YNdL__YytNa(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.enumNameGet__p1 */
Ti YNdL__YGR8(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.intGet__p1 */
Ti YNdL__YGR8a(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.intGet__p1 */
Ti32 YNdL__YAAo(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.int32Get__p1 */
Ti32 YNdL__YAAoa(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.int32Get__p1 */
Tu YNdL__YRqV(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.uint64Get__p1 */
Tu YNdL__YRqVa(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.uint64Get__p1 */
Tu32 YNdL__Y0tE(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.uint32Get__p1 */
Tu32 YNdL__Y0tEa(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.uint32Get__p1 */
Tf32 YNdL__Yyt7(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.floatGet__p1 */
Tf32 YNdL__Yyt7a(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.floatGet__p1 */
Tf YNdL__Yybv(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.doubleGet__p1 */
Tf YNdL__Yybva(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.doubleGet__p1 */
Tb YNdL__YGfza(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.boolGet__p1 */
Tc *YNdL__YsRaa(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.stringGet__p1 */
Tr YNdL__Yo5y(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.messageGet__p1 */
Tr YNdL__Yo5ya(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.messageGet__p1 */
Ti YNdL__YUDN(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.size__p1 */
Tc *YNdL__YC5i(YNdL *t); /* MZimbu__CConfig.ToString__p1 */
Tc *YNdL__YFL0_I_imt[54];
To ToYNdL[19];
int JzimbuConfig(int round);
/* zimbuConfig done */
Zs10 Yj_i = {"\010/usr/lib\000"};
Zs12 YftF = {"\012/usr/lib64\000"};
Zs6 YK0f = {"\004/lib\000"};
Zs8 YIMX = {"\006/lib64\000"};
Zs16 YDCH = {"\016/usr/local/lib\000"};
Zs25 YYHU = {"\027/usr/lib/i386-linux-gnu\000"};
Zs27 YGiO = {"\031/usr/lib/x86_64-linux-gnu\000"};
Zs18 Y912 = {"\020tcmalloc_minimal\000"};
Zs10 Y56Y = {"\010tcmalloc\000"};
Zs5 YEk4 = {"\003.so\000"};
Zs4 Y1ja = {"\002-l\000"};
Zs36 YbiD = {"\042tcmalloc_minimal library NOT FOUND\000"};
Zs68 Y51Q = {"\102install the tcmalloc_minimal library to make Zimbu programs faster\000"};
Zs11 YglX = {"\011-lpthread\000"};
Zs5 YtA1 = {"\003-lm\000"};
Zs7 YX_1 = {"\005short\000"};
Zs34 Y8PB = {"\040WARNING: int16 size is actually \000"};
Zs7 YMSv = {"\005 bits\000"};
Zs5 Y1Qt = {"\003int\000"};
Zs6 YDFJ = {"\004long\000"};
Zs34 Ynz4 = {"\040WARNING: int32 size is actually \000"};
Zs11 YDR5 = {"\011long long\000"};
Zs7 YmXc = {"\005%I64d\000"};
Zs7 YGXc = {"\005%I64x\000"};
Zs7 YDXc = {"\005%I64u\000"};
Zs6 YKd3 = {"\004%lld\000"};
Zs6 Y3d3 = {"\004%llx\000"};
Zs6 Y0d3 = {"\004%llu\000"};
Zs5 YY0H = {"\003%ld\000"};
Zs5 Yh1H = {"\003%lx\000"};
Zs4 Y46 = {"\002%d\000"};
Zs4 Yo7 = {"\002%x\000"};
Zs32 Y0OX = {"\036WARNING: int size is actually \000"};
Zs16 YFcv = {"\016unsigned short\000"};
Zs34 YTwi = {"\040WARNING: nat16 size is actually \000"};
Zs14 YVjT = {"\014unsigned int\000"};
Zs15 YOaN = {"\015unsigned long\000"};
Zs34 YENP = {"\040WARNING: nat32 size is actually \000"};
Zs20 Y2BO = {"\022unsigned long long\000"};
Zs5 Ye1H = {"\003%lu\000"};
Zs4 Yl7 = {"\002%u\000"};
Zs32 YfGK = {"\036WARNING: nat size is actually \000"};
Zs8 Ygep = {"\006double\000"};
Zs34 Y_4L = {"\040WARNING: float size is actually \000"};
Zs7 Yt7n = {"\005float\000"};
Zs36 YhOJ = {"\042WARNING: float32 size is actually \000"};
Zs17 YlTN = {"\017__INTPTR_TYPE__\000"};
Zs4 YFka = {"\002./\000"};
Zs17 Ys1d = {"\017zimbuConfig.out\000"};
Zs28 YLmd = {"\032Generated zimbuConfig.out:\000"};

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
Tc Y_4X[]="D:/zimbu/lib/EModule.zu";
Tc YkTo[]="D:/zimbu/lib/IOModule.zu";
Tc Ypx4[]="D:/zimbu/lib/ZModule.zu";
Tc YTBY[]="D:/zimbu/plugin/proto/Message.zu";
Tc YfKt[]="D:/zimbu/plugin/proto/Proto.zu";
Tc Y0hD[]="ZUDIR/zimbuConfig.zu";
Tc YTYp[]="zimbuConfig.zu";
Tc Ylvo[]="Config.ToString__p1/1()";
Tcpos ZcTbl79794[]={
{159,9},
{1,30},
{2,32},
{3,5},
{4,19},
};
Tc Y51G[]="Config.boolGet__p1/3()";
Tcpos ZcTbl79218[]={
{98,9},
{1,12},
};
Tc YqIG[]="Config.doubleGet__p1/2()";
Tcpos ZcTbl95580[]={
{89,9},
{1,12},
};
Tc Yv8D[]="Config.doubleGet__p1/3()";
Tcpos ZcTbl5781[]={
{92,9},
{1,12},
};
Tc YRsF[]="Config.enumGet__p1/2()";
Tcpos ZcTbl77282[]={
{45,9},
{1,12},
};
Tc YWTC[]="Config.enumGet__p1/3()";
Tcpos ZcTbl87483[]={
{48,9},
{1,12},
};
Tc YnCh[]="Config.enumNameGet__p1/2()";
Tcpos ZcTbl13235[]={
{51,9},
{1,12},
};
Tc Yibk[]="Config.enumNameGet__p1/3()";
Tcpos ZcTbl23436[]={
{54,9},
{1,12},
};
Tc YGC4[]="Config.floatGet__p1/2()";
Tcpos ZcTbl21451[]={
{82,9},
{1,12},
};
Tc YBb7[]="Config.floatGet__p1/3()";
Tcpos ZcTbl31652[]={
{85,9},
{1,12},
};
Tc YKxu[]="Config.int32Get__p1/2()";
Tcpos ZcTbl45061[]={
{63,9},
{1,12},
};
Tc YF6w[]="Config.int32Get__p1/3()";
Tcpos ZcTbl55262[]={
{66,9},
{1,12},
};
Tc YMHx[]="Config.intGet__p1/2()";
Tcpos ZcTbl30096[]={
{57,9},
{1,12},
};
Tc YHgA[]="Config.intGet__p1/3()";
Tcpos ZcTbl40297[]={
{60,9},
{1,12},
};
Tc Y2uD[]="Config.messageGet__p1/2()";
Tcpos ZcTbl95750[]={
{131,9},
{1,12},
};
Tc Y7VA[]="Config.messageGet__p1/3()";
Tcpos ZcTbl5951[]={
{134,9},
{1,12},
};
Tc YV4L[]="Config.size__p1/1()";
Tcpos ZcTbl81627[]={
{150,9},
{1,12},
};
Tc YiT7[]="Config.stringGet__p1/3()";
Tcpos ZcTbl25401[]={
{104,9},
{1,12},
};
Tc YOLm[]="Config.uint32Get__p1/2()";
Tcpos ZcTbl75882[]={
{75,9},
{1,12},
};
Tc YJkp[]="Config.uint32Get__p1/3()";
Tcpos ZcTbl86083[]={
{78,9},
{1,12},
};
Tc YQ25[]="Config.uint64Get__p1/2()";
Tcpos ZcTbl16247[]={
{69,9},
{1,12},
};
Tc YVt3[]="Config.uint64Get__p1/3()";
Tcpos ZcTbl26448[]={
{72,9},
{1,12},
};
Tc Y5LR[]="E.BadValue.NEW__p2/2()";
Tcpos ZcTbl60593[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
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
Tc Yp81[]="E.Init.NEW__p2/2()";
Tcpos ZcTbl53377[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
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
Tc YR5m[]="E.WrongType.NEW/1()";
Tcpos ZcTbl87235[]={
{514,5},
{1,16},
{2,12},
{4,20},
{4,24},
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
{2,5},
};
Tc Ys1a[]="IO";
Tcpos ZcTbl7452[]={
{26,8},
{3,8},
{6,8},
};
Tc Yxlj[]="IO.File.print__p1/15()";
Tcpos ZcTbl82618[]={
{230,11},
{1,15},
};
Tc Yj_J[]="IO.File.write/8()";
Tcpos ZcTbl94823[]={
{483,11},
{3,9},
{4,11},
{6,4},
{31,14},
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
Tc YzQB[]="IO.StringWriter.write__p1/9()";
Tcpos ZcTbl72007[]={
{129,11},
{1,15},
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
Tc YZKb[]="IO.isReadable()";
Tcpos ZcTbl71563[]={
{1697,4},
{8,14},
};
Tc YNFk[]="IO.print()";
Tcpos ZcTbl1872[]={
{1227,37},
{1,4},
{13,12},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{25,30},
{3,3},
{10,5},
{11,7},
{12,15},
{10,5},
{16,5},
{3,3},
{21,3},
{22,5},
{24,5},
{25,5},
{32,13},
{33,11},
{38,4},
{44,3},
{45,3},
{46,5},
{48,3},
{55,4},
{68,3},
{69,3},
{70,3},
{71,3},
{75,4},
{80,3},
{95,4},
{108,3},
{109,3},
{110,5},
{114,3},
{115,5},
{116,19},
{117,5},
{119,5},
{120,5},
{123,20},
{127,4},
{130,18},
{131,18},
{132,18},
{133,4},
{136,18},
{137,18},
{138,18},
{139,4},
{144,3},
{146,19},
{147,13},
{148,20},
{149,20},
{150,20},
{151,18},
{152,13},
{153,20},
{154,20},
{156,5},
{158,3},
{159,3},
{160,3},
{162,3},
{163,3},
{164,5},
{168,3},
{169,5},
{170,22},
{171,5},
{173,5},
{174,5},
{177,20},
{178,3},
{180,22},
{181,13},
{182,20},
{183,21},
{184,13},
{185,20},
{187,5},
{190,3},
{191,3},
{193,3},
{194,3},
{195,5},
{198,3},
{199,3},
{200,5},
{205,4},
{208,14},
{209,4},
{214,14},
{215,4},
{219,14},
{220,4},
{223,14},
{224,4},
{229,14},
{230,4},
{234,3},
{240,13},
{241,13},
};
Tcpos ZcTbl5271[]={
{267,4},
{6,3},
{7,3},
{9,23},
{10,31},
{11,3},
{13,3},
{14,3},
{16,10},
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
Tc YBc8[]="Zimbu.Config";
Tcpos ZcTbl74691[]={
{606,29},
};
Tc Y4yh[]="Zimbu.Config.NEW()";
Tcpos ZcTbl27632[]={
{8,5},
};
Tcode ZcodeTable[]={
{412,Y_4X,YxLq,ZcTbl412},
{1872,YkTo,YNFk,ZcTbl1872},
{5270,YTYp,Y9QD,ZcTbl5270},
{5271,YTYp,Y9QD,ZcTbl5271},
{5781,YTBY,Yv8D,ZcTbl5781},
{5951,YTBY,Y7VA,ZcTbl5951},
{6308,Y_4X,YR5_,ZcTbl6308},
{7452,YkTo,Ys1a,ZcTbl7452},
{10613,Y_4X,YCbo,ZcTbl10613},
{11217,Y_4X,YoZS,ZcTbl11217},
{12469,YfKt,YnDn,ZcTbl12469},
{13235,YTBY,YnCh,ZcTbl13235},
{13666,YfKt,YlSz,ZcTbl13666},
{14715,Y_4X,Y4SL,ZcTbl14715},
{15718,Y_4X,YEFs,ZcTbl15718},
{16247,YTBY,YQ25,ZcTbl16247},
{18187,Ypx4,Ym1t,ZcTbl18187},
{19299,YfKt,Yw9e,ZcTbl19299},
{21418,Y_4X,YtpQ,ZcTbl21418},
{21451,YTBY,YGC4,ZcTbl21451},
{23436,YTBY,Yibk,ZcTbl23436},
{24916,Y_4X,Y9iJ,ZcTbl24916},
{25401,YTBY,YiT7,ZcTbl25401},
{25958,Y_4X,Y4vu,ZcTbl25958},
{26448,YTBY,YVt3,ZcTbl26448},
{27632,Y0hD,Y4yh,ZcTbl27632},
{29585,Y_4X,YAVe,ZcTbl29585},
{30096,YTBY,YMHx,ZcTbl30096},
{30532,YfKt,Y1Hw,ZcTbl30532},
{31652,YTBY,YBb7,ZcTbl31652},
{32086,Y_4X,Y1As,ZcTbl32086},
{32956,YfKt,YlQ3,ZcTbl32956},
{35088,Y_4X,YcIS,ZcTbl35088},
{36159,Y_4X,Y_4w,ZcTbl36159},
{36491,Y_4X,YYT9,ZcTbl36491},
{36994,YfKt,YAt_,ZcTbl36994},
{37884,YfKt,YGqq,ZcTbl37884},
{40297,YTBY,YHgA,ZcTbl40297},
{42983,Y_4X,Y9aV,ZcTbl42983},
{43124,Y_4X,Ygil,ZcTbl43124},
{44130,Y_4X,YG80,ZcTbl44130},
{45061,YTBY,YKxu,ZcTbl45061},
{45289,Y_4X,Y7gV,ZcTbl45289},
{46171,Y_4X,Y9VX,ZcTbl46171},
{46312,Y_4X,YPz2,ZcTbl46312},
{46761,YkTo,YN2v,ZcTbl46761},
{48299,Y_4X,Y9Cv,ZcTbl48299},
{49183,Y_4X,YgcH,ZcTbl49183},
{49599,YfKt,Y6Nc,ZcTbl49599},
{52386,Y_4X,YgcM,ZcTbl52386},
{53325,Y_4X,YlJi,ZcTbl53325},
{53377,Y_4X,Yp81,ZcTbl53377},
{54331,Y_4X,YLzZ,ZcTbl54331},
{55262,YTBY,YF6w,ZcTbl55262},
{56372,Y_4X,Y4u_,ZcTbl56372},
{59819,YkTo,YGQL,ZcTbl59819},
{60593,Y_4X,Y5LR,ZcTbl60593},
{63483,Y_4X,Yuzo,ZcTbl63483},
{64531,YkTo,YrJP,ZcTbl64531},
{64912,YfKt,YufP,ZcTbl64912},
{70530,Y_4X,Yu0r,ZcTbl70530},
{70833,Y_4X,YWEC,ZcTbl70833},
{71563,YkTo,YZKb,ZcTbl71563},
{71988,YfKt,YleD,ZcTbl71988},
{72007,YkTo,YzQB,ZcTbl72007},
{73471,Y_4X,Y_Qs,ZcTbl73471},
{73580,Y_4X,YF6S,ZcTbl73580},
{73684,Y_4X,Yz_l,ZcTbl73684},
{74691,Y0hD,YBc8,ZcTbl74691},
{75882,YTBY,YOLm,ZcTbl75882},
{77282,YTBY,YRsF,ZcTbl77282},
{78082,Y_4X,YbzA,ZcTbl78082},
{79218,YTBY,Y51G,ZcTbl79218},
{79794,YTBY,Ylvo,ZcTbl79794},
{80644,Y_4X,YobA,ZcTbl80644},
{80731,Y_4X,Yzrp,ZcTbl80731},
{81580,YkTo,Y5X7,ZcTbl81580},
{81627,YTBY,YV4L,ZcTbl81627},
{82618,YkTo,Yxlj,ZcTbl82618},
{85000,Y_4X,Ycb9,ZcTbl85000},
{86083,YTBY,YJkp,ZcTbl86083},
{86818,Y_4X,YlgI,ZcTbl86818},
{87235,Y_4X,YR5m,ZcTbl87235},
{87483,YTBY,YWTC,ZcTbl87483},
{89685,Y_4X,Y59h,ZcTbl89685},
{89987,YkTo,YCbR,ZcTbl89987},
{90679,YfKt,YI64,ZcTbl90679},
{92163,Y_4X,YTjU,ZcTbl92163},
{94729,YfKt,Yutk,ZcTbl94729},
{94823,YkTo,Yj_J,ZcTbl94823},
{95580,YTBY,YqIG,ZcTbl95580},
{95750,YTBY,Y2uD,ZcTbl95750},
{96107,Y_4X,YMF2,ZcTbl96107},
{97019,Y_4X,YgQK,ZcTbl97019},
{99886,Y_4X,Y0Jk,ZcTbl99886},
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

void ZthrowCstringBadValue(char *msg) {
 Yaez(Zstr(msg));
}

void ZthrowDeadly(int nr) {
 YE93((Ti)nr);
}

void ZthrowInternal(Tc *text) {
 YUSH(NULL, text);
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

#ifdef __MINGW32__
void ZcorrFloatStr(char *buf) {
 size_t len = strlen(buf);
 if (len > 5 && buf[len - 3] == '0' && (buf[len - 5] == 'e' || buf[len - 5] == 'E')) {
  buf[len - 3] = buf[len - 2];
  buf[len - 2] = buf[len - 1];
  buf[len - 1] = 0;
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
 len = (int)strlen(fmtbuf);
 if (fmtbuf[len - 1] == 'F')
  fmtbuf[len - 1] = 'f';
 sprintf(buf, fmtbuf, n);
#ifdef __MINGW32__
 ZcorrFloatStr(buf);
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

Ti ZDictGetInt(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->item.ival;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return 0;
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
/* including EModule bodies */
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
Tto Ytlm__T = {390, (Tc*)&YDGe, 0, ToYtlm};
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
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YEro__T = {390, (Tc*)&YJMo, 0, ToYEro};
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
 (Tc*)0, /* MEModule__COutOfMemory.ToString - YKhn__YwtA__YH0V */
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
Tto YKhn__T = {390, (Tc*)&Y9Fv, 0, ToYKhn};
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
 (Tc*)0, /* MEModule__CNilAccess.ToString - Y1uN__YwtA__YH0V */
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
Tto Y1uN__T = {390, (Tc*)&Y4wO, 0, ToY1uN};
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
 (Tc*)0, /* MEModule__CMemoryAccess.ToString - YAxe__YwtA__YH0V */
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
Tto YAxe__T = {390, (Tc*)&Y4QW, 0, ToYAxe};
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
 (Tc*)0, /* MEModule__CInit.NEW - YVNj__YwtA__YRHRa */
 (Tc*)YVNj__YwtA__YRHR, /* MEModule__CInit.NEW - YVNj__YwtA__YRHR */
 (Tc*)0, /* MEModule__CInit.ToString - YVNj__YwtA__YH0V */
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
Tto YVNj__T = {390, (Tc*)&Ysqt, 0, ToYVNj};
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
 (Tc*)0, /* MEModule__CBadValue.ToString - Yalz__YwtA__YH0V */
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
Tto Yalz__T = {390, (Tc*)&YEZq, 0, ToYalz};
void Yaez(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yalz__YwtA__YRHR(NULL, Atext), Yalz__Ytlm_I_imt, 10);
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
 (Tc*)0, /* MEModule__CKeyNotFound.ToString - Y2EX__Yalz__YwtA__YH0V */
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
Tto Y2EX__T = {390, (Tc*)&YRiW, 0, ToY2EX};
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
 (Tc*)0, /* MEModule__CKeyExists.ToString - YX0i__Yalz__YwtA__YH0V */
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
Tto YX0i__T = {390, (Tc*)&Y9_h, 0, ToYX0i};
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
 (Tc*)0, /* MEModule__CDivideByZero.ToString - YzSI__Ylz1__YwtA__YH0V */
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
Tto YzSI__T = {390, (Tc*)&YxFl, 0, ToYzSI};
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
 (Tc*)0, /* MEModule__CIOError.ToString - YXKl__YwtA__YH0V */
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
Tto YXKl__T = {390, (Tc*)&YTj3, 0, ToYXKl};
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
 (Tc*)0, /* MEModule__CWrongType.ToString - YuDC__YwtA__YH0V */
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
Tto YuDC__T = {390, (Tc*)&YCoZ, 0, ToYuDC};
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
 (Tc*)0, /* MEModule__CInternal.ToString - YrHq__YwtA__YH0V */
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
Tto YrHq__T = {390, (Tc*)&YVki, 0, ToYrHq};
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
 sf.pos=5238617;
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
   return;
  case 12:
   Y2EX__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238609)); return;
  case 13:
   return;
  case 14:
   YX0i__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238610)); return;
  case 15:
   return;
  case 16:
   return;
  case 17:
   YzSI__Ylz1__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238611)); return;
  case 18:
   return;
  case 19:
   YXKl__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238612)); return;
  case 20:
   return;
  case 21:
   return;
  case 22:
   return;
  case 23:
   return;
  case 24:
   YuDC__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238613)); return;
  case 25:
   return;
  case 26:
   YrHq__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238614)); return;
  case 27:
   return;
  case 28:
   return;
  case 29:
   Ys_q__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238615)); return;
  case 30:
   YOEA__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238616)); return;
  case 31:
   return;
 }
 ZthrowCstringBadValue("writeTo: cannot select method to invoke");
 return;
}
/* EModule done */
/* including ZModule bodies */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) {
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 return t;
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
 {2, 0},
 {0, (Tt*)&string__T}, /* filename */
 {0, (Tt*)&string__T}, /* text */
};
Tto YkxB__T = {390, (Tc*)&YBCs, 0, ToYkxB};
/* ZModule done */
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
 (Tc*)0, /* MIOModule__CFile.writeChar - Yw8L__Ydti */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7 */
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
 (Tc*)0, /* MIOModule__CFile.readByte - YFeQ */
 (Tc*)0, /* MIOModule__CFile.readChar - YAPp */
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
 (Tc*)0, /* MIOModule__CFile.flush - YGmp */
 (Tc*)0, /* MIOModule__CFile.close - YrF8 */
 (Tc*)0, /* MIOModule__CFile.Finish - YSo_ */
 (Tc*)0, /* Init - Yw8La */
};
Tc *Yw8L__YdXi_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7 */
};
To ToYw8L[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* name */
};
Tto Yw8L__T = {390, (Tc*)&YtTU, 0, ToYw8L};
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
Tc *YjUM__YdXi_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
};
To ToYjUM[] = {
 {2, 0},
 {0, (Tt*)&array__T}, /* s */
 {0, (Tt*)&string__T}, /* x */
};
Tto YjUM__T = {390, (Tc*)&YE4c, 0, ToYjUM};
Tb Y0YB(Tc *Aname) {
 Ti Vv;
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vv = 0;
 sf.pos=7156300;
 Vv = access(ZgetCstring(Aname), R_OK);
 sf.pos=7156301;
 r = (Vv == 0);
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
/* including zimbuConfig bodies */
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
 (Tc*)0, /* MProto__CE_ProduceError.ToString - Ys_q__YwtA__YH0V */
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
Tto Ys_q__T = {390, (Tc*)&Y4sk, 0, ToYs_q};
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
 (Tc*)0, /* MProto__CE_BinaryError.ToString - YOEA__YwtA__YH0V */
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
Tto YOEA__T = {390, (Tc*)&YtJ_, 0, ToYOEA};
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
 {1, 0},
 {0, (Tt*)&string__T}, /* name */
};
Tto YqvM__T = {390, (Tc*)&Y5d5, 0, ToYqvM};
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
 {2, 0},
 {0, (Tt*)&iobj__T}, /* writer */
 {0, (Tt*)&string__T}, /* indent */
};
Tto YLWE__T = {390, (Tc*)&YaKG, 0, ToYLWE};
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
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(ZfloatFormat(((Tc*)&YmwI), Vf), ((Tc*)&Yk)));
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
YNdL *YA_Z(YNdL *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=2763200; t = Za(sizeof(YNdL));}
 topFrame = sf.prev;
 return t;
}
Tc *Ykvoa(YNdL *t) {
 Tc *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((Tc*)&YF2d);
 return r;
}
YNdL *YrF2(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_mallocArg = Av;
 r = t;
 return r;
}
Tb Y8zW(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_mallocArg != NULL);
 return r;
}
YNdL *YOPG(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_threadArg = Av;
 r = t;
 return r;
}
Tb YvKz(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_threadArg != NULL);
 return r;
}
YNdL *YWoP(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_socketArg = Av;
 r = t;
 return r;
}
Tb YDjI(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_socketArg != NULL);
 return r;
}
YNdL *Yjrt(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_mathArg = Av;
 r = t;
 return r;
}
Tb Y8om(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_mathArg != NULL);
 return r;
}
YNdL *Yqt5(YNdL *t, Tb Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_haveResolve = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb Y3Lr(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_haveResolve != 0);
 return r;
}
YNdL *YBhB(YNdL *t, Tb Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_haveFork = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YcPw(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_haveFork != 0);
 return r;
}
YNdL *YNXX(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_exeSuffix = Av;
 r = t;
 return r;
}
Tb YuSQ(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_exeSuffix != NULL);
 return r;
}
YNdL *YcU3(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_exePrefix = Av;
 r = t;
 return r;
}
Tb YUOX(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_exePrefix != NULL);
 return r;
}
YNdL *Y118(YNdL *t, Tb Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_haveSigaction = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YJrk(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_haveSigaction != 0);
 return r;
}
YNdL *YEDn(YNdL *t, Tb Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_gcWithThreads = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb Yo45(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_gcWithThreads != 0);
 return r;
}
YNdL *YIIX(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_int16Name = Av;
 r = t;
 return r;
}
Tb YpDQ(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_int16Name != NULL);
 return r;
}
YNdL *Y8TB(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_int32Name = Av;
 r = t;
 return r;
}
Tb YQOu(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_int32Name != NULL);
 return r;
}
YNdL *Y6PM(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_int64Name = Av;
 r = t;
 return r;
}
Tb YOKF(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_int64Name != NULL);
 return r;
}
YNdL *YXzR(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_nat16Name = Av;
 r = t;
 return r;
}
Tb YEuK(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_nat16Name != NULL);
 return r;
}
YNdL *YnLv(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_nat32Name = Av;
 r = t;
 return r;
}
Tb Y4Fo(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_nat32Name != NULL);
 return r;
}
YNdL *YlHG(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_nat64Name = Av;
 r = t;
 return r;
}
Tb Y2Bz(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_nat64Name != NULL);
 return r;
}
YNdL *Yla2(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_floatName = Av;
 r = t;
 return r;
}
Tb Y24V(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_floatName != NULL);
 return r;
}
YNdL *YI4N(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_float32Name = Av;
 r = t;
 return r;
}
Tb YftC(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_float32Name != NULL);
 return r;
}
YNdL *YJ6V(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_intPtrName = Av;
 r = t;
 return r;
}
Tb YTxb(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_intPtrName != NULL);
 return r;
}
YNdL *YUld(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_printIntFormat = Av;
 r = t;
 return r;
}
Tb YlFq(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_printIntFormat != NULL);
 return r;
}
YNdL *Y8c7(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_printNatFormat = Av;
 r = t;
 return r;
}
Tb Y6Nw(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_printNatFormat != NULL);
 return r;
}
YNdL *YRMv(YNdL *t, Tc *Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_scanfHexFormat = Av;
 r = t;
 return r;
}
Tb Yoe8(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_scanfHexFormat != NULL);
 return r;
}
YNdL *YeB5(YNdL *t, Tb Av) {
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_isMingw = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YdfK(YNdL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_isMingw != 0);
 return r;
}
Tb YFKUa(YNdL *t, Ti AfieldNr) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 4:
  {
   r = (t->Vf_haveResolve == 2);
   rt = 1;
   goto YMz1;
  }
 case 5:
  {
   r = (t->Vf_haveFork == 2);
   rt = 1;
   goto YMz1;
  }
 case 8:
  {
   r = (t->Vf_haveSigaction == 2);
   rt = 1;
   goto YMz1;
  }
 case 9:
  {
   r = (t->Vf_gcWithThreads == 2);
   rt = 1;
   goto YMz1;
  }
 case 50:
  {
   r = (t->Vf_isMingw == 2);
   rt = 1;
   goto YMz1;
  }
YMz1:
  if (rt) goto YNSH;
 }
 r = 0;
YNSH:
 return r;
}
Tc *Yxv3a(YNdL *t, Ti AfieldNr) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   r = t->Vf_mallocArg;
   rt = 1;
   goto YbWO;
  }
 case 2:
  {
   r = t->Vf_threadArg;
   rt = 1;
   goto YbWO;
  }
 case 3:
  {
   r = t->Vf_socketArg;
   rt = 1;
   goto YbWO;
  }
 case 10:
  {
   r = t->Vf_mathArg;
   rt = 1;
   goto YbWO;
  }
 case 6:
  {
   r = t->Vf_exeSuffix;
   rt = 1;
   goto YbWO;
  }
 case 7:
  {
   r = t->Vf_exePrefix;
   rt = 1;
   goto YbWO;
  }
 case 20:
  {
   r = t->Vf_int16Name;
   rt = 1;
   goto YbWO;
  }
 case 21:
  {
   r = t->Vf_int32Name;
   rt = 1;
   goto YbWO;
  }
 case 22:
  {
   r = t->Vf_int64Name;
   rt = 1;
   goto YbWO;
  }
 case 23:
  {
   r = t->Vf_nat16Name;
   rt = 1;
   goto YbWO;
  }
 case 24:
  {
   r = t->Vf_nat32Name;
   rt = 1;
   goto YbWO;
  }
 case 25:
  {
   r = t->Vf_nat64Name;
   rt = 1;
   goto YbWO;
  }
 case 26:
  {
   r = t->Vf_floatName;
   rt = 1;
   goto YbWO;
  }
 case 27:
  {
   r = t->Vf_float32Name;
   rt = 1;
   goto YbWO;
  }
 case 28:
  {
   r = t->Vf_intPtrName;
   rt = 1;
   goto YbWO;
  }
 case 40:
  {
   r = t->Vf_printIntFormat;
   rt = 1;
   goto YbWO;
  }
 case 41:
  {
   r = t->Vf_printNatFormat;
   rt = 1;
   goto YbWO;
  }
 case 42:
  {
   r = t->Vf_scanfHexFormat;
   rt = 1;
   goto YbWO;
  }
YbWO:
  if (rt) goto YB5N;
 }
 r = ((Tc*)&Ya);
YB5N:
 return r;
}
Tb YlZca(YNdL *t, Ti AfieldNr) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   r = Y8zW(t);
   rt = 1;
   goto YzmR;
  }
 case 2:
  {
   r = YvKz(t);
   rt = 1;
   goto YzmR;
  }
 case 3:
  {
   r = YDjI(t);
   rt = 1;
   goto YzmR;
  }
 case 10:
  {
   r = Y8om(t);
   rt = 1;
   goto YzmR;
  }
 case 4:
  {
   r = Y3Lr(t);
   rt = 1;
   goto YzmR;
  }
 case 5:
  {
   r = YcPw(t);
   rt = 1;
   goto YzmR;
  }
 case 6:
  {
   r = YuSQ(t);
   rt = 1;
   goto YzmR;
  }
 case 7:
  {
   r = YUOX(t);
   rt = 1;
   goto YzmR;
  }
 case 8:
  {
   r = YJrk(t);
   rt = 1;
   goto YzmR;
  }
 case 9:
  {
   r = Yo45(t);
   rt = 1;
   goto YzmR;
  }
 case 20:
  {
   r = YpDQ(t);
   rt = 1;
   goto YzmR;
  }
 case 21:
  {
   r = YQOu(t);
   rt = 1;
   goto YzmR;
  }
 case 22:
  {
   r = YOKF(t);
   rt = 1;
   goto YzmR;
  }
 case 23:
  {
   r = YEuK(t);
   rt = 1;
   goto YzmR;
  }
 case 24:
  {
   r = Y4Fo(t);
   rt = 1;
   goto YzmR;
  }
 case 25:
  {
   r = Y2Bz(t);
   rt = 1;
   goto YzmR;
  }
 case 26:
  {
   r = Y24V(t);
   rt = 1;
   goto YzmR;
  }
 case 27:
  {
   r = YftC(t);
   rt = 1;
   goto YzmR;
  }
 case 28:
  {
   r = YTxb(t);
   rt = 1;
   goto YzmR;
  }
 case 40:
  {
   r = YlFq(t);
   rt = 1;
   goto YzmR;
  }
 case 41:
  {
   r = Y6Nw(t);
   rt = 1;
   goto YzmR;
  }
 case 42:
  {
   r = Yoe8(t);
   rt = 1;
   goto YzmR;
  }
 case 50:
  {
   r = YdfK(t);
   rt = 1;
   goto YzmR;
  }
YzmR:
  if (rt) goto YXeK;
 }
 r = 0;
YXeK:
 return r;
}
Tl *Yozoa(YNdL *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = YR6X;
 return r;
}
Ti YNdL__Y0zD(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7728200;
  ZthrowThisNil();
 }
 sf.pos=7728201;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Ti YNdL__Y0zDa(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8748300;
  ZthrowThisNil();
 }
 sf.pos=8748301;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tc *YNdL__YytN(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1323500;
  ZthrowThisNil();
 }
 sf.pos=1323501;
 r = ((Tc*)&Ya);
 topFrame = sf.prev;
 return r;
}
Tc *YNdL__YytNa(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2343600;
  ZthrowThisNil();
 }
 sf.pos=2343601;
 r = ((Tc*)&Ya);
 topFrame = sf.prev;
 return r;
}
Ti YNdL__YGR8(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3009600;
  ZthrowThisNil();
 }
 sf.pos=3009601;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Ti YNdL__YGR8a(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4029700;
  ZthrowThisNil();
 }
 sf.pos=4029701;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Ti32 YNdL__YAAo(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Ti32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4506100;
  ZthrowThisNil();
 }
 sf.pos=4506101;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Ti32 YNdL__YAAoa(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Ti32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5526200;
  ZthrowThisNil();
 }
 sf.pos=5526201;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tu YNdL__YRqV(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Tu r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1624700;
  ZthrowThisNil();
 }
 sf.pos=1624701;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tu YNdL__YRqVa(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tu r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2644800;
  ZthrowThisNil();
 }
 sf.pos=2644801;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tu32 YNdL__Y0tE(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Tu32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7588200;
  ZthrowThisNil();
 }
 sf.pos=7588201;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tu32 YNdL__Y0tEa(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tu32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8608300;
  ZthrowThisNil();
 }
 sf.pos=8608301;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tf32 YNdL__Yyt7(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Tf32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2145100;
  ZthrowThisNil();
 }
 sf.pos=2145101;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tf32 YNdL__Yyt7a(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tf32 r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3165200;
  ZthrowThisNil();
 }
 sf.pos=3165201;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tf YNdL__Yybv(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Tf r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9558000;
  ZthrowThisNil();
 }
 sf.pos=9558001;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tf YNdL__Yybva(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tf r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=578100;
  ZthrowThisNil();
 }
 sf.pos=578101;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tb YNdL__YGfza(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7921800;
  ZthrowThisNil();
 }
 sf.pos=7921801;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tc *YNdL__YsRaa(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2540100;
  ZthrowThisNil();
 }
 sf.pos=2540101;
 r = ((Tc*)&Ya);
 topFrame = sf.prev;
 return r;
}
Tr YNdL__Yo5y(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Tr r = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9575000;
  ZthrowThisNil();
 }
 sf.pos=9575001;
 r = trZero;
 topFrame = sf.prev;
 return r;
}
Tr YNdL__Yo5ya(YNdL *t, Ti AfieldNr, Ti Aidx) {
 Zsf sf;
 Tr r = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=595100;
  ZthrowThisNil();
 }
 sf.pos=595101;
 r = trZero;
 topFrame = sf.prev;
 return r;
}
Ti YNdL__YUDN(YNdL *t, Ti AfieldNr) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8162700;
  ZthrowThisNil();
 }
 sf.pos=8162701;
 r = 0;
 topFrame = sf.prev;
 return r;
}
Tc *YNdL__YC5i(YNdL *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vwriter = 0;
 YLWE *VprotoWriter = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7979400;
  ZthrowThisNil();
 }
 sf.pos=7979401;
 Vwriter = Za(sizeof(YjUM));
 sf.pos=7979402;
 VprotoWriter = YrCUb(NULL, *Znao(&t0, Vwriter, YjUM__YdXi_imt, 2), ((Tc*)&Ya), 0);
 sf.pos=7979403;
 YP8Z(*Znao(&t0, t, YNdL__YFL0_I_imt, 0), VprotoWriter);
 sf.pos=7979404;
 r = YbNW(Vwriter);
 topFrame = sf.prev;
 return r;
}
Tc *YNdL__YFL0_I_imt[] = {
 (Tc*)&YNdL__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YlZca, /* MZimbu__CConfig.hasField - YlZca */
 (Tc*)Ykvoa, /* MZimbu__CConfig.name - Ykvoa */
 (Tc*)YNdL__Y0zDa, /* MZimbu__CConfig.enumGet - YNdL__Y0zDa */
 (Tc*)YNdL__Y0zD, /* MZimbu__CConfig.enumGet - YNdL__Y0zD */
 (Tc*)YNdL__YytNa, /* MZimbu__CConfig.enumNameGet - YNdL__YytNa */
 (Tc*)YNdL__YytN, /* MZimbu__CConfig.enumNameGet - YNdL__YytN */
 (Tc*)YNdL__YGR8a, /* MZimbu__CConfig.intGet - YNdL__YGR8a */
 (Tc*)YNdL__YGR8, /* MZimbu__CConfig.intGet - YNdL__YGR8 */
 (Tc*)YNdL__YAAoa, /* MZimbu__CConfig.int32Get - YNdL__YAAoa */
 (Tc*)YNdL__YAAo, /* MZimbu__CConfig.int32Get - YNdL__YAAo */
 (Tc*)YNdL__YRqVa, /* MZimbu__CConfig.uint64Get - YNdL__YRqVa */
 (Tc*)YNdL__YRqV, /* MZimbu__CConfig.uint64Get - YNdL__YRqV */
 (Tc*)YNdL__Y0tEa, /* MZimbu__CConfig.uint32Get - YNdL__Y0tEa */
 (Tc*)YNdL__Y0tE, /* MZimbu__CConfig.uint32Get - YNdL__Y0tE */
 (Tc*)YNdL__Yyt7a, /* MZimbu__CConfig.floatGet - YNdL__Yyt7a */
 (Tc*)YNdL__Yyt7, /* MZimbu__CConfig.floatGet - YNdL__Yyt7 */
 (Tc*)YNdL__Yybva, /* MZimbu__CConfig.doubleGet - YNdL__Yybva */
 (Tc*)YNdL__Yybv, /* MZimbu__CConfig.doubleGet - YNdL__Yybv */
 (Tc*)YNdL__YGfza, /* MZimbu__CConfig.boolGet - YNdL__YGfza */
 (Tc*)YFKUa, /* MZimbu__CConfig.boolGet - YFKUa */
 (Tc*)YNdL__YsRaa, /* MZimbu__CConfig.stringGet - YNdL__YsRaa */
 (Tc*)Yxv3a, /* MZimbu__CConfig.stringGet - Yxv3a */
 (Tc*)0, /* MZimbu__CConfig.enumSet - YNdL__Y3p7 */
 (Tc*)0, /* MZimbu__CConfig.enumNameSet - YNdL__YBjh */
 (Tc*)0, /* MZimbu__CConfig.intSet - YNdL__YJHD */
 (Tc*)0, /* MZimbu__CConfig.int32Set - YNdL__YDqT */
 (Tc*)0, /* MZimbu__CConfig.uint64Set - YNdL__YOAq */
 (Tc*)0, /* MZimbu__CConfig.uint32Set - YNdL__YYD9 */
 (Tc*)0, /* MZimbu__CConfig.floatSet - YNdL__YBjC */
 (Tc*)0, /* MZimbu__CConfig.doubleSet - YNdL__Yvl0 */
 (Tc*)0, /* MZimbu__CConfig.boolSet - YCUpa */
 (Tc*)0, /* MZimbu__CConfig.stringSet - YuFza */
 (Tc*)YNdL__Yo5ya, /* MZimbu__CConfig.messageGet - YNdL__Yo5ya */
 (Tc*)YNdL__Yo5y, /* MZimbu__CConfig.messageGet - YNdL__Yo5y */
 (Tc*)0, /* MZimbu__CConfig.messageSet - YNdL__YrW2 */
 (Tc*)0, /* MZimbu__CConfig.messageAdd - YNdL__Y0Dj */
 (Tc*)0, /* MZimbu__CConfig.mergeMessageFromReader - YNdL__Ymza */
 (Tc*)YNdL__YUDN, /* MZimbu__CConfig.size - YNdL__YUDN */
 (Tc*)Yozoa, /* MZimbu__CConfig.fieldSpecs - Yozoa */
 (Tc*)YNdL__YC5i, /* MZimbu__CConfig.ToString - YNdL__YC5i */
 (Tc*)0, /* MZimbu__CConfig.toString - YNdL__YVAI */
 (Tc*)0, /* MZimbu__CConfig.writeText - YNdL__Yr3ca */
 (Tc*)0, /* MZimbu__CConfig.writeText - YNdL__Yr3c */
 (Tc*)0, /* MZimbu__CConfig.Equal - YNdL__YYdF */
 (Tc*)0, /* MZimbu__CConfig.writeBinary - YNdL__YpSR */
 (Tc*)0, /* MZimbu__CConfig.writeBinaryDeref - YNdL__Yz9e */
 (Tc*)0, /* MZimbu__CConfig.writeJson - YNdL__YVaR */
 (Tc*)0, /* MZimbu__CConfig.writeJsonDeref - YNdL__YgZk */
 (Tc*)0, /* Init - YNdLa */
};
To ToYNdL[] = {
 {18, 0},
 {0, (Tt*)&string__T}, /* f_mallocArg */
 {0, (Tt*)&string__T}, /* f_threadArg */
 {0, (Tt*)&string__T}, /* f_socketArg */
 {0, (Tt*)&string__T}, /* f_mathArg */
 {0, (Tt*)&string__T}, /* f_exeSuffix */
 {0, (Tt*)&string__T}, /* f_exePrefix */
 {0, (Tt*)&string__T}, /* f_int16Name */
 {0, (Tt*)&string__T}, /* f_int32Name */
 {0, (Tt*)&string__T}, /* f_int64Name */
 {0, (Tt*)&string__T}, /* f_nat16Name */
 {0, (Tt*)&string__T}, /* f_nat32Name */
 {0, (Tt*)&string__T}, /* f_nat64Name */
 {0, (Tt*)&string__T}, /* f_floatName */
 {0, (Tt*)&string__T}, /* f_float32Name */
 {0, (Tt*)&string__T}, /* f_intPtrName */
 {0, (Tt*)&string__T}, /* f_printIntFormat */
 {0, (Tt*)&string__T}, /* f_printNatFormat */
 {0, (Tt*)&string__T}, /* f_scanfHexFormat */
};
Tto YNdL__T = {390, (Tc*)&YF2d, 0, ToYNdL};
int JzimbuConfig(int round) {
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
   sf.pos=7469100;
   YR6X = ZnewList((Tt*)&YqvM__T, 23); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y1i0), 1, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YF8m), 2, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yxze), 3, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YdV8), 10, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yefj), 4, 1, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YqSF), 5, 1, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YG05), 6, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yg4Z), 7, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YUN3), 8, 1, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yeai), 9, 1, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YLf6), 20, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yk4r), 21, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Ym8g), 22, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Ywoc), 23, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y5cy), 24, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y7gn), 25, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y7N0), 26, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y4ZK), 27, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YlnY), 28, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YMLF), 40, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YxUL), 41, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YPkn), 42, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y83L), 50, 1, 0));
  }
  topFrame = sf.prev;
 }
 return done;
}
/* zimbuConfig done */
/*
 * INIT IMT
 */
void ZimtInit(void) {
 {
  Ytlm *p = 0;
  ToYtlm[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtlm[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtlm[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YEro *p = 0;
  ToYEro[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYEro[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYEro[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  ToYkxB[2].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Yw8L *p = 0;
  Yw8L__Yw8L_I_imt[20] = (Tc*)((Tc*)&p->Vfd - (Tc*)p);
  Yw8L__Yw8L_I_imt[21] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYw8L[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
 }
 {
  YjUM *p = 0;
  ToYjUM[1].off = (int)((Tc*)&p->Vs - (Tc*)p);
  ToYjUM[2].off = (int)((Tc*)&p->Vx - (Tc*)p);
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
 }
 {
  YLWE *p = 0;
  ToYLWE[1].off = (int)((Tc*)&p->Vwriter - (Tc*)p);
  ToYLWE[2].off = (int)((Tc*)&p->Vindent - (Tc*)p);
 }
 {
  YNdL *p = 0;
  YNdL__YFL0_I_imt[1] = (Tc*)((Tc*)&p->VderefTime - (Tc*)p);
  YNdL__YFL0_I_imt[2] = (Tc*)((Tc*)&p->VderefId - (Tc*)p);
  YNdL__YFL0_I_imt[3] = (Tc*)((Tc*)&p->VderefTimeSize - (Tc*)p);
  YNdL__YFL0_I_imt[4] = (Tc*)((Tc*)&p->VderefIdSize - (Tc*)p);
  ToYNdL[1].off = (int)((Tc*)&p->Vf_mallocArg - (Tc*)p);
  ToYNdL[2].off = (int)((Tc*)&p->Vf_threadArg - (Tc*)p);
  ToYNdL[3].off = (int)((Tc*)&p->Vf_socketArg - (Tc*)p);
  ToYNdL[4].off = (int)((Tc*)&p->Vf_mathArg - (Tc*)p);
  ToYNdL[5].off = (int)((Tc*)&p->Vf_exeSuffix - (Tc*)p);
  ToYNdL[6].off = (int)((Tc*)&p->Vf_exePrefix - (Tc*)p);
  ToYNdL[7].off = (int)((Tc*)&p->Vf_int16Name - (Tc*)p);
  ToYNdL[8].off = (int)((Tc*)&p->Vf_int32Name - (Tc*)p);
  ToYNdL[9].off = (int)((Tc*)&p->Vf_int64Name - (Tc*)p);
  ToYNdL[10].off = (int)((Tc*)&p->Vf_nat16Name - (Tc*)p);
  ToYNdL[11].off = (int)((Tc*)&p->Vf_nat32Name - (Tc*)p);
  ToYNdL[12].off = (int)((Tc*)&p->Vf_nat64Name - (Tc*)p);
  ToYNdL[13].off = (int)((Tc*)&p->Vf_floatName - (Tc*)p);
  ToYNdL[14].off = (int)((Tc*)&p->Vf_float32Name - (Tc*)p);
  ToYNdL[15].off = (int)((Tc*)&p->Vf_intPtrName - (Tc*)p);
  ToYNdL[16].off = (int)((Tc*)&p->Vf_printIntFormat - (Tc*)p);
  ToYNdL[17].off = (int)((Tc*)&p->Vf_printNatFormat - (Tc*)p);
  ToYNdL[18].off = (int)((Tc*)&p->Vf_scanfHexFormat - (Tc*)p);
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
 done &= JzimbuConfig(round);
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
 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 1002) ZthrowCstringInit("Early initialization not done within 1000 rounds");
 }

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
 Tb VhaveResolve;
 Tb VhaveFork;
 Tb VhaveSigaction;
 Tb VgcWithThreads;
 Tb VisMingw;
 Ti VshortSize;
 Ti VintSize;
 Ti VlongSize;
 Ti VlongLongSize;
 Ti VunsShortSize;
 Ti VunsIntSize;
 Ti VunsLongSize;
 Ti VunsLongLongSize;
 Ti VptrSize;
 Ti VfloatSize;
 Ti VdoubleSize;
 Ti VvoidPtrSize;
 Zsf sf;
 Ti r = 0;
 YNdL *VzimbuConfig = 0;
 Tc *Vfound = NULL;
 Tl *Zf1 = NULL;
 Tc *Vdir = NULL;
 Tl *Zf2 = NULL;
 Tc *Vs = NULL;
 Tc *VthreadArg = NULL;
 Tc *VsocketArg = NULL;
 Tc *VmathArg = NULL;
 Tc *VintType = NULL;
 Tc *VprintIntFormat = NULL;
 Tc *VscanfHexFormat = NULL;
 Tc *VprintNatFormat = NULL;
 Tc *VnatType = NULL;
 Tc *VintPtrName = NULL;
 Tc *VexeSuffix = NULL;
 Tc *VexePrefix = NULL;
 Tr Vwriter = {NULL};
 Tc *Vconfig = NULL;
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 r = 0;
 sf.pos=527000;
 VzimbuConfig = YA_Z(NULL);
 sf.pos=527001;
 {
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&string__T, 7), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Yj_i)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YftF)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YK0f)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIMX)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YDCH)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYHU)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YGiO)));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdir;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=527002;
  {
   Tfl Zf2i;
   Zf2 = (t0 = ZnewList((Tt*)&string__T, 2), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Y912)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Y56Y)));
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vs;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=527003;
   if (Y0YB(ZcS5(Vdir, ((Tc*)&YK0f), Vs, ((Tc*)&YEk4), (Tc*)1)))
   {
    sf.pos=527004;
    Vfound = Vs;
    rt = 2;
    goto YCc4;
   }
YCc4:
   if (rt == 2) { rt &= 1; break; }
   sf.pos=527005;
   }
  }
  sf.pos=527006;
  if ((Vfound != NULL))
  {
   rt = 2;
   goto YPyu;
  }
YPyu:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=527007;
  }
 }
 sf.pos=527008;
 if ((Vfound != NULL))
 {
  sf.pos=527009;
  YrF2(VzimbuConfig, ZcS(((Tc*)&Y1ja), Vfound));
 }
 else
 {
  sf.pos=527010;
  Yl0k(((Tc*)&YbiD));
  sf.pos=527011;
  Yl0k(((Tc*)&Y51Q));
 }
 sf.pos=527012;
 VthreadArg = ((Tc*)&YglX);
 sf.pos=527013;
 VmathArg = ((Tc*)&YtA1);
 sf.pos=527014;
#if defined(__MINGW32__)
  VthreadArg = Zstr("-lpthreadGC2");
  VsocketArg = Zstr("-lws2_32");
#endif
 sf.pos=527015;
 YOPG(VzimbuConfig, VthreadArg);
 sf.pos=527016;
 if ((VsocketArg != NULL))
 {
  sf.pos=527017;
  YWoP(VzimbuConfig, VsocketArg);
 }
 sf.pos=527018;
 Yjrt(VzimbuConfig, VmathArg);
 VhaveResolve = 0;
 VhaveFork = 0;
 VhaveSigaction = 0;
 VgcWithThreads = 0;
 sf.pos=527019;
#ifdef __MINGW32__
  VhaveResolve = 0;
  VhaveFork = 0;
  VhaveSigaction = 0;
  VgcWithThreads = 0;
#else
  VhaveResolve = 1;
  VhaveFork = 1;
  VhaveSigaction = 1;
  VgcWithThreads = 1;
#endif
 sf.pos=527020;
 Yqt5(VzimbuConfig, VhaveResolve);
 sf.pos=527021;
 YBhB(VzimbuConfig, VhaveFork);
 sf.pos=527022;
 Y118(VzimbuConfig, VhaveSigaction);
 sf.pos=527023;
 YEDn(VzimbuConfig, VgcWithThreads);
 VisMingw = 0;
 sf.pos=527024;
#ifdef __MINGW32__
  VisMingw = 1;
#endif
 sf.pos=527025;
 YeB5(VzimbuConfig, VisMingw);
 VshortSize = 0;
 VintSize = 0;
 VlongSize = 0;
 VlongLongSize = 0;
 VunsShortSize = 0;
 VunsIntSize = 0;
 VunsLongSize = 0;
 VunsLongLongSize = 0;
 VptrSize = 0;
 VfloatSize = 0;
 VdoubleSize = 0;
 VvoidPtrSize = 0;
 sf.pos=527026;
  VshortSize = sizeof(short);
  VintSize = sizeof(int);
  VlongSize = sizeof(long);
  VlongLongSize = sizeof(long long);
  VunsShortSize = sizeof(unsigned short);
  VunsIntSize = sizeof(unsigned int);
  VunsLongSize = sizeof(unsigned long);
  VunsLongLongSize = sizeof(unsigned long long);
  VfloatSize = sizeof(float);
  VdoubleSize = sizeof(double);
  VvoidPtrSize = sizeof(void*);
 sf.pos=527027;
 YIIX(VzimbuConfig, ((Tc*)&YX_1));
 sf.pos=527028;
 if ((VshortSize != 2))
 {
  sf.pos=527029;
  Yl0k(ZcS3(((Tc*)&Y8PB), (Zint2string((VshortSize * 8))), ((Tc*)&YMSv)));
 }
 sf.pos=527030;
 if ((VintSize == 4))
 {
  sf.pos=527031;
  Y8TB(VzimbuConfig, ((Tc*)&Y1Qt));
 }
 else {
 sf.pos=527032;
 if ((VlongSize == 4))
 {
  sf.pos=527033;
  Y8TB(VzimbuConfig, ((Tc*)&YDFJ));
 }
 else
 {
  sf.pos=527034;
  Y8TB(VzimbuConfig, ((Tc*)&Y1Qt));
  sf.pos=527035;
  Yl0k(ZcS3(((Tc*)&Ynz4), (Zint2string((VintSize * 8))), ((Tc*)&YMSv)));
 }
 }
 sf.pos=527036;
 VintType = ((Tc*)&YDR5);
 sf.pos=527037;
#ifdef __MINGW32__
 sf.pos=527038;
 VprintIntFormat = ((Tc*)&YmXc);
 sf.pos=527039;
 VscanfHexFormat = ((Tc*)&YGXc);
 sf.pos=527040;
 VprintNatFormat = ((Tc*)&YDXc);
 sf.pos=527041;
#else
 sf.pos=527042;
 VprintIntFormat = ((Tc*)&YKd3);
 sf.pos=527043;
 VscanfHexFormat = ((Tc*)&Y3d3);
 sf.pos=527044;
 VprintNatFormat = ((Tc*)&Y0d3);
 sf.pos=527045;
#endif
 sf.pos=527046;
 if ((VlongLongSize == 8))
 {
 }
 else {
 sf.pos=527047;
 if ((VlongSize == 8))
 {
  sf.pos=527048;
  VintType = ((Tc*)&YDFJ);
  sf.pos=527049;
  VprintIntFormat = ((Tc*)&YY0H);
  sf.pos=527050;
  VscanfHexFormat = ((Tc*)&Yh1H);
  sf.pos=527051;
  VprintIntFormat = ((Tc*)&YY0H);
 }
 else {
 sf.pos=527052;
 if ((VintSize == 8))
 {
  sf.pos=527053;
  VintType = ((Tc*)&Y1Qt);
  sf.pos=527054;
  VprintIntFormat = ((Tc*)&Y46);
  sf.pos=527055;
  VscanfHexFormat = ((Tc*)&Yo7);
 }
 else
 {
  sf.pos=527056;
  Yl0k(ZcS3(((Tc*)&Y0OX), (Zint2string((VlongLongSize * 8))), ((Tc*)&YMSv)));
 }
 }}
 sf.pos=527057;
 Y6PM(VzimbuConfig, VintType);
 sf.pos=527058;
 YUld(VzimbuConfig, VprintIntFormat);
 sf.pos=527059;
 YRMv(VzimbuConfig, VscanfHexFormat);
 sf.pos=527060;
 YXzR(VzimbuConfig, ((Tc*)&YFcv));
 sf.pos=527061;
 if ((VunsShortSize != 2))
 {
  sf.pos=527062;
  Yl0k(ZcS3(((Tc*)&YTwi), (Zint2string((VunsShortSize * 8))), ((Tc*)&YMSv)));
 }
 sf.pos=527063;
 if ((VunsIntSize == 4))
 {
  sf.pos=527064;
  YnLv(VzimbuConfig, ((Tc*)&YVjT));
 }
 else {
 sf.pos=527065;
 if ((VunsLongSize == 4))
 {
  sf.pos=527066;
  YnLv(VzimbuConfig, ((Tc*)&YOaN));
 }
 else
 {
  sf.pos=527067;
  YnLv(VzimbuConfig, ((Tc*)&YVjT));
  sf.pos=527068;
  Yl0k(ZcS3(((Tc*)&YENP), (Zint2string((VunsIntSize * 8))), ((Tc*)&YMSv)));
 }
 }
 sf.pos=527069;
 VnatType = ((Tc*)&Y2BO);
 sf.pos=527070;
 if ((VunsLongLongSize == 8))
 {
 }
 else {
 sf.pos=527071;
 if ((VunsLongSize == 8))
 {
  sf.pos=527072;
  VnatType = ((Tc*)&YOaN);
  sf.pos=527073;
  VprintNatFormat = ((Tc*)&Ye1H);
 }
 else {
 sf.pos=527074;
 if ((VunsIntSize == 8))
 {
  sf.pos=527075;
  VnatType = ((Tc*)&YVjT);
  sf.pos=527076;
  VprintNatFormat = ((Tc*)&Yl7);
 }
 else
 {
  sf.pos=527077;
  Yl0k(ZcS3(((Tc*)&YfGK), (Zint2string((VunsLongLongSize * 8))), ((Tc*)&YMSv)));
 }
 }}
 sf.pos=527078;
 YlHG(VzimbuConfig, VnatType);
 sf.pos=527079;
 Y8c7(VzimbuConfig, VprintNatFormat);
 sf.pos=527080;
 Yla2(VzimbuConfig, ((Tc*)&Ygep));
 sf.pos=527081;
 if ((VdoubleSize != 8))
 {
  sf.pos=527082;
  Yl0k(ZcS3(((Tc*)&Y_4L), (Zint2string((VdoubleSize * 8))), ((Tc*)&YMSv)));
 }
 sf.pos=527083;
 YI4N(VzimbuConfig, ((Tc*)&Yt7n));
 sf.pos=527084;
 if ((VfloatSize != 4))
 {
  sf.pos=527085;
  Yl0k(ZcS3(((Tc*)&YhOJ), (Zint2string((VfloatSize * 8))), ((Tc*)&YMSv)));
 }
 sf.pos=527086;
#ifdef __INTPTR_TYPE__
 sf.pos=527087;
 VintPtrName = ((Tc*)&YlTN);
 sf.pos=527088;
#else
# ifdef __SIZEOF_POINTER__
#  if __SIZEOF_POINTER__ == __SIZEOF_INT__
 sf.pos=527089;
 VintPtrName = ((Tc*)&Y1Qt);
 sf.pos=527090;
#  else
#   if __SIZEOF_POINTER__ == __SIZEOF_LONG__
 sf.pos=527091;
 VintPtrName = ((Tc*)&YDFJ);
 sf.pos=527092;
#   else
 sf.pos=527093;
 VintPtrName = ((Tc*)&YDR5);
 sf.pos=527094;
#   endif
#  endif
# else
 sf.pos=527095;
 VintPtrName = ((Tc*)&YDFJ);
 sf.pos=527096;
# endif
#endif
 sf.pos=527097;
 YJ6V(VzimbuConfig, VintPtrName);
 sf.pos=527098;
 VexeSuffix = ((Tc*)&Ya);
 sf.pos=527099;
 VexePrefix = ((Tc*)&YFka);
 sf.pos=527100;
#if defined(__MINGW32__) || defined(_MSC_VER)
  VexeSuffix = Zstr(".exe");  /* set to ".exe" for MS-Windows */
  VexePrefix = Zstr("");      /* set to "" for MS-Windows */
#endif
 sf.pos=527101;
 YNXX(VzimbuConfig, VexeSuffix);
 sf.pos=527102;
 YcU3(VzimbuConfig, VexePrefix);
 sf.pos=527103;
 Vwriter = YiBk(((Tc*)&Ys1d), 1);
 sf.pos=527104;
 Vconfig = YNdL__YC5i(VzimbuConfig);
 sf.pos=527105;
 ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, Vconfig);
 sf.pos=527106;
 Yl0k(((Tc*)&YLmd));
 sf.pos=527107;
 Yl0k(Vconfig);
 sf.pos=527108;
 r = 0;
 topFrame = sf.prev;
 return r;
}
