/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** npc
*/

#include "my.h"

void create_npc7(sfRenderWindow *window, npc_t *returned)
{
    returned->texts = malloc(sizeof(sfText *) * 4);
    for (int i = 0; i < 3; i++) {
        returned->texts[i] = sfText_create();
        sfText_setScale(returned->texts[i], (sfVector2f){1.0, 1.0});
        sfText_setFont(returned->texts[i], returned->font);
        sfText_setColor(returned->texts[i], sfBlack);
    }
    sfText_setString(returned->texts[0], "I'm King George and I need your \
help stranger!");
    sfText_setString(returned->texts[1], "My Queeeeeeen Scarlet was taken \
from me!");
    sfText_setString(returned->texts[2], "Fight the monsters and find her!");
    returned->texts[3] = NULL;
    for (int i = 0; i < 3; i++)
        sfText_setPosition(returned->texts[i], (sfVector2f){(float)
        ((sfRenderWindow_getSize(window).x / 2) - (unsigned int)
        (sfText_getGlobalBounds(returned->texts[i]).width / 2)), 750.0});
    returned->texture =
    sfTexture_createFromFile("./src/person1.png", NULL);
}

void create_npc8(sfRenderWindow *window, npc_t *returned)
{
    returned->texts = malloc(sizeof(sfText *) * 5);
    for (int i = 0; i < 4; i++) {
        returned->texts[i] = sfText_create();
        sfText_setScale(returned->texts[i], (sfVector2f){1.0, 1.0});
        sfText_setFont(returned->texts[i], returned->font);
        sfText_setColor(returned->texts[i], sfBlack);
    }
    sfText_setString(returned->texts[0], "Why did you kill my bestie????");
    sfText_setString(returned->texts[1], "and all my other friends?");
    sfText_setString(returned->texts[2], "They helped me to escaped this \
monster of a husband.");
    sfText_setString(returned->texts[3], "I will rather kill myself than \
going with you.");
    returned->texts[4] = NULL;
    for (int i = 0; i < 4; i++)
        sfText_setPosition(returned->texts[i], (sfVector2f){(float)
        ((sfRenderWindow_getSize(window).x / 2) - (unsigned int)
        (sfText_getGlobalBounds(returned->texts[i]).width / 2)), 750.0});
    returned->texture =
    sfTexture_createFromFile("./src/person2.png", NULL);
}

void create_npc91(npc_t *returned)
{
    sfText_setString(returned->texts[0], "So i heard you want to help \
the king?");
    sfText_setString(returned->texts[1], "He asked me aswell.");
    sfText_setString(returned->texts[2], "I can tell you the queeeeeeen is \
right ahead, but i have to warn you.");
    sfText_setString(returned->texts[3], "There is a verry strong monster, \
thats why i cant help the king, but good luck.");
    sfText_setString(returned->texts[4], "By the way did you know the film \
titanic came better across the ocean than the ship?");
}

void create_npc9(sfRenderWindow *window, npc_t *returned)
{
    returned->texts = malloc(sizeof(sfText *) * 6);
    for (int i = 0; i < 5; i++) {
        returned->texts[i] = sfText_create();
        sfText_setScale(returned->texts[i], (sfVector2f){1.0, 1.0});
        sfText_setFont(returned->texts[i], returned->font);
        sfText_setColor(returned->texts[i], sfBlack);
    }
    create_npc91(returned);
    returned->texts[5] = NULL;
    for (int i = 0; i < 5; i++)
        sfText_setPosition(returned->texts[i], (sfVector2f){(float)
        ((sfRenderWindow_getSize(window).x / 2) - (unsigned int)
        (sfText_getGlobalBounds(returned->texts[i]).width / 2)), 750.0});
    returned->texture =
    sfTexture_createFromFile("./src/person3.png", NULL);
}

npc_t *create_npc(int lvl, sfRenderWindow *window, int x, int y)
{
    npc_t *returned = malloc(sizeof(npc_t));

    returned->npc_name = lvl;
    returned->scale = 3;
    returned->time = 0;
    returned->glock = sfClock_create();
    returned->lil_glock = sfClock_create();
    returned->x = x;
    returned->y = y;
    returned->font = sfFont_createFromFile("./bonus/DejaVuSans.ttf");
    if (lvl == 7)
        create_npc7(window, returned);
    if (lvl == 8)
        create_npc8(window, returned);
    if (lvl == 9)
        create_npc9(window, returned);
    returned->interacted = 0;
    returned->sprite = sfSprite_create();
    sfSprite_setTexture(returned->sprite, returned->texture, false);
    return (returned);
}