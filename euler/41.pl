#!perl
$|=1;

# n��Pandigital�ł���Ƃ�, 1����n�܂ł̐����e����1�������ƂƂ���.
# #���̃����N��ɂ���悤�Ȑ��w�I��`�Ƃ͈قȂ�
# �Ⴆ��2143��4��Pandigital���ł���, ���f���ł���. 
# n���i���̖��̒�`�ł�9���ȉ��jPandigital�ȑf���̒��ōő�̐��𓚂���.

my %sieve2 = &is_prime4();

#print is_prime(10_000_000);

#my $a = 1;
#while($a++ < 10_000_000) {
#    
#    
#    
#}

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
    %sieve = map {$_=>1} 0..$n+1;
    
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

# make sieve
sub is_prime3 {
}
__DATA__
