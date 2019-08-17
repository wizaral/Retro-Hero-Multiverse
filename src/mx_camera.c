#include "game.h"

void mx_camera_move(t_stage *stage) {
	stage->camera.x = (int) stage->hero.x + (stage->hero.width / 2);
	stage->camera.y = (int) stage->hero.y + (stage->hero.height / 2);

	stage->camera.x -= (SCREEN_WIDTH / 2);
	stage->camera.y -= (SCREEN_HEIGHT / 2);
	
	stage->camera.x = MIN(MAX(stage->camera.x, 0), (MAP_WIDTH * BLOCK_SIZE) - SCREEN_WIDTH);
	stage->camera.y = MIN(MAX(stage->camera.y, 0), (MAP_HEIGHT * BLOCK_SIZE) - SCREEN_HEIGHT);
}
