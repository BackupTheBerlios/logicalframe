<?php
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");

  $page = new olympicPage();
  $page->mustBeUser("login.php");

  // presentation layer. actually an html page
  $page->setDefaultPage("search.tpl");
 
  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();


  function processForm()
  {
    global $page;
  }
?>
