
#include <iostream>



void judgeNumber();
void ageGate();
void smallestNum();
void evenOrOdd();
void clampNum();
void thaiSpicy();
void cookieOrder();
void sketchbookOrder();
void motionBlur();
void textureSize();
void fourCalculator();
void dinoBattle();

void prnts(std::string s);
void prnti(int i);
void prntf(float f);
void brk();
void pause();
int roundToInt(float f);



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
		prnts("Enter 1 for Number Judge");
		prnts("Enter 2 for Age Gate");
		prnts("Enter 3 for Smallest Number");
		prnts("Enter 4 for Even or Odd");
		prnts("Enter 5 for Clamp Number");
		prnts("Enter 6 for Thai Spicy");
		prnts("Enter 7 for Cookie Order");
		prnts("Enter 8 for Sketchbook Order");
		prnts("Enter 9 for Hypothetical Motion Blur");
		prnts("Enter 10 for Texture Size");
		prnts("Enter 11 for Calculator");
		prnts("Enter 12 for Dino Battle");
		brk();

		std::cin >> selectionInput;
		std::cin.clear();
		std::cin.ignore();

		brk();
		brk();
		brk();

		/*
		if (selectionInput == 1)
		{
			judgeNumber();
		}
		*/

		switch (selectionInput)
		{
		case 1:
			judgeNumber();
			break;
		case 2:
			ageGate();
			break;
		case 3:
			smallestNum();
			break;
		case 4:
			evenOrOdd();
			break;
		case 5:
			clampNum();
			break;
		case 6:
			thaiSpicy();
			break;
		case 7:
			cookieOrder();
			break;
		case 8:
			sketchbookOrder();
			break;
		case 9:
			motionBlur();
			break;
		case 10:
			textureSize();
			break;
		case 11:
			fourCalculator();
			break;
		case 12:
			dinoBattle();
			break;
		default:
			break;
		}
	}
	// ---------- UTILITY SELECTION END ----------



	return 0;
}




void judgeNumber()
{
	bool goodEntry = false;

	while (!goodEntry)
	{
		int input = -1;

		prnts("Enter a number from 1 to 100:");

		std::cin >> input;
		//Without both clear and ignore in this order, loop will glitch if a letter is entered
		std::cin.clear();
		std::cin.ignore();

		if (input <= 100 && input >= 1)
		{
			goodEntry = true;

			if (input > 50)
			{
				std::cout << input << "? That's a big number." << std::endl;
			}
			else if (input < 50)
			{
				std::cout << input << "? That's a small number." << std::endl;
			}
			else
			{
				std::cout << "Ah, 50. A fine, balanced number." << std::endl;
			}
		}
		else
		{
			prnts("That is not a number from 1 to 100.");
		}
	}

	pause();
}

void ageGate()
{

	int age = 0;

	prnts("Enter your age:");

	std::cin >> age;

	brk();


	if (age < 0)
	{
		prnts("That is unlikely.");
	}
	else if (age == 0)
	{
		prnts("You are an infant and certainly cannot use a keyboard.");
	}
	else if (age < 18)
	{
		prnts("You are a minor.");
	}
	else if (age >= 18)
	{
		prnts("You are a legal adult.");

		if (age >= 50)
		{
			prnts("You are also eligible to join AARP!");
		}

		if (age >= 65)
		{
			prnts("You are also eligible for retirement benefits!");
		}
	}


	brk();
	pause();

}

void smallestNum()
{
	float a, b, c;
	a = b = c = 0.0f;
	float smallest = 0.0f;

	prnts("Smallest Number: Enter three numbers and the smallest will be printed.");

	prnts("Enter number A:");
	std::cin >> a;
	prnts("Enter number B:");
	std::cin >> b;
	prnts("Enter number C:");
	std::cin >> c;

	smallest = a;
	smallest = (b < smallest) ? b : smallest;
	smallest = (c < smallest) ? c : smallest;

	brk();
	std::cout << "The smallest number you entered was " << smallest << std::endl;


	brk();
	pause();

}

void evenOrOdd()
{
	int input = 0;

	prnts("Enter a whole number. Numbers beyond the decimal will be ignored.");

	//Numbers beyond the decimal are NOT ignored. How do I tell it to ignore them?
	std::cin >> input;

	brk();

	if (input % 2 == 1)
	{
		std::cout << input << " is an odd number." << std::endl;
	}
	else
	{
		std::cout << input << " is an even number." << std::endl;
	}



	brk();
	pause();
}

void clampNum()
{
	int input = 0;

	prnts("Enter a number. It will be clamped to the range 15-30");

	std::cin >> input;

	brk();

	input = (input < 15) ? 15 : input;
	input = (input > 30) ? 30 : input;

	std::cout << "Number is now " << input << std::endl;



	brk();
	pause();
}

void thaiSpicy()
{
	// Field:       Thai Spiciness Rating
	// Constraints: Any number from 0 to 5, inclusive of both ends.
	int thaiSpiceRating = 0;
	prnts("Welcome to the Lucky Elephant! Our food spiciness can be ordered from 0 to 5.");
	prnts("How spicy should your food be?");
	std::cin >> thaiSpiceRating;
	if (thaiSpiceRating > 5) { thaiSpiceRating = 5; }
	else if (thaiSpiceRating < 0) { thaiSpiceRating = 0; }
	std::cout << "You ordered with a spiciness rating of " << thaiSpiceRating << "!\n";

	brk();
	pause();
}

void cookieOrder()
{
	// Field:       Purchase Order for Cookies
	// Constraints: Must be ordered in multiples of 23. Only whole numbers.
	//              Round down to the nearest multiple if not a multiple of 23.
	//
	//              If nearest multiple is zero, provide an error message.
	bool goodInput = false;

	prnts("Please place your order of cookies.");
	prnts("Cookies come in orders of 23. Inexact entries will be rounded down.");
	prnts("Enter 0 to cancel your order.");
	int cookieOrder = 0;
	while (!goodInput)
	{
		std::cin >> cookieOrder;
		brk();

		if (cookieOrder == 0)
		{
			goodInput = true;
			prnts("Your order has been canceled. Please try us again!");
		}
		else if (cookieOrder < 23)
		{
			prnts("Invalid entry. Order must be at least 23. Please try again.");
		}
		else
		{
			goodInput = true;
			cookieOrder /= 23;
			std::cout << "You have ordered " << cookieOrder << " batches of 23 cookies. Thank you!" << std::endl;
		}
	}

	brk();
	pause();
}

void sketchbookOrder()
{
	// Field:       Purchase Order for Sketchbooks (3pk)
	// Constraints: Must order at least 9 sketchbooks total.
	//              The total may not exceed 30 sketchbooks ordered.
	//
	//              If the total number of sketchbooks ordered does not meet
	//              the minimum order count or exceeds the maximum order count,
	//              provide an error message.
	bool goodInput = false;

	prnts("Please place your order of sketchbooks.");
	prnts("Sketchbooks come in 3-packs. Inexact entries will be rounded down.");
	prnts("Orders must be at least 9 and no more than 30.");
	prnts("Enter 0 to cancel your order.");
	int bookOrder = 0;
	while (!goodInput)
	{
		std::cin >> bookOrder;
		brk();

		if (bookOrder == 0)
		{
			goodInput = true;
			prnts("Your order has been canceled. Please try us again!");
		}
		else if (bookOrder < 9 || bookOrder > 30)
		{
			prnts("Invalid entry. Order must be from 9 to 30. Please try again.");
		}
		else
		{
			goodInput = true;
			bookOrder /= 3;
			std::cout << "You have ordered " << bookOrder << " 3-packs of sketchbooks. Thank you!" << std::endl;
		}
	}

	brk();
	pause();
}

void motionBlur()
{
	// Field:       Enable Motion Blur
	// Constraints: Must be a 'y' or 'n' value.
	//
	//              Provide an error message if any other value.
	bool goodInput = false;

	prnts("Would you like to enable hypothetical motion blur?");
	prnts("Enter y or n");
	char input = 0;
	while (!goodInput)
	{
		std::cin >> input;
		brk();

		if (input == 'y')
		{
			goodInput = true;
			prnts("Hypothetical motion blur ENABLED.");
		}
		else if (input == 'n')
		{
			goodInput = true;
			prnts("Hypothetical motion blur DISABLED.");
		}
		else
		{
			prnts("Invalid entry.\nEnter y or n");
		}
	}

	brk();
	pause();
}

void textureSize()
{
	// Field:       Texture Size
	// Constraints: Round to the nearest power of two. Only whole numbers.
	//
	//              If nearest power is zero, provide an error message.
	bool goodInput = false;

	prnts("Enter a texture size.");
	prnts("Texture size will be rounded to nearest power of 2.");
	int input = 0;
	while (!goodInput)
	{
		std::cin >> input;
		brk();


		if (input < 1)
		{
			prnts("Invalid entry, nearest power is less than 1. Please try again.");
		}
		else
		{
			goodInput = true;

			//The following technique, but not code, was taken from this page:
			//https://stackoverflow.com/questions/364985/algorithm-for-finding-the-smallest-power-of-two-thats-greater-or-equal-to-a-giv

			int power = 1;
			int prevPower = power;
			while (power < input)
			{
				prevPower = power;
				power *= 2;
			}

			//Copied technique end

			if (power - input < input - prevPower)
			{
				std::cout << "The nearest power of 2 to " << input << " is " << power << std::endl;
			}
			else
			{
				std::cout << "The nearest power of 2 to " << input << " is " << prevPower << std::endl;
			}
		}
	}

	brk();
	pause();
}

void fourCalculator()
{
	bool goodInput = false;

	prnts("NOW USING CALCULATOR UTILITY");
	prnts("Enter the operator symbol you would like to use from the following list:");
	prnts("+ - Add");
	prnts("- - Subtract");
	prnts("* - Multiply");
	prnts("/ - Divide");
	brk();

	char inOperator = 0;
	int inNum1 = 0;
	int inNum2 = 0;

	while (!goodInput)
	{
		std::cin >> inOperator;

		if (inOperator == '+' || inOperator == '-' || inOperator == '*' || inOperator == '/')
		{
			goodInput = true;
			prnts("Opeartor accepted.");
		}
		else
		{
			prnts("Invalid entry. Valid entries: + - * /");
			prnts("Please try again.");
		}

		brk();
	}

	goodInput = false;

	std::cout << "Enter x in equation: x " << inOperator << " y = z" << std::endl;
	std::cin >> inNum1;
	prnts("Number accepted.");
	brk();

	std::cout << "Enter y in equation: " << inNum1 << " " << inOperator << " y = z" << std::endl;
	while (!goodInput)
	{
		std::cin >> inNum2;

		if (inOperator == '/' && inNum2 == 0)
		{
			prnts("Dividing a number by zero is impossible. Please enter another number.");
		}
		else
		{
			goodInput = true;
			prnts("Number accepted.");
			brk();
		}

		brk();
	}

	int result = 0;
	//No default because it's impossible to have another value
	switch (inOperator)
	{
	case '+':
		result = inNum1 + inNum2;
		break;
	case '-':
		result = inNum1 - inNum2;
		break;
	case '*':
		result = inNum1 * inNum2;
		break;
	case '/':
		result = inNum1 / inNum2;
		break;
	}

	std::cout << "Equation: " << inNum1 << " " << inOperator << " " << inNum2 << " = " << result;



	brk();
	pause();
}

void dinoBattle()
{
	int pPoints = 0;
	int dPoints = 0;
	int input = 0;
	char charInput = 0;
	bool goodInput = false;
	bool helped = false;
	bool prayed = false;


	prnts("You walk into the woods to go hunting for your hungry village.");
	prnts("It is winter and food has grown very scarce.");
	prnts("Along the way you encounter a wounded person from a rival tribe.");
	prnts("You remember that the village priest said to help people no matter who they are.");
	prnts("If you stop to help this enemy, you may not have time to go hunting.");
	prnts("Will you help them? Enter y or n");

	while (!goodInput)
	{
		std::cin >> charInput;
		brk();

		if (charInput == 'y')
		{
			goodInput = true;
			helped = true;
			prnts("You take time to build a small shelter for the rival hunter.");
			prnts("You also make a basic poultice to put on his wounds.");
			prnts("He thanks you and you continue on your way.");
			prnts("The morning has passed, but maybe you'll still find something.");
		}
		else if (charInput == 'n')
		{
			goodInput = true;
			helped = false;
			prnts("You pass the rival hunter by.");
		}
		else
		{
			prnts("Invalid entry.\nEnter y or n");
		}
	}

	brk();
	brk();
	pause();
	brk();
	brk();



	prnts("YOU HAVE ENCOUNTERED A BABY DINOSAUR!");
	prnts("You will soon fight it. Enter your stats and choices to determine the outcome.");
	prnts("A superior stat or good choice will award you a point.");
	prnts("An inferior stat or poor choice will award the dino a point.");
	prnts("Ties will award no points.");

	brk();
	brk();



	prnts("Rate your strength from 1 to 10. It will be clamped to the range if invalid.");

	std::cin >> input;

	brk();

	input = (input < 1) ? 1 : input;
	input = (input > 10) ? 10 : input;

	if (input > 4)
	{
		++pPoints;
		prnts("You are stronger than the dinosaur! You gain a point!");
	}
	else if (input < 4)
	{
		++dPoints;
		prnts("You are weaker than the dinosaur! The dino gains a point!");
	}
	else
	{
		prnts("You and the dinosaur are of equal strength! No points.");
	}
	/*
	std::cout << "Your score is " << pPoints << std::endl;
	std::cout << "The dino's score is " << dPoints << std::endl;

	brk();
	pause();
	brk();
	*/


	prnts("Experience check! How many battles have you fought?");

	input = 0;
	std::cin >> input;

	brk();

	if (input < 0)
	{
		pPoints += 2;
		prnts("You have defied logic itself! You gain 2 points for your awesome powers!");
	}
	else if (input > 2)
	{
		++pPoints;
		prnts("You are more experienced than the dinosaur! You gain a point!");
	}
	else if (input < 2)
	{
		++dPoints;
		prnts("You are less experienced than the dinosaur! The dino gains a point!");
	}
	else
	{
		prnts("You and the dinosaur have equal experience! No points.");
	}
	/*
	std::cout << "Your score is " << pPoints << std::endl;
	std::cout << "The dino's score is " << dPoints << std::endl;

	brk();
	pause();
	brk();
	*/


	prnts("Did you get enough sleep last night?");
	prnts("Enter y or n");
	goodInput = false;
	while (!goodInput)
	{
		std::cin >> charInput;
		brk();

		if (charInput == 'y')
		{
			goodInput = true;
			prnts("Good! You should always get enough sleep. No points.");
		}
		else if (charInput == 'n')
		{
			goodInput = true;
			++dPoints;
			prnts("Oh no! You will enter the battle tired, at a disadvantage! +1 for the dino.");
		}
		else
		{
			prnts("Invalid entry.\nEnter y or n");
		}
	}
	/*
	std::cout << "Your score is " << pPoints << std::endl;
	std::cout << "The dino's score is " << dPoints << std::endl;

	brk();
	pause();
	brk();
	*/


	prnts("How much vitamin C do you get each day (in milligrams)?");

	input = 0;
	std::cin >> input;

	brk();

	if (input < 0)
	{
		dPoints += 2;
		prnts("You are losing vitamin C! +2 points for the dino!");
	}
	else if (input >= 75)
	{
		++pPoints;
		prnts("You getting enough vitamin C! +1 point for you!");
	}
	else if (input < 75)
	{
		++dPoints;
		prnts("You not getting enough vitamin C! +1 point for the dino!");
	}
	/*
	std::cout << "Your score is " << pPoints << std::endl;
	std::cout << "The dino's score is " << dPoints << std::endl;

	brk();
	pause();
	brk();
	*/


	prnts("Would you like to pray to the god-king of your tribe?");
	prnts("Enter y or n");
	goodInput = false;
	charInput = 0;
	while (!goodInput)
	{
		std::cin >> charInput;
		brk();

		if (charInput == 'y')
		{
			goodInput = true;
			prayed = true;
			prnts("You pray. No points.");
		}
		else if (charInput == 'n')
		{
			goodInput = true;
			prayed = false;
			prnts("You don't pray and begin preparing. No points.");
		}
		else
		{
			prnts("Invalid entry.\nEnter y or n");
		}
	}
	/*
	std::cout << "Your score is " << pPoints << std::endl;
	std::cout << "The dino's score is " << dPoints << std::endl;

	brk();
	pause();
	brk();
	*/


	prnts("Choose your equipment! Enter a number from the list.");
	prnts("1) A sack of potatoes.");
	prnts("2) An invisibility cape.");
	prnts("3) The Mango Blade.");

	input = 0;
	goodInput = false;
	while (!goodInput)
	{
		std::cin >> input;
		brk();

		switch (input)
		{
		case 1:
			goodInput = true;
			++dPoints;
			prnts("The dinosaur eats the potatoes and grows stronger! +1 point for the dino!");
			break;
		case 2:
			goodInput = true;
			prnts("The dinosaur can still smell you! No points.");
			break;
		case 3:
			goodInput = true;
			++pPoints;
			prnts("The mysterious blade will be effective against scaly hide! +1 point for you!");
			break;
		default:
			prnts("Invalid entry, please try again.");
			break;
		}
	}
	/*
	std::cout << "Your score is " << pPoints << std::endl;
	std::cout << "The dino's score is " << dPoints << std::endl;

	brk();
	pause();
	brk();
	*/


	prnts("The fight begins!");
	if (prayed && helped)
	{
		prnts("The battle is fierce, but you emerge victorious!");
	}
	else
	{
		if (pPoints > dPoints)
		{
			prnts("The battle is fierce, but you emerge victorious!");
		}
		else if (pPoints < dPoints)
		{
			prnts("The battle is fierce, and the dinosaur defeats you!");
		}
		else
		{
			prnts("You and the dinosaur match each other!");
			prnts("You fight until you are both weary and leave with respect for each other.");
		}
	}



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