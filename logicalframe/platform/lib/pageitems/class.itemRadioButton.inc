<?php
  /**
  * This item class creates an Radio button
  */
  
  require_once("class.item.inc");

  class RadioButton extends item
  {
    //var $m_maxlength = "40"; laten we even staan als voorbeeld
    
  	function Radiobutton($name,$template="")
    { 
      $this->item($name);
      debug("initiate RadioButton object");
      $this->m_name = $name;
  	}

    function setCheckedValue($checkedvalue)
    {
      $this->m_value=$checkedvalue;
    }
    
    function show()
    {
      $this->m_item="<table width=\"100%\">";
      foreach($this->m_valuelist as $value=>$extra)
      {
      $checked="";
        if($value==$this->m_value)
        {   
          $checked="checked";
        }
  		  $this->m_item.="<tr>
                        <td width=\"100%\" valign=\"middle\" class=\"formtext\">".$extra."
                        <input type=\"radio\" name=\"".$this->m_name."\" value=\"".$value."\" ".$checked."></td></tr>";
      } 
      $this->m_item.="</table>";
      return $this->m_item;
    }
  }	
?>
