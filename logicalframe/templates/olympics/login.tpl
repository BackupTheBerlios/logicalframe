{include file=olympics/header.tpl}

    <br>
    Users must log in, in order to benefit from the information result system.<br>
    If you don't have an account yet, please refer to the <b>sign up section</b> in order to fullfil this request.<br>
    <br><li>Please note: the username should be the user e-mailaddress.<br></li><br>
    <p>
{if $loginerror!=""}
{$loginerror}
{elseif $errors!=""}
{$errors}
{/if}
{$form_begin}<table border="0" width="350" cellspacing="0" cellpadding="0">
            <tr>
<td width="110" class="formtext" valign="top">
<img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Login</td>
            <td>{$item_emailadres}</td>
    </tr>
            <tr>
<td width="110" class="formtext">
<img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Password</td><td>{$item_passwd}</td>
    </tr>
    <tr>
      <td width="110" class="formtext">&nbsp;</td>
      <td><input type="submit" name="submit"><br></td>
    </tr>
    </table>
{$form_end}
{include file=olympics/footer.tpl}
