<?php /* Smarty version 2.4.2, created on 2004-02-09 20:28:02
         compiled from olympics/judge.tpl */ ?>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/header.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>


  <b><?php echo $this->_tpl_vars['errors']; ?>

<?php echo $this->_tpl_vars['message']; ?>
</b>
    
   <?php echo $this->_tpl_vars['form_begin']; ?>

      <table border="0" width="400" cellspacing="0" cellpadding="0">
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Current Round</td>
              <td><?php echo $this->_tpl_vars['item_roundname']; ?>
</td>
      </tr>
      <?php if ($this->_tpl_vars['noplayers']): ?>
      <tr>
              <td width="200" class="formtext" valign="top"><p>This round has no player left to judge</td>
              <td></td>
      </tr>
      <?php else: ?>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Hill Type</td>
              <td><?php echo $this->_tpl_vars['item_roundhill']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">The K-point</td>
              <td><?php echo $this->_tpl_vars['item_kpoint']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">MeterPoint</td>
              <td><?php echo $this->_tpl_vars['item_meterpoint']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Player</td>
              <td><?php echo $this->_tpl_vars['item_scheduleid']; ?>
<?php echo $this->_tpl_vars['item_players']; ?>
<?php echo $this->_tpl_vars['item_player']; ?>
</td>
      </tr>
      </tr>
              <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Jumped:</td>
              <td class="formtext"><br>&nbsp;&nbsp;&nbsp;&nbsp;<?php echo $this->_tpl_vars['jumpes']; ?>
<br></td>
      </tr>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Speed km/h </td>
              <td><?php echo $this->_tpl_vars['item_speed']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Distance</td>
              <td><?php echo $this->_tpl_vars['item_distance']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Distance points <?php echo $this->_tpl_vars['meterpoint']; ?>
 p/m</td>
              <td><?php echo $this->_tpl_vars['item_distancepoints']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 1</td>
              <td><?php echo $this->_tpl_vars['item_grade1']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 2</td>
              <td><?php echo $this->_tpl_vars['item_grade2']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 3</td>
              <td><?php echo $this->_tpl_vars['item_grade3']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 4</td>
              <td><?php echo $this->_tpl_vars['item_grade4']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 5</td>
              <td><?php echo $this->_tpl_vars['item_grade5']; ?>
</td>
      </tr>
              <tr>
              <td width="200" class="formtext">&nbsp;</td>
              <td>
                 <img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">
                 <input type ="submit" value="submit"><br>

      </tr>
      <?php endif; ?> 
      </table>
      <?php echo $this->_tpl_vars['form_end']; ?>



<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/footer.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>