<?php
  /**
  * 
  */
  function convertToPlainText($in)
  {
    $in = ereg_replace("'", "", $in);
    $out = ereg_replace("[^[:alnum:]]|'", " ", $in);
    return $out;
  }

  function convertDate($array)
  {
     return $array[year]."-".$array[month]."-".$array[day];
  }
  
  function push_into_multi($array,$image_id,$onderwerp)
  {
    foreach($array as $image=>$data)
    {
      {
        array_push($image,$image_id);
        array_push($data,$onderwerp);
      }
    }
    return $array;
  }

  function getScriptName()
  {
    global $SCRIPT_FILENAME, $PHP_SELF;
    // $currentPage = basename($SCRIPT_FILENAME,".php");
    $stringed = substr($PHP_SELF,0,-4);
    $stringed = substr($stringed,1);
    return $stringed;
  }

  function getmicrotime()
  {
    list($usec, $sec) = explode(" ",microtime()); 
    return ((float)$usec + (float)$sec); 
  }
  
  function elapsed()
  { 
    static $offset="";
    if ($offset=="") 
    {
      $offset = getmicrotime();
      return strftime("%H:%M:%S")."h";
    }
    else
    {
      return "+".sprintf("%02.05f",getmicrotime()-$offset)."s";
    }
  }

  function debug($txt,$lvl = null)
  {
    global $g_debuginfo;

    if(isset($lvl))
    {
      $g_debuginfo[$lvl]="[".elapsed()."] ".$txt;
    }
    else
    {
      $g_debuginfo[]="[".elapsed()."] ".$txt;
    }
  
  }

  /**
  * Function dataSetContains
  *
  * checks if a value is in a Array
  */
  function dataSetContains($set, $key, $value)
  {
    for ($i=0;$i<count($set);$i++)
    {
      if ($set[$i][$key]==$value) return true;
    }
    return false;
  }


  /**
  * Function stripQuotes
  *
  * strips ' or  " from the begin and end of a string (only if they are 
  * on both sides, e.g. foo' remains foo' but 'bar' becomes bar.
  */
  function stripQuotes($string)
  {
    if ($string[0]=="'" && substr($string,-1)=="'") return substr($string,1,-1);
    if ($string[0]=='"' && substr($string,-1)=='"') return substr($string,1,-1);    
    return $string;
  }
 
 
	/**
  * This function writes a binary file to the browser for download.
  * $file is the local filename (the file you want to open on the serverside)
  * $filename is the name the file will get when the user downloads it.
  */
  function exportFile($file, $filename,$mimetype)
  {   
    $browser = getBrowserInfo();
    // var_dump($browser);
    if (eregi("ie", $browser["browser"]))
    {
      if (empty($mimetype))
        $mime = "application/octetstream";
      else
        $mime = $mimetype;
      $disp = 'inline';
    }
    else if (eregi("opera",$browser["browser"]))
    {
      if (empty($mimetype))
        $mime = "application/octetstream";
      else
        $mime = $mimetype;
      $disp = 'attachment';
    }
    else
    {
      if (empty($mimetype))
        $mime = "application/octet-stream";
      else
        $mime = $mimetype;
      $disp = 'attachment';
    }
    
		
    $fp = @fopen($file,"rb");
    if ($fp!=NULL)
    {
      header('Content-Type: '. $mime);    
      header('Content-Disposition:  '.$disp.'; filename="'.$filename.'"');
      header('Pragma: no-cache');
      header('Expires: 0');
		  fpassthru($fp);          
      return true;
    }
    return false;
  }

   function getBrowserInfo()
  {
       global $HTTP_USER_AGENT;
       // look for  Mozilla/4.05 [en] (X11; U; SunOs 5.4 sun4m)
            ereg("^([A-Za-z]+)/([0-9]+\.[0-9]+) (.*)$", $HTTP_USER_AGENT, $match);

            $BrowserArray["browser"] = $HTTP_USER_AGENT;
             $BrowserArray["Name"] = $match[1];
             $BrowserArray["Version"] = $match[2];
             $BrowserArray["Description"] = $match[3];

     // look for clues that this is MSIE
     if (eregi("msie",  $match[3] ))
     {
      // look for format (compatible; MSIE 4.01; Windows NT)
      ereg("\((.*); (.*) (.*); (.*)\)$", $match[3], $match2);
      $BrowserArray["Name"] = $match2[2];
      $BrowserArray["Version"] = $match2[3];
     }
  return $BrowserArray;
  }

?>
