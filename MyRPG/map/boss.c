/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** boss
*/

#include "my.h"

enemy_t *boss(int index, level_t *l)
{
    enemy_t *res = create_enemy();
    sfVector2i vector = xy_from_index(index, l->map, l);
    sfTexture *textur1 = sfTexture_createFromFile("./src/Montser6.png", NULL);

    res = init_enem(res, index, vector, textur1);
    res->dmg = 100;
    res->hp = 200;
    res->max_hp = 200;
    res->radius = 16;
    res->speed = 8;
    res->mvmnt_type = 0;
    res->range = 200;
    res->attack = 250000;
    res->size = 6;
    return (res);
}

void draw_fire(level_t *l, sfSprite *sprite, sfTexture *texture)
{
    sfSprite_setOrigin(sprite, (sfVector2f){96, 0});
    sfSprite_setPosition(sprite, (sfVector2f){hero_x, hero_y - 100});
    sfSprite_setRotation(sprite, ((l->hero_stat->aim == 4 || l->hero_stat->\
    aim == -1) * 0.0) + ((l->hero_stat->aim == 2) * 180.0) + ((l->hero_stat->\
    aim == 1) * 90.0) + ((l->hero_stat->aim == 3) * 270.0));
    sfSprite_setScale(sprite, (sfVector2f){0.75, 3.0});
    sfRenderWindow_drawSprite(l->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void particle_stor(level_t *l, sfSprite *sprite)
{
    if (l->count4 % 5 == 2)
        sfSprite_setTextureRect(sprite, (sfIntRect){2 * 192, 192, 192, 192});
    if (l->count4 % 5 == 3)
        sfSprite_setTextureRect(sprite, (sfIntRect){3 * 192, 192, 192, 192});
    if (l->count4 % 5 == 4)
        sfSprite_setTextureRect(sprite, (sfIntRect){4 * 192, 192, 192, 192});
}