/*
** EPITECH PROJECT, 2023
** SH_DUCK_H
** File description:
** SH_DUCK's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 11:01:09    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef SH_DUCK_H
    #define SH_DUCK_H
    #define DUCK_SCALE 2.75f
    #include <SFML/Audio/Music.h>
    #include "sh_sprite.h"
    #include "sh_text.h"

typedef struct sh_duck {
    sh_sprite_t *sprite;
    unsigned char state;
    sfMusic *audio;
    sh_text_t *points;
    struct sh_duck *next;
} sh_duck_t;

enum sh_duck_status {
    DUCK_FLYING,
    DUCK_SHOT,
    DUCK_FALLING,
    DUCK_LANDED
};

static
const double DUCK_A_DURATIONS[] = {
    0.15f, 2.0f, 0.1f
};

static
const int DUCK_A_WIDTHS[] = {
    34, 34, 34, 0
};

static
const int DUCK_A_HEIGHTS[] = {
    31, 31, 31, 0
};

static
const int DUCK_A_FROM_X[] = {
    102, 204, 238, 0
};

static
const int DUCK_A_FROM_Y[] = {
    0, 0, 0, 0
};

static
const int DUCK_A_TO_X[] = {
    170, 204, 272, 0
};

int sh_add_duck(sh_duck_t **ducks);
void sh_destroy_ducks(sh_duck_t **ducks);
int update_duck_animation(sh_duck_t *duck, unsigned char round);

#endif /* SH_DUCK_H */
