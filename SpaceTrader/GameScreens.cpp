
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





	//Ship stats
	std::string tvstring = "%s";
	ElementData elmdat = makeElementData(10, 10, shipName.size() + 2, 3, 0x000F);
	VarText vartxt = makeVarText(tvstring, 2, &shipName);
	makeTextImageWithVars(true, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	int idx = shipScreen.addElement(elmdat);
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


	//Screen buttons
	ElementData elmdat = makeElementData(1, 1, 6, 3, 0x000F);
	ButtonData butDat = makeButtonData(true, 0x000B, 0x0009, "Help", &switchScreenToHelp);
	makeButtonImage(&elmdat, &butDat);
	int idx = shopScreen.addElement(elmdat);
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
	lclick = false;
}

void switchScreenToShip()
{
	screen = &shipScreen;
	lclick = false;
}

void switchScreenToShop()
{
	screen = &shopScreen;
	lclick = false;
}

void switchScreenToStar()
{
	screen = &starScreen;
	lclick = false;
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