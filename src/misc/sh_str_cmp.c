/*
** EPITECH PROJECT, 2023
** SH_STR_CMP
** File description:
** Returns the difference between two strings.
** If both strings are the same, returns 0.
** Replicate of the libC "strcmp" function.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 13:00:12    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

int sh_str_cmp(char const *s1, char const *s2)
{
    while (*s1 == *s2 && *s1 != 0) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
