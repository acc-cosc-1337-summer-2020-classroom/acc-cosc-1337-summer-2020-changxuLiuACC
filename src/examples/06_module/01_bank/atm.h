//atm.h
#include "bank_account.h"

#ifndef ATM_H
#define ATM_H

class ATM
{
public:
    ATM(BankAccount& a) : account{a} {}
    void run();
private:
    //helper functions/utility functions
    //logic that we don't want users to know about - they don't need to know this stuff
    void display_menu();   
    void set_choice();
    void handle_transaction();
    BankAccount account;    //a user defined class in our class --composition
    int choice;
};

#endif
