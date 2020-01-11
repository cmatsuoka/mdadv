#pragma once

#include "advdata1.h"

void dmsg012(void);
void dmsg026(void);

void entr03(struct advdata *);
void entr06(struct advdata *);
void entr15(struct advdata *);
void entr19(struct advdata *);
void entr23(struct advdata *);
void entr24(struct advdata *);

void exit03(struct advdata *);
void exit06(struct advdata *);
void exit19(struct advdata *);
void exit22(struct advdata *);
void exit24(struct advdata *);
void exboat(struct advdata *);

void inrm06(void);
void inrm01(void);
void inrm24(void);

void get01(void);
void get02(void);
void get03(void);
void get04(void);
void get05(void);
void get06(void);
void getsha(void);

void go01(void);
void go02(void);
void go03(void);
void go04(void);
void go05(void);
void go06(void);
void go07(void);
void go08(void);
void go09(void);
void go10(void);
void go11(void);
void go12(void);
void go13(void);
void go14(void);
void go15(void);
void go16(void);

void look01(struct advdata *);
void look02(struct advdata *);
void look03(struct advdata *);
void look04(struct advdata *);
void look05(struct advdata *);
void look06(struct advdata *);
void look07(struct advdata *);
void look08(struct advdata *);
void look09(struct advdata *);
void look10(struct advdata *);
void look11(struct advdata *);
void look14(struct advdata *);
void look15(struct advdata *);
void look16(struct advdata *);
void look17(struct advdata *);
void look18(struct advdata *);
void look19(struct advdata *);
void look20(struct advdata *);
void look21(struct advdata *);

void open01(void);
void open02(void);

void put01(void);
void put04(void);

void vdefl(void);
void vinve(void);
void vread(void);

void movclk(struct advdata *);
void movlsr(struct advdata *);
void movlit(struct advdata *);
void movclo(struct advdata *);
void movsnk(struct advdata *);
