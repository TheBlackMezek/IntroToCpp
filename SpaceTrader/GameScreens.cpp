
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



void initScreens()
{
	initHelpScreen();
	initShipScreen();
	initShopScreen();
	initStarScreen();
}



void initHelpScreen()
{
	helpScreen = Screen();
	helpScreen.setSize(WIN_WIDTH, WIN_HEIGHT);

	std::string termStr = "TERMINOLOGY:\n\n"
		"object - Anything in space, be it planet, moon, star, or ship.\n"
		"satellite - Anything in orbit of something else.\n"
		"    Moons are satellites of planets.";
	ElementData elmdat = makeElementData(10, 10, WIN_WIDTH - 20, 10, 0x000F);
	makeTextImageMultiLine(false, termStr.c_str(), termStr.size(), &elmdat);
	helpScreen.addElement(elmdat);
	


	//Screen buttons
	elmdat = makeElementData(1, 1, 6, 3, 0x000F);
	ButtonData butDat = makeButtonData(true, 0x000B, 0x0009, "Ship", &switchScreenToShip);
	makeButtonImage(&elmdat, &butDat);
	int idx = helpScreen.addElement(elmdat);
	helpScreen.addButton(idx, butDat);

	elmdat = makeElementData(8, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Shop", &switchScreenToShop);
	makeButtonImage(&elmdat, &butDat);
	idx = helpScreen.addElement(elmdat);
	helpScreen.addButton(idx, butDat);

	elmdat = makeElementData(15, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Star", &switchScreenToStar);
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



	/*bay[0] = { "Goods", 3, 0 };
	bay[1] = { "Stuff", 9183, 0 };
	bay[2] = { "Stuff", 9183, 0 };
	bay[3] = { "Stuff", 9183, 0 };
	bay[4] = { "Stuff", 9183, 0 };
	bay[5] = { "Stuff", 9183, 0 };
	bay[6] = { "Stuff", 9183, 0 };
	bay[7] = { "Stuff", 9183, 0 };
	bay[8] = { "Stuff", 9183, 0 };
	bay[9] = { "Stuff", 9183, 0 };*/



	//Screen buttons
	elmdat = makeElementData(1, 1, 6, 3, 0x000F);
	ButtonData butDat = makeButtonData(true, 0x000B, 0x0009, "Help", &switchScreenToHelp);
	makeButtonImage(&elmdat, &butDat);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addButton(idx, butDat);

	elmdat = makeElementData(8, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Shop", &switchScreenToShop);
	makeButtonImage(&elmdat, &butDat);
	idx = shipScreen.addElement(elmdat);
	shipScreen.addButton(idx, butDat);

	elmdat = makeElementData(15, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Star", &switchScreenToStar);
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




	//Market name
	elmdat = makeElementData(10, 8, WIN_WIDTH - 10, 1, 0x000E);
	elmdat.imgRenderer = &makeShopNameImg;
	shopScreen.addElement(elmdat);

	int shopElmY = 10;
	int shopElmYInc = 4;
	for (int i = 0; i <= goodsSize; ++i)
	{

		elmdat = makeElementData(20, shopElmY, gal[loc].goods[i].type.size() + 3, 3, 0x000F);
		//elmdat.imgRenderer = &makeShopNameImg;
		makeTextImage(false, gal[loc].goods[i].type.c_str(), gal[loc].goods[i].type.size(), &elmdat);
		shopScreen.addElement(elmdat);


		elmdat = makeElementData(10, shopElmY, 4, 3, 0x000F);
		elmdat.data = std::to_string(i);
		butDat = makeButtonData(true, 0x000C, 0x0004, "-1", NULL);
		butDat.dataCallback = &sellGoods;
		makeButtonImage(&elmdat, &butDat);
		idx = shopScreen.addElement(elmdat);
		shopScreen.addButton(idx, butDat);


		elmdat = makeElementData(15, shopElmY, 4, 3, 0x000F);
		elmdat.data = std::to_string(i);
		butDat = makeButtonData(true, 0x000A, 0x0002, "+1", NULL);
		butDat.dataCallback = &buyGoods;
		makeButtonImage(&elmdat, &butDat);
		idx = shopScreen.addElement(elmdat);
		shopScreen.addButton(idx, butDat);


		shopElmY += shopElmYInc;
	}




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

	elmdat = makeElementData(15, 1, 6, 3, 0x000F);
	butDat = makeButtonData(true, 0x000B, 0x0009, "Star", &switchScreenToStar);
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);


	shopScreen.makeImage();
}

void initStarScreen()
{
	starScreen = Screen();
	starScreen.setSize(WIN_WIDTH, WIN_HEIGHT);


	//Screen buttons
	ElementData elmdat = makeElementData(1, 1, 6, 3, 0x000F);
	ButtonData butDat = makeButtonData(true, 0x000B, 0x0009, "Help", &switchScreenToHelp);
	makeButtonImage(&elmdat, &butDat);
	int idx = starScreen.addElement(elmdat);
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


	starScreen.makeImage();
}



void switchScreenToHelp()
{
	screen = &helpScreen;
}

void switchScreenToShip()
{
	screen = &shipScreen;
}

void switchScreenToShop()
{
	screen = &shopScreen;
	Element elm;

	for (int i = 0; i < screen->maxElms; ++i)
	{
		elm = screen->elements[i];
		if (screen->butDat[elm.buttonData].exists
			&& screen->elmDat[elm.elementData].data != "")
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



void buyGoods(ElementData* e)
{
	int idx = std::stoi(e->data);
	std::string item = gal[loc].goods[idx].type;

	int amt = 1;

	if (item == "fuel")
	{
		if (money >= fuelCost * amt)
		{
			if (fuel + amt <= maxFuel)
			{
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
	int idx = std::stoi(e->data);
	std::string item = gal[loc].goods[idx].type;
	int bayidx = -1;

	int amt = 1;

	if (item == "fuel")
	{
		if (amt <= fuel)
		{
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
				bay[b].qty -= amt;
				itemsInBay -= amt;
				money += gal[loc].goods[idx].val * amt;
				if (!bay[b].qty) { bay[b].type = ""; }
				break;
			}
		}
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
	std::string text = "CARGO BAY\n\n\n";


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


