<?php
  class ruleIsInt extends rule
  {
    function ruleIsInt ($value = "")
    {
      debug("Initiated ruleIsInt object");
      $this->m_ruledata = $value;
    }

    function validate($data)
    {
      $this->m_data = $data;
      
      $bool = is_numeric($data);
      if($bool)
      {
        return true;
      }
      else
      {
        debug("ruleIsInt says: not valid value");
        return false;
      }
    }

  }
?>
