/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** print
*/

#include "my.h"

void print_takes(int player, int nb, int line)
{
    if (player == 1)
        my_putstr("Player removed ");
    if (player == -1)
        my_putstr("AI removed ");
    my_put_nbr(nb);
    my_putstr(" match(es) from line ");
    my_put_nbr(line + 1);
    my_putstr("\n");
}

void print_manager(char **map, char *top)
{
    my_putstr(top);
    my_putstr("\n");
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr("*");
        my_putstr(map[i]);
        my_putstr("*");
        my_putstr("\n");
    }
    my_putstr(top);
    if (over(map) != 0)
        my_putstr("\n");
    my_putstr("\n");
}

instruct_t *set_instruct(char **map)
{
    instruct_t *list = malloc(sizeof(instruct_t));

    for (int i = 0; (map)[i] != NULL; i++) {
        list->nim = count_line((map)[i]);
        list->fours += list->nim / 4;
        list->twos += (list->nim % 4) / 2;
        list->ones += list->nim % 2;
    }
    return (list);
}