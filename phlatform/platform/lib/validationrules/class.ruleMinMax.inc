<?php

    class ruleMinMax extends rule
    {
    
        function ruleMinMax($min,$max)
        {
      debug("Initiated ruleMinMax object");
      $this->m_ruledata_min = $min;
      $this->m_ruledata_max = $max;
    }

    function validate($data)
    {
      $this->m_data = $data;
      
      $this->m_ruledata_min = (int) $this->m_ruledata_min;
      $this->m_ruledata_max = (int) $this->m_ruledata_max;
      
      // may not be an empty string
      if(is_int($this->m_ruledata_min) && is_int($this->m_ruledata_max))
      {
        if((strlen($this->m_data)>=($this->m_ruledata_min)) && (strlen($this->m_data)<=($this->m_ruledata_max)))
        {
          return true;
        }
      }
      else if($this->m_data!="")
      {
        return true;
      }
        debug("ruleMinMax says: the input is invalid");
        return false;;
    }
  }
?>
