<?php /* Smarty version 2.4.2, created on 2004-02-09 19:03:54
         compiled from olympics/signup.tpl */ ?>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/header.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
     	<a href="index.php" class="pathlinks">Home</a> -> <a href="signup.php" class="pathlinks">Sign Up</a>
	  <br><br>
      In order to view all other features of the Result Information System, users must sign up and login first. 
	  <br><br><li>Please note: all fields are required to be filled in.</li><br>
      <p>
<?php echo $this->_tpl_vars['errors']; ?>

<p>
      <?php echo $this->_tpl_vars['form_begin']; ?>

      <table border="0" width="550" cellspacing="0" cellpadding="0">
              <tr>

              <td width="175" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Company Name</td>
              <td width="300"><?php echo $this->_tpl_vars['item_company']; ?>
</td>
      </tr>
              <tr>
              <td width="175" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Email</td>
              <td width="400"><?php echo $this->_tpl_vars['item_emailadres']; ?>
</td>
      </tr>
              <tr>

              <td width="175" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Password</td>
              <td width="400"><?php echo $this->_tpl_vars['item_passwd']; ?>
</td>
      </tr>
              <tr>
              <td width="175" class="formtext">&nbsp;</td>
              <td width="400">
                 <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">
                 <a href="javascript:document.forms[0].submit();" class="more">Sign Up</a><br>

      </tr>
      </table>
      <?php echo $this->_tpl_vars['form_end']; ?>

      <!-- end main -->
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/footer.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>