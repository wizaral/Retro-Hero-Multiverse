#include "game.h"

static void hero_move_x(t_stage *stage, t_hero *hero) {
	int mx = hero->dx > 0 ? (hero->x + hero->width) : hero->x;
    int my;
    int adj;
    int hit = 0;

	mx /= BLOCK_SIZE;
	my = hero->y / BLOCK_SIZE;

	if (!isinside_map(mx, my) || stage->map[stage->type][my][mx] != 99)
		hit = 1;

	my = (hero->y + hero->height - 1) / BLOCK_SIZE;
	if (!isinside_map(mx, my) || stage->map[stage->type][my][mx] != 99)
	    hit = 1;

	if (hit) {
		adj = hero->dx > 0 ? -hero->width : BLOCK_SIZE;
		hero->x = (mx * BLOCK_SIZE) + adj;
		hero->dx = 0;
	}
}

static void hero_move_y(t_stage *stage, t_hero *hero) {
	int mx;
    int my = hero->dy > 0 ? (hero->y + hero->height) : hero->y;
    int adj;
    int hit = 0;

    my /= BLOCK_SIZE;
	mx = hero->x / BLOCK_SIZE;

    if (!isinside_map(mx, my)) {
        hero->x = 0;
        hero->y = 0;
        stage->type = 0;
    }

	if (stage->map[stage->type][my][mx] != 99)
		hit = 1;

    mx = (hero->x + hero->width - 1) / BLOCK_SIZE;
	if (stage->map[stage->type][my][mx] != 99)
		hit = 1;

	if (hit) {
		adj = hero->dy > 0 ? -hero->height : BLOCK_SIZE;
		hero->y = (my * BLOCK_SIZE) + adj;
		hero->is_stay = hero->dy > 0;
		hero->dy = 0;
	}
}

void mx_hero_input(t_game *game) {
    if (game->keyboard[SDL_SCANCODE_Q] || game->keyboard[SDL_SCANCODE_ESCAPE])
        mx_game_stop(game);

    if (!(game->stage.hero.in_ulti && game->stage.hero.type == 1)) {
	    game->stage.hero.dx = 0;

        if (game->keyboard[SDL_SCANCODE_S]) {
            game->stage.hero.type = (game->stage.hero.type + 1) % 3;
            game->keyboard[SDL_SCANCODE_S] = false;

            if (game->stage.hero.type == 0 && game->stage.hero.in_ulti) {
                game->stage.hero.y -= BLOCK_SIZE * 4;
                game->stage.hero.width = 3 * BLOCK_SIZE;
                game->stage.hero.height = 5 * BLOCK_SIZE;
                game->stage.hero.in_ulti = false;
            }

            Mix_PlayChannel(-1, game->stage.hero.sound_swap, 0);
        }

        if (game->keyboard[SDL_SCANCODE_F]) {
            game->stage.type = (game->stage.type + 1) % 3;
            game->keyboard[SDL_SCANCODE_F] = false;
            Mix_PlayChannel(-1, game->stage.sound_swap, 0);
        }

        if (!(game->keyboard[SDL_SCANCODE_RIGHT] && game->keyboard[SDL_SCANCODE_LEFT])) {
            if (game->keyboard[SDL_SCANCODE_LEFT]) {
                game->stage.hero.dx = -PLAYER_MOVE_SPEED;
                game->stage.hero.look_side = true;         // left
            }
            if (game->keyboard[SDL_SCANCODE_RIGHT]) {
                game->stage.hero.dx = PLAYER_MOVE_SPEED;
                game->stage.hero.look_side = false;         // right
            }
        }

        if (game->keyboard[SDL_SCANCODE_D]) {
            switch (game->stage.hero.type) {
                case 0:
                    mx_tiny_ulti(game);
                    break;
                case 1:
                    mx_sonic_ulti(game);
                    break;
                case 2:
                    mx_mario_ulti(game);
            }
            game->keyboard[SDL_SCANCODE_D] = false;
        }

        if (game->keyboard[SDL_SCANCODE_SPACE] && game->stage.hero.is_stay) {
            game->stage.hero.dy = PLAYER_JUMP_SPEED;
            game->stage.hero.is_stay = false;
            game->keyboard[SDL_SCANCODE_SPACE] = false;
            Mix_PlayChannel(-1, game->stage.hero.sound_jump, 0);
        }
    }
    else
        mx_sonic_ulti(game);
}

void mx_hero_move(t_stage *stage) {
    stage->hero.dy += 1.2;
    stage->hero.dy = MAX(MIN(stage->hero.dy, 18), -50);
    stage->hero.is_stay = false;

    stage->hero.x += stage->hero.dx;
    if (stage->hero.dx)
        hero_move_x(stage, &stage->hero);

    stage->hero.y += stage->hero.dy;
    if (stage->hero.dy)
        hero_move_y(stage, &stage->hero);
}
