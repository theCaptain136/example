/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void clicks(sfMouseButtonEvent ev, sfRenderWindow *win, scene_t **sc, \
                                                    sfSprite *set)
{
    sfVector2f mpos = {ev.x, ev.y};
    int cur = sc[1]->current_sc;
    sfRectangleShape *rollover;

    for (int i = 0; sc[cur]->buttons[i] != NULL; i++) {
        if (button_is_clicked(*sc[cur]->buttons[i], mpos) == 1) {
            rollover = sfRectangleShape_copy(sc[cur]->buttons[i]->rect);
            sfRectangleShape_setFillColor(rollover, \
                            sc[cur]->buttons[i]->colors.clicked);
            sfRenderWindow_drawRectangleShape(win, rollover, NULL);
            sfRenderWindow_drawText(win, sc[cur]->buttons[i]->name, NULL);
            sc[cur]->buttons[i]->callback(win, &cur, sc[1]->prev_m);
            sc[1]->current_sc = cur;
            if (cur < 0 || cur == 5) {
                restart_game(sc, win, set);
                break;
            }
        }
    }
}

void check_mouse_pos(sfRenderWindow *window, scene_t **sc)
{
    sfVector2i mouse = {0, 0};
    sfVector2f mousef = {0, 0};
    int cur = sc[1]->current_sc;
    sfRectangleShape *rollover;

    mouse = sfMouse_getPositionRenderWindow(window);
    mousef.x = (float)mouse.x;
    mousef.y = (float)mouse.y;
    for (int i = 0; sc[cur]->buttons[i] != NULL; i++) {
        if (button_is_clicked(*sc[cur]->buttons[i], mousef) == 1) {
            rollover = sfRectangleShape_copy(sc[cur]->buttons[i]->rect);
            sfRectangleShape_setFillColor(rollover, \
                            sc[cur]->buttons[i]->colors.rollover);
            sfRenderWindow_drawRectangleShape(window, rollover, NULL);
            sfRenderWindow_drawText(window, sc[cur]->buttons[i]->name, NULL);
        }
    }
}

void cases(sfRenderWindow *win, scene_t **sc, sfSprite *set, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(win);
    if (sc[1]->current_sc == 1 && event.type == sfEvtKeyPressed && \
        event.key.code == sfKeyEscape) {
        switch_scene(win, &sc[1]->current_sc, sc[1]->prev_m);
    }
    if (sc[1]->current_sc == 1 && event.type == sfEvtKeyPressed && \
        event.key.code == sfKeyM) {
        sc[1]->prev_m = sc[1]->current_sc;
        sc[1]->current_sc = 8;
    }
    check_inventor_btn(win, event, sc);
    check_mouse_pos(win, sc);
    if (event.type == sfEvtMouseButtonPressed) {
        clicks(event.mouseButton, win, sc, set);
        pause_music(event.mouseButton, sc);
    }
    music_settings(win, sc, event);
}

void cheat_code(scene_t **sc, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        sc[1]->game->lvl++;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
        sc[1]->game->hero_stat->hp += 100;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyO)
        sc[1]->game->hero_stat->dmg += 20;
}

void event(sfRenderWindow *window, scene_t **scenes, sfSprite *set)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        cases(window, scenes, set, event);
        cheat_code(scenes, event);
    }
}