/*
** EPITECH PROJECT, 2023
** SH_TEXT
** File description:
** Text manager
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 17:03:40    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "sh_text.h"
#include "sh_misc_lib.h"
#include "exit_messages.h"
#include "sh_assets.h"

sh_text_t *sh_create_text(char *str, int x, int y, unsigned int color)
{
    sh_text_t *text = malloc(sizeof(sh_text_t));
    sfText *text_t;
    sfFont *text_f;
    sfColor text_color = sfColor_fromInteger(color);

    if (text == NULL)
        return NULL;
    text_t = sfText_create();
    text_f = sfFont_createFromFile(TEXT_FONT_PATH);
    if (text_t == NULL || text_f == NULL)
        return NULL;
    sfText_setString(text_t, str);
    sfText_setFont(text_t, text_f);
    sfText_setCharacterSize(text_t, TEXT_FONT_SIZE);
    sfText_setColor(text_t, text_color);
    sfText_setPosition(text_t, (sfVector2f) { (float) x, (float) y });
    text->text = text_t;
    text->font = text_f;
    return text;
}

sh_text_t *sh_create_mini_text(char *str, int x, int y, unsigned int color)
{
    sh_text_t *text = malloc(sizeof(sh_text_t));
    sfText *text_t;
    sfFont *text_f;
    sfColor text_color = sfColor_fromInteger(color);

    if (text == NULL)
        return NULL;
    text_t = sfText_create();
    text_f = sfFont_createFromFile(TEXT_MINI_FONT_PATH);
    if (text_t == NULL || text_f == NULL)
        return NULL;
    sfText_setString(text_t, str);
    sfText_setFont(text_t, text_f);
    sfText_setCharacterSize(text_t, TEXT_FONT_SIZE);
    sfText_setColor(text_t, text_color);
    sfText_setPosition(text_t, (sfVector2f) { (float) x, (float) y });
    text->text = text_t;
    text->font = text_f;
    return text;
}

void sh_destroy_text(sh_text_t *text)
{
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    free(text);
}
