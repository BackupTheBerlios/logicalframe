<?php
  require_once("class.item.inc");

  class FileUpload extends item
  {
    var $m_name = "fileUpload";

  	function FileUpload($name,$template="")
    { 
      $this->item($name);
      debug("initiate itemFileUpload object");
      $this->m_name = $name;
  	}
		
		function setSize($size)
    {
      $this->m_size = $size;
    }
		
    function checkInput()
    {
      if(is_array($this->m_value))
      {
        if((array_key_exists('name',$this->m_value))&&(array_key_exists('type',$this->m_value))&&
          (array_key_exists('tmp_name',$this->m_value))&&(array_key_exists('size',$this->m_value)))
          {
             if(is_object($this->m_validationrule))
             {
               if($validateresult = $this->m_validationrule->validate($this->m_value))
               {
                  return true;
               }
               else
               {
                  $this->m_errormessage = $this->m_validationrule->getErrorMessage();
                  return false;
               }
             }
            else
            {
              debug("Er is geen validatie aan gekoppeld, het zal wel goed zijn");
              return true;
            }
          }
          else
          {
            debug("class:itemFileUpload.inc::checkInput:: this->m_value is geen upload array");
            return false;
          }
      }
      else
      {
        debug("class:itemFileUpload.inc::checkInput:: this->m_value is geen array");
        return false;
      }
    }
			
    function show()
    {
      $this->m_item="";
      if($this->m_value!="")
      {
        $value=$this->m_value;
      }
      $this->m_item.="<input name=\"".$this->m_name."\" type=\"file\" size=\"".$this->m_size."\">&nbsp;";
      return $this->m_item;
    }
  }	
?>
