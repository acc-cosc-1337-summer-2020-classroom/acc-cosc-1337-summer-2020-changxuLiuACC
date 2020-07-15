//main
#include "ref_pointers.h"
#include<iostream>

using std::cout;

int main() 
{
	//LECTURE 7.7.2020	MEMORY LEAKS and DANGLING POINTERS	-------------------------------------------------------------------------------------
	//MEMORY LEAKS - when we make a raw pointer but dont' delete it (leading to memory fill-up)
	//can be prevented with classes (will go over in a later class)
	int* valid_ptr = get_int_pointer();
	int* dangling_ptr = valid_ptr;

	delete valid_ptr;	//remember to delete to avoid memory leaks
	valid_ptr = nullptr;

	cout<<*dangling_ptr;	//will give bad data because the memory address it had been assigned to has been deleted - DANGLING POINTER
	dangling_ptr = nullptr;		//set pointers to deleted memory to nullptr (nullify) to prevent dangling pointer

	//using unique_ptr: won't have to worry about either of these, but with raw pointers, we do
	//--------------------------------------------------------------------------------------------------------------------------------------------	*/

	/*	//LECTURE 7.2.2020	RETURNING A POINTER from a FUNCTION		---------------------------------------------------------------------------------
	//with problem code
	int* invalid_ptr = get_int_pointer();
	cout<<"Invalid pointer: "<<*invalid_ptr<<"\n";
	cout<<"Invalid pointer: "<<invalid_ptr<<"\n";
	*invalid_ptr = 10;				//this shouldn't be working, WHY IS IT WORKING!?! (don't do this though)

	//fixed with DYNAMIC MEMORY (HEAP)
	//same main.cpp code as above, just pretend the word Invalid is now Vlid (code change in function definition)

	//DANGLING POINTER: when two pointers point to dynamic memory and then we delete the memory, but a pointer still points to it (opposite of a memory leak)
	int* dangling_ptr = invalid_ptr;

	delete invalid_ptr;		//DELETE THE MEMORY at n/invalid_ptr now that we're done - otherwise we could fill up the heap and crash the program
	invalid_ptr = nullptr;	//(you don't have to do this with unique_ptr though)

	cout<<*dangling_ptr;		//memory has already been deleted - invalid data (DANGLING POINTER)

	dangling_ptr = nullptr;		//fixing the dangling pointer
	//--------------------------------------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 7.2.2020	REFERENCES vs. POINTERS		-------------------------------------------------------------------------------------------
	int num{10};
	int& num_ref = num;		//REFERENCE

	cout<<"Value of num: "<<num<<"\n";
	cout<<"Address of num: "<<&num<<"\n";
	cout<<"Address of num via num_ref: "<<num_ref<<"\n";
	cout<<"Address of num_ref: "<<&num_ref<<"\n";		//address will be same as that of num as it's a reference
	num_ref = 15;
	cout<<"New value of num: "<<num<<"\n";		//because it's a reference to the original address in memory, num changes as well to 15
	//remember, references can't be reassigned

	auto x{5};
	auto* ptr = &x;		//POINTER (assigned the address of x to point there)
	cout<<"\nValue of x: "<<x<<"\n";
	cout<<"Address of x: "<<&x<<"\n";
	cout<<"Address of x: "<<ptr<<"\n";		//notice &x = address of x = ptr (we assigned it to point to that same address)
	cout<<"Value of x via ptr: "<<*ptr<<"\n";		//same as x with dereference operator
	*ptr = 20;
	cout<<"New value of x: "<<x<<"\n";		//modifies the original value as it points to the original memory address
	//unlike references though, pointers can be reassigned (and can use dynamic memory - covered later)

	//see example on passing into functions in the .h/.cpp files and test case

	//SO FAR, ONLY STACK MEMORY (NON-DYNAMIC) HAS BEEN USED
	------------------------------------------------------------------------------------------------------------------------------------	*/

	//int x = 7;
	//int* ptr = &x;
	//cout<<ptr;

	return 0;
}
