<?php
ini_set("display_errors",1);
// first we include the platform_functions.inc for debugging
require_once("platform/lib/platform_functions.inc");
// this is the debug info array, it's global
$g_debuginfo = array();
// secondly we include the class.libarian.inc for easy file inclusion
require_once("platform/lib/class.libarian.inc");

$libary= new libarian();
$includepathdirs = array("/platform/pear","/platform/lib/smarty");
$libary->includeDir($includepathdirs);
require_once("DB.php");
require_once("PEAR.php");

// load every class file in the following dirs
$libary->loadDir("platform");
$libary->loadDir("platform/lib/");
$libary->loadDir("platform/lib/pageitems");
$libary->loadDir("platform/lib/validationrules");

// the smarty template engine
require_once("platform/lib/smarty/Smarty.class.php");
// the configs.
require_once("misc/configs/config.inc.php");	

  /** 
   *  The platformpage
   * 
   * @author Trung Huynh
   * @version 
   */
  class platformPage extends PEAR
  {
    var $m_name;
    var $m_items = array(); 
    var $m_smarty; 
    var $m_db;
    var $m_sessionManager;
    var $m_page;
    var $m_template;
    var $m_errormessages;
    var $m_defaultpage;
    var $m_secondpage;
    var $m_validdata;
    var $m_enctype;
    var $m_redirectpage;
    var $m_forwardpage;
    var $m_comefrompage;
    var $m_management;
    var $m_objectdepend;
    var $m_novalidation="false";
    var $m_getvars;
    var $m_themedir;
    var $m_visitorsIp;

    function platformPage($tpl="")
    {
      global $config, $g_db, $PHP_SELF,$g_libmaster,$SCRIPT_FILENAME;
      $this->PEAR();
      $this->m_sessionManager = new sessionManager();
      $sessionid = $this->m_sessionManager->getCurrentSessionID();
      debug(__CLASS__."::".__FUNCTION__." : initiate a platformPage object... session_id =".$sessionid);
      $this->useSmarty(); 

      if((eregi($this->getClientIP(),$this->getConfigVar('debugips'))==1)&&$this->getConfigVar('smartydebug'))
      {
        $this->m_smarty->debugging = false; 
  //     $this->m_smarty->debugging = true; 
      }
    }

    /**
    * formValidator()
    *
    * This private function checks whether which action has to 
    * be taken for the current object.
    */
    function _formValidator()
    {
      global $_POST,$alreadyfilled,$previousObject,$_FILES,$PHP_SELF;
      global $itemName, $itemObject,$postvars;

      // There was an form an the previous page.
      if((isset($_POST["action"]))&&$_POST["action"]=="save")
      {
        // referre to the items objects
        // $usedItems = &$previousObject->m_items;
        $usedItems = &$this->m_items;
        
        // get the postvars
        $postvars = $this->getPostVars();

        if(count($usedItems)>0)
        {
          foreach($usedItems as $itemName=>$itemObject)
          {
            // first we map the postvars
            $this->mapPostVar();
          
            // checking the input
            if(!$itemObject->checkInput())
            {
              // there's something wrong with the input, so fetch the errors
              $this->m_errormessages[] = $itemObject->getErrors();
            }
            else
            {
              // these are the values that were filled in correctly.
              $alreadyfilled[$itemName] = $itemObject->getValue();
            }
          }
        }

        // the items doesn't have valid values. show the errors
        if(count($this->m_errormessages>0)&&((is_array($this->m_errormessages))))
        {
          // this is needed to get the form back with prefilled values.
          // $this->definePage();
          
          if(is_array($alreadyfilled)&&count($alreadyfilled)>0)
          {
            foreach($alreadyfilled as $itemName=>$itemValue)
            {
              foreach($this->m_items as $t_itemName=>$t_itemOject)
              {
                if($itemName==$t_itemName)
                {
                  $this->m_items[$itemName]->setValue($itemValue);
                  if($this->m_items[$itemName]->gotTemplate())
                  { 
                    $itemhtml="";
                    $itemhtml= $this->m_items[$itemName]->show();
                    $itemtag="item_".$itemName;
                    $this->m_smarty->assign($itemtag,$itemhtml);
                  }  
                }  
              }
            }
          }
          // show the errors
          $this->showFormErrors();
          // show the inputs that were correctly inserted.
          
        }
        else
        {
          foreach($usedItems as $itemName=>$itemObject)
          { 
            
            $this->mapPostVar();
            /**
            if(key_exists($itemName,$postvars))
            {
              $itemObject->setValue($postvars[$itemName]);
            }
            else
            {
              $itemObject->setValue($_FILES[$itemName]);
            }
            */
            $this->m_validdata[$itemName]= $itemObject->getValue();
          }

         if($PHP_SELF!="NULL")
         {
            $ses_id = $this->m_sessionManager->getCurrentSessionID();
            $client_ip = $this->m_sessionManager->getClientIP();

            $page_name = (basename($PHP_SELF));
            $keypage = md5($ses_id.$client_ip.$page_name);
            
            /**
            $this->m_comefrompage = $keypage;
            debug("All information have passed the validation engine ...");
            debug("So, setting the unique page id...$keypage in the sessionmanager");
            $this->m_sessionManager->setValue("previouspage_id",$keypage);
            */
         }
       } 
      } 
      else
      {
         // $this->definePage();
        //$this->display();
      }
    }

    function mapPostVar()
    {
      global $itemName,$postvars,$itemObject,$_FILES;
      
      if(phpversion() < '4.1')
      {
        if(key_exists($itemName,$postvars))
        {
          $itemObject->setValue($postvars[$itemName]);
        }
        else
        {
          $itemObject->setValue($_FILES[$itemName]);
        }
      }
      else
      {
        if(array_key_exists($itemName,$postvars))
        {
          $itemObject->setValue($postvars[$itemName]);
        }
        else
        {
          $itemObject->setValue($_FILES[$itemName]);
        }
      }
    }


    function setDefaultPage($i_defaultpage)
    {
      debug(__CLASS__."::".__FUNCTION__." : Default page setted with $i_defaultpage... ");
      $this->m_defaultpage = $i_defaultpage;
    }

    function setTheme($theme)
    {
      debug(__CLASS__."::".__FUNCTION__." : Theme setted with $theme... ");
      $this->m_themedir = $theme."/";
    }
    
    function setSecondPage($i_secondpage)
    {
      debug(__CLASS__."::".__FUNCTION__." : Second page setted with $i_secondpage...");
      $this->m_secondpage = $i_secondpage;
    }

    function mustComeFrom($previouspage)
    {
      debug(__CLASS__."::".__FUNCTION__." : $previouspage");
      $this->m_sessionManager->setValue("previouspage",$previouspage);
    }

    /**
    * This function will decide whether which page has to be displayed in which manner.
    */
    function showPlatformPage($functionname="")
    {
      global $_POST;

      // Stage 1::construct the items
      $this->constructItems();

      // Stage 2::check the items postvars against the validation rules
      // $valid = $this->_formValidator();
      $this->_formValidator();

      // check whether inputs were correct.
      if(count($this->m_validdata)>0&&is_array($this->m_validdata))
      {
        // first we check whether it must go to another page
        if($this->m_sessionManager->getValue("previouspage")!="")
        {
          $prev = $this->m_sessionManager->getValue("previouspage_id");

          $ses_id = $this->m_sessionManager->getCurrentSessionID();
          $client_ip = $this->m_sessionManager->getClientIP();
          $previouspage = $this->m_sessionManager->getValue("previouspage");
      
          $keypage = md5($ses_id.$client_ip.$previouspage);

          // we're one the second page
          if($prev==$keypage)
          { 
            $this->dataManipulation($functionname);
            //reset the previouspage
            $this->m_sessionManager->setValue("previouspage","");
            $this->forwardTo($this->m_forwardpage);
            exit();
          }
          // we're one the first page
          else
          {
            $this->dataManipulation($functionname);
            $this->forwardTo($this->m_forwardpage);
            exit();
          }
        }
        else if($this->m_forwardpage!="")
        { 
            $this->dataManipulation($functionname);
            $this->forwardTo($this->m_forwardpage);
            exit();
        }
        // second, we checkt whether page must reload itself but now with a different tpl file
        else if($this->m_secondpage)
        {
          $pagetogo = $this->m_secondpage;
        }
      }
      else if($this->m_novalidation=="true")
      {
        $this->dataManipulation($functionname);

        if($this->m_forwardpage!="")
        { 
            $this->forwardTo($this->m_forwardpage);
            exit();
        }
        else
        {
          $pagetogo = $this->m_themedir.$this->m_defaultpage;
        }
      }
      else
      {
        // if there are prefilled inputfields. construct here.
        $pagetogo = $this->m_themedir.$this->m_defaultpage;
      }
      // still not set?  fuck it, just set it to the defaultpage
      if($pagetogo==NULL) $pagetogo = $this->m_themedir.$this->m_defaultpage;

      $this->dataManipulation($functionname);
      $this->m_smarty->display($pagetogo);
      debug(__CLASS__."::".__FUNCTION__." : exposing smarty compiled page");
    }

    function noValidation()
    {
      $this->m_novalidation="true";
    }

    function nextPage()
    {
      $this->forwardTo($this->m_forwardpage);
    }
   

    /**
    *
    */
    function dataManipulation($i_functionparam)
    {
      if(is_array($this->m_validdata))
      {
        call_user_func($i_functionparam);
        debug(__CLASS__."::".__FUNCTION__." : calling the user defined $i_functionparam function");
      }  
    }

    function forwardTo($goto)
    {
      $dir = dirname($_SERVER[PHP_SELF]);
      header("Location: http://$_SERVER[SERVER_NAME]$dir/$goto");

      // this is for berlios
      //header("Location: http://$_SERVER[SERVER_NAME]$dir$goto");
      exit();
    }
    

    function setFormEnctype($option)
    {
      switch ($option)
      {
        case "file":
          $this->m_enctype="multipart/form-data";
          break;
        default:
        break;
      }
    }

    function setAction($page)
    {
      $this->m_redirectpage = $page;
    }
      
    function setForwardPage($page)
    {
      $this->m_forwardpage = $page;
    }
  
    /*
    * maintains the getvars for forms
    *
    **/
    function maintainGetVars()
    {
      $this->m_getvars = true;
    }
  
    /**
    *
    */
    function constructItems()
    {
      global $PHP_SELF,$config,$HTTP_GET_VARS;
     
      if($this->m_items)
      {
        if($this->m_redirectpage=="")
        {
          $action = $PHP_SELF;
        }
        else
        {
          $action = $this->m_redirectpage;
        }
        
        if($this->m_enctype!="")
        {
          $filenctype = "enctype=\"".$this->m_enctype."\"";
        }  
        
        if($this->m_getvars!="")
        {
          $getvars_string="?";
          
          foreach($HTTP_GET_VARS as $key=>$val)
          {
            $getvars_string.=$key."=".$val;
          }
          
          $action.=$getvars_string;
        }

        $form_begin ="<form name=\"".$this->m_name."\" action=\"".$action."\" method=\"post\" ".$filenctype.">\n";
        $form_begin.="<input type=\"hidden\" name=\"action\" value=\"save\" >";
        $form_end ="</form>";

        $this->m_smarty->assign("form_begin",$form_begin);
        $this->m_smarty->assign("form_end",$form_end);

        while(list($key,$val)=each($this->m_items))
        { 
          if($this->m_items[$key]->gotTemplate())
          { 
            $itemhtml="";

            $itemhtml= $this->m_items[$key]->showItem($this->getConfigVar('requiresign'));
            $itemtag="item_".$key;

            $this->m_smarty->assign($itemtag,$itemhtml);
          }
          else
          {
            debug("error, this item doesn't belong to a template");
          }  
        }
      }
    }

    /**
     * This function sets the name of the form
     */
    function setFormName($name) 
    {
      if(isset($name))
      {
        $this->m_name = $name;
        debug(__CLASS__."::".__FUNCTION__." : set the formname to $name ");
      }
    }

    /**
    * 
    */
    function showFormErrors()
    {
      $error_messages=&$this->m_errormessages;
      if(count($error_messages)>0&&is_array($error_messages))
      {
        foreach($error_messages as $key=>$value)
        {
          $errors.=$value."<br>";
        }
      }
      if($errors!="")
      {
        $this->m_smarty->assign("errors",$errors);
        debug(__CLASS__."::".__FUNCTION__." : assigning form errors to the template");
      }
    }


    function getFormData()
    {
      debug(__CLASS__."::".__FUNCTION__." : returning the form data ");
      return $this->m_validdata;
    }

    function getPostVars()
    {
      debug(__CLASS__."::".__FUNCTION__." : returning postvars");
      return $_POST;
    }
    
    /**
    * useDb
    *
    * An platform page has the ability to use the database.
    * use this method to establish an connection.
    * The main reason of making this a method rather than a
    * automatic procedure is that not every platformPage needs an
    * database connection. It could be that another inherited platformPage 
    * has already an open connection with the database. In that case the DB object 
    * of PEAR is clever enough to use that object rather inistanitiate a new one.
    */
    function useDb()
    {
      global $config;

      if(!is_object($this->m_db))
      {
        $db = DB::connect($config["dbma"]."://".$config["db_user"].":".$config["db_passwd"]."@".$config["db_host"]."/".$config["db"]);
        if(PEAR::isError($db))
        {
          debug(__CLASS__."::".__FUNCTION__." : ".$this->m_db->getMessage());
        }
        else if(is_object($db))
        {
          $this->m_db=&$db; 
          debug(__CLASS__."::".__FUNCTION__." : connected to database ");
        }
      }
      else
      {
        debug(__CLASS__."::".__FUNCTION__." : database connection already made, using existing db object");
      }
    }


    /**	
    * addItem
    *
    * Adds a item object to this page. such as a textArea or an dropdown list,
    * checkboxes etc. The added item must an object deriviated from
    * the base class (item/class.item.inc)
    */
    function addItem($typeitem, $itemname, $template="")
    {
      global $g_libmaster;
      $this->m_items[$itemname]= new $typeitem($itemname,$template);
      if(is_object($this->m_items[$itemname]))
      {
        debug(__CLASS__."::".__FUNCTION__." : ".$typeitem." added as ".$itemname);
        return true;
      }
      else
      {
        debug(__CLASS__."::".__FUNCTION__." : Item class could not added or not be found");
        // PEAR HERE
        halt();
      }
    }


    /**
    *
    * This is actually an class wrapper. 
    * The smarty object resides in the $this->m_smarty
    *
    * Templates should be in directory templates
    */
    function useSmarty()
    {

      // ???
//        $this->m_template = $tpl;
        $smarty = new Smarty();
        if(is_object($smarty))
        {
          $this->m_smarty = $smarty;
          debug(__CLASS__."::".__FUNCTION__." : smarty object created");
          return true;
        }
        else
        {
          debug(__CLASS__."::".__FUNCTION__." : smarty object <blink>NOT</blink>created");
          return false;
        }
    }
    
    
    /**
    * printDebug
    *
    * prints the debug information on the page along with the normal layout.
    * This function should be called at the very last moment, otherwise it will break the layout.
    */
    function printDebug()
    {
      global $g_debuginfo, $config;
      
 //     $ip = $this->getClientIP();
 //     if($ip == "62.238.226.167")
 //     {
 //       if($config['debug']==2)
 //       {
          echo "<br><br>";
          echo '<b>platform debug: </b>'.implode("<b><br>\nplatform debug: </b>",$g_debuginfo);
          echo "<p>";
 //       }  
 //     }
    }


   /**
    *
    */
    function getClientIP()
    {
      if (getenv('HTTP_X_FORWARDED_FOR')!="")
      {
        $this->m_visitorsIp = getenv('HTTP_X_FORWARDED_FOR');
      }
      else
      {  
        $this->m_visitorsIp = getenv('REMOTE_ADDR');
      }  
      return $this->m_visitorsIp;
    }


    /**
    * Gets a config var 
    */
    function getConfigVar($var)
    {
      global $config;
      if($config[$var]!="") return $config[$var];
      else
      {
        return false;
      }
    }


    /**
     * 
     */
    function _platformPage()
    {

    }

    
  }   
?>
