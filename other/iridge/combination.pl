#!perl
$n = 15 + 1;

@a;
@{$a[0]}=();
@{$a[1]}=(1);
for($i=2;$i<$n+1;$i++) {
    push @{$a[$i]}, 1;
    for($j=1;$j<$i-1;$j++) {
        push @{$a[$i]}, $a[$i-1]->[$j-1] + $a[$i-1]->[$j];
    }
    push @{$a[$i]}, 1;
}
use Data::Dumper; print Dumper $a[$n];
