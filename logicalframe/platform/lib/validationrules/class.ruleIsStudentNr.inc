<?php
  class ruleIsStudentNr extends rule
  {
    function ruleIsStudentNr($value)
    {
      debug("Initiated ruleIsStudentNr object");
      $this->m_ruledata = $value;
    }

    function validate($data)
    {
      $this->m_data = $data;
      
      $bool = ereg("[0-9]{7}[\.]{1}[A-Za-z]",$this->m_data);
      if($bool)
      {
        return true;
      }
      else
      {
        debug("RuleIsStudentNr says: not valid student number");
        return false;
      }
    }

  }
?>
