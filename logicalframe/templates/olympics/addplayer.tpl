{include file=olympics/header.tpl}
<a href="index.php" class="pathlinks">Home</a> -> <a href="addplayer.php" class="pathlinks">Add Player</a>
      <br><br>
      Please fill in all necessary fields.<br>
      <p>
{$errors}
<p>
      {$form_begin}
      <table border="0" width="450" cellspacing="0" cellpadding="0">
              <tr>

              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Players full name</td>
              <td>{$item_name}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Height</td>
              <td>{$item_height}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Weight</td>
              <td>{$item_weight}{$item_token}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Representing Country</td>
              <td>{$item_nationality}</td>
      </tr>
      
      {if $item_addteam}
      <tr>
        <td width="200" class="formtext">
        <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Add player to national team, currently: {$memberamount} teammember(s)</td>
        <td>{$item_addteam}</td>
      </tr>
      {elseif $item_createteam}
      <tr>
        <td width="200" class="formtext">
        <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">There is no nationalteam at the moment<br>Do you want to create one?</td>
        <td>{$item_createteam}</td>
      </tr>
      {/if}
      
      
      <tr>
              <td width="200" class="formtext">&nbsp;</td>
              <td>
                 <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">
                 <a href="javascript:document.forms[0].submit();" class="more">add player</a><br>
      </tr>
      </table>
      {$form_end}
      <!-- end main -->
{include file=olympics/footer.tpl}
