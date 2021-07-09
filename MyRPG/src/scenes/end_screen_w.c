/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

void end_text(sfRenderWindow *window)
{
    sfFont *font;
    sfText *buttont = sfText_create();
    sfVector2f text_pos = {660, 110};

    font = sfFont_createFromFile("bonus/DejaVuSans.ttf");
    sfText_setFont(buttont, font);
    sfText_setCharacterSize(buttont, 50);
    sfText_setStyle(buttont, sfTextBold);
    sfText_setColor(buttont, sfGreen);
    sfText_setOutlineColor(buttont, sfBlack);
    sfText_setOutlineThickness(buttont, 1);
    sfText_setPosition(buttont, text_pos);
    sfText_setString(buttont, \
        " Task failed succesfully:\nThe queen killed herself.");
    sfRenderWindow_drawText(window, buttont, NULL);
    sfFont_destroy(font);
    sfText_destroy(buttont);
}

scene_t *quitb(scene_t *scene, sfVector2f sz, colors_t cl, sfTexture *tx)
{
    sfVector2f pos3 = {790, 700};

    init_button((scene->buttons[2]), pos3, sz);
    scene->buttons[2]->callback = &end_game;
    scene->buttons[2]->name = button_text("QUIT", 910, 720, 40);
    sfRectangleShape_setTexture(scene->buttons[2]->rect, tx, sfTrue);
    init_b_colors(scene->buttons[2], cl);
    scene->buttons[3] = NULL;
    return (scene);
}

scene_t *end_screen(scene_t *scene, sfVector2f sz, colors_t color, \
                                            sfTexture *texture)
{
    sfVector2f pos1 = {790, 300};
    sfVector2f pos2 = {790, 500};

    scene = malloc_scene(scene, 4);
    if (scene == NULL)
        return (NULL);
    init_button((scene->buttons[0]), pos1, sz);
    scene->buttons[0]->callback = &switch_scene;
    scene->buttons[0]->name = button_text("RESTART", 890, 320, 35);
    sfRectangleShape_setTexture(scene->buttons[0]->rect, texture, sfTrue);
    init_b_colors(scene->buttons[0], color);
    init_button((scene->buttons[1]), pos2, sz);
    scene->buttons[1]->callback = &start_menu;
    scene->buttons[1]->name = button_text("MENU", 905, 520, 40);
    sfRectangleShape_setTexture(scene->buttons[1]->rect, texture, sfTrue);
    init_b_colors(scene->buttons[1], color);
    scene = quitb(scene, sz, color, texture);
    return (scene);
}

void winner(scene_t **scenes, sfRenderWindow *window, sfSprite *set)
{
    obj_t *node = malloc(sizeof(obj_t));

    scenes[1]->current_sc = 3;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        draw_scene(window, scenes);
        draw_game_freeze(scenes[1]->game);
        draw_menu_but(scenes, window);
        draw_ui(window, scenes);
        draw_menu(window, scenes, 1);
        event(window, scenes, set);
        if (scenes[1]->current_sc != 3)
            break;
        end_text(window);
        sfRenderWindow_drawSprite(window, set, NULL);
        sfRenderWindow_display(window);
    }
    if (sfRenderWindow_isOpen(window))
        game_loop(window, scenes, set);
    free (node);
}