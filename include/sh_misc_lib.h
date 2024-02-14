/*
** EPITECH PROJECT, 2023
** SH_MISC_LIB_H
** File description:
** Miscellaneous library
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 11:45:32    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef SH_MISC_LIB_H
    #define SH_MISC_LIB_H
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Clock.h>

int sh_str_len(char const *str);
int sh_put_err(char *err);
int sh_put_str(char const *str);
int sh_str_cmp(char const *s1, char const *s2);
char *sh_uint_to_str(unsigned int number);
char *sh_uint_to_filled_str(unsigned int number);
int sh_uint_len(unsigned int number);
char *sh_str_cat(char *dest, char const *src);
char *sh_str_ncat(char *dest, char const *src, int n);
char *sh_str_cpy(char *dest, char const *src);
char *sh_str_ncpy(char *dest, char const *src, int n);
sfVector2f sh_lerp(sfVector2f start, sfVector2f end, float time);
double sh_get_secs_from_clock(sfClock *clock);

#endif /* SH_MISC_LIB_H */
