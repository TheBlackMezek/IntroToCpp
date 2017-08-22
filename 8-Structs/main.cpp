
#include <iostream>
#include <time.h>

#include "coututils.h"
#include "mathutils.h"

#include "piggyBank.h"
#include "student.h"
#include "vector2.h"
#include "fighter.h"






int main()
{
	srand(time(NULL));


	piggyBank bank{ 10, 5, 2, 24, 5, 34, 2 };
	prntf(calcPiggybankCoins(bank));
	prntf(calcPiggybankNotes(bank));
	prntf(calcPiggybankTotal(bank));
	brk();
	pause();

	student s{ 179069, 2, 96 };
	prntStudentData(s);
	brk();
	pause();

	student ss[]{
		{ 179069, 2, 96 },
		{ 184939, 1, 15 },
		{ 149381, 2, 69 },
		{ 118382, 2, 92 },
		{ 100039, 1, 100 },
		{ 103929, 2, 59 }
	};
	prntAvgStudentScore(ss, 6);
	prntMedianStudentScore(ss, 6);
	prntStudentsInCourse(ss, 6, 1);
	prntStudentsInCourse(ss, 6, 2);
	brk();
	pause();

	vec2 v1{ 5, 10 };
	vec2 v2{ 20, 19 };
	vec2 vt = affineSum(v1, v2);
	std::cout << vt.x << ", " << vt.y << std::endl;
	vec2 difference = vecDiff(v1, v2);
	std::cout << difference.x << ", " << difference.y << std::endl;
	prntf(vecDist(v1, v2));
	brk();
	pause();

	fighter human{ 10, 2, 2 };
	fighter zombie{ 20, 3, 1 };
	while (human.hp > 0 && zombie.hp > 0)
	{
		std::cout << "Human hits the zombie for " << human.att - zombie.def << "!\n";
		zombie = hit(zombie, human.att);
		std::cout << "Zombie has " << zombie.hp << " hp left!\n";
		brk();
		std::cout << "Zombie hits the human for " << zombie.att - human.def << "!\n";
		human = hit(human, zombie.att);
		std::cout << "Human has " << human.hp << " hp left!\n";
		brk();
		pause();
	}



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
		brk();

		std::cin >> selectionInput;
		std::cin.clear();
		std::cin.ignore();

		brk();
		brk();
		brk();

		int tempArray[]{ 1, 34,-234, 12342, 23 };

		switch (selectionInput)
		{
		case 1:
			//prntArray(tempArray, 5);
			break;
		default:
			break;
		}
	}
	// ---------- UTILITY SELECTION END ----------



	return 0;
}