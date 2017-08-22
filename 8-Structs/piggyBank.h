#pragma once


struct piggyBank
{
	int dol1;
	int dol2;
	int dol5;

	int pennies;
	int nickels;
	int dimes;
	int quarters;
};



float calcPiggybankNotes(piggyBank p);

float calcPiggybankCoins(piggyBank p);

float calcPiggybankTotal(piggyBank p);