//customer.h
#include<string>
#include<vector>
#include<memory>
#include<stdlib.h>
#include "checking_account.h"
#include "savings_account.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
public:
    Customer(std::string n);
    std::string get_name() const {return name;}
    std::unique_ptr<BankAccount>& get_account (int index);
private:
    std::vector<std::unique_ptr<BankAccount>> accounts;
    std::string name;
};

#endif
