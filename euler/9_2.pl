#!perl

my $n = 1000;

my $a=0;
my $b;
while ($a < $n) {
    $a++;
    
    $b = &a_to_b($a);
    if ($b == int($b)) { last; }
}

my $c = &a_to_c($a);
print $a * $b * $c; #=> 31875000

sub a_to_b {
    return ( $n**2 / 2 - $n * $_[0] ) / ( $n - $_[0] );
}

sub a_to_c {
    return sqrt( $a**2 + &a_to_b($_[0])**2 );
}
