/*
 * Generated from Zimbu file livedemo.zu
 */
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#if defined(__MINGW32__) || defined(_MSC_VER)
# define GC_SIG SIGABRT
# include <excpt.h>
#else
# define GC_SIG SIGUSR2
#endif
#include <setjmp.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#ifndef __MINGW32__
# define HAVE_FORK
# include <sys/wait.h>
#endif
#ifdef __MINGW32__
# include <windows.h>
# undef THIS
# undef small
#endif

#ifdef WIN32
# include <winsock.h>
# include <winsock2.h>
# undef THIS
# undef small
  typedef int socklen_t;
# if defined _WIN32 || defined __WIN32__
#  define setsockopt(a,b,c,d,e) setsockopt(a,b,c,(const void*)(d),e)
# endif
# define sckt_read(a, b, c) recv(a, b, c, 0)
# define sckt_write(a, b, c) send(a, b, c, 0)
# define sckt_close(a) closesocket(a)
#else
# define sckt_read(a, b, c) read(a, b, c)
# define sckt_write(a, b, c) write(a, b, c)
# define sckt_close(a) close(a)
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
#endif

/*
 * TYPEDEFS
 */
#define ZINT_FORMAT "%lld"
#define ZNAT_FORMAT "%llu"
#define ZINT_XFORMAT "%llx"
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
typedef struct Zoh__S Zoh; /* allocated memory header */
struct Zoh__S {
 Zoh *np;
};
#define ZOH_OFF sizeof(Zoh)
Zoh Zstatic;
Zoh Znoalloc;
Zoh Zlast;
#define ZOHF_LAST (Zohf*)&Zlast
typedef struct {
 void *var;
 Tt   *type;
} Zop;
#define GC_BLOCK_SIZE 1022
typedef struct Zgcb__S Zgcb;
struct Zgcb__S {
 Zgcb *next;
 int used;
 Zop items[GC_BLOCK_SIZE];
};
typedef struct {
 Zgcb *todo;
 Zgcb *empty;
} Zgcs;
typedef struct Zohf__S Zohf;
struct Zohf__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
};
#define FOK_OK 1
#define FOK_NOX 2
typedef struct ZforString__S Tfs; /* FOR in string */
typedef struct ZforList__S Tfl; /* FOR in list */
typedef struct ZforRange__S Tfr; /* FOR in range */
typedef struct ZforEnum__S Tfe; /* FOR in enum */
typedef struct garray__S Tg; /* grow array */

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
typedef struct YtEE__S YtEE; /* MEModule.Check */
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
/* including PIPEModule typedefs */
typedef struct YK7s__S YK7s; /* MPIPEModule.Pipe__t1 */
/* PIPEModule done */
/* including SYSModule typedefs */
typedef struct Y2SD__S Y2SD; /* MSYSModule.E_Process */
typedef struct YDTf__S YDTf; /* MSYSModule.Process */
/* SYSModule done */
/* including HTTPModule typedefs */
/* including Proto typedefs */
typedef struct Yd7N__S Yd7N; /* MProto.E_ParseError */
typedef struct Ys_q__S Ys_q; /* MProto.E_ProduceError */
typedef struct YOEA__S YOEA; /* MProto.E_BinaryError */
typedef struct YqvM__S YqvM; /* MProto.FieldSpec */
typedef struct YLWE__S YLWE; /* MProto.Writer */
typedef struct YBRp__S YBRp; /* MProto.Reader */
typedef struct YKxQ__S YKxQ; /* MProto.RpcInfo */
/* Proto done */
typedef struct YSM1__S YSM1; /* MHTTPModule.Request */
typedef struct YKeB__S YKeB; /* MHTTPModule.Response */
typedef struct YtzZ__S YtzZ; /* MHTTPModule.Context */
typedef struct YphE__S YphE; /* MHTTPModule.RedirectServlet */
typedef struct YX8j__S YX8j; /* MHTTPModule.FileServlet */
typedef struct YIgO__S YIgO; /* MHTTPModule.StringServlet */
typedef struct YntX__S YntX; /* MHTTPModule.RpcServlet */
typedef struct Yivg__S Yivg; /* MHTTPModule__CRpcServlet.Handler */
typedef struct Y1QG__S Y1QG; /* MHTTPModule.Server */
/* HTTPModule done */
/* including ZModule typedefs */
typedef struct YkxB__S YkxB; /* MZModule.Pos */
/* ZModule done */
/* including IOModule typedefs */
typedef struct Yw8L__S Yw8L; /* MIOModule.File */
typedef struct YtZ0__S YtZ0; /* MIOModule.StringReader */
typedef struct YrC3__S YrC3; /* MIOModule.CharReaderStack */
typedef struct YjUM__S YjUM; /* MIOModule.StringWriter */
/* IOModule done */
/* including THREADModule typedefs */
typedef struct YgC4__S YgC4; /* MTHREADModule.E_Thread */
typedef struct YTgs__S YTgs; /* MTHREADModule.Thread */
typedef struct YlXt__S YlXt; /* MTHREADModule.Lock */
typedef struct Y0Wo__S Y0Wo; /* MTHREADModule.Cond */
/* THREADModule done */
/* including ARGModule typedefs */
typedef struct YnU5__S YnU5; /* MARGModule.Status */
typedef struct YuMQ__S YuMQ; /* MARGModule.Usage */
typedef struct Y86c__S Y86c; /* MARGModule.Bool */
typedef struct YJQu__S YJQu; /* MARGModule.Int */
typedef struct YzqH__S YzqH; /* MARGModule.String */
typedef struct Y_SI__S Y_SI; /* MARGModule.StringList */
/* ARGModule done */
/* including liveDemoPage typedefs */
/* including buildzimbu typedefs */
typedef struct YwcI__S YwcI; /* MLivedemo.BuildRequest */
typedef struct YWgO__S YWgO; /* MLivedemo.BuildResult */
/* buildzimbu done */
/* liveDemoPage done */
/* including BuildZimbuServlet typedefs */
typedef struct YvG2__S YvG2; /* BuildZimbuServlet */
/* BuildZimbuServlet done */
typedef struct Tcallback__S Tcb;
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
 Zoh *np;
 Tc *ptr;
 Ti idx;
 Ti len;
};
struct ZforList__S {
 Zoh *np;
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

struct ZforEnum__S {
 int count;
 int idx;
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
 void *Size;
 void *Finish;
 void *Equal;
 void *Compare;
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
extern Tt thread__T;
extern Tt array__T;
extern Tt list__T;
extern Tt dict__T;
extern Tt cb__T;
extern Tt iobj__T;

struct CArray__S {
 Zoh *np;
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
 Zoh *np;
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
Ti ZListFind(Tl *head, Tz val);
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
 Zoh *np;

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
 Zoh *np;
 char text[5];
} Zs5;
/* including EModule structs */
typedef struct {
 Zoh *np;
 char text[4];
} Zs4;
typedef struct {
 Zoh *np;
 char text[13];
} Zs13;
typedef struct {
 Zoh *np;
 char text[11];
} Zs11;
typedef struct {
 Zoh *np;
 char text[39];
} Zs39;
typedef struct {
 Zoh *np;
 char text[12];
} Zs12;
typedef struct {
 Zoh *np;
 char text[3];
} Zs3;
struct Ytlm__S {
 Zoh *np;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Ytlm__T;
typedef struct {
 Zoh *np;
 char text[7];
} Zs7;
struct YEro__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
 Ti Vvalue;
};
extern Tto YEro__T;
typedef struct {
 Zoh *np;
 char text[6];
} Zs6;
typedef struct {
 Zoh *np;
 char text[28];
} Zs28;
typedef struct {
 Zoh *np;
 char text[9];
} Zs9;
struct YKhn__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YKhn__T;
struct Y1uN__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y1uN__T;
struct YAxe__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YAxe__T;
typedef struct {
 Zoh *np;
 char text[14];
} Zs14;
struct YVNj__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YVNj__T;
struct YtEE__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YtEE__T;
struct Yalz__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yalz__T;
typedef struct {
 Zoh *np;
 char text[10];
} Zs10;
struct Yw3O__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yw3O__T;
struct Y2EX__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y2EX__T;
typedef struct {
 Zoh *np;
 char text[17];
} Zs17;
typedef struct {
 Zoh *np;
 char text[18];
} Zs18;
struct YX0i__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YX0i__T;
typedef struct {
 Zoh *np;
 char text[22];
} Zs22;
typedef struct {
 Zoh *np;
 char text[23];
} Zs23;
struct YP_P__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YP_P__T;
struct YzSI__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YzSI__T;
struct YXKl__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YXKl__T;
typedef struct {
 Zoh *np;
 char text[15];
} Zs15;
struct YuDC__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YuDC__T;
struct YrHq__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YrHq__T;
/* EModule done */
/* including PIPEModule structs */
struct YK7s__S {
 Zoh *np;
 Tb VisOpen;
 Ti VbufferSize;
 Tl *VitemList;
 YlXt *Vlock;
 Y0Wo *VreadCond;
 Y0Wo *VwriteCond;
};
extern Tto YK7s__T;
/* PIPEModule done */
/* including SYSModule structs */
struct Y2SD__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y2SD__T;
typedef struct {
 Zoh *np;
 char text[8];
} Zs8;
typedef struct {
 Zoh *np;
 char text[29];
} Zs29;
typedef struct {
 Zoh *np;
 char text[53];
} Zs53;
typedef struct {
 Zoh *np;
 char text[36];
} Zs36;
typedef struct {
 Zoh *np;
 char text[37];
} Zs37;
typedef struct {
 Zoh *np;
 char text[24];
} Zs24;
struct YDTf__S {
 Zoh *np;
 Tc *Vcmd;
 Tl *Varglist;
 Ti VabortTimeout;
 Tb Vstarted;
 Tb Vexited;
 Ti Vpid;
 Tb VdidExit;
 Ti VexitValue;
 Tc *VstdinFname;
 Tc *VstdoutFname;
 Tc *VstderrFname;
 Tb VstderrToStdout;
};
extern Tto YDTf__T;
/* SYSModule done */
/* including HTTPModule structs */
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
struct Yd7N__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yd7N__T;
struct Ys_q__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Ys_q__T;
typedef struct {
 Zoh *np;
 char text[16];
} Zs16;
struct YOEA__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YOEA__T;
struct YqvM__S {
 Zoh *np;
 Tc *Vname;
 Ti Vnr;
 Te Vtype;
 Tb Vrepeated;
};
extern Tto YqvM__T;
struct YLWE__S {
 Zoh *np;
 Tr Vwriter;
 Tc *Vindent;
 Tb VuseNr;
 Ti VderefId;
 Ti VderefIdSize;
 Ti VderefTime;
 Ti VderefTimeSize;
};
extern Tto YLWE__T;
struct YBRp__S {
 Zoh *np;
 YrC3 *VtheCharReader;
 Td *Vrefs;
 Ti Vlnum;
};
extern Tto YBRp__T;
typedef struct {
 Zoh *np;
 char text[34];
} Zs34;
typedef struct {
 Zoh *np;
 char text[38];
} Zs38;
typedef struct {
 Zoh *np;
 char text[42];
} Zs42;
typedef struct {
 Zoh *np;
 char text[47];
} Zs47;
typedef struct {
 Zoh *np;
 char text[44];
} Zs44;
typedef struct {
 Zoh *np;
 char text[57];
} Zs57;
typedef struct {
 Zoh *np;
 char text[25];
} Zs25;
typedef struct {
 Zoh *np;
 char text[30];
} Zs30;
typedef struct {
 Zoh *np;
 char text[2];
} Zs2;
typedef struct {
 Zoh *np;
 char text[31];
} Zs31;
struct YKxQ__S {
 Zoh *np;
 Tc *Vname;
 Tcb *VcreateFromJson;
 Tcb *VcreateResponse;
};
extern Tto YKxQ__T;
/* Proto done */
char *MHTTPModule__ERequestType[] = {
 (char*)9,
 "unknown",
 "options",
 "get",
 "head",
 "post",
 "put",
 "delete",
 "trace",
 "connect",
};
char *MHTTPModule__ERequestType__name(Te n) {
 return (n < 0 || n >= (Te)(size_t)MHTTPModule__ERequestType[0]) ? "INVALID" : MHTTPModule__ERequestType[n + 1];
};
struct YSM1__S {
 Zoh *np;
 Te Vtype;
 Tc *Vpath;
 Tc *Vparams;
 Tc *VhttpVersion;
 Td *VheaderItems;
 Tc *Vbody;
 Td *VparamItems;
};
extern Tto YSM1__T;
typedef struct {
 Zoh *np;
 char text[26];
} Zs26;
struct YKeB__S {
 Zoh *np;
 Ti Vcode;
 Tc *Vmsg;
 Td *VheaderItems;
 Tc *Vbody;
};
extern Tto YKeB__T;
struct YtzZ__S {
 Zoh *np;
 Y1QG *Vserver;
 YSM1 *Vrequest;
 YKeB *Vresponse;
};
extern Tto YtzZ__T;
typedef struct {
 Zoh *np;
 char text[48];
} Zs48;
typedef struct {
 Zoh *np;
 char text[20];
} Zs20;
typedef struct {
 Zoh *np;
 char text[19];
} Zs19;
struct YphE__S {
 Zoh *np;
Tc *Vname;
Tl *Vpaths;
Tc *VmimeType;
 Tc *VtoURL;
 Ti Vcode;
};
extern Tto YphE__T;
struct YX8j__S {
 Zoh *np;
Tc *Vname;
Tl *Vpaths;
Tc *VmimeType;
 Tc *VfileName;
};
extern Tto YX8j__T;
struct YIgO__S {
 Zoh *np;
Tc *Vname;
Tl *Vpaths;
Tc *VmimeType;
 Tc *Vbody;
};
extern Tto YIgO__T;
struct Yivg__S {
 Zoh *np;
 YKxQ *VrpcInfo;
 Tcb *Vhandler;
};
extern Tto Yivg__T;
typedef struct {
 Zoh *np;
 char text[35];
} Zs35;
struct YntX__S {
 Zoh *np;
Tc *Vname;
Tl *Vpaths;
Tc *VmimeType;
 Td *Vservices;
};
extern Tto YntX__T;
typedef struct {
 Zoh *np;
 char text[33];
} Zs33;
struct Y1QG__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
Tcb *Vproc;
Te Vstate;
pthread_t Vthread_id;
Tl *Vstack;
 Ti Vport;
 Ti VlistenQueueLen;
 Tl *Vservlets;
 Tc *VfileRoot;
 Tc *Vbase;
 Te Vverbosity;
 YK7s *VquitPipe;
 Tb VdidQuit;
 Tb Vbusy;
};
extern Tto Y1QG__T;
/* HTTPModule done */
/* including ZModule structs */
struct YkxB__S {
 Zoh *np;
 Tc *Vfilename;
 Ti Vlnum;
 Ti Vcol;
 Tc *Vtext;
};
extern Tto YkxB__T;
/* ZModule done */
/* including IOModule structs */
typedef struct {
 Zoh *np;
 char text[27];
} Zs27;
struct Yw8L__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
 FILE * Vfd;
 Tc *Vname;
};
extern Tto Yw8L__T;
struct YtZ0__S {
 Zoh *np;
 Ti VbyteIdx;
 Ti VbyteSize;
 Tc *Vdata;
};
extern Tto YtZ0__T;
struct YrC3__S {
 Zoh *np;
 Tr Vreader;
 Tl *Vstack;
};
extern Tto YrC3__T;
typedef struct {
 Zoh *np;
 char text[32];
} Zs32;
struct YjUM__S {
 Zoh *np;
 Ti VsLen;
 Ta *Vs;
 Tc *Vx;
};
extern Tto YjUM__T;
typedef struct {
 Zoh *np;
 char text[54];
} Zs54;
/* IOModule done */
/* including THREADModule structs */
/* including Config structs */
typedef struct {
 Zoh *np;
 char text[46];
} Zs46;
/* Config done */
struct YgC4__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YgC4__T;
struct YTgs__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
Te Vstate;
pthread_t Vthread_id;
Tl *Vstack;
 Tcb *Vproc;
};
extern Tto YTgs__T;
struct YlXt__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
 pthread_mutex_t Vmutex;
};
extern Tto YlXt__T;
struct Y0Wo__S {
 Zoh *np;
 pthread_cond_t Vcond;
};
extern Tto Y0Wo__T;
/* THREADModule done */
/* including ZWTModule structs */
typedef struct {
 Zoh *np;
 char text[160];
} Zs160;
typedef struct {
 Zoh *np;
 char text[394];
} Zs394;
typedef struct {
 Zoh *np;
 char text[602];
} Zs602;
/* ZWTModule done */
/* including CHECKModule structs */
typedef struct {
 Zoh *np;
 char text[21];
} Zs21;
/* CHECKModule done */
/* including ARGModule structs */
struct YnU5__S {
 Zoh *np;
};
extern Tto YnU5__T;
typedef struct {
 Zoh *np;
 char text[51];
} Zs51;
typedef struct {
 Zoh *np;
 char text[58];
} Zs58;
typedef struct {
 Zoh *np;
 char text[56];
} Zs56;
typedef struct {
 Zoh *np;
 char text[43];
} Zs43;
struct YuMQ__S {
 Zoh *np;
 Tc *Vtext;
};
extern Tto YuMQ__T;
typedef struct {
 Zoh *np;
 char text[50];
} Zs50;
typedef struct {
 Zoh *np;
 char text[52];
} Zs52;
struct Y86c__S {
 Zoh *np;
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
 Zoh *np;
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
 Zoh *np;
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
 Zoh *np;
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
/* including liveDemoPage structs */
/* including buildzimbu structs */
struct YwcI__S {
 Zoh *np;
Ti VderefTime;
Ti VderefId;
Ti VderefTimeSize;
Ti VderefIdSize;
 Tc *Vf_code;
};
extern Tto YwcI__T;
struct YWgO__S {
 Zoh *np;
Ti VderefTime;
Ti VderefId;
Ti VderefTimeSize;
Ti VderefIdSize;
 Tc *Vf_compilerMessages;
 Tc *Vf_runOutput;
};
extern Tto YWgO__T;
/* buildzimbu done */
/* liveDemoPage done */
/* including BuildZimbuServlet structs */
typedef struct {
 Zoh *np;
 char text[55];
} Zs55;
struct YvG2__S {
 Zoh *np;
Td *Vservices;
Tc *Vname;
Tl *Vpaths;
Tc *VmimeType;
};
extern Tto YvG2__T;
/* BuildZimbuServlet done */
struct Tcallback__S {
 Zoh *np;
 void *cfunc;
 int toCount;
};
/*
 * DECLARE FUNCTIONS AND GLOBALS
 */
Zs5 ZNilString = {&Zstatic, "\003NIL\000"};
/* including TIMEModule declarations */
Ti Y9Rj(); /* MTIMEModule.current */
void YQzL(Ti Ausec); /* MTIMEModule.sleep */
/* TIMEModule done */
/* including EModule declarations */
Ytlm *YRHR(Ytlm *t, Tc *Amsg); /* MEModule__CException.NEW */
Tc *YH0V(Ytlm *t); /* MEModule__CException.ToString */
void YxaJ(Ytlm *t, Tr Aw); /* MEModule__CException.writeTo */
Zs4 YFDa = {&Zstatic, "\002: \000"};
Zs13 YHbP = {&Zstatic, "\013Exception: \000"};
Zs11 YDGe = {&Zstatic, "\011Exception\000"};
Tc *Yoww(Ytlm *t, Tb Averbose); /* MEModule__CException.toString */
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw); /* MEModule__CException.writeTo */
Zs39 Y62e = {&Zstatic, "\045\nStack backtrace (last called first):\000"};
Zs12 Yv6_ = {&Zstatic, "\012\n(unknown)\000"};
Zs3 Yk = {&Zstatic, "\001\n\000"};
Tc *Ytlm__Ytlm_I_imt[14];
To ToYtlm[4];
char *StrYtlm[];
void YScq(Ti Apos, Tc *Atext); /* MEModule.throwException */
YEro *YE2c(YEro *t, Ti Avalue); /* MEModule__CExit.NEW */
Zs7 YxJ1 = {&Zstatic, "\005EXIT \000"};
Tc *Ydtua(YEro *t); /* MEModule__CExit.ToString */
void YXHSa(YEro *t, Tr Aw); /* MEModule__CExit.writeTo */
Tc *YEro__Yoww(YEro *t, Tb Averbose); /* MEModule__CExit.toString__p1 */
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw); /* MEModule__CExit.writeTo__p1 */
Tc *YEro__Ytlm_I_imt[14];
To ToYEro[5];
char *StrYEro[];
Zs6 YJMo = {&Zstatic, "\004Exit\000"};
void YNab(YkxB *Apos, Ti Aval); /* MEModule.throwExit */
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit); /* MEModule__COutOfMemory.NEW */
Zs28 YIBz = {&Zstatic, "\032Out of memory (allocating \000"};
Zs9 YDSH = {&Zstatic, "\007 bytes)\000"};
Tc *YKhn__YwtA__YH0V(YKhn *t); /* MEModule__COutOfMemory.ToString__p2 */
Tc *YKhn__YwtA__Yoww(YKhn *t, Tb Averbose); /* MEModule__COutOfMemory.toString__p2 */
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
Tc *YKhn__Ytlm_I_imt[14];
To ToYKhn[4];
char *StrYKhn[];
Zs13 Y9Fv = {&Zstatic, "\013OutOfMemory\000"};
void Y1KV(Ti Asize); /* MEModule.throwOutOfMemorySize */
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg); /* MEModule__CNilAccess.NEW__p2 */
Tc *Y1uN__YwtA__YH0V(Y1uN *t); /* MEModule__CNilAccess.ToString__p2 */
Tc *Y1uN__YwtA__Yoww(Y1uN *t, Tb Averbose); /* MEModule__CNilAccess.toString__p2 */
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
Tc *Y1uN__Ytlm_I_imt[14];
To ToY1uN[4];
char *StrY1uN[];
Zs11 Y4wO = {&Zstatic, "\011NilAccess\000"};
void YvdV(YkxB *Apos, Tc *Atext); /* MEModule.throwNil */
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg); /* MEModule__CMemoryAccess.NEW__p2 */
Tc *YAxe__YwtA__YH0V(YAxe *t); /* MEModule__CMemoryAccess.ToString__p2 */
Tc *YAxe__YwtA__Yoww(YAxe *t, Tb Averbose); /* MEModule__CMemoryAccess.toString__p2 */
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
Tc *YAxe__Ytlm_I_imt[14];
To ToYAxe[4];
char *StrYAxe[];
Zs14 Y4QW = {&Zstatic, "\014MemoryAccess\000"};
void YE93(Ti Anr); /* MEModule.throwDeadly */
Zs13 YkfG = {&Zstatic, "\013signal SEGV\000"};
Zs12 YoEx = {&Zstatic, "\012signal FPE\000"};
Zs12 YQNH = {&Zstatic, "\012signal BUS\000"};
Zs9 YpCZ = {&Zstatic, "\007signal \000"};
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
Tc *YVNj__YwtA__YH0V(YVNj *t); /* MEModule__CInit.ToString__p2 */
Tc *YVNj__YwtA__Yoww(YVNj *t, Tb Averbose); /* MEModule__CInit.toString__p2 */
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw); /* MEModule__CInit.writeTo__p2 */
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw); /* MEModule__CInit.writeTo__p2 */
Tc *YVNj__Ytlm_I_imt[14];
To ToYVNj[4];
char *StrYVNj[];
Zs6 Ysqt = {&Zstatic, "\004Init\000"};
void Y3w6(Tc *Atext); /* MEModule.throwInit */
YtEE *YtEE__YwtA__YRHRa(YtEE *t, YkxB *Apos, Tc *Amsg); /* MEModule__CCheck.NEW__p2 */
Tc *YtEE__YwtA__YH0V(YtEE *t); /* MEModule__CCheck.ToString__p2 */
Tc *YtEE__YwtA__Yoww(YtEE *t, Tb Averbose); /* MEModule__CCheck.toString__p2 */
void YtEE__YwtA__YxaJa(YtEE *t, Tb Averbose, Tr Aw); /* MEModule__CCheck.writeTo__p2 */
void YtEE__YwtA__YxaJ(YtEE *t, Tr Aw); /* MEModule__CCheck.writeTo__p2 */
Tc *YtEE__Ytlm_I_imt[14];
To ToYtEE[4];
char *StrYtEE[];
Zs7 YvUM = {&Zstatic, "\005Check\000"};
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg); /* MEModule__CBadValue.NEW__p2 */
Tc *Yalz__YwtA__YH0V(Yalz *t); /* MEModule__CBadValue.ToString__p2 */
Tc *Yalz__YwtA__Yoww(Yalz *t, Tb Averbose); /* MEModule__CBadValue.toString__p2 */
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
Tc *Yalz__Ytlm_I_imt[14];
To ToYalz[4];
char *StrYalz[];
Zs10 YEZq = {&Zstatic, "\010BadValue\000"};
void Yaez(Tc *Atext); /* MEModule.throwBadValue */
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg); /* MEModule__COutOfRange.NEW__p3 */
Tc *Yw3O__Yalz__YwtA__YH0V(Yw3O *t); /* MEModule__COutOfRange.ToString__p3 */
Tc *Yw3O__Yalz__YwtA__Yoww(Yw3O *t, Tb Averbose); /* MEModule__COutOfRange.toString__p3 */
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
Tc *Yw3O__Ytlm_I_imt[14];
To ToYw3O[4];
char *StrYw3O[];
Zs12 YFK2 = {&Zstatic, "\012OutOfRange\000"};
void Y6NT(Ti Aindex, Tc *Amsg); /* MEModule.throwOutOfRange */
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg); /* MEModule__CKeyNotFound.NEW__p3 */
Tc *Y2EX__Yalz__YwtA__YH0V(Y2EX *t); /* MEModule__CKeyNotFound.ToString__p3 */
Tc *Y2EX__Yalz__YwtA__Yoww(Y2EX *t, Tb Averbose); /* MEModule__CKeyNotFound.toString__p3 */
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
Tc *Y2EX__Ytlm_I_imt[14];
To ToY2EX[4];
char *StrY2EX[];
Zs13 YRiW = {&Zstatic, "\013KeyNotFound\000"};
void Yxmk(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyNotFound */
Zs17 Ym6C = {&Zstatic, "\017Key not found: \000"};
void Y5LT(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyNotFound */
Zs18 YJ3Y = {&Zstatic, "\020Key not found: \"\000"};
Zs3 YI = {&Zstatic, "\001\"\000"};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
Tc *YX0i__Yalz__YwtA__YH0V(YX0i *t); /* MEModule__CKeyExists.ToString__p3 */
Tc *YX0i__Yalz__YwtA__Yoww(YX0i *t, Tb Averbose); /* MEModule__CKeyExists.toString__p3 */
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
Tc *YX0i__Ytlm_I_imt[14];
To ToYX0i[4];
char *StrYX0i[];
Zs11 Y9_h = {&Zstatic, "\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {&Zstatic, "\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {&Zstatic, "\025Key already exists: \"\000"};
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg); /* MEModule__CIllegalByte.NEW__p3 */
Tc *YP_P__Yalz__YwtA__YH0V(YP_P *t); /* MEModule__CIllegalByte.ToString__p3 */
Tc *YP_P__Yalz__YwtA__Yoww(YP_P *t, Tb Averbose); /* MEModule__CIllegalByte.toString__p3 */
void YP_P__Yalz__YwtA__YxaJ(YP_P *t, Tr Aw); /* MEModule__CIllegalByte.writeTo__p3 */
void YP_P__Yalz__YwtA__YxaJa(YP_P *t, Tb Averbose, Tr Aw); /* MEModule__CIllegalByte.writeTo__p3 */
Tc *YP_P__Ytlm_I_imt[14];
To ToYP_P[4];
char *StrYP_P[];
Zs13 Ydbm = {&Zstatic, "\013IllegalByte\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
Tc *YzSI__Ylz1__YwtA__YH0V(YzSI *t); /* MEModule__CDivideByZero.ToString__p3 */
Tc *YzSI__Ylz1__YwtA__Yoww(YzSI *t, Tb Averbose); /* MEModule__CDivideByZero.toString__p3 */
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
Tc *YzSI__Ytlm_I_imt[14];
To ToYzSI[4];
char *StrYzSI[];
Zs14 YxFl = {&Zstatic, "\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
Tc *YXKl__YwtA__YH0V(YXKl *t); /* MEModule__CIOError.ToString__p2 */
Tc *YXKl__YwtA__Yoww(YXKl *t, Tb Averbose); /* MEModule__CIOError.toString__p2 */
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
Tc *YXKl__Ytlm_I_imt[14];
To ToYXKl[4];
char *StrYXKl[];
Zs9 YTj3 = {&Zstatic, "\007IOError\000"};
void YkuV(Tc *Amsg); /* MEModule.throwIOError */
YuDC *YdhH(YuDC *t); /* MEModule__CWrongType.NEW */
Zs15 Ynjz = {&Zstatic, "\015Type mismatch\000"};
Tc *YuDC__YwtA__YH0V(YuDC *t); /* MEModule__CWrongType.ToString__p2 */
Tc *YuDC__YwtA__Yoww(YuDC *t, Tb Averbose); /* MEModule__CWrongType.toString__p2 */
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
Tc *YuDC__Ytlm_I_imt[14];
To ToYuDC[4];
char *StrYuDC[];
Zs11 YCoZ = {&Zstatic, "\011WrongType\000"};
void YTuG(Ti Apos); /* MEModule.throwWrongType */
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg); /* MEModule__CInternal.NEW__p2 */
Tc *YrHq__YwtA__YH0V(YrHq *t); /* MEModule__CInternal.ToString__p2 */
Tc *YrHq__YwtA__Yoww(YrHq *t, Tb Averbose); /* MEModule__CInternal.toString__p2 */
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
Tc *YrHq__Ytlm_I_imt[14];
To ToYrHq[4];
char *StrYrHq[];
Zs10 YVki = {&Zstatic, "\010Internal\000"};
void YUSH(YkxB *Apos, Tc *Atext); /* MEModule.throwInternal */
void YxIS(Tr Ae); /* MEModule.unhandledException */
void YvL0(Tr Ae); /* MEModule.writeToStderr */
void YQar(Tr A0, Tb A1, Tr A2); /* Ytlm_I__MwriteTo_I__bool__Yw8L_I */
/* EModule done */
/* including PIPEModule declarations */
YK7s *YPsV(YK7s *t); /* MPIPEModule__CPipe__t1.NEW */
Ts YWty(YK7s *t, Tb Aitem); /* MPIPEModule__CPipe__t1.write */
Tb YIWK(YK7s *t, Ts *Rst); /* MPIPEModule__CPipe__t1.read */
Tb YIWKa(YK7s *t); /* MPIPEModule__CPipe__t1.read */
To ToYK7s[7];
char *StrYK7s[];
Zs10 YLJT = {&Zstatic, "\010Pipe__t1\000"};
/* PIPEModule done */
/* including SYSModule declarations */
Ti YMso(Tc *Acommand); /* MSYSModule.shell */
Ti Yyxi(Tc *Acommand); /* MSYSModule.shellBackground */
Zs3 YM = {&Zstatic, "\001&\000"};
Tc *Yhy5(Tc *Aname); /* MSYSModule.getEnv */
Y2SD *Y2SD__YwtA__YRHR(Y2SD *t, Tc *Amsg); /* MSYSModule__CE_Process.NEW__p2 */
Tc *Y2SD__YwtA__YH0V(Y2SD *t); /* MSYSModule__CE_Process.ToString__p2 */
Tc *Y2SD__YwtA__Yoww(Y2SD *t, Tb Averbose); /* MSYSModule__CE_Process.toString__p2 */
void Y2SD__YwtA__YxaJa(Y2SD *t, Tb Averbose, Tr Aw); /* MSYSModule__CE_Process.writeTo__p2 */
void Y2SD__YwtA__YxaJ(Y2SD *t, Tr Aw); /* MSYSModule__CE_Process.writeTo__p2 */
Tc *Y2SD__Ytlm_I_imt[14];
To ToY2SD[4];
char *StrY2SD[];
Zs11 YYbB = {&Zstatic, "\011E_Process\000"};
Ts YNAV(Tc *Apage); /* MSYSModule.openInBrowser */
Zs9 Y1ke = {&Zstatic, "\007BROWSER\000"};
Zs15 Ya0g = {&Zstatic, "\015/Applications\000"};
Zs8 Y0rB = {&Zstatic, "\006open '\000"};
Zs3 YN = {&Zstatic, "\001'\000"};
Zs15 YCuE = {&Zstatic, "\015google-chrome\000"};
Zs9 YwLx = {&Zstatic, "\007firefox\000"};
Zs8 YUjM = {&Zstatic, "\006safari\000"};
Zs7 YJPW = {&Zstatic, "\005opera\000"};
Zs4 Y6Qb = {&Zstatic, "\002ie\000"};
Zs4 Y5Y = {&Zstatic, "\002 '\000"};
YDTf *YV43(YDTf *t, Tc *Acmd); /* MSYSModule__CProcess.NEW */
YDTf *YCLu(YDTf *t); /* MSYSModule__CProcess.start */
Zs29 Yv1H = {&Zstatic, "\033process was already started\000"};
Zs53 YrFO = {&Zstatic, "\063Stderr has a file name while it's written to stdout\000"};
Zs36 Y_Ng = {&Zstatic, "\042Cannot open stdin file for reading\000"};
Zs37 Ygc3 = {&Zstatic, "\043Cannot open stdout file for writing\000"};
Zs37 Yn1N = {&Zstatic, "\043Cannot open stderr file for writing\000"};
Zs13 YaSc = {&Zstatic, "\013Cannot fork\000"};
Tb YHdE(YDTf *t); /* MSYSModule__CProcess.isRunning */
Ts YJmKa(YDTf *t, Ti Atimeout); /* MSYSModule__CProcess.wait */
YDTf *YYXC(YDTf *t); /* MSYSModule__CProcess.kill */
Zs29 Y5p2 = {&Zstatic, "\033process was not started yet\000"};
Zs24 YNx4 = {&Zstatic, "\026process already exited\000"};
YDTf *YkM8(YDTf *t, Tc *Afname); /* MSYSModule__CProcess.writeTo */
YDTf *Y0ha(YDTf *t, Tb Ayes); /* MSYSModule__CProcess.writeErrorsToOut */
Ti Ybv7 = 123 /* MSYSModule__CProcess__X.exec_failed_status */;
To ToYDTf[13];
char *StrYDTf[];
Zs9 Y8vv = {&Zstatic, "\007Process\000"};
Zs9 YVbO = {&Zstatic, "\007IOFlags\000"};
Tt MSYSModule__BIOFlags__T = {25, ((Tc*)&YVbO), 0};
/* SYSModule done */
/* including HTTPModule declarations */
/* including Proto declarations */
Tt MProto__EType__T = {23, 0, MProto__EType__name};
Tt MProto__EBinaryType__T = {23, 0, 0};
Tt MProto__EFileFormat__T = {23, 0, 0};
Yd7N *Yd7N__YwtA__YRHR(Yd7N *t, Tc *Amsg); /* MProto__CE_ParseError.NEW__p2 */
Tc *Yd7N__YwtA__YH0V(Yd7N *t); /* MProto__CE_ParseError.ToString__p2 */
Tc *Yd7N__YwtA__Yoww(Yd7N *t, Tb Averbose); /* MProto__CE_ParseError.toString__p2 */
void Yd7N__YwtA__YxaJa(Yd7N *t, Tb Averbose, Tr Aw); /* MProto__CE_ParseError.writeTo__p2 */
void Yd7N__YwtA__YxaJ(Yd7N *t, Tr Aw); /* MProto__CE_ParseError.writeTo__p2 */
Tc *Yd7N__Ytlm_I_imt[14];
To ToYd7N[4];
char *StrYd7N[];
Zs14 Y8kY = {&Zstatic, "\014E_ParseError\000"};
Ys_q *Ys_q__YwtA__YRHR(Ys_q *t, Tc *Amsg); /* MProto__CE_ProduceError.NEW__p2 */
Tc *Ys_q__YwtA__YH0V(Ys_q *t); /* MProto__CE_ProduceError.ToString__p2 */
Tc *Ys_q__YwtA__Yoww(Ys_q *t, Tb Averbose); /* MProto__CE_ProduceError.toString__p2 */
void Ys_q__YwtA__YxaJa(Ys_q *t, Tb Averbose, Tr Aw); /* MProto__CE_ProduceError.writeTo__p2 */
void Ys_q__YwtA__YxaJ(Ys_q *t, Tr Aw); /* MProto__CE_ProduceError.writeTo__p2 */
Tc *Ys_q__Ytlm_I_imt[14];
To ToYs_q[4];
char *StrYs_q[];
Zs16 Y4sk = {&Zstatic, "\016E_ProduceError\000"};
YOEA *YOEA__YwtA__YRHR(YOEA *t, Tc *Amsg); /* MProto__CE_BinaryError.NEW__p2 */
Tc *YOEA__YwtA__YH0V(YOEA *t); /* MProto__CE_BinaryError.ToString__p2 */
Tc *YOEA__YwtA__Yoww(YOEA *t, Tb Averbose); /* MProto__CE_BinaryError.toString__p2 */
void YOEA__YwtA__YxaJa(YOEA *t, Tb Averbose, Tr Aw); /* MProto__CE_BinaryError.writeTo__p2 */
void YOEA__YwtA__YxaJ(YOEA *t, Tr Aw); /* MProto__CE_BinaryError.writeTo__p2 */
Tc *YOEA__Ytlm_I_imt[14];
To ToYOEA[4];
char *StrYOEA[];
Zs15 YtJ_ = {&Zstatic, "\015E_BinaryError\000"};
YqvM *Ykww(YqvM *t, Tc *Aname, Ti Anr, Te Atype, Tb Arepeated); /* MProto__CFieldSpec.NEW */
To ToYqvM[5];
char *StrYqvM[];
Zs11 Y5d5 = {&Zstatic, "\011FieldSpec\000"};
YLWE *YrCUa(YLWE *t, Tr Awriter, Tb AwithRefs); /* MProto__CWriter.NEW */
YLWE *YrCUb(YLWE *t, Tr Awriter, Tc *Aindent, Tb AuseNr); /* MProto__CWriter.NEW */
void YEV9(YLWE *t); /* MProto__CWriter.initDeref */
Ti YcTI = 0; /* MProto__CWriter__X.derefTime */
To ToYLWE[8];
char *StrYLWE[];
Zs8 YaKG = {&Zstatic, "\006Writer\000"};
int YRBz__r = 0; /* MProto__CReader.Ready */
YBRp *YRBz(YBRp *t); /* MProto__CReader.Init */
YBRp *YtIRa(YBRp *t, Tr Areader, Tb AwithRefs); /* MProto__CReader.NEW */
YrC3 *Ytm4(YBRp *t); /* MProto__CReader.charReader */
YBRp *Y9eV(YBRp *t); /* MProto__CReader.protoReader */
Tr YnlR(YBRp *t, Ti Aidx); /* MProto__CReader.getRef */
Tc *YBRp__YMd3_imt[5];
To ToYBRp[4];
char *StrYBRp[];
Zs8 Y0Er = {&Zstatic, "\006Reader\000"};
Td *YXCQ = NULL; /* MProto.proto2binary */
Td *YLwW = NULL; /* MProto.binaryTypeValues */
Ti YqNA = 3 /* MProto.kTypeBits */;
Ti Ybyp(YqvM *Afspec); /* MProto.getBinaryTagSize */
Ti YFN0(Tr Amsg, YLWE *AprotoWriter); /* MProto.binarySize */
Zs34 Ytvm = {&Zstatic, "\040INTERNAL: type not implemented: \000"};
Ti YMrV(Tr At, Tr Amsg, YqvM *Afspec, YLWE *AprotoWriter); /* MProto.binaryMessageSize */
void YP8Z(Tr Amsg, YLWE *AprotoWriter); /* MProto.writeText */
Zs15 YvJi = {&Zstatic, "\015# reference: \000"};
Zs3 YT = {&Zstatic, "\001-\000"};
Zs4 YN2 = {&Zstatic, "\002# \000"};
Zs9 Y0Eh = {&Zstatic, "\007 size: \000"};
Zs9 Y8RH = {&Zstatic, "\007 bytes\n\000"};
void YWEg(Tr Amsg, YqvM *Afspec, Ti Aidx, YLWE *AprotoWriter); /* MProto.writeOneTextField */
Zs5 YxR2 = {&Zstatic, "\003.9g\000"};
Zs6 YmwI = {&Zstatic, "\004.17g\000"};
Zs6 YHoE = {&Zstatic, "\004TRUE\000"};
Zs7 Y2cy = {&Zstatic, "\005FALSE\000"};
Zs4 YQ0 = {&Zstatic, "\002\"\n\000"};
Zs4 Ywhc = {&Zstatic, "\002{\n\000"};
Zs4 YZY = {&Zstatic, "\002  \000"};
Zs4 YJkc = {&Zstatic, "\002}\n\000"};
Zs38 Y80t = {&Zstatic, "\044INTERNAL: field type not supported: \000"};
void YeeB(Tr At, Ti AfieldNr, YLWE *AprotoWriter); /* MProto.writeMessageText */
void YeeBa(Tr At, Ti AfieldNr, Ti Aidx, YLWE *AprotoWriter); /* MProto.writeMessageText */
void YsvG(Tr Amsg, Tl *Afspecs, Tr AiReader); /* MProto.mergeFromJsonFields */
Zs42 YP1D = {&Zstatic, "\050Missing [ at start of Json message, got \000"};
Zs38 YDDS = {&Zstatic, "\044Syntax error in Json: Unexpected EOF\000"};
Zs47 Y3Sh = {&Zstatic, "\055Syntax error in Json: can't read field number\000"};
Zs44 YACF = {&Zstatic, "\052Syntax error in Json: field number wrong: \000"};
Zs57 YQxb = {&Zstatic, "\067Syntax error in Json: missing comma after field number \000"};
Zs39 YtkV = {&Zstatic, "\045Missing comma in repeated field, got \000"};
Zs9 YgO5 = {&Zstatic, "\007 after \000"};
Zs8 Y54q = {&Zstatic, "\006 items\000"};
Zs39 Y9tS = {&Zstatic, "\045Expected [ at start of repeated field\000"};
Zs37 Yq6r = {&Zstatic, "\043Syntax error in Json: missing comma\000"};
Tb Yq4x(Tr Amsg, YqvM *Afspec, Tr AiReader); /* MProto.mergeOneJsonField */
Zs24 Y3FC = {&Zstatic, "\026Unexpected end of Json\000"};
Zs25 YE6N = {&Zstatic, "\027Expected a number, got \000"};
Zs30 Yo2d = {&Zstatic, "\034Unexpected message reference\000"};
Zs29 YmWB = {&Zstatic, "\033Message reference missing: \000"};
void YigD(Tr Amsg, YLWE *AjsonWriter); /* MProto.writeJson */
Zs3 YCa = {&Zstatic, "\001[\000"};
Zs2 Ya = {&Zstatic, "\000\000"};
Zs3 YS = {&Zstatic, "\001,\000"};
Zs3 YX = {&Zstatic, "\0011\000"};
Zs3 YW = {&Zstatic, "\0010\000"};
Zs3 YEa = {&Zstatic, "\001]\000"};
void Yly_(Ti Anr, Ti AlastProducedField, Tr Awriter); /* MProto.writeJsonFieldLeader */
void YL6X(Tr Amsg, YqvM *Afspec, YLWE *AprotoWriter); /* MProto.writeMessageJson */
Ti YmeT(Ti Avalue); /* MProto.getVarIntSize */
Ti YZHh(YrC3 *Areader); /* MProto.readJsonNumber */
Tf YHTg(YrC3 *Areader); /* MProto.readJsonDouble */
Tc *YB1v(YrC3 *Areader); /* MProto.readJsonString */
Zs18 Yfvl = {&Zstatic, "\020Truncated string\000"};
void YzK3(YrC3 *Areader); /* MProto.skipJsonField */
Zs28 Yuq6 = {&Zstatic, "\032Missing comma in Json list\000"};
Zs31 Y_9Q = {&Zstatic, "\035Not implemented: skip message\000"};
Zs22 YRr3 = {&Zstatic, "\024Syntax error in Json\000"};
void YwCv(Tc *As, Tr Awriter); /* MProto.writeJsonString */
Zs4 Ycvb = {&Zstatic, "\002\\\"\000"};
Zs4 Y7vb = {&Zstatic, "\002\\\\\000"};
Zs4 Ydwb = {&Zstatic, "\002\\b\000"};
Zs4 Yhwb = {&Zstatic, "\002\\f\000"};
Zs4 Ypwb = {&Zstatic, "\002\\n\000"};
Zs4 Ytwb = {&Zstatic, "\002\\r\000"};
Zs4 Yvwb = {&Zstatic, "\002\\t\000"};
Zs4 Ywwb = {&Zstatic, "\002\\u\000"};
YKxQ *YlyH(YKxQ *t, Tc *Aname, Tcb *AcreateFromJson, Tcb *AcreateResponse); /* MProto__CRpcInfo.NEW */
To ToYKxQ[4];
char *StrYKxQ[];
Zs9 Y2cL = {&Zstatic, "\007RpcInfo\000"};
void Yzyn(Tr A0, Ti A1, Tr A2); /* YFL0_I__MmessageAdd_I__int__YFL0_I */
void YslI(Tr A0, Ti A1, Tr A2); /* YFL0_I__MmessageSet_I__int__YFL0_I */
Tb YPR3(Tr A0, Ti A1, Te A2, Tr A3); /* YFL0_I__MmergeMessageFromReader_I__int__enumValue__YMd3_I */
int JProto(int round);
/* Proto done */
Tt MHTTPModule__ERequestType__T = {23, 0, MHTTPModule__ERequestType__name};
YSM1 *YF0N(YSM1 *t); /* MHTTPModule__CRequest.NEW */
Td *Yi2X(YSM1 *t); /* MHTTPModule__CRequest.paramDict */
Tc *YuPP(YSM1 *t); /* MHTTPModule__CRequest.ToString */
Zs8 Y5wx = {&Zstatic, "\006type: \000"};
Zs8 YXBd = {&Zstatic, "\006path: \000"};
Zs10 YrAc = {&Zstatic, "\010params: \000"};
Zs16 Y1xf = {&Zstatic, "\016HTTP version: \000"};
Zs15 YiH8 = {&Zstatic, "\015HEADER ITEMS:\000"};
Zs8 YLih = {&Zstatic, "\006Body: \000"};
To ToYSM1[8];
char *StrYSM1[];
Zs9 YFUt = {&Zstatic, "\007Request\000"};
YKeB *YikN(YKeB *t); /* MHTTPModule__CResponse.NEW */
Zs4 Y0ab = {&Zstatic, "\002OK\000"};
Zs26 Ylqg = {&Zstatic, "\030text/html; charset=UTF-8\000"};
Zs8 YBMI = {&Zstatic, "\006empty\n\000"};
void YjIQ(YKeB *t, Ti Alength); /* MHTTPModule__CResponse.setLength */
Zs16 Y95C = {&Zstatic, "\016Content-Length\000"};
void YDSB(YKeB *t, Tc *Atype); /* MHTTPModule__CResponse.setType */
Zs14 YPoL = {&Zstatic, "\014Content-Type\000"};
To ToYKeB[5];
char *StrYKeB[];
Zs10 YhQB = {&Zstatic, "\010Response\000"};
YtzZ *Y89Z(YtzZ *t, Y1QG *Aserver, YSM1 *Arequest, YKeB *Aresponse); /* MHTTPModule__CContext.NEW */
To ToYtzZ[4];
char *StrYtzZ[];
Zs9 Y36w = {&Zstatic, "\007Context\000"};
YphE *Ytlk(YphE *t, Tc *Ato); /* MHTTPModule__CRedirectServlet.NEW */
Zs17 YRBq = {&Zstatic, "\017RedirectServlet\000"};
Tb YSxaa(YphE *t, YtzZ *Acontext); /* MHTTPModule__CRedirectServlet.serve */
Zs47 Yme1 = {&Zstatic, "\055<html><head><title>Moved</title></head><body>\000"};
Zs48 Y8Uo = {&Zstatic, "\056<h1>Moved</h1>This page has moved to <a href='\000"};
Zs4 YG9 = {&Zstatic, "\002'>\000"};
Zs20 YFDK = {&Zstatic, "\022</a></body></html>\000"};
Zs19 YKIR = {&Zstatic, "\021Moved Permanently\000"};
Zs10 YEsW = {&Zstatic, "\010Location\000"};
void YphE__Y3fn(YphE *t, Tc *Apath); /* MHTTPModule__CRedirectServlet.addPath__p1 */
Tb YphE__YU_W(YphE *t, YtzZ *Acontext); /* MHTTPModule__CRedirectServlet.handle__p1 */
Tc *YphE__YtrZ_I_imt[9];
To ToYphE[6];
char *StrYphE[];
YX8j *Yb5K(YX8j *t, Tc *AfileName); /* MHTTPModule__CFileServlet.NEW */
Zs13 YAkv = {&Zstatic, "\013FileServlet\000"};
Tb Y3hma(YX8j *t, YtzZ *Acontext); /* MHTTPModule__CFileServlet.serve */
Zs10 Y95j = {&Zstatic, "\010reading \000"};
Zs3 YV = {&Zstatic, "\001/\000"};
void YX8j__Y3fn(YX8j *t, Tc *Apath); /* MHTTPModule__CFileServlet.addPath__p1 */
Tb YX8j__YU_W(YX8j *t, YtzZ *Acontext); /* MHTTPModule__CFileServlet.handle__p1 */
Tc *YX8j__YtrZ_I_imt[9];
To ToYX8j[5];
char *StrYX8j[];
YIgO *Y543(YIgO *t, Tc *Abody); /* MHTTPModule__CStringServlet.NEW */
Zs15 Y2iZ = {&Zstatic, "\015StringServlet\000"};
Tb YqXRa(YIgO *t, YtzZ *Acontext); /* MHTTPModule__CStringServlet.serve */
void YIgO__Y3fn(YIgO *t, Tc *Apath); /* MHTTPModule__CStringServlet.addPath__p1 */
Tb YIgO__YU_W(YIgO *t, YtzZ *Acontext); /* MHTTPModule__CStringServlet.handle__p1 */
Tc *YIgO__YtrZ_I_imt[9];
To ToYIgO[5];
char *StrYIgO[];
To ToYivg[3];
char *StrYivg[];
Zs9 Yesk = {&Zstatic, "\007Handler\000"};
void YvI9(YntX *t, YKxQ *ArpcInfo, Tcb *Ahandler); /* MHTTPModule__CRpcServlet.addHandler */
Zs35 Ybeb = {&Zstatic, "\041Adding already existing service: \000"};
Tb Yk9ua(YntX *t, YtzZ *Acontext); /* MHTTPModule__CRpcServlet.serve */
Zs6 Y4Po = {&Zstatic, "\004name\000"};
Zs36 YN6V = {&Zstatic, "\042binary/octet-stream; charset=UTF-8\000"};
void YntX__Y3fn(YntX *t, Tc *Apath); /* MHTTPModule__CRpcServlet.addPath__p1 */
Tb YntX__YU_W(YntX *t, YtzZ *Acontext); /* MHTTPModule__CRpcServlet.handle__p1 */
To ToYntX[5];
char *StrYntX[];
Zs12 Y103 = {&Zstatic, "\012RpcServlet\000"};
Tt MHTTPModule__EVerbosity__T = {23, 0, 0};
Y1QG *YAvl(Y1QG *t, Ti Aport); /* MHTTPModule__CServer.NEW */
Zs3 Y5 = {&Zstatic, "\001:\000"};
Zs8 Ycao = {&Zstatic, "\006/ZUDIR\000"};
void Yb8i(Y1QG *t, Tr Aservlet); /* MHTTPModule__CServer.addServlet */
void Yv7Q(Y1QG *t, Tc *Afrom, Tc *Ato); /* MHTTPModule__CServer.redirect */
void YVBU(Y1QG *t); /* MHTTPModule__CServer.body */
Zs12 Yj86 = {&Zstatic, "\012 params: '\000"};
Zs10 Ye88 = {&Zstatic, "\010HTTP/1.1\000"};
Zs13 YmUM = {&Zstatic, "\013 version: '\000"};
Zs24 YpFn = {&Zstatic, "\026Received HTTP request \000"};
Zs19 YUqj = {&Zstatic, "\021Request so far: '\000"};
Zs33 Yetr = {&Zstatic, "\037Warning: Request header too big\000"};
Zs3 YG = {&Zstatic, "\001 \000"};
Zs4 Ydha = {&Zstatic, "\002, \000"};
Zs17 Y5UY = {&Zstatic, "\017Header fields: \000"};
Zs16 YSBt = {&Zstatic, "\016content-length\000"};
Zs14 Y6Ov = {&Zstatic, "\014Body size = \000"};
Zs14 YLqJ = {&Zstatic, "\014Reading more\000"};
Zs13 Ylp1 = {&Zstatic, "\013Read size: \000"};
Zs11 YrD_ = {&Zstatic, "\011 bytes: '\000"};
Zs7 YKUO = {&Zstatic, "\005 ... \000"};
Zs18 Y_P0 = {&Zstatic, "\020Servlet failed: \000"};
Zs17 Yytr = {&Zstatic, "\017Page not found.\000"};
Zs37 YaLI = {&Zstatic, "\043Sorry, this page is not available.\n\000"};
Zs11 Y5E7 = {&Zstatic, "\011HTTP/1.1 \000"};
Zs4 Yau = {&Zstatic, "\002\r\n\000"};
Zs24 YkHK = {&Zstatic, "\026Sending HTTP response \000"};
Zs9 Y6wd = {&Zstatic, "\007Body: '\000"};
Ts YQj8(Y1QG *t, Tc *Apage); /* MHTTPModule__CServer.openInBrowser */
Zs19 YhLu = {&Zstatic, "\021http://localhost:\000"};
void YqJz(Y1QG *t); /* MHTTPModule__CServer.waitForExit */
void Y1QG__YTgs__Y7C8(Y1QG *t); /* MHTTPModule__CServer.startBody__p2 */
void Y1QG__YTgs__YSuw(Y1QG *t); /* MHTTPModule__CServer.start__p2 */
Zs14 YgzQ = {&Zstatic, "\014Thread start\000"};
Ts Y1QG__YTgs__Y2Cz(Y1QG *t, Te _fr); /* MHTTPModule__CServer.Finish__p2 */
void Y1QG__YcCua(Y1QG *t); /* MHTTPModule__CServer.body__p1 */
int Y1QGa__r = 0; /* Init/1().Ready */
Y1QG *Y1QGa(Y1QG *t); /* MHTTPModule__CServer.Init */
Zs18 YoWK = {&Zstatic, "\020http://localhost\000"};
To ToY1QG[13];
char *StrY1QG[];
Zs8 YooJ = {&Zstatic, "\006Server\000"};
Tb Y2jx(Ti Ac); /* MHTTPModule.isWhite */
int JHTTPModule(int round);
/* HTTPModule done */
/* including ZModule declarations */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {&Zstatic, "\016[unknown file]\000"};
Zs8 YBpY = {&Zstatic, "\006 line \000"};
Zs7 Y8ES = {&Zstatic, "\005 col \000"};
To ToYkxB[5];
char *StrYkxB[];
Zs5 YBCs = {&Zstatic, "\003Pos\000"};
/* ZModule done */
/* including STRINGModule declarations */
Tc *YO0w(Tc *Athis); /* MSTRINGModule.reverse */
Tc *Yvnf(Tc *Athis, Ti Afrom, Ti Ato); /* MSTRINGModule.replaceAll */
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
Ti YFeQ(Yw8L *t); /* MIOModule__CFile.readByte */
Zs18 YQe8 = {&Zstatic, "\020File is not open\000"};
Ti YAPp(Yw8L *t); /* MIOModule__CFile.readChar */
Zs27 YPHa = {&Zstatic, "\031first byte out of range: \000"};
Zs30 YKzT = {&Zstatic, "\034found EOF when getting byte \000"};
Zs7 Ymwv = {&Zstatic, "\005byte \000"};
Zs15 YPfW = {&Zstatic, "\015 out of range\000"};
Zs19 Y8Gn = {&Zstatic, "\021overlong sequence\000"};
Tc *Yyum(Yw8L *t); /* MIOModule__CFile.readAll */
Tc *YaEh(Yw8L *t); /* MIOModule__CFile.readLine */
Tl *YCm1a(Yw8L *t, Ti Acount); /* MIOModule__CFile.readAllLines */
Ts YwHoa(Yw8L *t, Tc *Atext); /* MIOModule__CFile.write */
Ts YrF8(Yw8L *t); /* MIOModule__CFile.close */
Ts YSo_(Yw8L *t, Te _fr); /* MIOModule__CFile.Finish */
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber); /* MIOModule__CFile.write__p1 */
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext); /* MIOModule__CFile.print__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__Yw8L_I_imt[38];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[2];
char *StrYw8L[];
Zs6 YtTU = {&Zstatic, "\004File\000"};
YtZ0 *YOD2(YtZ0 *t, Tc *Adata); /* MIOModule__CStringReader.NEW */
Ti YxQq(YtZ0 *t); /* MIOModule__CStringReader.readChar */
Tc *YtZ0__YFWV_imt[2];
To ToYtZ0[4];
char *StrYtZ0[];
Zs14 Yu_Y = {&Zstatic, "\014StringReader\000"};
YrC3 *Ynyh(YrC3 *t, Tr Areader); /* MIOModule__CCharReaderStack.NEW */
Ti YVZB(YrC3 *t); /* MIOModule__CCharReaderStack.readChar */
void Y3er(YrC3 *t, Ti Ac); /* MIOModule__CCharReaderStack.push */
To ToYrC3[3];
char *StrYrC3[];
Zs17 YmyU = {&Zstatic, "\017CharReaderStack\000"};
Tr YsGz(Tc *AfileName); /* MIOModule.fileReader */
Tr YiBk(Tc *AfileName, Tb Atruncate); /* MIOModule.fileWriter */
Ts Yhx8(); /* MIOModule.initSockets */
Tc *YDJh(Tc *AfileName); /* MIOModule.readFile */
Zs29 YroP = {&Zstatic, "\033IO.readFile(): Cannot open \000"};
Zs31 Y47X = {&Zstatic, "\035IO.readFile(): Seek error in \000"};
Zs32 Y9TS = {&Zstatic, "\036IO.readFile() Rewind error in \000"};
Zs30 YLjK = {&Zstatic, "\034IO.readFile() Read error in \000"};
Ts Yvcu(Tc *Atext); /* MIOModule.write */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Ts Ye7fa(YjUM *t, Ti Abyte); /* MIOModule__CStringWriter.writeByte */
Ti Yd3R(YjUM *t); /* MIOModule__CStringWriter.byteSize */
Ti YKJQ(YjUM *t); /* MIOModule__CStringWriter.Size */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Ts YjUM__Ydti(YjUM *t, Ti Achar); /* MIOModule__CStringWriter.writeChar__p1 */
Zs53 Yv8w = {&Zstatic, "\063UTF-8 character must be in range 0 - 0x10ffff, got \000"};
Ts YjUM__YRt7(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.print__p1 */
Tc *YjUM__YdXi_imt[3];
To ToYjUM[4];
char *StrYjUM[];
Zs14 YE4c = {&Zstatic, "\014StringWriter\000"};
Tb YpPE(Tc *Aname); /* MIOModule.isDirectory */
Tb Y_3K(Tc *Aname); /* MIOModule.isExecutable */
Ts Yb8K(Tc *AfileName); /* MIOModule.delete */
Tc *Ycmi(Tc *AexeName); /* MIOModule.findExe */
Zs4 YFka = {&Zstatic, "\002./\000"};
Zs5 Y0y2 = {&Zstatic, "\003../\000"};
Zs6 Yykt = {&Zstatic, "\004PATH\000"};
Zs3 Y6 = {&Zstatic, "\001;\000"};
Zs6 YpPR = {&Zstatic, "\004.exe\000"};
Tc *YDop(Tc *AexeName, Tl *Adirs); /* MIOModule.findExeInDirList */
Tc *Yr6O(Tc *AexeName, Tc *AnewName); /* MIOModule.modifyExeName */
Tc *Yq8a(Tc *Afirst, Tc *Asecond); /* MIOModule.concatPath */
Tc *Y2wM(Tc *Afname); /* MIOModule.fullPath */
Zs54 Yd94 = {&Zstatic, "\064IO.fullPath(): Unable to return to current directory\000"};
Zs3 YU = {&Zstatic, "\001.\000"};
Tc *YPjH(Tc *Afname); /* MIOModule.resolve */
Ti Yr30(Tc *Afname); /* MIOModule.tailIndex */
Ti YEpA(Tc *Afname); /* MIOModule.pastHeadIndex */
Tb Yhu2(Ti Ac); /* MIOModule.isPathSep */
Ti Y26N(Tc *Afname, Ti Aidx); /* MIOModule.nextPartIndex */
int JIOModule(int round);
/* IOModule done */
/* including THREADModule declarations */
/* including Config declarations */
Zs3 YYa = {&Zstatic, "\001q\000"};
Zs7 Yef1 = {&Zstatic, "\005quick\000"};
Zs36 YtSW = {&Zstatic, "\042Quick execution, disable backtrace\000"};
Y86c *Y4fD = 0; /* MConfig.quick */
Tb YEPH = 0; /* MConfig.noBacktrace */
Zs4 YsHb = {&Zstatic, "\002cc\000"};
Zs19 YhxU = {&Zstatic, "\021C compiler to use\000"};
Zs10 YeLO = {&Zstatic, "\010compiler\000"};
YzqH *Y6Gp = 0; /* MConfig.compiler */
Zs7 YApf = {&Zstatic, "\005ccarg\000"};
Zs4 YXja = {&Zstatic, "\002-g\000"};
Zs47 Yl1G = {&Zstatic, "\055C compiler arguments (before other arguments)\000"};
YzqH *YJ5o = 0; /* MConfig.ccarg */
Zs10 Yerz = {&Zstatic, "\010ccendarg\000"};
Zs46 YTzz = {&Zstatic, "\054C compiler arguments (after other arguments)\000"};
YzqH *Y6ma = 0; /* MConfig.ccendarg */
Zs10 Y_e2 = {&Zstatic, "\010portable\000"};
Zs44 Yslo = {&Zstatic, "\052Produce portable C code, not using threads\000"};
Y86c *YMSZ = 0; /* MConfig.portableFlag */
Tb YSaE = 0; /* MConfig.portable */
int JConfig(int round);
/* Config done */
Tt MTHREADModule__EState__T = {23, 0, 0};
YgC4 *YgC4__YwtA__YRHR(YgC4 *t, Tc *Amsg); /* MTHREADModule__CE_Thread.NEW__p2 */
Tc *YgC4__YwtA__YH0V(YgC4 *t); /* MTHREADModule__CE_Thread.ToString__p2 */
Tc *YgC4__YwtA__Yoww(YgC4 *t, Tb Averbose); /* MTHREADModule__CE_Thread.toString__p2 */
void YgC4__YwtA__YxaJa(YgC4 *t, Tb Averbose, Tr Aw); /* MTHREADModule__CE_Thread.writeTo__p2 */
void YgC4__YwtA__YxaJ(YgC4 *t, Tr Aw); /* MTHREADModule__CE_Thread.writeTo__p2 */
Tc *YgC4__Ytlm_I_imt[14];
To ToYgC4[4];
char *StrYgC4[];
Zs10 Yvlp = {&Zstatic, "\010E_Thread\000"};
Ts YTgs__Y2Cz(YTgs *t, Te _fr); /* MTHREADModule__CThread.Finish__p1 */
To ToYTgs[4];
char *StrYTgs[];
Zs8 YnY0 = {&Zstatic, "\006Thread\000"};
YlXt *YCyl(YlXt *t); /* MTHREADModule__CLock.NEW */
void YHl9(YlXt *t); /* MTHREADModule__CLock.begin */
void Yvoo(YlXt *t); /* MTHREADModule__CLock.end */
Ts YMFu(YlXt *t, Te _fr); /* MTHREADModule__CLock.Finish */
To ToYlXt[1];
char *StrYlXt[];
Zs6 YzBS = {&Zstatic, "\004Lock\000"};
Y0Wo *YXGL(Y0Wo *t); /* MTHREADModule__CCond.NEW */
void YjFj(Y0Wo *t, Tb Aall); /* MTHREADModule__CCond.wakeup */
void YN6a(Y0Wo *t, YlXt *Alock); /* MTHREADModule__CCond.wait */
To ToY0Wo[1];
char *StrY0Wo[];
Zs6 YeBN = {&Zstatic, "\004Cond\000"};
int JTHREADModule(int round);
/* THREADModule done */
/* including ZWTModule declarations */
void Y1DX(Y1QG *Aserver, Tc *Apath, Tc *Atitle, Tt *AmoduleType); /* MZWTModule.createPage */
Zs160 Y4gy = {&Zstatic, "\201\035<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n<html>\n<head>\n  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n  <title>\000"};
Zs394 Y4Rk = {&Zstatic, "\203\007</title>\n    <style title=\"zwt\" type=\"text/css\">\n      zwt {}\n    </style>\n  <script type=\"text/javascript\">\n    var $wnd = parent;\n    var $doc = $wnd.document;\n  </script>\n</head>\n<body>\n  <iframe src=\"javascript:''\" id=\"__zwt_historyFrame\" tabIndex='-1' style=\"position:absolute;width:0;height:0;border:0\"></iframe>\n  <script type=\"text/javascript\">\n  function getPageName() {\n    return \000"};
Zs602 YN_2 = {&Zstatic, "\204\127;\n  };\n  function loadIframe(fname) {\n    var iframe = $doc.createElement('iframe');\n    iframe.src = \"javascript:''\";\n    iframe.id = 'demoapp';\n    iframe.style.cssText = 'position:absolute;width:0;height:0;border:none';\n    iframe.tabIndex = -1;\n    $doc.body.appendChild(iframe);\n    iframe.contentWindow.location.replace(fname);\n  };\n  var pname = getPageName();\n  if (pname && pname != 'unknown') {\n    loadIframe(pname);\n  } else {\n    var e = $doc.createElement('div');\n    e.innerHTML = \"Sorry, your browser is not supported.\";\n    $doc.body.appendChild(e);\n  }\n  </script>\n</body>\n</html>\n\000"};
Zs7 Y1zY = {&Zstatic, "\005.html\000"};
/* ZWTModule done */
/* including CHECKModule declarations */
void Y8UT(Tb Ab); /* MCHECKModule.true */
Zs21 YG7w = {&Zstatic, "\023CHECK.true() failed\000"};
/* CHECKModule done */
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
char *StrYnU5[];
Zs8 Yr32 = {&Zstatic, "\006Status\000"};
void YY8i(); /* MARGModule.initCheck */
Zs51 YeBP = {&Zstatic, "\061Using command line flag before they are available\000"};
void YS39(); /* MARGModule.notInitCheck */
Zs58 YY2Q = {&Zstatic, "\070Changing command line flag behavior after initialization\000"};
void YQtK(); /* MARGModule.initExeName */
Tc *YzHL(); /* MARGModule.getExeDir */
void YZH8(); /* MARGModule.init */
Zs56 Y7T_ = {&Zstatic, "\066ARG.disable() used but command line flags were defined\000"};
Zs4 Y1ia = {&Zstatic, "\002--\000"};
Zs6 YqzQ = {&Zstatic, "\004help\000"};
Zs10 Y3vi = {&Zstatic, "\010morehelp\000"};
Zs10 Yll7 = {&Zstatic, "\010helpmore\000"};
Zs4 YhZb = {&Zstatic, "\002no\000"};
Zs20 YcW8 = {&Zstatic, "\022Invalid argument: \000"};
Zs29 Y2hB = {&Zstatic, "\033Unknown command line flag: \000"};
Zs31 YcLH = {&Zstatic, "\035Duplicate command line flag: \000"};
Zs5 YjK7 = {&Zstatic, "\003yes\000"};
Zs6 YsfP = {&Zstatic, "\004true\000"};
Zs7 YvpX = {&Zstatic, "\005false\000"};
Zs43 YHSJ = {&Zstatic, "\051Expected 'yes', 'no', 'true' or 'false': \000"};
Zs19 Y6QK = {&Zstatic, "\021Unexpected = in: \000"};
Zs28 Y_ju = {&Zstatic, "\032Missing argument for flag \000"};
Zs29 YjTs = {&Zstatic, "\033INTERNAL: unknown flag type\000"};
void YSUO(Tc *Amsg); /* MARGModule.error */
Zs22 YkFE = {&Zstatic, "\024To list flags use: '\000"};
Zs10 Y15F = {&Zstatic, "\010 --help'\000"};
Zs37 Ye5Da = {&Zstatic, "\043/home/tsuki/.zimbu/lib/ARGModule.zu\000"};
void Yfj5(Tb Averbose); /* MARGModule.displayHelp */
Zs21 YaBy = {&Zstatic, "\023Command line flags:\000"};
Zs13 YwXF = {&Zstatic, "\013--morehelp \000"};
Zs24 YEcf = {&Zstatic, "\026show more verbose help\000"};
Zs8 Yy2p = {&Zstatic, "\006number\000"};
Zs8 YanE = {&Zstatic, "\006string\000"};
Zs12 YDci = {&Zstatic, "\012string ...\000"};
Zs6 YulU = {&Zstatic, "\004 ...\000"};
Zs4 YVZ = {&Zstatic, "\002 [\000"};
Zs4 Yq_ = {&Zstatic, "\002 {\000"};
Zs3 Y9a = {&Zstatic, "\001}\000"};
Zs5 Y_y2 = {&Zstatic, "\003...\000"};
Zs6 Y2yA = {&Zstatic, "\004... \000"};
Zs13 Ym4c = {&Zstatic, "\013Defined in \000"};
void YTlu(Tc *Alead, Ti AmaxLeadLen); /* MARGModule.writeLead */
Tc *YAMW(YuMQ *t); /* MARGModule__CUsage.get */
Zs5 YMtG = {&Zstatic, "\003%0%\000"};
To ToYuMQ[2];
char *StrYuMQ[];
Zs7 Y6qT = {&Zstatic, "\005Usage\000"};
Td *Y7be = NULL; /* MARGModule.shortFlags */
Td *YBQy = NULL; /* MARGModule.longFlags */
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc); /* MARGModule__CBool.NEW */
void YEqoa(Y86c *t); /* MARGModule__CBool.setToDefault */
Tb YHoR(Y86c *t); /* MARGModule__CBool.get */
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CBool.NEW__p1 */
Zs42 Yc_h = {&Zstatic, "\050Adding command line flag after using one\000"};
Zs50 Y6pY = {&Zstatic, "\060Command line flag must have a short or long name\000"};
Zs52 Y9CP = {&Zstatic, "\062short command line flag name must be one character\000"};
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos); /* MARGModule__CBool.throwDuplicate__p1 */
Zs9 YbbH = {&Zstatic, "\007unknown\000"};
Zs32 YtzG = {&Zstatic, "\036Duplicate command line flag: '\000"};
Zs17 YDyy = {&Zstatic, "\017' also used at \000"};
Tc *Y86c__YuQR_I_imt[19];
To ToY86c[12];
char *StrY86c[];
Zs6 YZ1F = {&Zstatic, "\004Bool\000"};
YJQu *Y4qx(YJQu *t, Tc *AshortName, Tc *AlongName, Ti Adefault, Tc *Adoc); /* MARGModule__CInt.NEW */
void Y49ga(YJQu *t); /* MARGModule__CInt.setToDefault */
Ti YRvz(YJQu *t); /* MARGModule__CInt.get */
Ti Yl8r(YJQu *t); /* MARGModule__CInt.value */
YJQu *YJQu__YcLu(YJQu *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CInt.NEW__p1 */
void YJQu__YofP(YJQu *t, Tc *Aname, Tr Aflag, YkxB *Apos); /* MARGModule__CInt.throwDuplicate__p1 */
Tc *YJQu__YuQR_I_imt[19];
To ToYJQu[13];
char *StrYJQu[];
Zs5 YzBa = {&Zstatic, "\003Int\000"};
YzqH *YBtk(YzqH *t, Tc *AshortName, Tc *AlongName, Tc *Adefault, Tc *Adoc); /* MARGModule__CString.NEW */
void YJaza(YzqH *t); /* MARGModule__CString.setToDefault */
YzqH *YzqH__YcLu(YzqH *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CString.NEW__p1 */
void YzqH__YofP(YzqH *t, Tc *Aname, Tr Aflag, YkxB *Apos); /* MARGModule__CString.throwDuplicate__p1 */
Tr YzqH__Y836(YzqH *t, Tc *AargName); /* MARGModule__CString.setArgName__p1 */
Tc *YzqH__YuQR_I_imt[19];
To ToYzqH[13];
char *StrYzqH[];
Zs8 YDAE = {&Zstatic, "\006String\000"};
void YSkKa(Y_SI *t); /* MARGModule__CStringList.setToDefault */
To ToY_SI[12];
char *StrY_SI[];
Zs12 Ygf5 = {&Zstatic, "\012StringList\000"};
int JARGModule(int round);
/* ARGModule done */
/* including INTModule declarations */
Ta *YZEe = NULL; /* MINTModule.letters */
Tc *YIUba(Ti Athis, Ti AminSize); /* MINTModule.toHex */
int JINTModule(int round);
/* INTModule done */
/* including liveDemoPage declarations */
/* including buildzimbu declarations */
YwcI *YVL6(YwcI *t); /* MLivedemo__CBuildRequest.NEW */
Tc *Yyyva(YwcI *t); /* MLivedemo__CBuildRequest.name */
Zs14 YcmU = {&Zstatic, "\014BuildRequest\000"};
Tc *YVmS(YwcI *t); /* MLivedemo__CBuildRequest.getCode */
Tb YdWb(YwcI *t); /* MLivedemo__CBuildRequest.hasCode */
Tc *Yl1pa(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.stringGet */
void YoSUa(YwcI *t, Ti AfieldNr, Tc *Avalue); /* MLivedemo__CBuildRequest.stringSet */
Tb YgM2a(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.hasField */
Tl *YM1ka(YwcI *t); /* MLivedemo__CBuildRequest.fieldSpecs */
YwcI *Y1ns(YwcI *t, Tr Areader); /* MLivedemo__CBuildRequest.mergeFromJson */
Zs6 YI7D = {&Zstatic, "\004code\000"};
Tl *Y7nh = NULL; /* MLivedemo__CBuildRequest__X.fieldSpecs */
Tr YfT8(Tr Areader); /* MLivedemo__CBuildRequest__X.createMessageFromJsonDeref */
YwcI *YyBl(Tr Areader); /* MLivedemo__CBuildRequest__X.createFromJsonDeref */
Ti YwcI__Y0zD(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.enumGet__p1 */
Ti YwcI__Y0zDa(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.enumGet__p1 */
Tc *YwcI__YytN(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.enumNameGet__p1 */
Tc *YwcI__YytNa(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.enumNameGet__p1 */
Ti YwcI__YGR8(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.intGet__p1 */
Ti YwcI__YGR8a(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.intGet__p1 */
Ti32 YwcI__YAAo(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.int32Get__p1 */
Ti32 YwcI__YAAoa(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.int32Get__p1 */
Tu YwcI__YRqV(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.uint64Get__p1 */
Tu YwcI__YRqVa(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.uint64Get__p1 */
Tu32 YwcI__Y0tE(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.uint32Get__p1 */
Tu32 YwcI__Y0tEa(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.uint32Get__p1 */
Tf32 YwcI__Yyt7(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.floatGet__p1 */
Tf32 YwcI__Yyt7a(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.floatGet__p1 */
Tf YwcI__Yybv(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.doubleGet__p1 */
Tf YwcI__Yybva(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.doubleGet__p1 */
Tb YwcI__YGfz(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.boolGet__p1 */
Tb YwcI__YGfza(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.boolGet__p1 */
Tc *YwcI__YsRaa(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.stringGet__p1 */
void YwcI__Y3p7(YwcI *t, Ti AfieldNr, Ti Avalue); /* MLivedemo__CBuildRequest.enumSet__p1 */
void YwcI__YJHD(YwcI *t, Ti AfieldNr, Ti Avalue); /* MLivedemo__CBuildRequest.intSet__p1 */
void YwcI__YDqT(YwcI *t, Ti AfieldNr, Ti32 Avalue); /* MLivedemo__CBuildRequest.int32Set__p1 */
void YwcI__YOAq(YwcI *t, Ti AfieldNr, Tu Avalue); /* MLivedemo__CBuildRequest.uint64Set__p1 */
void YwcI__YYD9(YwcI *t, Ti AfieldNr, Tu32 Avalue); /* MLivedemo__CBuildRequest.uint32Set__p1 */
void YwcI__YBjC(YwcI *t, Ti AfieldNr, Tf32 Avalue); /* MLivedemo__CBuildRequest.floatSet__p1 */
void YwcI__Yvl0(YwcI *t, Ti AfieldNr, Tf Avalue); /* MLivedemo__CBuildRequest.doubleSet__p1 */
void YwcI__YJ52(YwcI *t, Ti AfieldNr, Tb Avalue); /* MLivedemo__CBuildRequest.boolSet__p1 */
Tr YwcI__Yo5y(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.messageGet__p1 */
Tr YwcI__Yo5ya(YwcI *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildRequest.messageGet__p1 */
void YwcI__YrW2(YwcI *t, Ti AfieldNr, Tr Am); /* MLivedemo__CBuildRequest.messageSet__p1 */
void YwcI__Y0Dj(YwcI *t, Ti AfieldNr, Tr Am); /* MLivedemo__CBuildRequest.messageAdd__p1 */
Ti YwcI__YUDN(YwcI *t, Ti AfieldNr); /* MLivedemo__CBuildRequest.size__p1 */
Tc *YwcI__YC5i(YwcI *t); /* MLivedemo__CBuildRequest.ToString__p1 */
Tb YwcI__Ymza(YwcI *t, Ti AfieldNr, Te Aformat, Tr Areader); /* MLivedemo__CBuildRequest.mergeMessageFromReader__p1 */
void YwcI__YgZk(YwcI *t, Tr Awriter); /* MLivedemo__CBuildRequest.writeJsonDeref__p1 */
Tc *YwcI__YFL0_I_imt[54];
To ToYwcI[6];
char *StrYwcI[];
YWgO *YDHy(YWgO *t); /* MLivedemo__CBuildResult.NEW */
Tc *YpCLa(YWgO *t); /* MLivedemo__CBuildResult.name */
Zs13 Yg51 = {&Zstatic, "\013BuildResult\000"};
YWgO *Yg41(YWgO *t, Tc *Av); /* MLivedemo__CBuildResult.setCompilerMessages */
Tb Ydce(YWgO *t); /* MLivedemo__CBuildResult.hasCompilerMessages */
YWgO *YLBO(YWgO *t, Tc *Av); /* MLivedemo__CBuildResult.setRunOutput */
Tb YswH(YWgO *t); /* MLivedemo__CBuildResult.hasRunOutput */
Tc *YcNka(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.stringGet */
void YfDPa(YWgO *t, Ti AfieldNr, Tc *Avalue); /* MLivedemo__CBuildResult.stringSet */
Tb YegVa(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.hasField */
Tl *YIg_a(YWgO *t); /* MLivedemo__CBuildResult.fieldSpecs */
Zs18 YKTm = {&Zstatic, "\020compilerMessages\000"};
Zs11 YPhm = {&Zstatic, "\011runOutput\000"};
Tl *YKva = NULL; /* MLivedemo__CBuildResult__X.fieldSpecs */
Tr Yivy(); /* MLivedemo__CBuildResult__X.newMessage */
Ti YWgO__Y0zD(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.enumGet__p1 */
Ti YWgO__Y0zDa(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.enumGet__p1 */
Tc *YWgO__YytN(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.enumNameGet__p1 */
Tc *YWgO__YytNa(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.enumNameGet__p1 */
Ti YWgO__YGR8(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.intGet__p1 */
Ti YWgO__YGR8a(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.intGet__p1 */
Ti32 YWgO__YAAo(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.int32Get__p1 */
Ti32 YWgO__YAAoa(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.int32Get__p1 */
Tu YWgO__YRqV(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.uint64Get__p1 */
Tu YWgO__YRqVa(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.uint64Get__p1 */
Tu32 YWgO__Y0tE(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.uint32Get__p1 */
Tu32 YWgO__Y0tEa(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.uint32Get__p1 */
Tf32 YWgO__Yyt7(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.floatGet__p1 */
Tf32 YWgO__Yyt7a(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.floatGet__p1 */
Tf YWgO__Yybv(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.doubleGet__p1 */
Tf YWgO__Yybva(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.doubleGet__p1 */
Tb YWgO__YGfz(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.boolGet__p1 */
Tb YWgO__YGfza(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.boolGet__p1 */
Tc *YWgO__YsRaa(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.stringGet__p1 */
void YWgO__Y3p7(YWgO *t, Ti AfieldNr, Ti Avalue); /* MLivedemo__CBuildResult.enumSet__p1 */
void YWgO__YJHD(YWgO *t, Ti AfieldNr, Ti Avalue); /* MLivedemo__CBuildResult.intSet__p1 */
void YWgO__YDqT(YWgO *t, Ti AfieldNr, Ti32 Avalue); /* MLivedemo__CBuildResult.int32Set__p1 */
void YWgO__YOAq(YWgO *t, Ti AfieldNr, Tu Avalue); /* MLivedemo__CBuildResult.uint64Set__p1 */
void YWgO__YYD9(YWgO *t, Ti AfieldNr, Tu32 Avalue); /* MLivedemo__CBuildResult.uint32Set__p1 */
void YWgO__YBjC(YWgO *t, Ti AfieldNr, Tf32 Avalue); /* MLivedemo__CBuildResult.floatSet__p1 */
void YWgO__Yvl0(YWgO *t, Ti AfieldNr, Tf Avalue); /* MLivedemo__CBuildResult.doubleSet__p1 */
void YWgO__YJ52(YWgO *t, Ti AfieldNr, Tb Avalue); /* MLivedemo__CBuildResult.boolSet__p1 */
Tr YWgO__Yo5y(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.messageGet__p1 */
Tr YWgO__Yo5ya(YWgO *t, Ti AfieldNr, Ti Aidx); /* MLivedemo__CBuildResult.messageGet__p1 */
void YWgO__YrW2(YWgO *t, Ti AfieldNr, Tr Am); /* MLivedemo__CBuildResult.messageSet__p1 */
void YWgO__Y0Dj(YWgO *t, Ti AfieldNr, Tr Am); /* MLivedemo__CBuildResult.messageAdd__p1 */
Ti YWgO__YUDN(YWgO *t, Ti AfieldNr); /* MLivedemo__CBuildResult.size__p1 */
Tc *YWgO__YC5i(YWgO *t); /* MLivedemo__CBuildResult.ToString__p1 */
Tb YWgO__Ymza(YWgO *t, Ti AfieldNr, Te Aformat, Tr Areader); /* MLivedemo__CBuildResult.mergeMessageFromReader__p1 */
void YWgO__YgZk(YWgO *t, Tr Awriter); /* MLivedemo__CBuildResult.writeJsonDeref__p1 */
Tc *YWgO__YFL0_I_imt[54];
To ToYWgO[7];
char *StrYWgO[];
Zs26 Yw36 = {&Zstatic, "\030BuildService.BuildAndRun\000"};
YKxQ *YgWI = 0; /* MLivedemo__MBuildService.handleBuildAndRun */
int Jbuildzimbu(int round);
/* buildzimbu done */
Zs14 YsB_ = {&Zstatic, "\014LiveDemoPage\000"};
Tt LiveDemoPage__T = {4, ((Tc*)&YsB_), 0};
int JliveDemoPage(int round);
/* liveDemoPage done */
/* including BuildZimbuServlet declarations */
YvG2 *YwNW(YvG2 *t, Tc *Adummy); /* CBuildZimbuServlet.NEW */
Zs3 Y0a = {&Zstatic, "\001t\000"};
Zs5 YfQV = {&Zstatic, "\003tcc\000"};
Zs24 YIrL = {&Zstatic, "\026Use the tcc C compiler\000"};
Y86c *Y_vl = 0; /* CBuildZimbuServlet__X.tcc */
Zs3 YKa = {&Zstatic, "\001c\000"};
Zs7 Y1Ak = {&Zstatic, "\005clang\000"};
Zs26 YGQA = {&Zstatic, "\030Use the clang C compiler\000"};
Y86c *YmKW = 0; /* CBuildZimbuServlet__X.clang */
Ts YXn8(YtzZ *Acontext, Tr ArequestArg, Tr AresponseArg); /* CBuildZimbuServlet__X.buildAndRun */
Zs10 Ypfm = {&Zstatic, "\010/demo.zu\000"};
Zs12 YLPw = {&Zstatic, "\012/demo.comp\000"};
Zs6 Y4em = {&Zstatic, "\004demo\000"};
Zs7 Ye5c = {&Zstatic, "\005zimbu\000"};
Zs55 YGZd = {&Zstatic, "\065--cc tcc --ccarg=\"-Wall -g -L/usr/lib/i386-linux-gnu\"\000"};
Zs12 YxWT = {&Zstatic, "\012--cc clang\000"};
Zs4 YsZ = {&Zstatic, "\002 >\000"};
Zs23 Y_xD = {&Zstatic, "\025compilation succeeded\000"};
Zs23 YVz0 = {&Zstatic, "\025starting demo process\000"};
Zs11 YWUH = {&Zstatic, "\011/demo.out\000"};
Zs22 YZbl = {&Zstatic, "\024KILLING demo process\000"};
Zs19 Yz3Z = {&Zstatic, "\021\n[program killed]\000"};
Zs23 YOWR = {&Zstatic, "\025demo process finished\000"};
Zs14 YKiz = {&Zstatic, "\014\n[truncated]\000"};
Zs9 YmWe = {&Zstatic, "\007[empty]\000"};
Zs13 Y2Mu = {&Zstatic, "\013[no output]\000"};
void YvG2__YntX__Y3fn(YvG2 *t, Tc *Apath); /* CBuildZimbuServlet.addPath__p2 */
Tb YvG2__YntX__YU_W(YvG2 *t, YtzZ *Acontext); /* CBuildZimbuServlet.handle__p2 */
void YvG2__Yk23(YvG2 *t); /* CBuildZimbuServlet.init__p1 */
Zs6 YvCv = {&Zstatic, "\004/rpc\000"};
void YvG2__YvI9(YvG2 *t, YKxQ *ArpcInfo, Tcb *Ahandler); /* CBuildZimbuServlet.addHandler__p1 */
Tb YvG2__Yk9ua(YvG2 *t, YtzZ *Acontext); /* CBuildZimbuServlet.serve__p1 */
Tc *YvG2__YtrZ_I_imt[9];
To ToYvG2[5];
char *StrYvG2[];
Zs19 YRDga = {&Zstatic, "\021BuildZimbuServlet\000"};
int JBuildZimbuServlet(int round);
/* BuildZimbuServlet done */
Zs3 YXa = {&Zstatic, "\001p\000"};
Zs6 Yb7c = {&Zstatic, "\004port\000"};
Zs26 Ys7y = {&Zstatic, "\030Port for the HTTP server\000"};
YJQu *Vport = 0;
Zs12 YyGk = {&Zstatic, "\012index.html\000"};
Zs17 YKlu = {&Zstatic, "\017Zimbu live demo\000"};
Zs7 Y0Z3 = {&Zstatic, "\005dummy\000"};
Zs10 YvpG = {&Zstatic, "\010Opening \000"};
/*** callbacks for methods invoked directly ***/
Ts ZcbYXn8(Tcb *cb, YtzZ *arg0, Tr arg1, Tr arg2);
Tcb ZCB_YXn8 = {0, ZcbYXn8, -1};
Tr ZcbYfT8(Tcb *cb, Tr arg0);
Tcb ZCB_YfT8 = {0, ZcbYfT8, -1};
Tr ZcbYivy(Tcb *cb);
Tcb ZCB_Yivy = {0, ZcbYivy, -1};

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
Tt thread__T = {250, 0, 0};
Tt array__T = {300, 0, 0};
Tt list__T = {301, 0, 0};
Tt dict__T = {302, 0, 0};
Tt cb__T  = {330, 0, 0};
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
typedef struct StryCtx__S {
 jmp_buf jmpBuf;
 Zsf *sf;
} Ttc;
typedef struct Senv__S {
 Ttc  *tryCtx;
 int  tryCtxSize;
 int  tryCtxUsed;
 Tr   *thrown;
 int  thrownSize;
 int  thrownUsed;
 pthread_t tid;
 int finished;
 int found;
 int timedOut;
 int inZa;
 int ZaEntered;
 Zsf *startFrames;
 Zsf *topFrame;
 Zohf *firstUsedF;
 int tosNr;
} Tn; /* per-thread environemnt */

typedef struct Zohpf__S Zohpf;
struct Zohpf__S {
 Zohpf *next;
 Zohf  *firstUsedF;
};
Zohpf *usedListF = NULL;
Zohf *toFinish = ZOHF_LAST;
pthread_mutex_t threadsMutex;
Tl *threads;

static pthread_key_t ZenvKey;
void ZenvFree(void *ptr) {
 Tn *e = (Tn *)ptr;
 if (e->startFrames) free(e->startFrames);
 pthread_mutex_lock(&threadsMutex);
 ZListRemovePtrItem(threads, ZListFind(threads, (Tz)(void*)e));
 pthread_mutex_unlock(&threadsMutex);
 free(ptr);
}
Tn *ZgetEnv() {
 Tn *e = pthread_getspecific(ZenvKey);
 if (e == NULL) {
  e = ZaNmi(sizeof(Tn));
  e->tid = pthread_self();
  pthread_setspecific(ZenvKey, e);
 }
 return e;
}
void ZenvInit() {
 (void)pthread_key_create(&ZenvKey, ZenvFree);
 pthread_setspecific(ZenvKey, NULL);
 pthread_mutex_init(&threadsMutex, NULL);
 threads = ZnewList(&thread__T, 0);
 ZLa(threads, -1, (Tz)(void*)ZgetEnv());
}

void ZgcFinishAll(int rsn);
void ZgcRun();
void beforeExit() {
 {
  int i;
  Tn *e = ZgetEnv();
  for (i = 0; i < threads->itemCount; ++i) {
   Tn *ie = ZListGetPtr(threads, i);
   if (ie != e && !ie->finished) {
    pthread_cancel(ie->tid);
    ie->finished = 1;
   }
  }
 }
 ZgcFinishAll(1);
}

Ti ZgcUseCount = 0;
Ti ZgcStwTime = 0;
Ti ZgcMarkTime = 0;
Ti ZgcFinishTime = 0;
Ti ZgcFreeTime = 0;
Ti ZgcFreeCount = 0;


Tc *Zstr(char *s) {
 return ZnewString((Tc*)s, strlen(s));
}

/* allocate memory */
void *Za(size_t size) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa) {
  e->inZa = 1;
  p = calloc(1, size);
  e->inZa = 0;
 }
 if (p == NULL) {
  if (e->inZa || e->ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (Za)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++e->ZaEntered;
  ZthrowOutOfMemory(size);
 }
 e->ZaEntered = 0;
 return p;
}

/* allocate memory */
void *ZaF(size_t size, To *to, Ts (*ff)(void *, Te), int nox) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa) {
  e->inZa = 1;
  p = calloc(1, size);
  e->inZa = 0;
 }
 if (p == NULL) {
  if (e->inZa || e->ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaF)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++e->ZaEntered;
  ZthrowOutOfMemory(size);
 }
 e->ZaEntered = 0;
 ((Zoh *)p)->np = (Zoh*)e->firstUsedF;
 e->firstUsedF = p;
 ((Zohf *)p)->to = to;
 ((Zohf *)p)->ff = ff;
 if (nox) ((Zohf *)p)->fok = FOK_NOX;
 return p;
}

/* allocate memory with offset */
#define ZaOff(size) (Za((size) + ZOH_OFF) + ZOH_OFF)
#define ZranOff(ptr, osize, nsize) (Zran((ptr) ? (void*)(ptr) - ZOH_OFF : NULL, (osize) + ZOH_OFF, (nsize) + ZOH_OFF) + ZOH_OFF)

/* allocate memory */
void *ZaNm(size_t size) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa) {
  e->inZa = 1;
  p = calloc(1, size);
  e->inZa = 0;
 }
 if (p == NULL) {
  if (e->inZa || e->ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNm)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++e->ZaEntered;
  ZthrowOutOfMemory(size);
 }
 e->ZaEntered = 0;
 return p;
}

void *ZaNmi(size_t size) {
 void *p = NULL;
 p = calloc(1, size);
 if (p == NULL) {
  {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNmi)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ZthrowOutOfMemory(size);
 }
 return p;
}

/* reallocate memory */
void *Zran(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa && !e->ZaEntered) {
  e->inZa = 1;
  p = realloc(op, nsize);
  e->inZa = 0;
  if (p == NULL) {
    ++e->ZaEntered;
    ZthrowOutOfMemory(nsize);
  }
  e->ZaEntered = 0;
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
 Tn *e = ZgetEnv();
 if (!e->inZa && !e->ZaEntered) {
  e->inZa = 1;
  p = realloc(op, nsize);
  e->inZa = 0;
  if (p == NULL) {
   ++e->ZaEntered;
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

void ZtryDeeper(Tn *e, Zsf *sf);

void ZcallFinish(Zohf *p, Te rsn) {
 if ((p->fok & FOK_OK) == 0 && (rsn != 1 || (p->fok & FOK_NOX) == 0)) {
  Tn *e = ZgetEnv();
  int try_index = e->tryCtxUsed;
  Zsf *tf = e->topFrame;
  ZtryDeeper(e, e->topFrame);
  if (setjmp(e->tryCtx[try_index].jmpBuf) == 0) {
   p->ff(p, rsn);
  } else {
   e->topFrame = tf;
   YvL0(e->thrown[--e->thrownUsed]);
   p->fok |= FOK_OK;
  }
  e->tryCtxUsed = try_index;
 }
}
void ZFinishIobj(Tr *tr, Te rsn) {
 if (tr->ptr != NULL) {
  if (((Tto*)tr->table[0])->Finish != NULL)
   ZcallFinish(tr->ptr, rsn);
   tr->ptr = NULL;
 }
}
void ZgcCallFinish(Te rsn) {
 Zohf *p = toFinish;
 Zohf *np;
 toFinish = ZOHF_LAST;
 while (p != ZOHF_LAST) {
  np = (Zohf*)((Tip)(p->np) & ~3);
  ZcallFinish(p, rsn);
  if (usedListF == NULL) {
   usedListF = ZaNmi(sizeof(Zohpf));
   usedListF->firstUsedF = ZOHF_LAST;
  }
  p->np = (Zoh*)usedListF->firstUsedF;
  usedListF->firstUsedF = p;
  p = np;
 }
}

void ZgcFinishAll(int rsn) {
 Zohpf *up;
 Zohpf *np;
 for (up = usedListF; up; up = np) {
  if (toFinish == ZOHF_LAST) {
   toFinish = up->firstUsedF;
  } else {
   Zohf *p = toFinish;
   while ((Zohf*)((Tip)p->np & ~3) != ZOHF_LAST) p = (Zohf*)((Tip)p->np & ~3);
   p->np = (Zoh*)up->firstUsedF;
  }
  np = up->next;
  free(up);
 }
 usedListF = NULL;
 ZgcCallFinish(rsn);
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
Tc Y6u6[]="/home/tsuki/.zimbu/Config.zu";
Tc Ye5D[]="/home/tsuki/.zimbu/lib/ARGModule.zu";
Tc Y6mX[]="/home/tsuki/.zimbu/lib/EModule.zu";
Tc YfGa[]="/home/tsuki/.zimbu/lib/HTTPModule.zu";
Tc YnAD[]="/home/tsuki/.zimbu/lib/INTModule.zu";
Tc Yusm[]="/home/tsuki/.zimbu/lib/IOModule.zu";
Tc Y7cp[]="/home/tsuki/.zimbu/lib/PIPEModule.zu";
Tc YiuM[]="/home/tsuki/.zimbu/lib/STRINGModule.zu";
Tc YDDW[]="/home/tsuki/.zimbu/lib/SYSModule.zu";
Tc YgU5[]="/home/tsuki/.zimbu/lib/THREADModule.zu";
Tc YTAg[]="/home/tsuki/.zimbu/lib/TIMEModule.zu";
Tc YHVP[]="/home/tsuki/.zimbu/lib/ZModule.zu";
Tc Y7jr[]="/home/tsuki/.zimbu/lib/ZWTModule.zu";
Tc Y8Lc[]="/home/tsuki/.zimbu/plugin/proto/Message.zu";
Tc YENO[]="/home/tsuki/.zimbu/plugin/proto/Proto.zu";
Tc YiQA[]="BuildZimbuServlet.zu";
Tc YQbF[]="ZUDIR/buildzimbu.zu";
Tc YYFp[]="livedemo.zu";
Tc Yaa[]="";
Tcpos ZcTbl0[]={
{11,9},
};
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
Tc YPPv[]="ARG.Init()";
Tcpos ZcTbl66501[]={
{78,29},
};
Tc YEvo[]="ARG.Int.NEW/1()";
Tcpos ZcTbl29660[]={
{857,5},
{1,7},
{2,16},
{3,16},
{4,21},
};
Tc Y6Ad[]="ARG.Int.NEW__p1/1()";
Tcpos ZcTbl31079[]={
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
Tc Ygzb[]="ARG.Int.setToDefault/1()";
Tcpos ZcTbl16350[]={
{865,11},
{1,16},
};
Tc YImu[]="ARG.Int.throwDuplicate__p1/1()";
Tcpos ZcTbl1320[]={
{679,11},
{1,44},
{2,18},
{4,7},
};
Tc YHNQ[]="ARG.Int.value()";
Tcpos ZcTbl87671[]={
{897,11},
{1,15},
};
Tc YAAq[]="ARG.String.NEW/1()";
Tcpos ZcTbl80636[]={
{945,5},
{1,7},
{2,16},
{3,16},
{4,21},
};
Tc YGq4[]="ARG.String.NEW__p1/1()";
Tcpos ZcTbl4839[]={
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
Tc YZNA[]="ARG.String.setToDefault/1()";
Tcpos ZcTbl86206[]={
{953,11},
{1,16},
};
Tc YF9k[]="ARG.String.throwDuplicate__p1/1()";
Tcpos ZcTbl52648[]={
{679,11},
{1,44},
{2,18},
{4,7},
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
Tc YTJ0b[]="ARG.initExeName()";
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
Tc Y5ch[]="BuildRequest.ToString__p1/1()";
Tcpos ZcTbl23729[]={
{159,9},
{1,30},
{2,32},
{3,5},
{4,19},
};
Tc YinI[]="BuildRequest.boolGet__p1/2()";
Tcpos ZcTbl69772[]={
{95,9},
{1,12},
};
Tc YdXK[]="BuildRequest.boolGet__p1/3()";
Tcpos ZcTbl79973[]={
{98,9},
{1,12},
};
Tc YCp3[]="BuildRequest.doubleGet__p1/2()";
Tcpos ZcTbl16855[]={
{89,9},
{1,12},
};
Tc YHQ0[]="BuildRequest.doubleGet__p1/3()";
Tcpos ZcTbl27056[]={
{92,9},
{1,12},
};
Tc YJyBa[]="BuildRequest.enumGet__p1/2()";
Tcpos ZcTbl78037[]={
{45,9},
{1,12},
};
Tc YOZy[]="BuildRequest.enumGet__p1/3()";
Tcpos ZcTbl88238[]={
{48,9},
{1,12},
};
Tc YQPe[]="BuildRequest.enumNameGet__p1/2()";
Tcpos ZcTbl28502[]={
{51,9},
{1,12},
};
Tc YVfc[]="BuildRequest.enumNameGet__p1/3()";
Tcpos ZcTbl38703[]={
{54,9},
{1,12},
};
Tc YqkY[]="BuildRequest.floatGet__p1/2()";
Tcpos ZcTbl65386[]={
{82,9},
{1,12},
};
Tc YlU_[]="BuildRequest.floatGet__p1/3()";
Tcpos ZcTbl75587[]={
{85,9},
{1,12},
};
Tc Y6Ao[]="BuildRequest.int32Get__p1/2()";
Tcpos ZcTbl88996[]={
{63,9},
{1,12},
};
Tc Yb1l[]="BuildRequest.int32Get__p1/3()";
Tcpos ZcTbl99197[]={
{66,9},
{1,12},
};
Tc Y6ax[]="BuildRequest.intGet__p1/2()";
Tcpos ZcTbl56423[]={
{57,9},
{1,12},
};
Tc YbCu[]="BuildRequest.intGet__p1/3()";
Tcpos ZcTbl66624[]={
{60,9},
{1,12},
};
Tc YNqw[]="BuildRequest.mergeMessageFromReader__p1/1()";
Tcpos ZcTbl52639[]={
{142,9},
{4,12},
};
Tc YL4O[]="BuildRequest.messageGet__p1/2()";
Tcpos ZcTbl54221[]={
{131,9},
{1,12},
};
Tc YQvM[]="BuildRequest.messageGet__p1/3()";
Tcpos ZcTbl64422[]={
{134,9},
{1,12},
};
Tc Y99_[]="BuildRequest.size__p1/1()";
Tcpos ZcTbl38922[]={
{150,9},
{1,12},
};
Tc Y6aL[]="BuildRequest.stringGet__p1/3()";
Tcpos ZcTbl46676[]={
{104,9},
{1,12},
};
Tc YC3Z[]="BuildRequest.uint32Get__p1/2()";
Tcpos ZcTbl97157[]={
{75,9},
{1,12},
};
Tc YxD1[]="BuildRequest.uint32Get__p1/3()";
Tcpos ZcTbl7358[]={
{78,9},
{1,12},
};
Tc Y1Kt[]="BuildRequest.uint64Get__p1/2()";
Tcpos ZcTbl37522[]={
{69,9},
{1,12},
};
Tc Y6ar[]="BuildRequest.uint64Get__p1/3()";
Tcpos ZcTbl47723[]={
{72,9},
{1,12},
};
Tc YSP7[]="BuildRequest.writeJsonDeref__p1/1()";
Tcpos ZcTbl18414[]={
{215,9},
{1,32},
{2,5},
};
Tc YR1J[]="BuildResult.ToString__p1/1()";
Tcpos ZcTbl86447[]={
{159,9},
{1,30},
{2,32},
{3,5},
{4,19},
};
Tc YcJr[]="BuildResult.boolGet__p1/2()";
Tcpos ZcTbl91122[]={
{95,9},
{1,12},
};
Tc Yh9o[]="BuildResult.boolGet__p1/3()";
Tcpos ZcTbl1323[]={
{98,9},
{1,12},
};
Tc Yc8f[]="BuildResult.doubleGet__p1/2()";
Tcpos ZcTbl9453[]={
{89,9},
{1,12},
};
Tc Y7Hi[]="BuildResult.doubleGet__p1/3()";
Tcpos ZcTbl19654[]={
{92,9},
{1,12},
};
Tc YDOZ[]="BuildResult.enumGet__p1/2()";
Tcpos ZcTbl99387[]={
{45,9},
{1,12},
};
Tc YIeX[]="BuildResult.enumGet__p1/3()";
Tcpos ZcTbl9588[]={
{48,9},
{1,12},
};
Tc Ynk8[]="BuildResult.enumNameGet__p1/2()";
Tcpos ZcTbl14940[]={
{51,9},
{1,12},
};
Tc YsL5[]="BuildResult.enumNameGet__p1/3()";
Tcpos ZcTbl25141[]={
{54,9},
{1,12},
};
Tc Yb9p[]="BuildResult.floatGet__p1/2()";
Tcpos ZcTbl28104[]={
{82,9},
{1,12},
};
Tc Y6Is[]="BuildResult.floatGet__p1/3()";
Tcpos ZcTbl38305[]={
{85,9},
{1,12},
};
Tc Yf4P[]="BuildResult.int32Get__p1/2()";
Tcpos ZcTbl51714[]={
{63,9},
{1,12},
};
Tc YaES[]="BuildResult.int32Get__p1/3()";
Tcpos ZcTbl61915[]={
{66,9},
{1,12},
};
Tc Yp5_[]="BuildResult.intGet__p1/2()";
Tcpos ZcTbl42549[]={
{57,9},
{1,12},
};
Tc YuwY[]="BuildResult.intGet__p1/3()";
Tcpos ZcTbl52750[]={
{60,9},
{1,12},
};
Tc YjMR[]="BuildResult.mergeMessageFromReader__p1/1()";
Tcpos ZcTbl34029[]={
{142,9},
{4,12},
};
Tc Y4Th[]="BuildResult.messageGet__p1/2()";
Tcpos ZcTbl26203[]={
{131,9},
{1,12},
};
Tc Y_sk[]="BuildResult.messageGet__p1/3()";
Tcpos ZcTbl36404[]={
{134,9},
{1,12},
};
Tc YyRc[]="BuildResult.size__p1/1()";
Tcpos ZcTbl56008[]={
{150,9},
{1,12},
};
Tc Y0p_[]="BuildResult.stringGet__p1/3()";
Tcpos ZcTbl90890[]={
{104,9},
{1,12},
};
Tc Y5i0[]="BuildResult.uint32Get__p1/2()";
Tcpos ZcTbl41371[]={
{75,9},
{1,12},
};
Tc Y0S2[]="BuildResult.uint32Get__p1/3()";
Tcpos ZcTbl51572[]={
{78,9},
{1,12},
};
Tc Yyvs[]="BuildResult.uint64Get__p1/2()";
Tcpos ZcTbl81736[]={
{69,9},
{1,12},
};
Tc YDWp[]="BuildResult.uint64Get__p1/3()";
Tcpos ZcTbl91937[]={
{72,9},
{1,12},
};
Tc YJOp[]="BuildResult.writeJsonDeref__p1/1()";
Tcpos ZcTbl38172[]={
{215,9},
{1,32},
{2,5},
};
Tc YRDg[]="BuildZimbuServlet";
Tcpos ZcTbl70344[]={
{20,14},
{1,14},
};
Tc YEGd[]="BuildZimbuServlet.NEW/1()";
Tcpos ZcTbl47289[]={
{14,3},
{1,5},
{2,5},
};
Tc YpNc[]="BuildZimbuServlet.buildAndRun()";
Tcpos ZcTbl70035[]={
{28,24},
{3,31},
{6,33},
{9,31},
{11,19},
{14,32},
{15,20},
{16,20},
{20,20},
{22,39},
{22,39},
{23,39},
{23,39},
{27,27},
{28,7},
{29,7},
{30,7},
{33,7},
{36,7},
{38,14},
{39,20},
{40,14},
{42,14},
{44,7},
{47,27},
{48,27},
{49,7},
{50,7},
{51,13},
{53,7},
{56,7},
{57,9},
{58,25},
{59,35},
{60,9},
{67,16},
{68,11},
{69,13},
{70,13},
{71,20},
{78,9},
{79,16},
{80,37},
{81,9},
{82,31},
{83,9},
{84,18},
{86,16},
{87,9},
{88,18},
{90,9},
{92,9},
{97,14},
};
Tc YF2d[]="Config";
Tcpos ZcTbl22398[]={
{57,12},
{2,12},
{6,29},
{5,14},
{7,14},
{9,14},
{12,12},
{14,12},
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
Tc YO_6[]="E.BadValue.toString__p2/2()";
Tcpos ZcTbl56573[]={
{105,11},
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
Tc Ya7k[]="E.Check.NEW__p2/3()";
Tcpos ZcTbl31332[]={
{69,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YEvN[]="E.Check.ToString__p2/2()";
Tcpos ZcTbl95135[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Ytle[]="E.Check.toString__p2/2()";
Tcpos ZcTbl47391[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YSxu[]="E.Check.writeTo__p2/4()";
Tcpos ZcTbl35029[]={
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
Tc YN6w[]="E.Check.writeTo__p2/5()";
Tcpos ZcTbl45230[]={
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
Tc YNLE[]="E.DivideByZero.toString__p3/3()";
Tcpos ZcTbl69435[]={
{105,11},
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
Tc Y1ps[]="E.E_BinaryError.toString__p2/2()";
Tcpos ZcTbl84416[]={
{105,11},
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
Tc Ym6U[]="E.E_ParseError.NEW__p2/2()";
Tcpos ZcTbl39186[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YN3C[]="E.E_ParseError.ToString__p2/2()";
Tcpos ZcTbl23634[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y1dq[]="E.E_ParseError.toString__p2/2()";
Tcpos ZcTbl27506[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YpMD[]="E.E_ParseError.writeTo__p2/4()";
Tcpos ZcTbl53292[]={
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
Tc YklG[]="E.E_ParseError.writeTo__p2/5()";
Tcpos ZcTbl63493[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YPKp[]="E.E_Process.NEW__p2/2()";
Tcpos ZcTbl64128[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YrgO[]="E.E_Process.ToString__p2/2()";
Tcpos ZcTbl54936[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Yn1e[]="E.E_Process.toString__p2/2()";
Tcpos ZcTbl58808[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YoIJ[]="E.E_Process.writeTo__p2/4()";
Tcpos ZcTbl25434[]={
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
Tc Yt8G[]="E.E_Process.writeTo__p2/5()";
Tcpos ZcTbl35635[]={
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
Tc YMLv[]="E.E_ProduceError.toString__p2/2()";
Tcpos ZcTbl21053[]={
{105,11},
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
Tc YVQQ[]="E.E_Thread.NEW__p2/2()";
Tcpos ZcTbl97985[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YZd2[]="E.E_Thread.ToString__p2/2()";
Tcpos ZcTbl33805[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y8CZ[]="E.E_Thread.toString__p2/2()";
Tcpos ZcTbl86061[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y8Ap[]="E.E_Thread.writeTo__p2/4()";
Tcpos ZcTbl7051[]={
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
Tc Y39r[]="E.E_Thread.writeTo__p2/5()";
Tcpos ZcTbl17252[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YpMw[]="E.Exception.NEW()";
Tcpos ZcTbl83031[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y2Qj[]="E.Exception.ToString()";
Tcpos ZcTbl51535[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y3yN[]="E.Exception.toString()";
Tcpos ZcTbl97135[]={
{105,11},
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
Tc YwZj[]="E.Exit.NEW/1()";
Tcpos ZcTbl31890[]={
{171,5},
{1,14},
{2,16},
{4,20},
{4,24},
};
Tc Y0TG[]="E.Exit.ToString/1()";
Tcpos ZcTbl18934[]={
{182,11},
{1,27},
{2,7},
{3,16},
};
Tc Ywpu[]="E.Exit.toString__p1/1()";
Tcpos ZcTbl94689[]={
{105,11},
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
Tc Yc7B[]="E.IOError.toString__p2/2()";
Tcpos ZcTbl32191[]={
{105,11},
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
Tc YPGE[]="E.IllegalByte.toString__p3/3()";
Tcpos ZcTbl13917[]={
{105,11},
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
Tc YeMI[]="E.Init.toString__p2/2()";
Tcpos ZcTbl93453[]={
{105,11},
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
Tc YFnU[]="E.Internal.toString__p2/2()";
Tcpos ZcTbl79874[]={
{105,11},
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
Tc YJyB[]="E.KeyExists.toString__p3/3()";
Tcpos ZcTbl4984[]={
{105,11},
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
Tc YlfT[]="E.KeyNotFound.toString__p3/3()";
Tcpos ZcTbl67925[]={
{105,11},
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
Tc Yh7q[]="E.MemoryAccess.toString__p2/2()";
Tcpos ZcTbl18292[]={
{105,11},
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
Tc YN54[]="E.NilAccess.ToString__p2/2()";
Tcpos ZcTbl26854[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YkLW[]="E.NilAccess.toString__p2/2()";
Tcpos ZcTbl79110[]={
{105,11},
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
Tc Ys9t[]="E.OutOfMemory.toString__p2/2()";
Tcpos ZcTbl90571[]={
{105,11},
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
Tc Y6co[]="E.OutOfRange.toString__p3/3()";
Tcpos ZcTbl83985[]={
{105,11},
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
Tc YOoP[]="E.WrongType.toString__p2/2()";
Tcpos ZcTbl16768[]={
{105,11},
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
{1,7},
{1,7},
{1,7},
{1,7},
{2,5},
};
Tc YhJL[]="HTTP.BuildZimbuServlet.addHandler__p1/1()";
Tcpos ZcTbl8607[]={
{334,11},
{2,7},
{3,9},
{3,9},
{5,19},
{6,17},
{7,17},
{8,7},
};
Tc Yzvq[]="HTTP.BuildZimbuServlet.addPath__p2/2()";
Tcpos ZcTbl51804[]={
{164,11},
{1,7},
{2,16},
{4,7},
};
Tc Yjdv[]="HTTP.BuildZimbuServlet.handle__p2/2()";
Tcpos ZcTbl63978[]={
{174,11},
{1,7},
{2,9},
{3,11},
{4,13},
{5,15},
{7,13},
{8,22},
{2,9},
{13,14},
};
Tc YXQJ[]="HTTP.BuildZimbuServlet.init__p1/1()";
Tcpos ZcTbl81328[]={
{327,11},
{1,13},
{2,7},
{3,17},
};
Tc YkXM[]="HTTP.BuildZimbuServlet.serve__p1/1()";
Tcpos ZcTbl18661[]={
{349,11},
{1,29},
{2,7},
{3,27},
{4,9},
{5,24},
{6,39},
{8,40},
{11,11},
{14,36},
{15,11},
{16,33},
{17,11},
{18,18},
{21,14},
};
Tc YGWN[]="HTTP.Context.NEW()";
Tcpos ZcTbl91620[]={
{150,5},
{1,15},
{2,16},
{3,17},
};
Tc Yd9V[]="HTTP.FileServlet.NEW()";
Tcpos ZcTbl94336[]={
{239,5},
{1,13},
{2,17},
};
Tc Y5GQ[]="HTTP.FileServlet.addPath__p1/1()";
Tcpos ZcTbl53063[]={
{164,11},
{1,7},
{2,16},
{4,7},
};
Tc YXHL[]="HTTP.FileServlet.handle__p1/1()";
Tcpos ZcTbl38545[]={
{174,11},
{1,7},
{2,9},
{3,11},
{4,13},
{5,15},
{7,13},
{8,22},
{2,9},
{13,14},
};
Tc Ykap[]="HTTP.FileServlet.serve/1()";
Tcpos ZcTbl53863[]={
{251,11},
{2,7},
{3,29},
{7,14},
};
Tc Y9NR[]="HTTP.RedirectServlet.NEW()";
Tcpos ZcTbl73462[]={
{209,5},
{1,13},
{2,14},
{3,13},
};
Tc YEhH[]="HTTP.RedirectServlet.addPath__p1/1()";
Tcpos ZcTbl8173[]={
{164,11},
{1,7},
{2,16},
{4,7},
};
Tc Y1J3[]="HTTP.RedirectServlet.handle__p1/1()";
Tcpos ZcTbl33183[]={
{174,11},
{1,7},
{2,9},
{3,11},
{4,13},
{5,15},
{7,13},
{8,22},
{2,9},
{13,14},
};
Tc YjKx[]="HTTP.RedirectServlet.serve/1()";
Tcpos ZcTbl52989[]={
{221,11},
{1,29},
{5,29},
{6,28},
{7,48},
{8,14},
};
Tc YFGh[]="HTTP.Request.NEW()";
Tcpos ZcTbl46640[]={
{52,5},
{1,20},
};
Tc YLdV[]="HTTP.Request.ToString()";
Tcpos ZcTbl84668[]={
{89,11},
{1,27},
{2,7},
{3,7},
{4,7},
{5,7},
{6,7},
{7,7},
{8,9},
{7,7},
{10,7},
{11,9},
{14,16},
};
Tc YiJI[]="HTTP.Request.paramDict()";
Tcpos ZcTbl30907[]={
{58,11},
{2,7},
{3,21},
{4,9},
{6,11},
{7,31},
{8,30},
{11,13},
{12,20},
{13,21},
{15,20},
{16,21},
{18,31},
{19,13},
{22,19},
{6,11},
{26,15},
};
Tc YfxG[]="HTTP.Response.NEW()";
Tcpos ZcTbl34822[]={
{124,5},
{1,13},
{2,12},
{3,20},
{4,7},
{5,13},
};
Tc Yxl5[]="HTTP.Response.setLength()";
Tcpos ZcTbl14874[]={
{133,11},
{1,38},
};
Tc Ys1T[]="HTTP.Response.setType()";
Tcpos ZcTbl84506[]={
{138,11},
{1,36},
};
Tc Y9Hg[]="HTTP.RpcServlet.addHandler()";
Tcpos ZcTbl16966[]={
{334,11},
{2,7},
{3,9},
{3,9},
{5,19},
{6,17},
{7,17},
{8,7},
};
Tc Y0Bh[]="HTTP.RpcServlet.addPath__p1/1()";
Tcpos ZcTbl89168[]={
{164,11},
{1,7},
{2,16},
{4,7},
};
Tc YSto[]="HTTP.RpcServlet.handle__p1/1()";
Tcpos ZcTbl14342[]={
{174,11},
{1,7},
{2,9},
{3,11},
{4,13},
{5,15},
{7,13},
{8,22},
{2,9},
{13,14},
};
Tc Yzyq[]="HTTP.RpcServlet.serve/1()";
Tcpos ZcTbl67592[]={
{349,11},
{1,29},
{2,7},
{3,27},
{4,9},
{5,24},
{6,39},
{8,40},
{11,11},
{14,36},
{15,11},
{16,33},
{17,11},
{18,18},
{21,14},
};
Tc YGL9[]="HTTP.Server.Init/1()";
Tcpos ZcTbl32864[]={
{391,22},
{1,22},
{3,22},
{4,22},
{7,22},
};
Tc Y32H[]="HTTP.Server.NEW()";
Tcpos ZcTbl96330[]={
{403,5},
{1,13},
{2,7},
{3,15},
{8,17},
};
Tc YXL6[]="HTTP.Server.addServlet()";
Tcpos ZcTbl98650[]={
{431,11},
{1,7},
};
Tc Y7FCa[]="HTTP.Server.body()";
Tcpos ZcTbl99366[]={
{465,11},
{2,24},
{3,7},
{4,4},
{58,4},
{72,4},
{76,23},
{80,28},
{81,9},
{82,4},
{86,52},
{87,9},
{88,11},
{89,22},
{87,9},
{95,9},
{96,13},
{95,9},
{100,18},
{101,9},
{102,13},
{101,9},
{104,18},
{105,27},
{106,9},
{108,22},
{109,20},
{113,9},
{114,13},
{113,9},
{120,29},
{122,9},
{123,15},
{124,15},
{126,15},
{127,11},
{128,11},
{129,13},
{132,25},
{134,9},
{135,27},
{136,11},
{137,20},
{139,25},
{140,11},
{142,18},
{144,11},
{148,11},
{149,13},
{155,9},
{156,15},
{157,11},
{159,13},
{160,17},
{163,11},
{165,17},
{170,33},
{171,11},
{172,64},
{173,33},
{174,36},
{175,13},
{176,34},
{177,15},
{178,17},
{181,15},
{182,17},
{181,15},
{185,15},
{186,17},
{185,15},
{188,26},
{189,15},
{193,19},
{194,19},
{195,15},
{199,26},
{200,26},
{175,13},
{202,13},
{205,26},
{207,40},
{210,15},
{155,9},
{212,9},
{213,11},
{217,24},
{218,9},
{219,20},
{220,11},
{221,13},
{224,9},
{227,36},
{228,11},
{232,11},
{234,13},
{235,15},
{237,4},
{242,4},
{246,13},
};
Tcpos ZcTbl99367[]={
{712,15},
{2,13},
{5,13},
{-15,11},
{7,20},
{8,11},
{9,13},
{10,13},
{11,15},
{12,15},
{13,15},
{15,15},
{17,13},
{20,20},
{23,15},
{26,25},
{28,27},
{29,9},
{29,9},
{30,11},
{31,13},
{32,20},
{30,11},
{37,11},
{38,13},
{40,13},
{43,9},
{44,21},
{45,20},
{46,21},
{48,9},
{53,70},
{55,9},
{56,22},
{55,9},
{58,17},
{60,9},
{61,11},
{62,11},
{63,13},
{64,13},
{65,13},
{66,15},
{67,15},
{68,15},
{70,15},
{72,13},
{75,4},
{79,4},
{82,4},
{89,11},
{90,24},
{91,21},
{92,4},
{98,4},
{101,4},
{109,4},
{114,15},
{115,9},
{116,11},
{118,4},
};
Tc Yv62[]="HTTP.Server.openInBrowser()";
Tcpos ZcTbl76361[]={
{839,11},
{1,18},
};
Tc Y0Qs[]="HTTP.Server.redirect()";
Tcpos ZcTbl80742[]={
{457,11},
{1,33},
{2,7},
{3,7},
};
Tc Yp9y[]="HTTP.Server.waitForExit()";
Tcpos ZcTbl34426[]={
{854,11},
{1,7},
};
Tc Ytbi[]="HTTP.StringServlet.NEW()";
Tcpos ZcTbl72151[]={
{267,5},
{1,13},
{2,13},
};
Tc YEI9[]="HTTP.StringServlet.addPath__p1/1()";
Tcpos ZcTbl76262[]={
{164,11},
{1,7},
{2,16},
{4,7},
};
Tc YAxR[]="HTTP.StringServlet.handle__p1/1()";
Tcpos ZcTbl31780[]={
{174,11},
{1,7},
{2,9},
{3,11},
{4,13},
{5,15},
{7,13},
{8,22},
{2,9},
{13,14},
};
Tc YPt0[]="HTTP.StringServlet.serve/1()";
Tcpos ZcTbl76846[]={
{278,11},
{1,29},
{2,14},
};
Tc YHiL[]="HTTP.isWhite()";
Tcpos ZcTbl74200[]={
{863,21},
};
Tc YLM9[]="INT";
Tcpos ZcTbl52635[]={
{123,14},
};
Tc YeB2[]="INT.toHex/1()";
Tcpos ZcTbl6550[]={
{142,15},
{2,25},
{3,5},
{4,19},
{5,11},
{6,7},
{9,13},
{11,7},
{3,5},
{13,5},
{14,7},
{13,5},
{16,25},
};
Tc Ys1a[]="IO";
Tcpos ZcTbl7452[]={
{26,8},
{3,8},
{6,8},
};
Tc Y7vJ[]="IO.CharReaderStack.NEW()";
Tcpos ZcTbl63102[]={
{895,5},
{1,15},
{2,14},
};
Tc YmhO[]="IO.CharReaderStack.push()";
Tcpos ZcTbl22848[]={
{912,11},
{1,7},
};
Tc Y39t[]="IO.CharReaderStack.readChar()";
Tcpos ZcTbl53986[]={
{903,11},
{1,7},
{2,23},
{4,22},
};
Tc YIxT[]="IO.File.Finish()";
Tcpos ZcTbl49822[]={
{601,11},
{1,7},
{5,14},
};
Tc YEgn[]="IO.File.close()";
Tcpos ZcTbl15755[]={
{582,11},
{1,20},
{2,7},
{6,4},
{9,4},
{12,15},
{15,14},
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
Tc Y58p[]="IO.File.readAll()";
Tcpos ZcTbl43258[]={
{321,11},
{1,27},
{2,7},
{3,18},
{4,9},
{7,9},
{2,7},
{9,16},
};
Tc YJrj[]="IO.File.readAllLines/1()";
Tcpos ZcTbl53326[]={
{449,11},
{1,29},
{2,7},
{3,24},
{4,9},
{7,9},
{8,9},
{2,7},
{12,14},
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
Tc YDzF[]="IO.File.readLine()";
Tcpos ZcTbl72841[]={
{374,11},
{1,16},
{2,7},
{3,16},
{5,24},
{7,7},
{8,9},
{10,11},
{12,11},
{13,13},
{14,13},
{12,11},
{16,11},
{18,11},
{7,7},
{20,16},
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
Tc YyL2[]="IO.StringReader.NEW()";
Tcpos ZcTbl95965[]={
{854,5},
{2,9},
{4,13},
{5,17},
};
Tc Yzh4[]="IO.StringReader.readChar()";
Tcpos ZcTbl41549[]={
{866,11},
{1,7},
{2,16},
{4,21},
{5,7},
{6,9},
{8,18},
{10,14},
};
Tc Y4qG[]="IO.StringWriter.Size()";
Tcpos ZcTbl34324[]={
{1416,11},
{1,7},
{2,16},
{5,26},
};
Tc YrJP[]="IO.StringWriter.ToString()";
Tcpos ZcTbl64531[]={
{1431,11},
{3,9},
{4,13},
{6,4},
{17,14},
};
Tc Ylob[]="IO.StringWriter.byteSize()";
Tcpos ZcTbl95336[]={
{1411,11},
{1,15},
};
Tc YYk7[]="IO.StringWriter.print__p1/8()";
Tcpos ZcTbl26760[]={
{184,11},
{1,7},
{2,16},
{4,14},
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
Tc Y0Nw[]="IO.concatPath()";
Tcpos ZcTbl68304[]={
{2077,5},
{1,7},
{2,22},
{4,20},
{6,5},
{7,20},
{9,25},
};
Tc YSjn[]="IO.delete()";
Tcpos ZcTbl73150[]={
{1875,4},
{11,12},
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
Tc YrlY[]="IO.findExe()";
Tcpos ZcTbl64970[]={
{1982,28},
{2,7},
{5,15},
{8,27},
{9,9},
{10,4},
{13,23},
{14,4},
{17,23},
{18,4},
{22,15},
{23,4},
{26,9},
{27,17},
{29,4},
{32,9},
{33,17},
{34,4},
{37,11},
{38,19},
{40,4},
{44,17},
{47,14},
};
Tc Y60W[]="IO.findExeInDirList()";
Tcpos ZcTbl86176[]={
{2038,5},
{1,22},
{2,7},
{3,16},
{0,5},
{6,12},
};
Tc YN2v[]="IO.flush()";
Tcpos ZcTbl46761[]={
{1337,4},
{9,12},
};
Tc Yk1s[]="IO.fullPath()";
Tcpos ZcTbl38403[]={
{2098,4},
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
Tc Y85R[]="IO.initSockets()";
Tcpos ZcTbl37363[]={
{1054,18},
{1,4},
{16,12},
};
Tc Y9tP[]="IO.isDirectory()";
Tcpos ZcTbl14832[]={
{1678,4},
{11,12},
};
Tc Yuq9[]="IO.isExecutable()";
Tcpos ZcTbl73877[]={
{1729,4},
{8,14},
};
Tc Yofe[]="IO.isPathSep()";
Tcpos ZcTbl79136[]={
{2475,14},
};
Tc YLaX[]="IO.modifyExeName()";
Tcpos ZcTbl28902[]={
{2061,22},
{1,33},
{2,12},
{3,28},
{4,5},
{5,14},
{7,12},
};
Tc YaL5[]="IO.nextPartIndex()";
Tcpos ZcTbl36277[]={
{2481,5},
{1,7},
{2,18},
{0,5},
{5,13},
};
Tc YSYC[]="IO.pastHeadIndex()";
Tcpos ZcTbl11017[]={
{2456,4},
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
{1227,37},
{1,4},
{13,12},
};
Tc Y4pE[]="IO.readFile()";
Tcpos ZcTbl7451[]={
{1106,18},
{2,4},
{9,4},
{10,4},
{16,4},
{17,4},
{22,4},
{23,4},
{26,4},
{34,5},
{35,4},
{43,7},
{44,4},
{54,12},
};
Tc YlPR[]="IO.resolve()";
Tcpos ZcTbl45331[]={
{2248,4},
{3,12},
{4,4},
{7,23},
{10,39},
{13,33},
{15,13},
{16,5},
{20,14},
{21,14},
{24,14},
{27,5},
{28,7},
{29,4},
{37,11},
{38,4},
{42,9},
{43,18},
{48,9},
{49,16},
{54,11},
{55,9},
{56,11},
{57,20},
{59,20},
{61,16},
{64,17},
{65,9},
{67,18},
{68,13},
{70,9},
{72,18},
{75,18},
{28,7},
{79,7},
{85,9},
{86,7},
{87,16},
{88,16},
{90,16},
{91,16},
{27,5},
{97,5},
{98,7},
{107,16},
{108,14},
{110,11},
{111,9},
{112,13},
{111,9},
{114,9},
{115,18},
{122,5},
{123,15},
{124,7},
{125,16},
{124,7},
{129,4},
{133,12},
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
Tc YBZV[]="Livedemo.BuildRequest";
Tcpos ZcTbl74724[]={
{91,29},
};
Tc YDma[]="Livedemo.BuildRequest.NEW()";
Tcpos ZcTbl50873[]={
{8,5},
};
Tc YC7s[]="Livedemo.BuildRequest.createFromJsonDeref()";
Tcpos ZcTbl69915[]={
{125,35},
};
Tc Y2fU[]="Livedemo.BuildRequest.createMessageFromJsonDeref()";
Tcpos ZcTbl34392[]={
{119,16},
};
Tc Y9tD[]="Livedemo.BuildRequest.mergeFromJson()";
Tcpos ZcTbl25969[]={
{82,11},
{1,7},
{2,14},
};
Tc YsvE[]="Livedemo.BuildResult";
Tcpos ZcTbl5998[]={
{236,29},
};
Tc YUCN[]="Livedemo.BuildResult.NEW()";
Tcpos ZcTbl89939[]={
{130,5},
};
Tc Y0EV[]="Livedemo.BuildResult.newMessage()";
Tcpos ZcTbl10988[]={
{241,28},
};
Tc Ypp_b[]="Livedemo.BuildService";
Tcpos ZcTbl55200[]={
{290,21},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{17,22},
{1,24},
{2,3},
{5,3},
{8,3},
{11,3},
{14,60},
{15,3},
{16,3},
{19,3},
{21,10},
};
Tc YV0a[]="PIPE.Pipe__t1.NEW()";
Tcpos ZcTbl64622[]={
{41,5},
{1,17},
{2,13},
{3,17},
{4,18},
{5,19},
{6,15},
};
Tc YHPQ[]="PIPE.Pipe__t1.read()";
Tcpos ZcTbl21692[]={
{152,11},
{2,7},
{3,9},
{4,11},
{5,16},
{6,33},
{7,13},
{10,13},
{11,20},
{13,11},
{14,16},
{17,11},
{3,9},
{20,7},
{22,14},
};
Tc Y0n5[]="PIPE.Pipe__t1.read/1()";
Tcpos ZcTbl43744[]={
{181,11},
{2,15},
};
Tc Ysl1[]="PIPE.Pipe__t1.write()";
Tcpos ZcTbl82363[]={
{126,11},
{2,7},
{3,9},
{4,11},
{5,13},
{6,20},
{8,11},
{9,13},
{12,11},
{3,9},
{15,7},
{18,7},
{19,14},
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
Tc YOvb[]="Proto.Reader.Init()";
Tcpos ZcTbl74012[]={
{206,13},
};
Tc Ywla[]="Proto.Reader.NEW/1()";
Tcpos ZcTbl27710[]={
{216,5},
{2,22},
{3,7},
{4,15},
};
Tc YfR5[]="Proto.Reader.charReader()";
Tcpos ZcTbl5609[]={
{228,11},
{1,15},
};
Tc YgkG[]="Proto.Reader.getRef()";
Tcpos ZcTbl99269[]={
{259,11},
{1,20},
};
Tc YUX0[]="Proto.Reader.protoReader()";
Tcpos ZcTbl59187[]={
{247,11},
{1,14},
};
Tc YNwI[]="Proto.RpcInfo.NEW()";
Tcpos ZcTbl31228[]={
{2113,5},
{3,13},
{4,23},
{5,23},
};
Tc Ys3k[]="Proto.Writer.NEW/1()";
Tcpos ZcTbl2268[]={
{148,5},
{1,15},
{2,7},
{3,9},
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
Tc YwJ3[]="Proto.mergeFromJsonFields()";
Tcpos ZcTbl72404[]={
{1247,42},
{1,21},
{2,5},
{3,7},
{6,22},
{7,21},
{8,5},
{9,7},
{11,5},
{12,7},
{15,7},
{17,9},
{18,20},
{19,9},
{20,11},
{23,9},
{24,11},
{27,11},
{28,9},
{29,11},
{34,9},
{36,11},
{37,13},
{40,9},
{45,7},
{46,9},
{47,11},
{48,15},
{49,13},
{51,15},
{52,22},
{53,17},
{54,19},
{56,21},
{57,19},
{60,19},
{61,21},
{66,17},
{51,15},
{68,20},
{70,15},
{73,18},
{45,7},
{79,7},
{80,9},
{83,9},
{84,7},
{85,9},
{86,11},
{88,11},
{90,7},
{11,5},
};
Tc YKD8[]="Proto.mergeOneJsonField()";
Tcpos ZcTbl40035[]={
{1343,42},
{2,5},
{6,17},
{7,9},
{8,14},
{11,19},
{12,9},
{13,14},
{16,17},
{17,9},
{18,14},
{21,19},
{22,9},
{23,14},
{26,21},
{27,9},
{28,14},
{31,19},
{32,9},
{33,14},
{36,17},
{37,9},
{38,14},
{41,20},
{42,9},
{43,14},
{46,17},
{47,9},
{48,14},
{50,25},
{51,9},
{52,9},
{53,11},
{54,13},
{55,15},
{57,13},
{60,21},
{61,36},
{62,11},
{65,13},
{67,31},
{68,11},
{71,13},
{73,11},
{74,13},
{76,13},
{78,16},
{81,16},
{84,9},
{87,12},
};
Tc YdSv[]="Proto.readJsonDouble()";
Tcpos ZcTbl32616[]={
{1950,25},
{1,5},
{2,22},
{3,7},
{5,9},
{8,7},
{1,5},
{11,25},
};
Tc YEEH[]="Proto.readJsonNumber()";
Tcpos ZcTbl59730[]={
{1937,5},
{1,22},
{2,7},
{3,9},
{6,9},
{0,5},
{8,12},
};
Tc YK_O[]="Proto.readJsonString()";
Tcpos ZcTbl48444[]={
{1966,5},
{1,14},
{3,30},
{4,5},
{5,22},
{6,7},
{7,9},
{9,7},
{12,7},
{13,11},
{14,9},
{16,13},
{18,13},
{20,13},
{22,13},
{24,13},
{26,50},
{27,15},
{28,15},
{29,15},
{30,13},
{33,13},
{36,9},
{4,5},
{39,19},
};
Tc YCmR[]="Proto.skipJsonField()";
Tcpos ZcTbl87404[]={
{2010,20},
{1,5},
{2,7},
{3,7},
{4,21},
{5,7},
{6,14},
{7,7},
{8,9},
{9,11},
{10,9},
{13,9},
{14,11},
{7,7},
{17,14},
{19,7},
{21,7},
};
Tc YUBc[]="Proto.writeJson()";
Tcpos ZcTbl25988[]={
{1434,29},
{1,37},
{2,5},
{3,5},
{4,7},
{5,25},
{6,9},
{7,11},
{8,29},
{9,11},
{10,29},
{11,11},
{12,13},
{13,22},
{14,13},
{17,17},
{19,17},
{21,17},
{23,17},
{25,17},
{27,17},
{30,17},
{31,19},
{33,19},
{36,17},
{38,17},
{40,37},
{41,17},
{43,17},
{11,11},
{47,11},
{50,9},
{51,11},
{52,29},
{53,11},
{56,15},
{58,15},
{60,15},
{62,15},
{64,15},
{66,15},
{69,15},
{70,17},
{72,17},
{75,15},
{77,15},
{79,35},
{80,15},
{82,15},
{3,5},
{88,5},
};
Tc YFdI[]="Proto.writeJsonFieldLeader()";
Tcpos ZcTbl51349[]={
{1527,5},
{2,7},
{3,9},
{5,7},
{6,7},
{10,7},
{11,9},
{10,7},
};
Tc YcZ9[]="Proto.writeJsonString()";
Tcpos ZcTbl22879[]={
{2037,5},
{1,5},
{2,7},
{3,19},
{4,20},
{5,20},
{6,20},
{7,20},
{8,20},
{9,20},
{11,11},
{13,13},
{14,13},
{17,13},
{1,5},
{21,5},
};
Tc Y6NR[]="Proto.writeMessageJson()";
Tcpos ZcTbl71601[]={
{1545,5},
{2,7},
{3,9},
{5,44},
{6,11},
{7,16},
{10,25},
{11,23},
{14,7},
{15,9},
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
Tc YuIh[]="STRING.replaceAll()";
Tcpos ZcTbl12035[]={
{669,5},
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
Tc Yiyv[]="STRING.reverse()";
Tcpos ZcTbl42834[]={
{635,5},
{1,14},
{3,25},
{4,5},
{6,7},
{4,5},
{8,14},
};
Tc YWKB[]="SYS.Process.NEW()";
Tcpos ZcTbl78949[]={
{132,5},
{1,12},
{2,21},
};
Tc YwRI[]="SYS.Process.isRunning()";
Tcpos ZcTbl34556[]={
{270,11},
{1,7},
{2,16},
{4,4},
{24,14},
};
Tc YHE5[]="SYS.Process.kill()";
Tcpos ZcTbl41031[]={
{404,11},
{1,7},
{2,9},
{2,9},
{4,7},
{5,9},
{5,9},
{7,4},
{12,14},
};
Tc YTx9[]="SYS.Process.start()";
Tcpos ZcTbl40405[]={
{156,11},
{3,4},
{10,7},
{11,9},
{11,9},
{13,16},
{17,7},
{18,14},
{20,4},
{23,8},
{24,4},
{30,10},
{31,4},
{38,10},
{39,4},
{49,10},
{50,4},
{63,11},
{64,13},
{66,4},
{104,14},
};
Tc YXDF[]="SYS.Process.wait/1()";
Tcpos ZcTbl36272[]={
{325,11},
{2,7},
{3,16},
{5,32},
{6,7},
{7,9},
{8,9},
{9,18},
{6,7},
{12,14},
};
Tc Yo15[]="SYS.Process.writeErrorsToOut()";
Tcpos ZcTbl38926[]={
{483,11},
{1,7},
{2,9},
{2,9},
{4,23},
{5,14},
};
Tc YZy1[]="SYS.Process.writeTo()";
Tcpos ZcTbl59277[]={
{457,11},
{1,7},
{2,9},
{2,9},
{4,20},
{5,14},
};
Tc YQ54[]="SYS.getEnv()";
Tcpos ZcTbl42323[]={
{56,4},
{4,12},
};
Tc YP_b[]="SYS.openInBrowser()";
Tcpos ZcTbl69095[]={
{82,22},
{1,5},
{2,7},
{4,62},
{6,4},
{12,7},
{13,17},
{14,9},
{17,17},
{12,7},
{20,5},
{21,14},
{23,65},
};
Tc Y0q_[]="SYS.shell()";
Tcpos ZcTbl90786[]={
{28,4},
{4,12},
};
Tc YvfVb[]="SYS.shellBackground()";
Tcpos ZcTbl76254[]={
{41,26},
{4,4},
{8,12},
};
Tc YCe5[]="THREAD.Cond.NEW()";
Tcpos ZcTbl68823[]={
{455,5},
{1,4},
};
Tc YL2R[]="THREAD.Cond.wait()";
Tcpos ZcTbl73734[]={
{475,11},
{1,4},
};
Tc YGy0[]="THREAD.Cond.wakeup()";
Tcpos ZcTbl1082[]={
{463,11},
{1,4},
};
Tc YOJ5[]="THREAD.Lock.Finish()";
Tcpos ZcTbl80111[]={
{407,11},
{1,4},
{4,14},
};
Tc YEgk[]="THREAD.Lock.NEW()";
Tcpos ZcTbl53428[]={
{363,5},
{1,4},
};
Tc YIVA[]="THREAD.Lock.begin()";
Tcpos ZcTbl7651[]={
{375,11},
{1,4},
};
Tc Yc45[]="THREAD.Lock.end()";
Tcpos ZcTbl17605[]={
{400,11},
{1,4},
};
Tc Yz4h[]="THREAD.Server.Finish__p2/2()";
Tcpos ZcTbl96282[]={
{193,11},
{1,4},
{4,14},
};
Tc Ys_j[]="THREAD.Server.startBody__p2/2()";
Tcpos ZcTbl39877[]={
{64,11},
{2,4},
{9,9},
{10,4},
{9,9},
{17,4},
{44,4},
{53,4},
};
Tc YEiU[]="THREAD.Server.start__p2/2()";
Tcpos ZcTbl22103[]={
{134,11},
{4,4},
{7,16},
{8,9},
{10,4},
{15,11},
{8,9},
{18,4},
{21,9},
{22,11},
{24,4},
{31,14},
};
Tc Y7wT[]="THREAD.Thread.Finish__p1/1()";
Tcpos ZcTbl84521[]={
{193,11},
{1,4},
{4,14},
};
Tc YLwM[]="TIME.current()";
Tcpos ZcTbl50841[]={
{22,4},
{5,12},
};
Tc Y0oq[]="TIME.sleep()";
Tcpos ZcTbl91247[]={
{248,4},
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
Tc YXHK[]="ZWT.createPage()";
Tcpos ZcTbl43825[]={
{628,23},
{5,23},
{19,23},
{44,41},
{48,23},
{49,29},
{50,7},
{51,7},
{55,37},
{56,12},
{57,12},
{59,31},
{60,7},
{63,7},
};
Tcode ZcodeTable[]={
{0,YYFp,Yaa,ZcTbl0},
{412,Y6mX,YxLq,ZcTbl412},
{1082,YgU5,YGy0,ZcTbl1082},
{1320,Ye5D,YImu,ZcTbl1320},
{1323,Y8Lc,Yh9o,ZcTbl1323},
{1872,Yusm,YNFk,ZcTbl1872},
{2268,YENO,Ys3k,ZcTbl2268},
{3273,Ye5D,Y_VO,ZcTbl3273},
{4839,Ye5D,YGq4,ZcTbl4839},
{4984,Y6mX,YJyB,ZcTbl4984},
{5270,YYFp,Y9QD,ZcTbl5270},
{5609,YENO,YfR5,ZcTbl5609},
{5998,YQbF,YsvE,ZcTbl5998},
{6308,Y6mX,YR5_,ZcTbl6308},
{6550,YnAD,YeB2,ZcTbl6550},
{7051,Y6mX,Y8Ap,ZcTbl7051},
{7358,Y8Lc,YxD1,ZcTbl7358},
{7451,Yusm,Y4pE,ZcTbl7451},
{7452,Yusm,Ys1a,ZcTbl7452},
{7651,YgU5,YIVA,ZcTbl7651},
{8173,YfGa,YEhH,ZcTbl8173},
{8607,YfGa,YhJL,ZcTbl8607},
{9453,Y8Lc,Yc8f,ZcTbl9453},
{9588,Y8Lc,YIeX,ZcTbl9588},
{9948,Y6mX,YALK,ZcTbl9948},
{10045,Y6mX,Y_Bo,ZcTbl10045},
{10613,Y6mX,YCbo,ZcTbl10613},
{10988,YQbF,Y0EV,ZcTbl10988},
{11017,Yusm,YSYC,ZcTbl11017},
{11217,Y6mX,YoZS,ZcTbl11217},
{12035,YiuM,YuIh,ZcTbl12035},
{12469,YENO,YnDn,ZcTbl12469},
{12896,Y6mX,Y0Td,ZcTbl12896},
{13666,YENO,YlSz,ZcTbl13666},
{13917,Y6mX,YPGE,ZcTbl13917},
{14342,YfGa,YSto,ZcTbl14342},
{14715,Y6mX,Y4SL,ZcTbl14715},
{14832,Yusm,Y9tP,ZcTbl14832},
{14874,YfGa,Yxl5,ZcTbl14874},
{14940,Y8Lc,Ynk8,ZcTbl14940},
{15669,Y6mX,YMB8,ZcTbl15669},
{15718,Y6mX,YEFs,ZcTbl15718},
{15755,Yusm,YEgn,ZcTbl15755},
{16053,Yusm,Y5P_,ZcTbl16053},
{16350,Ye5D,Ygzb,ZcTbl16350},
{16768,Y6mX,YOoP,ZcTbl16768},
{16855,Y8Lc,YCp3,ZcTbl16855},
{16966,YfGa,Y9Hg,ZcTbl16966},
{17179,Y6mX,Yk5m,ZcTbl17179},
{17252,Y6mX,Y39r,ZcTbl17252},
{17605,YgU5,Yc45,ZcTbl17605},
{18187,YHVP,Ym1t,ZcTbl18187},
{18292,Y6mX,Yh7q,ZcTbl18292},
{18414,Y8Lc,YSP7,ZcTbl18414},
{18661,YfGa,YkXM,ZcTbl18661},
{18934,Y6mX,Y0TG,ZcTbl18934},
{19299,YENO,Yw9e,ZcTbl19299},
{19654,Y8Lc,Y7Hi,ZcTbl19654},
{20149,Y6mX,YFbI,ZcTbl20149},
{21053,Y6mX,YMLv,ZcTbl21053},
{21418,Y6mX,YtpQ,ZcTbl21418},
{21692,Y7cp,YHPQ,ZcTbl21692},
{22103,YgU5,YEiU,ZcTbl22103},
{22398,Y6u6,YF2d,ZcTbl22398},
{22848,Yusm,YmhO,ZcTbl22848},
{22879,YENO,YcZ9,ZcTbl22879},
{23634,Y6mX,YN3C,ZcTbl23634},
{23729,Y8Lc,Y5ch,ZcTbl23729},
{24916,Y6mX,Y9iJ,ZcTbl24916},
{25141,Y8Lc,YsL5,ZcTbl25141},
{25434,Y6mX,YoIJ,ZcTbl25434},
{25958,Y6mX,Y4vu,ZcTbl25958},
{25969,YQbF,Y9tD,ZcTbl25969},
{25988,YENO,YUBc,ZcTbl25988},
{26203,Y8Lc,Y4Th,ZcTbl26203},
{26760,Yusm,YYk7,ZcTbl26760},
{26854,Y6mX,YN54,ZcTbl26854},
{27056,Y8Lc,YHQ0,ZcTbl27056},
{27506,Y6mX,Y1dq,ZcTbl27506},
{27618,Y6mX,Y8mE,ZcTbl27618},
{27710,YENO,Ywla,ZcTbl27710},
{28104,Y8Lc,Yb9p,ZcTbl28104},
{28502,Y8Lc,YQPe,ZcTbl28502},
{28902,Yusm,YLaX,ZcTbl28902},
{29560,Ye5D,YzK9,ZcTbl29560},
{29585,Y6mX,YAVe,ZcTbl29585},
{29660,Ye5D,YEvo,ZcTbl29660},
{30532,YENO,Y1Hw,ZcTbl30532},
{30907,YfGa,YiJI,ZcTbl30907},
{31079,Ye5D,Y6Ad,ZcTbl31079},
{31228,YENO,YNwI,ZcTbl31228},
{31332,Y6mX,Ya7k,ZcTbl31332},
{31729,Y6mX,Y0DD,ZcTbl31729},
{31780,YfGa,YAxR,ZcTbl31780},
{31890,Y6mX,YwZj,ZcTbl31890},
{32086,Y6mX,Y1As,ZcTbl32086},
{32160,Y6mX,Y5qz,ZcTbl32160},
{32191,Y6mX,Yc7B,ZcTbl32191},
{32616,YENO,YdSv,ZcTbl32616},
{32618,Ye5D,YBSz,ZcTbl32618},
{32864,YfGa,YGL9,ZcTbl32864},
{32956,YENO,YlQ3,ZcTbl32956},
{33183,YfGa,Y1J3,ZcTbl33183},
{33805,Y6mX,YZd2,ZcTbl33805},
{34029,Y8Lc,YjMR,ZcTbl34029},
{34324,Yusm,Y4qG,ZcTbl34324},
{34392,YQbF,Y2fU,ZcTbl34392},
{34426,YfGa,Yp9y,ZcTbl34426},
{34556,YDDW,YwRI,ZcTbl34556},
{34822,YfGa,YfxG,ZcTbl34822},
{35029,Y6mX,YSxu,ZcTbl35029},
{35088,Y6mX,YcIS,ZcTbl35088},
{35635,Y6mX,Yt8G,ZcTbl35635},
{36159,Y6mX,Y_4w,ZcTbl36159},
{36272,YDDW,YXDF,ZcTbl36272},
{36277,Yusm,YaL5,ZcTbl36277},
{36404,Y8Lc,Y_sk,ZcTbl36404},
{36491,Y6mX,YYT9,ZcTbl36491},
{36994,YENO,YAt_,ZcTbl36994},
{37363,Yusm,Y85R,ZcTbl37363},
{37522,Y8Lc,Y1Kt,ZcTbl37522},
{37884,YENO,YGqq,ZcTbl37884},
{38172,Y8Lc,YJOp,ZcTbl38172},
{38305,Y8Lc,Y6Is,ZcTbl38305},
{38403,Yusm,Yk1s,ZcTbl38403},
{38545,YfGa,YXHL,ZcTbl38545},
{38552,Yusm,Y35R,ZcTbl38552},
{38703,Y8Lc,YVfc,ZcTbl38703},
{38911,Ye5D,YM2k,ZcTbl38911},
{38922,Y8Lc,Y99_,ZcTbl38922},
{38926,YDDW,Yo15,ZcTbl38926},
{39186,Y6mX,Ym6U,ZcTbl39186},
{39877,YgU5,Ys_j,ZcTbl39877},
{40035,YENO,YKD8,ZcTbl40035},
{40405,YDDW,YTx9,ZcTbl40405},
{41031,YDDW,YHE5,ZcTbl41031},
{41371,Y8Lc,Y5i0,ZcTbl41371},
{41549,Yusm,Yzh4,ZcTbl41549},
{42323,YDDW,YQ54,ZcTbl42323},
{42549,Y8Lc,Yp5_,ZcTbl42549},
{42834,YiuM,Yiyv,ZcTbl42834},
{42983,Y6mX,Y9aV,ZcTbl42983},
{43000,Ye5D,YEFE,ZcTbl43000},
{43124,Y6mX,Ygil,ZcTbl43124},
{43258,Yusm,Y58p,ZcTbl43258},
{43744,Y7cp,Y0n5,ZcTbl43744},
{43825,Y7jr,YXHK,ZcTbl43825},
{44130,Y6mX,YG80,ZcTbl44130},
{45209,Y6mX,Y2NH,ZcTbl45209},
{45230,Y6mX,YN6w,ZcTbl45230},
{45289,Y6mX,Y7gV,ZcTbl45289},
{45331,Yusm,YlPR,ZcTbl45331},
{46171,Y6mX,Y9VX,ZcTbl46171},
{46312,Y6mX,YPz2,ZcTbl46312},
{46631,Yusm,YHCY,ZcTbl46631},
{46640,YfGa,YFGh,ZcTbl46640},
{46676,Y8Lc,Y6aL,ZcTbl46676},
{46761,Yusm,YN2v,ZcTbl46761},
{47289,YiQA,YEGd,ZcTbl47289},
{47391,Y6mX,Ytle,ZcTbl47391},
{47723,Y8Lc,Y6ar,ZcTbl47723},
{48299,Y6mX,Y9Cv,ZcTbl48299},
{48444,YENO,YK_O,ZcTbl48444},
{49183,Y6mX,YgcH,ZcTbl49183},
{49285,Yusm,Y1Ue,ZcTbl49285},
{49599,YENO,Y6Nc,ZcTbl49599},
{49822,Yusm,YIxT,ZcTbl49822},
{50841,YTAg,YLwM,ZcTbl50841},
{50873,YQbF,YDma,ZcTbl50873},
{51349,YENO,YFdI,ZcTbl51349},
{51535,Y6mX,Y2Qj,ZcTbl51535},
{51572,Y8Lc,Y0S2,ZcTbl51572},
{51714,Y8Lc,Yf4P,ZcTbl51714},
{51804,YfGa,Yzvq,ZcTbl51804},
{52386,Y6mX,YgcM,ZcTbl52386},
{52608,Y6mX,YqK0,ZcTbl52608},
{52635,YnAD,YLM9,ZcTbl52635},
{52639,Y8Lc,YNqw,ZcTbl52639},
{52648,Ye5D,YF9k,ZcTbl52648},
{52701,Y6mX,Y0hW,ZcTbl52701},
{52728,Y6mX,Yoiq,ZcTbl52728},
{52750,Y8Lc,YuwY,ZcTbl52750},
{52989,YfGa,YjKx,ZcTbl52989},
{53063,YfGa,Y5GQ,ZcTbl53063},
{53292,Y6mX,YpMD,ZcTbl53292},
{53325,Y6mX,YlJi,ZcTbl53325},
{53326,Yusm,YJrj,ZcTbl53326},
{53377,Y6mX,Yp81,ZcTbl53377},
{53428,YgU5,YEgk,ZcTbl53428},
{53863,YfGa,Ykap,ZcTbl53863},
{53986,Yusm,Y39t,ZcTbl53986},
{54221,Y8Lc,YL4O,ZcTbl54221},
{54331,Y6mX,YLzZ,ZcTbl54331},
{54936,Y6mX,YrgO,ZcTbl54936},
{55200,YQbF,Ypp_b,ZcTbl55200},
{56008,Y8Lc,YyRc,ZcTbl56008},
{56372,Y6mX,Y4u_,ZcTbl56372},
{56381,Y6mX,Y99g,ZcTbl56381},
{56423,Y8Lc,Y6ax,ZcTbl56423},
{56573,Y6mX,YO_6,ZcTbl56573},
{58808,Y6mX,Yn1e,ZcTbl58808},
{59187,YENO,YUX0,ZcTbl59187},
{59277,YDDW,YZy1,ZcTbl59277},
{59730,YENO,YEEH,ZcTbl59730},
{59819,Yusm,YGQL,ZcTbl59819},
{60593,Y6mX,Y5LR,ZcTbl60593},
{61915,Y8Lc,YaES,ZcTbl61915},
{62213,Yusm,YU58,ZcTbl62213},
{62809,Y6mX,Ylj3,ZcTbl62809},
{63102,Yusm,Y7vJ,ZcTbl63102},
{63483,Y6mX,Yuzo,ZcTbl63483},
{63493,Y6mX,YklG,ZcTbl63493},
{63578,Y6mX,Yuz_,ZcTbl63578},
{63978,YfGa,Yjdv,ZcTbl63978},
{64128,Y6mX,YPKp,ZcTbl64128},
{64422,Y8Lc,YQvM,ZcTbl64422},
{64478,Ye5D,YRbs,ZcTbl64478},
{64531,Yusm,YrJP,ZcTbl64531},
{64622,Y7cp,YV0a,ZcTbl64622},
{64912,YENO,YufP,ZcTbl64912},
{64970,Yusm,YrlY,ZcTbl64970},
{65386,Y8Lc,YqkY,ZcTbl65386},
{66036,Y6mX,YQJA,ZcTbl66036},
{66188,Yusm,YJ7z,ZcTbl66188},
{66501,Ye5D,YPPv,ZcTbl66501},
{66624,Y8Lc,YbCu,ZcTbl66624},
{67592,YfGa,Yzyq,ZcTbl67592},
{67925,Y6mX,YlfT,ZcTbl67925},
{68304,Yusm,Y0Nw,ZcTbl68304},
{68797,Y6mX,YfLf,ZcTbl68797},
{68823,YgU5,YCe5,ZcTbl68823},
{69095,YDDW,YP_b,ZcTbl69095},
{69435,Y6mX,YNLE,ZcTbl69435},
{69772,Y8Lc,YinI,ZcTbl69772},
{69915,YQbF,YC7s,ZcTbl69915},
{70035,YiQA,YpNc,ZcTbl70035},
{70344,YiQA,YRDg,ZcTbl70344},
{70530,Y6mX,Yu0r,ZcTbl70530},
{70833,Y6mX,YWEC,ZcTbl70833},
{71601,YENO,Y6NR,ZcTbl71601},
{71988,YENO,YleD,ZcTbl71988},
{72007,Yusm,YzQB,ZcTbl72007},
{72151,YfGa,Ytbi,ZcTbl72151},
{72404,YENO,YwJ3,ZcTbl72404},
{72841,Yusm,YDzF,ZcTbl72841},
{73150,Yusm,YSjn,ZcTbl73150},
{73462,YfGa,Y9NR,ZcTbl73462},
{73471,Y6mX,Y_Qs,ZcTbl73471},
{73580,Y6mX,YF6S,ZcTbl73580},
{73684,Y6mX,Yz_l,ZcTbl73684},
{73734,YgU5,YL2R,ZcTbl73734},
{73877,Yusm,Yuq9,ZcTbl73877},
{74012,YENO,YOvb,ZcTbl74012},
{74200,YfGa,YHiL,ZcTbl74200},
{74724,YQbF,YBZV,ZcTbl74724},
{75587,Y8Lc,YlU_,ZcTbl75587},
{75697,Ye5D,YgDO,ZcTbl75697},
{76254,YDDW,YvfVb,ZcTbl76254},
{76262,YfGa,YEI9,ZcTbl76262},
{76361,YfGa,Yv62,ZcTbl76361},
{76644,Ye5D,YImf,ZcTbl76644},
{76846,YfGa,YPt0,ZcTbl76846},
{77164,Ye5D,YTJ0b,ZcTbl77164},
{78037,Y8Lc,YJyBa,ZcTbl78037},
{78082,Y6mX,YbzA,ZcTbl78082},
{78949,YDDW,YWKB,ZcTbl78949},
{79110,Y6mX,YkLW,ZcTbl79110},
{79136,Yusm,Yofe,ZcTbl79136},
{79874,Y6mX,YFnU,ZcTbl79874},
{79935,Y6mX,YVJp,ZcTbl79935},
{79973,Y8Lc,YdXK,ZcTbl79973},
{80111,YgU5,YOJ5,ZcTbl80111},
{80636,Ye5D,YAAq,ZcTbl80636},
{80644,Y6mX,YobA,ZcTbl80644},
{80731,Y6mX,Yzrp,ZcTbl80731},
{80742,YfGa,Y0Qs,ZcTbl80742},
{81328,YfGa,YXQJ,ZcTbl81328},
{81580,Yusm,Y5X7,ZcTbl81580},
{81736,Y8Lc,Yyvs,ZcTbl81736},
{81798,Ye5D,YMnk,ZcTbl81798},
{82363,Y7cp,Ysl1,ZcTbl82363},
{82533,Ye5D,Yh2v,ZcTbl82533},
{82534,Ye5D,Yh2v,ZcTbl82534},
{82618,Yusm,Yxlj,ZcTbl82618},
{83031,Y6mX,YpMw,ZcTbl83031},
{83985,Y6mX,Y6co,ZcTbl83985},
{84416,Y6mX,Y1ps,ZcTbl84416},
{84506,YfGa,Ys1T,ZcTbl84506},
{84521,YgU5,Y7wT,ZcTbl84521},
{84668,YfGa,YLdV,ZcTbl84668},
{84870,Yusm,Y_pS,ZcTbl84870},
{85000,Y6mX,Ycb9,ZcTbl85000},
{85295,Ye5D,Yza4,ZcTbl85295},
{86061,Y6mX,Y8CZ,ZcTbl86061},
{86176,Yusm,Y60W,ZcTbl86176},
{86206,Ye5D,YZNA,ZcTbl86206},
{86447,Y8Lc,YR1J,ZcTbl86447},
{86699,Y6mX,Ym8y,ZcTbl86699},
{86818,Y6mX,YlgI,ZcTbl86818},
{87235,Y6mX,YR5m,ZcTbl87235},
{87404,YENO,YCmR,ZcTbl87404},
{87671,Ye5D,YHNQ,ZcTbl87671},
{88238,Y8Lc,YOZy,ZcTbl88238},
{88996,Y8Lc,Y6Ao,ZcTbl88996},
{89168,YfGa,Y0Bh,ZcTbl89168},
{89581,Y6mX,YAwk,ZcTbl89581},
{89685,Y6mX,Y59h,ZcTbl89685},
{89939,YQbF,YUCN,ZcTbl89939},
{89987,Yusm,YCbR,ZcTbl89987},
{90571,Y6mX,Ys9t,ZcTbl90571},
{90679,YENO,YI64,ZcTbl90679},
{90786,YDDW,Y0q_,ZcTbl90786},
{90890,Y8Lc,Y0p_,ZcTbl90890},
{91122,Y8Lc,YcJr,ZcTbl91122},
{91247,YTAg,Y0oq,ZcTbl91247},
{91620,YfGa,YGWN,ZcTbl91620},
{91937,Y8Lc,YDWp,ZcTbl91937},
{92163,Y6mX,YTjU,ZcTbl92163},
{93453,Y6mX,YeMI,ZcTbl93453},
{94336,YfGa,Yd9V,ZcTbl94336},
{94689,Y6mX,Ywpu,ZcTbl94689},
{94729,YENO,Yutk,ZcTbl94729},
{94823,Yusm,Yj_J,ZcTbl94823},
{95135,Y6mX,YEvN,ZcTbl95135},
{95336,Yusm,Ylob,ZcTbl95336},
{95965,Yusm,YyL2,ZcTbl95965},
{96107,Y6mX,YMF2,ZcTbl96107},
{96282,YgU5,Yz4h,ZcTbl96282},
{96330,YfGa,Y32H,ZcTbl96330},
{97019,Y6mX,YgQK,ZcTbl97019},
{97135,Y6mX,Y3yN,ZcTbl97135},
{97157,Y8Lc,YC3Z,ZcTbl97157},
{97985,Y6mX,YVQQ,ZcTbl97985},
{98650,YfGa,YXL6,ZcTbl98650},
{99197,Y8Lc,Yb1l,ZcTbl99197},
{99269,YENO,YgkG,ZcTbl99269},
{99366,YfGa,Y7FCa,ZcTbl99366},
{99367,YfGa,Y7FCa,ZcTbl99367},
{99387,Y8Lc,YDOZ,ZcTbl99387},
{99838,Yusm,YTE3,ZcTbl99838},
{99886,Y6mX,Y0Jk,ZcTbl99886},
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

void ZgcRun() {
}

void ZthrowPos(Ti pos, Tc *text) {
 YScq(pos, text);
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

int ZTypeInRange(int type, int low, int high) {
 return type >= low && type <= high;
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

Tc *ZbyteStringCheckUtf8(Tc *p) {
 /* TODO */
 return p;
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
 YNab(pos, val);
}

Tt *ZiobjType(Tr *p) {
 if (p == NULL) ZthrowCstringNil("using Type() on NIL");
 return (Tt *)(p->table[0]);
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

Ti ZbyteStringGetChar(Tc *sv, Ti idx, int dn) {
 Tc *p;
 Ti len;
 Ti r;
 if (sv == NULL) {
  if (dn) return 0;
  ZthrowCstringNil("using getChar() on NIL");
 }
 if (idx < 0) ZthrowCstringOutOfRange(idx, "using negative index");
 len = ZstringSizePtr(sv, &p);
 if (idx >= len) ZthrowCstringOutOfRange(idx, "index too big");
 p += idx;
 r = *p;
 if (r > 0x7f) {
  if ((r & 0xe0) == 0xc0) {
   if (idx + 1 >= len)
    r = -1;
   else
    r = ((r & 0x1f) << 6) + (p[1] & 0x3f);
  } else if  ((*p & 0xf0) == 0xe0) {
   if (idx + 2 >= len)
    r = -1;
   else
    r = ((r & 0x0f) << 12) + ((p[1] & 0x3f) << 6) + (p[2] & 0x3f);
  } else if  ((*p & 0xf8) == 0xf0) {
   if (idx + 3 >= len)
    r = -1;
   else
    r = ((r & 0x07) << 18) + ((p[1] & 0x3f) << 12) + ((p[2] & 0x3f) << 6) + (p[4] & 0x3f);
  } else {
   r = -1;
  }
 }
 return r;
}

Ti ZbyteStringGetCharSize(Tc *sv, Ti idx, int dn) {
 Tc *p;
 Ti len;
 Ti c;
 Ti r;
 if (sv == NULL) {
  if (dn) return 0;
  ZthrowCstringNil("using getChar() on NIL");
 }
 if (idx < 0) ZthrowCstringOutOfRange(idx, "using negative index");
 len = ZstringSizePtr(sv, &p);
 if (idx >= len) ZthrowCstringOutOfRange(idx, "index too big");
 c  = p[idx];
 if (c <= 0x7f) {
  r = 1;
 } else if ((c & 0xe0) == 0xc0) {
  if (idx + 1 >= len)
   r = -1;
  else
   r = 2;
 } else if ((c & 0xf0) == 0xe0) {
  if (idx + 2 >= len)
   r = -1;
  else
   r = 3;
 } else if ((c & 0xf8) == 0xf0) {
  if (idx + 3 >= len)
   r = -1;
  else
   r = 4;
 } else {
  r = -1;
 }
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

Tc *Znat2string(Tu n) {
 char buf[30];
 char *p;
 int len;
 sprintf(buf, ZNAT_FORMAT, n);
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

Tf Zstring2float(Tc *ss, Ti *dn) {
 Tc *s;
 char *e;
 Ti len;
 if (ss == NULL) {
  ZthrowCstringNil("using toFloat() on NIL");
 }
 len = ZstringSizePtr(ss, &s);
 Tf r = strtod((char *)s, &e);
 if (dn) *dn = (Tc*)e - s;
 return r;
}

Tc *ZstringToLower(Tc *ss) {
 return ZstringToLowerAscii(ss);
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
 return ZstringToUpperAscii(ss);
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

void ZforEnumGetEnum(Tfe *fe, Te *p) {
 *p = fe->idx;
}
int ZforEnumContEnum(Tfe *fe) {
 return fe->idx < fe->count;
}
void ZforEnumNextEnum(Tfe *fe, Te *p) {
 if (fe->idx < fe->count)
  ++(fe->idx);
 *p = fe->idx;
}

void ZtryDeeper(Tn *e, Zsf *sf) {
 if (e->tryCtx == NULL) {
  e->tryCtxSize = 20;
  e->tryCtx = ZaNm(sizeof(Ttc) * e->tryCtxSize);
  e->tryCtxUsed = 1;
 } else if (++e->tryCtxUsed > e->tryCtxSize) {
  e->tryCtxSize += 20;
  e->tryCtx = ZranNm(e->tryCtx, sizeof(Ttc) * (e->tryCtxSize - 20), sizeof(Ttc) * e->tryCtxSize);
 }
 e->tryCtx[e->tryCtxUsed - 1].sf = sf;
}
void Zrethrow() {
 Tn *e = ZgetEnv();
   ZthrowIobject(e->thrown[--e->thrownUsed]);
}

void ZthrowIobject(Tr eo) {
 Tn *e = ZgetEnv();
 Ttc *ctx = &e->tryCtx[e->tryCtxUsed - 1];
 int i;
 Zsf *stop = NULL;
 if (e->tryCtxUsed > 0) stop = ctx->sf;
 while (e->topFrame != stop) {
  Zfo *fo = e->topFrame->frof;
  if (fo != NULL) {
   for (i = 0; fo[i].off != 0; ++i) {
    Tto *tto = (Tto*)fo[i].type;
    if (tto->nr == 390 && tto->Finish != NULL && (fo[i].off & 1)) {
     Zohf *p = (Zohf*)((char *)e->topFrame - (fo[i].off - 1));
     if (p->np != NULL) {
      ZcallFinish(p, 2);
      p->np = NULL;
     }
    } else if (tto->nr == 391 && (fo[i].off & 1)) {
     ZFinishIobj((Tr*)((char *)e->topFrame - (fo[i].off - 1)), 2);
    }
   }
  }
  if (e->topFrame->prev == NULL) break;
  e->topFrame = e->topFrame->prev;
 }
 if (e->tryCtxUsed > 0) {
  if (e->thrown == NULL) {
   e->thrownSize = 10;
   e->thrown = ZaNmi(sizeof(Tr) * e->thrownSize);
   e->thrownUsed = 1;
  } else if (++e->thrownUsed > e->thrownSize) {
   e->thrownSize += 20;
   e->thrown = ZranNm(e->thrown, sizeof(Tr) * (e->thrownSize - 20), sizeof(Tr *) * e->thrownSize);
  }
  e->thrown[e->thrownUsed - 1] = eo;
  longjmp(ctx->jmpBuf, 42);
 } else
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
 ++ZgetEnv()->tosNr;
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
 ++ZgetEnv()->tosNr;
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
 Tn *e = ZgetEnv();
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
 ++ZgetEnv()->tosNr;
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
 Tn *e = ZgetEnv();
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
 ++ZgetEnv()->tosNr;
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
Tl *ZListInsert(Tl *head, Ti before, Tz val) {
 Ti nBefore;
 Ti idx;
 if (head == NULL) ZthrowCstringNil("Invoking insert() on NIL list");
 if (head->itemCount == 0 || before >= head->itemCount) return ZLa(head, -1, val);
 if (before < 0) {
  nBefore = head->itemCount + before;
 } else {
  nBefore = before;
 }
 if (nBefore <= 0) nBefore = -head->itemCount;
 return ZLa(head, nBefore - 1, val);
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

Ti ZListFind(Tl *head, Tz val) {
 Ti n;
 Ti tot;
 if (head == NULL) ZthrowCstringNil("Attempt to find in NIL list");
 n = head->empty;
 tot = n + head->itemCount;
 for ( ; n < tot ; ++n)
  switch (head->itemType->nr) {
   case 0:
   case 24:
   case 25:
    if (((Ti*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 10:
    if ((Ti)((Tu*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 1:
    if (((char*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 11:
    if ((Ti)((Tc*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 2:
    if (((Ti16*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 12:
    if ((Ti)((Tu16*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 3:
   case 13:
    if (((Ti32*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 21:
   case 22:
   case 23:
    if (((int*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 80:
   case 82:
   case 83:
    if (((Tf*)head->items)[n] == val.fval) return n - head->empty;
    break;
   case 81:
    if (((Tf32*)head->items)[n] == (Tf32)val.fval) return n - head->empty;
    break;
   case 200:
   case 201:
    if (ZstringCmp(head->items[n], val.ptr) == 0) return n - head->empty;
    break;
   case 391:
    ZthrowCstringNil("Invoking find() on iobject list");
    break;
   default:
    if (head->items[n] == val.ptr) return n - head->empty;
    break;
  }
 return -1;
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

Tc *ZListJoinVal(Tl *head, Tc *sep, int useq) {
 int size = 0;
 Tc *sepp;
 Tg ga;
 Ti n;
 Ti tot;
 if (head == NULL) ZthrowCstringNil("Invoking join() on NIL list");
 if (sep == NULL) ZthrowCstringNil("Invoking join() with NIL argument");
 ga.data = NULL;
 ga.used = 0;
 ZstringSizePtr(sep, &sepp);
 n = head->empty;
 tot = n + head->itemCount;
 if (n < tot) {
  for (;;) {
   Tc *p;
   Ti len;
   ZListitemToString(head, useq, n, &ga);
   if (++n == tot) break;
   ga_append(&ga, (char *)sepp);
  }
 }
 return ZnewString(ga.data, ga.used);
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
 d->np = &Znoalloc;
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
 Tn *e = ZgetEnv();
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
 ++ZgetEnv()->tosNr;
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

Ti ZDictSize(Td *d) {
 if (d == NULL) return 0;
 return d->used;
}

Tc *ZtypeName(Tt *type) {
 if (type == NULL) return Zstr("NIL");
 return type->name;
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
 Zsf *tf = ZgetEnv()->topFrame;
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
 Zsf *tf = ZgetEnv()->topFrame;
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
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vusec = 0;
 sf.pos=5084100;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    Vusec = (Ti)tv.tv_sec * 1000000 + (Ti)tv.tv_usec;
 sf.pos=5084101;
 r = Vusec;
 e->topFrame = sf.prev;
 return r;
}
void YQzL(Ti Ausec) {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=9124700;
#ifdef __MINGW32__
    Sleep((int)((Ausec + 999) / 1000));
#else
    struct timespec tm;
    tm.tv_sec = Ausec / 1000000;
    tm.tv_nsec = (Ausec % 1000000) * 1000;
    nanosleep(&tm, NULL);
#endif
 e->topFrame = sf.prev;
 return;
}
/* TIMEModule done */
/* including EModule bodies */
Zfo YRHRfo[3] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&string__T},{0,0}};
Ytlm *YRHR(Ytlm *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YRHRfo[0].off = (void*)&sf - (void*)&t;
  YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8303100; t = Za(sizeof(Ytlm));}
 sf.pos=8303101;
 t->Vmessage = Amsg;
 sf.pos=8303102;
 t->Vpos = MZ__callerPos();
 sf.pos=8303103;
 t->Vbacktrace = (sf.pos=8303104, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YH0Vfo[4] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YH0V(Ytlm *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YxaJfo[3] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&iobj__T},{0,0}};
void YxaJ(Ytlm *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YxaJfo[0].off = (void*)&sf - (void*)&t;
  YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo Yowwfo[4] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yoww(Ytlm *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yowwfo[0].off = (void*)&sf - (void*)&t;
  Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9713500;
  ZthrowThisNil();
 }
 sf.pos=9713501;
 Vw = Za(sizeof(YjUM));
 sf.pos=9713502;
 YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9713503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YxaJafo[5] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&list__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YkxB__T},{0,0}};
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YxaJafo[0].off = (void*)&sf - (void*)&t;
  YxaJafo[1].off = (void*)&sf - (void*)&Zf2;
  YxaJafo[2].off = (void*)&sf - (void*)&Aw;
  YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Tc *Ytlm__Ytlm_I_imt[] = {
 (Tc*)&Ytlm__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CException.NEW - YRHRa */
 (Tc*)YRHR, /* MEModule__CException.NEW - YRHR */
 (Tc*)YH0V, /* MEModule__CException.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CException.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CException.writeTo - YxaJ */
 (Tc*)Yoww, /* MEModule__CException.toString - Yoww */
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
char *StrYtlm[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Ytlm__T = {390, (Tc*)&YDGe, YH0V, StrYtlm, 0, 0, 0, 0, ToYtlm};
void YScq(Ti Apos, Tc *Atext) {
 Tr ex;
 Tr Ve = {NULL};
 Ve = Zao(YRHR(NULL, Atext), Ytlm__Ytlm_I_imt, 0);
 (*(YkxB**)(Ve.ptr + (size_t)Ve.table[2])) = MZ__posnr2pos(NULL, Apos);
 (ex = Ve);
 ZthrowIobject(ex);
}
Zfo YE2cfo[2] = {{0,(Tt*)&YEro__T},{0,0}};
YEro *YE2c(YEro *t, Ti Avalue) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YE2cfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YE2cfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3189000; t = Za(sizeof(YEro));}
 sf.pos=3189001;
 t->Vvalue = Avalue;
 sf.pos=3189002;
 t->Vmessage = ZcS(((Tc*)&YxJ1), Zint2string(Avalue));
 sf.pos=3189003;
 t->Vbacktrace = (sf.pos=3189004, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Ydtuafo[4] = {{0,(Tt*)&YEro__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Ydtua(YEro *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ydtuafo[0].off = (void*)&sf - (void*)&t;
  Ydtuafo[1].off = (void*)&sf - (void*)&Vw;
  Ydtuafo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Ydtuafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YXHSafo[3] = {{0,(Tt*)&YEro__T},{0,(Tt*)&iobj__T},{0,0}};
void YXHSa(YEro *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXHSafo[0].off = (void*)&sf - (void*)&t;
  YXHSafo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YXHSafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YEro__Yowwfo[4] = {{0,(Tt*)&YEro__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YEro__Yoww(YEro *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEro__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YEro__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YEro__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YEro__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9468900;
  ZthrowThisNil();
 }
 sf.pos=9468901;
 Vw = Za(sizeof(YjUM));
 sf.pos=9468902;
 YEro__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9468903;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YEro__YxaJafo[5] = {{0,(Tt*)&YEro__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEro__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YEro__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YEro__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YEro__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YEro__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Tc *YEro__Ytlm_I_imt[] = {
 (Tc*)&YEro__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CExit.NEW - YEro__YRHRa */
 (Tc*)0, /* MEModule__CExit.NEW - YEro__YRHR */
 (Tc*)Ydtua, /* MEModule__CExit.ToString - Ydtua */
 (Tc*)YEro__YxaJa, /* MEModule__CExit.writeTo - YEro__YxaJa */
 (Tc*)YXHSa, /* MEModule__CExit.writeTo - YXHSa */
 (Tc*)YEro__Yoww, /* MEModule__CExit.toString - YEro__Yoww */
 (Tc*)0, /* MEModule__CExit.getMessage - YEro__YCzX */
 (Tc*)0, /* MEModule__CExit.getPos - YEro__YvCK */
 (Tc*)0, /* MEModule__CExit.getBacktrace - YEro__Y4bq */
 (Tc*)0, /* Init - YEroa */
};
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
Tto YEro__T = {390, (Tc*)&YJMo, Ydtua, StrYEro, 0, 0, 0, 0, ToYEro};
void YNab(YkxB *Apos, Ti Aval) {
 Tr ex;
 YEro *Ve = 0;
 Tr t0 = {NULL};
 Ve = YE2c(NULL, Aval);
 Ve->Vpos = Apos;
 *Znao(&ex, Ve, YEro__Ytlm_I_imt, 1);
 ZthrowIobject(ex);
}
Zfo YDNobfo[2] = {{0,(Tt*)&YKhn__T},{0,0}};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDNobfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YDNobfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8064400; t = Za(sizeof(YKhn));}
 sf.pos=8064401;
 t->Vmessage = ZcS3(((Tc*)&YIBz), Zint2string(Asize), ((Tc*)&YDSH));
 sf.pos=8064402;
 t->Vpos = MZ__callerPos();
 sf.pos=8064403;
 t->Vbacktrace = (sf.pos=8064404, MZ__backtrace(1, Alimit));
 e->topFrame = sf.prev;
 return t;
}
Zfo YKhn__YwtA__YH0Vfo[4] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YKhn__YwtA__YH0V(YKhn *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YKhn__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YKhn__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YKhn__YwtA__Yowwfo[4] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YKhn__YwtA__Yoww(YKhn *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YKhn__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YKhn__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9057100;
  ZthrowThisNil();
 }
 sf.pos=9057101;
 Vw = Za(sizeof(YjUM));
 sf.pos=9057102;
 YKhn__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9057103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YKhn__YwtA__YxaJafo[5] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YKhn__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YKhn__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YKhn__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YKhn__YwtA__YxaJfo[3] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&iobj__T},{0,0}};
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YKhn__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YKhn__YwtA__Yoww, /* MEModule__COutOfMemory.toString - YKhn__YwtA__Yoww */
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
Tto YKhn__T = {390, (Tc*)&Y9Fv, YKhn__YwtA__YH0V, StrYKhn, 0, 0, 0, 0, ToYKhn};
void Y1KV(Ti Asize) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YDNob(NULL, Asize, 30), YKhn__Ytlm_I_imt, 4);
 ZthrowIobject(ex);
}
Zfo Y1uN__YwtA__YRHRfo[3] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&string__T},{0,0}};
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Y1uN__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3208600; t = Za(sizeof(Y1uN));}
 sf.pos=3208601;
 t->Vmessage = Amsg;
 sf.pos=3208602;
 t->Vpos = MZ__callerPos();
 sf.pos=3208603;
 t->Vbacktrace = (sf.pos=3208604, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Y1uN__YwtA__YH0Vfo[4] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y1uN__YwtA__YH0V(Y1uN *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Y1uN__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1uN__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Y1uN__YwtA__Yowwfo[4] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y1uN__YwtA__Yoww(Y1uN *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Y1uN__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1uN__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7911000;
  ZthrowThisNil();
 }
 sf.pos=7911001;
 Vw = Za(sizeof(YjUM));
 sf.pos=7911002;
 Y1uN__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=7911003;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y1uN__YwtA__YxaJafo[5] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Y1uN__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Y1uN__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Y1uN__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo Y1uN__YwtA__YxaJfo[3] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&iobj__T},{0,0}};
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Y1uN__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)Y1uN__YwtA__Yoww, /* MEModule__CNilAccess.toString - Y1uN__YwtA__Yoww */
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
Tto Y1uN__T = {390, (Tc*)&Y4wO, Y1uN__YwtA__YH0V, StrY1uN, 0, 0, 0, 0, ToY1uN};
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
Zfo YAxe__YwtA__YRHRfo[3] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&string__T},{0,0}};
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YAxe__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7358000; t = Za(sizeof(YAxe));}
 sf.pos=7358001;
 t->Vmessage = Amsg;
 sf.pos=7358002;
 t->Vpos = MZ__callerPos();
 sf.pos=7358003;
 t->Vbacktrace = (sf.pos=7358004, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YAxe__YwtA__YH0Vfo[4] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YAxe__YwtA__YH0V(YAxe *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YAxe__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YAxe__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YAxe__YwtA__Yowwfo[4] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YAxe__YwtA__Yoww(YAxe *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YAxe__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YAxe__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1829200;
  ZthrowThisNil();
 }
 sf.pos=1829201;
 Vw = Za(sizeof(YjUM));
 sf.pos=1829202;
 YAxe__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1829203;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YAxe__YwtA__YxaJafo[5] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YAxe__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YAxe__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YAxe__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YAxe__YwtA__YxaJfo[3] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&iobj__T},{0,0}};
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YAxe__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YAxe__YwtA__Yoww, /* MEModule__CMemoryAccess.toString - YAxe__YwtA__Yoww */
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
Tto YAxe__T = {390, (Tc*)&Y4QW, YAxe__YwtA__YH0V, StrYAxe, 0, 0, 0, 0, ToYAxe};
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
Zfo YVNj__YwtA__YRHRafo[4] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&string__T},{0,(Tt*)&YkxB__T},{0,0}};
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YRHRafo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YRHRafo[1].off = (void*)&sf - (void*)&Amsg;
  YVNj__YwtA__YRHRafo[2].off = (void*)&sf - (void*)&Apos;
 }
 sf.frof = YVNj__YwtA__YRHRafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6357800; t = Za(sizeof(YVNj));}
 sf.pos=6357801;
 t->Vmessage = Amsg;
 sf.pos=6357802;
 t->Vpos = Apos;
 sf.pos=6357803;
 t->Vbacktrace = (sf.pos=6357804, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YVNj__YwtA__YRHRfo[3] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&string__T},{0,0}};
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YVNj__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=5337700; t = Za(sizeof(YVNj));}
 sf.pos=5337701;
 t->Vmessage = Amsg;
 sf.pos=5337702;
 t->Vpos = MZ__callerPos();
 sf.pos=5337703;
 t->Vbacktrace = (sf.pos=5337704, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YVNj__YwtA__YH0Vfo[4] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YVNj__YwtA__YH0V(YVNj *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YVNj__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YVNj__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YVNj__YwtA__Yowwfo[4] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YVNj__YwtA__Yoww(YVNj *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YVNj__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YVNj__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9345300;
  ZthrowThisNil();
 }
 sf.pos=9345301;
 Vw = Za(sizeof(YjUM));
 sf.pos=9345302;
 YVNj__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9345303;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YVNj__YwtA__YxaJafo[5] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YVNj__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YVNj__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YVNj__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YVNj__YwtA__YxaJfo[3] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,0}};
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YVNj__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YVNj__YwtA__Yoww, /* MEModule__CInit.toString - YVNj__YwtA__Yoww */
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
Tto YVNj__T = {390, (Tc*)&Ysqt, YVNj__YwtA__YH0V, StrYVNj, 0, 0, 0, 0, ToYVNj};
void Y3w6(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YVNj__YwtA__YRHR(NULL, Atext), YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Zfo YtEE__YwtA__YRHRafo[4] = {{0,(Tt*)&YtEE__T},{0,(Tt*)&string__T},{0,(Tt*)&YkxB__T},{0,0}};
YtEE *YtEE__YwtA__YRHRa(YtEE *t, YkxB *Apos, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YtEE__YwtA__YRHRafo[0].off = (void*)&sf - (void*)&t;
  YtEE__YwtA__YRHRafo[1].off = (void*)&sf - (void*)&Amsg;
  YtEE__YwtA__YRHRafo[2].off = (void*)&sf - (void*)&Apos;
 }
 sf.frof = YtEE__YwtA__YRHRafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3133200; t = Za(sizeof(YtEE));}
 sf.pos=3133201;
 t->Vmessage = Amsg;
 sf.pos=3133202;
 t->Vpos = Apos;
 sf.pos=3133203;
 t->Vbacktrace = (sf.pos=3133204, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YtEE__YwtA__YH0Vfo[4] = {{0,(Tt*)&YtEE__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YtEE__YwtA__YH0V(YtEE *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YtEE__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YtEE__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YtEE__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YtEE__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9513500;
  ZthrowThisNil();
 }
 sf.pos=9513501;
 Vw = Za(sizeof(YjUM));
 sf.pos=9513502;
 YtEE__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9513503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YtEE__YwtA__Yowwfo[4] = {{0,(Tt*)&YtEE__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YtEE__YwtA__Yoww(YtEE *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YtEE__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YtEE__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YtEE__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YtEE__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4739100;
  ZthrowThisNil();
 }
 sf.pos=4739101;
 Vw = Za(sizeof(YjUM));
 sf.pos=4739102;
 YtEE__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=4739103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YtEE__YwtA__YxaJafo[5] = {{0,(Tt*)&YtEE__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YtEE__YwtA__YxaJa(YtEE *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YtEE__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YtEE__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YtEE__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YtEE__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YtEE__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3502900;
  ZthrowThisNil();
 }
 sf.pos=3502901;
 YtEE__YwtA__YxaJ(t, Aw);
 sf.pos=3502902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=3502903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3502904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3502905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=3502906;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=3502907;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=3502908;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3502909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=3502910;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=3502911;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3502912;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YtEE__YwtA__YxaJfo[3] = {{0,(Tt*)&YtEE__T},{0,(Tt*)&iobj__T},{0,0}};
void YtEE__YwtA__YxaJ(YtEE *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YtEE__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YtEE__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YtEE__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4523000;
  ZthrowThisNil();
 }
 sf.pos=4523001;
 if ((t->Vpos != NULL))
 {
  sf.pos=4523002;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4523003;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4523004;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4523005;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4523006;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4523007;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YtEE__Ytlm_I_imt[] = {
 (Tc*)&YtEE__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YtEE__YwtA__YRHRa, /* MEModule__CCheck.NEW - YtEE__YwtA__YRHRa */
 (Tc*)0, /* MEModule__CCheck.NEW - YtEE__YwtA__YRHR */
 (Tc*)YtEE__YwtA__YH0V, /* MEModule__CCheck.ToString - YtEE__YwtA__YH0V */
 (Tc*)YtEE__YwtA__YxaJa, /* MEModule__CCheck.writeTo - YtEE__YwtA__YxaJa */
 (Tc*)YtEE__YwtA__YxaJ, /* MEModule__CCheck.writeTo - YtEE__YwtA__YxaJ */
 (Tc*)YtEE__YwtA__Yoww, /* MEModule__CCheck.toString - YtEE__YwtA__Yoww */
 (Tc*)0, /* MEModule__CCheck.getMessage - YtEE__YwtA__YCzX */
 (Tc*)0, /* MEModule__CCheck.getPos - YtEE__YwtA__YvCK */
 (Tc*)0, /* MEModule__CCheck.getBacktrace - YtEE__YwtA__Y4bq */
 (Tc*)0, /* Init - YtEEa */
};
To ToYtEE[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYtEE[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YtEE__T = {390, (Tc*)&YvUM, YtEE__YwtA__YH0V, StrYtEE, 0, 0, 0, 0, ToYtEE};
Zfo Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&string__T},{0,0}};
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6059300; t = Za(sizeof(Yalz));}
 sf.pos=6059301;
 t->Vmessage = Amsg;
 sf.pos=6059302;
 t->Vpos = MZ__callerPos();
 sf.pos=6059303;
 t->Vbacktrace = (sf.pos=6059304, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yalz__YwtA__YH0V(Yalz *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yalz__YwtA__Yoww(Yalz *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5657300;
  ZthrowThisNil();
 }
 sf.pos=5657301;
 Vw = Za(sizeof(YjUM));
 sf.pos=5657302;
 Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5657303;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&iobj__T},{0,0}};
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)Yalz__YwtA__Yoww, /* MEModule__CBadValue.toString - Yalz__YwtA__Yoww */
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
Tto Yalz__T = {390, (Tc*)&YEZq, Yalz__YwtA__YH0V, StrYalz, 0, 0, 0, 0, ToYalz};
void Yaez(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yalz__YwtA__YRHR(NULL, Atext), Yalz__Ytlm_I_imt, 10);
 ZthrowIobject(ex);
}
Zfo Yw3O__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&string__T},{0,0}};
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Yw3O__Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=5638100; t = Za(sizeof(Yw3O));}
 sf.pos=5638101;
 t->Vmessage = Amsg;
 sf.pos=5638102;
 t->Vpos = MZ__callerPos();
 sf.pos=5638103;
 t->Vbacktrace = (sf.pos=5638104, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Yw3O__Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yw3O__Yalz__YwtA__YH0V(Yw3O *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Yw3O__Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yw3O__Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw3O__Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yw3O__Yalz__YwtA__Yoww(Yw3O *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Yw3O__Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yw3O__Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8398500;
  ZthrowThisNil();
 }
 sf.pos=8398501;
 Vw = Za(sizeof(YjUM));
 sf.pos=8398502;
 Yw3O__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8398503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw3O__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&iobj__T},{0,0}};
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Yw3O__Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo Yw3O__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Yw3O__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Yw3O__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Yw3O__Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)Yw3O__Yalz__YwtA__Yoww, /* MEModule__COutOfRange.toString - Yw3O__Yalz__YwtA__Yoww */
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
Tto Yw3O__T = {390, (Tc*)&YFK2, Yw3O__Yalz__YwtA__YH0V, StrYw3O, 0, 0, 0, 0, ToYw3O};
void Y6NT(Ti Aindex, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&YFDa), Zint2string(Aindex))), Yw3O__Ytlm_I_imt, 11);
 ZthrowIobject(ex);
}
Zfo Y2EX__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&string__T},{0,0}};
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Y2EX__Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=2958500; t = Za(sizeof(Y2EX));}
 sf.pos=2958501;
 t->Vmessage = Amsg;
 sf.pos=2958502;
 t->Vpos = MZ__callerPos();
 sf.pos=2958503;
 t->Vbacktrace = (sf.pos=2958504, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Y2EX__Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y2EX__Yalz__YwtA__YH0V(Y2EX *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Y2EX__Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y2EX__Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Y2EX__Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y2EX__Yalz__YwtA__Yoww(Y2EX *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Y2EX__Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y2EX__Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6792500;
  ZthrowThisNil();
 }
 sf.pos=6792501;
 Vw = Za(sizeof(YjUM));
 sf.pos=6792502;
 Y2EX__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6792503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y2EX__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&iobj__T},{0,0}};
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Y2EX__Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo Y2EX__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Y2EX__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Y2EX__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Y2EX__Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)Y2EX__Yalz__YwtA__Yoww, /* MEModule__CKeyNotFound.toString - Y2EX__Yalz__YwtA__Yoww */
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
Tto Y2EX__T = {390, (Tc*)&YRiW, Y2EX__Yalz__YwtA__YH0V, StrY2EX, 0, 0, 0, 0, ToY2EX};
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
Zfo YX0i__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&string__T},{0,0}};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YX0i__Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8500000; t = Za(sizeof(YX0i));}
 sf.pos=8500001;
 t->Vmessage = Amsg;
 sf.pos=8500002;
 t->Vpos = MZ__callerPos();
 sf.pos=8500003;
 t->Vbacktrace = (sf.pos=8500004, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YX0i__Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YX0i__Yalz__YwtA__YH0V(YX0i *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YX0i__Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YX0i__Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YX0i__Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YX0i__Yalz__YwtA__Yoww(YX0i *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YX0i__Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YX0i__Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=498400;
  ZthrowThisNil();
 }
 sf.pos=498401;
 Vw = Za(sizeof(YjUM));
 sf.pos=498402;
 YX0i__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=498403;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YX0i__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&iobj__T},{0,0}};
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YX0i__Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YX0i__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YX0i__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YX0i__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YX0i__Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YX0i__Yalz__YwtA__Yoww, /* MEModule__CKeyExists.toString - YX0i__Yalz__YwtA__Yoww */
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
Tto YX0i__T = {390, (Tc*)&Y9_h, YX0i__Yalz__YwtA__YH0V, StrYX0i, 0, 0, 0, 0, ToYX0i};
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
Zfo YP_P__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&YP_P__T},{0,(Tt*)&string__T},{0,0}};
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YP_P__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YP_P__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YP_P__Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=4520900; t = Za(sizeof(YP_P));}
 sf.pos=4520901;
 t->Vmessage = Amsg;
 sf.pos=4520902;
 t->Vpos = MZ__callerPos();
 sf.pos=4520903;
 t->Vbacktrace = (sf.pos=4520904, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YP_P__Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&YP_P__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YP_P__Yalz__YwtA__YH0V(YP_P *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YP_P__Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YP_P__Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YP_P__Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YP_P__Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YP_P__Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&YP_P__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YP_P__Yalz__YwtA__Yoww(YP_P *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YP_P__Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YP_P__Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YP_P__Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YP_P__Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1391700;
  ZthrowThisNil();
 }
 sf.pos=1391701;
 Vw = Za(sizeof(YjUM));
 sf.pos=1391702;
 YP_P__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1391703;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YP_P__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&YP_P__T},{0,(Tt*)&iobj__T},{0,0}};
void YP_P__Yalz__YwtA__YxaJ(YP_P *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YP_P__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YP_P__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YP_P__Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YP_P__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&YP_P__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YP_P__Yalz__YwtA__YxaJa(YP_P *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YP_P__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YP_P__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YP_P__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YP_P__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YP_P__Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YP_P__Yalz__YwtA__Yoww, /* MEModule__CIllegalByte.toString - YP_P__Yalz__YwtA__Yoww */
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
Tto YP_P__T = {390, (Tc*)&Ydbm, YP_P__Yalz__YwtA__YH0V, StrYP_P, 0, 0, 0, 0, ToYP_P};
Zfo YzSI__Ylz1__YwtA__YRHRfo[3] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&string__T},{0,0}};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YzSI__Ylz1__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7347100; t = Za(sizeof(YzSI));}
 sf.pos=7347101;
 t->Vmessage = Amsg;
 sf.pos=7347102;
 t->Vpos = MZ__callerPos();
 sf.pos=7347103;
 t->Vbacktrace = (sf.pos=7347104, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YzSI__Ylz1__YwtA__YH0Vfo[4] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YzSI__Ylz1__YwtA__YH0V(YzSI *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YzSI__Ylz1__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzSI__Ylz1__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YzSI__Ylz1__YwtA__Yowwfo[4] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YzSI__Ylz1__YwtA__Yoww(YzSI *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YzSI__Ylz1__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzSI__Ylz1__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6943500;
  ZthrowThisNil();
 }
 sf.pos=6943501;
 Vw = Za(sizeof(YjUM));
 sf.pos=6943502;
 YzSI__Ylz1__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6943503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YzSI__Ylz1__YwtA__YxaJfo[3] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&iobj__T},{0,0}};
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YzSI__Ylz1__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YzSI__Ylz1__YwtA__YxaJafo[5] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YzSI__Ylz1__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YzSI__Ylz1__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YzSI__Ylz1__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YzSI__Ylz1__YwtA__Yoww, /* MEModule__CDivideByZero.toString - YzSI__Ylz1__YwtA__Yoww */
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
Tto YzSI__T = {390, (Tc*)&YxFl, YzSI__Ylz1__YwtA__YH0V, StrYzSI, 0, 0, 0, 0, ToYzSI};
Zfo YXKl__YwtA__YRHRfo[3] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&string__T},{0,0}};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YXKl__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=4829900; t = Za(sizeof(YXKl));}
 sf.pos=4829901;
 t->Vmessage = Amsg;
 sf.pos=4829902;
 t->Vpos = MZ__callerPos();
 sf.pos=4829903;
 t->Vbacktrace = (sf.pos=4829904, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YXKl__YwtA__YH0Vfo[4] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YXKl__YwtA__YH0V(YXKl *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YXKl__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YXKl__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YXKl__YwtA__Yowwfo[4] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YXKl__YwtA__Yoww(YXKl *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YXKl__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YXKl__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3219100;
  ZthrowThisNil();
 }
 sf.pos=3219101;
 Vw = Za(sizeof(YjUM));
 sf.pos=3219102;
 YXKl__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=3219103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YXKl__YwtA__YxaJafo[5] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YXKl__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YXKl__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YXKl__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YXKl__YwtA__YxaJfo[3] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&iobj__T},{0,0}};
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YXKl__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YXKl__YwtA__Yoww, /* MEModule__CIOError.toString - YXKl__YwtA__Yoww */
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
Tto YXKl__T = {390, (Tc*)&YTj3, YXKl__YwtA__YH0V, StrYXKl, 0, 0, 0, 0, ToYXKl};
void YkuV(Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YXKl__YwtA__YRHR(NULL, Amsg), YXKl__Ytlm_I_imt, 19);
 ZthrowIobject(ex);
}
Zfo YdhHfo[2] = {{0,(Tt*)&YuDC__T},{0,0}};
YuDC *YdhH(YuDC *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YdhHfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YdhHfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8723500; t = Za(sizeof(YuDC));}
 sf.pos=8723501;
 t->Vmessage = ((Tc*)&Ynjz);
 sf.pos=8723502;
 t->Vpos = MZ__callerPos();
 sf.pos=8723503;
 t->Vbacktrace = (sf.pos=8723504, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YuDC__YwtA__YH0Vfo[4] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YuDC__YwtA__YH0V(YuDC *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YuDC__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YuDC__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YuDC__YwtA__Yowwfo[4] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YuDC__YwtA__Yoww(YuDC *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YuDC__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YuDC__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1676800;
  ZthrowThisNil();
 }
 sf.pos=1676801;
 Vw = Za(sizeof(YjUM));
 sf.pos=1676802;
 YuDC__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1676803;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YuDC__YwtA__YxaJafo[5] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YuDC__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YuDC__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YuDC__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YuDC__YwtA__YxaJfo[3] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&iobj__T},{0,0}};
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YuDC__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YuDC__YwtA__Yoww, /* MEModule__CWrongType.toString - YuDC__YwtA__Yoww */
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
Tto YuDC__T = {390, (Tc*)&YCoZ, YuDC__YwtA__YH0V, StrYuDC, 0, 0, 0, 0, ToYuDC};
void YTuG(Ti Apos) {
 Tr ex;
 YuDC *Ve = 0;
 Tr t0 = {NULL};
 Ve = YdhH(NULL);
 Ve->Vpos = MZ__posnr2pos(NULL, Apos);
 *Znao(&ex, Ve, YuDC__Ytlm_I_imt, 24);
 ZthrowIobject(ex);
}
Zfo YrHq__YwtA__YRHRfo[3] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&string__T},{0,0}};
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YrHq__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7808200; t = Za(sizeof(YrHq));}
 sf.pos=7808201;
 t->Vmessage = Amsg;
 sf.pos=7808202;
 t->Vpos = MZ__callerPos();
 sf.pos=7808203;
 t->Vbacktrace = (sf.pos=7808204, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YrHq__YwtA__YH0Vfo[4] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YrHq__YwtA__YH0V(YrHq *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YrHq__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YrHq__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YrHq__YwtA__Yowwfo[4] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YrHq__YwtA__Yoww(YrHq *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YrHq__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YrHq__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7987400;
  ZthrowThisNil();
 }
 sf.pos=7987401;
 Vw = Za(sizeof(YjUM));
 sf.pos=7987402;
 YrHq__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=7987403;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YrHq__YwtA__YxaJafo[5] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YrHq__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YrHq__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YrHq__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YrHq__YwtA__YxaJfo[3] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&iobj__T},{0,0}};
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YrHq__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YrHq__YwtA__Yoww, /* MEModule__CInternal.toString - YrHq__YwtA__Yoww */
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
Tto YrHq__T = {390, (Tc*)&YVki, YrHq__YwtA__YH0V, StrYrHq, 0, 0, 0, 0, ToYrHq};
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
Zfo YvL0fo[2] = {{0,(Tt*)&iobj__T},{0,0}};
void YvL0(Tr Ae) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YvL0fo[0].off = (void*)&sf - (void*)&Ae;
 }
 sf.frof = YvL0fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5238600;
 Ylxt();
 sf.pos=5238601;
 YQar(Ae, 1, YeNQ);
 sf.pos=5238623;
 ((Ts (*)(void*))(YeNQ.table[18]))(YeNQ.ptr);
 e->topFrame = sf.prev;
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
   YtEE__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238608)); return;
  case 9:
   return;
  case 10:
   Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238609)); return;
  case 11:
   Yw3O__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238610)); return;
  case 12:
   Y2EX__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238611)); return;
  case 13:
   return;
  case 14:
   YX0i__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238612)); return;
  case 15:
   YP_P__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238613)); return;
  case 16:
   return;
  case 17:
   YzSI__Ylz1__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238614)); return;
  case 18:
   return;
  case 19:
   YXKl__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238615)); return;
  case 20:
   return;
  case 21:
   return;
  case 22:
   return;
  case 23:
   return;
  case 24:
   YuDC__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238616)); return;
  case 25:
   return;
  case 26:
   YrHq__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238617)); return;
  case 27:
   Y2SD__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238618)); return;
  case 28:
   Yd7N__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238619)); return;
  case 29:
   Ys_q__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238620)); return;
  case 30:
   YOEA__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238621)); return;
  case 31:
   YgC4__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238622)); return;
  case 32:
   return;
 }
 ZthrowCstringBadValue("writeTo: cannot select method to invoke");
 return;
}
/* EModule done */
/* including PIPEModule bodies */
Zfo YPsVfo[2] = {{0,(Tt*)&YK7s__T},{0,0}};
YK7s *YPsV(YK7s *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YPsVfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YPsVfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6462200; t = Za(sizeof(YK7s));}
 sf.pos=6462201;
 t->VitemList = ZnewList((Tt*)&bool__T, 0);
 sf.pos=6462202;
 t->Vlock = YCyl(NULL);
 sf.pos=6462203;
 t->VreadCond = YXGL(NULL);
 sf.pos=6462204;
 t->VwriteCond = YXGL(NULL);
 sf.pos=6462205;
 t->VbufferSize = 1;
 sf.pos=6462206;
 t->VisOpen = 1;
 e->topFrame = sf.prev;
 return t;
}
Zfo YWtyfo[2] = {{0,(Tt*)&YK7s__T},{0,0}};
Ts YWty(YK7s *t, Tb Aitem) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YWtyfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWtyfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8236300;
  ZthrowThisNil();
 }
 sf.pos=8236301;
 YHl9(t->Vlock);
 sf.pos=8236302;
 while (1)
 {
  sf.pos=8236303;
  if (!(t->VisOpen))
  {
   sf.pos=8236304;
   Yvoo(t->Vlock);
   sf.pos=8236305;
   r = 0;
   rt = 1;
   goto YFdj;
  }
  sf.pos=8236306;
  if ((ZListSize(t->VitemList) < t->VbufferSize))
  {
   sf.pos=8236307;
   ZListInsert((Tl*)t->VitemList, 0, (Tz)(Ti)Aitem);
   rt = 2;
   goto YFdj;
  }
  sf.pos=8236308;
  YN6a(t->VwriteCond, t->Vlock);
YFdj:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto Ytc1;
 sf.pos=8236309;
 }
 sf.pos=8236310;
 Yvoo(t->Vlock);
 sf.pos=8236311;
 YjFj(t->VreadCond, 1);
 sf.pos=8236312;
 r = 1;
Ytc1:
 e->topFrame = sf.prev;
 return r;
}
Zfo YIWKfo[2] = {{0,(Tt*)&YK7s__T},{0,0}};
Tb YIWK(YK7s *t, Ts *Rst) {
 Tb Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YIWKfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YIWKfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2169200;
  ZthrowThisNil();
 }
 sf.pos=2169201;
 YHl9(t->Vlock);
 sf.pos=2169202;
 while (1)
 {
  sf.pos=2169203;
  if ((ZListSize(t->VitemList) > 0))
  {
   Tb Vs;
   sf.pos=2169204;
   (*Rst) = 1;
   sf.pos=2169205;
   Vs = ZListRemoveIntItem((Tl*)t->VitemList, -1);
   sf.pos=2169206;
   Yvoo(t->Vlock);
   sf.pos=2169207;
   YjFj(t->VwriteCond, 0);
   sf.pos=2169208;
   r = Vs;
   rt = 1;
   goto YUf8;
  }
  sf.pos=2169209;
  if (!(t->VisOpen))
  {
   sf.pos=2169210;
   (*Rst) = 0;
   rt = 2;
   goto YUf8;
  }
  sf.pos=2169211;
  YN6a(t->VreadCond, t->Vlock);
YUf8:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YbVa;
 sf.pos=2169212;
 }
 sf.pos=2169213;
 Yvoo(t->Vlock);
 Vret = 0;
 sf.pos=2169214;
 r = Vret;
YbVa:
 e->topFrame = sf.prev;
 return r;
}
Zfo YIWKafo[2] = {{0,(Tt*)&YK7s__T},{0,0}};
Tb YIWKa(YK7s *t) {
 Ts Vst;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YIWKafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YIWKafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4374400;
  ZthrowThisNil();
 }
 Vst = 0;
 sf.pos=4374401;
 r = YIWK(t, &(Vst));
 e->topFrame = sf.prev;
 return r;
}
To ToYK7s[] = {
 {6, 0},
 {0, (Tt*)&bool__T}, /* isOpen */
 {0, (Tt*)&int__T}, /* bufferSize */
 {0, (Tt*)&list__T}, /* itemList */
 {0, (Tt*)&YlXt__T}, /* lock */
 {0, (Tt*)&Y0Wo__T}, /* readCond */
 {0, (Tt*)&Y0Wo__T}, /* writeCond */
};
char *StrYK7s[] = {
 "isOpen",
 "bufferSize",
 "itemList",
 "lock",
 "readCond",
 "writeCond",
};
Tto YK7s__T = {390, (Tc*)&YLJT, 0, StrYK7s, 0, 0, 0, 0, ToYK7s};
/* PIPEModule done */
/* including SYSModule bodies */
Zfo YMsofo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti YMso(Tc *Acommand) {
 Ti Vr;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YMsofo[0].off = (void*)&sf - (void*)&Acommand;
 }
 sf.frof = YMsofo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vr = 0;
 sf.pos=9078600;
    fflush(stdout);
    Vr = system(ZgetCstring(Acommand));
 sf.pos=9078601;
 r = Vr;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yyxifo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Ti Yyxi(Tc *Acommand) {
 Ti Vr;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 Tc *Vcmd = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yyxifo[0].off = (void*)&sf - (void*)&Acommand;
  Yyxifo[1].off = (void*)&sf - (void*)&Vcmd;
 }
 sf.frof = Yyxifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7625400;
 Vcmd = ZcS(Acommand, ((Tc*)&YM));
 Vr = 0;
 sf.pos=7625401;
    fflush(stdout);
    Vr = system(ZgetCstring(Vcmd));
 sf.pos=7625402;
 r = Vr;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yhy5fo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *Yhy5(Tc *Aname) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yhy5fo[0].off = (void*)&sf - (void*)&Aname;
  Yhy5fo[1].off = (void*)&sf - (void*)&Vres;
 }
 sf.frof = Yhy5fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4232300;
 Vres = (Tc*)getenv(ZgetCstring(Aname));
 if (Vres != NULL) Vres = Zstr((char*)Vres);
 sf.pos=4232301;
 r = Vres;
 e->topFrame = sf.prev;
 return r;
}
Zfo Y2SD__YwtA__YRHRfo[3] = {{0,(Tt*)&Y2SD__T},{0,(Tt*)&string__T},{0,0}};
Y2SD *Y2SD__YwtA__YRHR(Y2SD *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2SD__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Y2SD__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Y2SD__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6412800; t = Za(sizeof(Y2SD));}
 sf.pos=6412801;
 t->Vmessage = Amsg;
 sf.pos=6412802;
 t->Vpos = MZ__callerPos();
 sf.pos=6412803;
 t->Vbacktrace = (sf.pos=6412804, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Y2SD__YwtA__YH0Vfo[4] = {{0,(Tt*)&Y2SD__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y2SD__YwtA__YH0V(Y2SD *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2SD__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Y2SD__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Y2SD__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y2SD__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5493600;
  ZthrowThisNil();
 }
 sf.pos=5493601;
 Vw = Za(sizeof(YjUM));
 sf.pos=5493602;
 Y2SD__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5493603;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y2SD__YwtA__Yowwfo[4] = {{0,(Tt*)&Y2SD__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y2SD__YwtA__Yoww(Y2SD *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2SD__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Y2SD__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Y2SD__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y2SD__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5880800;
  ZthrowThisNil();
 }
 sf.pos=5880801;
 Vw = Za(sizeof(YjUM));
 sf.pos=5880802;
 Y2SD__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5880803;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y2SD__YwtA__YxaJafo[5] = {{0,(Tt*)&Y2SD__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Y2SD__YwtA__YxaJa(Y2SD *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2SD__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Y2SD__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Y2SD__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Y2SD__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Y2SD__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2543400;
  ZthrowThisNil();
 }
 sf.pos=2543401;
 Y2SD__YwtA__YxaJ(t, Aw);
 sf.pos=2543402;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2543403;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2543404;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2543405;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2543406;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2543407;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2543408;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2543409;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2543410;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2543411;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2543412;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Y2SD__YwtA__YxaJfo[3] = {{0,(Tt*)&Y2SD__T},{0,(Tt*)&iobj__T},{0,0}};
void Y2SD__YwtA__YxaJ(Y2SD *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2SD__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Y2SD__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Y2SD__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3563500;
  ZthrowThisNil();
 }
 sf.pos=3563501;
 if ((t->Vpos != NULL))
 {
  sf.pos=3563502;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=3563503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=3563504;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=3563505;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=3563506;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=3563507;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *Y2SD__Ytlm_I_imt[] = {
 (Tc*)&Y2SD__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MSYSModule__CE_Process.NEW - Y2SD__YwtA__YRHRa */
 (Tc*)Y2SD__YwtA__YRHR, /* MSYSModule__CE_Process.NEW - Y2SD__YwtA__YRHR */
 (Tc*)Y2SD__YwtA__YH0V, /* MSYSModule__CE_Process.ToString - Y2SD__YwtA__YH0V */
 (Tc*)Y2SD__YwtA__YxaJa, /* MSYSModule__CE_Process.writeTo - Y2SD__YwtA__YxaJa */
 (Tc*)Y2SD__YwtA__YxaJ, /* MSYSModule__CE_Process.writeTo - Y2SD__YwtA__YxaJ */
 (Tc*)Y2SD__YwtA__Yoww, /* MSYSModule__CE_Process.toString - Y2SD__YwtA__Yoww */
 (Tc*)0, /* MSYSModule__CE_Process.getMessage - Y2SD__YwtA__YCzX */
 (Tc*)0, /* MSYSModule__CE_Process.getPos - Y2SD__YwtA__YvCK */
 (Tc*)0, /* MSYSModule__CE_Process.getBacktrace - Y2SD__YwtA__Y4bq */
 (Tc*)0, /* Init - Y2SDa */
};
To ToY2SD[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrY2SD[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Y2SD__T = {390, (Tc*)&YYbB, Y2SD__YwtA__YH0V, StrY2SD, 0, 0, 0, 0, ToY2SD};
Zfo YNAVfo[6] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,0}};
Ts YNAV(Tc *Apage) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 Tc *Vbrowser = NULL;
 Tl *Zf2 = NULL;
 Tc *Vn = NULL;
 Tl *t0 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YNAVfo[0].off = (void*)&sf - (void*)&Apage;
  YNAVfo[1].off = (void*)&sf - (void*)&Vbrowser;
  YNAVfo[2].off = (void*)&sf - (void*)&Zf2;
  YNAVfo[3].off = (void*)&sf - (void*)&Vn;
  YNAVfo[4].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YNAVfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6909500;
 Vbrowser = Yhy5(((Tc*)&Y1ke));
 sf.pos=6909501;
 if (((Vbrowser == NULL) || (ZbyteStringSize(Vbrowser) == 0)))
 {
  sf.pos=6909502;
  if (YpPE(((Tc*)&Ya0g)))
  {
   sf.pos=6909503;
   r = (((Yyxi(ZcS3(((Tc*)&Y0rB), Apage, ((Tc*)&YN))) == 0)) ? (1) : (0));
   rt = 1;
   goto YKzv;
  }
  sf.pos=6909504;
#if defined(__MINGW32__) || defined(_MSC_VER)
      ShellExecute(0, "open", ZgetCstring(Apage), 0, 0, 1);
#endif
  sf.pos=6909505;
  {
   Tfl Zf2i;
   Zf2 = (t0 = ZnewList((Tt*)&string__T, 5), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YCuE)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YwLx)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YUjM)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YJPW)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Y6Qb)));
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vn;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=6909506;
   Vbrowser = Ycmi(Vn);
   sf.pos=6909507;
   if (Y_3K(Vbrowser))
   {
    rt = 2;
    goto YSsF;
   }
   sf.pos=6909508;
   Vbrowser = NULL;
YSsF:
   if (rt == 2) { rt &= 1; break; }
   sf.pos=6909509;
   }
  }
YKzv:
  if (rt) goto Y1Dd;
 }
 sf.pos=6909510;
 if ((Vbrowser == NULL))
 {
  sf.pos=6909511;
  r = 0;
  rt = 1;
  goto Y1Dd;
 }
 sf.pos=6909512;
 r = (((Yyxi(ZcS5(Vbrowser, ((Tc*)&Y5Y), Apage, ((Tc*)&YN), (Tc*)1)) == 0)) ? (1) : (0));
Y1Dd:
 e->topFrame = sf.prev;
 return r;
}
Zfo YV43fo[3] = {{0,(Tt*)&YDTf__T},{0,(Tt*)&string__T},{0,0}};
YDTf *YV43(YDTf *t, Tc *Acmd) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YV43fo[0].off = (void*)&sf - (void*)&t;
  YV43fo[1].off = (void*)&sf - (void*)&Acmd;
 }
 sf.frof = YV43fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7894900; t = Za(sizeof(YDTf));}
 sf.pos=7894901;
 t->Vcmd = Acmd;
 sf.pos=7894902;
 t->VabortTimeout = 1000000;
 e->topFrame = sf.prev;
 return t;
}
Zfo YCLufo[3] = {{0,(Tt*)&YDTf__T},{0,(Tt*)&iobj__T},{0,0}};
YDTf *YCLu(YDTf *t) {
 Ti Vargc;
 Ti Vargidx;
 Tn *e = ZgetEnv();
 Zsf sf;
 YDTf *r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YCLufo[0].off = (void*)&sf - (void*)&t;
  YCLufo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YCLufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4040500;
  ZthrowThisNil();
 }
 sf.pos=4040501;
#ifdef HAVE_FORK
      pid_t pid;
      int stdin_fd = -1;
      int stdout_fd = -1;
      int stderr_fd = -1;
 sf.pos=4040502;
 if (t->Vstarted)
 {
  void *ex = NULL;
  sf.pos=4040503;
  ex = ((Tc*)&Yv1H);
  ZthrowPos(4040504, ex);
 }
 sf.pos=4040505;
 t->Vstarted = 1;
 Vargc = 0;
 Vargidx = 0;
 sf.pos=4040506;
 if ((t->Varglist != NULL))
 {
  sf.pos=4040507;
  Vargc = ZListSize(t->Varglist);
 }
 sf.pos=4040508;
      if (t->VstderrFname != NULL && t->VstderrToStdout) {
 sf.pos=4040509;
 YkuV(((Tc*)&YrFO));
 sf.pos=4040510;
      }
      if (t->VstdinFname != NULL) {
        stdin_fd = open(ZgetCstring(t->VstdinFname), O_RDONLY, 0);
        if (stdin_fd < 0) {
 sf.pos=4040511;
 YkuV(((Tc*)&Y_Ng));
 sf.pos=4040512;
        }
      }
      if (t->VstdoutFname != NULL) {
        stdout_fd = open(ZgetCstring(t->VstdoutFname), O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (stdout_fd < 0) {
 sf.pos=4040513;
 YkuV(((Tc*)&Ygc3));
 sf.pos=4040514;
        }
        if (t->VstderrToStdout) {
          stderr_fd = stdout_fd;
        }
      }
      if (t->VstderrFname != NULL) {
        stderr_fd = open(ZgetCstring(t->VstderrFname), O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (stderr_fd < 0) {
 sf.pos=4040515;
 YkuV(((Tc*)&Yn1N));
 sf.pos=4040516;
        }
      }

      pid = (Ti)fork();
      t->Vpid = pid;
      if (pid == -1) {
          if (stdin_fd >= 0) close(stdin_fd);
          if (stdout_fd >= 0) close(stdout_fd);
          if (stderr_fd >= 0 && stderr_fd != stdout_fd) close(stderr_fd);

          t->Vexited = 1;
 sf.pos=4040517;
 if (1)
 {
  Tr ex;
  sf.pos=4040518;
  *Znao(&ex, Y2SD__YwtA__YRHR(NULL, ((Tc*)&YaSc)), Y2SD__Ytlm_I_imt, 27);
  ZthrowIobject(ex);
 }
 sf.pos=4040519;
      } else if (pid == 0) {
          int dummy;
          /* child */
          /* TODO: reset signals to default */

          if (stdin_fd >= 0) {
            close(0);
            dummy = dup(stdin_fd);
          }
          if (stdout_fd >= 0) {
            close(1);
            dummy = dup(stdout_fd);
          }
          if (stderr_fd >= 0) {
            close(2);
            dummy = dup(stderr_fd);
          }
          /* TODO: stdin */

          {
            char **argv = (char **)malloc((unsigned)((Vargc + 2) * sizeof(char *)));
            argv[0] = ZgetCstring(t->Vcmd);
            for (Vargidx = 0; Vargidx < Vargc; ++Vargidx) {
              argv[Vargidx + 1] = ZgetCstring(((Tc *)ZListGetPtr(t->Varglist, Vargidx)));
            }
            argv[Vargc + 1] = NULL;
            execvp(argv[0], argv);
            _exit(Ybv7);  /* exec failed, return failure code */
          }
      } else {
          /* parent */
          if (stdin_fd >= 0) close(stdin_fd);
          if (stdout_fd >= 0) close(stdout_fd);
          if (stderr_fd >= 0 && stderr_fd != stdout_fd) close(stderr_fd);
      }
#endif  /* HAVE_FORK */
 sf.pos=4040520;
 r = t;
 e->topFrame = sf.prev;
 return r;
}
Zfo YHdEfo[2] = {{0,(Tt*)&YDTf__T},{0,0}};
Tb YHdE(YDTf *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YHdEfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YHdEfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3455600;
  ZthrowThisNil();
 }
 sf.pos=3455601;
 if ((!(t->Vstarted) || t->Vexited))
 {
  sf.pos=3455602;
  r = 0;
  rt = 1;
  goto Y_ZI;
 }
 sf.pos=3455603;
#ifdef HAVE_FORK
      {
        int  status = -1;
        int  wait_pid;
        wait_pid = waitpid(t->Vpid, &status, WNOHANG);
        if (wait_pid != 0) {
          if (wait_pid == t->Vpid) {
            t->Vexited = 1;
          } else if (wait_pid < 0 && errno == ECHILD) {
            t->Vexited = 1;
          }
        }
        if (t->Vexited == 1 && WIFEXITED(status)) {
          t->VdidExit = 1;
          t->VexitValue = WEXITSTATUS(status);
        }
      }
#endif  /* HAVE_FORK */
 sf.pos=3455604;
 r = !(t->Vexited);
Y_ZI:
 e->topFrame = sf.prev;
 return r;
}
Zfo YJmKafo[2] = {{0,(Tt*)&YDTf__T},{0,0}};
Ts YJmKa(YDTf *t, Ti Atimeout) {
 Ti Vend;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YJmKafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YJmKafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3627200;
  ZthrowThisNil();
 }
 sf.pos=3627201;
 if (!(YHdE(t)))
 {
  sf.pos=3627202;
  r = 1;
  rt = 1;
  goto Y6Su;
 }
 sf.pos=3627203;
 Vend = (Y9Rj() + Atimeout);
 sf.pos=3627204;
 while ((Y9Rj() < Vend))
 {
  sf.pos=3627205;
  YQzL(10000);
  sf.pos=3627206;
  if (!(YHdE(t)))
  {
   sf.pos=3627207;
   r = 1;
   rt = 1;
   goto YBg2;
  }
YBg2:
  if (rt) goto Y6Su;
 sf.pos=3627208;
 }
 sf.pos=3627209;
 r = 0;
Y6Su:
 e->topFrame = sf.prev;
 return r;
}
Zfo YYXCfo[2] = {{0,(Tt*)&YDTf__T},{0,0}};
YDTf *YYXC(YDTf *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YDTf *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YYXCfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YYXCfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4103100;
  ZthrowThisNil();
 }
 sf.pos=4103101;
 if (!(t->Vstarted))
 {
  void *ex = NULL;
  sf.pos=4103102;
  ex = ((Tc*)&Y5p2);
  ZthrowPos(4103103, ex);
 }
 sf.pos=4103104;
 if (t->Vexited)
 {
  void *ex = NULL;
  sf.pos=4103105;
  ex = ((Tc*)&YNx4);
  ZthrowPos(4103106, ex);
 }
 sf.pos=4103107;
#ifdef HAVE_FORK
      kill(t->Vpid, SIGKILL);
#endif
 sf.pos=4103108;
 r = t;
 e->topFrame = sf.prev;
 return r;
}
Zfo YkM8fo[3] = {{0,(Tt*)&YDTf__T},{0,(Tt*)&string__T},{0,0}};
YDTf *YkM8(YDTf *t, Tc *Afname) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YDTf *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YkM8fo[0].off = (void*)&sf - (void*)&t;
  YkM8fo[1].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = YkM8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5927700;
  ZthrowThisNil();
 }
 sf.pos=5927701;
 if (t->Vstarted)
 {
  void *ex = NULL;
  sf.pos=5927702;
  ex = ((Tc*)&Yv1H);
  ZthrowPos(5927703, ex);
 }
 sf.pos=5927704;
 t->VstdoutFname = Afname;
 sf.pos=5927705;
 r = t;
 e->topFrame = sf.prev;
 return r;
}
Zfo Y0hafo[2] = {{0,(Tt*)&YDTf__T},{0,0}};
YDTf *Y0ha(YDTf *t, Tb Ayes) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YDTf *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y0hafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y0hafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3892600;
  ZthrowThisNil();
 }
 sf.pos=3892601;
 if (t->Vstarted)
 {
  void *ex = NULL;
  sf.pos=3892602;
  ex = ((Tc*)&Yv1H);
  ZthrowPos(3892603, ex);
 }
 sf.pos=3892604;
 t->VstderrToStdout = Ayes;
 sf.pos=3892605;
 r = t;
 e->topFrame = sf.prev;
 return r;
}
To ToYDTf[] = {
 {12, 0},
 {0, (Tt*)&string__T}, /* cmd */
 {0, (Tt*)&list__T}, /* arglist */
 {0, (Tt*)&int__T}, /* abortTimeout */
 {0, (Tt*)&bool__T}, /* started */
 {0, (Tt*)&bool__T}, /* exited */
 {0, (Tt*)&int__T}, /* pid */
 {0, (Tt*)&bool__T}, /* didExit */
 {0, (Tt*)&int__T}, /* exitValue */
 {0, (Tt*)&string__T}, /* stdinFname */
 {0, (Tt*)&string__T}, /* stdoutFname */
 {0, (Tt*)&string__T}, /* stderrFname */
 {0, (Tt*)&bool__T}, /* stderrToStdout */
};
char *StrYDTf[] = {
 "cmd",
 "arglist",
 "abortTimeout",
 "started",
 "exited",
 "pid",
 "didExit",
 "exitValue",
 "stdinFname",
 "stdoutFname",
 "stderrFname",
 "stderrToStdout",
};
Tto YDTf__T = {390, (Tc*)&Y8vv, 0, StrYDTf, 0, 0, 0, 0, ToYDTf};
/* SYSModule done */
/* including HTTPModule bodies */
/* including Proto bodies */
Zfo Yd7N__YwtA__YRHRfo[3] = {{0,(Tt*)&Yd7N__T},{0,(Tt*)&string__T},{0,0}};
Yd7N *Yd7N__YwtA__YRHR(Yd7N *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yd7N__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Yd7N__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Yd7N__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3918600; t = Za(sizeof(Yd7N));}
 sf.pos=3918601;
 t->Vmessage = Amsg;
 sf.pos=3918602;
 t->Vpos = MZ__callerPos();
 sf.pos=3918603;
 t->Vbacktrace = (sf.pos=3918604, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Yd7N__YwtA__YH0Vfo[4] = {{0,(Tt*)&Yd7N__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yd7N__YwtA__YH0V(Yd7N *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yd7N__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Yd7N__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Yd7N__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yd7N__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2363400;
  ZthrowThisNil();
 }
 sf.pos=2363401;
 Vw = Za(sizeof(YjUM));
 sf.pos=2363402;
 Yd7N__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=2363403;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yd7N__YwtA__Yowwfo[4] = {{0,(Tt*)&Yd7N__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yd7N__YwtA__Yoww(Yd7N *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yd7N__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Yd7N__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Yd7N__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yd7N__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2750600;
  ZthrowThisNil();
 }
 sf.pos=2750601;
 Vw = Za(sizeof(YjUM));
 sf.pos=2750602;
 Yd7N__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=2750603;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yd7N__YwtA__YxaJafo[5] = {{0,(Tt*)&Yd7N__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Yd7N__YwtA__YxaJa(Yd7N *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yd7N__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Yd7N__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Yd7N__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Yd7N__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Yd7N__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5329200;
  ZthrowThisNil();
 }
 sf.pos=5329201;
 Yd7N__YwtA__YxaJ(t, Aw);
 sf.pos=5329202;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=5329203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5329204;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5329205;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=5329206;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=5329207;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=5329208;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5329209;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=5329210;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=5329211;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5329212;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Yd7N__YwtA__YxaJfo[3] = {{0,(Tt*)&Yd7N__T},{0,(Tt*)&iobj__T},{0,0}};
void Yd7N__YwtA__YxaJ(Yd7N *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yd7N__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Yd7N__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Yd7N__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6349300;
  ZthrowThisNil();
 }
 sf.pos=6349301;
 if ((t->Vpos != NULL))
 {
  sf.pos=6349302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=6349303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=6349304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=6349305;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=6349306;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=6349307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *Yd7N__Ytlm_I_imt[] = {
 (Tc*)&Yd7N__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MProto__CE_ParseError.NEW - Yd7N__YwtA__YRHRa */
 (Tc*)Yd7N__YwtA__YRHR, /* MProto__CE_ParseError.NEW - Yd7N__YwtA__YRHR */
 (Tc*)Yd7N__YwtA__YH0V, /* MProto__CE_ParseError.ToString - Yd7N__YwtA__YH0V */
 (Tc*)Yd7N__YwtA__YxaJa, /* MProto__CE_ParseError.writeTo - Yd7N__YwtA__YxaJa */
 (Tc*)Yd7N__YwtA__YxaJ, /* MProto__CE_ParseError.writeTo - Yd7N__YwtA__YxaJ */
 (Tc*)Yd7N__YwtA__Yoww, /* MProto__CE_ParseError.toString - Yd7N__YwtA__Yoww */
 (Tc*)0, /* MProto__CE_ParseError.getMessage - Yd7N__YwtA__YCzX */
 (Tc*)0, /* MProto__CE_ParseError.getPos - Yd7N__YwtA__YvCK */
 (Tc*)0, /* MProto__CE_ParseError.getBacktrace - Yd7N__YwtA__Y4bq */
 (Tc*)0, /* Init - Yd7Na */
};
To ToYd7N[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYd7N[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Yd7N__T = {390, (Tc*)&Y8kY, Yd7N__YwtA__YH0V, StrYd7N, 0, 0, 0, 0, ToYd7N};
Zfo Ys_q__YwtA__YRHRfo[3] = {{0,(Tt*)&Ys_q__T},{0,(Tt*)&string__T},{0,0}};
Ys_q *Ys_q__YwtA__YRHR(Ys_q *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ys_q__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Ys_q__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Ys_q__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7083300; t = Za(sizeof(Ys_q));}
 sf.pos=7083301;
 t->Vmessage = Amsg;
 sf.pos=7083302;
 t->Vpos = MZ__callerPos();
 sf.pos=7083303;
 t->Vbacktrace = (sf.pos=7083304, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Ys_q__YwtA__YH0Vfo[4] = {{0,(Tt*)&Ys_q__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Ys_q__YwtA__YH0V(Ys_q *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ys_q__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Ys_q__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Ys_q__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Ys_q__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Ys_q__YwtA__Yowwfo[4] = {{0,(Tt*)&Ys_q__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Ys_q__YwtA__Yoww(Ys_q *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ys_q__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Ys_q__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Ys_q__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Ys_q__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2105300;
  ZthrowThisNil();
 }
 sf.pos=2105301;
 Vw = Za(sizeof(YjUM));
 sf.pos=2105302;
 Ys_q__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=2105303;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Ys_q__YwtA__YxaJafo[5] = {{0,(Tt*)&Ys_q__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Ys_q__YwtA__YxaJa(Ys_q *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ys_q__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Ys_q__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Ys_q__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Ys_q__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Ys_q__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo Ys_q__YwtA__YxaJfo[3] = {{0,(Tt*)&Ys_q__T},{0,(Tt*)&iobj__T},{0,0}};
void Ys_q__YwtA__YxaJ(Ys_q *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ys_q__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Ys_q__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Ys_q__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)Ys_q__YwtA__Yoww, /* MProto__CE_ProduceError.toString - Ys_q__YwtA__Yoww */
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
Tto Ys_q__T = {390, (Tc*)&Y4sk, Ys_q__YwtA__YH0V, StrYs_q, 0, 0, 0, 0, ToYs_q};
Zfo YOEA__YwtA__YRHRfo[3] = {{0,(Tt*)&YOEA__T},{0,(Tt*)&string__T},{0,0}};
YOEA *YOEA__YwtA__YRHR(YOEA *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YOEA__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YOEA__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YOEA__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=4631200; t = Za(sizeof(YOEA));}
 sf.pos=4631201;
 t->Vmessage = Amsg;
 sf.pos=4631202;
 t->Vpos = MZ__callerPos();
 sf.pos=4631203;
 t->Vbacktrace = (sf.pos=4631204, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YOEA__YwtA__YH0Vfo[4] = {{0,(Tt*)&YOEA__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YOEA__YwtA__YH0V(YOEA *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YOEA__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YOEA__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YOEA__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YOEA__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YOEA__YwtA__Yowwfo[4] = {{0,(Tt*)&YOEA__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YOEA__YwtA__Yoww(YOEA *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YOEA__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YOEA__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YOEA__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YOEA__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8441600;
  ZthrowThisNil();
 }
 sf.pos=8441601;
 Vw = Za(sizeof(YjUM));
 sf.pos=8441602;
 YOEA__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8441603;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YOEA__YwtA__YxaJafo[5] = {{0,(Tt*)&YOEA__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YOEA__YwtA__YxaJa(YOEA *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YOEA__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YOEA__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YOEA__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YOEA__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YOEA__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YOEA__YwtA__YxaJfo[3] = {{0,(Tt*)&YOEA__T},{0,(Tt*)&iobj__T},{0,0}};
void YOEA__YwtA__YxaJ(YOEA *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YOEA__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YOEA__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YOEA__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
 (Tc*)YOEA__YwtA__Yoww, /* MProto__CE_BinaryError.toString - YOEA__YwtA__Yoww */
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
Tto YOEA__T = {390, (Tc*)&YtJ_, YOEA__YwtA__YH0V, StrYOEA, 0, 0, 0, 0, ToYOEA};
Zfo Ykwwfo[3] = {{0,(Tt*)&YqvM__T},{0,(Tt*)&string__T},{0,0}};
YqvM *Ykww(YqvM *t, Tc *Aname, Ti Anr, Te Atype, Tb Arepeated) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ykwwfo[0].off = (void*)&sf - (void*)&t;
  Ykwwfo[1].off = (void*)&sf - (void*)&Aname;
 }
 sf.frof = Ykwwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=1366600; t = Za(sizeof(YqvM));}
 sf.pos=1366601;
 t->Vname = Aname;
 sf.pos=1366602;
 t->Vnr = Anr;
 sf.pos=1366603;
 t->Vtype = Atype;
 sf.pos=1366604;
 t->Vrepeated = Arepeated;
 e->topFrame = sf.prev;
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
Tto YqvM__T = {390, (Tc*)&Y5d5, 0, StrYqvM, 0, 0, 0, 0, ToYqvM};
Zfo YrCUafo[3] = {{0,(Tt*)&YLWE__T},{0,(Tt*)&iobj__T},{0,0}};
YLWE *YrCUa(YLWE *t, Tr Awriter, Tb AwithRefs) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrCUafo[0].off = (void*)&sf - (void*)&t;
  YrCUafo[1].off = (void*)&sf - (void*)&Awriter;
 }
 sf.frof = YrCUafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=226800; t = Za(sizeof(YLWE));}
 sf.pos=226801;
 t->Vwriter = Awriter;
 sf.pos=226802;
 if (AwithRefs)
 {
  sf.pos=226803;
  YEV9(t);
 }
 e->topFrame = sf.prev;
 return t;
}
Zfo YrCUbfo[4] = {{0,(Tt*)&YLWE__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
YLWE *YrCUb(YLWE *t, Tr Awriter, Tc *Aindent, Tb AuseNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrCUbfo[0].off = (void*)&sf - (void*)&t;
  YrCUbfo[1].off = (void*)&sf - (void*)&Aindent;
  YrCUbfo[2].off = (void*)&sf - (void*)&Awriter;
 }
 sf.frof = YrCUbfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=1246900; t = Za(sizeof(YLWE));}
 sf.pos=1246901;
 t->Vwriter = Awriter;
 sf.pos=1246902;
 t->Vindent = Aindent;
 sf.pos=1246903;
 t->VuseNr = AuseNr;
 sf.pos=1246904;
 YEV9(t);
 e->topFrame = sf.prev;
 return t;
}
Zfo YEV9fo[2] = {{0,(Tt*)&YLWE__T},{0,0}};
void YEV9(YLWE *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEV9fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YEV9fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3295600;
  ZthrowThisNil();
 }
 sf.pos=3295601;
 t->VderefTime = ++(YcTI);
 sf.pos=3295602;
 t->VderefTimeSize = t->VderefTime;
 e->topFrame = sf.prev;
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
Tto YLWE__T = {390, (Tc*)&YaKG, 0, StrYLWE, 0, 0, 0, 0, ToYLWE};
Zfo YRBzfo[2] = {{0,(Tt*)&YBRp__T},{0,0}};
YBRp *YRBz(YBRp *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (t == NULL) t = Za(sizeof(YBRp));
 if (!sfF) {
  sfF = 1;
  YRBzfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YRBzfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7401200;
 t->Vlnum = 1;
 e->topFrame = sf.prev;
 return t;
}
Zfo YtIRafo[3] = {{0,(Tt*)&YBRp__T},{0,(Tt*)&iobj__T},{0,0}};
YBRp *YtIRa(YBRp *t, Tr Areader, Tb AwithRefs) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YtIRafo[0].off = (void*)&sf - (void*)&t;
  YtIRafo[1].off = (void*)&sf - (void*)&Areader;
 }
 sf.frof = YtIRafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=2771000; t = YRBz(NULL);}
 sf.pos=2771001;
 t->VtheCharReader = Ynyh(NULL, Areader);
 sf.pos=2771002;
 if (AwithRefs)
 {
  sf.pos=2771003;
  t->Vrefs = ZnewDict((Tt*)&int__T, (Tt*)&iobj__T, 0);
 }
 e->topFrame = sf.prev;
 return t;
}
Zfo Ytm4fo[2] = {{0,(Tt*)&YBRp__T},{0,0}};
YrC3 *Ytm4(YBRp *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YrC3 *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ytm4fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Ytm4fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=560900;
  ZthrowThisNil();
 }
 sf.pos=560901;
 r = t->VtheCharReader;
 e->topFrame = sf.prev;
 return r;
}
Zfo Y9eVfo[2] = {{0,(Tt*)&YBRp__T},{0,0}};
YBRp *Y9eV(YBRp *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YBRp *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y9eVfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y9eVfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5918700;
  ZthrowThisNil();
 }
 sf.pos=5918701;
 r = t;
 e->topFrame = sf.prev;
 return r;
}
Zfo YnlRfo[2] = {{0,(Tt*)&YBRp__T},{0,0}};
Tr YnlR(YBRp *t, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YnlRfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YnlRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9926900;
  ZthrowThisNil();
 }
 sf.pos=9926901;
 r = ZDictGetIobjDef(t->Vrefs, (Tz)(Ti)Aidx, trZero);
 e->topFrame = sf.prev;
 return r;
}
Tc *YBRp__YMd3_imt[] = {
 (Tc*)&YBRp__T,
 (Tc*)0, /* MProto__CReader.byteReader - YoPK */
 (Tc*)Ytm4, /* MProto__CReader.charReader - Ytm4 */
 (Tc*)Y9eV, /* MProto__CReader.protoReader - Y9eV */
 (Tc*)0, /* MProto__CReader.addRef - Y_ZW */
};
To ToYBRp[] = {
 {3, 0},
 {0, (Tt*)&YrC3__T}, /* theCharReader */
 {0, (Tt*)&dict__T}, /* refs */
 {0, (Tt*)&int__T}, /* lnum */
};
char *StrYBRp[] = {
 "theCharReader",
 "refs",
 "lnum",
};
Tto YBRp__T = {390, (Tc*)&Y0Er, 0, StrYBRp, 0, 0, 0, 0, ToYBRp};
Zfo Ybypfo[2] = {{0,(Tt*)&YqvM__T},{0,0}};
Ti Ybyp(YqvM *Afspec) {
 Ti Vtag;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ybypfo[0].off = (void*)&sf - (void*)&Afspec;
 }
 sf.frof = Ybypfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4959900;
 Vtag = (((Afspec->Vnr << YqNA)) + ZDictGetInt(YLwW, (Tz)(Ti)ZDictGetInt(YXCQ, (Tz)(Ti)Afspec->Vtype)));
 sf.pos=4959901;
 r = YmeT(Vtag);
 e->topFrame = sf.prev;
 return r;
}
Zfo YFN0fo[10] = {{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&list__T},{0,(Tt*)&byteString__T},{0,(Tt*)&iobj__T},{0,(Tt*)&byteString__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YqvM__T},{0,(Tt*)&iobj__T},{0,0}};
Ti YFN0(Tr Amsg, YLWE *AprotoWriter) {
 Ti Vsize;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 Tl *Zf1 = NULL;
 Tc *Vs = NULL;
 Tr Vother = {NULL};
 Tc *Vs1 = NULL;
 Tr Vother1 = {NULL};
 YqvM *Vfspec = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YFN0fo[0].off = (void*)&sf - (void*)&Amsg;
  YFN0fo[1].off = (void*)&sf - (void*)&AprotoWriter;
  YFN0fo[2].off = (void*)&sf - (void*)&Zf1;
  YFN0fo[3].off = (void*)&sf - (void*)&Vs;
  YFN0fo[4].off = (void*)&sf - (void*)&Vother;
  YFN0fo[5].off = (void*)&sf - (void*)&Vs1;
  YFN0fo[6].off = (void*)&sf - (void*)&Vother1;
  YFN0fo[7].off = (void*)&sf - (void*)&Vfspec;
  YFN0fo[8].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YFN0fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YMrVfo[6] = {{0,(Tt*)&iobj__T},{0,(Tt*)&YqvM__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&YqvM__T},{0,0}};
Ti YMrV(Tr At, Tr Amsg, YqvM *Afspec, YLWE *AprotoWriter) {
 Ti Vsize;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 YqvM *VintFspec = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YMrVfo[0].off = (void*)&sf - (void*)&At;
  YMrVfo[1].off = (void*)&sf - (void*)&Afspec;
  YMrVfo[2].off = (void*)&sf - (void*)&Amsg;
  YMrVfo[3].off = (void*)&sf - (void*)&AprotoWriter;
  YMrVfo[4].off = (void*)&sf - (void*)&VintFspec;
 }
 sf.frof = YMrVfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YP8Zfo[8] = {{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&list__T},{0,(Tt*)&YqvM__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
void YP8Z(Tr Amsg, YLWE *AprotoWriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YqvM *Vfspec = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YP8Zfo[0].off = (void*)&sf - (void*)&Amsg;
  YP8Zfo[1].off = (void*)&sf - (void*)&AprotoWriter;
  YP8Zfo[2].off = (void*)&sf - (void*)&Zf2;
  YP8Zfo[3].off = (void*)&sf - (void*)&Vfspec;
  YP8Zfo[4].off = (void*)&sf - (void*)&t0;
  YP8Zfo[5].off = (void*)&sf - (void*)&t1;
  YP8Zfo[6].off = (void*)&sf - (void*)&t2;
 }
 sf.frof = YP8Zfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YWEgfo[9] = {{0,(Tt*)&YqvM__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,0}};
void YWEg(Tr Amsg, YqvM *Afspec, Ti Aidx, YLWE *AprotoWriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *Vv = NULL;
 Tc *Vname = NULL;
 Tc *Vindent = NULL;
 Tr Vwriter = {NULL};
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWEgfo[0].off = (void*)&sf - (void*)&Afspec;
  YWEgfo[1].off = (void*)&sf - (void*)&Amsg;
  YWEgfo[2].off = (void*)&sf - (void*)&AprotoWriter;
  YWEgfo[3].off = (void*)&sf - (void*)&Vv;
  YWEgfo[4].off = (void*)&sf - (void*)&Vname;
  YWEgfo[5].off = (void*)&sf - (void*)&Vindent;
  YWEgfo[6].off = (void*)&sf - (void*)&Vwriter;
  YWEgfo[7].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YWEgfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YeeBfo[4] = {{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&iobj__T},{0,0}};
void YeeB(Tr At, Ti AfieldNr, YLWE *AprotoWriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr Vmsg = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YeeBfo[0].off = (void*)&sf - (void*)&At;
  YeeBfo[1].off = (void*)&sf - (void*)&AprotoWriter;
  YeeBfo[2].off = (void*)&sf - (void*)&Vmsg;
 }
 sf.frof = YeeBfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6491200;
 Vmsg = ((Tr (*)(void*, Ti))(At.table[38]))(At.ptr, AfieldNr);
 sf.pos=6491201;
 if ((((Vmsg).ptr) != NULL))
 {
  sf.pos=6491202;
  YP8Z(Vmsg, AprotoWriter);
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YeeBafo[4] = {{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&iobj__T},{0,0}};
void YeeBa(Tr At, Ti AfieldNr, Ti Aidx, YLWE *AprotoWriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr Vmsg = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YeeBafo[0].off = (void*)&sf - (void*)&At;
  YeeBafo[1].off = (void*)&sf - (void*)&AprotoWriter;
  YeeBafo[2].off = (void*)&sf - (void*)&Vmsg;
 }
 sf.frof = YeeBafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7198800;
 Vmsg = ((Tr (*)(void*, Ti, Ti))(At.table[37]))(At.ptr, AfieldNr, Aidx);
 sf.pos=7198801;
 if ((((Vmsg).ptr) != NULL))
 {
  sf.pos=7198802;
  YP8Z(Vmsg, AprotoWriter);
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YsvGfo[8] = {{0,(Tt*)&list__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YqvM__T},{0,(Tt*)&YrC3__T},{0,(Tt*)&iobj__T},{0,0}};
void YsvG(Tr Amsg, Tl *Afspecs, Tr AiReader) {
 Ti Vb;
 Ti VfieldIndex;
 Ti Vc;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YqvM *Vfspec = 0;
 YrC3 *Vsreader = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YsvGfo[0].off = (void*)&sf - (void*)&Afspecs;
  YsvGfo[1].off = (void*)&sf - (void*)&Amsg;
  YsvGfo[2].off = (void*)&sf - (void*)&AiReader;
  YsvGfo[3].off = (void*)&sf - (void*)&Zf2;
  YsvGfo[4].off = (void*)&sf - (void*)&Vfspec;
  YsvGfo[5].off = (void*)&sf - (void*)&Vsreader;
  YsvGfo[6].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YsvGfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7240400;
 Vsreader = ((YrC3* (*)(void*))(AiReader.table[2]))(AiReader.ptr);
 sf.pos=7240401;
 Vb = YVZB(Vsreader);
 sf.pos=7240402;
 if ((Vb != 91))
 {
  Tr ex;
  sf.pos=7240403;
  *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ZcS(((Tc*)&YP1D), Zint2string(Vb))), Yd7N__Ytlm_I_imt, 28);
  ZthrowIobject(ex);
 }
 sf.pos=7240404;
 VfieldIndex = 1;
 sf.pos=7240405;
 Vc = YVZB(Vsreader);
 sf.pos=7240406;
 if ((Vc == Y3QJ))
 {
  Tr ex;
  sf.pos=7240407;
  *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&YDDS)), Yd7N__Ytlm_I_imt, 28);
  ZthrowIobject(ex);
 }
 sf.pos=7240408;
 while (1)
 {
  Tb Vdone;
  Ti VnextChar;
  sf.pos=7240409;
  if ((Vc == 93))
  {
   rt = 2;
   goto YjuG;
  }
  sf.pos=7240410;
  if ((VfieldIndex > 50))
  {
   sf.pos=7240411;
   Y3er(Vsreader, Vc);
   sf.pos=7240412;
   VfieldIndex = YZHh(Vsreader);
   sf.pos=7240413;
   if ((VfieldIndex < 0))
   {
    Tr ex;
    sf.pos=7240414;
    *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&Y3Sh)), Yd7N__Ytlm_I_imt, 28);
    ZthrowIobject(ex);
   }
   sf.pos=7240415;
   if ((VfieldIndex <= 50))
   {
    Tr ex;
    sf.pos=7240416;
    *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ZcS(((Tc*)&YACF), Zint2string(VfieldIndex))), Yd7N__Ytlm_I_imt, 28);
    ZthrowIobject(ex);
   }
   sf.pos=7240417;
   Vc = YVZB(Vsreader);
   sf.pos=7240418;
   if ((Vc != 44))
   {
    Tr ex;
    sf.pos=7240419;
    *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ZcS(((Tc*)&YQxb), Zint2string(VfieldIndex))), Yd7N__Ytlm_I_imt, 28);
    ZthrowIobject(ex);
   }
  }
  else
  {
   sf.pos=7240420;
   if ((Vc == 44))
   {
    sf.pos=7240421;
    ++(VfieldIndex);
    sf.pos=7240422;
    Vc = YVZB(Vsreader);
    rt = 4;
    if (rt) goto Ybz9;
   }
   sf.pos=7240423;
   Y3er(Vsreader, Vc);
Ybz9:
   if (rt) goto YjuG;
  }
  Vdone = 0;
  VnextChar = 0;
  sf.pos=7240424;
  {
   Tfl Zf2i;
   Zf2 = Afspecs;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vfspec;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=7240425;
   if ((Vfspec->Vnr == VfieldIndex))
   {
    sf.pos=7240426;
    if (Vfspec->Vrepeated)
    {
     sf.pos=7240427;
     Vc = YVZB(Vsreader);
     sf.pos=7240428;
     if ((Vc == 91))
     {
      Ti Vcnt;
      Vcnt = 0;
      sf.pos=7240429;
      while (1)
      {
       sf.pos=7240430;
       Vdone = Yq4x(Amsg, Vfspec, AiReader);
       sf.pos=7240431;
       if (!(Vdone))
       {
        sf.pos=7240432;
        YzK3(Vsreader);
       }
       else
       {
        sf.pos=7240433;
        Vc = YVZB(Vsreader);
        sf.pos=7240434;
        if ((Vc == 93))
        {
         rt = 2;
         goto YSLY;
        }
        sf.pos=7240435;
        if ((Vc != 44))
        {
         Tr ex;
         sf.pos=7240436;
         *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ZcS5(((Tc*)&YtkV), ZintAsString(Vc), ((Tc*)&YgO5), Zint2string(Vcnt), ((Tc*)&Y54q))), Yd7N__Ytlm_I_imt, 28);
         ZthrowIobject(ex);
        }
YSLY:
        if (rt) goto Yp1O;
       }
       sf.pos=7240437;
       ++(Vcnt);
Yp1O:
       if (rt == 2) { rt &= 1; break; }
      sf.pos=7240438;
      }
      sf.pos=7240439;
      Vdone = 1;
     }
     else
     {
      Tr ex;
      sf.pos=7240440;
      *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&Y9tS)), Yd7N__Ytlm_I_imt, 28);
      ZthrowIobject(ex);
     }
    }
    else
    {
     sf.pos=7240441;
     Vdone = Yq4x(Amsg, Vfspec, AiReader);
    }
    rt = 2;
    goto Yz1s;
   }
Yz1s:
   if (rt == 2) { rt &= 1; break; }
   sf.pos=7240442;
   }
  }
  sf.pos=7240443;
  if (!(Vdone))
  {
   sf.pos=7240444;
   YzK3(Vsreader);
  }
  sf.pos=7240445;
  Vc = YVZB(Vsreader);
  sf.pos=7240446;
  if ((Vc != 93))
  {
   sf.pos=7240447;
   if ((Vc != 44))
   {
    Tr ex;
    sf.pos=7240448;
    *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&Yq6r)), Yd7N__Ytlm_I_imt, 28);
    ZthrowIobject(ex);
   }
   sf.pos=7240449;
   Vc = YVZB(Vsreader);
  }
  sf.pos=7240450;
  ++(VfieldIndex);
YjuG:
  if (rt == 2) { rt &= 1; break; }
  if (rt == 4) { rt &= 1; continue; }
 sf.pos=7240451;
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Yq4xfo[9] = {{0,(Tt*)&YqvM__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&string__T},{0,(Tt*)&YBRp__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YrC3__T},{0,(Tt*)&iobj__T},{0,0}};
Tb Yq4x(Tr Amsg, YqvM *Afspec, Tr AiReader) {
 Tb Vdone;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tc *Vs = NULL;
 YBRp *VpReader = 0;
 Tr Vm = {NULL};
 YrC3 *Vsreader = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yq4xfo[0].off = (void*)&sf - (void*)&Afspec;
  Yq4xfo[1].off = (void*)&sf - (void*)&Amsg;
  Yq4xfo[2].off = (void*)&sf - (void*)&AiReader;
  Yq4xfo[3].off = (void*)&sf - (void*)&Vs;
  Yq4xfo[4].off = (void*)&sf - (void*)&VpReader;
  Yq4xfo[5].off = (void*)&sf - (void*)&Vm;
  Yq4xfo[6].off = (void*)&sf - (void*)&Vsreader;
  Yq4xfo[7].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yq4xfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4003500;
 Vsreader = ((YrC3* (*)(void*))(AiReader.table[2]))(AiReader.ptr);
 Vdone = 0;
 sf.pos=4003501;
 switch (Afspec->Vtype)
 {
 case 9:
 case 11:
  {
   Ti Vn;
   sf.pos=4003502;
   Vn = YZHh(Vsreader);
   sf.pos=4003503;
   ((void (*)(void*, Ti, Ti))(Amsg.table[29]))(Amsg.ptr, Afspec->Vnr, Vn);
   sf.pos=4003504;
   Vdone = 1;
    break;
  }
 case 10:
  {
   Ti32 Vn;
   sf.pos=4003505;
   Vn = YZHh(Vsreader);
   sf.pos=4003506;
   ((void (*)(void*, Ti, Ti32))(Amsg.table[30]))(Amsg.ptr, Afspec->Vnr, Vn);
   sf.pos=4003507;
   Vdone = 1;
    break;
  }
 case 19:
  {
   Tu Vn;
   sf.pos=4003508;
   Vn = YZHh(Vsreader);
   sf.pos=4003509;
   ((void (*)(void*, Ti, Tu))(Amsg.table[31]))(Amsg.ptr, Afspec->Vnr, Vn);
   sf.pos=4003510;
   Vdone = 1;
    break;
  }
 case 18:
  {
   Tu32 Vn;
   sf.pos=4003511;
   Vn = YZHh(Vsreader);
   sf.pos=4003512;
   ((void (*)(void*, Ti, Tu32))(Amsg.table[32]))(Amsg.ptr, Afspec->Vnr, Vn);
   sf.pos=4003513;
   Vdone = 1;
    break;
  }
 case 6:
  {
   Tf32 Vf;
   sf.pos=4003514;
   Vf = YHTg(Vsreader);
   sf.pos=4003515;
   ((void (*)(void*, Ti, Tf32))(Amsg.table[33]))(Amsg.ptr, Afspec->Vnr, Vf);
   sf.pos=4003516;
   Vdone = 1;
    break;
  }
 case 7:
  {
   Tf Vf;
   sf.pos=4003517;
   Vf = YHTg(Vsreader);
   sf.pos=4003518;
   ((void (*)(void*, Ti, Tf))(Amsg.table[34]))(Amsg.ptr, Afspec->Vnr, Vf);
   sf.pos=4003519;
   Vdone = 1;
    break;
  }
 case 1:
  {
   Ti Vn;
   sf.pos=4003520;
   Vn = YZHh(Vsreader);
   sf.pos=4003521;
   ((void (*)(void*, Ti, Tb))(Amsg.table[35]))(Amsg.ptr, Afspec->Vnr, (((Vn == 0)) ? (0) : (1)));
   sf.pos=4003522;
   Vdone = 1;
    break;
  }
 case 17:
  {
   sf.pos=4003523;
   Vs = YB1v(Vsreader);
   sf.pos=4003524;
   ((void (*)(void*, Ti, Tc*))(Amsg.table[36]))(Amsg.ptr, Afspec->Vnr, Vs);
   sf.pos=4003525;
   Vdone = 1;
    break;
  }
 case 3:
  {
   Ti Vn;
   sf.pos=4003526;
   Vn = YZHh(Vsreader);
   sf.pos=4003527;
   ((void (*)(void*, Ti, Ti))(Amsg.table[27]))(Amsg.ptr, Afspec->Vnr, Vn);
   sf.pos=4003528;
   Vdone = 1;
    break;
  }
 case 12:
  {
   Ti Vc;
   sf.pos=4003529;
   Vc = YVZB(Vsreader);
   sf.pos=4003530;
   Y3er(Vsreader, Vc);
   sf.pos=4003531;
   if ((Vc != 91))
   {
    Ti Vkey;
    sf.pos=4003532;
    if (((Vc < 48) || (Vc > 57)))
    {
     Tr ex;
     sf.pos=4003533;
     if ((Vc == Y3QJ))
     {
      Tr ex;
      sf.pos=4003534;
      *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&Y3FC)), Yd7N__Ytlm_I_imt, 28);
      ZthrowIobject(ex);
     }
     sf.pos=4003535;
     *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ZcS(((Tc*)&YE6N), ZintAsString(Vc))), Yd7N__Ytlm_I_imt, 28);
     ZthrowIobject(ex);
    }
    sf.pos=4003536;
    Vkey = YZHh(Vsreader);
    sf.pos=4003537;
    VpReader = ((YBRp* (*)(void*))(AiReader.table[3]))(AiReader.ptr);
    sf.pos=4003538;
    if ((VpReader->Vrefs == NULL))
    {
     Tr ex;
     sf.pos=4003539;
     *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&Yo2d)), Yd7N__Ytlm_I_imt, 28);
     ZthrowIobject(ex);
    }
    sf.pos=4003540;
    Vm = YnlR(VpReader, Vkey);
    sf.pos=4003541;
    if ((((Vm).ptr) == NULL))
    {
     Tr ex;
     sf.pos=4003542;
     *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ZcS(((Tc*)&YmWB), Zint2string(Vkey))), Yd7N__Ytlm_I_imt, 28);
     ZthrowIobject(ex);
    }
    sf.pos=4003543;
    if (Afspec->Vrepeated)
    {
     sf.pos=4003544;
     Yzyn(Amsg, Afspec->Vnr, Vm);
    }
    else
    {
     sf.pos=4003545;
     YslI(Amsg, Afspec->Vnr, Vm);
    }
    sf.pos=4003546;
    Vdone = 1;
   }
   else
   {
    sf.pos=4003547;
    Vdone = YPR3(Amsg, Afspec->Vnr, 2, AiReader);
   }
    break;
  }
 default:
  {
   Tr ex;
   sf.pos=4003548;
   *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ZcS(((Tc*)&Y80t), Zenum2string(MProto__EType, Afspec->Vtype))), Yd7N__Ytlm_I_imt, 28);
   ZthrowIobject(ex);
  }
 }
 sf.pos=4003549;
 r = Vdone;
 e->topFrame = sf.prev;
 return r;
}
Zfo YigDfo[10] = {{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YqvM__T},{0,(Tt*)&iobj__T},{0,0}};
void YigD(Tr Amsg, YLWE *AjsonWriter) {
 Ti VlastProducedField;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf1 = NULL;
 Tc *VrepComma = NULL;
 Tr Vother = {NULL};
 Tr Vother1 = {NULL};
 Tr Vwriter = {NULL};
 YqvM *Vfspec = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YigDfo[0].off = (void*)&sf - (void*)&Amsg;
  YigDfo[1].off = (void*)&sf - (void*)&AjsonWriter;
  YigDfo[2].off = (void*)&sf - (void*)&Zf1;
  YigDfo[3].off = (void*)&sf - (void*)&VrepComma;
  YigDfo[4].off = (void*)&sf - (void*)&Vother;
  YigDfo[5].off = (void*)&sf - (void*)&Vother1;
  YigDfo[6].off = (void*)&sf - (void*)&Vwriter;
  YigDfo[7].off = (void*)&sf - (void*)&Vfspec;
  YigDfo[8].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YigDfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=2598800;
 VlastProducedField = 1;
 sf.pos=2598801;
 Vwriter = AjsonWriter->Vwriter;
 sf.pos=2598802;
 ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YCa));
 sf.pos=2598803;
 {
  Tfl Zf1i;
  Zf1 = ((Tl* (*)(void*))(Amsg.table[43]))(Amsg.ptr);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vfspec;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=2598804;
  if (Vfspec->Vrepeated)
  {
   Ti Vcount;
   sf.pos=2598805;
   Vcount = ((Ti (*)(void*, Ti))(Amsg.table[42]))(Amsg.ptr, Vfspec->Vnr);
   sf.pos=2598806;
   if ((Vcount > 0))
   {
    sf.pos=2598807;
    Yly_(Vfspec->Vnr, VlastProducedField, Vwriter);
    sf.pos=2598808;
    VlastProducedField = Vfspec->Vnr;
    sf.pos=2598809;
    ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YCa));
    sf.pos=2598810;
    VrepComma = ((Tc*)&Ya);
    sf.pos=2598811;
    {
     Ti Vi;
     Tfr Zf4;
     ZforRangeNew(0, Vcount, 1, 1, &Zf4);
     for (ZforRangeGetInt(&Zf4, &Vi); ZforRangeContInt(&Zf4); ZforRangeNextInt(&Zf4, &Vi)) {
     sf.pos=2598812;
     ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, VrepComma);
     sf.pos=2598813;
     VrepComma = ((Tc*)&YS);
     sf.pos=2598814;
     switch (Vfspec->Vtype)
     {
     case 9:
     case 11:
      {
       sf.pos=2598815;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(((Ti (*)(void*, Ti, Ti))(Amsg.table[11]))(Amsg.ptr, Vfspec->Vnr, Vi)), ((Tc*)&Ya)));
        break;
      }
     case 10:
      {
       sf.pos=2598816;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(((Ti32 (*)(void*, Ti, Ti))(Amsg.table[13]))(Amsg.ptr, Vfspec->Vnr, Vi)), ((Tc*)&Ya)));
        break;
      }
     case 19:
      {
       sf.pos=2598817;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Znat2string(((Tu (*)(void*, Ti, Ti))(Amsg.table[15]))(Amsg.ptr, Vfspec->Vnr, Vi)), ((Tc*)&Ya)));
        break;
      }
     case 18:
      {
       sf.pos=2598818;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Znat2string(((Tu32 (*)(void*, Ti, Ti))(Amsg.table[17]))(Amsg.ptr, Vfspec->Vnr, Vi)), ((Tc*)&Ya)));
        break;
      }
     case 6:
      {
       sf.pos=2598819;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZfloatFormat(((Tc*)&YxR2), ((Tf32 (*)(void*, Ti, Ti))(Amsg.table[19]))(Amsg.ptr, Vfspec->Vnr, Vi)));
        break;
      }
     case 7:
      {
       sf.pos=2598820;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZfloatFormat(((Tc*)&YmwI), ((Tf (*)(void*, Ti, Ti))(Amsg.table[21]))(Amsg.ptr, Vfspec->Vnr, Vi)));
        break;
      }
     case 1:
      {
       sf.pos=2598821;
       if (((Tb (*)(void*, Ti, Ti))(Amsg.table[23]))(Amsg.ptr, Vfspec->Vnr, Vi))
       {
        sf.pos=2598822;
        ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YX));
       }
       else
       {
        sf.pos=2598823;
        ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YW));
       }
        break;
      }
     case 17:
      {
       sf.pos=2598824;
       YwCv(((Tc* (*)(void*, Ti, Ti))(Amsg.table[25]))(Amsg.ptr, Vfspec->Vnr, Vi), Vwriter);
        break;
      }
     case 3:
      {
       sf.pos=2598825;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(((Ti (*)(void*, Ti, Ti))(Amsg.table[7]))(Amsg.ptr, Vfspec->Vnr, Vi)), ((Tc*)&Ya)));
        break;
      }
     case 12:
      {
       sf.pos=2598826;
       Vother = ((Tr (*)(void*, Ti, Ti))(Amsg.table[37]))(Amsg.ptr, Vfspec->Vnr, Vi);
       sf.pos=2598827;
       YL6X(Vother, Vfspec, AjsonWriter);
        break;
      }
     default:
      {
       Tr ex;
       sf.pos=2598828;
       *Znao(&ex, Ys_q__YwtA__YRHR(NULL, ZcS(((Tc*)&Y80t), Zenum2string(MProto__EType, Vfspec->Vtype))), Ys_q__Ytlm_I_imt, 29);
       ZthrowIobject(ex);
      }
     }
     sf.pos=2598829;
     }
    }
    sf.pos=2598830;
    ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YEa));
   }
  }
  else
  {
   sf.pos=2598831;
   if (((Tb (*)(void*, Ti))(Amsg.table[5]))(Amsg.ptr, Vfspec->Vnr))
   {
    sf.pos=2598832;
    Yly_(Vfspec->Vnr, VlastProducedField, Vwriter);
    sf.pos=2598833;
    VlastProducedField = Vfspec->Vnr;
    sf.pos=2598834;
    switch (Vfspec->Vtype)
    {
    case 9:
    case 11:
     {
      sf.pos=2598835;
      ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(((Ti (*)(void*, Ti))(Amsg.table[12]))(Amsg.ptr, Vfspec->Vnr)), ((Tc*)&Ya)));
       break;
     }
    case 10:
     {
      sf.pos=2598836;
      ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(((Ti32 (*)(void*, Ti))(Amsg.table[14]))(Amsg.ptr, Vfspec->Vnr)), ((Tc*)&Ya)));
       break;
     }
    case 19:
     {
      sf.pos=2598837;
      ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Znat2string(((Tu (*)(void*, Ti))(Amsg.table[16]))(Amsg.ptr, Vfspec->Vnr)), ((Tc*)&Ya)));
       break;
     }
    case 18:
     {
      sf.pos=2598838;
      ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Znat2string(((Tu32 (*)(void*, Ti))(Amsg.table[18]))(Amsg.ptr, Vfspec->Vnr)), ((Tc*)&Ya)));
       break;
     }
    case 6:
     {
      sf.pos=2598839;
      ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZfloatFormat(((Tc*)&YxR2), ((Tf32 (*)(void*, Ti))(Amsg.table[20]))(Amsg.ptr, Vfspec->Vnr)));
       break;
     }
    case 7:
     {
      sf.pos=2598840;
      ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZfloatFormat(((Tc*)&YmwI), ((Tf (*)(void*, Ti))(Amsg.table[22]))(Amsg.ptr, Vfspec->Vnr)));
       break;
     }
    case 1:
     {
      sf.pos=2598841;
      if (((Tb (*)(void*, Ti))(Amsg.table[24]))(Amsg.ptr, Vfspec->Vnr))
      {
       sf.pos=2598842;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YX));
      }
      else
      {
       sf.pos=2598843;
       ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YW));
      }
       break;
     }
    case 17:
     {
      sf.pos=2598844;
      YwCv(((Tc* (*)(void*, Ti))(Amsg.table[26]))(Amsg.ptr, Vfspec->Vnr), Vwriter);
       break;
     }
    case 3:
     {
      sf.pos=2598845;
      ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string(((Ti (*)(void*, Ti))(Amsg.table[8]))(Amsg.ptr, Vfspec->Vnr)), ((Tc*)&Ya)));
       break;
     }
    case 12:
     {
      sf.pos=2598846;
      Vother1 = ((Tr (*)(void*, Ti))(Amsg.table[38]))(Amsg.ptr, Vfspec->Vnr);
      sf.pos=2598847;
      YL6X(Vother1, Vfspec, AjsonWriter);
       break;
     }
    default:
     {
      Tr ex;
      sf.pos=2598848;
      *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ZcS(((Tc*)&Y80t), Zenum2string(MProto__EType, Vfspec->Vtype))), Yd7N__Ytlm_I_imt, 28);
      ZthrowIobject(ex);
     }
    }
   }
  }
  sf.pos=2598849;
  }
 }
 sf.pos=2598850;
 ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&YEa));
 e->topFrame = sf.prev;
 return;
}
Zfo Yly_fo[2] = {{0,(Tt*)&iobj__T},{0,0}};
void Yly_(Ti Anr, Ti AlastProducedField, Tr Awriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yly_fo[0].off = (void*)&sf - (void*)&Awriter;
 }
 sf.frof = Yly_fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5134900;
 if ((Anr > 50))
 {
  sf.pos=5134901;
  if ((AlastProducedField > 1))
  {
   sf.pos=5134902;
   ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&YS));
  }
  sf.pos=5134903;
  ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, Zint2string(Anr));
  sf.pos=5134904;
  ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&YS));
 }
 else
 {
  sf.pos=5134905;
  {
   Ti Vi;
   Tfr Zf2;
   ZforRangeNew(AlastProducedField, Anr, 1, 1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vi); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vi)) {
   sf.pos=5134906;
   ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&YS));
   sf.pos=5134907;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YL6Xfo[5] = {{0,(Tt*)&YqvM__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&iobj__T},{0,0}};
void YL6X(Tr Amsg, YqvM *Afspec, YLWE *AprotoWriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr Vwriter = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YL6Xfo[0].off = (void*)&sf - (void*)&Afspec;
  YL6Xfo[1].off = (void*)&sf - (void*)&Amsg;
  YL6Xfo[2].off = (void*)&sf - (void*)&AprotoWriter;
  YL6Xfo[3].off = (void*)&sf - (void*)&Vwriter;
 }
 sf.frof = YL6Xfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7160100;
 if ((((Amsg).ptr) != NULL))
 {
  Tb Vdone;
  Vdone = 0;
  sf.pos=7160101;
  if ((AprotoWriter->VderefTime != 0))
  {
   sf.pos=7160102;
   if (((*(Ti*)(Amsg.ptr + (size_t)Amsg.table[1])) == AprotoWriter->VderefTime))
   {
    sf.pos=7160103;
    Vwriter = AprotoWriter->Vwriter;
    sf.pos=7160104;
    ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ZcS(Zint2string((*(Ti*)(Amsg.ptr + (size_t)Amsg.table[2]))), ((Tc*)&Ya)));
    sf.pos=7160105;
    Vdone = 1;
   }
   else
   {
    sf.pos=7160106;
    (*(Ti*)(Amsg.ptr + (size_t)Amsg.table[1])) = AprotoWriter->VderefTime;
    sf.pos=7160107;
    (*(Ti*)(Amsg.ptr + (size_t)Amsg.table[2])) = ++(AprotoWriter->VderefId);
   }
  }
  sf.pos=7160108;
  if (!(Vdone))
  {
   sf.pos=7160109;
   YigD(Amsg, AprotoWriter);
  }
 }
 e->topFrame = sf.prev;
 return;
}
Ti YmeT(Ti Avalue) {
 Ti Vbytes;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YZHhfo[2] = {{0,(Tt*)&YrC3__T},{0,0}};
Ti YZHh(YrC3 *Areader) {
 Ti Vv;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YZHhfo[0].off = (void*)&sf - (void*)&Areader;
 }
 sf.frof = YZHhfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vv = 0;
 sf.pos=5973000;
 while (1)
 {
  Ti Vc;
  sf.pos=5973001;
  Vc = YVZB(Areader);
  sf.pos=5973002;
  if ((((Vc == Y3QJ) || (Vc < 48)) || (Vc > 57)))
  {
   sf.pos=5973003;
   Y3er(Areader, Vc);
   rt = 2;
   goto Y6h2;
  }
  sf.pos=5973004;
  Vv = ((Vv * 10) + ((Vc - 48)));
Y6h2:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=5973005;
 }
 sf.pos=5973006;
 r = Vv;
 e->topFrame = sf.prev;
 return r;
}
Zfo YHTgfo[3] = {{0,(Tt*)&YrC3__T},{0,(Tt*)&YjUM__T},{0,0}};
Tf YHTg(YrC3 *Areader) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YHTgfo[0].off = (void*)&sf - (void*)&Areader;
  YHTgfo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YHTgfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3261600;
 Vw = Za(sizeof(YjUM));
 sf.pos=3261601;
 while (1)
 {
  Ti Vc;
  sf.pos=3261602;
  Vc = YVZB(Areader);
  sf.pos=3261603;
  if (!((((((((((Vc >= 48) && (Vc <= 57))) || (Vc == 46)) || (Vc == 101)) || (Vc == 69)) || (Vc == 43)) || (Vc == 45)))))
  {
   sf.pos=3261604;
   Y3er(Areader, Vc);
   rt = 2;
   goto YNZ_;
  }
  sf.pos=3261605;
  YjUM__YHhZb(Vw, Vc);
YNZ_:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=3261606;
 }
 sf.pos=3261607;
 r = Zstring2float(YbNW(Vw), 0);
 e->topFrame = sf.prev;
 return r;
}
Zfo YB1vfo[4] = {{0,(Tt*)&YrC3__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YB1v(YrC3 *Areader) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vwriter = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YB1vfo[0].off = (void*)&sf - (void*)&Areader;
  YB1vfo[1].off = (void*)&sf - (void*)&Vwriter;
  YB1vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YB1vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4844400;
 if ((YVZB(Areader) != 34))
 {
  sf.pos=4844401;
  r = ((Tc*)&Ya);
  rt = 1;
  goto YQtb;
 }
 sf.pos=4844402;
 Vwriter = Za(sizeof(YjUM));
 sf.pos=4844403;
 while (1)
 {
  Ti Vc;
  sf.pos=4844404;
  Vc = YVZB(Areader);
  sf.pos=4844405;
  if ((Vc == Y3QJ))
  {
   Tr ex;
   sf.pos=4844406;
   *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&Yfvl)), Yd7N__Ytlm_I_imt, 28);
   ZthrowIobject(ex);
  }
  sf.pos=4844407;
  if ((Vc == 34))
  {
   rt = 2;
   goto YCJp;
  }
  sf.pos=4844408;
  if ((Vc == 92))
  {
   sf.pos=4844409;
   Vc = YVZB(Areader);
   sf.pos=4844410;
   switch (Vc)
   {
   case 98:
    {
     sf.pos=4844411;
     YjUM__Ydti(Vwriter, 8);
      break;
    }
   case 102:
    {
     sf.pos=4844412;
     YjUM__Ydti(Vwriter, 14);
      break;
    }
   case 110:
    {
     sf.pos=4844413;
     YjUM__Ydti(Vwriter, 10);
      break;
    }
   case 114:
    {
     sf.pos=4844414;
     YjUM__Ydti(Vwriter, 13);
      break;
    }
   case 116:
    {
     sf.pos=4844415;
     YjUM__Ydti(Vwriter, 9);
      break;
    }
   case 117:
    {
     Ti Vv;
     sf.pos=4844416;
     Vv = ZstringHexToInt(ZintAsString(YVZB(Areader)), 1, 0);
     sf.pos=4844417;
     Vv = ((Vv * 16) + ZstringHexToInt(ZintAsString(YVZB(Areader)), 1, 0));
     sf.pos=4844418;
     Vv = ((Vv * 16) + ZstringHexToInt(ZintAsString(YVZB(Areader)), 1, 0));
     sf.pos=4844419;
     Vv = ((Vv * 16) + ZstringHexToInt(ZintAsString(YVZB(Areader)), 1, 0));
     sf.pos=4844420;
     YjUM__Ydti(Vwriter, Vv);
      break;
    }
   default:
    {
     sf.pos=4844421;
     YjUM__Ydti(Vwriter, Vc);
      break;
    }
   }
  }
  else
  {
   sf.pos=4844422;
   YjUM__Ydti(Vwriter, Vc);
  }
YCJp:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=4844423;
 }
 sf.pos=4844424;
 r = YbNW(Vwriter);
YQtb:
 e->topFrame = sf.prev;
 return r;
}
Zfo YzK3fo[3] = {{0,(Tt*)&YrC3__T},{0,(Tt*)&iobj__T},{0,0}};
void YzK3(YrC3 *Areader) {
 Ti Vc;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YzK3fo[0].off = (void*)&sf - (void*)&Areader;
  YzK3fo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzK3fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8740400;
 Vc = YVZB(Areader);
 sf.pos=8740401;
 if ((Vc == 34))
 {
  sf.pos=8740402;
  Y3er(Areader, Vc);
  sf.pos=8740403;
  YB1v(Areader);
 }
 else {
 sf.pos=8740404;
 if (((Vc >= 48) && (Vc <= 57)))
 {
  sf.pos=8740405;
  YZHh(Areader);
 }
 else {
 sf.pos=8740406;
 if ((Vc == 91))
 {
  sf.pos=8740407;
  while (1)
  {
   sf.pos=8740408;
   YzK3(Areader);
   sf.pos=8740409;
   Vc = YVZB(Areader);
   sf.pos=8740410;
   if (((Vc == 93) || (Vc == Y3QJ)))
   {
    rt = 2;
    goto Yi_y;
   }
   sf.pos=8740411;
   if ((Vc != 44))
   {
    Tr ex;
    sf.pos=8740412;
    *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&Yuq6)), Yd7N__Ytlm_I_imt, 28);
    ZthrowIobject(ex);
   }
Yi_y:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=8740413;
  }
 }
 else {
 sf.pos=8740414;
 if ((Vc == 91))
 {
  Tr ex;
  sf.pos=8740415;
  *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&Y_9Q)), Yd7N__Ytlm_I_imt, 28);
  ZthrowIobject(ex);
 }
 else
 {
  Tr ex;
  sf.pos=8740416;
  *Znao(&ex, Yd7N__YwtA__YRHR(NULL, ((Tc*)&YRr3)), Yd7N__Ytlm_I_imt, 28);
  ZthrowIobject(ex);
 }
 }}}
 e->topFrame = sf.prev;
 return;
}
Zfo YwCvfo[4] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
void YwCv(Tc *As, Tr Awriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *Zf1 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwCvfo[0].off = (void*)&sf - (void*)&As;
  YwCvfo[1].off = (void*)&sf - (void*)&Zf1;
  YwCvfo[2].off = (void*)&sf - (void*)&Awriter;
 }
 sf.frof = YwCvfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=2287900;
 ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&YI));
 sf.pos=2287901;
 {
  Ti Vc;
  Tfs iZf1;
  Zf1 = As;
  ZforStringNew(Zf1, &iZf1);
  for (ZforStringGetInt(&iZf1, &Vc); ZforStringContInt(&iZf1); ZforStringNextInt(&iZf1, &Vc)) {
  sf.pos=2287902;
  switch (Vc)
  {
  case 34:
   {
    sf.pos=2287903;
    ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&Ycvb));
     break;
   }
  case 92:
   {
    sf.pos=2287904;
    ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&Y7vb));
     break;
   }
  case 8:
   {
    sf.pos=2287905;
    ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&Ydwb));
     break;
   }
  case 14:
   {
    sf.pos=2287906;
    ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&Yhwb));
     break;
   }
  case 10:
   {
    sf.pos=2287907;
    ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&Ypwb));
     break;
   }
  case 13:
   {
    sf.pos=2287908;
    ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&Ytwb));
     break;
   }
  case 9:
   {
    sf.pos=2287909;
    ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&Yvwb));
     break;
   }
  default:
   {
    sf.pos=2287910;
    if (((Vc < 32) || (Vc > 127)))
    {
     sf.pos=2287911;
     ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&Ywwb));
     sf.pos=2287912;
     ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, YIUba(Vc, 4));
    }
    else
    {
     sf.pos=2287913;
     ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ZintAsString(Vc));
    }
     break;
   }
  }
  sf.pos=2287914;
  }
 }
 sf.pos=2287915;
 ((Ts (*)(void*, Tc*))(Awriter.table[1]))(Awriter.ptr, ((Tc*)&YI));
 e->topFrame = sf.prev;
 return;
}
Zfo YlyHfo[5] = {{0,(Tt*)&YKxQ__T},{0,(Tt*)&cb__T},{0,(Tt*)&string__T},{0,(Tt*)&cb__T},{0,0}};
YKxQ *YlyH(YKxQ *t, Tc *Aname, Tcb *AcreateFromJson, Tcb *AcreateResponse) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YlyHfo[0].off = (void*)&sf - (void*)&t;
  YlyHfo[1].off = (void*)&sf - (void*)&AcreateFromJson;
  YlyHfo[2].off = (void*)&sf - (void*)&Aname;
  YlyHfo[3].off = (void*)&sf - (void*)&AcreateResponse;
 }
 sf.frof = YlyHfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3122800; t = Za(sizeof(YKxQ));}
 sf.pos=3122801;
 t->Vname = Aname;
 sf.pos=3122802;
 t->VcreateFromJson = AcreateFromJson;
 sf.pos=3122803;
 t->VcreateResponse = AcreateResponse;
 e->topFrame = sf.prev;
 return t;
}
To ToYKxQ[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&cb__T}, /* createFromJson */
 {0, (Tt*)&cb__T}, /* createResponse */
};
char *StrYKxQ[] = {
 "name",
 "createFromJson",
 "createResponse",
};
Tto YKxQ__T = {390, (Tc*)&Y2cL, 0, StrYKxQ, 0, 0, 0, 0, ToYKxQ};
void Yzyn(Tr A0, Ti A1, Tr A2) {
 if (A0.ptr == NULL) ZthrowCstringNil("messageAdd: object is NIL, cannot select method to invoke");
 switch (A0.type) {
  case 0:
   return;
  case 1:
   YwcI__Y0Dj(A0.ptr,A1,A2); return;
  case 2:
   YWgO__Y0Dj(A0.ptr,A1,A2); return;
 }
 ZthrowCstringBadValue("messageAdd: cannot select method to invoke");
 return;
}
void YslI(Tr A0, Ti A1, Tr A2) {
 if (A0.ptr == NULL) ZthrowCstringNil("messageSet: object is NIL, cannot select method to invoke");
 switch (A0.type) {
  case 0:
   return;
  case 1:
   YwcI__YrW2(A0.ptr,A1,A2); return;
  case 2:
   YWgO__YrW2(A0.ptr,A1,A2); return;
 }
 ZthrowCstringBadValue("messageSet: cannot select method to invoke");
 return;
}
Tb YPR3(Tr A0, Ti A1, Te A2, Tr A3) {
 if (A0.ptr == NULL) ZthrowCstringNil("mergeMessageFromReader: object is NIL, cannot select method to invoke");
 switch (A0.type) {
  case 0:
   return 0;
  case 1:
   return YwcI__Ymza(A0.ptr,A1,A2,A3);
  case 2:
   return YWgO__Ymza(A0.ptr,A1,A2,A3);
 }
 ZthrowCstringBadValue("mergeMessageFromReader: cannot select method to invoke");
 return 0;
}
int JProto(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 if (round == 2001) {
   sf.pos=3053200;
   YXCQ = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MProto__EType__T, (Tt*)&MProto__EBinaryType__T, 0), (Tz)(Ti)1, (Tz)(Ti)0), (Tz)(Ti)9, (Tz)(Ti)0), (Tz)(Ti)11, (Tz)(Ti)0), (Tz)(Ti)10, (Tz)(Ti)0), (Tz)(Ti)19, (Tz)(Ti)0), (Tz)(Ti)18, (Tz)(Ti)0), (Tz)(Ti)17, (Tz)(Ti)2), (Tz)(Ti)3, (Tz)(Ti)0), (Tz)(Ti)12, (Tz)(Ti)2), (Tz)(Ti)6, (Tz)(Ti)5), (Tz)(Ti)7, (Tz)(Ti)1);
   sf.pos=3053201;
   YLwW = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MProto__EBinaryType__T, (Tt*)&int__T, 0), (Tz)(Ti)0, (Tz)(Ti)0), (Tz)(Ti)1, (Tz)(Ti)1), (Tz)(Ti)2, (Tz)(Ti)2), (Tz)(Ti)3, (Tz)(Ti)3), (Tz)(Ti)4, (Tz)(Ti)4), (Tz)(Ti)5, (Tz)(Ti)5);
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* Proto done */
Zfo YF0Nfo[2] = {{0,(Tt*)&YSM1__T},{0,0}};
YSM1 *YF0N(YSM1 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YF0Nfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YF0Nfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=4664000; t = Za(sizeof(YSM1));}
 sf.pos=4664001;
 t->VheaderItems = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
 e->topFrame = sf.prev;
 return t;
}
Zfo Yi2Xfo[4] = {{0,(Tt*)&YSM1__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Td *Yi2X(YSM1 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Td *r = 0;
 Tc *Vname = NULL;
 Tc *Vvalue = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yi2Xfo[0].off = (void*)&sf - (void*)&t;
  Yi2Xfo[1].off = (void*)&sf - (void*)&Vname;
  Yi2Xfo[2].off = (void*)&sf - (void*)&Vvalue;
 }
 sf.frof = Yi2Xfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3090700;
  ZthrowThisNil();
 }
 sf.pos=3090701;
 if ((t->VparamItems == NULL))
 {
  sf.pos=3090702;
  t->VparamItems = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
  sf.pos=3090703;
  if ((t->Vparams != NULL))
  {
   Ti Vstart;
   Vstart = 0;
   sf.pos=3090704;
   while (1)
   {
    Ti Vend;
    Ti Veq;
    sf.pos=3090705;
    Vend = ZstringFindChar2(t->Vparams, 38, Vstart, 0);
    sf.pos=3090706;
    Veq = ZstringFindChar2(t->Vparams, 61, Vstart, 0);
    Vname = NULL;
    Vvalue = NULL;
    sf.pos=3090707;
    if (((Veq > 0) && (((Vend < 0) || (Veq < Vend)))))
    {
     sf.pos=3090708;
     Vname = ZstringSlice(t->Vparams, Vstart, (Veq - 1), 0);
     sf.pos=3090709;
     Vvalue = ZstringSlice(t->Vparams, (Veq + 1), Vend, 0);
    }
    else
    {
     sf.pos=3090710;
     Vname = ZstringSlice(t->Vparams, Vstart, Vend, 0);
     sf.pos=3090711;
     Vvalue = ((Tc*)&Ya);
    }
    sf.pos=3090712;
    *((Tc **)ZDictGetPtrP(t->VparamItems, (Tz)(void*)Vname)) = Vvalue;
    sf.pos=3090713;
    if ((Vend < 0))
    {
     rt = 2;
     goto YMoA;
    }
    sf.pos=3090714;
    Vstart = (Vend + 1);
YMoA:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=3090715;
   }
  }
 }
 sf.pos=3090716;
 r = t->VparamItems;
 e->topFrame = sf.prev;
 return r;
}
Zfo YuPPfo[6] = {{0,(Tt*)&YSM1__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Tc *YuPP(YSM1 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tl *Zf1 = NULL;
 Tc *Vi = NULL;
 YjUM *Vw = 0;
 Tc *t0 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuPPfo[0].off = (void*)&sf - (void*)&t;
  YuPPfo[1].off = (void*)&sf - (void*)&Zf1;
  YuPPfo[2].off = (void*)&sf - (void*)&Vi;
  YuPPfo[3].off = (void*)&sf - (void*)&Vw;
  YuPPfo[4].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YuPPfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8466800;
  ZthrowThisNil();
 }
 sf.pos=8466801;
 Vw = Za(sizeof(YjUM));
 sf.pos=8466802;
 YjUM__YRt7(Vw, ZcS(((Tc*)&Y5wx), Zenum2string(MHTTPModule__ERequestType, t->Vtype)));
 sf.pos=8466803;
 YjUM__YRt7(Vw, ZcS(((Tc*)&YXBd), t->Vpath));
 sf.pos=8466804;
 YjUM__YRt7(Vw, ZcS(((Tc*)&YrAc), t->Vparams));
 sf.pos=8466805;
 YjUM__YRt7(Vw, ZcS(((Tc*)&Y1xf), t->VhttpVersion));
 sf.pos=8466806;
 YjUM__YRt7(Vw, ((Tc*)&YiH8));
 sf.pos=8466807;
 {
  Tfl Zf1i;
  Zf1 = ZDictKeys(t->VheaderItems, 0);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vi;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8466808;
  YjUM__YRt7(Vw, ZcS3(Vi, ((Tc*)&YFDa), (t0 = ((Tc *)ZDictGetPtr(t->VheaderItems, (Tz)(void*)Vi)))));
  sf.pos=8466809;
  }
 }
 sf.pos=8466810;
 if ((t->Vbody != NULL))
 {
  sf.pos=8466811;
  YjUM__YRt7(Vw, ZcS(((Tc*)&YLih), ZbyteStringCheckUtf8(t->Vbody)));
 }
 sf.pos=8466812;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
To ToYSM1[] = {
 {7, 0},
 {0, (Tt*)&MHTTPModule__ERequestType__T}, /* type */
 {0, (Tt*)&string__T}, /* path */
 {0, (Tt*)&string__T}, /* params */
 {0, (Tt*)&string__T}, /* httpVersion */
 {0, (Tt*)&dict__T}, /* headerItems */
 {0, (Tt*)&byteString__T}, /* body */
 {0, (Tt*)&dict__T}, /* paramItems */
};
char *StrYSM1[] = {
 "type",
 "path",
 "params",
 "httpVersion",
 "headerItems",
 "body",
 "paramItems",
};
Tto YSM1__T = {390, (Tc*)&YFUt, YuPP, StrYSM1, 0, 0, 0, 0, ToYSM1};
Zfo YikNfo[2] = {{0,(Tt*)&YKeB__T},{0,0}};
YKeB *YikN(YKeB *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YikNfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YikNfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3482200; t = Za(sizeof(YKeB));}
 sf.pos=3482201;
 t->Vcode = 200;
 sf.pos=3482202;
 t->Vmsg = ((Tc*)&Y0ab);
 sf.pos=3482203;
 t->VheaderItems = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
 sf.pos=3482204;
 YDSB(t, ((Tc*)&Ylqg));
 sf.pos=3482205;
 t->Vbody = ((Tc*)&YBMI);
 e->topFrame = sf.prev;
 return t;
}
Zfo YjIQfo[2] = {{0,(Tt*)&YKeB__T},{0,0}};
void YjIQ(YKeB *t, Ti Alength) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjIQfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjIQfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1487400;
  ZthrowThisNil();
 }
 sf.pos=1487401;
 *((Tc **)ZDictGetPtrP(t->VheaderItems, (Tz)(void*)((Tc*)&Y95C))) = ZcS(Zint2string(Alength), ((Tc*)&Ya));
 e->topFrame = sf.prev;
 return;
}
Zfo YDSBfo[3] = {{0,(Tt*)&YKeB__T},{0,(Tt*)&string__T},{0,0}};
void YDSB(YKeB *t, Tc *Atype) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDSBfo[0].off = (void*)&sf - (void*)&t;
  YDSBfo[1].off = (void*)&sf - (void*)&Atype;
 }
 sf.frof = YDSBfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8450600;
  ZthrowThisNil();
 }
 sf.pos=8450601;
 *((Tc **)ZDictGetPtrP(t->VheaderItems, (Tz)(void*)((Tc*)&YPoL))) = Atype;
 e->topFrame = sf.prev;
 return;
}
To ToYKeB[] = {
 {4, 0},
 {0, (Tt*)&int__T}, /* code */
 {0, (Tt*)&string__T}, /* msg */
 {0, (Tt*)&dict__T}, /* headerItems */
 {0, (Tt*)&string__T}, /* body */
};
char *StrYKeB[] = {
 "code",
 "msg",
 "headerItems",
 "body",
};
Tto YKeB__T = {390, (Tc*)&YhQB, 0, StrYKeB, 0, 0, 0, 0, ToYKeB};
Zfo Y89Zfo[5] = {{0,(Tt*)&YtzZ__T},{0,(Tt*)&YKeB__T},{0,(Tt*)&YSM1__T},{0,(Tt*)&Y1QG__T},{0,0}};
YtzZ *Y89Z(YtzZ *t, Y1QG *Aserver, YSM1 *Arequest, YKeB *Aresponse) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y89Zfo[0].off = (void*)&sf - (void*)&t;
  Y89Zfo[1].off = (void*)&sf - (void*)&Aresponse;
  Y89Zfo[2].off = (void*)&sf - (void*)&Arequest;
  Y89Zfo[3].off = (void*)&sf - (void*)&Aserver;
 }
 sf.frof = Y89Zfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9162000; t = Za(sizeof(YtzZ));}
 sf.pos=9162001;
 t->Vserver = Aserver;
 sf.pos=9162002;
 t->Vrequest = Arequest;
 sf.pos=9162003;
 t->Vresponse = Aresponse;
 e->topFrame = sf.prev;
 return t;
}
To ToYtzZ[] = {
 {3, 0},
 {0, (Tt*)&Y1QG__T}, /* server */
 {0, (Tt*)&YSM1__T}, /* request */
 {0, (Tt*)&YKeB__T}, /* response */
};
char *StrYtzZ[] = {
 "server",
 "request",
 "response",
};
Tto YtzZ__T = {390, (Tc*)&Y36w, 0, StrYtzZ, 0, 0, 0, 0, ToYtzZ};
Zfo Ytlkfo[3] = {{0,(Tt*)&YphE__T},{0,(Tt*)&string__T},{0,0}};
YphE *Ytlk(YphE *t, Tc *Ato) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ytlkfo[0].off = (void*)&sf - (void*)&t;
  Ytlkfo[1].off = (void*)&sf - (void*)&Ato;
 }
 sf.frof = Ytlkfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7346200; t = Za(sizeof(YphE));}
 sf.pos=7346201;
 t->Vname = ((Tc*)&YRBq);
 sf.pos=7346202;
 t->VtoURL = Ato;
 sf.pos=7346203;
 t->Vcode = 301;
 e->topFrame = sf.prev;
 return t;
}
Zfo YSxaafo[4] = {{0,(Tt*)&YphE__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&string__T},{0,0}};
Tb YSxaa(YphE *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tc *t0 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSxaafo[0].off = (void*)&sf - (void*)&t;
  YSxaafo[1].off = (void*)&sf - (void*)&Acontext;
  YSxaafo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YSxaafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5298900;
  ZthrowThisNil();
 }
 sf.pos=5298901;
 Acontext->Vresponse->Vbody = ZcS8(((Tc*)&Yme1), ((Tc*)&Y8Uo), Acontext->Vserver->Vbase, t->VtoURL, ((Tc*)&YG9), (t0 = Acontext->Vserver->Vbase), t->VtoURL, ((Tc*)&YFDK));
 sf.pos=5298902;
 Acontext->Vresponse->Vcode = t->Vcode;
 sf.pos=5298903;
 Acontext->Vresponse->Vmsg = ((Tc*)&YKIR);
 sf.pos=5298904;
 *((Tc **)ZDictGetPtrP(Acontext->Vresponse->VheaderItems, (Tz)(void*)((Tc*)&YEsW))) = t->VtoURL;
 sf.pos=5298905;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo YphE__Y3fnfo[3] = {{0,(Tt*)&YphE__T},{0,(Tt*)&string__T},{0,0}};
void YphE__Y3fn(YphE *t, Tc *Apath) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YphE__Y3fnfo[0].off = (void*)&sf - (void*)&t;
  YphE__Y3fnfo[1].off = (void*)&sf - (void*)&Apath;
 }
 sf.frof = YphE__Y3fnfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=817300;
  ZthrowThisNil();
 }
 sf.pos=817301;
 if ((t->Vpaths == NULL))
 {
  sf.pos=817302;
  t->Vpaths = ZnewList((Tt*)&string__T, 0);
 }
 sf.pos=817303;
 ZLap((Tl*)t->Vpaths, (Tz)(void*)Apath);
 e->topFrame = sf.prev;
 return;
}
Zfo YphE__YU_Wfo[5] = {{0,(Tt*)&YphE__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tb YphE__YU_W(YphE *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tl *Zf2 = NULL;
 Tc *Vp = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YphE__YU_Wfo[0].off = (void*)&sf - (void*)&t;
  YphE__YU_Wfo[1].off = (void*)&sf - (void*)&Acontext;
  YphE__YU_Wfo[2].off = (void*)&sf - (void*)&Zf2;
  YphE__YU_Wfo[3].off = (void*)&sf - (void*)&Vp;
 }
 sf.frof = YphE__YU_Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3318300;
  ZthrowThisNil();
 }
 sf.pos=3318301;
 if ((t->Vpaths != NULL))
 {
  sf.pos=3318302;
  {
   Tfl Zf2i;
   Zf2 = t->Vpaths;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3318303;
   if ((ZstringCmp(Vp, Acontext->Vrequest->Vpath) == 0))
   {
    sf.pos=3318304;
    if ((t->VmimeType != NULL))
    {
     sf.pos=3318305;
     YDSB(Acontext->Vresponse, t->VmimeType);
    }
    sf.pos=3318306;
    if (YSxaa(t, Acontext))
    {
     sf.pos=3318307;
     r = 1;
     rt = 1;
     goto YbmA;
    }
YbmA:
    if (rt) goto YNgR;
   }
YNgR:
   if (rt) goto YSGl;
   sf.pos=3318308;
   }
  }
YSGl:
  if (rt) goto YrIx;
 }
 sf.pos=3318309;
 r = 0;
YrIx:
 e->topFrame = sf.prev;
 return r;
}
Tc *YphE__YtrZ_I_imt[] = {
 (Tc*)&YphE__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YphE__Y3fn, /* MHTTPModule__CRedirectServlet.addPath - YphE__Y3fn */
 (Tc*)YphE__YU_W, /* MHTTPModule__CRedirectServlet.handle - YphE__YU_W */
 (Tc*)0, /* MHTTPModule__CRedirectServlet.setMimeType - YphE__YuzN */
 (Tc*)YSxaa, /* MHTTPModule__CRedirectServlet.serve - YSxaa */
 (Tc*)0, /* Init - YphEa */
};
To ToYphE[] = {
 {5, 0},
 {0, (Tt*)&string__T}, /* toURL */
 {0, (Tt*)&int__T}, /* code */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* paths */
 {0, (Tt*)&string__T}, /* mimeType */
};
char *StrYphE[] = {
 "toURL",
 "code",
 "name",
 "paths",
 "mimeType",
};
Tto YphE__T = {390, (Tc*)&YRBq, 0, StrYphE, 0, 0, 0, 0, ToYphE};
Zfo Yb5Kfo[3] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&string__T},{0,0}};
YX8j *Yb5K(YX8j *t, Tc *AfileName) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yb5Kfo[0].off = (void*)&sf - (void*)&t;
  Yb5Kfo[1].off = (void*)&sf - (void*)&AfileName;
 }
 sf.frof = Yb5Kfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9433600; t = Za(sizeof(YX8j));}
 sf.pos=9433601;
 t->Vname = ((Tc*)&YAkv);
 sf.pos=9433602;
 t->VfileName = AfileName;
 e->topFrame = sf.prev;
 return t;
}
Zfo Y3hmafo[3] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&YtzZ__T},{0,0}};
Tb Y3hma(YX8j *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y3hmafo[0].off = (void*)&sf - (void*)&t;
  Y3hmafo[1].off = (void*)&sf - (void*)&Acontext;
 }
 sf.frof = Y3hmafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5386300;
  ZthrowThisNil();
 }
 sf.pos=5386301;
 Yl0k(ZcS5(((Tc*)&Y95j), Acontext->Vserver->VfileRoot, ((Tc*)&YV), t->VfileName, (Tc*)1));
 sf.pos=5386302;
 Acontext->Vresponse->Vbody = YDJh(ZcS3(Acontext->Vserver->VfileRoot, ((Tc*)&YV), t->VfileName));
 sf.pos=5386303;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo YX8j__Y3fnfo[3] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&string__T},{0,0}};
void YX8j__Y3fn(YX8j *t, Tc *Apath) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX8j__Y3fnfo[0].off = (void*)&sf - (void*)&t;
  YX8j__Y3fnfo[1].off = (void*)&sf - (void*)&Apath;
 }
 sf.frof = YX8j__Y3fnfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5306300;
  ZthrowThisNil();
 }
 sf.pos=5306301;
 if ((t->Vpaths == NULL))
 {
  sf.pos=5306302;
  t->Vpaths = ZnewList((Tt*)&string__T, 0);
 }
 sf.pos=5306303;
 ZLap((Tl*)t->Vpaths, (Tz)(void*)Apath);
 e->topFrame = sf.prev;
 return;
}
Zfo YX8j__YU_Wfo[5] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tb YX8j__YU_W(YX8j *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tl *Zf2 = NULL;
 Tc *Vp = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YX8j__YU_Wfo[0].off = (void*)&sf - (void*)&t;
  YX8j__YU_Wfo[1].off = (void*)&sf - (void*)&Acontext;
  YX8j__YU_Wfo[2].off = (void*)&sf - (void*)&Zf2;
  YX8j__YU_Wfo[3].off = (void*)&sf - (void*)&Vp;
 }
 sf.frof = YX8j__YU_Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3854500;
  ZthrowThisNil();
 }
 sf.pos=3854501;
 if ((t->Vpaths != NULL))
 {
  sf.pos=3854502;
  {
   Tfl Zf2i;
   Zf2 = t->Vpaths;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3854503;
   if ((ZstringCmp(Vp, Acontext->Vrequest->Vpath) == 0))
   {
    sf.pos=3854504;
    if ((t->VmimeType != NULL))
    {
     sf.pos=3854505;
     YDSB(Acontext->Vresponse, t->VmimeType);
    }
    sf.pos=3854506;
    if (Y3hma(t, Acontext))
    {
     sf.pos=3854507;
     r = 1;
     rt = 1;
     goto YzW5;
    }
YzW5:
    if (rt) goto YCxc;
   }
YCxc:
   if (rt) goto YIo4;
   sf.pos=3854508;
   }
  }
YIo4:
  if (rt) goto YENa;
 }
 sf.pos=3854509;
 r = 0;
YENa:
 e->topFrame = sf.prev;
 return r;
}
Tc *YX8j__YtrZ_I_imt[] = {
 (Tc*)&YX8j__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YX8j__Y3fn, /* MHTTPModule__CFileServlet.addPath - YX8j__Y3fn */
 (Tc*)YX8j__YU_W, /* MHTTPModule__CFileServlet.handle - YX8j__YU_W */
 (Tc*)0, /* MHTTPModule__CFileServlet.setMimeType - YX8j__YuzN */
 (Tc*)Y3hma, /* MHTTPModule__CFileServlet.serve - Y3hma */
 (Tc*)0, /* Init - YX8ja */
};
To ToYX8j[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* fileName */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* paths */
 {0, (Tt*)&string__T}, /* mimeType */
};
char *StrYX8j[] = {
 "fileName",
 "name",
 "paths",
 "mimeType",
};
Tto YX8j__T = {390, (Tc*)&YAkv, 0, StrYX8j, 0, 0, 0, 0, ToYX8j};
Zfo Y543fo[3] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&string__T},{0,0}};
YIgO *Y543(YIgO *t, Tc *Abody) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y543fo[0].off = (void*)&sf - (void*)&t;
  Y543fo[1].off = (void*)&sf - (void*)&Abody;
 }
 sf.frof = Y543fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7215100; t = Za(sizeof(YIgO));}
 sf.pos=7215101;
 t->Vname = ((Tc*)&Y2iZ);
 sf.pos=7215102;
 t->Vbody = Abody;
 e->topFrame = sf.prev;
 return t;
}
Zfo YqXRafo[3] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&YtzZ__T},{0,0}};
Tb YqXRa(YIgO *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqXRafo[0].off = (void*)&sf - (void*)&t;
  YqXRafo[1].off = (void*)&sf - (void*)&Acontext;
 }
 sf.frof = YqXRafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7684600;
  ZthrowThisNil();
 }
 sf.pos=7684601;
 Acontext->Vresponse->Vbody = t->Vbody;
 sf.pos=7684602;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo YIgO__Y3fnfo[3] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&string__T},{0,0}};
void YIgO__Y3fn(YIgO *t, Tc *Apath) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YIgO__Y3fnfo[0].off = (void*)&sf - (void*)&t;
  YIgO__Y3fnfo[1].off = (void*)&sf - (void*)&Apath;
 }
 sf.frof = YIgO__Y3fnfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7626200;
  ZthrowThisNil();
 }
 sf.pos=7626201;
 if ((t->Vpaths == NULL))
 {
  sf.pos=7626202;
  t->Vpaths = ZnewList((Tt*)&string__T, 0);
 }
 sf.pos=7626203;
 ZLap((Tl*)t->Vpaths, (Tz)(void*)Apath);
 e->topFrame = sf.prev;
 return;
}
Zfo YIgO__YU_Wfo[5] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tb YIgO__YU_W(YIgO *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tl *Zf2 = NULL;
 Tc *Vp = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YIgO__YU_Wfo[0].off = (void*)&sf - (void*)&t;
  YIgO__YU_Wfo[1].off = (void*)&sf - (void*)&Acontext;
  YIgO__YU_Wfo[2].off = (void*)&sf - (void*)&Zf2;
  YIgO__YU_Wfo[3].off = (void*)&sf - (void*)&Vp;
 }
 sf.frof = YIgO__YU_Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3178000;
  ZthrowThisNil();
 }
 sf.pos=3178001;
 if ((t->Vpaths != NULL))
 {
  sf.pos=3178002;
  {
   Tfl Zf2i;
   Zf2 = t->Vpaths;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3178003;
   if ((ZstringCmp(Vp, Acontext->Vrequest->Vpath) == 0))
   {
    sf.pos=3178004;
    if ((t->VmimeType != NULL))
    {
     sf.pos=3178005;
     YDSB(Acontext->Vresponse, t->VmimeType);
    }
    sf.pos=3178006;
    if (YqXRa(t, Acontext))
    {
     sf.pos=3178007;
     r = 1;
     rt = 1;
     goto YekN;
    }
YekN:
    if (rt) goto YzCH;
   }
YzCH:
   if (rt) goto YJ0k;
   sf.pos=3178008;
   }
  }
YJ0k:
  if (rt) goto Y6QF;
 }
 sf.pos=3178009;
 r = 0;
Y6QF:
 e->topFrame = sf.prev;
 return r;
}
Tc *YIgO__YtrZ_I_imt[] = {
 (Tc*)&YIgO__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YIgO__Y3fn, /* MHTTPModule__CStringServlet.addPath - YIgO__Y3fn */
 (Tc*)YIgO__YU_W, /* MHTTPModule__CStringServlet.handle - YIgO__YU_W */
 (Tc*)0, /* MHTTPModule__CStringServlet.setMimeType - YIgO__YuzN */
 (Tc*)YqXRa, /* MHTTPModule__CStringServlet.serve - YqXRa */
 (Tc*)0, /* Init - YIgOa */
};
To ToYIgO[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* body */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* paths */
 {0, (Tt*)&string__T}, /* mimeType */
};
char *StrYIgO[] = {
 "body",
 "name",
 "paths",
 "mimeType",
};
Tto YIgO__T = {390, (Tc*)&Y2iZ, 0, StrYIgO, 0, 0, 0, 0, ToYIgO};
To ToYivg[] = {
 {2, 0},
 {0, (Tt*)&YKxQ__T}, /* rpcInfo */
 {0, (Tt*)&cb__T}, /* handler */
};
char *StrYivg[] = {
 "rpcInfo",
 "handler",
};
Tto Yivg__T = {390, (Tc*)&Yesk, 0, StrYivg, 0, 0, 0, 0, ToYivg};
Zfo YvI9fo[5] = {{0,(Tt*)&YntX__T},{0,(Tt*)&YKxQ__T},{0,(Tt*)&cb__T},{0,(Tt*)&Yivg__T},{0,0}};
void YvI9(YntX *t, YKxQ *ArpcInfo, Tcb *Ahandler) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Yivg *Vh = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YvI9fo[0].off = (void*)&sf - (void*)&t;
  YvI9fo[1].off = (void*)&sf - (void*)&ArpcInfo;
  YvI9fo[2].off = (void*)&sf - (void*)&Ahandler;
  YvI9fo[3].off = (void*)&sf - (void*)&Vh;
 }
 sf.frof = YvI9fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1696600;
  ZthrowThisNil();
 }
 sf.pos=1696601;
 if (ZDictHas(t->Vservices, (Tz)(void*)ArpcInfo->Vname))
 {
  void *ex = NULL;
  sf.pos=1696602;
  ex = ZcS(((Tc*)&Ybeb), ArpcInfo->Vname);
  ZthrowPos(1696603, ex);
 }
 sf.pos=1696604;
 Vh = Za(sizeof(Yivg));
 sf.pos=1696605;
 Vh->VrpcInfo = ArpcInfo;
 sf.pos=1696606;
 Vh->Vhandler = Ahandler;
 sf.pos=1696607;
 ZDictAdd(0, t->Vservices, (Tz)(void*)ArpcInfo->Vname, (Tz)(void*)Vh);
 e->topFrame = sf.prev;
 return;
}
Zfo Yk9uafo[10] = {{0,(Tt*)&YntX__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&YSM1__T},{0,(Tt*)&string__T},{0,(Tt*)&Yivg__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tb Yk9ua(YntX *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 YSM1 *Vreq = 0;
 Tc *Vname = NULL;
 Yivg *Vh = 0;
 Tr Vrequest = {NULL};
 Tr Vresponse = {NULL};
 YjUM *Vwriter = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yk9uafo[0].off = (void*)&sf - (void*)&t;
  Yk9uafo[1].off = (void*)&sf - (void*)&Acontext;
  Yk9uafo[2].off = (void*)&sf - (void*)&Vreq;
  Yk9uafo[3].off = (void*)&sf - (void*)&Vname;
  Yk9uafo[4].off = (void*)&sf - (void*)&Vh;
  Yk9uafo[5].off = (void*)&sf - (void*)&Vrequest;
  Yk9uafo[6].off = (void*)&sf - (void*)&Vresponse;
  Yk9uafo[7].off = (void*)&sf - (void*)&Vwriter;
  Yk9uafo[8].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yk9uafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6759200;
  ZthrowThisNil();
 }
 sf.pos=6759201;
 Vreq = Acontext->Vrequest;
 sf.pos=6759202;
 if (ZDictHas(Yi2X(Vreq), (Tz)(void*)((Tc*)&Y4Po)))
 {
  sf.pos=6759203;
  Vname = ((Tc *)ZDictGetPtr(Yi2X(Vreq), (Tz)(void*)((Tc*)&Y4Po)));
  sf.pos=6759204;
  if (ZDictHas(t->Vservices, (Tz)(void*)Vname))
  {
   sf.pos=6759205;
   Vh = ((Yivg *)ZDictGetPtr(t->Vservices, (Tz)(void*)Vname));
   sf.pos=6759206;
   Vrequest = ((Tr (*)(Tcb *, Tr))Vh->VrpcInfo->VcreateFromJson->cfunc)(Vh->VrpcInfo->VcreateFromJson, *Znao(&t0, YOD2(NULL, ZbyteStringCheckUtf8(Vreq->Vbody)), YtZ0__YFWV_imt, 1));
   sf.pos=6759207;
   Vresponse = ((Tr (*)(Tcb *))Vh->VrpcInfo->VcreateResponse->cfunc)(Vh->VrpcInfo->VcreateResponse);
   sf.pos=6759208;
   ((Ts (*)(Tcb *, YtzZ*, Tr, Tr))Vh->Vhandler->cfunc)(Vh->Vhandler, Acontext, Vrequest, Vresponse);
   sf.pos=6759209;
   Vwriter = Za(sizeof(YjUM));
   sf.pos=6759210;
   ((void (*)(void*, Tr))(Vresponse.table[52]))(Vresponse.ptr, *Znao(&t0, Vwriter, YjUM__YdXi_imt, 2));
   sf.pos=6759211;
   Acontext->Vresponse->Vbody = YbNW(Vwriter);
   sf.pos=6759212;
   YDSB(Acontext->Vresponse, ((Tc*)&YN6V));
   sf.pos=6759213;
   r = 1;
   rt = 1;
   goto YVEe;
  }
YVEe:
  if (rt) goto YZtV;
 }
 sf.pos=6759214;
 r = 0;
YZtV:
 e->topFrame = sf.prev;
 return r;
}
Zfo YntX__Y3fnfo[3] = {{0,(Tt*)&YntX__T},{0,(Tt*)&string__T},{0,0}};
void YntX__Y3fn(YntX *t, Tc *Apath) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YntX__Y3fnfo[0].off = (void*)&sf - (void*)&t;
  YntX__Y3fnfo[1].off = (void*)&sf - (void*)&Apath;
 }
 sf.frof = YntX__Y3fnfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8916800;
  ZthrowThisNil();
 }
 sf.pos=8916801;
 if ((t->Vpaths == NULL))
 {
  sf.pos=8916802;
  t->Vpaths = ZnewList((Tt*)&string__T, 0);
 }
 sf.pos=8916803;
 ZLap((Tl*)t->Vpaths, (Tz)(void*)Apath);
 e->topFrame = sf.prev;
 return;
}
Zfo YntX__YU_Wfo[5] = {{0,(Tt*)&YntX__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tb YntX__YU_W(YntX *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tl *Zf2 = NULL;
 Tc *Vp = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YntX__YU_Wfo[0].off = (void*)&sf - (void*)&t;
  YntX__YU_Wfo[1].off = (void*)&sf - (void*)&Acontext;
  YntX__YU_Wfo[2].off = (void*)&sf - (void*)&Zf2;
  YntX__YU_Wfo[3].off = (void*)&sf - (void*)&Vp;
 }
 sf.frof = YntX__YU_Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1434200;
  ZthrowThisNil();
 }
 sf.pos=1434201;
 if ((t->Vpaths != NULL))
 {
  sf.pos=1434202;
  {
   Tfl Zf2i;
   Zf2 = t->Vpaths;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1434203;
   if ((ZstringCmp(Vp, Acontext->Vrequest->Vpath) == 0))
   {
    sf.pos=1434204;
    if ((t->VmimeType != NULL))
    {
     sf.pos=1434205;
     YDSB(Acontext->Vresponse, t->VmimeType);
    }
    sf.pos=1434206;
    if (Yk9ua(t, Acontext))
    {
     sf.pos=1434207;
     r = 1;
     rt = 1;
     goto Yyer;
    }
Yyer:
    if (rt) goto YDmi;
   }
YDmi:
   if (rt) goto YRwl;
   sf.pos=1434208;
   }
  }
YRwl:
  if (rt) goto Y82I;
 }
 sf.pos=1434209;
 r = 0;
Y82I:
 e->topFrame = sf.prev;
 return r;
}
To ToYntX[] = {
 {4, 0},
 {0, (Tt*)&dict__T}, /* services */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* paths */
 {0, (Tt*)&string__T}, /* mimeType */
};
char *StrYntX[] = {
 "services",
 "name",
 "paths",
 "mimeType",
};
Tto YntX__T = {390, (Tc*)&Y103, 0, StrYntX, 0, 0, 0, 0, ToYntX};
Zfo YAvlfo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
Y1QG *YAvl(Y1QG *t, Ti Aport) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAvlfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YAvlfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9633000; t = Y1QGa(NULL);}
 sf.pos=9633001;
 t->Vport = Aport;
 sf.pos=9633002;
 if ((t->Vport != 80))
 {
  sf.pos=9633003;
  t->Vbase =  ZcS(t->Vbase, ZcS(((Tc*)&Y5), Zint2string(t->Vport)));
 }
 sf.pos=9633004;
 t->VfileRoot = ZcS(YzHL(), ((Tc*)&Ycao));
 e->topFrame = sf.prev;
 return t;
}
Zfo Yb8ifo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&iobj__T},{0,0}};
void Yb8i(Y1QG *t, Tr Aservlet) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yb8ifo[0].off = (void*)&sf - (void*)&t;
  Yb8ifo[1].off = (void*)&sf - (void*)&Aservlet;
 }
 sf.frof = Yb8ifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9865000;
  ZthrowThisNil();
 }
 sf.pos=9865001;
 ZLapIobj((Tl*)t->Vservlets, Aservlet);
 e->topFrame = sf.prev;
 return;
}
Zfo Yv7Qfo[6] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YphE__T},{0,(Tt*)&iobj__T},{0,0}};
void Yv7Q(Y1QG *t, Tc *Afrom, Tc *Ato) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YphE *Vservlet = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yv7Qfo[0].off = (void*)&sf - (void*)&t;
  Yv7Qfo[1].off = (void*)&sf - (void*)&Ato;
  Yv7Qfo[2].off = (void*)&sf - (void*)&Afrom;
  Yv7Qfo[3].off = (void*)&sf - (void*)&Vservlet;
  Yv7Qfo[4].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yv7Qfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8074200;
  ZthrowThisNil();
 }
 sf.pos=8074201;
 Vservlet = Ytlk(NULL, Ato);
 sf.pos=8074202;
 YphE__Y3fn(Vservlet, Afrom);
 sf.pos=8074203;
 Yb8i(t, *Znao(&t0, Vservlet, YphE__YtrZ_I_imt, 0));
 e->topFrame = sf.prev;
 return;
}
Zfo YVBUfo[20] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&string__T},{0,(Tt*)&YSM1__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YKeB__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
void YVBU(Y1QG *t) {
 Ti VlistenArg;
 Ti Vsi;
 Ti Vei;
 Ti Vqi;
 Ti Veol;
 Ti Vbol;
 Ti VbodySize;
 volatile Tb Vdone;
 Ti VrespLen;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *VreqString = NULL;
 YSM1 *Vreq = 0;
 Tc *Vmethod = NULL;
 Tc *Vparams = NULL;
 Tc *Vvers = NULL;
 Tc *VfieldName = NULL;
 Tc *VfieldValue = NULL;
 YKeB *Vresp = 0;
 volatile YtzZ *Vcontext = 0;
 Tl *Zf3 = NULL;
 volatile Tr Vservlet = {NULL};
 volatile Tr Ve = {NULL};
 Tc *VrespString = NULL;
 Tl *Zf1 = NULL;
 Tc *Vkey = NULL;
 YjUM *Vwriter = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YVBUfo[0].off = (void*)&sf - (void*)&t;
  YVBUfo[1].off = (void*)&sf - (void*)&VreqString;
  YVBUfo[2].off = (void*)&sf - (void*)&Vreq;
  YVBUfo[3].off = (void*)&sf - (void*)&Vmethod;
  YVBUfo[4].off = (void*)&sf - (void*)&Vparams;
  YVBUfo[5].off = (void*)&sf - (void*)&Vvers;
  YVBUfo[6].off = (void*)&sf - (void*)&VfieldName;
  YVBUfo[7].off = (void*)&sf - (void*)&VfieldValue;
  YVBUfo[8].off = (void*)&sf - (void*)&Vresp;
  YVBUfo[9].off = (void*)&sf - (void*)&Vcontext;
  YVBUfo[10].off = (void*)&sf - (void*)&Zf3;
  YVBUfo[11].off = (void*)&sf - (void*)&Vservlet;
  YVBUfo[12].off = (void*)&sf - (void*)&Ve;
  YVBUfo[13].off = (void*)&sf - (void*)&VrespString;
  YVBUfo[14].off = (void*)&sf - (void*)&Zf1;
  YVBUfo[15].off = (void*)&sf - (void*)&Vkey;
  YVBUfo[16].off = (void*)&sf - (void*)&Vwriter;
  YVBUfo[17].off = (void*)&sf - (void*)&t0;
  YVBUfo[18].off = (void*)&sf - (void*)&t1;
 }
 sf.frof = YVBUfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9936600;
  ZthrowThisNil();
 }
 sf.pos=9936601;
 VlistenArg = t->VlistenQueueLen;
 sf.pos=9936602;
 Yhx8();
 sf.pos=9936603;
#if defined(__MINGW32__) || defined(_MSC_VER)
      {
        static int did_init = 0;
        if (did_init == 0) {
          WSADATA wsadata;
          did_init = 1;
          if (WSAStartup(MAKEWORD(1,1), &wsadata) == SOCKET_ERROR) {
            fprintf(stderr, "Error in WSAStartup()\n");
            return;
          }
        }
      }
#endif
      int serv_fd;
      serv_fd = socket(AF_INET, SOCK_STREAM, 0);
      if (serv_fd == -1) {
        perror("HTTP.Server socket()");
        return;
      }
      {
        int on = 1;
        if (setsockopt(serv_fd, SOL_SOCKET, SO_REUSEADDR,
                                                     &on, sizeof(on)) == -1) {
          perror("HTTP.Server setsockopt()");
          return;
        }
      }
      {
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(struct sockaddr_in));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons((int)t->Vport);
        if (bind(serv_fd, (struct sockaddr *)&serv_addr,
                                                   sizeof(serv_addr)) == -1) {
          perror("HTTP.Server bind()");
          return;
        }
      }

      if (listen(serv_fd, VlistenArg) == -1) {
        perror("HTTP.Server listen()");
        return;
      }
      while (!t->VdidQuit) {
        struct sockaddr_in client_addr;
        int fd;
#define MAX_HEADER_SIZE 9100
        char req_string[MAX_HEADER_SIZE];
        socklen_t addr_len = sizeof(client_addr);
        int len;
 sf.pos=9936604;

        fd = accept(serv_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (fd == -1) {
          if (errno != EINTR) perror("HTTP.Server accept()");
          if (errno == EBADF || errno == EFAULT || errno == EINVAL) break;
          continue;
        }
        len = sckt_read(fd, req_string, MAX_HEADER_SIZE - 1);
        if (len <= 0) {
          if (len < 0) perror("HTTP.Server read header");
          continue;
        }
 sf.pos=9936605;
        req_string[len] = 0;
        VreqString = Zstr(req_string);
 sf.pos=9936606;
 Vreq = YF0N(NULL);
 sf.pos=9936607;
 Vsi = ZstringFindChar(VreqString, 32, 0);
 sf.pos=9936608;
 if ((Vsi < 0))
 {
  sf.pos=9936609;
          continue;
 }
 sf.pos=9936610;
 Vmethod = ZstringToLower(ZstringSlice(VreqString, 0, (Vsi - 1), 0));
 sf.pos=9936611;
 {
  Te Vt;
  Tfe Zf1;
  Zf1.count = 9;
  Zf1.idx = 0;
  for (ZforEnumGetEnum(&Zf1, &Vt); ZforEnumContEnum(&Zf1); ZforEnumNextEnum(&Zf1, &Vt)) {
  sf.pos=9936612;
  if ((ZstringCmp(Zenum2string(MHTTPModule__ERequestType, Vt), Vmethod) == 0))
  {
   sf.pos=9936613;
   Vreq->Vtype = Vt;
   rt = 2;
   goto Yj3e;
  }
Yj3e:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=9936614;
  }
 }
 sf.pos=9936615;
 while ((ZstringGetChar(VreqString, Vsi) == 32))
 {
  sf.pos=9936616;
  ++(Vsi);
 sf.pos=9936617;
 }
 sf.pos=9936618;
 Vei = Vsi;
 sf.pos=9936619;
 while (((ZstringGetChar(VreqString, Vei) != 32) && (ZstringGetChar(VreqString, Vei) != 0)))
 {
  sf.pos=9936620;
  ++(Vei);
 sf.pos=9936621;
 }
 sf.pos=9936622;
 Vreq->Vpath = ZstringSlice(VreqString, Vsi, (Vei - 1), 0);
 sf.pos=9936623;
 Vqi = ZstringFindChar(Vreq->Vpath, 63, 0);
 sf.pos=9936624;
 if ((Vqi >= 0))
 {
  sf.pos=9936625;
  Vreq->Vparams = ZstringSlice(Vreq->Vpath, (Vqi + 1), -1, 0);
  sf.pos=9936626;
  Vreq->Vpath = ZstringSlice(Vreq->Vpath, 0, (Vqi - 1), 0);
 }
 sf.pos=9936627;
 while ((ZstringGetChar(VreqString, Vei) == 32))
 {
  sf.pos=9936628;
  ++(Vei);
 sf.pos=9936629;
 }
 sf.pos=9936630;
 Veol = ZstringFindChar2(VreqString, 10, Vei, 0);
 Vbol = 0;
 sf.pos=9936631;
 if ((Veol < 0))
 {
  sf.pos=9936632;
  Veol = (ZstringSize(VreqString) - 1);
  sf.pos=9936633;
  Vbol = Veol;
 }
 else
 {
  sf.pos=9936634;
  Vbol = (Veol + 1);
  sf.pos=9936635;
  --(Veol);
  sf.pos=9936636;
  if ((ZstringGetChar(VreqString, Veol) == 13))
  {
   sf.pos=9936637;
   --(Veol);
  }
 }
 sf.pos=9936638;
 Vreq->VhttpVersion = ZstringSlice(VreqString, Vei, Veol, 0);
 sf.pos=9936639;
 if ((t->Vverbosity != 0))
 {
  sf.pos=9936640;
  Vparams = ((Tc*)&Ya);
  sf.pos=9936641;
  if ((Vreq->Vparams != NULL))
  {
   sf.pos=9936642;
   Vparams = ZcS3(((Tc*)&Yj86), Vreq->Vparams, ((Tc*)&YN));
  }
  sf.pos=9936643;
  Vvers = ((Tc*)&Ya);
  sf.pos=9936644;
  if ((ZstringCmp(Vreq->VhttpVersion, ((Tc*)&Ye88)) != 0))
  {
   sf.pos=9936645;
   Vvers = ZcS3(((Tc*)&YmUM), Vreq->VhttpVersion, ((Tc*)&YN));
  }
  sf.pos=9936646;
  Yl0k(ZcS8(((Tc*)&YpFn), ZstringToUpper(Zenum2string(MHTTPModule__ERequestType, Vreq->Vtype)), ((Tc*)&Y5Y), (t0 = Vreq->Vpath), ((Tc*)&YN), Vparams, Vvers, (Tc*)1));
  sf.pos=9936647;
  if ((t->Vverbosity == 2))
  {
   sf.pos=9936648;
   Yl0k(ZcS3(((Tc*)&YUqj), VreqString, ((Tc*)&YN)));
  }
 }
 sf.pos=9936649;
 while (1)
 {
  Ti Vcolon;
  sf.pos=9936650;
  Veol = ZstringFindChar2(VreqString, 10, Vbol, 0);
  sf.pos=9936651;
  if ((Veol < 0))
  {
   sf.pos=9936652;
   Yl0k(((Tc*)&Yetr));
   sf.pos=9936653;
   Vbol = ZstringSize(VreqString);
   rt = 2;
   goto Yaoy;
  }
  sf.pos=9936654;
  if (((Veol == Vbol) || (((Veol == (Vbol + 1)) && (ZstringGetChar(VreqString, Vbol) == 13)))))
  {
   sf.pos=9936655;
   Vbol = (Veol + 1);
   rt = 2;
   goto Yaoy;
  }
  sf.pos=9936656;
  Vcolon = ZstringFindChar2(VreqString, 58, Vbol, 0);
  sf.pos=9936657;
  if ((Vcolon > 0))
  {
   Ti VfieldStart;
   sf.pos=9936658;
   VfieldName = ZstringToLower(ZstringSlice(VreqString, Vbol, (Vcolon - 1), 0));
   sf.pos=9936659;
   VfieldValue = ((Tc*)&Ya);
   sf.pos=9936660;
   VfieldStart = (Vcolon + 1);
   sf.pos=9936661;
   while (1)
   {
    Ti VfieldEnd;
    sf.pos=9936662;
    VfieldEnd = (Veol - 1);
    sf.pos=9936663;
    if ((ZstringGetChar(VreqString, VfieldEnd) == 13))
    {
     sf.pos=9936664;
     --(VfieldEnd);
    }
    sf.pos=9936665;
    while ((Y2jx(ZstringGetChar(VreqString, VfieldStart)) && (VfieldStart <= VfieldEnd)))
    {
     sf.pos=9936666;
     ++(VfieldStart);
    sf.pos=9936667;
    }
    sf.pos=9936668;
    while ((Y2jx(ZstringGetChar(VreqString, VfieldEnd)) && (VfieldEnd >= VfieldStart)))
    {
     sf.pos=9936669;
     --(VfieldEnd);
    sf.pos=9936670;
    }
    sf.pos=9936671;
    VfieldValue =  ZcS(VfieldValue, ZstringSlice(VreqString, VfieldStart, VfieldEnd, 0));
    sf.pos=9936672;
    if (!(Y2jx(ZstringGetChar(VreqString, (Veol + 1)))))
    {
     rt = 2;
     goto YU1X;
    }
    sf.pos=9936673;
    Vbol = (Veol + 1);
    sf.pos=9936674;
    Veol = ZstringFindChar2(VreqString, 10, Vbol, 0);
    sf.pos=9936675;
    if ((Veol < 0))
    {
     rt = 2;
     goto YU1X;
    }
    sf.pos=9936676;
    VfieldStart = (Vbol + 1);
    sf.pos=9936677;
    VfieldValue =  ZcS(VfieldValue, ((Tc*)&YG));
YU1X:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=9936678;
   }
   sf.pos=9936679;
   if (ZDictHas(Vreq->VheaderItems, (Tz)(void*)VfieldName))
   {
    sf.pos=9936680;
    VfieldValue = ZcS3(((Tc *)ZDictGetPtr(Vreq->VheaderItems, (Tz)(void*)VfieldName)), ((Tc*)&Ydha), VfieldValue);
   }
   sf.pos=9936681;
   *((Tc **)ZDictGetPtrP(Vreq->VheaderItems, (Tz)(void*)VfieldName)) = VfieldValue;
  }
  sf.pos=9936682;
  Vbol = (Veol + 1);
Yaoy:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9936683;
 }
 sf.pos=9936684;
 if ((t->Vverbosity == 2))
 {
  sf.pos=9936685;
  Yl0k(ZcS(((Tc*)&Y5UY), ZDictToString(Vreq->VheaderItems, 1, 1)));
 }
 sf.pos=9936686;
 VbodySize = 0;
 sf.pos=9936687;
 if (ZDictHas(Vreq->VheaderItems, (Tz)(void*)((Tc*)&YSBt)))
 {
  sf.pos=9936688;
  VbodySize = ZstringToInt(((Tc *)ZDictGetPtr(Vreq->VheaderItems, (Tz)(void*)((Tc*)&YSBt))), 1, 0);
  sf.pos=9936689;
  if ((t->Vverbosity != 0))
  {
   sf.pos=9936690;
   Yl0k(ZcS(((Tc*)&Y6Ov), Zint2string(VbodySize)));
  }
 }
 sf.pos=9936691;
 if ((VbodySize > 0))
 {
  sf.pos=9936692;
  Vwriter = Za(sizeof(YjUM));
  sf.pos=9936693;
  YJqza(Vwriter, ZstringSlice(VreqString, Vbol, -1, 0));
  sf.pos=9936694;
  while ((Yd3R(Vwriter) < VbodySize))
  {
   Ti Vlen;
   Vlen = 0;
   sf.pos=9936695;
   if ((t->Vverbosity == 2))
   {
    sf.pos=9936696;
    Yl0k(((Tc*)&YLqJ));
   }
   sf.pos=9936697;
            Vlen = sckt_read(fd, req_string, MAX_HEADER_SIZE - 1);
            if (Vlen > 0) {
              req_string[Vlen] = 0;
   sf.pos=9936698;
              VreqString = Zstr(req_string);
            }
   sf.pos=9936699;
   if ((t->Vverbosity == 2))
   {
    sf.pos=9936700;
    Yl0k(ZcS(((Tc*)&Ylp1), Zint2string(Vlen)));
   }
   sf.pos=9936701;
   if ((Vlen <= 0))
   {
    rt = 2;
    goto YAno;
   }
   sf.pos=9936702;
   YJqza(Vwriter, VreqString);
YAno:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=9936703;
  }
  sf.pos=9936704;
  Vreq->Vbody = YbNW(Vwriter);
  sf.pos=9936705;
  if ((t->Vverbosity == 2))
  {
   sf.pos=9936706;
   Yvcu(ZcS3(((Tc*)&YLih), Zint2string(ZbyteStringSize(Vreq->Vbody)), ((Tc*)&YrD_)));
   sf.pos=9936707;
   if ((ZbyteStringSize(Vreq->Vbody) > 1000))
   {
    sf.pos=9936708;
    Yl0k(ZstringSlice(ZbyteStringCheckUtf8(Vreq->Vbody), 0, 500, 0));
    sf.pos=9936709;
    Yl0k(((Tc*)&YKUO));
    sf.pos=9936710;
    Yvcu(ZstringSlice(ZbyteStringCheckUtf8(Vreq->Vbody), -500, -1, 0));
   }
   else
   {
    sf.pos=9936711;
    Yvcu(ZbyteStringCheckUtf8(Vreq->Vbody));
   }
   sf.pos=9936712;
   Yl0k(((Tc*)&YN));
  }
 }
 else
 {
  sf.pos=9936713;
  Vreq->Vbody = ((Tc*)&Ya);
 }
 sf.pos=9936714;
 t->Vbusy = 1;
 sf.pos=9936715;
 Vresp = YikN(NULL);
 Vdone = 0;
 sf.pos=9936716;
 Vcontext = Y89Z(NULL, t, Vreq, Vresp);
 sf.pos=9936717;
 {
  volatile int caught = 0;
  Tn *te = ZgetEnv();
  int try_index = te->tryCtxUsed;
  volatile int did_jump = 0;
  sf.pos=9936718;
  ZtryDeeper(te, &sf);
  if (setjmp(te->tryCtx[try_index].jmpBuf) != 0) {
   ++did_jump;
   e->topFrame = &sf;
  }
  if (did_jump == 0) /* TRY */
  {
   sf.pos=9936719;
   {
    Tfl Zf3i;
    Zf3 = t->Vservlets;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vservlet;
    Zf3i.i = 0;
    for (; ZforListIobjCont(&Zf3i); ) {
    sf.pos=9936720;
    if (((Tb (*)(void*, YtzZ*))(((Tr)Vservlet).table[5]))(((Tr)Vservlet).ptr, ((YtzZ*)Vcontext)))
    {
     sf.pos=9936721;
     Vdone = 1;
     rt = 2;
     goto YouY;
    }
YouY:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=9936722;
    }
   }
  }
  te->tryCtxUsed = try_index;
  if (did_jump == 1 && !caught && (ZTypeInRange((te->thrown[te->thrownUsed - 1]).type, 0, 32))) /* CATCH */
  {
   Ve = te->thrown[--te->thrownUsed];
   caught = 1;
   sf.pos=9936723;
   if ((t->Vverbosity == 2))
   {
    sf.pos=9936724;
    Yl0k(ZcS(((Tc*)&Y_P0), ((Tc* (*)(void*, Tb))(((Tr)Ve).table[9]))(((Tr)Ve).ptr, 1)));
   }
   else
   {
    sf.pos=9936725;
    Yl0k(ZcS(((Tc*)&Y_P0), ((Tc* (*)(void*))(((Tr)Ve).table[6]))(((Tr)Ve).ptr)));
   }
  }
  if ((did_jump == 1 && !caught) || did_jump > 1) Zrethrow();
 }
 sf.pos=9936726;
 if (!(Vdone))
 {
  sf.pos=9936727;
  Vresp->Vcode = 404;
  sf.pos=9936728;
  Vresp->Vmsg = ((Tc*)&Yytr);
  sf.pos=9936729;
  Vresp->Vbody = ((Tc*)&YaLI);
 }
 sf.pos=9936730;
 YjIQ(Vresp, ZstringSize(Vresp->Vbody));
 sf.pos=9936731;
 VrespString = ZcS5(((Tc*)&Y5E7), Zint2string(Vresp->Vcode), ((Tc*)&YG), (t0 = Vresp->Vmsg), ((Tc*)&Yau));
 VrespLen = 0;
 sf.pos=9936732;
 {
  Tfl Zf1i;
  Zf1 = ZDictKeys(Vresp->VheaderItems, 0);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vkey;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=9936733;
  VrespString =  ZcS(VrespString, ZcS5(Vkey, ((Tc*)&YFDa), (t0 = ((Tc *)ZDictGetPtr(Vresp->VheaderItems, (Tz)(void*)Vkey))), ((Tc*)&Yau), (Tc*)1));
  sf.pos=9936734;
  }
 }
 sf.pos=9936735;
 VrespLen = ZstringSize(VrespString);
 sf.pos=9936736;
 if ((t->Vverbosity != 0))
 {
  sf.pos=9936737;
  Yl0k(ZcS(((Tc*)&YkHK), Zint2string(Vresp->Vcode)));
  sf.pos=9936738;
  if ((t->Vverbosity == 2))
  {
   sf.pos=9936739;
   Yl0k(ZcS(((Tc*)&Y5UY), ZDictToString(Vresp->VheaderItems, 1, 1)));
   sf.pos=9936740;
   Yvcu(((Tc*)&Y6wd));
   sf.pos=9936741;
   if ((ZstringSize(Vresp->Vbody) > 1000))
   {
    sf.pos=9936742;
    Yl0k(ZstringSlice(Vresp->Vbody, 0, 500, 0));
    sf.pos=9936743;
    Yl0k(((Tc*)&YKUO));
    sf.pos=9936744;
    Yvcu(ZstringSlice(Vresp->Vbody, -500, -1, 0));
   }
   else
   {
    sf.pos=9936745;
    Yvcu(Vresp->Vbody);
   }
   sf.pos=9936746;
   Yl0k(((Tc*)&YN));
  }
 }
 sf.pos=9936747;
        /* dummy loop so that we can use "break" to get to sckt_close() */
        for (;;) {
 sf.pos=9936748;
          char *s = ZgetCstring(VrespString);
 sf.pos=9936749;
          if (sckt_write(fd, s, (size_t)VrespLen) <= 0)
          {
            perror("HTTP.Server write header");
            break;
          }
 sf.pos=9936750;
 if ((Vreq->Vtype != 3))
 {
  sf.pos=9936751;
  VrespString = Vresp->Vbody;
  sf.pos=9936752;
  VrespLen = ZstringSize(VrespString);
  sf.pos=9936753;
            if (sckt_write(fd, "\r\n", 2) != 2) {
              perror("HTTP.Server write separator");
              break;
            }
  sf.pos=9936754;
            char *s = ZgetCstring(VrespString);
  sf.pos=9936755;
            if (VrespLen > 0 && sckt_write(fd, s, (size_t)VrespLen) <= 0)
            {
              perror("HTTP.Server write body");
              break;
            }
 }
 sf.pos=9936756;
          break;
        }
        sckt_close(fd);
 sf.pos=9936757;
 t->Vbusy = 0;
 sf.pos=9936758;
 if (t->VdidQuit)
 {
  sf.pos=9936759;
  YWty(t->VquitPipe, 1);
 }
 sf.pos=9936760;
     }  /* while */
 e->topFrame = sf.prev;
 return;
}
Zfo YQj8fo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&string__T},{0,0}};
Ts YQj8(Y1QG *t, Tc *Apage) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YQj8fo[0].off = (void*)&sf - (void*)&t;
  YQj8fo[1].off = (void*)&sf - (void*)&Apage;
 }
 sf.frof = YQj8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7636100;
  ZthrowThisNil();
 }
 sf.pos=7636101;
 r = YNAV(ZcS5(((Tc*)&YhLu), Zint2string(t->Vport), ((Tc*)&YV), Apage, (Tc*)1));
 e->topFrame = sf.prev;
 return r;
}
Zfo YqJzfo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
void YqJz(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqJzfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YqJzfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3442600;
  ZthrowThisNil();
 }
 sf.pos=3442601;
 while (((YIWKa(t->VquitPipe) == 0) && !(t->VdidQuit)))
  ;
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QG__YTgs__Y7C8fo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&list__T},{0,0}};
void Y1QG__YTgs__Y7C8(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf1 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YTgs__Y7C8fo[0].off = (void*)&sf - (void*)&t;
  Y1QG__YTgs__Y7C8fo[1].off = (void*)&sf - (void*)&Zf1;
 }
 sf.frof = Y1QG__YTgs__Y7C8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3987700;
  ZthrowThisNil();
 }
 sf.pos=3987701;
 int i = 0;
 Zsf *prev = NULL;
 e->startFrames = calloc(1, ZListSize(t->Vstack) * sizeof(Zsf));
 sf.pos=3987702;
 {
  Ti Vpos;
  Tfl Zf1i;
  Zf1 = t->Vstack;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vpos;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=3987703;
 e->startFrames[i].pos = Vpos;
 e->startFrames[i].prev = prev;
 prev = &e->startFrames[i];
 ++i;
  sf.pos=3987704;
  }
 }
 sf.pos=3987705;
 sf.prev = prev;
 sf.pos=3987706;
 pthread_mutex_lock(&threadsMutex);
 ZLa(threads, -1, (Tz)(void*)e);
 pthread_mutex_unlock(&threadsMutex);
 sf.pos=3987707;
 YVBU(t);

 e->finished = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QG__YTgs__YSuwfo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&iobj__T},{0,0}};
void Y1QG__YTgs__YSuw(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YTgs__YSuwfo[0].off = (void*)&sf - (void*)&t;
  Y1QG__YTgs__YSuwfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1QG__YTgs__YSuwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2210300;
  ZthrowThisNil();
 }
 sf.pos=2210301;
 Zsf *top = e->topFrame;
 sf.pos=2210302;
 t->Vstack = ZnewList((Tt*)&int__T, 0);
 sf.pos=2210303;
 while ((ZListSize(t->Vstack) < 30))
 {
  Ti Ventry;
  Ventry = 0;
  sf.pos=2210304;
  if (top == NULL) break;
  Ventry = top->pos;
  top = top->prev;
  sf.pos=2210305;
  ZListInsert((Tl*)t->Vstack, 0, (Tz)(Ti)Ventry);
 sf.pos=2210306;
 }
 sf.pos=2210307;
 if (pthread_create(&t->Vthread_id, NULL, (void *(*)(void *))Y1QG__YTgs__Y7C8, t) != 0) {
 sf.pos=2210308;
 if (1)
 {
  Tr ex;
  sf.pos=2210309;
  *Znao(&ex, YgC4__YwtA__YRHR(NULL, ((Tc*)&YgzQ)), YgC4__Ytlm_I_imt, 31);
  ZthrowIobject(ex);
 }
 sf.pos=2210310;
 }
 {
  int oldstate;
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
 }
 sf.pos=2210311;
 t->Vstate = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QG__YTgs__Y2Czfo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
Ts Y1QG__YTgs__Y2Cz(Y1QG *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YTgs__Y2Czfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y1QG__YTgs__Y2Czfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9628200;
  ZthrowThisNil();
 }
 sf.pos=9628201;
 pthread_detach(t->Vthread_id);
 sf.pos=9628202;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
void Y1QG__YcCua(Y1QG *t) {
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vproc != NULL))
 {
  ((void (*)(Tcb *))t->Vproc->cfunc)((Tcb*)t->Vproc);
 }
 return;
}
Zfo Y1QGafo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
Y1QG *Y1QGa(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (t == NULL) t = Za(sizeof(Y1QG));
 if (!sfF) {
  sfF = 1;
  Y1QGafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y1QGafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3286400;
 t->VlistenQueueLen = 50;
 sf.pos=3286401;
 t->Vservlets = ZnewList((Tt*)&iobj__T, 0);
 sf.pos=3286402;
 t->Vbase = ((Tc*)&YoWK);
 sf.pos=3286403;
 t->Vverbosity = 1;
 sf.pos=3286404;
 t->VquitPipe = YPsV(NULL);
 e->topFrame = sf.prev;
 return t;
}
To ToY1QG[] = {
 {12, 0},
 {0, (Tt*)&int__T}, /* port */
 {0, (Tt*)&int__T}, /* listenQueueLen */
 {0, (Tt*)&list__T}, /* servlets */
 {0, (Tt*)&string__T}, /* fileRoot */
 {0, (Tt*)&string__T}, /* base */
 {0, (Tt*)&MHTTPModule__EVerbosity__T}, /* verbosity */
 {0, (Tt*)&YK7s__T}, /* quitPipe */
 {0, (Tt*)&bool__T}, /* didQuit */
 {0, (Tt*)&bool__T}, /* busy */
 {0, (Tt*)&cb__T}, /* proc */
 {0, (Tt*)&MTHREADModule__EState__T}, /* state */
 {0, (Tt*)&list__T}, /* stack */
};
char *StrY1QG[] = {
 "port",
 "listenQueueLen",
 "servlets",
 "fileRoot",
 "base",
 "verbosity",
 "quitPipe",
 "didQuit",
 "busy",
 "proc",
 "state",
 "stack",
};
Tto Y1QG__T = {390, (Tc*)&YooJ, 0, StrY1QG, 0, Y1QG__YTgs__Y2Cz, 0, 0, ToY1QG};
Tb Y2jx(Ti Ac) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7420000;
 r = ((Ac == 32) || (Ac == 9));
 e->topFrame = sf.prev;
 return r;
}
int JHTTPModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 done &= JProto(round);
  if (round == 0) {
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* HTTPModule done */
/* including ZModule bodies */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) {
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 return t;
}
Zfo YpI_fo[3] = {{0,(Tt*)&YkxB__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *YpI_(YkxB *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YpI_fo[0].off = (void*)&sf - (void*)&t;
  YpI_fo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YpI_fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
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
Tto YkxB__T = {390, (Tc*)&YBCs, YpI_, StrYkxB, 0, 0, 0, 0, ToYkxB};
/* ZModule done */
/* including STRINGModule bodies */
Zfo YO0wfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *YO0w(Tc *Athis) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YO0wfo[0].off = (void*)&sf - (void*)&Athis;
  YO0wfo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YO0wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4283400;
 if (Athis == NULL)
 {
  sf.pos=4283401;
  r = NULL;
  rt = 1;
  goto YX91;
 }
 sf.pos=4283402;
 Vw = Za(sizeof(YjUM));
 sf.pos=4283403;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew((ZstringSize(Athis) - 1), 0, 0, -1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=4283404;
  YjUM__Ydti(Vw, ZstringGetChar(Athis, Vi));
  sf.pos=4283405;
  }
 }
 sf.pos=4283406;
 r = YbNW(Vw);
YX91:
 e->topFrame = sf.prev;
 return r;
}
Zfo Yvnffo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *Yvnf(Tc *Athis, Ti Afrom, Ti Ato) {
 Ti Vi;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yvnffo[0].off = (void*)&sf - (void*)&Athis;
  Yvnffo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = Yvnffo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
  Vw = Za(sizeof(YjUM));
  sf.pos=1203505;
  while ((Vi >= 0))
  {
   sf.pos=1203506;
   if ((Vi > VnextChar))
   {
    sf.pos=1203507;
    YJqza(Vw, ZstringSlice(Athis, VnextChar, (Vi - 1), 0));
   }
   sf.pos=1203508;
   YjUM__Ydti(Vw, Ato);
   sf.pos=1203509;
   VnextChar = (Vi + 1);
   sf.pos=1203510;
   Vi = ZstringFindChar2(Athis, Afrom, VnextChar, 0);
  sf.pos=1203511;
  }
  sf.pos=1203512;
  YJqza(Vw, ZstringSlice(Athis, VnextChar, -1, 0));
  sf.pos=1203513;
  r = YbNW(Vw);
  rt = 1;
  goto YIVu;
 }
 sf.pos=1203514;
 r = Athis;
YIVu:
 e->topFrame = sf.prev;
 return r;
}
/* STRINGModule done */
/* including IOModule bodies */
Tr Yd89() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(ZaF(sizeof(Yw8L), ToYw8L, (Ts (*)(void*, Te))YSo_, 1), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdin;
 r = Vfile;
 return r;
}
Tr Yvyt() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(ZaF(sizeof(Yw8L), ToYw8L, (Ts (*)(void*, Te))YSo_, 1), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdout;
 r = Vfile;
 return r;
}
Tr YsM3() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(ZaF(sizeof(Yw8L), ToYw8L, (Ts (*)(void*, Te))YSo_, 1), Yw8L__Yw8L_I_imt, 0);
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
Zfo YFeQfo[3] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&iobj__T},{0,0}};
Ti YFeQ(Yw8L *t) {
 Ti Vb;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YFeQfo[0].off = (void*)&sf - (void*)&t;
  YFeQfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YFeQfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YAPpfo[3] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&iobj__T},{0,0}};
Ti YAPp(Yw8L *t) {
 Ti Vc;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAPpfo[0].off = (void*)&sf - (void*)&t;
  YAPpfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YAPpfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Yyumfo[3] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *Yyum(Yw8L *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yyumfo[0].off = (void*)&sf - (void*)&t;
  Yyumfo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = Yyumfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4325800;
  ZthrowThisNil();
 }
 sf.pos=4325801;
 Vw = Za(sizeof(YjUM));
 sf.pos=4325802;
 while (1)
 {
  Ti Vb;
  sf.pos=4325803;
  Vb = YFeQ(t);
  sf.pos=4325804;
  if ((Vb == Y3QJ))
  {
   rt = 2;
   goto YKpm;
  }
  sf.pos=4325805;
  Ye7fa(Vw, Vb);
YKpm:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=4325806;
 }
 sf.pos=4325807;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YaEhfo[3] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *YaEh(Yw8L *t) {
 Ti Vb;
 Ti VcrCount;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YaEhfo[0].off = (void*)&sf - (void*)&t;
  YaEhfo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YaEhfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7284100;
  ZthrowThisNil();
 }
 sf.pos=7284101;
 Vb = YFeQ(t);
 sf.pos=7284102;
 if ((Vb == Y3QJ))
 {
  sf.pos=7284103;
  r = NULL;
  rt = 1;
  goto Yphh;
 }
 sf.pos=7284104;
 Vw = Za(sizeof(YjUM));
 VcrCount = 0;
 sf.pos=7284105;
 while (((Vb != Y3QJ) && (Vb != 10)))
 {
  sf.pos=7284106;
  if ((Vb == 13))
  {
   sf.pos=7284107;
   ++(VcrCount);
  }
  else
  {
   sf.pos=7284108;
   while ((VcrCount > 0))
   {
    sf.pos=7284109;
    Ye7fa(Vw, 13);
    sf.pos=7284110;
    --(VcrCount);
   sf.pos=7284111;
   }
   sf.pos=7284112;
   Ye7fa(Vw, Vb);
  }
  sf.pos=7284113;
  Vb = YFeQ(t);
 sf.pos=7284114;
 }
 sf.pos=7284115;
 r = YbNW(Vw);
Yphh:
 e->topFrame = sf.prev;
 return r;
}
Zfo YCm1afo[4] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tl *YCm1a(Yw8L *t, Ti Acount) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *r = 0;
 Tl *Vresult = NULL;
 Tc *Vline = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YCm1afo[0].off = (void*)&sf - (void*)&t;
  YCm1afo[1].off = (void*)&sf - (void*)&Vresult;
  YCm1afo[2].off = (void*)&sf - (void*)&Vline;
 }
 sf.frof = YCm1afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5332600;
  ZthrowThisNil();
 }
 sf.pos=5332601;
 Vresult = ZnewList((Tt*)&string__T, 0);
 sf.pos=5332602;
 while (1)
 {
  sf.pos=5332603;
  Vline = YaEh(t);
  sf.pos=5332604;
  if ((Vline == NULL))
  {
   rt = 2;
   goto Y4YY;
  }
  sf.pos=5332605;
  ZLap((Tl*)Vresult, (Tz)(void*)Vline);
  sf.pos=5332606;
  if ((ZListSize(Vresult) >= Acount))
  {
   rt = 2;
   goto Y4YY;
  }
Y4YY:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=5332607;
 }
 sf.pos=5332608;
 r = Vresult;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwHoafo[4] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
Ts YwHoa(Yw8L *t, Tc *Atext) {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwHoafo[0].off = (void*)&sf - (void*)&t;
  YwHoafo[1].off = (void*)&sf - (void*)&Atext;
  YwHoafo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YwHoafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YrF8fo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts YrF8(Yw8L *t) {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrF8fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YrF8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YSo_fo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts YSo_(Yw8L *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSo_fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YSo_fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4982200;
  ZthrowThisNil();
 }
 sf.pos=4982201;
 YrF8(t);
 sf.pos=4982202;
 r = 1;
 if (r) t->fok |= FOK_OK;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YHhZbfo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YHhZbfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yw8L__YHhZbfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5981900;
  ZthrowThisNil();
 }
 sf.pos=5981901;
 r = YwHoa(t, Zint2string(Anumber));
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YRt7fo[3] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&string__T},{0,0}};
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YRt7fo[0].off = (void*)&sf - (void*)&t;
  Yw8L__YRt7fo[1].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yw8L__YRt7fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YRt7gfo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts Yw8L__YRt7g(Yw8L *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YRt7gfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yw8L__YRt7gfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8261800;
  ZthrowThisNil();
 }
 sf.pos=8261801;
 r = YwHoa(t, ((Tc*)&Yk));
 e->topFrame = sf.prev;
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
 (Tc*)Yyum, /* MIOModule__CFile.readAll - Yyum */
 (Tc*)0, /* MIOModule__CFile.readAllBytes - YVfz */
 (Tc*)YaEh, /* MIOModule__CFile.readLine - YaEh */
 (Tc*)0, /* MIOModule__CFile.readLineRaw - Yn2l */
 (Tc*)YCm1a, /* MIOModule__CFile.readAllLines - YCm1a */
 (Tc*)0, /* MIOModule__CFile.readAllLines - YCm1 */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWFa */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWF */
 (Tc*)0, /* MIOModule__CFile.writeAllLines - YZFx */
 (Tc*)0, /* MIOModule__CFile.flush - YGmp */
 (Tc*)YrF8, /* MIOModule__CFile.close - YrF8 */
 (Tc*)YSo_, /* MIOModule__CFile.Finish - YSo_ */
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
Tto Yw8L__T = {390, (Tc*)&YtTU, 0, StrYw8L, 0, YSo_, 0, 0, ToYw8L};
Zfo YOD2fo[3] = {{0,(Tt*)&YtZ0__T},{0,(Tt*)&string__T},{0,0}};
YtZ0 *YOD2(YtZ0 *t, Tc *Adata) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YOD2fo[0].off = (void*)&sf - (void*)&t;
  YOD2fo[1].off = (void*)&sf - (void*)&Adata;
 }
 sf.frof = YOD2fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9596500; t = Za(sizeof(YtZ0));}
 sf.pos=9596501;
 Y8UT((Adata != NULL));
 sf.pos=9596502;
 t->Vdata = Adata;
 sf.pos=9596503;
 t->VbyteSize = ZbyteStringSize(t->Vdata);
 e->topFrame = sf.prev;
 return t;
}
Zfo YxQqfo[2] = {{0,(Tt*)&YtZ0__T},{0,0}};
Ti YxQq(YtZ0 *t) {
 Ti Vc;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YxQqfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YxQqfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4154900;
  ZthrowThisNil();
 }
 sf.pos=4154901;
 if ((t->VbyteIdx >= t->VbyteSize))
 {
  sf.pos=4154902;
  r = Y3QJ;
  rt = 1;
  goto YrHZ;
 }
 sf.pos=4154903;
 Vc = ZbyteStringGetChar(t->Vdata, t->VbyteIdx, 0);
 sf.pos=4154904;
 if ((Vc < 0))
 {
  sf.pos=4154905;
  ++(t->VbyteIdx);
 }
 else
 {
  sf.pos=4154906;
  t->VbyteIdx += ZbyteStringGetCharSize(t->Vdata, t->VbyteIdx, 0);
 }
 sf.pos=4154907;
 r = Vc;
YrHZ:
 e->topFrame = sf.prev;
 return r;
}
Tc *YtZ0__YFWV_imt[] = {
 (Tc*)&YtZ0__T,
 (Tc*)YxQq, /* MIOModule__CStringReader.readChar - YxQq */
};
To ToYtZ0[] = {
 {3, 0},
 {0, (Tt*)&int__T}, /* byteIdx */
 {0, (Tt*)&int__T}, /* byteSize */
 {0, (Tt*)&byteString__T}, /* data */
};
char *StrYtZ0[] = {
 "byteIdx",
 "byteSize",
 "data",
};
Tto YtZ0__T = {390, (Tc*)&Yu_Y, 0, StrYtZ0, 0, 0, 0, 0, ToYtZ0};
Zfo Ynyhfo[3] = {{0,(Tt*)&YrC3__T},{0,(Tt*)&iobj__T},{0,0}};
YrC3 *Ynyh(YrC3 *t, Tr Areader) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ynyhfo[0].off = (void*)&sf - (void*)&t;
  Ynyhfo[1].off = (void*)&sf - (void*)&Areader;
 }
 sf.frof = Ynyhfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6310200; t = Za(sizeof(YrC3));}
 sf.pos=6310201;
 t->Vreader = Areader;
 sf.pos=6310202;
 t->Vstack = ZnewList((Tt*)&int__T, 0);
 e->topFrame = sf.prev;
 return t;
}
Zfo YVZBfo[2] = {{0,(Tt*)&YrC3__T},{0,0}};
Ti YVZB(YrC3 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YVZBfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YVZBfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5398600;
  ZthrowThisNil();
 }
 sf.pos=5398601;
 if ((ZListSize(t->Vstack) > 0))
 {
  sf.pos=5398602;
  r = ZListRemoveIntItem((Tl*)t->Vstack, -1);
  rt = 1;
  goto Y1US;
 }
 sf.pos=5398603;
 r = ((Ti (*)(void*))(t->Vreader.table[1]))(t->Vreader.ptr);
Y1US:
 e->topFrame = sf.prev;
 return r;
}
Zfo Y3erfo[2] = {{0,(Tt*)&YrC3__T},{0,0}};
void Y3er(YrC3 *t, Ti Ac) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y3erfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y3erfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2284800;
  ZthrowThisNil();
 }
 sf.pos=2284801;
 ZLap((Tl*)t->Vstack, (Tz)(Ti)Ac);
 e->topFrame = sf.prev;
 return;
}
To ToYrC3[] = {
 {2, 0},
 {0, (Tt*)&iobj__T}, /* reader */
 {0, (Tt*)&list__T}, /* stack */
};
char *StrYrC3[] = {
 "reader",
 "stack",
};
Tto YrC3__T = {390, (Tc*)&YmyU, 0, StrYrC3, 0, 0, 0, 0, ToYrC3};
Zfo YsGzfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
Tr YsGz(Tc *AfileName) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 Tr Vfile = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YsGzfo[0].off = (void*)&sf - (void*)&AfileName;
  YsGzfo[1].off = (void*)&sf - (void*)&Vfile;
 }
 sf.frof = YsGzfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=9983800;
 {
  int fnr = open(ZgetCstring(AfileName), O_RDONLY);
  if (fnr >= 0) {
 sf.pos=9983801;
 Vfile = *Znao(&Vfile, ZaF(sizeof(Yw8L), ToYw8L, (Ts (*)(void*, Te))YSo_, 1), Yw8L__Yw8L_I_imt, 0);
 sf.pos=9983802;
   (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = fdopen(fnr, "r");
  }
 }
 sf.pos=9983803;
 r = Vfile;
 e->topFrame = sf.prev;
 return r;
}
Zfo YiBkfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
Tr YiBk(Tc *AfileName, Tb Atruncate) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 Tr Vfile = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YiBkfo[0].off = (void*)&sf - (void*)&AfileName;
  YiBkfo[1].off = (void*)&sf - (void*)&Vfile;
 }
 sf.frof = YiBkfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8158000;
 {
  int flags = O_WRONLY|O_CREAT;
  if (Atruncate) flags |= O_TRUNC;
  int fnr = open(ZgetCstring(AfileName), flags, 0666);
  if (fnr >= 0) {
   if (!Atruncate) lseek(fnr, 0, SEEK_END);
 sf.pos=8158001;
 Vfile = *Znao(&Vfile, ZaF(sizeof(Yw8L), ToYw8L, (Ts (*)(void*, Te))YSo_, 1), Yw8L__Yw8L_I_imt, 0);
 sf.pos=8158002;
   (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = fdopen(fnr, "w");
  }
 }
 sf.pos=8158003;
 r = Vfile;
 e->topFrame = sf.prev;
 return r;
}
Ts Yhx8() {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3736300;
 Vret = 1;
 sf.pos=3736301;
#if defined(__MINGW32__) || defined(_MSC_VER)
      {
        static int did_init = 0;
        if (did_init == 0) {
          WSADATA wsadata;
          did_init = 1;
          if (WSAStartup(MAKEWORD(1,1), &wsadata) == SOCKET_ERROR) {
            fprintf(stderr, "Error in WSAStartup()\n");
            Vret = 0;
          }
        }
      }
#endif
 sf.pos=3736302;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo YDJhfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YDJh(Tc *AfileName) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDJhfo[0].off = (void*)&sf - (void*)&AfileName;
  YDJhfo[1].off = (void*)&sf - (void*)&Vres;
 }
 sf.frof = YDJhfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=745100;
 Vres = ((Tc*)&Ya);
 sf.pos=745101;
 {
  off_t len, rlen, off;
  int fd = open(ZgetCstring(AfileName), O_RDONLY, 0);
  Tc *resp;
  if (fd < 0) {
 sf.pos=745102;
 YkuV(ZcS(((Tc*)&YroP), AfileName));
 sf.pos=745103;
  }
  len = lseek(fd, 0, SEEK_END);
  if (len < 0) {
   close(fd);
 sf.pos=745104;
 YkuV(ZcS(((Tc*)&Y47X), AfileName));
 sf.pos=745105;
  }
  if (lseek(fd, 0, SEEK_SET) < 0) {
   close(fd);
 sf.pos=745106;
 YkuV(ZcS(((Tc*)&Y9TS), AfileName));
 sf.pos=745107;
  }
 sf.pos=745108;
  resp = ZaNm(len + 1);
  off = 0;
  while (len > 0) {
   rlen = read(fd, (char *)resp + off, len);
   if (rlen <= 0) {
    close(fd);
 sf.pos=745109;
 YkuV(ZcS(((Tc*)&YLjK), AfileName));
 sf.pos=745110;
   }
   len -= rlen;
   off += rlen;
  }
  resp[off] = 0;
  close(fd);
 sf.pos=745111;
 Vres = NULL;
 sf.pos=745112;
  Vres = ZnewString(resp, (Ti)off);
  free(resp);
 }
 sf.pos=745113;
 r = Vres;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yvcufo[2] = {{0,(Tt*)&string__T},{0,0}};
Ts Yvcu(Tc *Atext) {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yvcufo[0].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yvcufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Yl0kfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ts Yl0k(Tc *Atext) {
 Ts Vret;
 Ti Vlen;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yl0kfo[0].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yl0kfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Ts Ylxt() {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vret = 0;
 sf.pos=4676100;
 if (fflush(stdout) == 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=4676101;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo YJqzafo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Ts YJqza(YjUM *t, Tc *Atext) {
 Ti Vlen;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJqzafo[0].off = (void*)&sf - (void*)&t;
  YJqzafo[1].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = YJqzafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Ye7fafo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Ts Ye7fa(YjUM *t, Ti Abyte) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ye7fafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Ye7fafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Yd3Rfo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Ti Yd3R(YjUM *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yd3Rfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yd3Rfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9533600;
  ZthrowThisNil();
 }
 sf.pos=9533601;
 r = t->VsLen;
 e->topFrame = sf.prev;
 return r;
}
Zfo YKJQfo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Ti YKJQ(YjUM *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YKJQfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YKJQfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3432400;
  ZthrowThisNil();
 }
 sf.pos=3432401;
 if ((t->VsLen == 0))
 {
  sf.pos=3432402;
  r = 0;
  rt = 1;
  goto Yx8n;
 }
 sf.pos=3432403;
 r = ZstringSize(YbNW(t));
Yx8n:
 e->topFrame = sf.prev;
 return r;
}
Zfo YbNWfo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Tc *YbNW(YjUM *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vr = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YbNWfo[0].off = (void*)&sf - (void*)&t;
  YbNWfo[1].off = (void*)&sf - (void*)&Vr;
 }
 sf.frof = YbNWfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YjUM__YHhZbfo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Ts YjUM__YHhZb(YjUM *t, Ti Anumber) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjUM__YHhZbfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjUM__YHhZbfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7200700;
  ZthrowThisNil();
 }
 sf.pos=7200701;
 r = YJqza(t, Zint2string(Anumber));
 e->topFrame = sf.prev;
 return r;
}
Zfo YjUM__Ydtifo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Ts YjUM__Ydti(YjUM *t, Ti Achar) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjUM__Ydtifo[0].off = (void*)&sf - (void*)&t;
  YjUM__Ydtifo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YjUM__Ydtifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YjUM__YRt7fo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Ts YjUM__YRt7(YjUM *t, Tc *Atext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YjUM__YRt7fo[0].off = (void*)&sf - (void*)&t;
  YjUM__YRt7fo[1].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = YjUM__YRt7fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
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
Tto YjUM__T = {390, (Tc*)&YE4c, YbNW, StrYjUM, YKJQ, 0, 0, 0, ToYjUM};
Zfo YpPEfo[2] = {{0,(Tt*)&string__T},{0,0}};
Tb YpPE(Tc *Aname) {
 Tb Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YpPEfo[0].off = (void*)&sf - (void*)&Aname;
 }
 sf.frof = YpPEfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vret = 0;
 sf.pos=1483200;
 struct stat st;
 if (stat(ZgetCstring(Aname), &st) == 0) {
  Vret = S_ISDIR(st.st_mode);
 }
 sf.pos=1483201;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo Y_3Kfo[2] = {{0,(Tt*)&string__T},{0,0}};
Tb Y_3K(Tc *Aname) {
 Ti Vv;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y_3Kfo[0].off = (void*)&sf - (void*)&Aname;
 }
 sf.frof = Y_3Kfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vv = 0;
 sf.pos=7387700;
 Vv = access(ZgetCstring(Aname), X_OK);
 sf.pos=7387701;
 r = (Vv == 0);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yb8Kfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ts Yb8K(Tc *AfileName) {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yb8Kfo[0].off = (void*)&sf - (void*)&AfileName;
 }
 sf.frof = Yb8Kfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vret = 0;
 sf.pos=7315000;
 if (unlink(ZgetCstring(AfileName)) == 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=7315001;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo Ycmifo[6] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tc *Ycmi(Tc *AexeName) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vexe = NULL;
 Tc *Vfname = NULL;
 Tl *Vdirectories = NULL;
 Tc *Vpath = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ycmifo[0].off = (void*)&sf - (void*)&AexeName;
  Ycmifo[1].off = (void*)&sf - (void*)&Vexe;
  Ycmifo[2].off = (void*)&sf - (void*)&Vfname;
  Ycmifo[3].off = (void*)&sf - (void*)&Vdirectories;
  Ycmifo[4].off = (void*)&sf - (void*)&Vpath;
 }
 sf.frof = Ycmifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
   Vdirectories = ZstringSplit(Vpath, ((Tc*)&Y6), 0);
   sf.pos=6497007;
#else
   sf.pos=6497008;
   Vdirectories = ZstringSplit(Vpath, ((Tc*)&Y5), 0);
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
   Vfname = Vexe;
   sf.pos=6497017;
#if defined(__MINGW32__) || defined(_MSC_VER)
   sf.pos=6497018;
   if ((!(Y_3K(Vfname)) && Y_3K(ZcS(Vfname, ((Tc*)&YpPR)))))
   {
    sf.pos=6497019;
    Vfname =  ZcS(Vfname, ((Tc*)&YpPR));
   }
   sf.pos=6497020;
#endif
  }
  else
  {
   sf.pos=6497021;
   Vfname = Yvnf(Vfname, 92, 47);
  }
 }
 sf.pos=6497022;
 r = YPjH(Vfname);
 e->topFrame = sf.prev;
 return r;
}
Zfo YDopfo[6] = {{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YDop(Tc *AexeName, Tl *Adirs) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tl *Zf1 = NULL;
 Tc *Vdir = NULL;
 Tc *Vfname = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YDopfo[0].off = (void*)&sf - (void*)&Adirs;
  YDopfo[1].off = (void*)&sf - (void*)&AexeName;
  YDopfo[2].off = (void*)&sf - (void*)&Zf1;
  YDopfo[3].off = (void*)&sf - (void*)&Vdir;
  YDopfo[4].off = (void*)&sf - (void*)&Vfname;
 }
 sf.frof = YDopfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo Yr6Ofo[4] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *Yr6O(Tc *AexeName, Tc *AnewName) {
 Ti VtailIdx;
 Ti VdotIndex;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vresult = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yr6Ofo[0].off = (void*)&sf - (void*)&AnewName;
  Yr6Ofo[1].off = (void*)&sf - (void*)&AexeName;
  Yr6Ofo[2].off = (void*)&sf - (void*)&Vresult;
 }
 sf.frof = Yr6Ofo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=2890200;
 VtailIdx = Yr30(AexeName);
 sf.pos=2890201;
 Vresult = (((VtailIdx > 0)) ? (ZstringSlice(AexeName, 0, (VtailIdx - 1), 0)) : (((Tc*)&Ya)));
 sf.pos=2890202;
 Vresult =  ZcS(Vresult, AnewName);
 sf.pos=2890203;
 VdotIndex = ZstringFindLastChar(AexeName, 46, 0);
 sf.pos=2890204;
 if ((VdotIndex > VtailIdx))
 {
  sf.pos=2890205;
  Vresult =  ZcS(Vresult, ZstringSlice(AexeName, VdotIndex, -1, 0));
 }
 sf.pos=2890206;
 r = Vresult;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yq8afo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *Yq8a(Tc *Afirst, Tc *Asecond) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yq8afo[0].off = (void*)&sf - (void*)&Afirst;
  Yq8afo[1].off = (void*)&sf - (void*)&Asecond;
 }
 sf.frof = Yq8afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6830400;
 if (ZstringEndsWith(Afirst, ((Tc*)&YV), 0))
 {
  sf.pos=6830401;
  if (ZstringStartsWith(Asecond, ((Tc*)&YV), 0))
  {
   sf.pos=6830402;
   r = ZcS(Afirst, ZstringSlice(Asecond, 1, -1, 0));
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
 r = ZcS3(Afirst, ((Tc*)&YV), Asecond);
YSGC:
 e->topFrame = sf.prev;
 return r;
}
Zfo Y2wMfo[4] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *Y2wM(Tc *Afname) {
 Ts Vretval;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vdir = NULL;
 Tc *VnewFname = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Y2wMfo[0].off = (void*)&sf - (void*)&Afname;
  Y2wMfo[1].off = (void*)&sf - (void*)&Vdir;
  Y2wMfo[2].off = (void*)&sf - (void*)&VnewFname;
 }
 sf.frof = Y2wMfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YPjHfo[5] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YPjH(Tc *Afname) {
 Ti Vlimit;
 Tb VisRelative;
 Tb VhasTrailingSep;
 Ti Vi;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vresult = NULL;
 Tc *Vlink = NULL;
 Tc *Vremain = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YPjHfo[0].off = (void*)&sf - (void*)&Afname;
  YPjHfo[1].off = (void*)&sf - (void*)&Vresult;
  YPjHfo[2].off = (void*)&sf - (void*)&Vlink;
  YPjHfo[3].off = (void*)&sf - (void*)&Vremain;
 }
 sf.frof = YPjHfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
  Vresult = ZstringSlice(Afname, 0, (Vi - 2), 0);
  sf.pos=4533109;
  Vremain = ZstringSlice(Afname, (Vi - 1), -1, 0);
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
     Vremain = ZstringSlice(Vlink, (Vi - 1), -1, 0);
    }
    else
    {
     sf.pos=4533124;
     Vremain = ZcS(ZstringSlice(Vlink, (Vi - 1), -1, 0), Vremain);
    }
    sf.pos=4533125;
    Vlink = ZstringSlice(Vlink, 0, (Vi - 2), 0);
   }
   sf.pos=4533126;
   Vt = Yr30(Vresult);
   sf.pos=4533127;
   if (((Vt > 0) && (Vt == ZstringSize(Vresult))))
   {
    sf.pos=4533128;
    Vresult = ZstringSlice(Vresult, 0, -2, 0);
    sf.pos=4533129;
    Vt = Yr30(Vresult);
   }
   sf.pos=4533130;
   if (((Vt > 0) && (YEpA(Vlink) == 0)))
   {
    sf.pos=4533131;
    Vresult = ZcS(ZstringSlice(Vresult, 0, (Vt - 1), 0), Vlink);
   }
   else
   {
    sf.pos=4533132;
    Vresult = ZcS(Vlink, ((Tc*)&Ya));
   }
Yu7Z:
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
   Vresult =  ZcS(Vresult, ZstringSlice(Vremain, 0, (Vi - 2), 0));
   sf.pos=4533138;
   Vremain = ZstringSlice(Vremain, (Vi - 1), -1, 0);
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
    Vresult = ZstringSlice(Vresult, Vi, -1, 0);
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
   Vresult = ZstringSlice(Vresult, 0, -2, 0);
  sf.pos=4533156;
  }
 }
 sf.pos=4533157;
#endif
 sf.pos=4533158;
 r = Vresult;
YQMx:
 e->topFrame = sf.prev;
 return r;
}
Zfo Yr30fo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti Yr30(Tc *Afname) {
 Ti Vi;
 Ti Vj;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yr30fo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = Yr30fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Zfo YEpAfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti YEpA(Tc *Afname) {
 Ti Vi;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEpAfo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = YEpAfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
Tb Yhu2(Ti Ac) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7913600;
 r = (Ac == 47);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y26Nfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti Y26N(Tc *Afname, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Y26Nfo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = Y26Nfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
int JIOModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
  if (round == 0) {
   sf.pos=745200;
   Y59X = Yd89();
   sf.pos=745201;
   Yb0q = Yvyt();
   sf.pos=745202;
   YeNQ = YsM3();
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* IOModule done */
/* including THREADModule bodies */
/* including Config bodies */
int JConfig(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 if (round == 1) {
   sf.pos=2239800;
   Y4fD = YttT(NULL, ((Tc*)&YYa), ((Tc*)&Yef1), 0, ((Tc*)&YtSW));
   sf.pos=2239803;
   Y6Gp = ((YzqH *)Znio(2, 2239802, (YzqH__Y836(YBtk(NULL, NULL, ((Tc*)&YsHb), ((Tc*)&YsHb), ((Tc*)&YhxU)), ((Tc*)&YeLO)))));
   sf.pos=2239804;
   YJ5o = YBtk(NULL, NULL, ((Tc*)&YApf), ((Tc*)&YXja), ((Tc*)&Yl1G));
   sf.pos=2239805;
   Y6ma = YBtk(NULL, NULL, ((Tc*)&Yerz), ((Tc*)&Ya), ((Tc*)&YTzz));
   sf.pos=2239806;
   YMSZ = YttT(NULL, NULL, ((Tc*)&Y_e2), 0, ((Tc*)&Yslo));
  }
 if (round == 2001) {
   sf.pos=2239801;
   YEPH = YHoR(Y4fD);
   sf.pos=2239807;
   YSaE = YHoR(YMSZ);
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* Config done */
Zfo YgC4__YwtA__YRHRfo[3] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&string__T},{0,0}};
YgC4 *YgC4__YwtA__YRHR(YgC4 *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YgC4__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9798500; t = Za(sizeof(YgC4));}
 sf.pos=9798501;
 t->Vmessage = Amsg;
 sf.pos=9798502;
 t->Vpos = MZ__callerPos();
 sf.pos=9798503;
 t->Vbacktrace = (sf.pos=9798504, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YgC4__YwtA__YH0Vfo[4] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YgC4__YwtA__YH0V(YgC4 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YgC4__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YgC4__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3380500;
  ZthrowThisNil();
 }
 sf.pos=3380501;
 Vw = Za(sizeof(YjUM));
 sf.pos=3380502;
 YgC4__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=3380503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YgC4__YwtA__Yowwfo[4] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YgC4__YwtA__Yoww(YgC4 *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YgC4__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YgC4__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8606100;
  ZthrowThisNil();
 }
 sf.pos=8606101;
 Vw = Za(sizeof(YjUM));
 sf.pos=8606102;
 YgC4__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8606103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YgC4__YwtA__YxaJafo[5] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YgC4__YwtA__YxaJa(YgC4 *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YgC4__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YgC4__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YgC4__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=705100;
  ZthrowThisNil();
 }
 sf.pos=705101;
 YgC4__YwtA__YxaJ(t, Aw);
 sf.pos=705102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=705103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=705104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=705105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=705106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=705107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=705108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=705109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=705110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=705111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=705112;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YgC4__YwtA__YxaJfo[3] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&iobj__T},{0,0}};
void YgC4__YwtA__YxaJ(YgC4 *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YgC4__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1725200;
  ZthrowThisNil();
 }
 sf.pos=1725201;
 if ((t->Vpos != NULL))
 {
  sf.pos=1725202;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1725203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1725204;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1725205;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1725206;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1725207;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YgC4__Ytlm_I_imt[] = {
 (Tc*)&YgC4__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MTHREADModule__CE_Thread.NEW - YgC4__YwtA__YRHRa */
 (Tc*)YgC4__YwtA__YRHR, /* MTHREADModule__CE_Thread.NEW - YgC4__YwtA__YRHR */
 (Tc*)YgC4__YwtA__YH0V, /* MTHREADModule__CE_Thread.ToString - YgC4__YwtA__YH0V */
 (Tc*)YgC4__YwtA__YxaJa, /* MTHREADModule__CE_Thread.writeTo - YgC4__YwtA__YxaJa */
 (Tc*)YgC4__YwtA__YxaJ, /* MTHREADModule__CE_Thread.writeTo - YgC4__YwtA__YxaJ */
 (Tc*)YgC4__YwtA__Yoww, /* MTHREADModule__CE_Thread.toString - YgC4__YwtA__Yoww */
 (Tc*)0, /* MTHREADModule__CE_Thread.getMessage - YgC4__YwtA__YCzX */
 (Tc*)0, /* MTHREADModule__CE_Thread.getPos - YgC4__YwtA__YvCK */
 (Tc*)0, /* MTHREADModule__CE_Thread.getBacktrace - YgC4__YwtA__Y4bq */
 (Tc*)0, /* Init - YgC4a */
};
To ToYgC4[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYgC4[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YgC4__T = {390, (Tc*)&Yvlp, YgC4__YwtA__YH0V, StrYgC4, 0, 0, 0, 0, ToYgC4};
Zfo YTgs__Y2Czfo[2] = {{0,(Tt*)&YTgs__T},{0,0}};
Ts YTgs__Y2Cz(YTgs *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTgs__Y2Czfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YTgs__Y2Czfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8452100;
  ZthrowThisNil();
 }
 sf.pos=8452101;
 pthread_detach(t->Vthread_id);
 sf.pos=8452102;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
To ToYTgs[] = {
 {3, 0},
 {0, (Tt*)&cb__T}, /* proc */
 {0, (Tt*)&MTHREADModule__EState__T}, /* state */
 {0, (Tt*)&list__T}, /* stack */
};
char *StrYTgs[] = {
 "proc",
 "state",
 "stack",
};
Tto YTgs__T = {390, (Tc*)&YnY0, 0, StrYTgs, 0, YTgs__Y2Cz, 0, 0, ToYTgs};
Zfo YCylfo[2] = {{0,(Tt*)&YlXt__T},{0,0}};
YlXt *YCyl(YlXt *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YCylfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YCylfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=5342800; t = ZaF(sizeof(YlXt), ToYlXt, (Ts (*)(void*, Te))YMFu, 0);}
 sf.pos=5342801;
 pthread_mutex_init(&t->Vmutex, NULL);
 e->topFrame = sf.prev;
 return t;
}
Zfo YHl9fo[2] = {{0,(Tt*)&YlXt__T},{0,0}};
void YHl9(YlXt *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YHl9fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YHl9fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=765100;
  ZthrowThisNil();
 }
 sf.pos=765101;
 pthread_mutex_lock(&t->Vmutex);
 e->topFrame = sf.prev;
 return;
}
Zfo Yvoofo[2] = {{0,(Tt*)&YlXt__T},{0,0}};
void Yvoo(YlXt *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yvoofo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yvoofo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1760500;
  ZthrowThisNil();
 }
 sf.pos=1760501;
 pthread_mutex_unlock(&t->Vmutex);
 e->topFrame = sf.prev;
 return;
}
Zfo YMFufo[2] = {{0,(Tt*)&YlXt__T},{0,0}};
Ts YMFu(YlXt *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YMFufo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YMFufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8011100;
  ZthrowThisNil();
 }
 sf.pos=8011101;
 pthread_mutex_destroy(&t->Vmutex);
 sf.pos=8011102;
 r = 1;
 if (r) t->fok |= FOK_OK;
 e->topFrame = sf.prev;
 return r;
}
To ToYlXt[] = {
 {0, 0},
};
char *StrYlXt[] = {
};
Tto YlXt__T = {390, (Tc*)&YzBS, 0, StrYlXt, 0, YMFu, 0, 0, ToYlXt};
Zfo YXGLfo[2] = {{0,(Tt*)&Y0Wo__T},{0,0}};
Y0Wo *YXGL(Y0Wo *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXGLfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YXGLfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6882300; t = Za(sizeof(Y0Wo));}
 sf.pos=6882301;
 pthread_cond_init(&t->Vcond, NULL);
 e->topFrame = sf.prev;
 return t;
}
Zfo YjFjfo[2] = {{0,(Tt*)&Y0Wo__T},{0,0}};
void YjFj(Y0Wo *t, Tb Aall) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjFjfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjFjfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=108200;
  ZthrowThisNil();
 }
 sf.pos=108201;
 if (Aall)
  pthread_cond_broadcast(&t->Vcond);
 else
  pthread_cond_signal(&t->Vcond);
 e->topFrame = sf.prev;
 return;
}
Zfo YN6afo[3] = {{0,(Tt*)&Y0Wo__T},{0,(Tt*)&YlXt__T},{0,0}};
void YN6a(Y0Wo *t, YlXt *Alock) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YN6afo[0].off = (void*)&sf - (void*)&t;
  YN6afo[1].off = (void*)&sf - (void*)&Alock;
 }
 sf.frof = YN6afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7373400;
  ZthrowThisNil();
 }
 sf.pos=7373401;
 pthread_cond_wait(&t->Vcond, &Alock->Vmutex);
 e->topFrame = sf.prev;
 return;
}
To ToY0Wo[] = {
 {0, 0},
};
char *StrY0Wo[] = {
};
Tto Y0Wo__T = {390, (Tc*)&YeBN, 0, StrY0Wo, 0, 0, 0, 0, ToY0Wo};
int JTHREADModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 done &= JConfig(round);
  if (round == 0) {
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* THREADModule done */
/* including ZWTModule bodies */
Zfo Y1DXfo[13] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&Y1QG__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YX8j__T},{0,(Tt*)&string__T},{0,(Tt*)&YIgO__T},{0,(Tt*)&iobj__T},{0,0}};
void Y1DX(Y1QG *Aserver, Tc *Apath, Tc *Atitle, Tt *AmoduleType) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *Vleader = NULL;
 Tc *Vmiddle = NULL;
 Tc *Vfooter = NULL;
 Tc *VjsName = NULL;
 Tc *VjsPath = NULL;
 YX8j *Vfs = 0;
 Tc *Vhtml = NULL;
 YIgO *Vss = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1DXfo[0].off = (void*)&sf - (void*)&Apath;
  Y1DXfo[1].off = (void*)&sf - (void*)&Atitle;
  Y1DXfo[2].off = (void*)&sf - (void*)&Aserver;
  Y1DXfo[3].off = (void*)&sf - (void*)&Vleader;
  Y1DXfo[4].off = (void*)&sf - (void*)&Vmiddle;
  Y1DXfo[5].off = (void*)&sf - (void*)&Vfooter;
  Y1DXfo[6].off = (void*)&sf - (void*)&VjsName;
  Y1DXfo[7].off = (void*)&sf - (void*)&VjsPath;
  Y1DXfo[8].off = (void*)&sf - (void*)&Vfs;
  Y1DXfo[9].off = (void*)&sf - (void*)&Vhtml;
  Y1DXfo[10].off = (void*)&sf - (void*)&Vss;
  Y1DXfo[11].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1DXfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4382500;
 Vleader = ((Tc*)&Y4gy);
 sf.pos=4382501;
 Vmiddle = ((Tc*)&Y4Rk);
 sf.pos=4382502;
 Vfooter = ((Tc*)&YN_2);
 sf.pos=4382503;
 VjsName = ZcS(ZtypeName(AmoduleType), ((Tc*)&Y1zY));
 sf.pos=4382504;
 VjsPath = ((Tc*)&Ya);
 sf.pos=4382505;
 Vfs = Yb5K(NULL, ZcS(VjsPath, VjsName));
 sf.pos=4382506;
 YX8j__Y3fn(Vfs, ZcS(((Tc*)&YV), VjsName));
 sf.pos=4382507;
 Yb8i(Aserver, *Znao(&t0, Vfs, YX8j__YtrZ_I_imt, 1));
 sf.pos=4382508;
 Vhtml = ZcS3(Vleader, Atitle, Vmiddle);
 sf.pos=4382509;
 Vhtml =  ZcS(Vhtml, ZcS3(((Tc*)&YN), VjsName, ((Tc*)&YN)));
 sf.pos=4382510;
 Vhtml =  ZcS(Vhtml, Vfooter);
 sf.pos=4382511;
 Vss = Y543(NULL, Vhtml);
 sf.pos=4382512;
 YIgO__Y3fn(Vss, ZcS(((Tc*)&YV), Apath));
 sf.pos=4382513;
 Yb8i(Aserver, *Znao(&t0, Vss, YIgO__YtrZ_I_imt, 2));
 e->topFrame = sf.prev;
 return;
}
/* ZWTModule done */
/* including CHECKModule bodies */
void Y8UT(Tb Ab) {
 Tr t0 = {NULL};
 if (!(Ab))
 {
  Tr ex;
  *Znao(&ex, YtEE__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YG7w)), YtEE__Ytlm_I_imt, 8);
  ZthrowIobject(ex);
 }
 return;
}
/* CHECKModule done */
/* including ARGModule bodies */
Ts Ytu_() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6650100;
 r = (((Y6fX == NULL)) ? (0) : (1));
 e->topFrame = sf.prev;
 return r;
}
To ToYnU5[] = {
 {0, 0},
};
char *StrYnU5[] = {
};
Tto YnU5__T = {390, (Tc*)&Yr32, 0, StrYnU5, 0, 0, 0, 0, ToYnU5};
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
void YS39() {
 Tr t0 = {NULL};
 if ((Y6fX != NULL))
 {
  Tr ex;
  *Znao(&ex, YVNj__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YY2Q)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 return;
}
void YQtK() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7716400;
 Y2R7 = Ycmi(YzvW);
 e->topFrame = sf.prev;
 return;
}
Tc *YzHL() {
 Ti VtailIndex;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 int rt = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 r = ZstringSlice(Y2R7, 0, (VtailIndex - 2), 0);
Yt70:
 e->topFrame = sf.prev;
 return r;
}
Zfo YZH8fo[16] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&Y86c__T},{0,(Tt*)&Y86c__T},{0,(Tt*)&Y_SI__T},{0,(Tt*)&YJQu__T},{0,(Tt*)&YzqH__T},{0,(Tt*)&iobj__T},{0,0}};
void YZH8() {
 Tn *e = ZgetEnv();
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
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YZH8fo[0].off = (void*)&sf - (void*)&Varg;
  YZH8fo[1].off = (void*)&sf - (void*)&Vvalue;
  YZH8fo[2].off = (void*)&sf - (void*)&Vflagname;
  YZH8fo[3].off = (void*)&sf - (void*)&Vflagname1;
  YZH8fo[4].off = (void*)&sf - (void*)&Zf2;
  YZH8fo[5].off = (void*)&sf - (void*)&Vk;
  YZH8fo[6].off = (void*)&sf - (void*)&Zf21;
  YZH8fo[7].off = (void*)&sf - (void*)&Vk1;
  YZH8fo[8].off = (void*)&sf - (void*)&Vflag;
  YZH8fo[9].off = (void*)&sf - (void*)&Vbflag;
  YZH8fo[10].off = (void*)&sf - (void*)&Vbflag1;
  YZH8fo[11].off = (void*)&sf - (void*)&Vsflag;
  YZH8fo[12].off = (void*)&sf - (void*)&Viflag;
  YZH8fo[13].off = (void*)&sf - (void*)&Vsflag1;
  YZH8fo[14].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YZH8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YSUOfo[2] = {{0,(Tt*)&string__T},{0,0}};
void YSUO(Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSUOfo[0].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YSUOfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 Zexit(Ypp_a(NULL, ((Tc*)&Ye5Da), 456, 5), 1);
 e->topFrame = sf.prev;
 return;
}
Zfo Yfj5fo[12] = {{0,(Tt*)&dict__T},{0,(Tt*)&list__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,0}};
void Yfj5(Tb Averbose) {
 Ti VmaxLeadLen;
 Tn *e = ZgetEnv();
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
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yfj5fo[0].off = (void*)&sf - (void*)&VallFlags;
  Yfj5fo[1].off = (void*)&sf - (void*)&Zf1;
  Yfj5fo[2].off = (void*)&sf - (void*)&Zf2;
  Yfj5fo[3].off = (void*)&sf - (void*)&Vkey;
  Yfj5fo[4].off = (void*)&sf - (void*)&VargText;
  Yfj5fo[5].off = (void*)&sf - (void*)&Vlead;
  Yfj5fo[6].off = (void*)&sf - (void*)&Zf11;
  Yfj5fo[7].off = (void*)&sf - (void*)&Vkey1;
  Yfj5fo[8].off = (void*)&sf - (void*)&Vflag;
  Yfj5fo[9].off = (void*)&sf - (void*)&Vflag1;
  Yfj5fo[10].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yfj5fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 Zexit(Ypp_a(NULL, ((Tc*)&Ye5Da), 564, 5), YMLU);
 e->topFrame = sf.prev;
 return;
}
Zfo YTlufo[2] = {{0,(Tt*)&string__T},{0,0}};
void YTlu(Tc *Alead, Ti AmaxLeadLen) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTlufo[0].off = (void*)&sf - (void*)&Alead;
 }
 sf.frof = YTlufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return;
}
Zfo YAMWfo[4] = {{0,(Tt*)&YuMQ__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YAMW(YuMQ *t) {
 Ti Vidx;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YAMWfo[0].off = (void*)&sf - (void*)&t;
  YAMWfo[1].off = (void*)&sf - (void*)&t0;
  YAMWfo[2].off = (void*)&sf - (void*)&t1;
 }
 sf.frof = YAMWfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return r;
}
To ToYuMQ[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* text */
};
char *StrYuMQ[] = {
 "text",
};
Tto YuMQ__T = {390, (Tc*)&Y6qT, 0, StrYuMQ, 0, 0, 0, 0, ToYuMQ};
Zfo YttTfo[5] = {{0,(Tt*)&Y86c__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YttTfo[0].off = (void*)&sf - (void*)&t;
  YttTfo[1].off = (void*)&sf - (void*)&Adoc;
  YttTfo[2].off = (void*)&sf - (void*)&AshortName;
  YttTfo[3].off = (void*)&sf - (void*)&AlongName;
 }
 sf.frof = YttTfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=327300; t = Za(sizeof(Y86c));}
 sf.pos=327301;
 Y86c__YcLu(t, AshortName, AlongName, Adoc, MZ__callerPos());
 sf.pos=327302;
 t->Vcurrent = Adefault;
 sf.pos=327303;
 t->Vdefault = Adefault;
 sf.pos=327304;
 t->VcanRepeat = 1;
 e->topFrame = sf.prev;
 return t;
}
Zfo YEqoafo[2] = {{0,(Tt*)&Y86c__T},{0,0}};
void YEqoa(Y86c *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEqoafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YEqoafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3891100;
  ZthrowThisNil();
 }
 sf.pos=3891101;
 t->Vcurrent = t->Vdefault;
 e->topFrame = sf.prev;
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
Zfo Y86c__YcLufo[7] = {{0,(Tt*)&Y86c__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y86c__YcLufo[0].off = (void*)&sf - (void*)&t;
  Y86c__YcLufo[1].off = (void*)&sf - (void*)&Adoc;
  Y86c__YcLufo[2].off = (void*)&sf - (void*)&AshortName;
  Y86c__YcLufo[3].off = (void*)&sf - (void*)&Apos;
  Y86c__YcLufo[4].off = (void*)&sf - (void*)&AlongName;
  Y86c__YcLufo[5].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y86c__YcLufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 e->topFrame = sf.prev;
 return t;
}
Zfo Y86c__YofPfo[8] = {{0,(Tt*)&Y86c__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,0}};
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos) {
 void *Y_CE = NULL;
 void *p1;
 Tr ex;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y86c__YofPfo[0].off = (void*)&sf - (void*)&t;
  Y86c__YofPfo[1].off = (void*)&sf - (void*)&Aname;
  Y86c__YofPfo[2].off = (void*)&sf - (void*)&Aflag;
  Y86c__YofPfo[3].off = (void*)&sf - (void*)&Apos;
  Y86c__YofPfo[4].off = (void*)&sf - (void*)&VonePos;
  Y86c__YofPfo[5].off = (void*)&sf - (void*)&Ve;
  Y86c__YofPfo[6].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y86c__YofPfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
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
 (Tc*)0, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
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
Tto Y86c__T = {390, (Tc*)&YZ1F, 0, StrY86c, 0, 0, 0, 0, ToY86c};
Zfo Y4qxfo[5] = {{0,(Tt*)&YJQu__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
YJQu *Y4qx(YJQu *t, Tc *AshortName, Tc *AlongName, Ti Adefault, Tc *Adoc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y4qxfo[0].off = (void*)&sf - (void*)&t;
  Y4qxfo[1].off = (void*)&sf - (void*)&Adoc;
  Y4qxfo[2].off = (void*)&sf - (void*)&AshortName;
  Y4qxfo[3].off = (void*)&sf - (void*)&AlongName;
 }
 sf.frof = Y4qxfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=2966000; t = Za(sizeof(YJQu));}
 sf.pos=2966001;
 YJQu__YcLu(t, AshortName, AlongName, Adoc, MZ__callerPos());
 sf.pos=2966002;
 t->Vcurrent = Adefault;
 sf.pos=2966003;
 t->Vdefault = Adefault;
 sf.pos=2966004;
 t->VtheValueList = ZnewList((Tt*)&int__T, 0);
 e->topFrame = sf.prev;
 return t;
}
Zfo Y49gafo[2] = {{0,(Tt*)&YJQu__T},{0,0}};
void Y49ga(YJQu *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y49gafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y49gafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1635000;
  ZthrowThisNil();
 }
 sf.pos=1635001;
 t->Vcurrent = t->Vdefault;
 e->topFrame = sf.prev;
 return;
}
Ti YRvz(YJQu *t) {
 Ti r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->Vcurrent;
 return r;
}
Zfo Yl8rfo[2] = {{0,(Tt*)&YJQu__T},{0,0}};
Ti Yl8r(YJQu *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yl8rfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yl8rfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8767100;
  ZthrowThisNil();
 }
 sf.pos=8767101;
 r = YRvz(t);
 e->topFrame = sf.prev;
 return r;
}
Zfo YJQu__YcLufo[7] = {{0,(Tt*)&YJQu__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
YJQu *YJQu__YcLu(YJQu *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJQu__YcLufo[0].off = (void*)&sf - (void*)&t;
  YJQu__YcLufo[1].off = (void*)&sf - (void*)&Adoc;
  YJQu__YcLufo[2].off = (void*)&sf - (void*)&AshortName;
  YJQu__YcLufo[3].off = (void*)&sf - (void*)&Apos;
  YJQu__YcLufo[4].off = (void*)&sf - (void*)&AlongName;
  YJQu__YcLufo[5].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YJQu__YcLufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3107900; t = Za(sizeof(YJQu));}
 sf.pos=3107901;
 if ((Y6fX != NULL))
 {
  Tr ex;
  sf.pos=3107902;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Yc_h)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=3107903;
 if (((((AshortName == NULL) || (ZbyteStringSize(AshortName) == 0))) && (((AlongName == NULL) || (ZbyteStringSize(AlongName) == 0)))))
 {
  Tr ex;
  sf.pos=3107904;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y6pY)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=3107905;
 if ((ZbyteStringSize(AshortName) != 0))
 {
  sf.pos=3107906;
  t->VshortName = AshortName;
 }
 sf.pos=3107907;
 if ((ZbyteStringSize(AlongName) != 0))
 {
  sf.pos=3107908;
  t->VlongName = AlongName;
 }
 sf.pos=3107909;
 t->Vdoc = Adoc;
 sf.pos=3107910;
 if ((Y7be == NULL))
 {
  sf.pos=3107911;
  Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  sf.pos=3107912;
  YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
 }
 sf.pos=3107913;
 if (((AlongName != NULL) && (ZbyteStringSize(AlongName) != 0)))
 {
  sf.pos=3107914;
  if (ZDictHas(YBQy, (Tz)(void*)AlongName))
  {
   sf.pos=3107915;
   YJQu__YofP(t, AlongName, ZDictGetIobj(YBQy, (Tz)(void*)AlongName), Apos);
  }
  sf.pos=3107916;
  ZDictAddTzIobj(0, YBQy, (Tz)(void*)AlongName, *Znao(&t0, t, YJQu__YuQR_I_imt, 1));
 }
 sf.pos=3107917;
 if (((AshortName != NULL) && (ZbyteStringSize(AshortName) != 0)))
 {
  sf.pos=3107918;
  if ((ZstringSize(AshortName) > 1))
  {
   Tr ex;
   sf.pos=3107919;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y9CP)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=3107920;
  if (ZDictHas(Y7be, (Tz)(void*)AshortName))
  {
   sf.pos=3107921;
   YJQu__YofP(t, AshortName, ZDictGetIobj(Y7be, (Tz)(void*)AshortName), Apos);
  }
  sf.pos=3107922;
  ZDictAddTzIobj(0, Y7be, (Tz)(void*)AshortName, *Znao(&t0, t, YJQu__YuQR_I_imt, 1));
 }
 sf.pos=3107923;
 t->Vpos = Apos;
 e->topFrame = sf.prev;
 return t;
}
Zfo YJQu__YofPfo[8] = {{0,(Tt*)&YJQu__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,0}};
void YJQu__YofP(YJQu *t, Tc *Aname, Tr Aflag, YkxB *Apos) {
 void *Y8_j = NULL;
 void *p2;
 Tr ex;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJQu__YofPfo[0].off = (void*)&sf - (void*)&t;
  YJQu__YofPfo[1].off = (void*)&sf - (void*)&Aname;
  YJQu__YofPfo[2].off = (void*)&sf - (void*)&Aflag;
  YJQu__YofPfo[3].off = (void*)&sf - (void*)&Apos;
  YJQu__YofPfo[4].off = (void*)&sf - (void*)&VonePos;
  YJQu__YofPfo[5].off = (void*)&sf - (void*)&Ve;
  YJQu__YofPfo[6].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YJQu__YofPfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=132000;
  ZthrowThisNil();
 }
 sf.pos=132001;
 VonePos = ((p2 = ((Y8_j = (*(YkxB**)(Aflag.ptr + (size_t)Aflag.table[9])), Y8_j == NULL ? NULL : YpI_(Y8_j)))) == NULL ? (((Tc*)&YbbH)) : p2);
 sf.pos=132002;
 Ve = YVNj__YwtA__YRHRa(NULL, Apos, ZcS5(((Tc*)&YtzG), Aname, ((Tc*)&YDyy), VonePos, (Tc*)1));
 sf.pos=132003;
 *Znao(&ex, Ve, YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Tc *YJQu__YuQR_I_imt[] = {
 (Tc*)&YJQu__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YJQu__YcLu, /* MARGModule__CInt.NEW - YJQu__YcLu */
 (Tc*)YJQu__YofP, /* MARGModule__CInt.throwDuplicate - YJQu__YofP */
 (Tc*)0, /* MARGModule__CInt.setArgName - YJQu__Y836 */
 (Tc*)0, /* MARGModule__CInt.disableCompact - YJQu__YJbb */
 (Tc*)0, /* MARGModule__CInt.optionalArg - YJQu__YxuH */
 (Tc*)0, /* MARGModule__CInt.presentCount - YJQu__Ye9f */
 (Tc*)0, /* MARGModule__CInt.present - YJQu__Y8Dq */
 (Tc*)Y49ga, /* MARGModule__CInt.setToDefault - Y49ga */
 (Tc*)0, /* Init - YJQua */
};
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
Tto YJQu__T = {390, (Tc*)&YzBa, 0, StrYJQu, 0, 0, 0, 0, ToYJQu};
Zfo YBtkfo[6] = {{0,(Tt*)&YzqH__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
YzqH *YBtk(YzqH *t, Tc *AshortName, Tc *AlongName, Tc *Adefault, Tc *Adoc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YBtkfo[0].off = (void*)&sf - (void*)&t;
  YBtkfo[1].off = (void*)&sf - (void*)&Adoc;
  YBtkfo[2].off = (void*)&sf - (void*)&AshortName;
  YBtkfo[3].off = (void*)&sf - (void*)&Adefault;
  YBtkfo[4].off = (void*)&sf - (void*)&AlongName;
 }
 sf.frof = YBtkfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8063600; t = Za(sizeof(YzqH));}
 sf.pos=8063601;
 YzqH__YcLu(t, AshortName, AlongName, Adoc, MZ__callerPos());
 sf.pos=8063602;
 t->Vcurrent = Adefault;
 sf.pos=8063603;
 t->Vdefault = Adefault;
 sf.pos=8063604;
 t->VtheValueList = ZnewList((Tt*)&string__T, 0);
 e->topFrame = sf.prev;
 return t;
}
Zfo YJazafo[2] = {{0,(Tt*)&YzqH__T},{0,0}};
void YJaza(YzqH *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJazafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YJazafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8620600;
  ZthrowThisNil();
 }
 sf.pos=8620601;
 t->Vcurrent = t->Vdefault;
 e->topFrame = sf.prev;
 return;
}
Zfo YzqH__YcLufo[7] = {{0,(Tt*)&YzqH__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
YzqH *YzqH__YcLu(YzqH *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzqH__YcLufo[0].off = (void*)&sf - (void*)&t;
  YzqH__YcLufo[1].off = (void*)&sf - (void*)&Adoc;
  YzqH__YcLufo[2].off = (void*)&sf - (void*)&AshortName;
  YzqH__YcLufo[3].off = (void*)&sf - (void*)&Apos;
  YzqH__YcLufo[4].off = (void*)&sf - (void*)&AlongName;
  YzqH__YcLufo[5].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzqH__YcLufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=483900; t = Za(sizeof(YzqH));}
 sf.pos=483901;
 if ((Y6fX != NULL))
 {
  Tr ex;
  sf.pos=483902;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Yc_h)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=483903;
 if (((((AshortName == NULL) || (ZbyteStringSize(AshortName) == 0))) && (((AlongName == NULL) || (ZbyteStringSize(AlongName) == 0)))))
 {
  Tr ex;
  sf.pos=483904;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y6pY)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=483905;
 if ((ZbyteStringSize(AshortName) != 0))
 {
  sf.pos=483906;
  t->VshortName = AshortName;
 }
 sf.pos=483907;
 if ((ZbyteStringSize(AlongName) != 0))
 {
  sf.pos=483908;
  t->VlongName = AlongName;
 }
 sf.pos=483909;
 t->Vdoc = Adoc;
 sf.pos=483910;
 if ((Y7be == NULL))
 {
  sf.pos=483911;
  Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  sf.pos=483912;
  YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
 }
 sf.pos=483913;
 if (((AlongName != NULL) && (ZbyteStringSize(AlongName) != 0)))
 {
  sf.pos=483914;
  if (ZDictHas(YBQy, (Tz)(void*)AlongName))
  {
   sf.pos=483915;
   YzqH__YofP(t, AlongName, ZDictGetIobj(YBQy, (Tz)(void*)AlongName), Apos);
  }
  sf.pos=483916;
  ZDictAddTzIobj(0, YBQy, (Tz)(void*)AlongName, *Znao(&t0, t, YzqH__YuQR_I_imt, 2));
 }
 sf.pos=483917;
 if (((AshortName != NULL) && (ZbyteStringSize(AshortName) != 0)))
 {
  sf.pos=483918;
  if ((ZstringSize(AshortName) > 1))
  {
   Tr ex;
   sf.pos=483919;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y9CP)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=483920;
  if (ZDictHas(Y7be, (Tz)(void*)AshortName))
  {
   sf.pos=483921;
   YzqH__YofP(t, AshortName, ZDictGetIobj(Y7be, (Tz)(void*)AshortName), Apos);
  }
  sf.pos=483922;
  ZDictAddTzIobj(0, Y7be, (Tz)(void*)AshortName, *Znao(&t0, t, YzqH__YuQR_I_imt, 2));
 }
 sf.pos=483923;
 t->Vpos = Apos;
 e->topFrame = sf.prev;
 return t;
}
Zfo YzqH__YofPfo[8] = {{0,(Tt*)&YzqH__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,0}};
void YzqH__YofP(YzqH *t, Tc *Aname, Tr Aflag, YkxB *Apos) {
 void *YVCw = NULL;
 void *p3;
 Tr ex;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzqH__YofPfo[0].off = (void*)&sf - (void*)&t;
  YzqH__YofPfo[1].off = (void*)&sf - (void*)&Aname;
  YzqH__YofPfo[2].off = (void*)&sf - (void*)&Aflag;
  YzqH__YofPfo[3].off = (void*)&sf - (void*)&Apos;
  YzqH__YofPfo[4].off = (void*)&sf - (void*)&VonePos;
  YzqH__YofPfo[5].off = (void*)&sf - (void*)&Ve;
  YzqH__YofPfo[6].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzqH__YofPfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5264800;
  ZthrowThisNil();
 }
 sf.pos=5264801;
 VonePos = ((p3 = ((YVCw = (*(YkxB**)(Aflag.ptr + (size_t)Aflag.table[9])), YVCw == NULL ? NULL : YpI_(YVCw)))) == NULL ? (((Tc*)&YbbH)) : p3);
 sf.pos=5264802;
 Ve = YVNj__YwtA__YRHRa(NULL, Apos, ZcS5(((Tc*)&YtzG), Aname, ((Tc*)&YDyy), VonePos, (Tc*)1));
 sf.pos=5264803;
 *Znao(&ex, Ve, YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Tr YzqH__Y836(YzqH *t, Tc *AargName) {
 Tr r = {NULL};
 Tr t0 = {NULL};
 if (t == NULL) {
   ZthrowThisNil();
 }
 YS39();
 t->VargName = AargName;
 r = *Znao(&t0, t, YzqH__YuQR_I_imt, 2);
 return r;
}
Tc *YzqH__YuQR_I_imt[] = {
 (Tc*)&YzqH__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YzqH__YcLu, /* MARGModule__CString.NEW - YzqH__YcLu */
 (Tc*)YzqH__YofP, /* MARGModule__CString.throwDuplicate - YzqH__YofP */
 (Tc*)YzqH__Y836, /* MARGModule__CString.setArgName - YzqH__Y836 */
 (Tc*)0, /* MARGModule__CString.disableCompact - YzqH__YJbb */
 (Tc*)0, /* MARGModule__CString.optionalArg - YzqH__YxuH */
 (Tc*)0, /* MARGModule__CString.presentCount - YzqH__Ye9f */
 (Tc*)0, /* MARGModule__CString.present - YzqH__Y8Dq */
 (Tc*)YJaza, /* MARGModule__CString.setToDefault - YJaza */
 (Tc*)0, /* Init - YzqHa */
};
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
Tto YzqH__T = {390, (Tc*)&YDAE, 0, StrYzqH, 0, 0, 0, 0, ToYzqH};
Zfo YSkKafo[2] = {{0,(Tt*)&Y_SI__T},{0,0}};
void YSkKa(Y_SI *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSkKafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YSkKafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6447800;
  ZthrowThisNil();
 }
 sf.pos=6447801;
 t->Vcurrent = t->Vdefault;
 e->topFrame = sf.prev;
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
Tto Y_SI__T = {390, (Tc*)&Ygf5, 0, StrY_SI, 0, 0, 0, 0, ToY_SI};
int JARGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
  if (round == 0) {
  done = 0;
  } else if (round > 2001) {
    if (Ytu___r == 0) {
      Ytu___r = Ytu_();
      done &= Ytu___r;
    }
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* ARGModule done */
/* including INTModule bodies */
Zfo YIUbafo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Tc *YIUba(Ti Athis, Ti AminSize) {
 Ti Vval;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YIUbafo[0].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YIUbafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=655000;
 Vval = Athis;
 sf.pos=655001;
 Vw = Za(sizeof(YjUM));
 sf.pos=655002;
 while ((Vval != 0))
 {
  Ti Vc;
  sf.pos=655003;
  Vc = (Vval & 15);
  sf.pos=655004;
  Vval = (Vval >> 4);
  sf.pos=655005;
  if ((Vval < 0))
  {
   sf.pos=655006;
   Vval = (Vval & 1152921504606846975UL);
  }
  sf.pos=655007;
  YjUM__Ydti(Vw, (*(Ti*)ZarrayPtr(YZEe, Vc)));
 sf.pos=655008;
 }
 sf.pos=655009;
 while ((YKJQ(Vw) < AminSize))
 {
  sf.pos=655010;
  YjUM__Ydti(Vw, 48);
 sf.pos=655011;
 }
 sf.pos=655012;
 r = YO0w(YbNW(Vw));
 e->topFrame = sf.prev;
 return r;
}
int JINTModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
  if (round == 0) {
   sf.pos=5263500;
   YZEe = ZnewArray((Tt*)&int__T, sizeof(Ti), 16); ((Ti*)(YZEe->ptr))[0] = (Ti)48; ((Ti*)(YZEe->ptr))[1] = (Ti)49; ((Ti*)(YZEe->ptr))[2] = (Ti)50; ((Ti*)(YZEe->ptr))[3] = (Ti)51; ((Ti*)(YZEe->ptr))[4] = (Ti)52; ((Ti*)(YZEe->ptr))[5] = (Ti)53; ((Ti*)(YZEe->ptr))[6] = (Ti)54; ((Ti*)(YZEe->ptr))[7] = (Ti)55; ((Ti*)(YZEe->ptr))[8] = (Ti)56; ((Ti*)(YZEe->ptr))[9] = (Ti)57; ((Ti*)(YZEe->ptr))[10] = (Ti)97; ((Ti*)(YZEe->ptr))[11] = (Ti)98; ((Ti*)(YZEe->ptr))[12] = (Ti)99; ((Ti*)(YZEe->ptr))[13] = (Ti)100; ((Ti*)(YZEe->ptr))[14] = (Ti)101; ((Ti*)(YZEe->ptr))[15] = (Ti)102;
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* INTModule done */
/* including liveDemoPage bodies */
/* including buildzimbu bodies */
Zfo YVL6fo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
YwcI *YVL6(YwcI *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVL6fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YVL6fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=5087300; t = Za(sizeof(YwcI));}
 e->topFrame = sf.prev;
 return t;
}
Tc *Yyyva(YwcI *t) {
 Tc *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((Tc*)&YcmU);
 return r;
}
Tc *YVmS(YwcI *t) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_code == NULL))
 {
  r = ((Tc*)&Ya);
  rt = 1;
  goto Y425;
 }
 r = t->Vf_code;
Y425:
 return r;
}
Tb YdWb(YwcI *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_code != NULL);
 return r;
}
Tc *Yl1pa(YwcI *t, Ti AfieldNr) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   r = t->Vf_code;
   rt = 1;
   goto YO4Y;
  }
YO4Y:
  if (rt) goto Y8ds;
 }
 r = ((Tc*)&Ya);
Y8ds:
 return r;
}
void YoSUa(YwcI *t, Ti AfieldNr, Tc *Avalue) {
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   t->Vf_code = Avalue;
    break;
  }
 }
 return;
}
Tb YgM2a(YwcI *t, Ti AfieldNr) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   r = YdWb(t);
   rt = 1;
   goto YAf5;
  }
YAf5:
  if (rt) goto Ynzr;
 }
 r = 0;
Ynzr:
 return r;
}
Tl *YM1ka(YwcI *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = Y7nh;
 return r;
}
Zfo Y1nsfo[4] = {{0,(Tt*)&YwcI__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,0}};
YwcI *Y1ns(YwcI *t, Tr Areader) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YwcI *r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1nsfo[0].off = (void*)&sf - (void*)&t;
  Y1nsfo[1].off = (void*)&sf - (void*)&Areader;
  Y1nsfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1nsfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2596900;
  ZthrowThisNil();
 }
 sf.pos=2596901;
 YsvG(*Znao(&t0, t, YwcI__YFL0_I_imt, 1), Y7nh, Areader);
 sf.pos=2596902;
 r = t;
 e->topFrame = sf.prev;
 return r;
}
Zfo YfT8fo[3] = {{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,0}};
Tr YfT8(Tr Areader) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YfT8fo[0].off = (void*)&sf - (void*)&Areader;
  YfT8fo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YfT8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3439200;
 r = *Znao(&t0, YyBl(Areader), YwcI__YFL0_I_imt, 1);
 e->topFrame = sf.prev;
 return r;
}
Zfo YyBlfo[3] = {{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,0}};
YwcI *YyBl(Tr Areader) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YwcI *r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YyBlfo[0].off = (void*)&sf - (void*)&Areader;
  YyBlfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YyBlfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6991500;
 r = Y1ns(YVL6(NULL), *Znao(&t0, YtIRa(NULL, Areader, 1), YBRp__YMd3_imt, 0));
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Y0zDfo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Ti YwcI__Y0zD(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Y0zDfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Y0zDfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7803700;
  ZthrowThisNil();
 }
 sf.pos=7803701;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Y0zDafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Ti YwcI__Y0zDa(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Y0zDafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Y0zDafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8823800;
  ZthrowThisNil();
 }
 sf.pos=8823801;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YytNfo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tc *YwcI__YytN(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YytNfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YytNfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2850200;
  ZthrowThisNil();
 }
 sf.pos=2850201;
 r = ((Tc*)&Ya);
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YytNafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tc *YwcI__YytNa(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YytNafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YytNafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3870300;
  ZthrowThisNil();
 }
 sf.pos=3870301;
 r = ((Tc*)&Ya);
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YGR8fo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Ti YwcI__YGR8(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YGR8fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YGR8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5642300;
  ZthrowThisNil();
 }
 sf.pos=5642301;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YGR8afo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Ti YwcI__YGR8a(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YGR8afo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YGR8afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6662400;
  ZthrowThisNil();
 }
 sf.pos=6662401;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YAAofo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Ti32 YwcI__YAAo(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YAAofo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YAAofo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8899600;
  ZthrowThisNil();
 }
 sf.pos=8899601;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YAAoafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Ti32 YwcI__YAAoa(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YAAoafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YAAoafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9919700;
  ZthrowThisNil();
 }
 sf.pos=9919701;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YRqVfo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tu YwcI__YRqV(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tu r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YRqVfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YRqVfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3752200;
  ZthrowThisNil();
 }
 sf.pos=3752201;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YRqVafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tu YwcI__YRqVa(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tu r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YRqVafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YRqVafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4772300;
  ZthrowThisNil();
 }
 sf.pos=4772301;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Y0tEfo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tu32 YwcI__Y0tE(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tu32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Y0tEfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Y0tEfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9715700;
  ZthrowThisNil();
 }
 sf.pos=9715701;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Y0tEafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tu32 YwcI__Y0tEa(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tu32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Y0tEafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Y0tEafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=735800;
  ZthrowThisNil();
 }
 sf.pos=735801;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Yyt7fo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tf32 YwcI__Yyt7(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Yyt7fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Yyt7fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6538600;
  ZthrowThisNil();
 }
 sf.pos=6538601;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Yyt7afo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tf32 YwcI__Yyt7a(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Yyt7afo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Yyt7afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7558700;
  ZthrowThisNil();
 }
 sf.pos=7558701;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Yybvfo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tf YwcI__Yybv(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Yybvfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Yybvfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1685500;
  ZthrowThisNil();
 }
 sf.pos=1685501;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Yybvafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tf YwcI__Yybva(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Yybvafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Yybvafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2705600;
  ZthrowThisNil();
 }
 sf.pos=2705601;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YGfzfo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tb YwcI__YGfz(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YGfzfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YGfzfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6977200;
  ZthrowThisNil();
 }
 sf.pos=6977201;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YGfzafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tb YwcI__YGfza(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YGfzafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YGfzafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7997300;
  ZthrowThisNil();
 }
 sf.pos=7997301;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YsRaafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tc *YwcI__YsRaa(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YsRaafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YsRaafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4667600;
  ZthrowThisNil();
 }
 sf.pos=4667601;
 r = ((Tc*)&Ya);
 e->topFrame = sf.prev;
 return r;
}
void YwcI__Y3p7(YwcI *t, Ti AfieldNr, Ti Avalue) {
}
void YwcI__YJHD(YwcI *t, Ti AfieldNr, Ti Avalue) {
}
void YwcI__YDqT(YwcI *t, Ti AfieldNr, Ti32 Avalue) {
}
void YwcI__YOAq(YwcI *t, Ti AfieldNr, Tu Avalue) {
}
void YwcI__YYD9(YwcI *t, Ti AfieldNr, Tu32 Avalue) {
}
void YwcI__YBjC(YwcI *t, Ti AfieldNr, Tf32 Avalue) {
}
void YwcI__Yvl0(YwcI *t, Ti AfieldNr, Tf Avalue) {
}
void YwcI__YJ52(YwcI *t, Ti AfieldNr, Tb Avalue) {
}
Zfo YwcI__Yo5yfo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tr YwcI__Yo5y(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Yo5yfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Yo5yfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5422100;
  ZthrowThisNil();
 }
 sf.pos=5422101;
 r = trZero;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Yo5yafo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Tr YwcI__Yo5ya(YwcI *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Yo5yafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__Yo5yafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6442200;
  ZthrowThisNil();
 }
 sf.pos=6442201;
 r = trZero;
 e->topFrame = sf.prev;
 return r;
}
void YwcI__YrW2(YwcI *t, Ti AfieldNr, Tr Am) {
}
void YwcI__Y0Dj(YwcI *t, Ti AfieldNr, Tr Am) {
}
Zfo YwcI__YUDNfo[2] = {{0,(Tt*)&YwcI__T},{0,0}};
Ti YwcI__YUDN(YwcI *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YUDNfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YwcI__YUDNfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3892200;
  ZthrowThisNil();
 }
 sf.pos=3892201;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YC5ifo[5] = {{0,(Tt*)&YwcI__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YwcI__YC5i(YwcI *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vwriter = 0;
 YLWE *VprotoWriter = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YC5ifo[0].off = (void*)&sf - (void*)&t;
  YwcI__YC5ifo[1].off = (void*)&sf - (void*)&Vwriter;
  YwcI__YC5ifo[2].off = (void*)&sf - (void*)&VprotoWriter;
  YwcI__YC5ifo[3].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YwcI__YC5ifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2372900;
  ZthrowThisNil();
 }
 sf.pos=2372901;
 Vwriter = Za(sizeof(YjUM));
 sf.pos=2372902;
 VprotoWriter = YrCUb(NULL, *Znao(&t0, Vwriter, YjUM__YdXi_imt, 2), ((Tc*)&Ya), 0);
 sf.pos=2372903;
 YP8Z(*Znao(&t0, t, YwcI__YFL0_I_imt, 1), VprotoWriter);
 sf.pos=2372904;
 r = YbNW(Vwriter);
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__Ymzafo[3] = {{0,(Tt*)&YwcI__T},{0,(Tt*)&iobj__T},{0,0}};
Tb YwcI__Ymza(YwcI *t, Ti AfieldNr, Te Aformat, Tr Areader) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__Ymzafo[0].off = (void*)&sf - (void*)&t;
  YwcI__Ymzafo[1].off = (void*)&sf - (void*)&Areader;
 }
 sf.frof = YwcI__Ymzafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5263900;
  ZthrowThisNil();
 }
 sf.pos=5263901;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YwcI__YgZkfo[5] = {{0,(Tt*)&YwcI__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&iobj__T},{0,0}};
void YwcI__YgZk(YwcI *t, Tr Awriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YLWE *VprotoWriter = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwcI__YgZkfo[0].off = (void*)&sf - (void*)&t;
  YwcI__YgZkfo[1].off = (void*)&sf - (void*)&Awriter;
  YwcI__YgZkfo[2].off = (void*)&sf - (void*)&VprotoWriter;
  YwcI__YgZkfo[3].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YwcI__YgZkfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1841400;
  ZthrowThisNil();
 }
 sf.pos=1841401;
 VprotoWriter = YrCUa(NULL, Awriter, 1);
 sf.pos=1841402;
 YigD(*Znao(&t0, t, YwcI__YFL0_I_imt, 1), VprotoWriter);
 e->topFrame = sf.prev;
 return;
}
Tc *YwcI__YFL0_I_imt[] = {
 (Tc*)&YwcI__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YgM2a, /* MLivedemo__CBuildRequest.hasField - YgM2a */
 (Tc*)Yyyva, /* MLivedemo__CBuildRequest.name - Yyyva */
 (Tc*)YwcI__Y0zDa, /* MLivedemo__CBuildRequest.enumGet - YwcI__Y0zDa */
 (Tc*)YwcI__Y0zD, /* MLivedemo__CBuildRequest.enumGet - YwcI__Y0zD */
 (Tc*)YwcI__YytNa, /* MLivedemo__CBuildRequest.enumNameGet - YwcI__YytNa */
 (Tc*)YwcI__YytN, /* MLivedemo__CBuildRequest.enumNameGet - YwcI__YytN */
 (Tc*)YwcI__YGR8a, /* MLivedemo__CBuildRequest.intGet - YwcI__YGR8a */
 (Tc*)YwcI__YGR8, /* MLivedemo__CBuildRequest.intGet - YwcI__YGR8 */
 (Tc*)YwcI__YAAoa, /* MLivedemo__CBuildRequest.int32Get - YwcI__YAAoa */
 (Tc*)YwcI__YAAo, /* MLivedemo__CBuildRequest.int32Get - YwcI__YAAo */
 (Tc*)YwcI__YRqVa, /* MLivedemo__CBuildRequest.uint64Get - YwcI__YRqVa */
 (Tc*)YwcI__YRqV, /* MLivedemo__CBuildRequest.uint64Get - YwcI__YRqV */
 (Tc*)YwcI__Y0tEa, /* MLivedemo__CBuildRequest.uint32Get - YwcI__Y0tEa */
 (Tc*)YwcI__Y0tE, /* MLivedemo__CBuildRequest.uint32Get - YwcI__Y0tE */
 (Tc*)YwcI__Yyt7a, /* MLivedemo__CBuildRequest.floatGet - YwcI__Yyt7a */
 (Tc*)YwcI__Yyt7, /* MLivedemo__CBuildRequest.floatGet - YwcI__Yyt7 */
 (Tc*)YwcI__Yybva, /* MLivedemo__CBuildRequest.doubleGet - YwcI__Yybva */
 (Tc*)YwcI__Yybv, /* MLivedemo__CBuildRequest.doubleGet - YwcI__Yybv */
 (Tc*)YwcI__YGfza, /* MLivedemo__CBuildRequest.boolGet - YwcI__YGfza */
 (Tc*)YwcI__YGfz, /* MLivedemo__CBuildRequest.boolGet - YwcI__YGfz */
 (Tc*)YwcI__YsRaa, /* MLivedemo__CBuildRequest.stringGet - YwcI__YsRaa */
 (Tc*)Yl1pa, /* MLivedemo__CBuildRequest.stringGet - Yl1pa */
 (Tc*)YwcI__Y3p7, /* MLivedemo__CBuildRequest.enumSet - YwcI__Y3p7 */
 (Tc*)0, /* MLivedemo__CBuildRequest.enumNameSet - YwcI__YBjh */
 (Tc*)YwcI__YJHD, /* MLivedemo__CBuildRequest.intSet - YwcI__YJHD */
 (Tc*)YwcI__YDqT, /* MLivedemo__CBuildRequest.int32Set - YwcI__YDqT */
 (Tc*)YwcI__YOAq, /* MLivedemo__CBuildRequest.uint64Set - YwcI__YOAq */
 (Tc*)YwcI__YYD9, /* MLivedemo__CBuildRequest.uint32Set - YwcI__YYD9 */
 (Tc*)YwcI__YBjC, /* MLivedemo__CBuildRequest.floatSet - YwcI__YBjC */
 (Tc*)YwcI__Yvl0, /* MLivedemo__CBuildRequest.doubleSet - YwcI__Yvl0 */
 (Tc*)YwcI__YJ52, /* MLivedemo__CBuildRequest.boolSet - YwcI__YJ52 */
 (Tc*)YoSUa, /* MLivedemo__CBuildRequest.stringSet - YoSUa */
 (Tc*)YwcI__Yo5ya, /* MLivedemo__CBuildRequest.messageGet - YwcI__Yo5ya */
 (Tc*)YwcI__Yo5y, /* MLivedemo__CBuildRequest.messageGet - YwcI__Yo5y */
 (Tc*)YwcI__YrW2, /* MLivedemo__CBuildRequest.messageSet - YwcI__YrW2 */
 (Tc*)YwcI__Y0Dj, /* MLivedemo__CBuildRequest.messageAdd - YwcI__Y0Dj */
 (Tc*)YwcI__Ymza, /* MLivedemo__CBuildRequest.mergeMessageFromReader - YwcI__Ymza */
 (Tc*)YwcI__YUDN, /* MLivedemo__CBuildRequest.size - YwcI__YUDN */
 (Tc*)YM1ka, /* MLivedemo__CBuildRequest.fieldSpecs - YM1ka */
 (Tc*)YwcI__YC5i, /* MLivedemo__CBuildRequest.ToString - YwcI__YC5i */
 (Tc*)0, /* MLivedemo__CBuildRequest.toString - YwcI__YVAI */
 (Tc*)0, /* MLivedemo__CBuildRequest.writeText - YwcI__Yr3ca */
 (Tc*)0, /* MLivedemo__CBuildRequest.writeText - YwcI__Yr3c */
 (Tc*)0, /* MLivedemo__CBuildRequest.Equal - YwcI__YYdF */
 (Tc*)0, /* MLivedemo__CBuildRequest.writeBinary - YwcI__YpSR */
 (Tc*)0, /* MLivedemo__CBuildRequest.writeBinaryDeref - YwcI__Yz9e */
 (Tc*)0, /* MLivedemo__CBuildRequest.writeJson - YwcI__YVaR */
 (Tc*)YwcI__YgZk, /* MLivedemo__CBuildRequest.writeJsonDeref - YwcI__YgZk */
 (Tc*)0, /* Init - YwcIa */
};
To ToYwcI[] = {
 {5, 0},
 {0, (Tt*)&string__T}, /* f_code */
 {0, (Tt*)&int__T}, /* derefTime */
 {0, (Tt*)&int__T}, /* derefId */
 {0, (Tt*)&int__T}, /* derefTimeSize */
 {0, (Tt*)&int__T}, /* derefIdSize */
};
char *StrYwcI[] = {
 "f_code",
 "derefTime",
 "derefId",
 "derefTimeSize",
 "derefIdSize",
};
Tto YwcI__T = {390, (Tc*)&YcmU, YwcI__YC5i, StrYwcI, 0, 0, 0, 0, ToYwcI};
Zfo YDHyfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
YWgO *YDHy(YWgO *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDHyfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YDHyfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8993900; t = Za(sizeof(YWgO));}
 e->topFrame = sf.prev;
 return t;
}
Tc *YpCLa(YWgO *t) {
 Tc *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((Tc*)&Yg51);
 return r;
}
YWgO *Yg41(YWgO *t, Tc *Av) {
 YWgO *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_compilerMessages = Av;
 r = t;
 return r;
}
Tb Ydce(YWgO *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_compilerMessages != NULL);
 return r;
}
YWgO *YLBO(YWgO *t, Tc *Av) {
 YWgO *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_runOutput = Av;
 r = t;
 return r;
}
Tb YswH(YWgO *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_runOutput != NULL);
 return r;
}
Tc *YcNka(YWgO *t, Ti AfieldNr) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   r = t->Vf_compilerMessages;
   rt = 1;
   goto Y1hP;
  }
 case 2:
  {
   r = t->Vf_runOutput;
   rt = 1;
   goto Y1hP;
  }
Y1hP:
  if (rt) goto Y31N;
 }
 r = ((Tc*)&Ya);
Y31N:
 return r;
}
void YfDPa(YWgO *t, Ti AfieldNr, Tc *Avalue) {
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   t->Vf_compilerMessages = Avalue;
    break;
  }
 case 2:
  {
   t->Vf_runOutput = Avalue;
    break;
  }
 }
 return;
}
Tb YegVa(YWgO *t, Ti AfieldNr) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 switch (AfieldNr)
 {
 case 1:
  {
   r = Ydce(t);
   rt = 1;
   goto YTH_;
  }
 case 2:
  {
   r = YswH(t);
   rt = 1;
   goto YTH_;
  }
YTH_:
  if (rt) goto YRv7;
 }
 r = 0;
YRv7:
 return r;
}
Tl *YIg_a(YWgO *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = YKva;
 return r;
}
Zfo Yivyfo[2] = {{0,(Tt*)&iobj__T},{0,0}};
Tr Yivy() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yivyfo[0].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yivyfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=1098800;
 r = *Znao(&t0, YDHy(NULL), YWgO__YFL0_I_imt, 2);
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Y0zDfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Ti YWgO__Y0zD(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Y0zDfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Y0zDfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9938700;
  ZthrowThisNil();
 }
 sf.pos=9938701;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Y0zDafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Ti YWgO__Y0zDa(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Y0zDafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Y0zDafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=958800;
  ZthrowThisNil();
 }
 sf.pos=958801;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YytNfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tc *YWgO__YytN(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YytNfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YytNfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1494000;
  ZthrowThisNil();
 }
 sf.pos=1494001;
 r = ((Tc*)&Ya);
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YytNafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tc *YWgO__YytNa(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YytNafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YytNafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2514100;
  ZthrowThisNil();
 }
 sf.pos=2514101;
 r = ((Tc*)&Ya);
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YGR8fo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Ti YWgO__YGR8(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YGR8fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YGR8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4254900;
  ZthrowThisNil();
 }
 sf.pos=4254901;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YGR8afo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Ti YWgO__YGR8a(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YGR8afo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YGR8afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5275000;
  ZthrowThisNil();
 }
 sf.pos=5275001;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YAAofo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Ti32 YWgO__YAAo(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YAAofo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YAAofo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5171400;
  ZthrowThisNil();
 }
 sf.pos=5171401;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YAAoafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Ti32 YWgO__YAAoa(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YAAoafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YAAoafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6191500;
  ZthrowThisNil();
 }
 sf.pos=6191501;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YRqVfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tu YWgO__YRqV(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tu r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YRqVfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YRqVfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8173600;
  ZthrowThisNil();
 }
 sf.pos=8173601;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YRqVafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tu YWgO__YRqVa(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tu r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YRqVafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YRqVafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9193700;
  ZthrowThisNil();
 }
 sf.pos=9193701;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Y0tEfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tu32 YWgO__Y0tE(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tu32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Y0tEfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Y0tEfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4137100;
  ZthrowThisNil();
 }
 sf.pos=4137101;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Y0tEafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tu32 YWgO__Y0tEa(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tu32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Y0tEafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Y0tEafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5157200;
  ZthrowThisNil();
 }
 sf.pos=5157201;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Yyt7fo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tf32 YWgO__Yyt7(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Yyt7fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Yyt7fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2810400;
  ZthrowThisNil();
 }
 sf.pos=2810401;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Yyt7afo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tf32 YWgO__Yyt7a(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf32 r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Yyt7afo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Yyt7afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3830500;
  ZthrowThisNil();
 }
 sf.pos=3830501;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Yybvfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tf YWgO__Yybv(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Yybvfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Yybvfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=945300;
  ZthrowThisNil();
 }
 sf.pos=945301;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Yybvafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tf YWgO__Yybva(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tf r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Yybvafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Yybvafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1965400;
  ZthrowThisNil();
 }
 sf.pos=1965401;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YGfzfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tb YWgO__YGfz(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YGfzfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YGfzfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9112200;
  ZthrowThisNil();
 }
 sf.pos=9112201;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YGfzafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tb YWgO__YGfza(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YGfzafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YGfzafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=132300;
  ZthrowThisNil();
 }
 sf.pos=132301;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YsRaafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tc *YWgO__YsRaa(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YsRaafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YsRaafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9089000;
  ZthrowThisNil();
 }
 sf.pos=9089001;
 r = ((Tc*)&Ya);
 e->topFrame = sf.prev;
 return r;
}
void YWgO__Y3p7(YWgO *t, Ti AfieldNr, Ti Avalue) {
}
void YWgO__YJHD(YWgO *t, Ti AfieldNr, Ti Avalue) {
}
void YWgO__YDqT(YWgO *t, Ti AfieldNr, Ti32 Avalue) {
}
void YWgO__YOAq(YWgO *t, Ti AfieldNr, Tu Avalue) {
}
void YWgO__YYD9(YWgO *t, Ti AfieldNr, Tu32 Avalue) {
}
void YWgO__YBjC(YWgO *t, Ti AfieldNr, Tf32 Avalue) {
}
void YWgO__Yvl0(YWgO *t, Ti AfieldNr, Tf Avalue) {
}
void YWgO__YJ52(YWgO *t, Ti AfieldNr, Tb Avalue) {
}
Zfo YWgO__Yo5yfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tr YWgO__Yo5y(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Yo5yfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Yo5yfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2620300;
  ZthrowThisNil();
 }
 sf.pos=2620301;
 r = trZero;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Yo5yafo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Tr YWgO__Yo5ya(YWgO *t, Ti AfieldNr, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr r = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Yo5yafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__Yo5yafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3640400;
  ZthrowThisNil();
 }
 sf.pos=3640401;
 r = trZero;
 e->topFrame = sf.prev;
 return r;
}
void YWgO__YrW2(YWgO *t, Ti AfieldNr, Tr Am) {
}
void YWgO__Y0Dj(YWgO *t, Ti AfieldNr, Tr Am) {
}
Zfo YWgO__YUDNfo[2] = {{0,(Tt*)&YWgO__T},{0,0}};
Ti YWgO__YUDN(YWgO *t, Ti AfieldNr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YUDNfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWgO__YUDNfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5600800;
  ZthrowThisNil();
 }
 sf.pos=5600801;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YC5ifo[5] = {{0,(Tt*)&YWgO__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YWgO__YC5i(YWgO *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vwriter = 0;
 YLWE *VprotoWriter = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YC5ifo[0].off = (void*)&sf - (void*)&t;
  YWgO__YC5ifo[1].off = (void*)&sf - (void*)&Vwriter;
  YWgO__YC5ifo[2].off = (void*)&sf - (void*)&VprotoWriter;
  YWgO__YC5ifo[3].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YWgO__YC5ifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8644700;
  ZthrowThisNil();
 }
 sf.pos=8644701;
 Vwriter = Za(sizeof(YjUM));
 sf.pos=8644702;
 VprotoWriter = YrCUb(NULL, *Znao(&t0, Vwriter, YjUM__YdXi_imt, 2), ((Tc*)&Ya), 0);
 sf.pos=8644703;
 YP8Z(*Znao(&t0, t, YWgO__YFL0_I_imt, 2), VprotoWriter);
 sf.pos=8644704;
 r = YbNW(Vwriter);
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__Ymzafo[3] = {{0,(Tt*)&YWgO__T},{0,(Tt*)&iobj__T},{0,0}};
Tb YWgO__Ymza(YWgO *t, Ti AfieldNr, Te Aformat, Tr Areader) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__Ymzafo[0].off = (void*)&sf - (void*)&t;
  YWgO__Ymzafo[1].off = (void*)&sf - (void*)&Areader;
 }
 sf.frof = YWgO__Ymzafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3402900;
  ZthrowThisNil();
 }
 sf.pos=3402901;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
Zfo YWgO__YgZkfo[5] = {{0,(Tt*)&YWgO__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YLWE__T},{0,(Tt*)&iobj__T},{0,0}};
void YWgO__YgZk(YWgO *t, Tr Awriter) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YLWE *VprotoWriter = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWgO__YgZkfo[0].off = (void*)&sf - (void*)&t;
  YWgO__YgZkfo[1].off = (void*)&sf - (void*)&Awriter;
  YWgO__YgZkfo[2].off = (void*)&sf - (void*)&VprotoWriter;
  YWgO__YgZkfo[3].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YWgO__YgZkfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3817200;
  ZthrowThisNil();
 }
 sf.pos=3817201;
 VprotoWriter = YrCUa(NULL, Awriter, 1);
 sf.pos=3817202;
 YigD(*Znao(&t0, t, YWgO__YFL0_I_imt, 2), VprotoWriter);
 e->topFrame = sf.prev;
 return;
}
Tc *YWgO__YFL0_I_imt[] = {
 (Tc*)&YWgO__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YegVa, /* MLivedemo__CBuildResult.hasField - YegVa */
 (Tc*)YpCLa, /* MLivedemo__CBuildResult.name - YpCLa */
 (Tc*)YWgO__Y0zDa, /* MLivedemo__CBuildResult.enumGet - YWgO__Y0zDa */
 (Tc*)YWgO__Y0zD, /* MLivedemo__CBuildResult.enumGet - YWgO__Y0zD */
 (Tc*)YWgO__YytNa, /* MLivedemo__CBuildResult.enumNameGet - YWgO__YytNa */
 (Tc*)YWgO__YytN, /* MLivedemo__CBuildResult.enumNameGet - YWgO__YytN */
 (Tc*)YWgO__YGR8a, /* MLivedemo__CBuildResult.intGet - YWgO__YGR8a */
 (Tc*)YWgO__YGR8, /* MLivedemo__CBuildResult.intGet - YWgO__YGR8 */
 (Tc*)YWgO__YAAoa, /* MLivedemo__CBuildResult.int32Get - YWgO__YAAoa */
 (Tc*)YWgO__YAAo, /* MLivedemo__CBuildResult.int32Get - YWgO__YAAo */
 (Tc*)YWgO__YRqVa, /* MLivedemo__CBuildResult.uint64Get - YWgO__YRqVa */
 (Tc*)YWgO__YRqV, /* MLivedemo__CBuildResult.uint64Get - YWgO__YRqV */
 (Tc*)YWgO__Y0tEa, /* MLivedemo__CBuildResult.uint32Get - YWgO__Y0tEa */
 (Tc*)YWgO__Y0tE, /* MLivedemo__CBuildResult.uint32Get - YWgO__Y0tE */
 (Tc*)YWgO__Yyt7a, /* MLivedemo__CBuildResult.floatGet - YWgO__Yyt7a */
 (Tc*)YWgO__Yyt7, /* MLivedemo__CBuildResult.floatGet - YWgO__Yyt7 */
 (Tc*)YWgO__Yybva, /* MLivedemo__CBuildResult.doubleGet - YWgO__Yybva */
 (Tc*)YWgO__Yybv, /* MLivedemo__CBuildResult.doubleGet - YWgO__Yybv */
 (Tc*)YWgO__YGfza, /* MLivedemo__CBuildResult.boolGet - YWgO__YGfza */
 (Tc*)YWgO__YGfz, /* MLivedemo__CBuildResult.boolGet - YWgO__YGfz */
 (Tc*)YWgO__YsRaa, /* MLivedemo__CBuildResult.stringGet - YWgO__YsRaa */
 (Tc*)YcNka, /* MLivedemo__CBuildResult.stringGet - YcNka */
 (Tc*)YWgO__Y3p7, /* MLivedemo__CBuildResult.enumSet - YWgO__Y3p7 */
 (Tc*)0, /* MLivedemo__CBuildResult.enumNameSet - YWgO__YBjh */
 (Tc*)YWgO__YJHD, /* MLivedemo__CBuildResult.intSet - YWgO__YJHD */
 (Tc*)YWgO__YDqT, /* MLivedemo__CBuildResult.int32Set - YWgO__YDqT */
 (Tc*)YWgO__YOAq, /* MLivedemo__CBuildResult.uint64Set - YWgO__YOAq */
 (Tc*)YWgO__YYD9, /* MLivedemo__CBuildResult.uint32Set - YWgO__YYD9 */
 (Tc*)YWgO__YBjC, /* MLivedemo__CBuildResult.floatSet - YWgO__YBjC */
 (Tc*)YWgO__Yvl0, /* MLivedemo__CBuildResult.doubleSet - YWgO__Yvl0 */
 (Tc*)YWgO__YJ52, /* MLivedemo__CBuildResult.boolSet - YWgO__YJ52 */
 (Tc*)YfDPa, /* MLivedemo__CBuildResult.stringSet - YfDPa */
 (Tc*)YWgO__Yo5ya, /* MLivedemo__CBuildResult.messageGet - YWgO__Yo5ya */
 (Tc*)YWgO__Yo5y, /* MLivedemo__CBuildResult.messageGet - YWgO__Yo5y */
 (Tc*)YWgO__YrW2, /* MLivedemo__CBuildResult.messageSet - YWgO__YrW2 */
 (Tc*)YWgO__Y0Dj, /* MLivedemo__CBuildResult.messageAdd - YWgO__Y0Dj */
 (Tc*)YWgO__Ymza, /* MLivedemo__CBuildResult.mergeMessageFromReader - YWgO__Ymza */
 (Tc*)YWgO__YUDN, /* MLivedemo__CBuildResult.size - YWgO__YUDN */
 (Tc*)YIg_a, /* MLivedemo__CBuildResult.fieldSpecs - YIg_a */
 (Tc*)YWgO__YC5i, /* MLivedemo__CBuildResult.ToString - YWgO__YC5i */
 (Tc*)0, /* MLivedemo__CBuildResult.toString - YWgO__YVAI */
 (Tc*)0, /* MLivedemo__CBuildResult.writeText - YWgO__Yr3ca */
 (Tc*)0, /* MLivedemo__CBuildResult.writeText - YWgO__Yr3c */
 (Tc*)0, /* MLivedemo__CBuildResult.Equal - YWgO__YYdF */
 (Tc*)0, /* MLivedemo__CBuildResult.writeBinary - YWgO__YpSR */
 (Tc*)0, /* MLivedemo__CBuildResult.writeBinaryDeref - YWgO__Yz9e */
 (Tc*)0, /* MLivedemo__CBuildResult.writeJson - YWgO__YVaR */
 (Tc*)YWgO__YgZk, /* MLivedemo__CBuildResult.writeJsonDeref - YWgO__YgZk */
 (Tc*)0, /* Init - YWgOa */
};
To ToYWgO[] = {
 {6, 0},
 {0, (Tt*)&string__T}, /* f_compilerMessages */
 {0, (Tt*)&string__T}, /* f_runOutput */
 {0, (Tt*)&int__T}, /* derefTime */
 {0, (Tt*)&int__T}, /* derefId */
 {0, (Tt*)&int__T}, /* derefTimeSize */
 {0, (Tt*)&int__T}, /* derefIdSize */
};
char *StrYWgO[] = {
 "f_compilerMessages",
 "f_runOutput",
 "derefTime",
 "derefId",
 "derefTimeSize",
 "derefIdSize",
};
Tto YWgO__T = {390, (Tc*)&Yg51, YWgO__YC5i, StrYWgO, 0, 0, 0, 0, ToYWgO};
int Jbuildzimbu(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 if (round == 2001) {
   sf.pos=7472400;
   Y7nh = ZnewList((Tt*)&YqvM__T, 1); ZLap((Tl*)Y7nh, (Tz)(void*)Ykww(NULL, ((Tc*)&YI7D), 1, 17, 0));
   sf.pos=599800;
   YKva = ZnewList((Tt*)&YqvM__T, 2); ZLap((Tl*)YKva, (Tz)(void*)Ykww(NULL, ((Tc*)&YKTm), 1, 17, 0)); ZLap((Tl*)YKva, (Tz)(void*)Ykww(NULL, ((Tc*)&YPhm), 2, 17, 0));
   sf.pos=5520000;
   YgWI = YlyH(NULL, ((Tc*)&Yw36), (&ZCB_YfT8), (&ZCB_Yivy));
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* buildzimbu done */
int JliveDemoPage(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 done &= Jbuildzimbu(round);
 if (round == 2001) {
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* liveDemoPage done */
/* including BuildZimbuServlet bodies */
Zfo YwNWfo[3] = {{0,(Tt*)&YvG2__T},{0,(Tt*)&string__T},{0,0}};
YvG2 *YwNW(YvG2 *t, Tc *Adummy) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwNWfo[0].off = (void*)&sf - (void*)&t;
  YwNWfo[1].off = (void*)&sf - (void*)&Adummy;
 }
 sf.frof = YwNWfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=4728900; t = Za(sizeof(YvG2));}
 sf.pos=4728901;
 YvG2__Yk23(t);
 sf.pos=4728902;
 YvG2__YvI9(t, YgWI, (&ZCB_YXn8));
 e->topFrame = sf.prev;
 return t;
}
Zfo YXn8fo[26] = {{0,(Tt*)&YtzZ__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YwcI__T},{0,(Tt*)&YWgO__T},{0,(Tt*)&iobj__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YDTf__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Ts YXn8(YtzZ *Acontext, Tr ArequestArg, Tr AresponseArg) {
 Ti Vidx;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 Tc *Vdir = NULL;
 Tc *VdemoZuName = NULL;
 Tc *VdemoCompName = NULL;
 Tc *VdemoExeName = NULL;
 Tc *VzimbuExeName = NULL;
 YwcI *Vrequest = 0;
 YWgO *Vresponse = 0;
 Tr Vwriter = {NULL};
 Tc *Vargs = NULL;
 Tr Vreader = {NULL};
 Tc *Vmsg = NULL;
 Tc *Vkilled = NULL;
 Tc *VoutputFile = NULL;
 YDTf *Vproc = 0;
 Tl *Vlines = NULL;
 Tc *Voutput = NULL;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 Tc *t3 = NULL;
 Tc *t4 = NULL;
 Tc *t5 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXn8fo[0].off = (void*)&sf - (void*)&Acontext;
  YXn8fo[1].off = (void*)&sf - (void*)&ArequestArg;
  YXn8fo[2].off = (void*)&sf - (void*)&AresponseArg;
  YXn8fo[3].off = (void*)&sf - (void*)&Vdir;
  YXn8fo[4].off = (void*)&sf - (void*)&VdemoZuName;
  YXn8fo[5].off = (void*)&sf - (void*)&VdemoCompName;
  YXn8fo[6].off = (void*)&sf - (void*)&VdemoExeName;
  YXn8fo[7].off = (void*)&sf - (void*)&VzimbuExeName;
  YXn8fo[8].off = (void*)&sf - (void*)&Vrequest;
  YXn8fo[9].off = (void*)&sf - (void*)&Vresponse;
  YXn8fo[10].off = (void*)&sf - (void*)&Vwriter;
  YXn8fo[11].off = (void*)&sf - (void*)&Vargs;
  YXn8fo[12].off = (void*)&sf - (void*)&Vreader;
  YXn8fo[13].off = (void*)&sf - (void*)&Vmsg;
  YXn8fo[14].off = (void*)&sf - (void*)&Vkilled;
  YXn8fo[15].off = (void*)&sf - (void*)&VoutputFile;
  YXn8fo[16].off = (void*)&sf - (void*)&Vproc;
  YXn8fo[17].off = (void*)&sf - (void*)&Vlines;
  YXn8fo[18].off = (void*)&sf - (void*)&Voutput;
  YXn8fo[19].off = (void*)&sf - (void*)&t0;
  YXn8fo[20].off = (void*)&sf - (void*)&t1;
  YXn8fo[21].off = (void*)&sf - (void*)&t2;
  YXn8fo[22].off = (void*)&sf - (void*)&t3;
  YXn8fo[23].off = (void*)&sf - (void*)&t4;
  YXn8fo[24].off = (void*)&sf - (void*)&t5;
 }
 sf.frof = YXn8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7003500;
 Vdir = YzHL();
 sf.pos=7003501;
 VdemoZuName = ZcS(Vdir, ((Tc*)&Ypfm));
 sf.pos=7003502;
 VdemoCompName = ZcS(Vdir, ((Tc*)&YLPw));
 sf.pos=7003503;
 VdemoExeName = Yr6O(Y2R7, ((Tc*)&Y4em));
 sf.pos=7003504;
 VdemoExeName = Y2wM(VdemoExeName);
 sf.pos=7003505;
 VzimbuExeName = Yr6O(Y2R7, ((Tc*)&Ye5c));
 sf.pos=7003506;
 Vidx = Yr30(VzimbuExeName);
 sf.pos=7003507;
 VzimbuExeName = ZcS3(((((Vidx > 0)) ? (ZstringSlice(VzimbuExeName, 0, (Vidx - 1), 0)) : (((Tc*)&Ya)))), ((Tc*)&Y0y2), (t0 = ZstringSlice(VzimbuExeName, Vidx, -1, 0)));
 sf.pos=7003508;
 VzimbuExeName = Y2wM(VzimbuExeName);
 sf.pos=7003510;
 Vrequest = ((YwcI *)Znio(1, 7003509, (ArequestArg)));
 sf.pos=7003512;
 Vresponse = ((YWgO *)Znio(2, 7003511, (AresponseArg)));
 sf.pos=7003513;
 Vwriter = YiBk(VdemoZuName, 1);
 sf.pos=7003514;
 ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, YVmS(Vrequest));
 sf.pos=7003515;
 ((Ts (*)(void*, Tc*))(Vwriter.table[1]))(Vwriter.ptr, ((Tc*)&Yk));
 sf.pos=7003516;
 ((Ts (*)(void*))(Vwriter.table[35]))(Vwriter.ptr);
 sf.pos=7003517;
 Yb8K(VdemoExeName);
 sf.pos=7003518;
 if (YHoR(Y_vl))
 {
  sf.pos=7003519;
  Vargs = ((Tc*)&YGZd);
 }
 else {
 sf.pos=7003520;
 if (YHoR(YmKW))
 {
  sf.pos=7003521;
  Vargs = ((Tc*)&YxWT);
 }
 else
 {
  sf.pos=7003522;
  Vargs = ((Tc*)&Ya);
 }
 }
 sf.pos=7003523;
 YMso(ZcS8(VzimbuExeName, ((Tc*)&YG), (t0 = Vargs), ((Tc*)&YG), (t2 = VdemoZuName), ((Tc*)&YsZ), (t4 = VdemoCompName), (Tc*)1));
 sf.pos=7003524;
 Vreader = YsGz(VdemoCompName);
 sf.pos=7003525;
 Vmsg = ((Tc* (*)(void*))(Vreader.table[25]))(Vreader.ptr);
 sf.pos=7003526;
 ((Ts (*)(void*))(Vreader.table[35]))(Vreader.ptr);
 sf.pos=7003527;
 if ((ZbyteStringSize(Vmsg) == 0))
 {
  sf.pos=7003528;
  Vmsg = ((Tc*)&Y_xD);
 }
 sf.pos=7003529;
 Yg41(Vresponse, Vmsg);
 sf.pos=7003530;
 if (Y_3K(VdemoExeName))
 {
  sf.pos=7003531;
  Yl0k(((Tc*)&YVz0));
  sf.pos=7003532;
  Vkilled = ((Tc*)&Ya);
  sf.pos=7003533;
  VoutputFile = ZcS(Vdir, ((Tc*)&YWUH));
  sf.pos=7003534;
  Yb8K(VoutputFile);
  sf.pos=7003535;
  Vproc = YCLu(Y0ha(YkM8(YV43(NULL, VdemoExeName), VoutputFile), 1));
  sf.pos=7003536;
  if ((YJmKa(Vproc, 2000000) == 0))
  {
   sf.pos=7003537;
   Yl0k(((Tc*)&YZbl));
   sf.pos=7003538;
   YYXC(Vproc);
   sf.pos=7003539;
   Vkilled = ((Tc*)&Yz3Z);
  }
  sf.pos=7003540;
  Yl0k(((Tc*)&YOWR));
  sf.pos=7003541;
  Vreader = YsGz(VoutputFile);
  sf.pos=7003542;
  Vlines = ((Tl* (*)(void*, Ti))(Vreader.table[29]))(Vreader.ptr, 40);
  sf.pos=7003543;
  ((Ts (*)(void*))(Vreader.table[35]))(Vreader.ptr);
  sf.pos=7003544;
  Voutput = ZListJoinVal(Vlines, ((Tc*)&Yk), 0);
  sf.pos=7003545;
  if ((ZListSize(Vlines) >= 40))
  {
   sf.pos=7003546;
   Voutput =  ZcS(Voutput, ((Tc*)&YKiz));
  }
  sf.pos=7003547;
  Voutput =  ZcS(Voutput, Vkilled);
  sf.pos=7003548;
  if ((ZbyteStringSize(Voutput) == 0))
  {
   sf.pos=7003549;
   Voutput = ((Tc*)&YmWe);
  }
  sf.pos=7003550;
  YLBO(Vresponse, Voutput);
 }
 else
 {
  sf.pos=7003551;
  YLBO(Vresponse, ((Tc*)&Y2Mu));
 }
 sf.pos=7003552;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo YvG2__YntX__Y3fnfo[3] = {{0,(Tt*)&YvG2__T},{0,(Tt*)&string__T},{0,0}};
void YvG2__YntX__Y3fn(YvG2 *t, Tc *Apath) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YvG2__YntX__Y3fnfo[0].off = (void*)&sf - (void*)&t;
  YvG2__YntX__Y3fnfo[1].off = (void*)&sf - (void*)&Apath;
 }
 sf.frof = YvG2__YntX__Y3fnfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5180400;
  ZthrowThisNil();
 }
 sf.pos=5180401;
 if ((t->Vpaths == NULL))
 {
  sf.pos=5180402;
  t->Vpaths = ZnewList((Tt*)&string__T, 0);
 }
 sf.pos=5180403;
 ZLap((Tl*)t->Vpaths, (Tz)(void*)Apath);
 e->topFrame = sf.prev;
 return;
}
Zfo YvG2__YntX__YU_Wfo[5] = {{0,(Tt*)&YvG2__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tb YvG2__YntX__YU_W(YvG2 *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tl *Zf2 = NULL;
 Tc *Vp = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YvG2__YntX__YU_Wfo[0].off = (void*)&sf - (void*)&t;
  YvG2__YntX__YU_Wfo[1].off = (void*)&sf - (void*)&Acontext;
  YvG2__YntX__YU_Wfo[2].off = (void*)&sf - (void*)&Zf2;
  YvG2__YntX__YU_Wfo[3].off = (void*)&sf - (void*)&Vp;
 }
 sf.frof = YvG2__YntX__YU_Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6397800;
  ZthrowThisNil();
 }
 sf.pos=6397801;
 if ((t->Vpaths != NULL))
 {
  sf.pos=6397802;
  {
   Tfl Zf2i;
   Zf2 = t->Vpaths;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=6397803;
   if ((ZstringCmp(Vp, Acontext->Vrequest->Vpath) == 0))
   {
    sf.pos=6397804;
    if ((t->VmimeType != NULL))
    {
     sf.pos=6397805;
     YDSB(Acontext->Vresponse, t->VmimeType);
    }
    sf.pos=6397806;
    if (YvG2__Yk9ua(t, Acontext))
    {
     sf.pos=6397807;
     r = 1;
     rt = 1;
     goto YOmd;
    }
YOmd:
    if (rt) goto YReK;
   }
YReK:
   if (rt) goto YUfT;
   sf.pos=6397808;
   }
  }
YUfT:
  if (rt) goto YBYi;
 }
 sf.pos=6397809;
 r = 0;
YBYi:
 e->topFrame = sf.prev;
 return r;
}
Zfo YvG2__Yk23fo[2] = {{0,(Tt*)&YvG2__T},{0,0}};
void YvG2__Yk23(YvG2 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YvG2__Yk23fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YvG2__Yk23fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8132800;
  ZthrowThisNil();
 }
 sf.pos=8132801;
 t->Vname = ((Tc*)&Y103);
 sf.pos=8132802;
 YvG2__YntX__Y3fn(t, ((Tc*)&YvCv));
 sf.pos=8132803;
 t->Vservices = ZnewDict((Tt*)&string__T, (Tt*)&Yivg__T, 0);
 e->topFrame = sf.prev;
 return;
}
Zfo YvG2__YvI9fo[5] = {{0,(Tt*)&YvG2__T},{0,(Tt*)&YKxQ__T},{0,(Tt*)&cb__T},{0,(Tt*)&Yivg__T},{0,0}};
void YvG2__YvI9(YvG2 *t, YKxQ *ArpcInfo, Tcb *Ahandler) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Yivg *Vh = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YvG2__YvI9fo[0].off = (void*)&sf - (void*)&t;
  YvG2__YvI9fo[1].off = (void*)&sf - (void*)&ArpcInfo;
  YvG2__YvI9fo[2].off = (void*)&sf - (void*)&Ahandler;
  YvG2__YvI9fo[3].off = (void*)&sf - (void*)&Vh;
 }
 sf.frof = YvG2__YvI9fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=860700;
  ZthrowThisNil();
 }
 sf.pos=860701;
 if (ZDictHas(t->Vservices, (Tz)(void*)ArpcInfo->Vname))
 {
  void *ex = NULL;
  sf.pos=860702;
  ex = ZcS(((Tc*)&Ybeb), ArpcInfo->Vname);
  ZthrowPos(860703, ex);
 }
 sf.pos=860704;
 Vh = Za(sizeof(Yivg));
 sf.pos=860705;
 Vh->VrpcInfo = ArpcInfo;
 sf.pos=860706;
 Vh->Vhandler = Ahandler;
 sf.pos=860707;
 ZDictAdd(0, t->Vservices, (Tz)(void*)ArpcInfo->Vname, (Tz)(void*)Vh);
 e->topFrame = sf.prev;
 return;
}
Zfo YvG2__Yk9uafo[10] = {{0,(Tt*)&YvG2__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&YSM1__T},{0,(Tt*)&string__T},{0,(Tt*)&Yivg__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tb YvG2__Yk9ua(YvG2 *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 YSM1 *Vreq = 0;
 Tc *Vname = NULL;
 Yivg *Vh = 0;
 Tr Vrequest = {NULL};
 Tr Vresponse = {NULL};
 YjUM *Vwriter = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YvG2__Yk9uafo[0].off = (void*)&sf - (void*)&t;
  YvG2__Yk9uafo[1].off = (void*)&sf - (void*)&Acontext;
  YvG2__Yk9uafo[2].off = (void*)&sf - (void*)&Vreq;
  YvG2__Yk9uafo[3].off = (void*)&sf - (void*)&Vname;
  YvG2__Yk9uafo[4].off = (void*)&sf - (void*)&Vh;
  YvG2__Yk9uafo[5].off = (void*)&sf - (void*)&Vrequest;
  YvG2__Yk9uafo[6].off = (void*)&sf - (void*)&Vresponse;
  YvG2__Yk9uafo[7].off = (void*)&sf - (void*)&Vwriter;
  YvG2__Yk9uafo[8].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YvG2__Yk9uafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1866100;
  ZthrowThisNil();
 }
 sf.pos=1866101;
 Vreq = Acontext->Vrequest;
 sf.pos=1866102;
 if (ZDictHas(Yi2X(Vreq), (Tz)(void*)((Tc*)&Y4Po)))
 {
  sf.pos=1866103;
  Vname = ((Tc *)ZDictGetPtr(Yi2X(Vreq), (Tz)(void*)((Tc*)&Y4Po)));
  sf.pos=1866104;
  if (ZDictHas(t->Vservices, (Tz)(void*)Vname))
  {
   sf.pos=1866105;
   Vh = ((Yivg *)ZDictGetPtr(t->Vservices, (Tz)(void*)Vname));
   sf.pos=1866106;
   Vrequest = ((Tr (*)(Tcb *, Tr))Vh->VrpcInfo->VcreateFromJson->cfunc)(Vh->VrpcInfo->VcreateFromJson, *Znao(&t0, YOD2(NULL, ZbyteStringCheckUtf8(Vreq->Vbody)), YtZ0__YFWV_imt, 1));
   sf.pos=1866107;
   Vresponse = ((Tr (*)(Tcb *))Vh->VrpcInfo->VcreateResponse->cfunc)(Vh->VrpcInfo->VcreateResponse);
   sf.pos=1866108;
   ((Ts (*)(Tcb *, YtzZ*, Tr, Tr))Vh->Vhandler->cfunc)(Vh->Vhandler, Acontext, Vrequest, Vresponse);
   sf.pos=1866109;
   Vwriter = Za(sizeof(YjUM));
   sf.pos=1866110;
   ((void (*)(void*, Tr))(Vresponse.table[52]))(Vresponse.ptr, *Znao(&t0, Vwriter, YjUM__YdXi_imt, 2));
   sf.pos=1866111;
   Acontext->Vresponse->Vbody = YbNW(Vwriter);
   sf.pos=1866112;
   YDSB(Acontext->Vresponse, ((Tc*)&YN6V));
   sf.pos=1866113;
   r = 1;
   rt = 1;
   goto Ybypa;
  }
Ybypa:
  if (rt) goto YBtd;
 }
 sf.pos=1866114;
 r = 0;
YBtd:
 e->topFrame = sf.prev;
 return r;
}
Tc *YvG2__YtrZ_I_imt[] = {
 (Tc*)&YvG2__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YvG2__YntX__Y3fn, /* CBuildZimbuServlet.addPath - YvG2__YntX__Y3fn */
 (Tc*)YvG2__YntX__YU_W, /* CBuildZimbuServlet.handle - YvG2__YntX__YU_W */
 (Tc*)0, /* CBuildZimbuServlet.setMimeType - YvG2__YntX__YuzN */
 (Tc*)YvG2__Yk9ua, /* CBuildZimbuServlet.serve - YvG2__Yk9ua */
 (Tc*)0, /* Init - YvG2a */
};
To ToYvG2[] = {
 {4, 0},
 {0, (Tt*)&dict__T}, /* services */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* paths */
 {0, (Tt*)&string__T}, /* mimeType */
};
char *StrYvG2[] = {
 "services",
 "name",
 "paths",
 "mimeType",
};
Tto YvG2__T = {390, (Tc*)&YRDga, 0, StrYvG2, 0, 0, 0, 0, ToYvG2};
int JBuildZimbuServlet(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 if (round == 1) {
   sf.pos=7034400;
   Y_vl = YttT(NULL, ((Tc*)&Y0a), ((Tc*)&YfQV), 0, ((Tc*)&YIrL));
   sf.pos=7034401;
   YmKW = YttT(NULL, ((Tc*)&YKa), ((Tc*)&Y1Ak), 0, ((Tc*)&YGQA));
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* BuildZimbuServlet done */
Ts ZcbYXn8(Tcb *cb, YtzZ *arg0, Tr arg1, Tr arg2) {
return YXn8(arg0, arg1, arg2);
}
Tr ZcbYfT8(Tcb *cb, Tr arg0) {
return YfT8(arg0);
}
Tr ZcbYivy(Tcb *cb) {
return Yivy();
}
/*
 * INIT IMT
 */
void ZimtInit(void) {
 {
  Ytlm *p = 0;
  Ytlm__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Ytlm__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Ytlm__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYtlm[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtlm[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtlm[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YEro *p = 0;
  YEro__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YEro__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YEro__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  YtEE *p = 0;
  YtEE__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YtEE__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YtEE__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYtEE[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtEE[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtEE[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  YK7s *p = 0;
  ToYK7s[1].off = (int)((Tc*)&p->VisOpen - (Tc*)p);
  ToYK7s[2].off = (int)((Tc*)&p->VbufferSize - (Tc*)p);
  ToYK7s[3].off = (int)((Tc*)&p->VitemList - (Tc*)p);
  ToYK7s[4].off = (int)((Tc*)&p->Vlock - (Tc*)p);
  ToYK7s[5].off = (int)((Tc*)&p->VreadCond - (Tc*)p);
  ToYK7s[6].off = (int)((Tc*)&p->VwriteCond - (Tc*)p);
 }
 {
  Y2SD *p = 0;
  Y2SD__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y2SD__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y2SD__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY2SD[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY2SD[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY2SD[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YDTf *p = 0;
  ToYDTf[1].off = (int)((Tc*)&p->Vcmd - (Tc*)p);
  ToYDTf[2].off = (int)((Tc*)&p->Varglist - (Tc*)p);
  ToYDTf[3].off = (int)((Tc*)&p->VabortTimeout - (Tc*)p);
  ToYDTf[4].off = (int)((Tc*)&p->Vstarted - (Tc*)p);
  ToYDTf[5].off = (int)((Tc*)&p->Vexited - (Tc*)p);
  ToYDTf[6].off = (int)((Tc*)&p->Vpid - (Tc*)p);
  ToYDTf[7].off = (int)((Tc*)&p->VdidExit - (Tc*)p);
  ToYDTf[8].off = (int)((Tc*)&p->VexitValue - (Tc*)p);
  ToYDTf[9].off = (int)((Tc*)&p->VstdinFname - (Tc*)p);
  ToYDTf[10].off = (int)((Tc*)&p->VstdoutFname - (Tc*)p);
  ToYDTf[11].off = (int)((Tc*)&p->VstderrFname - (Tc*)p);
  ToYDTf[12].off = (int)((Tc*)&p->VstderrToStdout - (Tc*)p);
 }
 {
  Yd7N *p = 0;
  Yd7N__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yd7N__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yd7N__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYd7N[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYd7N[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYd7N[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  YBRp *p = 0;
  ToYBRp[1].off = (int)((Tc*)&p->VtheCharReader - (Tc*)p);
  ToYBRp[2].off = (int)((Tc*)&p->Vrefs - (Tc*)p);
  ToYBRp[3].off = (int)((Tc*)&p->Vlnum - (Tc*)p);
 }
 {
  YKxQ *p = 0;
  ToYKxQ[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYKxQ[2].off = (int)((Tc*)&p->VcreateFromJson - (Tc*)p);
  ToYKxQ[3].off = (int)((Tc*)&p->VcreateResponse - (Tc*)p);
 }
 {
  YSM1 *p = 0;
  ToYSM1[1].off = (int)((Tc*)&p->Vtype - (Tc*)p);
  ToYSM1[2].off = (int)((Tc*)&p->Vpath - (Tc*)p);
  ToYSM1[3].off = (int)((Tc*)&p->Vparams - (Tc*)p);
  ToYSM1[4].off = (int)((Tc*)&p->VhttpVersion - (Tc*)p);
  ToYSM1[5].off = (int)((Tc*)&p->VheaderItems - (Tc*)p);
  ToYSM1[6].off = (int)((Tc*)&p->Vbody - (Tc*)p);
  ToYSM1[7].off = (int)((Tc*)&p->VparamItems - (Tc*)p);
 }
 {
  YKeB *p = 0;
  ToYKeB[1].off = (int)((Tc*)&p->Vcode - (Tc*)p);
  ToYKeB[2].off = (int)((Tc*)&p->Vmsg - (Tc*)p);
  ToYKeB[3].off = (int)((Tc*)&p->VheaderItems - (Tc*)p);
  ToYKeB[4].off = (int)((Tc*)&p->Vbody - (Tc*)p);
 }
 {
  YtzZ *p = 0;
  ToYtzZ[1].off = (int)((Tc*)&p->Vserver - (Tc*)p);
  ToYtzZ[2].off = (int)((Tc*)&p->Vrequest - (Tc*)p);
  ToYtzZ[3].off = (int)((Tc*)&p->Vresponse - (Tc*)p);
 }
 {
  YphE *p = 0;
  YphE__YtrZ_I_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  YphE__YtrZ_I_imt[2] = (Tc*)((Tc*)&p->Vpaths - (Tc*)p);
  YphE__YtrZ_I_imt[3] = (Tc*)((Tc*)&p->VmimeType - (Tc*)p);
  ToYphE[1].off = (int)((Tc*)&p->VtoURL - (Tc*)p);
  ToYphE[2].off = (int)((Tc*)&p->Vcode - (Tc*)p);
  ToYphE[3].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYphE[4].off = (int)((Tc*)&p->Vpaths - (Tc*)p);
  ToYphE[5].off = (int)((Tc*)&p->VmimeType - (Tc*)p);
 }
 {
  YX8j *p = 0;
  YX8j__YtrZ_I_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  YX8j__YtrZ_I_imt[2] = (Tc*)((Tc*)&p->Vpaths - (Tc*)p);
  YX8j__YtrZ_I_imt[3] = (Tc*)((Tc*)&p->VmimeType - (Tc*)p);
  ToYX8j[1].off = (int)((Tc*)&p->VfileName - (Tc*)p);
  ToYX8j[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYX8j[3].off = (int)((Tc*)&p->Vpaths - (Tc*)p);
  ToYX8j[4].off = (int)((Tc*)&p->VmimeType - (Tc*)p);
 }
 {
  YIgO *p = 0;
  YIgO__YtrZ_I_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  YIgO__YtrZ_I_imt[2] = (Tc*)((Tc*)&p->Vpaths - (Tc*)p);
  YIgO__YtrZ_I_imt[3] = (Tc*)((Tc*)&p->VmimeType - (Tc*)p);
  ToYIgO[1].off = (int)((Tc*)&p->Vbody - (Tc*)p);
  ToYIgO[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYIgO[3].off = (int)((Tc*)&p->Vpaths - (Tc*)p);
  ToYIgO[4].off = (int)((Tc*)&p->VmimeType - (Tc*)p);
 }
 {
  Yivg *p = 0;
  ToYivg[1].off = (int)((Tc*)&p->VrpcInfo - (Tc*)p);
  ToYivg[2].off = (int)((Tc*)&p->Vhandler - (Tc*)p);
 }
 {
  YntX *p = 0;
  ToYntX[1].off = (int)((Tc*)&p->Vservices - (Tc*)p);
  ToYntX[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYntX[3].off = (int)((Tc*)&p->Vpaths - (Tc*)p);
  ToYntX[4].off = (int)((Tc*)&p->VmimeType - (Tc*)p);
 }
 {
  Y1QG *p = 0;
  ToY1QG[1].off = (int)((Tc*)&p->Vport - (Tc*)p);
  ToY1QG[2].off = (int)((Tc*)&p->VlistenQueueLen - (Tc*)p);
  ToY1QG[3].off = (int)((Tc*)&p->Vservlets - (Tc*)p);
  ToY1QG[4].off = (int)((Tc*)&p->VfileRoot - (Tc*)p);
  ToY1QG[5].off = (int)((Tc*)&p->Vbase - (Tc*)p);
  ToY1QG[6].off = (int)((Tc*)&p->Vverbosity - (Tc*)p);
  ToY1QG[7].off = (int)((Tc*)&p->VquitPipe - (Tc*)p);
  ToY1QG[8].off = (int)((Tc*)&p->VdidQuit - (Tc*)p);
  ToY1QG[9].off = (int)((Tc*)&p->Vbusy - (Tc*)p);
  ToY1QG[10].off = (int)((Tc*)&p->Vproc - (Tc*)p);
  ToY1QG[11].off = (int)((Tc*)&p->Vstate - (Tc*)p);
  ToY1QG[12].off = (int)((Tc*)&p->Vstack - (Tc*)p);
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
  YtZ0 *p = 0;
  ToYtZ0[1].off = (int)((Tc*)&p->VbyteIdx - (Tc*)p);
  ToYtZ0[2].off = (int)((Tc*)&p->VbyteSize - (Tc*)p);
  ToYtZ0[3].off = (int)((Tc*)&p->Vdata - (Tc*)p);
 }
 {
  YrC3 *p = 0;
  ToYrC3[1].off = (int)((Tc*)&p->Vreader - (Tc*)p);
  ToYrC3[2].off = (int)((Tc*)&p->Vstack - (Tc*)p);
 }
 {
  YjUM *p = 0;
  ToYjUM[1].off = (int)((Tc*)&p->VsLen - (Tc*)p);
  ToYjUM[2].off = (int)((Tc*)&p->Vs - (Tc*)p);
  ToYjUM[3].off = (int)((Tc*)&p->Vx - (Tc*)p);
 }
 {
  YgC4 *p = 0;
  YgC4__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YgC4__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YgC4__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYgC4[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYgC4[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYgC4[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YTgs *p = 0;
  ToYTgs[1].off = (int)((Tc*)&p->Vproc - (Tc*)p);
  ToYTgs[2].off = (int)((Tc*)&p->Vstate - (Tc*)p);
  ToYTgs[3].off = (int)((Tc*)&p->Vstack - (Tc*)p);
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
  YJQu__YuQR_I_imt[1] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  YJQu__YuQR_I_imt[2] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  YJQu__YuQR_I_imt[3] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  YJQu__YuQR_I_imt[4] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  YJQu__YuQR_I_imt[5] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  YJQu__YuQR_I_imt[6] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  YJQu__YuQR_I_imt[7] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  YJQu__YuQR_I_imt[8] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  YJQu__YuQR_I_imt[9] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
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
  YzqH__YuQR_I_imt[1] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  YzqH__YuQR_I_imt[2] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  YzqH__YuQR_I_imt[3] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  YzqH__YuQR_I_imt[4] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  YzqH__YuQR_I_imt[5] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  YzqH__YuQR_I_imt[6] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  YzqH__YuQR_I_imt[7] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  YzqH__YuQR_I_imt[8] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  YzqH__YuQR_I_imt[9] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
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
  YwcI *p = 0;
  YwcI__YFL0_I_imt[1] = (Tc*)((Tc*)&p->VderefTime - (Tc*)p);
  YwcI__YFL0_I_imt[2] = (Tc*)((Tc*)&p->VderefId - (Tc*)p);
  YwcI__YFL0_I_imt[3] = (Tc*)((Tc*)&p->VderefTimeSize - (Tc*)p);
  YwcI__YFL0_I_imt[4] = (Tc*)((Tc*)&p->VderefIdSize - (Tc*)p);
  ToYwcI[1].off = (int)((Tc*)&p->Vf_code - (Tc*)p);
  ToYwcI[2].off = (int)((Tc*)&p->VderefTime - (Tc*)p);
  ToYwcI[3].off = (int)((Tc*)&p->VderefId - (Tc*)p);
  ToYwcI[4].off = (int)((Tc*)&p->VderefTimeSize - (Tc*)p);
  ToYwcI[5].off = (int)((Tc*)&p->VderefIdSize - (Tc*)p);
 }
 {
  YWgO *p = 0;
  YWgO__YFL0_I_imt[1] = (Tc*)((Tc*)&p->VderefTime - (Tc*)p);
  YWgO__YFL0_I_imt[2] = (Tc*)((Tc*)&p->VderefId - (Tc*)p);
  YWgO__YFL0_I_imt[3] = (Tc*)((Tc*)&p->VderefTimeSize - (Tc*)p);
  YWgO__YFL0_I_imt[4] = (Tc*)((Tc*)&p->VderefIdSize - (Tc*)p);
  ToYWgO[1].off = (int)((Tc*)&p->Vf_compilerMessages - (Tc*)p);
  ToYWgO[2].off = (int)((Tc*)&p->Vf_runOutput - (Tc*)p);
  ToYWgO[3].off = (int)((Tc*)&p->VderefTime - (Tc*)p);
  ToYWgO[4].off = (int)((Tc*)&p->VderefId - (Tc*)p);
  ToYWgO[5].off = (int)((Tc*)&p->VderefTimeSize - (Tc*)p);
  ToYWgO[6].off = (int)((Tc*)&p->VderefIdSize - (Tc*)p);
 }
 {
  YvG2 *p = 0;
  YvG2__YtrZ_I_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  YvG2__YtrZ_I_imt[2] = (Tc*)((Tc*)&p->Vpaths - (Tc*)p);
  YvG2__YtrZ_I_imt[3] = (Tc*)((Tc*)&p->VmimeType - (Tc*)p);
  ToYvG2[1].off = (int)((Tc*)&p->Vservices - (Tc*)p);
  ToYvG2[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYvG2[3].off = (int)((Tc*)&p->Vpaths - (Tc*)p);
  ToYvG2[4].off = (int)((Tc*)&p->VmimeType - (Tc*)p);
 }
}

/*
 * INIT GLOBALS
 */
int ZglobInit(int round) {
 int done = 1;
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.prev = e->topFrame;
 sf.pos = 0;
 sf.frof = NULL;
 e->topFrame = &sf;
 if (round == 1) {
   sf.pos=0;
   Vport = Y4qx(NULL, ((Tc*)&YXa), ((Tc*)&Yb7c), 8889, ((Tc*)&Ys7y));
 }
 done &= JHTTPModule(round);
 done &= JIOModule(round);
 done &= JTHREADModule(round);
 done &= JARGModule(round);
 done &= JINTModule(round);
 done &= JliveDemoPage(round);
 done &= JBuildZimbuServlet(round);
 if (round == 2001) {
 }
 e->topFrame = sf.prev;
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
 ZenvInit();
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
 if (ZgetEnv()->topFrame != NULL) fprintf(stderr, "INTERNAL: topFrame not NULL\n");
 return r;
}

Zfo mainfo[5] = {{0,(Tt*)&string__T},{0,(Tt*)&Y1QG__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};

int Fmain(void) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 Tc *VindexPath = NULL;
 Y1QG *Vserver = 0;
 Tc *Vpage = NULL;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  mainfo[0].off = (void*)&sf - (void*)&VindexPath;
  mainfo[1].off = (void*)&sf - (void*)&Vserver;
  mainfo[2].off = (void*)&sf - (void*)&Vpage;
  mainfo[3].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = mainfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 r = 0;
 sf.pos=527000;
 VindexPath = ((Tc*)&YyGk);
 sf.pos=527001;
 Vserver = YAvl(NULL, Yl8r(Vport));
 sf.pos=527002;
 Y1DX(Vserver, VindexPath, ((Tc*)&YKlu), &LiveDemoPage__T);
 sf.pos=527003;
 Yv7Q(Vserver, ((Tc*)&YV), ZcS(((Tc*)&YV), VindexPath));
 sf.pos=527004;
 Yb8i(Vserver, *Znao(&t0, YwNW(NULL, ((Tc*)&Y0Z3)), YvG2__YtrZ_I_imt, 5));
 sf.pos=527005;
 Y1QG__YTgs__YSuw(Vserver);
 sf.pos=527006;
 Vpage = ZcS5(((Tc*)&YhLu), Zint2string(Yl8r(Vport)), ((Tc*)&YV), VindexPath, (Tc*)1);
 sf.pos=527007;
 Yl0k(ZcS(((Tc*)&YvpG), Vpage));
 sf.pos=527008;
 YQj8(Vserver, VindexPath);
 sf.pos=527009;
 YqJz(Vserver);
 sf.pos=527010;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
