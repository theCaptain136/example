/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void closing_ev(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void next_level_msg(sfRenderWindow *win, scene_t **sc)
{
    sfVector2f pos = {600, 400};
    sfClock *cl = sfClock_create();
    char *msg = malloc(sizeof(char) * 80);

    my_strcpy(msg, "You accomplished a level.\n Can you finish");
    my_strcat_j(msg, " the next\n\t\tone as well?");
    while (sfRenderWindow_isOpen(win) && \
        sfClock_getElapsedTime(cl).microseconds <= 4000000) {
        sfRenderWindow_clear(win, sfBlack);
        closing_ev(win);
        draw_game_freeze(sc[1]->game);
        draw_menu_but(sc, win);
        draw_ui(win, sc);
        draw_menu(win, sc, 0);
        sfRenderWindow_drawSprite(win, sc[8]->objs->start->sprite, NULL);
        draw_text_w(win, pos, msg, 70);
        sfRenderWindow_display(win);
    }
    free (msg);
    sfClock_destroy(cl);
}