
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
	system("pause");
}