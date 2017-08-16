
#include "rndutils.h"


#include <stdlib.h>
#include "mathutils.h"



//Seeds the generator with n using srand
void seedRng(int n)
{
	srand(n);
}

//Returns a random number from 1 to 100
int rnd()
{
	return rand() % 100 + 1;
}

//Returns a random number from bot to top
int rndRange(int bot, int top)
{
	return rand() % dif(top+1, bot) + bot;
}

//Returns a random bool
bool rndB()
{
	return rand() % 2;
}

//Returns a random bool with c being the percent chance to return true
bool rndbChance(int c)
{
	c = clamp(0, 100, c);
	return rnd() % 101 <= c;
}