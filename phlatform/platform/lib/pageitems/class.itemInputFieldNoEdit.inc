<?php
  /**
  * 
  *
  */
  require_once("class.item.inc");

  class InputFieldNoEdit extends item
  {
    var $m_maxlength = "40";
    var $m_size = "42";
        
  	function InputFieldNoEdit($name,$template="")
    { 
      $this->item($name);
      debug("initiate itemInputFieldNoEdit object");
      $this->m_name = $name;
  	}
  				
    function setMaxLength($length)
    {
      $this->m_maxlength = $length;
    }
    
    function setSize($size)
    {
      $this->m_size= $size;
    }
       
    function setText($text)
    {
      $this->m_item.=$text."<p>";
    }
          
    function show()
    {
      $this->m_item="";
      if($this->m_value!="")
      {
        $value ="value=\"".$this->m_value."\"";
      }
      
  		$this->m_item .="<input type=\"text\" name=\"".$this->m_name."\" size=\"".$this->m_size."\" maxlength=\"".$this->m_maxlength."\" $value READONLy>";
      return $this->m_item;
    }
  }	
?>
