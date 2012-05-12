#!perl
#
#d(n)をnの真の約数の和と定義する。（真の約数とはn以外の約数のことである。）
#もし、d(a) = b かつ d(b) = a （a ≠ b）を満たすとき、aとbは友愛数（親和数）であるという。
#
#例えば、220の約数は1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110なのでd(220) = 284である。
#また、284の約数は1, 2, 4, 71, 142なのでd(284) = 220である。
#
#それでは10000未満の友愛数の合計を求めよ。
#

use strict;
use warnings;

my $sum;
foreach my $num (2..9999) {
    if(d(d($num)) == $num) {
        $sum += $num;
    }
}
print $sum; #=>40284

sub d {
    my $num = shift;
    my %uniq;
    for(my $j=1; $j<=sqrt($num); $j++) {
        if($num % $j == 0) {
            $uniq{$j}++;
            $uniq{$num / $j}++ if($j != $num / $j and $j != 1);
        }
    }
    my $d;
    $d += $_ foreach (keys %uniq);
    return $d;
}
