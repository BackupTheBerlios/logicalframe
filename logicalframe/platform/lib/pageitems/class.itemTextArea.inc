<?php
  /**
  * This item class creates an input TextArea
  */
  require_once("class.item.inc");

  class TextArea extends item
  {
    var $m_maxlength;
    var $m_name = "textArea";
    var $m_rows = "5"; //default is 5
    var $m_cols = "40"; //default is 40

  	function TextArea($name,$template="")
    { 
      $this->item($name);
      debug("initiate itemTextArea object");
      $this->m_name = $name;
  	}

    function setMaxLength($length)
    {
      $this->m_maxlength = $length;
    }
 
  				
    function setRows($i_rows)
    {
      $this->m_rows = $i_rows;
    }
    
    function setCols($i_cols)
    {
      $this->m_cols= $i_cols;
    }
     
    function show()
    {
      $this->m_item="";
      if($this->m_value!="")
      {
        $value=$this->m_value;
      }
      
  		$this->m_item.="<textarea name=\"".$this->m_name."\" rows=\"".$this->m_rows."\" cols=\"".$this->m_cols."\" maxlength=\"".$this->m_maxlength."\" ".$this->m_manualcode.">".$value."</textarea>";
      return $this->m_item;
    }
  }	
?>
