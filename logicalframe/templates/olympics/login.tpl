{include file=olympics/header.tpl}

    
	<a href="index.php" class="pathlinks">Home</a> -> <a href="login.php" class="pathlinks">Login</a><br>
    <br>This section gives the users the possibility to log in the Result Information System, in order to benefit from its features.
    If you don't have an account yet, please refer to the <b>sign up section</b> in order to fullfil this request.<br>
    <br><li>Please note: the username should be the user e-mailaddress.<br></li><br>
    <p>
{if $loginerror!=""}
{$loginerror}
{elseif $errors!=""}
{$errors}
{/if}
{$form_begin}<table border="0" width="550" cellspacing="0" cellpadding="0">
            <tr>
<td width="100" class="formtext" valign="top">
<img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Login</td>
 <td width="400">{$item_emailadres}</td>
    </tr>
            <tr>
<td width="100" class="formtext">
<img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Password</td>
<td width="400">{$item_passwd}</td>
    </tr>
    <tr>
      <td width="100" class="formtext">&nbsp;</td>
      <td width="400"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle"> <a href="javascript:document.forms[0].submit();" class="more">Login</a><br></td>
    </tr>
    </table>
{$form_end}
{include file=olympics/footer.tpl}
