/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** aggro
*/

#include "my.h"

int aggro(level_t *l)
{
    if (l->list == NULL || l->list->size == 0)
        return (0);
    enemy_t *tmp = l->list->start;
    int x = 0;
    int y = 0;

    for (int i = 0; i < l->list->size; i++) {
        x = l->map->x + tmp->x / l->map->scale;
        y = l->map->y + tmp->y / l->map->scale;
        if (n_distance(x, y, hero_x, hero_y) < tmp->radius * 50 /
        l->map->scale) {
            step(tmp, x, y, l);
        }
        tmp = tmp->next;
    }
    return (0);
}

float n_distance(int x1, int y1, int x2, int y2)
{
    int x = x2 - x1;
    int y = y2 - y1;
    float res = 0;

    y = y * y;
    x = x * x;
    res = sqrt(x + y);
    return (res);
}

void pure_convex(sfRenderWindow **window, hero_t *hero, map_t *map, int range)
{
    sfConvexShape *convex = sfConvexShape_create();
    int new_rg = -(range * (50 / map->scale));

    sfConvexShape_setPointCount(convex, 4);
    sfConvexShape_setPoint(convex, 0, (sfVector2f){-40 / map->scale, 0});
    sfConvexShape_setPoint(convex, 1, (sfVector2f){40 / map->scale, 0});
    sfConvexShape_setPoint(convex, 2, (sfVector2f){40 / map->scale, new_rg});
    sfConvexShape_setPoint(convex, 3, (sfVector2f){-40 / map->scale, new_rg});
    sfConvexShape_setOutlineColor(convex, sfRed);
    sfConvexShape_setOutlineThickness(convex, 2.0);
    sfConvexShape_setFillColor(convex, sfColor_fromRGBA((sfUint8)255, \
        (sfUint8)255, (sfUint8)255, (sfUint8)0));
    sfConvexShape_setOrigin(convex, (sfVector2f){0, new_rg});
    sfConvexShape_setPosition(convex, (sfVector2f){hero_x, hero_y});
    sfConvexShape_setRotation(convex, ((hero->aim == 4 || hero->aim == -1) \
        * 0.0) + ((hero->aim == 2) * 180.0) + ((hero->aim == 1) * 90.0) + \
        ((hero->aim == 3) * 270.0));
    sfRenderWindow_drawConvexShape(*window, convex, NULL);
    sfConvexShape_destroy(convex);
}