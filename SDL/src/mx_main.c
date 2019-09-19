#include "game.h"

int main() {
    t_game game;

    mx_game_init(&game);
    mx_main_menu(&game);
    mx_game_loop(&game);
    mx_game_stop(&game);

    return 0;
}
