<?php
///******** designed by M.Naeem (naeem@email.com) from Pakistan ***************//////

class date_validate
{

function validate($d , $m , $y )
{

$months = array(1=>"January","February" ,"March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December");

if ( (($y % 4) == 0) && ($m == 2) && ($d > 29) )
  $message = "<b><font color=red>Invalid Date:-</b><u> $d $months[$m] , $y </u><br><br> February, $y(Leap Year) has not $d days";

else if ( (($y % 4) > 0) && ($m == 2) && ($d > 28) )
  $message = "<b><font color=red>Invalid Date:-</b><u> $d $months[$m] ,  $y </u>";

else if( (($m == 4) || ($m == 6) || ($m == 9) || ($m == 11) ) && ($d == 31))
  $message = "<b><font color=red>Invalid Date:-</b><u> $d $months[$m] , $y</u> <br><br> '$months[$m]' month has not 31 days";

else
  $message = "<b>Valid Date:-</b><u> $d $months[$m] , $y</u> <br><br> ";

return $message;  
}
 
}
php?>
