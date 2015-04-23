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
