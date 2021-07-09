/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** hero
*/

#include "my.h"

void sprite_set(sfRenderWindow **window, float scale, sfIntRect *rect)
{
    sfSprite *sprite = sfSprite_create();

    sfTexture *texture = sfTexture_createFromFile("./src/People3.png", rect);
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setOrigin(sprite, (sfVector2f){24, 48});
    sfSprite_setPosition(sprite, (sfVector2f){hero_x, hero_y});
    sfSprite_setScale(sprite, (sfVector2f){4 / scale, 4 / scale});
    sfRenderWindow_drawSprite(*window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

hero_t *set_hero(int dmg, int hp)
{
    hero_t *res = malloc(sizeof(hero_t));

    res->dmg = dmg;
    res->hp = hp;
    res->max_hp = hp;
    res->aim = -1;
    res->direction = -1;
    res->speed = 20;
    res->atk_speed = 15;
    res->dmg_type = 9;
    res->kills = 0;
    res->speed = 12;
    res->xp = 0;
    res->hp_bar1 = sfConvexShape_create();
    res->hp_bar2 = sfConvexShape_create();
    return (res);
}

sfIntRect *set_rect(void)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->height = 48;
    rect->width = 48;
    rect->top = 0;
    rect->left = 289;
    return (rect);
}