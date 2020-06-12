#include "payroll.h"
#include<iomanip>
//
/*
Function gross_pay returns the product of hours and rate.  The function pays
straight time, there is not overtime.
*/

const double FICA_TAX_RATE = .062;
const double OT_MULTIPLIER = 1.5;

using std::cout;    using std::setw;


double get_regular_pay(int hours, double rate)
{

    double regular_pay{0};

    if(hours > 0)
    {
        if(hours > 40)
        {
            hours = 40;
        }

        regular_pay = hours * rate;
    }

    return regular_pay;
}

double get_ot_pay(int hours, double rate)
{
    double overtime_pay{0};

    if(hours > 40)
    {
        overtime_pay = (hours - 40) * OT_MULTIPLIER * rate;
    }

    return overtime_pay;
}

double get_fica_tax_total(double gross_pay)     //parameter double& gross_pay won't create a copy parameter
//to give the double& gross_pay, add a const before it to safeguard it
//note: if changing this, remember to change the header file too
{
    //gross_pay = 1000;    //remove this - just for copy paramter stuff
    return gross_pay * FICA_TAX_RATE;
}

void display_pay(int hours, double rate)
{
    double regular_pay{0}, overtime_pay{0}, fica_tax_total{0}, gross_pay{0}, net_pay{0};

    regular_pay = get_regular_pay(hours, rate);
    overtime_pay = get_ot_pay(hours, rate);
    gross_pay = regular_pay + overtime_pay;

    fica_tax_total = get_fica_tax_total(gross_pay);
    net_pay = regular_pay + overtime_pay - fica_tax_total;

    cout<<std::fixed<<std::setprecision(2);
    cout<<setw(17)<<"Regular Pay: "<<setw(7)<<regular_pay<<"\n";
    cout<<setw(17)<<"Overtime Pay: "<<setw(7)<<overtime_pay<<"\n";
    cout<<setw(17)<<"Gross Pay: "<<setw(7)<<gross_pay<<"\n";
    cout<<setw(17)<<"FICA Deduction: "<<setw(7)<<fica_tax_total<<"\n";
    cout<<setw(17)<<"Net Pay: "<<setw(7)<<net_pay<<"\n";
}