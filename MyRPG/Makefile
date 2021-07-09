##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## .
##

SRC	=	lib/linked_list.c	\
	lib/my_revstr.c	\
	lib/my_strcat_j.c	\
	lib/my_strcpy.c	\
	lib/my_strlen.c	\
	lib/nb_to_str_cd.c	\
	lib/nb_to_str.c	\
	map/main.c \
	map/write.c \
	map/tile.c \
	map/lava.c \
	map/framebuffer.c \
	map/simple_tile.c \
	map/hero.c \
	map/position.c \
	map/enemi.c \
	map/move.c \
	map/attack.c \
	map/aggro.c \
	map/one_run.c \
	map/read.c	\
	map/enemy_types.c \
	map/init_enem.c	\
	map/aim.c	\
	map/draw_enemy.c	\
	map/spawn_enemy.c	\
	map/del_node.c	\
	map/npc.c \
	map/aggro_step.c	\
	map/set_hero.c	\
	map/draw_map.c	\
	map/interact_npc.c \
	map/colision.c \
	map/colision2.c \
	map/particle.c \
	map/boss.c \
	map/aggro_store.c \
	map/fire.c \
	map/thunder_stor.c \
	src/scenes/button_actions.c	\
	src/scenes/button_colors.c	\
	src/scenes/draw_scenes.c	\
	src/scenes/end_screen_l.c	\
	src/scenes/end_screen_w.c	\
	src/scenes/how_to_play.c	\
	src/scenes/init_buttons.c	\
	src/scenes/init_scenes.c	\
	src/scenes/malloc_scenes.c	\
	src/scenes/restart_game.c	\
	src/scenes/settings_menu.c	\
	src/scenes/status_menu.c	\
	src/scenes/volume_controller.c	\
	src/create_obj.c	\
	src/create_sprite.c	\
	src/draw_ui.c	\
	src/event.c	\
	src/game_loop.c	\
	src/music_buttons.c	\
	src/music_callback.c	\
	src/music_settings.c	\
	src/my_rpg.c	\
	src/next_level.c	\
	src/show_details.c	\
	src/sound_effects.c	\
	src/scenes/inventory_scene.c	\
	inventory.c	\
	src/inventory_utils.c	\
	src/free_utils.c	\
	src/change_lvl.c \
	src/scenes/help_shortcuts.c

INC	=	-I./include/

LIB =	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

NAME	=	my_rpg

OBJ	=	$(SRC1:.c=.o)

all:	$(NAME) clean

$(NAME):	$(OBJ)
	cd map/lib/my && make
	gcc $(SRC) $(INC) -o $(NAME) -g3 $(LIB) -I ./map/ -lm -L./map/lib -lmy -g3
	rm map/lib/my/*.o

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all