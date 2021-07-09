/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** particle
*/

#include "my.h"

void hit_particle(level_t *l)
{
    sfTexture *texture = sfTexture_createFromFile \
    ("./src/StickSpecial2.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect rec = {0, 0, 192, 192};

    sfSprite_setTexture(sprite, texture, false);
    rec = sfSprite_getTextureRect(sprite);
    if (l->count4 % 5 == 0)
        sfSprite_setTextureRect(sprite, (sfIntRect){0 * 192, 192, 192, 192});
    if (l->count4 % 5 == 1)
        sfSprite_setTextureRect(sprite, (sfIntRect){1 * 192, 192, 192, 192});
    particle_stor(l, sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){96, 96});
    sfSprite_setScale(sprite, (sfVector2f){0.75, 0.75});
    sfSprite_setPosition(sprite, (sfVector2f){hero_x, hero_y - 100});
    sfRenderWindow_drawSprite(l->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return;
}

void thunder(level_t *l)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;
    sfSprite *sprite2 = NULL;

    if (l->timer5 == NULL)
        return;
    sprite2 = sfSprite_create();
    sprite = sfSprite_create();
    texture = sfTexture_createFromFile("./src/fire1.png", NULL);
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setTexture(sprite2, texture, false);
    thunder_1(l, sprite, sprite2);
    thunder_2(l, sprite, sprite2);
    thunder_display(l, sprite, sprite2, texture);
}

void fire(level_t *l)
{
    if (l->timer5 == NULL)
        return;
    sfTexture *texture = sfTexture_createFromFile("./src/thunder2.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect rec = {0, 0, 192, 192};
    sfSprite_setTexture(sprite, texture, false);
    int i = 0;

    fire_1(l, sprite, i);
    fire_2(l, sprite, &i);
    fire_3(l, sprite, i);
    fire_4(l, sprite, &i);
    fire_5(l, sprite, i);
    if (sfClock_getElapsedTime(l->timer5).microseconds > 75000 * 2) {
    sfClock_destroy(l->timer5);
    l->timer5 = NULL;
    }
    draw_fire(l, sprite, texture);
}