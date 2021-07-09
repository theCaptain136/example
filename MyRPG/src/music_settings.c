/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void click_music(sfMouseButtonEvent ev, sfRenderWindow *win, scene_t **sc)
{
    sfVector2f mpos = {ev.x, ev.y};
    sfRectangleShape *rollover;

    for (int i = 0; sc[6]->music_b[i] != NULL; i++) {
        if (button_is_clicked(*sc[6]->music_b[i], mpos) == 1) {
            rollover = sfRectangleShape_copy(sc[6]->music_b[i]->rect);
            sfRectangleShape_setFillColor(rollover, \
                            sc[6]->music_b[i]->colors.clicked);
            sfRenderWindow_drawRectangleShape(win, rollover, NULL);
            sfRenderWindow_drawText(win, sc[6]->music_b[i]->name, NULL);
            sc[6]->music_b[i]->m_callback(&sc[1]->music_playing, \
                sc[1]->bg_music, sc[1]->game->sound_eff);
        }
    }
}

void rollover_mb(sfRenderWindow *window, scene_t *sc)
{
    sfVector2i mouse = {0, 0};
    sfVector2f mousef = {0, 0};
    sfRectangleShape *rollover;

    mouse = sfMouse_getPositionRenderWindow(window);
    mousef.x = (float)mouse.x;
    mousef.y = (float)mouse.y;
    for (int i = 0; sc->music_b[i] != NULL; i++) {
        if (button_is_clicked(*sc->music_b[i], mousef) == 1) {
            rollover = sfRectangleShape_copy(sc->music_b[i]->rect);
            sfRectangleShape_setFillColor(rollover, \
                            sc->music_b[i]->colors.rollover);
            sfRenderWindow_drawRectangleShape(window, rollover, NULL);
            sfRenderWindow_drawText(window, sc->music_b[i]->name, NULL);
        }
    }
}

void mute_keys(sfEvent event, scene_t **sc)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyZ) {
            stop_music(&sc[1]->music_playing, sc[1]->bg_music, \
                sc[1]->game->sound_eff);
            mute_se(&sc[1]->music_playing, sc[1]->bg_music, \
                sc[1]->game->sound_eff);
        }
        if (event.key.code == sfKeyH) {
            start_music(&sc[1]->music_playing, sc[1]->bg_music, \
                sc[1]->game->sound_eff);
            unmute_se(&sc[1]->music_playing, sc[1]->bg_music, \
                sc[1]->game->sound_eff);
        }
    }
}

void music_settings(sfRenderWindow *window, scene_t **sc, sfEvent event)
{
    mute_keys(event, sc);
    if (sc[1]->current_sc != 6)
        return;
    rollover_mb(window, sc[6]);
    if (event.type == sfEvtMouseButtonPressed)
        click_music(event.mouseButton, window, sc);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue || \
        sfMouse_isButtonPressed(sfMouseMiddle) == sfTrue || \
        sfMouse_isButtonPressed(sfMouseRight) == sfTrue) {
        change_volume(sfMouse_getPositionRenderWindow(window), sc, \
        (sfVector2f){1160, 585});
    }
}