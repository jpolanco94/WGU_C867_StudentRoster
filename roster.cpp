#pragma once
#include "roster.h"
#include <string>
#include "student.h"
using namespace std;

void Roster::parse(string studentData) {

	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);


	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string email = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string degreeProgramString = studentData.substr(lhs, rhs - lhs);


	DegreeProgram degreeProgram;
	if (degreeProgramString == "SECURITY") { degreeProgram = SECURITY; }
	if (degreeProgramString == "SOFTWARE") { degreeProgram = SOFTWARE; }
	if (degreeProgramString == "NETWORK") { degreeProgram = NETWORK; }

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeProgram) {

	int daysInCourseArray[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourseArray, degreeProgram);
}

void Roster::printAll() {

	Student::printTableColumnHeaders();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	Student::printTableColumnHeaders();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) { classRosterArray[i]->print(); }
	}
	cout << endl;
}

void Roster::printInvalidsEmails() {

	bool hasInvalidEmail = false;
	for (int i = 0; i < Roster::lastIndex; i++) {
		if (classRosterArray[i]->hasInvalidEmail() == true){
			cout << classRosterArray[i]->getFirstName() << " ";
			cout << classRosterArray[i]->getLastName() << " has an invalid email of: " << classRosterArray[i]->getEmail() << endl;
			hasInvalidEmail = true;
		}
	}
	if (!hasInvalidEmail) { cout << "No Invalid Emails" << endl; }
}

void Roster::printAverageDaysInCourse(string studentID) {

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getstudentID() == studentID) {
			cout << classRosterArray[i]->getstudentID() << ":" << classRosterArray[i]->averageDaysInCourse() << endl;
		}
	}
}

void Roster::remove(string studentID) {

	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {

		if (classRosterArray[i]->getstudentID() == studentID) {
			success = true;
			if (i < NUM_STUDENTS - 1) {
				
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[NUM_STUDENTS - 1];
				classRosterArray[NUM_STUDENTS - 1] = temp;
			}

			Roster::lastIndex--;
		}
	}
	if (success) {
		cout << studentID << " was removed from the roster." << endl << endl;
	}
	else cout << studentID << " not found" << endl << endl;

}

Roster::~Roster() {
	
	for (int i = 0; i < NUM_STUDENTS; i++) {
		cout << "Destructing student number " << i + 1 << "." << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
