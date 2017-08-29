
#include "GameScreens.h"

#include <string>

#include "WindowSetup.h"
#include "DataMaker.h"
#include "ImageMaker.h"


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
		"object - anything in space, be it planet, moon, star, or ship.\n"
		"satellite - anything in orbit of something else.\n"
		"    Moons are satellites of planets.";
	ElementData termsText = makeElementData(10, 10, WIN_WIDTH - 20, 10, 0x000F);
	makeTextImageMultiLine(false, termStr.c_str(), termStr.size(), &termsText);
	helpScreen.addElement(termsText);


	

	/*ElementData testBut = makeElementData(10, 20, 6, 3, 0x000F);
	ButtonData testButDat = makeButtonData(true, 0x000F, 0x000C, "Test", NULL);
	makeButtonImage(&testBut, &testButDat);
	int butIdx = helpScreen.addElement(testBut);
	helpScreen.addButton(butIdx, testButDat);*/
}

void initShipScreen()
{
	shipScreen = Screen();
	shipScreen.setSize(WIN_WIDTH, WIN_HEIGHT);
}

void initShopScreen()
{
	shopScreen = Screen();
	shopScreen.setSize(WIN_WIDTH, WIN_HEIGHT);
}

void initStarScreen()
{
	starScreen = Screen();
	starScreen.setSize(WIN_WIDTH, WIN_HEIGHT);
}
