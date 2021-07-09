/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "my.h"

enemy_t *init_enem(enemy_t *res, int indx, sfVector2i vector, sfTexture *tex)
{
    res->map_index = indx;
    res->sprite = sfSprite_create();
    sfSprite_setTexture(res->sprite, tex, false);
    res->hp_bar1 = sfConvexShape_create();
    res->hp_bar2 = sfConvexShape_create();
    res->direction = -1;
    res->size = rand() % 2 + 2;
    res->x = vector.x;
    res->y = vector.y;
    res->map_index = 0;
    res->previous = NULL;
    res->next = NULL;
    res->attack = 2000000;
    res->glock = sfClock_create();
    return (res);
}