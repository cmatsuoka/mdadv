#include <stdint.h>
#include "screen.h"
#include "graphics.h"

static uint8_t fb[GFX_WIDTH * GFX_HEIGHT];

void put_pixel(int x, int y, int c)
{
	fb[y * GFX_WIDTH + x] = c;
}


int get_pixel(int x, int y)
{
	return fb[y * GFX_WIDTH + x];
}


void show_block(int x, int y, int w, int h)
{
	int i;

	if (x + w - 1 >= GFX_WIDTH)
		w = GFX_WIDTH - x;
	if (y + h - 1 >= GFX_HEIGHT)
		h = GFX_HEIGHT - y;

	for (i = 0; i < h; i++)
		gfx_put_pixels(x, y + i, w, &fb[(y + i) * GFX_WIDTH + x]);

	//gfx->put_block(x, y, x + w - 1, y + h - 1);
}


void show_screen()
{
	show_block(0, 0, GFX_WIDTH, GFX_HEIGHT);
}


static void _clear_screen(int y1, int y2, int c)
{
	int x, y;

	for (y = y1; y < y2; y++) {
		for (x = 0; x < GFX_WIDTH; x++)
			put_pixel(x, y, c);
	}
}

void cls_clr(int c)
{
	_clear_screen(0, GFX_HEIGHT, c);
}

void clspic(int c)
{
	_clear_screen(0, PIC_HEIGHT, c);
}

void clstxt()
{
	_clear_screen(PIC_HEIGHT + 1, GFX_HEIGHT, COLOR_WHITE);
	show_block(0, PIC_HEIGHT + 1, GFX_WIDTH, GFX_HEIGHT - PIC_HEIGHT - 1);
	setcur(11, 0);
}

void cls()
{
	cls_clr(COLOR_WHITE);
}

