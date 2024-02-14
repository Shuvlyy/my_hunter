/*
** EPITECH PROJECT, 2023
** SH_ANIMATOR_H
** File description:
** SH_ANIMATOR's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 21:24:12    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef SH_ANIMATOR_H
    #define SH_ANIMATOR_H
    #include <SFML/System/Clock.h>

typedef struct sh_sprite sh_sprite_t;

typedef struct sh_animator {
    sfClock *clock;
    double duration;
    int width;
    int height;
    int from_x;
    int from_y;
    int to_x;
    int x;
    bool finished;
} sh_animator_t;

sh_animator_t *sh_create_animator(void);
void sh_animate(sh_sprite_t *sprite);
void sh_destroy_animator(sh_animator_t *animator);

#endif /* SH_ANIMATOR_H */
