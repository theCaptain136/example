/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

int get_cur(scene_t **scenes)
{
    int cur = scenes[1]->current_sc;

    if (cur == 2 || cur == 3 || cur == 4)
        cur = 1;
    return (cur);
}

void draw_mb(sfRenderWindow *window, scene_t *scene, sfRectangleShape *tmp)
{
    for (int i = 0; scene->music_b[i] != NULL; i++) {
        tmp = scene->music_b[i]->rect;
        sfRectangleShape_setFillColor(tmp, \
                    scene->music_b[i]->colors.normal);
        sfRenderWindow_drawRectangleShape(window, tmp, NULL);
        sfRenderWindow_drawText(window, scene->music_b[i]->name, NULL);
    }
}

void draw_scene(sfRenderWindow *window, scene_t **scenes)
{
    sfRectangleShape *tmp;
    int cur = get_cur(scenes);
    obj_t *node = malloc(sizeof(obj_t));

    for (node = scenes[cur]->objs->start; node != NULL; node = node->next)
        sfRenderWindow_drawSprite(window, node->sprite, NULL);
    for (int i = 0; scenes[cur]->buttons[i] != NULL; i++) {
        tmp = scenes[cur]->buttons[i]->rect;
        sfRectangleShape_setFillColor(tmp, \
                    scenes[cur]->buttons[i]->colors.normal);
        sfRenderWindow_drawRectangleShape(window, tmp, NULL);
        sfRenderWindow_drawText(window, scenes[cur]->buttons[i]->name, NULL);
    }
    if (cur == 6)
        draw_mb(window, scenes[6], tmp);
    free (node);
}

void draw_menu(sfRenderWindow *win, scene_t **scenes, int but)
{
    sfTexture *pattern = sfTexture_createFromFile("bonus/menu_bg.jpg", NULL);
    sfSprite *cover = sfSprite_create();
    sfVector2f scale = {2.2, 2};
    int cur = scenes[1]->current_sc;
    sfRectangleShape *tmp;

    sfSprite_setTexture(cover, pattern, sfTrue);
    sfSprite_setColor(cover, sfColor_fromRGBA(40, 40, 40, 150));
    sfSprite_setPosition(cover, (sfVector2f){0, 0});
    sfSprite_setScale(cover, scale);
    sfRenderWindow_drawSprite(win, cover, NULL);
    if (but == 0)
        return;
    for (int i = 0; scenes[cur]->buttons[i] != NULL; i++) {
        tmp = scenes[cur]->buttons[i]->rect;
        sfRectangleShape_setFillColor(tmp, \
                    scenes[cur]->buttons[i]->colors.normal);
        sfRenderWindow_drawRectangleShape(win, tmp, NULL);
        sfRenderWindow_drawText(win, scenes[cur]->buttons[i]->name, NULL);
    }
}