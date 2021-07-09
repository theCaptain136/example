/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** simple_tile
*/

#include "my.h"

void draw_convex_c(sfConvexShape *convex, sfColor col, \
                        sfRenderWindow **win, int fl)
{
    sfConvexShape_setFillColor(convex, col);
    sfConvexShape_setOutlineColor(convex, sfBlack);
    sfConvexShape_setOutlineThickness(convex, (float)fl);
    sfRenderWindow_drawConvexShape(*win, convex, NULL);
}

sfConvexShape *draw_tile(sfRenderWindow **win, sfVector2i ab, \
                            sfVector2f gs, sfColor color)
{
    sfConvexShape *cx = sfConvexShape_create();

    if (gs.x == 0) {
        sfConvexShape_setPointCount(cx, 3);
        sfConvexShape_setPoint(cx, 0, (sfVector2f){ab.x, ab.y});
        sfConvexShape_setPoint(cx, 1, (sfVector2f){ab.x, ab.y + 100 / gs.y});
        sfConvexShape_setPoint(cx, 2, (sfVector2f){ab.x + 100 / \
            gs.y, ab.y + 50 / gs.y});
        draw_convex_c(cx, color, win, 0);
    }
    else if (gs.x == 1) {
        sfConvexShape_setPointCount(cx, 3);
        sfConvexShape_setPoint(cx, 0, (sfVector2f){ab.x, ab.y});
        sfConvexShape_setPoint(cx, 1, (sfVector2f){ab.x, ab.y + 100 / gs.y});
        sfConvexShape_setPoint(cx, 2, (sfVector2f){ab.x - 100 / \
            gs.y, ab.y + 50 / gs.y});
        draw_convex_c(cx, color, win, 0);
    }
    return (cx);
}

void full_tile(sfRenderWindow **win, sfVector2i ab, sfColor cl, float sc)
{
    sfConvexShape *outline = sfConvexShape_create();
    sfConvexShape *right;
    sfConvexShape *left;
    int y = ab.y + 50 / sc;

    sfConvexShape_setPointCount(outline, 4);
    sfConvexShape_setPoint(outline, 0, (sfVector2f){ab.x, ab.y});
    sfConvexShape_setPoint(outline, 2, (sfVector2f){ab.x, ab.y + 100 / sc});
    sfConvexShape_setPoint(outline, 1, (sfVector2f){ab.x - 100 / sc, y});
    sfConvexShape_setPoint(outline, 3, (sfVector2f){ab.x + 100 / sc, y});
    draw_convex_c(outline, cl, win, 2);
    sfConvexShape_destroy(outline);
    right = draw_tile(win, (sfVector2i){ab.x, ab.y}, (sfVector2f){0, sc}, cl);
    left = draw_tile(win, (sfVector2i){ab.x, ab.y}, (sfVector2f){1, sc}, cl);
    sfConvexShape_destroy(right);
    sfConvexShape_destroy(left);
}

void full_block(sfRenderWindow **window, sfVector2f ab, \
                    sfVector2f hscale, sfSprite *sprite)
{
    if (hscale.x <= 0)
        return;
    for (int i = 0; i < hscale.x - 1; i++) {
        ab.y = ab.y - 25 / hscale.y;
    }
    sfSprite_setPosition(sprite, ab);
    sfRenderWindow_drawSprite(*window, sprite, NULL);
    return;
}