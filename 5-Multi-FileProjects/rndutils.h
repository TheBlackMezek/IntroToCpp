#pragma once



//Seeds the generator with n using srand
void seedRng(int n);

//Returns a random number from 1 to 100
int rnd();

//Returns a random number from bot to top, inclusive
int rndRange(int bot, int top);

//Returns a random bool
bool rndB();

//Returns a random bool with c being the percent chance to return true
bool rndbChance(int c);