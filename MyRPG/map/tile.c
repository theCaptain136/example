/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myworld-pablo-elias.herrmann
** File description:
** tile
*/

#include "my.h"

sfConvexShape *draw_left_face(sfVector2i xy, float scl, int b, sfColor water)
{
    sfConvexShape *outline = sfConvexShape_create();
    int point = xy.x - 100 / scl;

    sfConvexShape_setPointCount(outline, 4);
    sfConvexShape_setPoint(outline, 0, (sfVector2f){xy.x, xy.y});
    sfConvexShape_setPoint(outline, 1, (sfVector2f){point, xy.y - 50 / scl});
    sfConvexShape_setPoint(outline, 3, (sfVector2f){xy.x, b});
    sfConvexShape_setPoint(outline, 2, (sfVector2f){point, b - (50 / scl)});
    sfConvexShape_setFillColor(outline, water);
    sfConvexShape_setOutlineColor(outline, sfBlack);
    sfConvexShape_setOutlineThickness(outline, (float)2);
    return (outline);
}

sfConvexShape *draw_right_face(sfVector2i xy, float scl, int b, sfColor water)
{
    sfConvexShape *outline = sfConvexShape_create();
    int point = xy.x + 100 / scl;

    sfConvexShape_setPointCount(outline, 4);
    sfConvexShape_setPoint(outline, 0, (sfVector2f){xy.x, xy.y});
    sfConvexShape_setPoint(outline, 1, (sfVector2f){xy.x, b});
    sfConvexShape_setPoint(outline, 3, (sfVector2f){point, xy.y - 50 / scl});
    sfConvexShape_setPoint(outline, 2, (sfVector2f){point, b - (50 / scl)});
    sfConvexShape_setFillColor(outline, water);
    sfConvexShape_setOutlineColor(outline, sfBlack);
    sfConvexShape_setOutlineThickness(outline, (float)2);
    return (outline);
}