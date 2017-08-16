
#include <iostream>

#include "func.h"
#include "coututils.h"
#include "dtgreet.h"
#include "rndutils.h"






int main()
{

	seedRng(4);

	brk();
	
	//Bools and chars are really specially evaluated ints?
	prnti(rndB());
	prnti(rndB());
	prnti(rndB());
	prnti(rndB());
	prnti(rndB());
	brk();

	prnti(rndbChance(100));
	prnti(rndbChance(100));
	prnti(rndbChance(100));
	prnti(rndbChance(100));
	prnti(rndbChance(100));
	prnti(rndbChance(0));
	prnti(rndbChance(0));
	prnti(rndbChance(0));
	prnti(rndbChance(0));
	prnti(rndbChance(0));

	brk();
	pause();

	return 0;
}