/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** lib
*/

#ifndef MY_H_
#define MY_H_
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct maps {
    char **map;
    char **tmp;
} map_t;

void my_putchar(char c);
char *my_strstr(char *, char const);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
char **my_str_to_word_array(char *);
char *my_strdup(char const *);
char **result(char const *, char **, int, int);
int wordnum(char const *);
int is_alpha(char);
int my_numnum(char *);
int calculate_plus(char *, char *);
int calculate_minus(char **, char *, char *);
int my_strstrlen(char **str);
int st_size(char const *filepath);
char *load_1d_arr(char *filepath);
char **load_2d_arr(char *filepath);
int counter(char *sub_res);
char *cp_snipet(char *str, int start, int end, int size);
void mv_down(char **map);
void mv_up(char **map);
void mv_left(char **map);
void mv_right(char **map);
int find_P(char **str, int *x, int *y);
int sizeof_line(char *str, int n, int *pos);
int get_nb_rows(char *sub_res);
void find_O(char **, char **);
int is_fine(char a);
int char_error(char **str);
int other_corner(char **map, int x, int y);
void count_cornered(map_t *maps, int i, int a, int *res);
int lost(map_t *maps);
void print_manager(map_t *maps, WINDOW *win, int a, int b);
void get_input(map_t *maps);
char **my_arr_cpy(char **str, char **dest);
char **arr_cpy(char **arr);
void free_all(char **str);
int error_right(char **map, int *x, int *y);
int error_down(char **map, int *x, int *y);
int error_up(char **map, int *x, int *y);
int error_left(char **map, int *x, int *y);
int error_stor(int fd, char **str, char **av);
void X_check(char **str, char **tmp, int i, int *res);
int cornered(char **map, int x, int y);
int boxes(char **str);
void write_O(char **one, char **two, int i, int s);
int check(char **str, int i);
int error(int ac, char **av, char **str);
int done(char **str, char **tmp);
int main_loop(map_t *maps, WINDOW *win, int a, int b);
int x_center(char **map);
void box_counter(char **str, int i, int *res);
#endif /* !MY_H_ */