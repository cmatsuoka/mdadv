//
//        FILE: ADVCODE2.ASM   --   CALIXTO ISLAND
//

#include "advdata1.h"
#include "advcode2.h"

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
        if (!ckobj(94)) {        // OPEN DESK
            nosee(d);
            return;
        }
        if (!makvis(27+INV)) {   // MICROFILM
            dmsg012();
            return;
        }
        ckdraw();
        dmsg011();
        return;
    }

    if (desksw) {
        dmsg029();
        disply(28);
        dmsg017();
        return;
    }
}

//        LOOK TABLE

void look02(struct advdata *d)
{
    if (!ckobj(121)) {            // TABLE
        nosee(d);
        return;
    }
    if (!makvis(18+INV)) {        // MESSAGE
        dmsg012();
        return;
    }
    ckdraw();
    dmsg030();
}

//        LOOK RUG

void look03(struct advdata *d)
{
    if (locobj(10)) {             // RUG
        dmsg012();
        return;
    }
    if (ckobj(119)) {             // LADDER TO CELLAR
        dmsg012();
        return;
    }
    dmsg031();
}

//        LOOK DOOR

void look04(struct advdata *d)
{
    if (d->room >= 5 && d->room <= 8) {
        if (d->room == 8) {
            if (!ckobj(122)) {    // DEVICE
                nosee();
                return;
            }
        }
        dmsg012();
        return;
    }
    if (!ckobj(d->nounno)) {
        nosee();
        return;
    }
    if (ckobj(119)) {             // LADDER
        dmsg012();
        return;
    }
    disply(31);
    dmsg029();
}

//        LOOK CHEST

void look05(struct advdata *d)
{
    equobj(d);
    if (!locobj(d->nounno)) {
        nosee();
        return;
    }
    switch (chstsw) {
    case 0:
        dmsg016();
        return;
    case 1:
        dmsg035();
        return;
    case 2:
        dmsg036();
        return;
    }
    dmsg022();
}

//        LOOK CABINET

void look06(struct advdata *d)
{
    if (d->room != 3) {
        nosee();
        return;
    }
    if (mkvis(16+INV)) {          // MOUSETRAP
        ckdraw();
        dmsg037();
        returnl
    }
    disply(11);
    dmsg038();
}

//        LOOK LADDER

void look07(struct advdata *d)
{
    if (d->room == 3) {
        dmsg012();
        return;
    }
    lookob(d);
}

//        LOOK MANUAL

void look08(struct advdata *d)
{
    if (!havobj(d->nounno)) {
        nohave();
        return;
    }
    disply(31);
    dmsg042();
}

//        LOOK SWITCH

void look09(struct advdata *d)
{
    if (d->room == 3 || d->room == 6 || d->room == 7) {
        dmsg012();
        return;
    }
    lookob(d);
}

//        LOOK DEVICE

void look10(struct advdata *d)
{
    if (ckobj(117)) {             // SPEAKER
        dmsg014();
        return;
    }
    if (ckobj(122)) {             // DEVICE
        dmsg044();
        return;
    }
    nosee();
}

//        LOOK PASSAGE

//        LOOK PATH

//        LOOK MICROFILM

//        LOOK ENERGIZER

//        LOOK HILL

//        LOOK FIELD

//        LOOK LAB

//        LOOK SHACK

//        LOOK SHED

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

//        ROOM 06

//        ROOM 15

//        ROOM 19

//        ROOM 23

//        ROOM 24

//        EXIT ROOM ROUTINES

//        ROOM 03

//        ROOM 06

//        ROOM 19

//        ROOM 22

//        ROOM 24

//        EXIT FROM BOAT

//        ANIMATION ROUTINES

//        MOVE CLOUDS IN SKY

//        MOVE LASER IN LAB

//        BLINK LIGHTS IN DEVICE

//        MOVE SNAKES TAIL

//        MOVE CLOCK IN STUDY

//
//        END FILE: ADVCODE2.ASM   --   CALIXTO ISLAND
//
