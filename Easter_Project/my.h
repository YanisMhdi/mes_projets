/*
** my.h for  in /home/regency/Repo
** 
** Made by IRICANIN Filip
** Login   <irican_f@etna-alternance.net>
** 
** Started on  Mon Apr 13 10:17:59 2015 IRICANIN Filip
** Last update Mon Apr 13 10:18:02 2015 IRICANIN Filip
*/

#ifndef MY_H__
#define MY_H__

#include <SDL/SDL_mixer.h>

typedef struct s_screen
{
  SDL_Surface* 	s;
  SDL_Surface* 	m[3];
  SDL_Rect	pos[3];
  Mix_Chunk*	musique;
  int		player;
  Mix_Music*	battle;
}t_screen;

t_screen scr;

void	draw_rect();
void	set_color(int *k);
void	draw_sub_mag();
void	set_magie(int *p);
void	select_mag(SDL_Event e, int *p, int *quit, int *MainQuit);
void	magic_menu(int *MainQuit);
void	select_cbt(SDL_Event e, int *k, int *MainQuit);
void	draw_player_stats();
void	item_menu();
void	select_item(SDL_Event e, int *p, int *quit);
void	set_item(int *p);
void	draw_sub_item();
void	draw_item_count();
void	set_attack(int *p);
void	select_attack(SDL_Event e, int *p, int *quit, int *MainQuit);
void	attack_menu(int *MainQuit);
void	use_attack(int *p, int *MainQuit);
void	draw_sub_attack();
void	define_stats();
void	draw_player();
void	draw_player_model();
void	draw_ennemy_model();
void	set_select(int *k);
void	main_select(SDL_Event e, int *k);
void	draw_menu();
void	use_magic(int *p, int *MainQuit);
void	doom_animation();
void	anim_doom(SDL_Rect DOOM[81]);
void	fire_animation();
void	boucle_explose(SDL_Rect EXPLOSE[12], const int EXPLOSE_WIDTH,
		       const int EXPLOSE_HEIGHT);
void	anim_fireball(SDL_Surface* fireball, SDL_Surface* explose,
		      SDL_Rect FIRE[4], SDL_Rect EXPLOSE[12]);
void	decoupecatfire(SDL_Rect FIRE[4]);
void	heal_animation();
void	decoupe_heal(SDL_Rect* Health);
void	thunder_animation();
void	anim_thunder(SDL_Surface* thunder, SDL_Rect Thunder[3]);
void	decoupe_thunder(SDL_Rect Thunder[3]);
void	my_exit(void);
void	apply_surface(int x, int y, SDL_Surface* source,
		      SDL_Surface* destination, SDL_Rect* clip);
void	end_screen(int *MainQuit);
void	write_hero_damage(int dmg);
void	write_ennemy_damage(int dmg);
void	write_hero_heal(int dmg);
void	write_hero_ether(int dmg);
void	write_ennemy_ether(int dmg);
void	write_critical();
void	use_item(int *p);
void	game();
void	accept_sound();
void	heal_sound();
void	slash_sound();
void	ether_animation();
void	earthquake_animation();
void	battle_sound();
void	earthquake_sound();
void	thunder_sound();
void	attack_sound();
void	move_animation();
void	slash_animation ();
void	bite_animation();
void	main_menu();
void	move_sound();
void	fireball_sound();
void	explosion_sound();
int	draw_libra();
int	attack();
int	slash();
int	thunder();
int	fire();
int	potion();
int	ether();
int	heal();
int	monster_turn();
int	bite();
int	doom();
int	earthquake();

#endif
