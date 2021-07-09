/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../../include/my_rpg.h"

scene_t **init_nodes(scene_t **scenes)
{
    sfVector2f bg_pos = {0, -200};
    sfVector2f bg_sc = {1, 1};
    sfVector2f orig = {0, 0};

    if (scenes[0]->objs == NULL || scenes[1]->objs == NULL || \
        scenes[2]->objs == NULL || scenes[3]->objs == NULL || \
        scenes[4]->objs == NULL || scenes[5]->objs == NULL || \
        scenes[6]->objs == NULL || scenes[8]->objs == NULL || \
        scenes[7]->objs == NULL || scenes[9]->objs == NULL)
        return (NULL);
    if (new_node(scenes[0]->objs, "bonus/menu1.jpg", bg_pos, bg_sc) == -1)
        return (NULL);
    if (new_node(scenes[5]->objs, "bonus/htp.png", orig, bg_sc) == -1)
        return (NULL);
    if (new_node(scenes[6]->objs, "bonus/menu1.jpg", bg_pos, bg_sc) == -1)
        return (NULL);
    if (new_node(scenes[9]->objs, "bonus/menu1.jpg", bg_pos, bg_sc) == -1)
        return (NULL);
    init_inventory_nodes(scenes[7], bg_sc);
    return (scenes);
}

scene_t **malloc_scenes(void)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * 11);

    if (scenes == NULL)
        return (NULL);
    for (int i = 0; i < 11; i++) {
        scenes[i] = malloc(sizeof(scene_t));
        if (scenes[i] == NULL)
            return (NULL);
    }
    for (int i = 0; i < 10; i++)
        scenes[i]->objs = create_list();
    scenes = init_nodes(scenes);
    if (scenes == NULL)
        return (NULL);
    return (scenes);
}

scene_t *malloc_scene(scene_t *scene, int count)
{
    scene->buttons = malloc(sizeof(button_t *) * count);
    for (int i = 0; i < count; i++) {
        scene->buttons[i] = malloc(sizeof(button_t));
        if (scene->buttons[i] == NULL)
            return (NULL);
    }
    return (scene);
}

scene_t *malloc_mb(scene_t *scene, int count)
{
    scene->music_b = malloc(sizeof(button_t *) * count);
    for (int i = 0; i < count; i++) {
        scene->music_b[i] = malloc(sizeof(button_t));
        if (scene->music_b[i] == NULL)
            return (NULL);
    }
    return (scene);
}