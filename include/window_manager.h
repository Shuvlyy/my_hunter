/*
** EPITECH PROJECT, 2023
** WINDOW_MANAGER_H
** File description:
** WINDOW_MANAGER's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 11:38:00    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef WINDOW_MANAGER_H
    #define WINDOW_MANAGER_H
    #define WINDOW_TITLE "My Hunter"
    #define WINDOW_FRAMERATE 60

typedef struct sh_game sh_game_t;

sfRenderWindow *initialize_window(void);
void destroy_window(sfRenderWindow *window);

#endif /* WINDOW_MANAGER_H */
