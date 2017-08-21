
#include <iostream>
#include<time.h>

#include "coututils.h"
#include "mathutils.h"



void favNums();
void prntRange();
void prntRangeTrue(int x, int y);
void prntLargest();
void prntSmallest();
void prntEvenOdd();
void prntEvenOddTrue(int x, int y);
void prntFizzBuzz();
void gridGen();
void numGuess();



int main()
{
	srand(time(NULL));

	
	for (int i = 1; i <= 100; ++i)
	{
		prnti(i);
	}

	std::cout << std::endl;
	std::cin.get();



	int counter = 100;
	while(counter > 0)
	{
		prnti(counter);
		--counter;
	}

	std::cout << std::endl;
	std::cin.get();



	counter = 1995;
	do
	{
		prnti(counter);
		++counter;
	} while (counter <= 2017);

	std::cout << std::endl;
	std::cin.get();



	// ---------- UTILITY SELECTION BEGIN ----------
	int selectionInput = -1;

	while (selectionInput != 0)
	{
		brk();
		brk();
		brk();

		prnts("SELECT PROGRAM UTILITY");
		prnts("Enter 0 to exit");
		prnts("Enter 1 for Favorite Positive Numbers");
		prnts("Enter 2 for Print Range");
		prnts("Enter 3 for Largest Number");
		prnts("Enter 4 for Smallest Number");
		prnts("Enter 5 for Evens and Odds");
		prnts("Enter 6 for FizzBuzz");
		prnts("Enter 7 for Grid Generator");
		prnts("Enter 8 for Guess the Number");
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
			favNums();
			break;
		case 2:
			prntRange();
			break;
		case 3:
			prntLargest();
			break;
		case 4:
			prntSmallest();
			break;
		case 5:
			prntEvenOdd();
			break;
		case 6:
			prntFizzBuzz();
			break;
		case 7:
			gridGen();
			break;
		case 8:
			numGuess();
			break;
		default:
			break;
		}
	}
	// ---------- UTILITY SELECTION END ----------



	return 0;
}





void favNums()
{
	int num1, num2, num3;
	num1 = num2 = num3 = 0;

	prnts("What are your favorite positive numbers?");
	prnts("Answer one at a time.");

	while (num1 <= 0)
	{
		prnts("What's the first number?");
		std::cin >> num1;

		if (num1 <= 0)
		{
			prnts("That is not a positive number.");
		}
	}

	std::cout << "Your first favorite number is " << num1 << "!" << std::endl;

	while (num2 <= 0)
	{
		prnts("What's the second number?");
		std::cin >> num2;

		if (num2 <= 0)
		{
			prnts("That is not a positive number.");
		}
	}

	std::cout << "Your first two favorite numbers are " << num1 << " and " << num2 << "!" << std::endl;

	while (num3 <= 0)
	{
		prnts("What's the third number?");
		std::cin >> num3;

		if (num2 <= 0)
		{
			prnts("That is not a positive number.");
		}
	}

	std::cout << "Your favorite numbers are " << num1 << ", " << num2 << " and " << num3 << "!" << std::endl;
}

void prntRange()
{
	int x, y;
	x = y = 0;

	prnts("Enter a number:");
	std::cin >> x;

	prnts("Enter a second number:");
	std::cin >> y;

	brk();

	prntRangeTrue(x, y);
}

void prntRangeTrue(int x, int y)
{
	if (x < y)
	{
		for (x; x <= y; ++x)
		{
			prnti(x);
		}
	}
	else
	{
		for (x; x >= y; --x)
		{
			prnti(x);
		}
	}
}

void prntLargest()
{
	prnts("How many numbers would you like to enter?");

	int qty = 0;
	while (qty <= 0)
	{
		std::cin >> qty;

		if (qty <= 0)
		{
			prnts("Please enter a number greater than 0.");
		}
	}



	bool firstInput = true;
	int largest = 0;
	int input = 0;

	while (qty > 0)
	{
		prnts("Enter a number:");
		std::cin >> input;

		if (firstInput || largest < input)
		{
			firstInput = false;
			largest = input;
		}

		--qty;
	}



	std::cout << "The largest of those number is " << largest;
}

void prntSmallest()
{
	prnts("How many numbers would you like to enter?");

	int qty = 0;
	while (qty <= 0)
	{
		std::cin >> qty;

		if (qty <= 0)
		{
			prnts("Please enter a number greater than 0.");
		}
	}



	bool firstInput = true;
	int smallest = 0;
	int input = 0;

	while (qty > 0)
	{
		prnts("Enter a number:");
		std::cin >> input;

		if (firstInput || smallest > input)
		{
			firstInput = false;
			smallest = input;
		}

		--qty;
	}



	std::cout << "The smallest of those number is " << smallest;
}

void prntEvenOdd()
{
	int x, y;
	x = y = 0;

	prnts("Enter a number:");
	std::cin >> x;

	prnts("Enter a second number:");
	std::cin >> y;

	brk();

	prntEvenOddTrue(x, y);
}

void prntEvenOddTrue(int x, int y)
{
	if (x < y)
	{
		for (x; x <= y; ++x)
		{
			(x % 2 == 0) ? prnts("Even") : prnts("Odd");
		}
	}
	else
	{
		for (x; x >= y; --x)
		{
			(x % 2 == 0) ? prnts("Even") : prnts("Odd");
		}
	}
}

void prntFizzBuzz()
{
	int x, y;
	x = y = 0;

	prnts("Enter a number:");
	std::cin >> x;

	prnts("Enter a second number:");
	std::cin >> y;

	brk();



	if(x < y)
	{
		for (x; x <= y; ++x)
		{
			if (x % 3 == 0 && x % 5 != 0)
			{
				prnts("Fizz");
			}
			else if (x % 5 == 0 && x % 3 != 0)
			{
				prnts("Buzz");
			}
			else if (x % 5 == 0 && x % 3 == 0)
			{
				prnts("FizzBuzz");
			}
			else
			{
				prnti(x);
			}
		}
	}
	else
	{
		for (x; x >= y; --x)
		{
			if (x % 3 == 0 && x % 5 != 0)
			{
				prnts("Fizz");
			}
			else if (x % 5 == 0 && x % 3 != 0)
			{
				prnts("Buzz");
			}
			else if (x % 5 == 0 && x % 3 == 0)
			{
				prnts("FizzBuzz");
			}
			else
			{
				prnti(x);
			}
		}
	}
}

void gridGen()
{
	int w, h;
	w = h = 0;

	prnts("Enter width:");
	std::cin >> w;

	prnts("Enter height:");
	std::cin >> h;

	brk();


	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			std::cout << "X";
		}
		brk();
	}
}

void numGuess()
{
	int low = 1;
	int high = 100;
	int guesses = 10;
	int num = rand() % (high - low) + low;

	int input = 0;


	std::cout << "Try to guess the number, which can be from " << low << " to " << high << "." << std::endl;
	std::cout << "You have " << guesses << " tries to guess it!" << std::endl;

	while (guesses > 0)
	{
		prnts("Enter your guess:");

		std::cin >> input;

		if (input == num)
		{
			prnts("That is correct! You win!");
			break;
		}
		else if (input < num)
		{
			--guesses;
			std::cout << "That is too low! You have " << guesses << " tries left." << std::endl;
		}
		else
		{
			--guesses;
			std::cout << "That is too high! You have " << guesses << " tries left." << std::endl;
		}
	}
	
	if (guesses == 0)
	{
		prnts("You're out of guesses!");
	}
}