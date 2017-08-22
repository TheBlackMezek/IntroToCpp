
#include "fighter.h"



fighter hit(fighter f, int dmg)
{
	if (dmg > f.def) { f.hp -= dmg - f.def; }
	return f;
}