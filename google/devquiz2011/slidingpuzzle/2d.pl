#!perl

use strict;
use warnings;

use constant DEBUG => 0;
use constant DEBUG1 => 0;

my @op;
my @cl;

push @op, ["===================================0", ""];

my ($LL, $LX, $RX, $UX, $DX) = split(/\s/, <>);
print "$LL $LX $RX $UX $DX\n";
my $T = <>;

for(my $t = 1; $t <= $T; $t++) {
    my ($w, $h, $b) = split(/,/, <>);
    my $panel_goal = &conv($w, $h, $b);
    my $path = &a_star($panel_goal);
    
    my $L = (grep {/L/} split //, $path);
    my $R = (grep {/R/} split //, $path);
    my $U = (grep {/U/} split //, $path);
    my $D = (grep {/D/} split //, $path);
    print "\n"
        . " $t: $L $R $U $D $path\n"
        . "----------------------------------------------------------------\n";
}

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

# Convert to equivalent 6*6 panel
sub conv {
    my $w = shift;
    my $h = shift;
    my $a = shift;
    my $b = "====================================";
    for(my $i=0; $i<36; $i++) {
        if(6 <= $h + int($i / 6) and 6 <= $w + $i % 6) {
            substr($b, $i, 1)
                = substr($a, (int($i / 6) + $h - 6) * $w
                           + (    $i % 6  + $w - 6), 1);
        }
        
        if(substr($b, $i, 1) ne '=' and substr($b, $i, 1) ne '0') {
            my $n = &l_atoi(substr($b, $i, 1)) - 1;
            substr($b, $i, 1)
                = &l_itoa((int($n / $w) + 6 - $h) * 6
                        + (    $n % $w  + 6 - $w) + 1);
        }
    }
    return $b;
}

# Check for valid mask
sub valid {
    my $p = shift;
    my $g = shift;
    for(my $i=0; $i<36; $i++) {
        if(substr($g,$i,1) eq '=' and substr($p,$i,1) ne '=') {return 0;}
    }
    return 1;
}

# Check for panel difference
sub same {
    my $p = shift;
    my $g = shift;
    for(my $i=0; $i<36; $i++) {
#        if(substr($p,$i,1) ne '=' and substr($p,$i,1) ne substr($g,$i,1)
#        or substr($p,$i,1) eq '=' and substr($p,$i,1) ne &l_itoa($i+1)){
#            return 0;
#        }
        if(substr($g,$i,1) eq '=' and substr($p,$i,1) ne '='
        or substr($g,$i,1) ne '=' and substr($p,$i,1) ne '='
                                  and substr($p,$i,1) ne substr($g,$i,1)
        or substr($p,$i,1) eq '=' and substr($g,$i,1) ne '='
                                  and substr($g,$i,1) ne &l_itoa($i+1)){
            return 0;
        }
    }
    return 1;
}

# Manhattan Distance
sub md {
    my $p = shift;
    my $g = shift;
    my $ret = 0;
    my %m;
    for(my $i=0; $i<length($g); $i++) { $m{substr($g, $i, 1)} = $i; }
    for(my $i=0; $i<length($p); $i++) {
#        next if (substr($p, $i, 1) eq '0');
#        next if (substr($p, $i, 1) eq '=');
#        next if (! exists $m{substr($p, $i, 1)});
#        next if (substr($g, $m{substr($p, $i, 1)}, 1) eq '=');
#        $ret += abs(int($m{substr($p, $i, 1)} / 6) - int($i/6));
#        $ret += abs(    $m{substr($p, $i, 1)} % 6  -     $i%6 );
        if(substr($p, $i, 1) eq '0') {
            next;
        }
        elsif(substr($p, $i, 1) eq '=') {
            next if (! exists $m{&l_itoa($i)});
            $ret += abs(int($m{&l_itoa($i)} / 6) - int($i/6));
            $ret += abs(    $m{&l_itoa($i)} % 6  -     $i%6 );
        }
        elsif(exists $m{substr($p, $i, 1)}) {
            next if (substr($g, $m{substr($p, $i, 1)}, 1) eq '=');
            $ret += abs(int($m{substr($p, $i, 1)} / 6) - int($i/6));
            $ret += abs(    $m{substr($p, $i, 1)} % 6  -     $i%6 );
        }
        else {
            return 999;
        }
    }
    return $ret;
}

# less than
sub lt {
    my $p1 = shift;
    my $p2 = shift;
    my $g  = shift;
    return length($p1->[1]) + &md($p1->[0], $g)
         < length($p2->[1]) + &md($p1->[1], $g);
}

# A* Algorithm
sub a_star {
    my $panel_goal = shift;
    
    if(DEBUG1) {print "---- panel_goal\n";}
    if(DEBUG1) {print substr($panel_goal, $_*6, 6)."\n" foreach(0..5);}
    if(DEBUG1) {print "\n";}
    
    # calc f and sort open/close
    $_->[2] = length($_->[1]) + &md($_->[0], $panel_goal) foreach(@op);
    $_->[2] = length($_->[1]) + &md($_->[0], $panel_goal) foreach(@cl);
    @op = sort {$a->[2] <=> $b->[2]} @op;
    @cl = sort {$a->[2] <=> $b->[2]} @cl;
    
    # return if found
    foreach ((@cl, @op)) {
        return $_->[1] if(&same($_->[0], $panel_goal));
    }
    
    my $ret;
    while(1) {
        if(!@op) {
            if(DEBUG) {print "error.\n\n";}
            next;
        }
        
        # calc f and sort open
        foreach my $s (@op) {
            $s->[2] = length($s->[1]) + &md($s->[0], $panel_goal);
        }
        @op = sort {$a->[2] <=> $b->[2]} @op;
        
        # remove n from open and insert to close
        my $n;
        foreach my $s (@op) {
            if(&valid($s->[0], $panel_goal)) {
                @{$n} = @{$s};
                @op = grep {$_ ne $s} @op;
                last;
            }
        }
        push @cl, $n;
        
        if(DEBUG1) {print "---- n\n";}
        if(DEBUG1) {print substr($n->[0], $_*6, 6)."\n" foreach(0..5);}
        if(DEBUG1) {print "\n";}
        
        # solved if n is goal.
        if(&same($n->[0], $panel_goal)) {
            if(DEBUG) {print "cleared.\n\n";}
            push @op, $n;
            $ret = $n->[1];
            last;
        }
        
        # find '0'
        my $pos0;
        foreach my $i (0..35) {$pos0 = $i if(substr($n->[0], $i, 1) eq '0')}
        if(DEBUG) {print "pos0=$pos0\n\n";}
        
        foreach my $i (0..3) {
            # i=0 : L : swap pos0 <=> pos0+1
            # i=1 : R : swap pos0 <=> pos0-1
            # i=2 : U : swap pos0 <=> pos0+6
            # i=3 : D : swap pos0 <=> pos0-6
            
            next if($i==0 and     $pos0%6 ==5);
            next if($i==1 and     $pos0%6 ==0);
            next if($i==2 and int($pos0/6)==5);
            next if($i==3 and int($pos0/6)==0);
            
            my $p = $n->[0];
            my $t;
            
            if($i==0) { substr($p,$pos0,1) = (substr($p,$pos0+1,1)ne'=') ? substr($p,$pos0+1,1) : &l_itoa($pos0+1+1) ; substr($p,$pos0+1,1) = '0'; $t = "L"; }
            if($i==1) { substr($p,$pos0,1) = (substr($p,$pos0-1,1)ne'=') ? substr($p,$pos0-1,1) : &l_itoa($pos0-1+1) ; substr($p,$pos0-1,1) = '0'; $t = "R"; }
            if($i==2) { substr($p,$pos0,1) = (substr($p,$pos0+6,1)ne'=') ? substr($p,$pos0+6,1) : &l_itoa($pos0+6+1) ; substr($p,$pos0+6,1) = '0'; $t = "U"; }
            if($i==3) { substr($p,$pos0,1) = (substr($p,$pos0-6,1)ne'=') ? substr($p,$pos0-6,1) : &l_itoa($pos0-6+1) ; substr($p,$pos0-6,1) = '0'; $t = "D"; }
            
            $t .= $n->[1];
            my $m = [$p, $t];
            $m->[2] = length($m->[1]) + &md($m->[0], $panel_goal);
            
            if(DEBUG) {print "---- m : $t\n";}
            if(DEBUG) {print substr($m->[0], $_*6, 6)."\n" foreach(0..5);}
            if(DEBUG) {print "\n";}
            
            my $new_p = 1;
            my $old_t = "";
            
            foreach my $s (@op) {
                my $match = 1;
                foreach my $j (0..35) {
                    if(substr($p,$j,1) ne substr($s->[0],$j,1)) {
                        $match = 0;
                        last;
                    }
                }
                if($match) {
                    if($m->[2] < $s->[2]) {
                        $old_t = $s->[1];
                        @op = grep {$_ ne $s} @op;
                    }
                    
                    $new_p = 0;
                    last;
                }
            }
            
            foreach my $s (@cl) {
                my $match = 1;
                foreach my $j (0..35) {
                    if(substr($p,$j,1) ne substr($s->[0],$j,1)) {
                        $match = 0;
                        last;
                    }
                }
                if($match) {
                    if($m->[2] < $s->[2]) {
                        $old_t = $s->[1];
                        @cl = grep {$_ ne $s} @op;
                    }
                    
                    $new_p = 0;
                    last;
                }
            }
            
            if(DEBUG) {print "new_p=$new_p\n";}
            if(DEBUG) {print "old_t=$old_t\n";}
            if(DEBUG) {print "md(m,g)=".&md($m->[0], $panel_goal)."\n\n";}
            
            if($new_p) {
                push @op, $m;
                if(DEBUG) {print "add new m to open.\n\n";}
            }
            
            if(! $new_p and $old_t ne "") {
                push @op, $m;
                if(DEBUG) {print "update m.\n\n";}
                
                foreach my $s (@op) {
                    $s->[1] =~ s/$old_t$/$t/;
                }
                
                foreach my $s (@cl) {
                    $s->[1] =~ s/$old_t$/$t/;
                }
            }
        }
    }
    
    return $ret;
}
