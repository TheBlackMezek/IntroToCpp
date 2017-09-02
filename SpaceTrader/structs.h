#pragma once

#include <string>

//Cargo hold has a certain number of cargo slots
//Each cargo has a name, quantity and price
//Planets have a cargo array, name, and travel cost
//Planets need array for buying goods and selling goods
//Player needs to have a money var
//
//
//Game commands: help, planet stats, ship stats, planet list, travel, buy, sell


const int goodsSize = 10;
const int wantsSize = 3;

struct cargo
{
	std::string type;
	int qty;
	int val;
};

struct retirement
{
	std::string name;
	int cost;
	int color;
	std::string desc;
	std::string endText;
};

struct obj
{
	std::string name;
	std::string parent;
	int ploc;
	float dist;
	int sats;
	retirement retire;
	std::string desc;
	cargo goods[goodsSize];
	//cargo wants[wantsSize];
};







/*
To do over next 2 weeks (day goals):
//Separate planets and sats commands, planets have satellites (moons etc)
//Ability to buy/sell amounts of goods
//Cargo bay size is total number of items & variety of items, not just variety
//Ability to sell back into a market
Flesh out planets and goods, make a chart
Upgrade fuel tank
Upgrade cargo bay?
Retirement (look at options, retire on command)
Events (separate game state) with endgame-screen effects
Juice: news flashes when arriving on objects



Ideas:
Clear screen after every input & increase window size to allow for UI design
Planet UI should show name, shop, cargo, fuel and money
Fuel cost differences, planet location & fuel cost calculation
Other stuff to buy: upgrades, supplies, equipment, etc.
Events, game over changes based on actions
Events would be a separate game state
Economy simulation? Prices change as planet resources change
Planet resources would change sometimes because of random world events
Combat?
//Planet descriptions
//Player/Ship name

BUTTONS!

Need function to get substring by segment
Example:
string e = "Hi there friend";
func(e, 1) == "Hi"
func(e, 2) == "there"
func(e, 3) == "friend"

*/