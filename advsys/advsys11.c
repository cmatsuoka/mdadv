//	   FILE = ADVSYSI/ASM	LAST MODIFIED: 12/30/84

//    ********** THIS VERSION OF ADVSYSI MUST BE USED FOR ALL **********
//    ********** ADVENTURES PRIOR TO THE VORTEX FACTOR.	     **********

// VERSION 1.1 - 12/30/84
//	      CORRECTED ERRORS IN THE SCROLL DOWN ROUTINE (SCRDN)
//	      AND LOCATE LAST LINE OF OVERLAY ROUTINE (CALC_LAST)
//	      WHICH WERE PREVENTING THEM FROM WORKING PROPERLY.
// VERSION 1.1A - 10/11/85
//	      ADDED CODE TO ENABLE F1/F2 PANIC BUTTON.
// VERSION 1.1B - 12/15/87
//	      Modified timer interrupt CHKANT to use INT 08H rather than
//	      INT 1CH to support TI S1100.
//

#include "advsys.h"
#include "screen.h"
#include "text.h"
#include <stdint.h>

//********************************************************************
//
//  CLS	  CLEAR ENTIRE GRAPHIC & TEXT SCREENS
//	  (ENTRY POINT "CLS_CLR" ALLOWS DEFAULT COLOR IN "AX")
//
//	  INPUT:  NONE
//	  OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CLSTXT - CLEAR TEXT AREA OF THE SCREEN
//
//	  INPUT:  NONE
//	  OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  SHOSCR - DISPLAY BACKGROUND SCREEN ON VIDEO
//
//	    INPUT:  SI = POINTER TO COMPRESSED SCREEN DATA
//	    OUTPUT: NONE
//
//********************************************************************

void shoscr(int x, int y, uint8_t *ovl)
{
    dispovl(0, 0, ovl);
    show_screen();
}

//********************************************************************
//
//  SHOOBJ - DISPLAY GRAPHIC OVERLAYS ON SCREEN
//
//********************************************************************


//********************************************************************
//
//  SHOOVL - CALCULATE OVERLAY TABLE ENTRY FOR AN OVERLAY AND
//	    DISPLAY THE OVERLAY ON THE VIDEO SCREEN
//
//	    INPUT:  AL = OVERLAY NUMBER
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  DISPOVL - DISPLAY OVERLAY ON VIDEO SCREEN
//
//	    INPUT:  SI = POINTER TO THE COMPRESSED OVERLAY DATA
//		    DI = SCREEN OFFSET OF OVERLAY UPPER LEFT CORNER
//		    AL = EVEN/ODD VIDEO SCAN LINE INDICATOR
//			 IF = 0 START IS ON EVEN SCAN LINE
//			 IF = 1 START IS ON ODD SCAN LINE
//	    OUTPUT: NONE
//
//********************************************************************

void dispovl(int x, int y, uint8_t *ovl)
{
    display_overlay(x, y, ovl, 0); 
}

//********************************************************************
//
//  BIT_EXPL - EXPLODE A COLOR BYTE (4 PIXELS) INTO A COLOR WORD
//	      (8 PIXELS) BY DOUBLING EACH OF THE PIXELS
//
//	    INPUT:  AL = COLOR BYTE (4 PIXELS)
//	    OUTPUT: AX = COLOR WORD (8 PIXELS)
//
//********************************************************************


//********************************************************************
//
//  OBJBYT - PROCESS COMPRESSED OVERLAY DATA AND RETURN THE NEXT
//	    DATA BYTE EACH TIME CALLED
//
//	    INPUT:  NONE (INITIALIZE "MODE" TO ZERO BEFORE 1ST CALL)
//	    OUTPUT: AL = NEXT BYTE OF OVERLAY DATA
//		    AH = STATUS OF REQUEST
//			 IF = 0 THEN DATA BYTE RETURNED
//			 IF = 1 THEN NO MORE DATA FOR OVERLAY
//
//********************************************************************


//********************************************************************
//
//  DISPLY - DISPLAY TEXT STRING ON VIDEO AT CURRENT ROW/COL AND
//	    PROVIDE FOR WORD WRAP
//
//	    INPUT:  BX = POINTER TO TEXT STRING (TERMINATED BY 00H)
//	    OUTPUT: NONE
//
//********************************************************************

void disply(char *msg)
{
    display_text(msg);
}

//********************************************************************
//
//  TXTOUT - DISPLAY COMPRESSED PHRASE WITH POSSIBLE COMPRESSED
//	    PHRASES IMBEDDED WITHIN IT
//
//	    INPUT:  AL = COMPRESSED PHRASE NUMBER + 80H
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CHROUT - DISPLAY A SINGLE CHARACTER ON THE VIDEO SCREEN AT THE
//	    CURRENT ROW/COL
//
//	    INPUT:  AL = CHAR TO DISPLAY
//	    OUTPUT: NONE
//
//********************************************************************

void chrout(int ch)
{
    display_char(ch);
}

//********************************************************************
//
//  SCROLL - SCROLL THE TEXT SCREEN
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CLR_LINE - CLEAR THE CURRENT TEXT ROW
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CLR_CHAR - CLEAR THE CURRENT TEXT CHARACTER
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  GETLIN - GET INPUT LINE FROM KEYBOARD AND DISPLAY ON SCREEN
//
//	    INPUT:  NONE
//	    OUTPUT: "KEYBUF" CONTAINS THE LINE TYPED TERMINATED
//		    BY 00H
//
//********************************************************************


//********************************************************************
//
//  CURSOR - BLINK CURSOR ON SCREEN
//
//	    INPUT:  SI = KEEPS CURSOR BLINK COUNT
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CALC_CUR - CALCULATE SCREEN OFFSET FOR CURRENT ROW/COL
//
//	    INPUT:  NONE
//	    OUTPUT: BX = CURRENT SCREEN OFFSET
//
//********************************************************************


//********************************************************************
//
//  SOUND  - CREATE BEEP SOUND FOR "MORE" MESSAGE
//
//	    INPUT:  DI = FREQUENCY IN HERTZ (21 TO 65535)
//		    BX = DURATION IN HUNDREFTHS OF A SECOND
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  SCRUP  - SCROLL SCREEN UP
//
//	    INPUT:  BX = SCREEN OFFSET FOR UPPER LEFT CORNER
//		    AL = # BYTES IN A SCROLL LINE
//		    AH = # LINES TO SCROLL
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  SCRDN  - SCROLL SCREEN DOWN
//
//	    INPUT:  BX = SCREEN OFFSET FOR UPPER LEFT CORNER
//		    AL = # BYTES IN A SCROLL LINE
//		    AH = # LINES TO SCROLL
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  SCRLFT - SCROLL SCREEN LEFT
//
//	    INPUT:  BX = SCREEN OFFSET FOR UPPER LEFT CORNER
//		    AL = # BYTES IN A SCROLL LINE
//		    AH = # LINES TO SCROLL
//	    OUTPUT: NONE
//
//********************************************************************


//	 SHIFT "DX" LEFT 2 PIXELS AND MOVE THEM INTO THE
//	 RIGHT SIDE OF "AX"


//********************************************************************
//
//  SCRRIT - SCROLL SCREEN RIGHT
//
//	    INPUT:  BX = SCREEN OFFSET FOR UPPER LEFT CORNER
//		    AL = # BYTES IN A SCROLL LINE
//		    AH = # LINES TO SCROLL
//	    OUTPUT: NONE
//
//********************************************************************


//	 SHIFT "DX" RIGHT 2 PIXELS AND MOVE THEM INTO THE
//	 LEFT SIDE OF "AX"


//********************************************************************
//
//  REPCLR - REPLACE ONE COLOR WITH ANOTHER
//
//	    INPUT:  BX = SCREEN OFFSET FOR UPPER LEFT CORNER
//		    AL = # BYTES IN A SCROLL LINE
//		    AH = # LINES TO SCROLL
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CHGCLR - REPLACE ONE COLOR WITH ANOTHER
//
//	    INPUT:  AX = COLOR WORD FROM SCREEN
//	    OUTPUT: AX = MODIFIED COLOR WORD
//
//********************************************************************


//********************************************************************
//
//  FLPCLR - EXCHANGE TWO COLORS
//
//	    INPUT:  BX = SCREEN OFFSET FOR UPPER LEFT CORNER
//		    AL = # BYTES IN A SCROLL LINE
//		    AH = # LINES TO SCROLL
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  XCGCLR - EXCHANGE TWO COLORS
//
//	    INPUT:  AX = COLOR WORD FROM SCREEN
//	    OUTPUT: AX = MODIFIED COLOR WORD
//
//********************************************************************


//********************************************************************
//
//  CALC_EOL - CALC END OF LINE ADDR FOR CURRENT OVERLAY
//
//	    INPUT:  AL = LINE LENGTH OF OVERLAY (# WORDS)
//		    BX = POINTER TO LEFT CORNER OF OVERLAY
//	    OUTPUT: BX = POINTER TO RIGHT CORNER OF OVERLAY
//
//********************************************************************


//********************************************************************
//
//  CALC_LAST - CALC END OF LINE ADDR FOR CURRENT OVERLAY
//
//	    INPUT:  AL = # OF SCAN LINES IN OVERLAY
//		    BX = POINTER TO TOP SCAN LINE OF OVERLAY
//	    OUTPUT: BX = POINTER TO BOTTOM SCAN LINE OF OVERLAY
//
//********************************************************************


//********************************************************************
//
//  LODGAM - LOAD SAVED GAME ROUTINE
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  SAVGAM - SAVE GAME ROUTINE
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  GETPOS - GET SAVE/LOAD GAME POSITION
//
//	    INPUT:  NONE
//	    OUTPUT: AL = SAVE POSITION (13H = ABORT)
//
//********************************************************************


//********************************************************************
//
//  DSKERR - CRITICAL DISK I/O ERROR ROUTINE
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//********************************************************************
//
//  CHKANT - TIMER TICK INTERRUPT ROUTINE TO DRIVE ANTIMATION
//
//	    INPUT:  NONE
//	    OUTPUT: NONE
//
//********************************************************************


//	 END FILE = ADVSYSI/ASM
