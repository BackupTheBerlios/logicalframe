<?php
include_once("platform/class.platformpage.inc");
  /**
   * This is the base class deviation for the olympic, it contains all the fundamental framework functionality
   */
  class olympicPage extends platformPage
  {
    /**
     * member variables
     */
    var $m_offset;/*{{{*/
    var $m_version = "0.1";
    var $m_documentroot;
    /*}}}*/


    
    /**
     * constructor
     */
    function olympicPage()/*{{{*/
    {
      // - this is platform related, do not mind
      parent::platformPage(); 

      if(isset($PHP_SELF))
       $this->m_smarty->assign("currentpage",$PHP_SELF);
      // - this is platform related, do not mind

      /**
       * we use the theme soundlounge 
       */
      $this->setTheme("olympics");
      $this->m_documentroot = dirname($_SERVER['SCRIPT_FILENAME']);
      
      $this->debug("Initialising member settings");
      
      $this->m_smarty->assign("role",$this->getUserRole());
    }/*}}}*/

    /**
     * 
     */
    function subscribeUser($emailadress,$passwd,$user,$company)
    {
      $this->useDb();
      $query="INSERT into users 
                   (company,email,passwd,role)
              VALUES('".$company."','".$emailadress."','".$passwd."','".$user."')";
      return $this->m_db->query($query);
    }


    /**
     * 
     */
    function getRoundSchedule($round_id)
    {
      debug(__CLASS__."::".__FUNCTION__." : <b>here</b>");
      $this->useDb();
      $query="SELECT 
                   rounds.round_id,
                   rounds.name,
                   rounds.startdate,
                   rounds.enddate,
                   ktypes.ktype_id,
                   ktypes.kpoint,
                   ktypes.meterpoint,
                   ktypes.hill,
                   schedules.schedule_id,
                   schedules.player_id,
                   schedules.timestamp,
                   schedules.team_id,
                   schedules.round_id,
                   schedules.ktype_id,
                   players.player_id,
                   players.surname,
                   count(*) as occured,
                   results.result_id
                  FROM
                    rounds LEFT JOIN schedules on (schedules.round_id = rounds.round_id)
                                  LEFT JOIN players on ( schedules.player_id = players.player_id)
                                  LEFT JOIN ktypes on (schedules.ktype_id = ktypes.ktype_id)
                                  LEFT JOIN results on (schedules.player_id = results.player_id) 
                   WHERE 
                    rounds.round_id = $round_id
                  GROUP BY players.surname
                  HAVING  occured < 2
                  ORDER BY  schedules.timestamp desc, occured asc";

      $resultset = $this->m_db->getall($query,DB_FETCHMODE_ASSOC);          
      return $resultset;
    }

    /**
     * 
     */
    function getRounds()
    {
      $this->useDb();
      $query="SELECT
               round_id,
               name 
              FROM 
               rounds";   
      $resultset = $this->m_db->getAssoc($query);          
      return $resultset;
    }


    /**
     * 
     */
    function processResult($data = array())
    {
      extract($data);


      // dirty but quick
      $grades[1]=(float) $grade1;
      $grades[2]=(float) $grade2;
      $grades[3]=(float) $grade3;
      $grades[4]=(float) $grade4;
      $grades[5]=(float) $grade5;
      
      $sorted = sort($grades);


      // only add the 2nd 3rd 4th marks
      $judgespoints = $grades[1]+$grades[2]+$grades[3];
      $totalpoints = $judgespoints + $distancepoints;
      
      $query= "INSERT INTO 
                `results` (`schedule_id`,`player_id` , `speed` , `distance` , `distancepoints` , `mark1` , `mark2` , `mark3` , `mark4` , `mark5` , `judgespoints`, `totalpoints` )
                 VALUES ('$scheduleid','$players', '$speed', '$distance', '$distancepoints', '$grade1', '$grade2', '$grade3', '$grade4', '$grade5', '$judgespoints','$totalpoints')";
      $this->useDb();
      if($this->m_db->query($query))
      {
        $result2 = $this->m_db->getAll("SELECT LAST_INSERT_ID() as last_id",DB_FETCHMODE_ASSOC);
        return $result2[0]['last_id'];
      }
      else
      {
      }
    }


    
    /**
     * 
     */
    function login($email,$passwd,$user)
    {
      $this->useDb();
      $query="SELECT * FROM users WHERE email='".$email."' and passwd='".$passwd."'";
      $resultset = $this->m_db->getAll($query,DB_FETCHMODE_ASSOC);
      if(count($resultset)==1)
      {
        // set it into the register
        $this->m_sessionManager->setValue("role",$resultset[0]['role']);
        $this->m_sessionManager->setValue("email",$resultset[0]['email']);
        $role = $this->m_sessionManager->getValue("role");
        $regemail = $this->m_sessionManager->getValue("email");
        $this->debug("login: user regged as ". $role ."with email:".$regemail);
        return true;
      }
      else
        return false;
    }

    /**
     * 
     */
    function getResult($result_id)
    {
      $this->useDb();

      $query="SELECT * FROM results WHERE result_id='".$result_id."'";
      
      $resultset = $this->m_db->getAll($query,DB_FETCHMODE_ASSOC);
      if(is_array($resultset))
      {
        return $resultset[0];
      }
      else
      {
        debug(__CLASS__."::".__FUNCTION__." : result could not be fetched from the database...");
      }
    }



    
    /**
     * 
     */
    function registerAdmin($admin_id)/*{{{*/
    {
      if($admin_id!="")
      {
        $this->m_sessionManager->setValue("admin_id",$admin_id);
        $registered_id = $this->m_sessionManager->getValue("admin_id");
        $this->debug("registerAdmin: admin id registered with ". $registered_id);
      }
      else
      {
        return PEAR::raiseError("registerAdmin requires a valid id");
      }
    }/*}}}*/

    /**
     * 
     */
    function unregisterUser()/*{{{*/
    {
        $this->m_sessionManager->setValue("role","");
        $this->m_sessionManager->setValue("email","");
    }/*}}}*/

    /**
     * Get the admin id
     *
     * @return admin_id if there's any, otherwise false;
     */
    function getUserRole()/*{{{*/
    {
        $role = $this->m_sessionManager->getValue("role");
        if($role!="")
        {
          $this->debug("getting role ".$role);
          return $role;
        }
        else
        {
          return false;
        }
    }/*}}}*/

    /**
     * 
     */
    function mustBeAdmin($page)/*{{{*/
    {
      if($this->getAdminId()=="")
      {
        $this->debug("MustBeAdmin :: you're not registered as admin, forwarding u to index.php");
        $this->forwardTo($page);
      }
    }/*}}}*/

    /**
     * 
     */
    function mustBeUser($page)/*{{{*/
    {
      if($this->getUserRole()=="")
      {
        $this->debug("MustBeUser:: you're not registered as admin or user");
        $this->forwardTo($page);
      }
    }/*}}}*/

    



    /**
     *  use this for class specific debugging
     *  Primarly used for application level debugging, not for platform related things.
     */
    function debug($info)/*{{{*/
    {
      $sClassname = get_class($this);
      debug("<b>".$sClassname." : ".$info."</b>");
    }/*}}}*/

    
    /**
     * 
     */
    function _olympicPage()
    {
      //var_dump("destructor in olympicPage");
    }
  }
?>
