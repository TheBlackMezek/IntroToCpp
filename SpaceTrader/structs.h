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


const int goodsSize = 3;
const int wantsSize = 3;

struct cargo
{
	std::string type;
	int qty;
	int val;
};

struct planet
{
	std::string name;
	float fuelCost;
	std::string desc;
	cargo goods[goodsSize];
	cargo wants[wantsSize];
};







/*
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