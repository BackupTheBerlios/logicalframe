<?php
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");

  // every page relies on the platformPage, in this case the olympicPage
  $page = new olympicPage();

  // presentation layer. actually an html page
  $page->setDefaultPage("login.tpl");

  if($_GET['login']=="failed")
  {
    $page->m_smarty->assign("loginerror","The supplied username and/or passwd is not correct");
  }

  $page->addItem("InputField","emailadres","in_template");
  $page->m_items['emailadres']->addValidation("IsEmail");
  $page->m_items['emailadres']->setSize("40");
  $page->m_items['emailadres']->m_validationrule->setErrorMessage("Please enter a valid emailaddress!");
 
  $page->addItem("PasswordField","passwd","in_template");
  $page->m_items['passwd']->addValidation("NotEmpty","3");
  $page->m_items['passwd']->setSize("40");
  $page->m_items['passwd']->m_validationrule->setErrorMessage("Please enter passwd with at least 5 characters!");
 
  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();


  function processForm()
  {
    global $page;
    if($page->login($_POST['emailadres'],$_POST['passwd'],"user"))
    {
      // forward user to the index page
      $page->forwardTo("index.php");
    }
    else
    {
      $page->forwardTo("login.php?login=failed");
    }
  }
?>
