<?php
require_once("platform_functions.inc");

  class libarian
  {
    var $m_default_libdir;
    var $m_delimiter;
    var $m_os;

    /**
     * highest debuglevel
     */
    var $m_debuglvl = 2;

  /**
  * Constructor
  * Since the libmaster only handles classes.
  * independent functions will be included in the contstructor.
  */
  function libarian($i_libdir="")
  {
    if(isset($i_libdir))
    {	
      if (strtoupper(substr(PHP_OS, 0, 3)) == 'WIN')
      {
        $this->m_os = "windows";
        $this->m_delimiter = ";";
      }
      else
      {
        $this->m_delimiter = ":";
      }
      debug(__CLASS__."::".__FUNCTION__." ");
      $this->m_default_libdir = $i_libdir;
    }
  }

  function debug()
  {
    debug($message,$this->m_debuglvl);
  }

  function includeDir($dirarray)
  {
    $newpath = ".";
    foreach($dirarray as $val) 
    {
      $newpath.=$this->m_delimiter.".".$val; 
    }
    ini_set("include_path",$newpath);
    debug(__CLASS__."::".__FUNCTION__." : new include_path = $newpath");
  }	

  /**
   * 
   * @param  $dir      load the specified directory
   * @param  $method   include or require
   */
   function loadDir($dir,$method="require")
   {
     $classfiles = $this->getIncFilesOfDir($dir);
   
     foreach($classfiles as $index => $filename) 
     {
       if ($method=="include")
       {
         include_once($filename);
   //      debug(__CLASS__."::".__FUNCTION__." : including $filename");
       }
       else if($method=="require")
       {
         include_once($dir."/".$filename);
     //    debug(__CLASS__."::".__FUNCTION__." : including $filename");
       }
       else
       {
         debug(__CLASS__."::".__FUNCTION__." : method is not specified");
       }
     }
   }

   /**
   *  This function get the class.*.inc files of an directory
   */
   function getIncFilesOfDir($dir)
   {
     if ($handle = opendir($dir))
     {
       $tmp_filearray = array();  
       while (false !== ($file = readdir($handle)))
       {
         if(ereg("^class.*.inc$",$file))
         {
           $tmp_filearray[]=$file;
         }
       }
       return $tmp_filearray;
     }
   }
     

  /**
  * Use this function to load a lib file.
  * At the moment you have to specifie the relative path
  * In the future this function will search for the appropiate module
  * such as recursive file search etc.
  *
  * @param libname
  * @param $i_method include or require, default is include 
  */	
  function needLib($i_lib,$i_method="include")
  {
    global $g_masterlib;

    if($i_method=="require")
    {
      require_once($i_lib);
      return true;
    }
    else if($i_method=="include")
    {
      include_once($i_lib);
      return true;
    }
    else
    {
      debug("Library could not be found... ".$i_lib);
      return false;
    }
  }
  
}// end class
?>
