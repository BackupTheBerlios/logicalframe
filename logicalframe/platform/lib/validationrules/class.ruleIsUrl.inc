<?php
  class ruleIsUrl extends rule
  {
    function ruleIsUrl ($value = "")
    {
      debug("Initiated ruleIsUrl object");
      $this->m_ruledata = $value;
    }

    function validate($data)
    {
      $this->m_data = $data;

      
      $bool = ereg("http://.*\.*\..*",$this->m_data);
      if($bool)
      {
        return true;
      }
      else
      {
        debug("RuleIsUrl says: not valid email");
        return false;
      }
    }

  }
?>
