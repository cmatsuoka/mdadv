//
//        FILE: ADVCODE2.ASM   --   CALIXTO ISLAND
//

#include <stdlib.h>
#include "advdata1.h"
#include "advdata2.h"
#include "advcode1.h"
#include "advcode2.h"
#include "advutil.h"
#include "protect.h"


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

void get01(struct advdata *d)
{
    STUB();
}

//        GET DESK OR TABLE

void get02(struct advdata *d)
{
    STUB();
}

//        GET MANUAL/SPECS

void get03(struct advdata *d)
{
    STUB();
}

//        GET MICE

void get04(struct advdata *d)
{
    STUB();
}

//        GET BOAT

void get05(struct advdata *d)
{
    STUB();
}

//        GET PADDLES

void get06(struct advdata *d)
{
    STUB();
}

//        PUT MICE

void put01(struct advdata *d)
{
    STUB();
}

//        PUT JEWELS

void put04(struct advdata *d)
{
    STUB();
}

//        GO STAIRS

void go01(struct advdata *d)
{
    STUB();
}

//        GO LADDER/DOOR/CELLAR

void go02(struct advdata *d)
{
    STUB();
}

//        GO PASSAGE

void go03(struct advdata *d)
{
    STUB();
}

//        GO DEVICE

void go04(struct advdata *d)
{
    STUB();
}

//        GO FIELD

void go05(struct advdata *d)
{
    STUB();
}

//        GO PATH

void go06(struct advdata *d)
{
    STUB();
}

//        GO LAB

void go07(struct advdata *d)
{
    STUB();
}

//        GO SHED

void go08(struct advdata *d)
{
    STUB();
}

//        GO SHACK

void go09(struct advdata *d)
{
    STUB();
}

//        GO HILL

void go10(struct advdata *d)
{
    STUB();
}

//        GO JUNGLE

void go11(struct advdata *d)
{
    STUB();
}

//        GO CREVICE

void go12(struct advdata *d)
{

//
//        PROTECTION BELOW
//
    if (validsw != protsw) {      // CHECK FOR LEGAL COPY OF GAME
        dmsg(23);                 //   AND DISALLOW ENTRY TO
        return;                   //   PASSAGE IF NOT VALID
    }
//
//        PROTECTION ABOVE
//
    STUB();
}

//        GO SHORE/BEACH

void go13(struct advdata *d)
{
    STUB();
}

//        GO BOAT

void go14(struct advdata *d)
{
    STUB();
}

//        GO CLEARING

void go15(struct advdata *d)
{
    STUB();
}

//        GO DOOR

void go16(struct advdata *d)
{
    STUB();
}

//        FEED VERB PROCESSOR

void vfeed(struct advdata *d)
{
    STUB();
}

//        CUT VERB PROCESSOR

void vcut(struct advdata *d)
{
    STUB();
}

//        KILL VERB PROCESSOR

void vkill(struct advdata *d)
{
    STUB();
}

//        INFLATE VERB PROCESSOR

void vinfl(struct advdata *d)
{
    STUB();
}

//        DEFLATE VERB PROCESSOR

void vdefl(struct advdata *d)
{
    STUB();
}

//        ACTIVATE VERB PROCESSOR

void vactiv(struct advdata *d)
{
    STUB();
}

//        PRESS VERB PROCESSOR

void vpress(struct advdata *d)
{
//
//        PROTECTION BELOW
//
    if (validsw != protsw) {      // CHECK FOR LEGAL COPY OF GAME
        dmsg(55);                 //   AND DISALLOW ENTRY TO
        return;                   //   PASSAGE IF NOT VALID
    }

//
//        PROTECTION ABOVE
//
    STUB();
}

//        UNLIGHT VERB PROCESSOR

void vunlit(struct advdata *d)
{
    STUB();
}

//        LIGHT VERB PROCESSOR

void vlight(struct advdata *d)
{
    STUB();
}

//        READ VERB PROCESSOR

void vread(struct advdata *d)
{
    if (d->nounno == 125) {       // SIGN
        if (d->room == 4) {
            dmsg(47);
            return;
        }
        if (d->room == 19) {      // IN SHACK
            if (ckobj(d, 125)) {  // SIGN
                dmsg(101);
                return;
            }
        }
        nosee(d);
        return;
    }
    if (d->nounno == 12) {        // MANUAL
        if (!havobj(d, 12)) {
            nohave(d);
            return;
        }
        if (ckobj(d, 117)) {      // SPEAKER
            dmsg(53);
        } else {
            dmsg(48);
        }
        return;
    }
    badinp(d);
}

//        UNLOCK VERB PROCESSOR

void vunlok(struct advdata *d)
{
    STUB();
}

//        TRADE VERB PROCESSOR

void vtrade(struct advdata *d)
{
    STUB();
}

//        BAIL VERB PROCESSOR

void vbail(struct advdata *d)
{
    STUB();
}

//        ROW VERB PROCESSOR

void vrow(struct advdata *d)
{
    STUB();
}

//        DIG VERB PROCESSOR

void vdig(struct advdata *d)
{
    STUB();
}

//        GIVE VERB PROCESSOR

void vgive(struct advdata *d)
{
    STUB();
}

//        OPEN VERB PROCESSOR

void vopen(struct advdata *d)
{
    if (d->nounno != 120) {       // TRAP DOOR
        badinp(d);
        return;
    }
    if (!ckobj(d, 120)) {
        nosee(d);
        return;
    }
    if (ckobj(d, 119)) {          // LADDER
        disply(message[28]);
        dmsg(18);
        return;
    }
    makvis(d, 119+INV);           // LADDER
    ckdraw(d);
    dmsg(11);
}

//        OPEN CHEST

void open01(struct advdata *d)
{
    if (locobj(d, 31)) {          // OPEN CHEST
        disply(message[28]);
        dmsg(18);
        return;
    }
    if (havobj(d, 30)) {          // CLOSED CHEST
        repobj(d, 30, 31);        // OPEN CHEST
        chstsw++;
        dmsg(18);
        return;
    }
    if (ckobj(d, 30)) {
        chgobj(d, 30, 31);
        ckdraw(d);
        chstsw++;
        dmsg(18);
        return;
    }
    nosee(d);
}

//        OPEN DESK

void open02(struct advdata *d)
{
    if (ckobj(d, 94)) {           // OPEN DESK
        dmsg(18);
        return;
    }
    if (ckobj(d, 126)) {          // CLOSED DESK
        if (desksw) {
           dmsg(17);
           return;
        }
        chgobj(d, 126, 94);
        ckdraw(d);
        dmsg(18);
        return;
    }
    nosee(d);
}

//        SPECIAL GET ROUTINE FOR IN SHACK

void getsha(struct advdata *d)
{
    STUB();
}

//        CHECK FOR IN DARK AREA

//        CHECK EACH ITEM OF A PUT ALL

//        CHECK EACH ITEM OF A GET ALL

//        ROUTINE PERFORMED AFTER EACH MOVE

//        IN ROOM ROUTINES

void inrm01(struct advdata *d)
{
    STUB();
}

//        ROOM 06

void inrm06(struct advdata *d)
{
    STUB();
}

//        ROOM 24

void inrm24(struct advdata *d)
{
    STUB();
}

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

void entr06(struct advdata *d)
{
    STUB();
}

//        ROOM 15

void entr15(struct advdata *d)
{
    STUB();
}

//        ROOM 19

void entr19(struct advdata *d)
{
    STUB();
}

//        ROOM 23

void entr23(struct advdata *d)
{
    STUB();
}

//        ROOM 24

void entr24(struct advdata *d)
{
    STUB();
}

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

void exit06(struct advdata *d)
{
    STUB();
}

//        ROOM 19

void exit19(struct advdata *d)
{
    STUB();
}

//        ROOM 22

void exit22(struct advdata *d)
{
    STUB();
}

//        ROOM 24

void exit24(struct advdata *d)
{
    STUB();
}

//        EXIT FROM BOAT

void exboat(struct advdata *d)
{
    STUB();
}

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
