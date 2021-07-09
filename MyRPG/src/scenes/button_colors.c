/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

colors_t build_colors(sfColor n, sfColor ro, sfColor cl)
{
    colors_t colors;

    colors.normal = n;
    colors.rollover = ro;
    colors.clicked = cl;
    return (colors);
}

void init_b_colors(button_t *bt, colors_t colors)
{
    bt->colors.normal = colors.normal;
    bt->colors.rollover = colors.rollover;
    bt->colors.clicked = colors.clicked;
}