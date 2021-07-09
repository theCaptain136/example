/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** themes
*/

#include "my.h"

void fire_1(level_t *l, sfSprite *sprite, int i)
{
    if (sfClock_getElapsedTime(l->timer5).microseconds < 5000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){0 * 192, i \
        * 192, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 5000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){1 * 192, i \
        * 192, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 10000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){2 * 192, i \
        * 192, 192, 192});
    }
}

void fire_2(level_t *l, sfSprite *sprite, int *i)
{
    if (sfClock_getElapsedTime(l->timer5).microseconds > 15000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){3 * 192, \
        *i * 192, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 20000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){4 * 192, \
        *i * 192, 192, 192});
    }
    *i += 1;
    if (sfClock_getElapsedTime(l->timer5).microseconds > 25000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){0 * 192, \
        *i * 192, 192, 192});
    }
}

void fire_3(level_t *l, sfSprite *sprite, int i)
{
    if (sfClock_getElapsedTime(l->timer5).microseconds > 30000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){1 * 192, \
        i * 192, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 35000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){2 * 192, \
        i * 192, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 40000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){3 * 192, \
        i * 192, 192, 192});
    }
}

void fire_4(level_t *l, sfSprite *sprite, int *i)
{
    if (sfClock_getElapsedTime(l->timer5).microseconds > 45000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){4 * 192, \
        *i * 192, 192, 192});
    }
    *i += 1;
    if (sfClock_getElapsedTime(l->timer5).microseconds > 50000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){0 * 192, \
        *i * 192, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 55000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){1 * 192, \
        *i * 192, 192, 192});
    }
}

void fire_5(level_t *l, sfSprite *sprite, int i)
{
    if (sfClock_getElapsedTime(l->timer5).microseconds > 60000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){2 * 192, \
        i * 192, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 65000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){3 * 192, \
        i * 192, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 70000 * 2) {
        sfSprite_setTextureRect(sprite, (sfIntRect){4 * 192, \
        i * 192, 192, 192});
    }
}