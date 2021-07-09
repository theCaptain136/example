/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void shortcut_callb(sfRenderWindow *window, int *c, int prev)
{
    *c = 9;
}

scene_t *shortcur_but(scene_t *scene, sfVector2f sz, colors_t color, \
                                sfTexture *texture)
{
    sfVector2f pos3 = {790, 80};

    init_button((scene->buttons[2]), pos3, sz);
    scene->buttons[2]->callback = &shortcut_callb;
    scene->buttons[2]->name = button_text("KEYS", 910, 100, 40);
    sfRectangleShape_setTexture(scene->buttons[2]->rect, texture, sfTrue);
    init_b_colors(scene->buttons[2], color);
    scene->buttons[3] = NULL;
    return (scene);
}

scene_t *how_to_play(scene_t *scene, sfVector2f sz, colors_t color, \
                                            sfTexture *texture)
{
    sfVector2f pos1 = {440, 900};
    sfVector2f pos2 = {1140, 900};

    scene = malloc_scene(scene, 4);
    if (scene == NULL)
        return (NULL);
    init_button((scene->buttons[0]), pos1, sz);
    scene->buttons[0]->callback = &restart;
    scene->buttons[0]->name = button_text("START", 540, 920, 40);
    sfRectangleShape_setTexture(scene->buttons[0]->rect, texture, sfTrue);
    init_b_colors(scene->buttons[0], color);
    init_button((scene->buttons[1]), pos2, sz);
    scene->buttons[1]->callback = &end_game;
    scene->buttons[1]->name = button_text("QUIT", 1240, 920, 40);
    sfRectangleShape_setTexture(scene->buttons[1]->rect, texture, sfTrue);
    init_b_colors(scene->buttons[1], color);
    scene = shortcur_but(scene, sz, color, texture);
    return (scene);
}

void display_help(scene_t **scenes, sfRenderWindow *window, \
                                        sfSprite *set)
{
    obj_t *node = malloc(sizeof(obj_t));

    scenes[1]->current_sc = 5;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        draw_scene(window, scenes);
        event(window, scenes, set);
        if (scenes[1]->current_sc != 5)
            break;
        sfRenderWindow_drawSprite(window, set, NULL);
        sfRenderWindow_display(window);
    }
    if (sfRenderWindow_isOpen(window))
        game_loop(window, scenes, set);
    free (node);
}