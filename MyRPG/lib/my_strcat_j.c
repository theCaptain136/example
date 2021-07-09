/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** concatenate two strings
*/

#include <stdio.h>

char *my_strcat_j(char *dest, char const *src)
{
    int len = 0;
    int i = 0;

    while (dest[len] != '\0') {
        len++;
    }
    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
