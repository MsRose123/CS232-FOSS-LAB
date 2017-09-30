#FACTORIAL OF A NUMBER
print "ENTER A NUMBER :\n";
$n=<STDIN>;
$num=$n;
$f=1;
if($num==0)
{
  print "FACTORIAL = 1\n";
}
else
{ 
  while($num>0)
  {
    $f=$f*$num;
    $num--;
  }
}
print "FACTORIAL OF $n= $f\n";
