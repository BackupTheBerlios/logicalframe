<?php
  require_once("class.item.inc");

  class DropDown extends item
  {
    var $m_valuelist= array();
    var $m_changeonsubmit;
    var $m_startempty = false;
    var $m_defaultvalue;

    function DropDown($name,$template="")
    {
      $this->item($name);
      debug("initiate itemDropDown object");
    }

    /**
    *   
    */
    function setValue($val)
    {
       if($val!="")
       {
         $this->m_value = $val;
       }  
    }


    /**
    * Sets the dropdown keys and values
    */
    function setValues($values=array())
    {
      if(is_array($values))
      {
        $this->m_valuelist = $values;
      }
    }

    function changeOnSubmit()
    {
        return $this->m_changeonsubmit = true;
    }

    function startEmpty($param)
    {
      $this->m_startempty = $param;
    }
    

    function show()
    {
      global $PHP_SELF;

      $this->m_item="";
      // buil the dropdown list
      if(is_array($this->m_valuelist)&&count($this->m_valuelist)>0&&isset($this->m_name))
      {
        if($this->m_changeonsubmit)
        {
          $changeonsubmit = "onchange=\"this.form.submit()\"";
          //$this->m_item.="<form method=\"post\" action=\"".$PHP_SELF."\" name=\"".$this->m_name."\">\n";
        }

        $this->m_item.="<select name=\"".$this->m_name."\" $changeonsubmit>\n";

        if($this->m_startempty)
        {
          $this->m_item.="<option value=\"\">".$this->m_startempty."</option>\n";
        }

        while(list($key,$val)=each($this->m_valuelist))
        {
          $defaultselected="";
          if($this->m_defaultvalue==$key)
          {
            $defaultselected="selected";
          }
          $this->m_item.="<option value=\"".$key."\" ".$defaultselected.">".$val."\n";
        }
        $this->m_item.="</select>\n";
        if($this->m_changeonsubmit)
        {
          $this->m_item.="<noscript><input type=\"submit\" name=\"submit\" value=\"submit\"></noscript>";//</form>";
        }
      }
      else
      {
        debug("class.itemDropDown.inc says: m_value is not set!");
        return false;
      }
      debug("class.itemDropDown.inc says: returning html code");
      return $this->m_item;
    }
  }
?>
