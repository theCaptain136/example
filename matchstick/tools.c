/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** tools
*/

#include "my.h"

int has(char *str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] ==  '|')
            res++;
    }
    if (res > 0)
        return (1);
    return (0);
}

int input_error(char *str)
{
    int res = 0;

    if (str[0] == '\n')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] <= '9' && str[i] >= '0') || str[i] == '\n')
            res++;
    }
    if (res == my_strlen(str))
        return (0);
    return (1);
}

int get_nbs(int *pos, int *amount, char **map, int max_take)
{
    if (new_pos(map, max_take, pos) == 0 || \
    0 == new_amount(map, max_take, amount))
        return (0);
    if (*amount == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        get_nbs(pos, amount, map, max_take);
        return (1);
    }
    if (*amount < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        get_nbs(pos, amount, map, max_take);
        return (1);
    }
    if (error_cases(pos, amount, max_take, map) == 1)
        return (1);
    return (1);
}

int new_amount(char **map, int max_take, int *amount)
{
    char *str = NULL;
    size_t n = 0;
    int s = -1;

    my_putstr("Matches: ");
    if (getline(&str, &n, stdin) == -1) {
        return (0);
    }
    if (input_error(str) == 0)
        s = my_getnbr(str);
    *amount = s;
    return (1);
}

int new_pos(char **map, int max_take, int *pos)
{
    char *str = NULL;
    size_t n = 0;
    int s = -1;

    my_putstr("Line: ");
    if (getline(&str, &n, stdin) == -1) {
        return (0);
    }
    if (input_error(str) == 0)
        s = my_getnbr(str);
    if (pos_store(s, pos, max_take, map) == 1)
        return (1);
    *pos = s - 1;
    return (1);
}