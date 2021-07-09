##
## EPITECH PROJECT, 2021
## sokoban
## File description:
## makefile
##

NAME	= my_sokoban

CC	= gcc

RM	= rm -f

SRCS	= ./load_2d_arr.c \
	  main.c \
	  error.c \
	  map_tools.c \
	  move.c \
	  tools.c \
	  win_or_lose.c \
	  move_store.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra -lncurses -L ./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	cd lib/my && make
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
