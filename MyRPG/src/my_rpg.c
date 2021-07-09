/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void free_scenes(scene_t **scenes)
{
    obj_t *tmp = malloc(sizeof(obj_t));

    if (scenes[1]->music_playing == 1)
        sfMusic_stop(scenes[1]->bg_music);
    sfMusic_destroy(scenes[1]->bg_music);
    for (int i = 0; scenes[i] != NULL; i++) {
        for (tmp = scenes[i]->objs->start; tmp != NULL; tmp = tmp->next) {
            sfTexture_destroy(tmp->texture);
            sfSprite_destroy(tmp->sprite);
        }
        free (scenes[i]->objs);
        for (int k = 0; scenes[i]->buttons[k] != NULL; k++) {
            sfText_destroy(scenes[i]->buttons[k]->name);
            sfRectangleShape_destroy(scenes[i]->buttons[k]->rect);
        }
        free (scenes[i]->buttons);
    }
    free (tmp);
}

sfVector2f cursorvector(sfRenderWindow *window)
{
    sfVector2f curvec;

    curvec.x = sfMouse_getPositionRenderWindow(window).x;
    curvec.y = sfMouse_getPositionRenderWindow(window).y;
    return (curvec);
}

int my_defender(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    scene_t **scenes = init_scenes();
    sfVector2f pos = {20, 950};
    sfVector2f scale = {0.15, 0.15};
    sfSprite *set = create_sprite("bonus/settings1.png", pos, scale);

    if (set == NULL || scenes == NULL)
        return (-1);
    window = sfRenderWindow_create(mode, "rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfMusic_play(scenes[1]->bg_music);
    if (game_loop(window, scenes, set) == -1)
        return (-1);
    free_level_struct(scenes[1]->game);
    free(scenes[1]->game);
    return (0);
}

int main(void)
{
    if (my_defender() == -1)
        return (84);
    return (0);
}