/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void restart_game(scene_t **scenes, sfRenderWindow *window, sfSprite *set)
{
    int music_playing = scenes[1]->music_playing;
    int music_volume = scenes[1]->music_volume;

    if (scenes[1]->current_sc == 5) {
        display_help(scenes, window, set);
    } else {
        free_scenes(scenes);
        scenes = init_scenes();
        scenes[1]->current_sc = 1;
        scenes[1]->music_playing = music_playing;
        scenes[1]->music_volume = music_volume;
        sfMusic_setVolume(scenes[1]->bg_music, music_volume);
        if (scenes[1]->music_playing == 1)
            sfMusic_play(scenes[1]->bg_music);
        game_loop(window, scenes, set);
        sfRenderWindow_close(window);
    }
}