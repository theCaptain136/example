/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "my.h"

int special_cases(ll_enemy *obj, enemy_t *node)
{
    if (node->next == NULL) {
        obj->end = node->previous;
        obj->end->next = NULL;
        return (0);
    }
    if (node->previous == NULL) {
        obj->start = node->next;
        obj->start->previous = NULL;
        return (0);
    }
    if (obj->size == 1) {
        obj->start = node->next;
        obj->start->previous = NULL;
        return (0);
    }
    return (1);
}

int delete_node(ll_enemy *obj, enemy_t *node)
{
    if (obj->size <= 0)
        return (0);
    obj->size -= 1;
    if (obj->size == 0) {
        obj->start = NULL;
        obj->end = NULL;
        return (0);
    }
    if (special_cases(obj, node)) {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }
    return (0);
}