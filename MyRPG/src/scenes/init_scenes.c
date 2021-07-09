/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

scene_t *help_but(scene_t *scene, sfVector2f sz, colors_t cl, sfTexture *tx)
{
    sfVector2f pos3 = {790, 280};

    init_button((scene->buttons[2]), pos3, sz);
    scene->buttons[2]->callback = &go_to_htp;
    scene->buttons[2]->name = button_text("HELP", 905, 300, 40);
    sfRectangleShape_setTexture(scene->buttons[2]->rect, tx, sfTrue);
    init_b_colors(scene->buttons[2], cl);
    scene->buttons[3] = NULL;
    return (scene);
}

scene_t *scene_1(scene_t *scene, sfVector2f sz, colors_t color, sfTexture *tx)
{
    sfVector2f pos1 = {790, 480};
    sfVector2f pos2 = {790, 680};

    scene = malloc_scene(scene, 4);
    if (scene == NULL)
        return (NULL);
    init_button((scene->buttons[0]), pos1, sz);
    scene->buttons[0]->callback = &restart;
    scene->buttons[0]->name = button_text("START", 900, 500, 40);
    sfRectangleShape_setTexture(scene->buttons[0]->rect, tx, sfTrue);
    init_b_colors(scene->buttons[0], color);
    init_button((scene->buttons[1]), pos2, sz);
    scene->buttons[1]->callback = &end_game;
    scene->buttons[1]->name = button_text("QUIT", 905, 700, 40);
    sfRectangleShape_setTexture(scene->buttons[1]->rect, tx, sfTrue);
    init_b_colors(scene->buttons[1], color);
    scene = help_but(scene, sz, color, tx);
    return (scene);
}

scene_t *scene_2(scene_t *sc, colors_t color)
{
    sfVector2f scale = {0.5, 0.5};

    sc = malloc_scene(sc, 2);
    if (sc == NULL)
        return (NULL);
    sc->current_sc = 0;
    sc->prev_m = 0;
    sc->bg_music = sfMusic_createFromFile("bonus/sounds/Trial.ogg");
    sc->music_playing = 1;
    sfMusic_setLoop(sc->bg_music, sfTrue);
    sfMusic_setVolume(sc->bg_music, 20);
    init_button(sc->buttons[0], (sfVector2f){820, 30}, (sfVector2f){280, 71});
    sc->buttons[0]->callback = &switch_scene;
    sc->buttons[0]->name = button_text("MENU", 900, 45, 35);
    init_tower_button(sc->buttons[0], "bonus/buttonbg.png", scale);
    sfRectangleShape_setTexture(sc->buttons[0]->rect, \
                    sc->buttons[0]->texture, sfTrue);
    init_b_colors(sc->buttons[0], color);
    sc->buttons[1] = NULL;
    return (sc);
}

scene_t **prep_data(scene_t **scenes, sfVector2f size, colors_t color, \
                                        sfTexture *texture)
{
    scenes[0] = scene_1(scenes[0], size, color, texture);
    scenes[1] = scene_2(scenes[1], color);
    scenes[2] = scene_menu(scenes[2], size, color, texture);
    scenes[3] = end_screen(scenes[3], size, color, texture);
    scenes[4] = lost_screen(scenes[4], size, color, texture);
    scenes[5] = how_to_play(scenes[5], size, color, texture);
    scenes[6] = settings_menu(scenes[6], size, color, texture);
    scenes[7] = inventory(scenes[7], size, color, texture);
    scenes[8] = status_menu(scenes[8], size, color, texture);
    scenes[9] = help(scenes[9], size, color, texture);
    scenes[10] = NULL;
    return (scenes);
}

scene_t **init_scenes(void)
{
    sfVector2f size = {350, 89};
    scene_t **scenes = malloc_scenes();
    colors_t color = build_colors(sfWhite, sfColor_fromRGB(133, 42, 30), \
        sfColor_fromRGB(50, 40, 40));
    sfTexture *texture = sfTexture_createFromFile("bonus/buttonbg.png", NULL);

    if (scenes == NULL)
        return (NULL);
    scenes = prep_data(scenes, size, color, texture);
    if (scenes[0] == NULL || scenes[1] == NULL || scenes[2] == NULL)
        return (NULL);
    scenes[1]->music_volume = 20;
    return (scenes);
}