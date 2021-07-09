/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    WINDOW *win;
    int a;
    int b;
    map_t *maps = malloc(sizeof(map_t));

    maps->map = load_2d_arr(av[1]);
    maps->tmp = load_2d_arr(av[1]);
    if (error(ac, av, maps->map) == 1)
        return (84);
    timeout(-1);
    keypad(stdscr, TRUE);
    noecho();
    a = my_strstrlen(maps->map);
    b = x_center(maps->map);
    win = initscr();
    cbreak();
    if (main_loop(maps, win, a, b) == 1)
        return (1);
    return (0);
}

int main_loop(map_t *maps, WINDOW *win, int a, int b)
{
    while (true) {
        clear();
        print_manager(maps, win, a, b);
        refresh();
        if (done(maps->map, maps->tmp) == 1) {
            endwin();
            return (0);
        }
        if (lost(maps) == 1) {
            endwin();
            return (1);
        }
        get_input(maps);
        find_O(maps->tmp, maps->map);
    }
}

int boxes(char **str)
{
    int res = 0;

    for (int i = 0; str[i] != NULL; i++) {
        box_counter(str, i, &res);
    }
    return (res);
}

void box_counter(char **str, int i, int *res)
{
    for (int a = 0; str[i][a] != '\0'; a++) {
        if (str[i][a] == 'X')
            *res = *res + 1;
    }
}

void print_manager(map_t *maps, WINDOW *win, int a, int b)
{
    int x = 0;
    int y = 0;
    getmaxyx(win, y, x);
    if (y < my_strstrlen(maps->map) || max_strlen(maps->map) > x) {
        mvprintw((y / 2), (x / 2) - 9, "terminal too small");
    }
    else {
        for (int i = 0; maps->map[i] != NULL; i++)
            mvprintw(((y / 2) - (a / 2)) + i, ((x / 2) - (b / 2)), \
            "%s\n", maps->map[i]);
    }
}