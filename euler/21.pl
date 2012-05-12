#!perl
#
#d(n)��n�̐^�̖񐔂̘a�ƒ�`����B�i�^�̖񐔂Ƃ�n�ȊO�̖񐔂̂��Ƃł���B�j
#�����Ad(a) = b ���� d(b) = a �ia �� b�j�𖞂����Ƃ��Aa��b�͗F�����i�e�a���j�ł���Ƃ����B
#
#�Ⴆ�΁A220�̖񐔂�1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110�Ȃ̂�d(220) = 284�ł���B
#�܂��A284�̖񐔂�1, 2, 4, 71, 142�Ȃ̂�d(284) = 220�ł���B
#
#����ł�10000�����̗F�����̍��v�����߂�B
#

use strict;
use warnings;

my $sum;
foreach my $num (2..9999) {
    if(d(d($num)) == $num) {
        $sum += $num;
    }
}
print $sum; #=>40284

sub d {
    my $num = shift;
    my %uniq;
    for(my $j=1; $j<=sqrt($num); $j++) {
        if($num % $j == 0) {
            $uniq{$j}++;
            $uniq{$num / $j}++ if($j != $num / $j and $j != 1);
        }
    }
    my $d;
    $d += $_ foreach (keys %uniq);
    return $d;
}
