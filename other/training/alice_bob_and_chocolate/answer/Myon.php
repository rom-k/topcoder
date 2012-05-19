<?php
function input() 
{ 
    return rtrim(fgets(STDIN)); 
}

function input_array() 
{ 
    return explode(' ', input()); 
}

$n = input();
$num = input_array();
$dp = array(0);
$sum = 0;
for ($i = 0; $i < $n; $i++)
{
    $dp[$i + 1] = $sum += $num[$i];
}
for ($i = 0; $i < $n; $i++)
{
    if ($dp[$i] <= $sum - $dp[$i + 1]) continue;
    else
    {
        echo $i . ' ' . ($n - $i) . "\n";
        exit();
    }
}
echo  "$n 0\n";
?>
