//customer.cpp
#include "customer.h"

Customer::Customer(std::string n): name{n}
{
    int check_balance = rand() % 10000 + 1;
    int save_balance = rand() % 10000 + 1;

    accounts.push_back(std::make_unique<CheckingAccount>(check_balance));
    accounts.push_back(std::make_unique<SavingsAccount>(save_balance));
}

//                          v pass by reference to modify the account, not a copy
std::unique_ptr<BankAccount>& Customer::get_account(int index)
{
    return accounts[index-1];
}
