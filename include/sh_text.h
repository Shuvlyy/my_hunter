/*
** EPITECH PROJECT, 2023
** SH_TEXT_H
** File description:
** SH_TEXT's header
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 17:03:40    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef SH_TEXT_H
    #define SH_TEXT_H
    #define TEXT_FONT_SIZE 26

typedef struct sh_text {
    sfText *text;
    sfFont *font;
} sh_text_t;

enum sh_text_colors {
    SH_WHITE = 0XFFFFFFFF,
    SH_LIME = 0X53F24FFF,
    SH_GREEN = 0X8CD600FF,
    SH_ORANGE = 0XFC9838FF
};

sh_text_t *sh_create_text(char *str, int x, int y, unsigned int color);
sh_text_t *sh_create_mini_text(char *str, int x, int y, unsigned int color);
void sh_destroy_text(sh_text_t *text);

#endif /* SH_TEXT_H */
