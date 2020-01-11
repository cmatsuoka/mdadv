#pragma once

#include <stddef.h>
#include "advsys.h"
#include "text.h"

struct advdata {
    int room;
    int nounno;
    int verbno;
    int verb[MAXWRD];
    int noun[MAXWRD];
    int points;
    int score;
    int objcnt;
    int *object;

    int advnum;
    int maxobj1;
    int norms1;
    int tresrm1;
    int maxpnt1;
    int deadrm1;

    char keybuf[MAXLINE+1];
};
