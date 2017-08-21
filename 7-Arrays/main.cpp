
#include <iostream>
#include <time.h>

#include "coututils.h"
#include "mathutils.h"



void prntArray(int nums[], int size);
int sumArray(int nums[], int size);
int smallestInArray(int nums[], int size);
int biggestInArray(int nums[], int size);
int getIndexInArray(int nums[], int size, int val);
bool isArrayUnique(int nums[], int size);
void reverseArray(int nums[], int size);
void sortAscending(int nums[], int size);
void sortDescending(int nums[], int size);



int main()
{
	srand(time(NULL));


	



	// ---------- UTILITY SELECTION BEGIN ----------
	int selectionInput = -1;

	while (selectionInput != 0)
	{
		brk();
		brk();
		brk();

		prnts("SELECT PROGRAM UTILITY");
		prnts("Enter 0 to exit");
		prnts("Enter 1 for Print Array");
		prnts("Enter 2 for Print Array Sum");
		prnts("Enter 3 for Smallest In Array");
		prnts("Enter 4 for Biggest In Array");
		prnts("Enter 5 for Index Of 34");
		prnts("Enter 6 for Are Array Elements All Unique");
		prnts("Enter 7 for Reverse Array");
		prnts("Enter 8 for Sort By Ascending");
		prnts("Enter 9 for Sort By Descending");
		brk();

		std::cin >> selectionInput;
		std::cin.clear();
		std::cin.ignore();

		brk();
		brk();
		brk();

		int tempArray[] { 1, 34,-234, 12342, 23 };

		switch (selectionInput)
		{
		case 1:
			prntArray(tempArray, 5);
			break;
		case 2:
			prnti(sumArray(tempArray, 5));
			break;
		case 3:
			prnti(smallestInArray(tempArray, 5));
			break;
		case 4:
			prnti(biggestInArray(tempArray, 5));
			break;
		case 5:
			prnti(getIndexInArray(tempArray, 5, 34));
			break;
		case 6:
			prnti(isArrayUnique(tempArray, 5));
			break;
		case 7:
			reverseArray(tempArray, 5);
			prntArray(tempArray, 5);
			break;
		case 8:
			sortAscending(tempArray, 5);
			prntArray(tempArray, 5);
			break;
		case 9:
			sortDescending(tempArray, 5);
			prntArray(tempArray, 5);
			break;
		default:
			break;
		}
	}
	// ---------- UTILITY SELECTION END ----------



	return 0;
}




void prntArray(int nums[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		prnti(nums[i]);
	}
}

int sumArray(int nums[], int size)
{
	int ret = 0;

	for (int i = 0; i < size; ++i)
	{
		ret += nums[i];
	}

	return ret;
}

int smallestInArray(int nums[], int size)
{
	int ret = nums[0];

	for (int i = 0; i < size; ++i)
	{
		ret = (nums[i] < ret) ? nums[i] : ret;
	}

	return ret;
}

int biggestInArray(int nums[], int size)
{
	int ret = nums[0];

	for (int i = 0; i < size; ++i)
	{
		ret = (nums[i] > ret) ? nums[i] : ret;
	}

	return ret;
}

int getIndexInArray(int nums[], int size, int val)
{
	int ret = -1;

	for (int i = 0; i < size; ++i)
	{
		ret = (nums[i] == val) ? i : ret;
	}

	return ret;
}

bool isArrayUnique(int nums[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int n = 0; n < size; ++n)
		{
			if (i != n && nums[i] == nums[n])
			{
				return false;
			}
		}
	}

	return true;
}

void reverseArray(int nums[], int size)
{
	int temp = 0;

	for (int i = 0; i < size / 2; ++i)
	{
		temp = nums[size - 1 - i];
		nums[size - 1 - i] = nums[i];
		nums[i] = temp;
	}
}

void sortAscending(int nums[], int size)
{
	int temp = 0;

	for (int n = 0; n < size; ++n)
	{
		for (int i = 0; i < size - 1; ++i)
		{
			if (nums[i] > nums[i + 1])
			{
				temp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
			}
		}
	}
}

void sortDescending(int nums[], int size)
{
	int temp = 0;

	for (int n = 0; n < size; ++n)
	{
		for (int i = 0; i < size - 1; ++i)
		{
			if (nums[i] < nums[i + 1])
			{
				temp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
			}
		}
	}
}