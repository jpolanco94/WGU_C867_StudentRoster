#pragma once
#include "student.h"

class Roster {

private:
	int lastIndex = -1;
	const static int NUM_STUDENTS = 5;
	Student* classRosterArray[NUM_STUDENTS];

public:

	void parse(string studentData);
	void add(string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse();
	void printInvalidsEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};
