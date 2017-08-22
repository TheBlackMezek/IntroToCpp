
#include "vector2.h"

#include <math.h>



float affineSum(vec2 v1, vec2 v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

vec2 vecDiff(vec2 v1, vec2 v2)
{
	return vec2{ v1.x - v2.x, v2.y - v2.y };
}

float vecDist(vec2 v1, vec2 v2)
{
	return sqrtf(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}