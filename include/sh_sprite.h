/*
** EPITECH PROJECT, 2023
** SH_SPRITE_H
** File description:
** SH_SPRITE's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 16:51:25    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef SH_SPRITE_H
    #define SH_SPRITE_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct sh_animator sh_animator_t;
typedef struct sh_mover sh_mover_t;

typedef struct sh_sprite {
    sfSprite *sprite;
    char *texture_file_path;
    sfTexture *texture;
    sfIntRect texture_rect;
    sh_animator_t *animator;
    sh_mover_t *mover;
    bool finished;
} sh_sprite_t;

sh_sprite_t *sh_create_sprite(char *texture_file_path);
void sh_set_texture_rect(sh_sprite_t *sprite, sfIntRect rect);
bool sh_is_sprite_clicked(sh_sprite_t *sprite, sfVector2i mouse_pos);
void sh_destroy_sprite(sh_sprite_t *sprite);

#endif /* SH_SPRITE_H */
