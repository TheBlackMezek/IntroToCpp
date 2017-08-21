
#include "mathutils.h"

#include <iostream>



int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		// If b is smaller, return b. If equal, doesn't matter which is returned.
		return b;
	}
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		// If b is greater, return b. If equal, doesn't matter which is returned.
		return b;
	}
}

int clamp(int bot, int top, int val)
{
	val = (val < bot) ? bot : val;
	val = (val > top) ? top : val;
	return val;
}

float dist(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(((float)x2 - (float)x1), 2) + pow(((float)y2 - (float)y1), 2));
}

//Returns the difference between two ints
int dif(int n1, int n2)
{
	if (n1 > n2)
	{
		return n1 - n2;
	}
	else
	{
		return n2 - n1;
	}
}