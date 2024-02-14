/*
** EPITECH PROJECT, 2023
** SH_STR_LEN
** File description:
** Returns the length of a string (char *).
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 11:45:45    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

int sh_str_len(char const *str)
{
    int length = 0;

    for (; str[length] != '\0'; length++);
    return length;
}
