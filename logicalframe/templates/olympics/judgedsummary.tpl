{include file=olympics/header.tpl}

  This information is added into the database


      <table border="0" width="400" cellspacing="0" cellpadding="0">
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Player</td>
              <td>{$results.player_id}</td>
      </tr>
      <tr>
              <td width="200" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Speed km/h </td>
              <td>{$results.speed}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Distance</td>
              <td>{$results.distance}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Distance points {$meterpoint} p/m</td>
              <td>{$results.distancepoints}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 1</td>
              <td>{$results.mark1}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 2</td>
              <td>{$results.mark2}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 3</td>
              <td>{$results.mark3}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 4</td>
              <td>{$results.mark4}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Style point judge # 5</td>
              <td>{$results.mark5}</td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Judges Points</td>
              <td>{$results.judgespoints}</td>
      </tr>
      <tr>
              <td width="200" class="formtext">&nbsp;</td>
              <td><b>------------</b></td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Total Points</td>
              <td>{$results.totalpoints}<p></td>
      </tr>
      <tr>
              <td width="200" class="formtext"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle"></td>
              <td><a href="judge.php">Add new result</a></td>
      </tr>
      
      </table>


{include file=olympics/footer.tpl}
