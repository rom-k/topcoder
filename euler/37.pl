#!perl

my @left  = ("2","3","5","7");
my @right = ("2","3","5","7");
my $ret;
my $keta = 1;
$|=1;

while (@left and @right and ++$keta <= 6) {
    my %sieve = &is_prime3(10**$keta);
    
    my @tmp = @left; @left = ();
    foreach my $i (@tmp) {
        foreach my $j (0..9) {
            #if (&is_prime("$i$j")) {
            if ($sieve{"$i$j"}) {
                push @left, "$i$j";
                #print "l: $i$j\n";
            }
        }
    }
    @tmp = @right; @right = ();
    foreach my $i (@tmp) {
        foreach my $j (0..9) {
            #if (&is_prime("$j$i")) {
            if ($sieve{"$j$i"}) {
                push @right, "$j$i";
                #print "r: $j$i\n";
            }
        }
    }
    
    my %hash = map {$_=>1} @left;
    foreach (@right) {
        #print "$_\n" if exists $hash{$_};
        $ret += $_ if exists $hash{$_};
    }
}

print "$ret\n"; #=>748317

## is_prime
#sub is_prime {
#    $num = shift;
#    $n   = 2;
#    while(1) {
#        last if $n >= $num;
#        return 0 if $num % $n == 0;
#        $n++;
#    }
#    return 1;
#}

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



#$|=1;
#my $count;
#my $sum;
#my $i = 1;
#while($i++) {
#    
#    my $ok = 1;
#    my $len = length($i);
#    
#    next if !is_prime2($i);
##    print "i=$i is prime.\n";
#    
#    foreach (1..$len-1) {
#        if (!is_prime2(substr($i, $_   ))) {
#            $ok = 0;
#            last;
#        }
#        if (!is_prime2(substr($i, 0, $_))) {
#            $ok = 0;
#            last;
#        }
#    }
##    print " ok=$ok\n";
#    
#    if($ok and 10 < $i) {
#        print "$i\n";
#        $sum += $i;
#        last if (11 <= ++$count);
#    }
#}
#print $sum; #=>?
#
## keep in array
#my @_primes;
#sub is_prime2 {
#    $num = shift;
#    return 0 if $num == 1;
#    foreach (sort {$a<=>$b} @_primes) {
#        last if $num <= $_;
#        return 0 if $num % $_ == 0;
#    }
#    push @_primes, $num;
#    return 1;
#}
