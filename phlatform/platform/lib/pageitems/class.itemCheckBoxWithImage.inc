<?php
  /**
  *
  */
  
  require_once("class.item.inc");

  class CheckBoxWithImage extends item
  {
    var $m_maxlength = "40";
    var $m_name = "";
    var $m_defaultchecked;  // boolean
    var $m_info;
    var $m_javascriptbuttons;
    var $m_defaultchecked; 

    function setDefaultChecked($i_array)
    {
      $this->m_defaultchecked = $i_array;
    }

    function setCheckedValue($checkedvalue)
    {
      $this->m_value=$checkedvalue;
    }

    function setValue($val)
    {
      if($val!="0")
      {
        $this->m_value = $val;
      }  
    }
    
    function setOnclick($funcname)
    {
      if($funcname!="")
      {
        $this->m_onclick = $funcname;
      }  
    }

    function CheckBox($name,$template="")
    { 
      $this->item($name);
      debug("initiate itemCheckBox object");
      $this->m_name = $name;
  	}

    function setChecked()
    {
      $this->m_defaultchecked = true;
    }

    function addJavaButtons()
    {
      $this->m_javascriptbuttons="<script language=javascript>
      function selectAll(formObj, isInverse) 
      {
        for (var i=0;i < formObj.length;i++) 
        {
          fldObj = formObj.elements[i];
            if (fldObj.type == 'checkbox')
          { 
            if (fldObj.name == '".$this->m_name."[]')
            { 
              if(isInverse)
              fldObj.checked = (fldObj.checked) ? false : true;
            else fldObj.checked = true; 
            }
          }
         }
       }
      </script>
      <input type=\"button\" name=\"selectall\"  value=\"Selecteer Alles\" onclick=\"selectAll(this.form,0);\">
      <input type=\"button\" name=\"selectall\"  value=\"Inverse Alles\" onclick=\"selectAll(this.form,1);\">";

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
                          <input type=\"CHECKBOX\" name=\"".$this->m_name."[]\" value=\"".$value."\" ".$checked."><br><br>
                        </td>";
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
  }// end class
?>
