<?php /* Smarty version 2.4.2, created on 2004-02-09 11:43:38
         compiled from olympics/login.tpl */ ?>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/header.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

    <br>
    Users must log in, in order to benefit from the information result system.<br>
    If you don't have an account yet, please refer to the <b>sign up section</b> in order to fullfil this request.<br>
    <br><li>Please note: the username should be the user e-mailaddress.<br></li><br>
    <p>
<?php if ($this->_tpl_vars['loginerror'] != ""): ?>
<?php echo $this->_tpl_vars['loginerror']; ?>

<?php elseif ($this->_tpl_vars['errors'] != ""): ?>
<?php echo $this->_tpl_vars['errors']; ?>

<?php endif; ?>
<?php echo $this->_tpl_vars['form_begin']; ?>
<table border="0" width="350" cellspacing="0" cellpadding="0">
            <tr>
<td width="110" class="formtext" valign="top">
<img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Login</td>
            <td><?php echo $this->_tpl_vars['item_emailadres']; ?>
</td>
    </tr>
            <tr>
<td width="110" class="formtext">
<img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Password</td><td><?php echo $this->_tpl_vars['item_passwd']; ?>
</td>
    </tr>
    <tr>
      <td width="110" class="formtext">&nbsp;</td>
      <td><input type="submit" name="submit"><br></td>
    </tr>
    </table>
<?php echo $this->_tpl_vars['form_end']; ?>

<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/footer.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>