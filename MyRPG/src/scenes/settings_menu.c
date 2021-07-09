/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

void bt_prev(sfRenderWindow *window, int *c, int prev)
{
    if (*c == 9) {
        *c = 5;
        return;
    }
    *c = prev;
}

void init_tower_button(button_t *button, char *filepath, sfVector2f scale)
{
    button->texture = sfTexture_createFromFile(filepath, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setScale(button->sprite, scale);
    button->filepath = malloc(sizeof(char) * (my_strlen(filepath) + 1));
    my_strcpy(button->filepath, filepath);
}

scene_t *soundef_buttons(scene_t *scene, sfVector2f size, colors_t color)
{
    sfVector2f pos3 = {700, 660};
    sfVector2f pos4 = {1160, 660};
    sfVector2f orig = {0.15, 0.15};

    init_button(scene->music_b[1], pos3, size);
    init_tower_button(scene->music_b[1], "bonus/wooden_play.png", orig);
    sfRectangleShape_setTexture(scene->music_b[1]->rect, \
                    scene->music_b[1]->texture, sfTrue);
    scene->music_b[1]->m_callback = &unmute_se;
    scene->music_b[1]->name = button_text("Sound effects", 850, 670, 35);
    init_b_colors(scene->music_b[1], color);
    init_button(scene->music_b[2], pos4, size);
    init_tower_button(scene->music_b[2], "bonus/wooden_pause.png", orig);
    sfRectangleShape_setTexture(scene->music_b[2]->rect, \
                    scene->music_b[2]->texture, sfTrue);
    scene->music_b[2]->m_callback = &mute_se;
    scene->music_b[2]->name = button_text("Sound effects", 850, 670, 35);
    init_b_colors(scene->music_b[2], color);
    scene->music_b[3] = NULL;
    return (scene);
}

scene_t *music_buttons(scene_t *scene, colors_t color, sfVector2f orig, \
                                            sfVector2f szb)
{
    sfVector2f pos1 = {-700, -530};

    init_button(scene->music_b[0], pos1, szb);
    init_tower_button(scene->music_b[0], "bonus/wooden_play.png", orig);
    sfRectangleShape_setTexture(scene->music_b[0]->rect, \
                    scene->music_b[0]->texture, sfTrue);
    scene->music_b[0]->m_callback = &start_music;
    scene->music_b[0]->name = button_text("Music", 915, 500, 35);
    init_b_colors(scene->music_b[0], color);
    scene = soundef_buttons(scene, szb, color);
    return (scene);
}

scene_t *settings_menu(scene_t *scene, sfVector2f size, colors_t colors, \
                                                sfTexture *texture)
{
    sfVector2f pos1 = {790, 380};
    sfVector2f scale = {0.15, 0.15};
    sfVector2f szb = {480 * 0.15, 473 * 0.15};

    scene = malloc_scene(scene, 2);
    if (scene == NULL)
        return (NULL);
    init_button((scene->buttons[0]), pos1, size);
    scene->buttons[0]->callback = &bt_prev;
    scene->buttons[0]->name = button_text("BACK", 910, 400, 40);
    sfRectangleShape_setTexture(scene->buttons[0]->rect, texture, sfTrue);
    init_b_colors(scene->buttons[0], colors);
    scene->buttons[1] = NULL;
    scene = malloc_mb(scene, 5);
    if (scene == NULL)
        return (NULL);
    scene = music_buttons(scene, colors, scale, szb);
    return (scene);
}