/*
** EPITECH PROJECT, 2021
** inventory_utils.c
** File description:
** inventory_utils
*/

#include "../include/my_rpg.h"

sfVector2f modify_pos(sfVector2f pos)
{
    if (pos.x >= 1500) {
        pos.x = 1010;
        pos.y += 50;
    }
    pos.x += 50;
    return (pos);
}

inventory_t *create_inv(void)
{
    inventory_t *list = malloc(sizeof(inventory_t));

    if (list == NULL)
        return (NULL);
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
    return (list);
}
