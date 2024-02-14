/*
** EPITECH PROJECT, 2023
** WINDOW_MANAGER
** File description:
** Window manager
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 11:38:00    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <stdarg.h>
#include "window_manager.h"
#include "resolution.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"
#include "sh_sprite.h"
#include "sh_game_manager.h"

/*
 * TODO:
 *  - Change resolution in title screen options
 *  - Make an option to go fullscreen
 */
sfRenderWindow *initialize_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {
        BASE_RES.width, BASE_RES.height, BASE_RES.ppp};

    window = sfRenderWindow_create(
        video_mode, WINDOW_TITLE, sfClose | sfResize, NULL);
    if (window == NULL)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, WINDOW_FRAMERATE);
    return window;
}

void destroy_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
}
