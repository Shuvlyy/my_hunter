/*
** EPITECH PROJECT, 2023
** SH_GAME_MANAGER_H
** File description:
** SH_GAME_MANAGER's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 12:23:11    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef GAME_MANAGER_H
    #define GAME_MANAGER_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "sh_sprite.h"
    #include "sh_dog.h"
    #include "sh_hud.h"
    #include "sh_duck.h"

/*
 * Chars and shorts are used to save up some memory.
 * Maximum round is 100, the player can only shoot 3 times,
 * why should we allocate more ?
 */
typedef struct sh_game {
    sfRenderWindow *window;
    sfMusic *audio;
    sfMusic *gunshot;
    sh_sprite_t *map;
    sh_hud_t *hud;
    sfColor background_color;
    sh_dog_t *dog;
    sh_duck_t *ducks;
    unsigned char shot_ducks;
    unsigned char game_state;
    unsigned char game_mode;
    unsigned int score;
    unsigned int high_score;
    unsigned char round;
    unsigned char sessions;
    sfClock *timer;
    unsigned char shots;
} sh_game_t;

enum sh_game_state {
    GS_LOADING,
    GS_TITLE_SCREEN,
    GS_ROUND_CHANGE,
    GS_PLAYING,
    GS_FLY_AWAY,
    GS_GOT_DUCKS,
    GS_WIN,
    GS_GAME_OVER,
    GS_PAUSE,
    GS_EXITING
};

enum sh_game_mode {
    GM_ONE_DUCK,
    GM_TWO_DUCKS,
    GM_CLAY_SHOOTING
};

sh_game_t *initialize_game(void);
int end_game(sh_game_t *game, int status);
int update_window(sh_game_t *game);
void handle_common_events(sh_game_t *game, sfEvent *event);

#endif /* GAME_MANAGER_H */
