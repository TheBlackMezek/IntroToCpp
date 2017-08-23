

#include <iostream>

#include "CoutUtils.h"
#include "structs.h"


void printHelp();



bool play = true;

const int baySize = 2;
cargo bay[baySize];
float maxFuel = 100.0f;
float fuel = maxFuel;
int loc = 0;
int money = 100;
std::string shipName = "";

const int solSize = 4;
planet sol[solSize];

int fuelCost = 1;





int main()
{
	sol[0] = { "Earth", 15,
		"EARTH:\nA beautiful planet of many colors, but most strikingly blue.\nIt is the fertile homeworld of humanity.\n",
	{ { "food", 1, 10}, {}, {} },
	{ { "synthlife", 1, 60 }, {"metals", 1, 10}, { "machines", 1, 20 } } };

	sol[1] = { "Luna", 15,
		"LUNA:\nKnown by Earthlings as 'The Moon'.\nIt is a barren, gray orb.\nIt is known for its science facilities.\n",
	{ { "synthlife", 1, 50 },{},{} },
	{ { "food", 1, 15 },{ "metals", 1, 12 },{} } };

	sol[2] = { "Mars", 15,
		"MARS:\nA dusty orange planet, and the site of humankind's first offworld colonies.\nIt is known for its low-G manufacturing and breathtaking natural features.\n",
	{ { "food", 1, 15 },{ "machines", 1, 15 },{} },
	{ { "synthlife", 1, 80 },{},{} } };

	sol[3] = { "Ceres", 25,
		"CERES:\nA dwarf planet in the asteroid belt.\nIt serves as the main refinery and manufacturing hub for A belt miners.\n",
	{ { "machines", 1, 10 },{ "metals", 1, 5 },{} },
	{ { "food", 1, 25 },{},{} } };




	printf("Welcome to Space Trader!\n");
	//printf("Enter 'ship' to get started.\n");
	printf("Enter the name of your ship:\n");
	std::getline(std::cin, shipName);
	brk();
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
			printf("Currently orbiting %s\n", sol[loc].name.c_str());
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
			printf("Planets and Moons\n");
			printf("Name and Fuel Cost\n");
			for (int i = 0; i < solSize; ++i)
			{
				printf("%s %f\n", sol[i].name.c_str(), sol[i].fuelCost);
			}
		}
		else if (input == "shop")
		{
			printf("Welcome to the %s marketplace!\n", sol[loc].name.c_str());
			brk();
			printf("You have $%i\n", money);
			brk();
			printf("Companies are selling:\n");
			printf("    fuel for %i each\n", fuelCost);

			for (int i = 0; i < goodsSize; ++i)
			{
				if (sol[loc].goods[i].qty > 0)
				{
					printf("    %s for %i each\n", sol[loc].goods[i].type.c_str(), sol[loc].goods[i].val);
				}
			}

			brk();
			printf("Companies are buying:\n");
			bool foundWants = false;
			for (int i = 0; i < wantsSize; ++i)
			{
				if (sol[loc].wants[i].qty > 0)
				{
					foundWants = true;
					printf("    %s for %i each\n", sol[loc].wants[i].type.c_str(), sol[loc].wants[i].val);
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
					if (sol[loc].goods[i].type == item)
					{
						if (money >= sol[loc].goods[i].val)
						{
							bool foundItemInBay = false;
							bool bayHasSpace = false;
							for (int b = 0; b < baySize; ++b)
							{
								if (bay[b].type == item)
								{
									foundItemInBay = true;
									money -= sol[loc].goods[i].val;
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
										money -= sol[loc].goods[i].val;
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
						if (sol[loc].wants[i].type == item)
						{
							storeWantsItem = true;
							--bay[b].qty;
							money += sol[loc].wants[i].val;
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
			if (obj == sol[loc].name)
			{
				printf("You're already at %s!\n", sol[loc].name.c_str());
			}
			else
			{
				bool objFound = false;
				for (int i = 0; i < solSize; ++i)
				{
					if (sol[i].name == obj)
					{
						objFound = true;
						if (fuel >= sol[i].fuelCost)
						{
							fuel -= sol[i].fuelCost;
							loc = i;
							printf("You fly to %s, using up %f fuel.\n", sol[i].name.c_str(), sol[i].fuelCost);
							printf("You have %f fuel left.\n", fuel);
							printf("Welcome to %s!\n", sol[i].name.c_str());
						}
						else
						{
							printf("You don't have enough fuel to go to %s!\n", sol[i].name.c_str());
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
			printf(sol[loc].desc.c_str());
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
	printf("You are currently in orbit around %s.\n", sol[loc].name.c_str());
	printf("\nBasic commands (without the ''s):\n'help' to see this text again\n'exit' to exit the game\n");
	printf("'ship' to see your ship stats\n'shop' to see the planet's shop\n");
	printf("'planets' to see a list of objects\n'desc' to see the description of the object you're orbiting\n");
	printf("'goto PlanetName' to go to an object\n'buy ItemName' to buy 1 of an item\n'sell ItemName' to sell 1 of an item\n");
	printf("\nTerminology: 'objects' is used to collectively refer to\nplanets, moons, space stations, etc.\n");
}