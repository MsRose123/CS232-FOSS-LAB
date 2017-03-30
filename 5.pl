#LINEAR SEARCH
print "ENTER TOTAL NUM OF ELEMENTS :\n";
$n=<STDIN>;
for($i=0;$i<$n;$i++)
{
  print "ENTER AN ELEMENT :\n";
  $ar[$i]=<STDIN>;
}
print "ENTER ELEMENT TO BE SEARCHED :\n";
$item=<STDIN>;
$flag=0;
for($i=0;$i<$n;$i++)
{
  if($ar[$i]==$item)
  {
    $flag=1;
    $pos=$i;
    last;
  }
}
if($flag==1)
{
 chomp($item);
 print "SUCCESFUL SEARCH\nLOCATION OF $item WITH RESPECT TO ARRAY IS $pos\n";
}
else
{
 print "UNSUCCESFUL SEARCH\n";
}   
