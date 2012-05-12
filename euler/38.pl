#!perl

my $ret = 0;
foreach my $i (1..int(98764/2)) {
    next if $i !~ /^9/;
    
    my $flag = 0;
    my $j = 1;
    my $p = "";
    my %hash;
    while (scalar keys %hash < 9) {
        foreach (split //, ($i * $j)) {
            $p .= "$_";
            if ($_ == 0 or 1 < ++$hash{$_}) {
                $flag = 1;
                last;
            }
        }
        last if $flag;
        $j++;
    }
    
    if(!$flag and scalar keys %hash == 9) {
        $ret = ($ret < $p) ? $p : $ret;
    }
}
print "$ret\n"; #=>932718654
