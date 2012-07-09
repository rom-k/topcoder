#!perl

use strict;
use warnings;

while(<DATA>) {
    my @c = split //, $_;
    my $i = ord($c[0])-ord($c[1]);
    $i += 26 if ($i<0);
    my $i2 = ord($c[1])-ord($c[2]);
    $i2 += 26 if ($i2<0);
    my $w0;
    if    ($i==23 and $i2==8) { $w0 = 't'; } #-3
    elsif ($i==12) { $w0 = 't'; }
    elsif ($i==17) { $w0 = 'f'; } #-9
    elsif ($i==23) { $w0 = 'f'; } #-3
    elsif ($i==10) { $w0 = 's'; }
    elsif ($i==14) { $w0 = 's'; }
    elsif ($i==22) { $w0 = 'e'; } #-4
    elsif ($i== 5) { $w0 = 'n'; }
    else           { exit -1;   }
    my $d = ord($w0)-ord($c[0]);
    $d += 26 if ($d<26);
    $d -= 26 if (26<$d);
    foreach (@c) {
        if (/\w/) {
            my $k = ord($_)+$d;
            $k -= 26 if (ord('z')<$k);
            $_ = chr($k);
        }
        print;
    }
}

__DATA__
cfx cqxdbjwm, brg qdwmanm jwm wrwnch-wrwn
escpp eszfdlyo, ytyp sfyocpo lyo estcej-dti
ild iwdjhpcs, cxct wjcsgts pcs hxmittc
kfkb qelrpxka, pbsbk erkaoba xka cfcqv-clro
sbhe gubhfnaq, avar uhaqerq naq svsgl-sbhe
adqz ocjpnviy, nds cpiymzy viy orj
qtgp eszfdlyo, qzfc sfyocpo lyo ptrsej-ytyp
