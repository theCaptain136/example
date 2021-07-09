/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

typedef struct instruct {
    int i;
    int nim;
    int ones;
    int twos;
    int fours;
    int max_take;
    int nb;
}instruct_t;

typedef struct loop {
    int max_take;
    int who;
    char *top;
    char **map;
}loop_t;

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
char **my_arr_cpy(char **str, char ***dest);
char **arr_cpy(char **arr);
void free_all(char **str);
int sign(char const *str);
char **creat_map(int size);
int has(char *str);
void rm_at_pos(char **map, int line, int nb, int max_take);
void ai(char **map, int max_take);
void any(char **map, int *op, int max_take, instruct_t *t);
int last_turn(char **map);
int count_line(char *str);
void rm_all(char **map, int line);
void unsual_move(char **map, int *op, int max_take, instruct_t *t);
void print_manager(char **map, char *top);
int input_error(char *str);
int low_stacks(char **map);
int count_lines(char **map);
void set_op(int *op, int ones, int twos, int fours);
void ai_rm_at_pos(char **map, instruct_t *l, int *op);
void print_takes(int player, int nb, int line);
int over(char **map);
int extra_cases(char **map, int *op, instruct_t *t);
int param_error(int ac, char **av);
void maintain_symetry(int *op, int ones, int twos, int fours);
int new_value(int gate, char **map, int max_take);
int new_pos(char **map, int max_take, int *pos);
int get_nbs(int *pos, int *amount, char **map, int max_take);
int new_amount(char **map, int max_take, int *amount);
int nb_error(int nb, int max_take, int pos, char **map);
int error_cases(int *pos, int *amount, int max_take, char **map);
int pos_store(int s, int *pos, int max_take, char **map);
void do_stuff(char **map, instruct_t *list, int max_take, int *op);
void after_game(int who, char **map, char *top);
instruct_t *set_instruct(char **map);
int loop(int *pos, int *amount, loop_t *list);
void more_stuff_to_do(char **map, instruct_t *list, int max_take, int *op);
void ai_loop(char **map, instruct_t *list, int max_take, int op);
void last_turn_stuff(char **map, int i, int *lines);
int last_turn_other_stuff(char **map, int i);
void over_count(char **map, int i, int *res);
int user_loop(loop_t *list, int *pos, int *amount);