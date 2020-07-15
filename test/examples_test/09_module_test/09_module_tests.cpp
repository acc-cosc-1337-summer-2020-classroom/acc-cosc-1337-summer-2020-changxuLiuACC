#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "types.h"
#include "ref_pointers.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

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
