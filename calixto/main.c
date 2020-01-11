#include <unistd.h>
#include "advsys.h"
#include "graphics.h"

int main()
{
    gfx_init("Calixto Island");

    cls();

    sleep(10);

    return 0;
}
