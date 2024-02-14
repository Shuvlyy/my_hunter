##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile for my_hunter project
## ------------------------------- ##
## Written by Lysandre BOURSETTE   ##
## (lysandre.boursette@epitech.eu) ##
## Created on 21/11/2023 19:59:33  ##
## IDE used: CLion 2023.2.2        ##
## github.com/shuvlyy              ##
## ------------------------------- ##
##

NAME = my_hunter

SRC_MAIN = my_hunter.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

SRC_MISC = sh_str_len.c
SRC_MISC += sh_put_err.c
SRC_MISC += sh_put_str.c
SRC_MISC += sh_str_cmp.c
SRC_MISC += sh_uint_to_str.c
SRC_MISC += sh_uint_len.c
SRC_MISC += sh_str_cpy.c
SRC_MISC += sh_str_ncpy.c
SRC_MISC += sh_str_cat.c
SRC_MISC += sh_str_ncat.c
SRC_MISC += sh_lerp.c
SRC_MISC += sh_get_secs_from_clock.c
OBJ_MISC = $(SRC_MISC:.c=.o)

SRC_GAME = sh_game.c
SRC_GAME += sh_game_manager.c
SRC_GAME += title_screen.c
SRC_GAME += round_change.c
SRC_GAME += sh_hud.c
SRC_GAME += playing.c
SRC_GAME += fly_away.c
SRC_GAME += got_ducks.c
OBJ_GAME = $(SRC_GAME:.c=.o)

SRC_WINDOW = window_manager.c
OBJ_WINDOW = $(SRC_WINDOW:.c=.o)

SRC_TEXT = sh_text.c
OBJ_TEXT = $(SRC_TEXT:.c=.o)

SRC_AUDIO = sh_audio_manager.c
OBJ_AUDIO = $(SRC_AUDIO:.c=.o)

SRC_ENTITY = sh_dog.c
SRC_ENTITY += sh_duck.c
OBJ_ENTITY = $(SRC_ENTITY:.c=.o)

SRC_SPRITE = sh_sprite.c
SRC_SPRITE += sh_animator.c
SRC_SPRITE += sh_mover.c
OBJ_SPRITE = $(SRC_SPRITE:.c=.o)

SRC_RANDOM = sh_random.c
OBJ_RANDOM = $(SRC_RANDOM:.c=.o)

OBJS = $(OBJ_MAIN)
OBJS += $(OBJ_MISC)
OBJS += $(OBJ_GAME)
OBJS += $(OBJ_WINDOW)
OBJS += $(OBJ_TEXT)
OBJS += $(OBJ_AUDIO)
OBJS += $(OBJ_ENTITY)
OBJS += $(OBJ_SPRITE)
OBJS += $(OBJ_RANDOM)

D_MAIN = src/main/
D_MISC = src/misc/
D_GAME = src/game/
D_WINDOW = src/window/
D_TEXT = src/text/
D_AUDIO = src/audio/
D_ENTITY = src/entity/
D_SPRITE = src/sprite/
D_RANDOM = src/random/

CC = gcc -c $(CFLAGS)

CFLAGS = -Wall -Wextra
CFLAGS += -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
CFLAGS += -lm -g

all: $(NAME)

$(NAME):
	mkdir -p bin/
	cd $(D_MAIN) && $(CC) $(SRC_MAIN) -I../../include
	cd $(D_MAIN) && mv $(OBJ_MAIN) ../../bin
	cd $(D_MISC) && $(CC) $(SRC_MISC) -I../../include
	cd $(D_MISC) && mv $(OBJ_MISC) ../../bin
	cd $(D_GAME) && $(CC) $(SRC_GAME) -I../../include
	cd $(D_GAME) && mv $(OBJ_GAME) ../../bin
	cd $(D_WINDOW) && $(CC) $(SRC_WINDOW) -I../../include
	cd $(D_WINDOW) && mv $(OBJ_WINDOW) ../../bin
	cd $(D_TEXT) && $(CC) $(SRC_TEXT) -I../../include
	cd $(D_TEXT) && mv $(OBJ_TEXT) ../../bin
	cd $(D_AUDIO) && $(CC) $(SRC_AUDIO) -I../../include
	cd $(D_AUDIO) && mv $(OBJ_AUDIO) ../../bin
	cd $(D_ENTITY) && $(CC) $(SRC_ENTITY) -I../../include
	cd $(D_ENTITY) && mv $(OBJ_ENTITY) ../../bin
	cd $(D_SPRITE) && $(CC) $(SRC_SPRITE) -I../../include
	cd $(D_SPRITE) && mv $(OBJ_SPRITE) ../../bin
	cd $(D_RANDOM) && $(CC) $(SRC_RANDOM) -I../../include
	cd $(D_RANDOM) && mv $(OBJ_RANDOM) ../../bin
	cd bin && gcc -o $(NAME) $(OBJS) $(CFLAGS) && mv $(NAME) ../

main: re
	clear
	./$(NAME)

clean:
	cd bin/ && $(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
