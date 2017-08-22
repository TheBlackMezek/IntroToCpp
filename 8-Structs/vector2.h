#pragma once



struct vec2
{
	float x;
	float y;
};


//Somewhat guessing what an affine sum is.
//The Internet isn't giving me very understandable info about it.
vec2 affineSum(vec2 v1, vec2 v2);

vec2 vecDiff(vec2 v1, vec2 v2);

float vecDist(vec2 v1, vec2 v2);