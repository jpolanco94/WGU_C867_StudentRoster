#pragma once

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

/* Enums help throughout the program in assigning constant values to variables
For real world applications I would have another value in the enum for students that
may not have a set degree program. This helps for parameterless constructors and for 
making sure that there are no null values in this program */

static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
