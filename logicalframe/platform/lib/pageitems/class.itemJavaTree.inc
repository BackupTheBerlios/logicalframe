<?php
  /**
  *
  */
  
  require_once("class.item.inc");

  class JavaTree extends item
  {
    var $m_defaultchecked; 

  	function JavaTree($name,$template="")
    { 
      $this->item($name);
      debug("initiate itemJavaTree object");
      $this->m_name = $name;
  	}
     

    function setDefaultChecked($i_array)
    {
      $this->m_defaultchecked = $i_array;
    }

    function show()
    {
      $this->m_item="";
      if($this->m_value!="")
      {
        $value=$this->m_value;
      }
      
      // Haal voor elke sub de categorieen op
      //$this->m_value = array("hoofdcategorie"=>array("1"=>"subcategorie_naam"));

      foreach($this->m_valuelist as $main_key=>$val)
      {
        if($main_key!="")
        {
$this->m_item.="<script language='Javascript1.2' src='js/menu.js'></script>\n
<div class='look'><img src='images/menu_main.gif' class='folding'><b>".$main_key."</b>\n";
        }
        
        if(is_array($val))
        {
          $this->m_item.="<ul class='look2' style='list-style-image:url(menu_sub.gif);display:none'>\n";
          foreach($val as $subcat_key=>$subcat_val)
          {
            // check if subcat_id is in the 
            if(is_array($this->m_value))
            {
              $checked="";
              foreach($this->m_value as $t_value=>$t_extra)
              {
                if($subcat_val==$t_extra)
                {
                  $checked="checked";
                }
              }
            }  
             
            if(is_array($this->m_defaultchecked))
            {
              $checked="";
              foreach($this->m_defaultchecked as $checkedid=>$checkedval)
              {
                if($subcat_val==$checkedid)
                {
                  $checked="checked";
                }
              }
            }  
            $this->m_item.="<input type=\"checkbox\" name=\"".$this->m_name."[]\" value=\"".$subcat_val."\" ".$checked.">&nbsp;&nbsp;".$subcat_key."<br>\n";
            // $this->m_item.="<input type=\"checkbox\" name=\"".$this->m_name."[]\" value=\"".$subcat_val."\" checked>&nbsp;&nbsp;".$subcat_key."<br>\n";
          }
          $this->m_item.="</ul>\n";
        }
        $this->m_item.="</div>\n";
      }
      return $this->m_item;
    }
  }	
?>
