/*
** EPITECH PROJECT, 2021
** B-PSU-200-BER-2-1-mysokoban-pablo-elias.herrmann
** File description:
** move
*/

#include "my.h"

void get_input(map_t *maps)
{
    int mv = 0;

    mv = getch();
    switch (mv) {
        case 65: mv_up(maps->map); break;
        case 68: mv_left(maps->map); break;
        case 66: mv_down(maps->map); break;
        case 67: mv_right(maps->map); break;
        case 32: maps->map = my_arr_cpy(maps->tmp, maps->map);
    }
}

void mv_right(char **map)
{
    int x;
    int y;

    if (error_right(map, &x, &y) == 1)
        return;
    else if ((map)[y][x + 1] == 'X') {
        if (my_strlen((map)[y]) <= x + 2 || (map)[y][x + 2] == '#' || \
        (map)[y][x + 2] == 'X')
            return;
        (map)[y][x + 1] = ' ';
        (map)[y][x + 2] = 'X';
    }
    (map)[y][x] = ' ';
    (map)[y][x + 1] = 'P';
    return;
}

void mv_left(char **map)
{
    int x;
    int y;

    if (error_left(map, &x, &y))
        return;
    else if ((map)[y][x - 1] == 'X') {
        if (x - 2 < 0 || (map)[y][x - 2] == '#' || (map)[y][x - 2] == 'X')
            return;
        (map)[y][x - 1] = ' ';
        (map)[y][x - 2] = 'X';
    }
    (map)[y][x] = ' ';
    (map)[y][x - 1] = 'P';
    return;
}

void mv_up(char **map)
{
    int x;
    int y;

    if (error_up(map, &x, &y))
        return;
    else if ((map)[y - 1][x] == 'X') {
        if (y - 2 < 0 || x >= my_strlen((map)[y - 2]) || \
        (map)[y - 2][x] == '#' || (map)[y - 2][x] == 'X')
            return;
        (map)[y - 1][x] = ' ';
        (map)[y - 2][x] = 'X';
    }
    (map)[y][x] = ' ';
    (map)[y - 1][x] = 'P';
    return;
}

void mv_down(char **map)
{
    int x;
    int y;

    if (error_down(map, &x, &y))
        return;
    else if ((map)[y + 1][x] == 'X') {
        if (y + 2 >= my_strstrlen(map) || my_strlen((map)[y + 2]) <= x || \
        (map)[y + 2][x] == '#' || (map)[y + 2][x] == 'X')
            return;
        (map)[y + 1][x] = ' ';
        (map)[y + 2][x] = 'X';
    }
    (map)[y][x] = ' ';
    (map)[y + 1][x] = 'P';
    return;
}