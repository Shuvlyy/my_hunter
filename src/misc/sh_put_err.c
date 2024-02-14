/*
** EPITECH PROJECT, 2023
** SH_PUT_ERR
** File description:
** Prints an error to the standard error output
** and returns SH_EXIT_FAILURE (84).
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 23/11/23 11:43:39    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#include <unistd.h>
#include "sh_misc_lib.h"
#include "exit_messages.h"

int sh_put_err(char *err)
{
    write(2, err, sh_str_len(err));
    return SH_EXIT_FAILURE;
}
