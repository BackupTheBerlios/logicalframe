<?php
  ini_set("display_startup_errors",1);
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");
  
  // every page relies on the platformPage, in this case the olympicPage
  $page = new olympicPage();
  $page->mustBeUser("login.php");

  // presentation layer. actually an html page
  $page->setDefaultPage("judgedsummary.tpl");

  $results = $page->getResult($_GET['result_id']);
  $page->m_smarty->assign("results",$results);
  var_dump($results);
  
  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();

  function processForm()
  {
    global $page;
  }
?>
