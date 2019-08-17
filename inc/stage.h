#ifndef MAP_H
#define MAP_H
#include "lib.h"
#include "game.h"

typedef struct s_hero {
    float x;        // позиция
    float y;        // позиция
    float dx;       // смещение
    float dy;       // смещение
    int width;      // ширина текстуры в пикселях
    int height;     // высота текстуры в пикселях
    int type;       // тип перса (1 из трёх)

    bool is_stay;   // true - стоит на земле
    bool in_ulti;   // true - герой в ультимейте
    bool look_side; // true - left, false - right (направление взгляда)

    // для 3 персов + ульт. для левого и правого направления взгляда перса
    SDL_Texture *tex_stay[4][2][2]; // массив текстур простоя
    SDL_Texture *tex_move[4][2][4]; // массив ходьбы
    SDL_Texture *tex_jump[4][2][2]; // массив прыжка

    Mix_Chunk *sound_swap;          // свап
    Mix_Chunk *sound_jump;          // прыжок
    Mix_Chunk *sound_ulti[3];       // звук ульты для каждого перса
} t_hero;

typedef struct s_stage {
    SDL_Point camera;               // позиция камеры
    int type;                       // тип уровня (0 - 2)
    t_hero hero;                    // наш перс

    Mix_Chunk *sound_swap;          // свап уровня
    SDL_Texture *backs[3][8];       // задний фон
    SDL_Texture *levels[3][52];     // текстуры на каждый уровень
    int map[3][33][180];            // карта
} t_stage;

#endif
