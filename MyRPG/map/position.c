/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** position
*/

#include "my.h"

int get_pos(map_t *map, int end_x, int end_y, level_t *l)
{
    int a = l->MAP_size;
    int x = map->x;
    int y = map->y;
    int i = 1;
    sfVector2i end = {end_x, end_y};

    a = pow((double)a, 2.0);
    for (i = 1; i <= a; i++) {
        if (check_tile(map->scale, x, y, end) == 1)
            return (i);
        if (i % (int)sqrt((double)a) == 0) {
            x = map->x - ((100 / map->scale) * i / sqrt((double)a));
            y = map->y + ((50 / map->scale) * i / sqrt((double)a));
        }
        else {
            x = x + 100 / map->scale;
            y = y + 50 / map->scale;
        }
    }
    return (0);
}

int check_tile(float scale, double start_x, double start_y, sfVector2i end)
{
    start_y -= 0 / scale;
    double a1 = start_x - ((100 / scale));
    double a2 = start_y + ((50 / scale));
    double b1 = start_x;
    double b2 = start_y + ((100 / scale));
    double c1 = start_x + ((100 / scale));
    double c2 = start_y + ((50 / scale));
    double d1 = start_x;
    double d2 = start_y;
    double Q[2] = {0.5 * (a1 + c1), 0.5 * (a2 + c2)};
    double a = 0.5 * distance(a1, a2, c1, c2);
    double b = 0.5 * distance(b1, b2, d1, d2);
    double U[2] = {(c1 - a1) / (2 * a), (c2 - a2) / (2 * a)};
    double V[2] = {(d1 - b1)/(2 * b), (d2 - b2) / (2 * b)};
    double W[2] = {(double)end.x - Q[0], (double)end.y - Q[1]};
    double xabs = fabs(dot_product(W, U, 2));
    double yabs = fabs(dot_product(W, V, 2));
    if (xabs/a + yabs/b <= 1)
        return (1);
    return (0);
}

double dot_product(double v[], double u[], int n)
{
    double result = 0.0;

    for (int i = 0; i < n; i++)
        result += v[i]*u[i];
    return (result);
}

double distance(double start_x, double start_y, double end_x, double end_y)
{
    int x = end_x - start_x;
    int y = end_y - start_y;

    y = y * y;
    x = x * x;
    return (sqrt(x + y));
}