/*
** EPITECH PROJECT, 2021
** B-PSU-200-BER-2-1-mysokoban-pablo-elias.herrmann
** File description:
** tools
*/

#include "my.h"

char *cp_snipet(char *str, int start, int end, int size)
{
    char *res = malloc((sizeof(char)) * size + 1);
    int counter = 0;

    for (int i = start; str[i] != '\0' && i < end; i++) {
        res[counter] = str[i];
        counter++;
    }
    res[counter] = '\0';
    return (res);
}

int sizeof_line(char *str, int n, int *pos)
{
    int start = n;

    while (str[n] != '\0' && str[n] != '\n') {
        n++;
    }
    *pos = n;
    return (n - start);
}

int get_nb_rows(char *sub_res)
{
    int res = 0;

    for (int i = 0; sub_res[i] != '\0'; i++) {
        if (sub_res[i] == '\n')
            res++;
    }
    res--;
    return (res);
}

int x_center(char **map)
{
    int i = 0;
    int store = 0;

    for (i; map[i] != NULL; i++) {
        if (my_strlen(map[i]) > store)
            store = my_strlen(map[i]);
    }
    return (store);
}

void X_check(char **str, char **tmp, int i, int *res)
{
    for (int s = 0; str[i][s] != '\0'; s++) {
        if (tmp[i][s] == 'O' && str[i][s] == 'X') {
            *res = *res + 1;
        }
    }
    return;
}