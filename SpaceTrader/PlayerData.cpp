
#include "PlayerData.h"

#include "WindowSetup.h"

const int baySize = 10;
int itemsInBay = 0;
cargo bay[baySize];
const int logSize = (WIN_WIDTH - 20) * (WIN_HEIGHT - 30);
char tlog[logSize];
float maxFuel = 100.0f;
float fuel = maxFuel;
int loc = 2;
int money = 200;
std::string shipName = "";