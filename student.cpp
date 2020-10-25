#pragma once
#include "student.h"
using namespace std;

Student::Student() {

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) { this->daysArray[i] = 0; }
	/* An 'empty' would help in the DegreePrograms enum for this constructor*/
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) { this->daysArray[i] = days[i]; }
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getstudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->daysArray; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[]) {
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) { this->daysArray[i] = days[i]; }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; };

void Student::printTableColumnHeaders() {

	cout << "Student ID | First Name | Last Name | Email | Age | Days In Course | Degree Program" << endl;
}

void Student::print() {
	
	cout << this->getstudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ", ";
	cout << this->getDays()[1] << ", ";
	cout << this->getDays()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << endl;
}

bool Student::hasInvalidEmail() {
	if (Student::getEmail().find('@') == string::npos || Student::getEmail().find(' ') != string::npos ||
		Student::getEmail().find('.') == string::npos) {
		return true;
	}
	else return false;
}

double Student::averageDaysInCourse() {

	return (Student::getDays()[0] + Student::getDays()[1] + Student::getDays()[2]) / 3.0;
}

