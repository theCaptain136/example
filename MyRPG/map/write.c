/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myworld-pablo-elias.herrmann
** File description:
** write
*/

#include "my.h"

bool save_to_file(int *map, int size)
{
    size = size * size;
    FILE *fd = fopen("./saves/saves.txt", "a");
    char *save = malloc((sizeof(char)) * (size * 5) + 1);
    char *tmp = NULL;

    save[0] = '/';
    save[1] = '/';
    save[2] = '/';
    save[3] = '/';
    save[4] = '\0';
    for (int i = 0; i < size; i++) {
        tmp = my_nbr_to_str(map[i]);
        add_to_str(&save, tmp);
        free(tmp);
    }
    fwrite(save, 1, (size_t)my_strlen(save), fd);
    fclose(fd);
    return (true);
}

void add_to_str(char **one, char *snipped)
{
    int i = my_strlen(*one);
    int snip_c = 0;

    for (int s = i; s < my_strlen(*one) + my_strlen(snipped) + 1; s++) {
        (*one)[s] = snipped[snip_c];
        snip_c++;
    }
}

int my_nbr_len(int nb)
{
    int i = 1;
    int n = nb;
    int res = 0;

    if (n < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
        return (0);
    }
    while (n > 9) {
        n = n / 10;
        i = i * 10;
    }
    while (i >= 1) {
        res++;
        i = i / 10;
    }
    return (res);
}

char *my_nbr_to_str(int nb)
{
    int i = 1;
    int n = nb;
    char *res = malloc((sizeof(char)) * my_nbr_len(nb) + 2);
    int count = 0;

    if (n < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
        return (0);
    }
    for (; n > 9; n /= 10)
        i = i * 10;
    while (i >= 1) {
        res[count] = (((nb / i) % 10) + '0');
        i = i / 10;
        count++;
    }
    res[count] = ' ';
    res[count + 1] = '\0';
    return (res);
}