#!perl

use strict;
use warnings;

my $i   = 0;
my $num = 0;
while(1) {
    $i++;
    $num += $i;
    
    my $num_of_div = 0;
    for(my $j = 1; $j*$j <= $num; $j++) {
        if ($num % $j == 0) {
            if ($num == $j * $j) {
                $num_of_div++;
            }
            else {
                $num_of_div += 2;
            }
        }
    }
    
    last if $num_of_div >= 500;
}

print $num; #=> 76576500
