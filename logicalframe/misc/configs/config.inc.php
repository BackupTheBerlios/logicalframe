<?php
/**
*	All config options should reside here.
*/

$config['url'] = "http://logicalframe.berlios.de";

// mysql or postgresql.
$config['db_user']= "logicalframe";
$config['db_passwd']= "respect123";
$config['db']= "logicalframe";
$config['db_host']= "db.berlios.de";
$config['dbma']="mysql";

$config['templates_compiledir']="tmp/compiled_templates";
$config['smartydebug']="false";

// shows the debug level. 
// 0 = no debug info
// 1 = debug info, module niveau's default 
// 2 = all debug info, all niveau's (to do)
$config['debug']=2;

// seperate with | sign
$config['debugips'] = "81.70.10.9";
$config['smartydebug'] = true;

$config['requiresign']="&nbsp;&nbsp;&nbsp;<img src=\"images/required.gif\">";

$config['uploaddir']="albums/uploads/";

$config['albumdir']="albums/";

$config['tmpdir']="albums/uploads/tmp/";

$config['adminusername']="administrator";
$config['adminpasswd']="respect123";

// font configs
//$config['labeltxt']="Copyright © www.pinky.nl";
//$config['font']="tahoma.ttf";
//$config['mailalert']="true";

// default is white
$config['fontcolor']="whitesmoke";

// default is 10
$config['fontsize']="12";
?>
