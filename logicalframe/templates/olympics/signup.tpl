{include file=olympics/header.tpl}
      <br>
      Users must sign up, in order to benefit from the information result system.<br>
      <p>
{$errors}
<p>
      {$form_begin}
      <table border="0" width="350" cellspacing="0" cellpadding="0">
              <tr>

              <td width="110" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Company Name</td>
              <td>{$item_company}</td>
      </tr>
              <tr>
              <td width="110" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Email</td>
              <td>{$item_emailadres}</td>
      </tr>
              <tr>

              <td width="110" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Password</td>
              <td>{$item_passwd}</td>
      </tr>
              <tr>
              <td width="110" class="formtext">&nbsp;</td>
              <td>
                 <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">
                 <input type ="submit" value="submit"><br>

      </tr>
      </table>
      {$form_end}
      <!-- end main -->
{include file=olympics/footer.tpl}
