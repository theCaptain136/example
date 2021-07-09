/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void speed_text(int speed, sfRenderWindow *window)
{
    sfFont *font;
    sfText *buttont = sfText_create();
    sfVector2f text_pos = {600, 23};
    char *str = malloc(sizeof(char) * 20);

    font = sfFont_createFromFile("bonus/DejaVuSans.ttf");
    sfText_setFont(buttont, font);
    sfText_setCharacterSize(buttont, 30);
    sfText_setStyle(buttont, sfTextBold);
    sfText_setColor(buttont, sfColor_fromRGB(110, 59, 49));
    sfText_setOutlineColor(buttont, sfColor_fromRGB(143, 86, 7));
    sfText_setOutlineThickness(buttont, 1);
    sfText_setPosition(buttont, text_pos);
    my_strcpy(str, "SPEED\n   ");
    my_strcat_j(str, nb_to_str(speed));
    sfText_setString(buttont, str);
    sfRenderWindow_drawText(window, buttont, NULL);
    sfFont_destroy(font);
    sfText_destroy(buttont);
    free(str);
}

void xp_text(int level, int xp, sfRenderWindow *window, sfVector2f text_pos)
{
    sfFont *font = sfFont_createFromFile("bonus/DejaVuSans.ttf");
    sfText *buttont = sfText_create();
    char *str = malloc(sizeof(char) * 30);

    sfText_setFont(buttont, font);
    sfText_setCharacterSize(buttont, 30);
    sfText_setStyle(buttont, sfTextBold);
    sfText_setColor(buttont, sfColor_fromRGB(110, 59, 49));
    sfText_setOutlineColor(buttont, sfColor_fromRGB(143, 86, 7));
    sfText_setOutlineThickness(buttont, 1);
    sfText_setPosition(buttont, text_pos);
    my_strcpy(str, "LEVEL ");
    my_strcat_j(str, nb_to_str(level));
    my_strcat_j(str, "\n  ");
    my_strcat_j(str, nb_to_str(xp));
    sfText_setString(buttont, str);
    sfRenderWindow_drawText(window, buttont, NULL);
    sfFont_destroy(font);
    sfText_destroy(buttont);
    free(str);
}

void draw_convex(sfRenderWindow *window, sfConvexShape *gr, sfConvexShape *rd)
{
    sfConvexShape_setFillColor(gr, sfGreen);
    sfConvexShape_setOutlineColor(gr, sfWhite);
    sfConvexShape_setOutlineThickness(gr, 1);
    sfRenderWindow_drawConvexShape(window, gr, NULL);
    sfConvexShape_setFillColor(rd, sfRed);
    sfRenderWindow_drawConvexShape(window, rd, NULL);
}

void draw_bar(sfRenderWindow *window, int xp, sfVector2f pos)
{
    sfConvexShape *green = sfConvexShape_create();
    sfConvexShape *red = sfConvexShape_create();
    sfVector2f ul = {pos.x, pos.y};
    sfVector2f dl = {pos.x, pos.y + 25};
    sfVector2f ur = {pos.x + 200, pos.y};
    sfVector2f dr = {pos.x + 200, pos.y + 25};
    sfVector2f uborder = {pos.x + xp, pos.y};
    sfVector2f dborder = {pos.x + xp, pos.y + 25};

    sfConvexShape_setPointCount(green, 4);
    sfConvexShape_setPoint(green, 0, ur);
    sfConvexShape_setPoint(green, 1, ul);
    sfConvexShape_setPoint(green, 2, dl);
    sfConvexShape_setPoint(green, 3, dr);
    sfConvexShape_setPointCount(red, 4);
    sfConvexShape_setPoint(red, 0, uborder);
    sfConvexShape_setPoint(red, 1, ul);
    sfConvexShape_setPoint(red, 2, dl);
    sfConvexShape_setPoint(red, 3, dborder);
    draw_convex(window, green, red);
}

void draw_ui(sfRenderWindow *window, scene_t **scenes)
{
    sfVector2f text_pos = {1245, 23};
    sfVector2f pos = {1200, 65};

    speed_text(scenes[1]->game->hero_stat->speed, window);
    draw_bar(window, scenes[1]->game->hero_stat->xp, pos);
    xp_text(scenes[1]->game->lvl, scenes[1]->game->hero_stat->xp, \
        window, text_pos);
}