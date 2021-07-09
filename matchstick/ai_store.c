/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** ai_store
*/

#include "my.h"

int over(char **map)
{
    int res = 0;

    for (int i = 0; map[i] != NULL; i++) {
        over_count(map, i, &res);
    }
    return (res);
}

void set_op(int *op, int ones, int twos, int fours)
{
    if (fours % 2 == 1)
        *op += 4;
    if (twos % 2 == 1)
        *op += 2;
    if (ones % 2 == 1)
        *op += 1;
    maintain_symetry(op, ones, twos, fours);
    return;
}

void maintain_symetry(int *op, int ones, int twos, int fours)
{
    if (ones % 2 == 0 && twos % 2 == 0 && fours % 2 == 0)
        *op = -1;
    return;
}

void ai_rm_at_pos(char **map, instruct_t *t, int *op)
{
    int rm = 0;
    int l = t->i + 1;
    int size = my_strlen((map)[t->i]) - 1;

    if (t->nb > t->max_take) {
        any(map, op, t->max_take, t);
        return;
    }
    if (t->nb > 0)
        *op = 0;
    if (t->nb > 0)
        print_takes(-1, t->nb, t->i);
    if (has((map)[t->i]) == 0)
        return;
    for (int i = size; rm != t->nb && rm < l * 2 - 1 && rm < t->max_take; i--) {
        if ((map)[t->i][i] == '|') {
        (map)[t->i][i] = ' ';
        rm++;
        }
    }
}

int extra_cases(char **map, int *op, instruct_t *t)
{
    if (low_stacks(map) + 1 == count_lines(map) && \
    count_lines(map) % 2 == 0) {
        for (int i = 0; (map)[i] != NULL; i++) {
            if (count_line((map)[i]) > 1) {
                t->i = i;
                t->nb = count_line((map)[i]);
                ai_rm_at_pos(map, t, op);
                return (1);
            }
        }
        return (1);
    }
    if (low_stacks(map) + 1 == count_lines(map) && \
    count_lines(map) % 2 == 1) {
        unsual_move(map, op, t->max_take, t);
        return (1);
    }
    return (0);
}