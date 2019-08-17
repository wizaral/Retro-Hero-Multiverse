#include "game.h"

static void key_up(t_game *game, SDL_KeyboardEvent *event) {
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
        game->keyboard[event->keysym.scancode] = false;
}

static void key_down(t_game *game, SDL_KeyboardEvent *event) {
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
        game->keyboard[event->keysym.scancode] = true;
}

void mx_input(t_game *game) {
    static SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                mx_game_stop(game);
                break;

            case SDL_KEYDOWN:
                key_down(game, &event.key);
                break;

            case SDL_KEYUP:
                key_up(game, &event.key);
                break;
		}
	}
}
