//savings_account.h
#include "bank_account.h"

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

//    DERIVED CLASS          BASE CLASS
class SavingsAccount: public BankAccount
{
public:
    SavingsAccount() {}     //default constructor - must make one manually if another constructor as already been created
    SavingsAccount(int b) : BankAccount(b) {}       //constructors from BankAccount won't be inherited though - this passes on the argument to BankAccount in SavingsAccount
    //                                  ^ sends it to the base class

    //overriding the base class function - implementing interest (not accurate though)
    int get_balance() const {return BankAccount::get_balance() * 1050 / 1000 * 1000 / 12000 +
                                    BankAccount::get_balance();}
    //gives the derived class new meaning/function

    ~SavingsAccount() {}   
};

#endif
