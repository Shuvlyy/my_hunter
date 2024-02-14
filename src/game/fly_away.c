/*
** EPITECH PROJECT, 2023
** FLY_AWAY
** File description:
** Fly away scenery
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 29/11/23 12:53:45    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include "fly_away.h"
#include "exit_messages.h"
#include "sh_game.h"
#include "sh_assets.h"
#include "sh_misc_lib.h"
#include "sh_mover.h"
#include "sh_animator.h"
#include "sh_audio_manager.h"

int f_a_analyse_events(sh_game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event))
        handle_common_events(game, event);
    return SH_EXIT_SUCCESS;
}

static
sh_sprite_t *get_fly_away_tile(void)
{
    sh_sprite_t *fly_away_tile = sh_create_sprite(FLY_AWAY_FILE_PATH);

    if (fly_away_tile == NULL)
        return NULL;
    sfSprite_setScale(fly_away_tile->sprite, (sfVector2f) { 3.25f, 3.25f });
    sfSprite_setPosition(fly_away_tile->sprite, (sfVector2f) { 325, 190 });
    return fly_away_tile;
}

static
int update_dog_status(sh_game_t *game)
{
    sh_dog_t *dog = game->dog;
    bool is_move_finished = dog->sprite->mover->finished;

    if (!is_move_finished)
        return SH_EXIT_SUCCESS;
    if (dog->state < DOG_LAUGHING_4)
        dog->state++;
    else {
        game->game_state = GS_TITLE_SCREEN;
        return SH_EXIT_SUCCESS;
    }
    return update_dog_animation(dog);
}

static
int display_window_2_content(sh_game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->dog->sprite->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sh_draw_hud(game);
    return SH_EXIT_SUCCESS;
}

int fly_away_2(sh_game_t *game)
{
    sfEvent event;

    game->dog->state = DOG_LAUGHING_1;
    update_dog_animation(game->dog);
    game->background_color = sfColor_fromInteger(BG_BLUE_SKIES);
    sh_play_audio(&game->dog->audio, DOG_LAUGHING_PATH);
    while (sfRenderWindow_isOpen(game->window)
        && game->game_state == GS_FLY_AWAY) {
        f_a_analyse_events(game, &event);
        sfRenderWindow_clear(game->window, game->background_color);
        update_dog_status(game);
        sh_animate(game->dog->sprite);
        sh_move(game->dog->sprite);
        display_window_2_content(game);
        sfRenderWindow_display(game->window);
    }
    reset_game(game, true);
    update_window(game);
    return 0;
}

static
int display_window_1_content(sh_game_t *game, sh_sprite_t *fly_away_tile)
{
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fly_away_tile->sprite, NULL);
    sh_draw_hud(game);
    return SH_EXIT_SUCCESS;
}

int fly_away(sh_game_t *game)
{
    sfEvent event;
    sh_sprite_t *fly_away_tile = get_fly_away_tile();
    sfClock *scene_time = sfClock_create();

    if (fly_away_tile == NULL)
        return sh_put_err(SPRITE_CREATE_FAIL_MSG);
    game->background_color = sfColor_fromInteger(BG_PEACH_EYES);
    while (sfRenderWindow_isOpen(game->window)
        && game->game_state == GS_FLY_AWAY) {
        f_a_analyse_events(game, &event);
        if (sfTime_asSeconds(sfClock_getElapsedTime(scene_time)) > 1.0f)
            break;
        sfRenderWindow_clear(game->window, game->background_color);
        display_window_1_content(game, fly_away_tile);
        sfRenderWindow_display(game->window);
    }
    sfClock_destroy(scene_time);
    sh_destroy_sprite(fly_away_tile);
    fly_away_2(game);
    return 0;
}
