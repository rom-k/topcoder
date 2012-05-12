#!perl

$num = 2;
$cnt_of_primes = 0;
$tgt_cnt_of_primes = 10001;

while(1) {
    $cnt_of_primes++ if &is_prime2($num);
    last if $cnt_of_primes == $tgt_cnt_of_primes;
    $num++;
}
print $num; #=> 104743

sub is_prime {
    $num = shift;
    $n   = 2;
    while(1) {
        last if $n >= $num;
        return 0 if $num % $n == 0;
        $n++;
    }
    return 1;
}

@primes = ();
sub is_prime2 {
    $num = shift;
    foreach (@primes) {
        return 0 if $num % $_ == 0;
    }
    push @primes, $num;
    return 1;
}
