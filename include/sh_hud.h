/*
** EPITECH PROJECT, 2023
** SH_HUD_H
** File description:
** SH_HUD's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 27/11/23 06:52:36    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef SH_HUD_H
    #define SH_HUD_H
    #include <SFML/Graphics/Types.h>
    #include "sh_text.h"

typedef struct sh_game sh_game_t;
typedef struct sh_sprite sh_sprite_t;

/*
 * TODO: Ducks viewer
 */
typedef struct sh_hud {
    sh_text_t *round;
    sfRectangleShape *round_background;
    sh_text_t *score;
    sfRectangleShape *bullets_hide_rect;
    sh_sprite_t *cursor;
} sh_hud_t;

int sh_update_hud(sh_game_t *game);
sh_hud_t *sh_create_hud(sh_game_t *game);
void sh_draw_hud(sh_game_t *game);
void destroy_hud(sh_hud_t *hud);

#endif /* SH_HUD_H */
