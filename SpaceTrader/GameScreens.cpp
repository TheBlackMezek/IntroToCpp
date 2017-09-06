
#include "GameScreens.h"

#include <string>

#include "WindowSetup.h"
#include "DataMaker.h"
#include "ImageMaker.h"
#include "PlayerData.h"
#include "InputGetter.h"
#include "Galaxy.h"


Screen* screen;
Screen helpScreen;
Screen shipScreen;
Screen shopScreen;
Screen starScreen;
Screen loreScreen;
Screen endScreen;



void initScreens()
{
	initHelpScreen();
	initShipScreen();
	initShopScreen();
	initStarScreen();
	initLoreScreen();
	initEndScreen();

	for (int i = 0; i <= logSize; ++i)
	{
		if (i == logSize)
		{
			tlog[i] = '\0';
		}
		else
		{
			tlog[i] = ' ';
		}
	}
}



void initHelpScreen()
{
	helpScreen = Screen();
	helpScreen.setSize(WIN_WIDTH, WIN_HEIGHT);

	std::string termStr = 
		"HOW TO PLAY:\n\n"
		"Buy goods and fuel using the 'Shop' screen.\n"
		"Fly from one object to another using the 'Star' screen.\n"
		"Sell your goods somewhere else for a profit!\n"
		"When you're rich, look around for somewhere to retire, using the 'Ship' screen.\n"
		"Every retirement location will provide a different experience.\n\n"
		"If you run out of fuel and money, don't give up!\n"
		"The 'Lore' screen can help you figure out exports/imports.\n"
		"Nobody knows the best trade routes to begin with.\n"
		"Restart the game and try again!\n\n"
		"Press 'Esc' at any time to exit.\n"
		"\n\n\n"
		"TERMINOLOGY:\n\n"
		"object - Anything in space, be it planet, moon, star, or ship.\n"
		"satellite - Anything in orbit of something else.\n"
		"    Moons are satellites of planets.\n"
		"\n"
		"synthlife - Artificial plants and animals.\n"
		"    Some are pets, but most are for utility.\n"
		"    Most cannot reproduce and must be manufactured.\n";
	ElementData elmdat = makeElementData(10, 10, WIN_WIDTH - 20, WIN_HEIGHT - 20, 0x000F);
	makeTextImageMultiLine(false, termStr.c_str(), termStr.size(), &elmdat);
	helpScreen.addElement(elmdat);
	


	//Screen buttons
	elmdat = makeElementData(8, 1, 6, 3, 0x000F);
	ButtonData butDat = makeButtonData(true, 0x000B, 0x0009, "Ship", &switchScreenToShip);
	makeButtonImage(&elmdat, &butDat);
	int idx = helpScreen.addElement(elmdat);
	helpScreen.addButton(idx, butDat);

	elmdat = makeElementData(15, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Shop", &switchScreenToShop);
	makeButtonImage(&elmdat, &butDat);
	idx = helpScreen.addElement(elmdat);
	helpScreen.addButton(idx, butDat);

	elmdat = makeElementData(22, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Star", &switchScreenToStar);
	makeButtonImage(&elmdat, &butDat);
	idx = helpScreen.addElement(elmdat);
	helpScreen.addButton(idx, butDat);

	elmdat = makeElementData(29, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Lore", &switchScreenToLore);
	makeButtonImage(&elmdat, &butDat);
	idx = helpScreen.addElement(elmdat);
	helpScreen.addButton(idx, butDat);



	helpScreen.makeImage();
}

void initShipScreen()
{
	shipScreen = Screen();
	shipScreen.setSize(WIN_WIDTH, WIN_HEIGHT);


	std::string tvstring;
	ElementData elmdat;
	ButtonData butDat;
	VarText vartxt;
	int idx;



	//Image on top
	elmdat = makeElementData(50, 1, WIN_WIDTH - 52, 8, 0x000E);
	elmdat.imgRenderer = &makeShipScreenImg;
	shipScreen.addElement(elmdat);



	//Ship stats
	tvstring = "%s";
	elmdat = makeElementData(10, 10, shipName.size() + 2, 3, 0x000F);
	elmdat.bordered = true;
	vartxt = makeVarText(tvstring, 2, &shipName);
	makeTextImageWithVars(true, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addVarText(idx, vartxt);

	elmdat = makeElementData(10, 14, 50, 1, 0x000F);
	elmdat.imgRenderer = &makeCurrentOrbitImg;
	shipScreen.addElement(elmdat);

	tvstring = "Fuel: %f";
	elmdat = makeElementData(10, 17, 16, 1, 0x000F);
	vartxt = makeVarText(tvstring, 1, &fuel);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addVarText(idx, vartxt);

	tvstring = " / %f";
	elmdat = makeElementData(26, 17, 13, 3, 0x000F);
	vartxt = makeVarText(tvstring, 1, &maxFuel);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addVarText(idx, vartxt);

	tvstring = "Money: $%i";
	elmdat = makeElementData(10, 19, 50, 1, 0x000F);
	vartxt = makeVarText(tvstring, 0, &money);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addVarText(idx, vartxt);

	elmdat = makeElementData(10, 25, 50, WIN_HEIGHT - 30, 0x000F);
	elmdat.imgRenderer = &makeCargoImg;
	shipScreen.addElement(elmdat);



	//Retirement elements
	elmdat = makeElementData(45, 14, WIN_WIDTH - 46, WIN_HEIGHT - 20, 0x000F);
	elmdat.imgRenderer = &makeRetirementImg;
	shipScreen.addElement(elmdat);

	elmdat = makeElementData(70, 17, WIN_WIDTH - 46, 1, 0x000F);
	elmdat.imgRenderer = &makeRetireCostImg;
	elmdat.data = "retirehide";
	shipScreen.addElement(elmdat);

	elmdat = makeElementData(67, 13, 9, 3, 0x000F);
	elmdat.data = "retirehide";
	butDat = makeButtonData(true, 0x000B, 0x0009, "Retire", &clickRetire);
	makeButtonImage(&elmdat, &butDat);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addButton(idx, butDat);
	



	//Screen buttons
	elmdat = makeElementData(1, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Help", &switchScreenToHelp);
	makeButtonImage(&elmdat, &butDat);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addButton(idx, butDat);

	elmdat = makeElementData(15, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Shop", &switchScreenToShop);
	makeButtonImage(&elmdat, &butDat);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addButton(idx, butDat);

	elmdat = makeElementData(22, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Star", &switchScreenToStar);
	makeButtonImage(&elmdat, &butDat);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addButton(idx, butDat);

	elmdat = makeElementData(29, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Lore", &switchScreenToLore);
	makeButtonImage(&elmdat, &butDat);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addButton(idx, butDat);



	shipScreen.makeImage();
}

void initShopScreen()
{
	shopScreen = Screen();
	shopScreen.setSize(WIN_WIDTH, WIN_HEIGHT);


	std::string tvstring;
	ElementData elmdat;
	ButtonData butDat;
	VarText vartxt;
	int idx;


	//Decoration
	elmdat = makeElementData(50, 1, 50, 10, 0x000E);
	elmdat.imgRenderer = &makeShopPlanetImg;
	shopScreen.addElement(elmdat);

	//Market name
	elmdat = makeElementData(8, 8, WIN_WIDTH - 10, 1, 0x000E);
	elmdat.imgRenderer = &makeShopNameImg;
	shopScreen.addElement(elmdat);

	//Money, Fuel & Cargo displays
	tvstring = "Money: $%i";
	elmdat = makeElementData(55, 10, 30, 1, 0x000E);
	vartxt = makeVarText(tvstring, 0, &money);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addVarText(idx, vartxt);

	tvstring = "Fuel: %f";
	elmdat = makeElementData(55, 12, 16, 1, 0x000F);
	vartxt = makeVarText(tvstring, 1, &fuel);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addVarText(idx, vartxt);

	tvstring = " / %f";
	elmdat = makeElementData(71, 12, 13, 1, 0x000F);
	vartxt = makeVarText(tvstring, 1, &maxFuel);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addVarText(idx, vartxt);

	elmdat = makeElementData(55, 18, 45, WIN_HEIGHT - 20, 0x000F);
	elmdat.imgRenderer = &makeCargoImg;
	shopScreen.addElement(elmdat);

	//Fuel purchase display
	elmdat = makeElementData(55, 14, 4, 3, 0x000F);
	elmdat.data = "fuel";
	butDat = makeButtonData(true, 0x000C, 0x0004, "-1", NULL);
	butDat.dataCallback = &sellGoods;
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);

	elmdat = makeElementData(60, 14, 4, 3, 0x000F);
	elmdat.data = "fuel";
	butDat = makeButtonData(true, 0x000A, 0x0002, "+1", NULL);
	butDat.dataCallback = &buyGoods;
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);

	elmdat = makeElementData(65, 14, 4, 3, 0x000F);
	butDat = makeButtonData(true, 0x000A, 0x0002, "+5", NULL);
	butDat.dataCallback = &buyFiveFuel;
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);

	elmdat = makeElementData(70, 14, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000A, 0x0002, "+max", NULL);
	butDat.dataCallback = &fillFuel;
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);

	elmdat = makeElementData(77, 14, 30, 3, 0x000F);
	tvstring = "$1 / $2  fuel";
	makeTextImage(false, tvstring.c_str(), tvstring.size(), &elmdat);
	shopScreen.addElement(elmdat);



	//Market items & buy/sell buttons
	int shopElmY = 10;
	int shopElmYInc = 4;
	for (int i = 0; i <= goodsSize; ++i)
	{

		elmdat = makeElementData(32, shopElmY, 15, 3, 0x000F);
		elmdat.data = std::to_string(i);
		elmdat.imgRenderer = &makeShopItemImg;
		shopScreen.addElement(elmdat);

		elmdat = makeElementData(8, shopElmY, 6, 3, 0x000F);
		elmdat.data = std::to_string(i);
		butDat = makeButtonData(true, 0x000C, 0x0004, "-all", NULL);
		butDat.dataCallback = &sellAll;
		makeButtonImage(&elmdat, &butDat);
		idx = shopScreen.addElement(elmdat);
		shopScreen.addButton(idx, butDat);

		elmdat = makeElementData(15, shopElmY, 4, 3, 0x000F);
		elmdat.data = std::to_string(i);
		butDat = makeButtonData(true, 0x000C, 0x0004, "-1", NULL);
		butDat.dataCallback = &sellGoods;
		makeButtonImage(&elmdat, &butDat);
		idx = shopScreen.addElement(elmdat);
		shopScreen.addButton(idx, butDat);

		elmdat = makeElementData(20, shopElmY, 4, 3, 0x000F);
		elmdat.data = std::to_string(i);
		butDat = makeButtonData(true, 0x000A, 0x0002, "+1", NULL);
		butDat.dataCallback = &buyGoods;
		makeButtonImage(&elmdat, &butDat);
		idx = shopScreen.addElement(elmdat);
		shopScreen.addButton(idx, butDat);

		elmdat = makeElementData(25, shopElmY, 6, 3, 0x000F);
		elmdat.data = std::to_string(i);
		butDat = makeButtonData(true, 0x000A, 0x0002, "+max", NULL);
		butDat.dataCallback = &buyMax;
		makeButtonImage(&elmdat, &butDat);
		idx = shopScreen.addElement(elmdat);
		shopScreen.addButton(idx, butDat);


		shopElmY += shopElmYInc;
	}



	//   Log / Transaction history
	elmdat = makeElementData(10, 28, WIN_WIDTH - 10, WIN_HEIGHT - 30, 0x000E);
	elmdat.imgRenderer = &makeLogImg;
	shopScreen.addElement(elmdat);




	//Screen buttons
	elmdat = makeElementData(1, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Help", &switchScreenToHelp);
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);

	elmdat = makeElementData(8, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Ship", &switchScreenToShip);
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);

	elmdat = makeElementData(22, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Star", &switchScreenToStar);
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);

	elmdat = makeElementData(29, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Lore", &switchScreenToLore);
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);


	shopScreen.makeImage();
}

void initStarScreen()
{
	starScreen = Screen();
	starScreen.setSize(WIN_WIDTH, WIN_HEIGHT);


	std::string tvstring;
	ElementData elmdat;
	ButtonData butDat;
	VarText vartxt;
	int idx;




	tvstring = "Fuel: %f";
	elmdat = makeElementData(10, 7, 16, 1, 0x000E);
	vartxt = makeVarText(tvstring, 1, &fuel);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = starScreen.addElement(elmdat);
	starScreen.addVarText(idx, vartxt);

	elmdat = makeElementData(30, 7, 50, 1, 0x000E);
	elmdat.imgRenderer = &makeCurrentOrbitImg;
	starScreen.addElement(elmdat);

	//Decoration
	elmdat = makeElementData(59, 1, 50, 10, 0x000E);
	elmdat.imgRenderer = &makeStarSystemImg;
	starScreen.addElement(elmdat);



	int starScreenX = 10;
	int starScreenXInc = 5;
	int starScreenYBase = 10;
	int starScreenY = starScreenYBase;
	int starScreenYInc = 10;
	for (int i = 0; i < galSize; ++i)
	{
		if (gal[i].ploc == -1)
		{
			elmdat = makeElementData(starScreenX, 10, gal[i].name.size() + 2, 3, 0x000F);
			elmdat.data = std::to_string(i);
			butDat = makeButtonData(true, 0x000F, 0x0007, gal[i].name, NULL);
			butDat.dataCallback = &goToObj;
			makeButtonImage(&elmdat, &butDat);
			idx = starScreen.addElement(elmdat);
			starScreen.addButton(idx, butDat);

			elmdat = makeElementData(starScreenX, 15, 30, 3, 0x000F);
			elmdat.data = std::to_string(i);
			elmdat.imgRenderer = &makeFuelCostImg;
			starScreen.addElement(elmdat);

			if (gal[i].sats > 0)
			{
				for (int q = 0; q < galSize; ++q)
				{
					if (gal[q].ploc == i)
					{
						starScreenY += starScreenYInc;

						elmdat = makeElementData(starScreenX, starScreenY, gal[q].name.size() + 2, 3, 0x000F);
						elmdat.data = std::to_string(q);
						butDat = makeButtonData(true, 0x000F, 0x0007, gal[q].name, NULL);
						butDat.dataCallback = &goToObj;
						makeButtonImage(&elmdat, &butDat);
						idx = starScreen.addElement(elmdat);
						starScreen.addButton(idx, butDat);

						elmdat = makeElementData(starScreenX, starScreenY + 5, 30, 3, 0x000F);
						elmdat.data = std::to_string(q);
						elmdat.imgRenderer = &makeFuelCostImg;
						starScreen.addElement(elmdat);
					}
				}
				starScreenY = starScreenYBase;
			}


			starScreenX += starScreenXInc + gal[i].name.size();
		}
	}



	//Screen buttons
	elmdat = makeElementData(1, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Help", &switchScreenToHelp);
	makeButtonImage(&elmdat, &butDat);
	idx = starScreen.addElement(elmdat);
	starScreen.addButton(idx, butDat);

	elmdat = makeElementData(8, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Ship", &switchScreenToShip);
	makeButtonImage(&elmdat, &butDat);
	idx = starScreen.addElement(elmdat);
	starScreen.addButton(idx, butDat);

	elmdat = makeElementData(15, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Shop", &switchScreenToShop);
	makeButtonImage(&elmdat, &butDat);
	idx = starScreen.addElement(elmdat);
	starScreen.addButton(idx, butDat);

	elmdat = makeElementData(29, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Lore", &switchScreenToLore);
	makeButtonImage(&elmdat, &butDat);
	idx = starScreen.addElement(elmdat);
	starScreen.addButton(idx, butDat);


	starScreen.makeImage();
}

void initLoreScreen()
{
	loreScreen = Screen();
	loreScreen.setSize(WIN_WIDTH, WIN_HEIGHT);

	std::string termStr =
		"MERCURY: A plain ball of rock close to Sol, slowly rotating and intensely hot.\n"
		"    Factories on Mercury have access to enormous amounts of solar power.\n"
		"    That and low gravity let them produce special high-end tech.\n"
		"    It must import most supplies, and Mercurians have no room for luxuries.\n"
		"\n"
		"VENUS: A hellish planet shrouded in clouds, bright and beautiful from above.\n"
		"    Venus has several tourist and science stations in orbit.\n"
		"    Luxuries and basic supplies are major imports, as is special science tech.\n"
		"\n"
		"EARTH: The beautiful and fertile homeworld of humankind.\n"
		"    Earth produces most of what it needs, and imports next to nothing.\n"
		"    Earthers love the curiosities and luxuries from 'outer space'.\n"
		"    Traders mostly know Earth as the prime source of water in the inner planets.\n"
		"\n"
		"LUNA: The sole moon of Earth.\n"
		"    Luna has the biggest synthlife labs in the solar system.\n"
		"    The moon has few natural resources.\n"
		"    Supplies and manufactured goods must all be imported.\n"
		"\n"
		"MARS: Humankind's first and most populous colonized planet.\n"
		"    Mars is known as the great factory of the solar system.\n"
		"    Metals mined in the A-belt are shipped there and made into goods.\n"
		"    It also has reserves of water, and wealth enough for luxuries.\n"
		"\n"
		"CERES: A dwarf planet in the asteroid belt.\n"
		"    Ceres serves as the administrative hub and main port of the A-belt.\n"
		"    Hundreds of tons of metal flow through its docks every day.\n"
		"    It must import its goods, supplies and tech, and has no money for luxuries.\n"
		"\n"
		"\n";
	ElementData elmdat = makeElementData(10, 10, WIN_WIDTH - 20, WIN_HEIGHT - 20, 0x000F);
	makeTextImageMultiLine(false, termStr.c_str(), termStr.size(), &elmdat);
	loreScreen.addElement(elmdat);



	//Screen buttons
	elmdat = makeElementData(1, 1, 6, 3, 0x000F);
	ButtonData butDat = makeButtonData(true, 0x000B, 0x0009, "Help", &switchScreenToHelp);
	makeButtonImage(&elmdat, &butDat);
	int idx = loreScreen.addElement(elmdat);
	loreScreen.addButton(idx, butDat);

	elmdat = makeElementData(8, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Ship", &switchScreenToShip);
	makeButtonImage(&elmdat, &butDat);
	idx = loreScreen.addElement(elmdat);
	loreScreen.addButton(idx, butDat);

	elmdat = makeElementData(15, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Shop", &switchScreenToShop);
	makeButtonImage(&elmdat, &butDat);
	idx = loreScreen.addElement(elmdat);
	loreScreen.addButton(idx, butDat);

	elmdat = makeElementData(22, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Star", &switchScreenToStar);
	makeButtonImage(&elmdat, &butDat);
	idx = loreScreen.addElement(elmdat);
	loreScreen.addButton(idx, butDat);



	loreScreen.makeImage();
}

void initEndScreen()
{
	endScreen = Screen();
	endScreen.setSize(WIN_WIDTH, WIN_HEIGHT);

	std::string tvstring;
	ElementData elmdat;
	ButtonData butDat;
	VarText vartxt;
	int idx;


	elmdat = makeElementData(5, 5, WIN_WIDTH - 10, WIN_HEIGHT - 10, 0x000E);
	elmdat.imgRenderer = &makeEndImg;
	endScreen.addElement(elmdat);


	endScreen.makeImage();
}



void switchScreenToHelp()
{
	screen = &helpScreen;
}

void switchScreenToShip()
{
	screen = &shipScreen;

	for (int i = 0; i < screen->maxElms; ++i)
	{
		if (screen->elmDat[i].data == "retirehide" && gal[loc].retire.name == "")
		{
			screen->elmDat[i].visible = false;
		}
		else
		{
			screen->elmDat[i].visible = true;
		}
	}
}

void switchScreenToShop()
{
	screen = &shopScreen;
	Element elm;

	for (int i = 0; i < screen->maxElms; ++i)
	{
		elm = screen->elements[i];
		if (screen->butDat[elm.buttonData].exists &&
			(screen->elmDat[elm.elementData].data != "" &&
			 screen->elmDat[elm.elementData].data != "fuel"))
		{
			screen->elmDat[elm.elementData].visible =
				(gal[loc].goods[std::stoi(screen->elmDat[elm.elementData].data)].qty > 0);
		}
	}
}

void switchScreenToStar()
{
	screen = &starScreen;
}

void switchScreenToLore()
{
	screen = &loreScreen;
}

void switchScreenToEnd()
{
	screen = &endScreen;
}



void buyGoods(ElementData* e)
{
	int idx = -1;
	std::string item = "";

	if (e->data == "fuel")
	{
		item = "fuel";
	}
	else
	{
		idx = std::stoi(e->data);
		item = gal[loc].goods[idx].type;
	}

	int amt = 1;

	if (item == "fuel")
	{
		if (money >= fuelCost * amt)
		{
			if (fuel + amt <= maxFuel)
			{
				std::string line = "Bought ";
				line.append(std::to_string(amt));
				line.append(" fuel for $");
				line.append(std::to_string(fuelCost * amt));
				line.append("\n");
				addLineToLog(line.c_str(), line.size());

				money -= fuelCost * amt;
				fuel += amt;
			}
		}
	}
	else
	{
		if (amt <= baySize - itemsInBay)
		{
			if (gal[loc].goods[idx].qty > 0)
			{
				if (money >= gal[loc].goods[idx].val * amt)
				{
					std::string line = "Bought ";
					line.append(std::to_string(amt));
					line.append(" ");
					line.append(item);
					line.append(" for $");
					line.append(std::to_string(gal[loc].goods[idx].val * amt));
					line.append("\n");
					addLineToLog(line.c_str(), line.size());

					bool foundItemInBay = false;
					for (int b = 0; b < baySize; ++b)
					{
						if (bay[b].type == item)
						{
							foundItemInBay = true;
							money -= gal[loc].goods[idx].val * amt;
							bay[b].qty += amt;
							itemsInBay += amt;
							break;
						}
					}
					if (!foundItemInBay)
					{
						for (int b = 0; b < baySize; ++b)
						{
							if (bay[b].qty == 0)
							{
								money -= gal[loc].goods[idx].val * amt;
								bay[b].type = item;
								bay[b].qty += amt;
								itemsInBay += amt;
								break;
							}
						}
					}
				}
			}
		}
	}
}

void sellGoods(ElementData* e)
{
	int idx = -1;
	std::string item = "";

	if (e->data == "fuel")
	{
		item = "fuel";
	}
	else
	{
		idx = std::stoi(e->data);
		item = gal[loc].goods[idx].type;
	}

	int amt = 1;

	if (item == "fuel")
	{
		if (amt <= fuel)
		{
			std::string line = "Sold ";
			line.append(std::to_string(amt));
			line.append(" fuel for $");
			line.append(std::to_string(amt * (fuelCost / 2)));
			line.append("\n");
			addLineToLog(line.c_str(), line.size());

			money += amt * (fuelCost / 2);
			fuel -= amt;
		}
	}
	else
	{
		for (int b = 0; b < baySize; ++b)
		{
			if (bay[b].type == item && bay[b].qty >= amt)
			{
				std::string line = "Sold ";
				line.append(std::to_string(amt));
				line.append(" ");
				line.append(item);
				line.append(" for $");
				line.append(std::to_string(gal[loc].goods[idx].val * amt));
				line.append("\n");
				addLineToLog(line.c_str(), line.size());

				bay[b].qty -= amt;
				itemsInBay -= amt;
				money += gal[loc].goods[idx].val * amt;
				if (!bay[b].qty) { bay[b].type = ""; }
				break;
			}
		}
	}
}

void fillFuel(ElementData* e)
{
	int amt = maxFuel - fuel;

	if (amt * fuelCost > money)
	{
		amt = money / fuelCost;
	}

	if (amt > 0)
	{
		std::string line = "Bought ";
		line.append(std::to_string(amt));
		line.append(" fuel for $");
		line.append(std::to_string(amt * fuelCost));
		line.append("\n");
		addLineToLog(line.c_str(), line.size());
	}
	
	money -= fuelCost * amt;
	fuel += amt;
}

void buyFiveFuel(ElementData* e)
{
	int amt = 5;

	if (amt > maxFuel - fuel)
	{
		amt = maxFuel - fuel;
	}

	if (amt > 0 && amt * fuelCost <= money)
	{
		std::string line = "Bought ";
		line.append(std::to_string(amt));
		line.append(" fuel for $");
		line.append(std::to_string(amt * fuelCost));
		line.append("\n");
		addLineToLog(line.c_str(), line.size());

		money -= fuelCost * amt;
		fuel += amt;
	}
}

void buyMax(ElementData* e)
{
	int idx = -1;
	std::string item = "";

	idx = std::stoi(e->data);
	item = gal[loc].goods[idx].type;


	int amt = (baySize - itemsInBay);
	if (amt * gal[loc].goods[idx].val > money)
	{
		amt = money / gal[loc].goods[idx].val;
	}


	if (amt <= baySize - itemsInBay)
	{
		if (gal[loc].goods[idx].qty > 0)
		{
			if (money >= gal[loc].goods[idx].val * amt)
			{
				std::string line = "Bought ";
				line.append(std::to_string(amt));
				line.append(" ");
				line.append(item);
				line.append(" for $");
				line.append(std::to_string(gal[loc].goods[idx].val * amt));
				line.append("\n");
				addLineToLog(line.c_str(), line.size());

				bool foundItemInBay = false;
				for (int b = 0; b < baySize; ++b)
				{
					if (bay[b].type == item)
					{
						foundItemInBay = true;
						money -= gal[loc].goods[idx].val * amt;
						bay[b].qty += amt;
						itemsInBay += amt;
						break;
					}
				}
				if (!foundItemInBay)
				{
					for (int b = 0; b < baySize; ++b)
					{
						if (bay[b].qty == 0)
						{
							money -= gal[loc].goods[idx].val * amt;
							bay[b].type = item;
							bay[b].qty += amt;
							itemsInBay += amt;
							break;
						}
					}
				}
			}
		}
	}
}

void sellAll(ElementData* e)
{
	int idx = -1;
	std::string item = "";

	
	idx = std::stoi(e->data);
	item = gal[loc].goods[idx].type;

	
	
	for (int b = 0; b < baySize; ++b)
	{
		if (bay[b].type == item)
		{
			std::string line = "Sold ";
			line.append(std::to_string(bay[b].qty));
			line.append(" ");
			line.append(item);
			line.append(" for $");
			line.append(std::to_string(gal[loc].goods[idx].val * bay[b].qty));
			line.append("\n");
			addLineToLog(line.c_str(), line.size());

			money += gal[loc].goods[idx].val * bay[b].qty;
			itemsInBay -= bay[b].qty;
			bay[b].qty = 0;
			bay[b].type = "";
			break;
		}
	}
}

void goToObj(ElementData* e)
{
	int dest = std::stoi(e->data);
	float fuelCost = getFuelCost(loc, dest);

	if (fuel >= fuelCost)
	{
		fuel -= fuelCost;
		loc = dest;
	}
}

void clickRetire()
{
	if (money >= gal[loc].retire.cost)
	{
		money -= gal[loc].retire.cost; //Just in case you can unretire in future updates
		switchScreenToEnd();
	}
}




void addLineToLog(const char line[], int size)
{
	//Find end of text
	int logEnd = 0;
	for (int i = logSize - 1; i >= 0; --i)
	{
		if (tlog[i] != ' ')
		{
			logEnd = i;
			break;
		}
	}

	if (logEnd > 0)
	{
		//Clear space
		int idx = logEnd;
		while (size > logSize - logEnd + 1)
		{
			do
			{
				tlog[idx] = ' ';
				--idx;
			} while (tlog[idx] != '\n');
		}

		//Move text up
		for (int i = idx; i >= 0; --i)
		{
			tlog[i + size] = tlog[i];
			tlog[i] = ' ';
		}
	}

	//Add text
	for (int i = 0; i < size; ++i)
	{
		tlog[i] = line[i];
	}
}




void makeCurrentOrbitImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	std::string text = "Currently orbiting ";
	text.append(gal[loc].name.c_str());

	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (y == (e->sizeY - 1) / 2 && x <= text.size())
			{
				e->image[x + y * e->sizeX].chr = text[x];
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = e->textColor;
		}
	}
}

void makeCargoImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';
	std::string text = "CARGO BAY    ";
	text.append(std::to_string(itemsInBay));
	text.append(" / ");
	text.append(std::to_string(baySize));
	text.append("\n\n\n");


	for (int i = 0; i < baySize; ++i)
	{
		if (bay[i].qty > 0)
		{
			text.append(bay[i].type);
			text.append(": ");
			text.append(std::to_string(bay[i].qty));
			text.append("\n\n");
		}
	}


	int chridx = 0;
	int chrLine = 0;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < text.size() && y == chrLine)
			{
				e->image[x + y * e->sizeX].chr = text[chridx];
				++chridx;
				while (chridx < text.size() && text[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = e->textColor;
		}
	}
}

void makeShipScreenImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';
	std::string text = 
		"   *   * ===========\n"
		"             \\      \\\n"
		"  \\ +-------------------------\\\n"
		"   \\|                          \\\n"
		"   /|                          /\n"
		"  / +-------------------------/\n"
		"             /      /\n"
		"   *   * ===========";



	int chridx = 0;
	int chrLine = 0;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < text.size() && y == chrLine)
			{
				e->image[x + y * e->sizeX].chr = text[chridx];
				++chridx;
				while (chridx < text.size() && text[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = e->textColor;
		}
	}
}

void makeShopNameImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	std::string text = "Welcome to the ";
	text.append(gal[loc].name.c_str());
	text.append(" marketplace!");

	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (y == (e->sizeY - 1) / 2 && x <= text.size())
			{
				e->image[x + y * e->sizeX].chr = text[x];
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = e->textColor;
		}
	}
}

void makeShopItemImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	int idx = std::stoi(e->data);
	std::string item = gal[loc].goods[idx].type;

	std::string text = "";

	if (gal[loc].goods[idx].qty > 0)
	{
		text = "$";
		text.append(std::to_string(gal[loc].goods[idx].val));
		int spaces = 6 - text.size();
		for (int i = 0; i < spaces; ++i)
		{
			text.append(" ");
		}
		text.append(item);
	}

	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (y == (e->sizeY - 1) / 2 && x <= text.size())
			{
				e->image[x + y * e->sizeX].chr = text[x];
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = e->textColor;
		}
	}
}

void makeFuelCostImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	std::string text = "Fuel:\n";
	text.append(std::to_string((int)getFuelCost(loc, std::stoi(e->data))));

	int chridx = 0;
	int chrLine = 0;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < text.size() && y == chrLine)
			{
				e->image[x + y * e->sizeX].chr = text[chridx];
				++chridx;
				while (chridx < text.size() && text[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = e->textColor;
		}
	}
}

void makeRetirementImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	std::string text = "RETIREMENT OPTION:\n\n\n";

	if (gal[loc].retire.name == "")
	{
		text.append("None");
	}
	else
	{
		text.append(gal[loc].retire.name);
		text.append("\n\n\n");
		text.append(gal[loc].retire.desc);
	}


	int chridx = 0;
	int chrLine = 0;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < text.size() && y == chrLine)
			{
				e->image[x + y * e->sizeX].chr = text[chridx];
				++chridx;
				while (chridx < text.size() && text[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = e->textColor;
		}
	}
}

void makeRetireCostImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	std::string text = "$";
	text.append(std::to_string(gal[loc].retire.cost));

	int chridx = 0;
	int chrLine = 0;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < text.size() && y == chrLine)
			{
				e->image[x + y * e->sizeX].chr = text[chridx];
				++chridx;
				while (chridx < text.size() && text[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = e->textColor;
		}
	}
}

void makeEndImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	std::string text = gal[loc].retire.endText;

	int chridx = 0;
	int chrLine = 0;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < text.size() && y == chrLine)
			{
				e->image[x + y * e->sizeX].chr = text[chridx];
				++chridx;
				while (chridx < text.size() && text[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = gal[loc].retire.color;
		}
	}
}

void makeStarSystemImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	std::string text = 
		"%W         \\     \\       |             |  \n"
		"  %Y***%W     \\    %yo%W       |            %G.%W|  \n"
		" %Y*****%W    |    |       |             %Ro%G.%W \n"
		"%Y*******%W   %Go%W    |       |             |  \n"
		" %Y*****%W    |    |       %Bo%G.%W            |  \n"
		"  %Y***%W     /    |       |             |  \n"
		"         /     /       |             |  \n";


	int chridx = 0;
	int chrLine = 0;
	int color = 0x000F;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < text.size() && y == chrLine)
			{
				if (chridx < text.size() - 1 &&
					text[chridx] == '%')
				{
					if (text[chridx + 1] == 'W')
					{
						color = 0x000F;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'Y')
					{
						color = 0x000E;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'y')
					{
						color = 0x0006;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'G')
					{
						color = 0x0007;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'B')
					{
						color = 0x0009;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'R')
					{
						color = 0x000C;
						chridx += 2;
					}
				}


				e->image[x + y * e->sizeX].chr = text[chridx];
				++chridx;
				while (chridx < text.size() && text[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = color;
		}
	}
}

void makeShopPlanetImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';

	//Template
	std::string text =
		"                                        \n"
		"                                        \n"
		"                                        \n"
		"                                        \n"
		"                                        \n"
		"                                        \n"
		"                                        \n";

	//Mercury
	if (loc == 0)
	{
		text =
			"            %Y-- ********* --             \n"
			"               / ***** \\                \n"
			"              /    |    \\               \n"
			"                                        \n"
			"                                        \n"
			"                                        \n"
			"%g----------------------------------------\n";
	}
	//Venus
	else if (loc == 1)
	{
		text =
			"                  T                     \n"
			"      +--------+  |  +--------+         \n"
			"      |%B########%W|--0--|%B########%W|         \n"
			"      +--------+  |  +--------+         \n"
			"                  V                     \n"
			"                                        \n"
			"                                        \n";
	}
	//Earth
	else if (loc == 2)
	{
		text =
			"                 %G&&&&&                  \n"
			"              &&&&&&&&&&&               \n"
			"             &&&&&&&&&&&&&              \n"
			"              & %y---#---                 \n"
			"                   #                    \n"
			"                   #                    \n"
			"                   #                    \n";
	}
	//Luna
	else if (loc == 3)
	{
		text =
			"                  %B=%W==%B=                  \n"
			"                 %G=%B==%G===                \n"
			"                 %B====%G==                \n"
			"                  %W====          %W___  \n"
			"     %W_                          %W|%b#%W|  \n"
			"    %W/%b0%W\\                         %W|%b#%W|  \n"
			"%g----------------------------------------\n";
	}
	//Mars
	else if (loc == 4)
	{
		text =
			"      %Wo              %Y**            %Wo    \n"
			"                     %Y**       %g^         \n"
			"     %g______                  %g/|\\        \n"
			"    %g/=====|                   %g^         \n"
			"   %g/======|                   %W#         \n"
			"   %g|======|                %W# # ##       \n"
			"%R----------------------------------------\n";
	}
	//Ceres
	else if (loc == 5)
	{
		text =
			"     %W.                                %W. \n"
			"                 %g/==o=\\                 \n"
			"                %g/======\\    %W.          \n"
			"               %g|==0=====|             \n"
			"   %W.           %g|======o=|       %W.     \n"
			"                %g\\====o=/            %W. \n"
			"             %W.   %g\\====/                 \n";
	}



	int chridx = 0;
	int chrLine = 0;
	int color = 0x000F;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < text.size() && y == chrLine)
			{
				if (chridx < text.size() - 1 &&
					text[chridx] == '%')
				{
					if (text[chridx + 1] == 'W')
					{
						color = 0x000F;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'Y') //yellow
					{
						color = 0x000E;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'y') //brownish yellow
					{
						color = 0x0006;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'G') //green
					{
						color = 0x000A;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'g') //gray
					{
						color = 0x0007;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'b')
					{
						color = 0x000B;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'B')
					{
						color = 0x0009;
						chridx += 2;
					}
					else if (text[chridx + 1] == 'R')
					{
						color = 0x000C;
						chridx += 2;
					}
				}


				e->image[x + y * e->sizeX].chr = text[chridx];
				++chridx;
				while (chridx < text.size() && text[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = color;
		}
	}
}

void makeLogImg(ElementData* e)
{
	e->image = std::vector<CharData>();
	e->image.resize(e->sizeX * e->sizeY);
	char ap = ' ';



	int chridx = 0;
	int chrLine = 0;
	int color = 0x000F;
	for (int y = 0; y < e->sizeY; ++y)
	{
		for (int x = 0; x < e->sizeX; ++x)
		{
			//Text
			if (chridx < logSize && y == chrLine)
			{
				if (chridx < logSize - 1 &&
					tlog[chridx] == '%')
				{
					if (tlog[chridx + 1] == 'W')
					{
						color = 0x000F;
						chridx += 2;
					}
					else if (tlog[chridx + 1] == 'Y') //yellow
					{
						color = 0x000E;
						chridx += 2;
					}
					else if (tlog[chridx + 1] == 'y') //brownish yellow
					{
						color = 0x0006;
						chridx += 2;
					}
					else if (tlog[chridx + 1] == 'G') //green
					{
						color = 0x000A;
						chridx += 2;
					}
					else if (tlog[chridx + 1] == 'g') //gray
					{
						color = 0x0007;
						chridx += 2;
					}
					else if (tlog[chridx + 1] == 'b')
					{
						color = 0x000B;
						chridx += 2;
					}
					else if (tlog[chridx + 1] == 'B')
					{
						color = 0x0009;
						chridx += 2;
					}
					else if (tlog[chridx + 1] == 'R')
					{
						color = 0x000C;
						chridx += 2;
					}
				}


				e->image[x + y * e->sizeX].chr = tlog[chridx];
				++chridx;
				while (chridx < logSize && tlog[chridx] == '\n')
				{
					++chrLine;
					++chridx;
				}
			}

			//Empty space
			else
			{
				e->image[x + y * e->sizeX].chr = ' ';
			}

			e->image[x + y * e->sizeX].color = color;
		}
	}
}
