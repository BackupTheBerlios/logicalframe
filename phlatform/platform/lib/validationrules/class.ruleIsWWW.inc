<?php
  class ruleIsWWW extends rule
  {
    function ruleIsWWW($value)
    {
      debug("Initiated ruleIsWWW object");
      $this->m_ruledata = $value;
    }

    function validate($data)
    {
      $this->m_data = $data;
      
      $bool = ereg("^www\.[A-Za-z0-9_-]+[\.][A-Za-z0-9_-]",$this->m_data);
      if($bool)
      {
        return true;
      }
      else
      {
        debug("RuleIsWWW says: not valid webpage");
        return false;
      }
    }

  }
?>
