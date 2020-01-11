#pragma once

void lookob(struct advdata *d);

void nosee1(struct advdata *d, int msg);
void nosee(struct advdata *d);
void nohave(struct advdata *d);
void reply(void);
void dspmsg(int num);

#define dmsg(x) dspmsg(x)
