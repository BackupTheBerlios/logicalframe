<?php
  class ruleNotEmpty extends rule
  {
    function ruleNotEmpty($value)
    {
      debug("Initiated ruleNotEmpty object");
      $this->m_ruledata = $value;
    }

    function validate($data)
    {
      $this->m_data = $data;
      
      $this->m_ruledata = (int) $this->m_ruledata;
      // may not be an empty string
      if(is_int($this->m_ruledata))
      {
        if((strlen($this->m_data)>($this->m_ruledata)))
        {
          return true;
        }
      }
      else if($this->m_data!="")
      {
        return true;
      }
        debug("RuleNotEmpty says: the input is invalid");
        return false;
    }
  }
?>
