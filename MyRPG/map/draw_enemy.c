/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "my.h"

void convex_one(enemy_t *tmp, level_t *l, int x, int y)
{
    sfConvexShape_setPointCount(tmp->hp_bar1, 4);
    sfConvexShape_setPoint(tmp->hp_bar1, 0, (sfVector2f){x, y - 20});
    sfConvexShape_setPoint(tmp->hp_bar1, 1, \
    (sfVector2f){x - 100 / l->map->scale, y - 20});
    sfConvexShape_setPoint(tmp->hp_bar1, 2, \
    (sfVector2f){x - 100 / l->map->scale, y});
    sfConvexShape_setPoint(tmp->hp_bar1, 3, (sfVector2f){x, y});
    sfConvexShape_setFillColor(tmp->hp_bar1, sfRed);
    sfRenderWindow_drawConvexShape(l->window, tmp->hp_bar1, NULL);
}

void convex_two(enemy_t *tmp, level_t *l, int x, int y)
{
    float hp = (float)tmp->hp / tmp->max_hp;
    sfConvexShape_setPointCount(tmp->hp_bar2, 4);
    sfConvexShape_setPoint(tmp->hp_bar2, 0, (sfVector2f){x, y - 20});
    sfConvexShape_setPoint(tmp->hp_bar2, 1, (sfVector2f){x - \
        (100 * (tmp->hp ? hp : 0)) / l->map->scale, y - 20});
    sfConvexShape_setPoint(tmp->hp_bar2, 2, (sfVector2f){x - \
        (100 * (tmp->hp ? hp : 0)) / l->map->scale, y});
    sfConvexShape_setPoint(tmp->hp_bar2, 3, (sfVector2f){x, y});
    sfConvexShape_setFillColor(tmp->hp_bar2, sfGreen);
    sfRenderWindow_drawConvexShape(l->window, tmp->hp_bar2, NULL);
}

void set_texture(enemy_t *tmp, level_t *l)
{
    if (tmp->direction == 1) {
        sfSprite_setTextureRect(tmp->sprite, \
        (sfIntRect){48 * (l->count3 % 3), 144, 48, 48});
    }
    if (tmp->direction == 2) {
        sfSprite_setTextureRect(tmp->sprite, \
        (sfIntRect){48 * (l->count3 % 3), 48, 48, 48});
    }
    if (tmp->direction == 3 || tmp->direction == -1) {
        sfSprite_setTextureRect(tmp->sprite, \
        (sfIntRect){48 * (l->count3 % 3), 0, 48, 48});
    }
    if (tmp->direction == 4) {
        sfSprite_setTextureRect(tmp->sprite, \
        (sfIntRect){48 * (l->count3 % 3), 96, 48, 48});
    }
}

void draw_enemy2(enemy_t *tmp, level_t *l)
{
    int x = 0;
    int y = 0;

    set_texture(tmp, l);
    sfSprite_setOrigin(tmp->sprite, (sfVector2f){24.0, 48.0});
    sfSprite_setScale(tmp->sprite, (sfVector2f){tmp->size, tmp->size});
    x = l->map->x + tmp->x / l->map->scale + 50 / l->map->scale;
    y = l->map->y + tmp->y / l->map->scale - 120 / l->map->scale;
    sfSprite_setPosition(tmp->sprite, \
        (sfVector2f){x - 50 / l->map->scale, y + 120 / l->map->scale});
    sfRenderWindow_drawSprite(l->window, tmp->sprite, NULL);
    convex_one(tmp, l, x, y);
    convex_two(tmp, l, x, y);
}

void draw_enemy(ll_enemy *list, level_t *l)
{
    enemy_t *stor = NULL;
    enemy_t *tmp = NULL;

    if (list == NULL)
        return;
    tmp = list->start;
    while (tmp != NULL) {
        if (tmp->hp <= 0) {
            l->hero_stat->kills += 1;
            l->hero_stat->xp += 3 * l->lvl;
            stor = tmp->next;
            delete_node(list, tmp);
            sfClock_destroy(tmp->glock);
            sfConvexShape_destroy(tmp->hp_bar1);
            sfConvexShape_destroy(tmp->hp_bar2);
            sfSprite_destroy(tmp->sprite);
            free(tmp);
            tmp = stor;
        } else {
            draw_enemy2(tmp, l);
            tmp = tmp->next;
        }
    }
    return;
}