<?php
  ini_set("display_startup_errors",1);
  ini_set("display_errors",1);
  include_once("class.olympicPage.inc");
  
  // every page relies on the platformPage, in this case the olympicPage
  $page = new olympicPage();
  $page->mustBeUser("login.php");

  // presentation layer. actually an html page
  $page->setDefaultPage("judge.tpl");


  // first we get the schedule of the assigned round.
  $round_id = 1;
  $scheduleround = $page->getRoundSchedule($round_id);

  //  var_dump(count($scheduleround));
  for($i=0;count($scheduleround)>$i;$i++)
  {
    $players[$scheduleround[$i]['player_id']]=$scheduleround[$i]['surname'];
  }
  // first get the players of this session_id in sequence how it is scheduled.

  if(count($players)==0)
  {
    if($_GET['alternative'])
      $page->m_smarty->assign("message","The selected round is already judged, please choose another...");
    
    $page->m_smarty->assign("noplayers","true");
    
    $page->addItem("DropDown","roundname","in_template");
    $page->m_items['roundname']->changeOnSubmit();
    $page->m_items['roundname']->setValues($page->getRounds());
    $page->m_items['roundname']->startEmpty("------");
    $page->m_items['roundname']->addValidation("IsInt");
    $page->m_items['roundname']->m_validationrule->setErrorMessage("Please select a round");
  }
  else
  {
    $page->addItem("InputFieldNoEdit","roundname","in_template");
    $page->m_items['roundname']->setValue($scheduleround[0]['name']);
    $page->m_items['roundname']->setSize("20");
    
    $page->addItem("InputFieldNoEdit","roundhill","in_template");
    $page->m_items['roundhill']->setValue($scheduleround[0]['hill']);
    $page->m_items['roundhill']->setSize("20");

    $page->addItem("InputFieldNoEdit","kpoint","in_template");
    $page->m_items['kpoint']->setValue($scheduleround[0]['kpoint']);
    $page->m_items['kpoint']->setSize("20");

    $page->addItem("InputFieldNoEdit","meterpoint","in_template");
    $page->m_items['meterpoint']->setValue($scheduleround[0]['meterpoint']);
    $page->m_items['meterpoint']->setSize("20");

    // dropdown list with players 
//    $page->addItem("DropDown","players","in_template");
//    $page->m_items['players']->setValues($players);
//    $page->m_items['players']->addValidation("NotEmpty","0");
//    $page->m_items['players']->m_validationrule->setErrorMessage("Please select a player to judge");

    if($scheduleround['0']['occured']==1&&$scheduleround['0']['result_id']==null)
    {
      $page->m_smarty->assign("jumpes","This is the first jump");  
    }
    else
    {
      $page->m_smarty->assign("jumpes","This is the second jump");  
    }
    
    $page->addItem("InputFieldNoEdit","player","in_template");
    $page->m_items['player']->setValue($scheduleround['0']['surname']);
    $page->m_items['player']->setSize("20");
    $page->m_items['player']->addValidation("NotEmpty","0");

    $page->addItem("Hidden","players","in_template");
    $page->m_items['players']->setValue($scheduleround['0']['player_id']);
 
    $page->addItem("Hidden","scheduleid","in_template");
    $page->m_items['scheduleid']->setValue($scheduleround['0']['schedule_id']);
    
    // generate a random distance and set it, the user cannot change this
    $gamedata['type']=120;
    
    if($gamedata['type']==120)
    {
      $distance = rand(90,119);
      $meterpoint = 1.8;
      $kpoint = 118;
    }  
    else if($gamedata['type']==90) 
    {
      $distance = rand(80,89);
      $meterpoint = 2.0;
      $kpoint = 80;
    }  

    $speed = rand(87,92).".".rand(0,9);


    function calculateDistancePoints($distance,$kpoint,$meterpoint)
    {
      $distancepoints = ((($distance-$kpoint)*$meterpoint)+60);
      return round($distancepoints,1);
    }

    $distance.=".".rand(0,9);  

    $page->m_smarty->assign("meterpoint",$meterpoint);
    
    $page->addItem("InputFieldNoEdit","speed","in_template");
    $page->m_items['speed']->setValue($speed);
    $page->m_items['speed']->setSize("10");

    $page->addItem("InputFieldNoEdit","distance","in_template");
    $page->m_items['distance']->setValue($distance);
    $page->m_items['distance']->setSize("10");
   
    $page->addItem("InputFieldNoEdit","distancepoints","in_template");
    $page->m_items['distancepoints']->setValue(calculateDistancePoints($distance,$kpoint,$meterpoint));
    $page->m_items['distancepoints']->setSize("10");
    
    $page->addItem("InputField","grade1","in_template");
    $page->m_items['grade1']->addValidation("MinMaxFloat","1","60","1");
    $page->m_items['grade1']->setSize("10");
    $page->m_items['grade1']->m_validationrule->setErrorMessage("Please enter a grade with at most 1 decimals for judge # 1");
    
    $page->addItem("InputField","grade2","in_template");
    $page->m_items['grade2']->addValidation("MinMaxFloat","1","60","1");
    $page->m_items['grade2']->setSize("10");
    $page->m_items['grade2']->m_validationrule->setErrorMessage("Please enter a grade with at most 1 decimal for judge # 2");
    
    $page->addItem("InputField","grade3","in_template");
    $page->m_items['grade3']->addValidation("MinMaxFloat","1","60","1");
    $page->m_items['grade3']->setSize("10");
    $page->m_items['grade3']->m_validationrule->setErrorMessage("Please enter a grade with at most 1 decimal for judge # 3");
   
    $page->addItem("InputField","grade4","in_template");
    $page->m_items['grade4']->addValidation("MinMaxFloat","1","60","1");
    $page->m_items['grade4']->setSize("10");
    $page->m_items['grade4']->m_validationrule->setErrorMessage("Please enter a grade with at most 1 decimal for judge # 4");
   
    $page->addItem("InputField","grade5","in_template");
    $page->m_items['grade5']->addValidation("MinMaxFloat","1","60","1");
    $page->m_items['grade5']->setSize("10");
    $page->m_items['grade5']->m_validationrule->setErrorMessage("Please enter a grade with at most 1 decimal for judge # 5");
  }
   
 
  // show the page
  $page->showPlatformPage("processForm");

  // also show some debug information
  $page->printDebug();

  function processForm()
  {
    global $page;

    if($_POST['grade1']!="")
    {
      $result_id = $page->processResult($_POST);
      if($result_id!="")
      {
        $page->forwardTo("judgesummary.php?result_id=$result_id");
      }
      else
      {
        var_dump("Houston we have a problem....somethign went wrong");
      }
    }
    else
    {
      $page->forwardTo("judge.php?alternative=true");
    }
  }  
?>
