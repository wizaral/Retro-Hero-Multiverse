#ifndef LIB_H
#define LIB_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_sdl {
    SDL_Window *win;
    SDL_Renderer *ren;
    Mix_Music *music;
} t_sdl;

void mx_create_sdl_base(t_sdl *sdl);
void mx_delete_sdl_base(t_sdl *sdl);

#endif
