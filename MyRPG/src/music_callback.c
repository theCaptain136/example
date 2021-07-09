/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

void start_music(int *music_playing, sfMusic *bg_music, s_effects_t *se)
{
    if (*music_playing != 1) {
        *music_playing = 1;
        sfMusic_play(bg_music);
    }
}

void stop_music(int *music_playing, sfMusic *bg_music, s_effects_t *se)
{
    if (*music_playing == 1) {
        *music_playing = 0;
        sfMusic_stop(bg_music);
    }
}

void mute_se(int *mp, sfMusic *mu, s_effects_t *sound_eff)
{
    sfSound_setVolume(sound_eff->hurt->sound, 0);
    sfSound_setVolume(sound_eff->score->sound, 0);
    sfSound_setVolume(sound_eff->shot_enem->sound, 0);
    sfSound_setVolume(sound_eff->item->sound, 0);
    sfSound_setVolume(sound_eff->laser->sound, 0);
}

void unmute_se(int *mp, sfMusic *mu, s_effects_t *sound_eff)
{
    sfSound_setVolume(sound_eff->hurt->sound, 20);
    sfSound_setVolume(sound_eff->score->sound, 20);
    sfSound_setVolume(sound_eff->shot_enem->sound, 20);
    sfSound_setVolume(sound_eff->item->sound, 20);
    sfSound_setVolume(sound_eff->laser->sound, 20);
}