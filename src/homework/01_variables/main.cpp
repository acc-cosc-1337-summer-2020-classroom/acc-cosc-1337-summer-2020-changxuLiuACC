//write include statements
#include<iostream>
#include<iomanip>
#include "variables.h"
//write namespace using statement for cout
using std::cout;	using std::cin;

using std::setw;	using std::setprecision;
using std::fixed;	using std::right;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount, tip_amount, total;

	cout<<"Enter Meal Amount: ";
	cin>>meal_amount;

	total = get_sales_tax(meal_amount);

	cout<<"Enter Tip Rate (as a decimal): ";
	cin>>tip_amount;
	cout<<"\n";

	total = total + get_tip_amount(meal_amount, tip_amount) + meal_amount;
	//could I just use += instead?

	cout<<right<<setw(10)<<"RECIEPT:\n";
	cout<<setw(14)<<"Meal Amount: "<<"$"<<right<<setw(6)<<fixed<<setprecision(2)<<meal_amount<<"\n";
	cout<<setw(14)<<"Sales Tax: "<<"$"<<right<<setw(6)<<fixed<<setprecision(2)<<get_sales_tax(meal_amount)<<"\n";
	cout<<setw(14)<<"Tip Amount: "<<"$"<<right<<setw(6)<<fixed<<setprecision(2)<<get_tip_amount(meal_amount, tip_amount)<<"\n";
	cout<<setw(14)<<"Total: "<<"$"<<right<<setw(6)<<fixed<<setprecision(2)<<total<<"\n";

	return 0;
}
