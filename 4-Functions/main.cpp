
#include <iostream>




void prnts(std::string s);
void prnti(int i);
void prntf(float f);
void brk();
void pause();
int roundToInt(float f);
float getDiff(float a, float b);

void hello();
void prntSquare();
int square(int n);
void prntFrac();
float fracToFloat(int n, int d);
void prntDiff();
float getBiggestDiff(float a, float b, float c);
void prntNums();
void prntNumsActual(int a, int b);
void prntThreeSum();
int addThree(int a, int b, int c);
void prntMin();
int min(int a, int b);
void prntMax();
int max(int a, int b);
void prntClamp();
int clamp(int bot, int top, int n);
void prntDist();
float dist(int x1, int y1, int x2, int y2);
void prntTimeEst();
float timeEst(float dist, float speed);
void prntLerp();
float lerp(float n1, float n2, float q);




int main()
{
	// ---------- UTILITY SELECTION BEGIN ----------
	int selectionInput = -1;
	
	while (selectionInput != 0)
	{
		brk();
		brk();
		brk();
		
		prnts("SELECT PROGRAM UTILITY");
		prnts("Enter 0 to exit");
		prnts("Enter 1 for Hello World");
		prnts("Enter 2 for Square of Integer");
		prnts("Enter 3 for Fraction to Decimal");
		prnts("Enter 4 for Largest Difference");
		prnts("Enter 5 for Print Numbers with Comma");
		prnts("Enter 6 for Add Three Numbers");
		prnts("Enter 7 for Min");
		prnts("Enter 8 for Max");
		prnts("Enter 9 for Custom Clamp");
		prnts("Enter 10 for Distance Calculator");
		prnts("Enter 11 for Travel Time Estimater");
		prnts("Enter 12 for Linear Interpolater");
		brk();

		std::cin >> selectionInput;
		std::cin.clear();
		std::cin.ignore();

		brk();
		brk();
		brk();

		switch (selectionInput)
		{
		case 1:
			hello();
			break;
		case 2:
			prntSquare();
			break;
		case 3:
			prntFrac();
			break;
		case 4:
			prntDiff();
			break;
		case 5:
			prntNums();
			break;
		case 6:
			prntThreeSum();
			break;
		case 7:
			prntMin();
			break;
		case 8:
			prntMax();
			break;
		case 9:
			prntClamp();
			break;
		case 10:
			prntDist();
			break;
		case 11:
			prntTimeEst();
			break;
		case 12:
			prntLerp();
			break;
		default:
			break;
		}
	}
	// ---------- UTILITY SELECTION END ----------



	return 0;
}





void hello()
{
	prnts("Hello World!");
}

void prntSquare()
{
	prnts("Enter an integer to square:");

	int n = 0;
	std::cin >> n;
	
	std::cout << "The square of " << n << " is " << square(n) << std::endl;

	brk();
	pause();
}

int square(int n)
{
	return n * n;
}

void prntFrac()
{
	prnts("Enter an numerator:");

	int n = 0;
	std::cin >> n;
	brk();

	prnts("Enter a denominator:");

	int d = 0;
	std::cin >> d;
	brk();

	std::cout << "The decimal version of " << n << "/" << d << " is " << fracToFloat(n, d) << std::endl;

	brk();
	pause();
}

float fracToFloat(int n, int d)
{
	return (float)n / (float)d;
}

void prntDiff()
{
	prnts("Enter a number:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter a second number:");

	int b = 0;
	std::cin >> b;
	brk();

	prnts("Enter a third number:");

	int c = 0;
	std::cin >> c;
	brk();

	std::cout << "The largest difference between those numbers is " << getBiggestDiff(a, b, c) << std::endl;

	brk();
	pause();
}

float getBiggestDiff(float a, float b, float c)
{
	float diff = getDiff(a, b);

	float tempDiff = getDiff(a, c);
	diff = (tempDiff > diff) ? tempDiff : diff;

	tempDiff = getDiff(b, c);
	diff = (tempDiff > diff) ? tempDiff : diff;

	return diff;
}

void prntNums()
{
	prnts("Enter a number:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter a second number:");

	int b = 0;
	std::cin >> b;
	brk();

	prntNumsActual(a, b);

	brk();
	pause();
}

void prntNumsActual(int a, int b)
{
	std::cout << a << "," << b << std::endl;
}

void prntThreeSum()
{
	prnts("Enter a number:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter a second number:");

	int b = 0;
	std::cin >> b;
	brk();

	prnts("Enter a third number:");

	int c = 0;
	std::cin >> c;
	brk();

	std::cout << "The sum of those numbers is " << addThree(a, b, c) << std::endl;

	brk();
	pause();
}

int addThree(int a, int b, int c)
{
	return a + b + c;
}

void prntMin()
{
	prnts("Enter a number:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter a second number:");

	int b = 0;
	std::cin >> b;
	brk();

	std::cout << "The lesser of those numbers is " << min(a, b) << std::endl;

	brk();
	pause();
}

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		// If b is smaller, return b. If equal, doesn't matter which is returned.
		return b;
	}
}

void prntMax()
{
	prnts("Enter a number:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter a second number:");

	int b = 0;
	std::cin >> b;
	brk();

	std::cout << "The greater of those numbers is " << max(a, b) << std::endl;

	brk();
	pause();
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		// If b is greater, return b. If equal, doesn't matter which is returned.
		return b;
	}
}

void prntClamp()
{
	prnts("Enter a lower limit:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter an upper limit:");

	int b = 0;
	std::cin >> b;
	brk();

	prnts("Enter a number to clamp:");

	int c = 0;
	std::cin >> c;
	brk();

	std::cout << "After clamping, the third number is " << clamp(a, b, c) << std::endl;

	brk();
	pause();
}

int clamp(int bot, int top, int n)
{
	n = (n < bot) ? bot : n;
	n = (n > top) ? top : n;
	return n;
}

void prntDist()
{
	prnts("Enter X coord 1:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter Y coord 1:");

	int b = 0;
	std::cin >> b;
	brk();

	prnts("Enter X coord 2:");

	int c = 0;
	std::cin >> c;
	brk();

	prnts("Enter y coord 2:");

	int d = 0;
	std::cin >> d;
	brk();

	std::cout << "The distance between " << a << "," << b << " and " << c << "," << d << " is " << dist(a, b, c, d) << std::endl;

	brk();
	pause();
}

float dist(int x1, int y1, int x2, int y2)
{
	return sqrt( pow(((float)x2 - (float)x1), 2) + pow(((float)y2 - (float)y1), 2) );
}

void prntTimeEst()
{
	prnts("Enter X coord 1:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter Y coord 1:");

	int b = 0;
	std::cin >> b;
	brk();

	prnts("Enter X coord 2:");

	int c = 0;
	std::cin >> c;
	brk();

	prnts("Enter y coord 2:");

	int d = 0;
	std::cin >> d;
	brk();

	prnts("Enter speed:");

	int e = 0;
	std::cin >> e;
	brk();

	std::cout << "The time it will take to go between " << a << "," << b << " and " << c << "," << d << " is " << timeEst(dist(a, b, c, d), e) << std::endl;

	brk();
	pause();
}

float timeEst(float dist, float speed)
{
	return dist / speed;
}

void prntLerp()
{
	prnts("Enter a lower number:");

	float a = 0;
	std::cin >> a;
	brk();

	prnts("Enter a higher number:");

	float b = 0;
	std::cin >> b;
	brk();

	prnts("Enter a number from 0 to 1 to find within that range:");

	float c = 0;
	bool goodInput = false;
	while (!goodInput)
	{
		std::cin >> c;
		brk();

		if (c >= 0 && c <= 1)
		{
			goodInput = true;
		}
		else
		{
			prnts("Invalid entry. Enter a number from 0 to 1.");
		}
	}

	std::cout << "The lerp value is " << lerp(a, b, c) << std::endl;

	brk();
	pause();
}

float lerp(float n1, float n2, float q)
{
	n2 -= n1;
	return n2 * q + n1;
}










void prnts(std::string s)
{
	std::cout << s.c_str() << std::endl;
}

void prnti(int i)
{
	std::cout << i << std::endl;
}

void prntf(float f)
{
	std::cout << f << std::endl;
}

void brk()
{
	std::cout << std::endl;
}

void pause()
{
	system("pause");
}

int roundToInt(float f)
{
	return floor(f + 0.5f);
}

float getDiff(float a, float b)
{
	if (a > b)
	{
		return a - b;
	}
	else if (a < b)
	{
		return b - a;
	}
	else
	{
		return 0.0f;
	}
}