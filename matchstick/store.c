/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** store
*/

#include "my.h"

void last_turn_stuff(char **map, int i, int *lines)
{
    for (int a = 0; map[i][a] != '\0'; a++) {
        if (map[i][a] == '|') {
            *lines += 1;
            break;
        }
    }
}

int last_turn_other_stuff(char **map, int i)
{
    for (int a = 0; a < my_strlen(map[i]) - 2; a++) {
        if (map[i][a] == ' ' && map[i][a + 1] == '|' && \
            map[i][a + 2] == ' ') {
            return (2);
        }
    }
    return (0);
}

void over_count(char **map, int i, int *res)
{
    for (int a = 0; map[i][a] != '\0'; a++) {
        if (map[i][a] == '|')
            *res += 1;
    }
    return;
}