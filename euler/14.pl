#!perl

use strict;
use warnings;
use List::Util qw(max);

my $max      = 0;
my $max_step = 0;
foreach (1..1000000) {
    my $num = $_;
    if ($num % 2 != 0 and ($num * 3 + 1) > 1000000 and (($num * 3 + 1) / 2) % 2 != 0) {
        my $step = steps($num);
        if($max_step < $step) {
            $max = $num;
            $max_step = $step;
        }
    }
}
print $max;

sub steps {
    my $num  = shift;
    my $step = 0;
    while ($num != 1) {
        if ($num % 2 == 0) { $num = $num / 2     }
        else               { $num = $num * 3 + 1 }
        $step++;
    }
    return $step;
}

#use strict;
#use warnings;
#use List::Util qw(max);
#
#my %step = qw/ 0 0 1 0 /;
#my @stack = qw/ 1 /;
#my $maxstep = 0;
#
#while(@stack) {
#    my $num = shift @stack;
#    
#    $maxstep = max($maxstep, $step{$num});
#    
#    my @tmp;
#    push @tmp, (2 * $num);
#    push @tmp, (($num-1) % 3 == 0) ? (($num-1) / 3) : ();
#    
#    foreach (@tmp) {
#        if (!exists $step{$_} and $_ <= 1000000) {
#            $step{$_} = $step{$num}+1;
#            push @stack, $_;
#        }
#    }
#    
#    @stack = sort {$step{$a}<=>$step{$b}} @stack;
#    
#    #print "$num ($maxstep) ".join(",",@stack)."\n";
#}
#print $maxstep; #=> TLE
