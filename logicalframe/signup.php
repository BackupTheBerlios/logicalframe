<?php
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");

  // every page relies on the platformPage, in this case the olympicPage
  $page = new olympicPage();

  // presentation layer. actually an html page
  $page->setDefaultPage("signup.tpl");

  $page->addItem("InputField","company","in_template");
  $page->m_items['company']->addValidation("NotEmpty","1");
  $page->m_items['company']->setSize("40");
  $page->m_items['company']->m_validationrule->setErrorMessage("Please enter the company name!");
 
  $page->addItem("InputField","emailadres","in_template");
  $page->m_items['emailadres']->addValidation("IsEmail");
  $page->m_items['emailadres']->setSize("40");
  $page->m_items['emailadres']->m_validationrule->setErrorMessage("Please enter a valid emailaddress!");
 
  $page->addItem("PasswordField","passwd","in_template");
  $page->m_items['passwd']->addValidation("NotEmpty","4");
  $page->m_items['passwd']->setSize("40");
  $page->m_items['passwd']->m_validationrule->setErrorMessage("Please enter passwd with at least 5 characters!");
 
  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();


  function processForm()
  {
    global $page;
    
    // check whether this account already exists
    // we skip this for now.
    
    if($page->subscribeUser($_POST['emailadres'],$_POST['passwd'],'user',$_POST['company']))
    {
      $page->login($_POST['emailadres'],$_POST['passwd'],"user");
      $page->forwardTo("subscribed.php");
    }  
    else
      $page->forwardTo("index.php");
  }
?>
