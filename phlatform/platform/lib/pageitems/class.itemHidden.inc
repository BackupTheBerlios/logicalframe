<?php
  /**
  * 
  *
  */
  require_once("class.item.inc");

  class Hidden extends item
  {
    function Hidden($name,$template="")
    { 
      $this->item($name);
      debug(__CLASS__."::".__FUNCTION__." : ");
      $this->m_name = $name;
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
      
      $this->m_item .="<input type=\"hidden\" name=\"".$this->m_name."\" ".$value.">";
      return $this->m_item;
    }
  }	
?>
