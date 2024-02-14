/*
** EPITECH PROJECT, 2023
** SH_AUDIO_MANAGER
** File description:
** Audio manager to harmonize the volume.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 17:53:02    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <SFML/Audio.h>
#include "sh_audio_manager.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"

/*
 * TODO: Replace by game->settings->overall_volume or something like that
 */
int sh_play_audio(sfMusic **audio, char *audio_file_path)
{
    if (*audio == NULL) {
        *audio = sfMusic_createFromFile(audio_file_path);
        if (*audio == NULL)
            return sh_put_err(AUDIO_CREATE_FAIL_MSG);
    } else {
        sfMusic_stop(*audio);
        sfMusic_destroy(*audio);
        *audio = NULL;
        sh_play_audio(audio, audio_file_path);
    }
    sfMusic_setVolume(*audio, 20);
    sfMusic_play(*audio);
    return SH_EXIT_SUCCESS;
}
