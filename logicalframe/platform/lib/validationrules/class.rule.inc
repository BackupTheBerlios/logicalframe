<?php
  /**
  *  This is the basic of a validation rule
  */
  class rule
  {
    var $m_rulename;
    var $m_ruledata;
    var $m_data;
    var $m_errormessage;

    function rule()
    {
      debug("Initiating a object validation rule...");
    }
      
    function setErrorMessage($errormessage)
    {
      $this->m_errorMessage = $errormessage;
    }

    function getErrorMessage()
    {
      return $this->m_errorMessage;
    }

    function validate()
    {
      //abstract
    }
  }
?>
