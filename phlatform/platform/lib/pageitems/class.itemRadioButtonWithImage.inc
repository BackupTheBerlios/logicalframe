<?php
  /**
  * This item class creates an Radio button
  */
  
  require_once("class.item.inc");

  class RadioButtonWithImage extends item
  {
    //var $m_maxlength = "40"; laten we even staan als voorbeeld
    
  	function RadiobuttonWithImage($name,$template="")
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
      $this->m_item="<table>
                        <tr>";

      $counter = 0;
      if(count($this->m_valuelist)>0)
      {
        foreach($this->m_valuelist as $value=>$extra)
        {
          $checked="";
          $counter++;
        
          if($value==$this->m_value)
          { 
            $checked="checked";
          } 
          
    		  $this->m_item.="<td align=\"center\">          
                            <img src=\"".$extra."\"><p>
                            <input type=\"radio\" name=\"".$this->m_name."\" value=\"".$value."\" ".$checked."><br><br>
                          </td>
                        ";
          if(($counter%4)==0)
          {
            $this->m_item.="</tr>
                            <tr>";
          }
        }  
  
        $this->m_item.="</tr></table>";
        return $this->m_item;
      }
    }	
  }
?>
