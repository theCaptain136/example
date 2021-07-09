/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** interact_npc
*/

#include "./my.h"

void interact_with_npc3(level_t *l, sfConvexShape *shape)
{
    if (l->npc->interacted == 0) {
        l->npc->interacted = 1;
        sfRenderWindow_drawConvexShape(l->window, shape, 0);
        sfRenderWindow_drawText(l->window, l->npc->texts
        [l->npc->interacted - 1], NULL);
    } else if (sfKeyboard_isKeyPressed(sfKeySpace) &&
    sfClock_getElapsedTime(l->npc->lil_glock).microseconds > 1000000) {
        sfRenderWindow_drawConvexShape(l->window, shape, 0);
        sfRenderWindow_drawText(l->window, l->npc->texts
        [l->npc->interacted - 1], NULL);
        l->npc->interacted += 1;
        sfClock_restart(l->npc->lil_glock);
    } else {
        sfRenderWindow_drawConvexShape(l->window, shape, 0);
        sfRenderWindow_drawText(l->window, l->npc->texts
        [l->npc->interacted - 1], NULL);
    }
}

void interact_with_npc4(level_t *l, sfConvexShape *shape)
{
    if ((sfKeyboard_isKeyPressed(sfKeyE) &&
    n_distance(hero_x, hero_y, l->npc->x + l->map->x,
    l->npc->y + l->map->y) < 200.0 &&
    l->npc->interacted == 0) || l->npc->interacted > 0) {
        interact_with_npc3(l, shape);
    }
    sfConvexShape_destroy(shape);
}

void interact_with_npc2(level_t *l, sfConvexShape *shape)
{
    sfSprite_setPosition(l->npc->sprite, (sfVector2f)
    {(l->map->x + l->npc->x / l->map->scale + 50 / l->map->scale)
    - 50 / l->map->scale, (l->map->y + l->npc->y / l->map->scale
    - 120 / l->map->scale) + 120 / l->map->scale});
    sfRenderWindow_drawSprite(l->window, l->npc->sprite, NULL);
    if (l->list->start != NULL || l->npc == NULL) {
        sfConvexShape_destroy(shape);
        return;
    }
    if (l->npc->npc_name == 7)
        if (l->npc->interacted == 4)
            l->npc->interacted = -1;
    if (l->npc->npc_name == 8)
        if (l->npc->interacted == 5)
            l->npc->interacted = -1;
    if (l->npc->npc_name == 9)
        if (l->npc->interacted == 6)
            l->npc->interacted = -1;
    interact_with_npc4(l, shape);
}

void interact_with_npc(level_t *l)
{
    sfConvexShape *shape = sfConvexShape_create();

    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setPoint(shape, 0, (sfVector2f)
    {sfRenderWindow_getSize(l->window).x / 10, 700});
    sfConvexShape_setPoint(shape, 1, (sfVector2f)
    {sfRenderWindow_getSize(l->window).x / 10 * 9, 700});
    sfConvexShape_setPoint(shape, 2, (sfVector2f)
    {sfRenderWindow_getSize(l->window).x / 10 * 9, 900});
    sfConvexShape_setPoint(shape, 3, (sfVector2f)
    {sfRenderWindow_getSize(l->window).x / 10, 900});
    sfConvexShape_setOutlineThickness(shape, 5.0);
    sfConvexShape_setOutlineColor(shape, sfBlack);
    sfSprite_setTextureRect(l->npc->sprite,
    (sfIntRect){48 * (l->npc->time % 3), 0, 48, 48});
    sfSprite_setOrigin(l->npc->sprite, (sfVector2f){24.0, 48.0});
    sfSprite_setScale(l->npc->sprite,
    (sfVector2f){l->npc->scale, l->npc->scale});
    interact_with_npc2(l, shape);
}