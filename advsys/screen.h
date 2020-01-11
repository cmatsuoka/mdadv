#pragma once

#include <stdint.h>

#define COLOR_BLACK     0
#define COLOR_RED       1
#define COLOR_BLUE      2
#define COLOR_WHITE     3

int get_pixel(int,int);
void put_pixel(int,int,int);
void show_screen(void);
void show_block(int,int,int,int);
void cls(void);
void clstxt(void);
void clspic(int);
void cls_clr(int);
void setcur(int,int);
void display_overlay(int, int, uint8_t*, int);

void scrlft(int,int,int,int);
void scrrit(int,int,int,int);

