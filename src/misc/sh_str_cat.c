/*
** EPITECH PROJECT, 2023
** SH_STR_CAT
** File description:
** Concats a given string to another string and returns it.
** Replicate of the libC "strcat" function.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 18:36:08    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include "sh_misc_lib.h"

char *sh_str_cat(char *dest, char const *src)
{
    int dest_len = sh_str_len(dest);

    return sh_str_cpy(&dest[dest_len], src);
}
