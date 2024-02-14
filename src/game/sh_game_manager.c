/*
** EPITECH PROJECT, 2023
** SH_GAME_MANAGER
** File description:
** Game manager
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 12:22:45    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <unistd.h>
#include <stdlib.h>
#include "sh_game_manager.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"
#include "window_manager.h"
#include "title_screen.h"
#include "sh_assets.h"

static
void initialize_game_attributes(sh_game_t *game)
{
    game->shot_ducks = 0;
    game->game_state = GS_LOADING;
    game->game_mode = GM_ONE_DUCK;
    game->score = 0;
    game->high_score = 67000;
    game->round = 0;
    game->shots = MAX_SHOTS;
    game->sessions = 0;
    game->background_color = sfBlack;
    game->game_state = GS_TITLE_SCREEN;
}

static
int initialize_game_pointers(sh_game_t *game)
{
    game->audio = NULL;
    game->gunshot = NULL;
    game->map = NULL;
    game->dog = sh_create_dog();
    if (game->dog == NULL)
        return sh_put_err(SPRITE_CREATE_FAIL_MSG);
    game->ducks = NULL;
    game->timer = sfClock_create();
    game->hud = sh_create_hud(game);
    if (game->hud == NULL)
        return sh_put_err(SPRITE_CREATE_FAIL_MSG);
    game->map = sh_create_sprite(GAME_A_B_MAP_FILE_PATH);
    if (game->map == NULL)
        return sh_put_err(SPRITE_CREATE_FAIL_MSG);
    sfSprite_setScale(game->map->sprite, (sfVector2f) { 3.25f, 3.25f });
    game->window = initialize_window();
    if (game->window == NULL)
        return sh_put_err(SPRITE_CREATE_FAIL_MSG);
    return SH_EXIT_SUCCESS;
}

sh_game_t *initialize_game(void)
{
    sh_game_t *game = malloc(sizeof(sh_game_t));

    if (game == NULL)
        return NULL;
    srand(time(NULL));
    if (initialize_game_pointers(game) == SH_EXIT_FAILURE)
        return NULL;
    initialize_game_attributes(game);
    return game;
}

int end_game(sh_game_t *game, int status)
{
    game->game_state = GS_EXITING;
    destroy_window(game->window);
    destroy_hud(game->hud);
    if (game->audio != NULL)
        sfMusic_destroy(game->audio);
    if (game->gunshot != NULL)
        sfMusic_destroy(game->gunshot);
    sfClock_destroy(game->timer);
    sh_destroy_ducks(&game->ducks);
    sh_destroy_dog(game->dog);
    sh_destroy_sprite(game->map);
    free(game);
    return status;
}

int update_window(sh_game_t *game)
{
    if (game->game_state == GS_TITLE_SCREEN) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        return display_title_screen(game);
    }
    if (game->game_state > GS_TITLE_SCREEN
        && game->game_state < GS_EXITING) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        return game_loop(game);
    }
    return SH_EXIT_SUCCESS;
}

void handle_common_events(sh_game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        game->game_state = GS_EXITING;
    if (event->type == sfEvtMouseMoved) {
        sfSprite_setPosition(game->hud->cursor->sprite,
            (sfVector2f) { event->mouseMove.x - 19, event->mouseMove.y - 19 });
    }
}
