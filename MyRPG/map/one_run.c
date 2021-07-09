/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** one_run
*/

#include "my.h"

int draw_level(level_t *l)
{
    if (!l->window)
        return EXIT_FAILURE;
    if (l->npc->interacted == 0)
        move(l->map, l->hero_stat, l);
    aim(l->hero_stat);
    l->map->map = level(l->map->map, l);
    clocks(l);
    sfRenderWindow_clear(l->window, sfBlack);
    draw_map(&l->window, l);
    interact_with_npc(l);
    draw_enemy(l->list, l);
    hero(l);
    if (sfKeyboard_isKeyPressed(sfKeySpace) && l->count2 > \
    l->hero_stat->atk_speed && l->npc->interacted == 0) {
        attack_melee(l, l->hero_stat->dmg_type);
        l->count2 = 0;
    }
    aggro(l);
    thunder(l);
    return EXIT_SUCCESS;
}

void clocks2(level_t *l)
{
    if (l->npc != NULL)
        if (sfClock_getElapsedTime(l->npc->glock).microseconds > 1000000 / 5) {
            l->npc->time += 1;
            sfClock_restart(l->npc->glock);
        }
    if (zero_point_two_five_clock(sfClock_getElapsedTime(l->timer4), \
    &l->timer4))
        l->count4++;
}

void clocks(level_t *l)
{
    if (zero_point_two_five_clock(sfClock_getElapsedTime(l->timer), \
        &l->timer) && l->hero_stat->direction != -1)
        l->count++;
    if (zero_point_two_five_clock(sfClock_getElapsedTime(l->timer2), \
        &l->timer2))
        l->count2++;
    if (enemy_clock(sfClock_getElapsedTime(l->timer3), &l->timer3))
        l->count3++;
    clocks2(l);
}

int get_map_size(int *map)
{
    int res = 0;

    for (int i = 0; map[i] != -1; i++) {
        res++;
    }
    return (res - 1);
}