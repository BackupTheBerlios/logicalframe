<?php
  /**
  *
  */
  require_once("class.item.inc");

  class Date extends item
  {
    var $m_maxlength = "40";
    var $m_futureyears = "20";

  	function Date($name,$template="")
    { 
      $this->item($name);
      debug("initiate itemDate object");
      $this->m_name = $name;
  	}
    
    function setValue($i_value)
    {
      if(is_array($i_value))
      {
        $this->m_value = $i_value;
      }  
      else if($i_value!="")
      {
        $this->m_value['year'] = substr($i_value,0,4);
        $this->m_value['month'] = substr($i_value,5,2);
        $this->m_value['day'] = substr($i_value,8,9);
      }  
    }

    /**
    * 
    */
    function checkInput()
    {
      if(is_object($this->m_validationrule))
        {
          $checked = checkdate($this->m_value['month'],$this->m_value['day'],$this->m_value['year']);
          if($checked)
          {
            return true;
          }
          else
          {
            // get the error message
            $this->m_errormessage = $this->m_validationrule->getErrorMessage();
            return false;
          }
        }
        else
        {
          // validation rule is not an object, I suppose that any input is allowed.
          return true;
        }
    }

    function setDateNow()
    {
      $this->m_value['year'] = date("Y");
      $this->m_value['month'] = date("n");
      $this->m_value['day'] = date("j");
    }
  				
    function show()
    {

      $this->m_item="";

      if($this->m_value!="")
      {
        $value ="value=\"".$this->m_value."\"";
      }
      
      for($i=0;$i<31;$i++)
      {
        $default="";

        if($i==$this->m_value['day'])
        {
          $default="selected";
        }
        
        if($i=="0")
        {
      
          $day_html="<select name=\"".$this->m_name."[day]\">\n
                      <nobr>\n
                       <option value=\"0\">Dag\n";
        }
        else
        {
          $day_html.="<option value=\"".$i."\" ".$default.">".$i."\n";
        }  
      }
      $day_html.="</select>";

      
      $month_array=array("0"=>"Maand",
                         "1"=>"Januari",
                         "2"=>"Februari",
                         "3"=>"Maart",
                         "4"=>"April",
                         "5"=>"Mei",
                         "6"=>"Juni",
                         "7"=>"Juli",
                         "8"=>"Augustus",
                         "9"=>"September",
                         "10"=>"Oktober",
                         "11"=>"November",
                         "12"=>"December");  
      
      for($month=0;$month<count($month_array);$month++)
      {
        if($month=="0")
        {
          $month_html="<select name=\"".$this->m_name."[month]\">\n
                        <option value=\"0\">Maand\n";
        }  
        else
        {
          $month_selected="";
          if($month==$this->m_value['month'])
          { 
            $month_selected="selected";
          }
        $month_html.="<option value=\"".$month."\" ".$month_selected.">".$month_array[$month]."\n";
        } 
      }
      $month_html.="</select>";
        
      $year=date("Y");

      $year_html.="<select name=\"".$this->m_name."[year]\">\n";

      $calendaryears=$year+$this->m_futureyears;

      for($year;$year<$calendaryears;$year++)
      {
        $default_year="";
        if($this->m_value['year']==$year)
        {
          //$default_year=$this->m_value['year'];
          $default_year="selected";
        }  
          $year_html.="<option value=\"".$year."\" ".$default_year.">".$year."\n";
      }
      $year_html.="</select>";
        
  		
      $this->m_item.=$day_html.$month_html.$year_html;
      return $this->m_item;
    }
  }	
?>
