/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "my.h"

void aim(hero_t *hero)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        hero->aim = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        hero->aim = 4;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        hero->aim = 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        hero->aim = 1;
    }
}

void else_case_s(map_t *map, level_t *l, sfVector2i c1, sfVector2i c2)
{
    if ((map->map[get_pos(map, c1.x, c1.y, l)] != 0)) {
        map->x += 8 / map->scale;
        map->y -= 4 / map->scale;
    }
    else if (map->map[get_pos(map, c2.x, c2.y, l)] != 0) {
        map->x -= 8 / map->scale;
        map->y -= 4 / map->scale;
    }
}

int press_s(map_t *map, hero_t *hero, level_t *l)
{
    sfVector2i c1 = {1920 / 2 - 20 / map->scale, 1080 / 2 + (hero->speed \
    * 2) / map->scale};
    sfVector2i c2 = {1920 / 2 + 20 / map->scale, 1080 / 2 + (hero->speed \
    * 2) / map->scale};
    sfVector2i c3 = {1920 / 2, 1080 / 2 + (hero->speed * 4) / map->scale};
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) {
        hero->aim = 4;
        hero->direction = 3;
        if (map->map[get_pos(map, c3.x, c3.y, l)] != 0)
            map->y -= hero->speed / map->scale;
        else
            else_case_s(map, l, c1, c2);
        return 1;
    }
    return 0;
}

void else_case_w(map_t *map, level_t *l, sfVector2i c1, sfVector2i c2)
{
    if ((map->map[get_pos(map, c1.x, c1.y, l)] != 0)) {
        map->x += 8 / map->scale;
        map->y += 4 / map->scale;
    }
    else if (map->map[get_pos(map, c2.x, c2.y, l)] != 0) {
        map->x -= 8 / map->scale;
        map->y += 4 / map->scale;
    }
}

int press_w(map_t *map, hero_t *hero, level_t *l)
{
    sfVector2i c1 = {1920 / 2 - 20 / map->scale, 1080 / 2 - (hero->speed \
    * 2) / map->scale};
    sfVector2i c2 = {1920 / 2 + 20 / map->scale, 1080 / 2 - (hero->speed \
    * 2) / map->scale};
    sfVector2i c3 = {1920 / 2, 1080 / 2 - (hero->speed * 4) / map->scale};

    if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue) {
        hero->aim = 2;
        hero->direction = 1;
        if (map->map[get_pos(map, c3.x, c3.y, l)] != 0)
            map->y += hero->speed / map->scale;
        else
            else_case_w(map, l, c1, c2);
        return 1;
    }
    return 0;
}