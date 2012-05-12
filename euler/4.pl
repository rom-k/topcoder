my @list;
my %x_of;
foreach $x (100..999) {
    foreach $y (100..999) {
        last if $x < $y; # x>=y‚Ìê‡‚Ì‚İ
        if (_is_palindrome($x * $y)) {
            push(@list, $x * $y);
            $x_of{$x * $y} = $x;
        }
    }
}

@list = reverse sort {$a <=> $b} @list;
print $list[0]
    . " ("
    . $x_of{$list[0]}
    . " * "
    . $list[0]/$x_of{$list[0]}
    . ")";
#=> 906609 (913 * 993)

# ‰ñ•¶‚©‚Ç‚¤‚©‚ğŠm”F‚·‚éŠÖ”
sub _is_palindrome {
    $str = shift;
    foreach $i (1..length($str)) {
        return 0 if substr($str, $i-1, 1) ne substr($str, length($str)-$i, 1);
    }
    return 1;
}