#include <stdlib.h>
#include "advsys.h"
#include "advcode1.h"
#include "advcode2.h"

//
//        FILE: ADVDATA2.ASM
//
//        VERB TABLE

struct verb_noun verbtb[] = {
    { "LOOK", 1 },
    { "L   ", 1 },
    { "EXAM", 1 },
    { "INVE", 2 },
    { "I   ", 2 },
    { "G   ", 3 },
    { "GET ", 3 },
    { "TAKE", 3 },
    { "GRAB", 3 },
    { "PUT ", 4 },
    { "DROP", 4 },
    { "P   ", 4 },
    { "NORT", 5 },
    { "N   ", 5 },
    { "SOUT", 6 },
    { "S   ", 6 },
    { "EAST", 7 },
    { "E   ", 7 },
    { "WEST", 8 },
    { "W   ", 8 },
    { "UP  ", 9 },
    { "U   ", 9 },
    { "DOWN", 10 },
    { "D   ", 10 },
    { "GO  ", 11 },
    { "WALK", 11 },
    { "RUN ", 11 },
    { "ENTE", 11 },
    { "SAVE", 13 },
    { "LOAD", 14 },
    { "HELP", 15 },
    { "SCOR", 16 },
    { "OPEN", 17 },
    { "LIFT", 18 },
    { "READ", 19 },
    { "FEED", 20 },
    { "JUMP", 21 },
    { "ACTI", 22 },
    { "PRES", 23 },
    { "TURN", 23 },
    { "FLIP", 23 },
    { "PUSH", 23 },
    { "TRAD", 24 },
    { "FOLL", 25 },
    { "CUT ", 26 },
    { "CHOP", 26 },
    { "CLEA", 26 },
    { "CLIM", 27 },
    { "UNLO", 28 },
    { "LIST", 29 },
    { "HEAR", 29 },
    { "INFL", 30 },
    { "PUMP", 30 },
    { "DEFL", 31 },
    { "KILL", 32 },
    { "ATTA", 32 },
    { "FIGH", 32 },
    { "LIGH", 33 },
    { "UNLI", 34 },
    { "ROW ", 35 },
    { "PADD", 35 },
    { "BAIL", 36 },
    { "SIT ", 37 },
    { "LAUN", 37 },
    { "RELE", 38 },
    { "REMO", 38 },
    { "GIVE", 39 },
    { "DIG ", 40 },
    { "WEAR", 41 },
    { "QUIT", 42 },
    { NULL, 0 }
};

//        NOUN TABLE

struct verb_noun nountb[] = {
    { "NORT", 1 },
    { "SOUT", 2 },
    { "EAST", 3 },
    { "WEST", 4 },
    { "UP  ", 5 },
    { "DOWN", 6 },
    { "INVE", 7 },
    { "FLAS", 8 },
    { "LIGH", 8 },
    { "RUG ", 10 },
    { "SPEC", 11 },
    { "INST", 12 },
    { "MANU", 12 },
    { "JEWE", 13 },
    { "COST", 13 },
    { "TIRE", 14 },
    { "PUMP", 14 },
    { "BUCK", 15 },
    { "TRAP", 16 },
    { "MOUS", 16 },
    { "BOOT", 17 },
    { "MESS", 18 },
    { "PADD", 19 },
    { "SHOV", 20 },
    { "SPAD", 20 },
    { "BOAT", 21 },
    { "KEYS", 23 },
    { "KEY ", 23 },
    { "MACH", 24 },
    { "MICE", 26 },
    { "MICR", 27 },
    { "FILM", 27 },
    { "CROW", 28 },
    { "POTT", 29 },
    { "CHES", 30 },
    { "AIR ", 90 },
    { "JUNG", 91 },
    { "FOLI", 91 },
    { "GROW", 91 },
    { "HILL", 92 },
    { "ENER", 93 },
    { "BUTT", 94 },
    { "SWIT", 94 },
    { "SEAT", 95 },
    { "CELL", 97 },
    { "CLEA", 98 },
    { "FIEL", 99 },
    { "MARS", 99 },
    { "LAB ", 100 },
    { "LABO", 100 },
    { "OCEA", 101 },
    { "WATE", 101 },
    { "NATI", 102 },
    { "IDOL", 103 },
    { "TOMB", 104 },
    { "SHOR", 105 },
    { "BEAC", 106 },
    { "SAND", 108 },
    { "SHAC", 109 },
    { "GRAS", 109 },
    { "JACK", 110 },
    { "TRAD", 110 },
    { "SHED", 111 },
    { "SNAK", 112 },
    { "CREV", 114 },
    { "PATH", 115 },
    { "PASS", 116 },
    { "SPEA", 117 },
    { "PANE", 118 },
    { "LADD", 119 },
    { "DOOR", 120 },
    { "TABL", 121 },
    { "DEVI", 122 },
    { "TELE", 122 },
    { "CABI", 124 },
    { "SIGN", 125 },
    { "DESK", 126 },
    { "STAI", 127 },
    { "STEP", 127 },
    { "ALL ", 128 },
    { "EVER", 128 },
    { NULL, 0 }
};

// SPECIAL ACTION TABLE. LISTS
// VERB/NOUN COMBO'S THAT HAVE
// SPECIAL PROCESSING ROUTINES.
// FORMAT IS:
//
//  # BYTES       DEXCRIPTION
//  -------   ------------------
//     1      VERB NUMBER
//     1      NOUN NUMBER
//     2      SPECIAL RTN ADDR

struct special_action spcrtn[] = {
    { 0x017e, look01 },  // LOOK DESK
    { 0x0179, look02 },  // LOOK TABLE
    { 0x010a, look03 },  // LOOK RUG
    { 0x0178, look04 },  // LOOK DOOR
    { 0x011e, look05 },  // LOOK CHEST
    { 0x017c, look06 },  // LOOK CABINET
    { 0x0177, look07 },  // LOOK LADDER
    { 0x010c, look08 },  // LOOK MANUAL
    { 0x015e, look09 },  // LOOK SWITCH
    { 0x017a, look10 },  // LOOK DEVICE
    { 0x0174, look11 },  // LOOK PASSAGE
    { 0x0173, look14 },  // LOOK PATH
    { 0x011b, look15 },  // LOOK FILM
    { 0x015d, look16 },  // LOOK ENER
    { 0x015c, look17 },  // LOOK HILL
    { 0x0163, look18 },  // LOOK FIELD
    { 0x0164, look19 },  // LOOK LAB
    { 0x016d, look20 },  // LOOK SHACK
    { 0x016f, look21 },  // LOOK SHED
    { 0x015a, dmsg012 },  // LOOK AIR
    { 0x017d, vread },   // LOOK SIGN
    { 0x0307, vinve },   // TAKE INVENTORY
    { 0x030a, get01 },   // GET RUG
    { 0x037e, get02 },   // GET DESK
    { 0x0379, get02 },   // GET TABLE
    { 0x030b, get03 },   // GET SPECS
    { 0x030c, get03 },   // GET MANUAL
    { 0x031a, get04 },   // GET MICE
    { 0x0315, get05 },   // GET BOAT
    { 0x0313, get06 },   // GET PADDLES
    { 0x035a, dmsg026 },  // GET AIR
    { 0x041a, put01 },   // PUT MICE
    { 0x040d, put04 },   // PUT JEWELS
    { 0x045a, dmsg026 },  // PUT AIR
    { 0x0b7f, go01 },    // GO STAIRS
    { 0x0b77, go02 },    // GO LADDER
    { 0x0b61, go02 },    // GO CELLAR
    { 0x0b74, go03 },    // GO PASSAGE
    { 0x0b7a, go04 },    // GO DEVICE
    { 0x0b5f, go04 },    // GO SEAT
    { 0x0b63, go05 },    // GO FIELD
    { 0x0b73, go06 },    // GO PATH
    { 0x0b64, go07 },    // GO LAB
    { 0x0b6f, go08 },    // GO SHED
    { 0x0b6d, go09 },    // GO SHACK
    { 0x0b5c, go10 },    // GO HILL
    { 0x0b5b, go11 },    // GO JUNGLE
    { 0x0b72, go12 },    // GO CREVICE
    { 0x0b69, go13 },    // GO SHORE
    { 0x0b6a, go13 },    // GO BEACH
    { 0x0b15, go14 },    // GO BOAT
    { 0x0b62, go15 },    // GO CLEARING
    { 0x0b78, go16 },    // GO DOOR
    { 0x2515, go14 },    // SIT BOAT
    { 0x111e, open01 },  // OPEN CHEST
    { 0x117e, open02 },  // OPEN DESK
    { 0x110a, get01 },   // GET RUG
    { 0x120a, get01 },   // LIFT RUG
    { 0x1312, lookob },  // READ MESSAGE
    { 0x131b, look15 },  // READ FILM
    { 0x1368, lookob },  // READ TOMB
    { 0x1973, go06 },    // FOLLOW PATH
    { 0x1b77, go02 },    // CLIMB LADDER
    { 0x1b5c, go10 },    // CLIMB HILL
    { 0x1b7f, go01 },    // CLIMB STAIRS
    { 0x265a, vdefl },   // RELEASE AIR
    { 0x2911, getsha },  // WEAR BOOTS
    { 0x290b, get03 },   // WEAR SPECS
    { 0x0000, NULL }
};

// SPECIAL ACTION ON ENTRY TO A
// ROOM TABLE.  FORMAT IS:
//      ROOM#,RTNADDR

struct room_action entrtb[] = {
    { 3, entr03 },
    { 4, entr03 },
    { 6, entr06 },
    { 7, entr06 },
    { 11, entr03 },
    { 12, entr03 },
    { 13, entr03 },
    { 14, entr03 },
    { 15, entr15 },
    { 19, entr19 },
    { 23, entr23 },
    { 24, entr24 },
    { 25, entr24 },
    { 0, NULL }
};

// SPECIAL ACTION ON EXIT FROM
// A ROOM TABLE.

struct room_action exittb[] = {
    { 3, exit03 },
    { 4, exit03 },
    { 6, exit06 },
    { 7, exit06 },
    { 11, exit03 },
    { 12, exit03 },
    { 13, exit03 },
    { 14, exit03 },
    { 19, exit19 },
    { 20, exboat },
    { 21, exboat },
    { 22, exit22 },
    { 24, exit24 },
    { 25, exit24 },
    { 0, NULL }
};

// SPECIAL ACTION FOR COMMANDS
// GIVEN WHILE IN A ROOM TABLE

struct room_action inrmtb[] = {
    { 1, inrm01 },
    { 6, inrm06 },
    { 7, inrm06 },
    { 24, inrm24 },
    { 25, inrm24 },
    { 0, NULL }
};

// MESSAGE TABLE FOR GENERAL
// LOOK AT OBJECT ROUTINE
//
// FMT:         DB    OBJ#
//          MSG# IF CARRYING
//          MSG# IF IN ROOM

struct object_msg objmsg[] = {
    { 16, 43, 43 },       // MOUSETRAP
    { 18, 41, 10 },       // MESSAGE
    { 11, 40, 10 },       // SPECS
    { 118, 49, 49 },      // PANEL
    { 117, 49, 49 },      // SPEAKER
    { 17, 46, 46 },       // BOOTS
    { 21, 77, 77 },       // DEFLATED BOAT
    { 93, 0, 75 },        // INFLATED BOAT
    { 104, 93, 93 },      // TOMBSTONE
    { 103, 94, 94 },      // IDOL
    { 29, 95, 95 },       // POTTERY
    { 28, 100, 100 },     // CROWN
    { 0 }
};

// DEFINE OBJECTS THAT SHOULD
// BE REFERRED TO AS "THEM"

struct them_table themtb[] = {
    { 11, 1 },           // SPECS
    { 17, 1 },           // BOOTS
    { 19, 1 },           // PADDLES
    { 23, 1 },           // KEYS
    { 26, 1 },           // MICE
    { 127, 1 },          // STAIRS
    { 102, 1 },          // NATIVES
    { 0 }
};


char *pronoun[] = {
    "it.",
    "them.",
    "her.",
    "him.",
};

//ROOM 1

struct room_map rmtbdf[] = {
    { 0, 0, 0, 0, 0, 0 },
//ROOM 2
    { 0, 0, 0, 0, 0, 1 },
//ROOM 3
    { 0, 0, 0, 0, 1, 0 },
//ROOM 4
    { 3, 5, 0, 0, 0, 0 },
//ROOM 5
    { 0, 0, 0, 0, 0, 0 },
//ROOM 6
    { 0, 0, 0, 0, 0, 0 },
//ROOM 7
    { 0, 0, 0, 0, 0, 0 },
//ROOM 8
    { 0, 0, 0, 9, 0, 0 },
//ROOM 9
    { 0, 0, 8, 0, 0, 0 },
//ROOM 10
    { 9, 0, 0, 0, 0, 0 },
//ROOM 11
    { 0, 12, 12, 12, 0, 0 },
//ROOM 12
    { 11, 12, 13, 12, 0, 0 },
//ROOM 13
    { 13, 14, 13, 12, 0, 0 },
//ROOM 14
    { 13, 0, 0, 0, 0, 0 },
//ROOM 15
    { 0, 0, 0, 0, 16, 8 },
//ROOM 16
    { 15, 0, 0, 0, 0, 0 },
//ROOM 17
    { 0, 0, 0, 16, 0, 0 },
//ROOM 18
    { 0, 0, 0, 0, 16, 0 },
//ROOM 19
    { 0, 0, 18, 0, 0, 0 },
//ROOM 20
    { 0, 0, 0, 0, 0, 0 },
//ROOM 21
    { 0, 0, 0, 0, 0, 0 },
//ROOM 22
    { 0, 0, 0, 0, 0, 0 },
//ROOM 23
    { 0, 0, 22, 0, 0, 0 },
//ROOM 24
    { 0, 0, 0, 0, 0, 0 },
//ROOM 25
    { 0, 0, 0, 0, 0, 0 },
//ROOM 26
    { 0, 0, 0, 0, 0, 0 },
    { -1 }
};

//ROOM 1

int rmobdf[] = {
    126, 32, 121, 120+INV, 18+INV,
    127, 27+INV, 119+INV, 0,
//ROOM 2
    8, 30, 13, 127, 0,
//ROOM 3
    14, 15, 16+INV, 124, 0,
//ROOM 4
    125, 0,
//ROOM 5
    122, 116, 17, 0,
//ROOM 6
    118, 117, 100, 0,
//ROOM 7
    118, 117, 99, 0,
//ROOM 8
    122, 0,
//ROOM 9
    115, 0,
//ROOM 10
    114, 0,
//ROOM 11
    113, 0,
//ROOM 12
    0,
//ROOM 13
    0,
//ROOM 14
    112, 19, 0,
//ROOM 15
    0,
//ROOM 16
    111, 0,
//ROOM 17
    20, 21, 26, 0,
//ROOM 18
    109, 108, 101, 0,
//ROOM 19
    110, 23, 24, 0,
//ROOM 20
    101, 106, 0,
//ROOM 21
    101, 105, 0,
//ROOM 22
    98, 102, 101, 93, 0,
//ROOM 23
    104, 103, 29+INV, 28+INV, 0,
//ROOM 24
    101, 0,
//ROOM 25
    101, 0,
//ROOM 26
    0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0
};

// ROOM DIRECTION TABLE USED DURING GAME PLAY
// SOURCE IS RMTBDF

struct room_map *roomtb;

// ROOM OBJECT TABLE USED DURING GAME PLAY
// SOURCE IS RMOBDF

int rmtb_len = sizeof(rmtbdf);

// TREASURE POINT TABLE
// FORMAT:         DB    TREASURE,POINTS

struct point_table pnttab[] = {
    { 28, 1 },
    { 0 }
};

// GRAPHIC SCREEN INDICATOR
// TABLE (BY ROOM)
//ROOM 1

int scrind[] = {
    1, 11, 5, 6, 31, 1, 2, 4, 93, 0,
//ROOM 2
    2, 11, 13, 14, 12, 0,
//ROOM 3
    4, 30, 27, 28, 23, 24, 25, 0,
//ROOM 4
    4, 59, 60, 63, 99, 0,
//ROOM 5
    1, 11, 5, 6, 31, 41, 42, 32, 45, 0,
//ROOM 6
    2, 49, 47, 48, 50, 109, 110, 111, 112, 0,
//ROOM 7
    2, 49, 51, 52, 53, 113, 114, 115, 116, 0,
//ROOM 8
    1, 33, 67, 34, 36, 0,
//ROOM 9
    1, 36, 33, 55, 75, 73, 0,
//ROOM 10
    1, 33, 75, 74, 69, 70, 71, 72, 0,
//ROOM 11
    4, 59, 60, 63, 64, 65, 66, 61, 0,
//ROOM 12
    4, 59, 60, 63, 64, 65, 61, 62, 0,
//ROOM 13
    4, 59, 60, 63, 64, 65, 61, 62, 0,
//ROOM 14
    4, 64, 65, 63, 56, 57, 58, 0,
//ROOM 15
    1, 36, 34, 68, 0,
//ROOM 16
    1, 36, 33, 54, 55, 80, 79, 78, 77, 0,
//ROOM 17
    5, 33, 83, 0,
//ROOM 18
    1, 36, 81, 82, 84, 85, 86, 87, 0,
//ROOM 19
    6, 43, 91, 96, 0,
//ROOM 20
    1, 35, 36, 37, 117, 0,
//ROOM 21
    1, 35, 36, 37, 38, 39, 0,
//ROOM 22
    1, 36, 81, 82, 0,
//ROOM 23
    1, 33, 36, 67, 104, 107, 108, 0,
//ROOM 24
    1, 36, 35, 0,
//ROOM 25
    1, 36, 35, 0,
//ROOM 26
    1, 33, 36, 67, 107, 108, 0,
};


int equtab[] = {
    8, 9, 0,              // FLASHLIGHT
    10, 32, 0,            // ORIENTAL RUG
    21, 93, 0,            // RUBBER BOAT
    30, 31, 0,            // OLD WOODEN CHEST
    126, 94, 0,           // ROLLTOP DESK
    124, 123, 0,          // STORAGE CABINET
    115, 107, 0,          // PATH IN JUNGLE
};

// ANTIMATION ROUTINES BY ROOM
// FORMAT: ROOM #,RTN VECTOR

struct room_action anttab[] = {
    { 1, movclk },
    { 5, movlsr },
    { 6, movlit },
    { 7, movlit },
    { 8, movclo },
    { 9, movclo },
    { 14, movsnk },
    { 15, movclo },
    { 16, movclo },
    { 18, movclo },
    { 20, movclo },
    { 21, movclo },
    { 22, movclo },
    { 23, movclo },
    { 24, movclo },
    { 25, movclo },
    { 26, movclo },
    { 0, NULL }
};

// IF OBJECT DROPPED IN ROOM
// PUT IT IN ANOTHER ROOM TABLE
// FORMAT: CURR ROOM,NEW ROOM
// MOVABLE OBJ TABLE

int movobj[] = {
    28, 105, 0,           // JEWELLED CROWN
    23, 0,
    29, 106, 0,           // MAYAN POTTERY
    23, 0,
    110, 90, 0,           // TRADER JACK
    19, 0,
    125, 92, 0,           // SIGN
    19, 0,
    112, 94, 0,           // SNAKE
    14, 0,
    10, 118, 0,           // ROLLED UP RUG
    1, 5, 8, 9, 16, 17, 18,
    19, 0,
    16, 119, 0,           // MOUSETRAP
    3, 0,
    17, 95, 0,            // BOOTS
    5, 8, 16, 17, 18, 0,
    26, 100, 0,           // MICE
    17, 0,
    102, 101, 0,          // NATIVES
    22, 0,
    93, 102, 0,           // INFLATED BOAT
    18, 22, 0,
    19, 103, 0,           // PADDLES
    14, 0,
    20, 88, 0,            // SHOVEL
    17, 0,
    21, 89, 0,            // DEFLATED BOAT
    16, 17, 18, 22, 0,
    23, 97, 0,            // KEYS
    19, 0,
    24, 98, 0,            // MACHETE
    19, 0,
    107, 76, 0,           // CUT PATH IN JUNGLE
    9, 0,
    101, 37, 0,           // OCEAN
    24, 25, 0,
    122, 32, 0,           // DEVICE
    8, 0,
    32, 7, 0,             // RUG OVER TRAP DOOR
    1, 0,
    18, 10, 0,            // MESSAGE
    1, 0,
    120, 3, 0,            // TRAP DOOR
    1, 0,
    119, 8, 0,            // LADDER
    1, 0,
    8, 17, 0,             // UNLIT FLASHLIGHT
    2, 8, 16, 18, 0,
    9, 17, 0,             // LIT FLASHLIGHT
    2, 8, 16, 18, 0,
    30, 15, 0,            // CLOSED CHEST
    2, 0,
    31, 18, 0,            // OPEN CHEST
    2, 8, 18, 19, 0,
    13, 16, 0,            // JEWELRY
    2, 0,
    11, 19, 0,            // SPECS
    2, 3, 5, 8, 16, 17, 18,
    22, 0,
    12, 20, 0,            // MANUAL
    2, 3, 5, 8, 16, 17, 18,
    22, 0,
    14, 21, 0,            // TIRE PUMP
    3, 16, 18, 0,
    15, 22, 0,            // BUCKET
    3, 8, 16, 17, 18, 22, 0,
    123, 26, 0,           // CABINET
    3, 0,
    124, 29, 0,           // CABINET
    3, 0,
    94, 9, 0,            // DESK
    1, 0,
    0
};

// GRAPHIC SCREEN PNTR TABLE
// GRAPHIC OBJECT PNTR TABLE
// DIRECTION DESCRIPTIONS TABLE
// OBJECT DESCRIPTIONS TABLE
// ROOM DESCRIPTIONS TABLE
//ROOM 1
//ROOM 2
//ROOM 3
//ROOM 4
//ROOM 5
//ROOM 6
//ROOM 7
//ROOM 8
//ROOM 9
//ROOM 10
//ROOM 11
//ROOM 12
//ROOM 13
//ROOM 14
//ROOM 15
//ROOM 16
//ROOM 17
//ROOM 18
//ROOM 19
//ROOM 20
//ROOM 21
//ROOM 22
//ROOM 23
//ROOM 24
//ROOM 25
// COMPRESSED PHRASE TABLE
// VERB ROUTINE JUMP VECTORS
// ASSORTED TEXT MESSAGES

char *message[] = {
    [0] = "\n\nOK, ",
    [1] = "\n\nObvious directions: ",
    [2] = "\n\nI see \r: ",
    [3] = "\nI see no way to go in that direction.",
    [4] = "\nI don't understand \"",
    [5] = "\nI'm carrying the following:\n",
    [6] = "\nnothing.",
    [7] = "\nI don't see ",
    [8] = "\nI'm carrying ",
    [9] = "\nI can't carry anymore.",
    [10] = "\nI don't have ",
    [11] = "\nHey, I found something!",
    [12] = "\nI see nothing special.",
    [13] = "\nI'm on it!",
    [14] = "\nI'm in it!",
    [15] = "\nIt's beyond my power to do that.",
    [16] = "\nIt's closed.",
    [17] = "\nIt's locked.",
    [18] = "\nIt's open.",
    [19] = "\nIt's unlocked.",
    [20] = "\nWon't budge.",
    [21] = "\nDoesn't work.",
    [22] = "\nIt's empty.",
    [23] = "\nI can't do that ... yet!",
    [24] = "\n00000 of 1 treasure scored\n00000 moves used.",
    [25] = "\n\nThis Adventure is over.\n00000 of 1 treasure scored\n00000 moves were used.\n\nPlay again (Y/N)? ",
    [26] = "\nDon't be ridiculous.",
    [27] = "\nCongratulations, you did it.\n",
    [28] = "\nSorry, I can't do that - ",
    [29] = "\nMaybe I should open it.",
    [30] = "\nHey, there's a message here!",
    [31] = "\nIt looks interesting alright!",
    [32] = "\nI have no way to do that.",
    [33] = "\nThere's a trap door under it!",
    [34] = "\nIt's too big and heavy.",
    [35] = "\nI found a pair of spectacles.",
    [36] = "\nThere's an instruction manual in here.",
    [37] = "\nThere's a mouse trap in it.",
    [38] = "\nIt's a concealed switch.",
    [39] = "\nI heard a strange sound.",
    [40] = "\nThey're wire framed reading glasses.",
    [41] = "\nThe message reads...\n- The Professor's notes should give some clues -",
    [42] = "\nMaybe I should read it!",
    [43] = "\nIt's just a regular mousetrap.",
    [44] = "\nIt's quite large. I see an instrument panel and a reclining seat.",
    [45] = "\nI don't see them here.",
    [46] = "\nThey're made of heavy leather with rubber cleats.",
    [47] = "\nIt says...\n-To light is good\n-To unlight is wise",
    [48] = "\nThe title is :\n- Teleporter Operating Manual\nThe introduction says :\n- To be used if problems arise",
    [49] = "\nI'm not sure I understand these complex things.",
    [50] = "\nThe jungle growth is very dense.",
    [51] = "\nThe flashlight is lit.",
    [52] = "\nIt's off!",
    [53] = "\nThe manual says...\n1. Activate the energizer\n2. Press the teleport button",
    [54] = "\nThe teleporter vibrates slightly and emits a low hum.",
    [55] = "\nNothing happens!",
    [56] = "\n\nA mechanical sounding voice from the speaker says...\n-Please read your manual before operating the teleporter-",
    [57] = "\n\nWelcome to the Calixto Island Adventure.",
    [58] = "\n\nTrader Jack says - Hi Bub! Got somethin' to trade?",
    [59] = "\nJack won't let me. He says:\n- That's stealin' not tradin' -",
    [60] = "\nJack says:\n- That's cheatin' Bub -",
    [61] = "\nJack says:\n- No deal Bub! -",
    [62] = "\nI'm needin' somethin' to cover my dirt floor.",
    [63] = "\nI'm needin' somethin' to store my junk in.",
    [64] = "\nJack says - It's a deal Bub! - Take what yer needin' -",
    [65] = "\nBoy, that was hard work.",
    [66] = "\nI have no trap.",
    [67] = "\nI have no key.",
    [68] = "\nThe print is too small.",
    [69] = "\nit's a It must be buried at the pagan idol on Calixto Island. If you find it, put it in my study.",
    [70] = "\nI don't hear anything now.",
    [71] = "\nI don't have them.",
    [72] = "\nI'm carrying them!",
    [73] = "\nNot while I'm carrying it.",
    [74] = "\nI have no pump.",
    [75] = "\nIt's full of air.",
    [76] = "\nIt's too big and bulky.",
    [77] = "\nIt needs air.",
    [78] = "\nIt's already deflated.",
    [79] = "\nThat's not very nice.",
    [80] = "\nNo way, I won't go near it!",
    [81] = "\nNot with that snake there!",
    [82] = "\nThe snake grabs a mouse and slithers away.",
    [83] = "\nI lost my footing and fell on the rocks below. I'm dead!",
    [84] = "\nIt's pitch black. I can't see anything!\n",
    [85] = "\nIt's lit.",
    [86] = "\nIt's off.",
    [87] = "\n\nLight runs out in 00 move(s).",
    [88] = "\nI think we need some water!",
    [89] = "\nPerhaps I should sit in the boat.",
    [90] = "\nI have no paddles.",
    [91] = "\n\nThe boat is leaking, maybe I should \"BAIL WATER\".",
    [92] = "\n\nThe boat sank and I have drown.",
    [93] = "\nThe epitaph says...\nProfessor Lagarto didn't make it.",
    [94] = "\nIt's just a common pagan idol.",
    [95] = "\nIt's brightly decorated.",
    [96] = "\nI have no shovel.",
    [97] = "\nThe natives grab the jewelry and wander happily away.",
    [98] = "\n\nThe natives won't let me.",
    [99] = "\nI see no one to give them to.",
    [100] = "\nIt's made of gold and precious rubies.",
    [101] = "\nIt says...\nClosed for the summer.",
    [102] = "\nIt's dangerous to move around in the dark!",
    [103] = "\nOoh! ouch!! ... I fell down and cracked my head. I'm dead!",
    [104] = "\nWheeeee...",
//
//        END FILE: ADVDATA2.ASM
//
};

