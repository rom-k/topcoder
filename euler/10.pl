#!perl

# eratosthenes

@nums = 2..2_000_000;
while (1) {
    $num = shift @nums;
    $sum += $num;
    @nums = grep {$_ % $num != 0} @nums;
    
    if ($nums[-1] < $num**2) {
        $sum += $_ foreach(@nums);
        print $sum; # => 142913828922
        exit;
    }
}
