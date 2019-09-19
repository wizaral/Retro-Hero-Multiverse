#include "game.h"

void mx_mario_ulti(t_game *game) {
	if (!game->stage.hero.in_ulti) {
		game->stage.hero.in_ulti = true;
        game->stage.hero.y += BLOCK_SIZE * 4;
		game->stage.hero.width = BLOCK_SIZE;
		game->stage.hero.height = BLOCK_SIZE;
	}
	else {
		game->stage.hero.in_ulti = false;
        game->stage.hero.y -= BLOCK_SIZE * 4;
        game->stage.hero.width = 3 * BLOCK_SIZE;
        game->stage.hero.height = 5 * BLOCK_SIZE;
	}
	Mix_PlayChannel(-1, game->stage.hero.sound_ulti[2], 0);
}

void mx_sonic_ulti(t_game *game) {
	static int delta = 0;
	if (game->stage.hero.is_stay && !game->stage.hero.in_ulti) {
		delta = PLAYER_MOVE_SPEED + 3;
		game->stage.hero.dy = PLAYER_JUMP_SPEED;
        //game->stage.hero.width = 6 * BLOCK_SIZE;

		game->stage.hero.in_ulti = true;
		game->stage.hero.is_stay = false;

		Mix_PlayChannel(-1, game->stage.hero.sound_ulti[1], 0);
	}
	else if (!game->stage.hero.is_stay && game->stage.hero.in_ulti) {
		if (game->stage.hero.look_side && delta > 0)
			game->stage.hero.dx -= 2;
		else if (delta > 0)
			game->stage.hero.dx += 2;
		delta -= 1;
	}
	else {
		game->stage.hero.in_ulti = false;
        //game->stage.hero.width = 3 * BLOCK_SIZE;
	}
}

void mx_tiny_ulti(t_game *game) {
	if (game->stage.hero.is_stay) {
		game->stage.hero.in_ulti = true;
		game->stage.hero.is_stay = false;
		game->stage.hero.dy = PLAYER_JUMP_SPEED * 1.5;
		Mix_PlayChannel(-1, game->stage.hero.sound_ulti[0], 0);
	}
}
