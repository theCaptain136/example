/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** aggro_store
*/

#include "my.h"

void step_one_two(int dx, int dy, enemy_t *tmp, level_t *l)
{
    if (dx > 0 && dy > 0)
        step_one(dx, dy, tmp, l);
    if (dx > 0 && dy < 0)
        step_two(dx, dy, tmp, l);
}

level_t *set_lvl_stor(level_t *lev)
{
    lev->count = 0;
    lev->brush = 0;
    lev->scale = 1;
    lev->tool = -1;
    lev->load = 1;
    lev->timer = sfClock_create();
    lev->timer2 = sfClock_create();
    lev->timer3 = sfClock_create();
    lev->timer4 = sfClock_create();
    return (lev);
}

void set_lvl_2(level_t *lev)
{
    lev->map->scale = 1;
    lev->map->x = 1920 / 2;
    lev->map->y = 150;
}