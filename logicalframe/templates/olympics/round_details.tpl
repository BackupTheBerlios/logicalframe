{include file=olympics/header.tpl}
<table width="550" border="0" cellpadding="1" cellspacing="1">
<tr bgcolor="#eeeeee">
        <td class="tbltext" align="center" colspan="5">Ski Jumping Search Results</td>
</tr>
<tr bgcolor="#b9b9b9">
        <td class="tbltext" align="left"><b>Rank</b></td>
        <td class="tbltext" align="left"><b>Player Name</b></td>
        <td class="tbltext" align="left"><b>Nationality</b></td>
        <td class="tbltext" align="center"><b>Speed</b></td>
        <td class="tbltext" align="center"><b>Distance [m]</b></td>
        <td class="tbltext" align="center"><b>Distance [pts]</b></td>
        <td class="tbltext" align="center"><b>A</b></td>
        <td class="tbltext" align="center"><b>B</b></td>
        <td class="tbltext" align="center"><b>C</b></td>
        <td class="tbltext" align="center"><b>D</b></td>
        <td class="tbltext" align="center"><b>E</b></td>
        <td class="tbltext" align="center"><b>Judges Points</b></td>
        <td class="tbltext" align="center"><b>Total</b></td>
</tr>
<!-- loop search records -->
{section name=data loop=$round}
<tr bgcolor="{cycle values="#dddddd,#eeeeee"}">
        <td class="tbltext" align="left">{$round[data].rank}</td>
        <td class="tbltext" align="left">{$round[data].surname}</td>
        <td class="tbltext" align="left">{$round[data].nationality}</td>
        <td class="tbltext" align="center">{$round[data].speed}</td>
        <td class="tbltext" align="center">{$round[data].distance}</td>
        <td class="tbltext" align="center">{$round[data].distancepoints}</td>
        <td class="tbltext" align="center">{$round[data].mark1}</td>
        <td class="tbltext" align="center">{$round[data].mark2}</td>
        <td class="tbltext" align="center">{$round[data].mark3}</td>
        <td class="tbltext" align="center">{$round[data].mark4}</td>
        <td class="tbltext" align="center">{$round[data].mark5}</td>
        <td class="tbltext" align="center">{$round[data].judgespoints}</td>
        <td class="tbltext" align="center">{$round[data].totalpoints}</td>
</tr>                        
{/section}
<!-- end loop -->
</table>
{include file=olympics/footer.tpl}
