/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void draw_text(sfRenderWindow *window, sfVector2f text_pos, char *msg, int sz)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("bonus/DejaVuSans.ttf");

    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, sz);
    sfText_setColor(txt, sfBlack);
    sfText_setOutlineColor(txt, sfColor_fromRGB(70, 70, 70));
    sfText_setOutlineThickness(txt, 1);
    sfText_setPosition(txt, text_pos);
    sfText_setString(txt, msg);
    sfRenderWindow_drawText(window, txt, NULL);
    sfFont_destroy(font);
    sfText_destroy(txt);
}

void draw_board(sfRenderWindow *window, sfVector2f sprite_pos)
{
    sfTexture *texture = sfTexture_createFromFile("bonus/details.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.5, 0.5};

    if (texture == NULL || sprite == NULL)
        return;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_scale(sprite, scale);
    sfSprite_setPosition(sprite, sprite_pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void show_details_one_line(sfRenderWindow *window, sfVector2f pos, char *msg)
{
    sfVector2f sprite_pos = {pos.x - (598 * 0.25), pos.y - (230 * 0.5)};
    sfVector2f text_pos = {sprite_pos.x + 40, sprite_pos.y + 30};

    draw_board(window, sprite_pos);
    draw_text(window, text_pos, msg, 40);
}

void show_details_two_lines(sfRenderWindow *window, sfVector2f pos, \
                                        char *msg, char *sc)
{
    sfVector2f sprite_pos = {pos.x - (598 * 0.25), pos.y - (230 * 0.5)};
    sfVector2f text_pos = {sprite_pos.x + 40, sprite_pos.y + 10};
    sfVector2f sc_pos = {sprite_pos.x + 40, sprite_pos.y + 50};

    draw_board(window, sprite_pos);
    draw_text(window, text_pos, msg, 30);
    draw_text(window, sc_pos, sc, 25);
}