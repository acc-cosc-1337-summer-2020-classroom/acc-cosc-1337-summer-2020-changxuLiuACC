//write include statements
#include "input.h"
#include<iostream>

//write namespace using statements

/*
Capture units and rate values from keyboard.
Call the get_total function by passing units and rates variables to it.
Save the get_total return value to a variable named total.
Display the total:

Total: 100

*/

using std::cout;	//this way the compiler knows we're using the std cout object below.
using std::cin;

int main() 
{
	int units;
	double rate;
	cout<<"Enter units: ";
	//  ^notice the errors, that's the direction the data stream moves
	//   it's a stream insertion operator
	cin>>units;
	cout<<"Enter rate: ";
	cin>>rate;

	double total = get_total(units, rate);		//we could have created this variable above, but it's best practice to 
	//create the variables where we need them

	cout<<"Total: "<<total;
	
	return 0;
}