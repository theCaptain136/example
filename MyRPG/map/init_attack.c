/*
** EPITECH PROJECT, 2021
** init_attack.c
** File description:
** init_attack
*/

#include "my.h"

atk *init_atk_ext(hero_t *hero, atk *atk)
{
    rightatk *right = NULL;
    downatk *down = NULL;

    switch (hero->direction) {
        case 3:
            atk->down = init_down_atk(hero->direction);
            break;
        case 4:
            atk->right = init_right_atk(hero->direction);
            break;
    }
    return (atk);
}

atk *init_attack(hero_t *hero)
{
    atk *atk = malloc(sizeof(atk));
    leftatk *left = NULL;
    upatk *up = NULL;

    switch (hero->direction) {
        case 1:
            atk->up = init_up_atk(hero->direction);
            break;
        case 2:
            atk->left = init_left_atk(hero->direction);
            break;
        default:
            atk = init_atk_ext(hero, atk);
    }
    return (atk);
}