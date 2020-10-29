#include <iostream>
#include "roster.h"
using namespace std;

int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_Lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jorge,Polanco,jpola13@wgu.edu,26,21,30,16,SOFTWARE"
	};

	const int NUM_STUDENTS = 5;
	Roster roster;

	for (int i = 0; i < NUM_STUDENTS; i++) { roster.parse(studentData[i]); }
	cout << "Student Data" << endl;
	roster.printAll();
	cout << endl;

	for (int i = 0; i < 3; i++) {

		cout << "Students by degree program: " << degreeProgramStrings[i] << endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Students with invalid emails: " << endl;
	roster.printInvalidsEmails();
	cout << endl;

	cout << "Average days in course for students:  " << endl;
	for (int i = 0; i < NUM_STUDENTS; i++) {
		roster.printAverageDaysInCourse(roster.classRosterArray[i]->getstudentID());
	}
	cout << endl;

	cout << "Removing student A3 from roster..." << endl;
	roster.remove("A3");
	roster.printAll();
	cout << endl;

	cout << "Removing student A3 from roster..." << endl;
	roster.remove("A3");
	roster.printAll();

	cout << endl;

	return 0;
}