<?php
/****
* voor de manier waarop nu invisible fileobject is opgelost 
* kan beter door te controleren of het wat de waarde is van 
* het object wat hem invisible maakt
***/
  class ruleIsFile extends rule
  {
    function ruleIsFile($value)
    {
      debug("Initiated ruleIsFile object");
      $this->m_ruledata = $value;
    }

    function validate($data)
    {
      if(is_array($data))
      {
        $this->m_data = $data;
        if (is_array($this->m_ruledata))
        {
          // check file type extensions
          $ext = $this->m_data["name"];
          if (!(boolean) (strstr($ext,".")))
          {
            debug("RuleIsFile says: the file has no extention");
            return false;
          }
          else
          {
            while ((boolean) (strstr($ext,".")))
            {
              $ext = strstr($ext,".");
              $ext = substr($ext,1);
            }


            $x = 0;
            while ((!$ext == $this->m_ruledata[$x]) and ($x<$this->m_ruledata.length))
            {
              $x++;
            }

            if(!in_array($ext,$this->m_ruledata))
            {
            	debug("RuleIsFile says: the file has a wrong extention");
             	return false;
            }
            
            if(!file_exists($this->m_data["tmp_name"]))
            {
              debug("RuleIsFile says: the file doesn't exist");
              return false;
            }
            
            if (filesize($this->m_data["tmp_name"]) != ($this->m_data["size"]))
            {
              debug("RuleIsFile says: wrong filesize");
              return false;
            }
            
            debug("RuleIsFile says: Fileupload OK");
            return true;
           }
         }
      }
      else
      {
      	 return false;
      }
    }
     
  }
?>
