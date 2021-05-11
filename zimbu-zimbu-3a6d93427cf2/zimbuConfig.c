/*
 * Generated from Zimbu file zimbuConfig.zu
 */
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
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
typedef struct Tj__S Tj; /* xobject ref */
typedef struct Zref__S Tr; /* iobject ref */
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
typedef struct Yw3O__S Yw3O; /* MEModule.OutOfRange */
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
typedef struct Y8is__S Y8is; /* MIOModule.Writer */
typedef struct Yw8L__S Yw8L; /* MIOModule.File */
typedef struct YjUM__S YjUM; /* MIOModule.StringWriter */
/* IOModule done */
/* including ARGModule typedefs */
typedef struct YnU5__S YnU5; /* MARGModule.Status */
typedef struct YuMQ__S YuMQ; /* MARGModule.Usage */
typedef struct YuQR__S YuQR; /* MARGModule.Flag */
typedef struct Y86c__S Y86c; /* MARGModule.Bool */
typedef struct YJQu__S YJQu; /* MARGModule.Int */
typedef struct YzqH__S YzqH; /* MARGModule.String */
typedef struct Y_SI__S Y_SI; /* MARGModule.StringList */
/* ARGModule done */
/* including zimbuConfig typedefs */
/* including Proto typedefs */
/* including Message typedefs */
typedef struct YFL0__S YFL0; /* Message */
/* Message done */
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
struct ZforRange__S {
 Ti idx;
 Ti step;
 Ti last;
};

void ZthrowObject(Tr *eo);
void ZthrowIobject(Ytlm *eo);
Ta *ZnewArray(Tt *itemType, int itemSize, Ti size);

Tl *ZnewList(Tt *itemType, Ti size);

Tl *ZLap(Tl *head, Tz val);
Tl *ZLa(Tl *head, Ti after, Tz val);

void *ZListGetPtr(Tl *head, Ti idx);


struct Tj__S {
 Tc **mt;
};
struct Zref__S {
 void *ptr;
 Tc **table;
 int  type;
};
Tr trZero = {NULL,NULL,-1};
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
extern Tt xobj__T;

struct CArray__S {
 void *ptr;
 int dim;
 Ti size[3];
 Tt *itemType;
 int itemSize;
 int tosNr;
};
void ZfreeArray(Ta *head);
struct CListHead__S {
 Tt *itemType;
 void **items;
 Ti empty;
 Ti space;
 Ti itemCount;
 int itemSize;
 int tosNr;
};
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

Zhashtype ZDictHash(Tt *keyType, Tz key);
CDictItem *ZDictLookup(Td *d, Tz key, Zhashtype hash);
Td *ZDictAdd(int ow, Td *d, Tz key, Tz value);
void ZDictResize(Td *d, int minitems);

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
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Ytlm__T;
typedef struct {
 char text[7];
} Zs7;
struct YEro__S {
 Tc **mt;
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
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto YKhn__T;
struct Y1uN__S {
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Y1uN__T;
struct YAxe__S {
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto YAxe__T;
typedef struct {
 char text[14];
} Zs14;
struct YVNj__S {
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto YVNj__T;
struct Yalz__S {
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Yalz__T;
typedef struct {
 char text[10];
} Zs10;
struct Yw3O__S {
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Yw3O__T;
struct Y2EX__S {
 Tc **mt;
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
 Tc **mt;
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
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto YzSI__T;
struct YXKl__S {
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto YXKl__T;
typedef struct {
 char text[15];
} Zs15;
struct YuDC__S {
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto YuDC__T;
struct YrHq__S {
 Tc **mt;
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
/* including STRINGModule structs */
typedef struct {
 char text[2];
} Zs2;
/* STRINGModule done */
/* including IOModule structs */
struct Y8is__S {
 Tc **mt;
};
struct Yw8L__S {
 Tc **mt;
 FILE * Vfd;
};
extern Tto Yw8L__T;
typedef struct {
 char text[53];
} Zs53;
struct YjUM__S {
 Tc **mt;
 Ti VsLen;
 Ta *Vs;
};
extern Tto YjUM__T;
typedef struct {
 char text[54];
} Zs54;
/* IOModule done */
/* including LOGModule structs */
typedef struct {
 char text[45];
} Zs45;
/* LOGModule done */
/* including ARGModule structs */
struct YnU5__S {
};
extern Tto YnU5__T;
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
 char text[19];
} Zs19;
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
struct YuQR__S {
 Tc **mt;
};
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
 Tc **mt;
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
 Tc **mt;
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
 Tc **mt;
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
 Tc **mt;
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
/* including zimbuConfig structs */
/* including Proto structs */
/* including Message structs */
struct YFL0__S {
 Tc **mt;
};
/* Message done */
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
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Ys_q__T;
struct YOEA__S {
 Tc **mt;
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
 Tc **mt;
 Ti VderefTime;
 Ti VderefId;
 Ti VderefTimeSize;
 Ti VderefIdSize;
 Tc *Vf_mallocArg;
 Tc *Vf_threadArg;
 Tc *Vf_socketArg;
 Tc *Vf_mathArg;
 Tc *Vf_pcreArg;
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
 char text[27];
} Zs27;
typedef struct {
 char text[25];
} Zs25;
typedef struct {
 char text[36];
} Zs36;
typedef struct {
 char text[68];
} Zs68;
typedef struct {
 char text[37];
} Zs37;
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
Tc *Ytlm__mt[13];
To ToYtlm[4];
void YXHSa(YEro *t, Tr Aw); /* MEModule__CExit.writeTo */
Zs7 YxJ1 = {"\005EXIT \000"};
Tc *YEro__mt[23];
To ToYEro[4];
Zs6 YJMo = {"\004Exit\000"};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit); /* MEModule__COutOfMemory.NEW */
Zs28 YIBz = {"\032Out of memory (allocating \000"};
Zs9 YDSH = {"\007 bytes)\000"};
Tc *YKhn__mt[29];
To ToYKhn[4];
Zs13 Y9Fv = {"\013OutOfMemory\000"};
void Y1KV(Ti Asize); /* MEModule.throwOutOfMemorySize */
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg); /* MEModule__CNilAccess.NEW__p2 */
Tc *Y1uN__mt[29];
To ToY1uN[4];
Zs11 Y4wO = {"\011NilAccess\000"};
void YvdV(YkxB *Apos, Tc *Atext); /* MEModule.throwNil */
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg); /* MEModule__CMemoryAccess.NEW__p2 */
Tc *YAxe__mt[29];
To ToYAxe[4];
Zs14 Y4QW = {"\014MemoryAccess\000"};
void YE93(Ti Anr); /* MEModule.throwDeadly */
Zs13 YkfG = {"\013signal SEGV\000"};
Zs12 YoEx = {"\012signal FPE\000"};
Zs12 YQNH = {"\012signal BUS\000"};
Zs9 YpCZ = {"\007signal \000"};
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
Tc *YVNj__mt[29];
To ToYVNj[4];
Zs6 Ysqt = {"\004Init\000"};
void Y3w6(Tc *Atext); /* MEModule.throwInit */
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg); /* MEModule__CBadValue.NEW__p2 */
Tc *Yalz__mt[29];
To ToYalz[4];
Zs10 YEZq = {"\010BadValue\000"};
void Yaez(Tc *Atext); /* MEModule.throwBadValue */
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg); /* MEModule__COutOfRange.NEW__p3 */
Tc *Yw3O__mt[37];
To ToYw3O[4];
Zs12 YFK2a = {"\012OutOfRange\000"};
void Y6NT(Ti Aindex, Tc *Amsg); /* MEModule.throwOutOfRange */
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg); /* MEModule__CKeyNotFound.NEW__p3 */
Tc *Y2EX__mt[37];
To ToY2EX[4];
Zs13 YRiW = {"\013KeyNotFound\000"};
void Yxmk(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyNotFound */
Zs17 Ym6C = {"\017Key not found: \000"};
void Y5LT(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyNotFound */
Zs18 YJ3Y = {"\020Key not found: \"\000"};
Zs3 YI = {"\001\"\000"};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
Tc *YX0i__mt[37];
To ToYX0i[4];
Zs11 Y9_h = {"\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {"\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {"\025Key already exists: \"\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
Tc *YzSI__mt[37];
To ToYzSI[4];
Zs14 YxFl = {"\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
Tc *YXKl__mt[29];
To ToYXKl[4];
Zs9 YTj3 = {"\007IOError\000"};
void YkuV(Tc *Amsg); /* MEModule.throwIOError */
YuDC *YdhH(YuDC *t); /* MEModule__CWrongType.NEW */
Zs15 Ynjz = {"\015Type mismatch\000"};
Tc *YuDC__mt[29];
To ToYuDC[4];
Zs11 YCoZ = {"\011WrongType\000"};
void YTuG(Ti Apos); /* MEModule.throwWrongType */
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg); /* MEModule__CInternal.NEW__p2 */
Tc *YrHq__mt[29];
To ToYrHq[4];
Zs10 YVki = {"\010Internal\000"};
void YUSH(YkxB *Apos, Tc *Atext); /* MEModule.throwInternal */
void YxIS(Ytlm *Ae); /* MEModule.unhandledException */
void YvL0(Ytlm *Ae); /* MEModule.writeToStderr */
void YQar(Ytlm *A0, Tb A1, Yw8L *A2); /* Ytlm_I__MwriteTo_I__bool__Yw8L_I */
/* EModule done */
/* including SYSModule declarations */
Tc *Yhy5(Tc *Aname); /* MSYSModule.getEnv */
Zs9 YVbO = {"\007IOFlags\000"};
Tt MSYSModule__BIOFlags__T = {25, ((Tc*)&YVbO), 0};
/* SYSModule done */
/* including BYTESTRINGModule declarations */
Tc *YlD8(Tc *Athis); /* MBYTESTRINGModule.ToString */
Tc *YyEq(Tc *Athis); /* MBYTESTRINGModule.latin1ToString */
/* BYTESTRINGModule done */
/* including ZModule declarations */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {"\016[unknown file]\000"};
Zs8 YBpY = {"\006 line \000"};
Zs7 Y8ES = {"\005 col \000"};
To ToYkxB[3];
Zs5 YBCs = {"\003Pos\000"};
/* ZModule done */
/* including STRINGModule declarations */
Tc *Yvnf(Tc *Athis, Ti Afrom, Ti Ato); /* MSTRINGModule.replaceAll */
Tc *YuAL(Tc *Athis, Ti Astart); /* MSTRINGModule.slice */
Tc *YuALa(Tc *Athis, Ti Astart, Ti Aend); /* MSTRINGModule.slice */
Zs2 Ya = {"\000\000"};
/* STRINGModule done */
/* including IOModule declarations */
Yw8L *Y59X = NULL; /* MIOModule.stdin */
Yw8L *Yb0q = NULL; /* MIOModule.stdout */
Yw8L *YeNQ = NULL; /* MIOModule.stderr */
Yw8L *Yd89(); /* MIOModule.newStdin */
Yw8L *Yvyt(); /* MIOModule.newStdout */
Yw8L *YsM3(); /* MIOModule.newStderr */
Tc **YdXi__imtt[4];
Ts YwHoa(Yw8L *t, Tc *Atext); /* MIOModule__CFile.write */
Zs18 YQe8 = {"\020File is not open\000"};
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext); /* MIOModule__CFile.print__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__mt[59];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[1];
Zs6 YtTU = {"\004File\000"};
Yw8L *YiBk(Tc *AfileName, Tb Atruncate); /* MIOModule.fileWriter */
Ts Yvcu(Tc *Atext); /* MIOModule.write */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Ts YjUM__Ydti(YjUM *t, Ti Achar); /* MIOModule__CStringWriter.writeChar__p1 */
Zs53 Yv8w = {"\063UTF-8 character must be in range 0 - 0x10ffff, got \000"};
Tc *YjUM__mt[53];
Tc *YjUM__YdXi_imt[3];
To ToYjUM[2];
Zs14 YE4c = {"\014StringWriter\000"};
Tb Y0YB(Tc *Aname); /* MIOModule.isReadable */
Tb Y_3K(Tc *Aname); /* MIOModule.isExecutable */
Tc *Ycmi(Tc *AexeName); /* MIOModule.findExe */
Zs3 YV = {"\001/\000"};
Zs4 YFka = {"\002./\000"};
Zs5 Y0y2 = {"\003../\000"};
Zs6 Yykt = {"\004PATH\000"};
Zs3 Y6 = {"\001;\000"};
Zs3 Y5 = {"\001:\000"};
Zs6 YpPR = {"\004.exe\000"};
Tc *YDop(Tc *AexeName, Tl *Adirs); /* MIOModule.findExeInDirList */
Tc *Yq8a(Tc *Afirst, Tc *Asecond); /* MIOModule.concatPath */
Zs3 YU = {"\001.\000"};
Tc *Y2wM(Tc *Afname); /* MIOModule.fullPath */
Zs54 Yd94 = {"\064IO.fullPath(): Unable to return to current directory\000"};
Tc *YPjH(Tc *Afname); /* MIOModule.resolve */
Ti Yr30(Tc *Afname); /* MIOModule.tailIndex */
Ti YEpA(Tc *Afname); /* MIOModule.pastHeadIndex */
Tb Yhu2(Ti Ac); /* MIOModule.isPathSep */
Ti Y26N(Tc *Afname, Ti Aidx); /* MIOModule.nextPartIndex */
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
Zs7 YuXA = {"\005Flags\000"};
Tt MLOGModule__BFlags__T = {25, ((Tc*)&YuXA), 0};
int JLOGModule(int round);
/* LOGModule done */
/* including ARGModule declarations */
Tc *YzvW = NULL; /* MARGModule.rawName */
Tc *Y2R7 = NULL; /* MARGModule.exeName */
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
To ToYnU5[1];
Zs8 Yr32 = {"\006Status\000"};
void YQtK(); /* MARGModule.initExeName */
Tc *YzHL(); /* MARGModule.getExeDir */
void YZH8(); /* MARGModule.init */
Zs56 Y7T_ = {"\066ARG.disable() used but command line flags were defined\000"};
Zs3 YT = {"\001-\000"};
Zs4 Y1ia = {"\002--\000"};
Zs6 YqzQ = {"\004help\000"};
Zs10 Y3vi = {"\010morehelp\000"};
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
Zs3 YG = {"\001 \000"};
Zs5 Y_y2 = {"\003...\000"};
Zs6 Y2yA = {"\004... \000"};
Zs13 Ym4c = {"\013Defined in \000"};
void YTlu(Tc *Alead, Ti AmaxLeadLen); /* MARGModule.writeLead */
Tc *YAMW(YuMQ *t); /* MARGModule__CUsage.get */
Zs5 YMtG = {"\003%0%\000"};
To ToYuMQ[2];
Zs7 Y6qT = {"\005Usage\000"};
Td *Y7be = NULL; /* MARGModule.shortFlags */
Td *YBQy = NULL; /* MARGModule.longFlags */
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc); /* MARGModule__CBool.NEW */
void YEqoa(Y86c *t); /* MARGModule__CBool.setToDefault */
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CBool.NEW__p1 */
Zs42 Yc_h = {"\050Adding command line flag after using one\000"};
Zs50 Y6pY = {"\060Command line flag must have a short or long name\000"};
Zs52 Y9CP = {"\062short command line flag name must be one character\000"};
void Y86c__YofP(Y86c *t, Tc *Aname, YuQR *Aflag, YkxB *Apos); /* MARGModule__CBool.throwDuplicate__p1 */
Zs9 YbbH = {"\007unknown\000"};
Zs32 YtzG = {"\036Duplicate command line flag: '\000"};
Zs17 YDyy = {"\017' also used at \000"};
Tc *Y86c__mt[32];
To ToY86c[6];
Zs6 YZ1F = {"\004Bool\000"};
void Y49ga(YJQu *t); /* MARGModule__CInt.setToDefault */
Tc *YJQu__mt[35];
To ToYJQu[7];
Zs5 YzBa = {"\003Int\000"};
void YJaza(YzqH *t); /* MARGModule__CString.setToDefault */
Tc *YzqH__mt[35];
To ToYzqH[9];
Zs8 YDAE = {"\006String\000"};
void YSkKa(Y_SI *t); /* MARGModule__CStringList.setToDefault */
Tc *Y_SI__mt[31];
To ToY_SI[8];
Zs12 Ygf5 = {"\012StringList\000"};
int JARGModule(int round);
/* ARGModule done */
/* including zimbuConfig declarations */
/* including Proto declarations */
Tt MProto__EType__T = {23, 0, MProto__EType__name};
Tt MProto__EBinaryType__T = {23, 0, 0};
Ys_q *Ys_q__YwtA__YRHR(Ys_q *t, Tc *Amsg); /* MProto__CE_ProduceError.NEW__p2 */
Tc *Ys_q__mt[29];
To ToYs_q[4];
Zs16 Y4sk = {"\016E_ProduceError\000"};
YOEA *YOEA__YwtA__YRHR(YOEA *t, Tc *Amsg); /* MProto__CE_BinaryError.NEW__p2 */
Tc *YOEA__mt[29];
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
Ti YFN0(YFL0 *Amsg, YLWE *AprotoWriter); /* MProto.binarySize */
Zs34 Ytvm = {"\040INTERNAL: type not implemented: \000"};
Ti YMrV(YFL0 *At, YFL0 *Amsg, YqvM *Afspec, YLWE *AprotoWriter); /* MProto.binaryMessageSize */
void YP8Z(YFL0 *Amsg, YLWE *AprotoWriter); /* MProto.writeText */
Zs15 YvJi = {"\015# reference: \000"};
Zs4 YN2 = {"\002# \000"};
Zs9 Y0Eh = {"\007 size: \000"};
Zs9 Y8RH = {"\007 bytes\n\000"};
void YWEg(YFL0 *Amsg, YqvM *Afspec, Ti Aidx, YLWE *AprotoWriter); /* MProto.writeOneTextField */
Zs5 YxR2 = {"\003.9g\000"};
Zs6 YmwI = {"\004.17g\000"};
Zs6 YHoE = {"\004TRUE\000"};
Zs7 Y2cy = {"\005FALSE\000"};
Zs4 YQ0 = {"\002\"\n\000"};
Zs4 Ywhc = {"\002{\n\000"};
Zs4 YZY = {"\002  \000"};
Zs4 YJkc = {"\002}\n\000"};
Zs38 Y80t = {"\044INTERNAL: field type not supported: \000"};
void YeeB(YFL0 *At, Ti AfieldNr, YLWE *AprotoWriter); /* MProto.writeMessageText */
void YeeBa(YFL0 *At, Ti AfieldNr, Ti Aidx, YLWE *AprotoWriter); /* MProto.writeMessageText */
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
YNdL *YMyf(YNdL *t, Tc *Av); /* MZimbu__CConfig.setPcreArg */
Tb YGhA(YNdL *t); /* MZimbu__CConfig.hasPcreArg */
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
Zs9 YG1V = {"\007pcreArg\000"};
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
Tc *YNdL__YlHQ(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.bytesGet__p1 */
Tc *YNdL__YlHQa(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.bytesGet__p1 */
YFL0 *YNdL__Yo5y(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.messageGet__p1 */
YFL0 *YNdL__Yo5ya(YNdL *t, Ti AfieldNr, Ti Aidx); /* MZimbu__CConfig.messageGet__p1 */
Ti YNdL__YUDN(YNdL *t, Ti AfieldNr); /* MZimbu__CConfig.size__p1 */
Tc *YNdL__YC5i(YNdL *t); /* MZimbu__CConfig.ToString__p1 */
Tc *YNdL__mt[246];
To ToYNdL[20];
int JzimbuConfig(int round);
/* zimbuConfig done */
void YWeD(); /* generateConfigOut */
Zs17 Ys1d = {"\017zimbuConfig.out\000"};
Zs27 YIrD = {"\031Generated zimbuConfig.out\000"};
void YH2W(YNdL *AzimbuConfig); /* findTcmalloc */
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
void Y5sp(YNdL *AzimbuConfig); /* findThreadAndSocketLibs */
Zs11 YglX = {"\011-lpthread\000"};
void YTmn(YNdL *AzimbuConfig); /* findMathLib */
Zs5 YtA1 = {"\003-lm\000"};
void YqfB(YNdL *AzimbuConfig); /* findPcreLib */
Zs28 YhVq = {"\032/thirdparty/pcre/pcrelib.o\000"};
void YZP1(YNdL *AzimbuConfig); /* findLibMethods */
void Yfdk(YNdL *AzimbuConfig); /* checkIsMingw */
void YqaV(YNdL *AzimbuConfig); /* checkSizes */
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
void YB9D(YNdL *AzimbuConfig); /* checkExeName */
void YZTI(); /* generateConfigMak */
Zs6 YxAY = {"\004node\000"};
Zs8 Y6Qt = {"\006nodejs\000"};
Zs17 Ypn8 = {"\017zimbuConfig.mak\000"};
Zs28 Ybaf = {"\032# GENERATED by zimbuConfig\000"};
Zs17 YDew = {"\017NODEJS = nodejs\000"};
Zs15 Y0qk = {"\015NODEJS = node\000"};
Zs27 YL5I = {"\031Generated zimbuConfig.mak\000"};
Zs37 YzQa = {"\043Could not find a Node.js executable\000"};

Tt bool__T = {21, 0, 0};
Tt byte__T = {11, 0, 0};
Tt byteString__T = {201, 0, 0};
Tt float128__T = {83, 0, 0};
Tt float32__T = {81, 0, 0};
Tt float80__T = {82, 0, 0};
Tt float__T = {80, 0, 0};
Tt int16__T = {2, 0, 0};
Tt int32__T = {3, 0, 0};
Tt int8__T = {1, 0, 0};
Tt int__T = {0, 0, 0};
Tt nat16__T = {12, 0, 0};
Tt nat32__T = {13, 0, 0};
Tt nat__T = {10, 0, 0};
Tt status__T = {22, 0, 0};
Tt string__T = {200, 0, 0};
Tt type__T = {101, 0, 0};
Tt array__T = {300, 0, 0};
Tt list__T = {301, 0, 0};
Tt dict__T = {302, 0, 0};
Tt iobj__T = {391, 0, 0};
Tt xobj__T = {392, 0, 0};
int ZglobInit(int round);

typedef struct Zfo__S {
 int off;
 Tt  *type;
} Zfo;
typedef struct Zsf__S {
 volatile int pos;
 struct Zsf__S *prev;
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
    goto end;
   }
   fprintf(stderr, "Out of memory Za(%ld)\n", (long)size);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
end:
 return p;
}

/* allocate memory */
void *Zamt(size_t size, Tc **mt) {
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
    goto end;
   }
   fprintf(stderr, "Out of memory Zamt(%ld)\n", (long)size);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
end:
 ((Tj *)p)->mt = mt;
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
    goto end;
   }
   fprintf(stderr, "Out of memory ZaNm(%ld)\n", (long)size);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
end:
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
   fprintf(stderr, "Out of memory ZaNmi(%ld)\n", (long)size);
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
Tc Y0hD[]="ZUDIR/zimbuConfig.zu";
Tc YCG4[]="lib/ARGModule.zu";
Tc Y7ob[]="lib/BYTESTRINGModule.zu";
Tc Yt1T[]="lib/EModule.zu";
Tc Yay0[]="lib/IOModule.zu";
Tc Y76z[]="lib/LOGModule.zu";
Tc Yv00[]="lib/STRINGModule.zu";
Tc Y0dn[]="lib/SYSModule.zu";
Tc Y3zM[]="lib/ZModule.zu";
Tc Y_hM[]="plugin/proto/Message.zu";
Tc YxTh[]="plugin/proto/Proto.zu";
Tc YTYp[]="zimbuConfig.zu";
Tc Y_VO[]="ARG.Bool.NEW/1()";
Tcpos ZcTbl3273[]={
{791,5},
{1,7},
{2,16},
{3,16},
{4,18},
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
{799,11},
{1,16},
};
Tc YgDO[]="ARG.Bool.throwDuplicate__p1/1()";
Tcpos ZcTbl75697[]={
{679,11},
{1,44},
{2,18},
{4,7},
};
Tc YPPv[]="ARG.Init()";
Tcpos ZcTbl66501[]={
{78,29},
};
Tc Ygzb[]="ARG.Int.setToDefault/1()";
Tcpos ZcTbl16350[]={
{864,11},
{1,16},
};
Tc YZNA[]="ARG.String.setToDefault/1()";
Tcpos ZcTbl86206[]={
{952,11},
{1,16},
};
Tc YRbs[]="ARG.StringList.setToDefault/1()";
Tcpos ZcTbl64478[]={
{1045,11},
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
Tc YBSz[]="ARG.getExeDir()";
Tcpos ZcTbl32618[]={
{248,24},
{1,5},
{3,14},
{5,20},
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
Tc YTJ0[]="ARG.initExeName()";
Tcpos ZcTbl77164[]={
{238,13},
};
Tc YMnk[]="ARG.writeLead()";
Tcpos ZcTbl81798[]={
{569,5},
{2,5},
{3,7},
{2,5},
};
Tc YBlZ[]="BYTESTRING.ToString()";
Tcpos ZcTbl79192[]={
{52,5},
{1,14},
{3,25},
{4,5},
{5,7},
{4,5},
{7,14},
};
Tc Y8vN[]="BYTESTRING.latin1ToString()";
Tcpos ZcTbl3777[]={
{88,5},
{1,14},
{3,12},
};
Tc Ylvo[]="Config.ToString__p1/1()";
Tcpos ZcTbl79794[]={
{167,9},
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
Tc Yi9K[]="Config.bytesGet__p1/2()";
Tcpos ZcTbl33052[]={
{107,9},
{1,12},
};
Tc YnAI[]="Config.bytesGet__p1/3()";
Tcpos ZcTbl43253[]={
{110,9},
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
{139,9},
{1,12},
};
Tc Y7VA[]="Config.messageGet__p1/3()";
Tcpos ZcTbl5951[]={
{142,9},
{1,12},
};
Tc YV4L[]="Config.size__p1/1()";
Tcpos ZcTbl81627[]={
{158,9},
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
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y_Qs[]="E.DivideByZero.NEW__p3/3()";
Tcpos ZcTbl73471[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YPz2[]="E.E_BinaryError.NEW__p2/2()";
Tcpos ZcTbl46312[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YWEC[]="E.E_ProduceError.NEW__p2/2()";
Tcpos ZcTbl70833[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YgcH[]="E.Exception.writeTo()";
Tcpos ZcTbl49183[]={
{85,11},
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
{112,11},
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
{188,11},
{1,7},
{2,9},
{3,9},
{5,7},
{6,7},
{7,7},
{8,9},
{9,9},
};
Tc Y9Cv[]="E.IOError.NEW__p2/2()";
Tcpos ZcTbl48299[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yp81[]="E.Init.NEW__p2/2()";
Tcpos ZcTbl53377[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yuz_[]="E.Init.NEW__p2/3()";
Tcpos ZcTbl63578[]={
{67,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YbzA[]="E.Internal.NEW__p2/2()";
Tcpos ZcTbl78082[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Ycb9[]="E.KeyExists.NEW__p3/3()";
Tcpos ZcTbl85000[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YAVe[]="E.KeyNotFound.NEW__p3/3()";
Tcpos ZcTbl29585[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YF6S[]="E.MemoryAccess.NEW__p2/2()";
Tcpos ZcTbl73580[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y1As[]="E.NilAccess.NEW__p2/2()";
Tcpos ZcTbl32086[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YobA[]="E.OutOfMemory.NEW/3()";
Tcpos ZcTbl80644[]={
{268,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y99g[]="E.OutOfRange.NEW__p3/3()";
Tcpos ZcTbl56381[]={
{58,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YR5m[]="E.WrongType.NEW/1()";
Tcpos ZcTbl87235[]={
{520,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YEFs[]="E.unhandledException()";
Tcpos ZcTbl15718[]={
{618,23},
{0,23},
{0,23},
};
Tc YgcM[]="E.writeToStderr()";
Tcpos ZcTbl52386[]={
{638,5},
{1,5},
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
{234,11},
{1,15},
};
Tc YJ7z[]="IO.File.print__p1/8()";
Tcpos ZcTbl66188[]={
{186,11},
{1,7},
{2,16},
{4,14},
};
Tc Yj_J[]="IO.File.write/8()";
Tcpos ZcTbl94823[]={
{498,11},
{3,9},
{4,11},
{6,4},
{59,14},
};
Tc YrJP[]="IO.StringWriter.ToString()";
Tcpos ZcTbl64531[]={
{1778,11},
{3,9},
{4,13},
{6,4},
{17,14},
};
Tc YCbR[]="IO.StringWriter.write/8()";
Tcpos ZcTbl89987[]={
{1694,11},
{1,37},
{3,9},
{4,14},
{5,11},
{6,17},
{8,11},
{10,13},
{12,11},
{13,17},
{25,14},
};
Tc Y1Ue[]="IO.StringWriter.writeChar__p1/1()";
Tcpos ZcTbl49285[]={
{177,11},
{1,7},
{2,9},
{4,15},
};
Tc YzQB[]="IO.StringWriter.write__p1/9()";
Tcpos ZcTbl72007[]={
{129,11},
{1,15},
};
Tc Y0Nw[]="IO.concatPath()";
Tcpos ZcTbl68304[]={
{2541,5},
{1,7},
{2,22},
{4,20},
{6,5},
{7,20},
{10,4},
{14,7},
{15,16},
{17,4},
{22,25},
};
Tc Y5X7[]="IO.fileWriter()";
Tcpos ZcTbl81580[]={
{1250,4},
{8,9},
{9,4},
{32,12},
};
Tc YrlY[]="IO.findExe()";
Tcpos ZcTbl64970[]={
{2426,11},
{1,7},
{4,15},
{7,27},
{8,9},
{9,4},
{12,23},
{13,4},
{16,23},
{17,4},
{21,15},
{22,4},
{25,9},
{26,17},
{28,4},
{31,9},
{32,4},
{36,11},
{37,19},
{38,18},
{39,19},
{41,4},
{45,17},
{49,5},
{50,14},
{52,12},
};
Tc Y60W[]="IO.findExeInDirList()";
Tcpos ZcTbl86176[]={
{2486,5},
{1,22},
{2,7},
{3,16},
{0,5},
{6,12},
};
Tc YN2v[]="IO.flush()";
Tcpos ZcTbl46761[]={
{1672,4},
{9,12},
};
Tc Yk1s[]="IO.fullPath()";
Tcpos ZcTbl38403[]={
{2579,4},
{19,21},
{21,23},
{22,4},
{61,4},
{93,4},
{106,6},
{107,4},
{111,12},
{114,4},
{122,5},
{123,14},
{127,5},
{128,14},
{131,5},
{132,25},
{134,16},
};
Tc Yuq9[]="IO.isExecutable()";
Tcpos ZcTbl73877[]={
{2109,4},
{13,14},
};
Tc Yofe[]="IO.isPathSep()";
Tcpos ZcTbl79136[]={
{3018,14},
};
Tc YZKb[]="IO.isReadable()";
Tcpos ZcTbl71563[]={
{2067,4},
{13,14},
};
Tc YaL5[]="IO.nextPartIndex()";
Tcpos ZcTbl36277[]={
{3024,5},
{1,7},
{2,18},
{0,5},
{5,13},
};
Tc YSYC[]="IO.pastHeadIndex()";
Tcpos ZcTbl11017[]={
{2999,4},
{3,7},
{4,11},
{6,4},
{10,5},
{11,7},
{10,5},
{13,12},
};
Tc YNFk[]="IO.print()";
Tcpos ZcTbl1872[]={
{1551,37},
{1,4},
{18,12},
};
Tc YlPR[]="IO.resolve()";
Tcpos ZcTbl45331[]={
{2745,4},
{3,12},
{4,4},
{9,23},
{12,39},
{15,33},
{17,13},
{18,5},
{22,14},
{23,14},
{26,14},
{29,5},
{30,7},
{32,4},
{40,11},
{41,4},
{58,9},
{59,18},
{64,9},
{65,16},
{70,11},
{71,9},
{72,11},
{73,20},
{75,20},
{77,16},
{80,17},
{81,9},
{83,18},
{84,13},
{86,9},
{88,18},
{91,18},
{30,7},
{95,7},
{101,9},
{102,7},
{103,16},
{104,16},
{106,16},
{107,16},
{29,5},
{113,5},
{114,7},
{123,16},
{124,14},
{126,11},
{127,9},
{128,13},
{127,9},
{130,9},
{131,18},
{138,5},
{139,15},
{140,7},
{141,16},
{140,7},
{146,4},
{150,12},
};
Tc YU58[]="IO.tailIndex()";
Tcpos ZcTbl62213[]={
{2905,19},
{2,4},
{5,19},
{6,5},
{7,9},
{9,4},
{13,5},
{14,14},
{16,14},
};
Tc Y_pS[]="IO.write()";
Tcpos ZcTbl84870[]={
{1488,4},
{13,12},
};
Tc YVvh[]="LOG";
Tcpos ZcTbl83326[]={
{19,12},
{2,12},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{25,3},
{1,3},
{2,10},
};
Tc Y1Hw[]="Proto";
Tcpos ZcTbl30532[]={
{301,26},
{16,25},
};
Tc YlSz[]="Proto.FieldSpec.NEW()";
Tcpos ZcTbl13666[]={
{106,5},
{1,13},
{2,11},
{3,13},
{4,17},
};
Tc YnDn[]="Proto.Writer.NEW/2()";
Tcpos ZcTbl12469[]={
{170,5},
{1,15},
{2,15},
{3,14},
{5,7},
};
Tc YlQ3[]="Proto.Writer.initDeref()";
Tcpos ZcTbl32956[]={
{178,11},
{1,18},
{2,22},
};
Tc YGqq[]="Proto.binaryMessageSize()";
Tcpos ZcTbl37884[]={
{871,5},
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
{737,5},
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
{43,20},
{44,34},
{45,27},
{46,20},
{49,28},
{50,20},
{51,20},
{54,35},
{55,20},
{58,15},
{3,9},
{63,9},
{64,11},
{67,20},
{68,20},
{71,20},
{72,20},
{75,20},
{76,27},
{77,20},
{80,20},
{81,27},
{82,20},
{85,20},
{86,20},
{89,20},
{90,20},
{93,20},
{94,20},
{97,20},
{98,34},
{99,27},
{100,20},
{103,20},
{104,34},
{105,27},
{106,20},
{109,28},
{110,20},
{111,20},
{114,35},
{115,20},
{118,15},
{0,5},
{124,12},
};
Tc Y6Nc[]="Proto.getBinaryTagSize()";
Tcpos ZcTbl49599[]={
{342,35},
{1,12},
};
Tc YAt_[]="Proto.getVarIntSize()";
Tcpos ZcTbl36994[]={
{2106,5},
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
{1058,21},
{1,5},
{2,7},
};
Tc YleD[]="Proto.writeMessageText/1()";
Tcpos ZcTbl71988[]={
{1066,21},
{1,5},
{2,7},
};
Tc Yutk[]="Proto.writeOneTextField()";
Tcpos ZcTbl94729[]={
{935,38},
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
{76,9},
{77,13},
{79,13},
{81,9},
{83,9},
{85,11},
{86,15},
{88,15},
{90,11},
{93,9},
{94,16},
{96,16},
{98,9},
{100,9},
{101,37},
{102,9},
{103,30},
{105,9},
{106,11},
{108,11},
{110,28},
{111,9},
{112,11},
{114,9},
{116,9},
};
Tc Yw9e[]="Proto.writeText()";
Tcpos ZcTbl19299[]={
{909,5},
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
Tc YuIh[]="STRING.replaceAll()";
Tcpos ZcTbl12035[]={
{718,5},
{1,14},
{3,18},
{4,5},
{6,27},
{7,7},
{8,9},
{9,11},
{11,9},
{12,18},
{13,11},
{7,7},
{15,7},
{16,16},
{18,12},
};
Tc YPS1[]="STRING.slice()";
Tcpos ZcTbl50614[]={
{842,5},
{1,14},
{3,17},
};
Tc Y7DX[]="STRING.slice/1()";
Tcpos ZcTbl63594[]={
{858,5},
{1,14},
{3,5},
{4,14},
{6,17},
};
Tc YQ54[]="SYS.getEnv()";
Tcpos ZcTbl42323[]={
{93,4},
{5,12},
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
{629,29},
};
Tc Y4yh[]="Zimbu.Config.NEW()";
Tcpos ZcTbl27632[]={
{8,5},
};
Tc Y2C_[]="checkExeName()";
Tcpos ZcTbl70562[]={
{308,13},
{1,13},
{2,4},
{8,3},
{9,3},
};
Tc Yiu1[]="checkIsMingw()";
Tcpos ZcTbl26389[]={
{139,4},
{5,3},
};
Tc Ycjb[]="checkSizes()";
Tcpos ZcTbl42953[]={
{161,4},
{13,3},
{14,3},
{15,5},
{19,3},
{20,5},
{21,19},
{22,5},
{24,5},
{25,5},
{28,20},
{32,4},
{35,18},
{36,18},
{37,18},
{38,4},
{41,18},
{42,18},
{43,18},
{44,4},
{49,3},
{51,19},
{52,13},
{53,20},
{54,20},
{55,20},
{56,18},
{57,13},
{58,20},
{59,20},
{61,5},
{63,3},
{64,3},
{65,3},
{67,3},
{68,3},
{69,5},
{73,3},
{74,5},
{75,22},
{76,5},
{78,5},
{79,5},
{82,20},
{83,3},
{85,22},
{86,13},
{87,20},
{88,21},
{89,13},
{90,20},
{92,5},
{95,3},
{96,3},
{98,3},
{99,3},
{100,5},
{103,3},
{104,3},
{105,5},
{110,4},
{113,14},
{114,4},
{119,14},
{120,4},
{124,14},
{125,4},
{128,14},
{129,4},
{134,14},
{135,4},
{139,3},
};
Tc Y9px[]="findLibMethods()";
Tcpos ZcTbl9177[]={
{118,4},
{13,3},
{14,3},
{15,3},
{16,3},
};
Tc YzMq[]="findMathLib()";
Tcpos ZcTbl55751[]={
{100,22},
{1,3},
};
Tc YSN8[]="findPcreLib()";
Tcpos ZcTbl16851[]={
{108,49},
{1,3},
};
Tc Y3Cn[]="findTcmalloc()";
Tcpos ZcTbl43713[]={
{52,3},
{7,5},
{8,7},
{9,15},
{7,5},
{13,5},
{0,3},
{18,3},
{19,5},
{21,5},
{22,5},
};
Tc YGyE[]="findThreadAndSocketLibs()";
Tcpos ZcTbl20756[]={
{80,24},
{6,4},
{12,3},
{13,3},
{14,5},
};
Tc Y0Pm[]="generateConfigMak()";
Tcpos ZcTbl21191[]={
{322,20},
{1,22},
{5,3},
{6,25},
{7,5},
{8,5},
{9,7},
{11,7},
{14,5},
{16,5},
};
Tc YMht[]="generateConfigOut()";
Tcpos ZcTbl39822[]={
{31,30},
{2,3},
{3,3},
{4,3},
{5,3},
{6,3},
{7,3},
{8,3},
{9,3},
{11,23},
{12,31},
{13,3},
{15,3},
};
Tcode ZcodeTable[]={
{1872,Yay0,YNFk,ZcTbl1872},
{3273,YCG4,Y_VO,ZcTbl3273},
{3777,Y7ob,Y8vN,ZcTbl3777},
{5270,YTYp,Y9QD,ZcTbl5270},
{5781,Y_hM,Yv8D,ZcTbl5781},
{5951,Y_hM,Y7VA,ZcTbl5951},
{7452,Yay0,Ys1a,ZcTbl7452},
{9177,YTYp,Y9px,ZcTbl9177},
{11017,Yay0,YSYC,ZcTbl11017},
{12035,Yv00,YuIh,ZcTbl12035},
{12469,YxTh,YnDn,ZcTbl12469},
{13235,Y_hM,YnCh,ZcTbl13235},
{13666,YxTh,YlSz,ZcTbl13666},
{15718,Yt1T,YEFs,ZcTbl15718},
{16247,Y_hM,YQ25,ZcTbl16247},
{16350,YCG4,Ygzb,ZcTbl16350},
{16851,YTYp,YSN8,ZcTbl16851},
{18187,Y3zM,Ym1t,ZcTbl18187},
{19299,YxTh,Yw9e,ZcTbl19299},
{20756,YTYp,YGyE,ZcTbl20756},
{21191,YTYp,Y0Pm,ZcTbl21191},
{21451,Y_hM,YGC4,ZcTbl21451},
{23436,Y_hM,Yibk,ZcTbl23436},
{25401,Y_hM,YiT7,ZcTbl25401},
{26389,YTYp,Yiu1,ZcTbl26389},
{26448,Y_hM,YVt3,ZcTbl26448},
{27632,Y0hD,Y4yh,ZcTbl27632},
{29560,YCG4,YzK9,ZcTbl29560},
{29585,Yt1T,YAVe,ZcTbl29585},
{30096,Y_hM,YMHx,ZcTbl30096},
{30532,YxTh,Y1Hw,ZcTbl30532},
{31652,Y_hM,YBb7,ZcTbl31652},
{32086,Yt1T,Y1As,ZcTbl32086},
{32618,YCG4,YBSz,ZcTbl32618},
{32956,YxTh,YlQ3,ZcTbl32956},
{33052,Y_hM,Yi9K,ZcTbl33052},
{36277,Yay0,YaL5,ZcTbl36277},
{36491,Yt1T,YYT9,ZcTbl36491},
{36994,YxTh,YAt_,ZcTbl36994},
{37884,YxTh,YGqq,ZcTbl37884},
{38403,Yay0,Yk1s,ZcTbl38403},
{38911,YCG4,YM2k,ZcTbl38911},
{39822,YTYp,YMht,ZcTbl39822},
{40297,Y_hM,YHgA,ZcTbl40297},
{42323,Y0dn,YQ54,ZcTbl42323},
{42953,YTYp,Ycjb,ZcTbl42953},
{43000,YCG4,YEFE,ZcTbl43000},
{43253,Y_hM,YnAI,ZcTbl43253},
{43713,YTYp,Y3Cn,ZcTbl43713},
{45061,Y_hM,YKxu,ZcTbl45061},
{45331,Yay0,YlPR,ZcTbl45331},
{46312,Yt1T,YPz2,ZcTbl46312},
{46761,Yay0,YN2v,ZcTbl46761},
{48299,Yt1T,Y9Cv,ZcTbl48299},
{49183,Yt1T,YgcH,ZcTbl49183},
{49285,Yay0,Y1Ue,ZcTbl49285},
{49599,YxTh,Y6Nc,ZcTbl49599},
{50614,Yv00,YPS1,ZcTbl50614},
{52386,Yt1T,YgcM,ZcTbl52386},
{53377,Yt1T,Yp81,ZcTbl53377},
{55262,Y_hM,YF6w,ZcTbl55262},
{55751,YTYp,YzMq,ZcTbl55751},
{56381,Yt1T,Y99g,ZcTbl56381},
{60593,Yt1T,Y5LR,ZcTbl60593},
{62213,Yay0,YU58,ZcTbl62213},
{63578,Yt1T,Yuz_,ZcTbl63578},
{63594,Yv00,Y7DX,ZcTbl63594},
{64478,YCG4,YRbs,ZcTbl64478},
{64531,Yay0,YrJP,ZcTbl64531},
{64912,YxTh,YufP,ZcTbl64912},
{64970,Yay0,YrlY,ZcTbl64970},
{66188,Yay0,YJ7z,ZcTbl66188},
{66501,YCG4,YPPv,ZcTbl66501},
{68304,Yay0,Y0Nw,ZcTbl68304},
{70562,YTYp,Y2C_,ZcTbl70562},
{70833,Yt1T,YWEC,ZcTbl70833},
{71563,Yay0,YZKb,ZcTbl71563},
{71988,YxTh,YleD,ZcTbl71988},
{72007,Yay0,YzQB,ZcTbl72007},
{73471,Yt1T,Y_Qs,ZcTbl73471},
{73580,Yt1T,YF6S,ZcTbl73580},
{73877,Yay0,Yuq9,ZcTbl73877},
{74691,Y0hD,YBc8,ZcTbl74691},
{75697,YCG4,YgDO,ZcTbl75697},
{75882,Y_hM,YOLm,ZcTbl75882},
{76644,YCG4,YImf,ZcTbl76644},
{77164,YCG4,YTJ0,ZcTbl77164},
{77282,Y_hM,YRsF,ZcTbl77282},
{78082,Yt1T,YbzA,ZcTbl78082},
{79136,Yay0,Yofe,ZcTbl79136},
{79192,Y7ob,YBlZ,ZcTbl79192},
{79218,Y_hM,Y51G,ZcTbl79218},
{79794,Y_hM,Ylvo,ZcTbl79794},
{80644,Yt1T,YobA,ZcTbl80644},
{81580,Yay0,Y5X7,ZcTbl81580},
{81627,Y_hM,YV4L,ZcTbl81627},
{81798,YCG4,YMnk,ZcTbl81798},
{82533,YCG4,Yh2v,ZcTbl82533},
{82534,YCG4,Yh2v,ZcTbl82534},
{82618,Yay0,Yxlj,ZcTbl82618},
{83326,Y76z,YVvh,ZcTbl83326},
{84870,Yay0,Y_pS,ZcTbl84870},
{85000,Yt1T,Ycb9,ZcTbl85000},
{85295,YCG4,Yza4,ZcTbl85295},
{86083,Y_hM,YJkp,ZcTbl86083},
{86176,Yay0,Y60W,ZcTbl86176},
{86206,YCG4,YZNA,ZcTbl86206},
{87235,Yt1T,YR5m,ZcTbl87235},
{87483,Y_hM,YWTC,ZcTbl87483},
{89987,Yay0,YCbR,ZcTbl89987},
{90679,YxTh,YI64,ZcTbl90679},
{92163,Yt1T,YTjU,ZcTbl92163},
{94729,YxTh,Yutk,ZcTbl94729},
{94823,Yay0,Yj_J,ZcTbl94823},
{95580,Y_hM,YqIG,ZcTbl95580},
{95750,Y_hM,Y2uD,ZcTbl95750},
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

int ZxobjIsa(void *p, int i) {
 return p != NULL && (Tip)((Tj*)p)->mt[1] == i;
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
  if (orig.type < type || orig.type > maxType) YTuG(pos);
  p.ptr = orig.ptr;
  p.type = orig.type - type;
  p.table = table[p.type];
 }
 return p;
}
Tr ZconvertZiopref(void *orig, Tc ***table, int type, int maxType, Ti pos) {
 Tr p;
 p.ptr = orig;
 if (orig) {
  p.type = -type;
  p.table = table[p.type];
 }
 return p;
}
void *Ziobj2xobj(Tr orig, int type, int maxType, Ti pos) {
 if (orig.ptr == NULL) return NULL;
 if (orig.type < type || orig.type > maxType) YTuG(pos);
 return orig.ptr;
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
void *Znip(void *type, Ti pos, void *p) {
 if (p && ((Tj*)p)->mt[0] != type) YTuG(pos);
 return p;
}

void Zexit(YkxB *pos, Ti val) {
 beforeExit();
 exit((int)val);
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

Tc *ZstringToLowerAscii(Tc *ss) {
 Tc *r;
 Tc *d;
 Tc *s;
 Ti len;
 if (ss == NULL) return NULL;
 len = ZstringSizePtr(ss, &s);
 r = ZnewString(s, len);
 d = r + (s - (Tc*)ss);
 while (*s != 0)
  *d++ = tolower(*s++);
 *d = 0;
 return (Tc*)r;
}

Tc *ZstringToLower(Tc *ss) {
 return ZstringToLowerAscii(ss);
}

void ZforBytestringNew(void *p, Tfs *fs) {
 fs->len = p == NULL ? 0 : ZstringSizePtr(p, &(fs->ptr));
 fs->idx = 0;
}
void ZforBytestringGetInt(Tfs *fs, Ti *p) {
 if (fs->idx >= fs->len) *p = 0;
 else *p = fs->ptr[fs->idx];
}
int ZforBytestringContInt(Tfs *fs) {
 return fs->idx < fs->len;
}
void ZforBytestringNextInt(Tfs *fs, Ti *p) {
 if (fs->idx < fs->len) ++(fs->idx);
 ZforBytestringGetInt(fs, p);
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
 Ti idx = *p + s->step;
 s->idx = idx;
 *p = idx;
}

void ZthrowIobject(Ytlm *eo) {
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

Tl *ZstringSplit(Tc *b, Tc *m) {
 Tc *p;
 Ti len;
 Tl *r;
 if (b == NULL) {
  r = NULL;
 } else {
  if (m == NULL) ZthrowCstringNil("split() argument is NIL");
  len = ZstringSizePtr(b, &p);
  r = ZstringSplitLen(p, len, m);
 }
 return r;
}

Tc *ZstringSliceWrap(Tc *sv, Ti start, Ti end) {
 Ti is;
 Ti ie;
 Tc *p;
 Ti len;
 Tc *r;
 if (sv == NULL) return NULL;
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
  if (count > head->size[0] - offset) count = head->size[0] - offset;
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

void *ZListGetPtr(Tl *head, Ti idx) {
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) return head->items[n];
 return NULL;
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

void ZthrowIntKeyNotFound(Tz key, Tc *msg) {
  Yxmk(key.ival, msg);
}

void ZthrowStringKeyNotFound(Tz key, Tc *msg) {
  Y5LT(key.ptr, msg);
}

CDictItem *ZDictFind(Td *d, Tz key) {
 Zhashtype  hash = ZDictHash(d->keyType, key);
 CDictItem  *di = ZDictLookup(d, key, hash);
 if (di->flags & CDI_FLAG_USED) return di;
 return NULL;
}

void *ZDictGetPtrP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  ZDictAdd(1, d, key, (Tz)(void*)0);
  di = ZDictFind(d, key);
 }
 return &di->item.ptr;
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

void *ZDictGetPtrDef(Td *d, Tz key, void *def) {
 void *r;
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) r = di->item.ptr;
 else r = def;
 return r;
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

Ti ZDictSize(Td *d) {
 if (d == NULL) return 0;
 return d->used;
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
 Zhashtype hash;
 CDictItem *di;
 if (d == NULL) ZthrowCstringNil("Adding item to NIL dict");
 hash = ZDictHash(d->keyType, key);
 di = ZDictLookup(d, key, hash);
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
void YxaJ(Ytlm *t, Tr Aw) { /* MEModule__CException.writeTo */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4918300;
  ZthrowThisNil();
 }
 sf.pos=4918301;
 if ((t->Vpos != NULL))
 {
  sf.pos=4918302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_((YkxB *)t->Vpos));
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
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw) { /* MEModule__CException.writeTo */
 Zsf sf={0,topFrame};
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3649100;
  ZthrowThisNil();
 }
 sf.pos=3649101;
 ((void (*)(void*, Tr))(t->mt[7]))(t, Aw);
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
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_((YkxB *)Vpos));
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
Tc *Ytlm__mt[] = {
 (Tc*)&Ytlm__T,
 (Tc*)0,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CException.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CException.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CException.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CException.toString - Yoww */
 (Tc*)0, /* MEModule__CException.getMessage - YCzX */
 (Tc*)0, /* MEModule__CException.getPos - YvCK */
 (Tc*)0, /* MEModule__CException.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Ytlma */
};
To ToYtlm[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Ytlm__T = {390, (Tc*)&YDGe, 0, ToYtlm};
void YXHSa(YEro *t, Tr Aw) { /* MEModule__CExit.writeTo */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9216300;
  ZthrowThisNil();
 }
 sf.pos=9216301;
 if ((t->Vpos != NULL))
 {
  sf.pos=9216302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_((YkxB *)t->Vpos));
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
Tc *YEro__mt[] = {
 (Tc*)&YEro__T,
 (Tc*)1,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CExit.ToString - Ydtua */
 (Tc*)YxaJa, /* MEModule__CExit.writeTo - YxaJa */
 (Tc*)YXHSa, /* MEModule__CExit.writeTo - YXHSa */
 (Tc*)0, /* MEModule__CExit.toString - Yoww */
 (Tc*)0, /* MEModule__CExit.getMessage - YCzX */
 (Tc*)0, /* MEModule__CExit.getPos - YvCK */
 (Tc*)0, /* MEModule__CExit.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YEroa */
 (Tc*)0, /* MEModule__CExit.ToString - Ydtua */
 (Tc*)0, /* MEModule__CExit.toString - Yoww */
 (Tc*)0, /* MEModule__CExit.getMessage - YCzX */
 (Tc*)0, /* MEModule__CExit.getBacktrace - Y4bq */
 (Tc*)0, /* Vvalue */
 (Tc*)YxaJa, /* MEModule__CExit.writeTo - YxaJa */
 (Tc*)YXHSa, /* MEModule__CExit.writeTo - YXHSa */
 (Tc*)0, /* MEModule__CExit.getValue - YZSK */
 (Tc*)0, /* Init - YEroa */
 (Tc*)0, /* MEModule__CExit.getPos - YvCK */
};
To ToYEro[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YEro__T = {390, (Tc*)&YJMo, 0, ToYEro};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit) { /* MEModule__COutOfMemory.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=8064400; t = Zamt(sizeof(YKhn), YKhn__mt);}
 sf.pos=8064401;
 t->Vmessage = ZcS3(((Tc*)&YIBz), Zint2string(Asize), ((Tc*)&YDSH));
 sf.pos=8064402;
 t->Vpos = MZ__callerPos();
 sf.pos=8064403;
 t->Vbacktrace = (sf.pos=8064404, MZ__backtrace(1, Alimit));
 topFrame = sf.prev;
 return t;
}
Tc *YKhn__mt[] = {
 (Tc*)&YKhn__T,
 (Tc*)4,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__COutOfMemory.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__COutOfMemory.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__COutOfMemory.writeTo - YxaJ */
 (Tc*)0, /* MEModule__COutOfMemory.toString - Yoww */
 (Tc*)0, /* MEModule__COutOfMemory.getMessage - YCzX */
 (Tc*)0, /* MEModule__COutOfMemory.getPos - YvCK */
 (Tc*)0, /* MEModule__COutOfMemory.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YKhna */
 (Tc*)0, /* MEModule__COutOfMemory.ToString - YH0V */
 (Tc*)0, /* MEModule__COutOfMemory.toString - Yoww */
 (Tc*)0, /* MEModule__COutOfMemory.getMessage - YCzX */
 (Tc*)0, /* MEModule__COutOfMemory.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YKhna */
 (Tc*)YxaJ, /* MEModule__COutOfMemory.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__COutOfMemory.writeTo - YxaJa */
 (Tc*)0, /* MEModule__COutOfMemory.getPos - YvCK */
 (Tc*)0, /* MEModule__COutOfMemory.ToString - YH0V */
 (Tc*)0, /* MEModule__COutOfMemory.toString - Yoww */
 (Tc*)0, /* MEModule__COutOfMemory.getMessage - YCzX */
 (Tc*)0, /* MEModule__COutOfMemory.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YKhna */
 (Tc*)YxaJa, /* MEModule__COutOfMemory.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__COutOfMemory.writeTo - YxaJ */
 (Tc*)0, /* MEModule__COutOfMemory.getPos - YvCK */
};
To ToYKhn[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YKhn__T = {390, (Tc*)&Y9Fv, 0, ToYKhn};
void Y1KV(Ti Asize) { /* MEModule.throwOutOfMemorySize */
 Ytlm *ex;
 ex = (Ytlm*)YDNob(NULL, Asize, 30);
 ZthrowIobject(ex);
}
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg) { /* MEModule__CNilAccess.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=3208600; t = Zamt(sizeof(Y1uN), Y1uN__mt);}
 sf.pos=3208601;
 t->Vmessage = Amsg;
 sf.pos=3208602;
 t->Vpos = MZ__callerPos();
 sf.pos=3208603;
 t->Vbacktrace = (sf.pos=3208604, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Y1uN__mt[] = {
 (Tc*)&Y1uN__T,
 (Tc*)5,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CNilAccess.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CNilAccess.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CNilAccess.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CNilAccess.toString - Yoww */
 (Tc*)0, /* MEModule__CNilAccess.getMessage - YCzX */
 (Tc*)0, /* MEModule__CNilAccess.getPos - YvCK */
 (Tc*)0, /* MEModule__CNilAccess.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Y1uNa */
 (Tc*)0, /* MEModule__CNilAccess.ToString - YH0V */
 (Tc*)0, /* MEModule__CNilAccess.toString - Yoww */
 (Tc*)0, /* MEModule__CNilAccess.getMessage - YCzX */
 (Tc*)0, /* MEModule__CNilAccess.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Y1uNa */
 (Tc*)YxaJ, /* MEModule__CNilAccess.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CNilAccess.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CNilAccess.getPos - YvCK */
 (Tc*)0, /* MEModule__CNilAccess.ToString - YH0V */
 (Tc*)0, /* MEModule__CNilAccess.toString - Yoww */
 (Tc*)0, /* MEModule__CNilAccess.getMessage - YCzX */
 (Tc*)0, /* MEModule__CNilAccess.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Y1uNa */
 (Tc*)YxaJa, /* MEModule__CNilAccess.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CNilAccess.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CNilAccess.getPos - YvCK */
};
To ToY1uN[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Y1uN__T = {390, (Tc*)&Y4wO, 0, ToY1uN};
void YvdV(YkxB *Apos, Tc *Atext) { /* MEModule.throwNil */
 Ytlm *ex;
 Y1uN *Ve = 0;
 Ve = Y1uN__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 ex = (Ytlm*)Ve;
 ZthrowIobject(ex);
}
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg) { /* MEModule__CMemoryAccess.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=7358000; t = Zamt(sizeof(YAxe), YAxe__mt);}
 sf.pos=7358001;
 t->Vmessage = Amsg;
 sf.pos=7358002;
 t->Vpos = MZ__callerPos();
 sf.pos=7358003;
 t->Vbacktrace = (sf.pos=7358004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YAxe__mt[] = {
 (Tc*)&YAxe__T,
 (Tc*)6,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CMemoryAccess.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CMemoryAccess.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CMemoryAccess.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CMemoryAccess.toString - Yoww */
 (Tc*)0, /* MEModule__CMemoryAccess.getMessage - YCzX */
 (Tc*)0, /* MEModule__CMemoryAccess.getPos - YvCK */
 (Tc*)0, /* MEModule__CMemoryAccess.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YAxea */
 (Tc*)0, /* MEModule__CMemoryAccess.ToString - YH0V */
 (Tc*)0, /* MEModule__CMemoryAccess.toString - Yoww */
 (Tc*)0, /* MEModule__CMemoryAccess.getMessage - YCzX */
 (Tc*)0, /* MEModule__CMemoryAccess.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YAxea */
 (Tc*)YxaJ, /* MEModule__CMemoryAccess.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CMemoryAccess.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CMemoryAccess.getPos - YvCK */
 (Tc*)0, /* MEModule__CMemoryAccess.ToString - YH0V */
 (Tc*)0, /* MEModule__CMemoryAccess.toString - Yoww */
 (Tc*)0, /* MEModule__CMemoryAccess.getMessage - YCzX */
 (Tc*)0, /* MEModule__CMemoryAccess.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YAxea */
 (Tc*)YxaJa, /* MEModule__CMemoryAccess.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CMemoryAccess.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CMemoryAccess.getPos - YvCK */
};
To ToYAxe[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YAxe__T = {390, (Tc*)&Y4QW, 0, ToYAxe};
void YE93(Ti Anr) { /* MEModule.throwDeadly */
 Ytlm *ex;
 if ((Anr == 11))
 {
  Ytlm *ex;
  ex = (Ytlm*)YAxe__YwtA__YRHR(NULL, ((Tc*)&YkfG));
  ZthrowIobject(ex);
 }
 if ((Anr == 8))
 {
  Ytlm *ex;
  ex = (Ytlm*)YzSI__Ylz1__YwtA__YRHR(NULL, ((Tc*)&YoEx));
  ZthrowIobject(ex);
 }
 if ((Anr == 7))
 {
  Ytlm *ex;
  ex = (Ytlm*)YAxe__YwtA__YRHR(NULL, ((Tc*)&YQNH));
  ZthrowIobject(ex);
 }
 ex = (Ytlm*)YAxe__YwtA__YRHR(NULL, ZcS(((Tc*)&YpCZ), Zint2string(Anr)));
 ZthrowIobject(ex);
}
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg) { /* MEModule__CInit.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=6357800; t = Zamt(sizeof(YVNj), YVNj__mt);}
 sf.pos=6357801;
 t->Vmessage = Amsg;
 sf.pos=6357802;
 t->Vpos = Apos;
 sf.pos=6357803;
 t->Vbacktrace = (sf.pos=6357804, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg) { /* MEModule__CInit.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=5337700; t = Zamt(sizeof(YVNj), YVNj__mt);}
 sf.pos=5337701;
 t->Vmessage = Amsg;
 sf.pos=5337702;
 t->Vpos = MZ__callerPos();
 sf.pos=5337703;
 t->Vbacktrace = (sf.pos=5337704, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YVNj__mt[] = {
 (Tc*)&YVNj__T,
 (Tc*)7,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CInit.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CInit.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CInit.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CInit.toString - Yoww */
 (Tc*)0, /* MEModule__CInit.getMessage - YCzX */
 (Tc*)0, /* MEModule__CInit.getPos - YvCK */
 (Tc*)0, /* MEModule__CInit.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YVNja */
 (Tc*)0, /* MEModule__CInit.ToString - YH0V */
 (Tc*)0, /* MEModule__CInit.toString - Yoww */
 (Tc*)0, /* MEModule__CInit.getMessage - YCzX */
 (Tc*)0, /* MEModule__CInit.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YVNja */
 (Tc*)YxaJ, /* MEModule__CInit.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CInit.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CInit.getPos - YvCK */
 (Tc*)0, /* MEModule__CInit.ToString - YH0V */
 (Tc*)0, /* MEModule__CInit.toString - Yoww */
 (Tc*)0, /* MEModule__CInit.getMessage - YCzX */
 (Tc*)0, /* MEModule__CInit.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YVNja */
 (Tc*)YxaJa, /* MEModule__CInit.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CInit.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CInit.getPos - YvCK */
};
To ToYVNj[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YVNj__T = {390, (Tc*)&Ysqt, 0, ToYVNj};
void Y3w6(Tc *Atext) { /* MEModule.throwInit */
 Ytlm *ex;
 ex = (Ytlm*)YVNj__YwtA__YRHR(NULL, Atext);
 ZthrowIobject(ex);
}
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg) { /* MEModule__CBadValue.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=6059300; t = Zamt(sizeof(Yalz), Yalz__mt);}
 sf.pos=6059301;
 t->Vmessage = Amsg;
 sf.pos=6059302;
 t->Vpos = MZ__callerPos();
 sf.pos=6059303;
 t->Vbacktrace = (sf.pos=6059304, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Yalz__mt[] = {
 (Tc*)&Yalz__T,
 (Tc*)10,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CBadValue.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CBadValue.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CBadValue.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CBadValue.toString - Yoww */
 (Tc*)0, /* MEModule__CBadValue.getMessage - YCzX */
 (Tc*)0, /* MEModule__CBadValue.getPos - YvCK */
 (Tc*)0, /* MEModule__CBadValue.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Yalza */
 (Tc*)0, /* MEModule__CBadValue.ToString - YH0V */
 (Tc*)0, /* MEModule__CBadValue.toString - Yoww */
 (Tc*)0, /* MEModule__CBadValue.getMessage - YCzX */
 (Tc*)0, /* MEModule__CBadValue.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Yalza */
 (Tc*)YxaJ, /* MEModule__CBadValue.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CBadValue.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CBadValue.getPos - YvCK */
 (Tc*)0, /* MEModule__CBadValue.ToString - YH0V */
 (Tc*)0, /* MEModule__CBadValue.toString - Yoww */
 (Tc*)0, /* MEModule__CBadValue.getMessage - YCzX */
 (Tc*)0, /* MEModule__CBadValue.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Yalza */
 (Tc*)YxaJa, /* MEModule__CBadValue.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CBadValue.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CBadValue.getPos - YvCK */
};
To ToYalz[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Yalz__T = {390, (Tc*)&YEZq, 0, ToYalz};
void Yaez(Tc *Atext) { /* MEModule.throwBadValue */
 Ytlm *ex;
 ex = (Ytlm*)Yalz__YwtA__YRHR(NULL, Atext);
 ZthrowIobject(ex);
}
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg) { /* MEModule__COutOfRange.NEW__p3 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=5638100; t = Zamt(sizeof(Yw3O), Yw3O__mt);}
 sf.pos=5638101;
 t->Vmessage = Amsg;
 sf.pos=5638102;
 t->Vpos = MZ__callerPos();
 sf.pos=5638103;
 t->Vbacktrace = (sf.pos=5638104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Yw3O__mt[] = {
 (Tc*)&Yw3O__T,
 (Tc*)11,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__COutOfRange.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__COutOfRange.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__COutOfRange.writeTo - YxaJ */
 (Tc*)0, /* MEModule__COutOfRange.toString - Yoww */
 (Tc*)0, /* MEModule__COutOfRange.getMessage - YCzX */
 (Tc*)0, /* MEModule__COutOfRange.getPos - YvCK */
 (Tc*)0, /* MEModule__COutOfRange.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Yw3Oa */
 (Tc*)0, /* MEModule__COutOfRange.ToString - YH0V */
 (Tc*)0, /* MEModule__COutOfRange.toString - Yoww */
 (Tc*)0, /* MEModule__COutOfRange.getMessage - YCzX */
 (Tc*)0, /* MEModule__COutOfRange.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Yw3Oa */
 (Tc*)YxaJ, /* MEModule__COutOfRange.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__COutOfRange.writeTo - YxaJa */
 (Tc*)0, /* MEModule__COutOfRange.getPos - YvCK */
 (Tc*)0, /* MEModule__COutOfRange.ToString - YH0V */
 (Tc*)0, /* MEModule__COutOfRange.toString - Yoww */
 (Tc*)0, /* MEModule__COutOfRange.getMessage - YCzX */
 (Tc*)0, /* MEModule__COutOfRange.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Yw3Oa */
 (Tc*)YxaJa, /* MEModule__COutOfRange.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__COutOfRange.writeTo - YxaJ */
 (Tc*)0, /* MEModule__COutOfRange.getPos - YvCK */
 (Tc*)0, /* MEModule__COutOfRange.ToString - YH0V */
 (Tc*)0, /* MEModule__COutOfRange.toString - Yoww */
 (Tc*)0, /* MEModule__COutOfRange.getMessage - YCzX */
 (Tc*)0, /* MEModule__COutOfRange.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Yw3Oa */
 (Tc*)YxaJ, /* MEModule__COutOfRange.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__COutOfRange.writeTo - YxaJa */
 (Tc*)0, /* MEModule__COutOfRange.getPos - YvCK */
};
To ToYw3O[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Yw3O__T = {390, (Tc*)&YFK2a, 0, ToYw3O};
void Y6NT(Ti Aindex, Tc *Amsg) { /* MEModule.throwOutOfRange */
 Ytlm *ex;
 ex = (Ytlm*)Yw3O__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&YFDa), Zint2string(Aindex)));
 ZthrowIobject(ex);
}
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg) { /* MEModule__CKeyNotFound.NEW__p3 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=2958500; t = Zamt(sizeof(Y2EX), Y2EX__mt);}
 sf.pos=2958501;
 t->Vmessage = Amsg;
 sf.pos=2958502;
 t->Vpos = MZ__callerPos();
 sf.pos=2958503;
 t->Vbacktrace = (sf.pos=2958504, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Y2EX__mt[] = {
 (Tc*)&Y2EX__T,
 (Tc*)12,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CKeyNotFound.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CKeyNotFound.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CKeyNotFound.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CKeyNotFound.toString - Yoww */
 (Tc*)0, /* MEModule__CKeyNotFound.getMessage - YCzX */
 (Tc*)0, /* MEModule__CKeyNotFound.getPos - YvCK */
 (Tc*)0, /* MEModule__CKeyNotFound.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Y2EXa */
 (Tc*)0, /* MEModule__CKeyNotFound.ToString - YH0V */
 (Tc*)0, /* MEModule__CKeyNotFound.toString - Yoww */
 (Tc*)0, /* MEModule__CKeyNotFound.getMessage - YCzX */
 (Tc*)0, /* MEModule__CKeyNotFound.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Y2EXa */
 (Tc*)YxaJ, /* MEModule__CKeyNotFound.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CKeyNotFound.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CKeyNotFound.getPos - YvCK */
 (Tc*)0, /* MEModule__CKeyNotFound.ToString - YH0V */
 (Tc*)0, /* MEModule__CKeyNotFound.toString - Yoww */
 (Tc*)0, /* MEModule__CKeyNotFound.getMessage - YCzX */
 (Tc*)0, /* MEModule__CKeyNotFound.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Y2EXa */
 (Tc*)YxaJa, /* MEModule__CKeyNotFound.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CKeyNotFound.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CKeyNotFound.getPos - YvCK */
 (Tc*)0, /* MEModule__CKeyNotFound.ToString - YH0V */
 (Tc*)0, /* MEModule__CKeyNotFound.toString - Yoww */
 (Tc*)0, /* MEModule__CKeyNotFound.getMessage - YCzX */
 (Tc*)0, /* MEModule__CKeyNotFound.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Y2EXa */
 (Tc*)YxaJ, /* MEModule__CKeyNotFound.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CKeyNotFound.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CKeyNotFound.getPos - YvCK */
};
To ToY2EX[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Y2EX__T = {390, (Tc*)&YRiW, 0, ToY2EX};
void Yxmk(Ti Akey, Tc *Amsg) { /* MEModule.throwIntKeyNotFound */
 Ytlm *ex;
 ex = (Ytlm*)Y2EX__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Ym6C), Zint2string(Akey)));
 ZthrowIobject(ex);
}
void Y5LT(Tc *Akey, Tc *Amsg) { /* MEModule.throwStringKeyNotFound */
 Ytlm *ex;
 ex = (Ytlm*)Y2EX__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YJ3Y), Akey, ((Tc*)&YI), (Tc*)1));
 ZthrowIobject(ex);
}
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg) { /* MEModule__CKeyExists.NEW__p3 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=8500000; t = Zamt(sizeof(YX0i), YX0i__mt);}
 sf.pos=8500001;
 t->Vmessage = Amsg;
 sf.pos=8500002;
 t->Vpos = MZ__callerPos();
 sf.pos=8500003;
 t->Vbacktrace = (sf.pos=8500004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YX0i__mt[] = {
 (Tc*)&YX0i__T,
 (Tc*)14,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CKeyExists.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CKeyExists.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CKeyExists.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CKeyExists.toString - Yoww */
 (Tc*)0, /* MEModule__CKeyExists.getMessage - YCzX */
 (Tc*)0, /* MEModule__CKeyExists.getPos - YvCK */
 (Tc*)0, /* MEModule__CKeyExists.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YX0ia */
 (Tc*)0, /* MEModule__CKeyExists.ToString - YH0V */
 (Tc*)0, /* MEModule__CKeyExists.toString - Yoww */
 (Tc*)0, /* MEModule__CKeyExists.getMessage - YCzX */
 (Tc*)0, /* MEModule__CKeyExists.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YX0ia */
 (Tc*)YxaJ, /* MEModule__CKeyExists.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CKeyExists.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CKeyExists.getPos - YvCK */
 (Tc*)0, /* MEModule__CKeyExists.ToString - YH0V */
 (Tc*)0, /* MEModule__CKeyExists.toString - Yoww */
 (Tc*)0, /* MEModule__CKeyExists.getMessage - YCzX */
 (Tc*)0, /* MEModule__CKeyExists.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YX0ia */
 (Tc*)YxaJa, /* MEModule__CKeyExists.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CKeyExists.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CKeyExists.getPos - YvCK */
 (Tc*)0, /* MEModule__CKeyExists.ToString - YH0V */
 (Tc*)0, /* MEModule__CKeyExists.toString - Yoww */
 (Tc*)0, /* MEModule__CKeyExists.getMessage - YCzX */
 (Tc*)0, /* MEModule__CKeyExists.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YX0ia */
 (Tc*)YxaJ, /* MEModule__CKeyExists.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CKeyExists.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CKeyExists.getPos - YvCK */
};
To ToYX0i[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YX0i__T = {390, (Tc*)&Y9_h, 0, ToYX0i};
void YL9Z(Ti Akey, Tc *Amsg) { /* MEModule.throwIntKeyExists */
 Ytlm *ex;
 ex = (Ytlm*)YX0i__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Y9qa), Zint2string(Akey)));
 ZthrowIobject(ex);
}
void YEeX(Tc *Akey, Tc *Amsg) { /* MEModule.throwStringKeyExists */
 Ytlm *ex;
 ex = (Ytlm*)YX0i__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YMKM), Akey, ((Tc*)&YI), (Tc*)1));
 ZthrowIobject(ex);
}
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg) { /* MEModule__CDivideByZero.NEW__p3 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=7347100; t = Zamt(sizeof(YzSI), YzSI__mt);}
 sf.pos=7347101;
 t->Vmessage = Amsg;
 sf.pos=7347102;
 t->Vpos = MZ__callerPos();
 sf.pos=7347103;
 t->Vbacktrace = (sf.pos=7347104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YzSI__mt[] = {
 (Tc*)&YzSI__T,
 (Tc*)17,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CDivideByZero.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CDivideByZero.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CDivideByZero.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CDivideByZero.toString - Yoww */
 (Tc*)0, /* MEModule__CDivideByZero.getMessage - YCzX */
 (Tc*)0, /* MEModule__CDivideByZero.getPos - YvCK */
 (Tc*)0, /* MEModule__CDivideByZero.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YzSIa */
 (Tc*)0, /* MEModule__CDivideByZero.ToString - YH0V */
 (Tc*)0, /* MEModule__CDivideByZero.toString - Yoww */
 (Tc*)0, /* MEModule__CDivideByZero.getMessage - YCzX */
 (Tc*)0, /* MEModule__CDivideByZero.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YzSIa */
 (Tc*)YxaJ, /* MEModule__CDivideByZero.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CDivideByZero.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CDivideByZero.getPos - YvCK */
 (Tc*)0, /* MEModule__CDivideByZero.ToString - YH0V */
 (Tc*)0, /* MEModule__CDivideByZero.toString - Yoww */
 (Tc*)0, /* MEModule__CDivideByZero.getMessage - YCzX */
 (Tc*)0, /* MEModule__CDivideByZero.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YzSIa */
 (Tc*)YxaJa, /* MEModule__CDivideByZero.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CDivideByZero.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CDivideByZero.getPos - YvCK */
 (Tc*)0, /* MEModule__CDivideByZero.ToString - YH0V */
 (Tc*)0, /* MEModule__CDivideByZero.toString - Yoww */
 (Tc*)0, /* MEModule__CDivideByZero.getMessage - YCzX */
 (Tc*)0, /* MEModule__CDivideByZero.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YzSIa */
 (Tc*)YxaJ, /* MEModule__CDivideByZero.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CDivideByZero.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CDivideByZero.getPos - YvCK */
};
To ToYzSI[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YzSI__T = {390, (Tc*)&YxFl, 0, ToYzSI};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg) { /* MEModule__CIOError.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=4829900; t = Zamt(sizeof(YXKl), YXKl__mt);}
 sf.pos=4829901;
 t->Vmessage = Amsg;
 sf.pos=4829902;
 t->Vpos = MZ__callerPos();
 sf.pos=4829903;
 t->Vbacktrace = (sf.pos=4829904, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YXKl__mt[] = {
 (Tc*)&YXKl__T,
 (Tc*)19,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CIOError.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CIOError.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CIOError.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CIOError.toString - Yoww */
 (Tc*)0, /* MEModule__CIOError.getMessage - YCzX */
 (Tc*)0, /* MEModule__CIOError.getPos - YvCK */
 (Tc*)0, /* MEModule__CIOError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YXKla */
 (Tc*)0, /* MEModule__CIOError.ToString - YH0V */
 (Tc*)0, /* MEModule__CIOError.toString - Yoww */
 (Tc*)0, /* MEModule__CIOError.getMessage - YCzX */
 (Tc*)0, /* MEModule__CIOError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YXKla */
 (Tc*)YxaJ, /* MEModule__CIOError.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CIOError.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CIOError.getPos - YvCK */
 (Tc*)0, /* MEModule__CIOError.ToString - YH0V */
 (Tc*)0, /* MEModule__CIOError.toString - Yoww */
 (Tc*)0, /* MEModule__CIOError.getMessage - YCzX */
 (Tc*)0, /* MEModule__CIOError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YXKla */
 (Tc*)YxaJa, /* MEModule__CIOError.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CIOError.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CIOError.getPos - YvCK */
};
To ToYXKl[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YXKl__T = {390, (Tc*)&YTj3, 0, ToYXKl};
void YkuV(Tc *Amsg) { /* MEModule.throwIOError */
 Ytlm *ex;
 ex = (Ytlm*)YXKl__YwtA__YRHR(NULL, Amsg);
 ZthrowIobject(ex);
}
YuDC *YdhH(YuDC *t) { /* MEModule__CWrongType.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=8723500; t = Zamt(sizeof(YuDC), YuDC__mt);}
 sf.pos=8723501;
 t->Vmessage = ((Tc*)&Ynjz);
 sf.pos=8723502;
 t->Vpos = MZ__callerPos();
 sf.pos=8723503;
 t->Vbacktrace = (sf.pos=8723504, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YuDC__mt[] = {
 (Tc*)&YuDC__T,
 (Tc*)24,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CWrongType.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CWrongType.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CWrongType.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CWrongType.toString - Yoww */
 (Tc*)0, /* MEModule__CWrongType.getMessage - YCzX */
 (Tc*)0, /* MEModule__CWrongType.getPos - YvCK */
 (Tc*)0, /* MEModule__CWrongType.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YuDCa */
 (Tc*)0, /* MEModule__CWrongType.ToString - YH0V */
 (Tc*)0, /* MEModule__CWrongType.toString - Yoww */
 (Tc*)0, /* MEModule__CWrongType.getMessage - YCzX */
 (Tc*)0, /* MEModule__CWrongType.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YuDCa */
 (Tc*)YxaJ, /* MEModule__CWrongType.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CWrongType.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CWrongType.getPos - YvCK */
 (Tc*)0, /* MEModule__CWrongType.ToString - YH0V */
 (Tc*)0, /* MEModule__CWrongType.toString - Yoww */
 (Tc*)0, /* MEModule__CWrongType.getMessage - YCzX */
 (Tc*)0, /* MEModule__CWrongType.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YuDCa */
 (Tc*)YxaJa, /* MEModule__CWrongType.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CWrongType.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CWrongType.getPos - YvCK */
};
To ToYuDC[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YuDC__T = {390, (Tc*)&YCoZ, 0, ToYuDC};
void YTuG(Ti Apos) { /* MEModule.throwWrongType */
 Ytlm *ex;
 YuDC *Ve = 0;
 Ve = YdhH(NULL);
 Ve->Vpos = MZ__posnr2pos(NULL, Apos);
 ex = (Ytlm*)Ve;
 ZthrowIobject(ex);
}
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg) { /* MEModule__CInternal.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=7808200; t = Zamt(sizeof(YrHq), YrHq__mt);}
 sf.pos=7808201;
 t->Vmessage = Amsg;
 sf.pos=7808202;
 t->Vpos = MZ__callerPos();
 sf.pos=7808203;
 t->Vbacktrace = (sf.pos=7808204, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YrHq__mt[] = {
 (Tc*)&YrHq__T,
 (Tc*)26,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CInternal.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CInternal.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CInternal.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CInternal.toString - Yoww */
 (Tc*)0, /* MEModule__CInternal.getMessage - YCzX */
 (Tc*)0, /* MEModule__CInternal.getPos - YvCK */
 (Tc*)0, /* MEModule__CInternal.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YrHqa */
 (Tc*)0, /* MEModule__CInternal.ToString - YH0V */
 (Tc*)0, /* MEModule__CInternal.toString - Yoww */
 (Tc*)0, /* MEModule__CInternal.getMessage - YCzX */
 (Tc*)0, /* MEModule__CInternal.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YrHqa */
 (Tc*)YxaJ, /* MEModule__CInternal.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CInternal.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CInternal.getPos - YvCK */
 (Tc*)0, /* MEModule__CInternal.ToString - YH0V */
 (Tc*)0, /* MEModule__CInternal.toString - Yoww */
 (Tc*)0, /* MEModule__CInternal.getMessage - YCzX */
 (Tc*)0, /* MEModule__CInternal.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YrHqa */
 (Tc*)YxaJa, /* MEModule__CInternal.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CInternal.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CInternal.getPos - YvCK */
};
To ToYrHq[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YrHq__T = {390, (Tc*)&YVki, 0, ToYrHq};
void YUSH(YkxB *Apos, Tc *Atext) { /* MEModule.throwInternal */
 Ytlm *ex;
 YrHq *Ve = 0;
 Ve = YrHq__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 ex = (Ytlm*)Ve;
 ZthrowIobject(ex);
}
void YxIS(Ytlm *Ae) { /* MEModule.unhandledException */
      static int entered = 0;
      int didEnter = entered;
      entered = 1;
 if (ZxobjIsa(Ae, 1))
 {
  Ti VexitVal;
  VexitVal = ((YEro *)Znip(&YEro__T, 1571802, (Ae)))->Vvalue;
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
void YvL0(Ytlm *Ae) { /* MEModule.writeToStderr */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 sf.pos=5238600;
 Ylxt();
 sf.pos=5238601;
 YQar(Ae, 1, YeNQ);
 sf.pos=5238603;
 Yw8L__YRt7g((Yw8L *)YeNQ);
 topFrame = sf.prev;
 return;
}
void YQar(Ytlm *A0, Tb A1, Yw8L *A2) {
   YxaJa((void*)A0,A1,ZconvertZiopref(A2, YdXi__imtt, 0, 99998, 5238602));
}
/* EModule done */
/* including SYSModule bodies */
Tc *Yhy5(Tc *Aname) { /* MSYSModule.getEnv */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tc *Vres = NULL;
 topFrame = &sf;
 sf.pos=4232300;
 Vres = (Tc*)getenv(ZgetCstring(Aname));
 if (Vres != NULL) Vres = Zstr((char*)Vres);
 sf.pos=4232301;
 r = Vres;
 topFrame = sf.prev;
 return r;
}
/* SYSModule done */
/* including BYTESTRINGModule bodies */
Tc *YlD8(Tc *Athis) { /* MBYTESTRINGModule.ToString */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tc *Zf1 = NULL;
 YjUM *Vw = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=7919200;
 if (Athis == NULL)
 {
  sf.pos=7919201;
  r = NULL;
  rt = 1;
  goto Y9R8;
 }
 sf.pos=7919202;
 Vw = Zamt(sizeof(YjUM), YjUM__mt);
 sf.pos=7919203;
 {
  Ti Vc;
  Tfs iZf1;
  Zf1 = Athis;
  ZforBytestringNew(Zf1, &iZf1);
  for (ZforBytestringGetInt(&iZf1, &Vc); ZforBytestringContInt(&iZf1); ZforBytestringNextInt(&iZf1, &Vc)) {
  sf.pos=7919204;
  YJqza((YjUM *)Vw, ZintAsString(Vc));
  sf.pos=7919205;
  }
 }
 sf.pos=7919206;
 r = YbNW((YjUM *)Vw);
Y9R8:
 topFrame = sf.prev;
 return r;
}
Tc *YyEq(Tc *Athis) { /* MBYTESTRINGModule.latin1ToString */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=377700;
 if (Athis == NULL)
 {
  sf.pos=377701;
  r = NULL;
  rt = 1;
  goto YF7Q;
 }
 sf.pos=377702;
 r = YlD8(Athis);
YF7Q:
 topFrame = sf.prev;
 return r;
}
/* BYTESTRINGModule done */
/* including ZModule bodies */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) { /* MZModule__CPos.NEW */
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 return t;
}
Tc *YpI_(YkxB *t) { /* MZModule__CPos.ToString */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 YjUM *Vw = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1818700;
  ZthrowThisNil();
 }
 sf.pos=1818701;
 Vw = Zamt(sizeof(YjUM), YjUM__mt);
 sf.pos=1818702;
 if ((t->Vfilename == NULL))
 {
  sf.pos=1818703;
  YJqza((YjUM *)Vw, ((Tc*)&YKo1));
 }
 else
 {
  sf.pos=1818704;
  YJqza((YjUM *)Vw, t->Vfilename);
 }
 sf.pos=1818705;
 YJqza((YjUM *)Vw, ((Tc*)&YBpY));
 sf.pos=1818706;
 YjUM__YHhZb((YjUM *)Vw, t->Vlnum);
 sf.pos=1818707;
 YJqza((YjUM *)Vw, ((Tc*)&Y8ES));
 sf.pos=1818708;
 YjUM__YHhZb((YjUM *)Vw, t->Vcol);
 sf.pos=1818709;
 r = YbNW((YjUM *)Vw);
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
/* including STRINGModule bodies */
Tc *Yvnf(Tc *Athis, Ti Afrom, Ti Ato) { /* MSTRINGModule.replaceAll */
 Ti Vi;
 Zsf sf={0,topFrame};
 Tc *r = 0;
 YjUM *Vw = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=1203500;
 if (Athis == NULL)
 {
  sf.pos=1203501;
  r = NULL;
  rt = 1;
  goto YIVu;
 }
 sf.pos=1203502;
 Vi = ZstringFindChar(Athis, Afrom, 0);
 sf.pos=1203503;
 if ((Vi >= 0))
 {
  Ti VnextChar;
  VnextChar = 0;
  sf.pos=1203504;
  Vw = Zamt(sizeof(YjUM), YjUM__mt);
  sf.pos=1203505;
  while ((Vi >= 0))
  {
   sf.pos=1203506;
   if ((Vi > VnextChar))
   {
    sf.pos=1203507;
    YJqza((YjUM *)Vw, YuALa(Athis, VnextChar, (Vi - 1)));
   }
   sf.pos=1203508;
   YjUM__Ydti((YjUM *)Vw, Ato);
   sf.pos=1203509;
   VnextChar = (Vi + 1);
   sf.pos=1203510;
   Vi = ZstringFindChar2(Athis, Afrom, VnextChar, 0);
  sf.pos=1203511;
  }
  sf.pos=1203512;
  YJqza((YjUM *)Vw, YuAL(Athis, VnextChar));
  sf.pos=1203513;
  r = YbNW((YjUM *)Vw);
  rt = 1;
  goto YIVu;
 }
 sf.pos=1203514;
 r = Athis;
YIVu:
 topFrame = sf.prev;
 return r;
}
Tc *YuAL(Tc *Athis, Ti Astart) { /* MSTRINGModule.slice */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=5061400;
 if (Athis == NULL)
 {
  sf.pos=5061401;
  r = NULL;
  rt = 1;
  goto YWxy;
 }
 sf.pos=5061402;
 r = ZstringSliceWrap(Athis, (((Astart < 0)) ? (0) : (Astart)), -1);
YWxy:
 topFrame = sf.prev;
 return r;
}
Tc *YuALa(Tc *Athis, Ti Astart, Ti Aend) { /* MSTRINGModule.slice */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=6359400;
 if (Athis == NULL)
 {
  sf.pos=6359401;
  r = NULL;
  rt = 1;
  goto Yi5H;
 }
 sf.pos=6359402;
 if ((Aend < 0))
 {
  sf.pos=6359403;
  r = ((Tc*)&Ya);
  rt = 1;
  goto Yi5H;
 }
 sf.pos=6359404;
 r = ZstringSliceWrap(Athis, (((Astart < 0)) ? (0) : (Astart)), Aend);
Yi5H:
 topFrame = sf.prev;
 return r;
}
/* STRINGModule done */
/* including IOModule bodies */
Yw8L *Yd89() { /* MIOModule.newStdin */
 Yw8L *r = 0;
 Yw8L *Vfile = NULL;
 Vfile = (Yw8L*)Zamt(sizeof(Yw8L), Yw8L__mt);
 (*(FILE **)((Tc*)Vfile + (size_t)Vfile->mt[41])) = stdin;
 r = Vfile;
 return r;
}
Yw8L *Yvyt() { /* MIOModule.newStdout */
 Yw8L *r = 0;
 Yw8L *Vfile = NULL;
 Vfile = (Yw8L*)Zamt(sizeof(Yw8L), Yw8L__mt);
 (*(FILE **)((Tc*)Vfile + (size_t)Vfile->mt[41])) = stdout;
 r = Vfile;
 return r;
}
Yw8L *YsM3() { /* MIOModule.newStderr */
 Yw8L *r = 0;
 Yw8L *Vfile = NULL;
 Vfile = (Yw8L*)Zamt(sizeof(Yw8L), Yw8L__mt);
 (*(FILE **)((Tc*)Vfile + (size_t)Vfile->mt[41])) = stderr;
 r = Vfile;
 return r;
}
Tc **YdXi__imtt[] = {
  Yw8L__YdXi_imt,
    0,
  YjUM__YdXi_imt,
    0,
};
Ts YwHoa(Yw8L *t, Tc *Atext) { /* MIOModule__CFile.write */
 Ts Vret;
 Zsf sf={0,topFrame};
 Ts r = 0;
 Tc *Vbrtext = NULL;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9482300;
  ZthrowThisNil();
 }
 Vret = 0;
 sf.pos=9482301;
 if ((t->Vfd == NULL))
 {
  Ytlm *ex;
  sf.pos=9482302;
  ex = (Ytlm*)YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8));
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
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext) { /* MIOModule__CFile.print__p1 */
 Zsf sf={0,topFrame};
 Ts r = 0;
 int rt = 0;
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
Ts Yw8L__YRt7g(Yw8L *t) { /* MIOModule__CFile.print__p1 */
 Zsf sf={0,topFrame};
 Ts r = 0;
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
Tc *Yw8L__mt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)1,
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZg */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZf */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZe */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZd */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZc */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZb */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZa */
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)0, /* MIOModule__CFile.writeByte - YvfVa */
 (Tc*)0, /* MIOModule__CFile.writeChar - Yw8L__Ydti */
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
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZa */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZb */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZc */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZd */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZe */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZf */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZg */
 (Tc*)0, /* MIOModule__CFile.writeByte - YvfVa */
 (Tc*)0, /* MIOModule__CFile.writeChar - Yw8L__Ydti */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7a */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7b */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7c */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7d */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7e */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7f */
 (Tc*)Yw8L__YRt7g, /* MIOModule__CFile.print - Yw8L__YRt7g */
 (Tc*)0, /* MIOModule__CFile.format - Yw8L__YTPv */
 (Tc*)0, /* Vfd */
 (Tc*)0, /* Vname */
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
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
};
To ToYw8L[] = {
 {0, 0},
};
Tto Yw8L__T = {390, (Tc*)&YtTU, 0, ToYw8L};
Yw8L *YiBk(Tc *AfileName, Tb Atruncate) { /* MIOModule.fileWriter */
 Zsf sf={0,topFrame};
 Yw8L *r = 0;
 Yw8L *Vfile = NULL;
 Tc *Vflags = NULL;
 topFrame = &sf;
 sf.pos=8158000;
 {
  int flags = O_WRONLY|O_CREAT;
  if (Atruncate) flags |= O_TRUNC;
  int fnr = open(ZgetCstring(AfileName), flags, 0666);
  if (fnr >= 0) {
   if (!Atruncate) lseek(fnr, 0, SEEK_END);
 sf.pos=8158001;
 Vfile = (Yw8L*)Zamt(sizeof(Yw8L), Yw8L__mt);
 sf.pos=8158002;
   (*(FILE **)((Tc*)Vfile + (size_t)Vfile->mt[41])) = fdopen(fnr, "w");
  }
 }
 sf.pos=8158003;
 r = Vfile;
 topFrame = sf.prev;
 return r;
}
Ts Yvcu(Tc *Atext) { /* MIOModule.write */
 Ts Vret;
 Zsf sf={0,topFrame};
 Ts r = 0;
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
Ts Yl0k(Tc *Atext) { /* MIOModule.print */
 Ts Vret;
 Ti Vlen;
 Zsf sf={0,topFrame};
 Ts r = 0;
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
Ts Ylxt() { /* MIOModule.flush */
 Ts Vret;
 Zsf sf={0,topFrame};
 Ts r = 0;
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
Ts YJqza(YjUM *t, Tc *Atext) { /* MIOModule__CStringWriter.write */
 Ti Vlen;
 Zsf sf={0,topFrame};
 Ts r = 0;
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
   ZarrayResize(t->Vs, sizeof(Tc), (((ZArraySize(t->Vs) + (ZArraySize(t->Vs) / 8)) + Vlen) + 50));
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
Tc *YbNW(YjUM *t) { /* MIOModule__CStringWriter.ToString */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tc *Vr = NULL;
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
Ts YjUM__YHhZb(YjUM *t, Ti Anumber) { /* MIOModule__CStringWriter.write__p1 */
 Zsf sf={0,topFrame};
 Ts r = 0;
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
Ts YjUM__Ydti(YjUM *t, Ti Achar) { /* MIOModule__CStringWriter.writeChar__p1 */
 Zsf sf={0,topFrame};
 Ts r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4928500;
  ZthrowThisNil();
 }
 sf.pos=4928501;
 if (((Achar < 0) || (Achar > 1114111)))
 {
  Ytlm *ex;
  sf.pos=4928502;
  ex = (Ytlm*)Yw3O__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&Yv8w), Zint2string(Achar)));
  ZthrowIobject(ex);
 }
 sf.pos=4928503;
 r = YJqza(t, ZintAsString(Achar));
 topFrame = sf.prev;
 return r;
}
Tc *YjUM__mt[] = {
 (Tc*)&YjUM__T,
 (Tc*)3,
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZg */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZf */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZe */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZd */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZc */
 (Tc*)YjUM__YHhZb, /* MIOModule__CStringWriter.write - YjUM__YHhZb */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZa */
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)0, /* MIOModule__CStringWriter.writeByte - Ye7fa */
 (Tc*)YjUM__Ydti, /* MIOModule__CStringWriter.writeChar - YjUM__Ydti */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7g */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7f */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7e */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7d */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7c */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7b */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7a */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
 (Tc*)0, /* MIOModule__CStringWriter.format - YjUM__YTPv */
 (Tc*)0, /* Init - YjUMa */
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZa */
 (Tc*)YjUM__YHhZb, /* MIOModule__CStringWriter.write - YjUM__YHhZb */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZc */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZd */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZe */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZf */
 (Tc*)0, /* MIOModule__CStringWriter.write - YjUM__YHhZg */
 (Tc*)0, /* MIOModule__CStringWriter.writeByte - Ye7fa */
 (Tc*)YjUM__Ydti, /* MIOModule__CStringWriter.writeChar - YjUM__Ydti */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7a */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7b */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7c */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7d */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7e */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7f */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7g */
 (Tc*)0, /* MIOModule__CStringWriter.format - YjUM__YTPv */
 (Tc*)0, /* VsLen */
 (Tc*)0, /* Vs */
 (Tc*)0, /* Vx */
 (Tc*)0, /* MIOModule__CStringWriter.byteSize - Yd3R */
 (Tc*)0, /* MIOModule__CStringWriter.Size - YKJQ */
 (Tc*)0, /* MIOModule__CStringWriter.size - YfXZ */
 (Tc*)0, /* MIOModule__CStringWriter.empty - Yqej */
 (Tc*)YbNW, /* MIOModule__CStringWriter.ToString - YbNW */
 (Tc*)0, /* MIOModule__CStringWriter.remove - Y6jW */
 (Tc*)0, /* MIOModule__CStringWriter.clear - YXip */
 (Tc*)0, /* MIOModule__CStringWriter.truncate - Y3_a */
 (Tc*)0, /* Init - YjUMa */
};
Tc *YjUM__YdXi_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
};
To ToYjUM[] = {
 {1, 0},
 {0, (Tt*)&array__T}, /* s */
};
Tto YjUM__T = {390, (Tc*)&YE4c, 0, ToYjUM};
Tb Y0YB(Tc *Aname) { /* MIOModule.isReadable */
 Ti Vv;
 Zsf sf={0,topFrame};
 Tb r = 0;
 topFrame = &sf;
 Vv = 0;
 sf.pos=7156300;
 Vv = access(ZgetCstring(Aname), R_OK);
 sf.pos=7156301;
 r = (Vv == 0);
 topFrame = sf.prev;
 return r;
}
Tb Y_3K(Tc *Aname) { /* MIOModule.isExecutable */
 Ti Vv;
 Zsf sf={0,topFrame};
 Tb r = 0;
 topFrame = &sf;
 Vv = 0;
 sf.pos=7387700;
 Vv = access(ZgetCstring(Aname), X_OK);
 sf.pos=7387701;
 r = (Vv == 0);
 topFrame = sf.prev;
 return r;
}
Tc *Ycmi(Tc *AexeName) { /* MIOModule.findExe */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tc *Vfname = NULL;
 Tc *Vexe = NULL;
 Tl *Vdirectories = NULL;
 Tc *Vpath = NULL;
 int rt = 0;
 topFrame = &sf;
 sf.pos=6497000;
 Vexe = Yvnf(AexeName, 92, 47);
 sf.pos=6497001;
 if (((ZstringStartsWith(Vexe, ((Tc*)&YV), 0) || ZstringStartsWith(Vexe, ((Tc*)&YFka), 0)) || ZstringStartsWith(Vexe, ((Tc*)&Y0y2), 0)))
 {
  sf.pos=6497002;
  Vfname = Vexe;
 }
 else
 {
  sf.pos=6497003;
  Vpath = Yhy5(((Tc*)&Yykt));
  sf.pos=6497004;
  if ((Vpath != NULL))
  {
   sf.pos=6497005;
#if defined(__MINGW32__) || defined(_MSC_VER)
   sf.pos=6497006;
   Vdirectories = ZstringSplit(Vpath, ((Tc*)&Y6));
   sf.pos=6497007;
#else
   sf.pos=6497008;
   Vdirectories = ZstringSplit(Vpath, ((Tc*)&Y5));
   sf.pos=6497009;
#endif
  }
  sf.pos=6497010;
  Vfname = YDop(AexeName, Vdirectories);
  sf.pos=6497011;
#if defined(__MINGW32__) || defined(_MSC_VER)
  sf.pos=6497012;
  if (((Vfname == NULL) && !(ZstringEndsWith(ZstringToLower(AexeName), ((Tc*)&YpPR), 0))))
  {
   sf.pos=6497013;
   Vfname = YDop(ZcS(AexeName, ((Tc*)&YpPR)), Vdirectories);
  }
  sf.pos=6497014;
#endif
  sf.pos=6497015;
  if ((Vfname == NULL))
  {
   sf.pos=6497016;
#if defined(__MINGW32__) || defined(_MSC_VER)
   sf.pos=6497017;
   if (Y_3K(Vexe))
   {
    sf.pos=6497018;
    Vfname = Vexe;
   }
   else {
   sf.pos=6497019;
   if (Y_3K(ZcS(Vexe, ((Tc*)&YpPR))))
   {
    sf.pos=6497020;
    Vfname = ZcS(Vexe, ((Tc*)&YpPR));
   }
   }
   sf.pos=6497021;
#endif
  }
  else
  {
   sf.pos=6497022;
   Vfname = Yvnf(Vfname, 92, 47);
  }
 }
 sf.pos=6497023;
 if ((Vfname == NULL))
 {
  sf.pos=6497024;
  r = NULL;
  rt = 1;
  goto YNoZ;
 }
 sf.pos=6497025;
 r = YPjH(Vfname);
YNoZ:
 topFrame = sf.prev;
 return r;
}
Tc *YDop(Tc *AexeName, Tl *Adirs) { /* MIOModule.findExeInDirList */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tl *Zf1 = NULL;
 Tc *Vdir = NULL;
 Tc *Vfname = NULL;
 int rt = 0;
 topFrame = &sf;
 sf.pos=8617600;
 {
  Tfl Zf1i;
  Zf1 = Adirs;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdir;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8617601;
  Vfname = Yq8a(Vdir, AexeName);
  sf.pos=8617602;
  if (Y_3K(Vfname))
  {
   sf.pos=8617603;
   r = Vfname;
   rt = 1;
   goto Ycsu;
  }
Ycsu:
  if (rt) goto YsLr;
  sf.pos=8617604;
  }
 }
 sf.pos=8617605;
 r = NULL;
YsLr:
 topFrame = sf.prev;
 return r;
}
Tc *Yq8a(Tc *Afirst, Tc *Asecond) { /* MIOModule.concatPath */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=6830400;
 if (ZstringEndsWith(Afirst, ((Tc*)&YV), 0))
 {
  sf.pos=6830401;
  if (ZstringStartsWith(Asecond, ((Tc*)&YV), 0))
  {
   sf.pos=6830402;
   r = ZcS(Afirst, YuAL(Asecond, 1));
   rt = 1;
   goto YV1Y;
  }
  sf.pos=6830403;
  r = ZcS(Afirst, Asecond);
YV1Y:
  ;
  rt = 1;
  goto YSGC;
 }
 sf.pos=6830404;
 if (((ZbyteStringSize(Afirst) == 0) || ZstringStartsWith(Asecond, ((Tc*)&YV), 0)))
 {
  sf.pos=6830405;
  r = ZcS(Afirst, Asecond);
  rt = 1;
  goto YSGC;
 }
 sf.pos=6830406;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=6830407;
 if ((ZstringCmp(Afirst, ((Tc*)&YU)) == 0))
 {
  sf.pos=6830408;
  r = Asecond;
  rt = 1;
  goto YSGC;
 }
 sf.pos=6830409;
#endif
 sf.pos=6830410;
 r = ZcS3(Afirst, ((Tc*)&YV), Asecond);
YSGC:
 topFrame = sf.prev;
 return r;
}
Tc *Y2wM(Tc *Afname) { /* MIOModule.fullPath */
 Ts Vretval;
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tc *Vdir = NULL;
 Tc *VnewFname = NULL;
 Tc *Vcwd = NULL;
 int rt = 0;
 topFrame = &sf;
 sf.pos=3840300;
#if _BSD_SOURCE || _XOPEN_SOURCE >= 500
# define HAVE_FCHDIR
#endif
#ifndef PATH_MAX
# define PATH_MAX 1026
#endif
  int l;
#ifdef HAVE_FCHDIR
  int fd = -1;
  static int dont_fchdir = 0; /* TRUE when fchdir() doesn't work */
#endif
  char olddir[PATH_MAX];
  char newdir[PATH_MAX];
  char *fp;
#ifdef __CYGWIN__
  char posix_fname[PATH_MAX];
#endif
 sf.pos=3840301;
 Vretval = 1;
 sf.pos=3840302;
 VnewFname = Afname;
 sf.pos=3840303;
    char *fname = ZgetCstring(Afname);

#ifdef __CYGWIN__
 /* This helps for when "/etc/hosts" is a symlink to "c:/something/hosts". */
# if CYGWIN_VERSION_DLL_MAJOR >= 1007
 cygwin_conv_path(CCP_WIN_A_TO_POSIX, fname, posix_fname, PATH_MAX);
# else
 cygwin_conv_to_posix_path(fname, posix_fname);
# endif
 fname = posix_fname;
#endif

 /* If the file name has a path, change to that directory for a moment, and
 then do the getwd() (and get back to where we were).  This will get the
 correct path name with "../" things. */
 fp = strrchr(fname, '/');
 if (fp == NULL) {
   fp = strrchr(fname, '\\');
 }
 if (fp != NULL)
 {
#ifdef HAVE_FCHDIR
  /* Use fchdir() if possible, it's said to be faster and more reliable.  But
  on SunOS 4 it might not work.  Check this by doing a fchdir() right now. */
  if (!dont_fchdir)
  {
   fd = open((char *)".", O_RDONLY, 0);
   if (fd >= 0 && fchdir(fd) < 0)
   {
    close(fd);
    fd = -1;
    dont_fchdir = 1; /* don't try again */
   }
  }
#endif

 sf.pos=3840304;
  /* Only change directory when we are sure we can return to where we are now.
  After doing "su" chdir(".") might not work. */
  if (
#ifdef HAVE_FCHDIR
     fd < 0 &&
#endif
      (getcwd(olddir, PATH_MAX) == NULL || chdir(olddir) != 0))
   {
    fp = NULL;  /* can't get current dir: don't chdir */
    Vretval = 0;
   } else {
    /* The directory is copied into newdir[], to be able to remove the file
    name without changing it (could be a string in read-only memory) */
    if (fp - fname >= PATH_MAX)
     Vretval = 0;
    else
    {
     strncpy(newdir, fname, fp - fname);
     newdir[fp - fname] = 0;
     if (chdir(newdir))
      Vretval = 0;
     else
      fname = fp + 1;
     *newdir = 0;
    }
   }
  }
  if (getcwd(newdir, PATH_MAX) == NULL)
   Vretval = 0;
 sf.pos=3840305;
  if (fp != NULL)
  {
#ifdef HAVE_FCHDIR
   if (fd >= 0)
   {
    l = fchdir(fd);
    close(fd);
   } else
#endif
   l = chdir(olddir);
   if (l != 0) {
 sf.pos=3840306;
 YkuV(((Tc*)&Yd94));
 sf.pos=3840307;
   }
  }
 sf.pos=3840308;
 VnewFname = NULL;
 sf.pos=3840309;
#ifdef __MINGW32__
 while ((fp = strchr(newdir, '\\')) != NULL) *fp = '/';
 if (isalpha(*newdir) && newdir[1] == ':') *newdir = toupper(*newdir);
#endif
 VnewFname = Zstr(fname);
 Vdir = Zstr(newdir);
 sf.pos=3840310;
 if ((Vretval == 0))
 {
  sf.pos=3840311;
  r = NULL;
  rt = 1;
  goto YagJ;
 }
 sf.pos=3840312;
 if ((ZstringCmp(VnewFname, ((Tc*)&YU)) == 0))
 {
  sf.pos=3840313;
  r = Vdir;
  rt = 1;
  goto YagJ;
 }
 sf.pos=3840314;
 if ((((ZstringSize(Vdir) > 0) && !(ZstringEndsWith(Vdir, ((Tc*)&YV), 0))) && (ZstringSize(VnewFname) > 0)))
 {
  sf.pos=3840315;
  r = ZcS3(Vdir, ((Tc*)&YV), VnewFname);
  rt = 1;
  goto YagJ;
 }
 sf.pos=3840316;
 r = ZcS(Vdir, VnewFname);
YagJ:
 topFrame = sf.prev;
 return r;
}
Tc *YPjH(Tc *Afname) { /* MIOModule.resolve */
 Ti Vlimit;
 Tb VisRelative;
 Tb VhasTrailingSep;
 Ti Vi;
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tc *Vresult = NULL;
 Tc *Vlink = NULL;
 Tc *Vremain = NULL;
 int rt = 0;
 topFrame = &sf;
 sf.pos=4533100;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=4533101;
 Vresult = Afname;
 sf.pos=4533102;
#else
 sf.pos=4533103;
 Vlimit = 100;
 sf.pos=4533104;
 VisRelative = ((ZstringGetChar(Afname, 0) == 46) && ((Yhu2(ZstringGetChar(Afname, 1)) || (((ZstringGetChar(Afname, 1) == 46) && Yhu2(ZstringGetChar(Afname, 2)))))));
 sf.pos=4533105;
 VhasTrailingSep = ZstringEndsWith(Afname, ((Tc*)&YV), 0);
 sf.pos=4533106;
 Vi = Y26N(Afname, YEpA(Afname));
 sf.pos=4533107;
 if ((Vi > 1))
 {
  sf.pos=4533108;
  Vresult = YuALa(Afname, 0, (Vi - 2));
  sf.pos=4533109;
  Vremain = YuAL(Afname, (Vi - 1));
 }
 else
 {
  sf.pos=4533110;
  Vresult = Afname;
 }
 sf.pos=4533111;
 while (1)
 {
  sf.pos=4533112;
  while (1)
  {
   Ti Vt;
   sf.pos=4533113;
   {
    int   len;
    char  buf[PATH_MAX + 1];
    len = readlink(ZgetCstring(Vresult), (char *)buf, PATH_MAX);
    if (len <= 0) break;  /* can't read, use as-is */
    buf[len] = 0;
   sf.pos=4533114;
   Vlink = NULL;
   sf.pos=4533115;
    Vlink = Zstr(buf);
   }
   sf.pos=4533116;
   if (((Vlimit)-- == 0))
   {
    sf.pos=4533117;
    r = Afname;
    rt = 1;
    goto Yu7Z;
   }
   sf.pos=4533118;
   if (((Vremain == NULL) && VhasTrailingSep))
   {
    sf.pos=4533119;
    Vlink =  ZcS(Vlink, ((Tc*)&YV));
   }
   sf.pos=4533120;
   Vi = Y26N(Vlink, YEpA(Vlink));
   sf.pos=4533121;
   if ((Vi > 1))
   {
    sf.pos=4533122;
    if ((Vremain == NULL))
    {
     sf.pos=4533123;
     Vremain = YuAL(Vlink, (Vi - 1));
    }
    else
    {
     sf.pos=4533124;
     Vremain = ZcS(YuAL(Vlink, (Vi - 1)), Vremain);
    }
    sf.pos=4533125;
    Vlink = YuALa(Vlink, 0, (Vi - 2));
   }
   sf.pos=4533126;
   Vt = Yr30(Vresult);
   sf.pos=4533127;
   if (((Vt > 0) && (Vt == ZstringSize(Vresult))))
   {
    sf.pos=4533128;
    Vresult = ZstringSliceWrap(Vresult, 0, -2);
    sf.pos=4533129;
    Vt = Yr30(Vresult);
   }
   sf.pos=4533130;
   if (((Vt > 0) && (YEpA(Vlink) == 0)))
   {
    sf.pos=4533131;
    Vresult = ZcS(YuALa(Vresult, 0, (Vt - 1)), Vlink);
   }
   else
   {
    sf.pos=4533132;
    Vresult = ZcS(Vlink, ((Tc*)&Ya));
   }
Yu7Z:
   if (rt == 2) { rt &= 1; break; }
   if (rt) goto YqPr;
  sf.pos=4533133;
  }
  sf.pos=4533134;
  if ((Vremain == NULL))
  {
   rt = 2;
   goto YqPr;
  }
  sf.pos=4533135;
  Vi = Y26N(Vremain, 1);
  sf.pos=4533136;
  if ((Vi > 1))
  {
   sf.pos=4533137;
   Vresult =  ZcS(Vresult, YuALa(Vremain, 0, (Vi - 2)));
   sf.pos=4533138;
   Vremain = YuAL(Vremain, (Vi - 1));
  }
  else
  {
   sf.pos=4533139;
   Vresult =  ZcS(Vresult, Vremain);
   sf.pos=4533140;
   Vremain = NULL;
  }
YqPr:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YQMx;
 sf.pos=4533141;
 }
 sf.pos=4533142;
 if (Yhu2(ZstringGetChar(Vresult, 0)))
 {
  sf.pos=4533143;
  if (((VisRelative && (ZstringSize(Vresult) > 0)) && !((((ZstringGetChar(Vresult, 0) == 46) && ((((ZstringSize(Vresult) == 1) || Yhu2(ZstringGetChar(Vresult, 1))) || (((ZstringGetChar(Vresult, 1) == 46) && (((ZstringSize(Vresult) == 2) || Yhu2(ZstringGetChar(Vresult, 2)))))))))))))
  {
   sf.pos=4533144;
   Vresult = ZcS(((Tc*)&YFka), Vresult);
  }
  else {
  sf.pos=4533145;
  if (!(VisRelative))
  {
   sf.pos=4533146;
   Vi = 0;
   sf.pos=4533147;
   while (((ZstringGetChar(Vresult, Vi) == 46) && Yhu2(ZstringGetChar(Vresult, (Vi + 1)))))
   {
    sf.pos=4533148;
    Vi += 2;
   sf.pos=4533149;
   }
   sf.pos=4533150;
   if ((Vi > 0))
   {
    sf.pos=4533151;
    Vresult = YuAL(Vresult, Vi);
   }
  }
  }
 }
 sf.pos=4533152;
 if (!(VhasTrailingSep))
 {
  Ti Vm;
  sf.pos=4533153;
  Vm = YEpA(Vresult);
  sf.pos=4533154;
  while ((ZstringEndsWith(Vresult, ((Tc*)&YV), 0) && (ZstringSize(Vresult) > Vm)))
  {
   sf.pos=4533155;
   Vresult = ZstringSliceWrap(Vresult, 0, -2);
  sf.pos=4533156;
  }
 }
 sf.pos=4533157;
#endif
 sf.pos=4533158;
 r = Vresult;
YQMx:
 topFrame = sf.prev;
 return r;
}
Ti Yr30(Tc *Afname) { /* MIOModule.tailIndex */
 Ti Vi;
 Ti Vj;
 Zsf sf={0,topFrame};
 Ti r = 0;
 int rt = 0;
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
Ti YEpA(Tc *Afname) { /* MIOModule.pastHeadIndex */
 Ti Vi;
 Zsf sf={0,topFrame};
 Ti r = 0;
 topFrame = &sf;
 Vi = 0;
 sf.pos=1101700;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=1101701;
 if ((isalpha(ZstringGetChar(Afname, 0)) && (ZstringGetChar(Afname, 1) == 58)))
 {
  sf.pos=1101702;
  Vi = 2;
 }
 sf.pos=1101703;
#endif
 sf.pos=1101704;
 while (((Vi < ZstringSize(Afname)) && Yhu2(ZstringGetChar(Afname, Vi))))
 {
  sf.pos=1101705;
  ++(Vi);
 sf.pos=1101706;
 }
 sf.pos=1101707;
 r = Vi;
 topFrame = sf.prev;
 return r;
}
Tb Yhu2(Ti Ac) { /* MIOModule.isPathSep */
 Zsf sf={0,topFrame};
 Tb r = 0;
 topFrame = &sf;
 sf.pos=7913600;
 r = (Ac == 47);
 topFrame = sf.prev;
 return r;
}
Ti Y26N(Tc *Afname, Ti Aidx) { /* MIOModule.nextPartIndex */
 Zsf sf={0,topFrame};
 Ti r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=3627700;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(Aidx, (ZstringSize(Afname) - 1), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=3627701;
  if (Yhu2(ZstringGetChar(Afname, Vi)))
  {
   sf.pos=3627702;
   r = (Vi + 1);
   rt = 1;
   goto Ydy4;
  }
Ydy4:
  if (rt) goto Y3wQ;
  sf.pos=3627703;
  }
 }
 sf.pos=3627704;
 r = -1;
Y3wQ:
 topFrame = sf.prev;
 return r;
}
int JIOModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf={0,topFrame};
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
int JLOGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf={0,topFrame};
  topFrame = &sf;
  round_done = round;
 if (round == 0) {
   sf.pos=8332600;
   YU8T = YttT(NULL, ((Tc*)&YLa), ((Tc*)&YGwH), 0, ((Tc*)&YhpM));
   sf.pos=8332601;
   YlUb = YttT(NULL, ((Tc*)&Y2a), ((Tc*)&YUsn), 0, ((Tc*)&YSuP));
  }
  topFrame = sf.prev;
 }
 return done;
}
/* LOGModule done */
/* including ARGModule bodies */
Ts Ytu_() { /* MARGModule.Init */
 Zsf sf={0,topFrame};
 Ts r = 0;
 topFrame = &sf;
 sf.pos=6650100;
 r = (((Y6fX == NULL)) ? (0) : (1));
 topFrame = sf.prev;
 return r;
}
To ToYnU5[] = {
 {0, 0},
};
Tto YnU5__T = {390, (Tc*)&Yr32, 0, ToYnU5};
void YQtK() { /* MARGModule.initExeName */
 void *p1;
 Zsf sf={0,topFrame};
 topFrame = &sf;
 sf.pos=7716400;
 Y2R7 = ((p1 = (Ycmi(YzvW))) == NULL ? (YzvW) : p1);
 topFrame = sf.prev;
 return;
}
Tc *YzHL() { /* MARGModule.getExeDir */
 Ti VtailIndex;
 Zsf sf={0,topFrame};
 Tc *r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=3261800;
 VtailIndex = Yr30(Y2R7);
 sf.pos=3261801;
 if ((VtailIndex <= 0))
 {
  sf.pos=3261802;
  r = ((Tc*)&YU);
  rt = 1;
  goto Yt70;
 }
 sf.pos=3261803;
 r = YuALa(Y2R7, 0, (VtailIndex - 2));
Yt70:
 topFrame = sf.prev;
 return r;
}
void YZH8() { /* MARGModule.init */
 Zsf sf={0,topFrame};
 Tc *Varg = NULL;
 Tc *Vvalue = NULL;
 Tc *Vflagname = NULL;
 Tc *Vflagname1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vk = NULL;
 Tl *Zf21 = NULL;
 Tc *Vk1 = NULL;
 YuQR *Vflag = NULL;
 Y86c *Vbflag = 0;
 Y86c *Vbflag1 = 0;
 Y_SI *Vsflag = 0;
 YJQu *Viflag = 0;
 YzqH *Vsflag1 = 0;
 int rt = 0;
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
   Y7be = ZnewDict((Tt*)&string__T, (Tt*)&xobj__T, 0);
   sf.pos=8253303;
   YBQy = ZnewDict((Tt*)&string__T, (Tt*)&xobj__T, 0);
  }
  sf.pos=8253304;
  if ((YUBd && (((ZDictSize(Y7be) > 0) || (ZDictSize(YBQy) > 0)))))
  {
   Ytlm *ex;
   sf.pos=8253305;
   ex = (Ytlm*)YVNj__YwtA__YRHR(NULL, ((Tc*)&Y7T_));
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
   YuQR *YXyJ = NULL;
   sf.pos=8253307;
   (YXyJ = ((YuQR *)ZDictGetPtr(Y7be, (Tz)(void*)Vk)), ((void (*)(void*))(YXyJ->mt[17]))(YXyJ));
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
   YuQR *YWyJ = NULL;
   sf.pos=8253310;
   (YWyJ = ((YuQR *)ZDictGetPtr(YBQy, (Tz)(void*)Vk1)), ((void (*)(void*))(YWyJ->mt[17]))(YWyJ));
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
     Vflag = NULL;
     Vvalue = NULL;
     sf.pos=8253324;
     if ((ZstringCmp(YuALa(Varg, 0, 1), ((Tc*)&Y1ia)) == 0))
     {
      Ti Vidx;
      sf.pos=8253325;
      Vflagname = YuAL(Varg, 2);
      sf.pos=8253326;
      if ((!(YhUP) && ((((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) == 0) || (ZstringCmp(Vflagname, ((Tc*)&Y3vi)) == 0)) || (ZstringCmp(Vflagname, ((Tc*)&Yll7)) == 0)))))
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
       Vvalue = YuAL(Vflagname, (Vidx + 1));
       sf.pos=8253331;
       Vflagname = YuALa(Vflagname, 0, (Vidx - 1));
      }
      sf.pos=8253332;
      Vflag = ((YuQR *)ZDictGetPtrDef(YBQy, (Tz)(void*)Vflagname, NULL));
      sf.pos=8253333;
      if (((Vflag == (void *)NULL) && (ZstringCmp(YuALa(Vflagname, 0, 1), ((Tc*)&YhZb)) == 0)))
      {
       sf.pos=8253334;
       Vflag = ((YuQR *)ZDictGetPtrDef(YBQy, (Tz)(void*)YuAL(Vflagname, 2), NULL));
       sf.pos=8253335;
       if ((Vflag != (void *)NULL))
       {
        sf.pos=8253336;
        if (ZxobjIsa(Vflag, 1))
        {
         sf.pos=8253337;
         Vflagname = YuAL(Vflagname, 2);
         sf.pos=8253338;
         Vvalue = ((Tc*)&YhZb);
        }
        else
        {
         sf.pos=8253339;
         Vflag = NULL;
        }
       }
      }
     }
     else
     {
      Ti Vidx;
      sf.pos=8253340;
      Vflagname1 = YuAL(Varg, 1);
      sf.pos=8253341;
      Vidx = ZstringFindChar(Vflagname1, 61, 0);
      sf.pos=8253342;
      if ((Vidx > 0))
      {
       sf.pos=8253343;
       Vvalue = YuAL(Vflagname1, (Vidx + 1));
       sf.pos=8253344;
       Vflagname1 = YuALa(Vflagname1, 0, (Vidx - 1));
      }
      else
      {
       sf.pos=8253345;
       while ((ZstringSize(Vflagname1) > 1))
       {
        sf.pos=8253346;
        Vflag = ((YuQR *)ZDictGetPtrDef(Y7be, (Tz)(void*)YuALa(Vflagname1, 0, 0), NULL));
        sf.pos=8253347;
        if ((Vflag == (void *)NULL))
        {
         rt = 2;
         goto Yy70;
        }
        else
        {
         sf.pos=8253348;
         if (ZxobjIsa(Vflag, 1))
         {
          sf.pos=8253349;
          ++((*(Ti*)((Tc*)Vflag + (size_t)Vflag->mt[6])));
          sf.pos=8253351;
          Vbflag = ((Y86c *)Znip(&Y86c__T, 8253350, (Vflag)));
          sf.pos=8253352;
          Vbflag->Vcurrent = !(Vbflag->Vdefault);
          sf.pos=8253353;
          Vflagname1 = YuAL(Vflagname1, 1);
          sf.pos=8253354;
          Vflag = NULL;
         }
         else {
         sf.pos=8253355;
         if (ZxobjIsa(Vflag, 4))
         {
          rt = 2;
          goto YuBh;
         }
         else {
         sf.pos=8253356;
         if ((!(Y_kI) && !((*(Tb*)((Tc*)Vflag + (size_t)Vflag->mt[8])))))
         {
          sf.pos=8253357;
          Vvalue = YuAL(Vflagname1, 1);
          sf.pos=8253358;
          Vflagname1 = YuALa(Vflagname1, 0, 0);
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
      if ((Vflag == (void *)NULL))
      {
       sf.pos=8253363;
       Vflag = ((YuQR *)ZDictGetPtrDef(Y7be, (Tz)(void*)Vflagname1, NULL));
      }
      }
     }
     sf.pos=8253364;
     if ((Vflag == (void *)NULL))
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
      if ((((*(Ti*)((Tc*)Vflag + (size_t)Vflag->mt[6])) > 0) && !((*(Tb*)((Tc*)Vflag + (size_t)Vflag->mt[7])))))
      {
       sf.pos=8253368;
       YSUO(ZcS(((Tc*)&YcLH), Varg));
      }
      sf.pos=8253369;
      ++((*(Ti*)((Tc*)Vflag + (size_t)Vflag->mt[6])));
      sf.pos=8253370;
      if (ZxobjIsa(Vflag, 1))
      {
       sf.pos=8253372;
       Vbflag1 = ((Y86c *)Znip(&Y86c__T, 8253371, (Vflag)));
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
      if (ZxobjIsa(Vflag, 4))
      {
       sf.pos=8253381;
       if ((Vvalue != NULL))
       {
        sf.pos=8253382;
        YSUO(ZcS(((Tc*)&Y6QK), Varg));
       }
       sf.pos=8253384;
       Vsflag = ((Y_SI *)Znip(&Y_SI__T, 8253383, (Vflag)));
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
       if ((!((*(Tb*)((Tc*)Vflag + (size_t)Vflag->mt[9]))) && (Vvalue == NULL)))
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
       if (ZxobjIsa(Vflag, 2))
       {
        sf.pos=8253396;
        Viflag = ((YJQu *)Znip(&YJQu__T, 8253395, (Vflag)));
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
       if (ZxobjIsa(Vflag, 3))
       {
        sf.pos=8253405;
        Vsflag1 = ((YzqH *)Znip(&YzqH__T, 8253404, (Vflag)));
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
        Ytlm *ex;
        sf.pos=8253411;
        ex = (Ytlm*)YrHq__YwtA__YRHR(NULL, ((Tc*)&YjTs));
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
void YSUO(Tc *Amsg) { /* MARGModule.error */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 sf.pos=8529500;
 Yw8L__YRt7((Yw8L *)YeNQ, Amsg);
 sf.pos=8529501;
 if ((Yun4 != NULL))
 {
  sf.pos=8529502;
  Yl0k(YAMW((YuMQ *)Yun4));
 }
 sf.pos=8529503;
 if (!(YhUP))
 {
  sf.pos=8529504;
  Yw8L__YRt7((Yw8L *)YeNQ, ZcS3(((Tc*)&YkFE), YzvW, ((Tc*)&Y15F)));
 }
 sf.pos=8529505;
 Zexit(NULL, 1);
 topFrame = sf.prev;
 return;
}
void Yfj5(Tb Averbose) { /* MARGModule.displayHelp */
 Ti VmaxLeadLen;
 Zsf sf={0,topFrame};
 Td *VallFlags = NULL;
 Tl *Zf1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vkey = NULL;
 Tc *VargText = NULL;
 Tc *Vlead = NULL;
 Tl *Zf11 = NULL;
 Tc *Vkey1 = NULL;
 YuQR *Vflag = NULL;
 YuQR *Vflag1 = NULL;
 Tl *t0 = NULL;
 int rt = 0;
 topFrame = &sf;
 sf.pos=2956000;
 if ((Yun4 != NULL))
 {
  sf.pos=2956001;
  Yl0k(YAMW((YuMQ *)Yun4));
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
  Vflag = ((YuQR *)ZDictGetPtr(YBQy, (Tz)(void*)Vkey1));
  sf.pos=2956006;
  if (((*(Tc**)((Tc*)Vflag + (size_t)Vflag->mt[2])) == NULL))
  {
   sf.pos=2956007;
   *((YuQR **)ZDictGetPtrP(VallFlags, (Tz)(void*)(*(Tc**)((Tc*)Vflag + (size_t)Vflag->mt[3])))) = Vflag;
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
   Vflag1 = ((YuQR *)ZDictGetPtr(VallFlags, (Tz)(void*)Vkey));
   sf.pos=2956015;
   VargText = ((Tc*)&Ya);
   Vopt = 0;
   sf.pos=2956016;
   if (ZxobjIsa(Vflag1, 2))
   {
    sf.pos=2956017;
    if (((*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[5])) == NULL))
    {
     sf.pos=2956018;
     VargText = ((Tc*)&Yy2p);
    }
    else
    {
     sf.pos=2956019;
     VargText = (*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[5]));
    }
    sf.pos=2956020;
    Vopt = (*(Tb*)((Tc*)Vflag1 + (size_t)Vflag1->mt[9]));
   }
   else {
   sf.pos=2956021;
   if (ZxobjIsa(Vflag1, 3))
   {
    sf.pos=2956022;
    if (((*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[5])) == NULL))
    {
     sf.pos=2956023;
     VargText = ((Tc*)&YanE);
    }
    else
    {
     sf.pos=2956024;
     VargText = (*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[5]));
    }
    sf.pos=2956025;
    Vopt = (*(Tb*)((Tc*)Vflag1 + (size_t)Vflag1->mt[9]));
   }
   else {
   sf.pos=2956026;
   if (ZxobjIsa(Vflag1, 4))
   {
    sf.pos=2956027;
    if (((*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[5])) == NULL))
    {
     sf.pos=2956028;
     VargText = ((Tc*)&YDci);
    }
    else
    {
     sf.pos=2956029;
     VargText = ZcS((*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[5])), ((Tc*)&YulU));
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
   if (((*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[2])) != NULL))
   {
    sf.pos=2956037;
    Vlead = ZcS5(((Tc*)&YT), (*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[2])), VargText, ((Tc*)&YG), (Tc*)1);
   }
   sf.pos=2956038;
   if (((*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[3])) != NULL))
   {
    sf.pos=2956039;
    if (((ZbyteStringSize(Vlead) != 0) && (ZbyteStringSize(VargText) != 0)))
    {
     sf.pos=2956040;
     if (Vdisplay)
     {
      sf.pos=2956041;
      if ((*(Tb*)((Tc*)Vflag1 + (size_t)Vflag1->mt[7])))
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
    Vlead =  ZcS(Vlead, ZcS5(((Tc*)&Y1ia), (*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[3])), VargText, ((Tc*)&YG), (Tc*)1));
   }
   sf.pos=2956046;
   if ((*(Tb*)((Tc*)Vflag1 + (size_t)Vflag1->mt[7])))
   {
    sf.pos=2956047;
    Vlead =  ZcS(Vlead, ((Tc*)&Y2yA));
   }
   sf.pos=2956048;
   if (Vdisplay)
   {
    sf.pos=2956049;
    if (((*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[4])) != NULL))
    {
     sf.pos=2956050;
     YTlu(Vlead, VmaxLeadLen);
     sf.pos=2956051;
     Yl0k((*(Tc**)((Tc*)Vflag1 + (size_t)Vflag1->mt[4])));
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
     Yl0k(ZcS(((Tc*)&Ym4c), YpI_((YkxB *)(*(YkxB**)((Tc*)Vflag1 + (size_t)Vflag1->mt[10])))));
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
void YTlu(Tc *Alead, Ti AmaxLeadLen) { /* MARGModule.writeLead */
 Zsf sf={0,topFrame};
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
Tc *YAMW(YuMQ *t) { /* MARGModule__CUsage.get */
 Ti Vidx;
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
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
 r = ZcS3(YuALa(t->Vtext, 0, (Vidx - 1)), YzvW, (t0 = YuAL(t->Vtext, (Vidx + 3))));
YZtK:
 topFrame = sf.prev;
 return r;
}
To ToYuMQ[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* text */
};
Tto YuMQ__T = {390, (Tc*)&Y6qT, 0, ToYuMQ};
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc) { /* MARGModule__CBool.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=327300; t = Zamt(sizeof(Y86c), Y86c__mt);}
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
void YEqoa(Y86c *t) { /* MARGModule__CBool.setToDefault */
 Zsf sf={0,topFrame};
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
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) { /* MARGModule__CBool.NEW__p1 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=7664400; t = Zamt(sizeof(Y86c), Y86c__mt);}
 sf.pos=7664401;
 if ((Y6fX != NULL))
 {
  Ytlm *ex;
  sf.pos=7664402;
  ex = (Ytlm*)YVNj__YwtA__YRHR(NULL, ((Tc*)&Yc_h));
  ZthrowIobject(ex);
 }
 sf.pos=7664403;
 if (((((AshortName == NULL) || (ZbyteStringSize(AshortName) == 0))) && (((AlongName == NULL) || (ZbyteStringSize(AlongName) == 0)))))
 {
  Ytlm *ex;
  sf.pos=7664404;
  ex = (Ytlm*)YVNj__YwtA__YRHR(NULL, ((Tc*)&Y6pY));
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
  Y7be = ZnewDict((Tt*)&string__T, (Tt*)&xobj__T, 0);
  sf.pos=7664412;
  YBQy = ZnewDict((Tt*)&string__T, (Tt*)&xobj__T, 0);
 }
 sf.pos=7664413;
 if (((AlongName != NULL) && (ZbyteStringSize(AlongName) != 0)))
 {
  sf.pos=7664414;
  if (ZDictHas(YBQy, (Tz)(void*)AlongName))
  {
   sf.pos=7664415;
   Y86c__YofP(t, AlongName, ((YuQR *)ZDictGetPtr(YBQy, (Tz)(void*)AlongName)), Apos);
  }
  sf.pos=7664416;
  ZDictAdd(0, YBQy, (Tz)(void*)AlongName, (Tz)(void*)(YuQR*)t);
 }
 sf.pos=7664417;
 if (((AshortName != NULL) && (ZbyteStringSize(AshortName) != 0)))
 {
  sf.pos=7664418;
  if ((ZstringSize(AshortName) > 1))
  {
   Ytlm *ex;
   sf.pos=7664419;
   ex = (Ytlm*)YVNj__YwtA__YRHR(NULL, ((Tc*)&Y9CP));
   ZthrowIobject(ex);
  }
  sf.pos=7664420;
  if (ZDictHas(Y7be, (Tz)(void*)AshortName))
  {
   sf.pos=7664421;
   Y86c__YofP(t, AshortName, ((YuQR *)ZDictGetPtr(Y7be, (Tz)(void*)AshortName)), Apos);
  }
  sf.pos=7664422;
  ZDictAdd(0, Y7be, (Tz)(void*)AshortName, (Tz)(void*)(YuQR*)t);
 }
 sf.pos=7664423;
 t->Vpos = Apos;
 topFrame = sf.prev;
 return t;
}
void Y86c__YofP(Y86c *t, Tc *Aname, YuQR *Aflag, YkxB *Apos) { /* MARGModule__CBool.throwDuplicate__p1 */
 YkxB *Y_CE = NULL;
 void *p2;
 Ytlm *ex;
 Zsf sf={0,topFrame};
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7569700;
  ZthrowThisNil();
 }
 sf.pos=7569701;
 VonePos = ((p2 = ((Y_CE = (*(YkxB**)((Tc*)Aflag + (size_t)Aflag->mt[10])), Y_CE == NULL ? NULL : YpI_((YkxB *)Y_CE)))) == NULL ? (((Tc*)&YbbH)) : p2);
 sf.pos=7569702;
 Ve = YVNj__YwtA__YRHRa(NULL, Apos, ZcS5(((Tc*)&YtzG), Aname, ((Tc*)&YDyy), VonePos, (Tc*)1));
 sf.pos=7569703;
 ex = (Ytlm*)Ve;
 ZthrowIobject(ex);
}
Tc *Y86c__mt[] = {
 (Tc*)&Y86c__T,
 (Tc*)1,
 (Tc*)0, /* VshortName */
 (Tc*)0, /* VlongName */
 (Tc*)0, /* Vdoc */
 (Tc*)0, /* VargName */
 (Tc*)0, /* VsetCount */
 (Tc*)0, /* VcanRepeat */
 (Tc*)0, /* VnoCompactVal */
 (Tc*)0, /* VargOpt */
 (Tc*)0, /* Vpos */
 (Tc*)Y86c__YofP, /* MARGModule__CBool.throwDuplicate - Y86c__YofP */
 (Tc*)0, /* MARGModule__CBool.setArgName - Y86c__Y836 */
 (Tc*)0, /* MARGModule__CBool.disableCompact - Y86c__YJbb */
 (Tc*)0, /* MARGModule__CBool.optionalArg - Y86c__YxuH */
 (Tc*)0, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
 (Tc*)0, /* MARGModule__CBool.present - Y86c__Y8Dq */
 (Tc*)YEqoa, /* MARGModule__CBool.setToDefault - YEqoa */
 (Tc*)0, /* Init - Y86ca */
 (Tc*)Y86c__YofP, /* MARGModule__CBool.throwDuplicate - Y86c__YofP */
 (Tc*)0, /* MARGModule__CBool.setArgName - Y86c__Y836 */
 (Tc*)0, /* MARGModule__CBool.disableCompact - Y86c__YJbb */
 (Tc*)0, /* MARGModule__CBool.optionalArg - Y86c__YxuH */
 (Tc*)0, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
 (Tc*)0, /* MARGModule__CBool.present - Y86c__Y8Dq */
 (Tc*)0, /* Vcurrent */
 (Tc*)0, /* Vdefault */
 (Tc*)YEqoa, /* MARGModule__CBool.setToDefault - YEqoa */
 (Tc*)0, /* MARGModule__CBool.disableRepeat - YOxU */
 (Tc*)0, /* MARGModule__CBool.get - YHoR */
 (Tc*)0, /* MARGModule__CBool.value - YuOS */
 (Tc*)0, /* Init - Y86ca */
};
To ToY86c[] = {
 {5, 0},
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y86c__T = {390, (Tc*)&YZ1F, 0, ToY86c};
void Y49ga(YJQu *t) { /* MARGModule__CInt.setToDefault */
 Zsf sf={0,topFrame};
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
Tc *YJQu__mt[] = {
 (Tc*)&YJQu__T,
 (Tc*)2,
 (Tc*)0, /* VshortName */
 (Tc*)0, /* VlongName */
 (Tc*)0, /* Vdoc */
 (Tc*)0, /* VargName */
 (Tc*)0, /* VsetCount */
 (Tc*)0, /* VcanRepeat */
 (Tc*)0, /* VnoCompactVal */
 (Tc*)0, /* VargOpt */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* MARGModule__CInt.throwDuplicate - YJQu__YofP */
 (Tc*)0, /* MARGModule__CInt.setArgName - YJQu__Y836 */
 (Tc*)0, /* MARGModule__CInt.disableCompact - YJQu__YJbb */
 (Tc*)0, /* MARGModule__CInt.optionalArg - YJQu__YxuH */
 (Tc*)0, /* MARGModule__CInt.presentCount - YJQu__Ye9f */
 (Tc*)0, /* MARGModule__CInt.present - YJQu__Y8Dq */
 (Tc*)Y49ga, /* MARGModule__CInt.setToDefault - Y49ga */
 (Tc*)0, /* Init - YJQua */
 (Tc*)0, /* MARGModule__CInt.throwDuplicate - YJQu__YofP */
 (Tc*)0, /* MARGModule__CInt.setArgName - YJQu__Y836 */
 (Tc*)0, /* MARGModule__CInt.disableCompact - YJQu__YJbb */
 (Tc*)0, /* MARGModule__CInt.optionalArg - YJQu__YxuH */
 (Tc*)0, /* MARGModule__CInt.presentCount - YJQu__Ye9f */
 (Tc*)0, /* MARGModule__CInt.present - YJQu__Y8Dq */
 (Tc*)0, /* Vcurrent */
 (Tc*)0, /* Vdefault */
 (Tc*)0, /* VtheValueList */
 (Tc*)Y49ga, /* MARGModule__CInt.setToDefault - Y49ga */
 (Tc*)0, /* MARGModule__CInt.enableRepeat - Yw71 */
 (Tc*)0, /* MARGModule__CInt.get - YRvz */
 (Tc*)0, /* MARGModule__CInt.value - Yl8r */
 (Tc*)0, /* MARGModule__CInt.getList - Yo4o */
 (Tc*)0, /* MARGModule__CInt.valueList - YChW */
 (Tc*)0, /* Init - YJQua */
};
To ToYJQu[] = {
 {6, 0},
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YJQu__T = {390, (Tc*)&YzBa, 0, ToYJQu};
void YJaza(YzqH *t) { /* MARGModule__CString.setToDefault */
 Zsf sf={0,topFrame};
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
Tc *YzqH__mt[] = {
 (Tc*)&YzqH__T,
 (Tc*)3,
 (Tc*)0, /* VshortName */
 (Tc*)0, /* VlongName */
 (Tc*)0, /* Vdoc */
 (Tc*)0, /* VargName */
 (Tc*)0, /* VsetCount */
 (Tc*)0, /* VcanRepeat */
 (Tc*)0, /* VnoCompactVal */
 (Tc*)0, /* VargOpt */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* MARGModule__CString.throwDuplicate - YzqH__YofP */
 (Tc*)0, /* MARGModule__CString.setArgName - YzqH__Y836 */
 (Tc*)0, /* MARGModule__CString.disableCompact - YzqH__YJbb */
 (Tc*)0, /* MARGModule__CString.optionalArg - YzqH__YxuH */
 (Tc*)0, /* MARGModule__CString.presentCount - YzqH__Ye9f */
 (Tc*)0, /* MARGModule__CString.present - YzqH__Y8Dq */
 (Tc*)YJaza, /* MARGModule__CString.setToDefault - YJaza */
 (Tc*)0, /* Init - YzqHa */
 (Tc*)0, /* MARGModule__CString.throwDuplicate - YzqH__YofP */
 (Tc*)0, /* MARGModule__CString.setArgName - YzqH__Y836 */
 (Tc*)0, /* MARGModule__CString.disableCompact - YzqH__YJbb */
 (Tc*)0, /* MARGModule__CString.optionalArg - YzqH__YxuH */
 (Tc*)0, /* MARGModule__CString.presentCount - YzqH__Ye9f */
 (Tc*)0, /* MARGModule__CString.present - YzqH__Y8Dq */
 (Tc*)0, /* Vcurrent */
 (Tc*)0, /* Vdefault */
 (Tc*)0, /* VtheValueList */
 (Tc*)YJaza, /* MARGModule__CString.setToDefault - YJaza */
 (Tc*)0, /* MARGModule__CString.enableRepeat - YS6K */
 (Tc*)0, /* MARGModule__CString.get - YPoi */
 (Tc*)0, /* MARGModule__CString.value - YMjs */
 (Tc*)0, /* MARGModule__CString.getList - YQnF */
 (Tc*)0, /* MARGModule__CString.valueList - YmrI */
 (Tc*)0, /* Init - YzqHa */
};
To ToYzqH[] = {
 {8, 0},
 {0, (Tt*)&string__T}, /* current */
 {0, (Tt*)&string__T}, /* default */
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YzqH__T = {390, (Tc*)&YDAE, 0, ToYzqH};
void YSkKa(Y_SI *t) { /* MARGModule__CStringList.setToDefault */
 Zsf sf={0,topFrame};
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
Tc *Y_SI__mt[] = {
 (Tc*)&Y_SI__T,
 (Tc*)4,
 (Tc*)0, /* VshortName */
 (Tc*)0, /* VlongName */
 (Tc*)0, /* Vdoc */
 (Tc*)0, /* VargName */
 (Tc*)0, /* VsetCount */
 (Tc*)0, /* VcanRepeat */
 (Tc*)0, /* VnoCompactVal */
 (Tc*)0, /* VargOpt */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* MARGModule__CStringList.throwDuplicate - Y_SI__YofP */
 (Tc*)0, /* MARGModule__CStringList.setArgName - Y_SI__Y836 */
 (Tc*)0, /* MARGModule__CStringList.disableCompact - Y_SI__YJbb */
 (Tc*)0, /* MARGModule__CStringList.optionalArg - Y_SI__YxuH */
 (Tc*)0, /* MARGModule__CStringList.presentCount - Y_SI__Ye9f */
 (Tc*)0, /* MARGModule__CStringList.present - Y_SI__Y8Dq */
 (Tc*)YSkKa, /* MARGModule__CStringList.setToDefault - YSkKa */
 (Tc*)0, /* Init - Y_SIa */
 (Tc*)0, /* MARGModule__CStringList.throwDuplicate - Y_SI__YofP */
 (Tc*)0, /* MARGModule__CStringList.setArgName - Y_SI__Y836 */
 (Tc*)0, /* MARGModule__CStringList.disableCompact - Y_SI__YJbb */
 (Tc*)0, /* MARGModule__CStringList.optionalArg - Y_SI__YxuH */
 (Tc*)0, /* MARGModule__CStringList.presentCount - Y_SI__Ye9f */
 (Tc*)0, /* MARGModule__CStringList.present - Y_SI__Y8Dq */
 (Tc*)0, /* Vcurrent */
 (Tc*)0, /* Vdefault */
 (Tc*)YSkKa, /* MARGModule__CStringList.setToDefault - YSkKa */
 (Tc*)0, /* MARGModule__CStringList.get - YEKc */
 (Tc*)0, /* MARGModule__CStringList.value - YSNX */
 (Tc*)0, /* Init - Y_SIa */
};
To ToY_SI[] = {
 {7, 0},
 {0, (Tt*)&list__T}, /* current */
 {0, (Tt*)&list__T}, /* default */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y_SI__T = {390, (Tc*)&Ygf5, 0, ToY_SI};
int JARGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf={0,topFrame};
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
/* including zimbuConfig bodies */
/* including Proto bodies */
Ys_q *Ys_q__YwtA__YRHR(Ys_q *t, Tc *Amsg) { /* MProto__CE_ProduceError.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=7083300; t = Zamt(sizeof(Ys_q), Ys_q__mt);}
 sf.pos=7083301;
 t->Vmessage = Amsg;
 sf.pos=7083302;
 t->Vpos = MZ__callerPos();
 sf.pos=7083303;
 t->Vbacktrace = (sf.pos=7083304, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Ys_q__mt[] = {
 (Tc*)&Ys_q__T,
 (Tc*)29,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MProto__CE_ProduceError.ToString - YH0V */
 (Tc*)YxaJa, /* MProto__CE_ProduceError.writeTo - YxaJa */
 (Tc*)YxaJ, /* MProto__CE_ProduceError.writeTo - YxaJ */
 (Tc*)0, /* MProto__CE_ProduceError.toString - Yoww */
 (Tc*)0, /* MProto__CE_ProduceError.getMessage - YCzX */
 (Tc*)0, /* MProto__CE_ProduceError.getPos - YvCK */
 (Tc*)0, /* MProto__CE_ProduceError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Ys_qa */
 (Tc*)0, /* MProto__CE_ProduceError.ToString - YH0V */
 (Tc*)0, /* MProto__CE_ProduceError.toString - Yoww */
 (Tc*)0, /* MProto__CE_ProduceError.getMessage - YCzX */
 (Tc*)0, /* MProto__CE_ProduceError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Ys_qa */
 (Tc*)YxaJ, /* MProto__CE_ProduceError.writeTo - YxaJ */
 (Tc*)YxaJa, /* MProto__CE_ProduceError.writeTo - YxaJa */
 (Tc*)0, /* MProto__CE_ProduceError.getPos - YvCK */
 (Tc*)0, /* MProto__CE_ProduceError.ToString - YH0V */
 (Tc*)0, /* MProto__CE_ProduceError.toString - Yoww */
 (Tc*)0, /* MProto__CE_ProduceError.getMessage - YCzX */
 (Tc*)0, /* MProto__CE_ProduceError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Ys_qa */
 (Tc*)YxaJa, /* MProto__CE_ProduceError.writeTo - YxaJa */
 (Tc*)YxaJ, /* MProto__CE_ProduceError.writeTo - YxaJ */
 (Tc*)0, /* MProto__CE_ProduceError.getPos - YvCK */
};
To ToYs_q[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Ys_q__T = {390, (Tc*)&Y4sk, 0, ToYs_q};
YOEA *YOEA__YwtA__YRHR(YOEA *t, Tc *Amsg) { /* MProto__CE_BinaryError.NEW__p2 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=4631200; t = Zamt(sizeof(YOEA), YOEA__mt);}
 sf.pos=4631201;
 t->Vmessage = Amsg;
 sf.pos=4631202;
 t->Vpos = MZ__callerPos();
 sf.pos=4631203;
 t->Vbacktrace = (sf.pos=4631204, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YOEA__mt[] = {
 (Tc*)&YOEA__T,
 (Tc*)30,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MProto__CE_BinaryError.ToString - YH0V */
 (Tc*)YxaJa, /* MProto__CE_BinaryError.writeTo - YxaJa */
 (Tc*)YxaJ, /* MProto__CE_BinaryError.writeTo - YxaJ */
 (Tc*)0, /* MProto__CE_BinaryError.toString - Yoww */
 (Tc*)0, /* MProto__CE_BinaryError.getMessage - YCzX */
 (Tc*)0, /* MProto__CE_BinaryError.getPos - YvCK */
 (Tc*)0, /* MProto__CE_BinaryError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YOEAa */
 (Tc*)0, /* MProto__CE_BinaryError.ToString - YH0V */
 (Tc*)0, /* MProto__CE_BinaryError.toString - Yoww */
 (Tc*)0, /* MProto__CE_BinaryError.getMessage - YCzX */
 (Tc*)0, /* MProto__CE_BinaryError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YOEAa */
 (Tc*)YxaJ, /* MProto__CE_BinaryError.writeTo - YxaJ */
 (Tc*)YxaJa, /* MProto__CE_BinaryError.writeTo - YxaJa */
 (Tc*)0, /* MProto__CE_BinaryError.getPos - YvCK */
 (Tc*)0, /* MProto__CE_BinaryError.ToString - YH0V */
 (Tc*)0, /* MProto__CE_BinaryError.toString - Yoww */
 (Tc*)0, /* MProto__CE_BinaryError.getMessage - YCzX */
 (Tc*)0, /* MProto__CE_BinaryError.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YOEAa */
 (Tc*)YxaJa, /* MProto__CE_BinaryError.writeTo - YxaJa */
 (Tc*)YxaJ, /* MProto__CE_BinaryError.writeTo - YxaJ */
 (Tc*)0, /* MProto__CE_BinaryError.getPos - YvCK */
};
To ToYOEA[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YOEA__T = {390, (Tc*)&YtJ_, 0, ToYOEA};
YqvM *Ykww(YqvM *t, Tc *Aname, Ti Anr, Te Atype, Tb Arepeated) { /* MProto__CFieldSpec.NEW */
 Zsf sf={0,topFrame};
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
YLWE *YrCUb(YLWE *t, Tr Awriter, Tc *Aindent, Tb AuseNr) { /* MProto__CWriter.NEW */
 Zsf sf={0,topFrame};
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
void YEV9(YLWE *t) { /* MProto__CWriter.initDeref */
 Zsf sf={0,topFrame};
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
Ti Ybyp(YqvM *Afspec) { /* MProto.getBinaryTagSize */
 Ti Vtag;
 Zsf sf={0,topFrame};
 Ti r = 0;
 topFrame = &sf;
 sf.pos=4959900;
 Vtag = (((Afspec->Vnr << YqNA)) + ZDictGetInt(YLwW, (Tz)(Ti)ZDictGetInt(YXCQ, (Tz)(Ti)Afspec->Vtype)));
 sf.pos=4959901;
 r = YmeT(Vtag);
 topFrame = sf.prev;
 return r;
}
Ti YFN0(YFL0 *Amsg, YLWE *AprotoWriter) { /* MProto.binarySize */
 Ti Vsize;
 Zsf sf={0,topFrame};
 Ti r = 0;
 Tl *Zf1 = NULL;
 Tc *Vs = NULL;
 Tc *Vs1 = NULL;
 YFL0 *Vother = NULL;
 Tc *Vs2 = NULL;
 Tc *Vs3 = NULL;
 YFL0 *Vother1 = NULL;
 YqvM *Vfspec = 0;
 topFrame = &sf;
 Vsize = 0;
 sf.pos=9067900;
 {
  Tfl Zf1i;
  Zf1 = ((Tl* (*)(void*))(Amsg->mt[47]))(Amsg);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vfspec;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=9067901;
  if (Vfspec->Vrepeated)
  {
   Ti Vcount;
   sf.pos=9067902;
   Vcount = ((Ti (*)(void*, Ti))(Amsg->mt[46]))(Amsg, Vfspec->Vnr);
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
      Vsize += YmeT(((Ti (*)(void*, Ti, Ti))(Amsg->mt[12]))(Amsg, Vfspec->Vnr, Vi));
       break;
     }
     case 10:
     {
      sf.pos=9067907;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067908;
      Vsize += YmeT(((Ti32 (*)(void*, Ti, Ti))(Amsg->mt[14]))(Amsg, Vfspec->Vnr, Vi));
       break;
     }
     case 19:
     {
      Ti Vv;
      sf.pos=9067909;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067910;
      Vv = ((Tu (*)(void*, Ti, Ti))(Amsg->mt[16]))(Amsg, Vfspec->Vnr, Vi);
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
      Vv = ((Tu32 (*)(void*, Ti, Ti))(Amsg->mt[18]))(Amsg, Vfspec->Vnr, Vi);
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
      Vs = ((Tc* (*)(void*, Ti, Ti))(Amsg->mt[26]))(Amsg, Vfspec->Vnr, Vi);
      sf.pos=9067923;
      Vlen = ZbyteStringSize(Vs);
      sf.pos=9067924;
      Vsize += (YmeT(Vlen) + Vlen);
       break;
     }
     case 2:
     {
      Ti Vlen;
      sf.pos=9067925;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067926;
      Vs1 = ((Tc* (*)(void*, Ti, Ti))(Amsg->mt[28]))(Amsg, Vfspec->Vnr, Vi);
      sf.pos=9067927;
      Vlen = ZbyteStringSize(Vs1);
      sf.pos=9067928;
      Vsize += (YmeT(Vlen) + Vlen);
       break;
     }
     case 3:
     {
      Ti Vnr;
      sf.pos=9067929;
      Vnr = ((Ti (*)(void*, Ti, Ti))(Amsg->mt[8]))(Amsg, Vfspec->Vnr, Vi);
      sf.pos=9067930;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067931;
      Vsize += YmeT((((Vnr < 0)) ? (0) : (Vnr)));
       break;
     }
     case 12:
     {
      sf.pos=9067932;
      Vother = ((YFL0* (*)(void*, Ti, Ti))(Amsg->mt[41]))(Amsg, Vfspec->Vnr, Vi);
      sf.pos=9067933;
      Vsize += YMrV(Amsg, Vother, Vfspec, AprotoWriter);
       break;
     }
    default:
     {
      Ytlm *ex;
      sf.pos=9067934;
      ex = (Ytlm*)YOEA__YwtA__YRHR(NULL, ZcS(((Tc*)&Ytvm), Zenum2string(MProto__EType, Vfspec->Vtype)));
      ZthrowIobject(ex);
     }
    }
    sf.pos=9067935;
    }
   }
  }
  else
  {
   sf.pos=9067936;
   if (((Tb (*)(void*, Ti))(Amsg->mt[6]))(Amsg, Vfspec->Vnr))
   {
    sf.pos=9067937;
    switch (Vfspec->Vtype)
    {
     case 9:
     case 11:
     {
      sf.pos=9067938;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067939;
      Vsize += YmeT(((Ti (*)(void*, Ti))(Amsg->mt[13]))(Amsg, Vfspec->Vnr));
       break;
     }
     case 10:
     {
      sf.pos=9067940;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067941;
      Vsize += YmeT(((Ti32 (*)(void*, Ti))(Amsg->mt[15]))(Amsg, Vfspec->Vnr));
       break;
     }
     case 19:
     {
      Ti Vv;
      sf.pos=9067942;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067943;
      Vv = ((Tu (*)(void*, Ti))(Amsg->mt[17]))(Amsg, Vfspec->Vnr);
      sf.pos=9067944;
      Vsize += YmeT(Vv);
       break;
     }
     case 18:
     {
      Ti Vv;
      sf.pos=9067945;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067946;
      Vv = ((Tu32 (*)(void*, Ti))(Amsg->mt[19]))(Amsg, Vfspec->Vnr);
      sf.pos=9067947;
      Vsize += YmeT(Vv);
       break;
     }
     case 6:
     {
      sf.pos=9067948;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067949;
      Vsize += 4;
       break;
     }
     case 7:
     {
      sf.pos=9067950;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067951;
      Vsize += 8;
       break;
     }
     case 1:
     {
      sf.pos=9067952;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067953;
      Vsize += 1;
       break;
     }
     case 17:
     {
      Ti Vlen;
      sf.pos=9067954;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067955;
      Vs2 = ((Tc* (*)(void*, Ti))(Amsg->mt[27]))(Amsg, Vfspec->Vnr);
      sf.pos=9067956;
      Vlen = ZbyteStringSize(Vs2);
      sf.pos=9067957;
      Vsize += (YmeT(Vlen) + Vlen);
       break;
     }
     case 2:
     {
      Ti Vlen;
      sf.pos=9067958;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067959;
      Vs3 = ((Tc* (*)(void*, Ti))(Amsg->mt[29]))(Amsg, Vfspec->Vnr);
      sf.pos=9067960;
      Vlen = ZbyteStringSize(Vs3);
      sf.pos=9067961;
      Vsize += (YmeT(Vlen) + Vlen);
       break;
     }
     case 3:
     {
      Ti Vnr;
      sf.pos=9067962;
      Vnr = ((Ti (*)(void*, Ti))(Amsg->mt[9]))(Amsg, Vfspec->Vnr);
      sf.pos=9067963;
      Vsize += Ybyp(Vfspec);
      sf.pos=9067964;
      Vsize += YmeT((((Vnr < 0)) ? (0) : (Vnr)));
       break;
     }
     case 12:
     {
      sf.pos=9067965;
      Vother1 = ((YFL0* (*)(void*, Ti))(Amsg->mt[42]))(Amsg, Vfspec->Vnr);
      sf.pos=9067966;
      Vsize += YMrV(Amsg, Vother1, Vfspec, AprotoWriter);
       break;
     }
    default:
     {
      Ytlm *ex;
      sf.pos=9067967;
      ex = (Ytlm*)YOEA__YwtA__YRHR(NULL, ZcS(((Tc*)&Ytvm), Zenum2string(MProto__EType, Vfspec->Vtype)));
      ZthrowIobject(ex);
     }
    }
   }
  }
  sf.pos=9067968;
  }
 }
 sf.pos=9067969;
 r = Vsize;
 topFrame = sf.prev;
 return r;
}
Ti YMrV(YFL0 *At, YFL0 *Amsg, YqvM *Afspec, YLWE *AprotoWriter) { /* MProto.binaryMessageSize */
 Ti Vsize;
 Zsf sf={0,topFrame};
 Ti r = 0;
 YqvM *VintFspec = 0;
 topFrame = &sf;
 Vsize = 0;
 sf.pos=3788400;
 if ((Amsg == (void *)NULL))
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
   if (((*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[2])) == AprotoWriter->VderefTime))
   {
    sf.pos=3788406;
    Vid = (*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[3]));
   }
   else {
   sf.pos=3788407;
   if (((*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[4])) == AprotoWriter->VderefTimeSize))
   {
    sf.pos=3788408;
    Vid = (*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[5]));
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
    (*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[4])) = AprotoWriter->VderefTimeSize;
    sf.pos=3788415;
    (*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[5])) = ++(AprotoWriter->VderefIdSize);
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
void YP8Z(YFL0 *Amsg, YLWE *AprotoWriter) { /* MProto.writeText */
 Zsf sf={0,topFrame};
 Tl *Zf2 = NULL;
 YqvM *Vfspec = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 topFrame = &sf;
 sf.pos=1929900;
 if ((AprotoWriter->Vindent != NULL))
 {
  Tr YCSo = {NULL,NULL,-1};
  sf.pos=1929901;
  (YCSo = AprotoWriter->Vwriter, ((Ts (*)(void*, Tc*))(YCSo.table[1]))(YCSo.ptr, AprotoWriter->Vindent));
 }
 sf.pos=1929902;
 if (((*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[2])) == AprotoWriter->VderefTime))
 {
  Tr YDSo = {NULL,NULL,-1};
  sf.pos=1929903;
  (YDSo = AprotoWriter->Vwriter, ((Ts (*)(void*, Tc*))(YDSo.table[1]))(YDSo.ptr, ZcS5(((Tc*)&YvJi), ((Tc* (*)(void*))(Amsg->mt[7]))(Amsg), ((Tc*)&YT), (t0 = Zint2string((*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[3])))), ((Tc*)&Yk))));
 }
 else
 {
  Tr YESo = {NULL,NULL,-1};
  sf.pos=1929904;
  (*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[2])) = AprotoWriter->VderefTime;
  sf.pos=1929905;
  (*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[3])) = ++(AprotoWriter->VderefId);
  sf.pos=1929906;
  (YESo = AprotoWriter->Vwriter, ((Ts (*)(void*, Tc*))(YESo.table[1]))(YESo.ptr, ZcS8(((Tc*)&YN2), ((Tc* (*)(void*))(Amsg->mt[7]))(Amsg), ((Tc*)&YT), (t0 = Zint2string((*(Ti*)((Tc*)Amsg + (size_t)Amsg->mt[3])))), ((Tc*)&Y0Eh), (t1 = Zint2string(YFN0(Amsg, AprotoWriter))), ((Tc*)&Y8RH), (Tc*)1)));
  sf.pos=1929907;
  {
   Tfl Zf2i;
   Zf2 = ((Tl* (*)(void*))(Amsg->mt[47]))(Amsg);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vfspec;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1929908;
   if (Vfspec->Vrepeated)
   {
    Ti Vn;
    sf.pos=1929909;
    Vn = ((Ti (*)(void*, Ti))(Amsg->mt[46]))(Amsg, Vfspec->Vnr);
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
   if (((Tb (*)(void*, Ti))(Amsg->mt[6]))(Amsg, Vfspec->Vnr))
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
void YWEg(YFL0 *Amsg, YqvM *Afspec, Ti Aidx, YLWE *AprotoWriter) { /* MProto.writeOneTextField */
 Zsf sf={0,topFrame};
 Tr Vwriter = {NULL,0,-1};
 Tc *Vv = NULL;
 Tc *Vv1 = NULL;
 Tc *Vname = NULL;
 Tc *Vindent = NULL;
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
    Vv = ((Ti (*)(void*, Ti, Ti))(Amsg->mt[12]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472909;
    Vv = ((Ti (*)(void*, Ti))(Amsg->mt[13]))(Amsg, Afspec->Vnr);
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
    Vv = ((Ti32 (*)(void*, Ti, Ti))(Amsg->mt[14]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472913;
    Vv = ((Ti32 (*)(void*, Ti))(Amsg->mt[15]))(Amsg, Afspec->Vnr);
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
    Vv = ((Tu (*)(void*, Ti, Ti))(Amsg->mt[16]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472917;
    Vv = ((Tu (*)(void*, Ti))(Amsg->mt[17]))(Amsg, Afspec->Vnr);
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
    Vv = ((Tu32 (*)(void*, Ti, Ti))(Amsg->mt[18]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472921;
    Vv = ((Tu32 (*)(void*, Ti))(Amsg->mt[19]))(Amsg, Afspec->Vnr);
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
    Vf = ((Tf32 (*)(void*, Ti, Ti))(Amsg->mt[20]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472925;
    Vf = ((Tf32 (*)(void*, Ti))(Amsg->mt[21]))(Amsg, Afspec->Vnr);
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
    Vf = ((Tf (*)(void*, Ti, Ti))(Amsg->mt[22]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472929;
    Vf = ((Tf (*)(void*, Ti))(Amsg->mt[23]))(Amsg, Afspec->Vnr);
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
    Vv = ((Tb (*)(void*, Ti, Ti))(Amsg->mt[24]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472933;
    Vv = ((Tb (*)(void*, Ti))(Amsg->mt[25]))(Amsg, Afspec->Vnr);
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
    Vv = ((Tc* (*)(void*, Ti, Ti))(Amsg->mt[26]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472937;
    Vv = ((Tc* (*)(void*, Ti))(Amsg->mt[27]))(Amsg, Afspec->Vnr);
   }
   sf.pos=9472938;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS3(((Tc*)&YI), Vv, ((Tc*)&YQ0)));
    break;
  }
  case 2:
  {
   sf.pos=9472939;
   if ((Aidx >= 0))
   {
    sf.pos=9472940;
    Vv1 = ((Tc* (*)(void*, Ti, Ti))(Amsg->mt[28]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472941;
    Vv1 = ((Tc* (*)(void*, Ti))(Amsg->mt[29]))(Amsg, Afspec->Vnr);
   }
   sf.pos=9472942;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS3(((Tc*)&YI), YyEq(Vv1), ((Tc*)&YQ0)));
    break;
  }
  case 3:
  {
   sf.pos=9472943;
   if (AprotoWriter->VuseNr)
   {
    Ti Vv;
    Vv = 0;
    sf.pos=9472944;
    if ((Aidx >= 0))
    {
     sf.pos=9472945;
     Vv = ((Ti (*)(void*, Ti, Ti))(Amsg->mt[8]))(Amsg, Afspec->Vnr, Aidx);
    }
    else
    {
     sf.pos=9472946;
     Vv = ((Ti (*)(void*, Ti))(Amsg->mt[9]))(Amsg, Afspec->Vnr);
    }
    sf.pos=9472947;
    ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(Vv), ((Tc*)&YT)));
   }
   sf.pos=9472948;
   if ((Aidx >= 0))
   {
    sf.pos=9472949;
    Vname = ((Tc* (*)(void*, Ti, Ti))(Amsg->mt[10]))(Amsg, Afspec->Vnr, Aidx);
   }
   else
   {
    sf.pos=9472950;
    Vname = ((Tc* (*)(void*, Ti))(Amsg->mt[11]))(Amsg, Afspec->Vnr);
   }
   sf.pos=9472951;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Vname, ((Tc*)&Yk)));
    break;
  }
  case 12:
  {
   sf.pos=9472952;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&Ywhc));
   sf.pos=9472953;
   Vindent = AprotoWriter->Vindent;
   sf.pos=9472954;
   if ((Vindent != NULL))
   {
    sf.pos=9472955;
    AprotoWriter->Vindent = ZcS(Vindent, ((Tc*)&YZY));
   }
   sf.pos=9472956;
   if ((Aidx >= 0))
   {
    sf.pos=9472957;
    YeeBa(Amsg, Afspec->Vnr, Aidx, AprotoWriter);
   }
   else
   {
    sf.pos=9472958;
    YeeB(Amsg, Afspec->Vnr, AprotoWriter);
   }
   sf.pos=9472959;
   AprotoWriter->Vindent = Vindent;
   sf.pos=9472960;
   if ((Vindent != NULL))
   {
    sf.pos=9472961;
    ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, Vindent);
   }
   sf.pos=9472962;
   ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YJkc));
    break;
  }
 default:
  {
   Ytlm *ex;
   sf.pos=9472963;
   ex = (Ytlm*)Ys_q__YwtA__YRHR(NULL, ZcS(((Tc*)&Y80t), Zenum2string(MProto__EType, Afspec->Vtype)));
   ZthrowIobject(ex);
  }
 }
 topFrame = sf.prev;
 return;
}
void YeeB(YFL0 *At, Ti AfieldNr, YLWE *AprotoWriter) { /* MProto.writeMessageText */
 Zsf sf={0,topFrame};
 YFL0 *Vmsg = NULL;
 topFrame = &sf;
 sf.pos=6491200;
 Vmsg = ((YFL0* (*)(void*, Ti))(At->mt[42]))(At, AfieldNr);
 sf.pos=6491201;
 if ((Vmsg != (void *)NULL))
 {
  sf.pos=6491202;
  YP8Z(Vmsg, AprotoWriter);
 }
 topFrame = sf.prev;
 return;
}
void YeeBa(YFL0 *At, Ti AfieldNr, Ti Aidx, YLWE *AprotoWriter) { /* MProto.writeMessageText */
 Zsf sf={0,topFrame};
 YFL0 *Vmsg = NULL;
 topFrame = &sf;
 sf.pos=7198800;
 Vmsg = ((YFL0* (*)(void*, Ti, Ti))(At->mt[41]))(At, AfieldNr, Aidx);
 sf.pos=7198801;
 if ((Vmsg != (void *)NULL))
 {
  sf.pos=7198802;
  YP8Z(Vmsg, AprotoWriter);
 }
 topFrame = sf.prev;
 return;
}
Ti YmeT(Ti Avalue) { /* MProto.getVarIntSize */
 Ti Vbytes;
 Zsf sf={0,topFrame};
 Ti r = 0;
 int rt = 0;
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
  Zsf sf={0,topFrame};
  topFrame = &sf;
  round_done = round;
  if (round == 2001) {
   sf.pos=3053200;
   YXCQ = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MProto__EType__T, (Tt*)&MProto__EBinaryType__T, 0), (Tz)(Ti)1, (Tz)(Ti)0), (Tz)(Ti)9, (Tz)(Ti)0), (Tz)(Ti)11, (Tz)(Ti)0), (Tz)(Ti)10, (Tz)(Ti)0), (Tz)(Ti)19, (Tz)(Ti)0), (Tz)(Ti)18, (Tz)(Ti)0), (Tz)(Ti)17, (Tz)(Ti)2), (Tz)(Ti)2, (Tz)(Ti)2), (Tz)(Ti)3, (Tz)(Ti)0), (Tz)(Ti)12, (Tz)(Ti)2), (Tz)(Ti)6, (Tz)(Ti)5), (Tz)(Ti)7, (Tz)(Ti)1);
   sf.pos=3053201;
   YLwW = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MProto__EBinaryType__T, (Tt*)&int__T, 0), (Tz)(Ti)0, (Tz)(Ti)0), (Tz)(Ti)1, (Tz)(Ti)1), (Tz)(Ti)2, (Tz)(Ti)2), (Tz)(Ti)3, (Tz)(Ti)3), (Tz)(Ti)4, (Tz)(Ti)4), (Tz)(Ti)5, (Tz)(Ti)5);
  }
  topFrame = sf.prev;
 }
 return done;
}
/* Proto done */
YNdL *YA_Z(YNdL *t) { /* MZimbu__CConfig.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=2763200; t = Zamt(sizeof(YNdL), YNdL__mt);}
 topFrame = sf.prev;
 return t;
}
Tc *Ykvoa(YNdL *t) { /* MZimbu__CConfig.name */
 Tc *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((Tc*)&YF2d);
 return r;
}
YNdL *YrF2(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setMallocArg */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_mallocArg = Av;
 r = t;
 return r;
}
Tb Y8zW(YNdL *t) { /* MZimbu__CConfig.hasMallocArg */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_mallocArg != NULL);
 return r;
}
YNdL *YOPG(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setThreadArg */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_threadArg = Av;
 r = t;
 return r;
}
Tb YvKz(YNdL *t) { /* MZimbu__CConfig.hasThreadArg */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_threadArg != NULL);
 return r;
}
YNdL *YWoP(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setSocketArg */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_socketArg = Av;
 r = t;
 return r;
}
Tb YDjI(YNdL *t) { /* MZimbu__CConfig.hasSocketArg */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_socketArg != NULL);
 return r;
}
YNdL *Yjrt(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setMathArg */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_mathArg = Av;
 r = t;
 return r;
}
Tb Y8om(YNdL *t) { /* MZimbu__CConfig.hasMathArg */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_mathArg != NULL);
 return r;
}
YNdL *YMyf(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setPcreArg */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pcreArg = Av;
 r = t;
 return r;
}
Tb YGhA(YNdL *t) { /* MZimbu__CConfig.hasPcreArg */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_pcreArg != NULL);
 return r;
}
YNdL *Yqt5(YNdL *t, Tb Av) { /* MZimbu__CConfig.setHaveResolve */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_haveResolve = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb Y3Lr(YNdL *t) { /* MZimbu__CConfig.hasHaveResolve */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_haveResolve != 0);
 return r;
}
YNdL *YBhB(YNdL *t, Tb Av) { /* MZimbu__CConfig.setHaveFork */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_haveFork = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YcPw(YNdL *t) { /* MZimbu__CConfig.hasHaveFork */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_haveFork != 0);
 return r;
}
YNdL *YNXX(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setExeSuffix */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_exeSuffix = Av;
 r = t;
 return r;
}
Tb YuSQ(YNdL *t) { /* MZimbu__CConfig.hasExeSuffix */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_exeSuffix != NULL);
 return r;
}
YNdL *YcU3(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setExePrefix */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_exePrefix = Av;
 r = t;
 return r;
}
Tb YUOX(YNdL *t) { /* MZimbu__CConfig.hasExePrefix */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_exePrefix != NULL);
 return r;
}
YNdL *Y118(YNdL *t, Tb Av) { /* MZimbu__CConfig.setHaveSigaction */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_haveSigaction = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YJrk(YNdL *t) { /* MZimbu__CConfig.hasHaveSigaction */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_haveSigaction != 0);
 return r;
}
YNdL *YEDn(YNdL *t, Tb Av) { /* MZimbu__CConfig.setGcWithThreads */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_gcWithThreads = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb Yo45(YNdL *t) { /* MZimbu__CConfig.hasGcWithThreads */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_gcWithThreads != 0);
 return r;
}
YNdL *YIIX(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setInt16Name */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_int16Name = Av;
 r = t;
 return r;
}
Tb YpDQ(YNdL *t) { /* MZimbu__CConfig.hasInt16Name */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_int16Name != NULL);
 return r;
}
YNdL *Y8TB(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setInt32Name */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_int32Name = Av;
 r = t;
 return r;
}
Tb YQOu(YNdL *t) { /* MZimbu__CConfig.hasInt32Name */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_int32Name != NULL);
 return r;
}
YNdL *Y6PM(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setInt64Name */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_int64Name = Av;
 r = t;
 return r;
}
Tb YOKF(YNdL *t) { /* MZimbu__CConfig.hasInt64Name */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_int64Name != NULL);
 return r;
}
YNdL *YXzR(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setNat16Name */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_nat16Name = Av;
 r = t;
 return r;
}
Tb YEuK(YNdL *t) { /* MZimbu__CConfig.hasNat16Name */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_nat16Name != NULL);
 return r;
}
YNdL *YnLv(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setNat32Name */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_nat32Name = Av;
 r = t;
 return r;
}
Tb Y4Fo(YNdL *t) { /* MZimbu__CConfig.hasNat32Name */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_nat32Name != NULL);
 return r;
}
YNdL *YlHG(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setNat64Name */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_nat64Name = Av;
 r = t;
 return r;
}
Tb Y2Bz(YNdL *t) { /* MZimbu__CConfig.hasNat64Name */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_nat64Name != NULL);
 return r;
}
YNdL *Yla2(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setFloatName */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_floatName = Av;
 r = t;
 return r;
}
Tb Y24V(YNdL *t) { /* MZimbu__CConfig.hasFloatName */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_floatName != NULL);
 return r;
}
YNdL *YI4N(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setFloat32Name */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_float32Name = Av;
 r = t;
 return r;
}
Tb YftC(YNdL *t) { /* MZimbu__CConfig.hasFloat32Name */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_float32Name != NULL);
 return r;
}
YNdL *YJ6V(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setIntPtrName */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_intPtrName = Av;
 r = t;
 return r;
}
Tb YTxb(YNdL *t) { /* MZimbu__CConfig.hasIntPtrName */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_intPtrName != NULL);
 return r;
}
YNdL *YUld(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setPrintIntFormat */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_printIntFormat = Av;
 r = t;
 return r;
}
Tb YlFq(YNdL *t) { /* MZimbu__CConfig.hasPrintIntFormat */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_printIntFormat != NULL);
 return r;
}
YNdL *Y8c7(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setPrintNatFormat */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_printNatFormat = Av;
 r = t;
 return r;
}
Tb Y6Nw(YNdL *t) { /* MZimbu__CConfig.hasPrintNatFormat */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_printNatFormat != NULL);
 return r;
}
YNdL *YRMv(YNdL *t, Tc *Av) { /* MZimbu__CConfig.setScanfHexFormat */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_scanfHexFormat = Av;
 r = t;
 return r;
}
Tb Yoe8(YNdL *t) { /* MZimbu__CConfig.hasScanfHexFormat */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_scanfHexFormat != NULL);
 return r;
}
YNdL *YeB5(YNdL *t, Tb Av) { /* MZimbu__CConfig.setIsMingw */
 YNdL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_isMingw = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YdfK(YNdL *t) { /* MZimbu__CConfig.hasIsMingw */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_isMingw != 0);
 return r;
}
Tb YFKUa(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.boolGet */
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
Tc *Yxv3a(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.stringGet */
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
  case 11:
  {
   r = t->Vf_pcreArg;
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
Tb YlZca(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.hasField */
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
  case 11:
  {
   r = YGhA(t);
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
Tl *Yozoa(YNdL *t) { /* MZimbu__CConfig.fieldSpecs */
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = YR6X;
 return r;
}
Ti YNdL__Y0zD(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.enumGet__p1 */
 Zsf sf={0,topFrame};
 Ti r = 0;
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
Ti YNdL__Y0zDa(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.enumGet__p1 */
 Zsf sf={0,topFrame};
 Ti r = 0;
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
Tc *YNdL__YytN(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.enumNameGet__p1 */
 Zsf sf={0,topFrame};
 Tc *r = 0;
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
Tc *YNdL__YytNa(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.enumNameGet__p1 */
 Zsf sf={0,topFrame};
 Tc *r = 0;
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
Ti YNdL__YGR8(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.intGet__p1 */
 Zsf sf={0,topFrame};
 Ti r = 0;
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
Ti YNdL__YGR8a(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.intGet__p1 */
 Zsf sf={0,topFrame};
 Ti r = 0;
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
Ti32 YNdL__YAAo(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.int32Get__p1 */
 Zsf sf={0,topFrame};
 Ti32 r = 0;
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
Ti32 YNdL__YAAoa(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.int32Get__p1 */
 Zsf sf={0,topFrame};
 Ti32 r = 0;
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
Tu YNdL__YRqV(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.uint64Get__p1 */
 Zsf sf={0,topFrame};
 Tu r = 0;
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
Tu YNdL__YRqVa(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.uint64Get__p1 */
 Zsf sf={0,topFrame};
 Tu r = 0;
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
Tu32 YNdL__Y0tE(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.uint32Get__p1 */
 Zsf sf={0,topFrame};
 Tu32 r = 0;
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
Tu32 YNdL__Y0tEa(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.uint32Get__p1 */
 Zsf sf={0,topFrame};
 Tu32 r = 0;
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
Tf32 YNdL__Yyt7(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.floatGet__p1 */
 Zsf sf={0,topFrame};
 Tf32 r = 0;
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
Tf32 YNdL__Yyt7a(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.floatGet__p1 */
 Zsf sf={0,topFrame};
 Tf32 r = 0;
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
Tf YNdL__Yybv(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.doubleGet__p1 */
 Zsf sf={0,topFrame};
 Tf r = 0;
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
Tf YNdL__Yybva(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.doubleGet__p1 */
 Zsf sf={0,topFrame};
 Tf r = 0;
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
Tb YNdL__YGfza(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.boolGet__p1 */
 Zsf sf={0,topFrame};
 Tb r = 0;
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
Tc *YNdL__YsRaa(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.stringGet__p1 */
 Zsf sf={0,topFrame};
 Tc *r = 0;
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
Tc *YNdL__YlHQ(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.bytesGet__p1 */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3305200;
  ZthrowThisNil();
 }
 sf.pos=3305201;
 r = ((Tc*)&Ya);
 topFrame = sf.prev;
 return r;
}
Tc *YNdL__YlHQa(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.bytesGet__p1 */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4325300;
  ZthrowThisNil();
 }
 sf.pos=4325301;
 r = ((Tc*)&Ya);
 topFrame = sf.prev;
 return r;
}
YFL0 *YNdL__Yo5y(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.messageGet__p1 */
 Zsf sf={0,topFrame};
 YFL0 *r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9575000;
  ZthrowThisNil();
 }
 sf.pos=9575001;
 r = NULL;
 topFrame = sf.prev;
 return r;
}
YFL0 *YNdL__Yo5ya(YNdL *t, Ti AfieldNr, Ti Aidx) { /* MZimbu__CConfig.messageGet__p1 */
 Zsf sf={0,topFrame};
 YFL0 *r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=595100;
  ZthrowThisNil();
 }
 sf.pos=595101;
 r = NULL;
 topFrame = sf.prev;
 return r;
}
Ti YNdL__YUDN(YNdL *t, Ti AfieldNr) { /* MZimbu__CConfig.size__p1 */
 Zsf sf={0,topFrame};
 Ti r = 0;
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
Tc *YNdL__YC5i(YNdL *t) { /* MZimbu__CConfig.ToString__p1 */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 YjUM *Vwriter = 0;
 YLWE *VprotoWriter = 0;
 Tr t0 = {NULL,0,-1};
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7979400;
  ZthrowThisNil();
 }
 sf.pos=7979401;
 Vwriter = Zamt(sizeof(YjUM), YjUM__mt);
 sf.pos=7979402;
 VprotoWriter = YrCUb(NULL, *Znao(&t0, Vwriter, YjUM__YdXi_imt, 2), ((Tc*)&Ya), 0);
 sf.pos=7979403;
 YP8Z((YFL0*)t, VprotoWriter);
 sf.pos=7979404;
 r = YbNW((YjUM *)Vwriter);
 topFrame = sf.prev;
 return r;
}
Tc *YNdL__mt[] = {
 (Tc*)&YNdL__T,
 (Tc*)1,
 (Tc*)0, /* VderefTime */
 (Tc*)0, /* VderefId */
 (Tc*)0, /* VderefTimeSize */
 (Tc*)0, /* VderefIdSize */
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
 (Tc*)YNdL__YlHQa, /* MZimbu__CConfig.bytesGet - YNdL__YlHQa */
 (Tc*)YNdL__YlHQ, /* MZimbu__CConfig.bytesGet - YNdL__YlHQ */
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
 (Tc*)0, /* MZimbu__CConfig.bytesSet - YNdL__Yoxk */
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
 (Tc*)0, /* MZimbu__CConfig.Compare - YNdL__YSzC */
 (Tc*)0, /* MZimbu__CConfig.merge - YNdL__Y98G */
 (Tc*)0, /* MZimbu__CConfig.writeBinary - YNdL__YpSR */
 (Tc*)0, /* MZimbu__CConfig.writeBinaryDeref - YNdL__Yz9e */
 (Tc*)0, /* MZimbu__CConfig.toJson - YNdL__Y3fy */
 (Tc*)0, /* MZimbu__CConfig.writeJson - YNdL__YVaR */
 (Tc*)0, /* MZimbu__CConfig.writeJsonDeref - YNdL__YgZk */
 (Tc*)0, /* Init - YNdLa */
 (Tc*)YlZca, /* MZimbu__CConfig.hasField - YlZca */
 (Tc*)Ykvoa, /* MZimbu__CConfig.name - Ykvoa */
 (Tc*)YNdL__Y0zD, /* MZimbu__CConfig.enumGet - YNdL__Y0zD */
 (Tc*)YNdL__Y0zDa, /* MZimbu__CConfig.enumGet - YNdL__Y0zDa */
 (Tc*)YNdL__YytN, /* MZimbu__CConfig.enumNameGet - YNdL__YytN */
 (Tc*)YNdL__YytNa, /* MZimbu__CConfig.enumNameGet - YNdL__YytNa */
 (Tc*)YNdL__YGR8, /* MZimbu__CConfig.intGet - YNdL__YGR8 */
 (Tc*)YNdL__YGR8a, /* MZimbu__CConfig.intGet - YNdL__YGR8a */
 (Tc*)YNdL__YAAo, /* MZimbu__CConfig.int32Get - YNdL__YAAo */
 (Tc*)YNdL__YAAoa, /* MZimbu__CConfig.int32Get - YNdL__YAAoa */
 (Tc*)YNdL__YRqV, /* MZimbu__CConfig.uint64Get - YNdL__YRqV */
 (Tc*)YNdL__YRqVa, /* MZimbu__CConfig.uint64Get - YNdL__YRqVa */
 (Tc*)YNdL__Y0tE, /* MZimbu__CConfig.uint32Get - YNdL__Y0tE */
 (Tc*)YNdL__Y0tEa, /* MZimbu__CConfig.uint32Get - YNdL__Y0tEa */
 (Tc*)YNdL__Yyt7, /* MZimbu__CConfig.floatGet - YNdL__Yyt7 */
 (Tc*)YNdL__Yyt7a, /* MZimbu__CConfig.floatGet - YNdL__Yyt7a */
 (Tc*)YNdL__Yybv, /* MZimbu__CConfig.doubleGet - YNdL__Yybv */
 (Tc*)YNdL__Yybva, /* MZimbu__CConfig.doubleGet - YNdL__Yybva */
 (Tc*)YFKUa, /* MZimbu__CConfig.boolGet - YFKUa */
 (Tc*)YNdL__YGfza, /* MZimbu__CConfig.boolGet - YNdL__YGfza */
 (Tc*)Yxv3a, /* MZimbu__CConfig.stringGet - Yxv3a */
 (Tc*)YNdL__YsRaa, /* MZimbu__CConfig.stringGet - YNdL__YsRaa */
 (Tc*)YNdL__YlHQ, /* MZimbu__CConfig.bytesGet - YNdL__YlHQ */
 (Tc*)YNdL__YlHQa, /* MZimbu__CConfig.bytesGet - YNdL__YlHQa */
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
 (Tc*)0, /* MZimbu__CConfig.bytesSet - YNdL__Yoxk */
 (Tc*)YNdL__Yo5y, /* MZimbu__CConfig.messageGet - YNdL__Yo5y */
 (Tc*)YNdL__Yo5ya, /* MZimbu__CConfig.messageGet - YNdL__Yo5ya */
 (Tc*)0, /* MZimbu__CConfig.messageSet - YNdL__YrW2 */
 (Tc*)0, /* MZimbu__CConfig.messageAdd - YNdL__Y0Dj */
 (Tc*)YNdL__YUDN, /* MZimbu__CConfig.size - YNdL__YUDN */
 (Tc*)YNdL__YC5i, /* MZimbu__CConfig.ToString - YNdL__YC5i */
 (Tc*)0, /* MZimbu__CConfig.toString - YNdL__YVAI */
 (Tc*)0, /* MZimbu__CConfig.writeText - YNdL__Yr3c */
 (Tc*)0, /* MZimbu__CConfig.writeText - YNdL__Yr3ca */
 (Tc*)0, /* MZimbu__CConfig.Equal - YNdL__YYdF */
 (Tc*)0, /* MZimbu__CConfig.Compare - YNdL__YSzC */
 (Tc*)0, /* MZimbu__CConfig.merge - YNdL__Y98G */
 (Tc*)0, /* MZimbu__CConfig.writeBinary - YNdL__YpSR */
 (Tc*)0, /* MZimbu__CConfig.writeBinaryDeref - YNdL__Yz9e */
 (Tc*)0, /* MZimbu__CConfig.toJson - YNdL__Y3fy */
 (Tc*)0, /* MZimbu__CConfig.writeJson - YNdL__YVaR */
 (Tc*)0, /* MZimbu__CConfig.writeJsonDeref - YNdL__YgZk */
 (Tc*)0, /* Vf_mallocArg */
 (Tc*)YrF2, /* MZimbu__CConfig.setMallocArg - YrF2 */
 (Tc*)0, /* MZimbu__CConfig.getMallocArg - Y5PP */
 (Tc*)Y8zW, /* MZimbu__CConfig.hasMallocArg - Y8zW */
 (Tc*)0, /* MZimbu__CConfig.clearMallocArg - YM3c */
 (Tc*)0, /* Vf_threadArg */
 (Tc*)YOPG, /* MZimbu__CConfig.setThreadArg - YOPG */
 (Tc*)0, /* MZimbu__CConfig.getThreadArg - Ys_s */
 (Tc*)YvKz, /* MZimbu__CConfig.hasThreadArg - YvKz */
 (Tc*)0, /* MZimbu__CConfig.clearThreadArg - YpUz */
 (Tc*)0, /* Vf_socketArg */
 (Tc*)YWoP, /* MZimbu__CConfig.setSocketArg - YWoP */
 (Tc*)0, /* MZimbu__CConfig.getSocketArg - YAzB */
 (Tc*)YDjI, /* MZimbu__CConfig.hasSocketArg - YDjI */
 (Tc*)0, /* MZimbu__CConfig.clearSocketArg - Yhkr */
 (Tc*)0, /* Vf_mathArg */
 (Tc*)Yjrt, /* MZimbu__CConfig.setMathArg - Yjrt */
 (Tc*)0, /* MZimbu__CConfig.getMathArg - YQ_S */
 (Tc*)Y8om, /* MZimbu__CConfig.hasMathArg - Y8om */
 (Tc*)0, /* MZimbu__CConfig.clearMathArg - Yfqy */
 (Tc*)0, /* Vf_pcreArg */
 (Tc*)YMyf, /* MZimbu__CConfig.setPcreArg - YMyf */
 (Tc*)0, /* MZimbu__CConfig.getPcreArg - YnT5 */
 (Tc*)YGhA, /* MZimbu__CConfig.hasPcreArg - YGhA */
 (Tc*)0, /* MZimbu__CConfig.clearPcreArg - YNiM */
 (Tc*)0, /* Vf_haveResolve */
 (Tc*)Yqt5, /* MZimbu__CConfig.setHaveResolve - Yqt5 */
 (Tc*)0, /* MZimbu__CConfig.getHaveResolve - YqzX */
 (Tc*)Y3Lr, /* MZimbu__CConfig.hasHaveResolve - Y3Lr */
 (Tc*)0, /* MZimbu__CConfig.clearHaveResolve - Y9nB */
 (Tc*)0, /* Vf_haveFork */
 (Tc*)YBhB, /* MZimbu__CConfig.setHaveFork - YBhB */
 (Tc*)0, /* MZimbu__CConfig.getHaveFork - Y7ik */
 (Tc*)YcPw, /* MZimbu__CConfig.hasHaveFork - YcPw */
 (Tc*)0, /* MZimbu__CConfig.clearHaveFork - YdMB */
 (Tc*)0, /* Vf_exeSuffix */
 (Tc*)YNXX, /* MZimbu__CConfig.setExeSuffix - YNXX */
 (Tc*)0, /* MZimbu__CConfig.getExeSuffix - Yr7J */
 (Tc*)YuSQ, /* MZimbu__CConfig.hasExeSuffix - YuSQ */
 (Tc*)0, /* MZimbu__CConfig.clearExeSuffix - YqMi */
 (Tc*)0, /* Vf_exePrefix */
 (Tc*)YcU3, /* MZimbu__CConfig.setExePrefix - YcU3 */
 (Tc*)0, /* MZimbu__CConfig.getExePrefix - YR3Q */
 (Tc*)YUOX, /* MZimbu__CConfig.hasExePrefix - YUOX */
 (Tc*)0, /* MZimbu__CConfig.clearExePrefix - Y0Pb */
 (Tc*)0, /* Vf_haveSigaction */
 (Tc*)Y118, /* MZimbu__CConfig.setHaveSigaction - Y118 */
 (Tc*)0, /* MZimbu__CConfig.getHaveSigaction - YZQV */
 (Tc*)YJrk, /* MZimbu__CConfig.hasHaveSigaction - YJrk */
 (Tc*)0, /* MZimbu__CConfig.clearHaveSigaction - YiKD */
 (Tc*)0, /* Vf_gcWithThreads */
 (Tc*)YEDn, /* MZimbu__CConfig.setGcWithThreads - YEDn */
 (Tc*)0, /* MZimbu__CConfig.getGcWithThreads - Yjd9 */
 (Tc*)Yo45, /* MZimbu__CConfig.hasGcWithThreads - Yo45 */
 (Tc*)0, /* MZimbu__CConfig.clearGcWithThreads - YYmp */
 (Tc*)0, /* Vf_int16Name */
 (Tc*)YIIX, /* MZimbu__CConfig.setInt16Name - YIIX */
 (Tc*)0, /* MZimbu__CConfig.getInt16Name - YmTJ */
 (Tc*)YpDQ, /* MZimbu__CConfig.hasInt16Name - YpDQ */
 (Tc*)0, /* MZimbu__CConfig.clearInt16Name - Yv0i */
 (Tc*)0, /* Vf_int32Name */
 (Tc*)Y8TB, /* MZimbu__CConfig.setInt32Name - Y8TB */
 (Tc*)0, /* MZimbu__CConfig.getInt32Name - YN3n */
 (Tc*)YQOu, /* MZimbu__CConfig.hasInt32Name - YQOu */
 (Tc*)0, /* MZimbu__CConfig.clearInt32Name - Y4PE */
 (Tc*)0, /* Vf_int64Name */
 (Tc*)Y6PM, /* MZimbu__CConfig.setInt64Name - Y6PM */
 (Tc*)0, /* MZimbu__CConfig.getInt64Name - YL_y */
 (Tc*)YOKF, /* MZimbu__CConfig.hasInt64Name - YOKF */
 (Tc*)0, /* MZimbu__CConfig.clearInt64Name - Y6Tt */
 (Tc*)0, /* Vf_nat16Name */
 (Tc*)YXzR, /* MZimbu__CConfig.setNat16Name - YXzR */
 (Tc*)0, /* MZimbu__CConfig.getNat16Name - YBKD */
 (Tc*)YEuK, /* MZimbu__CConfig.hasNat16Name - YEuK */
 (Tc*)0, /* MZimbu__CConfig.clearNat16Name - Yg9o */
 (Tc*)0, /* Vf_nat32Name */
 (Tc*)YnLv, /* MZimbu__CConfig.setNat32Name - YnLv */
 (Tc*)0, /* MZimbu__CConfig.getNat32Name - Y1Vh */
 (Tc*)Y4Fo, /* MZimbu__CConfig.hasNat32Name - Y4Fo */
 (Tc*)0, /* MZimbu__CConfig.clearNat32Name - YQYKa */
 (Tc*)0, /* Vf_nat64Name */
 (Tc*)YlHG, /* MZimbu__CConfig.setNat64Name - YlHG */
 (Tc*)0, /* MZimbu__CConfig.getNat64Name - Y_Rs */
 (Tc*)Y2Bz, /* MZimbu__CConfig.hasNat64Name - Y2Bz */
 (Tc*)0, /* MZimbu__CConfig.clearNat64Name - YS1z */
 (Tc*)0, /* Vf_floatName */
 (Tc*)Yla2, /* MZimbu__CConfig.setFloatName - Yla2 */
 (Tc*)0, /* MZimbu__CConfig.getFloatName - Y_kP */
 (Tc*)Y24V, /* MZimbu__CConfig.hasFloatName - Y24V */
 (Tc*)0, /* MZimbu__CConfig.clearFloatName - YSyd */
 (Tc*)0, /* Vf_float32Name */
 (Tc*)YI4N, /* MZimbu__CConfig.setFloat32Name - YI4N */
 (Tc*)0, /* MZimbu__CConfig.getFloat32Name - YTF6 */
 (Tc*)YftC, /* MZimbu__CConfig.hasFloat32Name - YftC */
 (Tc*)0, /* MZimbu__CConfig.clearFloat32Name - Ytwp */
 (Tc*)0, /* Vf_intPtrName */
 (Tc*)YJ6V, /* MZimbu__CConfig.setIntPtrName - YJ6V */
 (Tc*)0, /* MZimbu__CConfig.getIntPtrName - Ymy9 */
 (Tc*)YTxb, /* MZimbu__CConfig.hasIntPtrName - YTxb */
 (Tc*)0, /* MZimbu__CConfig.clearIntPtrName - YaFB */
 (Tc*)0, /* Vf_printIntFormat */
 (Tc*)YUld, /* MZimbu__CConfig.setPrintIntFormat - YUld */
 (Tc*)0, /* MZimbu__CConfig.getPrintIntFormat - YoDj */
 (Tc*)YlFq, /* MZimbu__CConfig.hasPrintIntFormat - YlFq */
 (Tc*)0, /* MZimbu__CConfig.clearPrintIntFormat - YgH3 */
 (Tc*)0, /* Vf_printNatFormat */
 (Tc*)Y8c7, /* MZimbu__CConfig.setPrintNatFormat - Y8c7 */
 (Tc*)0, /* MZimbu__CConfig.getPrintNatFormat - YDud */
 (Tc*)Y6Nw, /* MZimbu__CConfig.hasPrintNatFormat - Y6Nw */
 (Tc*)0, /* MZimbu__CConfig.clearPrintNatFormat - YvyY */
 (Tc*)0, /* Vf_scanfHexFormat */
 (Tc*)YRMv, /* MZimbu__CConfig.setScanfHexFormat - YRMv */
 (Tc*)0, /* MZimbu__CConfig.getScanfHexFormat - Y_eH */
 (Tc*)Yoe8, /* MZimbu__CConfig.hasScanfHexFormat - Yoe8 */
 (Tc*)0, /* MZimbu__CConfig.clearScanfHexFormat - Yd7l */
 (Tc*)0, /* Vf_isMingw */
 (Tc*)YeB5, /* MZimbu__CConfig.setIsMingw - YeB5 */
 (Tc*)0, /* MZimbu__CConfig.getIsMingw - YVQf */
 (Tc*)YdfK, /* MZimbu__CConfig.hasIsMingw - YdfK */
 (Tc*)0, /* MZimbu__CConfig.clearIsMingw - YkgW */
 (Tc*)0, /* MZimbu__CConfig.clear - Yp20 */
 (Tc*)0, /* MZimbu__CConfig.valid - Yak5 */
 (Tc*)0, /* MZimbu__CConfig.copy - Y8T8 */
 (Tc*)Yozoa, /* MZimbu__CConfig.fieldSpecs - Yozoa */
 (Tc*)0, /* MZimbu__CConfig.mergeFromReader - YowW */
 (Tc*)0, /* MZimbu__CConfig.mergeFromBinary - YH21a */
 (Tc*)0, /* MZimbu__CConfig.mergeFromBinary - YH21 */
 (Tc*)0, /* MZimbu__CConfig.mergeFromBinaryDeref - Y57J */
 (Tc*)0, /* MZimbu__CConfig.mergeFromText - YUx0 */
 (Tc*)0, /* MZimbu__CConfig.mergeFromJson - Yqqna */
 (Tc*)0, /* MZimbu__CConfig.mergeFromJson - Yqqn */
 (Tc*)0, /* Init - YNdLa */
 (Tc*)0, /* MZimbu__CConfig.mergeMessageFromReader - YNdL__Ymza */
};
To ToYNdL[] = {
 {19, 0},
 {0, (Tt*)&string__T}, /* f_mallocArg */
 {0, (Tt*)&string__T}, /* f_threadArg */
 {0, (Tt*)&string__T}, /* f_socketArg */
 {0, (Tt*)&string__T}, /* f_mathArg */
 {0, (Tt*)&string__T}, /* f_pcreArg */
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
  Zsf sf={0,topFrame};
  topFrame = &sf;
  round_done = round;
 done &= JProto(round);
  if (round == 2001) {
   sf.pos=7469100;
   YR6X = ZnewList((Tt*)&YqvM__T, 24); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y1i0), 1, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YF8m), 2, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yxze), 3, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YdV8), 10, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YG1V), 11, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yefj), 4, 1, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YqSF), 5, 1, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YG05), 6, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yg4Z), 7, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YUN3), 8, 1, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yeai), 9, 1, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YLf6), 20, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Yk4r), 21, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Ym8g), 22, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Ywoc), 23, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y5cy), 24, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y7gn), 25, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y7N0), 26, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y4ZK), 27, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YlnY), 28, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YMLF), 40, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YxUL), 41, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&YPkn), 42, 17, 0)); ZLap((Tl*)YR6X, (Tz)(void*)Ykww(NULL, ((Tc*)&Y83L), 50, 1, 0));
  }
  topFrame = sf.prev;
 }
 return done;
}
/* zimbuConfig done */
void YWeD() { /* generateConfigOut */
 Zsf sf={0,topFrame};
 YNdL *VzimbuConfig = 0;
 Yw8L *Vwriter = NULL;
 Tc *Vconfig = NULL;
 topFrame = &sf;
 sf.pos=3982200;
 VzimbuConfig = YA_Z(NULL);
 sf.pos=3982201;
 YH2W(VzimbuConfig);
 sf.pos=3982202;
 Y5sp(VzimbuConfig);
 sf.pos=3982203;
 YTmn(VzimbuConfig);
 sf.pos=3982204;
 YqfB(VzimbuConfig);
 sf.pos=3982205;
 YZP1(VzimbuConfig);
 sf.pos=3982206;
 Yfdk(VzimbuConfig);
 sf.pos=3982207;
 YqaV(VzimbuConfig);
 sf.pos=3982208;
 YB9D(VzimbuConfig);
 sf.pos=3982209;
 Vwriter = YiBk(((Tc*)&Ys1d), 1);
 sf.pos=3982210;
 Vconfig = YNdL__YC5i((YNdL *)VzimbuConfig);
 sf.pos=3982211;
 YwHoa((Yw8L *)Vwriter, Vconfig);
 sf.pos=3982212;
 Yl0k(((Tc*)&YIrD));
 topFrame = sf.prev;
 return;
}
void YH2W(YNdL *AzimbuConfig) { /* findTcmalloc */
 Zsf sf={0,topFrame};
 Tc *Vfound = NULL;
 Tl *Zf1 = NULL;
 Tl *Zf2 = NULL;
 Tl *t0 = NULL;
 int rt = 0;
 topFrame = &sf;
 sf.pos=4371300;
 {
  Tc *Vdir;
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&string__T, 7), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Yj_i)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YftF)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YK0f)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIMX)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YDCH)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYHU)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YGiO)));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdir;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=4371301;
  {
   Tc *Vs;
   Tfl Zf2i;
   Zf2 = (t0 = ZnewList((Tt*)&string__T, 2), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Y912)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Y56Y)));
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vs;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4371302;
   if (Y0YB(ZcS5(Vdir, ((Tc*)&YK0f), Vs, ((Tc*)&YEk4), (Tc*)1)))
   {
    sf.pos=4371303;
    Vfound = Vs;
    rt = 2;
    goto YrsT;
   }
YrsT:
   if (rt == 2) { rt &= 1; break; }
   sf.pos=4371304;
   }
  }
  sf.pos=4371305;
  if ((Vfound != NULL))
  {
   rt = 2;
   goto Yetu;
  }
Yetu:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=4371306;
  }
 }
 sf.pos=4371307;
 if ((Vfound != NULL))
 {
  sf.pos=4371308;
  YrF2((YNdL *)AzimbuConfig, ZcS(((Tc*)&Y1ja), Vfound));
 }
 else
 {
  sf.pos=4371309;
  Yl0k(((Tc*)&YbiD));
  sf.pos=4371310;
  Yl0k(((Tc*)&Y51Q));
 }
 topFrame = sf.prev;
 return;
}
void Y5sp(YNdL *AzimbuConfig) { /* findThreadAndSocketLibs */
 Zsf sf={0,topFrame};
 Tc *VthreadArg = NULL;
 Tc *VsocketArg = NULL;
 topFrame = &sf;
 sf.pos=2075600;
 VthreadArg = ((Tc*)&YglX);
 sf.pos=2075601;
#if defined(__MINGW32__)
  VthreadArg = Zstr("-lpthreadGC2");
  VsocketArg = Zstr("-lws2_32");
#endif
 sf.pos=2075602;
 YOPG((YNdL *)AzimbuConfig, VthreadArg);
 sf.pos=2075603;
 if ((VsocketArg != NULL))
 {
  sf.pos=2075604;
  YWoP((YNdL *)AzimbuConfig, VsocketArg);
 }
 topFrame = sf.prev;
 return;
}
void YTmn(YNdL *AzimbuConfig) { /* findMathLib */
 Zsf sf={0,topFrame};
 Tc *VmathArg = NULL;
 topFrame = &sf;
 sf.pos=5575100;
 VmathArg = ((Tc*)&YtA1);
 sf.pos=5575101;
 Yjrt((YNdL *)AzimbuConfig, VmathArg);
 topFrame = sf.prev;
 return;
}
void YqfB(YNdL *AzimbuConfig) { /* findPcreLib */
 Zsf sf={0,topFrame};
 Tc *VpcreArg = NULL;
 topFrame = &sf;
 sf.pos=1685100;
 VpcreArg = ZcS(Y2wM(YzHL()), ((Tc*)&YhVq));
 sf.pos=1685101;
 YMyf((YNdL *)AzimbuConfig, VpcreArg);
 topFrame = sf.prev;
 return;
}
void YZP1(YNdL *AzimbuConfig) { /* findLibMethods */
 Tb VhaveResolve;
 Tb VhaveFork;
 Tb VhaveSigaction;
 Tb VgcWithThreads;
 Zsf sf={0,topFrame};
 topFrame = &sf;
 VhaveResolve = 0;
 VhaveFork = 0;
 VhaveSigaction = 0;
 VgcWithThreads = 0;
 sf.pos=917700;
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
 sf.pos=917701;
 Yqt5((YNdL *)AzimbuConfig, VhaveResolve);
 sf.pos=917702;
 YBhB((YNdL *)AzimbuConfig, VhaveFork);
 sf.pos=917703;
 Y118((YNdL *)AzimbuConfig, VhaveSigaction);
 sf.pos=917704;
 YEDn((YNdL *)AzimbuConfig, VgcWithThreads);
 topFrame = sf.prev;
 return;
}
void Yfdk(YNdL *AzimbuConfig) { /* checkIsMingw */
 Tb VisMingw;
 Zsf sf={0,topFrame};
 topFrame = &sf;
 VisMingw = 0;
 sf.pos=2638900;
#ifdef __MINGW32__
  VisMingw = 1;
#endif
 sf.pos=2638901;
 YeB5((YNdL *)AzimbuConfig, VisMingw);
 topFrame = sf.prev;
 return;
}
void YqaV(YNdL *AzimbuConfig) { /* checkSizes */
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
 Zsf sf={0,topFrame};
 Tc *VintType = NULL;
 Tc *VprintIntFormat = NULL;
 Tc *VscanfHexFormat = NULL;
 Tc *VprintNatFormat = NULL;
 Tc *VnatType = NULL;
 Tc *VintPtrName = NULL;
 topFrame = &sf;
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
 sf.pos=4295300;
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
 sf.pos=4295301;
 YIIX((YNdL *)AzimbuConfig, ((Tc*)&YX_1));
 sf.pos=4295302;
 if ((VshortSize != 2))
 {
  sf.pos=4295303;
  Yl0k(ZcS3(((Tc*)&Y8PB), (Zint2string((VshortSize * 8))), ((Tc*)&YMSv)));
 }
 sf.pos=4295304;
 if ((VintSize == 4))
 {
  sf.pos=4295305;
  Y8TB((YNdL *)AzimbuConfig, ((Tc*)&Y1Qt));
 }
 else {
 sf.pos=4295306;
 if ((VlongSize == 4))
 {
  sf.pos=4295307;
  Y8TB((YNdL *)AzimbuConfig, ((Tc*)&YDFJ));
 }
 else
 {
  sf.pos=4295308;
  Y8TB((YNdL *)AzimbuConfig, ((Tc*)&Y1Qt));
  sf.pos=4295309;
  Yl0k(ZcS3(((Tc*)&Ynz4), (Zint2string((VintSize * 8))), ((Tc*)&YMSv)));
 }
 }
 sf.pos=4295310;
 VintType = ((Tc*)&YDR5);
 sf.pos=4295311;
#ifdef __MINGW32__
 sf.pos=4295312;
 VprintIntFormat = ((Tc*)&YmXc);
 sf.pos=4295313;
 VscanfHexFormat = ((Tc*)&YGXc);
 sf.pos=4295314;
 VprintNatFormat = ((Tc*)&YDXc);
 sf.pos=4295315;
#else
 sf.pos=4295316;
 VprintIntFormat = ((Tc*)&YKd3);
 sf.pos=4295317;
 VscanfHexFormat = ((Tc*)&Y3d3);
 sf.pos=4295318;
 VprintNatFormat = ((Tc*)&Y0d3);
 sf.pos=4295319;
#endif
 sf.pos=4295320;
 if ((VlongLongSize == 8))
 {
 }
 else {
 sf.pos=4295321;
 if ((VlongSize == 8))
 {
  sf.pos=4295322;
  VintType = ((Tc*)&YDFJ);
  sf.pos=4295323;
  VprintIntFormat = ((Tc*)&YY0H);
  sf.pos=4295324;
  VscanfHexFormat = ((Tc*)&Yh1H);
  sf.pos=4295325;
  VprintIntFormat = ((Tc*)&YY0H);
 }
 else {
 sf.pos=4295326;
 if ((VintSize == 8))
 {
  sf.pos=4295327;
  VintType = ((Tc*)&Y1Qt);
  sf.pos=4295328;
  VprintIntFormat = ((Tc*)&Y46);
  sf.pos=4295329;
  VscanfHexFormat = ((Tc*)&Yo7);
 }
 else
 {
  sf.pos=4295330;
  Yl0k(ZcS3(((Tc*)&Y0OX), (Zint2string((VlongLongSize * 8))), ((Tc*)&YMSv)));
 }
 }}
 sf.pos=4295331;
 Y6PM((YNdL *)AzimbuConfig, VintType);
 sf.pos=4295332;
 YUld((YNdL *)AzimbuConfig, VprintIntFormat);
 sf.pos=4295333;
 YRMv((YNdL *)AzimbuConfig, VscanfHexFormat);
 sf.pos=4295334;
 YXzR((YNdL *)AzimbuConfig, ((Tc*)&YFcv));
 sf.pos=4295335;
 if ((VunsShortSize != 2))
 {
  sf.pos=4295336;
  Yl0k(ZcS3(((Tc*)&YTwi), (Zint2string((VunsShortSize * 8))), ((Tc*)&YMSv)));
 }
 sf.pos=4295337;
 if ((VunsIntSize == 4))
 {
  sf.pos=4295338;
  YnLv((YNdL *)AzimbuConfig, ((Tc*)&YVjT));
 }
 else {
 sf.pos=4295339;
 if ((VunsLongSize == 4))
 {
  sf.pos=4295340;
  YnLv((YNdL *)AzimbuConfig, ((Tc*)&YOaN));
 }
 else
 {
  sf.pos=4295341;
  YnLv((YNdL *)AzimbuConfig, ((Tc*)&YVjT));
  sf.pos=4295342;
  Yl0k(ZcS3(((Tc*)&YENP), (Zint2string((VunsIntSize * 8))), ((Tc*)&YMSv)));
 }
 }
 sf.pos=4295343;
 VnatType = ((Tc*)&Y2BO);
 sf.pos=4295344;
 if ((VunsLongLongSize == 8))
 {
 }
 else {
 sf.pos=4295345;
 if ((VunsLongSize == 8))
 {
  sf.pos=4295346;
  VnatType = ((Tc*)&YOaN);
  sf.pos=4295347;
  VprintNatFormat = ((Tc*)&Ye1H);
 }
 else {
 sf.pos=4295348;
 if ((VunsIntSize == 8))
 {
  sf.pos=4295349;
  VnatType = ((Tc*)&YVjT);
  sf.pos=4295350;
  VprintNatFormat = ((Tc*)&Yl7);
 }
 else
 {
  sf.pos=4295351;
  Yl0k(ZcS3(((Tc*)&YfGK), (Zint2string((VunsLongLongSize * 8))), ((Tc*)&YMSv)));
 }
 }}
 sf.pos=4295352;
 YlHG((YNdL *)AzimbuConfig, VnatType);
 sf.pos=4295353;
 Y8c7((YNdL *)AzimbuConfig, VprintNatFormat);
 sf.pos=4295354;
 Yla2((YNdL *)AzimbuConfig, ((Tc*)&Ygep));
 sf.pos=4295355;
 if ((VdoubleSize != 8))
 {
  sf.pos=4295356;
  Yl0k(ZcS3(((Tc*)&Y_4L), (Zint2string((VdoubleSize * 8))), ((Tc*)&YMSv)));
 }
 sf.pos=4295357;
 YI4N((YNdL *)AzimbuConfig, ((Tc*)&Yt7n));
 sf.pos=4295358;
 if ((VfloatSize != 4))
 {
  sf.pos=4295359;
  Yl0k(ZcS3(((Tc*)&YhOJ), (Zint2string((VfloatSize * 8))), ((Tc*)&YMSv)));
 }
 sf.pos=4295360;
#ifdef __INTPTR_TYPE__
 sf.pos=4295361;
 VintPtrName = ((Tc*)&YlTN);
 sf.pos=4295362;
#else
# ifdef __SIZEOF_POINTER__
#  if __SIZEOF_POINTER__ == __SIZEOF_INT__
 sf.pos=4295363;
 VintPtrName = ((Tc*)&Y1Qt);
 sf.pos=4295364;
#  else
#   if __SIZEOF_POINTER__ == __SIZEOF_LONG__
 sf.pos=4295365;
 VintPtrName = ((Tc*)&YDFJ);
 sf.pos=4295366;
#   else
 sf.pos=4295367;
 VintPtrName = ((Tc*)&YDR5);
 sf.pos=4295368;
#   endif
#  endif
# else
 sf.pos=4295369;
 VintPtrName = ((Tc*)&YDFJ);
 sf.pos=4295370;
# endif
#endif
 sf.pos=4295371;
 YJ6V((YNdL *)AzimbuConfig, VintPtrName);
 topFrame = sf.prev;
 return;
}
void YB9D(YNdL *AzimbuConfig) { /* checkExeName */
 Zsf sf={0,topFrame};
 Tc *VexeSuffix = NULL;
 Tc *VexePrefix = NULL;
 topFrame = &sf;
 sf.pos=7056200;
 VexeSuffix = ((Tc*)&Ya);
 sf.pos=7056201;
 VexePrefix = ((Tc*)&YFka);
 sf.pos=7056202;
#if defined(__MINGW32__) || defined(_MSC_VER)
  VexeSuffix = Zstr(".exe");  /* set to ".exe" for MS-Windows */
  VexePrefix = Zstr("");      /* set to "" for MS-Windows */
#endif
 sf.pos=7056203;
 YNXX((YNdL *)AzimbuConfig, VexeSuffix);
 sf.pos=7056204;
 YcU3((YNdL *)AzimbuConfig, VexePrefix);
 topFrame = sf.prev;
 return;
}
void YZTI() { /* generateConfigMak */
 Zsf sf={0,topFrame};
 Tc *Vnode = NULL;
 Tc *Vnodejs = NULL;
 Yw8L *Vwriter = NULL;
 topFrame = &sf;
 sf.pos=2119100;
 Vnode = Ycmi(((Tc*)&YxAY));
 sf.pos=2119101;
 Vnodejs = Ycmi(((Tc*)&Y6Qt));
 sf.pos=2119102;
 if (((Vnode != NULL) || (Vnodejs != NULL)))
 {
  sf.pos=2119103;
  Vwriter = YiBk(((Tc*)&Ypn8), 1);
  sf.pos=2119104;
  Yw8L__YRt7((Yw8L *)Vwriter, ((Tc*)&Ybaf));
  sf.pos=2119105;
  if ((Vnodejs != NULL))
  {
   sf.pos=2119106;
   Yw8L__YRt7((Yw8L *)Vwriter, ((Tc*)&YDew));
  }
  else
  {
   sf.pos=2119107;
   Yw8L__YRt7((Yw8L *)Vwriter, ((Tc*)&Y0qk));
  }
  sf.pos=2119108;
  Yl0k(((Tc*)&YL5I));
 }
 else
 {
  sf.pos=2119109;
  Yl0k(((Tc*)&YzQa));
 }
 topFrame = sf.prev;
 return;
}
/*
 * INIT IMT
 */
void ZimtInit(void) {
 {
  Ytlm *p = 0;
  Ytlm__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Ytlm__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Ytlm__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYtlm[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtlm[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtlm[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YEro *p = 0;
  YEro__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YEro__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YEro__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  YEro__mt[17] = (Tc*)((Tc*)&p->Vvalue - (Tc*)p);
  ToYEro[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYEro[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYEro[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YKhn *p = 0;
  YKhn__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YKhn__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YKhn__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYKhn[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYKhn[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYKhn[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y1uN *p = 0;
  Y1uN__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y1uN__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y1uN__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY1uN[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY1uN[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY1uN[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YAxe *p = 0;
  YAxe__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YAxe__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YAxe__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYAxe[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYAxe[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYAxe[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YVNj *p = 0;
  YVNj__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YVNj__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YVNj__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYVNj[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYVNj[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYVNj[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yalz *p = 0;
  Yalz__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yalz__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yalz__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYalz[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYalz[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYalz[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yw3O *p = 0;
  Yw3O__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yw3O__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yw3O__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYw3O[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYw3O[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYw3O[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y2EX *p = 0;
  Y2EX__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y2EX__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y2EX__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY2EX[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY2EX[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY2EX[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YX0i *p = 0;
  YX0i__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YX0i__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YX0i__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYX0i[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYX0i[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYX0i[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YzSI *p = 0;
  YzSI__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YzSI__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YzSI__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYzSI[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYzSI[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYzSI[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YXKl *p = 0;
  YXKl__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YXKl__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YXKl__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYXKl[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYXKl[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYXKl[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YuDC *p = 0;
  YuDC__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YuDC__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YuDC__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYuDC[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYuDC[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYuDC[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YrHq *p = 0;
  YrHq__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YrHq__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YrHq__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  Yw8L__mt[41] = (Tc*)((Tc*)&p->Vfd - (Tc*)p);
 }
 {
  YjUM *p = 0;
  YjUM__mt[41] = (Tc*)((Tc*)&p->VsLen - (Tc*)p);
  YjUM__mt[42] = (Tc*)((Tc*)&p->Vs - (Tc*)p);
  ToYjUM[1].off = (int)((Tc*)&p->Vs - (Tc*)p);
 }
 {
  YuMQ *p = 0;
  ToYuMQ[1].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Y86c *p = 0;
  Y86c__mt[2] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  Y86c__mt[3] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  Y86c__mt[4] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  Y86c__mt[5] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  Y86c__mt[6] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  Y86c__mt[7] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  Y86c__mt[8] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  Y86c__mt[9] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  Y86c__mt[10] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y86c__mt[25] = (Tc*)((Tc*)&p->Vcurrent - (Tc*)p);
  Y86c__mt[26] = (Tc*)((Tc*)&p->Vdefault - (Tc*)p);
  ToY86c[1].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY86c[2].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY86c[3].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY86c[4].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY86c[5].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YJQu *p = 0;
  YJQu__mt[2] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  YJQu__mt[3] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  YJQu__mt[4] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  YJQu__mt[5] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  YJQu__mt[6] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  YJQu__mt[7] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  YJQu__mt[8] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  YJQu__mt[9] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  YJQu__mt[10] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YJQu__mt[25] = (Tc*)((Tc*)&p->Vcurrent - (Tc*)p);
  YJQu__mt[26] = (Tc*)((Tc*)&p->Vdefault - (Tc*)p);
  YJQu__mt[27] = (Tc*)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYJQu[1].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYJQu[2].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYJQu[3].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYJQu[4].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYJQu[5].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYJQu[6].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YzqH *p = 0;
  YzqH__mt[2] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  YzqH__mt[3] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  YzqH__mt[4] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  YzqH__mt[5] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  YzqH__mt[6] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  YzqH__mt[7] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  YzqH__mt[8] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  YzqH__mt[9] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  YzqH__mt[10] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YzqH__mt[25] = (Tc*)((Tc*)&p->Vcurrent - (Tc*)p);
  YzqH__mt[26] = (Tc*)((Tc*)&p->Vdefault - (Tc*)p);
  YzqH__mt[27] = (Tc*)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYzqH[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToYzqH[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToYzqH[3].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYzqH[4].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYzqH[5].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYzqH[6].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYzqH[7].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYzqH[8].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Y_SI *p = 0;
  Y_SI__mt[2] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  Y_SI__mt[3] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  Y_SI__mt[4] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  Y_SI__mt[5] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  Y_SI__mt[6] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  Y_SI__mt[7] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  Y_SI__mt[8] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  Y_SI__mt[9] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  Y_SI__mt[10] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y_SI__mt[25] = (Tc*)((Tc*)&p->Vcurrent - (Tc*)p);
  Y_SI__mt[26] = (Tc*)((Tc*)&p->Vdefault - (Tc*)p);
  ToY_SI[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToY_SI[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY_SI[3].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY_SI[4].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY_SI[5].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY_SI[6].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY_SI[7].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Ys_q *p = 0;
  Ys_q__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Ys_q__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Ys_q__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYs_q[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYs_q[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYs_q[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YOEA *p = 0;
  YOEA__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YOEA__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YOEA__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  YNdL__mt[2] = (Tc*)((Tc*)&p->VderefTime - (Tc*)p);
  YNdL__mt[3] = (Tc*)((Tc*)&p->VderefId - (Tc*)p);
  YNdL__mt[4] = (Tc*)((Tc*)&p->VderefTimeSize - (Tc*)p);
  YNdL__mt[5] = (Tc*)((Tc*)&p->VderefIdSize - (Tc*)p);
  YNdL__mt[113] = (Tc*)((Tc*)&p->Vf_mallocArg - (Tc*)p);
  YNdL__mt[118] = (Tc*)((Tc*)&p->Vf_threadArg - (Tc*)p);
  YNdL__mt[123] = (Tc*)((Tc*)&p->Vf_socketArg - (Tc*)p);
  YNdL__mt[128] = (Tc*)((Tc*)&p->Vf_mathArg - (Tc*)p);
  YNdL__mt[133] = (Tc*)((Tc*)&p->Vf_pcreArg - (Tc*)p);
  YNdL__mt[138] = (Tc*)((Tc*)&p->Vf_haveResolve - (Tc*)p);
  YNdL__mt[143] = (Tc*)((Tc*)&p->Vf_haveFork - (Tc*)p);
  YNdL__mt[148] = (Tc*)((Tc*)&p->Vf_exeSuffix - (Tc*)p);
  YNdL__mt[153] = (Tc*)((Tc*)&p->Vf_exePrefix - (Tc*)p);
  YNdL__mt[158] = (Tc*)((Tc*)&p->Vf_haveSigaction - (Tc*)p);
  YNdL__mt[163] = (Tc*)((Tc*)&p->Vf_gcWithThreads - (Tc*)p);
  YNdL__mt[168] = (Tc*)((Tc*)&p->Vf_int16Name - (Tc*)p);
  YNdL__mt[173] = (Tc*)((Tc*)&p->Vf_int32Name - (Tc*)p);
  YNdL__mt[178] = (Tc*)((Tc*)&p->Vf_int64Name - (Tc*)p);
  YNdL__mt[183] = (Tc*)((Tc*)&p->Vf_nat16Name - (Tc*)p);
  YNdL__mt[188] = (Tc*)((Tc*)&p->Vf_nat32Name - (Tc*)p);
  YNdL__mt[193] = (Tc*)((Tc*)&p->Vf_nat64Name - (Tc*)p);
  YNdL__mt[198] = (Tc*)((Tc*)&p->Vf_floatName - (Tc*)p);
  YNdL__mt[203] = (Tc*)((Tc*)&p->Vf_float32Name - (Tc*)p);
  YNdL__mt[208] = (Tc*)((Tc*)&p->Vf_intPtrName - (Tc*)p);
  YNdL__mt[213] = (Tc*)((Tc*)&p->Vf_printIntFormat - (Tc*)p);
  YNdL__mt[218] = (Tc*)((Tc*)&p->Vf_printNatFormat - (Tc*)p);
  YNdL__mt[223] = (Tc*)((Tc*)&p->Vf_scanfHexFormat - (Tc*)p);
  YNdL__mt[228] = (Tc*)((Tc*)&p->Vf_isMingw - (Tc*)p);
  ToYNdL[1].off = (int)((Tc*)&p->Vf_mallocArg - (Tc*)p);
  ToYNdL[2].off = (int)((Tc*)&p->Vf_threadArg - (Tc*)p);
  ToYNdL[3].off = (int)((Tc*)&p->Vf_socketArg - (Tc*)p);
  ToYNdL[4].off = (int)((Tc*)&p->Vf_mathArg - (Tc*)p);
  ToYNdL[5].off = (int)((Tc*)&p->Vf_pcreArg - (Tc*)p);
  ToYNdL[6].off = (int)((Tc*)&p->Vf_exeSuffix - (Tc*)p);
  ToYNdL[7].off = (int)((Tc*)&p->Vf_exePrefix - (Tc*)p);
  ToYNdL[8].off = (int)((Tc*)&p->Vf_int16Name - (Tc*)p);
  ToYNdL[9].off = (int)((Tc*)&p->Vf_int32Name - (Tc*)p);
  ToYNdL[10].off = (int)((Tc*)&p->Vf_int64Name - (Tc*)p);
  ToYNdL[11].off = (int)((Tc*)&p->Vf_nat16Name - (Tc*)p);
  ToYNdL[12].off = (int)((Tc*)&p->Vf_nat32Name - (Tc*)p);
  ToYNdL[13].off = (int)((Tc*)&p->Vf_nat64Name - (Tc*)p);
  ToYNdL[14].off = (int)((Tc*)&p->Vf_floatName - (Tc*)p);
  ToYNdL[15].off = (int)((Tc*)&p->Vf_float32Name - (Tc*)p);
  ToYNdL[16].off = (int)((Tc*)&p->Vf_intPtrName - (Tc*)p);
  ToYNdL[17].off = (int)((Tc*)&p->Vf_printIntFormat - (Tc*)p);
  ToYNdL[18].off = (int)((Tc*)&p->Vf_printNatFormat - (Tc*)p);
  ToYNdL[19].off = (int)((Tc*)&p->Vf_scanfHexFormat - (Tc*)p);
 }
}

/*
 * INIT GLOBALS
 */
int ZglobInit(int round) {
 int done = 1;
 Zsf sf={0,topFrame};
 topFrame = &sf;
 done &= JIOModule(round);
 done &= JLOGModule(round);
 done &= JARGModule(round);
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
 YzvW = Zstr(argv[0]);
 YQtK();
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
 Zsf sf={0,topFrame};
 Ti r = 0;
 topFrame = &sf;
 r = 0;
 sf.pos=527000;
 YWeD();
 sf.pos=527001;
 YZTI();
 sf.pos=527002;
 r = 0;
 topFrame = sf.prev;
 return r;
}
