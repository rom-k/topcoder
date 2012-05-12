#!perl
$|=1;

my @factorial = qw/
    1
    1
    2
    6
    24
    120
    720
    5040
    40320
    362880
/;

my $end = 10_000_000; # 7*9! < 10^7
my $sum = 0;
for(my $i = 3; $i < $end; $i++) {
    my $b = 0;
    $b += $factorial[$_] foreach split //, $i;
    if($i == $b) {
        print "$i\n";
        $sum += $i
    }
}
print "sum=$sum\n";
