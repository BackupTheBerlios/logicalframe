{include file=olympics/header.tpl}
     	<a href="index.php" class="pathlinks">Home</a> -> <a href="signup.php" class="pathlinks">Sign Up</a>
	  <br><br>
      In order to view all other features of the Result Information System, users must sign up and login first. 
	  <br><br><li>Please note: all fields are required to be filled in.</li><br>
      <p>
{$errors}
<p>
      {$form_begin}
      <table border="0" width="550" cellspacing="0" cellpadding="0">
              <tr>

              <td width="175" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Company Name</td>
              <td width="300">{$item_company}</td>
      </tr>
              <tr>
              <td width="175" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Email</td>
              <td width="400">{$item_emailadres}</td>
      </tr>
              <tr>

              <td width="175" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Password</td>
              <td width="400">{$item_passwd}</td>
      </tr>
              <tr>
              <td width="175" class="formtext">&nbsp;</td>
              <td width="400">
                 <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">
                 <a href="javascript:document.forms[0].submit();" class="more">Sign Up</a><br>

      </tr>
      </table>
      {$form_end}
      <!-- end main -->
{include file=olympics/footer.tpl}
