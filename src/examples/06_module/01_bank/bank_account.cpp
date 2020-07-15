//bank_account.cpp
#include "bank_account.h"

using std::cout;    using std::cin;
using std::vector;

//vector<BankAccount> accounts{BankAccount(100), BankAccount(200), BankAccount(300)};
//moved to ATM

//virtual function, but no need to write "virtual" in definition in implementation file
int BankAccount::get_balance() const 
{
    return balance;
}


//      v signifies that deposit is part of the BankAccount class
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

//           v there's no BankAccount:: here because it's a free function
std::ostream& operator<<(std::ostream& out, const BankAccount& account)
{
    out<<"Balance: "<<account.balance<<"\n";      //access to the private data from being a friend
    //^ the parameter

    return out;
    //operator<<(cout, account)     takes place behind the scenes
}

std::istream& operator>>(std::istream& in, BankAccount& account)
{
    int amount;
    std::cout<<"Enter Amount: ";
    std::cin>>amount;

    if (account.option == OPTION::DEPOSIT)
    {
        account.deposit(amount);
    }
    else if(account.option == OPTION::WITHDRAW)
    {
        account.withdraw(amount);
    }

    return in;
}

int BankAccount::bank_balance = 0;

void BranchBank::update_balance(int b)
{
    branch_balance += b;
    BankAccount::bank_balance += b;
}

/*  //FREE FUNCTIONS (replaced by ATM class)
BankAccount& get_account(int i)
{
    return accounts[i];     //should have unit validation
}

void display_menu()
{
    cout<<"1) Make Deposit\n";
    cout<<"2) Make Withdrawal\n";
    cout<<"3) Show Balance\n";
    cout<<"4) Exit\n";
    cout<<"Enter your choice: \n";
}

int get_choice()
{
    int choice;
    cin>>choice;
    cin.ignore();

    while(choice < 1 || choice > 4)
    {
        cout<<"Valid choices are 1 to 4. Try again.";
        cin>>choice;
        cin.ignore();
    }

    return choice;
}

void handle_transaction(BankAccount& account, int choice)
{
    int amount;

    //C++11 way of enumerations
    switch(static_cast<OPTION>(choice))     //converts our choice int into an OPTION
    {
    case OPTION::DEPOSIT:           //also note how the enum class name and the scope resolution operator are needed
        cout<<"Enter deposit: ";
        cin>>amount;
        account.deposit(amount);
        break;
    case OPTION::WITHDRAW:
        cout<<"Enter withdrawal: ";
        cin>>amount;
        account.withdraw(amount);
    case OPTION::DISPLAY:
        cout<<account.get_balance();
        break;
    default:
        cout<<"Exiting...";
        break;
    }

    / *  old way of enumerations - remember to comment if above comments are uncommneted
    switch(choice)
    {
    case DEPOSIT:
        cout<<"Enter deposit: ";
        cin>>amount;
        account.deposit(amount);
        break;
    case WITHDRAW:
        cout<<"Enter withdrawal: ";
        cin>>amount;
        account.withdraw(amount);
    case DISPLAY:
        cout<<account.get_balance();
        break;
    default:
        cout<<"Exiting...";
        break;
    }
    * /     //remember to recomment this
}
*/
