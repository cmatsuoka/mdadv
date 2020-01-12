#include "advsys.h"
#include "graphics.h"
#include "screen.h"
#include "screens.h"

int main()
{
    gfx_init("Calixto Island");

    cls();

    display_overlay(0, 0, scrn, 1);
    /* shoscr (mdlogo); */

    setcur(20,0);
    disply("V2.2");
    setcur(1,13);
    disply("MARK DATA PRODUCTS\x0d\x0d          presents");
    setcur(13,0);
    disply("             By:\r\r"
           "    Bob Withers & Stephen O'Dea\r\r"
           "       Copyright (c)1981, 1983, 1984\r"
           "         Mark Data Products");

    while (check_key()) {
        poll_timer();
        scrlft(1, 44, 128, 10);
        scrrit(1, 92, 128, 10);
        show_screen();
    }

    cls();

    return 0;
}
