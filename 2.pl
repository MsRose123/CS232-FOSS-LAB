print "ENTER NO OF ELEMENTS ";
$n=<STDIN>;
$sum=0;
for($i=0;$i<$n;$i++)
{
   printf "ENTER AN ELEMENT :"; 
   $a[$i]=<STDIN>;
   $sum=$sum+$a[$i];
}
print "SUM = $sum\n";

