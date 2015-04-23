/*
** Sounds.c for  in /home/regency
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Sun Apr 12 12:40:10 2015 IRICANIN Filip
** Last update Sun Apr 12 12:40:33 2015 IRICANIN Filip
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

void	heal_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/heal.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0);	
}

void	slash_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/Slash.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0)	;
}

void	earthquake_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/Earthquake.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0);
}

void	fireball_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/Fireball.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0);
}

void	explosion_sound()
{
  scr.musique = Mix_LoadWAV("Sounds/Explode.wav");
  Mix_VolumeChunk(scr.musique, MIX_MAX_VOLUME);
  Mix_PlayChannel(2, scr.musique, 0);
}
