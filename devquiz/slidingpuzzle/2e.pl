#!perl

use strict;
use warnings;

use constant DEBUG => 0;
use constant DEBUG1 => 1;

my @op;
my @cl;

push @op, ["===================================0", ""];

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

# Manhattan Distance
sub md {
    my $p = shift;
    my $g = shift;
    my $ret = 0;
    my %m;
    for(my $i=0; $i<length($g); $i++) { $m{at($g,$i)} = $i; }
    for(my $i=0; $i<length($p); $i++) {
#        next if (at($p,$i) eq '0');
#        next if (at($p,$i) eq '=');
#        next if (! exists $m{at($p,$i)});
#        next if (at($g,$m{at($p,$i)}) eq '=');
#        $ret += abs(int($m{at($p,$i)} / 6) - int($i/6));
#        $ret += abs(    $m{at($p,$i)} % 6  -     $i%6 );
        if(at($p,$i) eq '0') {
            next;
        }
        elsif(at($p,$i) eq '=') {
            next if (! exists $m{&l_itoa($i)});
            $ret += abs(int($m{&l_itoa($i)} / 6) - int($i/6));
            $ret += abs(    $m{&l_itoa($i)} % 6  -     $i%6 );
        }
        elsif(exists $m{at($p,$i)}) {
            next if (at($g,$m{at($p,$i)}) eq '=');
            $ret += abs(int($m{at($p,$i)} / 6) - int($i/6));
            $ret += abs(    $m{at($p,$i)} % 6  -     $i%6 );
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

# Calc f'
sub calc_f {
    my $p = shift;
    my $g = shift;
    $p->[2] = length($p->[1]) + &md($p->[0], $g);
    foreach my $i (0..35) {
        if( at($g,$i) eq '=' and at($p->[0],$i) ne '=' ) {
            $p->[2] = 999;
            last;
        }
    }
}

# A* Algorithm
sub a_star {
    my $g = shift;
    
    if(DEBUG) {
        print "---- panel_goal\n";
        print substr($g,$_*6,6)."\n" foreach(0..5);
        print "\n";
    }
    if(DEBUG1) {print "g: $g\n";}
    
    # calc f and sort open/close
    calc_f($_,$g) foreach(@op);
    calc_f($_,$g) foreach(@cl);
    @op = sort {$a->[2] <=> $b->[2]} @op;
    @cl = sort {$a->[2] <=> $b->[2]} @cl;
    
    # return if found
    foreach ((@cl, @op)) {
        return $_->[1] if &clear($_->[0], $g);
    }
    
    while(1) {
        
        # error exit if no entry in open.
        die "ERROR: No open status.\n" if(!@op);
        
        # calc f and sort open
        #calc_f($_,$g) foreach(@op);
        @op = sort {$a->[2] <=> $b->[2]} @op;
        
        # get n from open.
        my $n = shift @op;
        
        if(DEBUG) {print "---- n\n";}
        if(DEBUG) {print substr($n->[0],$_*6,6)."\n" foreach(0..5);}
        if(DEBUG) {print "\n";}
        if(DEBUG1) {print "n: ".$n->[0]." (f=".$n->[2].", t=".$n->[1].")\n";}
        
        # error exit if n is invalid.
        die "ERROR: Invalid f(n) `".$n->[2]."'.\n" if($n->[2] >= 999);
        
        # solved if n is goal.
        if(&clear($n->[0], $g)) {
            if(DEBUG) {print "solved.\n\n";}
            push @op, $n;
            return $n->[1];
        }
        
        # put n to close.
        push @cl, $n;
        
        # find '0'
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
            
            calc_f($m,$g);
            
            if(DEBUG) {print "---- m : ".$m->[1]."\n";}
            if(DEBUG) {print substr($m->[0],$_*6,6)."\n" foreach(0..5);}
            if(DEBUG) {print "\n";}
            if(DEBUG) {print "md(m,g)=".&md($m->[0], $g)."\n";}
            if(DEBUG) {print "f(m)=".$m->[2]."\n\n";}
            
            my $new_p = 1;
            
            # Check for duplication
            foreach my $s ((@op, @cl)) {
                if($m->[0] eq $s->[0]) {
                    if($m->[2] < $s->[2]) {
                        
                        # Update other node
                        my $old_t = $s->[1];
                        my $new_t = $m->[1];
                        $_->[1] =~ s/$old_t$/$new_t/ foreach(@op);
                        $_->[1] =~ s/$old_t$/$new_t/ foreach(@cl);
                        
                        # Update this node
                        @op = grep {$_->[0] ne $m->[0]} @op;
                        @cl = grep {$_->[0] ne $m->[0]} @cl;
                        push @op, $m;
                        
                        if(DEBUG) {print "update m.\n\n";}
                    }
                    
                    $new_p = 0;
                    last;
                }
            }
            
            if($new_p) {
                push @op, $m;
                if(DEBUG) {print "add new m to open.\n\n";}
            }
        }
    }
}
