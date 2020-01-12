#pragma once

#include <stdint.h>

#define GFX_WIDTH 256
#define GFX_HEIGHT 192

#define PIC_HEIGHT 89

int gfx_init(char *);
void gfx_put_pixel(int, int, int);
void gfx_put_pixels(int x, int y, int w, uint8_t *buf);
void gfx_show(void);
int read_key(void);
void poll_timer(void);
int check_key(void);
int wait_key(void);
