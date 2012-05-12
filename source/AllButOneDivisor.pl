
#@a=<>; @b=sort {$a<=>$b} grep {$i = $_;(grep {$i % $_} @a)==1} 1..30000; print $b[0];

#@a=<>;print((sort{$a<=>$b}grep{$i=$_;(grep{$i%$_}@a)==1}1..9**5)[0])

#@a=<>;print(((grep{$i=$_;(grep{$i%$_}@a)==1}1..8**5),-1)[0])

#@a=<>;print+((grep{$i=$_;(grep{$i%$_}@a)==1}1..3E4),-1)[0]

#@a=<>;die+((grep{$b=$_;(grep{$b%$_}@a)==1}1..3E4),-1)[0]
#@a=<>;print+((grep{$b=$_;(grep{$b%$_}@a)==1}1..3E4),-1)[0]

##!perl -lpa
#((grep{$i=$_;(grep{$i%$_}@F)==1}1..3E4),-1)[0]
# “®‚©‚È‚¢

#@a=<>;for(1..3E4){$i=$_;die$i,if(grep{$i%$_}@a)==1}die-1

#@a=<>;($i=$_)&&(grep{$i%$_}@a)==1?die$_:0for+1..3E4;die-1

#@a=<>;(grep{$i%$_}@a)==1?die$i:$i++for+1..3E4;die-1

#@a=<>;(grep{$i%$_}@a)==1?die$i:$i++for+1..3E4;die-1

#@a=<>;(grep{$i%$_}@a)==1?die$i:$i++for+1..3E4;die-1
#@a=<>;(grep{$i%$_}@a)==1?print$i:$i++for+1..3E4;print-1

#@a=<>;(grep{$i%$_}@a)==1?last:$i++for+1..3E4;die$i<3E4?$i:-1


#@a=<>;(grep{$i%$_}@a)==1?die$i:$i++for+1..3E4;die-1
#@a=<>;(grep{$i%$_}@a)==1?print$i:$i++for+1..3E4;print-1
#@a=<>;die+((grep{$b=$_;(grep{$b%$_}@a)==1}1..3E4),-1)[0]
#@a=<>;print+((grep{$b=$_;(grep{$b%$_}@a)==1}1..3E4),-1)[0]

#@a=<>;(grep{$i%$_}@a)==1?die$i:0until($i++>3E4);die-1

#@a=<>;(grep{$i%$_}@a)==1?die$i:$i++for+1..3E4;die-1

#@a=<>;(grep{$i%$_}@a)-1?$i++:die$i,for+1..3E4;die-1


#@a=<>;(grep{$i%$_}@a)-1?$i++:die$i for 1..3E4;die-1
#@a=<>;print+((grep{$b=$_;(grep{$b%$_}@a)==1}1..3E4),-1)[0]

@a=<>;(grep{$i%$_}@a)-1?$i++:exit print$i for 1..3E4;print-1



#sub _gcd {
#    ($a, $b) = @_;
#    $b ? _gcd($b, $a % $b) : $a;
#}
#
#sub _lcm {
#    ($a, $b) = @_;
#    ($a, $b) = ($b, $a) if $a < $b;
#    $a * $b / _gcd($a, $b);
#}
#
#@a = <>;
#
#for ($i=0; $i<@a; $i++) {
#    
#    $r = 1;
#    
#    for ($j=0; $j<@a; $j++) {
#        
#        $r = _lcm($r, $a[$j]) if $i != $j;
#    }
#    
#    push @r, $r if $r % $a[$i];
#}
#
#print @r ? (sort $r)[0] : -1;
