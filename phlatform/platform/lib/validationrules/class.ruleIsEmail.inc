<?php
  class ruleIsEmail extends rule
  {
    function ruleIsEmail($value = "")
    {
      debug("Initiated ruleIsEmail object");
      $this->m_ruledata = $value;
    }

    function validate($data)
    {
      $this->m_data = $data;
      
      $bool = ereg("[A-Za-z0-9_-]+([\.]{1}[A-Za-z0-9_-]+)*@[A-Za-z0-9-]+([\.]{1}[A-Za-z0-9-]+)+",$this->m_data);
      if($bool)
      {
        return true;
      }
      else
      {
        debug("RuleIsEmail says: not valid email");
        return false;
      }
    }

  }
?>
