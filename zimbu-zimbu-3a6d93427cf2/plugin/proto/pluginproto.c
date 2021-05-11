/*
 * Generated from Zimbu file plugin/proto/pluginproto.zu
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
typedef struct ZforList__S Tfl; /* FOR in list */
typedef struct ZforRange__S Tfr; /* FOR in range */

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
typedef struct Y8is__S Y8is; /* MIOModule.Writer */
typedef struct Yw8L__S Yw8L; /* MIOModule.File */
typedef struct YjUM__S YjUM; /* MIOModule.StringWriter */
/* IOModule done */
/* including SETModule typedefs */
typedef struct Yhqr__S Yhqr; /* MSETModule.Set__t1 */
typedef struct Ygqr__S Ygqr; /* MSETModule.Set__t2 */
/* SETModule done */
/* including ARGModule typedefs */
typedef struct YnU5__S YnU5; /* MARGModule.Status */
typedef struct YuMQ__S YuMQ; /* MARGModule.Usage */
typedef struct YuQR__S YuQR; /* MARGModule.Flag */
typedef struct Y86c__S Y86c; /* MARGModule.Bool */
typedef struct YJQu__S YJQu; /* MARGModule.Int */
typedef struct YzqH__S YzqH; /* MARGModule.String */
typedef struct Y_SI__S Y_SI; /* MARGModule.StringList */
/* ARGModule done */
/* including ParseProto typedefs */
/* including EnumItem typedefs */
typedef struct Y2Kp__S Y2Kp; /* EnumItem */
typedef struct YFk1__S YFk1; /* CEnumItem.Value */
/* EnumItem done */
/* including MessageItem typedefs */
/* including FieldItem typedefs */
typedef struct Y0uC__S Y0uC; /* FieldItem */
/* FieldItem done */
/* including OptionItem typedefs */
/* including PToken typedefs */
typedef struct Ykeq__S Ykeq; /* PToken */
/* PToken done */
typedef struct Yswy__S Yswy; /* OptionItem */
/* OptionItem done */
typedef struct YRAB__S YRAB; /* MessageItem */
/* MessageItem done */
/* including ProtoFile typedefs */
typedef struct YP_l__S YP_l; /* ProtoFile */
/* ProtoFile done */
/* including ServiceItem typedefs */
/* including RpcItem typedefs */
typedef struct YlM3__S YlM3; /* RpcItem */
/* RpcItem done */
typedef struct YNW5__S YNW5; /* ServiceItem */
/* ServiceItem done */
/* including PTokenInput typedefs */
/* including Input typedefs */
typedef struct YeYq__S YeYq; /* Input */
/* Input done */
typedef struct YuI4__S YuI4; /* PTokenInput */
/* PTokenInput done */
/* ParseProto done */
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
void ZthrowIobject(Ytlm *eo);
Ta *ZnewArray(Tt *itemType, int itemSize, Ti size);

Tl *ZnewList(Tt *itemType, Ti size);

Tl *ZLap(Tl *head, Tz val);
Tl *ZLa(Tl *head, Ti after, Tz val);

void *ZListGetPtr(Tl *head, Ti idx);

void *ZListRemovePtrItem(Tl *head, Ti idx);


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
struct YP_P__S {
 Tc **mt;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto YP_P__T;
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
typedef struct {
 char text[27];
} Zs27;
typedef struct {
 char text[30];
} Zs30;
typedef struct {
 char text[19];
} Zs19;
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
struct Ygqr__S {
 Td *Vdict;
};
extern Tto Ygqr__T;
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
/* including ParseProto structs */
/* including EnumItem structs */
struct YFk1__S {
 Tc *Vid;
 Ti Vnr;
 YkxB *Vpos;
};
extern Tto YFk1__T;
typedef struct {
 char text[26];
} Zs26;
struct Y2Kp__S {
 Tc *Vname;
 Tl *Vmembers;
};
extern Tto Y2Kp__T;
/* EnumItem done */
/* including MessageItem structs */
/* including FieldItem structs */
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
/* Proto done */
struct Y0uC__S {
 Tc *Vname;
 Te Vtype;
 Tc *VtypeName;
 Tb Vrequired;
 Tb Vrepeated;
 Ti Vnr;
 Tc *Vdefault;
 YkxB *Vpos;
};
extern Tto Y0uC__T;
/* FieldItem done */
/* including OptionItem structs */
/* including PToken structs */
struct Ykeq__S {
 Te Vtype;
 Tc *Vvalue;
 YkxB *VstartPos;
 YkxB *VendPos;
};
extern Tto Ykeq__T;
/* PToken done */
struct Yswy__S {
 Tc *Vname;
 YkxB *Vpos;
 Te Vtype;
 Tc *Vvalue;
};
extern Tto Yswy__T;
/* OptionItem done */
typedef struct {
 char text[25];
} Zs25;
struct YRAB__S {
 Tr Vparent;
 Tc *Vname;
 Tl *Vfields;
 Tl *Vitems;
 Tl *VoptionList;
};
extern Tto YRAB__T;
/* MessageItem done */
/* including ProtoFile structs */
struct YP_l__S {
 Tc *Vpackage;
 Tl *Vimports;
 Tl *VitemList;
 Td *VitemDict;
};
extern Tto YP_l__T;
/* ProtoFile done */
/* including ServiceItem structs */
/* including RpcItem structs */
struct YlM3__S {
 Tc *Vname;
 Tc *VrequestName;
 Tc *VresponseName;
};
extern Tto YlM3__T;
/* RpcItem done */
struct YNW5__S {
 Tc *Vname;
 Tl *Vrpcs;
};
extern Tto YNW5__T;
/* ServiceItem done */
/* including PTokenInput structs */
/* including Input structs */
struct YeYq__S {
 Yw8L *Vfd;
 Tc *Vtext;
 Ti VtextIdx;
 YkxB *Vpos;
 Ti VprevLineCol;
 Tl *VcharStack;
 Tc *Vindent;
 Tb VallowTabs;
 YjUM *VrecordWriter;
 Ti VrecordStartCol;
};
extern Tto YeYq__T;
/* Input done */
struct YuI4__S {
 YeYq *Vinput;
 Tl *VtokenStack;
};
extern Tto YuI4__T;
/* PTokenInput done */
typedef struct {
 char text[33];
} Zs33;
typedef struct {
 char text[35];
} Zs35;
/* ParseProto done */
/* including WriteZimbu structs */
typedef struct {
 char text[40];
} Zs40;
typedef struct {
 char text[61];
} Zs61;
typedef struct {
 char text[72];
} Zs72;
typedef struct {
 char text[57];
} Zs57;
typedef struct {
 char text[47];
} Zs47;
typedef struct {
 char text[55];
} Zs55;
typedef struct {
 char text[48];
} Zs48;
typedef struct {
 char text[46];
} Zs46;
typedef struct {
 char text[78];
} Zs78;
typedef struct {
 char text[54];
} Zs54;
typedef struct {
 char text[65];
} Zs65;
typedef struct {
 char text[62];
} Zs62;
typedef struct {
 char text[69];
} Zs69;
typedef struct {
 char text[38];
} Zs38;
typedef struct {
 char text[34];
} Zs34;
typedef struct {
 char text[49];
} Zs49;
typedef struct {
 char text[41];
} Zs41;
/* WriteZimbu done */
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
To ToY2KX[1];
Zs8 YeCO = {"\006Values\000"};
Tt MTIMEModule__EDst__T = {23, 0, 0};
/* TIMEModule done */
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
YX0i *YX0i__Yalz__YwtA__YRHRa(YX0i *t, YkxB *Apos, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
Tc *YX0i__mt[37];
To ToYX0i[4];
Zs11 Y9_h = {"\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {"\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {"\025Key already exists: \"\000"};
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg); /* MEModule__CIllegalByte.NEW__p3 */
Tc *YP_P__mt[37];
To ToYP_P[4];
Zs13 Ydbm = {"\013IllegalByte\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
Tc *YzSI__mt[37];
To ToYzSI[4];
Zs14 YxFl = {"\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
Tc *YXKl__mt[29];
To ToYXKl[4];
Zs9 YTj3 = {"\007IOError\000"};
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
/* including ZModule declarations */
YkxB *Ypp_(YkxB *t, Tc *Afilename); /* MZModule__CPos.NEW */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
YkxB *Y83A(YkxB *t); /* MZModule__CPos.copy */
void YnS4(YkxB *t); /* MZModule__CPos.nextLine */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {"\016[unknown file]\000"};
Zs8 YBpY = {"\006 line \000"};
Zs7 Y8ES = {"\005 col \000"};
To ToYkxB[3];
Zs5 YBCs = {"\003Pos\000"};
/* ZModule done */
/* including STRINGModule declarations */
Tc *YuAL(Tc *Athis, Ti Astart); /* MSTRINGModule.slice */
Tc *YuALa(Tc *Athis, Ti Astart, Ti Aend); /* MSTRINGModule.slice */
Zs2 Ya = {"\000\000"};
/* STRINGModule done */
/* including IOModule declarations */
Ti Y3QJ__NOT = -1 /* MIOModule.eof */;
Yw8L *Y59X = NULL; /* MIOModule.stdin */
Yw8L *Yb0q = NULL; /* MIOModule.stdout */
Yw8L *YeNQ = NULL; /* MIOModule.stderr */
Yw8L *Yd89(); /* MIOModule.newStdin */
Yw8L *Yvyt(); /* MIOModule.newStdout */
Yw8L *YsM3(); /* MIOModule.newStderr */
Tc **YdXi__imtt[4];
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
Ts YrF8(Yw8L *t); /* MIOModule__CFile.close */
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext); /* MIOModule__CFile.print__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__mt[59];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[1];
Zs6 YtTU = {"\004File\000"};
Yw8L *YsGz(Tc *AfileName); /* MIOModule.fileReader */
Yw8L *YiBk(Tc *AfileName, Tb Atruncate); /* MIOModule.fileWriter */
Ts Yvcu(Tc *Atext); /* MIOModule.write */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Tb Yqej(YjUM *t); /* MIOModule__CStringWriter.empty */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Ti Y6jW(YjUM *t); /* MIOModule__CStringWriter.remove */
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Ts YjUM__Ydti(YjUM *t, Ti Achar); /* MIOModule__CStringWriter.writeChar__p1 */
Zs53 Yv8w = {"\063UTF-8 character must be in range 0 - 0x10ffff, got \000"};
Ts YjUM__YRt7(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.print__p1 */
Tc *YjUM__mt[53];
Tc *YjUM__YdXi_imt[3];
To ToYjUM[2];
Zs14 YE4c = {"\014StringWriter\000"};
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
Tb Yf55(); /* MLOGModule.isInfoLog */
Tb Y0Ft(); /* MLOGModule.isVerboseLog */
Tb YOvp(); /* MLOGModule.isDebugLog */
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
Yw8L *Yz2b = NULL; /* MLOGModule.logFile */
Tb YiAD = 1 /* MLOGModule.useTimeStamp */;
int JLOGModule(int round);
/* LOGModule done */
/* including SETModule declarations */
int Ypau__r = 0; /* MSETModule__CSet__t1.Ready */
Yhqr *Ypau(Yhqr *t); /* MSETModule__CSet__t1.Init */
Yhqr *Yh95(Yhqr *t); /* MSETModule__CSet__t1.NEW */
Tb YyHa(Yhqr *t, Ti Akey); /* MSETModule__CSet__t1.has */
Yhqr *YGMT(Yhqr *t, Ti Akey); /* MSETModule__CSet__t1.add */
Zs23 YLLX = {"\025key already present: \000"};
To ToYhqr[2];
Zs9 Yehz = {"\007Set__t1\000"};
int YuFZ__r = 0; /* MSETModule__CSet__t2.Ready */
Ygqr *YuFZ(Ygqr *t); /* MSETModule__CSet__t2.Init */
Ygqr *YGrg(Ygqr *t); /* MSETModule__CSet__t2.NEW */
Tb YXZk(Ygqr *t, Tc *Akey); /* MSETModule__CSet__t2.has */
Ygqr *Y432(Ygqr *t, Tc *Akey); /* MSETModule__CSet__t2.add */
To ToYgqr[2];
Zs9 Yfhz = {"\007Set__t2\000"};
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
Zs8 Yr32 = {"\006Status\000"};
void YY8i(); /* MARGModule.initCheck */
Zs51 YeBP = {"\061Using command line flag before they are available\000"};
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
Tb YHoR(Y86c *t); /* MARGModule__CBool.get */
Tb YuOS(Y86c *t); /* MARGModule__CBool.value */
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CBool.NEW__p1 */
Zs42 Yc_h = {"\050Adding command line flag after using one\000"};
Zs50 Y6pY = {"\060Command line flag must have a short or long name\000"};
Zs52 Y9CP = {"\062short command line flag name must be one character\000"};
void Y86c__YofP(Y86c *t, Tc *Aname, YuQR *Aflag, YkxB *Apos); /* MARGModule__CBool.throwDuplicate__p1 */
Zs9 YbbH = {"\007unknown\000"};
Zs32 YtzG = {"\036Duplicate command line flag: '\000"};
Zs17 YDyy = {"\017' also used at \000"};
Ti Y86c__Ye9f(Y86c *t); /* MARGModule__CBool.presentCount__p1 */
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
/* including ParseProto declarations */
/* including EnumItem declarations */
Y2Kp *YIur(Y2Kp *t); /* CEnumItem.NEW */
void Y_Nc(Y2Kp *t, Tc *Aname, Ti Anr, YkxB *Apos); /* CEnumItem.addValue */
To ToYFk1[3];
Zs7 YmNk = {"\005Value\000"};
Ts YXXO(Y2Kp *t); /* CEnumItem.checkErrors */
Zs26 Y_xt = {"\030Enum number used again: \000"};
Tc *Y2Kp__YuXI_imt[2];
To ToY2Kp[3];
Zs10 Ym3J = {"\010EnumItem\000"};
/* EnumItem done */
/* including MessageItem declarations */
/* including FieldItem declarations */
/* including Proto declarations */
Tt MProto__EType__T = {23, 0, MProto__EType__name};
/* Proto done */
Tc *YULH(Y0uC *t); /* CFieldItem.memberName */
Zs5 YliF = {"\003$f_\000"};
Tc *YFlx(Y0uC *t); /* CFieldItem.hasMemberName */
Zs7 YZYy = {"\005$has_\000"};
Tc *YqGL(Y0uC *t); /* CFieldItem.funcName */
Zs7 YGxv = {"\005bytes\000"};
Zs5 Y1Qt = {"\003int\000"};
Zs7 YrQi = {"\005int32\000"};
Zs8 YJyN = {"\006uint32\000"};
Zs7 YhVi = {"\005int64\000"};
Zs8 YzDN = {"\006uint64\000"};
Zs7 Yt7n = {"\005float\000"};
Zs8 Ygep = {"\006double\000"};
Zs6 YtPw = {"\004bool\000"};
Td *YGNu = NULL; /* CFieldItem__X.typeDict */
Te YKJX(Tc *AtypeName); /* CFieldItem__X.getType */
To ToY0uC[5];
Zs11 Y5D2a = {"\011FieldItem\000"};
int JFieldItem(int round);
/* FieldItem done */
/* including OptionItem declarations */
/* including PToken declarations */
Tt CPToken__EType__T = {23, 0, 0};
To ToYkeq[4];
Zs8 YgVD = {"\006PToken\000"};
/* PToken done */
To ToYswy[4];
Zs12 YcBr = {"\012OptionItem\000"};
/* OptionItem done */
YRAB *YI6R(YRAB *t); /* CMessageItem.NEW */
void YNVJ(YRAB *t, Yswy *Aoption); /* CMessageItem.addOption */
Tr YBZe(YRAB *t, Tc *Aname); /* CMessageItem.findItem */
Ts YbaL(YRAB *t); /* CMessageItem.checkErrors */
Zs27 YUra = {"\031Field number used again: \000"};
Zs25 Yy3i = {"\027Field name used again: \000"};
Tc *YRAB__YuXI_imt[2];
Tc *YRAB__Ytv2_imt[2];
To ToYRAB[6];
Zs13 YQoy = {"\013MessageItem\000"};
int JMessageItem(int round);
/* MessageItem done */
/* including ProtoFile declarations */
YP_l *Yy3W(YP_l *t); /* CProtoFile.NEW */
void YhB6(YP_l *t, Tr Aitem); /* CProtoFile.addItem */
void YYPi(YP_l *t, Yswy *Aoption); /* CProtoFile.addOption */
Tr YKwR(YP_l *t, Tc *Aname); /* CProtoFile.findItem */
Tc *YP_l__Ytv2_imt[2];
To ToYP_l[5];
Zs11 YU8M = {"\011ProtoFile\000"};
/* ProtoFile done */
/* including ServiceItem declarations */
/* including RpcItem declarations */
YlM3 *YwLI(YlM3 *t, Tc *Aname); /* CRpcItem.NEW */
Tc *YlM3__YuXI_imt[2];
To ToYlM3[4];
Zs9 YWB_ = {"\007RpcItem\000"};
/* RpcItem done */
YNW5 *Y_oR(YNW5 *t); /* CServiceItem.NEW */
void YBM3(YNW5 *t, YlM3 *Arpc); /* CServiceItem.add */
Tr Y96y(YNW5 *t, Tc *Aname); /* CServiceItem.findItem */
Tc *YNW5__YuXI_imt[2];
To ToYNW5[3];
Zs13 YMK2 = {"\013ServiceItem\000"};
/* ServiceItem done */
/* including PTokenInput declarations */
/* including Input declarations */
YeYq *YOdr(YeYq *t, Yw8L *Afd, Tc *Afname, Tc *Aindent, Tb Arecord); /* CInput.NEW */
Ti YAit(YeYq *t); /* CInput.get */
Zs21 YrKy = {"\023found NUL character\000"};
Zs21 YemR = {"\023found Tab character\000"};
Zs25 Y3Pw = {"\027found control character\000"};
void YmK2(YeYq *t, Ti Ac); /* CInput.push */
To ToYeYq[7];
Zs7 YVUW = {"\005Input\000"};
/* Input done */
/* including PTokenize declarations */
Ykeq *Y7Z3(YuI4 *Ain); /* MPTokenize.get */
Zs22 YD4M = {"\024missing double quote\000"};
Zs22 YYrm = {"\024missing single quote\000"};
Zs27 YtNZ = {"\031Unrecognized character: '\000"};
Zs3 YN = {"\001'\000"};
void YVn_(YuI4 *Ain); /* MPTokenize.skipWhite */
Tb YdpE(Ti Ac); /* MPTokenize.isIdChar */
Zs9 YpLJ = {"\007default\000"};
Zs6 Y89Q = {"\004enum\000"};
Zs9 YL0B = {"\007message\000"};
Zs8 YXqe = {"\006option\000"};
Zs10 Yveu = {"\010optional\000"};
Zs9 Yg9u = {"\007package\000"};
Zs10 Ygug = {"\010repeated\000"};
Zs10 YJcg = {"\010required\000"};
Zs9 Yiu9 = {"\007returns\000"};
Zs5 Yf1Q = {"\003rpc\000"};
Zs9 YmU3 = {"\007service\000"};
Td *YwVY = NULL; /* MPTokenize.keywords */
int JPTokenize(int round);
/* PTokenize done */
YuI4 *YW5n(YuI4 *t, Yw8L *Afd, Tc *Afname, Tc *Aindent); /* CPTokenInput.NEW */
Ti YIaq(YuI4 *t); /* CPTokenInput.get */
void YCer(YuI4 *t, Ti Ac); /* CPTokenInput.push */
Ykeq *YVoF(YuI4 *t); /* CPTokenInput.getToken */
void Y4Sj(YuI4 *t, Ykeq *Atoken); /* CPTokenInput.pushToken */
To ToYuI4[3];
Zs13 Ytw1 = {"\013PTokenInput\000"};
int JPTokenInput(int round);
/* PTokenInput done */
YP_l *YSOt(Tc *Afname); /* MParseProto.parse */
Zs27 YdgR = {"\031Cannot open for reading: \000"};
Zs21 YJWm = {"\023Unrecognized item: \000"};
void YjA8(YuI4 *Ain, YP_l *Apfile); /* MParseProto.parsePackage */
Zs23 Y2by = {"\025Expected package name\000"};
Zs31 YHnJ = {"\035Only one package name allowed\000"};
Yswy *YDgP(YuI4 *Ain); /* MParseProto.parseOption */
Zs22 Y6FG = {"\024Expected option name\000"};
Zs29 Y82z = {"\033Expected string value or ID\000"};
Zs33 Y0Xz = {"\037Missing semicolor or equal sign\000"};
Tr YpkI(YuI4 *Ain, YP_l *Apfile); /* MParseProto.parseService */
Zs23 YJUj = {"\025Expected service name\000"};
Zs11 YlMg = {"\011Missing {\000"};
Zs16 YT_h = {"\016Expected \"rpc\"\000"};
Zs19 YImx = {"\021Expected rpc name\000"};
Zs12 YZG7 = {"\012Expected (\000"};
Zs23 Yq4F = {"\025Expected request name\000"};
Zs12 Y_G7 = {"\012Expected )\000"};
Zs20 YMrT = {"\022Expected \"returns\"\000"};
Zs24 YXcR = {"\026Expected response name\000"};
Tr YOrf(YuI4 *Ain); /* MParseProto.parseMessage */
Zs23 YmWM = {"\025Expected message name\000"};
Zs19 Y8wy = {"\021Unexpected item: \000"};
Y0uC *YFuL(Ykeq *Atoken, YuI4 *Ain); /* MParseProto.parseField */
Zs20 Yhu6 = {"\022Expected type name\000"};
Zs21 Yoyn = {"\023Expected field name\000"};
Zs6 YKIS = {"\004_has\000"};
Zs35 Ye1M = {"\041Field name cannot start with _has\000"};
Zs21 YHNV = {"\023Expected equal sign\000"};
Zs20 YG5z = {"\022Expected 'default'\000"};
Zs24 Y8XM = {"\026Expected default value\000"};
Zs7 Y2cy = {"\005FALSE\000"};
Zs6 YHoE = {"\004TRUE\000"};
Zs28 YItG = {"\032Expected 'false' or 'true'\000"};
Zs11 YSLg = {"\011Missing ]\000"};
Tr YCm2(YuI4 *Ain); /* MParseProto.parseEnum */
Zs20 YyCj = {"\022Expected enum name\000"};
Zs15 YTWr = {"\015Expected name\000"};
void YYYx(YuI4 *Ain); /* MParseProto.checkSemiColon */
Zs19 Ybzg = {"\021Missing semicolon\000"};
Tb YtEy(Ykeq *At); /* MParseProto.checkEof */
Zs24 YF0E = {"\026Unexpected end of file\000"};
Ti YeT_(YuI4 *Ain); /* MParseProto.parseNumber */
Zs17 YNZb = {"\017Expected number\000"};
void YUys(YP_l *A0, Tr A1); /* YP_l__MaddItem_I__YuXI_I */
int JParseProto(int round);
/* ParseProto done */
/* including WriteZimbu declarations */
void YCCA(YP_l *Apfile, Tc *AinFileName, Tc *AoutFileName); /* MWriteZimbu.write */
Zs27 Y32K = {"\031Cannot open for writing: \000"};
Zs19 Y_ZB = {"\021# Generated from \000"};
Zs31 YRCg = {"\035IMPORT $PLUGIN/proto/Proto.zu\000"};
Zs33 Y0jn = {"\037IMPORT $PLUGIN/proto/Message.zu\000"};
Zs9 YoyN = {"\007MODULE \000"};
Zs24 Y7Qg = {"\026 @public @items=public\000"};
Zs4 YZY = {"\002  \000"};
Zs19 YoBQ = {"\021unknown item type\000"};
void YxvA(YRAB *Amsg, Yw8L *Aout, Tc *Aindent); /* MWriteZimbu.writeClass */
Zs8 YB_i = {"\006CLASS \000"};
Zs40 YxMq = {"\046 EXTENDS Message @public @items=public\000"};
Zs9 YXgq = {"\007  NEW()\000"};
Zs5 YVet = {"\003  }\000"};
Zs43 Yow3 = {"\051  FUNC $name() string @replace @primitive\000"};
Zs14 YlWb = {"\014    RETURN \"\000"};
Zs16 Ysxb = {"\016Unknown type: \000"};
Zs10 YW8X = {"\010.unknown\000"};
Zs4 Ywla = {"\002.e\000"};
Zs12 YP0m = {"\012byteString\000"};
Zs3 YW = {"\0010\000"};
Zs7 YDFy = {"\005nat32\000"};
Zs5 YNmG = {"\003nat\000"};
Zs9 YdsC = {"\007float32\000"};
Zs33 Yl1o = {"\037SORRY, type not supported yet: \000"};
Zs7 Y9Ra = {"\005list<\000"};
Zs4 Y4Ja = {"\002> \000"};
Zs7 Y8Y5 = {"\005bool \000"};
Zs5 YWXt = {"\003 = \000"};
Zs6 YG4L = {"\004$has\000"};
Zs4 YXaa = {"\002()\000"};
Zs26 YJaV = {"\030PROC $clear() @primitive\000"};
Zs10 YRRN = {"\010 = FALSE\000"};
Zs31 Yzw4 = {"\035FUNC $valid() bool @primitive\000"};
Zs9 YZ35 = {"\007RETURN \000"};
Zs6 Y4zz = {"\004 && \000"};
Zs4 Yd1 = {"\002\"\"\000"};
Zs61 YcBy = {"\073FUNC $fieldSpecs() list<Proto.FieldSpec> @define @primitive\000"};
Zs19 Y1Dj = {"\021RETURN fieldSpecs\000"};
Zs72 YyUd = {"\106FUNC $mergeFromReader(Proto.FileFormat format, Proto.I_Reader reader) \000"};
Zs57 YKEm = {"\067Proto.mergeFromFields(THIS, format, fieldSpecs, reader)\000"};
Zs13 Y_Lu = {"\013RETURN THIS\000"};
Zs47 Y4Tv = {"\055FUNC $mergeFromBinary(Proto.I_Reader reader) \000"};
Zs55 YYQ8 = {"\065Proto.mergeFromBinaryFields(THIS, fieldSpecs, reader)\000"};
Zs48 YgCV = {"\056FUNC $mergeFromBinary(IO.I_ByteReader reader) \000"};
Zs51 Yew9 = {"\061$mergeFromBinary(Proto.Reader.NEW(reader, FALSE))\000"};
Zs53 YK2S = {"\063FUNC $mergeFromBinaryDeref(IO.I_ByteReader reader) \000"};
Zs50 Y0Sk = {"\060$mergeFromBinary(Proto.Reader.NEW(reader, TRUE))\000"};
Zs45 YwRP = {"\053FUNC $mergeFromText(Proto.I_Reader reader) \000"};
Zs53 Y4vI = {"\063Proto.mergeFromTextFields(THIS, fieldSpecs, reader)\000"};
Zs45 Yk1Y = {"\053FUNC $mergeFromJson(Proto.I_Reader reader) \000"};
Zs53 YwU4 = {"\063Proto.mergeFromJsonFields(THIS, fieldSpecs, reader)\000"};
Zs46 Yevx = {"\054FUNC $mergeFromJson(IO.I_CharReader reader) \000"};
Zs78 YlR1 = {"\114Proto.mergeFromJsonFields(THIS, fieldSpecs, Proto.Reader.NEW(reader, FALSE))\000"};
Zs8 YuOB = {"\006SHARED\000"};
Zs27 YaU5 = {"\031FUNC newMessage() Message\000"};
Zs8 YyLL = {"\006.NEW()\000"};
Zs8 Yjby = {"\006Binary\000"};
Zs6 Y27q = {"\004Text\000"};
Zs6 Yz0N = {"\004Json\000"};
Zs17 Yts2 = {"\017FUNC createFrom\000"};
Zs17 YIIp = {"\017IO.I_ByteReader\000"};
Zs17 YDa5 = {"\017IO.I_CharReader\000"};
Zs3 YO = {"\001(\000"};
Zs11 YYDR = {"\011 reader) \000"};
Zs18 Yvx0 = {"\020.NEW().mergeFrom\000"};
Zs35 YPYp = {"\041(Proto.Reader.NEW(reader, FALSE))\000"};
Zs10 Yqfe = {"\010(reader)\000"};
Zs24 YKhU = {"\026FUNC createMessageFrom\000"};
Zs18 Y52_ = {"\020 reader) Message\000"};
Zs19 YGO0 = {"\021RETURN createFrom\000"};
Zs8 YZix = {"\006Deref(\000"};
Zs15 Yvyf = {"\015Deref(reader)\000"};
Zs53 YD3Q = {"\063FUNC createFromBinaryDeref(IO.I_ByteReader reader) \000"};
Zs56 YNfH = {"\066.NEW().mergeFromBinary(Proto.Reader.NEW(reader, TRUE))\000"};
Zs51 Y8OQ = {"\061FUNC createFromJsonDeref(IO.I_CharReader reader) \000"};
Zs54 Y55l = {"\064.NEW().mergeFromJson(Proto.Reader.NEW(reader, TRUE))\000"};
void YHzx(Tc *Atype, Tc *AretType, Tl *Afields, Tc *Adefault, Tc *Aindent, Yw8L *Aout); /* MWriteZimbu.writeGetSet */
Zs8 YMja = {"\006FUNC $\000"};
Zs17 YQBH = {"\017Get(int fieldNr\000"};
Zs11 YNcD = {"\011, int idx\000"};
Zs4 Ypca = {"\002) \000"};
Zs22 YYx8 = {"\024 @replace @primitive\000"};
Zs18 Y3Rg = {"\020  SWITCH fieldNr\000"};
Zs11 Y4Qg = {"\011    CASE \000"};
Zs11 YBII = {"\011; RETURN \000"};
Zs7 YxsN = {"\005[idx]\000"};
Zs6 YbT7 = {"\004from\000"};
Zs7 Y14u = {"\0052int[\000"};
Zs7 Y9Ud = {"\005 == 2\000"};
Zs11 YKKn = {"\011  RETURN \000"};
Zs31 YTzv = {"\035FUNC $enumNameGet(int fieldNr\000"};
Zs30 Y5Bw = {"\034) string @replace @primitive\000"};
Zs12 YBXc = {"\012  string s\000"};
Zs8 YuV2 = {"\006; s = \000"};
Zs53 YgZi = {"\063.ToString(); RETURN s == \"unknown\" ? s : s.slice(1)\000"};
Zs13 YfaF = {"\013  RETURN \"\"\000"};
Zs8 YmYN = {"\006PROC $\000"};
Zs19 Y5KZ = {"\021Set(int fieldNr, \000"};
Zs29 YmiC = {"\033 value) @replace @primitive\000"};
Zs4 YgFa = {"\002; \000"};
Zs6 YO9t = {"\004$add\000"};
Zs6 Yxtk = {"\004int2\000"};
Zs16 YoJI = {"\016.has(value) ? \000"};
Zs12 Y9CL = {"\012[value] : \000"};
Zs7 Y37y = {"\005value\000"};
Zs17 YHfx = {"\017(value ? 2 : 1)\000"};
Zs9 YPKf = {"\007value; \000"};
Zs9 YKf1 = {"\007 = TRUE\000"};
Zs3 YP = {"\001)\000"};
Zs65 Ygbr = {"\077PROC $enumNameSet(int fieldNr, string name) @replace @primitive\000"};
Zs26 Y4s5 = {"\030.FromString(\"e\" .. name)\000"};
Tb YTU9(Tl *Afields); /* MWriteZimbu.hasRepeated */
Tb YADt(Tl *Afields); /* MWriteZimbu.hasNotRepeated */
void YwAg(Tl *Afields, Tc *Aindent, Yw8L *Aout); /* MWriteZimbu.writeWriteMerge */
Zs30 YO3G = {"\034FUNC $messageGet(int fieldNr\000"};
Zs31 YRua = {"\035) Message @replace @primitive\000"};
Zs14 Yzrg = {"\014  RETURN NIL\000"};
Zs62 YhqR = {"\074PROC $messageAdd(int fieldNr, Message m) @replace @primitive\000"};
Zs62 YfRA = {"\074PROC $messageSet(int fieldNr, Message m) @replace @primitive\000"};
Zs5 Y6y9 = {"\003IF \000"};
Zs11 YNM4 = {"\011 == NIL; \000"};
Zs13 YI0U = {"\013 = NEW(); }\000"};
Zs14 YR8A = {"\014            \000"};
Zs9 YVtc = {"\007.add(m)\000"};
Zs6 YRyv = {"\004 = m\000"};
Zs69 YfXS = {"\103FUNC $mergeMessageFromReader(int fieldNr, Proto.FileFormat format, \000"};
Zs38 Yf3o = {"\044Proto.I_Reader reader) bool @replace\000"};
Zs8 Ya8x = {"\006      \000"};
Zs9 YgCk = {"\007 == NIL\000"};
Zs10 YII0 = {"\010 = NEW()\000"};
Zs12 Yi_6 = {"\012 m = NEW()\000"};
Zs18 Yt1y = {"\020reader.addRef(m)\000"};
Zs35 YU62 = {"\041m.mergeFromReader(format, reader)\000"};
Zs16 YG9J = {"\016reader.addRef(\000"};
Zs34 YDFV = {"\040.mergeFromReader(format, reader)\000"};
Zs13 YdMU = {"\013RETURN TRUE\000"};
Zs16 YwAl = {"\016  RETURN FALSE\000"};
void YYCV(Tl *Afields, Tc *Aindent, Yw8L *Aout); /* MWriteZimbu.writeHasField */
Zs54 YpN1 = {"\064FUNC $hasField(int fieldNr) bool @replace @primitive\000"};
Zs15 YpgF = {"\015; RETURN $has\000"};
void Yg8t(YRAB *Amsg, Tc *Aindent, Yw8L *Aout); /* MWriteZimbu.writeCopy */
Zs24 YcuF = {"\026FUNC $copy(bool deep) \000"};
Zs14 YEsj = {"\014 ret = NEW()\000"};
Zs6 Y2C2 = {"\004ret.\000"};
Zs9 YGbi = {"\007IF deep\000"};
Zs7 YiHe = {"\005  IF \000"};
Zs9 Y2Nk = {"\007 != NIL\000"};
Zs10 Y5Fk = {"\010    ret.\000"};
Zs15 YAGs = {"\015    FOR i IN \000"};
Zs12 YO9y = {"\012      ret.\000"};
Zs20 YR9A = {"\022.add(i.copy(deep))\000"};
Zs9 Yvnc = {"\007.add(i)\000"};
Zs7 Y6my = {"\005    }\000"};
Zs6 Yc7A = {"\004ELSE\000"};
Zs8 YhLg = {"\006  ret.\000"};
Zs12 YRQE = {"\012 = deep ? \000"};
Zs16 Ybf2 = {"\016.copy(deep) : \000"};
Zs12 Yxe8 = {"\012RETURN ret\000"};
void Ycma(Tl *Afields, Tc *Aindent, Yw8L *Aout); /* MWriteZimbu.writeSize */
Zs49 YvCR = {"\057FUNC $size(int fieldNr) int @replace @primitive\000"};
Zs16 YG_R = {"\016 == NIL ? 0 : \000"};
Zs9 YZY7 = {"\007.Size()\000"};
Zs12 Yc_G = {"\012  RETURN 0\000"};
void YMWy(Tl *Afields, Tc *Aindent, Yw8L *Aout); /* MWriteZimbu.writeFieldTable */
Zs38 YMvm = {"\044list<Proto.FieldSpec> fieldSpecs = [\000"};
Zs9 YQgq = {"\007  NEW(\"\000"};
Zs5 YwFy = {"\003\", \000"};
Zs15 YqQF = {"\015, Proto.Type.\000"};
Zs4 Ydha = {"\002, \000"};
Zs4 YBca = {"\002),\000"};
void Y1M2(Tc *Aclass, Y0uC *Afield, Tc *Atype, Tc *AinitVal, Tc *AdefaultVal, Tc *Aindent, Yw8L *Aout); /* MWriteZimbu.writeSetGetHas */
Zs11 Yctj = {"\011FUNC $set\000"};
Zs6 YxgQ = {"\004 v) \000"};
Zs13 YNOm = {"\013 @primitive\000"};
Zs14 Ybd2 = {"\014 = v ? 2 : 1\000"};
Zs6 Y_yv = {"\004 = v\000"};
Zs15 YYwn = {"\015  RETURN THIS\000"};
Zs11 YEC6 = {"\011FUNC $new\000"};
Zs5 Ye0N = {"\003() \000"};
Zs11 Y9CPa = {"\011FUNC $get\000"};
Zs8 YwS1 = {"\006  IF !\000"};
Zs6 Y7gw = {"\004 == \000"};
Zs13 YG_k = {"\013    RETURN \000"};
Zs18 YQIB = {"\020    RETURN FALSE\000"};
Zs15 YJGx = {"\015    RETURN \"\"\000"};
Zs14 YzWb = {"\014    RETURN 0\000"};
Zs13 YdiJ = {"\013    THROW \"\000"};
Zs15 YTKi = {"\015 was not set\"\000"};
Zs11 YE5R = {"\011FUNC $has\000"};
Zs20 YBMj = {"\022() bool @primitive\000"};
Zs6 Yljn = {"\004 != \000"};
Zs13 YnyF = {"\013FUNC $clear\000"};
void YsmR(Tc *Aclass, Y0uC *Afield, Tc *Atype, Tc *AdefaultVal, Tc *Aindent, Yw8L *Aout); /* MWriteZimbu.writeAddGetHas */
Zs11 YMaA = {"\011FUNC $add\000"};
Zs6 YW_j = {"\004    \000"};
Zs9 YlIc = {"\007.add(v)\000"};
Zs14 YEnH = {"\014FUNC $addNew\000"};
Zs12 Y0_k = {"\012 v = NEW()\000"};
Zs8 Y2hI = {"\006  $add\000"};
Zs5 YPYP = {"\003(v)\000"};
Zs12 Y5YG = {"\012  RETURN v\000"};
Zs10 Y7in = {"\010(int i) \000"};
Zs16 YD5ta = {"\016  IF i < 0 || \000"};
Zs18 YAGJ = {"\020 == NIL || i >= \000"};
Zs41 YOn3 = {"\047    THROW \"list index out of range for \000"};
Zs10 YEpL = {"\010: \" .. i\000"};
Zs5 YLJU = {"\003[i]\000"};
Zs14 Ynjc = {"\014List() list<\000"};
Zs14 Yp5Q = {"\014> @primitive\000"};
Zs12 YCj9 = {"\012List(list<\000"};
Zs7 YWFy = {"\005> l) \000"};
Zs6 YQyv = {"\004 = l\000"};
Zs12 YgyZ = {"\012FUNC $size\000"};
Zs19 Y3FL = {"\021() int @primitive\000"};
Zs13 YIgG = {"\013 != NIL && \000"};
Zs13 YW_F = {"\013.Size() > 0\000"};
Zs25 YwnZ = {"\027(int i) bool @primitive\000"};
Zs21 YBWs = {"\023  RETURN i >= 0 && \000"};
Zs17 YEqC = {"\017 != NIL && i < \000"};
Zs8 YsTa = {"\006 = NIL\000"};
void Yk4Q(YNW5 *Aservice, Yw8L *Aout, Tc *Aindent); /* MWriteZimbu.writeService */
Zs11 Y9d4 = {"\011  MODULE \000"};
Zs10 YZZg = {"\010  # rpc \000"};
Zs12 YOlD = {"\012) returns \000"};
Zs13 YHny = {"\013  FUNC call\000"};
Zs12 Y8Bf = {"\012 request, \000"};
Zs35 YJ4N = {"\041proc<RPC.Control, Message> done) \000"};
Zs13 Y84u = {"\013RPC.Control\000"};
Zs21 YclF = {"\023IF !request.valid()\000"};
Zs22 YI05 = {"\024  RETURN Proto.rpc(\"\000"};
Zs14 YnFL = {"\014\", request, \000"};
Zs28 YQuz = {"\032GENERATE_IF Z.lang == \"JS\"\000"};
Zs41 Y9Ba = {"\047.createMessageFromJsonDeref, NIL, done)\000"};
Zs31 YKC8 = {"\035GENERATE_ELSEIF Z.lang == \"C\"\000"};
Zs7 YZeO = {"\005NIL, \000"};
Zs38 YihP = {"\044.createMessageFromBinaryDeref, done)\000"};
Zs15 Yuso = {"\015GENERATE_ELSE\000"};
Zs29 YIzR = {"\033  GENERATE_IF Z.lang == \"C\"\000"};
Zs22 Yhls = {"\024Proto.RpcInfo handle\000"};
Zs10 YBI0 = {"\010 = NEW(\"\000"};
Zs31 YJQW = {"\035.createMessageFromJsonDeref, \000"};
Zs14 YNbo = {"\014.newMessage)\000"};
void Y8RG(Y2Kp *Aenum, Yw8L *Aout, Tc *Aindent); /* MWriteZimbu.writeEnum */
Zs7 Ywwj = {"\005ENUM \000"};
Zs10 YAId = {"\010 @public\000"};
Zs11 YXRY = {"\011  unknown\000"};
Zs5 Yxet = {"\003  e\000"};
Zs7 Yfpd = {"\005dict<\000"};
Zs13 Yj9U = {"\013, int> from\000"};
Zs10 Y9UL = {"\0102int = [\000"};
Zs15 Yu8y = {"\015.unknown: -1,\000"};
Zs3 YS = {"\001,\000"};
Zs12 Yxa6 = {"\012dict<int, \000"};
Zs8 Y9oy = {"\006> int2\000"};
Zs6 Yzyv = {"\004 = [\000"};
void YCOQ(Tc *AinFileName, Tc *AoutFileName); /* MWriteZimbu.writeError */
Zs17 YK3s = {"\017Error handling \000"};
/* WriteZimbu done */
Zs9 YZVC = {"\007Usage: \000"};
Zs26 YWbL = {"\030 infile.proto outfile.zu\000"};
Zs8 YnKK = {"\006.proto\000"};
Zs42 YwwA = {"\050ERROR: Input name must end in '.proto': \000"};
Zs5 YYv4 = {"\003.zu\000"};
Zs40 YIhh = {"\046ERROR: output name must end in '.zu': \000"};

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
Tc YCG4[]="lib/ARGModule.zu";
Tc Yt1T[]="lib/EModule.zu";
Tc Yay0[]="lib/IOModule.zu";
Tc Y76z[]="lib/LOGModule.zu";
Tc YxHL[]="lib/SETModule.zu";
Tc Yv00[]="lib/STRINGModule.zu";
Tc YyXk[]="lib/TIMEModule.zu";
Tc Y3zM[]="lib/ZModule.zu";
Tc YPyp[]="parser/Input.zu";
Tc Yeop[]="plugin/proto/EnumItem.zu";
Tc Y7gD[]="plugin/proto/FieldItem.zu";
Tc Yxbi[]="plugin/proto/MessageItem.zu";
Tc YEew[]="plugin/proto/PTokenInput.zu";
Tc Y1IY[]="plugin/proto/PTokenize.zu";
Tc YnGo[]="plugin/proto/ParseProto.zu";
Tc Y_R2[]="plugin/proto/ProtoFile.zu";
Tc YjxU[]="plugin/proto/RpcItem.zu";
Tc YGYp[]="plugin/proto/ServiceItem.zu";
Tc YFTE[]="plugin/proto/WriteZimbu.zu";
Tc YLrK[]="plugin/proto/pluginproto.zu";
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
Tc Y2cg[]="ARG.Bool.value()";
Tcpos ZcTbl61284[]={
{829,11},
{1,15},
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
Tc Y2NH[]="E.IllegalByte.NEW__p3/3()";
Tcpos ZcTbl45209[]={
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
Tc YhC6[]="E.KeyExists.NEW__p3/4()";
Tcpos ZcTbl95201[]={
{67,5},
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
Tc YmDz[]="EnumItem.NEW()";
Tcpos ZcTbl58121[]={
{16,3},
{1,14},
};
Tc YTU3[]="EnumItem.addValue()";
Tcpos ZcTbl89141[]={
{20,9},
{1,15},
{2,10},
{3,10},
{4,11},
{5,5},
};
Tc YLFA[]="EnumItem.checkErrors()";
Tcpos ZcTbl40190[]={
{35,9},
{1,21},
{2,18},
{3,5},
{4,7},
{5,9},
{6,13},
{8,9},
{3,5},
{11,12},
};
Tc Y5D2[]="FieldItem";
Tcpos ZcTbl90183[]={
{53,30},
};
Tc YAt2[]="FieldItem.funcName()";
Tcpos ZcTbl2571[]={
{47,9},
{1,40},
};
Tc YHJi[]="FieldItem.getType()";
Tcpos ZcTbl19772[]={
{67,7},
{1,16},
{3,25},
};
Tc YIwZ[]="FieldItem.hasMemberName()";
Tcpos ZcTbl60791[]={
{30,9},
{1,5},
{2,7},
{10,26},
{13,12},
};
Tc YBp9[]="FieldItem.memberName()";
Tcpos ZcTbl36283[]={
{24,9},
{1,18},
};
Tc Ys1a[]="IO";
Tcpos ZcTbl7452[]={
{26,8},
{3,8},
{6,8},
};
Tc YEgn[]="IO.File.close()";
Tcpos ZcTbl15755[]={
{642,11},
{1,20},
{2,7},
{6,4},
{9,4},
{19,13},
{21,14},
};
Tc YskO[]="IO.File.flush()";
Tcpos ZcTbl60567[]={
{624,11},
{1,20},
{2,7},
{4,4},
{12,14},
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
Tc Y5P_[]="IO.File.readByte()";
Tcpos ZcTbl16053[]={
{257,11},
{1,7},
{2,9},
{6,4},
{28,14},
};
Tc YHCY[]="IO.File.readChar()";
Tcpos ZcTbl46631[]={
{290,11},
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
Tc YdDi[]="IO.StringWriter.empty()";
Tcpos ZcTbl59312[]={
{1772,11},
{1,20},
};
Tc YYk7[]="IO.StringWriter.print__p1/8()";
Tcpos ZcTbl26760[]={
{186,11},
{1,7},
{2,16},
{4,14},
};
Tc YSa1[]="IO.StringWriter.remove()";
Tcpos ZcTbl58975[]={
{1800,11},
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
Tc YTE3[]="IO.fileReader()";
Tcpos ZcTbl99838[]={
{1208,4},
{5,9},
{6,4},
{28,12},
};
Tc Y5X7[]="IO.fileWriter()";
Tcpos ZcTbl81580[]={
{1250,4},
{8,9},
{9,4},
{32,12},
};
Tc YN2v[]="IO.flush()";
Tcpos ZcTbl46761[]={
{1672,4},
{9,12},
};
Tc YNFk[]="IO.print()";
Tcpos ZcTbl1872[]={
{1551,37},
{1,4},
{18,12},
};
Tc Y_pS[]="IO.write()";
Tcpos ZcTbl84870[]={
{1488,4},
{13,12},
};
Tc YOoa[]="Input.NEW()";
Tcpos ZcTbl44401[]={
{39,3},
{1,9},
{2,10},
{3,16},
{4,13},
{5,5},
{6,21},
};
Tc YHM2[]="Input.get()";
Tcpos ZcTbl19887[]={
{63,9},
{1,25},
{3,5},
{4,9},
{5,15},
{6,16},
{7,7},
{8,11},
{10,11},
{11,9},
{12,17},
{15,7},
{16,11},
{17,17},
{19,9},
{20,11},
{21,13},
{22,15},
{23,20},
{24,13},
{25,15},
{27,15},
{28,28},
{29,13},
{30,15},
{33,7},
{15,7},
{36,5},
{37,20},
{38,7},
{41,5},
{42,7},
{43,25},
{45,7},
{48,12},
};
Tc Yq05[]="Input.push()";
Tcpos ZcTbl34047[]={
{115,9},
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
{19,12},
{2,12},
{49,20},
};
Tc YFIR[]="LOG.flush()";
Tcpos ZcTbl56555[]={
{243,5},
{1,5},
{2,7},
{4,15},
};
Tc YfqK[]="LOG.isDebugLog()";
Tcpos ZcTbl42310[]={
{156,22},
};
Tc YI4R[]="LOG.isInfoLog()";
Tcpos ZcTbl47139[]={
{146,39},
};
Tc YwYU[]="LOG.isVerboseLog()";
Tcpos ZcTbl15153[]={
{151,39},
};
Tc Y8w5[]="LOG.reportStack()";
Tcpos ZcTbl84899[]={
{226,7},
{2,18},
{2,7},
{2,18},
{3,9},
{4,11},
{6,20},
{2,7},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{29,3},
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
{19,36},
{21,3},
{24,5},
{25,12},
{28,3},
{30,10},
};
Tc YFwg[]="MessageItem.NEW()";
Tcpos ZcTbl39213[]={
{26,3},
{1,13},
{2,12},
{3,17},
};
Tc YA9q[]="MessageItem.checkErrors()";
Tcpos ZcTbl39906[]={
{49,9},
{1,23},
{2,28},
{3,18},
{4,5},
{5,7},
{6,9},
{7,13},
{8,23},
{9,9},
{10,13},
{12,9},
{13,9},
{4,5},
{16,12},
};
Tc YU0e[]="MessageItem.findItem()";
Tcpos ZcTbl1679[]={
{36,9},
{1,5},
{2,7},
{3,16},
{1,5},
{6,5},
{7,22},
{9,12},
};
Tc Yu_S[]="PTokenInput.NEW()";
Tcpos ZcTbl44318[]={
{28,3},
{1,12},
{2,17},
};
Tc YnnL[]="PTokenInput.get()";
Tcpos ZcTbl19804[]={
{37,9},
{1,19},
};
Tc Y7nB[]="PTokenInput.getToken()";
Tcpos ZcTbl35249[]={
{48,9},
{1,5},
{2,26},
{4,22},
};
Tc YWz4[]="PTokenInput.push()";
Tcpos ZcTbl44960[]={
{42,9},
{1,5},
};
Tc YKZm[]="PTokenInput.pushToken()";
Tcpos ZcTbl20933[]={
{56,9},
{1,5},
};
Tc YWUU[]="PTokenize";
Tcpos ZcTbl50421[]={
{173,29},
};
Tc YKPD[]="PTokenize.get()";
Tcpos ZcTbl63024[]={
{19,18},
{1,18},
{4,5},
{6,18},
{7,30},
{9,16},
{10,5},
{11,7},
{13,5},
{15,18},
{17,18},
{19,18},
{21,18},
{23,18},
{25,18},
{27,18},
{29,18},
{31,18},
{34,9},
{35,18},
{37,9},
{38,13},
{39,11},
{42,11},
{43,13},
{44,13},
{47,11},
{48,15},
{49,13},
{50,15},
{53,13},
{54,15},
{55,22},
{56,15},
{57,22},
{58,15},
{60,15},
{63,13},
{37,9},
{69,13},
{70,20},
{71,11},
{72,15},
{73,13},
{75,19},
{77,19},
{79,19},
{82,11},
{83,11},
{84,13},
{85,11},
{86,13},
{92,11},
{93,13},
{97,13},
{98,20},
{100,13},
{101,13},
{102,15},
{103,17},
{101,13},
{105,13},
{108,20},
{109,11},
{110,22},
{114,15},
{115,16},
{116,12},
};
Tc Yit2[]="PTokenize.isIdChar()";
Tcpos ZcTbl41999[]={
{170,9},
};
Tc YPvQ[]="PTokenize.skipWhite()";
Tcpos ZcTbl50024[]={
{143,5},
{1,9},
{2,7},
{3,21},
{4,9},
{6,11},
{7,15},
{8,13},
{6,11},
{14,9},
{16,7},
{0,5},
{20,5},
};
Tc Ypaua[]="ParseProto.checkEof()";
Tcpos ZcTbl5070[]={
{398,5},
{1,7},
{2,14},
{4,12},
};
Tc Y0Ij[]="ParseProto.checkSemiColon()";
Tcpos ZcTbl35761[]={
{389,19},
{1,5},
{2,7},
{3,7},
};
Tc YDsz[]="ParseProto.parse()";
Tcpos ZcTbl71573[]={
{34,23},
{2,21},
{3,5},
{4,7},
{5,12},
{7,22},
{8,24},
{10,5},
{11,5},
{12,25},
{13,7},
{17,7},
{19,11},
{22,11},
{25,11},
{28,29},
{28,29},
{29,22},
{30,11},
{33,11},
{36,11},
{11,5},
{40,5},
{42,12},
};
Tc YCVw[]="ParseProto.parseEnum()";
Tcpos ZcTbl51410[]={
{344,21},
{2,19},
{3,5},
{4,7},
{6,17},
{7,9},
{8,7},
{9,9},
{11,9},
{13,13},
{14,11},
{17,11},
{20,11},
{21,13},
{23,27},
{25,13},
{26,11},
{27,13},
{30,20},
{31,11},
{33,11},
{11,9},
{36,9},
{40,12},
};
Tc YdOc[]="ParseProto.parseField()";
Tcpos ZcTbl52269[]={
{268,23},
{1,15},
{2,5},
{4,24},
{6,24},
{10,19},
{11,5},
{12,7},
{14,18},
{15,22},
{18,7},
{19,5},
{20,7},
{22,18},
{23,7},
{25,9},
{29,7},
{30,5},
{31,7},
{34,14},
{36,7},
{37,5},
{39,9},
{40,7},
{41,9},
{43,9},
{44,7},
{45,9},
{47,9},
{48,7},
{49,9},
{51,23},
{53,9},
{54,25},
{55,11},
{56,13},
{60,9},
{61,7},
{62,9},
{64,11},
{68,5},
{69,5},
{71,12},
};
Tc YJA9[]="ParseProto.parseMessage()";
Tcpos ZcTbl8550[]={
{219,24},
{2,19},
{3,5},
{4,7},
{6,17},
{7,9},
{8,7},
{9,9},
{11,9},
{12,13},
{13,11},
{16,11},
{19,11},
{23,15},
{26,33},
{26,33},
{27,26},
{28,15},
{31,15},
{34,15},
{37,15},
{11,9},
{41,7},
{44,12},
};
Tc YQ3a[]="ParseProto.parseNumber()";
Tcpos ZcTbl66510[]={
{408,19},
{1,5},
{2,7},
{4,20},
};
Tc YPIw[]="ParseProto.parseOption()";
Tcpos ZcTbl12726[]={
{95,25},
{1,19},
{2,5},
{3,7},
{5,18},
{6,19},
{8,9},
{9,7},
{10,11},
{11,9},
{12,11},
{14,23},
{15,24},
{16,11},
{18,21},
{19,9},
{22,12},
};
Tc YgZJ[]="ParseProto.parsePackage()";
Tcpos ZcTbl94525[]={
{81,19},
{1,5},
{2,7},
{3,26},
{4,7},
{6,21},
{8,5},
};
Tc YKht[]="ParseProto.parseService()";
Tcpos ZcTbl6262[]={
{134,27},
{3,19},
{4,5},
{5,7},
{7,20},
{8,9},
{9,7},
{10,9},
{12,9},
{13,13},
{14,11},
{17,11},
{21,11},
{22,13},
{24,15},
{25,13},
{26,15},
{28,29},
{29,15},
{32,17},
{33,15},
{34,17},
{36,17},
{37,15},
{38,17},
{40,33},
{42,15},
{43,19},
{44,17},
{45,19},
{48,17},
{49,15},
{50,17},
{56,17},
{58,15},
{59,30},
{60,19},
{62,15},
{63,17},
{65,34},
{67,15},
{68,19},
{69,17},
{70,19},
{74,15},
{12,9},
{80,12},
};
Tc YjO7[]="ProtoFile.NEW()";
Tcpos ZcTbl35721[]={
{27,3},
{1,15},
{2,15},
{3,14},
};
Tc Y5m_[]="ProtoFile.addItem()";
Tcpos ZcTbl3531[]={
{34,9},
{1,5},
{2,7},
{3,7},
};
Tc YcQA[]="ProtoFile.findItem()";
Tcpos ZcTbl38811[]={
{45,9},
{2,5},
{3,7},
{4,16},
{2,5},
{8,5},
{9,33},
{10,7},
{11,16},
{8,5},
{15,12},
};
Tc YViu[]="RpcItem.NEW()";
Tcpos ZcTbl57273[]={
{18,3},
{1,11},
};
Tc YYkI[]="SET.Set__t1.Init()";
Tcpos ZcTbl89012[]={
{41,13},
};
Tc YjAA[]="SET.Set__t1.NEW()";
Tcpos ZcTbl21378[]={
{45,5},
};
Tc YFAP[]="SET.Set__t1.has()";
Tcpos ZcTbl25860[]={
{92,7},
{1,16},
{3,20},
};
Tc YzJ7[]="SET.Set__t2.Init()";
Tcpos ZcTbl99713[]={
{41,13},
};
Tc YiL5[]="SET.Set__t2.NEW()";
Tcpos ZcTbl71979[]={
{45,5},
};
Tc YELk[]="SET.Set__t2.has()";
Tcpos ZcTbl76461[]={
{92,7},
{1,16},
{3,20},
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
Tc YLSX[]="ServiceItem.NEW()";
Tcpos ZcTbl36381[]={
{18,3},
{1,11},
};
Tc YM1j[]="ServiceItem.add()";
Tcpos ZcTbl55944[]={
{22,9},
{1,5},
};
Tc YYJc[]="ServiceItem.findItem()";
Tcpos ZcTbl66335[]={
{26,9},
{1,5},
{2,7},
{3,16},
{1,5},
{6,12},
};
Tc YQE_[]="TIME.Values.NEW()";
Tcpos ZcTbl5342[]={
{56,5},
{1,7},
};
Tc Y0DO[]="TIME.Values.NEW/2()";
Tcpos ZcTbl32939[]={
{70,5},
{2,4},
{37,13},
};
Tc YHWY[]="TIME.Values.ToString()";
Tcpos ZcTbl34818[]={
{138,11},
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
{23,4},
{10,12},
};
Tc YnO0[]="WriteZimbu.hasNotRepeated()";
Tcpos ZcTbl10800[]={
{542,5},
{1,7},
{2,16},
{0,5},
{5,12},
};
Tc YIr_[]="WriteZimbu.hasRepeated()";
Tcpos ZcTbl1755[]={
{533,5},
{1,7},
{2,16},
{0,5},
{5,12},
};
Tc Yehha[]="WriteZimbu.write()";
Tcpos ZcTbl44260[]={
{24,22},
{1,5},
{2,7},
{3,12},
{5,5},
{6,5},
{7,5},
{8,5},
{9,5},
{13,5},
{14,13},
{15,21},
{16,7},
{17,15},
{20,13},
{22,19},
{23,5},
{24,13},
{26,7},
{27,5},
{28,13},
{31,11},
{32,5},
{35,5},
{36,7},
{37,27},
{37,27},
{38,9},
{39,19},
{40,25},
{40,25},
{41,9},
{42,19},
{43,31},
{43,31},
{44,9},
{46,9},
{35,5},
{50,5},
{52,5},
};
Tc Y8JY[]="WriteZimbu.writeAddGetHas()";
Tcpos ZcTbl24269[]={
{809,31},
{1,29},
{4,5},
{6,5},
{7,5},
{8,5},
{9,5},
{10,5},
{11,5},
{13,5},
{15,7},
{16,7},
{17,7},
{18,7},
{19,7},
{23,5},
{25,5},
{29,5},
{31,5},
{32,5},
{33,5},
{36,5},
{38,5},
{39,5},
{42,5},
{44,5},
{45,5},
{46,5},
{49,5},
{50,5},
{52,5},
{55,5},
{56,5},
{58,5},
{61,5},
{62,5},
{65,5},
{68,5},
{70,5},
{71,5},
{72,5},
};
Tc YjpD[]="WriteZimbu.writeClass()";
Tcpos ZcTbl1802[]={
{81,5},
{3,5},
{4,5},
{6,5},
{7,5},
{8,5},
{10,29},
{11,31},
{12,31},
{13,33},
{14,34},
{15,33},
{16,35},
{17,35},
{18,36},
{19,34},
{20,36},
{21,40},
{22,38},
{23,41},
{25,29},
{26,30},
{27,30},
{31,5},
{32,7},
{33,28},
{33,28},
{34,9},
{35,19},
{38,9},
{31,5},
{42,5},
{47,7},
{50,20},
{51,34},
{52,11},
{53,13},
{54,21},
{55,24},
{56,23},
{57,20},
{58,21},
{59,24},
{60,13},
{62,20},
{63,21},
{64,13},
{65,26},
{67,13},
{70,20},
{71,19},
{72,22},
{73,11},
{75,20},
{76,19},
{77,22},
{78,11},
{81,20},
{82,19},
{83,22},
{84,11},
{86,20},
{87,19},
{88,22},
{89,11},
{91,20},
{92,19},
{93,22},
{94,11},
{96,20},
{97,19},
{98,22},
{99,11},
{101,20},
{102,19},
{103,22},
{104,11},
{106,20},
{107,19},
{108,22},
{109,11},
{111,20},
{112,23},
{113,19},
{114,22},
{115,11},
{117,11},
{119,7},
{120,21},
{123,7},
{124,9},
{126,9},
{129,17},
{130,9},
{132,9},
{134,9},
{137,28},
{138,9},
{139,11},
{140,11},
};
Tcpos ZcTbl1803[]={
{224,9},
{3,7},
{6,7},
{7,9},
{-101,5},
{12,5},
{13,5},
{14,7},
{13,5},
{16,5},
{17,7},
{16,5},
{19,5},
{22,5},
{23,5},
{24,5},
{25,7},
{27,20},
{28,7},
{29,9},
{30,13},
{28,7},
{33,5},
{34,5},
{37,5},
{38,7},
{40,5},
{41,7},
{43,5},
{44,7},
{46,5},
{47,7},
{49,5},
{50,7},
{52,5},
{53,7},
{55,5},
{56,7},
{58,5},
{59,7},
{63,5},
{66,5},
{67,7},
{70,5},
{71,7},
{75,5},
{78,5},
{80,5},
{81,5},
{84,5},
{85,5},
{86,5},
{87,5},
{90,5},
{91,5},
{92,5},
{93,5},
{94,5},
{95,5},
{96,5},
{97,5},
{98,5},
{99,5},
{100,5},
{101,5},
{103,5},
{104,5},
{105,5},
{106,5},
{109,5},
{110,5},
{111,5},
{112,5},
{113,5},
{114,5},
{115,5},
{116,5},
{119,5},
{122,5},
{126,5},
{127,5},
{128,5},
{131,5},
{132,7},
{134,7},
{135,16},
{137,16},
{139,7},
{140,7},
{141,7},
{142,9},
{144,9},
{146,7},
{147,7},
{149,7},
{150,7},
{151,7},
{152,9},
{154,9},
{155,9},
};
Tcpos ZcTbl1804[]={
{355,5},
{28,5},
{29,5},
{31,5},
{33,5},
{34,5},
{36,5},
{38,5},
{39,7},
{40,9},
{40,19},
{40,19},
{38,5},
{45,5},
{48,5},
};
Tc YyyW[]="WriteZimbu.writeCopy()";
Tcpos ZcTbl75475[]={
{650,5},
{1,29},
{2,5},
{3,5},
{4,42},
{5,26},
{6,24},
{7,7},
{8,17},
{9,9},
{10,9},
{12,7},
{13,9},
{14,9},
{15,9},
{16,9},
{17,9},
{18,11},
{21,11},
{23,9},
{24,9},
{25,9},
{26,9},
{28,9},
{30,9},
{31,11},
{32,11},
{35,11},
{37,11},
{41,7},
{42,9},
{3,5},
{45,5},
{46,5},
};
Tc YblT[]="WriteZimbu.writeEnum()";
Tcpos ZcTbl45169[]={
{930,5},
{1,5},
{2,5},
{4,7},
{2,5},
{6,5},
{9,5},
{11,5},
{12,5},
{13,7},
{12,5},
{16,5},
{18,5},
{20,5},
{21,7},
{20,5},
{24,5},
};
Tc YVKo[]="WriteZimbu.writeError()";
Tcpos ZcTbl1422[]={
{960,22},
{1,5},
{2,7},
{3,12},
{5,5},
{6,5},
};
Tc YSmP[]="WriteZimbu.writeFieldTable()";
Tcpos ZcTbl49240[]={
{716,5},
{1,5},
{2,7},
{1,5},
{8,5},
};
Tc YMb9[]="WriteZimbu.writeGetSet()";
Tcpos ZcTbl59408[]={
{411,19},
{1,22},
{5,5},
{6,7},
{8,9},
{9,9},
{10,11},
{12,9},
{13,9},
{14,9},
{15,11},
{16,13},
{17,35},
{18,13},
{19,26},
{21,13},
{22,15},
{24,35},
{25,15},
{27,15},
{14,9},
{31,9},
{32,9},
{33,9},
{36,9},
{37,11},
{38,11},
{39,13},
{41,11},
{42,11},
{43,11},
{44,11},
{45,13},
{46,37},
{47,15},
{48,28},
{50,15},
{51,15},
{44,11},
{54,11},
{55,11},
{56,11},
{61,9},
{62,18},
{63,11},
{64,11},
{65,11},
{66,11},
{67,35},
{68,13},
{69,13},
{70,15},
{72,15},
{74,13},
{75,15},
{78,22},
{79,15},
{80,25},
{81,15},
{83,34},
{84,15},
{85,17},
{87,17},
{90,13},
{66,11},
{92,11},
{93,11},
{96,11},
{97,13},
{98,13},
{99,13},
{100,13},
{101,13},
{102,37},
{103,15},
{104,15},
{105,15},
{106,17},
{108,17},
{110,15},
{111,15},
{101,13},
{113,13},
{114,13},
{5,5},
};
Tc Ynau[]="WriteZimbu.writeHasField()";
Tcpos ZcTbl85132[]={
{638,5},
{1,5},
{2,5},
{3,7},
{2,5},
{6,5},
{7,5},
{8,5},
};
Tc YtY8[]="WriteZimbu.writeService()";
Tcpos ZcTbl54137[]={
{886,5},
{2,29},
{3,5},
{5,7},
{7,7},
{12,7},
{13,7},
{14,7},
{16,44},
{17,57},
{18,7},
{19,7},
{21,7},
{22,7},
{24,7},
{25,7},
{26,7},
{28,7},
{31,7},
{32,7},
{37,7},
{3,5},
{39,5},
};
Tc YTVO[]="WriteZimbu.writeSetGetHas()";
Tcpos ZcTbl21476[]={
{731,31},
{1,29},
{2,28},
{5,5},
{7,5},
{9,7},
{11,7},
{13,5},
{14,7},
{16,5},
{17,5},
{20,5},
{21,7},
{22,7},
{23,7},
{24,7},
{28,5},
{30,5},
{31,7},
{33,7},
{35,5},
{36,7},
{37,17},
{38,7},
{39,29},
{40,7},
{41,62},
{42,7},
{44,7},
{46,5},
{48,5},
{49,7},
{51,7},
{53,5},
{56,5},
{57,5},
{58,7},
{60,7},
{62,5},
{65,5},
{67,5},
{68,5},
{69,7},
{71,5},
{72,5},
};
Tc YS9k[]="WriteZimbu.writeSize()";
Tcpos ZcTbl20075[]={
{702,5},
{1,5},
{2,5},
{3,7},
{2,5},
{7,5},
{8,5},
{9,5},
};
Tc Yqom[]="WriteZimbu.writeWriteMerge()";
Tcpos ZcTbl37411[]={
{554,19},
{1,22},
{5,5},
{6,7},
{7,9},
{8,9},
{9,11},
{11,9},
{12,9},
{13,9},
{14,11},
{15,13},
{17,13},
{18,15},
{20,13},
{13,9},
{23,9},
{24,9},
{25,9},
{27,9},
{28,11},
{30,11},
{32,9},
{33,9},
{34,11},
{35,13},
{36,13},
{37,15},
{38,15},
{39,15},
{42,15},
{33,9},
{46,9},
{47,9},
{50,9},
{51,20},
{52,11},
{53,11},
{54,11},
{55,35},
{56,11},
{57,13},
{58,13},
{59,13},
{60,13},
{61,13},
{62,15},
{63,15},
{64,15},
{65,15},
{67,15},
{69,15},
{72,13},
{56,11},
{74,11},
{75,11},
{76,11},
{5,5},
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
Tc YPRm[]="Z.Pos.copy()";
Tcpos ZcTbl16020[]={
{42,11},
{1,15},
{2,14},
{3,13},
{4,14},
{5,14},
};
Tc YzF7[]="Z.Pos.nextLine()";
Tcpos ZcTbl46868[]={
{59,11},
{1,12},
{2,12},
};
Tcode ZcodeTable[]={
{1422,YFTE,YVKo,ZcTbl1422},
{1679,Yxbi,YU0e,ZcTbl1679},
{1755,YFTE,YIr_,ZcTbl1755},
{1802,YFTE,YjpD,ZcTbl1802},
{1803,YFTE,YjpD,ZcTbl1803},
{1804,YFTE,YjpD,ZcTbl1804},
{1872,Yay0,YNFk,ZcTbl1872},
{2571,Y7gD,YAt2,ZcTbl2571},
{3273,YCG4,Y_VO,ZcTbl3273},
{3531,Y_R2,Y5m_,ZcTbl3531},
{5070,YnGo,Ypaua,ZcTbl5070},
{5270,YLrK,Y9QD,ZcTbl5270},
{5342,YyXk,YQE_,ZcTbl5342},
{6262,YnGo,YKht,ZcTbl6262},
{7452,Yay0,Ys1a,ZcTbl7452},
{8550,YnGo,YJA9,ZcTbl8550},
{10800,YFTE,YnO0,ZcTbl10800},
{12726,YnGo,YPIw,ZcTbl12726},
{15153,Y76z,YwYU,ZcTbl15153},
{15718,Yt1T,YEFs,ZcTbl15718},
{15755,Yay0,YEgn,ZcTbl15755},
{16020,Y3zM,YPRm,ZcTbl16020},
{16053,Yay0,Y5P_,ZcTbl16053},
{16350,YCG4,Ygzb,ZcTbl16350},
{18187,Y3zM,Ym1t,ZcTbl18187},
{19772,Y7gD,YHJi,ZcTbl19772},
{19804,YEew,YnnL,ZcTbl19804},
{19887,YPyp,YHM2,ZcTbl19887},
{20075,YFTE,YS9k,ZcTbl20075},
{20933,YEew,YKZm,ZcTbl20933},
{21378,YxHL,YjAA,ZcTbl21378},
{21476,YFTE,YTVO,ZcTbl21476},
{24269,YFTE,Y8JY,ZcTbl24269},
{25860,YxHL,YFAP,ZcTbl25860},
{26760,Yay0,YYk7,ZcTbl26760},
{29560,YCG4,YzK9,ZcTbl29560},
{29585,Yt1T,YAVe,ZcTbl29585},
{32086,Yt1T,Y1As,ZcTbl32086},
{32939,YyXk,Y0DO,ZcTbl32939},
{34047,YPyp,Yq05,ZcTbl34047},
{34818,YyXk,YHWY,ZcTbl34818},
{35249,YEew,Y7nB,ZcTbl35249},
{35721,Y_R2,YjO7,ZcTbl35721},
{35761,YnGo,Y0Ij,ZcTbl35761},
{36283,Y7gD,YBp9,ZcTbl36283},
{36381,YGYp,YLSX,ZcTbl36381},
{36491,Yt1T,YYT9,ZcTbl36491},
{37411,YFTE,Yqom,ZcTbl37411},
{38811,Y_R2,YcQA,ZcTbl38811},
{38911,YCG4,YM2k,ZcTbl38911},
{39213,Yxbi,YFwg,ZcTbl39213},
{39906,Yxbi,YA9q,ZcTbl39906},
{40190,Yeop,YLFA,ZcTbl40190},
{41999,Y1IY,Yit2,ZcTbl41999},
{42310,Y76z,YfqK,ZcTbl42310},
{43000,YCG4,YEFE,ZcTbl43000},
{44260,YFTE,Yehha,ZcTbl44260},
{44318,YEew,Yu_S,ZcTbl44318},
{44401,YPyp,YOoa,ZcTbl44401},
{44960,YEew,YWz4,ZcTbl44960},
{45169,YFTE,YblT,ZcTbl45169},
{45209,Yt1T,Y2NH,ZcTbl45209},
{46631,Yay0,YHCY,ZcTbl46631},
{46761,Yay0,YN2v,ZcTbl46761},
{46868,Y3zM,YzF7,ZcTbl46868},
{47139,Y76z,YI4R,ZcTbl47139},
{48299,Yt1T,Y9Cv,ZcTbl48299},
{49183,Yt1T,YgcH,ZcTbl49183},
{49240,YFTE,YSmP,ZcTbl49240},
{49285,Yay0,Y1Ue,ZcTbl49285},
{50024,Y1IY,YPvQ,ZcTbl50024},
{50421,Y1IY,YWUU,ZcTbl50421},
{50614,Yv00,YPS1,ZcTbl50614},
{50841,YyXk,YLwM,ZcTbl50841},
{51410,YnGo,YCVw,ZcTbl51410},
{52269,YnGo,YdOc,ZcTbl52269},
{52386,Yt1T,YgcM,ZcTbl52386},
{53377,Yt1T,Yp81,ZcTbl53377},
{54137,YFTE,YtY8,ZcTbl54137},
{55944,YGYp,YM1j,ZcTbl55944},
{56381,Yt1T,Y99g,ZcTbl56381},
{56555,Y76z,YFIR,ZcTbl56555},
{57273,YjxU,YViu,ZcTbl57273},
{58121,Yeop,YmDz,ZcTbl58121},
{58975,Yay0,YSa1,ZcTbl58975},
{59312,Yay0,YdDi,ZcTbl59312},
{59408,YFTE,YMb9,ZcTbl59408},
{60567,Yay0,YskO,ZcTbl60567},
{60593,Yt1T,Y5LR,ZcTbl60593},
{60791,Y7gD,YIwZ,ZcTbl60791},
{61284,YCG4,Y2cg,ZcTbl61284},
{63024,Y1IY,YKPD,ZcTbl63024},
{63578,Yt1T,Yuz_,ZcTbl63578},
{63594,Yv00,Y7DX,ZcTbl63594},
{64478,YCG4,YRbs,ZcTbl64478},
{64531,Yay0,YrJP,ZcTbl64531},
{66188,Yay0,YJ7z,ZcTbl66188},
{66335,YGYp,YYJc,ZcTbl66335},
{66501,YCG4,YPPv,ZcTbl66501},
{66510,YnGo,YQ3a,ZcTbl66510},
{71573,YnGo,YDsz,ZcTbl71573},
{71979,YxHL,YiL5,ZcTbl71979},
{72007,Yay0,YzQB,ZcTbl72007},
{73471,Yt1T,Y_Qs,ZcTbl73471},
{73580,Yt1T,YF6S,ZcTbl73580},
{75475,YFTE,YyyW,ZcTbl75475},
{75697,YCG4,YgDO,ZcTbl75697},
{76461,YxHL,YELk,ZcTbl76461},
{76644,YCG4,YImf,ZcTbl76644},
{78082,Yt1T,YbzA,ZcTbl78082},
{80644,Yt1T,YobA,ZcTbl80644},
{81580,Yay0,Y5X7,ZcTbl81580},
{81798,YCG4,YMnk,ZcTbl81798},
{82533,YCG4,Yh2v,ZcTbl82533},
{82534,YCG4,Yh2v,ZcTbl82534},
{82618,Yay0,Yxlj,ZcTbl82618},
{83326,Y76z,YVvh,ZcTbl83326},
{84870,Yay0,Y_pS,ZcTbl84870},
{84899,Y76z,Y8w5,ZcTbl84899},
{85000,Yt1T,Ycb9,ZcTbl85000},
{85132,YFTE,Ynau,ZcTbl85132},
{85295,YCG4,Yza4,ZcTbl85295},
{86206,YCG4,YZNA,ZcTbl86206},
{87235,Yt1T,YR5m,ZcTbl87235},
{89012,YxHL,YYkI,ZcTbl89012},
{89141,Yeop,YTU3,ZcTbl89141},
{89987,Yay0,YCbR,ZcTbl89987},
{90183,Y7gD,Y5D2,ZcTbl90183},
{92163,Yt1T,YTjU,ZcTbl92163},
{94525,YnGo,YgZJ,ZcTbl94525},
{94823,Yay0,Yj_J,ZcTbl94823},
{95201,Yt1T,YhC6,ZcTbl95201},
{99713,YxHL,YzJ7,ZcTbl99713},
{99838,Yay0,YTE3,ZcTbl99838},
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

/* concat string */
Tc *ZcS12(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5, Tc *s6, Tc *s7, Tc *s8, Tc *s9, Tc *s10, Tc *s11, Tc *s12) {
 Tc *p[12];
 Ti len[12];
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
 if (s7 == NULL) {len[6] = 3; p[6] = (Tc*)"NIL";}
 else len[6] = ZstringSizePtr(s7, &p[6]);
 if (s8 == NULL) {len[7] = 3; p[7] = (Tc*)"NIL";}
 else len[7] = ZstringSizePtr(s8, &p[7]);
 if (s9 == NULL) {len[8] = 3; p[8] = (Tc*)"NIL";}
 else len[8] = ZstringSizePtr(s9, &p[8]);
 if (s10 == (Tc*)1) len[9] = 0;
 else if (s10 == NULL) {len[9] = 3; p[9] = (Tc*)"NIL";}
 else len[9] = ZstringSizePtr(s10, &p[9]);
 if (s11 == (Tc*)1) len[10] = 0;
 else if (s11 == NULL) {len[10] = 3; p[10] = (Tc*)"NIL";}
 else len[10] = ZstringSizePtr(s11, &p[10]);
 if (s12 == (Tc*)1) len[11] = 0;
 else if (s12 == NULL) {len[11] = 3; p[11] = (Tc*)"NIL";}
 else len[11] = ZstringSizePtr(s12, &p[11]);
 for (i = 0; i < 12; ++i) totlen += len[i];
 r = ZnewStringInit(totlen, &pp);
 totlen = 0;
 for (i = 0; i < 12; ++i) {
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

Tc *Zbool2string(Tb n) {
 return Zstr(n == 0 ? "FALSE" : "TRUE");
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

Tc *ZstringToUpperAscii(Tc *ss) {
 Tc *r;
 Tc *d;
 Tc *s;
 Ti len;
 if (ss == NULL) return NULL;
 len = ZstringSizePtr(ss, &s);
 r = ZnewString(s, len);
 d = r + (s - (Tc*)ss);
 while (*s != 0)
  *d++ = toupper(*s++);
 *d = 0;
 return (Tc*)r;
}

Tc *ZstringToUpper(Tc *ss) {
 Tc *r;
 Tc *d;
 Tc *s;
 Ti len;
 if (ss == NULL) return NULL;
 len = ZstringSizePtr(ss, &s);
 r = ZnewString(s, len);
 d = r + (s - (Tc*)ss);
 while (*s != 0) {
  int c = *s++;
  if (c <= 0x7f) {
   *d++ = toupper(c);
  } else if (c == 0xc3) {
   *d++ = c;
   *d++ = *s++ & 0xdf;
  } else {
   for(;;) {
    *d++ = c;
    if ((c & 0x80) == 0) break;
    c = *s++;
   }
  }
 }
 *d = 0;
 return (Tc*)r;
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

void *ZarrayPtr(Ta *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("using [] on NIL array");
 if (idx < 0 || idx >= head->size[0]) ZthrowCstringOutOfRange(idx, "array index out of range");
 return head->ptr + idx * head->itemSize;
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

int ZforListIobjCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(Tr*)tfl->valp = ((Tr*)l->items)[i + l->empty];
 ++tfl->i;
 return 1;
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

Ti ZDictGetIntDef(Td *d, Tz key, Ti def) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) return di->item.ival;
 return def;
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
/* including TIMEModule bodies */
Ti Y9Rj() { /* MTIMEModule.current */
 Ti Vusec;
 Zsf sf={0,topFrame};
 Ti r = 0;
 topFrame = &sf;
 Vusec = 0;
 sf.pos=5084100;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    Vusec = (Ti)tv.tv_sec * 1000000LL + (Ti)(Ti)tv.tv_usec;
 sf.pos=5084101;
 r = Vusec;
 topFrame = sf.prev;
 return r;
}
Y2KX *YgaY(Y2KX *t) { /* MTIMEModule__CValues.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=534200; t = Za(sizeof(Y2KX));}
 sf.pos=534201;
 YgaYb(t, Y9Rj());
 topFrame = sf.prev;
 return t;
}
Y2KX *YgaYb(Y2KX *t, Ti Ausec) { /* MTIMEModule__CValues.NEW */
 Zsf sf={0,topFrame};
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
Tc *YYTs(Y2KX *t) { /* MTIMEModule__CValues.ToString */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 YjUM *Vw = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3481800;
  ZthrowThisNil();
 }
 sf.pos=3481801;
 Vw = Zamt(sizeof(YjUM), YjUM__mt);
 sf.pos=3481802;
 YjUM__YHhZb((YjUM *)Vw, t->Vyear);
 sf.pos=3481803;
 YJqza((YjUM *)Vw, ((Tc*)&YV));
 sf.pos=3481804;
 YJqza((YjUM *)Vw, ZintFormat(((Tc*)&Y6O7), t->Vmonth));
 sf.pos=3481805;
 YJqza((YjUM *)Vw, ((Tc*)&YV));
 sf.pos=3481806;
 YJqza((YjUM *)Vw, ZintFormat(((Tc*)&Y6O7), t->Vday));
 sf.pos=3481807;
 YJqza((YjUM *)Vw, ((Tc*)&YG));
 sf.pos=3481808;
 YJqza((YjUM *)Vw, ZintFormat(((Tc*)&Y6O7), t->Vhour));
 sf.pos=3481809;
 YJqza((YjUM *)Vw, ((Tc*)&Y5));
 sf.pos=3481810;
 YJqza((YjUM *)Vw, ZintFormat(((Tc*)&Y6O7), t->Vmin));
 sf.pos=3481811;
 YJqza((YjUM *)Vw, ((Tc*)&Y5));
 sf.pos=3481812;
 YJqza((YjUM *)Vw, ZintFormat(((Tc*)&Y6O7), t->Vsec));
 sf.pos=3481813;
 r = YbNW((YjUM *)Vw);
 topFrame = sf.prev;
 return r;
}
To ToY2KX[] = {
 {0, 0},
};
Tto Y2KX__T = {390, (Tc*)&YeCO, 0, ToY2KX};
/* TIMEModule done */
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
YX0i *YX0i__Yalz__YwtA__YRHRa(YX0i *t, YkxB *Apos, Tc *Amsg) { /* MEModule__CKeyExists.NEW__p3 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=9520100; t = Zamt(sizeof(YX0i), YX0i__mt);}
 sf.pos=9520101;
 t->Vmessage = Amsg;
 sf.pos=9520102;
 t->Vpos = Apos;
 sf.pos=9520103;
 t->Vbacktrace = (sf.pos=9520104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
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
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg) { /* MEModule__CIllegalByte.NEW__p3 */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=4520900; t = Zamt(sizeof(YP_P), YP_P__mt);}
 sf.pos=4520901;
 t->Vmessage = Amsg;
 sf.pos=4520902;
 t->Vpos = MZ__callerPos();
 sf.pos=4520903;
 t->Vbacktrace = (sf.pos=4520904, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YP_P__mt[] = {
 (Tc*)&YP_P__T,
 (Tc*)15,
 (Tc*)0, /* Vmessage */
 (Tc*)0, /* Vpos */
 (Tc*)0, /* Vbacktrace */
 (Tc*)0, /* MEModule__CIllegalByte.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CIllegalByte.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CIllegalByte.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CIllegalByte.toString - Yoww */
 (Tc*)0, /* MEModule__CIllegalByte.getMessage - YCzX */
 (Tc*)0, /* MEModule__CIllegalByte.getPos - YvCK */
 (Tc*)0, /* MEModule__CIllegalByte.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YP_Pa */
 (Tc*)0, /* MEModule__CIllegalByte.ToString - YH0V */
 (Tc*)0, /* MEModule__CIllegalByte.toString - Yoww */
 (Tc*)0, /* MEModule__CIllegalByte.getMessage - YCzX */
 (Tc*)0, /* MEModule__CIllegalByte.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YP_Pa */
 (Tc*)YxaJ, /* MEModule__CIllegalByte.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CIllegalByte.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CIllegalByte.getPos - YvCK */
 (Tc*)0, /* MEModule__CIllegalByte.ToString - YH0V */
 (Tc*)0, /* MEModule__CIllegalByte.toString - Yoww */
 (Tc*)0, /* MEModule__CIllegalByte.getMessage - YCzX */
 (Tc*)0, /* MEModule__CIllegalByte.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YP_Pa */
 (Tc*)YxaJa, /* MEModule__CIllegalByte.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CIllegalByte.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CIllegalByte.getPos - YvCK */
 (Tc*)0, /* MEModule__CIllegalByte.ToString - YH0V */
 (Tc*)0, /* MEModule__CIllegalByte.toString - Yoww */
 (Tc*)0, /* MEModule__CIllegalByte.getMessage - YCzX */
 (Tc*)0, /* MEModule__CIllegalByte.getBacktrace - Y4bq */
 (Tc*)0, /* Init - YP_Pa */
 (Tc*)YxaJ, /* MEModule__CIllegalByte.writeTo - YxaJ */
 (Tc*)YxaJa, /* MEModule__CIllegalByte.writeTo - YxaJa */
 (Tc*)0, /* MEModule__CIllegalByte.getPos - YvCK */
};
To ToYP_P[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YP_P__T = {390, (Tc*)&Ydbm, 0, ToYP_P};
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
/* including ZModule bodies */
YkxB *Ypp_(YkxB *t, Tc *Afilename) { /* MZModule__CPos.NEW */
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = 1;
 t->Vcol = 1;
 return t;
}
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) { /* MZModule__CPos.NEW */
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 return t;
}
YkxB *Y83A(YkxB *t) { /* MZModule__CPos.copy */
 Zsf sf={0,topFrame};
 YkxB *r = 0;
 YkxB *Vp = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1602000;
  ZthrowThisNil();
 }
 sf.pos=1602001;
 Vp = Ypp_(NULL, t->Vfilename);
 sf.pos=1602002;
 Vp->Vlnum = t->Vlnum;
 sf.pos=1602003;
 Vp->Vcol = t->Vcol;
 sf.pos=1602004;
 Vp->Vtext = t->Vtext;
 sf.pos=1602005;
 r = Vp;
 topFrame = sf.prev;
 return r;
}
void YnS4(YkxB *t) { /* MZModule__CPos.nextLine */
 Zsf sf={0,topFrame};
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
Ti YFeQ(Yw8L *t) { /* MIOModule__CFile.readByte */
 Ti Vb;
 Zsf sf={0,topFrame};
 Ti r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1605300;
  ZthrowThisNil();
 }
 sf.pos=1605301;
 if ((t->Vfd == NULL))
 {
  Ytlm *ex;
  sf.pos=1605302;
  ex = (Ytlm*)YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8));
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
Ti YAPp(Yw8L *t) { /* MIOModule__CFile.readChar */
 Ti Vc;
 Zsf sf={0,topFrame};
 Ti r = 0;
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
   Ytlm *ex;
   sf.pos=4663112;
   ex = (Ytlm*)YP_P__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&YPHa), Zint2string(Vc)));
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
    Ytlm *ex;
    sf.pos=4663116;
    ex = (Ytlm*)YP_P__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&YKzT), Zint2string(Vnr)));
    ZthrowIobject(ex);
   }
   else {
   sf.pos=4663117;
   if ((((Vc2 & 192)) != 128))
   {
    Ytlm *ex;
    sf.pos=4663118;
    ex = (Ytlm*)YP_P__Yalz__YwtA__YRHR(NULL, ZcS3(((Tc*)&Ymwv), Zint2string(Vnr), ((Tc*)&YPfW)));
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
     Ytlm *ex;
     sf.pos=4663123;
     ex = (Ytlm*)YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn));
     ZthrowIobject(ex);
    }
     break;
   }
   case 3:
   {
    sf.pos=4663124;
    if ((Vc <= 2047))
    {
     Ytlm *ex;
     sf.pos=4663125;
     ex = (Ytlm*)YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn));
     ZthrowIobject(ex);
    }
     break;
   }
   case 4:
   {
    sf.pos=4663126;
    if ((Vc <= 65535))
    {
     Ytlm *ex;
     sf.pos=4663127;
     ex = (Ytlm*)YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn));
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
Ts YGmp(Yw8L *t) { /* MIOModule__CFile.flush */
 Ts Vret;
 Zsf sf={0,topFrame};
 Ts r = 0;
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
Ts YrF8(Yw8L *t) { /* MIOModule__CFile.close */
 Ts Vret;
 Zsf sf={0,topFrame};
 Ts r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1575500;
  ZthrowThisNil();
 }
 sf.pos=1575501;
 Vret = 0;
 sf.pos=1575502;
 if ((t->Vfd != NULL))
 {
  sf.pos=1575503;
 if (fflush(t->Vfd) != 0) Vret = 0;
  sf.pos=1575504;
 if (fclose(t->Vfd) != 0) Vret = 0;
  sf.pos=1575505;
  t->Vfd = NULL;
 }
 sf.pos=1575506;
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
 (Tc*)YrF8, /* MIOModule__CFile.close - YrF8 */
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
Yw8L *YsGz(Tc *AfileName) { /* MIOModule.fileReader */
 Zsf sf={0,topFrame};
 Yw8L *r = 0;
 Yw8L *Vfile = NULL;
 topFrame = &sf;
 sf.pos=9983800;
 {
  int fnr = open(ZgetCstring(AfileName), O_RDONLY);
  if (fnr >= 0) {
 sf.pos=9983801;
 Vfile = (Yw8L*)Zamt(sizeof(Yw8L), Yw8L__mt);
 sf.pos=9983802;
   (*(FILE **)((Tc*)Vfile + (size_t)Vfile->mt[41])) = fdopen(fnr, "r");
  }
 }
 sf.pos=9983803;
 r = Vfile;
 topFrame = sf.prev;
 return r;
}
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
Tb Yqej(YjUM *t) { /* MIOModule__CStringWriter.empty */
 Zsf sf={0,topFrame};
 Tb r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5931200;
  ZthrowThisNil();
 }
 sf.pos=5931201;
 r = (t->VsLen == 0);
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
Ti Y6jW(YjUM *t) { /* MIOModule__CStringWriter.remove */
 Ti Vc;
 Zsf sf={0,topFrame};
 Ti r = 0;
 int rt = 0;
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
Ts YjUM__YRt7(YjUM *t, Tc *Atext) { /* MIOModule__CStringWriter.print__p1 */
 Zsf sf={0,topFrame};
 Ts r = 0;
 int rt = 0;
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
 (Tc*)YjUM__YRt7, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
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
 (Tc*)YjUM__YRt7, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
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
 (Tc*)Yqej, /* MIOModule__CStringWriter.empty - Yqej */
 (Tc*)YbNW, /* MIOModule__CStringWriter.ToString - YbNW */
 (Tc*)Y6jW, /* MIOModule__CStringWriter.remove - Y6jW */
 (Tc*)0, /* MIOModule__CStringWriter.clear - YXip */
 (Tc*)0, /* MIOModule__CStringWriter.truncate - Y3_a */
 (Tc*)0, /* Init - YjUMa */
};
Tc *YjUM__YdXi_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)YjUM__YRt7, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
};
To ToYjUM[] = {
 {1, 0},
 {0, (Tt*)&array__T}, /* s */
};
Tto YjUM__T = {390, (Tc*)&YE4c, 0, ToYjUM};
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
void YDli(Tc *Amsg, YkxB *Apos, Tbs Aflags) { /* MLOGModule.error */
 Ygkj(5, Amsg, Apos, Aflags);
 return;
}
void Y2oO(Tc *Amsg, YkxB *Apos, Tbs Aflags) { /* MLOGModule.internal */
 Ygkj(5, Amsg, Apos, (Aflags + 2));
 return;
}
Tb Yf55() { /* MLOGModule.isInfoLog */
 Zsf sf={0,topFrame};
 Tb r = 0;
 topFrame = &sf;
 sf.pos=4713900;
 r = (Y86c__Ye9f((Y86c *)YlUb) >= 1);
 topFrame = sf.prev;
 return r;
}
Tb Y0Ft() { /* MLOGModule.isVerboseLog */
 Zsf sf={0,topFrame};
 Tb r = 0;
 topFrame = &sf;
 sf.pos=1515300;
 r = (Y86c__Ye9f((Y86c *)YlUb) >= 2);
 topFrame = sf.prev;
 return r;
}
Tb YOvp() { /* MLOGModule.isDebugLog */
 Zsf sf={0,topFrame};
 Tb r = 0;
 topFrame = &sf;
 sf.pos=4231000;
 r = YuOS((Y86c *)YU8T);
 topFrame = sf.prev;
 return r;
}
void Ygkj(Te Alevel, Tc *Amsg, YkxB *Apos, Tbs Aflags) { /* MLOGModule.log */
 YjUM *Vw = 0;
 Tc *VwholeMsg = NULL;
 Y2KX *Vtv = 0;
 Tr t0 = {NULL,0,-1};
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 int rt = 0;
 if ((((((Alevel == 0) && !(YOvp()))) || (((Alevel == 1) && !(Y0Ft())))) || (((Alevel == 2) && !(Yf55())))))
 {
  rt = 1;
  goto YbRZ;
 }
 *ZDictGetIntP(Ytd2, (Tz)(Ti)Alevel) = (ZDictGetInt(Ytd2, (Tz)(Ti)Alevel) + 1);
 Vw = Zamt(sizeof(YjUM), YjUM__mt);
 if ((Apos != NULL))
 {
  YJqza((YjUM *)Vw, YpI_((YkxB *)Apos));
  YJqza((YjUM *)Vw, ((Tc*)&YFDa));
 }
 if ((((Aflags) & 2) >> 1))
 {
  YJqza((YjUM *)Vw, ((Tc*)&YJ5p));
 }
 switch (Alevel)
 {
  case 4:
  {
   YJqza((YjUM *)Vw, ((Tc*)&Yyq1));
    break;
  }
  case 5:
  {
   YJqza((YjUM *)Vw, ((Tc*)&Y27a));
    break;
  }
  case 6:
  {
   YJqza((YjUM *)Vw, ((Tc*)&Y3l3));
    break;
  }
  case 7:
  {
   YJqza((YjUM *)Vw, ((Tc*)&YmM8));
    break;
  }
 }
 YJqza((YjUM *)Vw, YmaW);
 YJqza((YjUM *)Vw, Amsg);
 if ((((Aflags) & 1)))
 {
  YwlF(*Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 }
 if (!((((Aflags) & 4) >> 2)))
 {
  YJqza((YjUM *)Vw, ((Tc*)&Yk));
 }
 VwholeMsg = YbNW((YjUM *)Vw);
 Yvcu(VwholeMsg);
 if ((Yz2b != (void *)NULL))
 {
  if (YiAD)
  {
   Vtv = YgaY(NULL);
   YwHoa((Yw8L *)Yz2b, ZcS5((Vtv == NULL ? NULL : YYTs((Y2KX *)Vtv)), ((Tc*)&YU), (t1 = ZintFormat(((Tc*)&YwV7), Vtv->Vusec)), ((Tc*)&YG), (Tc*)1));
  }
  YwHoa((Yw8L *)Yz2b, VwholeMsg);
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
void YwlF(Tr Aout) { /* MLOGModule.reportStack */
 Tb VdidFirst;
 Zsf sf={0,topFrame};
 Tl *Zf1 = NULL;
 YkxB *Vp = 0;
 Tc *t0 = NULL;
 topFrame = &sf;
 sf.pos=8489900;
 ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ((Tc*)&YDzC));
 VdidFirst = 0;
 sf.pos=8489902;
 {
  Tfl Zf1i;
  Zf1 = (sf.pos=8489903, MZ__backtrace(0, -1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vp;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8489904;
  if (VdidFirst)
  {
   sf.pos=8489905;
   ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ZcS3(YpI_((YkxB *)Vp), ((Tc*)&YFDa), (t0 = Vp->Vtext)));
  }
  else
  {
   sf.pos=8489906;
   VdidFirst = 1;
  }
  sf.pos=8489907;
  }
 }
 topFrame = sf.prev;
 return;
}
void Y7LJ() { /* MLOGModule.flush */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 sf.pos=5655500;
 Ylxt();
 sf.pos=5655501;
 if ((Yz2b != (void *)NULL))
 {
  sf.pos=5655502;
  YGmp((Yw8L *)Yz2b);
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
  Zsf sf={0,topFrame};
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
Yhqr *Ypau(Yhqr *t) { /* MSETModule__CSet__t1.Init */
 Zsf sf={0,topFrame};
 if (t == NULL) {t = Za(sizeof(Yhqr));}
 topFrame = &sf;
 sf.pos=8901200;
 t->Vdict = ZnewDict((Tt*)&int__T, (Tt*)&bool__T, 0);
 topFrame = sf.prev;
 return t;
}
Yhqr *Yh95(Yhqr *t) { /* MSETModule__CSet__t1.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=2137800; t = Ypau(NULL);}
 topFrame = sf.prev;
 return t;
}
Tb YyHa(Yhqr *t, Ti Akey) { /* MSETModule__CSet__t1.has */
 Zsf sf={0,topFrame};
 Tb r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=2586000;
 if (t == NULL)
 {
  sf.pos=2586001;
  r = 0;
  rt = 1;
  goto Y2Rd;
 }
 sf.pos=2586002;
 r = ZDictHas(t->Vdict, (Tz)(Ti)Akey);
Y2Rd:
 topFrame = sf.prev;
 return r;
}
Yhqr *YGMT(Yhqr *t, Ti Akey) { /* MSETModule__CSet__t1.add */
 Yhqr *r = 0;
 YkxB *t0 = 0;
 Tc *t1 = NULL;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (ZDictHas(t->Vdict, (Tz)(Ti)Akey))
 {
  Ytlm *ex;
  ex = (Ytlm*)YX0i__Yalz__YwtA__YRHRa(NULL, (t0 = MZ__callerPos()), (t1 = ZcS(((Tc*)&YLLX), Zint2string(Akey))));
  ZthrowIobject(ex);
 }
 ZDictAdd(0, t->Vdict, (Tz)(Ti)Akey, (Tz)(Ti)1);
 r = t;
 return r;
}
To ToYhqr[] = {
 {1, 0},
 {0, (Tt*)&dict__T}, /* dict */
};
Tto Yhqr__T = {390, (Tc*)&Yehz, 0, ToYhqr};
Ygqr *YuFZ(Ygqr *t) { /* MSETModule__CSet__t2.Init */
 Zsf sf={0,topFrame};
 if (t == NULL) {t = Za(sizeof(Ygqr));}
 topFrame = &sf;
 sf.pos=9971300;
 t->Vdict = ZnewDict((Tt*)&string__T, (Tt*)&bool__T, 0);
 topFrame = sf.prev;
 return t;
}
Ygqr *YGrg(Ygqr *t) { /* MSETModule__CSet__t2.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=7197900; t = YuFZ(NULL);}
 topFrame = sf.prev;
 return t;
}
Tb YXZk(Ygqr *t, Tc *Akey) { /* MSETModule__CSet__t2.has */
 Zsf sf={0,topFrame};
 Tb r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=7646100;
 if (t == NULL)
 {
  sf.pos=7646101;
  r = 0;
  rt = 1;
  goto YzXL;
 }
 sf.pos=7646102;
 r = ZDictHas(t->Vdict, (Tz)(void*)Akey);
YzXL:
 topFrame = sf.prev;
 return r;
}
Ygqr *Y432(Ygqr *t, Tc *Akey) { /* MSETModule__CSet__t2.add */
 Ygqr *r = 0;
 YkxB *t0 = 0;
 Tc *t1 = NULL;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (ZDictHas(t->Vdict, (Tz)(void*)Akey))
 {
  Ytlm *ex;
  ex = (Ytlm*)YX0i__Yalz__YwtA__YRHRa(NULL, (t0 = MZ__callerPos()), (t1 = ZcS(((Tc*)&YLLX), Akey)));
  ZthrowIobject(ex);
 }
 ZDictAdd(0, t->Vdict, (Tz)(void*)Akey, (Tz)(Ti)1);
 r = t;
 return r;
}
To ToYgqr[] = {
 {1, 0},
 {0, (Tt*)&dict__T}, /* dict */
};
Tto Ygqr__T = {390, (Tc*)&Yfhz, 0, ToYgqr};
/* SETModule done */
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
Ti Yd2Z() { /* MARGModule.Size */
 Ti r = 0;
 YY8i();
 r = ZListSize(Y6fX);
 return r;
}
Tc *YtgL(Ti Aindex) { /* MARGModule.get */
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
Tto YnU5__T = {390, (Tc*)&Yr32, 0, ToYnU5};
void YY8i() { /* MARGModule.initCheck */
 if ((Y6fX == NULL))
 {
  Ytlm *ex;
  ex = (Ytlm*)YVNj__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YeBP));
  ZthrowIobject(ex);
 }
 return;
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
Tb YHoR(Y86c *t) { /* MARGModule__CBool.get */
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->Vcurrent;
 return r;
}
Tb YuOS(Y86c *t) { /* MARGModule__CBool.value */
 Zsf sf={0,topFrame};
 Tb r = 0;
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
 void *p1;
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
 VonePos = ((p1 = ((Y_CE = (*(YkxB**)((Tc*)Aflag + (size_t)Aflag->mt[10])), Y_CE == NULL ? NULL : YpI_((YkxB *)Y_CE)))) == NULL ? (((Tc*)&YbbH)) : p1);
 sf.pos=7569702;
 Ve = YVNj__YwtA__YRHRa(NULL, Apos, ZcS5(((Tc*)&YtzG), Aname, ((Tc*)&YDyy), VonePos, (Tc*)1));
 sf.pos=7569703;
 ex = (Ytlm*)Ve;
 ZthrowIobject(ex);
}
Ti Y86c__Ye9f(Y86c *t) { /* MARGModule__CBool.presentCount__p1 */
 Ti r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->VsetCount;
 return r;
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
 (Tc*)Y86c__Ye9f, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
 (Tc*)0, /* MARGModule__CBool.present - Y86c__Y8Dq */
 (Tc*)YEqoa, /* MARGModule__CBool.setToDefault - YEqoa */
 (Tc*)0, /* Init - Y86ca */
 (Tc*)Y86c__YofP, /* MARGModule__CBool.throwDuplicate - Y86c__YofP */
 (Tc*)0, /* MARGModule__CBool.setArgName - Y86c__Y836 */
 (Tc*)0, /* MARGModule__CBool.disableCompact - Y86c__YJbb */
 (Tc*)0, /* MARGModule__CBool.optionalArg - Y86c__YxuH */
 (Tc*)Y86c__Ye9f, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
 (Tc*)0, /* MARGModule__CBool.present - Y86c__Y8Dq */
 (Tc*)0, /* Vcurrent */
 (Tc*)0, /* Vdefault */
 (Tc*)YEqoa, /* MARGModule__CBool.setToDefault - YEqoa */
 (Tc*)0, /* MARGModule__CBool.disableRepeat - YOxU */
 (Tc*)YHoR, /* MARGModule__CBool.get - YHoR */
 (Tc*)YuOS, /* MARGModule__CBool.value - YuOS */
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
/* including ParseProto bodies */
/* including EnumItem bodies */
Y2Kp *YIur(Y2Kp *t) { /* CEnumItem.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=5812100; t = Za(sizeof(Y2Kp));}
 sf.pos=5812101;
 t->Vmembers = ZnewList((Tt*)&YFk1__T, 0);
 topFrame = sf.prev;
 return t;
}
void Y_Nc(Y2Kp *t, Tc *Aname, Ti Anr, YkxB *Apos) { /* CEnumItem.addValue */
 Zsf sf={0,topFrame};
 YFk1 *Vv = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8914100;
  ZthrowThisNil();
 }
 sf.pos=8914101;
 Vv = Za(sizeof(YFk1));
 sf.pos=8914102;
 Vv->Vid = Aname;
 sf.pos=8914103;
 Vv->Vnr = Anr;
 sf.pos=8914104;
 Vv->Vpos = Apos;
 sf.pos=8914105;
 ZLap((Tl*)t->Vmembers, (Tz)(void*)Vv);
 topFrame = sf.prev;
 return;
}
To ToYFk1[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* id */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YFk1__T = {390, (Tc*)&YmNk, 0, ToYFk1};
Ts YXXO(Y2Kp *t) { /* CEnumItem.checkErrors */
 Ts Vret;
 Zsf sf={0,topFrame};
 Ts r = 0;
 Tl *Zf1 = NULL;
 Yhqr *Vused = 0;
 YFk1 *Vm = 0;
 YkxB *t0 = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4019000;
  ZthrowThisNil();
 }
 sf.pos=4019001;
 Vused = Yh95(NULL);
 sf.pos=4019002;
 Vret = 1;
 sf.pos=4019003;
 {
  Tfl Zf1i;
  Zf1 = t->Vmembers;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vm;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=4019004;
  if (YyHa((Yhqr *)Vused, Vm->Vnr))
  {
   sf.pos=4019005;
   YDli(ZcS(((Tc*)&Y_xt), Zint2string(Vm->Vnr)), (t0 = Vm->Vpos), 0);
   sf.pos=4019006;
   Vret = 0;
  }
  else
  {
   sf.pos=4019007;
   YGMT((Yhqr *)Vused, Vm->Vnr);
  }
  sf.pos=4019008;
  }
 }
 sf.pos=4019009;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tc *Y2Kp__YuXI_imt[] = {
 (Tc*)&Y2Kp__T,
 (Tc*)0, /* Vname */
};
To ToY2Kp[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* members */
};
Tto Y2Kp__T = {390, (Tc*)&Ym3J, 0, ToY2Kp};
/* EnumItem done */
/* including MessageItem bodies */
/* including FieldItem bodies */
Tc *YULH(Y0uC *t) { /* CFieldItem.memberName */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3628300;
  ZthrowThisNil();
 }
 sf.pos=3628301;
 r = ZcS(((Tc*)&YliF), t->Vname);
 topFrame = sf.prev;
 return r;
}
Tc *YFlx(Y0uC *t) { /* CFieldItem.hasMemberName */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 int rt = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6079100;
  ZthrowThisNil();
 }
 sf.pos=6079101;
 if (!(t->Vrepeated))
 {
  sf.pos=6079102;
  switch (t->Vtype)
  {
   case 9:
   case 10:
   case 18:
   case 11:
   case 19:
   case 6:
   case 7:
   {
    sf.pos=6079103;
    r = ZcS(((Tc*)&YZYy), t->Vname);
    rt = 1;
    goto YCIv;
   }
YCIv:
   if (rt) goto YTdB;
  }
YTdB:
  if (rt) goto YrvEa;
 }
 sf.pos=6079104;
 r = NULL;
YrvEa:
 topFrame = sf.prev;
 return r;
}
Tc *YqGL(Y0uC *t) { /* CFieldItem.funcName */
 Zsf sf={0,topFrame};
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=257100;
  ZthrowThisNil();
 }
 sf.pos=257101;
 r = ZcS((t1 = ZstringToUpper(YuALa(t->Vname, 0, 0))), (t0 = YuAL(t->Vname, 1)));
 topFrame = sf.prev;
 return r;
}
Te YKJX(Tc *AtypeName) { /* CFieldItem__X.getType */
 Zsf sf={0,topFrame};
 Te r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=1977200;
 if (ZDictHas(YGNu, (Tz)(void*)AtypeName))
 {
  sf.pos=1977201;
  r = ZDictGetInt(YGNu, (Tz)(void*)AtypeName);
  rt = 1;
  goto Yxgy;
 }
 sf.pos=1977202;
 r = 0;
Yxgy:
 topFrame = sf.prev;
 return r;
}
To ToY0uC[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&string__T}, /* typeName */
 {0, (Tt*)&string__T}, /* default */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y0uC__T = {390, (Tc*)&Y5D2a, 0, ToY0uC};
int JFieldItem(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf={0,topFrame};
  topFrame = &sf;
  round_done = round;
  if (round == 2001) {
   sf.pos=9018300;
   YGNu = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&string__T, (Tt*)&MProto__EType__T, 0), (Tz)(void*)((Tc*)&YanE), (Tz)(Ti)17), (Tz)(void*)((Tc*)&YGxv), (Tz)(Ti)2), (Tz)(void*)((Tc*)&Y1Qt), (Tz)(Ti)9), (Tz)(void*)((Tc*)&YrQi), (Tz)(Ti)10), (Tz)(void*)((Tc*)&YJyN), (Tz)(Ti)18), (Tz)(void*)((Tc*)&YhVi), (Tz)(Ti)11), (Tz)(void*)((Tc*)&YzDN), (Tz)(Ti)19), (Tz)(void*)((Tc*)&Yt7n), (Tz)(Ti)6), (Tz)(void*)((Tc*)&Ygep), (Tz)(Ti)7), (Tz)(void*)((Tc*)&YtPw), (Tz)(Ti)1);
  }
  topFrame = sf.prev;
 }
 return done;
}
/* FieldItem done */
/* including OptionItem bodies */
/* including PToken bodies */
To ToYkeq[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* value */
 {0, (Tt*)&YkxB__T}, /* startPos */
 {0, (Tt*)&YkxB__T}, /* endPos */
};
Tto Ykeq__T = {390, (Tc*)&YgVD, 0, ToYkeq};
/* PToken done */
To ToYswy[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&string__T}, /* value */
};
Tto Yswy__T = {390, (Tc*)&YcBr, 0, ToYswy};
/* OptionItem done */
YRAB *YI6R(YRAB *t) { /* CMessageItem.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=3921300; t = Za(sizeof(YRAB));}
 sf.pos=3921301;
 t->Vfields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=3921302;
 t->Vitems = ZnewList((Tt*)&iobj__T, 0);
 sf.pos=3921303;
 t->VoptionList = ZnewList((Tt*)&Yswy__T, 0);
 topFrame = sf.prev;
 return t;
}
void YNVJ(YRAB *t, Yswy *Aoption) { /* CMessageItem.addOption */
}
Tr YBZe(YRAB *t, Tc *Aname) { /* CMessageItem.findItem */
 Zsf sf={0,topFrame};
 Tr r = {NULL};
 Tl *Zf1 = NULL;
 Tr Vitem = {NULL,0,-1};
 int rt = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=167900;
  ZthrowThisNil();
 }
 sf.pos=167901;
 {
  Tfl Zf1i;
  Zf1 = t->Vitems;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vitem;
  Zf1i.i = 0;
  for (; ZforListIobjCont(&Zf1i); ) {
  sf.pos=167902;
  if ((ZstringCmp((*(Tc**)(Vitem.ptr + (size_t)Vitem.table[1])), Aname) == 0))
  {
   sf.pos=167903;
   r = Vitem;
   rt = 1;
   goto YT0Y;
  }
YT0Y:
  if (rt) goto YPos;
  sf.pos=167904;
  }
 }
 sf.pos=167905;
 if ((((t->Vparent).ptr) != (void *)NULL))
 {
  sf.pos=167906;
  r = ((Tr (*)(void*, Tc*))(t->Vparent.table[1]))(t->Vparent.ptr, Aname);
  rt = 1;
  goto YPos;
 }
 sf.pos=167907;
 r = trZero;
YPos:
 topFrame = sf.prev;
 return r;
}
Ts YbaL(YRAB *t) { /* CMessageItem.checkErrors */
 Ts Vret;
 Zsf sf={0,topFrame};
 Ts r = 0;
 Tl *Zf1 = NULL;
 Y0uC *Vf = 0;
 Yhqr *VusedNr = 0;
 Ygqr *VusedName = 0;
 YkxB *t0 = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3990600;
  ZthrowThisNil();
 }
 sf.pos=3990601;
 VusedNr = Yh95(NULL);
 sf.pos=3990602;
 VusedName = YGrg(NULL);
 sf.pos=3990603;
 Vret = 1;
 sf.pos=3990604;
 {
  Tfl Zf1i;
  Zf1 = t->Vfields;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vf;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=3990605;
  if (YyHa((Yhqr *)VusedNr, Vf->Vnr))
  {
   sf.pos=3990606;
   YDli(ZcS(((Tc*)&YUra), Zint2string(Vf->Vnr)), (t0 = Vf->Vpos), 0);
   sf.pos=3990607;
   Vret = 0;
  }
  else {
  sf.pos=3990608;
  if (YXZk((Ygqr *)VusedName, Vf->Vname))
  {
   sf.pos=3990609;
   YDli(ZcS(((Tc*)&Yy3i), Vf->Vname), (t0 = Vf->Vpos), 0);
   sf.pos=3990610;
   Vret = 0;
  }
  else
  {
   sf.pos=3990611;
   YGMT((Yhqr *)VusedNr, Vf->Vnr);
   sf.pos=3990612;
   Y432((Ygqr *)VusedName, Vf->Vname);
  }
  }
  sf.pos=3990613;
  }
 }
 sf.pos=3990614;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tc *YRAB__YuXI_imt[] = {
 (Tc*)&YRAB__T,
 (Tc*)0, /* Vname */
};
Tc *YRAB__Ytv2_imt[] = {
 (Tc*)&YRAB__T,
 (Tc*)YBZe, /* CMessageItem.findItem - YBZe */
};
To ToYRAB[] = {
 {5, 0},
 {0, (Tt*)&iobj__T}, /* parent */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* fields */
 {0, (Tt*)&list__T}, /* items */
 {0, (Tt*)&list__T}, /* optionList */
};
Tto YRAB__T = {390, (Tc*)&YQoy, 0, ToYRAB};
int JMessageItem(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf={0,topFrame};
  topFrame = &sf;
  round_done = round;
 done &= JFieldItem(round);
  if (round == 2001) {
  }
  topFrame = sf.prev;
 }
 return done;
}
/* MessageItem done */
/* including ProtoFile bodies */
YP_l *Yy3W(YP_l *t) { /* CProtoFile.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=3572100; t = Za(sizeof(YP_l));}
 sf.pos=3572101;
 t->VitemList = ZnewList((Tt*)&iobj__T, 0);
 sf.pos=3572102;
 t->VitemDict = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
 sf.pos=3572103;
 t->Vimports = ZnewList((Tt*)&YP_l__T, 0);
 topFrame = sf.prev;
 return t;
}
void YhB6(YP_l *t, Tr Aitem) { /* CProtoFile.addItem */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=353100;
  ZthrowThisNil();
 }
 sf.pos=353101;
 if (((*(Tc**)(Aitem.ptr + (size_t)Aitem.table[1])) != NULL))
 {
  sf.pos=353102;
  ZLapIobj((Tl*)t->VitemList, Aitem);
  sf.pos=353103;
  ZDictAddTzIobj(0, t->VitemDict, (Tz)(void*)(*(Tc**)(Aitem.ptr + (size_t)Aitem.table[1])), Aitem);
 }
 topFrame = sf.prev;
 return;
}
void YYPi(YP_l *t, Yswy *Aoption) { /* CProtoFile.addOption */
}
Tr YKwR(YP_l *t, Tc *Aname) { /* CProtoFile.findItem */
 Zsf sf={0,topFrame};
 Tr r = {NULL};
 Tl *Zf1 = NULL;
 Tr Vitem = {NULL,0,-1};
 Tl *Zf11 = NULL;
 YP_l *Vimport = 0;
 Tr Vitem1 = {NULL,0,-1};
 int rt = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3881100;
  ZthrowThisNil();
 }
 sf.pos=3881101;
 {
  Tfl Zf1i;
  Zf1 = t->VitemList;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vitem;
  Zf1i.i = 0;
  for (; ZforListIobjCont(&Zf1i); ) {
  sf.pos=3881102;
  if ((ZstringCmp((*(Tc**)(Vitem.ptr + (size_t)Vitem.table[1])), Aname) == 0))
  {
   sf.pos=3881103;
   r = Vitem;
   rt = 1;
   goto YGnf;
  }
YGnf:
  if (rt) goto YjkG;
  sf.pos=3881104;
  }
 }
 sf.pos=3881105;
 {
  Tfl Zf11i;
  Zf11 = t->Vimports;
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vimport;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=3881106;
  Vitem1 = YKwR((YP_l *)Vimport, Aname);
  sf.pos=3881107;
  if ((((Vitem1).ptr) != (void *)NULL))
  {
   sf.pos=3881108;
   r = Vitem1;
   rt = 1;
   goto Y3Qy;
  }
Y3Qy:
  if (rt) goto YjkG;
  sf.pos=3881109;
  }
 }
 sf.pos=3881110;
 r = trZero;
YjkG:
 topFrame = sf.prev;
 return r;
}
Tc *YP_l__Ytv2_imt[] = {
 (Tc*)&YP_l__T,
 (Tc*)YKwR, /* CProtoFile.findItem - YKwR */
};
To ToYP_l[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* package */
 {0, (Tt*)&list__T}, /* imports */
 {0, (Tt*)&list__T}, /* itemList */
 {0, (Tt*)&dict__T}, /* itemDict */
};
Tto YP_l__T = {390, (Tc*)&YU8M, 0, ToYP_l};
/* ProtoFile done */
/* including ServiceItem bodies */
/* including RpcItem bodies */
YlM3 *YwLI(YlM3 *t, Tc *Aname) { /* CRpcItem.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=5727300; t = Za(sizeof(YlM3));}
 sf.pos=5727301;
 t->Vname = Aname;
 topFrame = sf.prev;
 return t;
}
Tc *YlM3__YuXI_imt[] = {
 (Tc*)&YlM3__T,
 (Tc*)0, /* Vname */
};
To ToYlM3[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&string__T}, /* requestName */
 {0, (Tt*)&string__T}, /* responseName */
};
Tto YlM3__T = {390, (Tc*)&YWB_, 0, ToYlM3};
/* RpcItem done */
YNW5 *Y_oR(YNW5 *t) { /* CServiceItem.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=3638100; t = Za(sizeof(YNW5));}
 sf.pos=3638101;
 t->Vrpcs = ZnewList((Tt*)&YlM3__T, 0);
 topFrame = sf.prev;
 return t;
}
void YBM3(YNW5 *t, YlM3 *Arpc) { /* CServiceItem.add */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5594400;
  ZthrowThisNil();
 }
 sf.pos=5594401;
 ZLap((Tl*)t->Vrpcs, (Tz)(void*)Arpc);
 topFrame = sf.prev;
 return;
}
Tr Y96y(YNW5 *t, Tc *Aname) { /* CServiceItem.findItem */
 Zsf sf={0,topFrame};
 Tr r = {NULL};
 Tl *Zf1 = NULL;
 YlM3 *Vrpc = 0;
 Tr t0 = {NULL,0,-1};
 int rt = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6633500;
  ZthrowThisNil();
 }
 sf.pos=6633501;
 {
  Tfl Zf1i;
  Zf1 = t->Vrpcs;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vrpc;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=6633502;
  if ((ZstringCmp(Vrpc->Vname, Aname) == 0))
  {
   sf.pos=6633503;
   r = *Znao(&t0, Vrpc, YlM3__YuXI_imt, 3);
   rt = 1;
   goto YiOk;
  }
YiOk:
  if (rt) goto Y6AE;
  sf.pos=6633504;
  }
 }
 sf.pos=6633505;
 r = trZero;
Y6AE:
 topFrame = sf.prev;
 return r;
}
Tc *YNW5__YuXI_imt[] = {
 (Tc*)&YNW5__T,
 (Tc*)0, /* Vname */
};
To ToYNW5[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* rpcs */
};
Tto YNW5__T = {390, (Tc*)&YMK2, 0, ToYNW5};
/* ServiceItem done */
/* including PTokenInput bodies */
/* including Input bodies */
YeYq *YOdr(YeYq *t, Yw8L *Afd, Tc *Afname, Tc *Aindent, Tb Arecord) { /* CInput.NEW */
 Zsf sf={0,topFrame};
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
  t->VrecordWriter = Zamt(sizeof(YjUM), YjUM__mt);
 }
 topFrame = sf.prev;
 return t;
}
Ti YAit(YeYq *t) { /* CInput.get */
 Ti Vstartcol;
 Ti Vc;
 Zsf sf={0,topFrame};
 Ti r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1988700;
  ZthrowThisNil();
 }
 sf.pos=1988701;
 Vstartcol = t->Vpos->Vcol;
 Vc = 0;
 sf.pos=1988702;
 if ((ZListSize(t->VcharStack) > 0))
 {
  sf.pos=1988703;
  Vc = ZListRemoveIntItem((Tl*)t->VcharStack, -1);
  sf.pos=1988704;
  ++(t->Vpos->Vcol);
 }
 else {
 sf.pos=1988705;
 if ((t->Vfd == (void *)NULL))
 {
  sf.pos=1988706;
  if ((t->VtextIdx >= ZstringSize(t->Vtext)))
  {
   sf.pos=1988707;
   Vc = Y3QJ;
  }
  else
  {
   sf.pos=1988708;
   Vc = ZstringGetChar(t->Vtext, t->VtextIdx);
   sf.pos=1988709;
   ++(t->VtextIdx);
   sf.pos=1988710;
   ++(t->Vpos->Vcol);
  }
 }
 else
 {
  sf.pos=1988711;
  for (;;)
  {
   sf.pos=1988712;
   Vc = YAPp((Yw8L *)t->Vfd);
   sf.pos=1988713;
   ++(t->Vpos->Vcol);
   sf.pos=1988714;
   if (((((Vc >= 0) && (Vc <= 31))) || (((Vc >= 127) && (Vc <= 160)))))
   {
    sf.pos=1988715;
    if ((Vc == 0))
    {
     sf.pos=1988716;
     YDli(((Tc*)&YrKy), t->Vpos, 0);
     sf.pos=1988717;
     Vc = 32;
    }
    else {
    sf.pos=1988718;
    if ((Vc == 9))
    {
     sf.pos=1988719;
     if (!(t->VallowTabs))
     {
      sf.pos=1988720;
      YDli(((Tc*)&YemR), t->Vpos, 0);
     }
     sf.pos=1988721;
     Vc = 32;
    }
    else {
    sf.pos=1988722;
    if (((Vc != 13) && (Vc != 10)))
    {
     sf.pos=1988723;
     YDli(((Tc*)&Y3Pw), t->Vpos, 0);
     sf.pos=1988724;
     Vc = 32;
    }
    }}
   }
   sf.pos=1988725;
   if (((Vc != 13) && (Vc != 65279))) break;
  sf.pos=1988726;
  }
 }
 }
 sf.pos=1988727;
 if ((Vc == 10))
 {
  sf.pos=1988728;
  t->VprevLineCol = t->Vpos->Vcol;
  sf.pos=1988729;
  YnS4((YkxB *)t->Vpos);
 }
 sf.pos=1988730;
 if (((t->VrecordWriter != NULL) && (Vc != Y3QJ)))
 {
  sf.pos=1988731;
  if (Yqej((YjUM *)t->VrecordWriter))
  {
   sf.pos=1988732;
   t->VrecordStartCol = Vstartcol;
  }
  sf.pos=1988733;
  YjUM__Ydti((YjUM *)t->VrecordWriter, Vc);
 }
 sf.pos=1988734;
 r = Vc;
 topFrame = sf.prev;
 return r;
}
void YmK2(YeYq *t, Ti Ac) { /* CInput.push */
 Zsf sf={0,topFrame};
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
   Y6jW((YjUM *)t->VrecordWriter);
  }
 }
 topFrame = sf.prev;
 return;
}
To ToYeYq[] = {
 {6, 0},
 {0, (Tt*)&xobj__T}, /* fd */
 {0, (Tt*)&string__T}, /* text */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* charStack */
 {0, (Tt*)&string__T}, /* indent */
 {0, (Tt*)&xobj__T}, /* recordWriter */
};
Tto YeYq__T = {390, (Tc*)&YVUW, 0, ToYeYq};
/* Input done */
/* including PTokenize bodies */
Ykeq *Y7Z3(YuI4 *Ain) { /* MPTokenize.get */
 Ti Vc;
 Zsf sf={0,topFrame};
 Ykeq *r = 0;
 Ykeq *Vres = 0;
 YjUM *Vwriter = 0;
 YkxB *t0 = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=6302400;
 Vres = Za(sizeof(Ykeq));
 sf.pos=6302401;
 Vres->VstartPos = Y83A((YkxB *)Ain->Vinput->Vpos);
 sf.pos=6302402;
 YVn_(Ain);
 sf.pos=6302403;
 Vres->VstartPos = Y83A((YkxB *)Ain->Vinput->Vpos);
 sf.pos=6302404;
 Vwriter = Zamt(sizeof(YjUM), YjUM__mt);
 sf.pos=6302405;
 Vc = YIaq((YuI4 *)Ain);
 sf.pos=6302406;
 if ((Vc != Y3QJ))
 {
  sf.pos=6302407;
  YjUM__Ydti((YjUM *)Vwriter, Vc);
 }
 sf.pos=6302408;
 switch (Vc)
 {
  case Y3QJ:
  {
   sf.pos=6302409;
   Vres->Vtype = 25;
    break;
  }
  case 59:
  {
   sf.pos=6302410;
   Vres->Vtype = 17;
    break;
  }
  case 61:
  {
   sf.pos=6302411;
   Vres->Vtype = 18;
    break;
  }
  case 40:
  {
   sf.pos=6302412;
   Vres->Vtype = 19;
    break;
  }
  case 41:
  {
   sf.pos=6302413;
   Vres->Vtype = 20;
    break;
  }
  case 123:
  {
   sf.pos=6302414;
   Vres->Vtype = 21;
    break;
  }
  case 125:
  {
   sf.pos=6302415;
   Vres->Vtype = 22;
    break;
  }
  case 91:
  {
   sf.pos=6302416;
   Vres->Vtype = 23;
    break;
  }
  case 93:
  {
   sf.pos=6302417;
   Vres->Vtype = 24;
    break;
  }
  case 34:
  {
   Ti Vi;
   sf.pos=6302418;
   Y6jW((YjUM *)Vwriter);
   sf.pos=6302419;
   Vres->Vtype = 16;
   Vi = 0;
   sf.pos=6302420;
   while (1)
   {
    sf.pos=6302421;
    Vc = YIaq((YuI4 *)Ain);
    sf.pos=6302422;
    if ((Vc == 34))
    {
     rt = 2;
     goto YBCw;
    }
    sf.pos=6302423;
    if (((Vc == 10) || (Vc == Y3QJ)))
    {
     sf.pos=6302424;
     YCer((YuI4 *)Ain, Vc);
     sf.pos=6302425;
     YDli(((Tc*)&YD4M), Vres->VstartPos, 0);
     rt = 2;
     goto YBCw;
    }
    sf.pos=6302426;
    if ((Vc == 92))
    {
     sf.pos=6302427;
     Vc = YIaq((YuI4 *)Ain);
     sf.pos=6302428;
     if (((Vc == 10) || (Vc == Y3QJ)))
     {
      sf.pos=6302429;
      YDli(((Tc*)&YD4M), Vres->VstartPos, 0);
      rt = 2;
      goto Yd3y;
     }
     sf.pos=6302430;
     if ((Vc == 110))
     {
      sf.pos=6302431;
      YjUM__Ydti((YjUM *)Vwriter, 10);
     }
     else {
     sf.pos=6302432;
     if ((Vc == 116))
     {
      sf.pos=6302433;
      YjUM__Ydti((YjUM *)Vwriter, 9);
     }
     else {
     sf.pos=6302434;
     if ((Vc == 114))
     {
      sf.pos=6302435;
      YjUM__Ydti((YjUM *)Vwriter, 13);
     }
     else
     {
      sf.pos=6302436;
      YjUM__Ydti((YjUM *)Vwriter, Vc);
     }
     }}
Yd3y:
     if (rt) goto YBCw;
    }
    else
    {
     sf.pos=6302437;
     YjUM__Ydti((YjUM *)Vwriter, Vc);
    }
YBCw:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=6302438;
   }
    break;
  }
  case 39:
  {
   sf.pos=6302439;
   Vc = YIaq((YuI4 *)Ain);
   sf.pos=6302440;
   Vres->Vtype = 15;
   sf.pos=6302441;
   if ((Vc == 92))
   {
    sf.pos=6302442;
    Vc = YIaq((YuI4 *)Ain);
    sf.pos=6302443;
    switch (Vc)
    {
     case 110:
     {
      sf.pos=6302444;
      Vc = 10;
       break;
     }
     case 114:
     {
      sf.pos=6302445;
      Vc = 13;
       break;
     }
     case 116:
     {
      sf.pos=6302446;
      Vc = 9;
       break;
     }
    }
   }
   sf.pos=6302447;
   Y6jW((YjUM *)Vwriter);
   sf.pos=6302448;
   YjUM__Ydti((YjUM *)Vwriter, Vc);
   sf.pos=6302449;
   Vc = YIaq((YuI4 *)Ain);
   sf.pos=6302450;
   if ((Vc != 39))
   {
    sf.pos=6302451;
    YDli(((Tc*)&YYrm), Vres->VstartPos, 0);
   }
    break;
  }
 default:
  {
   Ti Vi;
   Vi = 0;
   sf.pos=6302452;
   if (!(YdpE(Vc)))
   {
    sf.pos=6302453;
    YDli(ZcS3(((Tc*)&YtNZ), ZintAsString(Vc), ((Tc*)&YN)), (t0 = Vres->VstartPos), 0);
   }
   else
   {
    Ti Vquot;
    Vquot = 0;
    sf.pos=6302454;
    if (((Vc >= 48) && (Vc <= 57)))
    {
     sf.pos=6302455;
     Vquot = 39;
    }
    sf.pos=6302456;
    Y6jW((YjUM *)Vwriter);
    sf.pos=6302457;
    while ((YdpE(Vc) || (Vc == Vquot)))
    {
     sf.pos=6302458;
     YjUM__Ydti((YjUM *)Vwriter, Vc);
     sf.pos=6302459;
     Vc = YIaq((YuI4 *)Ain);
    sf.pos=6302460;
    }
    sf.pos=6302461;
    YCer((YuI4 *)Ain, Vc);
   }
   sf.pos=6302462;
   Vres->Vtype = ZDictGetIntDef(YwVY, (Tz)(void*)YbNW((YjUM *)Vwriter), 0);
   sf.pos=6302463;
   if ((Vres->Vtype == 0))
   {
    sf.pos=6302464;
    Vres->Vtype = 12;
   }
    break;
  }
 }
 sf.pos=6302465;
 Vres->Vvalue = YbNW((YjUM *)Vwriter);
 sf.pos=6302466;
 Vres->VendPos = Y83A((YkxB *)Ain->Vinput->Vpos);
 sf.pos=6302467;
 r = Vres;
 topFrame = sf.prev;
 return r;
}
void YVn_(YuI4 *Ain) { /* MPTokenize.skipWhite */
 Ti Vc;
 Zsf sf={0,topFrame};
 int rt = 0;
 topFrame = &sf;
 Vc = 0;
 sf.pos=5002400;
 while (1)
 {
  sf.pos=5002401;
  Vc = YIaq((YuI4 *)Ain);
  sf.pos=5002402;
  if ((Vc == 47))
  {
   Ti Vnc;
   sf.pos=5002403;
   Vnc = YIaq((YuI4 *)Ain);
   sf.pos=5002404;
   if ((Vnc == 47))
   {
    sf.pos=5002405;
    while (1)
    {
     sf.pos=5002406;
     Vc = YIaq((YuI4 *)Ain);
     sf.pos=5002407;
     if (((Vc == Y3QJ) || (Vc == 10)))
     {
      rt = 2;
      goto Y4bI;
     }
Y4bI:
     if (rt == 2) { rt &= 1; break; }
    sf.pos=5002408;
    }
    rt = 4;
    if (rt) goto YVK1;
   }
   sf.pos=5002409;
   YCer((YuI4 *)Ain, Vnc);
YVK1:
   if (rt) goto YW6P;
  }
  sf.pos=5002410;
  if (((Vc != 32) && (Vc != 10)))
  {
   rt = 2;
   goto YW6P;
  }
YW6P:
  if (rt == 2) { rt &= 1; break; }
  if (rt == 4) { rt &= 1; continue; }
 sf.pos=5002411;
 }
 sf.pos=5002412;
 YCer((YuI4 *)Ain, Vc);
 topFrame = sf.prev;
 return;
}
Tb YdpE(Ti Ac) { /* MPTokenize.isIdChar */
 Zsf sf={0,topFrame};
 Tb r = 0;
 topFrame = &sf;
 sf.pos=4199900;
 r = ((((((Ac >= 97) && (Ac <= 122))) || (((Ac >= 65) && (Ac <= 90)))) || (((Ac >= 48) && (Ac <= 57)))) || (Ac == 95));
 topFrame = sf.prev;
 return r;
}
int JPTokenize(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf={0,topFrame};
  topFrame = &sf;
  round_done = round;
  if (round == 2001) {
   sf.pos=5042100;
   YwVY = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&string__T, (Tt*)&CPToken__EType__T, 0), (Tz)(void*)((Tc*)&YpLJ), (Tz)(Ti)8), (Tz)(void*)((Tc*)&Y89Q), (Tz)(Ti)3), (Tz)(void*)((Tc*)&YL0B), (Tz)(Ti)2), (Tz)(void*)((Tc*)&YXqe), (Tz)(Ti)4), (Tz)(void*)((Tc*)&Yveu), (Tz)(Ti)6), (Tz)(void*)((Tc*)&Yg9u), (Tz)(Ti)1), (Tz)(void*)((Tc*)&Ygug), (Tz)(Ti)7), (Tz)(void*)((Tc*)&YJcg), (Tz)(Ti)5), (Tz)(void*)((Tc*)&Yiu9), (Tz)(Ti)11), (Tz)(void*)((Tc*)&Yf1Q), (Tz)(Ti)10), (Tz)(void*)((Tc*)&YmU3), (Tz)(Ti)9);
  }
  topFrame = sf.prev;
 }
 return done;
}
/* PTokenize done */
YuI4 *YW5n(YuI4 *t, Yw8L *Afd, Tc *Afname, Tc *Aindent) { /* CPTokenInput.NEW */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {sf.pos=4431800; t = Za(sizeof(YuI4));}
 sf.pos=4431801;
 t->Vinput = YOdr(NULL, Afd, Afname, Aindent, 0);
 sf.pos=4431802;
 t->VtokenStack = ZnewList((Tt*)&Ykeq__T, 0);
 topFrame = sf.prev;
 return t;
}
Ti YIaq(YuI4 *t) { /* CPTokenInput.get */
 Zsf sf={0,topFrame};
 Ti r = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1980400;
  ZthrowThisNil();
 }
 sf.pos=1980401;
 r = YAit((YeYq *)t->Vinput);
 topFrame = sf.prev;
 return r;
}
void YCer(YuI4 *t, Ti Ac) { /* CPTokenInput.push */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4496000;
  ZthrowThisNil();
 }
 sf.pos=4496001;
 YmK2((YeYq *)t->Vinput, Ac);
 topFrame = sf.prev;
 return;
}
Ykeq *YVoF(YuI4 *t) { /* CPTokenInput.getToken */
 Zsf sf={0,topFrame};
 Ykeq *r = 0;
 int rt = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3524900;
  ZthrowThisNil();
 }
 sf.pos=3524901;
 if ((ZListSize(t->VtokenStack) > 0))
 {
  sf.pos=3524902;
  r = ZListRemovePtrItem((Tl*)t->VtokenStack, -1);
  rt = 1;
  goto YiWv;
 }
 sf.pos=3524903;
 r = Y7Z3(t);
YiWv:
 topFrame = sf.prev;
 return r;
}
void Y4Sj(YuI4 *t, Ykeq *Atoken) { /* CPTokenInput.pushToken */
 Zsf sf={0,topFrame};
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2093300;
  ZthrowThisNil();
 }
 sf.pos=2093301;
 ZLap((Tl*)t->VtokenStack, (Tz)(void*)Atoken);
 topFrame = sf.prev;
 return;
}
To ToYuI4[] = {
 {2, 0},
 {0, (Tt*)&YeYq__T}, /* input */
 {0, (Tt*)&list__T}, /* tokenStack */
};
Tto YuI4__T = {390, (Tc*)&Ytw1, 0, ToYuI4};
int JPTokenInput(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf={0,topFrame};
  topFrame = &sf;
  round_done = round;
 done &= JPTokenize(round);
  if (round == 2001) {
  }
  topFrame = sf.prev;
 }
 return done;
}
/* PTokenInput done */
YP_l *YSOt(Tc *Afname) { /* MParseProto.parse */
 Zsf sf={0,topFrame};
 YP_l *r = 0;
 YP_l *Vpfile = 0;
 Yw8L *Vfd = NULL;
 YuI4 *Vin = 0;
 Ykeq *Vtoken = 0;
 YRAB *Vmsg = 0;
 Tr t0 = {NULL,0,-1};
 YkxB *t1 = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=7157300;
 Vpfile = Yy3W(NULL);
 sf.pos=7157301;
 Vfd = YsGz(Afname);
 sf.pos=7157302;
 if ((Vfd == (void *)NULL))
 {
  sf.pos=7157303;
  Yl0k(ZcS(((Tc*)&YdgR), Afname));
  sf.pos=7157304;
  Zexit(NULL, 1);
  return NULL;
 }
 sf.pos=7157305;
 Vin = YW5n(NULL, Vfd, Afname, ((Tc*)&Ya));
 sf.pos=7157306;
 Vin->Vinput->VallowTabs = 1;
 sf.pos=7157307;
 Ylxt();
 sf.pos=7157308;
 while (1)
 {
  sf.pos=7157309;
  Vtoken = YVoF((YuI4 *)Vin);
  sf.pos=7157310;
  if ((Vtoken->Vtype == 25))
  {
   rt = 2;
   goto YjCc;
  }
  sf.pos=7157311;
  switch (Vtoken->Vtype)
  {
   case 1:
   {
    sf.pos=7157312;
    YjA8(Vin, Vpfile);
     break;
   }
   case 4:
   {
    sf.pos=7157313;
    YYPi((YP_l *)Vpfile, YDgP(Vin));
     break;
   }
   case 9:
   {
    sf.pos=7157314;
    YUys(Vpfile, YpkI(Vin, Vpfile));
     break;
   }
   case 2:
   {
    sf.pos=7157316;
    Vmsg = ((YRAB *)Znio(2, 7157315, (YOrf(Vin))));
    sf.pos=7157317;
    Vmsg->Vparent = *Znao(&t0, Vpfile, YP_l__Ytv2_imt, 1);
    sf.pos=7157318;
    YhB6((YP_l *)Vpfile, *Znao(&t0, Vmsg, YRAB__YuXI_imt, 2));
     break;
   }
   case 3:
   {
    sf.pos=7157319;
    YUys(Vpfile, YCm2(Vin));
     break;
   }
  default:
   {
    sf.pos=7157320;
    YDli(ZcS(((Tc*)&YJWm), Vtoken->Vvalue), (t1 = Vtoken->VstartPos), 0);
     break;
   }
  }
YjCc:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=7157321;
 }
 sf.pos=7157322;
 YrF8((Yw8L *)Vfd);
 sf.pos=7157323;
 r = Vpfile;
 topFrame = sf.prev;
 return r;
}
void YjA8(YuI4 *Ain, YP_l *Apfile) { /* MParseProto.parsePackage */
 Zsf sf={0,topFrame};
 Ykeq *Vt = 0;
 topFrame = &sf;
 sf.pos=9452500;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=9452501;
 if ((Vt->Vtype != 12))
 {
  sf.pos=9452502;
  YDli(((Tc*)&Y2by), Vt->VstartPos, 0);
 }
 else {
 sf.pos=9452503;
 if ((Apfile->Vpackage != NULL))
 {
  sf.pos=9452504;
  YDli(((Tc*)&YHnJ), Vt->VstartPos, 0);
 }
 else
 {
  sf.pos=9452505;
  Apfile->Vpackage = Vt->Vvalue;
 }
 }
 sf.pos=9452506;
 YYYx(Ain);
 topFrame = sf.prev;
 return;
}
Yswy *YDgP(YuI4 *Ain) { /* MParseProto.parseOption */
 Zsf sf={0,topFrame};
 Yswy *r = 0;
 Yswy *Voption = 0;
 Ykeq *Vt = 0;
 topFrame = &sf;
 sf.pos=1272600;
 Voption = Za(sizeof(Yswy));
 sf.pos=1272601;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=1272602;
 if ((Vt->Vtype != 12))
 {
  sf.pos=1272603;
  YDli(((Tc*)&Y6FG), Vt->VstartPos, 0);
 }
 else
 {
  sf.pos=1272604;
  Voption->Vpos = Vt->VstartPos;
  sf.pos=1272605;
  Voption->Vname = Vt->Vvalue;
  sf.pos=1272606;
  Vt = YVoF((YuI4 *)Ain);
  sf.pos=1272607;
  if ((Vt->Vtype == 18))
  {
   sf.pos=1272608;
   Vt = YVoF((YuI4 *)Ain);
   sf.pos=1272609;
   if (((Vt->Vtype != 16) && (Vt->Vtype != 12)))
   {
    sf.pos=1272610;
    YDli(((Tc*)&Y82z), Vt->VstartPos, 0);
   }
   else
   {
    sf.pos=1272611;
    Voption->Vtype = Vt->Vtype;
    sf.pos=1272612;
    Voption->Vvalue = Vt->Vvalue;
    sf.pos=1272613;
    YYYx(Ain);
   }
  }
  else {
  sf.pos=1272614;
  if ((Vt->Vtype != 17))
  {
   sf.pos=1272615;
   YDli(((Tc*)&Y0Xz), Vt->VstartPos, 0);
  }
  }
 }
 sf.pos=1272616;
 r = Voption;
 topFrame = sf.prev;
 return r;
}
Tr YpkI(YuI4 *Ain, YP_l *Apfile) { /* MParseProto.parseService */
 Zsf sf={0,topFrame};
 Tr r = {NULL};
 YNW5 *Vservice = 0;
 Ykeq *Vt = 0;
 YlM3 *Vrpc = 0;
 Tr t0 = {NULL,0,-1};
 int rt = 0;
 topFrame = &sf;
 sf.pos=626200;
 Vservice = Y_oR(NULL);
 sf.pos=626201;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=626202;
 if ((Vt->Vtype != 12))
 {
  sf.pos=626203;
  YDli(((Tc*)&YJUj), Vt->VstartPos, 0);
 }
 else
 {
  sf.pos=626204;
  Vservice->Vname = Vt->Vvalue;
  sf.pos=626205;
  Vt = YVoF((YuI4 *)Ain);
  sf.pos=626206;
  if ((Vt->Vtype != 21))
  {
   sf.pos=626207;
   YDli(((Tc*)&YlMg), Vt->VstartPos, 0);
  }
  else
  {
   sf.pos=626208;
   while (1)
   {
    sf.pos=626209;
    Vt = YVoF((YuI4 *)Ain);
    sf.pos=626210;
    if ((Vt->Vtype == 22))
    {
     rt = 2;
     goto Y9kj;
    }
    sf.pos=626211;
    if (YtEy(Vt))
    {
     rt = 2;
     goto Y9kj;
    }
    sf.pos=626212;
    if ((Vt->Vtype != 10))
    {
     sf.pos=626213;
     YDli(((Tc*)&YT_h), Vt->VstartPos, 0);
    }
    else
    {
     sf.pos=626214;
     Vt = YVoF((YuI4 *)Ain);
     sf.pos=626215;
     if ((Vt->Vtype != 12))
     {
      sf.pos=626216;
      YDli(((Tc*)&YImx), Vt->VstartPos, 0);
     }
     else
     {
      Tb VhadOpenParen;
      sf.pos=626217;
      Vrpc = YwLI(NULL, Vt->Vvalue);
      sf.pos=626218;
      YBM3((YNW5 *)Vservice, Vrpc);
      sf.pos=626219;
      Vt = YVoF((YuI4 *)Ain);
      sf.pos=626220;
      if ((Vt->Vtype != 19))
      {
       sf.pos=626221;
       YDli(((Tc*)&YZG7), Vt->VstartPos, 0);
      }
      sf.pos=626222;
      Vt = YVoF((YuI4 *)Ain);
      sf.pos=626223;
      if ((Vt->Vtype != 12))
      {
       sf.pos=626224;
       YDli(((Tc*)&Yq4F), Vt->VstartPos, 0);
      }
      else
      {
       sf.pos=626225;
       Vrpc->VrequestName = Vt->Vvalue;
      }
      sf.pos=626226;
      if ((Vt->Vtype != 20))
      {
       sf.pos=626227;
       Vt = YVoF((YuI4 *)Ain);
       sf.pos=626228;
       if ((Vt->Vtype != 20))
       {
        sf.pos=626229;
        YDli(((Tc*)&Y_G7), Vt->VstartPos, 0);
       }
      }
      sf.pos=626230;
      Vt = YVoF((YuI4 *)Ain);
      sf.pos=626231;
      if ((Vt->Vtype != 11))
      {
       sf.pos=626232;
       YDli(((Tc*)&YMrT), Vt->VstartPos, 0);
      }
      sf.pos=626233;
      Vt = YVoF((YuI4 *)Ain);
      VhadOpenParen = 0;
      sf.pos=626234;
      if ((Vt->Vtype == 19))
      {
       sf.pos=626235;
       VhadOpenParen = 1;
       sf.pos=626236;
       Vt = YVoF((YuI4 *)Ain);
      }
      sf.pos=626237;
      if ((Vt->Vtype != 12))
      {
       sf.pos=626238;
       YDli(((Tc*)&YXcR), Vt->VstartPos, 0);
      }
      else
      {
       sf.pos=626239;
       Vrpc->VresponseName = Vt->Vvalue;
      }
      sf.pos=626240;
      if (VhadOpenParen)
      {
       sf.pos=626241;
       Vt = YVoF((YuI4 *)Ain);
       sf.pos=626242;
       if ((Vt->Vtype != 20))
       {
        sf.pos=626243;
        YDli(((Tc*)&Y_G7), Vt->VstartPos, 0);
       }
      }
      sf.pos=626244;
      YYYx(Ain);
     }
    }
Y9kj:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=626245;
   }
  }
 }
 sf.pos=626246;
 r = *Znao(&t0, Vservice, YNW5__YuXI_imt, 4);
 topFrame = sf.prev;
 return r;
}
Tr YOrf(YuI4 *Ain) { /* MParseProto.parseMessage */
 Zsf sf={0,topFrame};
 Tr r = {NULL};
 YRAB *Vitem = 0;
 Ykeq *Vt = 0;
 YRAB *Vmsg = 0;
 Tr t0 = {NULL,0,-1};
 YkxB *t1 = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=855000;
 Vitem = YI6R(NULL);
 sf.pos=855001;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=855002;
 if ((Vt->Vtype != 12))
 {
  sf.pos=855003;
  YDli(((Tc*)&YmWM), Vt->VstartPos, 0);
 }
 else
 {
  sf.pos=855004;
  Vitem->Vname = Vt->Vvalue;
  sf.pos=855005;
  Vt = YVoF((YuI4 *)Ain);
  sf.pos=855006;
  if ((Vt->Vtype != 21))
  {
   sf.pos=855007;
   YDli(((Tc*)&YlMg), Vt->VstartPos, 0);
  }
  else
  {
   sf.pos=855008;
   while (1)
   {
    sf.pos=855009;
    Vt = YVoF((YuI4 *)Ain);
    sf.pos=855010;
    if ((Vt->Vtype == 22))
    {
     rt = 2;
     goto YsRb;
    }
    sf.pos=855011;
    if (YtEy(Vt))
    {
     rt = 2;
     goto YsRb;
    }
    sf.pos=855012;
    switch (Vt->Vtype)
    {
     case 5:
     case 6:
     case 7:
     {
      sf.pos=855013;
      ZLap((Tl*)Vitem->Vfields, (Tz)(void*)YFuL(Vt, Ain));
       break;
     }
     case 2:
     {
      sf.pos=855015;
      Vmsg = ((YRAB *)Znio(2, 855014, (YOrf(Ain))));
      sf.pos=855016;
      Vmsg->Vparent = *Znao(&t0, Vitem, YRAB__Ytv2_imt, 0);
      sf.pos=855017;
      ZLapIobj((Tl*)Vitem->Vitems, *Znao(&t0, Vmsg, YRAB__YuXI_imt, 2));
       break;
     }
     case 3:
     {
      sf.pos=855018;
      ZLapIobj((Tl*)Vitem->Vitems, YCm2(Ain));
       break;
     }
     case 4:
     {
      sf.pos=855019;
      YNVJ((YRAB *)Vitem, YDgP(Ain));
       break;
     }
    default:
     {
      sf.pos=855020;
      YDli(ZcS(((Tc*)&Y8wy), Vt->Vvalue), (t1 = Vt->VstartPos), 0);
       break;
     }
    }
YsRb:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=855021;
   }
  }
  sf.pos=855022;
  YbaL((YRAB *)Vitem);
 }
 sf.pos=855023;
 r = *Znao(&t0, Vitem, YRAB__YuXI_imt, 2);
 topFrame = sf.prev;
 return r;
}
Y0uC *YFuL(Ykeq *Atoken, YuI4 *Ain) { /* MParseProto.parseField */
 Zsf sf={0,topFrame};
 Y0uC *r = 0;
 Y0uC *Vfield = 0;
 Ykeq *Vt = 0;
 topFrame = &sf;
 sf.pos=5226900;
 Vfield = Za(sizeof(Y0uC));
 sf.pos=5226901;
 Vfield->Vpos = Atoken->VstartPos;
 sf.pos=5226902;
 switch (Atoken->Vtype)
 {
  case 5:
  {
   sf.pos=5226903;
   Vfield->Vrequired = 1;
    break;
  }
  case 7:
  {
   sf.pos=5226904;
   Vfield->Vrepeated = 1;
    break;
  }
 }
 sf.pos=5226905;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=5226906;
 if ((Vt->Vtype != 12))
 {
  sf.pos=5226907;
  YDli(((Tc*)&Yhu6), Vt->VstartPos, 0);
 }
 else
 {
  sf.pos=5226908;
  Vfield->Vtype = YKJX(Vt->Vvalue);
  sf.pos=5226909;
  Vfield->VtypeName = Vt->Vvalue;
 }
 sf.pos=5226910;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=5226911;
 if ((Vt->Vtype != 12))
 {
  sf.pos=5226912;
  YDli(((Tc*)&Yoyn), Vt->VstartPos, 0);
 }
 else
 {
  sf.pos=5226913;
  Vfield->Vname = Vt->Vvalue;
  sf.pos=5226914;
  if (ZstringStartsWith(Vfield->Vname, ((Tc*)&YKIS), 0))
  {
   sf.pos=5226915;
   YDli(((Tc*)&Ye1M), Vt->VstartPos, 0);
  }
 }
 sf.pos=5226916;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=5226917;
 if ((Vt->Vtype != 18))
 {
  sf.pos=5226918;
  YDli(((Tc*)&YHNV), Vt->VstartPos, 0);
 }
 sf.pos=5226919;
 Vfield->Vnr = YeT_(Ain);
 sf.pos=5226920;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=5226921;
 if ((Vt->Vtype == 23))
 {
  sf.pos=5226922;
  Vt = YVoF((YuI4 *)Ain);
  sf.pos=5226923;
  if ((Vt->Vtype != 8))
  {
   sf.pos=5226924;
   YDli(((Tc*)&YG5z), Vt->VstartPos, 0);
  }
  sf.pos=5226925;
  Vt = YVoF((YuI4 *)Ain);
  sf.pos=5226926;
  if ((Vt->Vtype != 18))
  {
   sf.pos=5226927;
   YDli(((Tc*)&YHNV), Vt->VstartPos, 0);
  }
  sf.pos=5226928;
  Vt = YVoF((YuI4 *)Ain);
  sf.pos=5226929;
  if ((Vt->Vtype != 12))
  {
   sf.pos=5226930;
   YDli(((Tc*)&Y8XM), Vt->VstartPos, 0);
  }
  else
  {
   sf.pos=5226931;
   Vfield->Vdefault = Vt->Vvalue;
   sf.pos=5226932;
   if ((Vfield->Vtype == 1))
   {
    sf.pos=5226933;
    Vfield->Vdefault = ZstringToUpper(Vfield->Vdefault);
    sf.pos=5226934;
    if (((ZstringCmp(Vfield->Vdefault, ((Tc*)&Y2cy)) != 0) && (ZstringCmp(Vfield->Vdefault, ((Tc*)&YHoE)) != 0)))
    {
     sf.pos=5226935;
     YDli(((Tc*)&YItG), Vt->VstartPos, 0);
    }
   }
  }
  sf.pos=5226936;
  Vt = YVoF((YuI4 *)Ain);
  sf.pos=5226937;
  if ((Vt->Vtype != 24))
  {
   sf.pos=5226938;
   YDli(((Tc*)&YSLg), Vt->VstartPos, 0);
  }
  else
  {
   sf.pos=5226939;
   Vt = YVoF((YuI4 *)Ain);
  }
 }
 sf.pos=5226940;
 Y4Sj((YuI4 *)Ain, Vt);
 sf.pos=5226941;
 YYYx(Ain);
 sf.pos=5226942;
 r = Vfield;
 topFrame = sf.prev;
 return r;
}
Tr YCm2(YuI4 *Ain) { /* MParseProto.parseEnum */
 Zsf sf={0,topFrame};
 Tr r = {NULL};
 Y2Kp *Vitem = 0;
 Ykeq *Vt = 0;
 Tc *Vname = NULL;
 Tr t0 = {NULL,0,-1};
 int rt = 0;
 topFrame = &sf;
 sf.pos=5141000;
 Vitem = YIur(NULL);
 sf.pos=5141001;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=5141002;
 if ((Vt->Vtype != 12))
 {
  sf.pos=5141003;
  YDli(((Tc*)&YyCj), Vt->VstartPos, 0);
 }
 else
 {
  sf.pos=5141004;
  Vitem->Vname = Vt->Vvalue;
  sf.pos=5141005;
  Vt = YVoF((YuI4 *)Ain);
  sf.pos=5141006;
  if ((Vt->Vtype != 21))
  {
   sf.pos=5141007;
   YDli(((Tc*)&YlMg), Vt->VstartPos, 0);
  }
  else
  {
   sf.pos=5141008;
   while (1)
   {
    Ti Vnr;
    sf.pos=5141009;
    Vt = YVoF((YuI4 *)Ain);
    sf.pos=5141010;
    if ((Vt->Vtype == 22))
    {
     rt = 2;
     goto YHDg;
    }
    sf.pos=5141011;
    if (YtEy(Vt))
    {
     rt = 2;
     goto YHDg;
    }
    sf.pos=5141012;
    if ((Vt->Vtype != 12))
    {
     sf.pos=5141013;
     YDli(((Tc*)&YTWr), Vt->VstartPos, 0);
    }
    sf.pos=5141014;
    Vname = Vt->Vvalue;
    sf.pos=5141015;
    Vt = YVoF((YuI4 *)Ain);
    sf.pos=5141016;
    if ((Vt->Vtype != 18))
    {
     sf.pos=5141017;
     YDli(((Tc*)&YHNV), Vt->VstartPos, 0);
    }
    sf.pos=5141018;
    Vnr = YeT_(Ain);
    sf.pos=5141019;
    Y_Nc((Y2Kp *)Vitem, Vname, Vnr, Vt->VstartPos);
    sf.pos=5141020;
    YYYx(Ain);
YHDg:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=5141021;
   }
   sf.pos=5141022;
   YXXO((Y2Kp *)Vitem);
  }
 }
 sf.pos=5141023;
 r = *Znao(&t0, Vitem, Y2Kp__YuXI_imt, 0);
 topFrame = sf.prev;
 return r;
}
void YYYx(YuI4 *Ain) { /* MParseProto.checkSemiColon */
 Zsf sf={0,topFrame};
 Ykeq *Vt = 0;
 topFrame = &sf;
 sf.pos=3576100;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=3576101;
 if ((Vt->Vtype != 17))
 {
  sf.pos=3576102;
  YDli(((Tc*)&Ybzg), Vt->VstartPos, 0);
  sf.pos=3576103;
  Y4Sj((YuI4 *)Ain, Vt);
 }
 topFrame = sf.prev;
 return;
}
Tb YtEy(Ykeq *At) { /* MParseProto.checkEof */
 Zsf sf={0,topFrame};
 Tb r = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=507000;
 if ((At->Vtype == 25))
 {
  sf.pos=507001;
  YDli(((Tc*)&YF0E), At->VstartPos, 0);
  sf.pos=507002;
  r = 1;
  rt = 1;
  goto YDJj;
 }
 sf.pos=507003;
 r = 0;
YDJj:
 topFrame = sf.prev;
 return r;
}
Ti YeT_(YuI4 *Ain) { /* MParseProto.parseNumber */
 Zsf sf={0,topFrame};
 Ti r = 0;
 Ykeq *Vt = 0;
 topFrame = &sf;
 sf.pos=6651000;
 Vt = YVoF((YuI4 *)Ain);
 sf.pos=6651001;
 if (((Vt->Vtype != 12) || !((((ZstringGetChar(Vt->Vvalue, 0) >= 48) && (ZstringGetChar(Vt->Vvalue, 0) <= 57))))))
 {
  sf.pos=6651002;
  YDli(((Tc*)&YNZb), Vt->VstartPos, 0);
 }
 sf.pos=6651003;
 r = ZstringToInt(Vt->Vvalue, 1, 0);
 topFrame = sf.prev;
 return r;
}
void YUys(YP_l *A0, Tr A1) {
   YhB6(A0,A1);
}
int JParseProto(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf={0,topFrame};
  topFrame = &sf;
  round_done = round;
 done &= JMessageItem(round);
 done &= JPTokenInput(round);
  if (round == 2001) {
  }
  topFrame = sf.prev;
 }
 return done;
}
/* ParseProto done */
/* including WriteZimbu bodies */
void YCCA(YP_l *Apfile, Tc *AinFileName, Tc *AoutFileName) { /* MWriteZimbu.write */
 Ti Vi;
 Zsf sf={0,topFrame};
 Yw8L *Vout = NULL;
 Tc *Vmname = NULL;
 Tl *Zf1 = NULL;
 Tr Vitem = {NULL,0,-1};
 YRAB *Vmsg = 0;
 Y2Kp *Venum = 0;
 YNW5 *Vservice = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 topFrame = &sf;
 sf.pos=4426000;
 Vout = YiBk(AoutFileName, 1);
 sf.pos=4426001;
 if ((Vout == (void *)NULL))
 {
  sf.pos=4426002;
  Yl0k(ZcS(((Tc*)&Y32K), AoutFileName));
  sf.pos=4426003;
  Zexit(NULL, 1);
 }
 sf.pos=4426004;
 Yw8L__YRt7((Yw8L *)Vout, ZcS(((Tc*)&Y_ZB), AinFileName));
 sf.pos=4426005;
 Yw8L__YRt7g((Yw8L *)Vout);
 sf.pos=4426006;
 Yw8L__YRt7((Yw8L *)Vout, ((Tc*)&YRCg));
 sf.pos=4426007;
 Yw8L__YRt7((Yw8L *)Vout, ((Tc*)&Y0jn));
 sf.pos=4426008;
 Yw8L__YRt7g((Yw8L *)Vout);
 sf.pos=4426009;
 if ((Apfile->Vpackage == NULL))
 {
  Ti Vi;
  sf.pos=4426010;
  Vmname = AinFileName;
  sf.pos=4426011;
  Vi = ZstringFindLastChar(Vmname, 47, 0);
  sf.pos=4426012;
  if ((Vi >= 0))
  {
   sf.pos=4426013;
   Vmname = YuAL(Vmname, (Vi + 1));
  }
 }
 else
 {
  sf.pos=4426014;
  Vmname = Apfile->Vpackage;
 }
 sf.pos=4426015;
 Vi = ZstringFindLastChar(Vmname, 46, 0);
 sf.pos=4426016;
 if ((Vi >= 0))
 {
  sf.pos=4426017;
  Vmname = YuALa(Vmname, 0, (Vi - 1));
 }
 sf.pos=4426018;
 Vi = ZstringFindLastChar(Vmname, 46, 0);
 sf.pos=4426019;
 if ((Vi >= 0))
 {
  sf.pos=4426020;
  Vmname = YuAL(Vmname, (Vi + 1));
 }
 sf.pos=4426021;
 Vmname = ZcS((t1 = ZstringToUpper(YuALa(Vmname, 0, 0))), (t0 = YuAL(Vmname, 1)));
 sf.pos=4426022;
 Yw8L__YRt7((Yw8L *)Vout, ZcS3(((Tc*)&YoyN), Vmname, ((Tc*)&Y7Qg)));
 sf.pos=4426023;
 {
  Tfl Zf1i;
  Zf1 = Apfile->VitemList;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vitem;
  Zf1i.i = 0;
  for (; ZforListIobjCont(&Zf1i); ) {
  sf.pos=4426024;
  if ((Vitem).type == 2)
  {
   sf.pos=4426026;
   Vmsg = ((YRAB *)Znio(2, 4426025, (Vitem)));
   sf.pos=4426027;
   YxvA(Vmsg, Vout, ((Tc*)&YZY));
  }
  else {
  sf.pos=4426028;
  if ((Vitem).type == 0)
  {
   sf.pos=4426030;
   Venum = ((Y2Kp *)Znio(0, 4426029, (Vitem)));
   sf.pos=4426031;
   Y8RG(Venum, Vout, ((Tc*)&YZY));
  }
  else {
  sf.pos=4426032;
  if ((Vitem).type == 4)
  {
   sf.pos=4426034;
   Vservice = ((YNW5 *)Znio(4, 4426033, (Vitem)));
   sf.pos=4426035;
   Yk4Q(Vservice, Vout, ((Tc*)&YZY));
  }
  else
  {
   sf.pos=4426036;
   Y2oO(((Tc*)&YoBQ), NULL, 0);
  }
  }}
  sf.pos=4426037;
  }
 }
 sf.pos=4426038;
 Yw8L__YRt7((Yw8L *)Vout, ((Tc*)&Y9a));
 sf.pos=4426039;
 YrF8((Yw8L *)Vout);
 topFrame = sf.prev;
 return;
}
void YxvA(YRAB *Amsg, Yw8L *Aout, Tc *Aindent) { /* MWriteZimbu.writeClass */
 Zsf sf={0,topFrame};
 Tl *VhasNames = NULL;
 Tl *VclearLines = NULL;
 Tl *VvalidItems = NULL;
 Tl *VmsgFields = NULL;
 Tl *VenumFields = NULL;
 Tl *VintFields = NULL;
 Tl *Vint32Fields = NULL;
 Tl *VfloatFields = NULL;
 Tl *VdoubleFields = NULL;
 Tl *VboolFields = NULL;
 Tl *VstringFields = NULL;
 Tl *VbyteStringFields = NULL;
 Tl *VrepeatedFields = NULL;
 Tl *VnotRepeatedFields = NULL;
 Tc *Vindent2 = NULL;
 Tc *Vindent4 = NULL;
 Tc *Vindent6 = NULL;
 Tl *Zf1 = NULL;
 Tr Vitem = {NULL,0,-1};
 YRAB *Vnmsg = 0;
 Tl *Zf11 = NULL;
 Y0uC *Vf = 0;
 Tc *VtypeName = NULL;
 Tc *VvarTypeName = NULL;
 Tc *VinitVal = NULL;
 Tc *VdefaultVal = NULL;
 Tr Vitem1 = {NULL,0,-1};
 Tc *VhasName = NULL;
 Tl *Zf12 = NULL;
 Tc *Vl = NULL;
 Tl *Zf13 = NULL;
 Tc *Vh = NULL;
 Tc *Vsep = NULL;
 Tl *Zf2 = NULL;
 Tc *Vi = NULL;
 Tl *Zf14 = NULL;
 Tc *Vreader = NULL;
 Tl *Zf15 = NULL;
 Tr Vitem2 = {NULL,0,-1};
 Tc *t0 = NULL;
 YkxB *t1 = 0;
 Tc *t2 = NULL;
 Tl *t3 = NULL;
 topFrame = &sf;
 sf.pos=180200;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YB_i), (t0 = Amsg->Vname), ((Tc*)&YxMq), (Tc*)1));
 sf.pos=180201;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YXgq)));
 sf.pos=180202;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
 sf.pos=180203;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Yow3)));
 sf.pos=180204;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YlWb), (t0 = Amsg->Vname), ((Tc*)&YI), (Tc*)1));
 sf.pos=180205;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
 sf.pos=180206;
 VhasNames = ZnewList((Tt*)&string__T, 0);
 sf.pos=180207;
 VclearLines = ZnewList((Tt*)&string__T, 0);
 sf.pos=180208;
 VvalidItems = ZnewList((Tt*)&string__T, 0);
 sf.pos=180209;
 VmsgFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180210;
 VenumFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180211;
 VintFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180212;
 Vint32Fields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180213;
 VfloatFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180214;
 VdoubleFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180215;
 VboolFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180216;
 VstringFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180217;
 VbyteStringFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180218;
 VrepeatedFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180219;
 VnotRepeatedFields = ZnewList((Tt*)&Y0uC__T, 0);
 sf.pos=180220;
 Vindent2 = ZcS(Aindent, ((Tc*)&YZY));
 sf.pos=180221;
 Vindent4 = ZcS(Vindent2, ((Tc*)&YZY));
 sf.pos=180222;
 Vindent6 = ZcS(Vindent4, ((Tc*)&YZY));
 sf.pos=180223;
 {
  Tfl Zf1i;
  Zf1 = Amsg->Vitems;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vitem;
  Zf1i.i = 0;
  for (; ZforListIobjCont(&Zf1i); ) {
  sf.pos=180224;
  if ((Vitem).type == 2)
  {
   sf.pos=180226;
   Vnmsg = ((YRAB *)Znio(2, 180225, (Vitem)));
   sf.pos=180227;
   YxvA(Vnmsg, Aout, ZcS(Aindent, ((Tc*)&YZY)));
  }
  else {
  sf.pos=180228;
  if ((Vitem).type == 0)
  {
  }
  else
  {
   sf.pos=180229;
   Y2oO(((Tc*)&YoBQ), NULL, 0);
  }
  }
  sf.pos=180230;
  }
 }
 sf.pos=180231;
 {
  Tfl Zf11i;
  Zf11 = Amsg->Vfields;
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vf;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  VtypeName = NULL;
  VvarTypeName = NULL;
  VinitVal = NULL;
  VdefaultVal = NULL;
  sf.pos=180232;
  switch (Vf->Vtype)
  {
   case 0:
   {
    sf.pos=180233;
    VtypeName = Vf->VtypeName;
    sf.pos=180234;
    Vitem1 = YBZe((YRAB *)Amsg, Vf->VtypeName);
    sf.pos=180235;
    if ((((Vitem1).ptr) == (void *)NULL))
    {
     sf.pos=180236;
     YDli(ZcS(((Tc*)&Ysxb), Vf->VtypeName), (t1 = Vf->Vpos), 0);
     sf.pos=180237;
     VinitVal = ((Tc*)&Ya);
     sf.pos=180238;
     VdefaultVal = ((Tc*)&Ya);
    }
    else {
    sf.pos=180239;
    if ((Vitem1).type == 2)
    {
     sf.pos=180240;
     Vf->Vtype = 12;
     sf.pos=180241;
     VinitVal = ((Tc*)&ZNilString);
     sf.pos=180242;
     VdefaultVal = Vf->Vdefault;
     sf.pos=180243;
     ZLap((Tl*)VmsgFields, (Tz)(void*)Vf);
    }
    else
    {
     sf.pos=180244;
     Vf->Vtype = 3;
     sf.pos=180245;
     VinitVal = ZcS(Vf->VtypeName, ((Tc*)&YW8X));
     sf.pos=180246;
     if ((Vf->Vdefault != NULL))
     {
      sf.pos=180247;
      VdefaultVal = ZcS3(Vf->VtypeName, ((Tc*)&Ywla), (t0 = Vf->Vdefault));
     }
     sf.pos=180248;
     ZLap((Tl*)VenumFields, (Tz)(void*)Vf);
    }
    }
     break;
   }
   case 17:
   {
    sf.pos=180249;
    VtypeName = ((Tc*)&YanE);
    sf.pos=180250;
    VinitVal = ((Tc*)&ZNilString);
    sf.pos=180251;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180252;
    ZLap((Tl*)VstringFields, (Tz)(void*)Vf);
     break;
   }
   case 2:
   {
    sf.pos=180253;
    VtypeName = ((Tc*)&YP0m);
    sf.pos=180254;
    VinitVal = ((Tc*)&ZNilString);
    sf.pos=180255;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180256;
    ZLap((Tl*)VbyteStringFields, (Tz)(void*)Vf);
     break;
   }
   case 9:
   case 11:
   {
    sf.pos=180257;
    VtypeName = ((Tc*)&Y1Qt);
    sf.pos=180258;
    VinitVal = ((Tc*)&YW);
    sf.pos=180259;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180260;
    ZLap((Tl*)VintFields, (Tz)(void*)Vf);
     break;
   }
   case 10:
   {
    sf.pos=180261;
    VtypeName = ((Tc*)&YrQi);
    sf.pos=180262;
    VinitVal = ((Tc*)&YW);
    sf.pos=180263;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180264;
    ZLap((Tl*)Vint32Fields, (Tz)(void*)Vf);
     break;
   }
   case 18:
   {
    sf.pos=180265;
    VtypeName = ((Tc*)&YDFy);
    sf.pos=180266;
    VinitVal = ((Tc*)&YW);
    sf.pos=180267;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180268;
    ZLap((Tl*)VintFields, (Tz)(void*)Vf);
     break;
   }
   case 19:
   {
    sf.pos=180269;
    VtypeName = ((Tc*)&YNmG);
    sf.pos=180270;
    VinitVal = ((Tc*)&YW);
    sf.pos=180271;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180272;
    ZLap((Tl*)VintFields, (Tz)(void*)Vf);
     break;
   }
   case 6:
   {
    sf.pos=180273;
    VtypeName = ((Tc*)&YdsC);
    sf.pos=180274;
    VinitVal = ((Tc*)&YW);
    sf.pos=180275;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180276;
    ZLap((Tl*)VfloatFields, (Tz)(void*)Vf);
     break;
   }
   case 7:
   {
    sf.pos=180277;
    VtypeName = ((Tc*)&Yt7n);
    sf.pos=180278;
    VinitVal = ((Tc*)&YW);
    sf.pos=180279;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180280;
    ZLap((Tl*)VdoubleFields, (Tz)(void*)Vf);
     break;
   }
   case 1:
   {
    sf.pos=180281;
    VtypeName = ((Tc*)&YtPw);
    sf.pos=180282;
    VvarTypeName = ((Vf->Vrepeated) ? (((Tc*)&YtPw)) : (((Tc*)&Y1Qt)));
    sf.pos=180283;
    VinitVal = ((Tc*)&YW);
    sf.pos=180284;
    VdefaultVal = Vf->Vdefault;
    sf.pos=180285;
    ZLap((Tl*)VboolFields, (Tz)(void*)Vf);
     break;
   }
  default:
   {
    sf.pos=180286;
    YDli(ZcS(((Tc*)&Yl1o), Zenum2string(MProto__EType, Vf->Vtype)), NULL, 0);
     break;
   }
  }
  sf.pos=180287;
  if ((VvarTypeName == NULL))
  {
   sf.pos=180288;
   VvarTypeName = VtypeName;
  }
  sf.pos=180289;
  if (Vf->Vrepeated)
  {
   sf.pos=180290;
   ZLap((Tl*)VrepeatedFields, (Tz)(void*)Vf);
   sf.pos=180291;
   Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent2, ((Tc*)&Y9Ra), VvarTypeName, ((Tc*)&Y4Ja), (t0 = YULH((Y0uC *)Vf))));
   sf.pos=180292;
   VinitVal = ((Tc*)&ZNilString);
   sf.pos=180293;
   YsmR(Amsg->Vname, Vf, VtypeName, VdefaultVal, Vindent2, Aout);
  }
  else
  {
   sf.pos=180294;
   ZLap((Tl*)VnotRepeatedFields, (Tz)(void*)Vf);
   sf.pos=180295;
   Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent2, VvarTypeName, ((Tc*)&YG), (t0 = YULH((Y0uC *)Vf)), (Tc*)1));
   sf.pos=180296;
   VhasName = YFlx((Y0uC *)Vf);
   sf.pos=180297;
   if ((VhasName != NULL))
   {
    sf.pos=180298;
    ZLap((Tl*)VhasNames, (Tz)(void*)VhasName);
    sf.pos=180299;
    Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&Y8Y5), VhasName));
   }
   sf.pos=180300;
   Y1M2(Amsg->Vname, Vf, VtypeName, VinitVal, VdefaultVal, Vindent2, Aout);
  }
  sf.pos=180301;
  ZLap((Tl*)VclearLines, (Tz)(void*)ZcS3(YULH((Y0uC *)Vf), ((Tc*)&YWXt), VinitVal));
  sf.pos=180302;
  if (Vf->Vrequired)
  {
   sf.pos=180303;
   ZLap((Tl*)VvalidItems, (Tz)(void*)ZcS3(((Tc*)&YG4L), YqGL((Y0uC *)Vf), ((Tc*)&YXaa)));
  }
  sf.pos=180304;
  }
 }
 sf.pos=180305;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&YJaV)));
 sf.pos=180306;
 {
  Tfl Zf12i;
  Zf12 = VclearLines;
  Zf12i.l = Zf12;
  Zf12i.valp = (void*)&Vl;
  Zf12i.i = 0;
  for (; ZforListPtrCont(&Zf12i); ) {
  sf.pos=180307;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, Vl));
  sf.pos=180308;
  }
 }
 sf.pos=180309;
 {
  Tfl Zf13i;
  Zf13 = VhasNames;
  Zf13i.l = Zf13;
  Zf13i.valp = (void*)&Vh;
  Zf13i.i = 0;
  for (; ZforListPtrCont(&Zf13i); ) {
  sf.pos=180310;
  Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent4, Vh, ((Tc*)&YRRN)));
  sf.pos=180311;
  }
 }
 sf.pos=180312;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180313;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Yzw4)));
 sf.pos=180314;
 YwHoa((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YZ35)));
 sf.pos=180315;
 if ((ZListSize(VvalidItems) == 0))
 {
  sf.pos=180316;
  YwHoa((Yw8L *)Aout, ((Tc*)&YHoE));
 }
 else
 {
  sf.pos=180317;
  Vsep = ((Tc*)&Ya);
  sf.pos=180318;
  {
   Tfl Zf2i;
   Zf2 = VvalidItems;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vi;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=180319;
   YwHoa((Yw8L *)Aout, ZcS(Vsep, Vi));
   sf.pos=180320;
   Vsep = ((Tc*)&Y4zz);
   sf.pos=180321;
   }
  }
 }
 sf.pos=180322;
 Yw8L__YRt7g((Yw8L *)Aout);
 sf.pos=180323;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180324;
 if ((ZListSize(VenumFields) > 0))
 {
  sf.pos=180325;
  YHzx(((Tc*)&Y89Q), ((Tc*)&Y1Qt), VenumFields, ((Tc*)&YW), Vindent2, Aout);
 }
 sf.pos=180326;
 if ((ZListSize(VintFields) > 0))
 {
  sf.pos=180327;
  YHzx(((Tc*)&Y1Qt), ((Tc*)&Y1Qt), VintFields, ((Tc*)&YW), Vindent2, Aout);
 }
 sf.pos=180328;
 if ((ZListSize(Vint32Fields) > 0))
 {
  sf.pos=180329;
  YHzx(((Tc*)&YrQi), ((Tc*)&YrQi), Vint32Fields, ((Tc*)&YW), Vindent2, Aout);
 }
 sf.pos=180330;
 if ((ZListSize(VfloatFields) > 0))
 {
  sf.pos=180331;
  YHzx(((Tc*)&Yt7n), ((Tc*)&YdsC), VfloatFields, ((Tc*)&YW), Vindent2, Aout);
 }
 sf.pos=180332;
 if ((ZListSize(VdoubleFields) > 0))
 {
  sf.pos=180333;
  YHzx(((Tc*)&Ygep), ((Tc*)&Yt7n), VdoubleFields, ((Tc*)&YW), Vindent2, Aout);
 }
 sf.pos=180334;
 if ((ZListSize(VboolFields) > 0))
 {
  sf.pos=180335;
  YHzx(((Tc*)&YtPw), ((Tc*)&YtPw), VboolFields, ((Tc*)&Y2cy), Vindent2, Aout);
 }
 sf.pos=180336;
 if ((ZListSize(VstringFields) > 0))
 {
  sf.pos=180337;
  YHzx(((Tc*)&YanE), ((Tc*)&YanE), VstringFields, ((Tc*)&Yd1), Vindent2, Aout);
 }
 sf.pos=180338;
 if ((ZListSize(VbyteStringFields) > 0))
 {
  sf.pos=180339;
  YHzx(((Tc*)&YGxv), ((Tc*)&YP0m), VbyteStringFields, ((Tc*)&Yd1), Vindent2, Aout);
 }
 sf.pos=180340;
 YwAg(VmsgFields, Vindent2, Aout);
 sf.pos=180341;
 if ((ZListSize(VnotRepeatedFields) > 0))
 {
  sf.pos=180342;
  YYCV(VnotRepeatedFields, Vindent2, Aout);
 }
 sf.pos=180343;
 if ((ZListSize(VrepeatedFields) > 0))
 {
  sf.pos=180344;
  Ycma(VrepeatedFields, Vindent2, Aout);
 }
 sf.pos=180345;
 Yg8t(Amsg, Vindent2, Aout);
 sf.pos=180346;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&YcBy)));
 sf.pos=180347;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y1Dj)));
 sf.pos=180348;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180349;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&YyUd), (t0 = Amsg->Vname)));
 sf.pos=180350;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YKEm)));
 sf.pos=180351;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y_Lu)));
 sf.pos=180352;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180353;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&Y4Tv), (t0 = Amsg->Vname)));
 sf.pos=180354;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YYQ8)));
 sf.pos=180355;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y_Lu)));
 sf.pos=180356;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180357;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&YgCV), (t0 = Amsg->Vname)));
 sf.pos=180358;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Yew9)));
 sf.pos=180359;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y_Lu)));
 sf.pos=180360;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180361;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&YK2S), (t0 = Amsg->Vname)));
 sf.pos=180362;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y0Sk)));
 sf.pos=180363;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y_Lu)));
 sf.pos=180364;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180365;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&YwRP), (t0 = Amsg->Vname)));
 sf.pos=180366;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y4vI)));
 sf.pos=180367;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y_Lu)));
 sf.pos=180368;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180369;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&Yk1Y), (t0 = Amsg->Vname)));
 sf.pos=180370;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YwU4)));
 sf.pos=180371;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y_Lu)));
 sf.pos=180372;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180373;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&Yevx), (t0 = Amsg->Vname)));
 sf.pos=180374;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YlR1)));
 sf.pos=180375;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y_Lu)));
 sf.pos=180376;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180377;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&YuOB)));
 sf.pos=180378;
 YMWy(Amsg->Vfields, Vindent4, Aout);
 sf.pos=180379;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YaU5)));
 sf.pos=180380;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&YZ35), (t0 = Amsg->Vname), ((Tc*)&YyLL), (Tc*)1));
 sf.pos=180381;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y9a)));
 sf.pos=180382;
 {
  Tc *Vtype;
  Tfl Zf14i;
  Zf14 = (t3 = ZnewList((Tt*)&string__T, 3), ZLap((Tl*)t3, (Tz)(void*)((Tc*)&Yjby)), ZLap((Tl*)t3, (Tz)(void*)((Tc*)&Y27q)), ZLap((Tl*)t3, (Tz)(void*)((Tc*)&Yz0N)));
  Zf14i.l = Zf14;
  Zf14i.valp = (void*)&Vtype;
  Zf14i.i = 0;
  for (; ZforListPtrCont(&Zf14i); ) {
  sf.pos=180383;
  YwHoa((Yw8L *)Aout, ZcS3(Vindent4, ((Tc*)&Yts2), Vtype));
  Vreader = NULL;
  sf.pos=180384;
  if ((ZstringCmp(Vtype, ((Tc*)&Yjby)) == 0))
  {
   sf.pos=180385;
   Vreader = ((Tc*)&YIIp);
  }
  else
  {
   sf.pos=180386;
   Vreader = ((Tc*)&YDa5);
  }
  sf.pos=180387;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(((Tc*)&YO), Vreader, ((Tc*)&YYDR), (t0 = Amsg->Vname), (Tc*)1));
  sf.pos=180388;
  YwHoa((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&YZ35), (t0 = Amsg->Vname), ((Tc*)&Yvx0), Vtype));
  sf.pos=180389;
  if ((ZstringCmp(Vtype, ((Tc*)&Yz0N)) != 0))
  {
   sf.pos=180390;
   Yw8L__YRt7((Yw8L *)Aout, ((Tc*)&YPYp));
  }
  else
  {
   sf.pos=180391;
   Yw8L__YRt7((Yw8L *)Aout, ((Tc*)&Yqfe));
  }
  sf.pos=180392;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y9a)));
  sf.pos=180393;
  Yw8L__YRt7((Yw8L *)Aout, ZcS8(Vindent4, ((Tc*)&YKhU), Vtype, ((Tc*)&YO), Vreader, ((Tc*)&Y52_), (Tc*)1, (Tc*)1));
  sf.pos=180394;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&YGO0), Vtype, ((Tc*)&Yqfe), (Tc*)1));
  sf.pos=180395;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y9a)));
  sf.pos=180396;
  if ((ZstringCmp(Vtype, ((Tc*)&Y27q)) != 0))
  {
   sf.pos=180397;
   Yw8L__YRt7((Yw8L *)Aout, ZcS8(Vindent4, ((Tc*)&YKhU), Vtype, ((Tc*)&YZix), Vreader, ((Tc*)&Y52_), (Tc*)1, (Tc*)1));
   sf.pos=180398;
   Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&YGO0), Vtype, ((Tc*)&Yvyf), (Tc*)1));
   sf.pos=180399;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y9a)));
  }
  sf.pos=180400;
  }
 }
 sf.pos=180401;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent4, ((Tc*)&YD3Q), (t0 = Amsg->Vname)));
 sf.pos=180402;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&YZ35), (t0 = Amsg->Vname), ((Tc*)&YNfH), (Tc*)1));
 sf.pos=180403;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y9a)));
 sf.pos=180404;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent4, ((Tc*)&Y8OQ), (t0 = Amsg->Vname)));
 sf.pos=180405;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&YZ35), (t0 = Amsg->Vname), ((Tc*)&Y55l), (Tc*)1));
 sf.pos=180406;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y9a)));
 sf.pos=180407;
 {
  Tfl Zf15i;
  Zf15 = Amsg->Vitems;
  Zf15i.l = Zf15;
  Zf15i.valp = (void*)&Vitem2;
  Zf15i.i = 0;
  for (; ZforListIobjCont(&Zf15i); ) {
  sf.pos=180408;
  if ((Vitem2).type == 0)
  {
   sf.pos=180409;
   Y8RG(((Y2Kp *)Znio(0, 180411, (Vitem2))), Aout, Vindent4);
  }
  sf.pos=180412;
  }
 }
 sf.pos=180413;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
 sf.pos=180414;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 topFrame = sf.prev;
 return;
}
void YHzx(Tc *Atype, Tc *AretType, Tl *Afields, Tc *Adefault, Tc *Aindent, Yw8L *Aout) { /* MWriteZimbu.writeGetSet */
 Tb VhasRep;
 Tb VhasNotRep;
 Tb VdidSet;
 Zsf sf={0,topFrame};
 Tl *Zf1 = NULL;
 Tl *Zf3 = NULL;
 Y0uC *Vf = 0;
 Tc *VmemberName = NULL;
 Tl *Zf4 = NULL;
 Y0uC *Vf1 = 0;
 Tc *VmemberName1 = NULL;
 Tl *Zf41 = NULL;
 Y0uC *Vf2 = 0;
 Tc *VmemberName2 = NULL;
 Tc *VhasName = NULL;
 Tl *Zf5 = NULL;
 Y0uC *Vf3 = 0;
 Tc *VmemberName3 = NULL;
 Tl *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 topFrame = &sf;
 sf.pos=5940800;
 VhasRep = YTU9(Afields);
 sf.pos=5940801;
 VhasNotRep = YADt(Afields);
 VdidSet = 0;
 sf.pos=5940802;
 {
  Ti Vrepeated;
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&bool__T, 2), ZLap((Tl*)t0, (Tz)(Ti)0), ZLap((Tl*)t0, (Tz)(Ti)1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vrepeated;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=5940803;
  if ((((!(Vrepeated) && VhasNotRep)) || ((Vrepeated && VhasRep))))
  {
   sf.pos=5940804;
   YwHoa((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YMja), Atype, ((Tc*)&YQBH), (Tc*)1));
   sf.pos=5940805;
   if (Vrepeated)
   {
    sf.pos=5940806;
    YwHoa((Yw8L *)Aout, ((Tc*)&YNcD));
   }
   sf.pos=5940807;
   Yw8L__YRt7((Yw8L *)Aout, ZcS3(((Tc*)&Ypca), AretType, ((Tc*)&YYx8)));
   sf.pos=5940808;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y3Rg)));
   sf.pos=5940809;
   {
    Tfl Zf3i;
    Zf3 = Afields;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vf;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=5940810;
    if ((Vf->Vrepeated == Vrepeated))
    {
     sf.pos=5940811;
     YwHoa((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&Y4Qg), (t1 = Zint2string(Vf->Vnr)), ((Tc*)&YBII), (Tc*)1));
     sf.pos=5940812;
     VmemberName = YULH((Y0uC *)Vf);
     sf.pos=5940813;
     if (Vrepeated)
     {
      sf.pos=5940814;
      VmemberName =  ZcS(VmemberName, ((Tc*)&YxsN));
     }
     sf.pos=5940815;
     if ((ZstringCmp(Atype, ((Tc*)&Y89Q)) == 0))
     {
      sf.pos=5940816;
      Yw8L__YRt7((Yw8L *)Aout, ZcS5(((Tc*)&YbT7), Vf->VtypeName, ((Tc*)&Y14u), VmemberName, ((Tc*)&YEa)));
     }
     else {
     sf.pos=5940817;
     if (((ZstringCmp(Atype, ((Tc*)&YtPw)) == 0) && !(Vf->Vrepeated)))
     {
      sf.pos=5940818;
      Yw8L__YRt7((Yw8L *)Aout, ZcS(VmemberName, ((Tc*)&Y9Ud)));
     }
     else
     {
      sf.pos=5940819;
      Yw8L__YRt7((Yw8L *)Aout, VmemberName);
     }
     }
    }
    sf.pos=5940820;
    }
   }
   sf.pos=5940821;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
   sf.pos=5940822;
   Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&YKKn), Adefault));
   sf.pos=5940823;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
   sf.pos=5940824;
   if ((ZstringCmp(Atype, ((Tc*)&Y89Q)) == 0))
   {
    sf.pos=5940825;
    YwHoa((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YTzv)));
    sf.pos=5940826;
    if (Vrepeated)
    {
     sf.pos=5940827;
     YwHoa((Yw8L *)Aout, ((Tc*)&YNcD));
    }
    sf.pos=5940828;
    Yw8L__YRt7((Yw8L *)Aout, ((Tc*)&Y5Bw));
    sf.pos=5940829;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YBXc)));
    sf.pos=5940830;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y3Rg)));
    sf.pos=5940831;
    {
     Tfl Zf4i;
     Zf4 = Afields;
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Vf1;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=5940832;
     if ((Vf1->Vrepeated == Vrepeated))
     {
      sf.pos=5940833;
      VmemberName1 = YULH((Y0uC *)Vf1);
      sf.pos=5940834;
      if (Vrepeated)
      {
       sf.pos=5940835;
       VmemberName1 =  ZcS(VmemberName1, ((Tc*)&YxsN));
      }
      sf.pos=5940836;
      YwHoa((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&Y4Qg), (t1 = Zint2string(Vf1->Vnr)), ((Tc*)&YuV2), (Tc*)1));
      sf.pos=5940837;
      Yw8L__YRt7((Yw8L *)Aout, ZcS(VmemberName1, ((Tc*)&YgZi)));
     }
     sf.pos=5940838;
     }
    }
    sf.pos=5940839;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
    sf.pos=5940840;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YfaF)));
    sf.pos=5940841;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
   }
   sf.pos=5940842;
   if (!(VdidSet))
   {
    sf.pos=5940843;
    VdidSet = 1;
    sf.pos=5940844;
    YwHoa((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YmYN), Atype, ((Tc*)&Y5KZ), (Tc*)1));
    sf.pos=5940845;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(AretType, ((Tc*)&YmiC)));
    sf.pos=5940846;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y3Rg)));
    sf.pos=5940847;
    {
     Tfl Zf41i;
     Zf41 = Afields;
     Zf41i.l = Zf41;
     Zf41i.valp = (void*)&Vf2;
     Zf41i.i = 0;
     for (; ZforListPtrCont(&Zf41i); ) {
     sf.pos=5940848;
     VmemberName2 = YULH((Y0uC *)Vf2);
     sf.pos=5940849;
     YwHoa((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&Y4Qg), (t1 = Zint2string(Vf2->Vnr)), ((Tc*)&YgFa), (Tc*)1));
     sf.pos=5940850;
     if (Vf2->Vrepeated)
     {
      sf.pos=5940851;
      YwHoa((Yw8L *)Aout, ZcS3(((Tc*)&YO9t), YqGL((Y0uC *)Vf2), ((Tc*)&YO)));
     }
     else
     {
      sf.pos=5940852;
      YwHoa((Yw8L *)Aout, ZcS(VmemberName2, ((Tc*)&YWXt)));
     }
     sf.pos=5940853;
     if ((ZstringCmp(Atype, ((Tc*)&Y89Q)) == 0))
     {
      sf.pos=5940854;
      YwHoa((Yw8L *)Aout, ZcS8(((Tc*)&Yxtk), Vf2->VtypeName, ((Tc*)&YoJI), ((Tc*)&Yxtk), (t1 = Vf2->VtypeName), ((Tc*)&Y9CL), (t2 = Vf2->VtypeName), ((Tc*)&YW8X)));
     }
     else {
     sf.pos=5940855;
     if (Vf2->Vrepeated)
     {
      sf.pos=5940856;
      YwHoa((Yw8L *)Aout, ((Tc*)&Y37y));
     }
     else {
     sf.pos=5940857;
     if ((ZstringCmp(Atype, ((Tc*)&YtPw)) == 0))
     {
      sf.pos=5940858;
      YwHoa((Yw8L *)Aout, ((Tc*)&YHfx));
     }
     else
     {
      sf.pos=5940859;
      VhasName = YFlx((Y0uC *)Vf2);
      sf.pos=5940860;
      if ((VhasName != NULL))
      {
       sf.pos=5940861;
       YwHoa((Yw8L *)Aout, ZcS3(((Tc*)&YPKf), VhasName, ((Tc*)&YKf1)));
      }
      else
      {
       sf.pos=5940862;
       YwHoa((Yw8L *)Aout, ((Tc*)&Y37y));
      }
     }
     }}
     sf.pos=5940863;
     Yw8L__YRt7((Yw8L *)Aout, ((Vf2->Vrepeated) ? (((Tc*)&YP)) : (((Tc*)&Ya))));
     sf.pos=5940864;
     }
    }
    sf.pos=5940865;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
    sf.pos=5940866;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
    sf.pos=5940867;
    if ((ZstringCmp(Atype, ((Tc*)&Y89Q)) == 0))
    {
     sf.pos=5940868;
     YwHoa((Yw8L *)Aout, Aindent);
     sf.pos=5940869;
     Yw8L__YRt7((Yw8L *)Aout, ((Tc*)&Ygbr));
     sf.pos=5940870;
     YwHoa((Yw8L *)Aout, Aindent);
     sf.pos=5940871;
     Yw8L__YRt7((Yw8L *)Aout, ((Tc*)&Y3Rg));
     sf.pos=5940872;
     {
      Tfl Zf5i;
      Zf5 = Afields;
      Zf5i.l = Zf5;
      Zf5i.valp = (void*)&Vf3;
      Zf5i.i = 0;
      for (; ZforListPtrCont(&Zf5i); ) {
      sf.pos=5940873;
      VmemberName3 = YULH((Y0uC *)Vf3);
      sf.pos=5940874;
      YwHoa((Yw8L *)Aout, Aindent);
      sf.pos=5940875;
      YwHoa((Yw8L *)Aout, ZcS3(((Tc*)&Y4Qg), Zint2string(Vf3->Vnr), ((Tc*)&YgFa)));
      sf.pos=5940876;
      if (Vf3->Vrepeated)
      {
       sf.pos=5940877;
       YwHoa((Yw8L *)Aout, ZcS3(((Tc*)&YO9t), YqGL((Y0uC *)Vf3), ((Tc*)&YO)));
      }
      else
      {
       sf.pos=5940878;
       YwHoa((Yw8L *)Aout, ZcS(VmemberName3, ((Tc*)&YWXt)));
      }
      sf.pos=5940879;
      Yw8L__YRt7((Yw8L *)Aout, ZcS(Vf3->VtypeName, ((Tc*)&Y4s5)));
      sf.pos=5940880;
      Yw8L__YRt7((Yw8L *)Aout, ((Vf3->Vrepeated) ? (((Tc*)&YP)) : (((Tc*)&Ya))));
      sf.pos=5940881;
      }
     }
     sf.pos=5940882;
     Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
     sf.pos=5940883;
     Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
    }
   }
  }
  sf.pos=5940884;
  }
 }
 topFrame = sf.prev;
 return;
}
Tb YTU9(Tl *Afields) { /* MWriteZimbu.hasRepeated */
 Zsf sf={0,topFrame};
 Tb r = 0;
 Tl *Zf1 = NULL;
 Y0uC *Vf = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=175500;
 {
  Tfl Zf1i;
  Zf1 = Afields;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vf;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=175501;
  if (Vf->Vrepeated)
  {
   sf.pos=175502;
   r = 1;
   rt = 1;
   goto Y6d1;
  }
Y6d1:
  if (rt) goto Ygal;
  sf.pos=175503;
  }
 }
 sf.pos=175504;
 r = 0;
Ygal:
 topFrame = sf.prev;
 return r;
}
Tb YADt(Tl *Afields) { /* MWriteZimbu.hasNotRepeated */
 Zsf sf={0,topFrame};
 Tb r = 0;
 Tl *Zf1 = NULL;
 Y0uC *Vf = 0;
 int rt = 0;
 topFrame = &sf;
 sf.pos=1080000;
 {
  Tfl Zf1i;
  Zf1 = Afields;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vf;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=1080001;
  if (!(Vf->Vrepeated))
  {
   sf.pos=1080002;
   r = 1;
   rt = 1;
   goto YK5W;
  }
YK5W:
  if (rt) goto YnNd;
  sf.pos=1080003;
  }
 }
 sf.pos=1080004;
 r = 0;
YnNd:
 topFrame = sf.prev;
 return r;
}
void YwAg(Tl *Afields, Tc *Aindent, Yw8L *Aout) { /* MWriteZimbu.writeWriteMerge */
 Tb VhasRep;
 Tb VhasNotRep;
 Tb VdidMerge;
 Zsf sf={0,topFrame};
 Tl *Zf1 = NULL;
 Tl *Zf3 = NULL;
 Y0uC *Vf = 0;
 Tl *Zf31 = NULL;
 Y0uC *Vf1 = 0;
 Tc *Vindent6 = NULL;
 Tl *Zf4 = NULL;
 Y0uC *Vf2 = 0;
 Tl *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 Tc *t3 = NULL;
 topFrame = &sf;
 sf.pos=3741100;
 VhasRep = YTU9(Afields);
 sf.pos=3741101;
 VhasNotRep = YADt(Afields);
 VdidMerge = 0;
 sf.pos=3741102;
 {
  Ti Vrepeated;
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&bool__T, 2), ZLap((Tl*)t0, (Tz)(Ti)0), ZLap((Tl*)t0, (Tz)(Ti)1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vrepeated;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=3741103;
  if ((((!(Vrepeated) && VhasNotRep)) || ((Vrepeated && VhasRep))))
  {
   sf.pos=3741104;
   YwHoa((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YO3G)));
   sf.pos=3741105;
   if (Vrepeated)
   {
    sf.pos=3741106;
    YwHoa((Yw8L *)Aout, ((Tc*)&YNcD));
   }
   sf.pos=3741107;
   Yw8L__YRt7((Yw8L *)Aout, ((Tc*)&YRua));
   sf.pos=3741108;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y3Rg)));
   sf.pos=3741109;
   {
    Tfl Zf3i;
    Zf3 = Afields;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vf;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=3741110;
    if ((Vf->Vrepeated == Vrepeated))
    {
     sf.pos=3741111;
     YwHoa((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&Y4Qg), (t1 = Zint2string(Vf->Vnr)), ((Tc*)&YBII), (t2 = YULH((Y0uC *)Vf))));
     sf.pos=3741112;
     if (Vrepeated)
     {
      sf.pos=3741113;
      YwHoa((Yw8L *)Aout, ((Tc*)&YxsN));
     }
     sf.pos=3741114;
     Yw8L__YRt7g((Yw8L *)Aout);
    }
    sf.pos=3741115;
    }
   }
   sf.pos=3741116;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
   sf.pos=3741117;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Yzrg)));
   sf.pos=3741118;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
   sf.pos=3741119;
   if (Vrepeated)
   {
    sf.pos=3741120;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YhqR)));
   }
   else
   {
    sf.pos=3741121;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YfRA)));
   }
   sf.pos=3741122;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y3Rg)));
   sf.pos=3741123;
   {
    Tfl Zf31i;
    Zf31 = Afields;
    Zf31i.l = Zf31;
    Zf31i.valp = (void*)&Vf1;
    Zf31i.i = 0;
    for (; ZforListPtrCont(&Zf31i); ) {
    sf.pos=3741124;
    if ((Vf1->Vrepeated == Vrepeated))
    {
     sf.pos=3741125;
     YwHoa((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&Y4Qg), (t1 = Zint2string(Vf1->Vnr)), ((Tc*)&YgFa), (Tc*)1));
     sf.pos=3741126;
     if (Vrepeated)
     {
      sf.pos=3741127;
      YwHoa((Yw8L *)Aout, ZcS3(((Tc*)&Y6y9), YULH((Y0uC *)Vf1), ((Tc*)&YNM4)));
      sf.pos=3741128;
      Yw8L__YRt7((Yw8L *)Aout, ZcS(YULH((Y0uC *)Vf1), ((Tc*)&YI0U)));
      sf.pos=3741129;
      Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YR8A), (t1 = YULH((Y0uC *)Vf1)), ((Tc*)&YVtc), (Tc*)1));
     }
     else
     {
      sf.pos=3741130;
      Yw8L__YRt7((Yw8L *)Aout, ZcS(YULH((Y0uC *)Vf1), ((Tc*)&YRyv)));
     }
    }
    sf.pos=3741131;
    }
   }
   sf.pos=3741132;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
   sf.pos=3741133;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
   sf.pos=3741134;
   if (!(VdidMerge))
   {
    sf.pos=3741135;
    VdidMerge = 1;
    sf.pos=3741136;
    YwHoa((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YfXS)));
    sf.pos=3741137;
    Yw8L__YRt7((Yw8L *)Aout, ((Tc*)&Yf3o));
    sf.pos=3741138;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y3Rg)));
    sf.pos=3741139;
    Vindent6 = ZcS(Aindent, ((Tc*)&Ya8x));
    sf.pos=3741140;
    {
     Tfl Zf4i;
     Zf4 = Afields;
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Vf2;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=3741141;
     Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&Y4Qg), (t1 = Zint2string(Vf2->Vnr))));
     sf.pos=3741142;
     Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&Y6y9), (t1 = YULH((Y0uC *)Vf2)), ((Tc*)&YgCk), (Tc*)1));
     sf.pos=3741143;
     Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&YZY), (t1 = YULH((Y0uC *)Vf2)), ((Tc*)&YII0), (Tc*)1));
     sf.pos=3741144;
     Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent6, ((Tc*)&Y9a)));
     sf.pos=3741145;
     if (Vf2->Vrepeated)
     {
      sf.pos=3741146;
      Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent6, Vf2->VtypeName, ((Tc*)&Yi_6)));
      sf.pos=3741147;
      Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent6, YULH((Y0uC *)Vf2), ((Tc*)&YVtc)));
      sf.pos=3741148;
      Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent6, ((Tc*)&Yt1y)));
      sf.pos=3741149;
      Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent6, ((Tc*)&YU62)));
     }
     else
     {
      sf.pos=3741150;
      Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent6, ((Tc*)&YG9J), (t1 = YULH((Y0uC *)Vf2)), ((Tc*)&YP), (Tc*)1));
      sf.pos=3741151;
      Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent6, YULH((Y0uC *)Vf2), ((Tc*)&YDFV)));
     }
     sf.pos=3741152;
     Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent6, ((Tc*)&YdMU)));
     sf.pos=3741153;
     }
    }
    sf.pos=3741154;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
    sf.pos=3741155;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YwAl)));
    sf.pos=3741156;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
   }
  }
  sf.pos=3741157;
  }
 }
 topFrame = sf.prev;
 return;
}
void YYCV(Tl *Afields, Tc *Aindent, Yw8L *Aout) { /* MWriteZimbu.writeHasField */
 Zsf sf={0,topFrame};
 Tl *Zf1 = NULL;
 Y0uC *Vf = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 topFrame = &sf;
 sf.pos=8513200;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YpN1)));
 sf.pos=8513201;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y3Rg)));
 sf.pos=8513202;
 {
  Tfl Zf1i;
  Zf1 = Afields;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vf;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8513203;
  Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Y4Qg), (t0 = Zint2string(Vf->Vnr)), ((Tc*)&YpgF), (t1 = YqGL((Y0uC *)Vf)), ((Tc*)&YXaa), (Tc*)1, (Tc*)1));
  sf.pos=8513204;
  }
 }
 sf.pos=8513205;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
 sf.pos=8513206;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YwAl)));
 sf.pos=8513207;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 topFrame = sf.prev;
 return;
}
void Yg8t(YRAB *Amsg, Tc *Aindent, Yw8L *Aout) { /* MWriteZimbu.writeCopy */
 Zsf sf={0,topFrame};
 Tc *Vindent2 = NULL;
 Tl *Zf1 = NULL;
 Y0uC *Vf = 0;
 Tc *VmemberName = NULL;
 Tc *VhasName = NULL;
 Tc *VindentX = NULL;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 Tc *t3 = NULL;
 topFrame = &sf;
 sf.pos=7547500;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&YcuF), (t0 = Amsg->Vname)));
 sf.pos=7547501;
 Vindent2 = ZcS(Aindent, ((Tc*)&YZY));
 sf.pos=7547502;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, Amsg->Vname, ((Tc*)&YEsj)));
 sf.pos=7547503;
 {
  Tfl Zf1i;
  Zf1 = Amsg->Vfields;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vf;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=7547504;
  VmemberName = YuAL(YULH((Y0uC *)Vf), 1);
  sf.pos=7547505;
  VhasName = YFlx((Y0uC *)Vf);
  sf.pos=7547506;
  VindentX = Vindent2;
  sf.pos=7547507;
  if ((VhasName != NULL))
  {
   sf.pos=7547508;
   VindentX =  ZcS(VindentX, ((Tc*)&YZY));
   sf.pos=7547509;
   Yw8L__YRt7((Yw8L *)Aout, ZcS3(Vindent2, ((Tc*)&Y6y9), VhasName));
   sf.pos=7547510;
   Yw8L__YRt7((Yw8L *)Aout, ZcS5(VindentX, ((Tc*)&Y2C2), (t0 = YuAL(VhasName, 1)), ((Tc*)&YKf1), (Tc*)1));
  }
  sf.pos=7547511;
  if (Vf->Vrepeated)
  {
   sf.pos=7547512;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(VindentX, ((Tc*)&YGbi)));
   sf.pos=7547513;
   Yw8L__YRt7((Yw8L *)Aout, ZcS5(VindentX, ((Tc*)&YiHe), (t0 = YULH((Y0uC *)Vf)), ((Tc*)&Y2Nk), (Tc*)1));
   sf.pos=7547514;
   Yw8L__YRt7((Yw8L *)Aout, ZcS5(VindentX, ((Tc*)&Y5Fk), VmemberName, ((Tc*)&YII0), (Tc*)1));
   sf.pos=7547515;
   Yw8L__YRt7((Yw8L *)Aout, ZcS3(VindentX, ((Tc*)&YAGs), (t0 = YULH((Y0uC *)Vf))));
   sf.pos=7547516;
   if ((Vf->Vtype == 12))
   {
    sf.pos=7547517;
    Yw8L__YRt7((Yw8L *)Aout, ZcS5(VindentX, ((Tc*)&YO9y), VmemberName, ((Tc*)&YR9A), (Tc*)1));
   }
   else
   {
    sf.pos=7547518;
    Yw8L__YRt7((Yw8L *)Aout, ZcS5(VindentX, ((Tc*)&YO9y), VmemberName, ((Tc*)&Yvnc), (Tc*)1));
   }
   sf.pos=7547519;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(VindentX, ((Tc*)&Y6my)));
   sf.pos=7547520;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(VindentX, ((Tc*)&YVet)));
   sf.pos=7547521;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(VindentX, ((Tc*)&Yc7A)));
   sf.pos=7547522;
   Yw8L__YRt7((Yw8L *)Aout, ZcS5(VindentX, ((Tc*)&YhLg), VmemberName, ((Tc*)&YWXt), (t0 = YULH((Y0uC *)Vf))));
   sf.pos=7547523;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(VindentX, ((Tc*)&Y9a)));
  }
  else
  {
   sf.pos=7547524;
   if ((Vf->Vtype == 12))
   {
    sf.pos=7547525;
    Yw8L__YRt7((Yw8L *)Aout, ZcS5(VindentX, ((Tc*)&Y6y9), (t0 = YULH((Y0uC *)Vf)), ((Tc*)&Y2Nk), (Tc*)1));
    sf.pos=7547526;
    Yw8L__YRt7((Yw8L *)Aout, ZcS8(VindentX, ((Tc*)&YhLg), VmemberName, ((Tc*)&YRQE), (t0 = YULH((Y0uC *)Vf)), ((Tc*)&Ybf2), (t2 = YULH((Y0uC *)Vf)), (Tc*)1));
    sf.pos=7547527;
    Yw8L__YRt7((Yw8L *)Aout, ZcS(VindentX, ((Tc*)&Y9a)));
   }
   else
   {
    sf.pos=7547528;
    Yw8L__YRt7((Yw8L *)Aout, ZcS5(VindentX, ((Tc*)&Y2C2), VmemberName, ((Tc*)&YWXt), (t0 = YULH((Y0uC *)Vf))));
   }
  }
  sf.pos=7547529;
  if ((VhasName != NULL))
  {
   sf.pos=7547530;
   Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Y9a)));
  }
  sf.pos=7547531;
  }
 }
 sf.pos=7547532;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent2, ((Tc*)&Yxe8)));
 sf.pos=7547533;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 topFrame = sf.prev;
 return;
}
void Ycma(Tl *Afields, Tc *Aindent, Yw8L *Aout) { /* MWriteZimbu.writeSize */
 Zsf sf={0,topFrame};
 Tl *Zf1 = NULL;
 Y0uC *Vf = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 Tc *t3 = NULL;
 Tc *t4 = NULL;
 topFrame = &sf;
 sf.pos=2007500;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YvCR)));
 sf.pos=2007501;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y3Rg)));
 sf.pos=2007502;
 {
  Tfl Zf1i;
  Zf1 = Afields;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vf;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=2007503;
  Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Y4Qg), (t0 = Zint2string(Vf->Vnr)), ((Tc*)&YBII), (t1 = YULH((Y0uC *)Vf)), ((Tc*)&YG_R), (t3 = YULH((Y0uC *)Vf)), ((Tc*)&YZY7)));
  sf.pos=2007504;
  }
 }
 sf.pos=2007505;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
 sf.pos=2007506;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Yc_G)));
 sf.pos=2007507;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 topFrame = sf.prev;
 return;
}
void YMWy(Tl *Afields, Tc *Aindent, Yw8L *Aout) { /* MWriteZimbu.writeFieldTable */
 Zsf sf={0,topFrame};
 Tl *Zf1 = NULL;
 Y0uC *Vfield = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 Tc *t3 = NULL;
 Tc *t4 = NULL;
 topFrame = &sf;
 sf.pos=4924000;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YMvm)));
 sf.pos=4924001;
 {
  Tfl Zf1i;
  Zf1 = Afields;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vfield;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=4924002;
  Yw8L__YRt7((Yw8L *)Aout, ZcS12(Aindent, ((Tc*)&YQgq), (t0 = Vfield->Vname), ((Tc*)&YwFy), (t1 = Zint2string(Vfield->Vnr)), ((Tc*)&YqQF), (t2 = Zenum2string(MProto__EType, Vfield->Vtype)), ((Tc*)&Ydha), (t4 = Zbool2string(Vfield->Vrepeated)), ((Tc*)&YBca), (Tc*)1, (Tc*)1));
  sf.pos=4924003;
  }
 }
 sf.pos=4924004;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YEa)));
 topFrame = sf.prev;
 return;
}
void Y1M2(Tc *Aclass, Y0uC *Afield, Tc *Atype, Tc *AinitVal, Tc *AdefaultVal, Tc *Aindent, Yw8L *Aout) { /* MWriteZimbu.writeSetGetHas */
 Zsf sf={0,topFrame};
 Tc *VmemberName = NULL;
 Tc *VfuncName = NULL;
 Tc *VhasName = NULL;
 Tc *t0 = NULL;
 topFrame = &sf;
 sf.pos=2147600;
 VmemberName = YULH((Y0uC *)Afield);
 sf.pos=2147601;
 VfuncName = YqGL((Y0uC *)Afield);
 sf.pos=2147602;
 VhasName = YFlx((Y0uC *)Afield);
 sf.pos=2147603;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Yctj), VfuncName, ((Tc*)&YO), Atype, ((Tc*)&YxgQ), Aclass, ((Tc*)&YNOm)));
 sf.pos=2147604;
 if ((ZstringCmp(Atype, ((Tc*)&YtPw)) == 0))
 {
  sf.pos=2147605;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VmemberName, ((Tc*)&Ybd2), (Tc*)1));
 }
 else
 {
  sf.pos=2147606;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VmemberName, ((Tc*)&Y_yv), (Tc*)1));
 }
 sf.pos=2147607;
 if ((VhasName != NULL))
 {
  sf.pos=2147608;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VhasName, ((Tc*)&YKf1), (Tc*)1));
 }
 sf.pos=2147609;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YYwn)));
 sf.pos=2147610;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2147611;
 if ((Afield->Vtype == 12))
 {
  sf.pos=2147612;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YEC6), VfuncName, ((Tc*)&Ye0N), Atype));
  sf.pos=2147613;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VmemberName, ((Tc*)&YII0), (Tc*)1));
  sf.pos=2147614;
  Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&YKKn), VmemberName));
  sf.pos=2147615;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 }
 sf.pos=2147616;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Y9CPa), VfuncName, ((Tc*)&Ye0N), Atype, ((Tc*)&YNOm), (Tc*)1, (Tc*)1));
 sf.pos=2147617;
 if ((VhasName != NULL))
 {
  sf.pos=2147618;
  Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&YwS1), VhasName));
 }
 else
 {
  sf.pos=2147619;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YiHe), VmemberName, ((Tc*)&Y7gw), AinitVal));
 }
 sf.pos=2147620;
 if ((Afield->Vdefault != NULL))
 {
  sf.pos=2147621;
  Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&YG_k), AdefaultVal));
 }
 else {
 sf.pos=2147622;
 if ((ZstringCmp(Atype, ((Tc*)&YtPw)) == 0))
 {
  sf.pos=2147623;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YQIB)));
 }
 else {
 sf.pos=2147624;
 if (((ZstringCmp(Atype, ((Tc*)&YanE)) == 0) || (ZstringCmp(Atype, ((Tc*)&YGxv)) == 0)))
 {
  sf.pos=2147625;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YJGx)));
 }
 else {
 sf.pos=2147626;
 if (((((ZstringCmp(Atype, ((Tc*)&Y1Qt)) == 0) || (ZstringCmp(Atype, ((Tc*)&YrQi)) == 0)) || (ZstringCmp(Atype, ((Tc*)&YNmG)) == 0)) || (ZstringCmp(Atype, ((Tc*)&YDFy)) == 0)))
 {
  sf.pos=2147627;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YzWb)));
 }
 else
 {
  sf.pos=2147628;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YdiJ), (t0 = Afield->Vname), ((Tc*)&YTKi), (Tc*)1));
 }
 }}}
 sf.pos=2147629;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
 sf.pos=2147630;
 if ((ZstringCmp(Atype, ((Tc*)&YtPw)) == 0))
 {
  sf.pos=2147631;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YKKn), VmemberName, ((Tc*)&Y9Ud), (Tc*)1));
 }
 else
 {
  sf.pos=2147632;
  Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&YKKn), VmemberName));
 }
 sf.pos=2147633;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2147634;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YE5R), VfuncName, ((Tc*)&YBMj), (Tc*)1));
 sf.pos=2147635;
 if ((VhasName != NULL))
 {
  sf.pos=2147636;
  Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&YKKn), VhasName));
 }
 else
 {
  sf.pos=2147637;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YKKn), VmemberName, ((Tc*)&Yljn), AinitVal));
 }
 sf.pos=2147638;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2147639;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YnyF), VfuncName, ((Tc*)&Ye0N), Aclass, ((Tc*)&YNOm), (Tc*)1, (Tc*)1));
 sf.pos=2147640;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VmemberName, ((Tc*)&YWXt), AinitVal));
 sf.pos=2147641;
 if ((VhasName != NULL))
 {
  sf.pos=2147642;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VhasName, ((Tc*)&YRRN), (Tc*)1));
 }
 sf.pos=2147643;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YYwn)));
 sf.pos=2147644;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 topFrame = sf.prev;
 return;
}
void YsmR(Tc *Aclass, Y0uC *Afield, Tc *Atype, Tc *AdefaultVal, Tc *Aindent, Yw8L *Aout) { /* MWriteZimbu.writeAddGetHas */
 Zsf sf={0,topFrame};
 Tc *VmemberName = NULL;
 Tc *VfuncName = NULL;
 Tc *t0 = NULL;
 topFrame = &sf;
 sf.pos=2426900;
 VmemberName = YULH((Y0uC *)Afield);
 sf.pos=2426901;
 VfuncName = YqGL((Y0uC *)Afield);
 sf.pos=2426902;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YMaA), VfuncName, ((Tc*)&YO), Atype, ((Tc*)&YxgQ), Aclass, (Tc*)1));
 sf.pos=2426903;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YiHe), VmemberName, ((Tc*)&YgCk), (Tc*)1));
 sf.pos=2426904;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YW_j), VmemberName, ((Tc*)&YII0), (Tc*)1));
 sf.pos=2426905;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
 sf.pos=2426906;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VmemberName, ((Tc*)&YlIc), (Tc*)1));
 sf.pos=2426907;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YYwn)));
 sf.pos=2426908;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2426909;
 if ((Afield->Vtype == 12))
 {
  sf.pos=2426910;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YEnH), VfuncName, ((Tc*)&Ye0N), Atype));
  sf.pos=2426911;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), Atype, ((Tc*)&Y0_k), (Tc*)1));
  sf.pos=2426912;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&Y2hI), VfuncName, ((Tc*)&YPYP), (Tc*)1));
  sf.pos=2426913;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y5YG)));
  sf.pos=2426914;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 }
 sf.pos=2426915;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Y9CPa), VfuncName, ((Tc*)&Y7in), Atype, ((Tc*)&YNOm), (Tc*)1, (Tc*)1));
 sf.pos=2426916;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YD5ta), VmemberName, ((Tc*)&YAGJ), VmemberName, ((Tc*)&YZY7), (Tc*)1, (Tc*)1));
 sf.pos=2426917;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YOn3), (t0 = Afield->Vname), ((Tc*)&YEpL), (Tc*)1));
 sf.pos=2426918;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
 sf.pos=2426919;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YKKn), VmemberName, ((Tc*)&YLJU), (Tc*)1));
 sf.pos=2426920;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2426921;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Y9CPa), VfuncName, ((Tc*)&Ynjc), Atype, ((Tc*)&Yp5Q), (Tc*)1, (Tc*)1));
 sf.pos=2426922;
 Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&YKKn), VmemberName));
 sf.pos=2426923;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2426924;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Yctj), VfuncName, ((Tc*)&YCj9), Atype, ((Tc*)&YWFy), Aclass, ((Tc*)&YNOm)));
 sf.pos=2426925;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VmemberName, ((Tc*)&YQyv), (Tc*)1));
 sf.pos=2426926;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YYwn)));
 sf.pos=2426927;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2426928;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YgyZ), VfuncName, ((Tc*)&Y3FL), (Tc*)1));
 sf.pos=2426929;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YKKn), VmemberName, ((Tc*)&YG_R), VmemberName, ((Tc*)&YZY7), (Tc*)1, (Tc*)1));
 sf.pos=2426930;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2426931;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YE5R), VfuncName, ((Tc*)&YBMj), (Tc*)1));
 sf.pos=2426932;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YKKn), VmemberName, ((Tc*)&YIgG), VmemberName, ((Tc*)&YW_F), (Tc*)1, (Tc*)1));
 sf.pos=2426933;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2426934;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YE5R), VfuncName, ((Tc*)&YwnZ), (Tc*)1));
 sf.pos=2426935;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YBWs), VmemberName, ((Tc*)&YEqC), VmemberName, ((Tc*)&YZY7), (Tc*)1, (Tc*)1));
 sf.pos=2426936;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=2426937;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YnyF), VfuncName, ((Tc*)&Ye0N), Aclass, ((Tc*)&YNOm), (Tc*)1, (Tc*)1));
 sf.pos=2426938;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), VmemberName, ((Tc*)&YsTa), (Tc*)1));
 sf.pos=2426939;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YYwn)));
 sf.pos=2426940;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 topFrame = sf.prev;
 return;
}
void Yk4Q(YNW5 *Aservice, Yw8L *Aout, Tc *Aindent) { /* MWriteZimbu.writeService */
 Zsf sf={0,topFrame};
 Tc *Vindent4 = NULL;
 Tl *Zf1 = NULL;
 YlM3 *Vrpc = 0;
 Tc *VdotName = NULL;
 Tc *Vcall = NULL;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 topFrame = &sf;
 sf.pos=5413700;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(((Tc*)&Y9d4), ZstringToUpper(YuALa(Aservice->Vname, 0, 0)), (t0 = YuAL(Aservice->Vname, 1)), ((Tc*)&Y7Qg), (Tc*)1));
 sf.pos=5413701;
 Vindent4 = ZcS(Aindent, ((Tc*)&YW_j));
 sf.pos=5413702;
 {
  Tfl Zf1i;
  Zf1 = Aservice->Vrpcs;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vrpc;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=5413703;
  Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YZZg), (t0 = Vrpc->Vname), ((Tc*)&YO), (t1 = Vrpc->VrequestName), ((Tc*)&YOlD), (t2 = Vrpc->VresponseName), (Tc*)1));
  sf.pos=5413704;
  Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YHny), (t0 = Vrpc->Vname), ((Tc*)&YO), (t1 = Vrpc->VrequestName), ((Tc*)&Y8Bf), ((Tc*)&YJ4N), ((Tc*)&Y84u)));
  sf.pos=5413705;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YclF)));
  sf.pos=5413706;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Yzrg)));
  sf.pos=5413707;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y9a)));
  sf.pos=5413708;
  VdotName = ZcS3(Aservice->Vname, ((Tc*)&YU), (t0 = Vrpc->Vname));
  sf.pos=5413709;
  Vcall = ZcS3(((Tc*)&YI05), VdotName, ((Tc*)&YnFL));
  sf.pos=5413710;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YQuz)));
  sf.pos=5413711;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent4, Vcall, (t0 = Vrpc->VresponseName), ((Tc*)&Y9Ba), (Tc*)1));
  sf.pos=5413712;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&YKC8)));
  sf.pos=5413713;
  Yw8L__YRt7((Yw8L *)Aout, ZcS5(Vindent4, Vcall, ((Tc*)&YZeO), (t0 = Vrpc->VresponseName), ((Tc*)&YihP)));
  sf.pos=5413714;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Yuso)));
  sf.pos=5413715;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Yzrg)));
  sf.pos=5413716;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Vindent4, ((Tc*)&Y9a)));
  sf.pos=5413717;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
  sf.pos=5413718;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YIzR)));
  sf.pos=5413719;
  Yw8L__YRt7((Yw8L *)Aout, ZcS12(Vindent4, ((Tc*)&Yhls), (t0 = Vrpc->Vname), ((Tc*)&YBI0), VdotName, ((Tc*)&YwFy), (t1 = Vrpc->VrequestName), ((Tc*)&YJQW), (t2 = Vrpc->VresponseName), ((Tc*)&YNbo), (Tc*)1, (Tc*)1));
  sf.pos=5413720;
  Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YVet)));
  sf.pos=5413721;
  }
 }
 sf.pos=5413722;
 Yw8L__YRt7((Yw8L *)Aout, ((Tc*)&YVet));
 topFrame = sf.prev;
 return;
}
void Y8RG(Y2Kp *Aenum, Yw8L *Aout, Tc *Aindent) { /* MWriteZimbu.writeEnum */
 Zsf sf={0,topFrame};
 Tl *Zf1 = NULL;
 Tl *Zf11 = NULL;
 Tl *Zf12 = NULL;
 YFk1 *Vm = 0;
 YFk1 *Vm1 = 0;
 YFk1 *Vm2 = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 topFrame = &sf;
 sf.pos=4516900;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&Ywwj), (t0 = Aenum->Vname), ((Tc*)&YAId), (Tc*)1));
 sf.pos=4516901;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YXRY)));
 sf.pos=4516902;
 {
  Tfl Zf1i;
  Zf1 = Aenum->Vmembers;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vm;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=4516903;
  Yw8L__YRt7((Yw8L *)Aout, ZcS3(Aindent, ((Tc*)&Yxet), (t0 = Vm->Vid)));
  sf.pos=4516904;
  }
 }
 sf.pos=4516905;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&Y9a)));
 sf.pos=4516906;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Yfpd), (t0 = Aenum->Vname), ((Tc*)&Yj9U), (t1 = Aenum->Vname), ((Tc*)&Y9UL), (Tc*)1, (Tc*)1));
 sf.pos=4516907;
 Yw8L__YRt7((Yw8L *)Aout, ZcS5(Aindent, ((Tc*)&YZY), (t0 = Aenum->Vname), ((Tc*)&Yu8y), (Tc*)1));
 sf.pos=4516908;
 {
  Tfl Zf11i;
  Zf11 = Aenum->Vmembers;
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vm1;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=4516909;
  Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YZY), (t0 = Aenum->Vname), ((Tc*)&Ywla), (t1 = Vm1->Vid), ((Tc*)&YFDa), (t2 = Zint2string(Vm1->Vnr)), ((Tc*)&YS)));
  sf.pos=4516910;
  }
 }
 sf.pos=4516911;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YEa)));
 sf.pos=4516912;
 Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&Yxa6), (t0 = Aenum->Vname), ((Tc*)&Y9oy), (t1 = Aenum->Vname), ((Tc*)&Yzyv), (Tc*)1, (Tc*)1));
 sf.pos=4516913;
 {
  Tfl Zf12i;
  Zf12 = Aenum->Vmembers;
  Zf12i.l = Zf12;
  Zf12i.valp = (void*)&Vm2;
  Zf12i.i = 0;
  for (; ZforListPtrCont(&Zf12i); ) {
  sf.pos=4516914;
  Yw8L__YRt7((Yw8L *)Aout, ZcS8(Aindent, ((Tc*)&YZY), (t0 = Zint2string(Vm2->Vnr)), ((Tc*)&YFDa), (t1 = Aenum->Vname), ((Tc*)&Ywla), (t2 = Vm2->Vid), ((Tc*)&YS)));
  sf.pos=4516915;
  }
 }
 sf.pos=4516916;
 Yw8L__YRt7((Yw8L *)Aout, ZcS(Aindent, ((Tc*)&YEa)));
 topFrame = sf.prev;
 return;
}
void YCOQ(Tc *AinFileName, Tc *AoutFileName) { /* MWriteZimbu.writeError */
 Zsf sf={0,topFrame};
 Yw8L *Vout = NULL;
 topFrame = &sf;
 sf.pos=142200;
 Vout = YiBk(AoutFileName, 1);
 sf.pos=142201;
 if ((Vout == (void *)NULL))
 {
  sf.pos=142202;
  Yl0k(ZcS(((Tc*)&Y32K), AoutFileName));
  sf.pos=142203;
  Zexit(NULL, 1);
 }
 sf.pos=142204;
 Yw8L__YRt7((Yw8L *)Vout, ZcS(((Tc*)&YK3s), AinFileName));
 sf.pos=142205;
 YrF8((Yw8L *)Vout);
 topFrame = sf.prev;
 return;
}
/* WriteZimbu done */
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
  YP_P *p = 0;
  YP_P__mt[2] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YP_P__mt[3] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YP_P__mt[4] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYP_P[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYP_P[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYP_P[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  Yhqr *p = 0;
  ToYhqr[1].off = (int)((Tc*)&p->Vdict - (Tc*)p);
 }
 {
  Ygqr *p = 0;
  ToYgqr[1].off = (int)((Tc*)&p->Vdict - (Tc*)p);
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
  YFk1 *p = 0;
  ToYFk1[1].off = (int)((Tc*)&p->Vid - (Tc*)p);
  ToYFk1[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Y2Kp *p = 0;
  Y2Kp__YuXI_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToY2Kp[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToY2Kp[2].off = (int)((Tc*)&p->Vmembers - (Tc*)p);
 }
 {
  Y0uC *p = 0;
  ToY0uC[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToY0uC[2].off = (int)((Tc*)&p->VtypeName - (Tc*)p);
  ToY0uC[3].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY0uC[4].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Ykeq *p = 0;
  ToYkeq[1].off = (int)((Tc*)&p->Vvalue - (Tc*)p);
  ToYkeq[2].off = (int)((Tc*)&p->VstartPos - (Tc*)p);
  ToYkeq[3].off = (int)((Tc*)&p->VendPos - (Tc*)p);
 }
 {
  Yswy *p = 0;
  ToYswy[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYswy[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYswy[3].off = (int)((Tc*)&p->Vvalue - (Tc*)p);
 }
 {
  YRAB *p = 0;
  YRAB__YuXI_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYRAB[1].off = (int)((Tc*)&p->Vparent - (Tc*)p);
  ToYRAB[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYRAB[3].off = (int)((Tc*)&p->Vfields - (Tc*)p);
  ToYRAB[4].off = (int)((Tc*)&p->Vitems - (Tc*)p);
  ToYRAB[5].off = (int)((Tc*)&p->VoptionList - (Tc*)p);
 }
 {
  YP_l *p = 0;
  ToYP_l[1].off = (int)((Tc*)&p->Vpackage - (Tc*)p);
  ToYP_l[2].off = (int)((Tc*)&p->Vimports - (Tc*)p);
  ToYP_l[3].off = (int)((Tc*)&p->VitemList - (Tc*)p);
  ToYP_l[4].off = (int)((Tc*)&p->VitemDict - (Tc*)p);
 }
 {
  YlM3 *p = 0;
  YlM3__YuXI_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYlM3[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYlM3[2].off = (int)((Tc*)&p->VrequestName - (Tc*)p);
  ToYlM3[3].off = (int)((Tc*)&p->VresponseName - (Tc*)p);
 }
 {
  YNW5 *p = 0;
  YNW5__YuXI_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYNW5[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYNW5[2].off = (int)((Tc*)&p->Vrpcs - (Tc*)p);
 }
 {
  YeYq *p = 0;
  ToYeYq[1].off = (int)((Tc*)&p->Vfd - (Tc*)p);
  ToYeYq[2].off = (int)((Tc*)&p->Vtext - (Tc*)p);
  ToYeYq[3].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYeYq[4].off = (int)((Tc*)&p->VcharStack - (Tc*)p);
  ToYeYq[5].off = (int)((Tc*)&p->Vindent - (Tc*)p);
  ToYeYq[6].off = (int)((Tc*)&p->VrecordWriter - (Tc*)p);
 }
 {
  YuI4 *p = 0;
  ToYuI4[1].off = (int)((Tc*)&p->Vinput - (Tc*)p);
  ToYuI4[2].off = (int)((Tc*)&p->VtokenStack - (Tc*)p);
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
 done &= JParseProto(round);
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
 Zsf sf={0,topFrame};
 Ti r = 0;
 Tc *VinFileName = NULL;
 Tc *VoutFileName = NULL;
 YP_l *Vprotofile = 0;
 int rt = 0;
 topFrame = &sf;
 r = 0;
 sf.pos=527000;
 if ((Yd2Z() != 2))
 {
  sf.pos=527001;
  Yl0k(ZcS3(((Tc*)&YZVC), YzvW, ((Tc*)&YWbL)));
  sf.pos=527002;
  Zexit(NULL, 1);
  return 0;
 }
 sf.pos=527003;
 VinFileName = YtgL(0);
 sf.pos=527004;
 if ((ZstringCmp(ZstringSliceWrap(VinFileName, -6, -1), ((Tc*)&YnKK)) != 0))
 {
  sf.pos=527005;
  Yl0k(ZcS(((Tc*)&YwwA), VinFileName));
  sf.pos=527006;
  Zexit(NULL, 1);
  return 0;
 }
 sf.pos=527007;
 VoutFileName = YtgL(1);
 sf.pos=527008;
 if ((ZstringCmp(ZstringSliceWrap(VoutFileName, -3, -1), ((Tc*)&YYv4)) != 0))
 {
  sf.pos=527009;
  Yl0k(ZcS(((Tc*)&YIhh), VoutFileName));
  sf.pos=527010;
  Zexit(NULL, 1);
  return 0;
 }
 sf.pos=527011;
 Vprotofile = YSOt(VinFileName);
 sf.pos=527012;
 if ((Yrpn > 0))
 {
  sf.pos=527013;
  YCOQ(VinFileName, VoutFileName);
  sf.pos=527014;
  r = 1;
  rt = 1;
  goto YtK3;
 }
 sf.pos=527015;
 YCCA(Vprotofile, VinFileName, VoutFileName);
 sf.pos=527016;
 r = 0;
YtK3:
 topFrame = sf.prev;
 return r;
}
