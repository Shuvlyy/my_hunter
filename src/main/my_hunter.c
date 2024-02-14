/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** Video game based on the rules of Duck Hunt, a 1984 NES game.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 21/11/23 19:59:45    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_hunter.h"
#include "sh_game_manager.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"

static
int display_help(char **argv)
{
    for (int k = 0; HELP_FLAGS[k] != NULL; k++) {
        if (sh_str_cmp(argv[1], HELP_FLAGS[k]) == 0) {
            write(STDOUT_FILENO, HELP_MESSAGE, sh_str_len(HELP_MESSAGE));
            return SH_EXIT_SUCCESS;
        }
    }
    return sh_put_err(UNKNOWN_FLAG_MSG);
}

int main(int argc, char **argv)
{
    sh_game_t *game;

    if (argc >= 2)
        return display_help(argv);
    game = initialize_game();
    if (game == NULL)
        return SH_EXIT_FAILURE;
    update_window(game);
    return end_game(game, SH_EXIT_SUCCESS);
}
