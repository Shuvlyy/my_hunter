/*
** EPITECH PROJECT, 2023
** SH_ANIMATOR
** File description:
** Animation manager for sprites
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 21:24:12    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <malloc.h>
#include <stdlib.h>
#include "sh_sprite.h"
#include "sh_animator.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"

sh_animator_t *sh_create_animator(void)
{
    sh_animator_t *animator = malloc(sizeof(sh_animator_t));

    if (animator == NULL)
        return NULL;
    animator->clock = sfClock_create();
    if (animator->clock == NULL)
        return NULL;
    animator->duration = 0.0;
    animator->width = 0;
    animator->height = 0;
    animator->from_x = 0;
    animator->from_y = 0;
    animator->to_x = 0;
    animator->x = 0;
    animator->finished = false;
    return animator;
}

/*
 * TODO: Not optimised at all but fuck this shit.
 */
void sh_animate(sh_sprite_t *sprite)
{
    sh_animator_t *animator = sprite->animator;
    sfClock *clock = animator->clock;
    sfIntRect cropped_sprite = {
        animator->x,
        animator->from_y,
        animator->width,
        animator->height
    };

    sh_set_texture_rect(sprite, cropped_sprite);
    if (sh_get_secs_from_clock(clock) >= animator->duration) {
        animator->finished = true;
        animator->x += animator->width;
        if (animator->x > animator->to_x) {
            animator->x = animator->from_x;
        }
        sfClock_restart(clock);
    } else
        animator->finished = false;
}

void sh_destroy_animator(sh_animator_t *animator)
{
    sfClock_destroy(animator->clock);
    free(animator);
}
