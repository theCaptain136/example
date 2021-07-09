/*
** EPITECH PROJECT, 2020
** nb_to_str_cd.c
** File description:
** .
*/

int count_digits(int nb)
{
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    if (nb == 0)
        count++;
    for (; nb > 0; count++) {
        nb = nb / 10;
    }
    return (count);
}
