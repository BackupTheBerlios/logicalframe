
function thugluv_checkBrowser(){
	this.ver=navigator.appVersion; this.dom=document.getElementById?1:0;
	this.mac=(this.ver.indexOf("PPC")!= -1)?1:0; this.win=(this.ver.indexOf("Win")!= -1)?1:0;
	this.ie5=(this.ver.indexOf("MSIE")!= -1 && this.dom && parseInt(this.ver) >= 4)?1:0;
	this.ie4=(document.all && !this.dom)?1:0; this.ie=(this.ie5 || this.ie4);
	this.ns6=(this.dom && parseInt(this.ver) >= 5)?1:0;
	this.ns4=(document.layers && !this.dom)?1:0; this.ns=(this.ns4 || this.ns6);
	this.thugluv=(this.ie || this.ns);
	return this;
}
thugluv=new thugluv_checkBrowser();
function thugluv_message(txt){alert(txt); return false}
function thugluv_obj(obj,nest){ 
  if(!thugluv.thugluv) return thugluv_message('Old browser')
  nest=(!nest) ? "":'document.'+nest+'.'
  this.evnt=thugluv.dom? document.getElementById(obj):
    thugluv.ie4?document.all[obj]:thugluv.ns4?eval(nest+"document.layers." +obj):0;	
  if(!this.evnt) return thugluv_message('The layer does not exist ('+obj+')' 
    +'- \nIf your using Netscape please check the nesting of your tags!')
  this.css=thugluv.dom||thugluv.ie4?this.evnt.style:this.evnt; 
  this.ref=thugluv.dom||thugluv.ie4?document:this.css.document;
  this.x=parseInt(this.css.left)||this.css.pixelLeft||this.evnt.offsetLeft||0;
  this.y=parseInt(this.css.top)||this.css.pixelTop||this.evnt.offsetTop||0;
  this.w=this.evnt.offsetWidth||this.css.clip.width||this.ref.width||this.css.pixelWidth||0; 
  this.h=this.evnt.offsetHeight||this.css.clip.height||this.ref.height||this.css.pixelHeight||0;
  this.c=0; //Clip values
  if((thugluv.dom || thugluv.ie4) && this.css.clip) {
  this.c=this.css.clip; this.c=this.c.slice(5,this.c.length-1); 
  this.c=this.c.split(' ');
  for(var i=0;i<4;i++){this.c[i]=parseInt(this.c[i])}
  }
  this.ct=this.css.clip.top||this.c[0]||0; 
  this.cr=this.css.clip.right||this.c[1]||this.w||0;
  this.cb=this.css.clip.bottom||this.c[2]||this.h||0; 
  this.cl=this.css.clip.left||this.c[3]||0;
  this.obj = obj + "Object"; eval(this.obj + "=this")
  // extra non standard functions:  
  this.newsDown=gonewsDown; // news ticker function
  this.up=goUp;this.down=goDown; // scrolling functions
  this.toleft=goToLeft;this.toright=goToRight; // left and right login
  return this
}
thugluv_obj.prototype.moveIt = function(x,y){
  this.x=x;this.y=y; this.css.left=x;this.css.top=y
}
thugluv_obj.prototype.moveBy = function(x,y){
  this.css.left=this.x+=x; this.css.top=this.y+=y
}
thugluv_obj.prototype.showIt = function(){this.css.visibility="visible"}
thugluv_obj.prototype.hideIt = function(){this.css.visibility="hidden"}
thugluv_obj.prototype.bg = function(color){ 
	if(thugluv.dom || thugluv.ie4) this.css.backgroundColor=color
	else if(thugluv.ns4) this.css.bgColor=color  
}
thugluv_obj.prototype.writeIt = function(text,startHTML,endHTML){
	if(thugluv.ns4){
    if(!startHTML){startHTML=""; endHTML=""}
	  this.ref.open("text/html"); 
    this.ref.write(startHTML+text+endHTML); 
    this.ref.close()
	}else this.evnt.innerHTML=text
}
thugluv_obj.prototype.clipTo = function(t,r,b,l,setwidth){ 
  this.ct=t; this.cr=r; this.cb=b; this.cl=l
  if(thugluv.ns4){
    this.css.clip.top=t;this.css.clip.right=r
    this.css.clip.bottom=b;this.css.clip.left=l
  }else{
    if(t<0)t=0;if(r<0)r=0;if(b<0)b=0;if(b<0)b=0
    this.css.clip="rect("+t+","+r+","+b+","+l+")";
    if(setwidth){this.css.pixelWidth=this.css.width=r; 
    this.css.pixelHeight=this.css.height=b}
  }
}
thugluv_obj.prototype.clipBy = function(t,r,b,l,setwidth){ 
  this.clipTo(this.ct+t,this.cr+r,this.cb+b,this.cl+l,setwidth)
}
function thugluv_doc_size(){ 
  this.x=0;this.x2=thugluv.ie && document.body.offsetWidth-20||innerWidth||0;
  this.y=0;this.y2=thugluv.ie && document.body.offsetHeight-5||innerHeight||0;
  if(!this.x2||!this.y2) return message('Document has no width or height') 
  this.x50=this.x2/2;this.y50=this.y2/2;
  return this;
}
function clearDots() {
	if (thugluv.ie) { dots.focus() }
}
function popup(pagename,winid,wwidth,wheight) {
	window.open(pagename,winid,'toolbar=no,location=no,directories=no,status=no,menubar=no,scrolling=AUTO,scrollbars=1,resizable=no,width='+wwidth+',height='+wheight);			
}
function popGame(pagename) {
	window.open(pagename,'game','toolbar=no,location=no,directories=no,status=no,menubar=no,scrolling=no,scrollbars=no,resizable=no,width=770,height=610');			
}
function popPrivacy(pagename) {
	window.open(pagename,'game','toolbar=no,location=no,directories=no,status=no,menubar=no,scrolling=AUTO,scrollbars=1,resizable=no,width=580,height=350');			
}


function printit(){  
if (window.print) {
    window.print() ;  
} else {
    var WebBrowser = '<OBJECT ID="WebBrowser1" WIDTH=0 HEIGHT=0 CLASSID="CLSID:8856F961-340A-11D0-A96B-00C04FD705A2"></OBJECT>';
document.body.insertAdjacentHTML('beforeEnd', WebBrowser);
    WebBrowser1.ExecWB(6, 2);//Use a 1 vs. a 2 for a prompting dialog box    WebBrowser1.outerHTML = "";  
}
}
function MM_findObj(n, d) { //v4.0
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && document.getElementById) x=document.getElementById(n); return x;
}