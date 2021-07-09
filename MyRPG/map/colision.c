/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** colision
*/

#include "my.h"

void else_case_up(enemy_t *tmp, level_t *l, sfVector2i c1, sfVector2i c2)
{
    if ((l->map->map[get_pos(l->map, c1.x, c1.y, l)] != 0)) {
        tmp->x -= 4 / l->map->scale;
        tmp->y += 2 / l->map->scale;
    }
    else if (l->map->map[get_pos(l->map, c2.x, c2.y, l)] != 0) {
        tmp->x += 4 / l->map->scale;
        tmp->y += 2 / l->map->scale;
    }
}

void colision_up(enemy_t *tmp, level_t *l)
{
    sfVector2i nmy = {l->map->x + (tmp->x / l->map->scale), l->map->y +\
    (tmp->y / l->map->scale)};
    sfVector2i c1 = {nmy.x - 25 / l->map->scale, nmy.y + (tmp->speed * \
    2) / l->map->scale};
    sfVector2i c2 = {nmy.x + 25 / l->map->scale, nmy.y + (tmp->speed * \
    2) / l->map->scale};
    sfVector2i c3 = {nmy.x, nmy.y + (tmp->speed * 2) / l->map->scale};

        if (tmp->mvmnt_type == 1 || l->map->map[get_pos(l->map, c3.x, c3.y, \
        l)] != 0)
            tmp->y += tmp->speed / l->map->scale;
        else
            else_case_up(tmp, l, c1, c2);
}

void else_case_right(enemy_t *tmp, level_t *l, sfVector2i c1, sfVector2i c2)
{
    if ((l->map->map[get_pos(l->map, c1.x, c1.y, l)] != 0)) {
        tmp->x += 4 / l->map->scale;
        tmp->y -= 2 / l->map->scale;
    }
    else if (l->map->map[get_pos(l->map, c2.x, c2.y, l)] != 0) {
        tmp->x += 4 / l->map->scale;
        tmp->y += 2 / l->map->scale;
    }
}

void colision_right(enemy_t *tmp, level_t *l)
{
    sfVector2i nmy = {l->map->x + (tmp->x / l->map->scale), l->map->y +\
    (tmp->y / l->map->scale)};
    sfVector2i c1 = {nmy.x + (tmp->speed * 2) / l->map->scale, nmy.y - \
    20 / l->map->scale};
    sfVector2i c2 = {nmy.x + (tmp->speed * 2) / l->map->scale, nmy.y + \
    20 / l->map->scale};
    sfVector2i c3 = {nmy.x + (tmp->speed * 2) / l->map->scale, nmy.y};

        if (tmp->mvmnt_type == 1 || l->map->map[get_pos(l->map, c3.x, c3.y, \
        l)] != 0)
            tmp->x += tmp->speed / l->map->scale;
        else
            else_case_right(tmp, l, c1, c2);
}