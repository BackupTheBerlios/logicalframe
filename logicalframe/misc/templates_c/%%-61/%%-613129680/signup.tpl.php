<?php /* Smarty version 2.4.2, created on 2004-02-08 14:18:15
         compiled from olympics/signup.tpl */ ?>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/header.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
      <br>
      Users must sign up, in order to benefit from the information result system.<br>
      <p>
<?php echo $this->_tpl_vars['errors']; ?>

<p>
      <?php echo $this->_tpl_vars['form_begin']; ?>

      <table border="0" width="350" cellspacing="0" cellpadding="0">
              <tr>

              <td width="110" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Company Name</td>
              <td><?php echo $this->_tpl_vars['item_company']; ?>
</td>
      </tr>
              <tr>
              <td width="110" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Email</td>
              <td><?php echo $this->_tpl_vars['item_emailadres']; ?>
</td>
      </tr>
              <tr>

              <td width="110" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Password</td>
              <td><?php echo $this->_tpl_vars['item_passwd']; ?>
</td>
      </tr>
              <tr>
              <td width="110" class="formtext">&nbsp;</td>
              <td>
                 <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">
                 <input type ="submit" value="submit"><br>

      </tr>
      </table>
      <?php echo $this->_tpl_vars['form_end']; ?>

      <!-- end main -->
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/footer.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>