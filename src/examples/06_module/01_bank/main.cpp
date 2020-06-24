#include<iostream>
#include "bank_account.h"
#include "atm.h"

using std::cout;
using std::cin;

int main()
{
	BankAccount account = get_account(1);
	//cout<<"Account: "<<account.get_balance()<<"\n";

	ATM atm(account);
	atm.run();
	
	//BankAccount account1 = account;
	//cout<<"Account1: "<<account1.get_balance()<<"\n";
	
	//account.deposit(50);
	//cout<<"Account: "<<account.get_balance()<<"\n";
	//cout<<"Account1: "<<account1.get_balance()<<"\n";

	return 0;
}

/*
SOME OLDER CODE:
	int deposit;
	cout<<"Enter deposit amount:  ";
	cin>>deposit;
	account.deposit(deposit);
	cout<<"Balance: "<<account.get_balance()<<"\n";

	int withdraw;
	cout<<"Enter withdraw amount:  ";
	cin>>withdraw;
	account.withdraw(withdraw);
	cout<<"Balance: "<<account.get_balance()<<"\n";
*/

/*
	BankAccount account(1000);
	int balance = account.get_balance();

	cout<<"Balance: "<<balance<<"\n";
*/
