//bank_account.cpp
#include<vector>
#include "bank_account.h"

using std::cout;
using std::cin;
using std::vector;

vector<BankAccount> accounts{BankAccount(100), BankAccount(200), BankAccount(300)};

void BankAccount::deposit(int amount)
{
    if(amount > 0)
    {
        balance += amount;
        bank_balance += amount;
    }
}

void BankAccount::withdraw(int amount)
{
    if(amount > 0 && balance >= amount)
    {
        balance -= amount;
        bank_balance -= amount;
    }
    
}

int BankAccount::bank_balance = 0;

BankAccount& get_account(int i)
{
    return accounts[i];
}   

void display_menu()
{
    cout<<"1) Make Deposit \n";
    cout<<"2) Make Withdraw \n";
    cout<<"3) Display Balance \n";
    cout<<"4) Exit \n";
    cout<<"Enter your choice: ";
}

void get_choice()
{
    int choice;
    cin>>choice;
    cin.ignore();

    while(choice < 1 || choice > 4)
    {
        cout<<"Valid choices are 1 to 4. Try Again.";
        cin>>choice;
        cin.ignore();
    }
}
