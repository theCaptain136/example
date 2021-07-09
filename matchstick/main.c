/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-pablo-elias.herrmann
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    loop_t *list = malloc(sizeof(loop_t));
    int size;
    int pos = 0;
    int amount = 0;

    list->who = 1;
    if (param_error(ac, av))
        return (84);
    size = my_getnbr(av[1]);
    list->max_take = my_getnbr(av[2]);
    list->top = malloc((sizeof(char))* (size * 2 + 2));
    list->map = creat_map(size);
    for (int i = 0; i <= size * 2; i++)
        list->top[i] = '*';
    list->who = loop(&pos, &amount, list);
    if (list->who == 0)
        return (0);
    after_game(list->who, list->map, list->top);
    return (((list->who == 1) * 2) + ((list->who == -1) * 1));
}

char **creat_map(int size)
{
    char **res = malloc((sizeof(char *)) * (size + 10));
    int border = size * 2 - 1;
    int a = 0;
    int  i = 0;

    for (i = 0; i < size; i++) {
        res[i] = malloc((sizeof(char)) * (border + 3));
        for (a = 0; a < border; a++) {
            if (a == (border) / 2 || (i > a - size && a > border / 2) || \
            (a + 1 >= size - i && a < size))
                res[i][a] = '|';
            else
                res[i][a] = ' ';
        }
        res[i][a] = '\0';
    }
    res[i] = NULL;
    return (res);
}

void rm_at_pos(char **map, int line, int nb, int max_take)
{
    int rm = 0;
    int l = line + 1;
    int size = my_strlen((map)[line]) - 1;

    if (nb > 0) {
        print_takes(1, nb, line);
    }
    if (has((map)[line]) == 0)
        return;
    for (int i = size; rm != nb && rm < l * 2 - 1 && rm < max_take; i--) {
        if ((map)[line][i] == '|') {
        (map)[line][i] = ' ';
        rm++;
        }
    }
}

void after_game(int who, char **map, char *top)
{
    if (who == 1) {
        print_manager(map, top);
        my_putstr("you are no match for me weak human!!!\n");
    }
    else {
        print_manager(map, top);
        my_putstr("you are litteraly a god!!!\n");
    }
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

void do_stuff(char **map, instruct_t *list, int max_take, int *op)
{
    list->max_take = max_take;
    list->nb = (*op == 1) * list->ones;
    ai_rm_at_pos(map, list, op);
    list->nb = ((*op == 2) * 1) * ((list->twos == 1) * 2);
    ai_rm_at_pos(map, list, op);
    list->nb = ((*op == 3) * 1) * ((list->twos == 1) * 1) * \
    (1 + (list->ones == 1) * 2);
    list->nb = ((*op == 3) * 1) * ((list->twos == 1) * 1) * \
    (1 + (list->ones == 1) * 2);
    ai_rm_at_pos(map, list, op);
    list->nb = ((*op == 4) * 1) * (((list->fours > 0) * 1) * \
    (((list->fours > 0) * 4)));
    ai_rm_at_pos(map, list, op);
}
