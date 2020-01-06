
#include "advdata1.h"
#include "advcode1.h"

//********************************************************************
//
//  VLOOK  - "LOOK" VERB HANDLER
//
//********************************************************************


//********************************************************************
//
//  LOOKOB - GENERAL LOOK AT OBJECT ROUTINE
//
//********************************************************************


//********************************************************************
//
//  NOSEE  - DISPLAY OBJECT NOT SEEN MESSAGE
//
//********************************************************************

void nosee1(struct advdata *d, int msg)
{
    disply(message[msg]);
    int p = 0;
    for (struct them_table *t = themtb; t->obj_num != 0; t++) {
        if (t->pronoun) {
            if (d->nounno == t->obj_num) {
                p = t->pronoun;
            }
        }
    }
    disply pronoun[p];
}

void nosee(struct advdata *d)
{
    noosee1(d, 7);
}

//********************************************************************
//
//  NOHAVE - DISPLAY DON'T HAVE OBJECT MESSAGE
//
//********************************************************************

void nohave(struct advdata *d)
{
    nosee(d, 10);
}

//********************************************************************
//
//  ALRHAV - DISPLAY ALREADY HAVE OBJECT MESSAGE
//
//********************************************************************

void alrhav(struct advdata *d)
{
    nosee(d, 8);
}

//********************************************************************
//
//  VGO    - "GO" VERB HANDLER
//
//********************************************************************


//********************************************************************
//
//  VINVE  - "INVENTORY" VERB HANDLER
//
//********************************************************************


//********************************************************************
//
//  VGET   - "GET" VERB HANDLER
//
//********************************************************************


//********************************************************************
//
//  VPUT   - "PUT" VERB HANDLER
//
//********************************************************************


//********************************************************************
//
//  VSCORE - "SCORE" VERB HANDLER
//
//********************************************************************


//********************************************************************
//
//  BADINP - PROCESS UNKNOWN INPUT
//
//********************************************************************


//********************************************************************
//
//  REPLY  - ADVENTURE MAINLINE PROCESSOR
//
//********************************************************************


//********************************************************************
//
//  VHELP  - GENERAL HELP VERB PROCESSOR
//
//********************************************************************


//********************************************************************
//
//  VSAVE  - SAVE GAME PROCESSOR
//
//********************************************************************


//********************************************************************
//
//  VLOAD  - LOAD GAME PROCESSOR
//
//********************************************************************


//********************************************************************
//
//  DEAD1  - END OF GAME ROUTINES
//
//********************************************************************


//********************************************************************
//
//  DSPMSG - DISPLAY MESSAGE ROUTINES
//
//********************************************************************
