
var $doc = window.document;
var zut = {
    controllers: {}
  };


// structs
// including TIMEModule structs
// including EModule structs
function Ytlm(){ // Exception
}
_ = Ytlm.prototype = {};
_.Vmessage = null;
_.Vpos = null;
_.Vbacktrace = null;
_.ToString = YH0V;
_.writeTo__1 = YxaJa;
_.writeTo = YxaJ;
_.toString = Yoww;
function YwtA(){ // Error
}
_ = YwtA.prototype = new Ytlm();
function YVNj(){ // Init
}
_ = YVNj.prototype = new YwtA();
function Yalz(){ // BadValue
}
_ = Yalz.prototype = new YwtA();
function Y2EX(){ // KeyNotFound
}
_ = Y2EX.prototype = new Yalz();
function YX0i(){ // KeyExists
}
_ = YX0i.prototype = new Yalz();
function YXKl(){ // IOError
}
_ = YXKl.prototype = new YwtA();
// including PIPEModule structs
// including IModule structs
// including SYSModule structs
// including DYNModule structs
// including HTTPModule structs
// including Proto structs
// including Message structs
// including RPCModule structs
// including ZModule structs
function YkxB(){ // Pos
}
_ = YkxB.prototype = {};
_.Vfilename = null;
_.Vlnum = 0;
_.Vcol = 0;
_.Vtext = null;
_.ToString = YpI_;
// including STRINGModule structs
// including THREADModule structs
// including Config structs
// including zimbuConfig structs
// including LISTModule structs
// including ZUTModule structs
// including MainPage structs
function YJgz(){ // Context
}
_ = YJgz.prototype = {};
_.VhttpContext = null;
_.VcssNames = null;
_.VcssEntries = null;
_.hasCss = YdGR;
_.addCss = Yl3F;
function Yq5o(){ // Element
}
_ = Yq5o.prototype = {};
function YN5G(){ // Event
}
_ = YN5G.prototype = {};
_.Vtype = 0;
_.Velement = null;
// including BYTESTRINGModule structs
// including IOModule structs
function Y8is(){ // Writer
}
_ = Y8is.prototype = {};
_.write__2 = YHhZb;
function Yw8L(){ // File
}
_ = Yw8L.prototype = new Y8is();
_.write = YwHoa;
_.Vfd = null;
_.Vname = null;
function YjUM(){ // StringWriter
}
_ = YjUM.prototype = new Y8is();
_.write = YJqza;
_.VsLen = 0;
_.Vs = null;
_.Vx = null;
_.ToString = YbNW;
// including SETModule structs
function Yhqr(){ // Set__t1
}
_ = Yhqr.prototype = {};
_.Vdict = null;
_.Init = Ypau;
_.has = YyHa;
_.add = YGMT;
// including CHECKModule structs
// including BOXModule structs
// including ARGModule structs
// including INTModule structs
// MyController.zu structs
// including HelloMessage structs
function Y5cA(){ // MyController
}
_ = Y5cA.prototype = {};
_.clicked = YiUW;

// declarations
// including TIMEModule declarations
// including EModule declarations
// including PIPEModule declarations
// including IModule declarations
// including SYSModule declarations
// including DYNModule declarations
// including HTTPModule declarations
// including Proto declarations
// including Message declarations
// including RPCModule declarations
// including ZModule declarations
// including STRINGModule declarations
// including THREADModule declarations
// including Config declarations
// including zimbuConfig declarations
// including LISTModule declarations
// including ZUTModule declarations
// including MainPage declarations
// including BYTESTRINGModule declarations
// including IOModule declarations
var Y59X = Yd89(); // IOModule.stdin
var Yb0q = Yvyt(); // IOModule.stdout
var YeNQ = YsM3(); // IOModule.stderr
// including SETModule declarations
// including CHECKModule declarations
// including BOXModule declarations
// including ARGModule declarations
// including INTModule declarations
// MyController.zu declarations
// including HelloMessage declarations
var YdUK = 0; // iUW.done

// bodies

function ZforListNew(p) {
 var f = {};
 f['list'] = p;
 f['idx'] = 0;
 return f;
}
function ZforListGet(f) {
 if (f.list != null && f.idx < f.list.length)
  return f.list[f.idx];
 return null;
}
function ZforListCont(f) {
  return f.list != null && f.idx < f.list.length;
}
function ZforListNext(f) {
 ++f.idx;
 if (f.list != null && f.idx < f.list.length)
  return f.list[f.idx];
 return null;
}

function Zthrow(msg) {
  alert("Exception: " + msg);
}

/* List add */
function ZLa(head, after, val) {
  if (head == null) Zthrow("Inovking add() on NIL list");
  if (after == -1 || after >= head.length) {
    head.push(val);
  } else {
    if (after < 0) {
      var before = head.length + after + 1;
      if (before < 0) {
        before = 0;
      }
      head.splice(before, 0, val);
    } else {
      head.splice(after + 1, 0, val);
    }
  }
  return head;
}

function ZDictAdd(ow, d, key, value) {
  if (d[key]) {
    if (!ow) alert("dict item already exists: " + key);
  } else {
    d.size++;
  }
  d[key] = value;
  return d;
}

function ZnewDict(keyType, valType) {
  var d = {size: 0};
  d['keyType'] = keyType;
  d['valType'] = valType;
  return d;
}
zut.controllers['MyController'] = Y5cA;
// including TIMEModule bodies
// including EModule bodies
function YRHR(thisO, Amsg) { // MEModule__CException.NEW
 if (!thisO) thisO = new Ytlm();
 thisO.Vmessage = Amsg;
 thisO.Vpos = null;
 thisO.Vbacktrace = null;
 return thisO;
}
function YRHRa(thisO, Apos, Amsg) { // MEModule__CException.NEW
 if (!thisO) thisO = new Ytlm();
 thisO.Vmessage = Amsg;
 thisO.Vpos = Apos;
 thisO.Vbacktrace = null;
 return thisO;
}
function YH0V() { // MEModule__CException.ToString
 var Vw = new YjUM();
 this.writeTo(Vw);
 return Vw.ToString();
}
function YxaJ(Aw) { // MEModule__CException.writeTo
 if ((this.Vpos != null))
 {
  Aw.write(this.Vpos.ToString());
  Aw.write(": ");
 }
 if (((this.Vmessage != null) && (this.Vmessage != "")))
 {
  Aw.write("Exception: ");
  Aw.write(this.Vmessage);
 }
 else
 {
  Aw.write("Exception");
 }
}
function Yoww(Averbose) { // MEModule__CException.toString
 var Vw = new YjUM();
 this.writeTo__1(Averbose, Vw);
 return Vw.ToString();
}
function YxaJa(Averbose, Aw) { // MEModule__CException.writeTo
 this.writeTo(Aw);
 if ((Averbose && (this.Vbacktrace != null)))
 {
  Aw.write("\nStack backtrace (last called first):");
  {
   var Vpos;
   var Zf2 = ZforListNew(this.Vbacktrace);
for (Vpos = ZforListGet(Zf2); ZforListCont(Zf2); Vpos = ZforListNext(Zf2)) {
   if ((Vpos.Vfilename == null))
   {
    Aw.write("\n(unknown)");
   }
   else
   {
    Aw.write("\n");
    Aw.write(Vpos.ToString());
    if ((Vpos.Vtext != null))
    {
     Aw.write(": ");
     Aw.write(Vpos.Vtext);
    }
   }
   }
  }
 }
}
function YwtA__YRHRa(thisO, Apos, Amsg) { // MEModule__CError.NEW__p1
 if (!thisO) thisO = new YwtA();
 thisO.Vmessage = Amsg;
 thisO.Vpos = Apos;
 thisO.Vbacktrace = null;
 return thisO;
}
function YwtA__YRHR(thisO, Amsg) { // MEModule__CError.NEW__p1
 if (!thisO) thisO = new YwtA();
 thisO.Vmessage = Amsg;
 thisO.Vpos = null;
 thisO.Vbacktrace = null;
 return thisO;
}
function Yalz__YwtA__YRHRa(thisO, Apos, Amsg) { // MEModule__CBadValue.NEW__p2
 if (!thisO) thisO = new Yalz();
 thisO.Vmessage = Amsg;
 thisO.Vpos = Apos;
 thisO.Vbacktrace = null;
 return thisO;
}
function Yalz__YwtA__YRHR(thisO, Amsg) { // MEModule__CBadValue.NEW__p2
 if (!thisO) thisO = new Yalz();
 thisO.Vmessage = Amsg;
 thisO.Vpos = null;
 thisO.Vbacktrace = null;
 return thisO;
}
function Y2EX__Yalz__YwtA__YRHR(thisO, Amsg) { // MEModule__CKeyNotFound.NEW__p3
 if (!thisO) thisO = new Y2EX();
 thisO.Vmessage = Amsg;
 thisO.Vpos = null;
 thisO.Vbacktrace = null;
 return thisO;
}
function Yxmk(Akey, Amsg) { // MEModule.throwIntKeyNotFound
 alert("Exception in D:/zimbu/lib/EModule.zu line 374 col 5: " + Y2EX__Yalz__YwtA__YRHR(null, Amsg + "Key not found: " + "" + Akey).Vmessage);
 return;
}
function Y5LT(Akey, Amsg) { // MEModule.throwStringKeyNotFound
 alert("Exception in D:/zimbu/lib/EModule.zu line 380 col 5: " + Y2EX__Yalz__YwtA__YRHR(null, Amsg + "Key not found: \"" + Akey + "\"").Vmessage);
 return;
}
function YX0i__Yalz__YwtA__YRHRa(thisO, Apos, Amsg) { // MEModule__CKeyExists.NEW__p3
 if (!thisO) thisO = new YX0i();
 thisO.Vmessage = Amsg;
 thisO.Vpos = Apos;
 thisO.Vbacktrace = null;
 return thisO;
}
function YX0i__Yalz__YwtA__YRHR(thisO, Amsg) { // MEModule__CKeyExists.NEW__p3
 if (!thisO) thisO = new YX0i();
 thisO.Vmessage = Amsg;
 thisO.Vpos = null;
 thisO.Vbacktrace = null;
 return thisO;
}
function YL9Z(Akey, Amsg) { // MEModule.throwIntKeyExists
 alert("Exception in D:/zimbu/lib/EModule.zu line 396 col 5: " + YX0i__Yalz__YwtA__YRHR(null, Amsg + "Key already exists: " + "" + Akey).Vmessage);
 return;
}
function YEeX(Akey, Amsg) { // MEModule.throwStringKeyExists
 alert("Exception in D:/zimbu/lib/EModule.zu line 402 col 5: " + YX0i__Yalz__YwtA__YRHR(null, Amsg + "Key already exists: \"" + Akey + "\"").Vmessage);
 return;
}
function YXKl__YwtA__YRHR(thisO, Amsg) { // MEModule__CIOError.NEW__p2
 if (!thisO) thisO = new YXKl();
 thisO.Vmessage = Amsg;
 thisO.Vpos = null;
 thisO.Vbacktrace = null;
 return thisO;
}
// including PIPEModule bodies
// including IModule bodies
// including SYSModule bodies
// including DYNModule bodies
// including HTTPModule bodies
// including Proto bodies
// including Message bodies
// including RPCModule bodies
// including ZModule bodies
function Ypp_a(thisO, Afilename, Alnum, Acol) { // MZModule__CPos.NEW
 if (!thisO) thisO = new YkxB();
 thisO.Vfilename = Afilename;
 thisO.Vlnum = Alnum;
 thisO.Vcol = Acol;
 return thisO;
}
function YpI_() { // MZModule__CPos.ToString
 var Vw = new YjUM();
 if ((this.Vfilename == null))
 {
  Vw.write("[unknown file]");
 }
 else
 {
  Vw.write(this.Vfilename);
 }
 Vw.write(" line ");
 Vw.write__2(this.Vlnum);
 Vw.write(" col ");
 Vw.write__2(this.Vcol);
 return Vw.ToString();
}
// including STRINGModule bodies
// including THREADModule bodies
// including Config bodies
// including zimbuConfig bodies
// including LISTModule bodies
// including ZUTModule bodies
// including MainPage bodies
function YIZda(thisO) { // MZUTModule__CContext.NEW
 if (!thisO) thisO = new YJgz();
 thisO.VcssEntries = [];
 thisO.VcssNames = Yh95(null);
 return thisO;
}
function YdGR(Aname) { // MZUTModule__CContext.hasCss
 return this.VcssNames.has(Aname);
}
function Yl3F(Aname, Acss) { // MZUTModule__CContext.addCss
 this.VcssNames.add(Aname);
        var styleEl = $doc.createElement('style');
        styleEl.type = 'text/css';
        if (styleEl.styleSheet) {
          styleEl.styleSheet.cssText = Acss;
        } else {
          styleEl.appendChild($doc.createTextNode(Acss));
        }
        $doc.head.appendChild(styleEl);
}
function YXm4(thisO, Ael) { // MZUTModule__CEvent.NEW
 if (!thisO) thisO = new YN5G();
 thisO.Velement = Ael;
 return thisO;
}
function YYe7(Ael) { // MZUTModule__CEvent__X.newClickEvent
 var Ve = YXm4(null, Ael);
 Ve.Vtype = 0;
 return Ve;
}
function YNKL(Ael, Aname) { // MZUTModule.getAttribute
 var Vvalue = null;
      Vvalue = Ael.getAttribute(Aname);
 return Vvalue;
}
function YS1u(Aid, Atemplate) { // MZUTModule.fillElement
 var Vhtml = (Atemplate)(zut.context);
      var el = $doc.getElementById(Aid);
      if (el) {
        el.innerHTML = Vhtml;
      }
}
// including BYTESTRINGModule bodies
// including IOModule bodies
function Yd89() { // MIOModule.newStdin
 var Vfile = new Yw8L();
 Vfile.Vname = "stdin";
 return Vfile;
}
function Yvyt() { // MIOModule.newStdout
 var Vfile = new Yw8L();
 Vfile.Vname = "stdout";
 return Vfile;
}
function YsM3() { // MIOModule.newStderr
 var Vfile = new Yw8L();
 Vfile.Vname = "stderr";
 return Vfile;
}
function YHhZb(Anumber) { // MIOModule__CWriter.write
 return this.write(((Anumber) + ""));
}
function YwHoa(Atext) { // MIOModule__CFile.write
 var Vret = 0;
 if ((this.Vname == null))
 {
  alert("Exception in D:/zimbu/lib/IOModule.zu line 501 col 11: " + YXKl__YwtA__YRHR(null, "File is not open").Vmessage);
  return;
 }
 var e = $doc.getElementById(this.Vname);
 if (e == null) {
  e = $doc.createElement('div');
  e.id = this.Vname;
  $doc.body.appendChild(e);
 }
 e.innerHTML += Atext;
 return Vret;
}
function Yl0k(Atext) { // MIOModule.print
 var Vret = 0;
 Vret = Yb0q.write(Atext);
 $doc.getElementById("stdout").innerHTML += "<br>";
 return Vret;
}
function Yl0kh() { // MIOModule.print
 return Yl0k("");
}
function YJqza(Atext) { // MIOModule__CStringWriter.write
 var Vlen = (Atext).length;
 if (this.Vx == null) {
  this.Vx = Atext;
 } else {
  this.Vx = this.Vx + Atext;
 }
 return 1;
}
function YbNW() { // MIOModule__CStringWriter.ToString
 var Vr = null;
 if ((this.Vx == null))
 {
  Vr = "";
 }
 else
 {
  Vr = this.Vx;
 }
 return Vr;
}
// including SETModule bodies
function Ypau(thisO) { // MSETModule__CSet__t1.Init
 if (!thisO) thisO = new Yhqr();
 thisO.Vdict = ZnewDict(1, 0);
 return thisO;
}
function Yh95(thisO) { // MSETModule__CSet__t1.NEW
 if (!thisO) thisO = Ypau(null);
 return thisO;
}
function YyHa(Akey) { // MSETModule__CSet__t1.has
 return ':' + Akey in this.Vdict;
}
function YGMT(Akey) { // MSETModule__CSet__t1.add
 if (':' + Akey in this.Vdict)
 {
  alert("Exception in D:/zimbu/lib/SETModule.zu line 104 col 9: " + YX0i__Yalz__YwtA__YRHRa(null, null, "key already present: " + Akey).Vmessage);
  return;
 }
 ZDictAdd(0, this.Vdict, ':' + Akey, 1);
 return this;
}
// including CHECKModule bodies
// including BOXModule bodies
// including ARGModule bodies
// including INTModule bodies
// MyController.zu bodies
// including HelloMessage bodies
function YHTw(Acontext) { // MHelloMessage.addCss
 if (Acontext.hasCss("HelloMessage.zut"))
 {
  return;
 }
 var Vw = new YjUM();
 Vw.write(".hello {\ncolor: blue;\n}\n");
 Acontext.addCss("HelloMessage.zut", Vw.ToString());
}
function YqnP(Acontext, Atext) { // MHelloMessage.show
 YHTw(Acontext);
 var Vw = new YjUM();
 Vw.write("<div class=\"hello\">\n");
 Vw.write(Atext);
 Vw.write("</div>\n");
 return Vw.ToString();
}
function YiUW(Aevent) { // CMyController.clicked
 if (!(YdUK))
 {
  YdUK = 1;
  Yl0kh();
  Yl0k("--- stdout --");
 }
 Yl0k("You clicked!");
 var Vid = YNKL(Aevent.Velement, "data-id");
 var Vcb = function(a) { return YqnP(a, "Hello World!"); };
 YS1u(Vid, Vcb);
 return 0;
}

$doc.onclick = function(e) {
  var event = e || window.event; // for old IE
  var el = event.target || event.srcElement; // for old IE
  if (el) {
    var controller;
    var action;
    var actionEl;
    while (el) {
      if (!action && el.getAttribute('zaction')) {
        var actions = el.getAttribute('zaction');
        var parts = actions.split(',');
        for (var i = 0; i < parts.length; ++i) {
          if (parts[i].indexOf('click:') >= 0) {
            action = parts[i].substring(6).trim();
            actionEl = el;
            break;
          }
        }
      }
      if (action) {
        controller = el.getAttribute('zcontroller');
        if (controller) {
          var inst = el.zcontrollerInst;
          if (!inst) {
            var ctrlClass = zut.controllers[controller];
            if (!ctrlClass) {
              alert('controller not registered: ' + controller);
              return;
            }
            inst = new ctrlClass();
            el.zcontrollerInst = inst;
          }
          if (inst[action]) {
            var event = YYe7(el);
            inst[action](event);
          } else {
            alert('action ' + action + ' does not exist on ' + controller);
          }
          return;
        }
      }
      el = el.parentNode;
    }
  }
};
zut.context = YIZda(null);

