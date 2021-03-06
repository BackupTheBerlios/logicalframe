<?php
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");

  // every page relies on the platformPage, in this case the olympicPage
  $page = new olympicPage();
  $page->mustComeFrom("subscribe.php");

  // presentation layer. actually an html page
  $page->setDefaultPage("subscribed.tpl");
 
  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();


  function processForm()
  {
    global $page;
  }
?>
