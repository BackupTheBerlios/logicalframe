<?php
  /**
  * 
  *
  */
  require_once("class.item.inc");

  class PasswordField extends item
  {
    var $m_maxlength = "40";
    var $m_size = "42";
        
  	function PasswordField($name,$template="")
    { 
      $this->item($name);
      debug("initiate PasswordField object");
      $this->m_name = $name;
  	}
  				
    function setMaxLength($i_max)
    {
      $this->m_maxlength=$i_max;
    }
    
    function setSize($i_size)
    {
      $this->m_size=$i_size;
    }
       
    function show()
    {
      $this->m_item="";
      
  		$this->m_item .="<input type=\"password\" name=\"".$this->m_name."\" size=\"".$this->m_size."\" maxlength=\"".$this->m_maxlength."\">";
      return $this->m_item;
    }
  }	
?>
