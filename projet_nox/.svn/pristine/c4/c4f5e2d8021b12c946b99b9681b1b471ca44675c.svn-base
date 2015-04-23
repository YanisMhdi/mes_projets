<?php
// erreurs.php for Nox in /home/diman_i/0test
//
// Made by Diman Ioan-Adrian
// Login   <diman_i@etna-alternance.net>
//
// Started on  Fri Nov  7 17:31:49 2014 Diman Ioan-Adrian
// Last update Mon Nov 10 16:19:05 2014 Diman Ioan-Adrian
//

function	erreur($argv, $argc)
{
  $x = 1;
  if (isset($argv[3]))
    {
      if ($argv[3] != "-m" && $argv[3] != "-o")
	{
	  echo "nox : Bad argument\n";
	  return 1;
	}
    }
  if (!isset($argv[1]) || !isset($argv[2]))
    {
      echo ("nox : Missing arguments\n");
      return 1;
    }
  while ($x != 3)
    {
      if (file_exists($argv[$x]) == FALSE)
	{
	  echo ("nox: $argv[$x] : No such file or directory\n");
	  return 1;
	}
      if (is_dir($argv[$x]) == TRUE)
	{
	  echo ("nox: $argv[$x]: Is a directory\n");
	  return 1;
	}
      if (is_readable($argv[$x]) == FALSE)
	{
	  echo ("nox: $argv[$x]: Cannot open file\n");
	  return 1;
	}
      if (is_writeable($argv[$x]) == FALSE)
	{
	  echo ("nox: $argv[$x]: Permission denied\n");
	  return 1;
	}
      $x++;
    }
}