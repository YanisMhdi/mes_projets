/*
** main.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:29:06 2015 IRICANIN Filip
** Last update Sun Apr 12 18:31:54 2015 IRICANIN Filip
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "my.h"
#include "my_hero.h"
#include "my_monster.h"

void	thunder_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/Thunder.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0);
}

void	move_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/CursorMove.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0);
}

void	accept_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/CursorAccept.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0);
}

void	battle_sound()
{
  scr.battle = Mix_LoadMUS("Sounds/Clenching.mp3");
  Mix_VolumeMusic(MIX_MAX_VOLUME - 5);
  Mix_PlayMusic(scr.battle, -1);
}

int	main()
{
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
  game();
  Mix_CloseAudio();
  SDL_Quit();
  return (0);
}
