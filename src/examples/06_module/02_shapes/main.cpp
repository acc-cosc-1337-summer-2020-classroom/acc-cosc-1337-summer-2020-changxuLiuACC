//main
#include <iostream>
#include<memory>
#include<vector>
#include "shape.h"
#include "line.h"
#include "circle.h"

/*
Create a Shape pointer of type Line
Create vector of Shape pointers
iterate with auto
*/

using std::unique_ptr;	using std::make_unique;

int main() 
{
	//LECTURE 6.30.2020		ABSTRACT/CONCRETE CLASSES, VIRTUAL FUNCTIONS/POLYMORPHISM, PURE VIRTUAL FUNCTIONS
	//unique_ptr<Shape> shape = make_unique<Shape>();	//with shape being an abstract class (with the pure virtual function in the class), can't create an instance of it
	unique_ptr<Shape> line = make_unique<Line>();		//pointer of shape to instance of line
	unique_ptr<Shape> circle = make_unique<Circle>();
	//line and circle are CONCRETE CLASSES, while shape is an ABSTRACT CLASS (that we shouldn't allow instantiation of)
	//usually derived classes ^ 			usually base classes ^

	//shape->draw();
	line->draw();
	circle->draw();
	

	/*	//LECTURE 6.30.2020		REFERENCES and POINTERS		----------------------------------------------------------------------------------------------
	//C++ 98 had to use pointers in order to allocate memory dynamically and then must delete that memory manually after
	//String and vector are already sort of smart pointers - they allocate memory dynamically (into the heap) and deallocate (remove from heap)
	//Memory leaks: memory created, used, but not deleted (smart pointers help mitigate this)

	//REFERENCES refer to another variable (its original, not a copy)	-----------------------------------------------------------------------------------
	int num;
	int& num_ref = num;		//stores the address of num - modifies/reads the original num variable value in its location in memory
	//these can only be assigned one time
	std::cout<<num_ref<<"\n";		//prints out the value of num as num_ref references the original, not a copy 
	//almost like an alternative name for the same variable

	//raw POINTERS point to the address (stores the location that a variable/object takes up in memory) - no protection against memory leaks	-----------
	int num1;
	int* num_ptr = &num1;		//pointer to the address of num1 (num_ptr would be the address of num1, *num_ptr would be the value of num1 in memory)
	
	std::cout<<"Address of num1: "<<num_ptr<<"\n";		//prints out the address of num1
	std::cout<<"Value of num1 (through original variable): "<<num1<<"\n";
	std::cout<<"Value of num1 (through pointer with dereference operator): "<<*num_ptr<<"\n";		//prints out the value at that address (where num1 is)

	int num2;
	num_ptr = &num2;	//can be reassigned
	std::cout<<num_ptr<<"\n";

	//The above here are stored on the stack, NONE OF THIS SO FAR IS ONE THE HEAP

	//DYNAMIC MEMORY with the NEW keyword	---------------------------------------------------------------------------------------------------------------
	int* num_dm = new int;
	//			   ^ new creates memory on the heap; dynamic memory
	std::cout<<"Address: "<<num_dm;
	std::cout<<"Value (derefenced the pointer): "<<*num_dm;

	//delete/remove memory
	delete num_dm;
	num_dm = nullptr;	//prevent dangling pointer and make clear that num_dm isn't pointing to anything anymore

	//delete num1;		 isn't possible as it's stored on the stack, not the heap - not dynamic memory 
	-----------------------------------------------------------------------------------------------------------------------------------------------		*/

	return 0;
}
