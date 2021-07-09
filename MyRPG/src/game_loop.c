/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void draw_game_freeze(level_t *l)
{
    draw_map(&l->window, l);
    interact_with_npc(l);
    draw_enemy(l->list, l);
    hero(l);
}

void draw_menu_but(scene_t **scenes, sfRenderWindow *window)
{
    sfRectangleShape *tmp;

    if (scenes[1]->current_sc != 2 && scenes[1]->current_sc != 3 && \
        scenes[1]->current_sc != 4)
        return;
    for (int i = 0; scenes[1]->buttons[i] != NULL; i++) {
        tmp = scenes[1]->buttons[i]->rect;
        sfRectangleShape_setFillColor(tmp, \
                    scenes[1]->buttons[i]->colors.normal);
        sfRenderWindow_drawRectangleShape(window, tmp, NULL);
        sfRenderWindow_drawText(window, scenes[1]->buttons[i]->name, NULL);
    }
}

void draw_bg(sfRenderWindow *win, scene_t **sc)
{
    if (sc[1]->current_sc == 2 || sc[1]->current_sc == 3 || \
        sc[1]->current_sc == 4 || sc[1]->current_sc == 7 || \
        sc[1]->current_sc == 8) {
        draw_game_freeze(sc[1]->game);
        draw_menu_but(sc, win);
        draw_ui(win, sc);
        draw_menu(win, sc, 1);
    }
    if (sc[1]->current_sc == 8) {
        draw_scene(win, sc);
        draw_status(win, sc);
    }
    if (sc[1]->current_sc == 7) {
        draw_scene(win, sc);
        draw_inventory(win, sc);
    }
    if (sc[1]->current_sc == 9) {
        draw_scene(win, sc);
        draw_shortcuts(win);
    }
}

void draw_cur(sfRenderWindow *win, scene_t **sc, sfSprite *set)
{
    change_level(sc, win);
    if (sc[1]->game->lvl == 5)
        return;
    sfRenderWindow_clear(win, sfBlack);
    if (sc[1]->current_sc == 1) {
        draw_level(sc[1]->game);
        draw_ui(win, sc);
    }
    draw_scene(win, sc);
    draw_bg(win, sc);
    if (sc[1]->current_sc == 6)
        volume_controller(win, sc);
    event(win, sc, set);
    if (sc[1]->current_sc != 6 && sc[1]->current_sc != 7 && \
        sc[1]->current_sc != 8)
        sfRenderWindow_drawSprite(win, set, NULL);
    sfRenderWindow_display(win);
}

int game_loop(sfRenderWindow *window, scene_t **scenes, sfSprite *set)
{
    scenes[1]->game = set_level(window, "map/maps/map1", 1);

    if (scenes[1]->game == NULL)
        return (-1);
    while (sfRenderWindow_isOpen(window) && scenes[1]->game->lvl <= 4 && \
        scenes[1]->game->hero_stat->hp > 0) {
        draw_cur(window, scenes, set);
    }
    if (scenes[1]->game->hero_stat->hp == 0)
        looser(scenes, window, set);
    else
        winner(scenes, window, set);
    return (0);
}