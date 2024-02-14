/*
** EPITECH PROJECT, 2023
** ROUND_CHANGE
** File description:
** Round change scenery
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 11:33:31    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <malloc.h>
#include "round_change.h"
#include "sh_assets.h"
#include "sh_audio_manager.h"
#include "sh_misc_lib.h"
#include "window_manager.h"
#include "sh_animator.h"
#include "sh_mover.h"
#include "exit_messages.h"

void rc_analyse_events(sh_game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event))
        handle_common_events(game, event);
}

static
sh_sprite_t *get_round_tile(void)
{
    sh_sprite_t *round_tile = sh_create_sprite(ROUND_TILE_FILE_PATH);

    if (round_tile == NULL)
        return NULL;
    sfSprite_setScale(round_tile->sprite, (sfVector2f) { 3.5f, 3.5f });
    sfSprite_setPosition(round_tile->sprite, (sfVector2f) { 330, 150 });
    return round_tile;
}

static
sh_text_t *get_round_tile_n(sh_game_t *game)
{
    char *round_as_str = sh_uint_to_str(game->round);
    int original_x = 405;
    int round_as_str_len = sh_str_len(round_as_str);
    int round_offset = 14 * (round_as_str_len - 1);
    sh_text_t *round_tile_n = sh_create_text(round_as_str,
        original_x - round_offset, 215, SH_WHITE);

    if (round_as_str == NULL || round_tile_n == NULL)
        return NULL;
    free(round_as_str);
    return round_tile_n;
}

static
int update_dog_status(sh_game_t *game)
{
    sh_dog_t *dog = game->dog;
    bool is_move_finished = dog->sprite->mover->finished;

    if (!is_move_finished)
        return SH_EXIT_SUCCESS;
    if (dog->state < DOG_JUMPING_3)
        dog->state++;
    else {
        game->game_state = GS_PLAYING;
        return SH_EXIT_SUCCESS;
    }
    if (dog->state >= DOG_JUMPING_1)
        if (sh_dog_bark(game->dog) == SH_EXIT_FAILURE)
            return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    return update_dog_animation(dog);
}

static
int draw_sprites(sh_game_t *game)
{
    bool display_dog_front = game->dog->state < DOG_JUMPING_2;
    sh_sprite_t *first_sprite =
        display_dog_front ? game->map : game->dog->sprite;
    sh_sprite_t *second_sprite =
        display_dog_front ? game->dog->sprite : game->map;

    if (first_sprite == NULL || second_sprite == NULL)
        return sh_put_err(SPRITE_CREATE_FAIL_MSG);
    sfRenderWindow_drawSprite(game->window, first_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, second_sprite->sprite, NULL);
    return SH_EXIT_SUCCESS;
}

static
int display_win_content(
    sh_game_t *game, sh_sprite_t *round_tile, sh_text_t *round_tile_n
)
{
    if (update_dog_status(game) == SH_EXIT_FAILURE)
        return SH_EXIT_FAILURE;
    sh_animate(game->dog->sprite);
    sh_move(game->dog->sprite);
    draw_sprites(game);
    sh_draw_hud(game);
    sfRenderWindow_drawSprite(game->window, round_tile->sprite, NULL);
    sfRenderWindow_drawText(game->window, round_tile_n->text, NULL);
    return SH_EXIT_SUCCESS;
}

int round_change(sh_game_t *game)
{
    sfEvent event;
    sh_sprite_t *round_t = get_round_tile();
    sh_text_t *round_t_n = get_round_tile_n(game);

    game->sessions = 0;
    update_dog_animation(game->dog);
    if (sh_play_audio(&game->audio, INTRO_MUSIC_PATH) == SH_EXIT_FAILURE
        || round_t == NULL || round_t_n == NULL)
        return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    while (sfRenderWindow_isOpen(game->window)
        && game->game_state == GS_ROUND_CHANGE) {
        rc_analyse_events(game, &event);
        sfRenderWindow_clear(game->window, game->background_color);
        if (display_win_content(game, round_t, round_t_n) == SH_EXIT_FAILURE)
            return SH_EXIT_FAILURE;
        sfRenderWindow_display(game->window);
    }
    sh_destroy_sprite(round_t);
    sh_destroy_text(round_t_n);
    return update_window(game);
}
