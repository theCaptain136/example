/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

int button_is_clicked(button_t button, sfVector2f click_position)
{
    if (click_position.x < button.pos.x || click_position.x > button.pos.x
        + button.size.x)
        return (0);
    if (click_position.y < button.pos.y || click_position.y > button.pos.y
        + button.size.y)
        return (0);
    return (1);
}

void init_button(button_t *button, sfVector2f position, sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    button->pos = position;
    button->size = size;
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
}

sfText *button_text(char *str, int x, int y, int size)
{
    sfFont *font;
    sfText *buttont = sfText_create();
    sfVector2f text_pos = {x, y};

    font = sfFont_createFromFile("bonus/DejaVuSans.ttf");
    sfText_setFont(buttont, font);
    sfText_setCharacterSize(buttont, size);
    sfText_setStyle(buttont, sfTextBold);
    sfText_setColor(buttont, sfBlack);
    sfText_setOutlineColor(buttont, sfColor_fromRGB(70, 70, 70));
    sfText_setOutlineThickness(buttont, 1);
    sfText_setPosition(buttont, text_pos);
    sfText_setString(buttont, str);
    return (buttont);
}

scene_t *quit_but(scene_t *scene, sfVector2f sz, colors_t cl, sfTexture *tx)
{
    sfVector2f pos3 = {790, 680};

    init_button((scene->buttons[2]), pos3, sz);
    scene->buttons[2]->callback = &end_game;
    scene->buttons[2]->name = button_text("QUIT", 910, 700, 40);
    sfRectangleShape_setTexture(scene->buttons[2]->rect, tx, sfTrue);
    init_b_colors(scene->buttons[2], cl);
    scene->buttons[3] = NULL;
    return (scene);
}

scene_t *scene_menu(scene_t *scene, sfVector2f sz, colors_t cl, sfTexture *tx)
{
    sfVector2f pos1 = {790, 280};
    sfVector2f pos2 = {790, 480};

    scene = malloc_scene(scene, 4);
    if (scene == NULL)
        return (NULL);
    init_button((scene->buttons[0]), pos1, sz);
    scene->buttons[0]->callback = &switch_scene;
    scene->buttons[0]->name = button_text("RESUME", 880, 300, 40);
    sfRectangleShape_setTexture(scene->buttons[0]->rect, tx, sfTrue);
    init_b_colors(scene->buttons[0], cl);
    init_button((scene->buttons[1]), pos2, sz);
    scene->buttons[1]->callback = &start_menu;
    scene->buttons[1]->name = button_text("MENU", 905, 500, 40);
    sfRectangleShape_setTexture(scene->buttons[1]->rect, tx, sfTrue);
    init_b_colors(scene->buttons[1], cl);
    scene = quit_but(scene, sz, cl, tx);
    return (scene);
}