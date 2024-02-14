/*
** EPITECH PROJECT, 2023
** SH_STR_CPY
** File description:
** Copies a given string to an empty string.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 18:37:26    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

char *sh_str_cpy(char *dest, char const *src)
{
    int k = 0;

    for (; src[k] != '\0'; k++)
        dest[k] = src[k];
    dest[k] = '\0';
    return dest;
}
