

#include "student.h"

#include <iostream>



void prntStudentData(student s)
{
	std::cout << "Student ID: " << s.id << std::endl;
	std::cout << "Course enrolled in: " << s.course << std::endl;
	std::cout << "Last exam score: " << s.lastExamScore << std::endl;
}

void prntAvgStudentScore(student s[], int size)
{
	int total = 0;
	for (int i = 0; i < size; ++i)
	{
		total += s[i].lastExamScore;
	}
	std::cout << "The average score on the last exam was " << total / size << std::endl;
}

void prntMedianStudentScore(student s[], int size)
{
	float median;
	if (size % 2 == 0)
	{
		median = (s[size / 2].lastExamScore + s[size / 2 + 1].lastExamScore) / 2.0f;
	}
	else
	{
		median = s[size / 2 + 1].lastExamScore;
	}
	std::cout << "The median score on the last exam was " << median << std::endl;
}

void prntStudentsInCourse(student s[], int size, int course)
{
	int total = 0;
	for (int i = 0; i < size; ++i)
	{
		if (s[i].course == course)
		{
			++total;
		}
	}
	std::cout << "The total number of students in course " << course << " is " << total << std::endl;
}