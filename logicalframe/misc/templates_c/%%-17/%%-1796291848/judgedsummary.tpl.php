<?php /* Smarty version 2.4.2, created on 2004-02-09 11:43:56
         compiled from olympics/judgedsummary.tpl */ ?>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/header.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>

  This information is added into the database


      <table border="0" width="400" cellspacing="0" cellpadding="0">
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Player</td>
              <td><?php echo $this->_tpl_vars['results']['player_id']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Speed km/h </td>
              <td><?php echo $this->_tpl_vars['results']['speed']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Distance</td>
              <td><?php echo $this->_tpl_vars['results']['distance']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Distance points <?php echo $this->_tpl_vars['meterpoint']; ?>
 p/m</td>
              <td><?php echo $this->_tpl_vars['results']['distancepoints']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 1</td>
              <td><?php echo $this->_tpl_vars['results']['mark1']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 2</td>
              <td><?php echo $this->_tpl_vars['results']['mark2']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 3</td>
              <td><?php echo $this->_tpl_vars['results']['mark3']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 4</td>
              <td><?php echo $this->_tpl_vars['results']['mark4']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 5</td>
              <td><?php echo $this->_tpl_vars['results']['mark5']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Judges Points</td>
              <td><?php echo $this->_tpl_vars['results']['judgespoints']; ?>
</td>
      </tr>
      <tr>
              <td width="200" class="formtext">&nbsp;</td>
              <td><b>------------</b></td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Total Points</td>
              <td><?php echo $this->_tpl_vars['results']['totalpoints']; ?>
<p></td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle"></td>
              <td><a href="judge.php">Add new result</a></td>
      </tr>
      
      </table>


<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include("olympics/footer.tpl", array());
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>