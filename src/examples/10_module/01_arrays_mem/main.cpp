//main
#include<iostream>
#include "arr_functions.h"

using std::cout;	using std::cin;

int main()
{
	//LECTURE 7.7.2020	-----------------------------------------------------------------------------------------------
	//INT ARRAY -------------------------------------------------------------------------------------------------------
	const int SIZE = 3;
	int nums[]{5, 10, 15};		//if you initialize less than the size, rest of the values will be 0
	//if you initialize, and don't put a size in the [ ], then it'll be as big as your initialization

	/*
	for(int i = 0; i < SIZE; ++i)		
	{
		cout<<"Enter value "<<i+1<<": ";
		cin>>nums[i];							//you can use cin to take input into arrays
	}
	*/		//remember to re-end this comment if using
	
	int sum{0};
	for(int i = 0; i < SIZE; ++i)
	{
		cout<<nums[i]<<"\n";
		sum += nums[i];
	}
	//cout<<nums[3]<<"\n";	//if you go past the scope, it'll give some other unknown value
	cout<<sum;
	

	//COPYING AN INT ARRAY ---------------------------------------------------------------------------------------------
	int nums1[SIZE] {5, 10, 15};
	
	for(int i=0; i < SIZE; ++i)
	{
		nums[i] = nums1[i];		//just loop through and assign each index
	}

	//can also be used to compare arrays, find highest/lowest, etc. 


	//STRING ARRAY ----------------------------------------------------------------------------------------------------
	std::string names[SIZE]{"Mary", "John"};		//in this case, indices not initialized would be a blank string ""
	
	for(std::string name: names)	//string with a FOR-EACH loop
	{
		cout<<name<<"\n";
		name = "Modifying the Copy";		//This won't work affect the string unless it's a reference in the for-each
	}


	//SAMPLE PAYROLL --------------------------------------------------------------------------------------------------
	const int SIZE1 = 3;
	std::string name[SIZE];
	int hours[SIZE];
	double pay_rate[SIZE];

	for(int i = 0; i < SIZE; ++i)		//Not an effecitve method to do in real life - difficult to test and maintain
	{
		cout<<"\nEnter Name: ";
		cin>>name[i];
		cout<<"\nEnter Hours: ";		//in reality, these would come from a file
		cin>>hours[i];
		cout<<"\nEnter Rate: ";			//of course I totally work for $2814290.99/hour boss!
		cin>>pay_rate[i];
	}

	auto total_salary{0};
	for(int i = 0; i < SIZE; ++i)
	{
		cout<<names[i]<<" ";
		cout<<hours[i]<<" ";
		cout<<pay_rate[i]<<" ";
		cout<<hours[i] * pay_rate[i]<<" ";

		total_salary += (hours[i] * pay_rate[i]);
	}
	cout<<"\n"<<total_salary;
	//-----------------------------------------------------------------------------------------------------------------

	return 0;
}
