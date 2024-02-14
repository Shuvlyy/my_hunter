/*
** EPITECH PROJECT, 2023
** SH_STR_NCPY
** File description:
** Same as sh_str_cpy, but for the n first characters.
** Replicate of the libC "strncpy" function.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 26/11/23 17:55:30    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

char *sh_str_ncpy(char *dest, const char *src, int n)
{
    while (n > 1 && *src != '\0') {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    if (n > 0)
        *dest = '\0';
    return dest;
}
