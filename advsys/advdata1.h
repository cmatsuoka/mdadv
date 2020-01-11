#pragma once

#include "advsys.h"

struct advdata {
    int maxobj0;                  // MAX OBJECTS ALLOWED TO CARRY
    int norms0;                   // NUMBER OF ROOMS IN ADVENTURE
    int tresrm0;                  // ROOM TO STORE TREASURE IN
    int maxpnt0;                  // TOTAL POINTS REQUIRED TO WIN
    int deadrm0;                  // DEFAULT ROOM TO DIE IN
    int advnum0;                  // ADVENTURE NUMBER FOR SAVE GAME

    int room;
    int nounno;
    int verbno;
    int verb[MAXWRD];
    int noun[MAXWRD];
    int points;
    int score;
    int objcnt;
    int *object;
};
