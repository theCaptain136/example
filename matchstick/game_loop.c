/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** game_loop
*/

#include "my.h"

int loop(int *pos, int *amount, loop_t *list)
{
    while (1) {
        print_manager(list->map, list->top);
        if (list->who == 1) {
            my_putstr("Your turn:\n");
            if (get_nbs(pos, amount, list->map, list->max_take) == 0)
                return (0);
            rm_at_pos(list->map, *pos, *amount, list->max_take);
        }
        else {
            my_putstr("AI's turn...\n");
            ai(list->map, list->max_take);
        }
        if (over(list->map) == 0)
            break;
        list->who *= -1;
    }
    return (list->who);
}

void ai_loop(char **map, instruct_t *list, int max_take, int op)
{
    for (int i = 0; (map)[i] != NULL; i++) {
        list->nim = count_line((map)[i]);
        list->fours = list->nim / 4;
        list->twos = (list->nim % 4) / 2;
        list->ones = list->nim % 2;
        if (op == -1 && list->fours > 1) {
            list->nb = 8;
            list->i = i;
            ai_rm_at_pos(map, list, &op);
        }
        list->i = i;
        do_stuff(map, list, max_take, &op);
    }
}