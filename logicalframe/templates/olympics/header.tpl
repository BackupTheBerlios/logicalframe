<html>
<head>
<title>Ski Jumping :: Result Information System</title>
<link rel="stylesheet" type="text/css" href="stylesheets/olympics/default.css">
</head>
<body>
<table border="0" cellspacing="0" cellpadding="0" width="760">
        <tr>
                <td width="200"><img src="images/5.jpg" alt="Ski Jumping" width="110" height="66"></td>
        <td><img src="images/1.jpg" alt="Ski Jumping" border="0"></td>
            <td><img src="images/2.jpg" alt="Ski Jumping" border="0"></td>
        <td><img src="images/3.jpg" alt="Ski Jumping" border="0"></td>
            <td><img src="images/4.jpg" alt="Ski Jumping" width="208" height="66" border="0"></td>         
        </tr>
</table>
<table border="0" cellspacing="0" cellpadding="0" width="817">
        <tr>
                <td width="32" bgcolor="#3398CC"></td>
        <td rowspan="2" align="right" width="161" background="images/5.jpg"><img src="images/menu_curve_off_02.gif" alt="" width="31" height="31" border="0"></td>
        <td width="95" class="topnav_off" bgcolor="#666666">&nbsp;&nbsp;&nbsp;&nbsp;<a href="index.php" class="topnav">Home</a></td>
        <td width="1"><img src="images/pixel_white.gif" alt="" width="1" height="30" border="0"></td>
        <td width="125" align="center" class="topnav_off" bgcolor="#666666"><a href="scores.php" class="topnav">Scores</a></td>
        <td width="1"><img src="/images/pixel_white.gif" alt="" width="1" height="30" border="0"></td>
        <td width="125" align="center" class="topnav_off" bgcolor="#B91450"><a href="teams.php" class="topnav">Teams</a></td>
        <td width="1"><img src="/images/pixel_white.gif" alt="" width="1" height="30" border="0"></td>
        <td width="125" align="center" class="topnav_off" bgcolor="#666666"><a href="news.php" class="topnav">News</a></td>
                <td width="1"><img src="/images/pixel_white.gif" alt="" width="1" height="30" border="0"></td>
        <td width="125" align="center" class="topnav_off" bgcolor="#B91450">{if $role!=""}<a href="logout.php" class="topnav">Logout</a>{else}<a href="login.php" class="topnav">Login</a>{/if}</td>
                <td width="1"><img src="/images/pixel_white.gif" alt="" width="1" height="30" border="0"></td>
                <td width="125" align="center" class="topnav_off" bgcolor="#666666">{if $role!=""}&nbsp;{else}<a href="signup.php" class="topnav">Sign Up</a>{/if}</td>
        </tr>
        <tr>
        <td colspan="9" bgcolor="#eeeeee" height="1"><img src="/images/pixel_white.gif" alt="" width="95" height="1" border="0"></td>
        </tr>
</table>
<table border="0" cellspacing="0" cellpadding="0" width="760">
        <tr>
        <td valign="top" align="center" bgcolor="#eeeeee" width="226">
                <table border="0" cellspacing="0" cellpadding="0">
                        <tr>
                                <td><script language="JavaScript1.2" src="script/image.js"></script></td>
                                </tr>
                                <tr>
                                        <td>
                        <table width="226" cellspacing="0" cellpadding="0" border="0" bgcolor="#eeeeee">
                                                        <tr>
                                <td bgcolor="#eeeeee" height="20">
                                        <img src="images/menu_arrow_grey.gif" border="0" alt="" align="absmiddle" width="25" height="20">
                                        <a href="history.php" class="menulinks">-History-</a>
                                    </td>
                                                        </tr>
                                                        <tr>
                                <td bgcolor="#CCCCCC">
                                        <img src="images/pixel.gif" width="256" height="1" border="0" alt="">
                                    </td>
                                                        </tr>
                                                        <tr>
                                <td bgcolor="#eeeeee" height="20">
                                        <img src="images/menu_arrow_grey.gif" border="0" alt="" align="absmiddle" width="25" height="20">
                                        <a href="rules.php" class="menulinks">-GameRules-</a>
                                    </td>
                                                        </tr>
                                                        <tr>
                                <td bgcolor="#CCCCCC">
                                        <img src="images/pixel.gif" width="256" height="1" border="0" alt="">
                                    </td>
                                                        </tr>
                                                        <tr>
                                                                <td bgcolor="#eeeeee" height="20">
                                        <img src="images/menu_arrow_grey.gif" border="0" alt="" align="absmiddle" width="25" height="20">
                                        <a href="schedule.php" class="menulinks">-Schedule-</a>
                                </td>
                                                        </tr>
                                                        <tr>
                                                                <td bgcolor="#CCCCCC">
                                        <img src="images/pixel.gif" width="256" height="1" border="0" alt="">
                                </td>
                                                        </tr>
                                <tr>
                                <td bgcolor="#eeeeee" height="20">
                                        <img src="images/menu_arrow_grey.gif" border="0" alt="" align="absmiddle" width="25" height="20">
                                        <a href="search.php" class="menulinks">-Search-</a>
                                    </td>
                                                        </tr>
                            <tr>
                                                                <td bgcolor="#CCCCCC">
                                        <img src="images/pixel.gif" width="256" height="1" border="0" alt="">
                                </td>
                                                        </tr>                                                   
                                                </table>
                                        </td>
                                </tr>
                        </table>
                </td>        
        <td valign="top" width="500" height="225"><br>          
                        <table border="0" cellspacing="0" cellpadding="0">
                                <tr>
                                        <td><img src="/images/pixel.gif" alt="" width="15" height="1" border="0"></td>
                                        <td valign="top">
                        <table border="0" width="450" cellspacing="0" cellpadding="0">
                                                        
                                                        <tr>
                                                        <td valign="top" class="subtitle">Ski-jumping result information system</td>
                                                        </tr>
                                                        <tr>
                                                        <td valign="top">
                                                                <table border="0" width="550" cellspacing="0" cellpadding="0">
                                                                        <tr>
                                                                                <td valign="top" background="../images/dotline_h.gif" width="550"><img src="/images/pixel.gif" alt="" width="1" height="1" border="0"></td>
                                                                        </tr>
                                                                        <tr>
                                                                                <td valign="top" class="bodytext">
                                                                                                <!-- end header -->
{if $role=="judge"}
<p><br>
Logged in as a judge: <br><br>
<a href="addplayer.php">Add player</a>&nbsp;&nbsp;&nbsp;&nbsp;
<a href="addplayer.php">Schedule rounds</a>&nbsp;&nbsp;&nbsp;&nbsp;
<a href="judge.php">Judge Jumps</a>&nbsp;&nbsp;&nbsp;&nbsp;
{/if}
