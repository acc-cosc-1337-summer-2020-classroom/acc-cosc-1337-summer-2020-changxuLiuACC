//atm.cpp
#include "atm.h"

using std::cout;
using std::cin;

void ATM::run()
{
    do
	{
		display_menu();
		set_choice();
		handle_transaction();
	} while (choice != 4);
}

void ATM::display_menu()
{
    cout<<"\n1) Make Deposit \n";
    cout<<"2) Make Withdraw \n";
    cout<<"3) Display Balance \n";
    cout<<"4) Exit \n";
    cout<<"Enter your choice: ";
}

void ATM::set_choice()
{
    cin>>choice;
    cin.ignore();

    while(choice < 1 || choice > 4)
    {
        cout<<"Valid choices are 1 to 4. Try again: ";
        cin>>choice;
        cin.ignore();
    }

    cout<<"\n";
}

void ATM::handle_transaction()
{
    int amount;

    switch(static_cast<OPTION>(choice))
    {
    case OPTION::DEPOSIT:
        cout<<"Enter deposit: ";
        cin>>amount;
        account.deposit(amount);
        break;
    case OPTION::WITHDRAW:
        cout<<"Enter withdraw: ";
        cin>>amount;
        account.withdraw(amount);
        break;
    case OPTION::DISPLAY:
        cout<<account.get_balance()<<"\n";
        break;
    default:
        cout<<"Exiting...";
        break;
    }
}
