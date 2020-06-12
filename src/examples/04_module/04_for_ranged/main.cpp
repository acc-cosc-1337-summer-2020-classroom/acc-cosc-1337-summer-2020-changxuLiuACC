//#include<string> not needed because already done in header file
#include<iostream>
#include "for_ranged.h"

int main() 
{
	std::string name = "John";
	
	loop_string_w_index(name);
	std::cout<<"\n\n";
	loop_string_w_for_range(name);

	return 0;
}