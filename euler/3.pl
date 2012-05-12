use Math::BigInt;
$num = Math::BigInt->new("600851475143");
$i   = Math::BigInt->new("0");
for ($i=2; $i<=$num; $i++) {
    while ($num%$i == 0) {
        $prime = $num;
        $num = $num/$i;
    }
}
print $prime; #=> 6857
