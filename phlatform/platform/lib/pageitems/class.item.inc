<?php
  /**
	*	This is the base class of a item. 
  * To do better interaction with class.ruleName.inc
  * better error handling and returning
  *
  * Author Trung Huynh projex@sourceforge.net
	*/

	class item
	{
     // the html item
     var $m_item;
     
     // the item name
     var $m_name;
     
     // the value of the item.
     var $m_value;

     // the value list
     var $m_valuelist;
     
     // the default value of the item
     var $m_defaultvalue;
     
     // boolean, whether with template or not
     var $m_withtemplate;
     
     // the validation rule 
     var $m_validationrule;
     
     // error message if value isn't valid
     var $m_errormessage;
     var $m_manualcode;
     var $m_dummy;
    /**
    * item
    *
		* Base constructor
    *
    * @params $name
    * @params $template
		*/
	  function item($name,$template="")
		{
      $this->m_name = $name;   
       if(isset($template))
       {
         $this->m_withtemplate="true";
       }
       $this->setDummy("default");
		}
    
    /**
    * 
    */
    function addManualCode($string)
    {
      $this->m_manualcode=$string;
    }

 
    /**
    *
    */
    function hello()
    {
      debug("I'm the base class item and I say hello");
    }

    function setDummy($waarde)
    {
      $this->m_dummy = $waarde;
    }

    function getDummy()
    {
      return $this->m_dummy;
    }
  

     /**
     * setDefaultValue
     *
     * sets the value of the widget
     */
     function setDefaultValue($val)
     {
       if($val!="")
       {
         $this->m_defaultvalue = $val;
       }  
     }

      function getDefaultValue()
      {
        return $this->m_defaultvalue;
      }

     /**
     * setValue
     *
     * sets the value of the widget
     */
     function setValue($val)
     {
       if($val!="")
       {
         $this->m_value = $val;
         //debug($this->m_name." is setted with  the value ". $this->m_value ."!");
       }  
     }

    /**
    * Sets multiple values and 
    * usefull for dropdown, selectboxs, checkboxs
    */ 
    function setValues($values=array())
    {
      if(is_array($values))
      {
        $this->m_valuelist = $values; 
      }
    }

      
    /**
    * getValue
    *
    * returns the value
    */
    function getValue()
    {
      return $this->m_value;
    }

	   /**
     * show
     *
     * returns the item in html format.
     */
     function show()
     {
       return $this->m_item;
     }

      
      /**
      * there are different kind or rule types:
      * equals
      * email
      * not empty
      * length
      * regex
      */
      // function addValidation($namerule, $value="",$value2="")
      function addValidation($namerule)
      {
        // DIRTY HACK
        // require_once("class.rule.inc");
        // require_once("class.ruleNotEmpty.inc");
        // DIRTY HACK
        
        $ruleobject = "rule".$namerule;

        $inputs = func_get_args();

        // dirty hack
        if(is_array($inputs[1]))
        {
          $this->m_validationrule = new $ruleobject($inputs[1]);
        }
        // end dirty hack
        else
        {
          $params = array_slice(func_get_args(),1);
          $paramstring = implode(',', $params);
      
          // we skip the first one, because it's an validation object, the rest are params
          $string = "\$this->m_validationrule = new $ruleobject(".$paramstring.");";
          eval($string);
        }
      }

      /**
      * 
      */
      function checkInput()
      {
        if(is_object($this->m_validationrule))
        {
          if(is_array($this->m_value))
          {
            foreach($this->m_value as $val=>$extra)
            {
              $resultarray = $this->m_validationrule->validate($val); 
            }
            return true;
          }
          else
          {
            $result = $this->m_validationrule->validate($this->m_value); 
            if($result=="true")
            {
              return true;
            }
            else
            {
              $this->m_errormessage = $this->m_validationrule->getErrorMessage();
            }
          }
        }
        else
        {
          // validation rule is not an object, I suppose that any input is allowed.
          return true;
        }
      }

      function getErrors()
      {
        if($this->m_errormessage!=""or$this->m_errormessage!="NULL")
        {
          return $this->m_errormessage;
        }
        else
        {
          // there is no error message so we consider the input good, even if it is empty
          return true;
        }
      }

      function showItem($sign="")
      {
        if(is_object($this->m_validationrule))
        {
          $requiredsign= $sign;
        }
        $objecthtml = $this->show();

        return $objecthtml.$requiredsign;
      }

    
      /**
      * gotTemplate
      *
      */
      function gotTemplate()
      {
        if($this->m_withtemplate!="")
        {
          return true;
        }
      } 
    }	
?>
