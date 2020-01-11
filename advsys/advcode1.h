#pragma once

#include "advdata1.h"

void lookob(struct advdata *d);

void nosee1(struct advdata *d, int msg);
void nosee(struct advdata *d);
void nohave(struct advdata *d);
void badinp(struct advdata *d);
void reply(void);
void reply1(void);
void dead1(struct advdata *d, int msg);
void dspmsg(int num);

void dmsg012(struct advdata *);
void dmsg026(struct advdata *);

#define dmsg(x) dspmsg(x)
