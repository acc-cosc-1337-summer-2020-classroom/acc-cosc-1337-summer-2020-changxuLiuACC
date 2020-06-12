#include<iostream>



//
/*
Write double return-value function gross_pay with int parameter(hour) and double parameter (rate)
*/

double get_regular_pay(int hour, double rate);

double get_ot_pay(int hours, double rate);

double get_fica_tax_total(double gross_pay = 1000);     //if no parameter is ued for gross_pay, default 1000 will be used instead

void display_pay(int hours, double rate);