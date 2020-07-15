//atm.cpp
#include<iostream>
#include "atm.h"

using std::cout;    using std::cin;

ATM::ATM()
{
    customers.push_back(Customer("John Doe"));
    customers.push_back(Customer("Mary Doe"));
    customers.push_back(Customer("Jr Doe"));
}


void ATM::scan_card()
{
    cout<<"Please scan your card...\n";
    selected_customer_index = rand() % 3 + 1;
    cout<<"Card scanned. Processing...\n\n";
    Customer& customer = customers[selected_customer_index-1];

    cout<<"Welcome "<<customer.get_name()<<" to Austin Community Bank!\n";
    cout<<"1 - Checking \n";
    cout<<"2 - Savings \n";
    cout<<"Select Account: ";
    cin>>selected_account_index;

    /*  ALL OF BEFORE 7.2.2020 (BEFORE CUSTOMER CLASS)
    cout<<"Welcome to ACC Community Bank.\n";
    cout<<"Select Account: ";
    cin>>selected_account_index;
    */
}

void ATM::run()
{
    do
    {
        scan_card();
        do
        {
            display_menu();
            set_choice();
            handle_transaction();
        } while (choice != 4);
    } while(true);  //or at least until some secret code by technicians/operators

}

void ATM::display_menu()
{
    cout<<"\n1) Make Deposit \n";
    cout<<"2) Make Withdraw \n";
    cout<<"3) Display Balance \n";
    cout<<"4) Exit \n";
    cout<<"Enter your choice: ";
}

void ATM::set_choice()  //class has access to private variables, so there's no need to return anything (compared to free function)
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
    //LECTURE 7.2.2020
    Customer& customer = customers[selected_customer_index - 1];
    std::unique_ptr<BankAccount>& account = customer.get_account(selected_account_index);
    account->set_option(static_cast<OPTION>(choice));
    //to access pointer functions, must use the arrow operator

    switch(static_cast<OPTION>(choice))
    {
    case OPTION::DEPOSIT:
        cin>>*account;  //must dereference account with * to get value
        break;
    case OPTION::WITHDRAW:
        cin>>*account;
        break;
    case OPTION::DISPLAY:
        cout<<*account;
        break;
    default:
        cout<<"Exiting...";
        break;
    }

    /*  //LECTURE 6.30.2020 --------------------------------------------------------------------------------------------------
    BankAccount account = accounts[selected_account_index - 1];     //edits for readability - better practice
    account.set_option(static_cast<OPTION>(choice));
    
    switch(static_cast<OPTION>(choice))
    {
    case OPTION::DEPOSIT:
        cin>>accounts[selected_account_index];
        break;
    case OPTION::WITHDRAW:
        cin>>accounts[selected_account_index];
        break;
    case OPTION::DISPLAY:
        cout<<accounts[selected_account_index]<<"\n";
        break;
    default:
        cout<<"Exiting...";
        break;
    }
    ------------------------------------------------------------------------------------------------------------    */

    /*  //LECTURE 6.25.2020     ----------------------------------------------------------------------------------------
    accounts[selected_account_index].set_option(static_cast<OPTION>(choice));   //set_option lets the cin operator overload know what action to do (deposit/withdraw)
                                                                                //ATM knows through the choice member variable, but we must give that 
                                                                                //info to the BankAccount account through set_option for option variable so that it knows
    int amount;

    switch(static_cast<OPTION>(choice))
    {
    case OPTION::DEPOSIT:
        cin>>accounts[selected_account_index];              //operator overloading
        //accounts[selected_account_index].deposit(amount); //without operator overloading
        break;
    case OPTION::WITHDRAW:
        cin>>accounts[selected_account_index];
        //accounts[selected_account_index].withdraw(amount);
        break;
    case OPTION::DISPLAY:
        cout<<accounts[selected_account_index];             //operator overloading
        //cout<<accounts[selected_account_index].get_balance()<<"\n";     //without operator overloading
        break;
    default:
        cout<<"Exiting...";
        break;
    }
    ------------------------------------------------------------------------------------------------------------    */


    /*  //LECTURE 6.23.2020 -------------------------------------------------------------------------------------------
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
    --------------------------------------------------------------------------------------------------------------  */
}


//LECTURE 6.30.2020     FREE FUNCTIONS just to demonstrate UNIQUE_PTRs  
void display_account(const std::unique_ptr<BankAccount>& account)
{
    std::cout<<*account<<"\n";      //pointer dereferenced, displays balance with operator overload

    //std::cout<<account.get()->get_balance();
}

void display_account_val(std::unique_ptr<BankAccount> account)
{
    std::cout<<*account<<"\n";
}

std::unique_ptr<BankAccount> get_account()
{
    //std::unique_ptr<BankAccount> a = std::make_unique<BankAccount>(1000);

    std::unique_ptr<BankAccount> a = std::make_unique<SavingsAccount>(1000);
    //                                                     ^ now that BankAccount is abstract, can't instantiate it

    return a;
}

void use_account()
{
    //std::unique_ptr<BankAccount> a = std::make_unique<BankAccount>(1000);

    std::unique_ptr<BankAccount> a = std::make_unique<SavingsAccount>(1000);
    //                                                     ^ now that BankAccount is abstract, can't instantiate it

    cout<<*a;

    //once this function exits, the memory is cleaned up automatically. (demonstration of how smart unique_ptr works and makes lives easier)
        //unique_ptr is the standard/recommended in the industry
        //except in robotics (because of its limited memory) like the Mars rover - instead they manage memory themselves
        
}
