/*
** EPITECH PROJECT, 2021
** B-PSU-200-BER-2-1-bsmysokoban-pablo-elias.herrmann
** File description:
** map_tools
*/

#include "my.h"

void find_O(char **one, char **two)
{
    int i;
    int s;

    for (i = 0; one[i] != NULL; i++) {
        for (s = 0; one[i][s] != '\0'; s++) {
            write_O(one, two, i, s);
        }
    }
    return;
}

void write_O(char **one, char **two, int i, int s)
{
    if (one[i][s] == 'O') {
        if ((two)[i][s] == ' ')
            (two)[i][s] = 'O';
    }
}

int find_P(char **str, int *x, int *y)
{
    int res_x = 0;
    int res_y = 0;

    while (str[res_y] != NULL) {
        while (str[res_y][res_x] != '\0' && str[res_y][res_x] != 'P') {
            res_x++;
        }
        if (str[res_y][res_x] == 'P')
            break;
        res_x = 0;
        res_y++;
    }
    if (res_y == my_strstrlen(str))
        return (0);
    *x = res_x;
    *y = res_y;
    return (1);
}

int max_strlen(char **str)
{
    int res = 0;

    for (int i = 0; str[i] != NULL; i++) {
        if (my_strlen(str[i]) > res)
            res = my_strlen(str[i]);
    }
    return (res);
}