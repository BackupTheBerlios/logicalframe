<?php
  /**
  *
  */
  
  require_once("class.item.inc");

  class CheckBox extends item
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
                  $this->m_item="";
                        foreach($this->m_valuelist as $value=>$extra)
                                {
                                          $checked="";
                                                  if(is_array($this->m_value))
                                                            {
                                                                        foreach($this->m_value as $t_value=>$t_extra)
                                                                                    {
                                                                                                  if($value==$t_extra)
                                                                                                                {
                                                                                                                                $checked="checked";
                                                                                                                                            }
                                                                                                            }
                                                                                }  
                                                           
                                                          if(is_array($this->m_defaultchecked))
                                                                    {
                                                                                foreach($this->m_defaultchecked as $checkedid=>$checkedval)
                                                                                            {
                                                                                                          if($value==$checkedid)
                                                                                                                        {
                                                                                                                                        $checked="checked";
                                                                                                                                                    }
                                                                                                                    }
                                                                                        }  
                                                                    
                                                                  $this->m_item.="<input type=\"checkbox\" name=\"".$this->m_name."[]\" value=\"".$value."\" ".$checked." onclick=\"".$this->m_onclick."\" >&nbsp;&nbsp;".$extra."<br>\n";
                                                                        }
                              return $$this->m_item.$this->m_javascriptbuttons;
;
          }
 
  }	
?>
