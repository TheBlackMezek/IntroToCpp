#pragma once

#include "Screen.h"



extern Screen* screen;
extern Screen helpScreen;
extern Screen shipScreen;
extern Screen shopScreen;
extern Screen starScreen;
extern Screen endScreen;

void initScreens();

void initHelpScreen();

void initShipScreen();

void initShopScreen();

void initStarScreen();

void initEndScreen();


void switchScreenToHelp();
void switchScreenToShip();
void switchScreenToShop();
void switchScreenToStar();
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

void buyGoods(ElementData* e);
void sellGoods(ElementData* e);
void goToObj(ElementData* e);
void clickRetire();
