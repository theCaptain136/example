/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "include/my_rpg.h"

int connect_items(inventory_t *list, items_t *next_node)
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

items_t *create_item_sprite(items_t *next_node, char *path)
{
    next_node->pos.x = 100;
    next_node->pos.y = 100;
    next_node->texture = sfTexture_createFromFile(path, NULL);
    if (next_node->texture == NULL)
        return (NULL);
    next_node->sprite = sfSprite_create();
    if (next_node->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(next_node->sprite, next_node->texture, sfTrue);
    sfSprite_setPosition(next_node->sprite, next_node->pos);
    return (next_node);
}

items_t *count_text(items_t *next_node)
{
    next_node->count = malloc(sizeof(name_t));
    if (next_node->count == NULL)
        return (NULL);
    next_node->count->pos.x = 25;
    next_node->count->pos.y = 15;
    next_node->count->quantity = 1;
    next_node->count->text = sfText_create();
    next_node->count->font = sfFont_createFromFile("bonus/DejaVuSans.ttf");
    sfText_setFont(next_node->count->text, next_node->count->font);
    sfText_setCharacterSize(next_node->count->text, 15);
    sfText_setColor(next_node->count->text, sfWhite);
    sfText_setOutlineColor(next_node->count->text, sfBlack);
    sfText_setOutlineThickness(next_node->count->text, 1);
    sfText_setString(next_node->count->text, \
        nb_to_str(next_node->count->quantity));
    sfText_setPosition(next_node->count->text, next_node->count->pos);
    return (next_node);
}

int new_item(inventory_t *list, char *name, char *path, int i)
{
    items_t *next_node = malloc(sizeof(items_t));

    if (list == NULL || next_node == NULL)
        return (-1);
    next_node->prev = NULL;
    next_node->next = NULL;
    if ((next_node = count_text(next_node)) == NULL)
        return (-1);
    if (i == 1) {
        next_node->count->quantity = 1;
    } else {
        next_node->count->quantity = i;
    }
    next_node = create_item_sprite(next_node, path);
    if (next_node == NULL)
        return (-1);
    if (connect_items(list, next_node) == -1)
        return (-1);
    return (0);
}

inventory_t *build_inventory(void)
{
    inventory_t *inv = create_inv();

    if (inv == NULL)
        return (NULL);
    if (new_item(inv, "helmet", "bonus/helmet.png", 1) == -1)
            return (NULL);
    if (new_item(inv, "armor", "bonus/armor.png", 1) == -1)
            return (NULL);
    if (new_item(inv, "laser", "bonus/laser.png", 1) == -1)
            return (NULL);
    if (new_item(inv, "boots", "bonus/boots.png", 1) == -1)
            return (NULL);
    if (new_item(inv, "pots", "bonus/pots.png", 50) == -1)
            return (NULL);
    return (inv);
}



//to be deleted

// int main(void)
// {
//     sfRenderWindow *window;
//     sfVideoMode video_mode = {500, 500, 32};
//     char *filepath = "bonus/inventorygrid.png";
//     sfTexture* bgtexture = 0;
//     sfSprite* backgroundsprite = 0;
//     inventory_t *inv = build_inventory();
//     items_t *cur = malloc(sizeof(items_t));
//     sfEvent event;
//     sfVector2f pos = {0, 0};

//     bgtexture = sfTexture_createFromFile(filepath, NULL);
//     backgroundsprite = sfSprite_create();
//     sfSprite_setTexture(backgroundsprite, bgtexture, sfTrue);
//     window = sfRenderWindow_create(video_mode, "MyDefender", sfClose, NULL);
//     sfRenderWindow_setFramerateLimit(window, 1);
//     while (sfRenderWindow_isOpen(window)) {
//         while (sfRenderWindow_pollEvent(window, &event)) {
//             if (event.type == sfEvtClosed)
//                 sfRenderWindow_close(window);
//         }
//         pos.x = 10;
//         pos.y = 10;
//         for (cur = inv->start; cur != NULL; cur = cur->next) {
//             display_item(cur, window, pos);
//             pos = modify_pos(pos);
//         }
//         sfRenderWindow_display(window);
//         sfRenderWindow_clear(window, sfBlack);
//         sfRenderWindow_drawSprite(window, backgroundsprite, NULL);
//     }
//     free_inventory(inv, cur);
//     return (0);
// }