/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** change_lvl
*/

#include "../include/my_rpg.h"

void free_level_struct2(level_t *l)
{
    sfConvexShape_destroy(l->hero_stat->hp_bar1);
    sfConvexShape_destroy(l->hero_stat->hp_bar2);
    free(l->hero_stat);
    free(l->list);
    sfClock_destroy(l->npc->glock);
    sfClock_destroy(l->npc->lil_glock);
    sfSprite_destroy(l->npc->sprite);
    for (int i = 0; l->npc->texts[i] != NULL; i++)
        sfText_destroy(l->npc->texts[i]);
}

void free_level_struct(level_t *l)
{
    free(l->map->map);
    free(l->map);
    sfSound_destroy(l->sound_eff->hurt->sound);
    sfSoundBuffer_destroy(l->sound_eff->hurt->buffer);
    sfSound_destroy(l->sound_eff->item->sound);
    sfSoundBuffer_destroy(l->sound_eff->item->buffer);
    sfSound_destroy(l->sound_eff->score->sound);
    sfSoundBuffer_destroy(l->sound_eff->score->buffer);
    sfSound_destroy(l->sound_eff->shot_enem->sound);
    sfSoundBuffer_destroy(l->sound_eff->shot_enem->buffer);
    free(l->sound_eff->hurt);
    free(l->sound_eff->item);
    free(l->sound_eff->score);
    free(l->sound_eff->shot_enem);
    free(l->sound_eff);
    sfClock_destroy(l->timer2);
    sfClock_destroy(l->timer3);
    sfClock_destroy(l->timer);
    free_level_struct2(l);
}

void change_level(scene_t **sc, sfRenderWindow *window)
{
    int lvl = sc[1]->game->lvl;

    if (sc[1]->game->lvl == 4 && sc[1]->game->npc->interacted == -1) {
        sc[1]->game->lvl = 5;
        return;
    }
    if (sc[1]->game->npc->interacted == -1) {
        free_level_struct(sc[1]->game);
        free(sc[1]->game);
        if (lvl == 1)
            sc[1]->game = set_level(window, "map/maps/map2", 2);
        if (lvl == 2)
            sc[1]->game = set_level(window, "map/maps/map3", 3);
        if (lvl == 3)
            sc[1]->game = set_level(window, "map/maps/map5", 4);
        next_level_msg(window, sc);
    }
}