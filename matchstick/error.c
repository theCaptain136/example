/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** error
*/

#include "my.h"

int param_error(int ac, char **av)
{
    if (ac != 3)
        return (1);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100)
        return (1);
    if (my_getnbr(av[2]) <= 0)
        return (1);
    return (0);
}

int nb_error(int nb, int max_take, int pos, char **map)
{
    if (nb > max_take || pos >= my_strstrlen(map) || nb < 1 || pos + 1 < 1)
        return (1);
    if ((my_strstrlen(map) < pos))
        return (1);
    if ((nb > count_line(map[pos])))
        return (1);
    return (0);
}

void unsual_move(char **map, int *op, int max_take, instruct_t *t)
{
    for (int i = 0; (map)[i] != NULL; i++) {
        if (count_line((map)[i]) > 1) {
            t->i = i;
            t->nb = count_line((map)[i]) - 1;
            ai_rm_at_pos(map, t, op);
        }
    }
    return;
}

int last_turn(char **map)
{
    int lines = 0;

    for (int i = 0; map[i] != NULL; i++)
    last_turn_stuff(map, i, &lines);
    if (lines == 1)
        return (1);
    if (lines == 2)
    for (int i = 0; map[i] != NULL; i++)
    return ((last_turn_other_stuff(map, i) == 2) * 2 );
}

void rm_all(char **map, int line)
{

    for (int i = 0; (map)[line][i] != '\0'; i++)
        if ((map)[line][i] == '|')
                (map)[line][i] = ' ';
    return;
}