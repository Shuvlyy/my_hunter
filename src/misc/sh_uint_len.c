/*
** EPITECH PROJECT, 2023
** SH_UINT_LEN
** File description:
** Returns the length of an unsigned int
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 13:42:33    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include "sh_misc_lib.h"

int sh_uint_len(unsigned int number)
{
    int len = 0;

    for (; number > 0; number /= 10)
        len++;
    return len;
}
