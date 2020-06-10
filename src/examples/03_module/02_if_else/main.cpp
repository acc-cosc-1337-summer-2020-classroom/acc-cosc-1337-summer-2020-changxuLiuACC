//write include statements
#include "if_else.h"
#include<iostream>
//#include<string>

//write cin and cout using statements
using std::cout;
using std::cin;

/*
Write code to capture year from keyboard.
Pass the year to get_generation function and display function result.
*/
int main() 
{
	auto year = 1900;
	cout<<"Enter Year: ";
	cin>>year;

	std::string result = get_generation(year);
	cout<<"Generation is: "<<result;

	return 0;
}