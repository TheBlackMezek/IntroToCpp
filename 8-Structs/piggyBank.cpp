
#include "piggyBank.h"



float calcPiggybankNotes(piggyBank p)
{
	return p.dol1 + p.dol2 * 2 + p.dol5 * 5;
}


float calcPiggybankCoins(piggyBank p)
{
	return (p.pennies + p.nickels * 5 + p.dimes * 10 + p.quarters * 25) / 100.0f;
}


float calcPiggybankTotal(piggyBank p)
{
	return calcPiggybankCoins(p) + calcPiggybankNotes(p);
}