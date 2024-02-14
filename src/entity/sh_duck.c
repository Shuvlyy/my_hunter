/*
** EPITECH PROJECT, 2023
** SH_DUCK
** File description:
** Duck entity
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 11:01:09    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include "sh_duck.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"
#include "sh_assets.h"
#include "sh_animator.h"
#include "sh_mover.h"
#include "sh_random.h"

sh_duck_t *create_duck(void)
{
    sh_duck_t *duck = malloc(sizeof(sh_duck_t));

    if (duck == NULL)
        return NULL;
    duck->sprite = sh_create_sprite(DUCK_FILE_PATH);
    if (duck->sprite == NULL)
        return NULL;
    sfSprite_setPosition(duck->sprite->sprite,
        (sfVector2f) { (float) get_random_number(60, 720), 500 });
    sfSprite_setScale(duck->sprite->sprite,
        (sfVector2f) { DUCK_SCALE, DUCK_SCALE });
    duck->sprite->animator = NULL;
    duck->sprite->mover = NULL;
    duck->state = DUCK_FLYING;
    duck->audio = NULL;
    duck->next = NULL;
    duck->points = NULL;
    sfSprite_setOrigin(duck->sprite->sprite, (sfVector2f) { 17, 15 });
    return duck;
}

static
void add_duck(sh_duck_t **ducks, sh_duck_t *duck)
{
    sh_duck_t *current = *ducks;

    duck->next = current;
    *ducks = duck;
}

int sh_add_duck(sh_duck_t **ducks)
{
    sh_duck_t *created_duck = create_duck();

    if (created_duck == NULL)
        return sh_put_err(MALLOC_FAIL_MSG);
    add_duck(ducks, created_duck);
    return SH_EXIT_SUCCESS;
}

static
void destroy_duck(sh_duck_t *duck)
{
    sh_destroy_sprite(duck->sprite);
    sfMusic_destroy(duck->audio);
    if (duck->points != NULL)
        sh_destroy_text(duck->points);
    free(duck);
}

void sh_destroy_ducks(sh_duck_t **ducks)
{
    sh_duck_t *current = *ducks;
    sh_duck_t *next;

    while (current != NULL) {
        next = current->next;
        destroy_duck(current);
        current = next;
    }
    *ducks = NULL;
}

static
int initialize_anim_mover(sh_duck_t *duck)
{
    if (duck->sprite->animator == NULL) {
        duck->sprite->animator = sh_create_animator();
        if (duck->sprite->animator == NULL)
            return sh_put_err(ANIMATOR_CREATE_FAIL_MSG);
    }
    if (duck->sprite->mover == NULL) {
        duck->sprite->mover = sh_create_mover();
        if (duck->sprite->mover == NULL)
            return sh_put_err(MOVER_CREATE_FAIL_MSG);
    }
    return SH_EXIT_SUCCESS;
}

static
void set_animator(sh_duck_t *duck)
{
    sh_animator_t *animator = duck->sprite->animator;
    unsigned char state = duck->state;

    animator->duration = DUCK_A_DURATIONS[state];
    animator->width = DUCK_A_WIDTHS[state];
    animator->height = DUCK_A_HEIGHTS[state];
    animator->from_x = DUCK_A_FROM_X[state];
    animator->from_y = DUCK_A_FROM_Y[state];
    animator->to_x = DUCK_A_TO_X[state];
    animator->x = DUCK_A_FROM_X[state];
}

static
void set_mover(sh_duck_t *duck, unsigned char round)
{
    sh_mover_t *mover = duck->sprite->mover;
    float speed = 200.0f + (round * 50);

    mover->from = sfSprite_getPosition(duck->sprite->sprite);
    if (duck->state == DUCK_FLYING)
        mover->to = (sfVector2f) {
            get_random_number(40, 750), get_random_number(40, 450)};
    else if (duck->state == DUCK_FALLING)
        mover->to = (sfVector2f) { mover->from.x, 600 };
    else
        mover->to = mover->from;
    if (duck->state == DUCK_SHOT)
        mover->time = 0.35f;
    else
        mover->time = sqrt(pow(mover->to.x - mover->from.x, 2) +
            pow(mover->to.y - mover->from.y, 2)) / speed;
    mover->finished = false;
    sfClock_restart(mover->clock);
}

int update_duck_animation(sh_duck_t *duck, unsigned char round)
{
    sfVector2f duck_scale = sfSprite_getScale(duck->sprite->sprite);

    if (initialize_anim_mover(duck) == SH_EXIT_FAILURE)
        return SH_EXIT_FAILURE;
    set_animator(duck);
    set_mover(duck, round);
    if (duck->sprite->mover->from.x > duck->sprite->mover->to.x)
        sfSprite_setScale(duck->sprite->sprite,
            (sfVector2f) {-duck_scale.x, duck_scale.y});
    else
        sfSprite_setScale(duck->sprite->sprite,
            (sfVector2f) { fabsf(duck_scale.x), duck_scale.y });
    return SH_EXIT_SUCCESS;
}
