
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
Screen endScreen;



void initScreens()
{
	initHelpScreen();
	initShipScreen();
	initShopScreen();
	initStarScreen();
	initEndScreen();
}



void initHelpScreen()
{
	helpScreen = Screen();
	helpScreen.setSize(WIN_WIDTH, WIN_HEIGHT);

	std::string termStr = "TERMINOLOGY:\n\n"
		"object - Anything in space, be it planet, moon, star, or ship.\n"
		"satellite - Anything in orbit of something else.\n"
		"    Moons are satellites of planets.\n"
		"\n"
		"synthlife - Artificial plants and animals.\n"
		"    Some are for pleasure, but most are for utility.\n"
		"    Most cannot reproduce and must be manufactured.\n";
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

	//Money, Fuel & Cargo displays
	tvstring = "Money: $%i";
	elmdat = makeElementData(51, 10, 30, 1, 0x000E);
	vartxt = makeVarText(tvstring, 0, &money);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addVarText(idx, vartxt);

	tvstring = "Fuel: %f";
	elmdat = makeElementData(51, 12, 16, 1, 0x000F);
	vartxt = makeVarText(tvstring, 1, &fuel);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addVarText(idx, vartxt);

	tvstring = " / %f";
	elmdat = makeElementData(67, 12, 13, 1, 0x000F);
	vartxt = makeVarText(tvstring, 1, &maxFuel);
	makeTextImageWithVars(false, tvstring.c_str(), tvstring.size(), &elmdat, &vartxt);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addVarText(idx, vartxt);

	elmdat = makeElementData(51, 18, 45, WIN_HEIGHT - 20, 0x000F);
	elmdat.imgRenderer = &makeCargoImg;
	shopScreen.addElement(elmdat);

	//Fuel purchase display
	elmdat = makeElementData(60, 14, 30, 3, 0x000F);
	tvstring = "$1 / $2  fuel";
	makeTextImage(false, tvstring.c_str(), tvstring.size(), &elmdat);
	shopScreen.addElement(elmdat);

	elmdat = makeElementData(51, 14, 4, 3, 0x000F);
	elmdat.data = "fuel";
	butDat = makeButtonData(true, 0x000C, 0x0004, "-1", NULL);
	butDat.dataCallback = &sellGoods;
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);


	elmdat = makeElementData(56, 14, 4, 3, 0x000F);
	elmdat.data = "fuel";
	butDat = makeButtonData(true, 0x000A, 0x0002, "+1", NULL);
	butDat.dataCallback = &buyGoods;
	makeButtonImage(&elmdat, &butDat);
	idx = shopScreen.addElement(elmdat);
	shopScreen.addButton(idx, butDat);



	//Market items & buy/sell buttons
	int shopElmY = 10;
	int shopElmYInc = 4;
	for (int i = 0; i <= goodsSize; ++i)
	{

		elmdat = makeElementData(21, shopElmY, 30, 3, 0x000F);
		elmdat.data = std::to_string(i);
		elmdat.imgRenderer = &makeShopItemImg;
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



	int starScreenX = 10;
	int starScreenXInc = 5;
	for (int i = 0; i < galSize; ++i)
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


		starScreenX += starScreenXInc + gal[i].name.size();
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


	starScreen.makeImage();
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
