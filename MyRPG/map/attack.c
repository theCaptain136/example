/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** attack
*/

#include "my.h"

void attack_one(enemy_t *stor, enemy_t *tmp, level_t *l, int range)
{
    while (tmp != NULL) {
        if ((((tmp->x / l->map->scale) + l->map->x) > hero_x - (range * \
        (50  / l->map->scale)) && ((tmp->x / l->map->scale) + l->map->x) \
        < hero_x) && (((tmp->y / l->map->scale) + l->map->y) > hero_y - \
        (60  / l->map->scale) && ((tmp->y / l->map->scale) + l->map->y) < \
        hero_y + (60  / l->map->scale))) {
            stor = tmp->next;
            tmp->hp -= l->hero_stat->dmg;
            sfSound_play(l->sound_eff->laser->sound);
            tmp = stor;
        }
        else {
            tmp = tmp->next;
        }
    }
}

void attack_two(enemy_t *stor, enemy_t *tmp, level_t *l, int range)
{
    while (tmp != NULL) {
        if (((tmp->x / l->map->scale + l->map->x) > hero_x - ((60  / l->map->\
        scale)) && (tmp->x / l->map->scale + l->map->x) < hero_x + (60  / l->\
        map->scale)) && ((tmp->y / l->map->scale + l->map->y) > hero_y - \
        (range * (50  / l->map->scale)) && (tmp->y / l->map->scale + l->map->y)\
        < hero_y)) {
            stor = tmp->next;
            tmp->hp -= l->hero_stat->dmg;
            sfSound_play(l->sound_eff->laser->sound);
            tmp = stor;
        }
        else {
            tmp = tmp->next;
        }
    }
}

void attack_three(enemy_t *stor, enemy_t *tmp, level_t *l, int range)
{
    while (tmp != NULL) {
        if (((tmp->x / l->map->scale + l->map->x) < hero_x + (range * (50 / \
        l->map->scale)) && (tmp->x / l->map->scale + l->map->x) > hero_x) && \
        ((tmp->y / l->map->scale + l->map->y) > hero_y - (60  / l->map->scale)\
        && (tmp->y / l->map->scale + l->map->y) < hero_y + (60  / \
        l->map->scale))) {
            stor = tmp->next;
            tmp->hp -= l->hero_stat->dmg;
            sfSound_play(l->sound_eff->laser->sound);
            tmp = stor;
        }
        else {
            tmp = tmp->next;
        }
    }
}

void attack_four(enemy_t *stor, enemy_t *tmp, level_t *l, int range)
{
    while (tmp != NULL) {
        if (((tmp->x / l->map->scale + l->map->x) > hero_x - \
        ((60  / l->map->scale)) && (tmp->x / l->map->scale + l->map->x) \
        < hero_x + (60 / l->map->scale)) && ((tmp->y / l->map->scale + \
        l->map->y) < hero_y + (range * (50  / l->map->scale)) && (tmp->y / \
        l->map->scale + l->map->y) > hero_y)) {
            stor = tmp->next;
            tmp->hp -= l->hero_stat->dmg;
            sfSound_play(l->sound_eff->laser->sound);
            tmp = stor;
        }
        else {
            tmp = tmp->next;
        }
    }
}

void attack_melee(level_t *l, int range)
{
    enemy_t *tmp = l->list->start;
    enemy_t *stor = NULL;
    l->timer5 = sfClock_create();

    attack_one_two(stor, tmp, l, range);
    if (l->hero_stat->aim == 3)
        attack_three(stor, tmp, l, range);
    if (l->hero_stat->aim == 4)
        attack_four(stor, tmp, l, range);
}
