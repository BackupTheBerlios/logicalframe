<?php /* Smarty version 2.4.2, created on 2004-02-09 21:57:26
         compiled from olympics/login.tpl */ ?>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/header.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

    
	<a href="index.php" class="pathlinks">Home</a> -> <a href="login.php" class="pathlinks">Login</a><br>
    <br>This section gives the users the possibility to log in the Result Information System, in order to benefit from its features.
    If you don't have an account yet, please refer to the <b>sign up section</b> in order to fullfil this request.<br>
    <br><li>Please note: the username should be the user e-mailaddress.<br></li><br>
    <p>
<?php if ($this->_tpl_vars['loginerror'] != ""): ?>
<?php echo $this->_tpl_vars['loginerror']; ?>

<?php elseif ($this->_tpl_vars['errors'] != ""): ?>
<?php echo $this->_tpl_vars['errors']; ?>

<?php endif; ?>
<?php echo $this->_tpl_vars['form_begin']; ?>
<table border="0" width="550" cellspacing="0" cellpadding="0">
            <tr>
<td width="100" class="formtext" valign="top">
<img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Login</td>
 <td width="400"><?php echo $this->_tpl_vars['item_emailadres']; ?>
</td>
    </tr>
            <tr>
<td width="100" class="formtext">
<img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Password</td>
<td width="400"><?php echo $this->_tpl_vars['item_passwd']; ?>
</td>
    </tr>
    <tr>
      <td width="100" class="formtext">&nbsp;</td>
      <td width="400"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle"> <a href="javascript:document.forms[0].submit();" class="more">Login</a><br></td>
    </tr>
    </table>
<?php echo $this->_tpl_vars['form_end']; ?>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/footer.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>