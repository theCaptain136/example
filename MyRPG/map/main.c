/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myworld-pablo-elias.herrmann
** File description:
** main
*/

#include "./my.h"

void clear(int **map, level_t *l)
{
    for (int i = 0; i <= pow((double)l->MAP_size, 2.0); i++) {
        (*map)[i] = 1;
    }
}

int *load_map(int size)
{
    int *map = malloc((sizeof(int)) * (pow((double)(int)size, 2.0) + 100));
    int i = 0;

    for (i; i <= pow((double)size, 2.0); i++) {
        map[i] = 1;
    }
    map[i] = -1;
    map[0] = 0;
    return (map);
}

int zero_point_two_five_clock(sfTime clock, sfClock **time)
{
    if (clock.microseconds > 1000000 / 20) {
        sfClock_restart(*time);
        return (1);
    }
    return (0);
}

int *level(int *map, level_t *l)
{
    for (int i = 1; i <= pow((double)l->MAP_size, 2.0); i++) {
        if (map[i] < 0)
            map[i] = 0;
    }
    map[0] = 0;
    return (map);
}