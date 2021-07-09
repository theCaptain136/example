/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

void switch_scene(sfRenderWindow *window, int *c, int prev)
{
    if (*c == 0 || *c == 2 || *c == 3 || *c == 7) {
        *c = 1;
        return;
    }
    if (*c == 1)
        *c = 2;
}

void start_menu(sfRenderWindow *window, int *c, int prev)
{
    *c = 0;
}

void restart(sfRenderWindow *window, int *c, int prev)
{
    *c = -1;
}

void end_game(sfRenderWindow *window, int *c, int prev)
{
    sfRenderWindow_close(window);
}

void go_to_htp(sfRenderWindow *window, int *c, int prev)
{
    *c = 5;
}