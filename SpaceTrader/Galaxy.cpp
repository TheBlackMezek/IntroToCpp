
#include "Galaxy.h"


obj gal[galSize];

void initGalaxy()
{
	//gal[galSize];

	gal[0] = { "Earth", "", 0, 20, 0,
		{ "Paradise Falls", 5000, "A beautiful house in a forest overlooking a waterfall.\n", "You have retired.\n" },
		"EARTH:\nA beautiful planet of many colors, but most strikingly blue.\nIt is the fertile homeworld of humanity.\n",
		{ { "food", 1, 10 },{},{} },
		{ { "synthlife", 1, 60 },{ "metals", 1, 10 },{ "machines", 1, 20 } } };

	gal[1] = { "Luna", "Earth", 0, 5, 0,
		{ "Stardome House", 5000, "A retirement home with a fantastic sky dome.\n", "You have retired.\n" },
		"LUNA:\nKnown by Earthlings as 'The Moon'.\nIt is a barren, gray orb.\nIt is known for its science facilities.\n",
		{ { "synthlife", 1, 50 },{},{} },
		{ { "food", 1, 15 },{ "metals", 1, 12 },{} } };

	gal[2] = { "Mars", "", 0, 40, 0,
		{ "Mariner's Rest", 5000, "A nice colonial-style house overlooking the Valles Marineris.\n", "You have retired.\n" },
		"MARS:\nA dusty orange planet, and the site of humankind's first offworld colonies.\nIt is known for its low-G manufacturing and breathtaking natural features.\n",
		{ { "food", 1, 15 },{ "machines", 1, 15 },{} },
		{ { "synthlife", 1, 80 },{},{} } };

	gal[3] = { "Ceres", "", 0, 70, 0,
		{ "None", 0, "Why would you retire here?\n", "" },
		"CERES:\nA dwarf planet in the asteroid belt.\nIt serves as the main refinery and manufacturing hub for A belt miners.\n",
		{ { "machines", 1, 10 },{ "metals", 1, 5 },{} },
		{ { "food", 1, 25 },{},{} } };




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