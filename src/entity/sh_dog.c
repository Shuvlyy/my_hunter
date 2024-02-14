/*
** EPITECH PROJECT, 2023
** SH_DOG
** File description:
** Dog entity
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 11:01:48    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <stdlib.h>
#include "sh_dog.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"
#include "sh_assets.h"
#include "sh_animator.h"
#include "sh_mover.h"

sh_dog_t *sh_create_dog(void)
{
    sh_dog_t *dog = malloc(sizeof(sh_dog_t));

    if (dog == NULL)
        return NULL;
    dog->sprite = sh_create_sprite(DOG_FILE_PATH);
    if (dog->sprite == NULL)
        return NULL;
    sfSprite_setScale(dog->sprite->sprite,
        (sfVector2f) { DOG_SCALE, DOG_SCALE });
    dog->sprite->animator = NULL;
    dog->sprite->mover = NULL;
    dog->state = DOG_WALKING;
    dog->audio = NULL;
    return dog;
}

void sh_destroy_dog(sh_dog_t *dog)
{
    sh_destroy_sprite(dog->sprite);
    sfMusic_destroy(dog->audio);
}

int sh_dog_bark(sh_dog_t *dog)
{
    if (dog->audio != NULL)
        sfMusic_destroy(dog->audio);
    dog->audio = sfMusic_createFromFile(DOG_BARK_PATH);
    if (dog->audio == NULL)
        return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    sfMusic_setVolume(dog->audio, 20);
    sfMusic_play(dog->audio);
    return SH_EXIT_SUCCESS;
}

static
int initialize_anim_mover(sh_dog_t *dog)
{
    if (dog->sprite->animator == NULL) {
        dog->sprite->animator = sh_create_animator();
        if (dog->sprite->animator == NULL)
            return sh_put_err(ANIMATOR_CREATE_FAIL_MSG);
    }
    if (dog->sprite->mover == NULL) {
        dog->sprite->mover = sh_create_mover();
        if (dog->sprite->mover == NULL)
            return sh_put_err(MOVER_CREATE_FAIL_MSG);
    }
    return SH_EXIT_SUCCESS;
}

static
void set_animator(sh_dog_t *dog)
{
    sh_animator_t *animator = dog->sprite->animator;
    unsigned char state = dog->state;

    animator->duration = DOG_A_DURATIONS[state];
    animator->width = DOG_A_WIDTHS[state];
    animator->height = DOG_A_HEIGHTS[state];
    animator->from_x = DOG_A_FROM_X[state];
    animator->from_y = DOG_A_FROM_Y[state];
    animator->to_x = DOG_A_TO_X[state];
    animator->x = DOG_A_FROM_X[state];
}

static
void set_mover(sh_dog_t *dog)
{
    sh_mover_t *mover = dog->sprite->mover;
    unsigned char state = dog->state;

    if (DOG_M_FROM[state].x == -1)
        mover->from = sfSprite_getPosition(dog->sprite->sprite);
    else
        mover->from = DOG_M_FROM[state];
    if (DOG_M_TO[state].x == -1)
        mover->to = sfSprite_getPosition(dog->sprite->sprite);
    else
        mover->to = DOG_M_TO[state];
    mover->time = M_TIMES[state];
    mover->finished = false;
    sfClock_restart(mover->clock);
}

int update_dog_animation(sh_dog_t *dog)
{
    if (initialize_anim_mover(dog) == SH_EXIT_FAILURE)
        return SH_EXIT_FAILURE;
    set_animator(dog);
    set_mover(dog);
    return SH_EXIT_SUCCESS;
}
