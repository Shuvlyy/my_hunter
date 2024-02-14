/*
** EPITECH PROJECT, 2023
** SH_HUD
** File description:
** Hud manager
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 27/11/23 06:52:35    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <malloc.h>
#include "sh_hud.h"
#include "sh_game_manager.h"
#include "sh_misc_lib.h"
#include "window_manager.h"
#include "sh_game.h"
#include "exit_messages.h"
#include "sh_assets.h"

static
void set_bullets_background(sh_game_t *game)
{
    sh_hud_t *hud = game->hud;

    if (hud->bullets_hide_rect == NULL)
        hud->bullets_hide_rect = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->bullets_hide_rect,
        (sfVector2f) { 26 * (MAX_SHOTS - game->shots), 32 });
    sfRectangleShape_setPosition(hud->bullets_hide_rect,
        (sfVector2f) { 155 - 26 * (MAX_SHOTS - game->shots), 670 });
    sfRectangleShape_setFillColor(hud->bullets_hide_rect, sfBlack);
}

static
void set_round_background(sh_game_t *game)
{
    sh_hud_t *hud = game->hud;
    int round_len = sh_uint_len(game->round) - 1;

    if (hud->round_background == NULL)
        hud->round_background = sfRectangleShape_create();
    if (round_len < 0)
        round_len = 0;
    sfRectangleShape_setSize(hud->round_background,
        (sfVector2f) { 25 * round_len, 26 });
    sfRectangleShape_setPosition(hud->round_background,
        (sfVector2f) { 180 - (26 * round_len), 624 });
    sfRectangleShape_setFillColor(hud->round_background, sfBlack);
}

static
sh_sprite_t *create_cursor(void)
{
    sh_sprite_t *cursor = sh_create_sprite(CURSOR_PATH);

    if (cursor == NULL)
        return NULL;
    sfSprite_setScale(cursor->sprite, (sfVector2f) { 2.75f, 2.75f });
    return cursor;
}

int sh_update_hud(sh_game_t *game)
{
    sh_hud_t *hud = game->hud;
    char *round_as_string = sh_uint_to_str(game->round);

    if (hud->round == NULL)
        hud->round = sh_create_text("", 128, 620, SH_GREEN);
    if (hud->score == NULL)
        hud->score = sh_create_text("", 625, 670, SH_WHITE);
    sfText_setString(hud->round->text, round_as_string);
    sfText_setString(hud->score->text, sh_uint_to_filled_str(game->score));
    set_bullets_background(game);
    set_round_background(game);
    free(round_as_string);
    return SH_EXIT_SUCCESS;
}

sh_hud_t *sh_create_hud(sh_game_t *game)
{
    sh_hud_t *hud = malloc(sizeof(sh_hud_t));

    hud->round = NULL;
    hud->round_background = NULL;
    hud->score = NULL;
    hud->bullets_hide_rect = NULL;
    hud->cursor = create_cursor();
    game->hud = hud;
    return hud;
}

void sh_draw_hud(sh_game_t *game)
{
    sh_hud_t *hud = game->hud;

    sfRenderWindow_drawText(game->window, hud->score->text, NULL);
    sfRenderWindow_drawRectangleShape(
        game->window, hud->round_background, NULL);
    sfRenderWindow_drawText(game->window, hud->round->text, NULL);
    sfRenderWindow_drawRectangleShape(
        game->window, hud->bullets_hide_rect, NULL);
    sfRenderWindow_drawSprite(game->window, hud->cursor->sprite, NULL);
}

void destroy_hud(sh_hud_t *hud)
{
    if (hud->round != NULL)
        sh_destroy_text(hud->round);
    if (hud->round_background != NULL)
        sfRectangleShape_destroy(hud->round_background);
    if (hud->score != NULL)
        sh_destroy_text(hud->score);
    if (hud->bullets_hide_rect != NULL)
        sfRectangleShape_destroy(hud->bullets_hide_rect);
    if (hud->cursor != NULL)
        sh_destroy_sprite(hud->cursor);
    free(hud);
}
