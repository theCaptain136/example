/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** thunder_stor
*/

#include "my.h"

void thunder_1(level_t *l, sfSprite *sprite, sfSprite *sprite2)
{
    if (sfClock_getElapsedTime(l->timer5).microseconds < 5000) {
        sfSprite_setTextureRect(sprite, (sfIntRect){0 * 192, 192, 192, 192});
        sfSprite_setTextureRect(sprite2, (sfIntRect){0 * 192, 0, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 5000) {
        sfSprite_setTextureRect(sprite, (sfIntRect){1 * 192, 192, 192, 192});
        sfSprite_setTextureRect(sprite2, (sfIntRect){1 * 192, 0, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 50000) {
        sfSprite_setTextureRect(sprite, (sfIntRect){2 * 192, 192, 192, 192});
        sfSprite_setTextureRect(sprite2, (sfIntRect){2 * 192, 0, 192, 192});
    }
}

void thunder_2(level_t *l, sfSprite *sprite, sfSprite *sprite2)
{
    if (sfClock_getElapsedTime(l->timer5).microseconds > 100000) {
        sfSprite_setTextureRect(sprite, (sfIntRect){3 * 192, 192, 192, 192});
        sfSprite_setTextureRect(sprite2, (sfIntRect){3 * 192, 0, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 150000) {
        sfSprite_setTextureRect(sprite, (sfIntRect){4 * 192, 192, 192, 192});
        sfSprite_setTextureRect(sprite2, (sfIntRect){4 * 192, 0, 192, 192});
    }
    if (sfClock_getElapsedTime(l->timer5).microseconds > 225000) {
    sfClock_destroy(l->timer5);
    l->timer5 = NULL;
    }
}

void thunder_display(level_t *l, sfSprite *sprite, sfSprite *sprite2\
, sfTexture *texture)
{
    sfSprite_setOrigin(sprite, (sfVector2f){96, 0});
    sfSprite_setPosition(sprite, (sfVector2f){hero_x, hero_y - 100});
    sfSprite_setRotation(sprite, ((l->hero_stat->aim == 4 || \
    l->hero_stat->aim == -1) * 0.0) + ((l->hero_stat->aim == 2) * 180.0) \
    + ((l->hero_stat->aim == 1) * 90.0) + ((l->hero_stat->aim == 3) * 270.0));
    sfSprite_setScale(sprite, (sfVector2f){0.75, 2.0});
    sfRenderWindow_drawSprite(l->window, sprite, NULL);
    sfSprite_setOrigin(sprite2, (sfVector2f){96, 0});
    sfSprite_setPosition(sprite2, (sfVector2f){hero_x, hero_y - 100});
    sfSprite_setRotation(sprite2, ((l->hero_stat->aim == 4 || l->hero_stat->\
    aim == -1) * 0.0) + ((l->hero_stat->aim == 2) * 180.0) + ((l->hero_stat->\
    aim == 1) * 90.0) + ((l->hero_stat->aim == 3) * 270.0));
    sfSprite_setScale(sprite2, (sfVector2f){0.75, 3.0});
    sfRenderWindow_drawSprite(l->window, sprite2, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    sfSprite_destroy(sprite2);
}