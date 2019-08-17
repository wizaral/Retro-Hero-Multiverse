#include "lib.h"
#include "defines.h"

void mx_create_sdl_base(t_sdl *sdl) {
    if (sdl) {
        sdl->win = SDL_CreateWindow("EndGame", CENTER, CENTER, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        sdl->ren = SDL_CreateRenderer(sdl->win, -1, RENDER_FLAGS);

	    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
        Mix_AllocateChannels(MAX_SND_CHANNELS);

        sdl->music = Mix_LoadMUS("resource/sounds/music/music.mp3");
	    Mix_PlayMusic(sdl->music, -1);
	    SDL_ShowCursor(0);
    }
}

void mx_delete_sdl_base(t_sdl *sdl) {
    if (sdl) {
        Mix_HaltMusic();
		Mix_FreeMusic(sdl->music);

        SDL_DestroyRenderer(sdl->ren);
        SDL_DestroyWindow(sdl->win);
    }
}
