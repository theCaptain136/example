/*
** EPITECH PROJECT, 2021
** B-PSU-200-BER-2-1-mysokoban-pablo-elias.herrmann
** File description:
** move_store
*/

#include "my.h"

int error_right(char **map, int *x, int *y)
{
    if (!find_P(map, x, y))
        return (1);
    if ((map)[*y][*x + 1] == '#' || my_strlen((map)[*y]) <= *x + 1)
        return (1);
    return (0);
}

int error_left(char **map, int *x, int *y)
{
    if (!find_P(map, x, y))
        return (1);
    if (*x - 1 < 0 || (map)[*y][*x - 1] == '#')
        return (1);
    return (0);
}

int error_up(char **map, int *x, int *y)
{
    if (!find_P(map, x, y))
        return (1);
    if (*y - 1 < 0 || *x >= my_strlen((map)[*y - 1]) || \
    (map)[*y - 1][*x] == '#')
        return (1);
    return (0);
}

int error_down(char **map, int *x, int *y)
{
    if (!find_P(map, x, y))
        return (1);
    if (*y + 1 >= my_strstrlen(map) || my_strlen((map)[*y + 1]) <= *x)
        return (1);
    if ((map)[*y + 1][*x] == '#')
        return (1);
    return (0);
}