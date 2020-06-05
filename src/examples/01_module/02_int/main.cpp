#include "vars.h"
#include<iostream>

int main() 
{
	int result = echo_variable(10);		//the variable result will be the return of echo_variable with parameter 10
	//it'll scan our code for the echo variable function and then run the code in there

	std::cout<<"Result: "<<result;
	//			^literal	^variable

	return 0;
}