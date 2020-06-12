//write include statements
#include<iostream>
#include<iomanip>
#include "variables.h"

//write namespace using statement for cout and cin
using std::cout;	using std::cin;

//namespace using for formatting result
using std::setw;	using std::setprecision;
using std::fixed;	using std::right;

int main()
{
	//(2a)
	double meal_amount{0}, tip_rate{0}, tip_amount{0}, tax_amount{0}, total{0};

	//capture meal raw cost from user for calclating sales tax and tip amount (2b)
	cout<<"Enter Meal Amount: ";
	cin>>meal_amount;	//raw cost of meal

	//calculation of sales tax using get_sales_tax_amount function defined in variables.cpp (2c)
	tax_amount = get_sales_tax_amount(meal_amount);	

	//capture tip percentage using cout for calculating tip amount (2d)
	cout<<"Enter Tip Rate (as a decimal): ";
	cin>>tip_rate;	//decimal(percent) value of tip

	//calculation of tip amount using get_tip_amount function defined in variables.cpp (2e)
	tip_amount = get_tip_amount(meal_amount, tip_rate);		//actual value of tip (not percent)

	//adding up the total - raw cost, sales tax, and tip together (2f)
	total = meal_amount + tax_amount + tip_amount;

	//printing out final receipt with formatting (2g)
	cout<<"\n"<<right<<setw(10)<<"RECIEPT:\n";
	cout<<fixed<<setprecision(2);
	cout<<setw(14)<<"Meal Amount: "<<"$"<<right<<setw(6)<<meal_amount<<"\n";
	cout<<setw(14)<<"Sales Tax: "<<"$"<<right<<setw(6)<<tax_amount<<"\n";
	cout<<setw(14)<<"Tip Amount: "<<"$"<<right<<setw(6)<<tip_amount<<"\n";
	cout<<setw(14)<<"Total: "<<"$"<<right<<setw(6)<<total<<"\n";

	/*
	Format of final receipt (spaces to the left not needed will not be filled with 0):

	 Meal Amount: $XXX.XX
	   Sales Tax: $XXX.XX
	  Tip Amount: $XXX.XX
	       Total: $XXX.XX
	*/

	return 0;
}
