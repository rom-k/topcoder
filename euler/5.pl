#!perl

use strict;
use warnings;

print &_lcm(2..20);

sub _gcd2 {
    my $a = shift;
    my $b = shift;
    if ($a < $b) { my $c = $a; $a = $b; $b = $c; }
    if ($b == 0) { return $a; }
    return _gcd2($b, $a % $b);
}

sub _gcd {
    my @a = @_;
    my $ret = $a[0];
    for(my $i=1; $i<@a; $i++) {
        $ret = _gcd2($ret, $a[$i]);
    }
    return $ret;
}

sub _lcm2 {
    my $a = shift;
    my $b = shift;
    return $b * $a / _gcd2($a, $b);
}

sub _lcm {
    my @a = @_;
    my $ret = $a[0];
    for(my $i=1; $i<@a; $i++) {
        $ret = _lcm2($ret, $a[$i]);
    }
    return $ret;
}

#$num = 1;
#foreach $i (2..20) {
#    if (_is_prime($i)) {
#        $num *= $i;
#        print "$i => $num\n";
#    }
#}
#print $num; #=> 210 => Å~
#
#sub _is_prime {
#    my $num = shift;
#    foreach my $i (2..$num-1) {
#        return 0 if $num % $i == 0;
#    }
#    return 1;
#}
