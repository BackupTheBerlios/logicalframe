# phpMyAdmin MySQL-Dump
# version 2.3.2
# http://www.phpmyadmin.net/ (download page)
#
# Host: localhost
# Generation Time: Feb 12, 2004 at 03:22 AM
# Server version: 4.00.16
# PHP Version: 4.3.4
# Database : `logicalframe`
# --------------------------------------------------------

#
# Table structure for table `countries`
#

CREATE TABLE countries (
  country_id char(2) NOT NULL default '',
  country varchar(40) NOT NULL default ''
) TYPE=MyISAM;

#
# Dumping data for table `countries`
#

INSERT INTO countries VALUES ('AF', 'Afghanistan');
INSERT INTO countries VALUES ('AL', 'Albania');
INSERT INTO countries VALUES ('DZ', 'Algeria');
INSERT INTO countries VALUES ('AS', 'American Samoa');
INSERT INTO countries VALUES ('AD', 'Andorra');
INSERT INTO countries VALUES ('AO', 'Angola');
INSERT INTO countries VALUES ('AI', 'Anguilla');
INSERT INTO countries VALUES ('AQ', 'Antarctica');
INSERT INTO countries VALUES ('AG', 'Antigua and Barbuda');
INSERT INTO countries VALUES ('AR', 'Argentina');
INSERT INTO countries VALUES ('AM', 'Armenia');
INSERT INTO countries VALUES ('AW', 'Aruba');
INSERT INTO countries VALUES ('AU', 'Australia');
INSERT INTO countries VALUES ('AT', 'Austria');
INSERT INTO countries VALUES ('AZ', 'Azerbaijan');
INSERT INTO countries VALUES ('BS', 'Bahamas');
INSERT INTO countries VALUES ('BH', 'Bahrain');
INSERT INTO countries VALUES ('BD', 'Bangladesh');
INSERT INTO countries VALUES ('BB', 'Barbados');
INSERT INTO countries VALUES ('BY', 'Belarus');
INSERT INTO countries VALUES ('BE', 'Belgium');
INSERT INTO countries VALUES ('BZ', 'Belize');
INSERT INTO countries VALUES ('BJ', 'Benin');
INSERT INTO countries VALUES ('BM', 'Bermuda');
INSERT INTO countries VALUES ('BT', 'Bhutan');
INSERT INTO countries VALUES ('BO', 'Bolivia');
INSERT INTO countries VALUES ('BA', 'Bosnia and Herzegovina');
INSERT INTO countries VALUES ('BW', 'Botswana');
INSERT INTO countries VALUES ('BV', 'Bouvet Island');
INSERT INTO countries VALUES ('BR', 'Brazil');
INSERT INTO countries VALUES ('IO', 'British Indian Ocean Territory');
INSERT INTO countries VALUES ('BN', 'Brunei');
INSERT INTO countries VALUES ('BG', 'Bulgaria');
INSERT INTO countries VALUES ('BF', 'Burkina Faso');
INSERT INTO countries VALUES ('BI', 'Burundi');
INSERT INTO countries VALUES ('KH', 'Cambodia');
INSERT INTO countries VALUES ('CM', 'Cameroon');
INSERT INTO countries VALUES ('CA', 'Canada');
INSERT INTO countries VALUES ('CV', 'Cape Verde');
INSERT INTO countries VALUES ('KY', 'Cayman Islands');
INSERT INTO countries VALUES ('CF', 'Central African Republic');
INSERT INTO countries VALUES ('TD', 'Chad');
INSERT INTO countries VALUES ('CL', 'Chile');
INSERT INTO countries VALUES ('CN', 'China');
INSERT INTO countries VALUES ('CX', 'Christmas Island');
INSERT INTO countries VALUES ('CC', 'Cocos &#40;Keeling&#41; Islands');
INSERT INTO countries VALUES ('CO', 'Colombia');
INSERT INTO countries VALUES ('KM', 'Comoros');
INSERT INTO countries VALUES ('CG', 'Congo');
INSERT INTO countries VALUES ('CK', 'Cook Islands');
INSERT INTO countries VALUES ('CR', 'Costa Rica');
INSERT INTO countries VALUES ('CI', 'Côte d&#39;Ivoire');
INSERT INTO countries VALUES ('HR', 'Croatia &#40;Hrvatska&#41;');
INSERT INTO countries VALUES ('CU', 'Cuba');
INSERT INTO countries VALUES ('CY', 'Cyprus');
INSERT INTO countries VALUES ('CZ', 'Czech Republic');
INSERT INTO countries VALUES ('CD', 'Congo &#40;DRC&#41;');
INSERT INTO countries VALUES ('DK', 'Denmark');
INSERT INTO countries VALUES ('DJ', 'Djibouti');
INSERT INTO countries VALUES ('DM', 'Dominica');
INSERT INTO countries VALUES ('DO', 'Dominican Republic');
INSERT INTO countries VALUES ('TP', 'East Timor');
INSERT INTO countries VALUES ('EC', 'Ecuador');
INSERT INTO countries VALUES ('EG', 'Egypt');
INSERT INTO countries VALUES ('SV', 'El Salvador');
INSERT INTO countries VALUES ('GQ', 'Equatorial Guinea');
INSERT INTO countries VALUES ('ER', 'Eritrea');
INSERT INTO countries VALUES ('EE', 'Estonia');
INSERT INTO countries VALUES ('ET', 'Ethiopia');
INSERT INTO countries VALUES ('FK', 'Falkland Islands &#40;Islas Malvinas&#41');
INSERT INTO countries VALUES ('FO', 'Faroe Islands');
INSERT INTO countries VALUES ('FJ', 'Fiji Islands');
INSERT INTO countries VALUES ('FI', 'Finland');
INSERT INTO countries VALUES ('FR', 'France');
INSERT INTO countries VALUES ('GF', 'French Guiana');
INSERT INTO countries VALUES ('PF', 'French Polynesia');
INSERT INTO countries VALUES ('TF', 'French Southern and Antarctic Lands');
INSERT INTO countries VALUES ('GA', 'Gabon');
INSERT INTO countries VALUES ('GM', 'Gambia');
INSERT INTO countries VALUES ('GE', 'Georgia');
INSERT INTO countries VALUES ('DE', 'Germany');
INSERT INTO countries VALUES ('GH', 'Ghana');
INSERT INTO countries VALUES ('GI', 'Gibraltar');
INSERT INTO countries VALUES ('GR', 'Greece');
INSERT INTO countries VALUES ('GL', 'Greenland');
INSERT INTO countries VALUES ('GD', 'Grenada');
INSERT INTO countries VALUES ('GP', 'Guadeloupe');
INSERT INTO countries VALUES ('GU', 'Guam');
INSERT INTO countries VALUES ('GT', 'Guatemala');
INSERT INTO countries VALUES ('GN', 'Guinea');
INSERT INTO countries VALUES ('GW', 'Guinea-Bissau');
INSERT INTO countries VALUES ('GY', 'Guyana');
INSERT INTO countries VALUES ('HT', 'Haiti');
INSERT INTO countries VALUES ('HM', 'Heard Island and McDonald Islands');
INSERT INTO countries VALUES ('HN', 'Honduras');
INSERT INTO countries VALUES ('HK', 'Hong Kong SAR');
INSERT INTO countries VALUES ('HU', 'Hungary');
INSERT INTO countries VALUES ('IS', 'Iceland');
INSERT INTO countries VALUES ('IN', 'India');
INSERT INTO countries VALUES ('ID', 'Indonesia');
INSERT INTO countries VALUES ('IR', 'Iran');
INSERT INTO countries VALUES ('IQ', 'Iraq');
INSERT INTO countries VALUES ('IE', 'Ireland');
INSERT INTO countries VALUES ('IL', 'Israel');
INSERT INTO countries VALUES ('IT', 'Italy');
INSERT INTO countries VALUES ('JM', 'Jamaica');
INSERT INTO countries VALUES ('JP', 'Japan');
INSERT INTO countries VALUES ('JO', 'Jordan');
INSERT INTO countries VALUES ('KZ', 'Kazakhstan');
INSERT INTO countries VALUES ('KE', 'Kenya');
INSERT INTO countries VALUES ('KI', 'Kiribati');
INSERT INTO countries VALUES ('KR', 'Korea');
INSERT INTO countries VALUES ('KW', 'Kuwait');
INSERT INTO countries VALUES ('KG', 'Kyrgyzstan');
INSERT INTO countries VALUES ('LA', 'Laos');
INSERT INTO countries VALUES ('LV', 'Latvia');
INSERT INTO countries VALUES ('LB', 'Lebanon');
INSERT INTO countries VALUES ('LS', 'Lesotho');
INSERT INTO countries VALUES ('LR', 'Liberia');
INSERT INTO countries VALUES ('LY', 'Libya');
INSERT INTO countries VALUES ('LI', 'Liechtenstein');
INSERT INTO countries VALUES ('LT', 'Lithuania');
INSERT INTO countries VALUES ('LU', 'Luxembourg');
INSERT INTO countries VALUES ('MO', 'Macao SAR');
INSERT INTO countries VALUES ('MK', 'Macedonia, Former Yugoslav Republic of');
INSERT INTO countries VALUES ('MG', 'Madagascar');
INSERT INTO countries VALUES ('MW', 'Malawi');
INSERT INTO countries VALUES ('MY', 'Malaysia');
INSERT INTO countries VALUES ('MV', 'Maldives');
INSERT INTO countries VALUES ('ML', 'Mali');
INSERT INTO countries VALUES ('MT', 'Malta');
INSERT INTO countries VALUES ('MH', 'Marshall Islands');
INSERT INTO countries VALUES ('MQ', 'Martinique');
INSERT INTO countries VALUES ('MR', 'Mauritania');
INSERT INTO countries VALUES ('MU', 'Mauritius');
INSERT INTO countries VALUES ('YT', 'Mayotte');
INSERT INTO countries VALUES ('MX', 'Mexico');
INSERT INTO countries VALUES ('FM', 'Micronesia');
INSERT INTO countries VALUES ('MD', 'Moldova');
INSERT INTO countries VALUES ('MC', 'Monaco');
INSERT INTO countries VALUES ('MN', 'Mongolia');
INSERT INTO countries VALUES ('MS', 'Montserrat');
INSERT INTO countries VALUES ('MA', 'Morocco');
INSERT INTO countries VALUES ('MZ', 'Mozambique');
INSERT INTO countries VALUES ('MM', 'Myanmar');
INSERT INTO countries VALUES ('NA', 'Namibia');
INSERT INTO countries VALUES ('NR', 'Nauru');
INSERT INTO countries VALUES ('NP', 'Nepal');
INSERT INTO countries VALUES ('NL', 'Netherlands');
INSERT INTO countries VALUES ('AN', 'Netherlands Antilles');
INSERT INTO countries VALUES ('NC', 'New Caledonia');
INSERT INTO countries VALUES ('NZ', 'New Zealand');
INSERT INTO countries VALUES ('NI', 'Nicaragua');
INSERT INTO countries VALUES ('NE', 'Niger');
INSERT INTO countries VALUES ('NG', 'Nigeria');
INSERT INTO countries VALUES ('NU', 'Niue');
INSERT INTO countries VALUES ('NF', 'Norfolk Island');
INSERT INTO countries VALUES ('KP', 'North Korea');
INSERT INTO countries VALUES ('MP', 'Northern Mariana Islands');
INSERT INTO countries VALUES ('NO', 'Norway');
INSERT INTO countries VALUES ('OM', 'Oman');
INSERT INTO countries VALUES ('PK', 'Pakistan');
INSERT INTO countries VALUES ('PW', 'Palau');
INSERT INTO countries VALUES ('PA', 'Panama');
INSERT INTO countries VALUES ('PG', 'Papua New Guinea');
INSERT INTO countries VALUES ('PY', 'Paraguay');
INSERT INTO countries VALUES ('PE', 'Peru');
INSERT INTO countries VALUES ('PH', 'Philippines');
INSERT INTO countries VALUES ('PN', 'Pitcairn Islands');
INSERT INTO countries VALUES ('PL', 'Poland');
INSERT INTO countries VALUES ('PT', 'Portugal');
INSERT INTO countries VALUES ('PR', 'Puerto Rico');
INSERT INTO countries VALUES ('QA', 'Qatar');
INSERT INTO countries VALUES ('RE', 'Reunion');
INSERT INTO countries VALUES ('RO', 'Romania');
INSERT INTO countries VALUES ('RU', 'Russia');
INSERT INTO countries VALUES ('RW', 'Rwanda');
INSERT INTO countries VALUES ('WS', 'Samoa');
INSERT INTO countries VALUES ('SM', 'San Marino');
INSERT INTO countries VALUES ('ST', 'São Tomé and Príncipe');
INSERT INTO countries VALUES ('SA', 'Saudi Arabia');
INSERT INTO countries VALUES ('SN', 'Senegal');
INSERT INTO countries VALUES ('YU', 'Serbia and Montenegro');
INSERT INTO countries VALUES ('SC', 'Seychelles');
INSERT INTO countries VALUES ('SL', 'Sierra Leone');
INSERT INTO countries VALUES ('SG', 'Singapore');
INSERT INTO countries VALUES ('SK', 'Slovakia');
INSERT INTO countries VALUES ('SI', 'Slovenia');
INSERT INTO countries VALUES ('SB', 'Solomon Islands');
INSERT INTO countries VALUES ('SO', 'Somalia');
INSERT INTO countries VALUES ('ZA', 'South Africa');
INSERT INTO countries VALUES ('GS', 'South Georgia and the South Sandwich Isl');
INSERT INTO countries VALUES ('ES', 'Spain');
INSERT INTO countries VALUES ('LK', 'Sri Lanka');
INSERT INTO countries VALUES ('SH', 'St. Helena');
INSERT INTO countries VALUES ('KN', 'St. Kitts and Nevis');
INSERT INTO countries VALUES ('LC', 'St. Lucia');
INSERT INTO countries VALUES ('PM', 'St. Pierre and Miquelon');
INSERT INTO countries VALUES ('VC', 'St. Vincent and the Grenadines');
INSERT INTO countries VALUES ('SD', 'Sudan');
INSERT INTO countries VALUES ('SR', 'Suriname');
INSERT INTO countries VALUES ('SJ', 'Svalbard and Jan Mayen');
INSERT INTO countries VALUES ('SZ', 'Swaziland');
INSERT INTO countries VALUES ('SE', 'Sweden');
INSERT INTO countries VALUES ('CH', 'Switzerland');
INSERT INTO countries VALUES ('SY', 'Syria');
INSERT INTO countries VALUES ('TW', 'Taiwan');
INSERT INTO countries VALUES ('TJ', 'Tajikistan');
INSERT INTO countries VALUES ('TZ', 'Tanzania');
INSERT INTO countries VALUES ('TH', 'Thailand');
INSERT INTO countries VALUES ('TG', 'Togo');
INSERT INTO countries VALUES ('TK', 'Tokelau');
INSERT INTO countries VALUES ('TO', 'Tonga');
INSERT INTO countries VALUES ('TT', 'Trinidad and Tobago');
INSERT INTO countries VALUES ('TN', 'Tunisia');
INSERT INTO countries VALUES ('TR', 'Turkey');
INSERT INTO countries VALUES ('TM', 'Turkmenistan');
INSERT INTO countries VALUES ('TC', 'Turks and Caicos Islands');
INSERT INTO countries VALUES ('TV', 'Tuvalu');
INSERT INTO countries VALUES ('UG', 'Uganda');
INSERT INTO countries VALUES ('UA', 'Ukraine');
INSERT INTO countries VALUES ('AE', 'United Arab Emirates');
INSERT INTO countries VALUES ('UK', 'United Kingdom');
INSERT INTO countries VALUES ('US', 'selected>United States');
INSERT INTO countries VALUES ('UM', 'United States Minor Outlying Islands');
INSERT INTO countries VALUES ('UY', 'Uruguay');
INSERT INTO countries VALUES ('UZ', 'Uzbekistan');
INSERT INTO countries VALUES ('VU', 'Vanuatu');
INSERT INTO countries VALUES ('VA', 'Vatican City');
INSERT INTO countries VALUES ('VE', 'Venezuela');
INSERT INTO countries VALUES ('VN', 'Viet Nam');
INSERT INTO countries VALUES ('VG', 'Virgin Islands &#40;British&#41;');
INSERT INTO countries VALUES ('VI', 'Virgin Islands');
INSERT INTO countries VALUES ('WF', 'Wallis and Futuna');
INSERT INTO countries VALUES ('YE', 'Yemen');
INSERT INTO countries VALUES ('ZM', 'Zambia');
INSERT INTO countries VALUES ('AF', 'Afghanistan');
INSERT INTO countries VALUES ('AL', 'Albania');
INSERT INTO countries VALUES ('DZ', 'Algeria');
INSERT INTO countries VALUES ('AS', 'American Samoa');
INSERT INTO countries VALUES ('AD', 'Andorra');
INSERT INTO countries VALUES ('AO', 'Angola');
INSERT INTO countries VALUES ('AI', 'Anguilla');
INSERT INTO countries VALUES ('AQ', 'Antarctica');
INSERT INTO countries VALUES ('AG', 'Antigua and Barbuda');
INSERT INTO countries VALUES ('AR', 'Argentina');
INSERT INTO countries VALUES ('AM', 'Armenia');
INSERT INTO countries VALUES ('AW', 'Aruba');
INSERT INTO countries VALUES ('AU', 'Australia');
INSERT INTO countries VALUES ('AT', 'Austria');
INSERT INTO countries VALUES ('AZ', 'Azerbaijan');
INSERT INTO countries VALUES ('BS', 'Bahamas');
INSERT INTO countries VALUES ('BH', 'Bahrain');
INSERT INTO countries VALUES ('BD', 'Bangladesh');
INSERT INTO countries VALUES ('BB', 'Barbados');
INSERT INTO countries VALUES ('BY', 'Belarus');
INSERT INTO countries VALUES ('BE', 'Belgium');
INSERT INTO countries VALUES ('BZ', 'Belize');
INSERT INTO countries VALUES ('BJ', 'Benin');
INSERT INTO countries VALUES ('BM', 'Bermuda');
INSERT INTO countries VALUES ('BT', 'Bhutan');
INSERT INTO countries VALUES ('BO', 'Bolivia');
INSERT INTO countries VALUES ('BA', 'Bosnia and Herzegovina');
INSERT INTO countries VALUES ('BW', 'Botswana');
INSERT INTO countries VALUES ('BV', 'Bouvet Island');
INSERT INTO countries VALUES ('BR', 'Brazil');
INSERT INTO countries VALUES ('IO', 'British Indian Ocean Territory');
INSERT INTO countries VALUES ('BN', 'Brunei');
INSERT INTO countries VALUES ('BG', 'Bulgaria');
INSERT INTO countries VALUES ('BF', 'Burkina Faso');
INSERT INTO countries VALUES ('BI', 'Burundi');
INSERT INTO countries VALUES ('KH', 'Cambodia');
INSERT INTO countries VALUES ('CM', 'Cameroon');
INSERT INTO countries VALUES ('CA', 'Canada');
INSERT INTO countries VALUES ('CV', 'Cape Verde');
INSERT INTO countries VALUES ('KY', 'Cayman Islands');
INSERT INTO countries VALUES ('CF', 'Central African Republic');
INSERT INTO countries VALUES ('TD', 'Chad');
INSERT INTO countries VALUES ('CL', 'Chile');
INSERT INTO countries VALUES ('CN', 'China');
INSERT INTO countries VALUES ('CX', 'Christmas Island');
INSERT INTO countries VALUES ('CC', 'Cocos &#40;Keeling&#41; Islands');
INSERT INTO countries VALUES ('CO', 'Colombia');
INSERT INTO countries VALUES ('KM', 'Comoros');
INSERT INTO countries VALUES ('CG', 'Congo');
INSERT INTO countries VALUES ('CK', 'Cook Islands');
INSERT INTO countries VALUES ('CR', 'Costa Rica');
INSERT INTO countries VALUES ('CI', 'Côte d&#39;Ivoire');
INSERT INTO countries VALUES ('HR', 'Croatia &#40;Hrvatska&#41;');
INSERT INTO countries VALUES ('CU', 'Cuba');
INSERT INTO countries VALUES ('CY', 'Cyprus');
INSERT INTO countries VALUES ('CZ', 'Czech Republic');
INSERT INTO countries VALUES ('CD', 'Congo &#40;DRC&#41;');
INSERT INTO countries VALUES ('DK', 'Denmark');
INSERT INTO countries VALUES ('DJ', 'Djibouti');
INSERT INTO countries VALUES ('DM', 'Dominica');
INSERT INTO countries VALUES ('DO', 'Dominican Republic');
INSERT INTO countries VALUES ('TP', 'East Timor');
INSERT INTO countries VALUES ('EC', 'Ecuador');
INSERT INTO countries VALUES ('EG', 'Egypt');
INSERT INTO countries VALUES ('SV', 'El Salvador');
INSERT INTO countries VALUES ('GQ', 'Equatorial Guinea');
INSERT INTO countries VALUES ('ER', 'Eritrea');
INSERT INTO countries VALUES ('EE', 'Estonia');
INSERT INTO countries VALUES ('ET', 'Ethiopia');
INSERT INTO countries VALUES ('FK', 'Falkland Islands &#40;Islas Malvinas&#41');
INSERT INTO countries VALUES ('FO', 'Faroe Islands');
INSERT INTO countries VALUES ('FJ', 'Fiji Islands');
INSERT INTO countries VALUES ('FI', 'Finland');
INSERT INTO countries VALUES ('FR', 'France');
INSERT INTO countries VALUES ('GF', 'French Guiana');
INSERT INTO countries VALUES ('PF', 'French Polynesia');
INSERT INTO countries VALUES ('TF', 'French Southern and Antarctic Lands');
INSERT INTO countries VALUES ('GA', 'Gabon');
INSERT INTO countries VALUES ('GM', 'Gambia');
INSERT INTO countries VALUES ('GE', 'Georgia');
INSERT INTO countries VALUES ('DE', 'Germany');
INSERT INTO countries VALUES ('GH', 'Ghana');
INSERT INTO countries VALUES ('GI', 'Gibraltar');
INSERT INTO countries VALUES ('GR', 'Greece');
INSERT INTO countries VALUES ('GL', 'Greenland');
INSERT INTO countries VALUES ('GD', 'Grenada');
INSERT INTO countries VALUES ('GP', 'Guadeloupe');
INSERT INTO countries VALUES ('GU', 'Guam');
INSERT INTO countries VALUES ('GT', 'Guatemala');
INSERT INTO countries VALUES ('GN', 'Guinea');
INSERT INTO countries VALUES ('GW', 'Guinea-Bissau');
INSERT INTO countries VALUES ('GY', 'Guyana');
INSERT INTO countries VALUES ('HT', 'Haiti');
INSERT INTO countries VALUES ('HM', 'Heard Island and McDonald Islands');
INSERT INTO countries VALUES ('HN', 'Honduras');
INSERT INTO countries VALUES ('HK', 'Hong Kong SAR');
INSERT INTO countries VALUES ('HU', 'Hungary');
INSERT INTO countries VALUES ('IS', 'Iceland');
INSERT INTO countries VALUES ('IN', 'India');
INSERT INTO countries VALUES ('ID', 'Indonesia');
INSERT INTO countries VALUES ('IR', 'Iran');
INSERT INTO countries VALUES ('IQ', 'Iraq');
INSERT INTO countries VALUES ('IE', 'Ireland');
INSERT INTO countries VALUES ('IL', 'Israel');
INSERT INTO countries VALUES ('IT', 'Italy');
INSERT INTO countries VALUES ('JM', 'Jamaica');
INSERT INTO countries VALUES ('JP', 'Japan');
INSERT INTO countries VALUES ('JO', 'Jordan');
INSERT INTO countries VALUES ('KZ', 'Kazakhstan');
INSERT INTO countries VALUES ('KE', 'Kenya');
INSERT INTO countries VALUES ('KI', 'Kiribati');
INSERT INTO countries VALUES ('KR', 'Korea');
INSERT INTO countries VALUES ('KW', 'Kuwait');
INSERT INTO countries VALUES ('KG', 'Kyrgyzstan');
INSERT INTO countries VALUES ('LA', 'Laos');
INSERT INTO countries VALUES ('LV', 'Latvia');
INSERT INTO countries VALUES ('LB', 'Lebanon');
INSERT INTO countries VALUES ('LS', 'Lesotho');
INSERT INTO countries VALUES ('LR', 'Liberia');
INSERT INTO countries VALUES ('LY', 'Libya');
INSERT INTO countries VALUES ('LI', 'Liechtenstein');
INSERT INTO countries VALUES ('LT', 'Lithuania');
INSERT INTO countries VALUES ('LU', 'Luxembourg');
INSERT INTO countries VALUES ('MO', 'Macao SAR');
INSERT INTO countries VALUES ('MK', 'Macedonia, Former Yugoslav Republic of');
INSERT INTO countries VALUES ('MG', 'Madagascar');
INSERT INTO countries VALUES ('MW', 'Malawi');
INSERT INTO countries VALUES ('MY', 'Malaysia');
INSERT INTO countries VALUES ('MV', 'Maldives');
INSERT INTO countries VALUES ('ML', 'Mali');
INSERT INTO countries VALUES ('MT', 'Malta');
INSERT INTO countries VALUES ('MH', 'Marshall Islands');
INSERT INTO countries VALUES ('MQ', 'Martinique');
INSERT INTO countries VALUES ('MR', 'Mauritania');
INSERT INTO countries VALUES ('MU', 'Mauritius');
INSERT INTO countries VALUES ('YT', 'Mayotte');
INSERT INTO countries VALUES ('MX', 'Mexico');
INSERT INTO countries VALUES ('FM', 'Micronesia');
INSERT INTO countries VALUES ('MD', 'Moldova');
INSERT INTO countries VALUES ('MC', 'Monaco');
INSERT INTO countries VALUES ('MN', 'Mongolia');
INSERT INTO countries VALUES ('MS', 'Montserrat');
INSERT INTO countries VALUES ('MA', 'Morocco');
INSERT INTO countries VALUES ('MZ', 'Mozambique');
INSERT INTO countries VALUES ('MM', 'Myanmar');
INSERT INTO countries VALUES ('NA', 'Namibia');
INSERT INTO countries VALUES ('NR', 'Nauru');
INSERT INTO countries VALUES ('NP', 'Nepal');
INSERT INTO countries VALUES ('NL', 'Netherlands');
INSERT INTO countries VALUES ('AN', 'Netherlands Antilles');
INSERT INTO countries VALUES ('NC', 'New Caledonia');
INSERT INTO countries VALUES ('NZ', 'New Zealand');
INSERT INTO countries VALUES ('NI', 'Nicaragua');
INSERT INTO countries VALUES ('NE', 'Niger');
INSERT INTO countries VALUES ('NG', 'Nigeria');
INSERT INTO countries VALUES ('NU', 'Niue');
INSERT INTO countries VALUES ('NF', 'Norfolk Island');
INSERT INTO countries VALUES ('KP', 'North Korea');
INSERT INTO countries VALUES ('MP', 'Northern Mariana Islands');
INSERT INTO countries VALUES ('NO', 'Norway');
INSERT INTO countries VALUES ('OM', 'Oman');
INSERT INTO countries VALUES ('PK', 'Pakistan');
INSERT INTO countries VALUES ('PW', 'Palau');
INSERT INTO countries VALUES ('PA', 'Panama');
INSERT INTO countries VALUES ('PG', 'Papua New Guinea');
INSERT INTO countries VALUES ('PY', 'Paraguay');
INSERT INTO countries VALUES ('PE', 'Peru');
INSERT INTO countries VALUES ('PH', 'Philippines');
INSERT INTO countries VALUES ('PN', 'Pitcairn Islands');
INSERT INTO countries VALUES ('PL', 'Poland');
INSERT INTO countries VALUES ('PT', 'Portugal');
INSERT INTO countries VALUES ('PR', 'Puerto Rico');
INSERT INTO countries VALUES ('QA', 'Qatar');
INSERT INTO countries VALUES ('RE', 'Reunion');
INSERT INTO countries VALUES ('RO', 'Romania');
INSERT INTO countries VALUES ('RU', 'Russia');
INSERT INTO countries VALUES ('RW', 'Rwanda');
INSERT INTO countries VALUES ('WS', 'Samoa');
INSERT INTO countries VALUES ('SM', 'San Marino');
INSERT INTO countries VALUES ('ST', 'São Tomé and Príncipe');
INSERT INTO countries VALUES ('SA', 'Saudi Arabia');
INSERT INTO countries VALUES ('SN', 'Senegal');
INSERT INTO countries VALUES ('YU', 'Serbia and Montenegro');
INSERT INTO countries VALUES ('SC', 'Seychelles');
INSERT INTO countries VALUES ('SL', 'Sierra Leone');
INSERT INTO countries VALUES ('SG', 'Singapore');
INSERT INTO countries VALUES ('SK', 'Slovakia');
INSERT INTO countries VALUES ('SI', 'Slovenia');
INSERT INTO countries VALUES ('SB', 'Solomon Islands');
INSERT INTO countries VALUES ('SO', 'Somalia');
INSERT INTO countries VALUES ('ZA', 'South Africa');
INSERT INTO countries VALUES ('GS', 'South Georgia and the South Sandwich Isl');
INSERT INTO countries VALUES ('ES', 'Spain');
INSERT INTO countries VALUES ('LK', 'Sri Lanka');
INSERT INTO countries VALUES ('SH', 'St. Helena');
INSERT INTO countries VALUES ('KN', 'St. Kitts and Nevis');
INSERT INTO countries VALUES ('LC', 'St. Lucia');
INSERT INTO countries VALUES ('PM', 'St. Pierre and Miquelon');
INSERT INTO countries VALUES ('VC', 'St. Vincent and the Grenadines');
INSERT INTO countries VALUES ('SD', 'Sudan');
INSERT INTO countries VALUES ('SR', 'Suriname');
INSERT INTO countries VALUES ('SJ', 'Svalbard and Jan Mayen');
INSERT INTO countries VALUES ('SZ', 'Swaziland');
INSERT INTO countries VALUES ('SE', 'Sweden');
INSERT INTO countries VALUES ('CH', 'Switzerland');
INSERT INTO countries VALUES ('SY', 'Syria');
INSERT INTO countries VALUES ('TW', 'Taiwan');
INSERT INTO countries VALUES ('TJ', 'Tajikistan');
INSERT INTO countries VALUES ('TZ', 'Tanzania');
INSERT INTO countries VALUES ('TH', 'Thailand');
INSERT INTO countries VALUES ('TG', 'Togo');
INSERT INTO countries VALUES ('TK', 'Tokelau');
INSERT INTO countries VALUES ('TO', 'Tonga');
INSERT INTO countries VALUES ('TT', 'Trinidad and Tobago');
INSERT INTO countries VALUES ('TN', 'Tunisia');
INSERT INTO countries VALUES ('TR', 'Turkey');
INSERT INTO countries VALUES ('TM', 'Turkmenistan');
INSERT INTO countries VALUES ('TC', 'Turks and Caicos Islands');
INSERT INTO countries VALUES ('TV', 'Tuvalu');
INSERT INTO countries VALUES ('UG', 'Uganda');
INSERT INTO countries VALUES ('UA', 'Ukraine');
INSERT INTO countries VALUES ('AE', 'United Arab Emirates');
INSERT INTO countries VALUES ('UK', 'United Kingdom');
INSERT INTO countries VALUES ('US', 'selected>United States');
INSERT INTO countries VALUES ('UM', 'United States Minor Outlying Islands');
INSERT INTO countries VALUES ('UY', 'Uruguay');
INSERT INTO countries VALUES ('UZ', 'Uzbekistan');
INSERT INTO countries VALUES ('VU', 'Vanuatu');
INSERT INTO countries VALUES ('VA', 'Vatican City');
INSERT INTO countries VALUES ('VE', 'Venezuela');
INSERT INTO countries VALUES ('VN', 'Viet Nam');
INSERT INTO countries VALUES ('VG', 'Virgin Islands &#40;British&#41;');
INSERT INTO countries VALUES ('VI', 'Virgin Islands');
INSERT INTO countries VALUES ('WF', 'Wallis and Futuna');
INSERT INTO countries VALUES ('YE', 'Yemen');
INSERT INTO countries VALUES ('ZM', 'Zambia');
INSERT INTO countries VALUES ('ZW', 'Zimbabwe');
# --------------------------------------------------------

#
# Table structure for table `ktypes`
#

CREATE TABLE ktypes (
  ktype_id int(10) NOT NULL default '0',
  kpoint float NOT NULL default '0',
  meterpoint float NOT NULL default '0',
  hill int(10) NOT NULL default '0'
) TYPE=MyISAM;

#
# Dumping data for table `ktypes`
#

INSERT INTO ktypes VALUES (1, '118', '1.8', 120);
INSERT INTO ktypes VALUES (2, '83', '2', 90);
# --------------------------------------------------------

#
# Table structure for table `players`
#

CREATE TABLE players (
  player_id int(11) NOT NULL auto_increment,
  surname varchar(30) NOT NULL default '',
  nationality char(2) NOT NULL default '',
  birthdate date NOT NULL default '0000-00-00',
  weight float NOT NULL default '0',
  team_id int(10) NOT NULL default '0',
  height float NOT NULL default '0',
  history varchar(255) NOT NULL default '',
  PRIMARY KEY  (player_id)
) TYPE=MyISAM;

#
# Dumping data for table `players`
#

INSERT INTO players VALUES (1, 'Trung', 'NL', '1981-01-16', '62', 17, '0', 'A dutch veteran that won a lot of medals, a true icon');
INSERT INTO players VALUES (2, 'Marijn', 'BE', '1980-01-01', '75', 2, '0', 'A true belgium guy');
# --------------------------------------------------------

#
# Table structure for table `results`
#

CREATE TABLE results (
  result_id int(10) NOT NULL auto_increment,
  schedule_id int(10) NOT NULL default '0',
  team_id int(10) NOT NULL default '0',
  player_id int(10) NOT NULL default '0',
  speed varchar(10) NOT NULL default '',
  distance float NOT NULL default '0',
  distancepoints float NOT NULL default '0',
  mark1 float NOT NULL default '0',
  mark2 float NOT NULL default '0',
  mark3 float NOT NULL default '0',
  mark4 float NOT NULL default '0',
  mark5 float NOT NULL default '0',
  judgespoints float NOT NULL default '0',
  totalpoints float NOT NULL default '0',
  PRIMARY KEY  (result_id)
) TYPE=MyISAM;

#
# Dumping data for table `results`
#

# --------------------------------------------------------

#
# Table structure for table `rounds`
#

CREATE TABLE rounds (
  round_id int(10) NOT NULL auto_increment,
  name varchar(30) NOT NULL default '',
  startdate datetime NOT NULL default '0000-00-00 00:00:00',
  enddate datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (round_id)
) TYPE=MyISAM;

#
# Dumping data for table `rounds`
#

INSERT INTO rounds VALUES (1, 'Elite Round', '2006-01-16 13:00:00', '2006-01-16 15:00:00');
INSERT INTO rounds VALUES (2, 'SuperRound', '2006-01-20 12:00:00', '2006-01-20 15:00:00');
INSERT INTO rounds VALUES (3, 'UniversityRound', '2006-02-10 12:00:00', '2006-02-10 15:00:00');
INSERT INTO rounds VALUES (4, 'Gandalf Round', '2006-02-15 12:00:00', '2006-02-15 15:00:00');
# --------------------------------------------------------

#
# Table structure for table `schedules`
#

CREATE TABLE schedules (
  schedule_id int(10) NOT NULL auto_increment,
  round_id int(10) NOT NULL default '0',
  player_id int(10) NOT NULL default '0',
  team_id int(10) NOT NULL default '0',
  timestamp datetime default NULL,
  ktype_id int(10) NOT NULL default '0',
  PRIMARY KEY  (schedule_id)
) TYPE=MyISAM;

#
# Dumping data for table `schedules`
#

INSERT INTO schedules VALUES (1, 1, 1, 0, '2004-02-09 12:10:52', 1);
INSERT INTO schedules VALUES (2, 1, 2, 0, '2004-02-09 14:14:24', 1);
# --------------------------------------------------------

#
# Table structure for table `teams`
#

CREATE TABLE teams (
  team_id int(10) NOT NULL auto_increment,
  nationality char(2) NOT NULL default '',
  memberamount int(1) NOT NULL default '0',
  PRIMARY KEY  (team_id)
) TYPE=MyISAM;

#
# Dumping data for table `teams`
#

INSERT INTO teams VALUES (1, 'NL', 1);
INSERT INTO teams VALUES (2, 'BE', 1);
# --------------------------------------------------------

#
# Table structure for table `users`
#

CREATE TABLE users (
  user_id int(10) NOT NULL auto_increment,
  email varchar(40) NOT NULL default '',
  passwd varchar(15) NOT NULL default '',
  company varchar(30) NOT NULL default '',
  role varchar(30) NOT NULL default 'user',
  PRIMARY KEY  (user_id)
) TYPE=MyISAM;

#
# Dumping data for table `users`
#

INSERT INTO users VALUES (1, 'trung@zeelandnet.nl', 'test', 'Leiden University', 'user');
INSERT INTO users VALUES (2, 'mriemens81@hotmail.com', 'test', 'Marijns Riemens BV', 'user');
INSERT INTO users VALUES (3, 'yourmarco@hotmail.com', 'test', 'Wei Zhang Company', 'user');
INSERT INTO users VALUES (4, 'jiameikun@yahoo.com.cn', 'test', 'Jiameikun Company', 'user');
INSERT INTO users VALUES (5, 'carl_suares@yahoo.com', 'test', 'Lalo Company', 'user');
INSERT INTO users VALUES (10, 'judge@hotmail.com', 'test', 'A Judge', 'judge');
INSERT INTO users VALUES (11, 'billgates@cnn.com', 'testtest', 'CNN', 'user');

