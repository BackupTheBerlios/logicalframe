<?php
  /**
  * Author: Trung Huynh 0532530@student.hro.nl 
  *
  * In order the let this sessionmanager work correctly
  * you have to enable register_globals on in your php.ini
  */

  class sessionManager
  {
    var $m_sessionTable;    // the table name
    var $m_sessionField;    // the unique table field for sessionID's
    var $m_sessionIpField;    // the ip of the visitor
    var $m_currentSessionID;//
    var $m_maxLifeTime;     // the max life time of the set cookie
    var $m_visitorsIp;      

   /**
    * constructor
    */
    function sessionManager()
    {
      global $_COOKIE, $g_registered; 
      $this->getClientIP();


      /**
      *  cookie is not set, so set the damn cookie
      *  FUCK INTERNET EXPLORER, FUCK GATES
      *  
      *  
      */
      if((isset($_COOKIE['PHPSESSID']))&&$_COOKIE['PHPSESSID']=="")
      {
        // var_dump($_COOKIE);
        $uniqueid = $this->generateUniqueID();
        session_id($uniqueid);
        $this->startSession();
      }
      else
      {
        //var_dump($_COOKIE);
        /**
        * resume the session
        */
        $this->startSession();
        debug(__CLASS__."::".__FUNCTION__." : resuming the session");
      }
    }
   
    /**
    * private member function
    */
    function startSession()
    {
      session_start();
      $this->m_currentSessionID=session_id();

      // this is for register_globals on
      // session_register("g_registered");
    }
    
    /**
    * dummy function
    */
    function hello()
    {
      echo "session manager says hello";
    }
    
   /**
    * Creates a new session
    * if there already is a session_id, it will kill it first and creates a new one.
    */
    function newSession()
    {
      // first check whether there's an session_id
      // cookie monster will eat your cookie
      if($_COOKIE['PHPSESSID']!=""&&$this->getCurrentSessionID);
      {
        $this->endSession();
        $uniqueid= $this->generateUniqueID();
        session_id($uniqueid);
        $this->startSession();
        //session_register("g_registered");
      }
    }
   
    function setSessionTable($i_table){  $this->m_sessionTable = $i_table; }
    function setSessionField($i_field){  $this->m_sessionField = $i_field; }
    function setSessionIpField($i_field){ $this->m_sessionIpField = $i_field; }

   /**
    * 
    */
    function setValue($key, $value)
    {
      $_SESSION[$key] = $value;
      debug("class.sessionmanager.inc::setValue: setting: $key"); 
    }
 
   /**
    *
    */
    function getValue($var)
    {
      debug("class.sessionmanager.inc::getValue: getting value...$var");
      if(isset($_SESSION[$var]))
        return $_SESSION[$var];
      else
        return false;
    }

   /**
    *
    */
    function getClientIP()
    {
      if (getenv('HTTP_X_FORWARDED_FOR'))
      {
        $this->m_visitorsIp = getenv('HTTP_X_FORWARDED_FOR');
      }  
      else $this->m_visitorsIp = getenv('REMOTE_ADDR');
      return $this->m_visitorsIp;
    }


   /**
    * tends to create an unique id and returns the value. 
    */
    function generateUniqueID()
    { 
      $unique = md5($this->m_visitorsIp.time()); 
      return $unique;
    }


   /**
    * First unset each registered variable, after that, kill the session.
    * kill session id, 
    */
    function endSession()
    {
      session_unset();
      if(session_destroy())
      {
        unset($this->m_currentSessionID);
        return true;
      }
    }

   /**
    *
    */
    function getCurrentSessionID()
    {
      return session_id();
    }
  }
?>
