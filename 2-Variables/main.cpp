

#include <iostream>


void cfConverter();
void areaRectCalc();
void avgOfFiveCalc();
void numSwap();
void ageFacts();

void prnts(std::string s);
void prnti(int i);
void prntf(float f);
void brk();
void pause();
int roundToInt(float f);


/*
//10 fundamental types for challenge 2, commented out so it doesn't interfere by accident.
//I have 11 types here.
void voidTest; //Cannot be assigned
char charTest = 'l';
char charTest2 = 2;
signed char sCharTest = -3; //C++ considers signed chars, unsigned chars, and normal chars to be different types.
unsigned char usCharTest = 3;
bool boolTest = true;
short shortTest = 10; //Larger than char and smaller than int.
int intTest = 100; //Larger than short and smaller than long.
long longTest = 1000; //Larger than int.
float floatTest = 1111; //Smallest floating point type.
double doubleTest = 1212; //Larger than float but smaller than long double.
long double ldTest = 121212; //Larger than double.
*/


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
		prnts("Enter 1 for Celcius-Fahrenheit Converter");
		prnts("Enter 2 for Area of Rectangle Calculator");
		prnts("Enter 3 for Average of Five Calculator");
		prnts("Enter 4 for Number Swap");
		prnts("Enter 5 for Age Facts");
		brk();

		std::cin >> selectionInput;
		std::cin.clear();
		std::cin.ignore();

		brk();
		brk();
		brk();

		if (selectionInput == 1)
		{
			cfConverter();
		}
		else if (selectionInput == 2)
		{
			areaRectCalc();
		}
		else if (selectionInput == 3)
		{
			avgOfFiveCalc();
		}
		else if (selectionInput == 4)
		{
			numSwap();
		}
		else if (selectionInput == 5)
		{
			ageFacts();
		}
	}
	// ---------- UTILITY SELECTION END ----------



	return 0;
}



void cfConverter()
{
	int selectionInput = -1;

	//Degrees Celcius and Farenheit
	float degC = 0.0f;
	float degF = 0.0f;

	prnts("Fahrenheit to Celcius Converter");

	while (selectionInput != 1 && selectionInput != 2) {
		prnts("Enter 1 for C to F   or   2 for F to C");
		std::cin >> selectionInput;
	}

	if (selectionInput == 2) {
		prnts("Enter a Fahrenheit value to convert to Celcius:");
		std::cin >> degF;
		brk();

		degC = (degF - 32) * (5.0f / 9.0f);
		prntf(degC);
	}
	else
	{
		prnts("Enter a Celcius value to convert to Fahrenheit:");
		std::cin >> degC;
		brk();

		degF = degC * (5.0f / 9.0f) + 32;
		prntf(degF);
	}

	brk();
	pause();
}

void areaRectCalc()
{
	float rectWidth = 0.0f;
	float rectHeight = 0.0f;
	float rectArea = 0.0f;

	prnts("RECTANGLE AREA CALCULATION");
	prnts("Enter rectangle height:");
	std::cin >> rectHeight;
	brk();
	prnts("Enter rectangle width:");
	std::cin >> rectWidth;
	brk();

	rectArea = rectHeight * rectWidth;

	prnts("Area of a Rectangle)");
	std::cout << "H: " << rectHeight << " , W: " << rectWidth << std::endl;
	std::cout << "Area: " << rectArea << std::endl;

	brk();
	pause();
}

void avgOfFiveCalc()
{
	float a, b, c, d, e;
	float avg;
	avg = a = b = c = d = e = 0.0f;

	prnts("AVERAGE OF FIVE NUMBERS CALCULATION");
	prnts("Enter first number:");
	std::cin >> a;
	prnts("Enter second number:");
	std::cin >> b;
	prnts("Enter third number:");
	std::cin >> c;
	prnts("Enter fourth number:");
	std::cin >> d;
	prnts("Enter fifth number:");
	std::cin >> e;
	brk();

	avg = (a + b + c + d + e) / 5;

	prnts("Average of Five)");
	std::cout << a << "," << b << "," << c << "," << d << "," << e << "," << std::endl;
	std::cout << "avg: " << avg << std::endl;

	brk();
	pause();
}

void numSwap()
{
	int x = 13;
	int y = 24;

	prnts("NUMBER SWAP");
	prnts("Enter number x:");
	std::cin >> x;
	brk();
	prnts("Enter number y:");
	std::cin >> y;
	brk();

	int xHolder = x;
	x = y;
	y = xHolder;

	prnts("Number Swap)");
	std::cout << "x is " << x << std::endl;
	std::cout << "y is " << y << std::endl;

	brk();
	pause();
}

void ageFacts()
{
	float age = 0.0f;
	float avgJapLife = 84.0f;
	float ageAmrLife = 79.0f;
	float avgSiLeLife = 50.0f;

	prnts("FACTS ABOUT YOUR AGE");
	prnts("Enter your age:");
	std::cin >> age;

	brk();

	std::cout << "You are " << age << " years old." << std::endl;
	std::cout << "You are at least " << age * 12 << " months old." << std::endl;
	std::cout << "You are about " << roundToInt(age / 10) << " decades old." << std::endl;
	std::cout << "You are about " << roundToInt(age / 20) << " score old, if you like old terms." << std::endl;
	std::cout << "You have lived through about " << (age / avgJapLife) * 100.0f << "% of an avg Japanese lifespan." << std::endl;
	std::cout << "You have lived through about " << (age / ageAmrLife) * 100.0f << "% of an avg American lifespan." << std::endl;
	std::cout << "You have lived through about " << (age / avgSiLeLife) * 100.0f << "% of an avg Sierra Leonean lifespan." << std::endl;

	brk();
	pause();
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