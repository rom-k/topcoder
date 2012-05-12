#!perl

$n = 100;

#—Í‹Z
$a = &sum(map {&square($_)} 1..$n);
$b = &square(&sum(1..$n));
print $b - $a; #=> 25164150

sub sum {
    my $ret;
    $ret += $_ foreach (@_);
    return $ret;
}

sub square {
    return $_[0] ** 2;
}
