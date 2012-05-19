<?php
function input()
{
    return rtrim(fgets(STDIN));
}

function input_array()
{
    return explode(' ', input());
}

list($h, $w, $c) = input_array();
$board = array();
for ($i = 0; $i < $h; $i++)
{
    $board[$i] = input();
}
$dic = array();
$dic['.'] = 1;
$dic[$c] = 1;
$vx = array( 1, 0, -1, 0 );
$vy = array( 0, 1, 0, -1 );
for ($i = 0; $i < $h; $i++)
{
    for ($j = 0; $j < $w; $j++)
    {
        if ($board[$i][$j] == $c)
        {
            for ($k = 0; $k < 4; $k++)
            {
                $y = $i + $vy[$k];
                $x = $j + $vx[$k];
                if ($y < 0 || $y >= $h) continue;
                if ($x < 0 || $x >= $w) continue;
                $dic[$board[$y][$x]] = 1;
            }
        }
    }
}
echo count($dic) - 2 . "\n";
?>
