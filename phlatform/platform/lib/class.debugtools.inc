<?php
  require_once("platform_functions.inc");
  /************************************************
  ** Title.........: Debug Lib
  ** Version.......: 0.5.3
  ** Author........: Thomas Schüßler <tulpe@atomar.de>
  ** Filename......: debuglib.php(s)
  ** Last changed..: 24. February 2003
  ** License.......: Free to use. Postcardware ;)
  **
  *************************************************
  **
  ** Functions in this library:
  **
  ** print_a( array array [,int mode] )
  **   prints arrays in a readable, understandable form.
  **   if mode is defined the function returns the output instead of
  **   printing it to the browser
  **   
  **   
  ** show_vars([int mode])
  **   use this function on the bottom of your script to see all
  **   superglobals and global variables in your script in a nice
  **   formated way
  **   
  **   show_vars() without parameter shows $_GET, $_POST, $_SESSION,
  **   $_FILES and all global variables you've defined in your script
  **
  **   show_vars(1) shows $_SERVER and $_ENV in addition
  **
  **   
  **   
  **
  ** Happy debugging and feel free to email me your comments.
  **
  **
  **
  ** History: (starting with version 0.5.3 at 2003-02-24)
  **
  **   - added tooltips to the td's showing the type of keys and values (thanks Itomic)
  **   
  ************************************************/
  
  
  // This file must be the first include on your page.
  
  /* used for tracking of generation-time */
  {
      $MICROTIME_START = microtime();
      @$GLOBALS_initial_count = count($GLOBALS);
  }
      
  /************************************************
  ** print_a class and helper function
  ** prints out an array in a more readable way
  ** than print_r()
  **
  ** based on the print_a() function from
  ** Stephan Pirson (Saibot)
  ************************************************/
  
  class Print_a_class
  {
      
      // this can be changed to FALSE if you don't like the fancy string formatting
      var $look_for_leading_tabs = TRUE;
  
      var $output;
      var $iterations;
      var $key_bg_color = '1E32C8';
      var $value_bg_color = 'DDDDEE';
      var $fontsize = '8pt';
      var $keyalign = 'center';
      var $fontfamily = 'Verdana';
      var $export_flag;
      var $show_object_vars;
      var $export_dumper_path = 'http://tools.www.mdc.xmc.de/print_a_dumper/print_a_dumper.php';
      // i'm still working on the dumper! don't use it now
      // put the next line into the print_a_dumper.php file (optional)
      // print htmlspecialchars( stripslashes ( $_POST['array'] ) );  
      var $export_hash;
          
      function Print_a_class()
      {
          $this->export_hash = uniqid('');
      }
      
      // recursive function!
      function print_a($array, $iteration = FALSE, $key_bg_color = FALSE)
      {
          $key_bg_color or $key_bg_color = $this->key_bg_color;
          
              // if print_a() was called with a fourth parameter (1 or 2)
              // and you click on the table a window opens with only the output of print_a() in it
              // 1 = serialized array
              // 2 = normal print_a() display
              
              /* put the following code on the page defined with $export_dumper_path;
              --->%---- snip --->%----
              
                  if($_GET['mode'] == 1)
                  {
                      print htmlspecialchars( stripslashes ( $_POST['array'] ) );
                  } elseif($_GET['mode'] == 2)
                  {
                      print_a(unserialize( stripslashes($_POST['array'])) );
                  }
  
              ---%<---- snip ---%<----
              */
              
          if( !$iteration && $this->export_flag )
          {
              $this->output .= '<form id="pa_form_'.$this->export_hash.'" action="'.$this->export_dumper_path.'?mode='.$this->export_flag.'" method="post" target="_blank"><input name="array" type="hidden" value="'.htmlspecialchars( serialize( $array ) ).'"></form>';
          }
          
          // lighten up the background color for the key td's =)
          if( $iteration )
          {
              for($i=0; $i<6; $i+=2)
              {
                  $c = substr( $key_bg_color, $i, 2 );
                  $c = hexdec( $c );
                  ( $c += 15 ) > 255 and $c = 255;
                  $tmp_key_bg_color .= sprintf( "%02X", $c );
              }
              $key_bg_color = $tmp_key_bg_color;
          }
          
          // build a single table ... may be nested
          $this->output .= '<table style="border:none;" cellspacing="1" '.( !$iteration && $this->export_flag ? 'onClick="document.getElementById(\'pa_form_'.$this->export_hash.'\').submit();" )' : '' ).'>';
          foreach( $array as $key => $value ) {
              
              $value_style = 'color:black;';
              $key_style = 'color:white;';
              
              $type = gettype( $value );
              // print $type.'<br />';
              
              // change the color and format of the value
              switch( $type )
              {
                  case 'array':
                      break;
                  
                  case 'object':
                      $key_style = 'color://FF9B2F;';
                      break;
                  
                  case 'integer':
                      $value_style = 'color:green;';
                      break;
                  
                  case 'double':
                      $value_style = 'color:red;';
                      break;
                  
                  case 'bool':
                      $value_style = 'color:blue;';
                      break;
                      
                  case 'resource':
                      $value_style = 'color:darkblue;';
                      break;
                  
                  case 'string':
                      if( $this->look_for_leading_tabs && preg_match('/^\t/m', $value) )
                      {
                          $search = array('/\t/', "/\n/");
                          $replace = array('&nbsp;&nbsp;&nbsp;','<br />');
                          $value = preg_replace( $search, $replace, htmlspecialchars( $value ) );
                          $value_style = 'color:black;border:1px gray dotted;';
                      } else
                      {
                          $value_style = 'color:black;';
                          $value = nl2br( htmlspecialchars( $value ) );
                      }
                      break;
              }
  
              $this->output .= '<tr>';
              $this->output .= '<td nowrap align="'.$this->keyalign.'" style="background-color://'.$key_bg_color.';'.$key_style.';font:bold '.$this->fontsize.' '.$this->fontfamily.';" title="'.gettype( $key ).'['.$type.']">';
              $this->output .= $key;
              $this->output .= '</td>';
              $this->output .= '<td nowrap="nowrap" style="background-color://'.$this->value_bg_color.';font: '.$this->fontsize.' '.$this->fontfamily.'; color:black;">';
  
              
              // value output
              if($type == 'array')
              {
                  $this->print_a( $value, TRUE, $key_bg_color );
              } elseif($type == 'object')
              {
                  if( $this->show_object_vars )
                  {
                      $this->print_a( get_object_vars( $value ), TRUE, $key_bg_color );
                  } else
                  {
                      $this->output .= '<div style="'.$value_style.'">OBJECT</div>';
                  }
              } else
              {
                  $this->output .= '<div style="'.$value_style.'" title="'.$type.'">'.$value.'</div>';
              }
              
              $this->output .= '</td>';
              $this->output .= '</tr>';
          }
          $this->output .= '</table>';
      }
  }
  // end class
  

  /**
  * helper function.. calls print_a() inside the print_a_class
  */
  function print_a( $array, $return_mode = FALSE, $show_object_vars = FALSE, $export_flag = FALSE )
  {
      if( is_array( $array ) or is_object( $array ) )
      {
          $pa = new Print_a_class;
          $show_object_vars and $pa->show_object_vars = TRUE;
          $export_flag and $pa->export_flag = $export_flag;
          
          $pa->print_a( $array );
          
          // $output = $pa->output; unset($pa);
          $output = &$pa->output;
      }
      else
      {
          $output = '<span style="color:red;font-size:small;">print_a( '.gettype( $array ).' )</span>';
      }
      
      if($return_mode)
      {
          return $output;
      }
      else
      {
          print $output;
          return TRUE;
      }
  }
  
  function script_globals()
  {
      global $GLOBALS_initial_count;
  
      $varcount = 0;
  
      foreach($GLOBALS as $GLOBALS_current_key => $GLOBALS_current_value)
      {
          if(++$varcount > $GLOBALS_initial_count)
          {
              /* die wollen wir nicht! */
              if ($GLOBALS_current_key != 'HTTP_SESSION_VARS' && $GLOBALS_current_key != '_SESSION')
              {
                  $script_GLOBALS[$GLOBALS_current_key] = $GLOBALS_current_value;
              }
          }
      }
      
      unset($script_GLOBALS['GLOBALS_initial_count']);
      return $script_GLOBALS;
  }
  

  /**
  * 
  */
  function show_vars($show_all_vars = FALSE, $show_object_vars = FALSE)
  {
      // Hi Wolfram!!! :))
      $MICROTIME_END        = microtime();
      $MICROTIME_START    = explode(' ', $GLOBALS['MICROTIME_START']);
      $MICROTIME_END        = explode(' ', $MICROTIME_END);
      $GENERATIONSEC        = $MICROTIME_END[1] - $MICROTIME_START[1];
      $GENERATIONMSEC    = $MICROTIME_END[0] - $MICROTIME_START[0];
      $GENERATIONTIME    = substr($GENERATIONSEC + $GENERATIONMSEC, 0, 8);
  
      if($GLOBALS['no_vars']) return;
      
      // Script zur Anzeige der GET/POST/SESSION/COOKIE/etc.. Variablen
      // einfach am Ende einer PHP Seite includen.
      
      $script_globals = script_globals();
      print '
          <style type="text/css">
          .vars-container
          {
              font-family: Verdana, Arial, Helvetica, Geneva, Swiss, SunSans-Regular, sans-serif;
              font-size: 8pt;
              padding:5px;
          }
          .varsname {
              font-weight:bold;
          }
          </style>
      ';
  
      print '<br />
          <div style="border-style:dotted;border-width:1px;padding:2px;font-family:Verdana;font-size:10pt;font-weight:bold;">
          DEBUG <span style="color:red;font-weight:normal;font-size:9px;">(runtime: '.$GENERATIONTIME.' sec)</span>
      ';
  
      $vars_arr['script_globals'] = array('global script variables', '//7ACCC8');
      $vars_arr['_GET'] = array('GET', '//7DA7D9');
      $vars_arr['_POST'] = array('POST', '//F49AC1');
      $vars_arr['_FILES'] = array('POST FILES', '//82CA9C');
      $vars_arr['_SESSION'] = array('SESSION', '//FCDB26');
      $vars_arr['_COOKIE'] = array('COOKIE', '//A67C52');
  
      if($show_all_vars)
      {
          $vars_arr['_SERVER'] =  array('SERVER', '//A186BE');
          $vars_arr['_ENV'] =  array('ENV', '//7ACCC8');
      }
  
      foreach($vars_arr as $vars_name => $vars_data)
      {
          if($vars_name != 'script_globals') global $$vars_name;
          if($$vars_name)
          {
              print '<div class="vars-container" style="background-color:'.$vars_data[1].';"><span class="varsname">'.$vars_data[0].'</span><br />';
              print_a($$vars_name, FALSE, $show_object_vars, FALSE );
              print '</div>';
          }
      }
    print '</div>';
  }
  
  
  function pre($sql_string)
  {
      print '<pre>'.$sql_string.'</pre>';
  }
?>
