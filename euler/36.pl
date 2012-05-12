#!perl
my $sum;
$sum += $_ foreach(
    grep {
        $i = sprintf("%b", $_); $i eq reverse $i
    } grep {
        $_ eq reverse $_
    } (1..1000000)
);
print $sum; #=>872187
