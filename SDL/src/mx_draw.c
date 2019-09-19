#include "game.h"

static void blit_map(t_game *game, int texture, int x, int y) {
	SDL_Rect dest = {.x = x, .y = y};

    SDL_QueryTexture(game->stage.levels[game->stage.type][texture], NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(game->sdl.ren, game->stage.levels[game->stage.type][texture], NULL, &dest);
}

static void blit_hero(t_game *game, SDL_Texture *texture, int x, int y) {
	SDL_Rect dest = {.x = x, .y = y};

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(game->sdl.ren, texture, NULL, &dest);
}

void mx_draw_map(t_game *game) {
    SDL_Point p1;
    SDL_Point p2;
    SDL_Point pm;

    p1.x = (game->stage.camera.x % BLOCK_SIZE) * -1;
    p2.x = p1.x + MAP_RENDER_WIDTH * BLOCK_SIZE + 8;

    p1.y = (game->stage.camera.y % BLOCK_SIZE) * -1;
    p2.y = p1.y + MAP_RENDER_HEIGHT * BLOCK_SIZE;

    pm.x = game->stage.camera.x / BLOCK_SIZE;
    pm.y = game->stage.camera.y / BLOCK_SIZE;

    for (int y = p1.y; y < p2.y; y += BLOCK_SIZE, pm.y++) {
        for (int x = p1.x; x < p2.x; x += BLOCK_SIZE, pm.x++)
            if (game->stage.map[game->stage.type][pm.y][pm.x] != 99)
                blit_map(game, game->stage.map[game->stage.type][pm.y][pm.x], x, y);
        pm.x = game->stage.camera.x / BLOCK_SIZE;
    }
}

void mx_draw_hero(t_game *game) {
    static int ticks = 0;
    static int number1 = 0;
    static int number2 = 0;

    if (game->stage.hero.is_stay && game->stage.hero.dx == 0 && game->stage.hero.dy == 0) {
        if (game->stage.hero.type == 2 && game->stage.hero.in_ulti)
            blit_hero(game,
                game->stage.hero.tex_stay[3][game->stage.hero.look_side][number1],
                game->stage.hero.x - game->stage.camera.x,
                game->stage.hero.y - game->stage.camera.y);
        else
            blit_hero(game,
                game->stage.hero.tex_stay[game->stage.hero.type][game->stage.hero.look_side][number1],
                game->stage.hero.x - game->stage.camera.x,
                game->stage.hero.y - game->stage.camera.y);
        number1 += ++ticks % 24 ? 0 : 1;
        number1 = number1 > 1 ? 0 : number1;
    }
    else if (game->stage.hero.is_stay) {
        if (game->stage.hero.type == 2 && game->stage.hero.in_ulti)
            blit_hero(game,
                game->stage.hero.tex_move[3][game->stage.hero.look_side][number2],
                game->stage.hero.x - game->stage.camera.x,
                game->stage.hero.y - game->stage.camera.y);
        else
            blit_hero(game,
                game->stage.hero.tex_move[game->stage.hero.type][game->stage.hero.look_side][number2],
                game->stage.hero.x - game->stage.camera.x,
                game->stage.hero.y - game->stage.camera.y);
        number2 += ++ticks % 8 ? 0 : 1;
        number2 = number2 > 3 ? 0 : number2;
    }
    else if (game->stage.hero.is_stay == 0) {
        if (game->stage.hero.type == 2 && game->stage.hero.in_ulti) {
            if (game->stage.hero.dy < 0)
                blit_hero(game,
                    game->stage.hero.tex_jump[3][game->stage.hero.look_side][0],
                    game->stage.hero.x - game->stage.camera.x,
                    game->stage.hero.y - game->stage.camera.y);
            else
                blit_hero(game,
                    game->stage.hero.tex_jump[3][game->stage.hero.look_side][1],
                    game->stage.hero.x - game->stage.camera.x,
                    game->stage.hero.y - game->stage.camera.y);
        }
        else {
            if (game->stage.hero.dy < 0)
                blit_hero(game,
                    game->stage.hero.tex_jump[game->stage.hero.type][game->stage.hero.look_side][0],
                    game->stage.hero.x - game->stage.camera.x,
                    game->stage.hero.y - game->stage.camera.y);
            else
                blit_hero(game,
                    game->stage.hero.tex_jump[game->stage.hero.type][game->stage.hero.look_side][1],
                    game->stage.hero.x - game->stage.camera.x,
                    game->stage.hero.y - game->stage.camera.y);
        }
    }
}

void mx_draw_background(t_game *game) {
    static int ticks = 0;
    static int number = 0;
	static SDL_Rect dest = {.x = 0, .y = 0};

    SDL_QueryTexture(game->stage.backs[game->stage.type][number], NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(game->sdl.ren, game->stage.backs[game->stage.type][number], NULL, &dest);

    number += ++ticks % 8 ? 0 : 1;
    number = number > 7 ? 0 : number;
}
