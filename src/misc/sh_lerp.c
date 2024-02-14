/*
** EPITECH PROJECT, 2023
** SH_LERP
** File description:
** Linear interpolation between two vectors
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 26/11/23 13:38:16    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <SFML/System/Vector2.h>
#include "sh_misc_lib.h"

sfVector2f sh_lerp(sfVector2f start, sfVector2f end, float time)
{
    sfVector2f result;

    result.x = start.x + time * (end.x - start.x);
    result.y = start.y + time * (end.y - start.y);
    return result;
}
