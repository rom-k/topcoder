$a+=$_ foreach( grep{$_%3==0 or $_%5==0} (1..999) );
print $a; #=> 233168
