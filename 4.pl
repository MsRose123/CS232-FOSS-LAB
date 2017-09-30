#LARGEST OF 3 NUMBERS
print "ENTER 3 NUMBERS :\n";
$a=<STDIN>;
$b=<STDIN>;
$c=<STDIN>;
if($a>$b && $a>$c)
{ 
 chomp($a);
 print "$a IS LARGEST \n";
}
elsif($b>$c && $b>$c)
{
 chomp($b);
 print "$b IS LARGEST\n";
}
else
{
 chomp($c);
 print "$c IS LARGEST\n";
}

