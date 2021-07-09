##
## EPITECH PROJECT, 2021
## .
## File description:
## .
##

NAME	= my_world

CC	= gcc

RM	= rm -f

SRCS	=	./main.c \
			./write.c \
			./tile.c \
			./lava.c \
			./framebuffer.c \
			./simple_tile.c \
			./hero.c \
			./position.c \
			./enemi.c \
			./move.c \
			./attack.c \
			./aggro.c \
			./one_run.c \
			./read.c \
			./enemy_types.c \
			./init_enem.c	\
			./aim.c	\
			./draw_enemy.c	\
			./spawn_enemy.c	\
			./del_node.c	\
			./aggro_step.c	\
			./set_hero.c	\
			./draw_map.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ../include/
CFLAGS += -Wall -Wextra -lm -L./lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network -g3

all: $(NAME)

$(NAME): $(OBJS)
	cd lib/my && make
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) lib/libmy.a
	$(RM) lib/my/libmy.a

re: fclean all

.PHONY: all clean fclean re
