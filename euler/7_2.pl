#!perl

$n = 10001;

#�͋Z
my $cnt = 0;
my $num = 1;
while ($cnt != $n) {
    $num++;
    my $square_root = (int sqrt $num) + 1;
    foreach (2..$square_root) {
        if ( $_ == $square_root ){ $cnt++ }
        if ( $num % $_ == 0     ){ last   };
    }
}
print $num; #=>104743
