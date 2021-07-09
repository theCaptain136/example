/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** my
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/Graphics.h>
#include <string.h>

#define hero_x 1920 / 2
#define hero_y 1080 / 2

typedef struct downatk {
    sfSprite *atksprite;
    sfIntRect *rect;
    int direction;
} downatk;

typedef struct upatk {
    sfSprite *atksprite;
    sfIntRect *rect;
    int direction;
} upatk;

typedef struct rightatk {
    sfSprite *atksprite;
    sfIntRect *rect;
    int direction;
} rightatk;

typedef struct leftatk {
    sfSprite *atksprite;
    sfIntRect *rect;
    int direction;
} leftatk;

typedef struct atk {
    downatk *down;
    upatk *up;
    leftatk *left;
    rightatk *right;
} atk;

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

typedef struct map_details {
    int *map;
    int x;
    int y;
    float scale;
} map_t;

typedef struct npc_stat {
    int time;
    sfClock *glock;
    sfClock *lil_glock;
    int x;
    int y;
    sfTexture *texture;
    sfSprite *sprite;
    int interacted;
    int npc_name;
    sfText **texts;
    sfFont *font;
    int scale;
} npc_t;

typedef struct hero__stat {
    int aim;
    int direction;
    int speed;
    int kills;
    int hp;
    int atk_speed;
    int max_hp;
    int xp;
    int dmg;
    int dmg_type;
    sfConvexShape *hp_bar1;
    sfConvexShape *hp_bar2;
    sfTexture *texture;
    sfSprite *sprite;
} hero_t;

typedef struct enemy__stat {
    int direction;
    int x;
    int y;
    int map_index;
    int speed;
    int radius;
    int range;
    int max_hp;
    int xp;
    int hp;
    int dmg;
    int dmg_type;
    float size;
    int mvmnt_type;
    sfTexture *texture;
    sfSprite *sprite;
    sfConvexShape *hp_bar1;
    sfConvexShape *hp_bar2;
    struct enemy__stat *previous;
    struct enemy__stat *next;
    sfClock *glock;
    int attack;
} enemy_t;

typedef struct ll__enemy {
    struct enemy__stat *start;
    struct enemy__stat *end;
    int size;
} ll_enemy;


typedef struct sound_effect {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

typedef struct s_effects_s {
    sound_t *shot_enem;
    sound_t *hurt;
    sound_t *score;
    sound_t *item;
    sound_t *laser;
} s_effects_t;


typedef struct level {
    int lvl;
    int count;
    int brush;
    int scale;
    int tool;
    int load;
    int count2;
    int count3;
    int count4;
    char *path;
    int theme;
    int MAP_size;
    s_effects_t *sound_eff;
    sfEvent event;
    sfClock *timer;
    sfClock *timer2;
    sfClock *timer3;
    sfClock *timer4;
    sfClock *timer5;
    map_t *map;
    sfSprite *sprite;
    sfTexture *texture;
    hero_t *hero_stat;
    ll_enemy *list;
    npc_t *npc;
    sfRenderWindow *window;
} level_t;

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
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, \
                                unsigned int y, sfColor color);
void tild_a(sfRenderWindow **window, int x, int y, float scale, \
                                int *map, int h);
void tild_b(sfRenderWindow **window, int x, int y, float scale, \
                                int *map, int h);
void tild_d(sfRenderWindow **window, int x, int y, float scale, \
                                int *map, int h);
void tild_c(sfRenderWindow **window, int x, int y, float scale, \
                                int *map, int h);
void hill(sfRenderWindow **win, int x, int y, float scale, int *map, int h);
void corner_right(sfRenderWindow **window, int x, int y, float scale);
void corner_mid(sfRenderWindow **win, int x, int y, float scale, int *, int);
void corner_left(sfRenderWindow **window, int x, int y, float scale);
void full_block(sfRenderWindow **window, sfVector2f ab, sfVector2f hsscale, \
                                                sfSprite *spr);
void draw_map(sfRenderWindow **window, level_t *l);
void clear(int **map, level_t *l);
sfConvexShape *draw_left_face(sfVector2i xy, float scl, int b, sfColor water);
sfConvexShape *draw_right_face(sfVector2i xy, float sc, int b, sfColor water);
void water_block(sfRenderWindow **window, int a, int b, int h, \
                            sfColor top, float scale, int *map, int k);
void full_tile(sfRenderWindow **win, sfVector2i ab, sfColor cl, float scale);
void full_tile_w(sfRenderWindow **win, int a, int b, sfColor color, float sc);
sfConvexShape *draw_left_face_w(int x, int y, float sc, int b, sfColor water);
sfConvexShape *draw_right_face_w(int x, int y, float sc, int b, sfColor watr);
int get_pos(map_t *map, int end_x, int end_y, level_t *l);
void lava_block(sfRenderWindow **wn, sfVector2i ab, sfColor top, float scale);
int zero_point_two_five_clock(sfTime clock, sfClock **time);
int *level(int *map, level_t *l);
int my_get_n_nbr(char *str, int *i);
int read_from_file(int **map, char *path);
void add_to_str(char **one, char *snipped);
bool save_to_file(int *map, int size);
int my_nbr_len(int nb);
char *my_nbr_to_str(int nb);
void hero(level_t *);
int check_tile(float scale, double start_x, double start_y, sfVector2i end);
double distance(double start_x, double start_y, double end_x, double end_y);
double dot_product(double v[], double u[], int n);
sfIntRect *set_rect(void);
enemy_t *create_enemy(void);
ll_enemy *create_plane_list();
bool push_back_plane(enemy_t *airplane, ll_enemy *list_plane);
void print_ll(ll_enemy *list);
ll_enemy *spawn_enemys(map_t *map, level_t *l);
void draw_enemy(ll_enemy *list, level_t *l);
sfVector2i xy_from_index(int index, map_t *map, level_t *l);
void move(map_t *map, hero_t *hero, level_t *);
int delete_node(ll_enemy *obj, enemy_t *node);
int count_file(void);
void aim(hero_t *hero);
void attack_melee(level_t *l, int range);
level_t *set_level(sfRenderWindow *window, char *path, int lvl);
int enemy_clock(sfTime clock, sfClock **time);
int aggro(level_t *l);
float n_distance(int x1, int y1, int x2, int y2);
void step(enemy_t *tmp, int x, int y, level_t *l);
hero_t *set_hero(int dmg, int hp);
int draw_level(level_t *l);
void clocks(level_t *l);
int *load_map(int);
int get_map_size(int *map);
enemy_t *enemy_1(int index, level_t *l);
enemy_t *enemy_2(int index, level_t *l);
enemy_t *enemy_3(int index, level_t *l);
enemy_t *enemy_4(int index, level_t *l);
enemy_t *enemy_5(int index, level_t *l);
enemy_t *init_enem(enemy_t *res, int indx, sfVector2i vector, sfTexture *tex);
int press_w(map_t *map, hero_t *hero, level_t *l);
int press_s(map_t *map, hero_t *hero, level_t *l);
void colision_down(enemy_t *tmp, level_t *l);
void interact_with_npc(level_t *l);
npc_t *create_npc(int lvl, sfRenderWindow *window, int x, int y);
void pure_convex(sfRenderWindow **win, hero_t *hero, map_t *map, int range);
void sprite_set(sfRenderWindow **window, float scale, sfIntRect *rect);
void colision_up(enemy_t *tmp, level_t *l);
void else_case_up(enemy_t *tmp, level_t *l, sfVector2i c1, sfVector2i c2);
void colision_right(enemy_t *tmp, level_t *l);
void colision_right(enemy_t *tmp, level_t *l);
void colision_down(enemy_t *tmp, level_t *l);
void colision_left(enemy_t *tmp, level_t *l);
void hit_particle(level_t *l);
s_effects_t *init_sound_eff(void);
void thunder(level_t *l);
void fire(level_t *l);
enemy_t *boss(int index, level_t *l);
void attack_one_two(enemy_t *stor, enemy_t *tmp, level_t *l, int range);
void attack_one(enemy_t *stor, enemy_t *tmp, level_t *l, int range);
void attack_two(enemy_t *stor, enemy_t *tmp, level_t *l, int range);
void step_one_two(int dx, int dy, enemy_t *tmp, level_t *l);
void step_one(int dx, int dy, enemy_t *tmp, level_t *l);
void step_two(int dx, int dy, enemy_t *tmp, level_t *l);
level_t *set_lvl_stor(level_t *lev);
void set_lvl_2(level_t *lev);
void fire_1(level_t *l, sfSprite *sprite, int i);
void fire_2(level_t *l, sfSprite *sprite, int *i);
void fire_3(level_t *l, sfSprite *sprite, int i);
void fire_4(level_t *l, sfSprite *sprite, int *i);
void fire_5(level_t *l, sfSprite *sprite, int i);
void draw_fire(level_t *l, sfSprite *sprite, sfTexture *texture);
void thunder_1(level_t *l, sfSprite *sprite, sfSprite *sprite2);
void thunder_2(level_t *l, sfSprite *sprite, sfSprite *sprite2);
void thunder_display(level_t *l, sfSprite *sprite, sfSprite *sprite2\
, sfTexture *texture);
void particle_stor(level_t *l, sfSprite *sprite);