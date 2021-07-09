/*
** EPITECH PROJECT, 2020
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

int delete_node_obj(llist_t *obj, obj_t *node)
{
    if (obj->size <= 0)
        return (0);
    obj->size -= 1;
    if (obj->size == 0) {
        obj->start = NULL;
        obj->end = NULL;
    }
    if (node->next == NULL) {
        obj->end = node->prev;
        obj->end->next = NULL;
        return (0);
    }
    if (obj->size == 1) {
        obj->start = node->next;
        obj->start->prev = NULL;
        return (0);
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    return (0);
}

int size_manager(llist_t *list, obj_t *next_node)
{
    if (list == NULL || next_node == NULL || list->size < 0)
        return (-1);
    if (list->size == 0) {
        list->start = next_node;
        list->end = next_node;
    } else {
        list->end->next = next_node;
        next_node->prev = list->end;
        list->end = next_node;
    }
    list->size += 1;
    return (0);
}

int new_node(llist_t *list, char *path, sfVector2f pos, sfVector2f scale)
{
    obj_t *next_node = malloc(sizeof(obj_t));

    if (list == NULL || next_node == NULL)
        return (-1);
    next_node->prev = NULL;
    next_node->next = NULL;
    next_node = create_obj(next_node, path, pos, scale);
    if (next_node == NULL)
        return (-1);
    if (size_manager(list, next_node) == -1)
        return (-1);
    return (0);
}

llist_t *create_list(void)
{
    llist_t *list = malloc(sizeof(llist_t));

    if (list == NULL)
        return (NULL);
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
    return (list);
}