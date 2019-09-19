#include "game.h"

static void frame_rate_manager(long *then, float *remainder) {
	long wait = 16 + *remainder;
    long frame_time = SDL_GetTicks() - *then;

	*remainder -= (int)*remainder;
	wait -= frame_time;

    wait = wait < 1 ? 1 : wait;
	SDL_Delay(wait);

	*remainder += 0.667;
	*then = SDL_GetTicks();
}

void mx_game_init(t_game *game) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    Mix_Init(MIX_INIT_MP3);
    TTF_Init();

    mx_create_sdl_base(&game->sdl);
    mx_create_stage(game);
    mx_create_hero(game);
}

void mx_game_loop(t_game *game) {
	long then = SDL_GetTicks();
	float remainder = 0;

    while (true) {
        SDL_RenderClear(game->sdl.ren);
        mx_draw_background(game);

        mx_input(game);
        mx_hero_input(game);
        mx_hero_move(&game->stage);
        mx_camera_move(&game->stage);

        mx_draw_map(game);
        mx_draw_hero(game);

        SDL_RenderPresent(game->sdl.ren);
        frame_rate_manager(&then, &remainder);
    }
}

void mx_game_stop(t_game *game) {
    mx_destroy_stage_tex(game, "pezrio");
    mx_destroy_stage_tex(game, "mario");
    mx_destroy_stage_tex(game, "sonic");
    mx_destroy_stage_tex(game, "tiny");

    mx_destroy_hero_tex(&game->stage.hero, "mario");
    mx_destroy_hero_tex(&game->stage.hero, "sonic");
    mx_destroy_hero_tex(&game->stage.hero, "tiny");
    mx_delete_sdl_base(&game->sdl);

    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    exit(0);
}
