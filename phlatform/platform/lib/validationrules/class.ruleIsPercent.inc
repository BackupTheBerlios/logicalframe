<?php
  class ruleIsPercent extends rule
  {
    function ruleIsPercent($value)
    {
      debug("Initiated ruleIsPrecent object");
      $this->m_ruledata = $value;
    }

    function validate($data)
    {
      $this->m_data = $data;

      $this->m_ruledata = (int) $this->m_ruledata;
      $this->m_data = (int) $data;

      // may not be an empty string
      if(is_int($this->m_data))
      {
        if($this->m_data<=$this->m_ruledata)
        {
          return true;
        }
      }
      else if($this->m_data!="")
      {
        return true;
      }
        debug("ruleIsPercent says: the input is more then 100%");
        return false;
    }
  }
?>
