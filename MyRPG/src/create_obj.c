/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

obj_t *create_obj(obj_t *object, char *pt, sfVector2f ps, sfVector2f sc)
{
    object->texture = sfTexture_createFromFile(pt, NULL);
    if (object->texture == NULL)
        return (NULL);
    object->sprite = sfSprite_create();
    if (object->sprite == NULL)
        return (NULL);
    sfTexture_setRepeated(object->texture, sfTrue);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_scale(object->sprite, sc);
    object->pos = ps;
    sfSprite_setPosition(object->sprite, ps);
    return (object);
}