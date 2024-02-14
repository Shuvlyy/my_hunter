/*
** EPITECH PROJECT, 2023
** SH_STR_NCAT
** File description:
** Same as sh_str_cat, but for the n first characters.
** Replicate of the libC "strncat" function.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 26/11/23 17:54:33    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include "sh_misc_lib.h"

char *sh_str_ncat(char *dest, char const *src, int n)
{
    int dest_len = sh_str_len(dest);

    return sh_str_ncpy(&dest[dest_len], src, n);
}
