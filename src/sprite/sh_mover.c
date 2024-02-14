/*
** EPITECH PROJECT, 2023
** SH_MOVER
** File description:
** Movement manager for sprites
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 26/11/23 14:11:00    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <malloc.h>
#include "sh_mover.h"
#include "sh_sprite.h"
#include "sh_misc_lib.h"

sh_mover_t *sh_create_mover(void)
{
    sh_mover_t *mover = malloc(sizeof(sh_mover_t));

    mover->clock = sfClock_create();
    mover->from = (sfVector2f) { 0, 0 };
    mover->to = (sfVector2f) { 0, 0 };
    mover->time = 0.0f;
    mover->current = (sfVector2f) { 0, 0 };
    mover->finished = false;
    return mover;
}

void sh_move(sh_sprite_t *sprite)
{
    sh_mover_t *mover = sprite->mover;
    sfTime time_elapsed;
    float time_elapsed_seconds;
    float t;
    sfVector2f next_pos;

    if (mover->finished)
        return;
    time_elapsed = sfClock_getElapsedTime(mover->clock);
    time_elapsed_seconds = sfTime_asSeconds(time_elapsed);
    t = time_elapsed_seconds / mover->time;
    next_pos = sh_lerp(mover->from, mover->to, t);
    if (time_elapsed_seconds <= mover->time)
        sfSprite_setPosition(sprite->sprite, next_pos);
    else
        mover->finished = true;
}

void sh_destroy_mover(sh_mover_t *mover)
{
    sfClock_destroy(mover->clock);
    free(mover);
}
