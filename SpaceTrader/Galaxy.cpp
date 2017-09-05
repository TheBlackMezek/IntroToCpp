
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
	{ "", 5000, 0x000F, "RETDESC\n" },
		"MERCURY:\nA slow-turning gray ball orbiting very close to Sol.\n"
		"Mercury isn't pretty, but it has access to enormous amounts of solar power.\n"
		"Mobile manufactories slowly move to stay in the night side.\n",
		{ { "tech", 1, 25 },{ "water", 1, 23 },{ "metal", 1, 100},{ "machines", 1, 110 },{},
		 {}, {}, {}, {}, {} }
	};



	gal[1] = { "Venus", "", 0, 20, 0,
	{ "", 5000, 0x000F, "RETDESC\n" },
		"VENUS:\n"
		"Beneath its tan-yellow clouds, Venus is very hot and always dark.\n"
		"Venusians refer to the surface as 'The Underworld'.\n"
		"It has several tourist hotel stations and science bases.\n"
		"Only unmanned craft descend to explore or gather atmosphere.\n",
		{ { "synthlife", 1, 600 }, { "tech", 1, 40 },{ "water", 1, 19 }, {}, {},
		 {}, {}, {}, {}, {} }
	};



	gal[2] = { "Earth", "", 0, 40, 0,
		{ "Paradise Falls", 1000, 0x000A, "A beautiful house in a forest next to a waterfall.\n",
		"The sun sets in brilliant pinks, yellows and blues.\n\n"
		"Birds sing and flutter from tree to tree, while the water rumbles down.\n\n"
		"Sitting on your wooden balcony, surrounded by the luxuries of the homeworld, you wonder\n"
		"    why did anyone ever leave this beautiful planet?\n\n\n\n\n"
		"Congratulations, you've won!\n"},
		"EARTH:\n"
		"The beautiful and fertile homeworld of humanity.\n"
		"Earth is the most populous, wealthy, and powerful object around Sol.\n"
		"It remains divided into several alliances of sovereign nations.\n"
		"Earthers are fascinated by the exotic products from 'outer space'.\n",
		{ { "water", 1, 10 }, { "synthlife", 1, 550 }, {}, {}, {},
		{}, {}, {}, {}, {} }
	};

	gal[3] = { "Luna", "Earth", 0, 5, 0,
		{ "Stardome House", 5000, 0x0007, "A retirement home with a fantastic sky dome.\n",
		"The crystal-clear plastic dome stands fifty meters from your house.\n\n"
		"The vast sky amazes you every time you rise up the stairs from the tunnel.\n\n"
		"Here in the Leibnitz crater, there are almost no crater walls to obstruct the view.\n\n"
		"When the sun is up, it turns the plain blinding white.\n\n"
		"But now the sky and ground are black.\n\n\n\n"
		"Your eyes adjust slowly, and the stars begin to shine.\n\n"
		"With no atmosphere or lights, you can see more stars than anyone on Earth.\n\n"
		"You are unable to describe the awe of the Milky Way.\n\n\n\n\n"
		"Congratulations, you've won!\n"},
		"LUNA:\n"
		"Known by Earthers as 'The Moon'.\n"
		"Luna produces little of its own, but has many specialized facilities.\n"
		"Low-g, no atmosphere, and proximity to Earth bring tourists and scientists.\n"
		"It is known as one of the few producers of synthlife.\n",
		{ { "synthlife", 1, 500 },{ "water", 1, 12 }, { "machines", 1, 80 }, { "tech", 1, 65 },{},
		{}, {}, {}, {}, {} }
	};



	gal[4] = { "Mars", "", 0, 80, 0,
		{ "Mariner's Rest", 3000, 0x000E, "A nice colonial-style house overlooking the Valles Marineris.\n",
		"Your house was built with the white pod architecture style of the early colonists.\n\n"
		"Of course, it is much safer and has modern luxiries.\n\n"
		"The vast canyons and plateaus of the Valles Marineris stretch out in your windows.\n\n"
		"In a few places, the orange landscape is discolored with engineered lichens.\n\n"
		"Over the years you see the lichens slowly spread, and tourism increase.\n\n"
		"It's like an orange canvas being painted with life.\n\n\n\n\n"
		"Congratulations, you've won!\n"},
		"MARS:\n"
		"The first planet colonized by humankind.\n"
		"Mars is known for its orange color, prosperity, and natural wonders.\n"
		"Mars is by far the most populous planet after Earth.\n"
		"It serves as a gateway between the inner and outer solar system.\n",
		{ { "water", 1, 11 },{ "machines", 1, 50 },{ "synthlife", 1, 600 },{ "metal", 1, 50 },{},
		{}, {}, {}, {}, {} }
	};



	gal[5] = { "Ceres", "", 0, 160, 0,
		{ "", 0, 0x000F, "Why would you retire here?\n", "" },
		"CERES:\n"
		"The largest dwarf planet in the asteroid belt.\n"
		"Ceres is the main hub for miners in the A-belt.\n"
		"It houses administration, refineries, factories, shipyards, and ports.\n"
		"It's not an attractive place and receives few tourists.\n",
		{ { "water", 1, 30 },{ "tech", 1, 80 },{ "metal", 1, 20 },{ "machines", 1, 60 },{},
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
