#include <stdlib.h>
#include "graphics.h"
#include "screen.h"

union {
    uint16_t w;
    struct {
        uint8_t b1;
        uint8_t b2;
    } b;
} cur_byte;

static int objbyt(uint8_t **b)
{
    static int mode = 0;
    static int count = 0;
    static int refrct = 0;
    static int nlnsct = 0;
    uint8_t ah, al;

    if (b == NULL) {
        mode = count = refrct = nlnsct = 0;
        return 0;
    }

    
    switch (mode) {
    case 1:
        if (!--count)
            mode = 0;
        return cur_byte.b.b1;

    case 2:
        if (!--count)
            mode = 0;
        return *(*b)++;

    case 0:
        al = *(*b)++;
        if (al != 0) {
            if (al == 0xff)
                return 0x1ff;
    
            ah = al;
            al = *(*b)++;
            mode = 2;
    
            if (!--ah)
                mode = 0;
            count = ah;
            return al;
        }
    
    
        if ((ah = *(*b)++) != 0) {
            mode = 1;
    
            if (!--ah)
                mode = 0;
            count = ah;
            return cur_byte.b.b1 = *(*b)++;
        }
    
        mode = 3;
        al = *(*b)++;
        refrct = count = al;
        al = *(*b)++;
        nlnsct = al;
        {
            uint16_t w = *((uint16_t *)(*b));
            cur_byte.w = w++;
            //*((uint16_t *)(*b)) = w;
        }

        /* fall through */

    case 3:
        al = cur_byte.b.b1;
    
        if (--count)
            return al;
        
        {
            uint8_t x;
            x = cur_byte.b.b1;
            cur_byte.b.b1 = cur_byte.b.b2;
            cur_byte.b.b2 = x;
        }
    
    
        if (!--nlnsct)
            mode = 0;
    
        count = refrct;
    
        return al;
    }

    abort();
}

void display_overlay(int x, int y, uint8_t *ovl, int fs)
{
    int l, len, xref, yref;
    int max_y;

    x *= 2;

    len = *ovl++;
    xref = x;
    yref = y;

    //DBG(D_INFO "len=%d xref=%d", len, xref);

    objbyt(NULL);

    max_y = fs ? GFX_HEIGHT : PIC_HEIGHT;

    for (; y < max_y; y++) {
        l = len;
        x = xref;
        while (l--) {
            int data = objbyt(&ovl);

            if (data & 0xff00)
                goto done;
            data &= 0xff;

            put_pixel(x++, y, (data & 0xc0)>>6);
            put_pixel(x++, y, (data & 0xc0)>>6);
            put_pixel(x++, y, (data & 0x30)>>4);
            put_pixel(x++, y, (data & 0x30)>>4);
            put_pixel(x++, y, (data & 0x0c)>>2);
            put_pixel(x++, y, (data & 0x0c)>>2);
            put_pixel(x++, y, (data & 0x03)>>0);
            put_pixel(x++, y, (data & 0x03)>>0);
        }
    }

done:
    show_block(xref, yref, x - xref + 1, y - yref + 1);
}


