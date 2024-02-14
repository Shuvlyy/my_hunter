/*
** EPITECH PROJECT, 2023
** SH_DOG_H
** File description:
** SH_DOG's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 11:01:48    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef SH_DOG_H
    #define SH_DOG_H
    #define DOG_SCALE 2.75f
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio/Music.h>
    #include "sh_sprite.h"

typedef struct sh_dog {
    sh_sprite_t *sprite;
    unsigned char state;
    sfMusic *audio;
} sh_dog_t;

enum sh_dog_status {
    DOG_WALKING,
    DOG_SNIFFING,
    DOG_FOUND,
    DOG_JUMPING_1,
    DOG_JUMPING_2,
    DOG_JUMPING_3,
    DOG_LAUGHING_1,
    DOG_LAUGHING_2,
    DOG_LAUGHING_3,
    DOG_LAUGHING_4,
    DOG_GOT_DUCKS_1,
    DOG_GOT_DUCKS_2,
    DOG_GOT_DUCKS_3,
    DOG_GOT_DUCKS_4,
};

static
const double DOG_A_DURATIONS[] = {
    .15f,
    .15f,
    2.0f,
    2.0f, 2.0f, 2.0f,
    .15f, .15f, .15f, 2.0f,
    2.0f, 2.0f, 2.0f, 2.0f
};

static
const int DOG_A_WIDTHS[] = {
    56,
    56,
    56,
    56, 56, 56,
    56, 56, 56, 56,
    56, 56, 56, 56
};

static
const int DOG_A_HEIGHTS[] = {
    48,
    48,
    48,
    48, 48, 48,
    40, 40, 40, 40,
    58, 58, 58, 58
};

static
const int DOG_A_FROM_X[] = {
    0,
    0,
    0,
    0, 56, 56,
    0, 0, 0, 0,
    0, 0, 0, 0
};

static
const int DOG_A_FROM_Y[] = {
    0,
    48,
    96,
    144, 144, 144,
    250, 250, 250, 250,
    192, 192, 192, 192
};

static
const int DOG_A_TO_X[] = {
    168,
    56,
    0,
    0, 56, 56,
    56, 56, 56, 56,
    0, 0, 0, 0
};

static
const sfVector2f DOG_M_FROM[] = {
    { 30, 485 },
    { -1, -1 },
    { -1, -1 },
    { -1, -1 }, { -1, -1 }, { -1, -1 },
    { 330, 520 }, { -1, -1 }, { 330, 410 }, { -1, -1 },
    { 330, 520 }, { -1, -1 }, { 330, 360 }, { -1, -1 }
};

static
const sfVector2f DOG_M_TO[] = {
    { 250, 485 },
    { -1, -1 },
    { -1, -1 },
    { 280, 380 }, { 335, 350 }, { 390, 520 },
    { 330, 410 }, { -1, -1 }, { 330, 520 }, { -1, -1 },
    { 330, 360 }, { -1, -1 }, { 330, 520 }, { -1, -1 }
};

static
const float M_TIMES[] = {
    5.4f,
    .8f,
    .4f,
    .25f, .25f, .25f,
    .8f, 1.0f, .8f, .7f,
    .5f, .5f, .5f, .3f
};

sh_dog_t *sh_create_dog(void);
void sh_destroy_dog(sh_dog_t *dog);
int sh_dog_bark(sh_dog_t *dog);
int update_dog_animation(sh_dog_t *dog);

#endif /* SH_DOG_H */
