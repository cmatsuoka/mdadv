#pragma once

#include "graphics.h"

#define C_LIN 9
#define C_COL 6
#define MAXLINE (GFX_WIDTH / C_COL - 1)
#define CURSOR ('z' + 1)

void scroll(void);
void setcur (int, int);
void discursor(void);
//void dischr(int);
//void clr_char(void);
void display_char(int);
void display_text(char *);
