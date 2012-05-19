<?php
function input()
{
    return rtrim(fgets(STDIN));
}

$member = 0;
$ret = 0;
while (true)
{
    $s = input() ?:"";
    if (strlen($s) == 0) break;
    $st = explode(':', $s);
    if (count($st) == 1)
    {
        if ($s[0] == '+') $member++;
        else $member--;
    }
    else
    {
        $ret += $member * strlen($st[1]);
    }
}
echo "$ret\n";
?>
