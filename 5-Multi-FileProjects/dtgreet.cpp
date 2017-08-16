
#include "dtgreet.h"

#include <iostream>

#include "coututils.h"
#include "mathutils.h"



//Prints a greeting to console based on d/m/y
void dayGreeting(int d, int m, int y)
{
	std::string mName = "";

	m = clamp(1, 12, m);
	switch (m)
	{
	case 1:
		mName = "January";
		break;
	case 2:
		mName = "February";
		break;
	case 3:
		mName = "March";
		break;
	case 4:
		mName = "April";
		break;
	case 5:
		mName = "May";
		break;
	case 6:
		mName = "June";
		break;
	case 7:
		mName = "July";
		break;
	case 8:
		mName = "August";
		break;
	case 9:
		mName = "September";
		break;
	case 10:
		mName = "October";
		break;
	case 11:
		mName = "November";
		break;
	case 12:
		mName = "December";
		break;
	}

	
	prnts("Good morning!");
	prnts("We hope you have enjoyed your rest in the Aperture Science Relaxation Chamber!");
	std::cout << "Since your entry on " << d << " " << mName.c_str() << ", " << y << "," << std::endl;
	prnts("you have slept for *--ERROR_TIME_OUT_OF_BOUNDS--*");
}

//Prints a greeting to console based on hours and minutes
void timeGreeting(int m, int h)
{
	m = clamp(0, 59, m);
	h = clamp(1, 12, h);

	prnts("Good morning!");
	std::cout << "The time is " << h << ":" << m << std::endl;
	prnts("Your coffe maker has been auto-activated.");
}

//Returns true if year is a leap year, false if normal
bool isLeapYear(int y)
{
	return (y % 4 == 0) ? true : false;
}