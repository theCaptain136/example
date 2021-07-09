/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

scene_t *help(scene_t *sc, sfVector2f sz, colors_t color, sfTexture *text)
{
    sfVector2f pos1 = {790, 115};
    sfVector2f pos = {280, 70};
    sfVector2f scale_bg = {0.25, 0.18};

    sc = malloc_scene(sc, 4);
    if (sc == NULL)
        return (NULL);
    init_button((sc->buttons[0]), pos1, sz);
    sc->buttons[0]->callback = &bt_prev;
    sc->buttons[0]->name = button_text("BACK", 910, 135, 40);
    sfRectangleShape_setTexture(sc->buttons[0]->rect, text, sfTrue);
    init_b_colors(sc->buttons[0], color);
    sc->buttons[1] = NULL;
    sc->buttons[2] = NULL;
    sc->buttons[3] = NULL;
    if (new_node(sc->objs, "bonus/board.png", pos, scale_bg) == -1)
        return (NULL);
    sfSprite_setColor(sc->objs->end->sprite, sfColor_fromRGB(181, 136, 134));
    return (sc);
}

void draw_shortcuts(sfRenderWindow *window)
{
    draw_text_w(window, (sfVector2f){760, 260}, "SHORTCUTS", 70);
    draw_text_w(window, (sfVector2f){710, 400}, \
        "M-Key\t\tstatus menu", 45);
    draw_text_w(window, (sfVector2f){710, 500}, \
        "B-Key\t\tInventory", 45);
    draw_text_w(window, (sfVector2f){710, 600}, \
        "Z-Key\t\tmute music", 45);
    draw_text_w(window, (sfVector2f){710, 700}, \
        "B-Key\t\tunmute music", 45);
}