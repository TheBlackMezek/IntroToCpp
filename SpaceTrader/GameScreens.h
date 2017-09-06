#pragma once

#include "Screen.h"



extern Screen* screen;
extern Screen helpScreen;
extern Screen shipScreen;
extern Screen shopScreen;
extern Screen starScreen;
extern Screen loreScreen;
extern Screen endScreen;

void initScreens();

void initHelpScreen();
void initShipScreen();
void initShopScreen();
void initStarScreen();
void initLoreScreen();
void initEndScreen();


void switchScreenToHelp();
void switchScreenToShip();
void switchScreenToShop();
void switchScreenToStar();
void switchScreenToLore();
void switchScreenToEnd();




void makeCurrentOrbitImg(ElementData* e);
void makeCargoImg(ElementData* e);
void makeShipScreenImg(ElementData* e);
void makeShopNameImg(ElementData* e);
void makeShopItemImg(ElementData* e);
void makeFuelCostImg(ElementData* e);
void makeRetirementImg(ElementData* e);
void makeRetireCostImg(ElementData* e);
void makeEndImg(ElementData* e);
void makeStarSystemImg(ElementData* e);
void makeShopPlanetImg(ElementData* e);
void makeLogImg(ElementData* e);

void addLineToLog(const char line[], int size);

void buyGoods(ElementData* e);
void sellGoods(ElementData* e);
void buyMax(ElementData* e);
void sellAll(ElementData* e);
void fillFuel(ElementData* e);
void buyFiveFuel(ElementData* e);
void buyBayUpgrade(ElementData* e);
void goToObj(ElementData* e);
void clickRetire();
