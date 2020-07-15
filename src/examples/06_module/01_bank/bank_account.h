//bank_account.h
#include<iostream>
#include<vector>

#ifndef BRANCH_BANK_H
#define BRANCH_BANK_H

class BranchBank 
{
public:
    BranchBank(int b) : branch_balance{b} {}
    void update_balance(int b);
    int get_branch_balance() const {return branch_balance;}
private:
    int branch_balance;
};

#endif

//header guards (prevents a class from being defined twice)
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

enum transaction{DEPOSIT=1, WITHDRAW=2, DISPLAY=3};     //old way of enumerations
enum class OPTION{DEPOSIT=1, WITHDRAW=2, DISPLAY=3, EXIT=4};    //C++11 enumerations 

class BankAccount       //abstract class
{
/*
This is an example of both encapsulation and abstraction, as balance is encapsulated into 
BankAccount, while when main uses get_balance(), it's abstraction as you don't have to have written 
the code to use it. The complexity part of it is under the hood.
*/
public:
    //constructor overloading (many constructors, but each has unique parameter list)
    BankAccount() : balance(0) {std::cout<<"\nCreate Memory.\n"; ptr_value = new int(10);}      //(stuff in the { } is just to demonstrate dynamic memory members in classes)
    explicit BankAccount(int b) : balance{b} {std::cout<<"Create Memory.\n"; ptr_value = new int(10); bank_balance += balance;}    //initializer list
    // ^ explicit prevents creation of objects by BankAccount account = 900;        forces creation of objects only through BankAccount account(900);
    //             would see that this is argument 1 for the constructor ^

    //PAST CONSTRUCTORS that were gone over: 
    //BankAccount() {}      //default constructors have no parameters
    //BankAccount(){balance = 500;}
    //BankAccount() : BankAccount(500) {}   //delegating constructor
    //BankAccount(int b){balance = b;};

    //virtual int get_balance() const {return balance;}  //this is an inline class funciton (one line = can write in header)
    //entry point into our bank account class - allows users to use the functionality
    //                           ^ const makes sure no one can make changes to the class - protects the integrity of private variabales
    //THIS WAS MADE ONLY INTO A PROTOTYPE SO THAT IT CAN BE A PURE VIRTUAL FUNCTION (see more about this in 02_shapes)
    
    virtual int get_balance() const = 0;
    //this way, BankAccount is an abstract class, and only CheckingAccount and SavingsAccount can be instantiated (see more about this in 02_shapes)


    //ABSTRACT CLASS - if something is abstract concept, we shouldn't allow creation of an instance of it
        //we shouldn't allow an creation of a BankAccount object, it's abstract
        //see more in the 02_shapes module

    //if it's multiple lines, define it in the implementation file
    void deposit(int amount);
    void withdraw(int amount);

    void set_option(OPTION o){option = o;};

    //needs to be static as it uses a static variable
    static int get_bank_balance(){return bank_balance;}

    //FRIEND FUNCTION (function of BranchBank is able to access public and private members of this class)
    friend void BranchBank::update_balance(int b);      //note that the class that contains the friend must be already defined (reason why BranchBank is above)

    //OPERATOR OVERLOADING (these are free functions, but are still declared in the class)
    //                 v needs to be reference          v const for read-only (prevents modifications)
    friend std::ostream& operator<<(std::ostream& out, const BankAccount& account);
    friend std::istream& operator>>(std::istream& in, BankAccount& account);

    int get_ptr_value() const {return *ptr_value;}      //demonstrating pointer class members
    void set_ptr_value(int value) {*ptr_value = value;}

    //~BankAccount(){std::cout<<"\nDelete Memory.\n"; delete ptr_value; ptr_value = nullptr;}      //in this case, destructor prevents memory leak (when class goes bye-bye out of scope, ensures dynamic memory goes bye-bye too)
    virtual ~BankAccount(){std::cout<<"Delete Memory"; delete ptr_value; ptr_value = nullptr;}      //virtual is needed with inheritance hierarchy (now derived class must provide its own destructor)

private:    //it's good practice to make variables private
    int balance{0};    //private is inaccessible in main.cpp - prevents data from being messed with
    
    static int bank_balance;    //variable exists as the same in all instances of this class we create (initialized in implementation file)

    OPTION option;

    int* ptr_value;     //initialized in constructor - demonstrating pointer class members
};

/*  //FREE FUNCTIONS - not part of the class above (LECTURE 6.23.2020)   ----------------------------------------
BankAccount& get_account(int i);
// ^ returns a reference (the original) to an object

void display_menu();     //these will later be replaced by an ATM class
int get_choice();
void handle_transaction(BankAccount& account, int choice);
-------------------------------------------------------------------------------------------------------------   */

#endif
