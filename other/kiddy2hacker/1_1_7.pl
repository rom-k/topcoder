#!/usr/bin/perl

use strict;
use warnings;

while(<DATA>) {
    my @a;
    foreach my $c (split //) {
        last if $c eq "\n";
        $c = ord $c;
        push @a, $c;
    }

#    @a = sort {$a <=> $b} @a;

    foreach my $c (@a) {
        print sprintf("  %02x",$c);
    }
    print "\n";

    print "# ";
    my $prev;
    foreach my $c (@a) {
        if (defined $prev) {
            if ($prev<=$c) {
                print sprintf("  %02x",$c-$prev);
            }
            else {
                print sprintf(" (%02x",128+$c-$prev);
            }
        }
        $prev = $c;
    }
    print "\n";
}

__DATA__
w&G4kP%jC
9JM>u*1HQ
+Bir3Zs8#
A@=f[Lut5
E8Kp?2{ny
