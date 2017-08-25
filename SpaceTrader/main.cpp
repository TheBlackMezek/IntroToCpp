

#include <iostream>

#include "CoutUtils.h"
//#include "structs.h"
#include "Galaxy.h"


void printHelp();
float getFuelCost(int strt, int dest);
float diff(float a, float b);
//Gets word i from the string, words being separated by spaces
std::string getWord(std::string s, int i);



bool play = true;

const int baySize = 2;
cargo bay[baySize];
float maxFuel = 100.0f;
float fuel = maxFuel;
int loc = 2;
int money = 100;
std::string shipName = "";



int fuelCost = 1;





int main()
{
	



	//This puts all the data in gal[]
	initGalaxy();



	printf("Welcome to Space Trader!\n");
	printf("Enter the name of your ship:\n");
	std::getline(std::cin, shipName);
	brk();
	printf("Welcome aboard the %s captain!\n", shipName.c_str());
	printHelp();


	std::string input = "";
	while (play)
	{
		brk();
		std::getline(std::cin, input);
		brk();

		if (input == "exit")
		{
			play = false;
			break;
		}
		else if (input == "ship")
		{
			brk();
			printf("%s stats:\n", shipName.c_str());
			printf("Money: $%i\n", money);
			printf("Fuel: %f / %f\n", fuel, maxFuel);
			printf("Currently orbiting %s\n", gal[loc].name.c_str());
			printf("Current cargo:\n");
			bool foundCargo = false;
			for (int i = 0; i < baySize; ++i)
			{
				if (bay[i].qty > 0)
				{
					foundCargo = true;
					printf("%i %s\n", bay[i].qty, bay[i].type.c_str());
				}
			}
			if (!foundCargo)
			{
				printf("None\n");
			}
		}
		else if (input == "planets")
		{
			printf("Planets around Sol\n");
			printf("Name, satellite count and fuel cost from %s\n", gal[loc].name.c_str());
			for (int i = 0; i < galSize; ++i)
			{
				if (gal[i].ploc == -1)
				{
					printf("%s %i %f\n", gal[i].name.c_str(), gal[i].sats, getFuelCost(loc, i));
				}
			}
		}
		else if (input == "objects")
		{
			printf("All objects around Sol\n");
			printf("Name, satellite count and fuel cost from %s\n", gal[loc].name.c_str());
			for (int i = 0; i < galSize; ++i)
			{
				printf("%s %i %f\n", gal[i].name.c_str(), gal[i].sats, getFuelCost(loc, i));
			}
		}
		else if (input == "sats")
		{
			printf("Objects around %s\n", gal[loc].name.c_str());
			printf("Name, satellite count and fuel cost from %s:\n", gal[loc].name.c_str());
			bool foundSat = false;
			for (int i = 0; i < galSize; ++i)
			{
				if (gal[i].ploc == loc)
				{
					foundSat = true;
					printf("%s %i %f\n", gal[i].name.c_str(), gal[i].sats, getFuelCost(loc, i));
				}
			}
			if (!foundSat)
			{
				printf("No satellites found\n");
			}
		}
		//else if (input.substr(0, 4) == "sats")
		else if (getWord(input, 0) == "sats")
		{
			std::string obj = input.substr(5, input.npos);
			bool objFound = false;
			for (int i = 0; i < galSize; ++i)
			{
				if (gal[i].name == obj)
				{
					objFound = true;
					printf("Objects around %s\n", gal[i].name.c_str());
					printf("Name, satellite count and fuel cost from %s:\n", gal[loc].name.c_str());
					bool foundSat = false;
					for (int q = 0; q < galSize; ++q)
					{
						if (gal[q].ploc == i)
						{
							foundSat = true;
							printf("%s %i %f\n", gal[q].name.c_str(), gal[q].sats, getFuelCost(loc, q));
						}
					}
					if (!foundSat)
					{
						printf("No satellites found\n");
					}
					break;
				}
			}
			if (!objFound)
			{
				printf("%s is not a known object.\n", obj.c_str());
			}
		}
		else if (input == "shop")
		{
			printf("Welcome to the %s marketplace!\n", gal[loc].name.c_str());
			brk();
			printf("You have $%i\n", money);
			brk();
			printf("Companies are selling:\n");
			printf("    fuel for %i each\n", fuelCost);

			for (int i = 0; i < goodsSize; ++i)
			{
				if (gal[loc].goods[i].qty > 0)
				{
					printf("    %s for %i each\n", gal[loc].goods[i].type.c_str(), gal[loc].goods[i].val);
				}
			}

			brk();
			printf("Companies are buying:\n");
			bool foundWants = false;
			for (int i = 0; i < wantsSize; ++i)
			{
				if (gal[loc].wants[i].qty > 0)
				{
					foundWants = true;
					printf("    %s for %i each\n", gal[loc].wants[i].type.c_str(), gal[loc].wants[i].val);
				}
			}
			if (!foundWants)
			{
				printf("None\n");
			}
		}
		else if (input.substr(0, 3) == "buy")
		{
			std::string item = input.substr(4, input.npos);
			if (item == "fuel")
			{
				if (money >= fuelCost)
				{
					if (fuel < maxFuel)
					{
						money -= fuelCost;
						++fuel;
						printf("You have $i left and %f fuel in your tank.\n", money, fuel);
						printf("Thank you for your purchase!\n");
					}
					else
					{
						printf("Your fuel tank is full!\n");
					}
				}
				else
				{
					printf("You don't have enough money!\n");
				}
			}
			else
			{
				for (int i = 0; i < goodsSize; ++i)
				{
					if (gal[loc].goods[i].type == item)
					{
						if (money >= gal[loc].goods[i].val)
						{
							bool foundItemInBay = false;
							bool bayHasSpace = false;
							for (int b = 0; b < baySize; ++b)
							{
								if (bay[b].type == item)
								{
									foundItemInBay = true;
									money -= gal[loc].goods[i].val;
									++bay[b].qty;
									printf("You have $%i left and %i %s in your cargo hold.\n", money, bay[b].qty, item.c_str());
									break;
								}
							}
							if (!foundItemInBay)
							{
								for (int b = 0; b < baySize; ++b)
								{
									if (bay[b].qty == 0)
									{
										bayHasSpace = true;
										money -= gal[loc].goods[i].val;
										bay[b].type = item;
										++bay[b].qty;
										printf("You have $%i left and %i %s in your cargo hold.\n", money, bay[b].qty, item.c_str());
										break;
									}
								}
							}
							if (!bayHasSpace && !foundItemInBay)
							{
								printf("Your cargo bay doesn't have space!");
							}
						}
						else
						{
							printf("You don't have enough money.\n");
						}
						printf("Thank you for your purchase!\n");
						break;
					}
					else
					{
						printf("Sorry, I don't sell that.\n");
					}
				}
			}
		}
		else if (input.substr(0, 4) == "sell")
		{
			std::string item = input.substr(5, input.npos);
			bool bayHasItem = false;
			for (int b = 0; b < baySize; ++b)
			{
				if (bay[b].type == item)
				{
					bayHasItem = true;
					bool storeWantsItem = false;
					for (int i = 0; i < wantsSize; ++i)
					{
						if (gal[loc].wants[i].type == item)
						{
							storeWantsItem = true;
							--bay[b].qty;
							money += gal[loc].wants[i].val;
							printf("Sale successful!\n");
							printf("You now have $%i and %i %s in your cargo bay.\n", money, bay[b].qty, bay[b].type.c_str());
							if (!bay[b].qty) { bay[b].type = ""; }
							break;
						}
					}
					if (!storeWantsItem)
					{
						printf("Sorry, we're not interested in buying that.\n");
					}
					break;
				}
			}
			if (!bayHasItem)
			{
				printf("You don't have that in your cargo bay!\n");
			}
		}
		else if (input.substr(0, 4) == "goto")
		{
			std::string obj = input.substr(5, input.npos);
			if (obj == gal[loc].name)
			{
				printf("You're already at %s!\n", gal[loc].name.c_str());
			}
			else
			{
				bool objFound = false;
				for (int i = 0; i < galSize; ++i)
				{
					if (gal[i].name == obj)
					{
						objFound = true;
						float fuelCost = getFuelCost(loc, i);
						if (fuel >= fuelCost)
						{
							fuel -= fuelCost;
							loc = i;
							printf("You fly to %s, using up %f fuel.\n", gal[i].name.c_str(), fuelCost);
							printf("You have %f fuel left.\n", fuel);
							printf("Welcome to %s!\n", gal[i].name.c_str());
						}
						else
						{
							printf("You don't have enough fuel to go to %s!\n", gal[i].name.c_str());
						}
						break;
					}
				}
				if (!objFound)
				{
					printf("%s is not a viable destination.\n", obj.c_str());
				}
			}
		}
		else if (input == "desc")
		{
			printf(gal[loc].desc.c_str());
		}
		else if (input == "help")
		{
			printHelp();
		}
	}



	return 0;
}


void printHelp()
{
	printf("You are currently in orbit around %s.\n", gal[loc].name.c_str());
	printf("\nBASIC COMMANDS (without the ''s):\n'help' to see this text again\n'exit' to exit the game\n");
	printf("'ship' to see your ship stats\n'shop' to see the planet's shop\n");
	printf("'planets' to see the list of planets\n");
	printf("'sats' to see a list of satellites in your current orbit\n");
	printf("'sats ObjectName' to see a list of satellites for an object\n");
	printf("'objects' to see a list of all objects around Sol\n");
	printf("'desc' to see the description of the object you're orbiting\n");
	printf("'goto PlanetName' to go to an object\n'buy ItemName' to buy 1 of an item\n'sell ItemName' to sell 1 of an item\n");
	printf("\nTERMINOLOGY: 'objects' is used to collectively refer to\nplanets, moons, space stations, etc.\n");
	printf("A 'satellite' isn't just man-made. Moons are also satellites.\n");
}

float getFuelCost(int strt, int dest)
{
	//If orbiting the same object, just get distance from each other
	if (gal[strt].ploc == gal[dest].ploc)
	{
		return diff(gal[strt].dist, gal[dest].dist);
	}
	//If destination is parent of current object, get distance to parent
	else if (gal[strt].ploc == dest)
	{
		return gal[strt].dist;
	}
	//If destination is satellite of current object, get distance to parent
	else if (gal[dest].ploc == strt)
	{
		return gal[dest].dist;
	}
	//If not siblings or parent/child, find lowest common ancestor
	else
	{
		//Find distance from each location to top
		int sToTop = 0;
		int dToTop = 0;

		int loopLoc = strt;
		while (gal[loopLoc].ploc != -1)
		{
			++sToTop;
			loopLoc = gal[loopLoc].ploc;
		}
		loopLoc = dest;
		while (gal[loopLoc].ploc != -1)
		{
			++dToTop;
			loopLoc = gal[loopLoc].ploc;
		}

		//Sum up distance
		float totalDist = 0;
		while (sToTop >= 0 && dToTop >= 0)
		{
			if (sToTop > dToTop)
			{
				totalDist += gal[strt].dist;
				strt = gal[strt].ploc;
				--sToTop;
			}
			else if (dToTop > sToTop)
			{
				totalDist += gal[dest].dist;
				dest = gal[dest].ploc;
				--dToTop;
			}
			else
			{
				totalDist += gal[strt].dist;
				strt = gal[strt].ploc;
				--sToTop;
				totalDist += gal[dest].dist;
				dest = gal[dest].ploc;
				--dToTop;
			}

			if (gal[strt].ploc == gal[dest].ploc)
			{
				totalDist += diff(gal[strt].dist, gal[dest].dist);
				break;
			}
			else if (gal[strt].ploc == dest)
			{
				totalDist += gal[strt].dist;
				break;
			}
			else if (gal[dest].ploc == strt)
			{
				totalDist += gal[dest].dist;
				break;
			}
		}
		return totalDist;
	}
}

float diff(float a, float b)
{
	return (a > b) ? a - b : b - a;
}

std::string getWord(std::string s, int i)
{
	int lastPos = -1;
	int pos = 0;

	do
	{
		pos = s.find(' ');
		if (pos == std::string::npos)
		{
			return s.substr(lastPos + 1, pos);
		}
		else if (i == 0)
		{
			return s.substr(lastPos + 1, pos - lastPos - 1);
		}
		--i;
		lastPos = pos;

	} while (i >= 0);
}