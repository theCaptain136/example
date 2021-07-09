/*
** EPITECH PROJECT, 2021
** inventory_scene.c
** File description:
** inventory_scene
*/

#include "../../include/my_rpg.h"

void display_item(items_t *cur, sfRenderWindow *window, sfVector2f pos)
{
    sfVector2f sprite = {pos.x, pos.y};
    sfVector2f count = {pos.x + cur->count->pos.x, pos.y + cur->count->pos.y};

    sfSprite_setPosition(cur->sprite, sprite);
    sfText_setPosition(cur->count->text, count);
    sfRenderWindow_drawSprite(window, cur->sprite, NULL);
    if (cur->count->quantity > 0)
        sfRenderWindow_drawText(window, cur->count->text, NULL);
}

void draw_inventory(sfRenderWindow *window, scene_t **scenes)
{
    sfVector2f pos = {0, 0};
    items_t *cur = malloc(sizeof(items_t));

    pos.x = 1060;
    pos.y = 360;
    for (cur = scenes[7]->inv->start; cur != NULL; cur = cur->next) {
        cur->pos = pos;
        display_item(cur, window, pos);
        pos = modify_pos(pos);
    }
}

void init_inventory_nodes(scene_t *scene, sfVector2f bg_sc)
{
    sfVector2f invenpos = {1050, 350};
    sfVector2f eqpos = {500, 350};
    sfVector2f hbpos = {500, 800};
    sfVector2f scale_bg = {0.25, 0.18};
    sfVector2f pos = {280, 70};

    new_node(scene->objs, "bonus/board.png", pos, scale_bg);
    new_node(scene->objs, "bonus/inventorygrid.png", invenpos, bg_sc);
    new_node(scene->objs, "bonus/equipmentwindow.png", eqpos, bg_sc);
    new_node(scene->objs, "bonus/hotbar.png", hbpos, bg_sc);
}

scene_t *inventory(scene_t *scene, sfVector2f sz, colors_t cl, sfTexture *tx)
{
    sfVector2f pos1 = {790, 115};

    scene = malloc_scene(scene, 2);
    if (scene == NULL)
        return (NULL);
    init_button((scene->buttons[0]), pos1, sz);
    scene->buttons[0]->callback = &bt_prev;
    scene->buttons[0]->name = button_text("BACK", 910, 135, 40);
    sfRectangleShape_setTexture(scene->buttons[0]->rect, tx, sfTrue);
    init_b_colors(scene->buttons[0], cl);
    scene->buttons[1] = NULL;
    scene->inv = build_inventory();
    return (scene);
}

void check_inventor_btn(sfRenderWindow *window, sfEvent event, \
scene_t **scenes)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB \
    && scenes[1]->current_sc == 1) {
        scenes[1]->prev_m = scenes[1]->current_sc;
        scenes[1]->current_sc = 7;
    }
}