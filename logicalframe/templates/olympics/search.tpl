{include file=olympics/header.tpl}
<!-- begin main -->
<br>
The Results Information System provides the users the ability to search in the database. 
Such request can be done by searching on data types, for example name or last name of a sport participant. 
<p>
<p>
{$errors}

<p>

{$form_begin}
<form name="formulier" action="search.php" method="post">
<table border="0" width="350" cellspacing="0" cellpadding="0">
        <tr>
        <td width="110" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Search</td>
        <td>{$item_search}<br><br></td>
</tr>   
        <tr class="formtext">
        <td width="110" class="formtext" valign="middle"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle"></td>
        <td width="150" height="30" class="formtext" valign="middle">{$item_criteria}</td>
</tr>
        <tr>
        <td width="110" class="formtext">&nbsp;</td>
        <td><input type="submit" name="submit" value="submit"></td>
</tr>
</table>
</form>
{$form_end}


{if $results!=""}
    <table width="550" border="0" cellpadding="1" cellspacing="1">
    <tr bgcolor="#eeeeee">
            <td class="tbltext" align="center" colspan="5">Ski Jumping Search Results</td>
    </tr>
    <tr bgcolor="#b9b9b9">
            <td class="tbltext" align="left"><b>Round </b></td>
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
    {section name=data loop=$results}
    <tr bgcolor="{cycle values="#dddddd,#eeeeee"}">
            <td class="tbltext" align="left">{$results[data].name}</td>
            <td class="tbltext" align="left">{$results[data].surname}</td>
            <td class="tbltext" align="left">{$results[data].nationality}</td>
            <td class="tbltext" align="center">{$results[data].speed}</td>
            <td class="tbltext" align="center">{$results[data].distance}</td>
            <td class="tbltext" align="center">{$results[data].distancepoints}</td>
            <td class="tbltext" align="center">{$results[data].mark1}</td>
            <td class="tbltext" align="center">{$results[data].mark2}</td>
            <td class="tbltext" align="center">{$results[data].mark3}</td>
            <td class="tbltext" align="center">{$results[data].mark4}</td>
            <td class="tbltext" align="center">{$results[data].mark5}</td>
            <td class="tbltext" align="center">{$results[data].judgespoints}</td>
            <td class="tbltext" align="center">{$results[data].totalpoints}</td>
    </tr>
    <tr bgcolor="{cycle values="#dddddd,#eeeeee"}">    
            <td class="tbltext" colspan="2"align="center">history data:</td>
            <td class="tbltext" colspan="11" align="center">{$results[data].history}</td>
    </tr>    
    {/section}
    <!-- end loop -->
    </table>
{/if}
{include file=olympics/footer.tpl}
