#include "variables.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write code for multiply_numbers function here
//function returns product of num1 and num2

double get_sales_tax(double meal_amount)
{
	double tax_rate = .0675;
	double tax = meal_amount * tax_rate;
	
	return tax;
}

double get_tip_amount(double meal_amount, double tip_rate)
{
	float tip = meal_amount * tip_rate;

	return tip;
}

