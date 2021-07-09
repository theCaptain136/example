/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

scene_t *status_menu(scene_t *sc, sfVector2f size, colors_t colors, \
                                                sfTexture *texture)
{
    sfVector2f pos1 = {790, 115};
    sfVector2f pos = {280, 70};
    sfVector2f scale_bg = {0.25, 0.18};

    sc = malloc_scene(sc, 2);
    if (sc == NULL)
        return (NULL);
    init_button((sc->buttons[0]), pos1, size);
    sc->buttons[0]->callback = &bt_prev;
    sc->buttons[0]->name = button_text("BACK", 910, 135, 40);
    sfRectangleShape_setTexture(sc->buttons[0]->rect, texture, sfTrue);
    init_b_colors(sc->buttons[0], colors);
    sc->buttons[1] = NULL;
    if (new_node(sc->objs, "bonus/board.png", pos, scale_bg) == -1)
        return (NULL);
    sfSprite_setColor(sc->objs->end->sprite, sfColor_fromRGB(181, 136, 134));
    return (sc);
}

void draw_text_w(sfRenderWindow *win, sfVector2f text_pos, char *msg, int sz)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("bonus/DejaVuSans.ttf");

    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, sz);
    sfText_setColor(txt, sfWhite);
    sfText_setOutlineColor(txt, sfColor_fromRGB(70, 70, 70));
    sfText_setOutlineThickness(txt, 1);
    sfText_setPosition(txt, text_pos);
    sfText_setString(txt, msg);
    sfRenderWindow_drawText(win, txt, NULL);
    sfFont_destroy(font);
    sfText_destroy(txt);
}

void draw_player(sfRenderWindow **window, float scale, sfIntRect *rect)
{
    sfSprite *sprite = sfSprite_create();

    sfTexture *texture = sfTexture_createFromFile("./src/People3.png", rect);
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setOrigin(sprite, (sfVector2f){24, 48});
    sfSprite_setPosition(sprite, (sfVector2f){670, 560});
    sfSprite_setScale(sprite, (sfVector2f){4 / scale, 4 / scale});
    sfRenderWindow_drawSprite(*window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void draw_data(sfRenderWindow *win, scene_t **sc, char *level)
{
    float hp = 200.0 - (float)sc[1]->game->hero_stat->hp / \
        (float)sc[1]->game->hero_stat->max_hp * 200;

    if ((int)hp < 0)
        hp = 0;
    my_strcpy(level, "Level ");
    draw_text_w(win, (sfVector2f){820, 370}, my_strcat_j(level, \
        nb_to_str(sc[1]->game->lvl)), 50);
    draw_text_w(win, (sfVector2f){820, 450}, "HP", 45);
    draw_bar(win, (int)hp, (sfVector2f){920, 465});
    draw_text_w(win, (sfVector2f){820, 520}, "XP", 45);
    draw_bar(win, sc[1]->game->hero_stat->xp, (sfVector2f){920, 535});
    my_strcpy(level, "Speed:\t");
    draw_text_w(win, (sfVector2f){550, 620}, my_strcat_j(level, \
        nb_to_str(sc[1]->game->hero_stat->speed)), 45);
    my_strcpy(level, "Kills:\t\t");
    draw_text_w(win, (sfVector2f){550, 690}, \
        my_strcat_j(level, nb_to_str(sc[1]->game->hero_stat->kills)), 45);
    draw_text_w(win, (sfVector2f){1100, 620}, "Characteristics", 45);
    draw_text_w(win, (sfVector2f){1100, 690}, "goodness", 45);
}

void draw_status(sfRenderWindow *win, scene_t **scenes)
{
    char *level = malloc(sizeof(char) * 20);
    sfIntRect *rect = set_rect();

    rect->left = 337;
    rect->top = 0;
    draw_text_w(win, (sfVector2f){860, 260}, "Charis", 70);
    draw_player(&scenes[1]->game->window, scenes[1]->game->scale, rect);
    draw_data(win, scenes, level);
    free (level);
}