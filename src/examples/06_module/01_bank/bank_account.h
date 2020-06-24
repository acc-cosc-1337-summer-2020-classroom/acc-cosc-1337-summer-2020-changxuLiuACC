#include<iostream>

//header guards
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

enum transaction{DEPOSIT=1, WITHDRAW=2, DISPLAY=3};
enum class OPTION{DEPOSIT=1, WITHDRAW=2, DISPLAY=3, EXIT=4};

//bank_account.h
class BankAccount
{
/*
This is an example of both encapsulation and abstraction, as balance is encapsulated into 
BankAccount, while when main uses get_balance(), it's abstraction as you don't have to have written 
the code to use it. The complexity part of it is under the hood.
*/
public:
    BankAccount() : balance(0){}
    
    //BankAccount(){balance = 500;}
    BankAccount(int b) : balance{b} { bank_balance += balance;}
    //BankAccount(int b){balance = b;};

    int get_balance() const {return balance;}  //create an instance/variable    this is an inline class funciton
    //entry point into our bank account class - allows users to use the functionality
    //                  ^ const makes sure no one can make changes to the class - protects the integrity of private variabales
    //if its inline, we can just write it in the header

    void deposit(int amount);
    //if it's multiple lines, do it in bank_account.cpp

    void withdraw(int amount);

    static int get_bank_balance(){return bank_balance;}

private:
    int balance{0};    //inaccessible in main.cpp - locked the variable
    //don't want people to just go balance += 394203849 in main.cpp
    //initialize to prevent getting bad data

    static int bank_balance;
};

//This is not part of the BankAccount class, it's an independent function that's just getting something from
//the BankAccount class (an object from that) to be used in main.cpp

//These will be moved into an atm class.
BankAccount& get_account(int i);

void display_menu();

void get_choice();

void handle_transaction(BankAccount& account, int choice);

#endif
