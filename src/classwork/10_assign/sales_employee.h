//h
#include "employee.h"

#ifndef SALES_EMPLOYEE_H
#define SALES_EMPLOYEE_H

class SalesEmployee : public Employee
{
public:
    SalesEmployee(double hours_worked, double pay_rate, double commission_amt) : hours{hours_worked}, rate{pay_rate}, commission{commission_amt} {}
    SalesEmployee() : SalesEmployee(0.0, 0.0, 0.0) {}   //default constructor
    
    double get_pay() const {return (hours * rate) + commission;}     //overridden function from Employee
    
    ~SalesEmployee() {}     //to prevent warning message
private:
    double hours;   //I've never had a job before so I don't know how wages are calculated in real life, but if they don't count
                    //part of an hour, then this could be an int instead. Double is in case they also count things like 39.5 hours into pay.
    double rate;
    double commission;
};

#endif
