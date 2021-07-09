/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** input
*/

#include "my.h"

int error_cases(int *pos, int *amount, int max_take, char **map)
{
    if (*amount > max_take) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max_take);
        my_putstr(" matches per turn\n");
        get_nbs(pos, amount, map, max_take);
        return (1);
    }
    if (*amount > count_line(map[*pos])) {
        my_putstr("Error: not enough matches on this line\n");
        get_nbs(pos, amount, map, max_take);
        return (1);
    }
    if (nb_error(*amount, max_take, *pos, map) == 1) {
        get_nbs(pos, amount, map, max_take);
        return (1);
    }
    return (0);
}

int pos_store(int s, int *pos, int max_take, char **map)
{
    if (s == -1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        new_pos(map, max_take, pos);
        return (1);
    }
    if ((my_strstrlen(map) < s || s == 0)) {
        my_putstr("Error: this line is out of range\n");
        new_pos(map, max_take, pos);
        return (1);
    }
    return (0);
}

void more_stuff_to_do(char **map, instruct_t *list, int max_take, int *op)
{
    list->nb = ((*op == 5) * 1) * (((list->fours > 0) * 1) * \
    (((list->fours > 0) * 3) + (list->twos * 2)));
    ai_rm_at_pos(map, list, op);
    list->nb = ((*op == 6) * 1) * (((list->fours > 0) * 1) * \
    (((list->fours > 0) * 2) + (list->twos * 4)));
    ai_rm_at_pos(map, list, op);
    list->nb = ((*op == 7) * 1) * (((list->fours > 0) * 1) * \
    (((list->fours > 0) * 1) + (list->ones * 2) + (list->twos * 4)));
    ai_rm_at_pos(map, list, op);
}