
/*Multi image slideshow script- by javascriptkit.com
Visit JavaScript Kit (http://javascriptkit.com) for script
Credit must stay intact for use*/

//#1 SPECIFY number of slideshows
var number_of_slideshows=10

//#2 SPECIFY interval between slide (2000=2 seconds)
var interval=4000

//#3 SHOULD each slide be linked to a unique URL?
var linked=1

var slideshows=new Array(number_of_slideshows)
for (i=0; i <number_of_slideshows; i++)
slideshows[i]=new Array()

//#4 SPECIFY image paths of 1st slideshow
slideshows[0][0]='images/slide9.jpg'
slideshows[0][1]='images/slide1.jpg'
slideshows[0][2]='images/slide7.jpg'
slideshows[0][3]='images/slide.jpg'
slideshows[0][4]='images/slide5.jpg'
slideshows[0][5]='images/slide10.jpg'
slideshows[0][6]='images/slide11.jpg'
slideshows[0][7]='images/slide.jpg'


//SPECIFY image paths of 2nd slideshow (remove if number_of_slides less than 2)
slideshows[1][0]='house1.gif'
slideshows[1][1]='house2.gif'
slideshows[1][2]='house3.gif'

//SPECIFY image paths of 3rd slideshow (remove if number_of_slides less than 3)
slideshows[2][0]='boat1.gif'
slideshows[2][1]='boat2.gif'
slideshows[2][2]='boat3.gif'

//EXTEND THIS ARRAY if more than 3 slide shows

<!--Remove the below portion if "var linked" above is set to 0-->

<!-- END removal ---------------------------------->

var maininc=0
var subinc=0

if (linked)
document.write('<img src="'+slideshows[0][0]+'" width="256" height="173" name="multislide" border=0 alt="ski jumping">')
else
document.write('<img src="'+slideshows[0][0]+'" name="multislide">')

function slideit(){
subinc= (subinc<slideshows[maininc].length-1)? subinc+1: 0
document.images.multislide.src=slideshows[maininc][subinc]
}

function setslide(which){
clearInterval(runit)
maininc=which
subinc=0
runit=setInterval("slideit()",interval)
}

runit=setInterval("slideit()",interval)
