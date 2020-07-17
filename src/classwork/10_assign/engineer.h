//h
#include "employee.h"

#ifndef ENGINEER_H
#define ENGINEER_H

class Engineer : public Employee    //Engineer derives from Employee class
{
public:
    Engineer(double pay, double bonus_pay) : base_pay{pay}, bonus{bonus_pay} {}
    Engineer() : Engineer(0.0, 0.0) {}   //default constructor
    
    double get_pay() const {return base_pay + bonus;}     //overridden function from Employee
    
    ~Engineer() {}      //to prevent warning message
private:
    double base_pay;
    double bonus;
};

#endif
