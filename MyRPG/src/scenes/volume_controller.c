/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

sfConvexShape *draw_controller_bar(sfVector2f pos, sfTexture *text)
{
    sfConvexShape *outline = sfConvexShape_create();

    sfConvexShape_setPointCount(outline, 6);
    sfConvexShape_setPoint(outline, 0, (sfVector2f){pos.x, pos.y});
    sfConvexShape_setPoint(outline, 1, (sfVector2f){pos.x - 400, pos.y});
    sfConvexShape_setPoint(outline, 2, (sfVector2f){pos.x - 410, pos.y - 10});
    sfConvexShape_setPoint(outline, 3, (sfVector2f){pos.x - 400, pos.y - 20});
    sfConvexShape_setPoint(outline, 4, (sfVector2f){pos.x, pos.y - 20});
    sfConvexShape_setPoint(outline, 5, (sfVector2f){pos.x + 10, pos.y - 10});
    sfConvexShape_setTexture(outline, text, sfTrue);
    return (outline);
}

void draw_controller_cir(scene_t **sc, sfVector2f pos, \
            sfRenderWindow *win, sfTexture *text)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f vol = {(pos.x - 400) + (4 * sc[1]->music_volume), pos.y - 10};

    sfCircleShape_setRadius(circle, 30.0);
    sfCircleShape_setOrigin(circle, (sfVector2f){30, 30});
    sfCircleShape_setTexture(circle, text, sfFalse);
    sfCircleShape_setPosition(circle, vol);
    sfRenderWindow_drawCircleShape(win, circle, NULL);
    sfCircleShape_destroy(circle);
}

void change_volume(sfVector2i ev, scene_t **scenes, sfVector2f pos)
{
    if (ev.y < pos.y - 40 || ev.y > pos.y + 20)
        return;
    if (ev.x < pos.x - 430 || ev.x > pos.x + 30)
        return;
    if (ev.x <= pos.x - 410) {
        scenes[1]->music_volume = 0;
        return;
    }
    if (ev.x >= pos.x + 10) {
        scenes[1]->music_volume = 100;
        return;
    }
    scenes[1]->music_volume = (ev.x - (pos.x - 400)) / 4;
}

void volume_controller(sfRenderWindow *window, scene_t **scenes)
{
    sfVector2f pos = {1160, 585};
    sfTexture *text = sfTexture_createFromFile("bonus/controller.png", NULL);
    static int prev = 20;

    if (scenes[1]->music_volume != prev)
        sfMusic_setVolume(scenes[1]->bg_music, scenes[1]->music_volume);
    sfRenderWindow_drawConvexShape(window, \
            draw_controller_bar(pos, text), NULL);
    draw_controller_cir(scenes, pos, window, text);
    prev = scenes[1]->music_volume;
}