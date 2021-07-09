/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** enemy_types
*/

#include "my.h"

enemy_t *enemy_1(int index, level_t *l)
{
    enemy_t *res = create_enemy();
    sfVector2i vector = xy_from_index(index, l->map, l);
    sfTexture *textur1 = sfTexture_createFromFile("./src/nmy1.png", NULL);

    res = init_enem(res, index, vector, textur1);
    res->dmg = 10 + rand() % (15 + l->lvl) + 2 * l->lvl;
    res->hp = 120 + 15 * l->lvl;
    res->max_hp = 120;
    res->radius = 8 + rand() % 5 + 2 * l->lvl;
    res->speed = 5 + rand() % 3;
    res->mvmnt_type = 1;
    res->range = 50;
    res->attack = 250000;
    return (res);
}

enemy_t *enemy_2(int index, level_t *l)
{
    enemy_t *res = create_enemy();
    sfVector2i vector = xy_from_index(index, l->map, l);
    sfTexture *textur1 = sfTexture_createFromFile("./src/nmy2.png", NULL);

    res = init_enem(res, index, vector, textur1);
    res->dmg = 50 * l->lvl;
    res->hp = 100 + 20 * l->lvl;
    res->max_hp = 100 + 20 * l->lvl;
    res->radius = 12;
    res->speed = 2;
    res->range = 200;
    res->mvmnt_type = 0;
    res->size = 2 + (l->lvl > 2) * 1 + (l->lvl > 3) * 1 + (l->lvl > 4) * 1;
    return (res);
}

enemy_t *enemy_3(int index, level_t *l)
{
    enemy_t *res = create_enemy();
    sfVector2i vector = xy_from_index(index, l->map, l);
    sfTexture *textur1 = sfTexture_createFromFile("./src/nmy3.png", NULL);

    res = init_enem(res, index, vector, textur1);
    res->dmg = 20;
    res->hp = 60;
    res->max_hp = 40;
    res->radius = 30;
    res->speed = 7 + rand() % 3;
    res->range = 120;
    res->mvmnt_type = 1;
    res->attack = 250000;
    return (res);
}

enemy_t *enemy_4(int index, level_t *l)
{
    enemy_t *res = create_enemy();
    sfVector2i vector = xy_from_index(index, l->map, l);
    sfTexture *textur1 = sfTexture_createFromFile("./src/nmy4.png", NULL);

    res = init_enem(res, index, vector, textur1);
    res->dmg = 20;
    res->hp = 40;
    res->max_hp = 40;
    res->radius = 10;
    res->speed = 10;
    res->range = 120;
    res->size = 2.0;
    res->attack = 50000;
    res->mvmnt_type = 0;
    return (res);
}

enemy_t *enemy_5(int index, level_t *l)
{
    enemy_t *res = create_enemy();
    sfVector2i vector = xy_from_index(index, l->map, l);
    sfTexture *textur1 = sfTexture_createFromFile("./src/nmy5.png", NULL);

    res = init_enem(res, index, vector, textur1);
    res->dmg = 50;
    res->hp = 200;
    res->max_hp = 200;
    res->radius = 10;
    res->speed = 5 + rand() % 3;
    res->range = 100;
    res->mvmnt_type = 1;
    res->attack = 1000000;
    return (res);
}