#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student {

public:
	const static int DAYS_ARRAY_SIZE = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysArray[DAYS_ARRAY_SIZE];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
	~Student();
	bool hasInvalidEmail();
	double averageDaysInCourse();

	string getstudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printTableColumnHeaders();

	void print();
};