<?php
function input()
{
    return rtrim(fgets(STDIN));
}

function input_array()
{
    return explode(' ', input());
}

$num = input_array();
sort($num);
if ($num[0] + $num[1] > $num[2] || $num[1] + $num[2] > $num[3]) echo "TRIANGLE\n";
else if($num[0] + $num[1] == $num[2] || $num[1] + $num[2] == $num[3]) echo "SEGMENT\n";
else echo "IMPOSSIBLE\n";
?>
