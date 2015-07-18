<?php

function self_concat($str, $n)
{
    $result = "";
    for ($i = 0; $i < $n; $i++) {
        $result .= $str;
    }

    return $result;
}

echo self_concat("HappyHacker", 3);
echo "\n";
echo self_concat("Lovelock", 1);
