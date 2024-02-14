/*
** EPITECH PROJECT, 2023
** RESOLUTION_H
** File description:
** Resolution manager
** Game will render in a 1:07:1 ratio,
** with a base resolution of 830x780.
** ------------------------------- **
** Written by Lysandre BOURSETTE   **
** (lysandre.boursette@epitech.eu) **
** Created on 22/11/23 20:36:02    **
** IDE used: CLion 2023.2.2        **
** github.com/shuvlyy              **
** ------------------------------- **
*/

#ifndef RESOLUTION_H
    #define RESOLUTION_H

typedef struct sh_resolution {
    unsigned int width;
    unsigned int height;
    unsigned int ppp;
} sh_resolution_t;

const sh_resolution_t BASE_RES = { 830, 780, 8 };

#endif /* RESOLUTION_H */
