<?php
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");

  $page = new olympicPage();
  $page->mustBeUser("login.php");

  // presentation layer. actually an html page
  $page->setDefaultPage("search.tpl");

  $page->addItem("InputField","search","in_template");
  $page->m_items['search']->addValidation("NotEmpty","2");
  $page->m_items['search']->setSize("30");
  $page->m_items['search']->m_validationrule->setErrorMessage("Please provide an search term with at least 3 characters...");

 
  $page->addItem("RadioButton","criteria","in_template");
  $page->m_items['criteria']->setValues(array("players.surname"=>"name","countries.country"=>"nationality","players.history"=>"history"));
  $page->m_items['criteria']->addValidation("NotEmpty","1");
  $page->m_items['criteria']->m_validationrule->setErrorMessage("Please select one of the search criterion");


  if(count($_GET)>0)
  {
     $results =  $page->searchOn($_GET['criteria'],$_GET['search']);
     $page->m_smarty->assign("results",$results);
  }
  
  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();


  function processForm()
  {
    global $page;

    if($_POST!="")
    {
     $results =  $page->searchOn($_POST['criteria'],$_POST['search']);
     if(count($results)>0)
     {
       //forward
       $forwardstring = "search.php?criteria=".$_POST['criteria']."&search=".$_POST['search'];
     }
     else
      {
       $forwardstring = "search.php?noresults=true";
      }
    $page->forwardTo($forwardstring);
    }
  }
?>
