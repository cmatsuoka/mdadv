#pragma once

#include "advsys.h"
#include "advdata1.h"

int havobj(struct advdata *d, int obj_num);
int ckobj(struct advdata *d, int obj_num);
int makvis(struct advdata *d, int obj_num);
int *pntrm1(struct advdata *d);
int locobj(struct advdata *d, int obj_num);
void ckdraw(struct advdata *d);

extern int scrind[];
extern int *rmobt1;
extern struct them_table themtb[];
extern char *message[];
extern char *pronoun[];
