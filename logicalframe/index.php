<?php
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");

  // every page relies on the platformPage, in this case the olympicPage
  $page = new olympicPage();

  // presentation layer. actually an html page
  $page->setDefaultPage("index.tpl");
 
  $page->addItem("InputField","name","in_template");
  $page->m_items['name']->addValidation("NotEmpty","2");
  $page->m_items['name']->setSize("40");
  $page->m_items['name']->m_validationrule->setErrorMessage("please enter a name");
 
  $page->addItem("InputField","height","in_template");
  $page->m_items['height']->addValidation("MinMaxFloat","1","10","2");
  $page->m_items['height']->setSize("40");
  $page->m_items['height']->m_validationrule->setErrorMessage("please enter the grade between 1 and 10 and at most 2 decimals");
 
  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();


  function processForm()
  {
    global $page;

  }
?>
