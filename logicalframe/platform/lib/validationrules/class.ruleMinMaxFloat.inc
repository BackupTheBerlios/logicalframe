<?php
     
    class ruleMinMaxFloat extends rule
    {
      function ruleMinMaxFloat($min,$max,$dec)
      {
        debug("Initiated ruleMinMaxFloat object");
        $this->m_ruledata_min = $min;
        $this->m_ruledata_max = $max;
        $this->m_ruledata_dec = $dec;
      }

    function validate($data)
    {
      $this->m_data = $data;
      
      $this->m_ruledata_min = (int) $this->m_ruledata_min;
      $this->m_ruledata_max = (int) $this->m_ruledata_max;
      $this->m_ruledata_dec = (int) $this->m_ruledata_dec;
      
      // may not be an empty string
      if(is_int($this->m_ruledata_min) && is_int($this->m_ruledata_max))
      {
        $numbers = explode(".",$this->m_data);
        $realdecimals = strlen($numbers[1]);

        if(($numbers[0]>=($this->m_ruledata_min)) && ($numbers[0]<=($this->m_ruledata_max))&&(($realdecimals<=$this->m_ruledata_dec)&&($numbers[0]<$this->m_ruledata_max)))
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
