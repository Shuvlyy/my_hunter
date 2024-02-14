/*
** EPITECH PROJECT, 2023
** GOT_DUCKS
** File description:
** Got ducks scenery
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 30/11/23 15:14:38    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include "got_ducks.h"
#include "exit_messages.h"
#include "sh_mover.h"
#include "sh_audio_manager.h"
#include "sh_assets.h"
#include "sh_misc_lib.h"
#include "sh_animator.h"

int g_d_analyse_events(sh_game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event))
        handle_common_events(game, event);
    return SH_EXIT_SUCCESS;
}

static
int update_dog_status(sh_game_t *game)
{
    sh_dog_t *dog = game->dog;
    sh_animator_t *dog_anim = dog->sprite->animator;
    bool is_move_finished = dog->sprite->mover->finished;
    int dog_from_x = game->shot_ducks - 1 > 0 ? game->shot_ducks - 1 : 0;
    int res = 0;

    if (!is_move_finished)
        return SH_EXIT_SUCCESS;
    if (dog->state < DOG_GOT_DUCKS_4)
        dog->state++;
    else {
        reset_game(game, false);
        game->sessions += game->game_mode + 1;
        game->game_state = game->sessions >= 10 ? GS_ROUND_CHANGE : GS_PLAYING;
        return SH_EXIT_SUCCESS;
    }
    res = update_dog_animation(dog);
    dog_anim->from_x = dog_anim->width * dog_from_x;
    dog_anim->x = dog_anim->from_x;
    return res;
}

static
int display_window_content(sh_game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->dog->sprite->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sh_draw_hud(game);
    return SH_EXIT_SUCCESS;
}

static
void update_dog_anim(sh_game_t *game)
{
    sh_dog_t *dog = game->dog;
    sh_animator_t *dog_anim = dog->sprite->animator;
    int dog_from_x = game->shot_ducks - 1 > 0 ? game->shot_ducks - 1 : 0;

    dog->state = DOG_GOT_DUCKS_1;
    update_dog_animation(dog);
    dog_anim->from_x = dog_anim->width * dog_from_x;
}

int got_ducks(sh_game_t *game)
{
    sfEvent event;

    if (game->score > game->high_score)
        game->high_score = game->score;
    update_dog_anim(game);
    if (sh_play_audio(&game->audio, GOT_DUCKS_MUSIC_PATH) == SH_EXIT_FAILURE)
        return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    while (sfRenderWindow_isOpen(game->window)
        && game->game_state == GS_GOT_DUCKS) {
        g_d_analyse_events(game, &event);
        sfRenderWindow_clear(game->window, game->background_color);
        update_dog_status(game);
        sh_animate(game->dog->sprite);
        sh_move(game->dog->sprite);
        display_window_content(game);
        sfRenderWindow_display(game->window);
    }
    update_window(game);
    return 0;
}
