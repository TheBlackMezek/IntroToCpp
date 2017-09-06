
#include "PlayerData.h"

#include "WindowSetup.h"

const int baySizeMax = 20;
int baySize = 10;
int itemsInBay = 0;
cargo bay[baySizeMax];
const int logSize = (WIN_WIDTH - 60) * (WIN_HEIGHT - 30);
char tlog[logSize + 1];
float maxFuel = 100.0f;
float fuel = maxFuel;
int loc = 2;
int money = 200;
std::string shipName = "";

int bayUpCost = 250;
float bayCostMult = 1.2f;