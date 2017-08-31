#pragma once

#include "Screen.h"



extern Screen* screen;
extern Screen helpScreen;
extern Screen shipScreen;
extern Screen shopScreen;
extern Screen starScreen;

void initScreens();

void initHelpScreen();

void initShipScreen();

void initShopScreen();

void initStarScreen();


void switchScreenToHelp();
void switchScreenToShip();
void switchScreenToShop();
void switchScreenToStar();




void makeCurrentOrbitImg(ElementData* e);
void makeCargoImg(ElementData* e);
void makeShipScreenImg(ElementData* e);
void makeShopNameImg(ElementData* e);
void makeShopItemImg(ElementData* e);
void makeFuelCostImg(ElementData* e);

void buyGoods(ElementData* e);
void sellGoods(ElementData* e);
void goToObj(ElementData* e);
