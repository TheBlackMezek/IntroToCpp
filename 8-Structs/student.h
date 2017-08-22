#pragma once


struct student
{
	int id;
	int course;
	int lastExamScore;
};


void prntStudentData(student s);

void prntAvgStudentScore(student s[], int size);

void prntMedianStudentScore(student s[], int size);

void prntStudentsInCourse(student s[], int size, int course);