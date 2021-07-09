/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myworld-pablo-elias.herrmann
** File description:
** read
*/

#include "my.h"

int str_n_compare(char *one, char *two, int n, int end)
{
    int count = 0;
    int res = 0;

    for (int i = n; i < end; i++) {
        if (one[i] == two[count])
            res++;
        else
            res = 0;
        count++;
    }
    if (res == end - n)
        return (1);
    else
        return (0);
}

int convert_readed2(int **map, char *line, int ground, int k)
{
    int j = 1;

    for (int i = k + 2; line[i] != '\0'; i++) {
        if (line[i] == '\n')
            i++;
        (*map)[j] = line[i] - 48;
        j++;
    }
    free(line);
    return (ground);
}

int convert_readed(int **map, char *line, char *number)
{
    int size = my_getnbr(number);
    char *ground_str = malloc(sizeof(char) * 10);
    int pos = 0;
    int ground = 0;

    for (int i = my_strlen(number) + 1; line[i] != '\n'; i++) {
        ground_str[pos] = line[i];
        pos++;
    }
    ground_str[pos] = '\0';
    ground = my_getnbr(ground_str);
    (*map) = malloc(sizeof(int) * ((size * size) + 2));
    (*map)[0] = 0;
    (*map)[(size * size) + 1] = -1;
    return (convert_readed2(map, line, ground, my_strlen(number) + pos));
}

int read_from_file(int **map, char *path)
{
    int fd = open(path, O_RDONLY);
    char *line = malloc(sizeof(char) * 2000);
    char *c = malloc(sizeof(char) * 1);
    char *number = malloc(sizeof(char) * 10);
    int pos = 0;

    while (read(fd, c, 1) > 0) {
        line[pos] = c[0];
        pos++;
    }
    line[pos] = '\0';
    for (int i = 0; line[i] != ' '; i++) {
        number[i] = line[i];
        if (line[i + 1] == ' ')
            number[i + 1] = '\0';
    }
    return (convert_readed(map, line, number));
}