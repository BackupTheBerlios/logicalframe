{include file=olympics/header.tpl}
<!-- begin main -->
<br>

<br>
<table width="550" border="0" cellpadding="1" cellspacing="1">
<tr bgcolor="#eeeeee">
        <td class="tbltext" align="center" colspan="5">Programmed Rounds</td>
</tr>
<tr bgcolor="#b9b9b9">
        <td class="tbltext" align="left"><b>round-id</b></td>
        <td class="tbltext" align="left"><b>Name</b></td>
        <td class="tbltext" align="center"><b>Start date</b></td>
        <td class="tbltext" align="center"><b>End date</b></td>
        <td class="tbltext" align="center"><b>Hill Type</b></td>
</tr>

{section name=data loop=$rounds}
<!-- loop search records -->
<tr bgcolor="{cycle values="#eeeeee,#dddddd"}">
  
        <td class="tbltext" align="left"><a href="round_details.php?round_id={$rounds[data].round_id}" alt="">{$rounds[data].round_id}</a></td>
        <td class="tbltext" align="left"><a href="round_details.php?round_id={$rounds[data].round_id}" alt="">{$rounds[data].name}</a></td>
        <td class="tbltext" align="center"><a href="round_details.php?round_id={$rounds[data].round_id}" alt="">{$rounds[data].startdate}</a></td>
        <td class="tbltext" align="center"><a href="round_details.php?round_id={$rounds[data].round_id}" alt="">{$rounds[data].enddate}</a></td>
        <td class="tbltext" align="center"><a href="round_details.php?round_id={$rounds[data].round_id}" alt="">{$rounds[data].hill}</a></td>
</a>                                                                                           
</tr>
{/section}
<!-- end loop -->
</table>

{include file=olympics/footer.tpl}
