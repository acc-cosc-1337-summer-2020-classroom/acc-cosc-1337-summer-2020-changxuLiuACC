//atm.h
#include<vector>
#include<memory>
#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"
#include "customer.h"

#ifndef ATM_H
#define ATM_H

class ATM
{
public:
    ATM();      //now its only prototyped here - definition in implementation file
    
    //OLD CONSTRUCTORS:
    //               v reference (&) to work with original object
    //ATM(BankAccount& a) : account{a}    {}    //with the vector of BankAccount below - no need to take external account objects
    
    void run();
private:
    //helper/utility functions
    //logic that we don't want users to know about - they don't need to know this stuff
    void scan_card(); 
    void display_menu();   
    void set_choice();
    void handle_transaction();
    //         v must be reference to modify the original bank account
    //BankAccount& account;    //a user defined class in our class --composition        no need any longer as vector of accounts added
    
    //this class depends on BankAccount - won't work without it (with this, can hide the stuff in BankAccount and just give the binary)
    int choice;
    
    int selected_account_index;
    int selected_customer_index;

    //std::vector<BankAccount> accounts{BankAccount(100), BankAccount(200), BankAccount(300)};    //moved here from bank_account.h to be part of ATM class
    
    //std::vector<BankAccount> accounts{CheckingAccount(100), BankAccount(200)};  //modifications for polymorphism (6.30.2020) - note this isn't with pointers
                                                                                 //this vector to be replaced by Customer class

    std::vector<Customer> customers;       //Customer class

    
};

#endif

//LECTURE 6.30.2020     FREE FUNCTIONS just to demonstrate UNIQUE_PTRs
//pass by reference                                    v const reference to original object
void display_account(const std::unique_ptr<BankAccount>& account);
//can be const or non-const

//pass by value (copy created)
void display_account_val(std::unique_ptr<BankAccount> account);

//      v returning a unique_ptr of BankAccount
std::unique_ptr<BankAccount> get_account();
