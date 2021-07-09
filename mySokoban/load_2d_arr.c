/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include "my.h"

int st_size(char const *filepath)
{
    struct stat buf;
    (void)stat(filepath, &buf);
    int res = buf.st_size;

    return (res);
}

char *load_1d_arr(char *filepath)
{
    int fildes = open(filepath, O_RDONLY);
    int size = st_size(filepath);
    char *sub_res = malloc((sizeof(char)) * (size) + 1);

    (void)read(fildes, sub_res, size);
    close (fildes);
    sub_res[size] = '\0';
    return (sub_res);
}

char **load_2d_arr(char *filepath)
{
    char *sub_res = load_1d_arr(filepath);
    char **res = malloc((sizeof(char *)) * (get_nb_rows(sub_res) + 5));
    int line_size = 0;
    int pos = 0;
    int rows = get_nb_rows(sub_res) + 1;
    int i = 0;

    for (i = 0; i <= rows; i++) {
        line_size = sizeof_line(sub_res, pos, &pos);
        res[i] = cp_snipet(sub_res, pos - line_size, pos, line_size);
        pos++;
    }
    res[i] = NULL;
    return (res);
}