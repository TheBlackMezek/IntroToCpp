
#include <iostream>
#include <string>
#include <time.h>



std::string removeSpaces(std::string s);

bool isPalindrome(std::string s);

std::string lowerCase(std::string s);

std::string pigLatin(std::string s);

std::string makeTitle(std::string first, std::string last);




int numOfTitles = 2;
std::string titles[]{
	"1 2 the Great",
	"1 of the 2 clan"
};



int main()
{
	srand(time(NULL));


	char name[80];
	name[79] = 0;
	char lastname[80];
	lastname[79] = 0;
	char color[80];
	color[79] = 0;
	char nowhite[80];
	nowhite[79] = 0;
	std::string test = "";

	std::cout << "Enter a few words:\n";

	std::getline(std::cin, test);

	std::cout << "Enter your first name:\n";

	std::cin >> name;

	std::cout << "Enter your last first name:\n";

	std::cin >> lastname;

	std::cout << "Enter your favorite color:\n";

	std::cin >> color;





	std::cout << "Hello " << name << "!\n";

	if (strstr(color, "red"))
	{
		std::cout << "Red is a vibrant color!\n";
	}
	else
	{
		std::cout << "Your favorite color is a color! Probably. I'm just a string.\n";
	}

	test = removeSpaces(test);

	std::cout << test << "\n";

	std::cout << isPalindrome(test) << std::endl;

	std::cout << pigLatin(test) << std::endl;

	std::cout << makeTitle(name, lastname) << std::endl;

	system("pause");





	return 0;
}


std::string removeSpaces(std::string s)
{
	while (s.find_first_of(' ') != s.npos)
	{
		s.replace(s.find_first_of(' '), 1, "");
	}
	return s;
}

bool isPalindrome(std::string s)
{
	s = removeSpaces(s);
	s = lowerCase(s);

	bool ret = true;
	for (int i = 0; i < (s.size() / 2) + (s.size() % 2); ++i)
	{
		if (s.at(i) != s.at(s.size() - 1 - i))
		{
			ret = false;
			break;
		}
	}
	return ret;
}

std::string lowerCase(std::string s)
{
	while (s.find_first_of('A') != s.npos)
	{
		s.replace(s.find_first_of('A'), 1, "a");
	}
	while (s.find_first_of('B') != s.npos)
	{
		s.replace(s.find_first_of('B'), 1, "b");
	}
	while (s.find_first_of('C') != s.npos)
	{
		s.replace(s.find_first_of('C'), 1, "c");
	}
	while (s.find_first_of('D') != s.npos)
	{
		s.replace(s.find_first_of('D'), 1, "d");
	}
	while (s.find_first_of('E') != s.npos)
	{
		s.replace(s.find_first_of('E'), 1, "e");
	}
	while (s.find_first_of('F') != s.npos)
	{
		s.replace(s.find_first_of('F'), 1, "f");
	}
	while (s.find_first_of('G') != s.npos)
	{
		s.replace(s.find_first_of('G'), 1, "g");
	}
	while (s.find_first_of('H') != s.npos)
	{
		s.replace(s.find_first_of('H'), 1, "h");
	}
	while (s.find_first_of('I') != s.npos)
	{
		s.replace(s.find_first_of('I'), 1, "i");
	}
	while (s.find_first_of('J') != s.npos)
	{
		s.replace(s.find_first_of('J'), 1, "j");
	}
	while (s.find_first_of('K') != s.npos)
	{
		s.replace(s.find_first_of('K'), 1, "k");
	}
	while (s.find_first_of('L') != s.npos)
	{
		s.replace(s.find_first_of('L'), 1, "l");
	}
	while (s.find_first_of('M') != s.npos)
	{
		s.replace(s.find_first_of('M'), 1, "m");
	}
	while (s.find_first_of('N') != s.npos)
	{
		s.replace(s.find_first_of('N'), 1, "n");
	}
	while (s.find_first_of('O') != s.npos)
	{
		s.replace(s.find_first_of('O'), 1, "o");
	}
	while (s.find_first_of('P') != s.npos)
	{
		s.replace(s.find_first_of('P'), 1, "p");
	}
	while (s.find_first_of('Q') != s.npos)
	{
		s.replace(s.find_first_of('Q'), 1, "q");
	}
	while (s.find_first_of('R') != s.npos)
	{
		s.replace(s.find_first_of('R'), 1, "r");
	}
	while (s.find_first_of('S') != s.npos)
	{
		s.replace(s.find_first_of('S'), 1, "s");
	}
	while (s.find_first_of('T') != s.npos)
	{
		s.replace(s.find_first_of('T'), 1, "t");
	}
	while (s.find_first_of('U') != s.npos)
	{
		s.replace(s.find_first_of('U'), 1, "u");
	}
	while (s.find_first_of('V') != s.npos)
	{
		s.replace(s.find_first_of('V'), 1, "v");
	}
	while (s.find_first_of('W') != s.npos)
	{
		s.replace(s.find_first_of('W'), 1, "w");
	}
	while (s.find_first_of('X') != s.npos)
	{
		s.replace(s.find_first_of('X'), 1, "x");
	}
	while (s.find_first_of('Y') != s.npos)
	{
		s.replace(s.find_first_of('Y'), 1, "y");
	}
	while (s.find_first_of('Z') != s.npos)
	{
		s.replace(s.find_first_of('Z'), 1, "z");
	}



	return s;
}

std::string pigLatin(std::string s)
{
	lowerCase(s);
	bool startsWithVowel = true;
	while (s.at(0) != 'a' && s.at(0) != 'e' && s.at(0) != 'i' && s.at(0) != 'o' && s.at(0) != 'u')
	{
		startsWithVowel = false;
		s = s.substr(1, s.npos) + s.at(0);
	}

	if (startsWithVowel)
	{
		s.append("ay");
	}
	else
	{
		s.append("a");
	}

	return s;
}

std::string makeTitle(std::string first, std::string last)
{
	std::string ret = titles[rand() % numOfTitles];
	ret.replace(ret.find_first_of('1'), 1, first);
	ret.replace(ret.find_first_of('2'), 1, last);
	return ret;
}
