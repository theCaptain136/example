/*
** EPITECH PROJECT, 2021
** init_atk_dir.c
** File description:
** init_atk_dir
*/

#include "my.h"

sfIntRect *make_rect(void)
{
    sfIntRect *rect = NULL;

    rect->height = 150;
    rect->width = 150;
    rect->left = 0;
    rect->top = 0;
    return rect;
}

rightatk *init_right_atk(int direction)
{
    rightatk *rightatk = malloc(sizeof(rightatk));
    sfTexture *texture = sfTexture_createFromFile("bonus/sright.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect *rect = make_rect();

    rightatk->direction = direction;
    rightatk->rect = rect;
    rightatk->atksprite = sprite;
    return rightatk;
}

leftatk *init_left_atk(int direction)
{
    leftatk *leftatk = malloc(sizeof(leftatk));
    sfTexture *texture = sfTexture_createFromFile("bonus/sleft.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect *rect = make_rect();

    leftatk->direction = direction;
    leftatk->rect = rect;
    leftatk->atksprite = sprite;
    return leftatk;
}

upatk *init_up_atk(int direction)
{
    upatk *upatk = malloc(sizeof(upatk));
    sfTexture *texture = sfTexture_createFromFile("bonus/sup.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect *rect = make_rect();

    upatk->direction = direction;
    upatk->rect = rect;
    upatk->atksprite = sprite;
    return upatk;
}

downatk *init_down_atk(int direction)
{
    downatk *downatk = malloc(sizeof(downatk));
    sfTexture *texture = sfTexture_createFromFile("bonus/sdown.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect *rect = make_rect();

    downatk->direction = direction;
    downatk->rect = rect;
    downatk->atksprite = sprite;
    return downatk;
}