{include file=olympics/header.tpl}
<a href="index.php" class="pathlinks">Home</a> -> <a href="search.php" class="pathlinks">Search</a><br>
<!-- begin main -->
<br>
The Results Information System provides the users to make a search request. Such request can be done by searching on data types, for example name or last name of a sport participant. It's also possible to make a search request to view a particular Olympic history records (statistics). This can be done by using the following criteria (data type) such as date. The system will search in the Results Information database if the requested search data is available.<br>                                                                                              
<form name="formulier" action="search.php" method="post">
<table border="0" width="350" cellspacing="0" cellpadding="0">
        <tr>
        <td width="110" class="formtext" valign="top"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Search</td>
        <td><input class="login_input" type="text" name="search" size="30" maxlength="40"><br><br></td>
</tr>   
        <tr>
        <td width="110" class="formtext" valign="middle"><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle">Choice</td>
        <td width="150" height="30" class="formtext" valign="middle">Name: <input type="radio" checked name="choice" size="30" value="search_name" maxlength="40">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Date:<input type="radio" name="choice" size="30" value="search_date" maxlength="40"></td>                                                                                                               
</tr>
        <tr>
        <td width="110" class="formtext">&nbsp;</td>
        <td><input type="hidden" name="action" value="submit"><br><img src="images/arrow.gif" width="11" height="17" alt="" border="0" align="absmiddle"><a href="javascript:document.forms[0].submit();" class="more">Submit</a></td>
</tr>
</table>
</form>

<br>
<table width="550" border="0" cellpadding="1" cellspacing="1">
<tr bgcolor="#eeeeee">
        <td class="tbltext" align="center" colspan="5">Ski Jumping Search Results</td>
</tr>
<tr bgcolor="#b9b9b9">
        <td class="tbltext" align="left"><b>Rank</b></td>
        <td class="tbltext" align="left"><b>Player Name</b></td>
        <td class="tbltext" align="center"><b>date</b></td>
        <td class="tbltext" align="center"><b>Round</b></td>
        <td class="tbltext" align="center"><b>Dist.[m]</b></td>
        <td class="tbltext" align="center"><b>Dist.[pts]</b></td>
        <td class="tbltext" align="center"><b>A</b></td>
        <td class="tbltext" align="center"><b>B</b></td>
        <td class="tbltext" align="center"><b>C</b></td>
        <td class="tbltext" align="center"><b>D</b></td>
        <td class="tbltext" align="center"><b>Total</b></td>
</tr>
<!-- loop search records -->
<tr bgcolor="#f0f0f0">
        <td class="tbltext" align="left">1</td>
        <td class="tbltext" align="left">Carl Suares</td>
        <td class="tbltext" align="center">12-12-2000</td>
        <td class="tbltext" align="center">10</td>
        <td class="tbltext" align="center">95,0</td>
        <td class="tbltext" align="center">70,0</td>
        <td class="tbltext" align="center">18,5</td>
        <td class="tbltext" align="center">18,5</td>
        <td class="tbltext" align="center">18,5</td>
        <td class="tbltext" align="center">17,5</td>
        <td class="tbltext" align="center">170,0</td>
</tr>                                                                                           
<tr bgcolor="#f0f0f0">
        <td class="tbltext" align="left">2</td>
        <td class="tbltext" align="left">Carl Suares</td>
        <td class="tbltext" align="center">13-12-2000</td>
        <td class="tbltext" align="center">9</td>
        <td class="tbltext" align="center">85,0</td>
        <td class="tbltext" align="center">70,0</td>
        <td class="tbltext" align="center">18,5</td>
        <td class="tbltext" align="center">18,5</td>
        <td class="tbltext" align="center">19,5</td>
        <td class="tbltext" align="center">19,5</td>
        <td class="tbltext" align="center">180,0</td>
</tr>   
<!-- end loop -->
</table>

{include file=olympics/footer.tpl}
