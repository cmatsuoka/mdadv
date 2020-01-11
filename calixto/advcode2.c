//
//        FILE: ADVCODE2.ASM   --   CALIXTO ISLAND
//

#include "advdata1.h"
#include "advdata2.h"
#include "advcode1.h"
#include "advcode2.h"
#include "advutil.h"


//        ADVENTURE UNIQUE VARIABLES
static int bailsw;
static int pottsw;
static int enersw;
static int first1;
static int tradsw;
static int chstsw;
static int desksw;
static int clrsw;


//        LOOK DESK

void look01(struct advdata *d)
{
    if (!ckobj(d, d->nounno)) {
        if (!ckobj(d, 94)) {      // OPEN DESK
            nosee(d);
            return;
        }
        if (!makvis(d, 27+INV)) {  // MICROFILM
            dmsg(12);
            return;
        }
        ckdraw(d);
        dmsg(11);
        return;
    }

    if (desksw) {
        dmsg(29);
        disply(message[28]);
        dmsg(17);
        return;
    }
}

//        LOOK TABLE

void look02(struct advdata *d)
{
    if (!ckobj(d, 121)) {         // TABLE
        nosee(d);
        return;
    }
    if (!makvis(d, 18+INV)) {     // MESSAGE
        dmsg(12);
        return;
    }
    ckdraw(d);
    dmsg(30);
}

//        LOOK RUG

void look03(struct advdata *d)
{
    if (locobj(d, 10)) {          // RUG
        dmsg(12);
        return;
    }
    if (ckobj(d, 119)) {          // LADDER TO CELLAR
        dmsg(12);
        return;
    }
    dmsg(31);
}

//        LOOK DOOR

void look04(struct advdata *d)
{
    if (d->room >= 5 && d->room <= 8) {
        if (d->room == 8) {
            if (!ckobj(d, 122)) {  // DEVICE
                nosee(d);
                return;
            }
        }
        dmsg(12);
        return;
    }
    if (!ckobj(d, d->nounno)) {
        nosee(d);
        return;
    }
    if (ckobj(d, 119)) {          // LADDER
        dmsg(12);
        return;
    }
    disply(message[31]);
    dmsg(29);
}

//        LOOK CHEST

void look05(struct advdata *d)
{
    equobj(d);
    if (!locobj(d, d->nounno)) {
        nosee(d);
        return;
    }
    switch (chstsw) {
    case 0:
        dmsg(16);
        return;
    case 1:
        dmsg(35);
        return;
    case 2:
        dmsg(36);
        return;
    }
    dmsg(22);
}

//        LOOK CABINET

void look06(struct advdata *d)
{
    if (d->room != 3) {
        nosee(d);
        return;
    }
    if (makvis(d, 16+INV)) {      // MOUSETRAP
        ckdraw(d);
        dmsg(37);
        return;
    }
    disply(message[11]);
    dmsg(38);
}

//        LOOK LADDER

void look07(struct advdata *d)
{
    if (d->room == 3) {
        dmsg(12);
        return;
    }
    lookob(d);
}

//        LOOK MANUAL

void look08(struct advdata *d)
{
    if (!havobj(d, d->nounno)) {
        nohave(d);
        return;
    }
    disply(message[31]);
    dmsg(42);
}

//        LOOK SWITCH

void look09(struct advdata *d)
{
    if (d->room == 3 || d->room == 6 || d->room == 7) {
        dmsg(12);
        return;
    }
    lookob(d);
}

//        LOOK DEVICE

void look10(struct advdata *d)
{
    if (ckobj(d, 117)) {          // SPEAKER
        dmsg(14);
        return;
    }
    if (ckobj(d, 122)) {          // DEVICE
        dmsg(44);
        return;
    }
    nosee(d);
}

//        LOOK PASSAGE

void look11(struct advdata *d)
{
    if (d->room == 4) {
        dmsg(12);
        return;
    }
    if (ckobj(d, 123)) {          // STORAGE CABINET W/PASSAGE
        dmsg(12);
        return;
    }
    lookob(d);
}

//        LOOK PATH

void look14(struct advdata *d)
{
    if (d->room == 16 || d->room == 9) {
        dmsg(12);
        return;
    }
    nosee(d);
}

//        LOOK MICROFILM

void look15(struct advdata *d)
{
    if (!havobj(d, d->nounno)) {
        nohave(d);
        return;
    }
    if (!havobj(d, 11)) {         // SPECS
        dmsg(68);
        return;
    }
    dmsg(69);
}

//        LOOK ENERGIZER

void look16(struct advdata *d)
{
    if (d->room == 6 || d->room == 7) {
        dmsg(12);
        return;
    }
    nosee(d);
}

//        LOOK HILL

void look17(struct advdata *d)
{
    if (d->room == 8 || d->room == 15 || d->room == 16) {
        dmsg(12);
        return;
    }
    nosee(d);
}

//        LOOK FIELD

void look18(struct advdata *d)
{
    if (d->room == 8) {
        dmsg(12);
        return;
    }
    lookob(d);
}

//        LOOK LAB

void look19(struct advdata *d)
{
    if (d->room == 5) {
        dmsg(12);
        return;
    }
    lookob(d);
}

//        LOOK SHACK

void look20(struct advdata *d)
{
    if (d->room == 19) {
        dmsg(12);
        return;
    }
    lookob(d);
}

//        LOOK SHED

void look21(struct advdata *d)
{
    if (d->room == 17) {
        dmsg(12);
        return;
    }
    lookob(d);
}

//        GET RUG

//        GET DESK OR TABLE

//        GET MANUAL/SPECS

//        GET MICE

//        GET BOAT

//        GET PADDLES

//        PUT MICE

//        PUT JEWELS

//        GO STAIRS

//        GO LADDER/DOOR/CELLAR

//        GO PASSAGE

//        GO DEVICE

//        GO FIELD

//        GO PATH

//        GO LAB

//        GO SHED

//        GO SHACK

//        GO HILL

//        GO JUNGLE

//        GO CREVICE

//
//        PROTECTION BELOW
//

//
//        PROTECTION ABOVE
//

//        GO SHORE/BEACH

//        GO BOAT

//        GO CLEARING

//        GO DOOR

//        FEED VERB PROCESSOR

//        CUT VERB PROCESSOR

//        KILL VERB PROCESSOR

//        INFLATE VERB PROCESSOR

//        DEFLATE VERB PROCESSOR

//        ACTIVATE VERB PROCESSOR

//        PRESS VERB PROCESSOR

//
//        PROTECTION BELOW
//

//
//        PROTECTION ABOVE
//

//        UNLIGHT VERB PROCESSOR

//        LIGHT VERB PROCESSOR

//        READ VERB PROCESSOR

//        UNLOCK VERB PROCESSOR

//        TRADE VERB PROCESSOR

//        BAIL VERB PROCESSOR

//        ROW VERB PROCESSOR

//        DIG VERB PROCESSOR

//        GIVE VERB PROCESSOR

//        OPEN VERB PROCESSOR

//        OPEN CHEST

//        OPEN DESK

//        SPECIAL GET ROUTINE FOR IN SHACK

//        CHECK FOR IN DARK AREA

//        CHECK EACH ITEM OF A PUT ALL

//        CHECK EACH ITEM OF A GET ALL

//        ROUTINE PERFORMED AFTER EACH MOVE

//        IN ROOM ROUTINES

//        ROOM 06

//        ROOM 24

//        ENTER ROOM ROUTINES

//        ROOM 03

void entr03(struct advdata *d)
{
    if (!locobj(d, 3)) {          // LIT FLASHLIGHT
        if ((rand() & 0x7f) <= 50) {
            disply(message[102]);
        }
    }
}

//        ROOM 06

//        ROOM 15

//        ROOM 19

//        ROOM 23

//        ROOM 24

//        EXIT ROOM ROUTINES

//        ROOM 03

void exit03(struct advdata *d)
{
    if (!locobj(d, 3)) {          // LIT FLASHLIGHT
        if ((rand() & 0x7f) <= 40) {
            dead1(d, 102);
            return;
        }
    }
}

//        ROOM 06

//        ROOM 19

//        ROOM 22

//        ROOM 24

//        EXIT FROM BOAT

//        ANIMATION ROUTINES

//        MOVE CLOUDS IN SKY

void movclo(struct advdata *d)
{
    STUB();
}

//        MOVE LASER IN LAB

void movlsr(struct advdata *d)
{
    STUB();
}

//        BLINK LIGHTS IN DEVICE

void movlit(struct advdata *d)
{
    STUB();
}

//        MOVE SNAKES TAIL

void movsnk(struct advdata *d)
{
    STUB();
}

//        MOVE CLOCK IN STUDY

void movclk(struct advdata *d)
{
    STUB();
}

//
//        END FILE: ADVCODE2.ASM   --   CALIXTO ISLAND
//
