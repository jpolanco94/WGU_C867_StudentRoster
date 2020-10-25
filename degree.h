#pragma once
#include <iostream>
using namespace std;

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

/* Enums help throughout the program in assigning constant values to variables
For real world applications I would have another value in the enum for students that
may not have a set degree program. This helps for parameterless constructors and for 
making sure thatthere are no null values in this program */

static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
