/*
** EPITECH PROJECT, 2021
** B-PSU-200-BER-2-1-mysokoban-pablo-elias.herrmann
** File description:
** win_or_lose
*/

#include "my.h"

int done(char **str, char **tmp)
{
    int i = 0;
    int res = 0;

    for (i = 0; str[i] != NULL; i++) {
        X_check(str, tmp, i, &res);
    }
    if (res == boxes(tmp))
        return (1);
    return (0);
}

int lost(map_t *maps)
{
    int res = 0;

    for (int i = 0; maps->map[i] != NULL; i++) {
        for (int a = 0; maps->map[i][a] != '\0'; a++) {
            count_cornered(maps, i, a, &res);
        }
    }
    if (res == boxes(maps->map))
        return (1);
    return (0);
}

void count_cornered(map_t *maps, int i, int a, int *res)
{
    if (maps->map[i][a] == 'X' && maps->tmp[i][a] != 'O') {
        if (cornered(maps->map, i, a) == 1) {
            *res = *res + 1;
        }
    }
    return;
}

int cornered(char **map, int x, int y)
{
    if (other_corner(map, x, y) == 1)
        return (1);
    else if ((map[x][y - 1] == '#' || map[x][y - 1] == 'X') && \
    (map[x - 1][y] == '#' || map[x - 1][y] == 'X'))
        return (1);
    return (0);
}

int other_corner(char **map, int x, int y)
{
    if (((map[x][y + 1] == '#' || map[x][y + 1] == 'X' ) && \
    (map[x + 1][y] == '#' || map[x + 1][y] == 'X')))
        return (1);
    else if ((map[x][y + 1] == '#' || map[x][y + 1] == 'X') && \
    (map[x - 1][y] == '#' || map[x - 1][y] == 'X'))
        return (1);
    else if ((map[x][y - 1] == '#' || map[x][y - 1] == 'X') && \
    (map[x + 1][y] == '#' || map[x + 1][y] == 'X'))
        return (1);
    return (0);
}