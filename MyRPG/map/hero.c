/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "my.h"

void draw_circle(level_t *lev)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 30.0);
    sfCircleShape_setOrigin(circle, (sfVector2f){30, 30});
    sfCircleShape_setOutlineColor(circle, sfBlack);
    sfCircleShape_setFillColor(circle, sfColor_fromRGB(((lev->count2 < 25) \
        * 200), (lev->count2 > lev->hero_stat->atk_speed) * 200, 0));
    sfCircleShape_setPosition(circle, (sfVector2f){hero_x, hero_y - 220});
    sfRenderWindow_drawCircleShape(lev->window, circle, NULL);
    sfCircleShape_destroy(circle);
}

void set_sprite(level_t *lev)
{
    sfIntRect *rect = set_rect();

    rect->left += (lev->count % 3) * 48;
    if (lev->hero_stat->direction == 2)
        rect->top += 1 * 48;
    if (lev->hero_stat->direction == 4)
        rect->top += 2 * 48;
    if (lev->hero_stat->direction == 3 || lev->hero_stat->direction == -1)
        rect->top += 0;
    if (lev->hero_stat->direction == 1)
        rect->top += 3 * 48;
    sprite_set(&lev->window, lev->scale, rect);
    free(rect);
}

void hp_bar_gr(level_t *lv)
{
    sfConvexShape_setPointCount(lv->hero_stat->hp_bar1, 4);
    sfConvexShape_setPoint(lv->hero_stat->hp_bar1, 0, (sfVector2f){hero_x + \
        50 / lv->map->scale, hero_y - 250 / lv->map->scale});
    sfConvexShape_setPoint(lv->hero_stat->hp_bar1, 1, (sfVector2f){hero_x - \
        55 / lv->map->scale, hero_y - 250 / lv->map->scale});
    sfConvexShape_setPoint(lv->hero_stat->hp_bar1, 2, (sfVector2f){hero_x - \
        55 / lv->map->scale, hero_y - 230 / lv->map->scale});
    sfConvexShape_setPoint(lv->hero_stat->hp_bar1, 3, (sfVector2f){hero_x + \
        50 / lv->map->scale, hero_y - 230 / lv->map->scale});
    sfConvexShape_setFillColor(lv->hero_stat->hp_bar1, sfRed);
    sfRenderWindow_drawConvexShape(lv->window, lv->hero_stat->hp_bar1, NULL);
}

void hp_bar_red(level_t *lv, float hp, int x, int y)
{
    sfConvexShape_setPointCount(lv->hero_stat->hp_bar2, 4);
    sfConvexShape_setPoint(lv->hero_stat->hp_bar2, 0, \
        (sfVector2f){x, y - 20});
    sfConvexShape_setPoint(lv->hero_stat->hp_bar2, 1, \
        (sfVector2f){x - 110 * (lv->hero_stat->hp ? hp : 0), y - 20});
    sfConvexShape_setPoint(lv->hero_stat->hp_bar2, 2, \
        (sfVector2f){x - 110 * (lv->hero_stat->hp ? hp : 0), y});
    sfConvexShape_setPoint(lv->hero_stat->hp_bar2, 3, (sfVector2f){x, y});
    sfConvexShape_setFillColor(lv->hero_stat->hp_bar2, sfGreen);
    sfRenderWindow_drawConvexShape(lv->window, lv->hero_stat->hp_bar2, NULL);
}

void hero(level_t *lev)
{
    int x = 0;
    int y = 0;

    set_sprite(lev);
    hp_bar_gr(lev);
    float hp = (float)lev->hero_stat->hp / lev->hero_stat->max_hp;
    x = hero_x + 50 / lev->map->scale;
    y = hero_y - 230 / lev->map->scale;
    hp_bar_red(lev, hp, x, y);
}