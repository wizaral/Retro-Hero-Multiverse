#include "game.h"

void mx_create_hero(t_game *game) {
    game->stage.hero.x = 32;
    game->stage.hero.y = 32;
    game->stage.hero.dx = 0;
    game->stage.hero.dy = 0;

    game->stage.hero.type = 0;
    game->stage.hero.width = BLOCK_SIZE * 3;
    game->stage.hero.height = BLOCK_SIZE * 5;
    game->stage.hero.is_stay = 0;
    game->stage.hero.in_ulti = 0;
    game->stage.hero.look_side = 0;

    game->stage.hero.sound_jump = Mix_LoadWAV("resource/sounds/effects/jump.wav");
    game->stage.hero.sound_swap = Mix_LoadWAV("resource/sounds/effects/swap_hero.wav");
    game->stage.hero.sound_ulti[0] = Mix_LoadWAV("resource/sounds/effects/tiny_ulti.wav");
    game->stage.hero.sound_ulti[1] = Mix_LoadWAV("resource/sounds/effects/sonic_ulti.wav");
    game->stage.hero.sound_ulti[2] = Mix_LoadWAV("resource/sounds/effects/mario_ulti.wav");

    mx_load_hero_tex(game, &game->stage.hero, "tiny");
    mx_load_hero_tex(game, &game->stage.hero, "sonic");
    mx_load_hero_tex(game, &game->stage.hero, "mario");
    mx_load_hero_tex(game, &game->stage.hero, "pezrio");
}

void mx_create_stage(t_game *game) {
    game->stage.type = 0;
    game->stage.camera.x = 0;
    game->stage.camera.y = 0;
    game->stage.sound_swap = Mix_LoadWAV("resource/sounds/effects/swap_level.wav");

    mx_load_stage_tex(game, "tiny");
    mx_load_stage_tex(game, "sonic");
    mx_load_stage_tex(game, "mario");
    mx_load_maps(&game->stage);
}

bool isinside_map(int x, int y) {
	return x >= 0 && x < MAP_WIDTH && y < MAP_HEIGHT;
}
