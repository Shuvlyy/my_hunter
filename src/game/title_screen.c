/*
** EPITECH PROJECT, 2023
** TITLE_SCREEN
** File description:
** Title screen scenery
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 16:41:39    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <SFML/Graphics.h>
#include <SFML/Audio/Music.h>
#include "title_screen.h"
#include "sh_text.h"
#include "sh_audio_manager.h"
#include "sh_assets.h"
#include "window_manager.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"

static
void process_key_pressed_event(sfKeyEvent key_event, sh_game_t *game)
{
    switch (key_event.code) {
        case sfKeyDown:
            if (game->game_mode < GM_TWO_DUCKS)
                game->game_mode++;
            break;
        case sfKeyUp:
            if (game->game_mode > GM_ONE_DUCK)
                game->game_mode--;
            break;
        case sfKeyEnter:
            game->game_state = GS_ROUND_CHANGE;
            break;
        default:
            break;
    }
}

static
void tc_analyse_events(sh_game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        handle_common_events(game, event);
        switch (event->type) {
            case sfEvtKeyPressed:
                process_key_pressed_event(event->key, game);
                break;
            default:
                return;
        }
    }
}

static
void display_window_content(
    sh_game_t *game,
    sh_sprite_t *title_screen,
    sh_sprite_t *arrow,
    sh_text_t *high_score
)
{
    sfRenderWindow_clear(game->window, game->background_color);
    sfSprite_setPosition(arrow->sprite,
        (sfVector2f) { 150, (float) (443 + (52 * game->game_mode)) });
    sfRenderWindow_drawSprite(game->window, title_screen->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, arrow->sprite, NULL);
    sfRenderWindow_drawText(game->window, high_score->text, NULL);
    sfRenderWindow_display(game->window);
}

/*
 * Outputted error can be inaccurate : if high_score has failed to create,
 * outputted error will be about sprites but yeah, coding style issue.
 */
int display_title_screen(sh_game_t *game)
{
    sfEvent event;
    sh_sprite_t *title_screen = sh_create_sprite(TS_TITLE_SCREEN_PATH);
    sh_sprite_t *arrow = sh_create_sprite(TS_ARROW_PATH);
    sh_text_t *high_score = sh_create_text(
        sh_uint_to_filled_str(game->high_score), 490, 620, SH_LIME);

    if (title_screen == NULL || arrow == NULL || high_score == NULL)
        return sh_put_err(SPRITE_CREATE_FAIL_MSG);
    if (sh_play_audio(&game->audio, TS_MUSIC_PATH) == SH_EXIT_FAILURE)
        return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    sfSprite_setScale(title_screen->sprite, (sfVector2f) { 3.25f, 3.25f });
    sfSprite_setScale(arrow->sprite, (sfVector2f) { 3.5f, 3.5f });
    while (sfRenderWindow_isOpen(game->window)
        && game->game_state == GS_TITLE_SCREEN) {
        tc_analyse_events(game, &event);
        display_window_content(game, title_screen, arrow, high_score);
    }
    sh_destroy_sprite(title_screen);
    sh_destroy_sprite(arrow);
    return update_window(game);
}
