/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myworld-pablo-elias.herrmann
** File description:
** lava
*/

#include "my.h"

sfColor get_water_color(void)
{
    sfColor water = sfColor_fromRGBA(120, 30, 20, 180);

    water.b += rand() % 10;
    water.r -= rand() % 10;
    water.g += rand() % 10;
    return (water);
}

void lava_block(sfRenderWindow **win, sfVector2i ab, sfColor top, float scale)
{
    sfColor water = get_water_color();
    sfConvexShape *left;
    sfConvexShape *right;
    int y = ab.y;

    for (int i = 1; i < 4; i++) {
        if (top.g < 235)
            top.g += 20;
        top.b += 10;
        top.r += 5;
        ab.y = ab.y - 25 / scale;
    }
    right = draw_right_face((sfVector2i){ab.x, y}, scale, ab.y, water);
    sfRenderWindow_drawConvexShape(*win, right, NULL);
    sfConvexShape_destroy(right);
    left = draw_left_face((sfVector2i){ab.x, y}, scale, ab.y, water);
    sfRenderWindow_drawConvexShape(*win, left, NULL);
    sfConvexShape_destroy(left);
    full_tile(win, (sfVector2i){ab.x, ab.y - 100 / scale}, water, scale);
}