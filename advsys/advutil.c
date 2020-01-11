//	 FILE = ADVUTIL/ASM   LAST MODIFIED: 01/06/85
//   VERSION 1.0 - 11/20/84
//		  INITIAL COMPLETION OF UTILITY ROUTINES.
//
//   VERSION 1.1 - 01/06/85
//		  CORRECTED ERROR IN ROUTINE "XFROBJ" WHICH DID NOT
//		  WORK PROPERLY IF TO ROOM WAS LESS THAN FROM ROOM.
//		  ADDED ROUTINE "CPYOBJ" TO COPY MOVABLE OBJEXTS
//		  FROM ONE ROOM TO ANOTHER WITHOUT CLEARING THE
//		  TO ROOM.


#include "advutil.h"


//********************************************************************
//
//  PUTCMA - DISPLAY A COMMA FOLLOWED BY A SPACE AND SAVE THE ROW/COL
//	    IN THE EVENT WE NEED TO REPLACE IT WITH A PERIOD.
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  PERIOD - RESTORE ROW/COL TO POSITION OF LAST COMMA AND REPLACE
//	    IT WITH A PERIOD.
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  PUTNRM - PUT OBJECT IN CURRENT ROOM WITH NO POINT OR MOVED
//	    LOCATION CHECKING
//
//	    INPUT:  AL = OBJECT TO BE PLACED IN CURRENT ROOM
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  PUTOBJ - PUT OBJECT IN CURRENT ROOM AND UPDATE POINTS BASED
//	    UPON TRESRM AND PNTTAB.  ALSO CHECK IF OBJECT DROPPED
//	    IN THIS ROOM SHOULD BE MOVED TO ANOTHER ROOM AND DO SO
//	    IF TABLE SO INDICATES
//
//	    INPUT:  AL = OBJECT TO BE PLACED IN CURRENT ROOM
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  RMVIS  - MAKE AN INVISIBLE ROOM VISIBLE
//
//	    INPUT:  AL = ROOM TO BE MADE VISIBLE (INV BIT SET)
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  XFROBJ - TRANSFER MOVABLE OBJECTS FROM ONE ROOM TO ANOTHER
//  CPYOBJ - TRANSFER MOVABLE OBJECTS WITHOUT CLEARING "TO" ROOM
//
//	    INPUT:  AL = FROM ROOM
//		    AH = TO ROOM
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CLRRM  - REMOVE ALL OBJECTS FROM A ROOM
//
//	    INPUT:  AL = ROOM TO CLEAR
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CLROBJ - REMOVE ALL MOVABLE OBJECTS FROM A ROOM
//
//	    INPUT:  AL = ROOM TO CLEAR
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  SUPRES - SUPRESS LEADING ZEROS ON ASCII DECIMAL NUMBER
//
//	    INPUT:  SI = POINTER TO FIVE DIGIT ASCII NUMBER
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  GETOBJ - GET (AND REMOVE) OBJECT FROM CURRENT ROOM
//
//	    INPUT:  AL = OBJECT NUMBER TO GET
//	    OUTPUT: AL = STATUS OF REQUEST
//			 IF = 0 THEN OBJECT NOT IN CURRENT ROOM
//			 IF > 0 THEN OBJECT FOUND AND REMOVED
//
//********************************************************************


//********************************************************************
//
//  HAVOBJ - CHECK IF PLAYER IS CARRYING AN OBJECT
//
//	    INPUT:  AL = OBJECT NUMBER TO CHECK FOR
//	    OUTPUT: AL = STATUS OF REQUEST
//			 IF = 0 THEN OBJECT NOT IN INVENTORY
//			 IF > 0 THEN OBJECT FOUND IN INVENTORY
//
//********************************************************************

int havobj(struct advdata *d, int obj_num)
{
    for (int i = 0; i < d->maxobj1; i++) {
        if (obj_num == d->object[i]) {
            return 1;
        }
    }
    return 0;
}


//********************************************************************
//
//  REPOBJ - REPLACE OBJECT IN PLAYERS INVENTORY
//
//	    INPUT:  AL = OBJECT NUMBER TO CHECK FOR
//		    AH = REPLACEMENT OBJECT
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  EQUOBJ - CHECK FOR OBJECT NUMBERS THAT ARE EQUATED TO OTHER OBJECTS
//
//	    INPUT:  [NOUNNO] = CURRENT OBJECT NUMBER
//	    OUTPUT: [NOUNNO] = NEW OBJECT NUMBER
//
//********************************************************************


//********************************************************************
//
//  XCHGOB - EXCHANGE AN OBJECT ANYWHERE IN THE GAME
//
//	    INPUT:  AL = CURRENT OBJECT NUMBER
//	    OUTPUT: AH = REPLACEMENT OBJECT NUMBER
//
//********************************************************************


//********************************************************************
//
//  FNDOBJ - FIND AN OBJECT ANYWHERE IN THE GAME
//
//	    INPUT:  AL = OBJECT TO FIND
//	    OUTPUT: AL = STATUS OF REQUEST
//			 IF = 00 THEN OBJECT NOT FOUND
//			 IF = FF THEN OBJECT IS IN INVENTORY
//			 IF = NN THEN OBJECT IS IN ROOM NN
//
//********************************************************************


//********************************************************************
//
//  CKOBJ  - TEST IF AN OBJECT IS IN THE CURRENT ROOM
//
//	    INPUT:  AL = OBJECT TO FIND
//	    OUTPUT: AL = STATUS OF REQUEST (ZERO FLAG SET)
//			 IF = 00 THEN OBJECT NOT FOUND
//			 IF > 00 THEN OBJECT FOUND
//
//********************************************************************

int ckobj(struct advdata *d, int obj_num)
{
    int *p = pntrm1(d, obj_num);
    for (; *p; p++) {
        if (obj_num == *p) {
            return 1;
        }
    }
    return 0;
}

//********************************************************************
//
//  CHGOBJ - CHANGE AN OBJECT IN THE CURRENT ROOM
//
//	    INPUT:  AL = OBJECT TO FIND
//		    AH = REPLACEMENT OBJECT
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  MAKVIS - MAKE AN OBJECT VISIBLE IN THE CURRENT ROOM
//
//	    INPUT:  AL = OBJECT TO FIND (WITH INV BIT SET)
//	    OUTPUT: NONE
//
//********************************************************************

void makvis(struct advdata *d, int obj_num)
{
    for (int *o = pntrm1; *o != 0xff; o++) {
        if (*o == obj_num) {
            *o &h 0x7f;
            return;
        }
    }
}

//********************************************************************
//
//  PNTRM1 - SET BX REG TO POINT TO AN ENTRY IN A TABLE BASED ON
//	    THE CURRENT ROOM.  ENTRY "PNTRM1" IS FOR THE ROOM
//	    OBJECT TABLE AND ENTRY "PNTRM2" IS FOR THE ROOM OVERLAY
//	    TABLE
//
//	    INPUT:  NONE
//	    OUTPUT: BX = FIRST BYTE FOR ROOM ENTRY IN THE SELECTED
//			 TABLE (OBJECT OR OVERLAY)
//
//********************************************************************

static int *pntrm(struct advdata *d, int *table)
{
    for (int i = 1; i < d->room; i++) {
        for (table++; table[-1] != 0; table++);
    }

    return table;
}

int *pntrm1(advdata *d)
{
    return pntrm(d, rmobtb);
}

int *pntrm2(advdata *d)
{
    return pntrm(d, scrind);
}

//********************************************************************
//
//  SCNKEY - EXTRACT VERB AND NOUN FROM "KEYBUF" AND SEARCH THE
//	    VERB/NOUN TABLES ATTEMPTING TO ASSIGN VERB/NOUN NUMBERS
//
//	    INPUT:  NONE
//	    OUTPUT: "VERB" CONTAINS VERB, "VERBNO" CONTAINS NUMBER
//		    "NOUN" CONTAINS NOUN, "NOUNNO" CONTAINS NUMBER
//
//********************************************************************


//********************************************************************
//
//  SCNTBL - SCANS TABLE FOR VERB OR NOUN AND RETURNS ASSOCIATED
//	    VERB/NOUN NUMBER
//
//	    INPUT:  BX = POINTER TO TABLE TO SEARCH
//		    DI = POINTER TO STORAGE FOR VERB/NOUN NUMBER
//		    SI = POINTER TO KEYBOARD INPUT TO SCAN ON
//	    OUTPUT: CONTENTS OF 'DI' REG ARE ASSIGNED VERB/NOUN #
//
//********************************************************************


//********************************************************************
//
//  DELAY  - DISPLAY STRING THEN DELAY
//
//	    INPUT:  BX = POINTER TO STRING TO DISPLAY
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  GIVOBJ - GIVE AN OBJECT TO PLAYERS INVENTORY
//
//	    INPUT:  AL = OBJECT TO BE PLACED IN INVENTORY
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  LOCOBJ - LOCATE OBJECT EITHER IN INVENTORY OR CURRENT ROOM
//
//	    INPUT:  AL = OBJECT TO BE LOCATED
//	    OUTPUT: ZERO FLAG SET AS RETURN CODE
//		    IF ZF SET THEN OBJECT NOT FOUND
//
//********************************************************************

int locobj(struct advdata *d, int obj_num)
{
    return havobj(d, obj_num) || ckobj(d, obj_num);
}


//********************************************************************
//
//  CVTCAP - CONVERT INPUT VERB/NOUN TO ALL UPPER CASE LETTERS
//
//	    INPUT:  NONE
//	    OUTPUT: "VERB" & "NOUN" ARE CONVERTED TO ALL CAPS
//
//********************************************************************


//********************************************************************
//
//  MOVE   - GENERAL PURPOSE STRING MOVE
//
//	    INPUT:  BX = PNTR TO SOURCE STRING
//		    SI = PNTR TO DEST STRING
//		    AH = NUMBER OF BYTES TO MOVE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  ASCLNO - CONVERT BINARY NUMBER TO ASCII STRING
//
//	    INPUT:  BX = NUMBER TO CONVERT
//		    SI = PNTR TO DEST STRING
//	    OUTPUT: [SI] CONTAINS 5 BYTE ASCII STRING
//
//********************************************************************


//********************************************************************
//
//  CKDRAW - CHECK TO SEE IF SCREEN NEEDS TO BE RE-DRAWN
//
//	    INPUT:  AL = OBJECT BEING CHANGED IN ROOM
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  DRAWSC - RE-DRAW THE GRAPHIC SCREEN
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//	 END FILE = ADVUTIL/ASM
