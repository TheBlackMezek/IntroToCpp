
#include "coututils.h"

#include <iostream>



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
	//I read that system() is ridiculously resource intensive, and
	//OS specific, and that I should use cin.get() instead.
	std::cout << "Press Enter to continue...";
	std::cin.get();
	//Use ignore() to clear the buffer. Why is this important maintenance?
	std::cin.ignore();
	//system("pause");
}