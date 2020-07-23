#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "types.h"
#include "ref_pointers.h"
#include "vector.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

//06_vector
TEST_CASE("Test vector size stack variable for copies (FIG 1)")
{
	Vector v1(3);
	Vector v2 = v1;

	REQUIRE(v1.Size() == v2.Size());	
	//if size was in the heap instead, when copying, it would still probably to point to the same value (not making a copy) - see test case below this one

	/*	JUST FOR DEMONSTRATION
	v1.set_size(4);
	REQUIRE(v1.Size() == 4);
	REQUIRE(v2.Size() == 3);	//make sure they're not pointing to the same memory, but made a copy
	*/
}

TEST_CASE("Test vector heap variables for copies (FIG 2 - 3)")
{
	Vector v1(3);
	Vector v2 = v1;

	REQUIRE(v1[1] == v2[1]);
	v1[1] = 4;
	//without copy constructor, this will fail
	REQUIRE(v1[1] != v2[1]);	//FIG 2 - this is set to fail, to show that they're still pointing to the same value (only one private member array, not two, in heap)
														//so as a result, these are both pointing to a value 5
	//now that we've added a copy constructor, they point to separate memory, so this passes now
}

TEST_CASE("Test vector copy assignment from existing instances (FIG 4)")
{
	Vector v1(3);
	Vector v2(3);
	//v2 = v1;		//this causes a memory leak (FIG 4), however fixed with the =operator copy assingment constructor in =operator (FIG 5)

	v1[0] = 1;
	REQUIRE(v1[0] != v2[0]);

	v2 = v1;
	REQUIRE(v1[0] == v2[0]);	//should fail, as without = overloading, it points to the same memory locations as v1 for v1's elements (it didn't create a copy, just pointing to the same things)
								//fixed with =operator function for operator overloading

	//v1[2];			//by overloading the subscript operator, we can now use it like this to access/modify values
	v1[0] = 5;
	REQUIRE(v1[0] != v2[0]);	//this should pass if we made a copy by = above correctly
}


//SOME OTHER MODULE
/*
TEST_CASE("Function value, refernce, pointer, pointer constant")
{
	int n1 = 1, n2 = 3, n3 = 3, n4 = 4;

	val_ref_ptr_cptr(n1, n2, &n3, &n4);
	//						  ^    ^ pass in the address to point to for pointers

	REQUIRE(n1 == 1);	//doesn't change as pass by value makes a copy			    (1  -/>  0)
	REQUIRE(n2 == 5);	//changes as it was a reference to the original	  			(3  ->  5)
	REQUIRE(n3 == 10);	//changes as pointers point to the original memory address  (3  ->  10)
	REQUIRE(n4 == 4);	//doesn't change as can't change a const					(4  -/>  20) 	commented out in function definition to prevent errors
	
}
*/
