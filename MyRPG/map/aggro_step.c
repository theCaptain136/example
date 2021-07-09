/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "my.h"

void step_one(int dx, int dy, enemy_t *tmp, level_t *l)
{
    if (dy > dx) {
        if (dy - dx > 100)
            tmp->direction = 3;
        colision_up(tmp, l);
    }
    else {
        tmp->direction = 4;
        colision_right(tmp, l);
    }
}

void step_two(int dx, int dy, enemy_t *tmp, level_t *l)
{
    if (abs(dy) > dx) {
        if (abs(dy) - dx > 100)
            tmp->direction = 1;
        colision_down(tmp, l);
    }
    else {
        colision_right(tmp, l);
        tmp->direction = 4;
    }
}

void step_three(int dx, int dy, enemy_t *tmp, level_t *l)
{
    if (dy > abs(dx)) {
        if ((dy) - abs(dx) > 100)
            tmp->direction = 3;
        colision_up(tmp, l);
    }
    else {
        colision_left(tmp, l);
        tmp->direction = 2;
    }
}

void step_four(int dx, int dy, enemy_t *tmp, level_t *l)
{
    if (abs(dy) > abs(dx)) {
        if (abs(dy) - abs(dx) > 100)
            tmp->direction = 1;
        colision_down(tmp, l);
    }
    else {
        colision_left(tmp, l);
        tmp->direction = 2;
    }
}

void step(enemy_t *tmp, int x, int y, level_t *l)
{
    int dx = hero_x - x;
    int dy = hero_y - y;

    if (abs(dx) < tmp->range && abs(dy) < tmp->range) {
        if (sfClock_getElapsedTime(tmp->glock).microseconds > tmp->attack) {
            sfClock_restart(tmp->glock);
            l->hero_stat->hp -= tmp->dmg;
            sfSound_play(l->sound_eff->hurt->sound);
            if (l->hero_stat->hp < 0)
                l->hero_stat->hp = 0;
        }
        hit_particle(l);
        return;
    }
    step_one_two(dx, dy, tmp, l);
    if (dx < 0 && dy > 0)
        step_three(dx, dy, tmp, l);
    if (dx < 0 && dy < 0)
        step_four(dx, dy, tmp, l);
}