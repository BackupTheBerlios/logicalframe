<?php
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");

  // every page relies on the platformPage, in this case the olympicPage
  $page = new olympicPage();

  $page->mustBeUser("login.php");
  // presentation layer. actually an html page
  $page->setDefaultPage("round_details.tpl");

  if($_GET['round_id']!="")
  {
    $round = $page->getRoundResults($_GET['round_id']);

    if(is_array($round)&&count($round)>0)
    {
      $page->m_smarty->assign("round",$round);
    }
    else
    {
      // shit no round data?
    }
  }
  else
  {
    // no round_id so forward
    $page->forwardTo("rounds.php");
  }


  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();


  function processForm()
  {
    global $page;
  }
?>
