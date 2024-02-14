/*
** EPITECH PROJECT, 2023
** PLAYING
** File description:
** Playing scenery
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 27/11/23 16:05:22    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include "playing.h"
#include "sh_animator.h"
#include "sh_mover.h"
#include "sh_audio_manager.h"
#include "sh_assets.h"
#include "exit_messages.h"
#include "sh_misc_lib.h"

int p_shoot_duck(sh_game_t *game, sh_duck_t *duck)
{
    sfVector2f d_pos = sfSprite_getPosition(duck->sprite->sprite);

    game->shot_ducks++;
    game->score += 500;
    duck->state = DUCK_SHOT;
    duck->points = sh_create_mini_text("500", d_pos.x, d_pos.y, SH_WHITE);
    if (duck->points == NULL)
        return SH_EXIT_FAILURE;
    duck->sprite->mover->finished = true;
    update_duck_animation(duck, game->round);
    return SH_EXIT_SUCCESS;
}

static
int process_click_event(
    sh_game_t *game, sfMouseButtonEvent event, bool is_party_finished
)
{
    sh_duck_t *duck = game->ducks;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    int res = 0;

    if (event.button != sfMouseLeft || is_party_finished || game->shots == 0)
        return SH_EXIT_SUCCESS;
    game->shots--;
    if (sh_play_audio(&game->gunshot, GUNSHOT_PATH) == SH_EXIT_FAILURE)
        return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    while (duck != NULL) {
        if (sh_is_sprite_clicked(duck->sprite, mouse_pos)
            && duck->state == DUCK_FLYING)
            res = p_shoot_duck(game, duck);
        duck = duck->next;
    }
    if (res == SH_EXIT_FAILURE)
        return res;
    return sh_update_hud(game);
}

int p_analyse_events(
    sh_game_t *game, sfEvent *event, bool is_party_finished
)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        handle_common_events(game, event);
        if (event->type == sfEvtMouseButtonPressed)
            return process_click_event(
                game, event->mouseButton, is_party_finished);
    }
    return SH_EXIT_SUCCESS;
}

static
int update_duck_status(sh_duck_t *duck, unsigned char round)
{
    sh_animator_t *duck_anim = duck->sprite->animator;

    if (duck->state == DUCK_FLYING && duck_anim->finished)
        sh_play_audio(&duck->audio, DUCK_FLAPPING_PATH);
    if (!duck->sprite->mover->finished)
        return SH_EXIT_SUCCESS;
    if (duck->state == DUCK_FALLING) {
        duck->state++;
        if (sh_play_audio(&duck->audio, DUCK_LANDED_PATH) == SH_EXIT_FAILURE)
            return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    }
    if (duck->state == DUCK_SHOT) {
        duck->state++;
        if (sh_play_audio(&duck->audio, DUCK_FALLING_PATH) == SH_EXIT_FAILURE)
            return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    }
    if (duck->state == DUCK_LANDED)
        sfText_setScale(duck->points->text, (sfVector2f) { 0, 0 });
    return update_duck_animation(duck, round);
}

static
int is_play_finished(sh_game_t *game)
{
    sh_duck_t *duck = game->ducks;
    sfTime timer_elapsed_time = sfClock_getElapsedTime(game->timer);
    float elapsed_time_as_sec = sfTime_asSeconds(timer_elapsed_time);

    if (elapsed_time_as_sec >= MAX_PLAY_TIME)
        return 1 + (game->shot_ducks > 0);
    if (game->shots == 0 && game->shot_ducks == 0)
        return 1;
    while (duck != NULL) {
        if (game->shots == 0 && duck->state == DUCK_FLYING)
            return 2;
        if (duck->state != DUCK_LANDED)
            return 0;
        duck = duck->next;
    }
    return 2;
}

static
int display_window_content(sh_game_t *game)
{
    sh_duck_t *current_duck = game->ducks;

    while (current_duck != NULL) {
        if (update_duck_status(current_duck, game->round) == SH_EXIT_FAILURE)
            return SH_EXIT_FAILURE;
        sh_animate(current_duck->sprite);
        sh_move(current_duck->sprite);
        sfRenderWindow_drawSprite(
            game->window, current_duck->sprite->sprite, NULL);
        if (current_duck->points != NULL)
            sfRenderWindow_drawText(
                game->window, current_duck->points->text, NULL);
        current_duck = current_duck->next;
    }
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sh_draw_hud(game);
    return SH_EXIT_SUCCESS;
}

static
void update_ducks_animations(sh_game_t *game)
{
    sh_duck_t *current = game->ducks;

    while (current != NULL) {
        update_duck_animation(current, game->round);
        current = current->next;
    }
}

int playing(sh_game_t *game)
{
    sfEvent evt;
    int is_party_finished = 0;

    sh_update_hud(game);
    update_ducks_animations(game);
    while (sfRenderWindow_isOpen(game->window)
        && game->game_state == GS_PLAYING) {
        is_party_finished = is_play_finished(game);
        if (p_analyse_events(game, &evt, is_party_finished) == SH_EXIT_FAILURE)
            return SH_EXIT_FAILURE;
        game->game_state += is_party_finished;
        sfRenderWindow_clear(game->window, game->background_color);
        if (display_window_content(game) == SH_EXIT_FAILURE)
            return SH_EXIT_FAILURE;
        sfRenderWindow_display(game->window);
    }
    update_window(game);
    return SH_EXIT_SUCCESS;
}
