<?php
include_once("class.olympicPage.inc");

  $page = new olympicPage();
  $page->unregisterUser();
  $page->forwardTo("index.php");

  $page->printDebug();
?>
