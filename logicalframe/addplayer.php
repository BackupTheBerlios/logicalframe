<?php
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");

  // every page relies on the platformPage, in this case the olympicPage
  $page = new olympicPage();

  // presentation layer. actually an html page
  $page->setDefaultPage("addplayer.tpl");

  $page->addItem("InputField","name","in_template");
  if($_POST['name']!="")
    $page->m_items['name']->setValue($_POST['name']);
  $page->m_items['name']->addValidation("NotEmpty","3");
  $page->m_items['name']->setSize("20");
  $page->m_items['name']->m_validationrule->setErrorMessage("please  provide a full Name");
 
  $page->addItem("InputField","height","in_template");
  if($_POST['height']!="")
    $page->m_items['height']->setValue($_POST['height']);
  $page->m_items['height']->addValidation("MinMaxFloat","0","240","2");
  $page->m_items['height']->setSize("10");
  $page->m_items['height']->m_validationrule->setErrorMessage("Please enter a height");
 
  $page->addItem("InputField","weight","in_template");
  if($_POST['weight']!="")
    $page->m_items['weight']->setValue($_POST['weight']);
  $page->m_items['weight']->addValidation("MinMaxFloat","0","240","1");
  $page->m_items['weight']->setSize("10");
  $page->m_items['weight']->m_validationrule->setErrorMessage("Please enter a weight");

  $page->addItem("Hidden","token","in_template");
  $page->m_items['token']->setValue("test");

  $countries = $page->getCountries();

  // check whether there is a teamplay and there is still room for a person/
  $page->addItem("DropDown","nationality","in_template");
  $page->m_items['nationality']->changeOnSubmit();
  $page->m_items['nationality']->setValues($countries);
  if($_POST['nationality']!="")
  {
    $page->m_items['nationality']->setDefaultValue($_POST['nationality']);
  }
  else
  {
    $page->m_items['nationality']->startEmpty("-------------");
  }

  $page->m_items['nationality']->addValidation("MinMaxFloat","0","240","1");
  $page->m_items['nationality']->m_validationrule->setErrorMessage("Please enter a nationality");

  
  if($_POST['nationality']!="")
  {
    $page->m_smarty->assign("selectednationality",$_POST['nationality']);
    $teamdata = $page->getTeamData($_POST['nationality']);
    $page->m_smarty->assign("memberamount",$teamdata[0]['memberamount']);
    if(count($teamdata)>0&&$teamdata[0]['memberamount']<=3)
    {
      // this player can join an existing team
      $page->addItem("CheckBox","addteam","in_template");
      $page->m_items['addteam']->setValues(array('1'=>"Add this player to team"));
      $page->m_items['token']->setValue("1");
    }
    else if(count($teamdata)>0&&$teamdata[0]['memberamount']>=4)
    {
      // this player can not be added to a team, it's full
      $page->m_smarty->assign("individual","The national team is already full, it is not possible to add this player to the team");
      $page->m_items['token']->setValue("1");
    }
    else
    {
      // team does not exists, do u want to create one?
      $page->addItem("CheckBox","createteam","in_template");
      $page->m_items['createteam']->setValues(array('1'=>"Create team"));
      $page->m_items['token']->setValue("1");
    }
  }
  $page->m_items['token']->addValidation("IsInt");

    // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();


  function processForm()
  {
    global $page;

    // insert player
    $player_id = $page->addPlayer($_POST);
    if($player_id!="")
    {
      if($_POST['addteam'])
      {
        // update
        $team_id = $page->incrementTeam($player_id,$_POST['nationality']);
        $page->assignTeamMember($player_id,$team_id);
      }
      else if($_POST['createteam'])
      {
        $team_id = $page->createTeam($_POST['nationality']);
        if($team_id!="")
        {
          $page->assignTeamMember($player_id,$team_id);
        }
      }
      else
      {
        // no teamplay, just individual
      }
      $page->forwardTo("addplayer.php");
    }
    else
    {
      debug(__CLASS__."::".__FUNCTION__." : something went wrong by inserting the player");
    }
  }
?>
