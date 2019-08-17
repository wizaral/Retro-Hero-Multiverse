#ifndef GAME_H
#define GAME_H

#include "lib.h"
#include "stage.h"
#include "defines.h"

typedef struct s_game {
    t_sdl sdl;
    t_stage stage;
    bool keyboard[MAX_KEYBOARD_KEYS];
} t_game;

void mx_game_init(t_game *game);
void mx_main_menu(t_game *game);
void mx_game_loop(t_game *game);
void mx_game_stop(t_game *game);

void mx_create_hero(t_game *game);
void mx_create_stage(t_game *game);

void mx_load_maps(t_stage *stage);
void mx_load_hero_tex(t_game *game, t_hero *hero, const char *name);
void mx_load_stage_tex(t_game *game, const char *name);

void mx_destroy_stage_tex(t_game *game, const char *name);
void mx_destroy_hero_tex(t_hero *hero, const char *name);

void mx_camera_move(t_stage *stage);
void mx_hero_move(t_stage *stage);

void mx_hero_input(t_game *game);
void mx_input(t_game *game);

bool isinside_map(int x, int y);

void mx_draw_background(t_game *game);
void mx_draw_hero(t_game *game);
void mx_draw_map(t_game *game);

void mx_sonic_ulti(t_game *game);
void mx_mario_ulti(t_game *game);
void mx_tiny_ulti(t_game *game);

#endif
