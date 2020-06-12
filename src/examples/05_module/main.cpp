#include "payroll.h"

int main()
{
    ///*
    int num = 10;
    int& num_ref = num;     //gives the memory adress of num
    
    std::cout<<num<<" memory address is: "<<num_ref<<"\n";
    
    num_ref = 20;
    std::cout<<num<<" memory address is: "<<num_ref;
    /*
    int hours;
    double rate;
    
    cout<<"Enter hours: ";
    cin>>hours;
    cout<<"Enter rate: ";
    cin>>rate;
    cout<<"\n";

    display_pay(hours, rate);

    return 0;
    */
}