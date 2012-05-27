#!perl

use strict;
use warnings;

use constant DEBUG => 0;
use constant DEBUG1 => 1;

my @op;
my @cl;
my %exist;
my @fact = (
    89, 55, 34, 21, 13,  8,
    55, 34, 21, 13,  8,  5,
    34, 21, 13,  8,  5,  3,
    21, 13,  8,  5,  3,  2,
    13,  8,  5,  3,  2,  1,
     8,  5,  3,  2,  1,  0,
#    10, 9, 8, 7, 6, 5,
#     9, 8, 7, 6, 5, 4,
#     8, 7, 6, 5, 4, 3,
#     7, 6, 5, 4, 3, 2,
#     6, 5, 4, 3, 2, 1,
#     5, 4, 3, 2, 1, 0,
);

my $p0 = "===================================0";
push @op, [$p0, ""];

my ($LL, $LX, $RX, $UX, $DX) = split(/\s/, <>);
print "$LL $LX $RX $UX $DX\n";
my $T = <>;

for(my $t = 1; $t <= $T; $t++) {
    my ($w, $h, $b) = split(/,/, <>);
    my $g = &conv($w, $h, $b);
    my $path = &a_star($g);
    
    my $L = (grep {/L/} split //, $path);
    my $R = (grep {/R/} split //, $path);
    my $U = (grep {/U/} split //, $path);
    my $D = (grep {/D/} split //, $path);
    print "\n"
        . " $t: $L $R $U $D $path\n"
        . "----------------------------------------------------------------\n";
}


#======== Founctions

# Local atoi
sub l_atoi {
    my $a = shift;
    my $i = ord($a) - ord('0');
    if(0 <= $i && $i <= 9) { return $i; }
    else                   { return ord($a) - ord('A') + 10; }
}

# Local itoa
sub l_itoa {
    my $i = shift;
    return ($i < 10) ? chr(ord('0') + $i)
         :             chr(ord('A') + $i - 10);
}

# substr(s,i,1)
sub at {
    return substr($_[0],$_[1],1);
}

# Check for panel difference
# O(36)
sub clear {
    my $p = shift;
    my $g = shift;
    for(my $i=0; $i<36; $i++) {
        if(at($g,$i) eq '=' and at($p,$i) ne '='
        or at($g,$i) ne '=' and at($p,$i) ne '='
                            and at($p,$i) ne at($g,$i)
        or at($p,$i) eq '=' and at($g,$i) ne '='
                            and at($g,$i) ne &l_itoa($i+1)){
            return 0;
        }
    }
    return 1;
}

# Convert to equivalent 6*6 panel
# O(36)
sub conv {
    my $w = shift;
    my $h = shift;
    my $a = shift;
    my $b = "====================================";
    for(my $i=0; $i<36; $i++) {
        if(6 <= $h + int($i / 6) and 6 <= $w + $i % 6) {
            substr($b,$i,1)
                = substr($a, (int($i / 6) + $h - 6) * $w
                           + (    $i % 6  + $w - 6),1);
        }
        
        if(at($b,$i) ne '=' and at($b,$i) ne '0') {
            my $n = &l_atoi(at($b,$i)) - 1;
            substr($b,$i,1)
                = &l_itoa((int($n / $w) + 6 - $h) * 6
                        + (    $n % $w  + 6 - $w) + 1);
        }
    }
    return $b;
}

## Manhattan Distance
#sub md {
#    my $p = shift;
#    my $g = shift;
#    my $ret = 0;
#    my %m;
#    for(my $i=0; $i<length($g); $i++) { $m{at($g,$i)} = $i; }
#    for(my $i=0; $i<length($p); $i++) {
##        next if (at($p,$i) eq '0');
##        next if (at($p,$i) eq '=');
##        next if (! exists $m{at($p,$i)});
##        next if (at($g,$m{at($p,$i)}) eq '=');
##        $ret += abs(int($m{at($p,$i)} / 6) - int($i/6));
##        $ret += abs(    $m{at($p,$i)} % 6  -     $i%6 );
#        if(at($p,$i) eq '0') {
#            next;
#        }
#        elsif(at($p,$i) eq '=') {
#            next if (! exists $m{&l_itoa($i)});
#            $ret += abs(int($m{&l_itoa($i)} / 6) - int($i/6));
#            $ret += abs(    $m{&l_itoa($i)} % 6  -     $i%6 );
#        }
#        elsif(exists $m{at($p,$i)}) {
#            next if (at($g,$m{at($p,$i)}) eq '=');
#            $ret += abs(int($m{at($p,$i)} / 6) - int($i/6));
#            $ret += abs(    $m{at($p,$i)} % 6  -     $i%6 );
#        }
#        else {
#            return 999;
#        }
#    }
#    return $ret;
#}

## less than
#sub lt {
#    my $p1 = shift;
#    my $p2 = shift;
#    my $g  = shift;
#    return length($p1->[1]) + &md($p1->[0], $g)
#         < length($p2->[1]) + &md($p1->[1], $g);
#}

# Calc distance map
# O(36^3)
sub calc_dist_map {
    my $g = shift;
    my @dist;
    foreach my $i (0..35) { foreach my $j (0..35) {
        $dist[$i][$j]
        = (at($g,$i) eq '=' or at($g,$j) eq '=')               ? 999
        : ($i == $j)                                           ? 0
        : ((int($i / 6) == int($j / 6)) and abs($i - $j) == 1) ? 1
        : (                                 abs($i - $j) == 6) ? 1
        :                                                        999;
    }}
    foreach my $i (0..35) { foreach my $j (0..35) { foreach my $k (0..35) {
        $dist[$i][$k]
        = ($dist[$i][$k] < $dist[$i][$j] + $dist[$j][$k])
            ? $dist[$i][$k]
            : $dist[$i][$j] + $dist[$j][$k];
        $dist[$k][$i] = $dist[$i][$k];
    }}}
    
    if(DEBUG) {
        foreach my $i (0..35) { 
            print "DEBUG:::\t";
            foreach my $j (0..35) {
                print substr("   ".$dist[$i][$j], -4);
                print " | "if ($j % 6 == 5);
            }
            print "\n"; 
            if ($i % 6 == 5) {print "DEBUG:::         ".("-"x159)."\n";}
        }
        print "\n";
    }
    return @dist;
}

# Calc f'
# O(36)
sub calc_f {
    my $s         = shift;
    my $g         = shift;
    my $dist_ref  = shift;
    my $g_map_ref = shift;
    my $p = $s->[0];
    
    foreach my $i (0..35) {
        if( at($g,$i) eq '=' and at($p,$i) ne '=' ) {
            $s->[2] = 999;
            last;
        }
    }
    
    #$s->[2] = length($s->[1]) + &md($p, $g);
    $s->[2] = length($s->[1]);
    
    #foreach my $i (0..35) { $g_map_ref->{at($g,$i)} = $i; }
    
    foreach my $i (0..35) {
        next if at($p,$i) eq '0';
        next if at($p,$i) eq '=' and at($g,$i) eq '=';
        my $c = (at($p,$i) ne '=') ? &at($p,$i) : &l_itoa($i+1);
        
        if(exists $g_map_ref->{$c}) {
            my $j = $g_map_ref->{$c};
            $s->[2] += $fact[$j] * $dist_ref->[$i][$j];
        }
    }
}

# Push with keeping sorted
sub l_push {
    my $ary_ref = shift;
    my $s       = shift;
    
    foreach my $i (0..@{$ary_ref}-1) {
        if($s->[2] < $ary_ref->[$i]->[2]) {
            splice(@{$ary_ref}, $i, 0, ($s));
            return;
        }
    }
    push @{$ary_ref}, $s;
}

# A* Algorithm
sub a_star {
    my $g = shift;
    
    # make distance map
    # O(36^3)
    my @dist = &calc_dist_map($g);
    
    # make goal charactor map
    my %g_map;
    foreach my $i (0..35) { $g_map{at($g,$i)} = $i; }
    
    # calc f and sort open/close
    # O((Nop + Ncl) * 36)
    calc_f($_,$g,\@dist,\%g_map) foreach(@op);
    calc_f($_,$g,\@dist,\%g_map) foreach(@cl);
    @op = sort {$a->[2] <=> $b->[2]} @op;
    @cl = sort {$a->[2] <=> $b->[2]} @cl;
    
    if(DEBUG) {
        print "---- panel_goal\n";
        print substr($g,$_*6,6)."\n" foreach(0..5);
        print "\n";
    }
    if(DEBUG1) {print "g: $g\n";}
    
    # return if found
    # O((Nop + Ncl) * 36)
    foreach ((@cl, @op)) {
        return $_->[1] if &clear($_->[0], $g);
    }
    
    while(1) {
        
        # error exit if no entry in open.
        die "ERROR: No open status.\n" if(!@op);
        
        # calc f and sort open
        # O(Nop)? -> O(0)
        #@op = sort {$a->[2] <=> $b->[2]} @op;
        
        # get n from open.
        my $n = shift @op;
        
        if(DEBUG) {print "---- n\n";}
        if(DEBUG) {print substr($n->[0],$_*6,6)."\n" foreach(0..5);}
        if(DEBUG) {print "\n";}
        if(DEBUG1) {print "n: ".$n->[0]." (f=".$n->[2].", t=".$n->[1].") / ".scalar(@op)." & ".scalar(@cl)."\n";}
        
        # error exit if n is invalid.
        die "ERROR: Invalid f(n) `".$n->[2]."'.\n" if($n->[2] >= 999);
        
        # solved if n is goal.
        # O(36)
        if(&clear($n->[0], $g)) {
            if(DEBUG) {print "solved.\n\n";}
            #unshift @op, $n;
            &l_push(\@op, $n);
            return $n->[1];
        }
        
        # put n to close.
        #push @cl, $n;
        &l_push(\@cl, $n);
        
        # find '0'
        # O(36)
        my $pos0;
        foreach my $i (0..35) {$pos0 = $i if(at($n->[0],$i) eq '0')}
        if(DEBUG) {print "pos0=$pos0\n\n";}
        
        foreach my $i (0..3) {
            # i=0 : L : swap pos0 <=> pos0+1
            # i=1 : R : swap pos0 <=> pos0-1
            # i=2 : U : swap pos0 <=> pos0+6
            # i=3 : D : swap pos0 <=> pos0-6
            
            next if($i==0 and (    $pos0%6 ==5 or $n->[1] =~ /^R/));
            next if($i==1 and (    $pos0%6 ==0 or $n->[1] =~ /^L/));
            next if($i==2 and (int($pos0/6)==5 or $n->[1] =~ /^D/));
            next if($i==3 and (int($pos0/6)==0 or $n->[1] =~ /^U/));
            
            my $m = [$n->[0], "", 0];
            
            my $j;
            if($i==0) { $j = $pos0+1; }
            if($i==1) { $j = $pos0-1; }
            if($i==2) { $j = $pos0+6; }
            if($i==3) { $j = $pos0-6; }
            substr($m->[0],$pos0,1) = at($m->[0],$j);
            substr($m->[0],$pos0,1) = &l_itoa($j+1) if(at($m->[0],$pos0) eq '=');
            substr($m->[0],$j,1) = '0';
            
            if($i==0) { $m->[1] = "L".$n->[1]; }
            if($i==1) { $m->[1] = "R".$n->[1]; }
            if($i==2) { $m->[1] = "U".$n->[1]; }
            if($i==3) { $m->[1] = "D".$n->[1]; }
            
            # Calc f'
            # O(36)
            &calc_f($m,$g,\@dist,\%g_map);
            
            if(DEBUG) {print "---- m : ".$m->[1]."\n";}
            if(DEBUG) {print substr($m->[0],$_*6,6)."\n" foreach(0..5);}
            if(DEBUG) {print "\n";}
#            if(DEBUG) {print "md(m,g)=".&md($m->[0], $g)."\n";}
            if(DEBUG) {print "f(m)=".$m->[2]."\n\n";}
            
            my $new_p = 1;
            
            # Check for duplication
            # O(1)?
            if($exist{$m->[0]}) {
                my $s = $exist{$m->[0]};
                if($m->[2] < $s->[2]) {
                    
                    # Update other node
                    my $old_t = $s->[1];
                    my $new_t = $m->[1];
                    $_->[1] =~ s/$old_t$/$new_t/ foreach(@op);
                    $_->[1] =~ s/$old_t$/$new_t/ foreach(@cl);
                    
                    # Update this node
                    @op = grep {$_->[0] ne $m->[0]} @op;
                    @cl = grep {$_->[0] ne $m->[0]} @cl;
                    #push @op, $m;
                    &l_push(\@op, $m);
                    
                    if(DEBUG) {print "update m.\n\n";}
                }
                
                $new_p = 0;
                last;
            }
#            # O(Nop + Ncl)
#            foreach my $s ((@op, @cl)) {
#                if($m->[0] eq $s->[0]) {
#                    if($m->[2] < $s->[2]) {
#                        
#                        # Update other node
#                        my $old_t = $s->[1];
#                        my $new_t = $m->[1];
#                        $_->[1] =~ s/$old_t$/$new_t/ foreach(@op);
#                        $_->[1] =~ s/$old_t$/$new_t/ foreach(@cl);
#                        
#                        # Update this node
#                        @op = grep {$_->[0] ne $m->[0]} @op;
#                        @cl = grep {$_->[0] ne $m->[0]} @cl;
#                        #push @op, $m;
#                        &l_push(\@op, $m);
#                        
#                        if(DEBUG) {print "update m.\n\n";}
#                    }
#                    
#                    $new_p = 0;
#                    last;
#                }
#            }
            
            if($new_p) {
                #push @op, $m;
                &l_push(\@op, $m);
                $exist{$m->[0]} = $op[-1];
                if(DEBUG) {print "add new m to open.\n\n";}
            }
        }
    }
}
