/*
** EPITECH PROJECT, 2023
** SH_RANDOM
** File description:
** Random number generator
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 23:16:27    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <stdlib.h>
#include <time.h>
#include "sh_random.h"

int get_random_number(int a, int b)
{
    return rand() % (b - a + 1) + a;
}
