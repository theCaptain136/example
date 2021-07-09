/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** header
*/

#ifndef MY_RPG
#define MY_RPG

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector3.h>
#include <SFML/System/InputStream.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>

typedef enum options_s {
    none,
    fight,
    eat,
    wear
} options_t;

typedef struct name_s {
    char *name;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
} name_t;

typedef struct count_s {
    int quantity;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
} count_t;

typedef struct item_s {
    struct item_s *next;
    struct item_s *prev;
    name_t *name;
    count_t *count;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int index;
} items_t;

typedef struct inventory {
    int size;
    items_t *start;
    items_t *end;
} inventory_t;

typedef struct game_object_s {
    struct game_object_s *prev;
    struct game_object_s *next;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f movement;
    sfIntRect rect;
    int rect_size;
} obj_t;

typedef struct linked_list {
    int size;
    obj_t *start;
    obj_t *end;
} llist_t;

typedef struct colors_s {
    sfColor normal;
    sfColor rollover;
    sfColor clicked;
} colors_t;

#include "../map/my.h"

typedef struct button_s {
    sfRectangleShape *rect;
    void (*callback)(sfRenderWindow *window, int *c, int prev);
    void (*m_callback)(int *music_playing, sfMusic *bgmusic, s_effects_t *se);
    colors_t colors;
    sfVector2f pos;
    sfVector2f size;
    sfText *name;
    sfTexture *texture;
    sfSprite *sprite;
    char *filepath;
} button_t;

typedef struct scene_s {
    level_t *game;
    llist_t *objs;
    button_t **buttons;
    s_effects_t *se;
    button_t **music_b;
    sfMusic *bg_music;
    inventory_t *inv;
    int music_playing;
    int music_volume;
    int current_sc;
    int prev_m;
} scene_t;

char *nb_to_str(int nbr);

int count_digits(int nb);

char *my_revstr(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_strcat_j(char *dest, char const *src);

llist_t *create_list(void);

int new_node(llist_t *list, char *path, sfVector2f pos, sfVector2f scale);

int delete_node_obj(llist_t *obj, obj_t *node);

scene_t **init_scenes(void);

scene_t *malloc_scene(scene_t *scene, int count);

colors_t build_colors(sfColor n, sfColor ro, sfColor cl);

void go_to_htp(sfRenderWindow *window, int *c, int prev);

void end_game(sfRenderWindow *window, int *c, int prev);

void restart(sfRenderWindow *window, int *c, int prev);

void start_menu(sfRenderWindow *window, int *c, int prev);

void switch_scene(sfRenderWindow *window, int *c, int prev);

void bt_prev(sfRenderWindow *window, int *c, int prev);

scene_t *scene_menu(scene_t *scen, sfVector2f sz, colors_t cl, sfTexture *tx);

sfSprite *create_sprite(char *filepath, sfVector2f pos, sfVector2f scale);

obj_t *create_obj(obj_t *object, char *pt, sfVector2f ps, sfVector2f sc);

void init_b_colors(button_t *bt, colors_t colors);

void init_button(button_t *button, sfVector2f position, sfVector2f size);

sfText *button_text(char *str, int x, int y, int size);

scene_t *end_screen(scene_t *scene, sfVector2f sz, colors_t color, \
                                            sfTexture *texture);

scene_t *lost_screen(scene_t *scene, sfVector2f sz, colors_t color, \
                                            sfTexture *texture);

void init_ml(scene_t *scene);

void draw_ui(sfRenderWindow *window, scene_t **scenes);

int game_loop(sfRenderWindow *window, scene_t **scenes, sfSprite *set);

void draw_scene(sfRenderWindow *window, scene_t **scenes);

void pause_music(sfMouseButtonEvent ev, scene_t **scene);

void event(sfRenderWindow *window, scene_t **scenes, sfSprite *set);

int button_is_clicked(button_t button, sfVector2f click_position);

void restart_game(scene_t **scenes, sfRenderWindow *window, sfSprite *set);

sfVector2f cursorvector(sfRenderWindow *window);

void display_help(scene_t **scenes, sfRenderWindow *window, \
                                        sfSprite *set);

void free_scenes(scene_t **scenes);

void draw_menu(sfRenderWindow *win, scene_t **scenes, int but);

scene_t *settings_menu(scene_t *scene, sfVector2f size, colors_t colors, \
                                                sfTexture *texture);

scene_t *how_to_play(scene_t *scene, sfVector2f sz, colors_t color, \
                                            sfTexture *texture);

void start_music(int *music_playing, sfMusic *bg_music, s_effects_t *se);

void stop_music(int *music_playing, sfMusic *bg_music, s_effects_t *se);

void mute_se(int *mp, sfMusic *mu, s_effects_t *sound_eff);

void unmute_se(int *mp, sfMusic *mu, s_effects_t *sound_eff);

void music_settings(sfRenderWindow *window, scene_t **scenes, sfEvent event);

s_effects_t *init_sound_eff(void);

void free_sound_eff(s_effects_t *se);

scene_t **malloc_scenes(void);

scene_t *malloc_mb(scene_t *scene, int count);

void init_tower_button(button_t *button, char *filepath, sfVector2f scale);

void looser(scene_t **scenes, sfRenderWindow *window, sfSprite *set);

void winner(scene_t **scenes, sfRenderWindow *window, sfSprite *set);

void show_details_one_line(sfRenderWindow *window, sfVector2f pos, char *msg);

void show_details_two_lines(sfRenderWindow *window, sfVector2f pos, \
                                        char *msg, char *sc);
void free_inventory(inventory_t *inv, items_t *cur);

sfVector2f modify_pos(sfVector2f pos);

void display_item(items_t *cur, sfRenderWindow *window, sfVector2f pos);

inventory_t *build_inventory(void);

inventory_t *create_inv(void);

int new_item(inventory_t *list, char *name, char *path, int i);

void open_inventory(void);

void check_inventor_btn(sfRenderWindow *window, sfEvent event, \
scene_t **scenes);

scene_t *inventory(scene_t *scene, sfVector2f sz, colors_t color, \
sfTexture *tx);

void init_inventory_nodes(scene_t *scene, sfVector2f bg_sc);

void draw_text(sfRenderWindow *window, sfVector2f pos, char *msg, int sz);

scene_t *status_menu(scene_t *scene, sfVector2f size, colors_t colors, \
                                                sfTexture *texture);

void draw_status(sfRenderWindow *window, scene_t **scenes);

void sprite_set(sfRenderWindow **window, float scale, sfIntRect *rect);

void draw_bar(sfRenderWindow *window, int xp, sfVector2f pos);

void draw_game_freeze(level_t *l);

void draw_inventory(sfRenderWindow *window, scene_t **scenes);

void volume_controller(sfRenderWindow *window, scene_t **scenes);

void change_volume(sfVector2i ev, scene_t **scenes, sfVector2f pos);

void change_level(scene_t **sc, sfRenderWindow *window);

scene_t *quitb(scene_t *scene, sfVector2f sz, colors_t cl, sfTexture *tx);

void draw_menu_but(scene_t **scenes, sfRenderWindow *window);

scene_t *help(scene_t *sc, sfVector2f sz, colors_t color, sfTexture *text);

void draw_text_w(sfRenderWindow *win, sfVector2f text_pos, char *msg, int sz);

void draw_shortcuts(sfRenderWindow *window);
void free_level_struct(level_t *l);

void next_level_msg(sfRenderWindow *win, scene_t **sc);

#endif /* !MY_RPG */