#include<iostream>
#include "bank_account.h"

using std::cout;
using std::cin;

int main()
{

	BankAccount account(100000);
	int balance = account.get_balance();

	cout<<"Balance: "<<balance<<"\n";

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

	cout<<account.testing;

	return 0;
}