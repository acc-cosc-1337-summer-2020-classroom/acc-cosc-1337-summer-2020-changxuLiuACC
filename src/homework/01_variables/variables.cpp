#include "variables.h"

/*
//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}
*/

//although unlikely to accidentally be changed, pre-determined tax rate set as const
const double TAX_RATE = .0675;

//function definition: get_sales_tax_amount (prototyped in variables.h)
double get_sales_tax_amount(double meal_amount)
{
	// calculates tax
	double tax = meal_amount * TAX_RATE;

	return tax;
}

//function definition: get_tip_amount (prototyped in variables.h)
double get_tip_amount(double meal_amount, double tip_rate)
{
	//calculates tip
	double tip = meal_amount * tip_rate;

	return tip;
}
