#pragma once

#include "structs.h"



const int galSize = 6;
extern obj gal[galSize];


extern int fuelCost;

void initGalaxy();
float getFuelCost(int strt, int dest);
float diff(float a, float b);


/*

GOODS LIST:
food avg 10
water avg 10
//ice
metal avg 15
synthlife avg 100
machines avg 30
tech avg 30


*/