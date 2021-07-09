/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** my_ai
*/

#include "my.h"

void ai(char **map, int max_take)
{
    instruct_t *list = set_instruct(map);
    int op = 0;

    list->max_take = max_take;
    set_op(&op, list->ones, list->twos, list->fours);
    if (extra_cases(map, &op, list) == 1)
        return;
    ai_loop(map, list, max_take, op);
    if (op == -1)
        any(map, &op, max_take, list);
}

int count_line(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|')
            res++;
    }
    return (res);
}

int count_lines(char **map)
{
    int res = 0;

    for (int i = 0; map[i] != NULL; i++) {
        if (count_line(map[i]) > 0)
            res++;
    }
    return (res);
}

void any(char **map, int *op, int max_take, instruct_t *t)
{
    for (int i = my_strstrlen(map) - 1; i >= 0; i--) {
        for (int a = my_strlen((map)[i]) - 1; a >= 0; a--)
            if ((map)[i][a] == '|') {
                t->i = i;
                t->nb = 1;
                ai_rm_at_pos(map, t, op);
                return;
            }
    }
    return;
}

int low_stacks(char **map)
{
    int res = 0;

    for (int i = 0; (map)[i] != NULL; i++)
        for (int a = 0; a < my_strlen(map[i]) - 2; a++)
            if (map[i][a] == ' ' && map[i][a + 1] == '|' && \
            map[i][a + 2] == ' ')
                res++;
    if (map[my_strstrlen(map) - 1][0] == '|' && \
    map[my_strstrlen(map) - 1][1] == ' ')
        res++;
    return (res);
}