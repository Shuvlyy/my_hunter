/*
** EPITECH PROJECT, 2023
** SH_MOVER_H
** File description:
** SH_MOVER's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 26/11/23 14:11:00    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef SH_MOVER_H
    #define SH_MOVER_H
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Clock.h>
    #include <stdbool.h>

typedef struct sh_sprite sh_sprite_t;

typedef struct sh_mover {
    sfClock *clock;
    sfVector2f from;
    sfVector2f to;
    float time;
    sfVector2f current;
    bool finished;
} sh_mover_t;

sh_mover_t *sh_create_mover(void);
void sh_move(sh_sprite_t *sprite);
void sh_destroy_mover(sh_mover_t *mover);

#endif /* SH_MOVER_H */
