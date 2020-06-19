#include<iostream>
#include<string>
#include<iomanip>	//used for formatting the final result
using std::cout; using std::cin; using std::string;
using std::fixed;	using std::setprecision;	//used for formatting the final result
//write include statements
#include "decisions.h"

/*
In main write code to capture a letter_grade and credit_hours from the keyboard:


Grade   Credit Hours	grade_points   credit_points
A          3            4              12
B          3            3               9
C          3            2               6
-----------------------------------------------
           9                           27
After each user input convert the Grade to grade points by calling the get_grade_points function, and
keep a running total for both credit_points and credit_hours.

Call the calculate_gpa function with its arguments.
The GPA should calculate to 3.0, make sure to display it before program exits.

Display:
GPA 3.0

*/
int main() 
{
	string letter_grade;
	int credit_hours, sum_credit_hours = 0, sum_credit_points = 0;

	char choice;	//used to determine when data entry is complete on letter grade and credit hours

	do
	{
		cout << "\nEnter letter grade: ";
		cin >> letter_grade;
		cout << "Enter credit hours: ";
		cin >> credit_hours;
		sum_credit_points += get_grade_points(letter_grade) * credit_hours;
		sum_credit_hours += credit_hours;
        cout<<"Enter 'Y' or 'y' to continue inputting additional grade data: ";
        cin>>choice;
	}	
	while(choice == 'y' || choice == 'Y');
	//the do while will run until the user is done entering data, signified by entering a 
	//character other than 'y' or 'Y' at the end

	//gpa calculations after all data is entered (do-while above ends)
	double gpa = calculate_gpa(sum_credit_hours, sum_credit_points);
	//your example gave 2 decimal points in the Blackboard assignment, so formatting added
	cout << "\nGPA: " << fixed << setprecision(2) << gpa << "\n";

	return 0;
}