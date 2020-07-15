#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "arr_functions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test display array, array parameter modifiable")
{
	double grades[]{70, 80, 90};
	double expected_grades[]{70, 80, 90};
	display_array(grades, 3);

	for(int i = 0; i < 3; ++i)
	{
		REQUIRE(grades[i] == expected_grades[i]);
	}

}

TEST_CASE("Test get_average array function")
{
	double grades[]{70, 80, 90};

	REQUIRE(get_average(grades, 3) == 80);
}
