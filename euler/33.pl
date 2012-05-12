#!perl

sub _gcd2 {
    my $a = shift;
    my $b = shift;
    if ($a < $b) { my $c = $a; $a = $b; $b = $c; }
    return $a if $b == 0;
    return _gcd2($b, $a % $b);
}

sub _lcm2 {
    my $a = shift;
    my $b = shift;
    return $b * $a / _gcd2($a, $b);
}

#my $prod = 1;
my $prod1 = 1;
my $prod2 = 1;

foreach my $a (1..9) {
    foreach my $b (0..9) {
        foreach my $c (1..9) {
            foreach my $d (0..9) {
                
                next if $b == 0 and $d == 0;
                my $A = 10 * $a + $b;
                my $C = 10 * $c + $d;
                
                if (
                    $A < $C
                and (
                    $a == $c and $A * $d == $C * $b
                or  $a == $d and $A * $c == $C * $b
                or  $b == $c and $A * $d == $C * $a
                or  $b == $d and $A * $c == $C * $a
                ) ) {
                    print "$A / $C\n";
                    
#                    my $gcd = _gcd2($A, $C);
#                    $prod *= $C / $gcd;
                    
                    $prod1 *= $A;
                    $prod2 *= $C;
                }
            }
        }
    }
}

#print "$prod\n";

my $gcd = _gcd2($prod1, $prod2);
print ($prod2 / $gcd) . "\n"; #=>100
