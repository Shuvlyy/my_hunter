/*
** EPITECH PROJECT, 2023
** SH_GET_SECS_FROM_CLOCK
** File description:
** Get seconds from a clock
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 26/11/23 15:18:03    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include "sh_misc_lib.h"

double sh_get_secs_from_clock(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);

    return (double) time.microseconds / 1000000.0;
}
