/*
** EPITECH PROJECT, 2020
** nb_to_str
** File description:
** .
*/

#include "../include/my_rpg.h"

char *minus_nb(int nb)
{
    char *str = malloc(sizeof(char) * 12);
    int i = 0;

    for (; nb != 0; i++) {
        str[i] = ((nb % 10 * -1) + '0');
        nb = nb / 10;
    }
    str[i] = '-';
    str[i + 1] = '\0';
    str = my_revstr(str);
    return (str);
}

int handle_minus(int nb)
{
    if (nb < 0)
        nb = nb * -1;
    return (nb);
}

char *create_str(char *str, int nb, int nbr, int count)
{
    int i = 0;

    for (; nb > 9; i++) {
        count = nb % 10;
        str[i] = count + 48;
        nb = nb / 10;
    }
    str[i] = nb + 48;
    i++;
    if (nbr < 0) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *handle_another_minus(char *str, int nb, int nbr)
{
    int count = 0;
    char *s1;

    count = count_digits(nb);
    str = malloc(sizeof(char) * (count + 2));
    nb = handle_minus(nb);
    str = create_str(str, nb, nbr, count);
    s1 = my_revstr(str);
    return (s1);
}

char *nb_to_str(int nbr)
{
    char *str = 0;
    int nb = nbr;

    if (nb == -2147483648) {
        str = minus_nb(nb);
        return (str);
    }
    str = handle_another_minus(str, nb, nbr);
    return (str);
}