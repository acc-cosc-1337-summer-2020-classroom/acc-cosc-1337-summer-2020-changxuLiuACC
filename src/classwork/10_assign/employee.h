//h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee  //abstract class thanks to having a pure virtual function
{
public:
    Employee() {}
    
    virtual double get_pay() const = 0;   //pure virtual function - overridden in SalesEmployee and Engineer
    
    virtual ~Employee() {}          //virtual destructor to prevent warning message
};

#endif
