#!perl

#If the numbers 1 to 5 are written out in words: one, two, three, four, five,
# then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#
#If all the numbers from 1 to 1000 (one thousand) inclusive were written out
# in words, how many letters would be used?
#
#
#NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
#forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
# letters. The use of "and" when writing out numbers is in compliance with
# British usage.

use strict;
use warnings;

my $len;
foreach (1..1000) {
    print "$_\t";
    my $str = &num2str($_);
    print "$str";
    $str =~ s/\s//g;
    print "\t".length($str)."\n";
    $len += length($str);
}
print $len;

sub num2str {
    my $num = shift;
    my $str = "";
    
    if($num >= 1000) {
        $str = " one thousand";
        $num -= 1000;
    }
    
    if($num >= 100) {
        my @tmp = qw/ dummy one two three four five six seven eight nine /;
        my $tmp_num = int($num / 100);
        $str .= " ".$tmp[$tmp_num]." hundred";
        $num -= $tmp_num * 100;
        $str .= " and" if ($num > 0);
    }
    
    if($num >= 20) {
        my @tmp = qw/ dummy dummy twenty thirty forty fifty sixty seventy eighty ninety /;
        my $tmp_num = int($num / 10);
        $str .= " ".$tmp[$tmp_num];
        $num -= $tmp_num * 10;
    }
    
    if($num >= 10) {
        my @tmp = qw/ ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen /;
        my $tmp_num = $num - 10;
        $str .= " ".$tmp[$tmp_num];
        $num = 0;
    }
    
    if($num > 0) {
        my @tmp = qw/ dummy one two three four five six seven eight nine /;
        $str .= " ".$tmp[$num];
    }
    
    return $str;
}
