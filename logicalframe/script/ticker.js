/* *************** */
function goUp() {}
function goDown() {}
function goToLeft() {}
function goToRight() {}
/* ************** */

/* ********* newsticker code *** */
var rollStop = 50;
var newsconTent  = 0;
var newsspeed    = 30;
var newspause    = 4000;
// ************* news scroll code *************************
var pauseTimer = 0; 
var rollIt=0; // do not change
var newsloop, newstimer
function gonewsDown(newsmove){ 
	if (rollIt<=rollStop && !(rollIt == 0 && pauseTimer == 1)) { 
		if(this.y>-newsconTent){ 
			this.moveIt(0,this.y-newsmove) 
			if(newsloop) { 
				newstimer = setTimeout(this.obj+".newsDown("+newsmove+")",newsspeed); 
			} 
			rollIt=rollIt+1; 
		} else if (this.y<=-newsconTent){ 
			this.moveIt(0,0); 
			nText.newsDown(newsmove); 
		} 
	} else { 
		nonewsScroll(); 
		setTimeout("newsScroll("+1+")",newspause); 
	} 
}
// Calls the scrolling functions. Also checks whether the page is loaded or not.
function newsScroll(newsspeed){
newsconTent=eval("(nText.h-nCont.cb)");
// alert(-oText.h+oCont.cb)
	if(loaded){
		newsloop=true;
		if(newsspeed>0) nText.newsDown(newsspeed)
	}
}
// Stops the scrolling (called on mouseout)
function nonewsScroll(){
	loop=false;
	clearTimeout(newstimer);
	rollIt=0;
}
/* ************************* */
// Makes the object
var loaded;
function scrollInit(){
	page=new thugluv_doc_size()
	nCont=new thugluv_obj('newsCont');
    nText=new thugluv_obj('newsText','newsCont');
	nText.moveIt(0,0);
    nCont.showIt();
	nText.showIt();
	loaded=true;
	setTimeout("newsScroll("+1+")",newspause);
}