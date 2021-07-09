/*
** EPITECH PROJECT, 2021
** MyRPG_private
** File description:
** framebuffer
*/

#include "my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->height = height;
    framebuffer->width = width;
    framebuffer->pixels = malloc(sizeof(sfUint8) * width * height * 32 / 4);
    return (framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, \
                        unsigned int y, sfColor color)
{
    int position = ((y) * framebuffer->width + x) * 4;

    framebuffer->pixels[position + 0] = color.r;
    framebuffer->pixels[position + 1] = color.g;
    framebuffer->pixels[position + 2] = color.b;
    framebuffer->pixels[position + 3] = color.a;
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}