#include "text.h"
#include <stdint.h>
#include <string.h>
#include "screen.h"

static int msglns;
static const uint8_t font[];
static int row, col;

static int _x1, _y1, _x2, _y2;

void scroll()
{
    int i, j;

    for (i = PIC_HEIGHT + 1 + C_LIN; i < GFX_HEIGHT; i++) {
        for (j = 0; j < GFX_WIDTH; j++) {
            put_pixel(j, i - C_LIN, get_pixel(j, i));
        }
    }

    for (i = GFX_HEIGHT - C_LIN; i < GFX_HEIGHT; i++) {
        for (j = 0; j < GFX_WIDTH; j++) {
            put_pixel(j, i, COLOR_WHITE);
        }
    }

    show_block(0, PIC_HEIGHT + 1, GFX_WIDTH, GFX_HEIGHT - PIC_HEIGHT + 1);
}

void setcur(int r, int c)
{
    row = r;
    col = c;
}

#define CURSOR_RATE 30

static void dischr_(int x)
{
    int i, j, k;
    int color = COLOR_BLACK;
    static int counter = 0;

    if (x == CURSOR) {        /* Blink cursor */
        counter++;
        counter %= CURSOR_RATE;
        color = counter > (CURSOR_RATE / 2) ? COLOR_RED : COLOR_BLUE;
    }

    if (_x1 > col * C_COL) _x1 = col * C_COL;
    if (_y1 > row * C_LIN) _y1 = row * C_LIN;
    if (_x2 < (col + 1) * C_COL - 1) _x2 = (col + 1) * C_COL - 1;
    if (_y2 < (row + 1) * C_LIN - 1) _y2 = (row + 1) * C_LIN - 1;

    x -= ' ';
    for (i = 0; i < C_LIN; i++) {
        k = font[x * C_LIN + i];
        for (j = 0; j < C_COL; j++) {
            if (k & 0x20)
                put_pixel(col * C_COL + j, row * C_LIN + i, color);
            else
                put_pixel(col * C_COL + j, row * C_LIN + i, COLOR_WHITE);
            k <<= 1;
        }
    }

    show_block(col * C_COL, row * C_LIN, C_COL, C_LIN);
}

void discursor()
{
    int c0, r0;

    c0 = col;
    r0 = row;

    dischr_(CURSOR);

    show_block(c0 * C_COL, r0 * C_LIN, C_COL, C_LIN);
}

static void clr_char()
{
    dischr_(' ');
}

void display_char(int c)
{
    if (row >= (GFX_HEIGHT / C_LIN)) {
        scroll();
        row--;
    }

    setcur(row, col);

    if (c == 0x0d) {        /* new line */
        dischr_(' ');        /* erase cursor */
        msglns++;
        row++;
        col = 0;
        return;
    }
        
    if (c == 0x0c) {        /* clear screen */
        clstxt();
        return;
    }

    if (c == 0x08) {        /* backspace */
        clr_char();

        if (row == 0 && col == 0)
            return;

        if (--col)
            return;

        col = MAXLINE;
        row--;
        return;
    }

    if (c < ' ' || c > 'z')        /* valid range */
        return;

    dischr_(c);

    col++;
    
    if (col > MAXLINE) {
        col = 1;
        row++;
        msglns++;
    }
}

void display_text(char *msg)
{
    int l;

    _x1 = _y1 = 10000;
    _x2 = _y2 = 0;

    for (; *msg; msg++) {
        if (*msg == ' ') {
            l = strcspn(msg + 1, " \n");
            if (l > (MAXLINE - col)) {
                display_char(0x0d);
                continue;
            }
        }

        display_char(*msg);
    }

    show_block(_x1, _y1, _x2 - _x1 + 1, _y2 - _y1 + 1);
}

/* 8x9 font patterns */
static const uint8_t font[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        /* SPACE */
    0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x08, 0x00, 0x00,        /* ! */
    0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        /* " */
    0x12, 0x12, 0x3E, 0x12, 0x3E, 0x12, 0x12, 0x00, 0x00,        /* # */
    0x08, 0x1E, 0x28, 0x1C, 0x0A, 0x3C, 0x08, 0x00, 0x00,        /* $ */
    0x32, 0x32, 0x04, 0x08, 0x10, 0x26, 0x26, 0x00, 0x00,        /* % */
    0x10, 0x28, 0x28, 0x10, 0x2A, 0x24, 0x1A, 0x00, 0x00,        /* & */
    0x08, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        /* ' */
    0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02, 0x00, 0x00,        /* ( */
    0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08, 0x00, 0x00,        /* ) */
    0x08, 0x2A, 0x1C, 0x3E, 0x1C, 0x2A, 0x08, 0x00, 0x00,        /* * */
    0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 0x00, 0x00,        /* + */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x10, 0x00,        /* , */
    0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,        /* - */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00,        /* . */
    0x02, 0x02, 0x04, 0x08, 0x10, 0x20, 0x20, 0x00, 0x00,        /* / */
    0x1C, 0x22, 0x26, 0x2A, 0x32, 0x22, 0x1C, 0x00, 0x00,        /* 0 */
    0x08, 0x18, 0x08, 0x08, 0x08, 0x08, 0x1C, 0x00, 0x00,        /* 1 */
    0x1C, 0x22, 0x02, 0x0C, 0x10, 0x20, 0x3E, 0x00, 0x00,        /* 2 */
    0x1C, 0x22, 0x02, 0x0C, 0x02, 0x22, 0x1C, 0x00, 0x00,        /* 3 */
    0x04, 0x0C, 0x14, 0x3E, 0x04, 0x04, 0x04, 0x00, 0x00,        /* 4 */
    0x3E, 0x20, 0x20, 0x3C, 0x02, 0x02, 0x3C, 0x00, 0x00,        /* 5 */
    0x1C, 0x22, 0x20, 0x3C, 0x22, 0x22, 0x1C, 0x00, 0x00,        /* 6 */
    0x3E, 0x22, 0x04, 0x04, 0x08, 0x08, 0x08, 0x00, 0x00,        /* 7 */
    0x1C, 0x22, 0x22, 0x1C, 0x22, 0x22, 0x1C, 0x00, 0x00,        /* 8 */
    0x1C, 0x22, 0x22, 0x1E, 0x02, 0x22, 0x1C, 0x00, 0x00,        /* 9 */
    0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,        /* : */
    0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x08, 0x10, 0x00,        /* ; */
    0x04, 0x08, 0x10, 0x20, 0x10, 0x08, 0x04, 0x00, 0x00,        /* < */
    0x00, 0x00, 0x3E, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00,        /* = */
    0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x00, 0x00,        /* > */
    0x1C, 0x22, 0x02, 0x04, 0x08, 0x00, 0x08, 0x00, 0x00,        /* ? */
    0x1C, 0x22, 0x02, 0x1A, 0x2A, 0x2A, 0x1C, 0x00, 0x00,        /* @ */
    0x1C, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x22, 0x00, 0x00,        /* A */
    0x3C, 0x22, 0x22, 0x3C, 0x22, 0x22, 0x3C, 0x00, 0x00,        /* B */
    0x1C, 0x22, 0x20, 0x20, 0x20, 0x22, 0x1C, 0x00, 0x00,        /* C */
    0x38, 0x24, 0x22, 0x22, 0x22, 0x24, 0x38, 0x00, 0x00,        /* D */
    0x3E, 0x20, 0x20, 0x3C, 0x20, 0x20, 0x3E, 0x00, 0x00,        /* E */
    0x3E, 0x20, 0x20, 0x3C, 0x20, 0x20, 0x20, 0x00, 0x00,        /* F */
    0x1C, 0x22, 0x20, 0x2E, 0x22, 0x22, 0x1C, 0x00, 0x00,        /* G */
    0x22, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x22, 0x00, 0x00,        /* H */
    0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3E, 0x00, 0x00,        /* I */
    0x0F, 0x02, 0x02, 0x02, 0x02, 0x12, 0x0C, 0x00, 0x00,        /* J */
    0x22, 0x24, 0x28, 0x30, 0x28, 0x24, 0x22, 0x00, 0x00,        /* K */
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3C, 0x00, 0x00,        /* L */
    0x22, 0x36, 0x2A, 0x2A, 0x22, 0x22, 0x22, 0x00, 0x00,        /* M */
    0x22, 0x32, 0x32, 0x2A, 0x26, 0x26, 0x22, 0x00, 0x00,        /* N */
    0x1C, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x00, 0x00,        /* O */
    0x3C, 0x22, 0x22, 0x3C, 0x20, 0x20, 0x20, 0x00, 0x00,        /* P */
    0x1C, 0x22, 0x22, 0x22, 0x2A, 0x24, 0x1A, 0x00, 0x00,        /* Q */
    0x3C, 0x22, 0x22, 0x3C, 0x28, 0x24, 0x22, 0x00, 0x00,        /* R */
    0x1C, 0x22, 0x20, 0x1C, 0x02, 0x22, 0x1C, 0x00, 0x00,        /* S */
    0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,        /* T */
    0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x00, 0x00,        /* U */
    0x22, 0x22, 0x22, 0x22, 0x14, 0x14, 0x08, 0x00, 0x00,        /* V */
    0x22, 0x22, 0x22, 0x2A, 0x2A, 0x36, 0x22, 0x00, 0x00,        /* W */
    0x22, 0x22, 0x14, 0x08, 0x14, 0x22, 0x22, 0x00, 0x00,        /* X */
    0x22, 0x22, 0x14, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,        /* Y */
    0x3E, 0x02, 0x04, 0x08, 0x10, 0x20, 0x3E, 0x00, 0x00,        /* Z */
    0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x00, 0x00,        /* [ */
    0x3C, 0x42, 0x99, 0xA1, 0xA1, 0x99, 0x42, 0x3C, 0x00,        /* BACK SLASH */
    0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E, 0x00, 0x00,        /* ] */
    0x08, 0x1C, 0x3E, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,        /* UP ARROW */
    0x00, 0x08, 0x18, 0x3E, 0x18, 0x08, 0x00, 0x00, 0x00,        /* BACK ARROW */
    0x20, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        /* BACK QUOTE */
    0x00, 0x00, 0x0C, 0x02, 0x0E, 0x12, 0x0D, 0x00, 0x00,        /* a */
    0x20, 0x20, 0x3C, 0x22, 0x22, 0x22, 0x3C, 0x00, 0x00,        /* b */
    0x00, 0x00, 0x1C, 0x22, 0x20, 0x22, 0x1C, 0x00, 0x00,        /* c */
    0x02, 0x02, 0x1E, 0x22, 0x22, 0x22, 0x1E, 0x00, 0x00,        /* d */
    0x00, 0x00, 0x1C, 0x22, 0x3E, 0x20, 0x1C, 0x00, 0x00,        /* e */
    0x04, 0x0A, 0x08, 0x1C, 0x08, 0x08, 0x08, 0x00, 0x00,        /* f */
    0x00, 0x00, 0x1C, 0x22, 0x22, 0x1E, 0x02, 0x22, 0x1C,        /* g */
    0x20, 0x20, 0x2C, 0x32, 0x22, 0x22, 0x22, 0x00, 0x00,        /* h */
    0x08, 0x00, 0x18, 0x08, 0x08, 0x08, 0x1C, 0x00, 0x00,        /* i */
    0x08, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x28, 0x10,        /* j */
    0x20, 0x20, 0x24, 0x28, 0x30, 0x28, 0x24, 0x00, 0x00,        /* k */
    0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1C, 0x00, 0x00,        /* l */
    0x00, 0x00, 0x14, 0x2A, 0x2A, 0x22, 0x22, 0x00, 0x00,        /* m */
    0x00, 0x00, 0x2C, 0x32, 0x22, 0x22, 0x22, 0x00, 0x00,        /* n */
    0x00, 0x00, 0x1C, 0x22, 0x22, 0x22, 0x1C, 0x00, 0x00,        /* o */
    0x00, 0x00, 0x2C, 0x32, 0x22, 0x22, 0x3C, 0x20, 0x20,        /* p */
    0x00, 0x00, 0x1A, 0x26, 0x22, 0x26, 0x1A, 0x02, 0x02,        /* q */
    0x00, 0x00, 0x2C, 0x32, 0x20, 0x20, 0x20, 0x00, 0x00,        /* r */
    0x00, 0x00, 0x1C, 0x20, 0x1C, 0x02, 0x1C, 0x00, 0x00,        /* s */
    0x08, 0x08, 0x1C, 0x08, 0x08, 0x0A, 0x04, 0x00, 0x00,        /* t */
    0x00, 0x00, 0x22, 0x22, 0x22, 0x26, 0x1A, 0x00, 0x00,        /* u */
    0x00, 0x00, 0x22, 0x22, 0x22, 0x14, 0x08, 0x00, 0x00,        /* v */
    0x00, 0x00, 0x22, 0x22, 0x2A, 0x2A, 0x14, 0x00, 0x00,        /* w */
    0x00, 0x00, 0x22, 0x14, 0x08, 0x14, 0x22, 0x00, 0x00,        /* x */
    0x00, 0x00, 0x22, 0x22, 0x22, 0x1E, 0x02, 0x02, 0x1C,        /* y */
    0x00, 0x00, 0x3E, 0x04, 0x08, 0x10, 0x3E, 0x00, 0x00,        /* z */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff        /* Cursor */
};

