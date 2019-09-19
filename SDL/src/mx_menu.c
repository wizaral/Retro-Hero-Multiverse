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

void mx_main_menu(t_game *game) {
	long then = SDL_GetTicks();
	float remainder = 0;
    SDL_Event event;
	SDL_Rect dest = {.x = 246, .y = 99};

    SDL_Color Red = {222, 19, 13, 255};
    SDL_Color Blue = {0, 95, 250, 255};

    SDL_Texture *menu = IMG_LoadTexture(game->sdl.ren, "resource/textures/menu/LOGO3.png");
    TTF_Font *font = TTF_OpenFont("resource/fonts/17660.otf", 70);

    SDL_Surface *text1 = TTF_RenderText_Solid(font, "PRESS F", Blue);
    SDL_Texture *message1 = SDL_CreateTextureFromSurface(game->sdl.ren, text1);
    SDL_Surface *text2 = TTF_RenderText_Solid(font, "PRESS Q", Red);
    SDL_Texture *message2 = SDL_CreateTextureFromSurface(game->sdl.ren, text2);

    SDL_Rect rect1 = {.x = 600, .y = 650, .w = 600, .h = 140};
    SDL_Rect rect2 = {.x = 600, .y = 820, .w = 600, .h = 140};

    while (true) {
        SDL_RenderClear(game->sdl.ren);
        SDL_QueryTexture(menu, NULL, NULL, &dest.w, &dest.h);
	    SDL_RenderCopy(game->sdl.ren, menu, NULL, &dest);
        SDL_RenderCopy(game->sdl.ren, message1, NULL, &rect1);
        SDL_RenderCopy(game->sdl.ren, message2, NULL, &rect2);
        SDL_RenderPresent(game->sdl.ren);

        if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN) {
            if (event.key.keysym.scancode == SDL_SCANCODE_F)
                break;
            else if (event.key.keysym.scancode == SDL_SCANCODE_Q
                || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                mx_game_stop(game);
            }
        }
        else if (event.type == SDL_QUIT)
            mx_game_stop(game);
        frame_rate_manager(&then, &remainder);
    }
    SDL_DestroyTexture(menu);
}
