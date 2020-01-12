#pragma once

#include <stdio.h>
#include <stdint.h>

#define MAXWRD   4                // VERB/NOUN COMPARE LENGTH
#define MVOBMX   2                // MAX # OF MOVABLE OVERLAYS PER OBJECT
#define RMSIZE   6                // SIZE OF A ROOM TABLE ENTRY
#define INV      0x80             // OBJECT INVISABLE ATTRIBUTE
#define SPC      0x80             // SPACE AFTER CHARACTER ATTRIBUTE
//#define MAXLINE  (40-1)           // MAX CHARACTERS ON A DISPLAY LINE
#define R_PNTS   1                // SET TO 1 TO ENABLE TREASURE POINTS
#define ADVMARK  0xA5             // MARKER USED FOR SAVE FILES
#define QUOTE    0x27             // SINGLE QUOTE HEX CODE

#define STUB() printf("not implemented: %s\n", __FUNCTION__);

struct verb_noun {
    char *name;
    int num;
};

struct special_action {
    int verb_noun_num;
    void (*action)();
};

struct room_action {
    int room_num;
    void (*action)();
};

struct object_msg {
    int obj_num;
    int msg_carrying;
    int msg_in_room;
};

struct them_table {
    int obj_num;
    int pronoun;
};

struct room_map {
    int north;
    int south;
    int east;
    int west;
    int up;
    int down;
};

struct point_table {
    int obj_num;
    int val;
};


void cls(void);
void cls_clr(int);
void clstxt(void);
void disply(char *msg);
void chrout(int ch);
void dispovl(int, int, uint8_t *);
void shoscr(int, int, uint8_t *);

