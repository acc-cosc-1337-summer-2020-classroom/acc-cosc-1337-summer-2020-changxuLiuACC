#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#include "employee.h"
#include "engineer.h"
#include "sales_employee.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test class function Engineer::get_pay()")
{
	Employee* engineer1 = new Engineer(1500, 400);		//pointer to Engineer object created in dynamic memory
	REQUIRE(engineer1->get_pay() == 1900);

	delete engineer1;	//releasing memory
	engineer1 = nullptr;
}

TEST_CASE("Test calss function SalesPerson::get_pay()")
{
	Employee* sales1 = new SalesEmployee(40, 10, 500);	//pointer to SalesEmployee object created in dynamic memory
	REQUIRE(sales1->get_pay() == 900);

	delete sales1;		//releasing memory
	sales1 = nullptr;
}
