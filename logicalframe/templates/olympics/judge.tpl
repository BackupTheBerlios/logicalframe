{include file=olympics/header.tpl}


      <br><br>
<b>{$errors}
{$message}</b>
    
   {$form_begin}
      <table border="0" width="400" cellspacing="0" cellpadding="0">
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Current Round</td>
              <td>{$item_roundname}</td>
      </tr>
      {if $noplayers}
      <tr>
              <td width="200" class="formtext" valign="top"><p>This round has no player left to judge</td>
              <td></td>
      </tr>
      {else}
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Hill Type</td>
              <td>{$item_roundhill}</td>
      </tr>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">The K-point</td>
              <td>{$item_kpoint}</td>
      </tr>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">MeterPoint</td>
              <td>{$item_meterpoint}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Player</td>
              <td>{$item_scheduleid}{$item_players}{$item_player}</td>
      </tr>
      </tr>
              <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Jumped:</td>
              <td class="formtext"><br>&nbsp;&nbsp;&nbsp;&nbsp;{$jumpes}<br></td>
      </tr>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Speed km/h </td>
              <td>{$item_speed}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Distance</td>
              <td>{$item_distance}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Distance points {$meterpoint} p/m</td>
              <td>{$item_distancepoints}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 1</td>
              <td>{$item_grade1}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 2</td>
              <td>{$item_grade2}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 3</td>
              <td>{$item_grade3}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 4</td>
              <td>{$item_grade4}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 5</td>
              <td>{$item_grade5}</td>
      </tr>
              <tr>
              <td width="200" class="formtext">&nbsp;</td>
              <td>
                 <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">
                 <a href="javascript:document.forms[0].submit();" class="more">judge</a><br>

      </tr>
      {/if} 
      </table>
      {$form_end}


{include file=olympics/footer.tpl}
