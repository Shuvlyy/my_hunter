/*
** EPITECH PROJECT, 2023
** SH_GAME_H
** File description:
** SH_GAME's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 21/11/23 20:49:24    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef GAME_H
    #define GAME_H
    #include "sh_game_manager.h"
    #define MAX_SHOTS 3
    #define MAX_ROUNDS 99

enum sh_background_colors {
    BG_PEACH_EYES = 0XFFCCC5FF,
    BG_BLUE_SKIES = 0X63AFFFFF
};

int game_loop(sh_game_t *game);
void reset_game(sh_game_t *game, bool hard_reset);

#endif /* GAME_H */
