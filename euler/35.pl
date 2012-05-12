#!perl

my %sieve = &is_prime3(1_000_000);
my $keta = 1;
my $num;
foreach my $i (2..1_000_000) {
    $keta++ if 10**$keta <= $i;
    
    my $i2 = $i;
    my $flag = 1;
    foreach my $j (1..$keta) {
        my $a = $i2 % 10;
        $i2 /=10;
        $i2 = int($i2);
        $i2 += $a * 10**($keta-1);
        
        $flag = 0 if $a == 0 or not $sieve{$i2};
    }
    
    $num++ if $flag;
}
print $num; #=>55

# is_prime
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

# keep in array
my @_primes;
sub is_prime2 {
    $num = shift;
    foreach (sort {$a<=>$b} @_primes) {
        last if $num <= $_;
        return 0 if $num % $_ == 0;
    }
    push @_primes, $num;
    return 1;
}

# make sieve
sub is_prime3 {
    my $n = shift;
    my %sieve;
    $sieve{$_} = 1 foreach (0..$n+1);
    
    $sieve{0} = 0;
    $sieve{1} = 0;
    
    my $m = int sqrt $n;
    for(my $i=2; $i<=$m; $i++) {
        if ($sieve{$i}) {
            for(my $k=$i*$i; $k<=$n; $k+=$i) {
                $sieve{$k} = 0;
            }
        }
    }
    
    return %sieve;
}
