//main
#include<iostream>

using std::cout;

int main() 
{
	//LECTURE 7.14.2020
	const int SIZE = 3;
	int nums[SIZE]{10, 20, 30};

	int* nums_ptr = nums;	//pointer to the (first element of) nums array
	
	/*
	cout<<*nums_ptr<<"\n";	//will print out the first element - 10
	nums_ptr++;				//navigates the pointer to the next element
	cout<<*nums_ptr<<"\n";	//will print out the second element now - 20
	nums_ptr++;
	cout<<*nums_ptr<<"\n";	//30
	*/

	for(int i = 0; i < SIZE; ++i)
	{
		cout<<*nums_ptr<<"\n";
		nums_ptr++;
	}

	for(int i = 0; i < SIZE; ++i)
	{
		nums_ptr--;		//decrementing first because it has already gone past the size of the array in the previous loop
		cout<<*nums_ptr<<"\n";
	}

	return 0;
}