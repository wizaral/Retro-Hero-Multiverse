#include "game.h"

void mx_load_maps(t_stage *stage) {
    FILE *file[3];

    file[0] = fopen("resource/maps/sonic.txt", "r");
    file[1] = fopen("resource/maps/mario.txt", "r");
    file[2] = fopen("resource/maps/tiny.txt", "r");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 33; j++)
            for (int k = 0; k < 180; k++)
                fscanf(file[i], "%i", &stage->map[i][j][k]);

    for (int i = 0; i < 3; i++)
        fclose(file[i]);
}

void mx_load_stage_tex(t_game *game, const char *name) {
    char filename[50] = {0};
    int amount = !strcmp("sonic", name) ? 52 : 21;
    int level_type = amount == 52 ? 0 : !strcmp("tiny", name) ? 1 : 2;

    for (int i = 0; i < amount; i++) {
        sprintf(filename, "resource/textures/levels/%s/block%d.png", name, i);
        game->stage.levels[level_type][i] = IMG_LoadTexture(game->sdl.ren, filename);
    }
    for (int i = 0; i < 8; i++) {
        sprintf(filename, "resource/textures/levels/%s/back%d.png", name, i);
        game->stage.backs[level_type][i] = IMG_LoadTexture(game->sdl.ren, filename);
    }
}

void mx_load_hero_tex(t_game *game, t_hero *hero, const char *name) {
    char filename[50] = {0};
    int type = !strcmp("pezrio", name) ? 3 : !strcmp("mario", name) ? 2 : !strcmp("sonic", name) ? 1 : 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sprintf(filename, "resource/textures/heroes/%s/jump%d%d.png", name, i, j);
            hero->tex_jump[type][i][j] = IMG_LoadTexture(game->sdl.ren, filename);
        }
        for (int j = 0; j < 4; j++) {
            sprintf(filename, "resource/textures/heroes/%s/move%d%d.png", name, i, j);
            hero->tex_move[type][i][j] = IMG_LoadTexture(game->sdl.ren, filename);
        }
        for (int j = 0; j < 2; j++) {
            sprintf(filename, "resource/textures/heroes/%s/stay%d%d.png", name, i, j);
            hero->tex_stay[type][i][j] = IMG_LoadTexture(game->sdl.ren, filename);
        }
    }
}

void mx_destroy_stage_tex(t_game *game, const char *name) {
    int amount = !strcmp("sonic", name) ? 52 : 21;
    int level_type = amount == 52 ? 0 : !strcmp("tiny", name) ? 1 : 2;

    for (int i = 0; i < amount; i++)
        SDL_DestroyTexture(game->stage.levels[level_type][i]);

    for (int i = 0; i < 8; i++)
        SDL_DestroyTexture(game->stage.backs[level_type][i]);
}

void mx_destroy_hero_tex(t_hero *hero, const char *name) {
    int type = !strcmp("pezrio", name) ? 3 : !strcmp("mario", name) ? 2 : !strcmp("sonic", name) ? 1 : 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            SDL_DestroyTexture(hero->tex_jump[type][i][j]);

        for (int j = 0; j < 4; j++)
            SDL_DestroyTexture(hero->tex_move[type][i][j]);

        for (int j = 0; j < 2; j++)
            SDL_DestroyTexture(hero->tex_stay[type][i][j]);
    }
}
