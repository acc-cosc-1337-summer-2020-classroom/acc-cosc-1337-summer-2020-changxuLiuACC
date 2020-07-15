//checking_account.h
#include "bank_account.h"

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

//    DERIVED CLASS           BASE CLASS
class CheckingAccount: public BankAccount
{
public:
    CheckingAccount() {}    //default constructor - must make one manually if another constructor as already been created
    CheckingAccount(int b) : BankAccount(b) {}      //constructors from BankAccount won't be inherited though - this passes on the argument to BankAccount in CheckingAccount
    //                                   ^ sends it to the base class

    //now that BankAccount is an abstract class, we must override the get_balance() function because it has become a pure virtual function
    int get_balance() const {return BankAccount::get_balance();}
    //if we don't redefine that pure virtual function inherited from BankAccount, it'll make CheckingAccount an abstract class as well

    ~CheckingAccount() {}   //now that BankAccount destructor is virtual, this class must provide its own
};

#endif
