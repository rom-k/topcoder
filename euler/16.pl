use Math::BigInt;
$i = Math::BigInt->new("1");
$i *= 2 foreach 1..1000;
$j += $_ foreach split //, $i;
print $j;
