/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void pause_music(sfMouseButtonEvent ev, scene_t **scenes)
{
    if (scenes[1]->current_sc == 6 || scenes[1]->current_sc == 7 || \
        scenes[1]->current_sc == 8)
        return;
    if (ev.x < 120 && ev.x >= 20 && ev.y < 1050 && ev.y >= 950) {
        scenes[1]->prev_m = scenes[1]->current_sc;
        scenes[1]->current_sc = 6;
    }
}