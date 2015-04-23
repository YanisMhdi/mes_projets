<?php

function	nox_o($tab)
{
  $res = array_count_values($tab);
  foreach($res as $key => $value)
    echo $key . " => " . $value . "\n";
}
