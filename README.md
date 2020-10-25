# WGU C867 StudentRoster

## Performance Assessment Scenario
<p> You are hired as a contractor to help a university migrate an existing student system to a new platform using C++ language.
Since the application already exists, its requirements exist as well, and they are outlined in the next section. 
You are responsible for implementing the part of the system based on these requirements. 
A list of data is provided as part of these requirements. This part of the system is responsible for reading and manipulating the provided data. </p>

<p> You must write a program containing two classes (i.e., Student and Roster). The program will maintain a current roster of students within a given course. 
Student data for the program include student ID, first name, last name, email address, age, an array of the number of days to complete each course, and degree program. 
This information can be found in the “studentData Table” below. The program will read a list of five students and use function calls to manipulate data 
(see part F4 in the requirements below). While parsing the list of data, the program should create student objects. 
The entire student list will be stored in one array of students called classRosterArray. Specific data-related output will be directed to the console. </p>

## README.md Structure
<p> I will go through the six required files for this assignment and explain what each is doing and my reasoning behind it.</p>

## main.cpp
<p>The main.cpp is where the int main() function lives. The int main() function is a special function that is called when the program is run. 
It holds all the code I want to be executed. The int main() function does not have to be in the main.cpp file but it lets other readers of this code 
know where the program is being executed</p>

## degree.h
<p>The degree.h contains the DegreeProgram enum, which contains SECURITY, NETWORK, and SOFTWARE. These values are just stand-ins for integers, meaning that 
SECURITY holds the value of 0, NETWORK holds the value of 1, and SOFTWARE holds the value of 2. There is also a string array similar to the enum in this file.
This is used to display the degrees as strings rather than as integers when they are printed. I use this by assigning a student a enum value. When I want to print his degree
I pass that enum value into the string array in order to get a string value
</p>

<p>In a real world application, I would have added another enum value that represents null or empty. This is better than having a null value for a student's degree type.</p>
