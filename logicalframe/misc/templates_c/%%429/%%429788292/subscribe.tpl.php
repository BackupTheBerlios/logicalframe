<?php /* Smarty version 2.4.2, created on 2004-02-07 11:54:14
         compiled from olympics/subscribe.tpl */ ?>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/header.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>


<h1>This is the index.tpl</h1>
  <b><?php echo $this->_tpl_vars['errors']; ?>
</b>
            <?php echo $this->_tpl_vars['form_begin']; ?>

            <table width="100%">
              <tr>
                <td width="50%">Company</td>
                <td><?php echo $this->_tpl_vars['item_company']; ?>
</td>
              </tr> 
              <tr>
                <td width="50%">Email as login</td>
                <td><?php echo $this->_tpl_vars['item_emailadres']; ?>
</td>
              </tr>  
              <tr>
                <td width="50%">Password</td>
                <td><?php echo $this->_tpl_vars['item_passwd']; ?>
</td>
              </tr>  
                <td>Send</td>
                <td><input type="submit" value="submit"></td>
              </tr>  
            </table>
          <?php echo $this->_tpl_vars['form_end']; ?>



<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/footer.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>