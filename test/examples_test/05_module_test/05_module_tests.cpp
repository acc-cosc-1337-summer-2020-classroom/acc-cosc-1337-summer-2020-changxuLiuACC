#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "payroll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test regular pay function")
{
	REQUIRE(get_regular_pay(-5, 10) == 0);
	REQUIRE(get_regular_pay(30, 10) == 300);
	REQUIRE(get_regular_pay(50, 10) == 400);
}

TEST_CASE("Test overtime function")
{
	REQUIRE(get_ot_pay(30, 10) == 0);
	REQUIRE(get_ot_pay(50, 10) == 150);
}

TEST_CASE("Verify get FICA tax rate")
{
	//REQUIRE(get_fica_tax_total(100) == 6.2);
	//REQUIRE(get_fica_tax_total() == 62);
}

TEST_CASE("Verify that value parameters")
{
	double gross_pay = 100;
	get_fica_tax_total(gross_pay);

	REQUIRE(gross_pay == 100);
}