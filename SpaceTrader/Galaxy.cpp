
#include "Galaxy.h"


obj gal[galSize];

int fuelCost = 2;



void initGalaxy()
{
	//Second number is dist to parent, don't modify others
	//Second string is parent name

	//Template
	/*
	gal[0] = { "Name", "", 0, 0, 0,
	{ "RETNAME", 5000, "RETDESC\n" },
		"NAME:\n"
		"Desc\n",
		{ { "item", 1, 10 },{},{} },
		{ { "item", 1, 20 },{},{} } };
	*/


	gal[0] = { "Mercury", "", 0, 10, 0,
	{ "RETNAME", 5000, "RETDESC\n" },
		"MERCURY:\nA slow-turning gray ball orbiting very close to Sol.\n"
		"Mercury isn't pretty, but it has access to enormous amounts of solar power.\n"
		"Mobile manufactories slowly move to stay in the night side.\n",
		{ { "machines", 1, 27 },{ "tech", 1, 25 },{ "food", 1, 13 },{ "water", 1, 18 },{ "metal", 1, 20 },
		 {}, {}, {}, {}, {} }
	};



	gal[1] = { "Venus", "", 0, 20, 0,
	{ "RETNAME", 5000, "RETDESC\n" },
		"VENUS:\n"
		"Beneath its tan-yellow clouds, Venus is very hot and always dark.\n"
		"Venusians refer to the surface as 'The Underworld'.\n"
		"It has several tourist hotel stations and science bases.\n"
		"Only unmanned craft descend to explore or gather atmosphere.\n",
		{ { "synthlife", 1, 115 }, {}, {}, { "food", 1, 12 },{ "water", 1, 15 },
		 {}, {}, {}, {}, {} }
	};



	gal[2] = { "Earth", "", 0, 40, 0,
		{ "Paradise Falls", 5000, "A beautiful house in a forest overlooking a waterfall.\n", "You have retired.\n" },
		"EARTH:\n"
		"The beautiful and fertile homeworld of humanity.\n"
		"Earth is the most populous, wealthy, and powerful object around Sol.\n"
		"It remains divided into several alliances of sovereign nations.\n"
		"Earthers are fascinated by the exotic products from 'outer space'.\n",
		{ { "water", 1, 10 }, { "synthlife", 1, 105 }, {}, {}, {},
		{}, {}, {}, {}, {} }
	};

	gal[3] = { "Luna", "Earth", 0, 5, 0,
		{ "Stardome House", 5000, "A retirement home with a fantastic sky dome.\n", "You have retired.\n" },
		"LUNA:\n"
		"Known by Earthers as 'The Moon'.\n"
		"Luna produces little of its own, but has many specialized facilities.\n"
		"Low-g, no atmosphere, and proximity to Earth bring tourists and scientists.\n"
		"It is known as one of the few producers of synthlife.\n",
		{ { "synthlife", 1, 100 },{ "food", 1, 12 },{ "water", 1, 11 },{ "tech", 1, 35 }, {},
		{}, {}, {}, {}, {} }
	};



	gal[4] = { "Mars", "", 0, 80, 0,
		{ "Mariner's Rest", 5000, "A nice colonial-style house overlooking the Valles Marineris.\n", "You have retired.\n" },
		"MARS:\n"
		"The first planet colonized by humankind.\n"
		"Mars is known for its orange color, prosperity, and natural wonders.\n"
		"Mars is by far the most populous planet after Earth.\n"
		"It serves as a gateway between the inner and outer solar system.\n",
		{ { "food", 1, 8 }, { "water", 1, 10 },{ "synthlife", 1, 110 },{ "machines", 1, 30 },{},
		{}, {}, {}, {}, {} }
	};



	gal[5] = { "Ceres", "", 0, 160, 0,
		{ "None", 0, "Why would you retire here?\n", "" },
		"CERES:\n"
		"The largest dwarf planet in the asteroid belt.\n"
		"Ceres is the main hub for miners in the A-belt.\n"
		"It houses administration, refineries, factories, shipyards, and ports.\n"
		"It's not an attractive place and receives few tourists.\n",
		{ { "machines", 1, 25 }, { "metals", 1, 10 }, { "food", 1, 13 },{ "water", 1, 12 },{ "tech", 1, 30 },
		{}, {}, {}, {}, {} }
	};




	for (int i = 0; i < galSize; ++i)
	{
		if (gal[i].parent == "")
		{
			gal[i].ploc = -1;
		}
		else
		{
			for (int q = 0; q < galSize; ++q)
			{
				if (gal[q].name == gal[i].parent)
				{
					gal[i].ploc = q;
					++gal[q].sats;
					break;
				}
			}
		}
	}
}

float getFuelCost(int strt, int dest)
{
	//If orbiting the same object, just get distance from each other
	if (gal[strt].ploc == gal[dest].ploc)
	{
		return diff(gal[strt].dist, gal[dest].dist);
	}
	//If destination is parent of current object, get distance to parent
	else if (gal[strt].ploc == dest)
	{
		return gal[strt].dist;
	}
	//If destination is satellite of current object, get distance to parent
	else if (gal[dest].ploc == strt)
	{
		return gal[dest].dist;
	}
	//If not siblings or parent/child, find lowest common ancestor
	else
	{
		//Find distance from each location to top
		int sToTop = 0;
		int dToTop = 0;

		int loopLoc = strt;
		while (gal[loopLoc].ploc != -1)
		{
			++sToTop;
			loopLoc = gal[loopLoc].ploc;
		}
		loopLoc = dest;
		while (gal[loopLoc].ploc != -1)
		{
			++dToTop;
			loopLoc = gal[loopLoc].ploc;
		}

		//Sum up distance
		float totalDist = 0;
		while (sToTop >= 0 && dToTop >= 0)
		{
			if (sToTop > dToTop)
			{
				totalDist += gal[strt].dist;
				strt = gal[strt].ploc;
				--sToTop;
			}
			else if (dToTop > sToTop)
			{
				totalDist += gal[dest].dist;
				dest = gal[dest].ploc;
				--dToTop;
			}
			else
			{
				totalDist += gal[strt].dist;
				strt = gal[strt].ploc;
				--sToTop;
				totalDist += gal[dest].dist;
				dest = gal[dest].ploc;
				--dToTop;
			}

			if (gal[strt].ploc == gal[dest].ploc)
			{
				totalDist += diff(gal[strt].dist, gal[dest].dist);
				break;
			}
			else if (gal[strt].ploc == dest)
			{
				totalDist += gal[strt].dist;
				break;
			}
			else if (gal[dest].ploc == strt)
			{
				totalDist += gal[dest].dist;
				break;
			}
		}
		return totalDist;
	}
}

float diff(float a, float b)
{
	return (a > b) ? a - b : b - a;
}
