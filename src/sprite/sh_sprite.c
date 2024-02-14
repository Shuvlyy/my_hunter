/*
** EPITECH PROJECT, 2023
** SH_SPRITE
** File description:
** Sprite manager
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 16:51:25    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "sh_sprite.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"
#include "sh_animator.h"
#include "sh_mover.h"

sh_sprite_t *sh_create_sprite(char *texture_file_path)
{
    sh_sprite_t *sprite = malloc(sizeof(sh_sprite_t));

    sprite->sprite = sfSprite_create();
    if (sprite->sprite == NULL)
        return NULL;
    sprite->texture_file_path = texture_file_path;
    sprite->texture = sfTexture_createFromFile(
        sprite->texture_file_path, NULL);
    if (sprite->texture == NULL)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->animator = NULL;
    sprite->mover = NULL;
    return sprite;
}

void sh_set_texture_rect(sh_sprite_t *sprite, sfIntRect rect)
{
    sprite->texture_rect = rect;
    sfSprite_setTextureRect(sprite->sprite, sprite->texture_rect);
}

bool sh_is_sprite_clicked(sh_sprite_t *sprite, sfVector2i mouse_pos)
{
    sfVector2f sprite_pos = sfSprite_getPosition(sprite->sprite);
    sfVector2f sprite_origin = sfSprite_getOrigin(sprite->sprite);
    sfVector2f sprite_scale = sfSprite_getScale(sprite->sprite);
    sfVector2f sp_pos = (sfVector2f) {
        fabsf(sprite_pos.x - (sprite_origin.x * fabsf(sprite_scale.x))),
        sprite_pos.y - (sprite_origin.y * sprite_scale.y)};
    sfIntRect sprite_rect = sfSprite_getTextureRect(sprite->sprite);

    return mouse_pos.x >= sp_pos.x && mouse_pos.y >= sp_pos.y
        && mouse_pos.x <= sp_pos.x + sprite_rect.width * fabsf(sprite_scale.x)
        && mouse_pos.y <= sp_pos.y + sprite_rect.height * sprite_scale.y;
}

void sh_destroy_sprite(sh_sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    if (sprite->animator != NULL)
        sh_destroy_animator(sprite->animator);
    if (sprite->mover != NULL)
        sh_destroy_mover(sprite->mover);
    free(sprite);
}
