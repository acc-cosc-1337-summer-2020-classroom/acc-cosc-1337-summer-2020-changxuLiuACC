#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#include "expressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

//FOR NOW
int operator_precedence_1(int num1, int num2, int num3)
{
    return num1 + num2 / num3;
}

int operator_precedence_2(int num1, int num2, int num3)
{
    return (num1 + num2) / num3;
}

double convert_int_to_double(int year, double interest_rate)
{
    return year * interest_rate;
	//year will remain int, however it's temporarily converted to double for the expression
}

int int_overflow()
{
    int num = 2147483647;       //maximum value an int can use
    num++;
    return num;
    
}

int static_cast_double_int(double num)
{
	int n = static_cast<int>(num);
	return n;
}

int int_data_size()
{
	return sizeof(int);
}
//

/*Test case operator precedence 1 with function argument values 12, 6 and 3 returns 14*/
TEST_CASE("Test operator precedence 1 with args: 12, 6, 3 returns 14")
{
	REQUIRE(operator_precedence_1(12, 6, 3) == 14);
}

/*Test case operator precedence 2 with function argument values 12, 6 and 3 returns 6*/
TEST_CASE("Test operator precedence 2 with args: 12, 6, 3 returns 6")
{
	REQUIRE(operator_precedence_2(12, 6, 3) == 6);
}

/*Test case operator precedence 3 with function argument values 12, 6 and 3 returns 6*/

/*Test case operator precedence 3 with function argument values 12, 6 and 3 returns 6*/

/*Test case convert_to_double to show that multiplying int and double returns a double*/
TEST_CASE("Test convert into to double implicity")
{
	REQUIRE(convert_int_to_double(10, 0.15) == 1.5);
}

/*Test case convert double to int to show that a double converted to int truncates 
the decimal portion*/

/*Test case static cast double int to show that a double casted to int truncates
decimal portion*/
//TEST_CASE("") wut I'm so confused

/*Test int overflow to show adding 1 to 2147483647 returns -2147483648*/
TEST_CASE("test INT overflow")
{
	REQUIRE(int_overflow() == -2147483648);
}

/*Test get radius of a circle with 10 to show that it returns 314.159*/

/*Test int data size */
TEST_CASE("Test size of int is 4 bytes")
{
	REQUIRE(int_data_size() == 4);
}
/*Test multi assign addition*/

