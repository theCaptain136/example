/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "my.h"

void types_enem3(level_t *l, int i)
{
    if (l->map->map[i] >= 7) {
        l->npc = create_npc(l->map->map[i],
        l->window, xy_from_index(i, l->map, l).x,
        xy_from_index(i, l->map, l).y);
        l->map->map[i] = 1;
    }
}

void types_enem_fur(map_t *map, level_t *l, int i, ll_enemy *new_list)
{
    enemy_t *tmp = NULL;

    if (map->map[i] == 4) {
        tmp = enemy_3(i, l);
        push_back_plane(tmp, new_list);
        map->map[i] = 1;
    }
    if (map->map[i] == 5) {
        tmp = enemy_4(i, l);
        push_back_plane(tmp, new_list);
        map->map[i] = 1;
    }
    if (map->map[i] == 6) {
        tmp = enemy_5(i, l);
        push_back_plane(tmp, new_list);
        map->map[i] = 1;
    }
    types_enem3(l, i);
}

void types_enem(map_t *map, level_t *l, int i, ll_enemy *new_list)
{
    enemy_t *tmp = NULL;

    if (map->map[i] == 2) {
        tmp = enemy_1(i, l);
        push_back_plane(tmp, new_list);
        map->map[i] = 1;
    }
    if (map->map[i] == 3) {
        tmp = enemy_2(i, l);
        push_back_plane(tmp, new_list);
        map->map[i] = 1;
    }
    types_enem_fur(map, l, i, new_list);
}

ll_enemy *spawn_enemys(map_t *map, level_t *l)
{
    ll_enemy *new_list = create_plane_list();
    enemy_t *tmp = NULL;
    int i = 5;

    if (l->theme == 6) {
        tmp = boss((l->MAP_size * l->MAP_size) / 2, l);
        push_back_plane(tmp, new_list);
        l->npc = create_npc(8,
        l->window, xy_from_index(i, l->map, l).x,
        xy_from_index(i, l->map, l).y);
        l->map->map[i] = 1;
        return (new_list);
        }
    for (int i = 1; map->map[i] != -1; i++) {
        types_enem(map, l, i, new_list);
    }
    return (new_list);
}