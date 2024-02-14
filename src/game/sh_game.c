/*
** EPITECH PROJECT, 2023
** SH_GAME
** File description:
** Game display redirector
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 21/11/23 20:49:24    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include "sh_game_manager.h"
#include "round_change.h"
#include "sh_game.h"
#include "playing.h"
#include "exit_messages.h"
#include "fly_away.h"
#include "got_ducks.h"

static
void update_round(sh_game_t *game)
{
    if (game->round < MAX_ROUNDS)
        game->round++;
    else
        game->round = 1;
    game->background_color = sfColor_fromRGB(99, 173, 255);
    game->dog->state = DOG_WALKING;
}

void reset_game(sh_game_t *game, bool hard_reset)
{
    sh_destroy_ducks(&game->ducks);
    game->shot_ducks = 0;
    game->shots = MAX_SHOTS;
    sfClock_restart(game->timer);
    if (hard_reset) {
        game->round = 0;
        game->dog->state = DOG_WALKING;
        game->game_mode = GM_ONE_DUCK;
        game->score = 0;
        game->sessions = 0;
    }
}

int game_loop(sh_game_t *game)
{
    switch (game->game_state) {
        case GS_ROUND_CHANGE:
            update_round(game);
            sh_update_hud(game);
            return round_change(game);
        case GS_PLAYING:
            sfClock_restart(game->timer);
            for (int k = 0; k < game->game_mode + 1; k++)
                sh_add_duck(&game->ducks);
            return playing(game);
        case GS_FLY_AWAY:
            return fly_away(game);
        case GS_GOT_DUCKS:
            return got_ducks(game);
        default:
            return SH_EXIT_FAILURE;
    }
}
