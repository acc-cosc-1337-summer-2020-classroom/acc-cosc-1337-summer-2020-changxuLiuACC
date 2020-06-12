#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "variables.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test get_sales_tax_amount")
{
	//verify meal_amount of 10 returns sales tax of 0.675 (1b)
	REQUIRE(get_sales_tax_amount(10) == 0.675);
	//verify meal_amount of 20 returns sales tax of 1.35 (1c)
	REQUIRE(get_sales_tax_amount(20) == 1.35);
}

TEST_CASE("Test get_tip_amount")
{
	//verify meal_amount of 20 and tip rate of 15% (0.15) returns tip of 3 (1d)
	REQUIRE(get_tip_amount(20, 0.15) == 3);
	//verify meal_amount of 20 and tip rate of 20% (0.2) returns tip of 4 (1e)
	REQUIRE(get_tip_amount(20, 0.2) == 4);
}

/*
TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}
*/
