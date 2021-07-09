/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

sfSprite *create_sprite(char *filepath, sfVector2f pos, sfVector2f scale)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();

    if (texture == NULL || sprite == NULL)
        return (NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

sfIntRect rect_coints(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 16;
    rect.height = 16;
    return (rect);
}