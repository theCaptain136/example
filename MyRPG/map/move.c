/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** move
*/

#include "my.h"

void else_case_a(map_t *map, level_t *l, sfVector2i c1, sfVector2i c2)
{
    if ((map->map[get_pos(map, c1.x, c1.y, l)] != 0)) {
        map->x += 8 / map->scale;
        map->y -= 4 / map->scale;
    }
    else if (map->map[get_pos(map, c2.x, c2.y, l)] != 0) {
        map->x += 8 / map->scale;
        map->y += 4 / map->scale;
    }
}

int press_a(map_t *map, hero_t *hero, level_t *l)
{
    sfVector2i c1 = {1920 / 2 - (hero->speed * 2) / map->scale, 1080 / \
    2 + 10 / map->scale};
    sfVector2i c2 = {1920 / 2 - (hero->speed * 2) / map->scale, 1080 / \
    2 - 10 / map->scale};
    sfVector2i c3 = {1920 / 2 - (hero->speed * 4) / map->scale, 1080 / 2};

    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        hero->direction = 2;
        hero->aim = 1;
        if (map->map[get_pos(map, c3.x, c3.y, l)] != 0)
            map->x += hero->speed / map->scale;
        else
            else_case_a(map, l, c1, c2);
        return 1;
    }
    return 0;
}

void else_case_d(map_t *map, level_t *l, sfVector2i c1, sfVector2i c2)
{
    if ((map->map[get_pos(map, c1.x, c1.y, l)] != 0)) {
        map->x -= 8 / map->scale;
        map->y -= 4 / map->scale;
    }
    else if (map->map[get_pos(map, c2.x, c2.y, l)] != 0) {
        map->x -= 8 / map->scale;
        map->y += 4 / map->scale;
    }
}

int press_d(map_t *map, hero_t *hero, level_t *l)
{
    sfVector2i c1 = {1920 / 2 + (hero->speed * 2) / map->scale, 1080 / 2 \
    + 10 / map->scale};
    sfVector2i c2 = {1920 / 2 + (hero->speed * 2) / map->scale, 1080 / 2 \
    - 10 / map->scale};
    sfVector2i c3 = {1920 / 2 + (hero->speed * 4) / map->scale, 1080 / 2};

    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        hero->aim = 3;
        hero->direction = 4;
        if (map->map[get_pos(map, c3.x, c3.y, l)] != 0)
            map->x -= hero->speed / map->scale;
        else
            else_case_d(map, l, c1, c2);
        return 1;
    }
    return 0;
}

void move(map_t *map, hero_t *hero, level_t *l)
{
    if (press_a(map, hero, l) == 1)
        return;
    if (press_d(map, hero, l) == 1)
        return;
    if (press_s(map, hero, l) == 1)
        return;
    if (press_w(map, hero, l) == 1)
        return;
    hero->direction = -1;
}