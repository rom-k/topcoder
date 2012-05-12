$prv = 1;
$cur = 1;
while(true) {
    last if $cur > 4000000;
    $sum += $cur if $cur%2==0;
    
    $new = $prv + $cur;
    $prv = $cur;
    $cur = $new;
}
print $sum; #=> 4613732