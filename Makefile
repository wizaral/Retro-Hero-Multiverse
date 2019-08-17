NAME = endgame

SRC = src/mx_camera.c \
	src/mx_draw.c \
	src/mx_game.c \
	src/mx_hero_ulti.c \
	src/mx_hero.c \
	src/mx_keyboard.c \
	src/mx_lib.c \
	src/mx_load.c \
	src/mx_main.c \
	src/mx_menu.c \
	src/mx_stage.c

INC = inc/defines.h \
	inc/game.h \
	inc/lib.h \
	inc/stage.h

CFILES = mx_camera.c \
	mx_draw.c \
	mx_game.c \
	mx_hero_ulti.c \
	mx_hero.c \
	mx_keyboard.c \
	mx_lib.c \
	mx_load.c \
	mx_main.c \
	mx_menu.c \
	mx_stage.c

HFILES = defines.h \
	game.h \
	lib.h \
	stage.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
DFLAGS = -fsanitize=address -g
RFLAGS = -Ofast

FFLAGS = -I ./Frameworks/SDL2.framework/Versions/A/Header \
		-F ./Frameworks -framework SDL2 -rpath ./Frameworks \
		-I ./Frameworks/SDL2_image.framework/Versions/A/Header \
		-F ./Frameworks -framework SDL2_image -rpath ./Frameworks \
		-I ./Frameworks/SDL2_mixer.framework/Versions/A/Header \
		-F ./Frameworks -framework SDL2_mixer -rpath ./Frameworks \
		-I ./Frameworks/SDL2_ttf.framework/Versions/A/Header \
		-F ./Frameworks -framework SDL2_ttf -rpath ./Frameworks

all: install clean
dbg: debug clean
release: build clean

install:
		@cp $(SRC) .
		@cp $(INC) .
		@clang $(CFLAGS) $(FFLAGS) -o $(NAME) $(CFILES)
debug:
		@cp $(SRC) .
		@cp $(INC) .
		@clang $(CFLAGS) $(FFLAGS) $(DFLAGS) -o $(NAME) $(CFILES)
build:
		@cp $(SRC) .
		@cp $(INC) .
		@clang $(CFLAGS) $(FFLAGS) $(RFLAGS) -o $(NAME) $(CFILES)
clean:
		@rm -rf $(CFILES)
		@rm -rf $(HFILES)
uninstall: clean
		@rm -rf $(NAME)
reinstall: uninstall all
