#!/usr/bin/env php
<?php
// no_x.php for  in /home/diman_i/no_x
//
// Made by Diman Ioan-Adrian
// Login   <diman_i@etna-alternance.net>
//
// Started on  Thu Nov  6 09:15:38 2014 Diman Ioan-Adrian
// Last update Mon Nov 10 17:13:26 2014 Diman Ioan-Adrian
//
require('erreurs.php');
require('nox_o.php');
$dico = array(
	      "keusse" => "un sac",
	      "oseille" => "argent",
	      "teuf" => "fete",
	      "wesh" => "salut",
	      "Veuche" => "cheveu");
function	nox($argv, $argc, $dico)
{
  $x = 0;
  $y = 0;
  if (erreur($argv, $argc) == 0)
    {
      
      $wesh = file_get_contents($argv[1]);
      $text = file_get_contents($argv[2]);
      $text = strtolower($text);
      $wesh = strtolower($wesh);
      preg_match_all("/\w+/", $text, $matches);
      $matches = $matches[0];
      while ((isset($matches[$x])))
	{
	  if (preg_match_all("/\b$matches[$x]\b/", $wesh) != FALSE)
	    {
	      if (isset($argv[3]))
		{
		  if ($argv[3] == "-m")
		    {
		      foreach ($dico as $key => $val )
			{
			  if ($key == $matches[$x])
			    echo "\n" . $matches[$x] . " => " . $val . "\n";
			}
		    }
		  else if ($argv[3] == "-o")
		    {
		      $tab[$y] = $matches[$x];
		      $y++;
		    }
		}
	      else
		echo $matches[$x] . "\n";
	    }
	  $x++;
	}
      if (isset($argv[3]) && $argv[3] == "-o")
	nox_o($tab);
    }
}

if (erreur($argv, $argc) == TRUE)
  {
    return (0);
  }
else
  {
    $time_start = microtime(true);
    nox($argv, $argc, $dico);
    $time_end = microtime(true);
    $time = $time_end - $time_start;
    echo "Résolu en $time secondes\n";
  }