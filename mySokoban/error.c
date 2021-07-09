/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** error
*/

#include "my.h"

int char_error(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        if (check(str, i) == 1)
            return (1);
    }
    return (0);
}

int check(char **str, int i)
{
    for (int a = 0; str[i][a] != '\0'; a++) {
        if (is_fine(str[i][a]) != 1)
            return (1);
    }
    return (0);
}

int is_fine(char a)
{
    if (a != '\n' && a != 'X' && a != 'O' && a != 'P' && a != ' ' && \
    a != '\0' && a != '#')
        return (0);
    else
        return (1);
}

int error(int ac, char **av, char **str)
{
    int fd = 0;

    if (ac != 2)
        return (1);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("USAGE\n     ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n     map  file \
        representing the warehouse map, containing ‘#’");
        my_putstr("for walls,\n          \
        ‘P’ for the player, ‘X’ for boxes and ‘O’ for");
        my_putstr("storage locations.\n");
        return (0);
    }
    if (error_stor(fd, str, av))
        return (1);
    return (0);
}

int error_stor(int fd, char **str, char **av)
{
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (1);
    close(fd);
    if (char_error(str) == 1)
        return (1);
    return (0);
}