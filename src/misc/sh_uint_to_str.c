/*
** EPITECH PROJECT, 2023
** SH_UINT_TO_STR
** File description:
** Converts an unsigned int to a str.
** Filled str too.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 25/11/23 13:29:47    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <stdlib.h>
#include <string.h>
#include "sh_misc_lib.h"
#include "exit_messages.h"

static
unsigned int iterate_through_digit(unsigned short digit)
{
    unsigned int k = 1;

    while (digit > 0) {
        digit--;
        k *= 10;
    }
    return k;
}

char *sh_uint_to_str(unsigned int number)
{
    char *output;
    int number_len = sh_uint_len(number);
    unsigned short digit = 1;
    int k = 0;

    output = malloc((number_len + 2) * sizeof(char));
    if (output == NULL)
        return NULL;
    for (unsigned int tmp = number; tmp > 9; digit++)
        tmp /= 10;
    while (digit > 0) {
        digit--;
        output[k] = (number / iterate_through_digit(digit) % 10) + '0';
        k++;
    }
    output[k] = '\0';
    return output;
}

char *sh_uint_to_filled_str(unsigned int number)
{
    char *output;
    char *base_output = "000000";
    int base_output_len = sh_str_len(base_output);
    char *number_as_str = sh_uint_to_str(number);
    int number_len = sh_uint_len(number);

    if (number_as_str == NULL)
        return NULL;
    if (number_len == base_output_len)
        return number_as_str;
    output = malloc((base_output_len + 1) * sizeof(char));
    if (output == NULL)
        return NULL;
    memset(output, 0, base_output_len + 1);
    sh_str_ncat(output, base_output, base_output_len + 1 - number_len);
    if (number > 0)
        sh_str_cat(output, number_as_str);
    free(number_as_str);
    return output;
}
