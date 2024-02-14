/*
** EPITECH PROJECT, 2023
** SH_PUT_STR
** File description:
** Prints a given string to the standard output.
** Replicate of the libC "putstr" function.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 13:20:17    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <unistd.h>
#include "sh_misc_lib.h"

int sh_put_str(char const *str)
{
    return write(1, str, sh_str_len(str));
}
