##
## EPITECH PROJECT, 2021
## B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
## File description:
## Makefile
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	=	./main.c \
			./my_ai.c \
			./print.c \
			./error.c \
			./map.c \
			./tools.c \
			./ai_store.c \
			./input.c \
			./game_loop.c \
			./store.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./lib/my/ -L ./lib -lmy -g3
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 cd lib/my && make re
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
