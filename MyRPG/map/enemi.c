/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** enemi
*/

#include "my.h"

ll_enemy *create_plane_list(void)
{
    ll_enemy *new_list = malloc(sizeof(ll_enemy));

    new_list->start = NULL;
    new_list->end = NULL;
    new_list->size = 0;

    return (new_list);
}

bool push_back_plane(enemy_t *airplane, ll_enemy *list_plane)
{
    if (!airplane || !list_plane)
        return false;
    if (list_plane->size == 0) {
        list_plane->start = airplane;
        list_plane->end = airplane;
    } else {
        airplane->next = NULL;
        airplane->previous = list_plane->end;
        list_plane->end->next = airplane;
        list_plane->end = airplane;
    }
    list_plane->size += 1;
    return true;
}

sfVector2i xy_from_index(int index, map_t *map, level_t *l)
{
    int x = (index - 1) % l->MAP_size;
    int y = (index - 1) / l->MAP_size;
    int pos_x = 0;
    int pos_y = 0;

    pos_x += -(100 / map->scale) * y;
    pos_y += (50 / map->scale) * y;
    pos_x += (100 / map->scale) * x;
    pos_y += (50 / map->scale) * x;
    pos_y += 50 / map->scale;
    return ((sfVector2i){pos_x, pos_y});
}

int enemy_clock(sfTime clock, sfClock **time)
{
    if (clock.microseconds > 1000000 / 5) {
        sfClock_restart(*time);
        return (1);
    }
    return (0);
}

enemy_t *create_enemy(void)
{
    enemy_t *new_enemy = malloc(sizeof(enemy_t));

    new_enemy->direction = -1;
    new_enemy->y = 0;
    new_enemy->x = 0;
    new_enemy->map_index = 0;
    new_enemy->sprite = NULL;
    new_enemy->texture = NULL;
    new_enemy->previous = NULL;
    new_enemy->next = NULL;
    new_enemy->attack = 2000000;
    new_enemy->glock = sfClock_create();
    return (new_enemy);
}