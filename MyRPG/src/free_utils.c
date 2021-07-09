/*
** EPITECH PROJECT, 2021
** free_utils.c
** File description:
** free_utils
*/

#include "../include/my_rpg.h"

void free_inventory(inventory_t *inv, items_t *cur)
{
    for (cur = inv->start; cur != NULL; cur = cur->next) {
        free (cur->name->name);
        sfText_destroy(cur->count->text);
        sfText_destroy(cur->name->text);
        sfFont_destroy(cur->name->font);
        sfFont_destroy(cur->count->font);
        free (cur->count);
        free (cur->name);
        sfTexture_destroy(cur->texture);
        sfSprite_destroy(cur->sprite);
        free (cur->prev);
    }
    free (inv->end);
    free (inv);
}