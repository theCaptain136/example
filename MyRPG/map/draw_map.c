/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "my.h"

sfSprite *set_grass_block(level_t *l, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setOrigin(sprite, (sfVector2f){32, 0});
    sfSprite_setScale(sprite, (sfVector2f){3 / l->map->scale, \
                3 / l->map->scale});
    return (sprite);
}

void free_gras_block(sfTexture *texture, sfSprite *sprite)
{
    sfSprite_destroy(sprite);
}

void draw_map(sfRenderWindow **window, level_t *l)
{
    int a = pow((double)l->MAP_size, 2.0);
    float x = l->map->x;
    float y = l->map->y;
    sfSprite *sprite = set_grass_block(l, l->texture);


    for (int i = 1; i <= a; i++) {
        full_block(window, (sfVector2f){x, y}, \
        (sfVector2f){(float)l->map->map[i], l->map->scale}, sprite);
        if (i % (int)sqrt((double)a) == 0) {
            x = l->map->x - (100 * i / sqrt((double)a)) / l->map->scale;
            y = l->map->y + (50 * i / sqrt((double)a)) / l->map->scale;
        }
        else {
            x = x + 100 / l->map->scale;
            y = y + 50 / l->map->scale;
        }
    }
    free_gras_block(l->texture, sprite);
    return;
}

level_t *init_level_map(sfRenderWindow *window, char *path, level_t *lev, \
int lvl)
{
    lev->lvl = lvl;
    lev->map = malloc(sizeof(map_t));
    if (lev->map == NULL)
        return (NULL);
    lev->window = window;
    lev->theme = read_from_file(&lev->map->map, path);
    lev->MAP_size = sqrt(get_map_size(lev->map->map));
    set_lvl_2(lev);
    lev->path = malloc(sizeof(char) * (my_strlen(path) + 1));
    lev->path = my_strcpy(lev->path, path);
    lev->npc = NULL;
    lev->list = spawn_enemys(lev->map, lev);
    if (lev->theme == 0)
        lev->texture = sfTexture_createFromFile("./src/grass1.png", NULL);
    if (lev->theme == 1 || lev->theme == 6)
        lev->texture = sfTexture_createFromFile("./src/stone.png", NULL);
    if (lev->theme == 2)
        lev->texture = sfTexture_createFromFile\
        ("./src/pablos_boden3.png", NULL);
    return (lev);
}

level_t *set_level(sfRenderWindow *window, char *path, int lvl)
{
    level_t *lev = malloc(sizeof(level_t));

    if (lev == NULL)
        return (NULL);
    lev = set_lvl_stor(lev);
    lev->timer5 = NULL;
    lev->hero_stat = set_hero(40, 400);
    lev->count2 = lev->hero_stat->atk_speed;
    lev->hero_stat->direction = -1;
    lev->count4 = 0;
    lev = init_level_map(window, path, lev, lvl);
    lev->sound_eff = init_sound_eff();
    return (lev);
}