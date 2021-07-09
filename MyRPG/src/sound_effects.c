/*
** EPITECH PROJECT, 2021
** .
** File description:
** .
*/

#include "../include/my_rpg.h"

sound_t *init_one_se(char *filepath)
{
    sound_t *se = malloc(sizeof(sound_t));

    if (se == NULL)
        return (NULL);
    se->buffer = sfSoundBuffer_createFromFile(filepath);
    if (se->buffer == NULL)
        return (NULL);
    se->sound = sfSound_create();
    sfSound_setBuffer(se->sound, se->buffer);
    sfSound_setVolume(se->sound, 20);
    return (se);
}

s_effects_t *init_sound_eff(void)
{
    s_effects_t *sound_eff = malloc(sizeof(s_effects_t));

    if (sound_eff == NULL)
        return (NULL);
    sound_eff->hurt = init_one_se("bonus/sounds/hurt.ogg");
    sound_eff->score = init_one_se("bonus/sounds/Starlight.ogg");
    sound_eff->shot_enem = init_one_se("bonus/sounds/switch1.ogg");
    sound_eff->item = init_one_se("bonus/sounds/Item1.ogg");
    sound_eff->laser = init_one_se("bonus/sounds/laser.ogg");
    return (sound_eff);
}

void free_one_se(sound_t *sound)
{
    sfSoundBuffer_destroy(sound->buffer);
    sfSound_destroy(sound->sound);
}

void free_sound_eff(s_effects_t *se)
{
    free_one_se(se->hurt);
    free_one_se(se->item);
    free_one_se(se->score);
    free_one_se(se->shot_enem);
    free_one_se(se->laser);
    free (se);
}