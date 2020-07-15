//main
#include<iostream>
#include<memory>
#include<time.h>
#include<vector>
#include "bank_account.h"
#include "atm.h"
#include "checking_account.h"
#include "savings_account.h"
#include "customer.h"

using std::cout;
using std::cin;
using std::unique_ptr;	using std::make_unique;

int main()
{
	srand(time(NULL));		//force true random number generation

	///*	//LECTURE 7.14.2020		ARRAY OF OBJECTS	--------------------------------------------------------------------------------------------------------------
	//BankAccount* a1 = new SavingsAccount(50);		//can have a pointer to an object
	//  ^ to take advantage of polymorphism

	{
		const int SIZE = 3;
		BankAccount* accounts[SIZE];	//static array (in the stack) that points to heap memory
		//int** nums[3];				//array in the heap (pointers in heap that point to memory in the heap)

		accounts[0] = new SavingsAccount(50);	//dynamic memory creation (stored in heap)
		accounts[1] = new CheckingAccount(100);
		accounts[2] = new CheckingAccount(200);

		BankAccount* a = accounts[0];		//should be pointing to the original (note: must confirm this)

		//using dynamic memory
		for (auto account: accounts)
		{
			cout<<*account<<"\n";	//thanks to operator overloading
		}

		//deleting allocated memory to free it up in the heap
		for(int i = 0; i < SIZE; ++i)
		{
			delete accounts[i];		//any time we create inheritance hierarchy and derive, we need to add a constructor and make it virtual
			accounts[i] = nullptr;
		}
		//if we don't do this, there will be a memory leak ((now) useless data squatting in heap, not making space more useful stuff)
	}




	//---------------------------------------------------------------------------------------------------------------------------------------	*/

	/*	//LECTURE 7.7.2020 + 7.9.2020
	{
		//BankAccount account;		//should create memory as the function runs, but delete memory when function exits (thanks to the destructor)
		
		/ *
		std::vector<BankAccount*> accounts;
		accounts.push_back(new SavingsAccount());
		accounts.push_back(new CheckingAccount());
		//with this, we're creating memory, but not deleting it (causing memory leak)
				//		v reference to get the pointer when was using the "new"
		for(auto& account: accounts)
		{
			cout<<account->get_balance()<<"\n";
		}
		* /		//remember to recomment this if using this code
		
		//to fix this, we c o u l d just use stack memory and let that manage it for us (but we have an abstract class, so we use the following option instead)
		//or use unique_ptr
		std::vector<std::unique_ptr<BankAccount>> accountss;
		std::unique_ptr<BankAccount> s = std::make_unique<SavingsAccount>();	//smart pointers help manage the memory for us - YAY
		std::unique_ptr<BankAccount> c = std::make_unique<CheckingAccount>();
		accountss.push_back(std::move(s));	//needs std::move() to shift ownership to the vector
		accountss.push_back(std::move(c));
	}
	//----------------------------------------------------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 7.7.2020	POINTER CLASS MEMBERS	-------------------------------------------------------------------------------------------------------------------
	SavingsAccount account;
	SavingsAccount account2 = account;		//copy created

	cout<<account.get_balance()<<"\n";		//non-dynamic memory
	cout<<account.get_ptr_value()<<"\n";	//dynamic memory
	cout<<account2.get_balance()<<"\n";
	cout<<account2.get_ptr_value()<<"\n";

	account.deposit(50);		//non-dynamic memory
	account.set_ptr_value(50);	//dynamic memory
	cout<<account.get_balance()<<"\n";
	cout<<account.get_ptr_value()<<"\n";
	cout<<account2.get_balance()<<"\n";
	cout<<account2.get_ptr_value()<<"\n";

	//notice that with non-dynamic members, the copy has it's own individual value (shown as depositing 50 into account doesn't affect balance of account2)
	//however, with dynamic members, the copy still points to the same address as the object it was supposed to be copied from (changing ptr_value of account affects ptr_value of account2 as they point to the same memory)

	//----------------------------------------------------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 7.7.2020	POINTERS TO CLASSES	--------------------------------------------------------------------------------------------------------------------
	BankAccount* account = new CheckingAccount(500);

	BankAccount* account2 = account;	//still points to the same location in heap memory though - did not make a copy

	cout<<account->get_balance()<<"\n";
	cout<<account2->get_balance()<<"\n";

	account->deposit(50);
	cout<<account->get_balance()<<"\n";
	cout<<account2->get_balance()<<"\n";

	delete account;		//prevent memory leak
	account = nullptr;		//prevent dangling pointers
	account2 = nullptr;
	//----------------------------------------------------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 7.2.2020		BANKACCOUNT WITH POINTERS	--------------------------------------------------------------------------------------------------------
	//		   v raw/naked pointer - no protection from the C++ library (we responsible for deleting)
	BankAccount* account = new CheckingAccount(500);
	//						^ dynamic memory creation in the heap

	//now it works like a unique pointer
	cout<<account->get_balance();
	//			 ^ arrow operator

	delete account;
	account = nullptr;

	//-----------------------------------------------------------------------------------------------------------------------------------------------------		*/

	
	/*	//LECTURE 7.2.2020	CUSTOMER CLASS (prior to integration into ATM class)	----------------------------------------------------------------------------
	Customer c("John Doe");
	cout<<c.get_name();
	
	//cout<<c.get_account(1)->get_balance();	//c.get_account(1) basically refers to the object (thanks to the ampersand & in the return type)
	//cout<<c.get_account(1);		//operator overload should allow this, but doesn't work, need to find out more about
	
	//					   v needs to be reference as the get_account() return type is a reference
	unique_ptr<BankAccount>& account = c.get_account(1);	//more readable format
	cout<<account->get_balance();
	-------------------------------------------------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 6.30.2020		POLYMORPHISM - one class taking many forms	-------------------------------------------------------------------------------------
	//sometimes we may want to use the get_balance from the derived class (SavingsAccount, CheckingAccount) and other times, from the base class (BankAccount)
	SavingsAccount a(100);
	cout<<a.get_balance()<<"\n";	//prints out the balance + interest (get_balance of the derived SavingsAccount class)

	//to implement polymorphism, we must use pointers

	//			v is the same type as ........ v
	unique_ptr<BankAccount> a1 = make_unique<BankAccount>(600);
	cout<<a1->get_balance();			//prints out the balance with get_balance of the base BankAccount class
	//		^ arrow operator (mimics an asterik *)

	//theoretically, we should be able to work with a vector of BankAccount and have C++ decide which derived functions to work with
	
	//we should be able to have a BankAccount of type SavingsAccount with a SavingsAccount function
	//however, we need to be able to use that SavingsAccount in a vector of BankAccounts
	//(Ch. 15) VIRTUAL FUNCTIONS help us do this ... they tell C++ not to run that function, but the derived functions (see get_balance() in bank_account.h)
		//"when I create a pointer of BankAccount to a Savings or Checking account, run the derived function, not the one in BankAcccount"
	
	unique_ptr<BankAccount> a2 = make_unique<SavingsAccount>(600);	//a BankAccount pointer pointing to a SavingsAccount
	cout<<a2->get_balance();
	//virtual keyword allows us to create a pointer to BankAccount, but an instance of SavingsAccount - calls the SavingsAccount function, not base class function
		//a BankAccount with the form of a SavingsAccount (?)
		//we have the option to OVERRIDE functions (like with get_balance())

	unique_ptr<BankAccount> a3 = make_unique<CheckingAccount>(100);
	cout<<a3->get_balance();	//there's no need to override the function here

	//now, we can create a vector of BankAccount and store SavingsAccount and CheckingAccount
		//see in the ATM class
	-------------------------------------------------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 6.30.2020		SMART POINTERS	--------------------------------------------------------------------------------------------------------------
	//must #include<memory>
	//shared pointers, weak pointers, and unique pointers manage memory for us behind the scenes
	//unique_ptr can have one reference (only one pointer/construct can own it) - to shift ownership and sometimes when passing in as argument, must use move()
	//shared_ptr can be shared by different vectors/constructs/parts of our code

	BankAccount as(600);	//creates on stack

	//creates an instance of BankAccount on the heap
	unique_ptr<BankAccount> a = make_unique<BankAccount>(600);
	// data/class type ^			^ creates dynamic memory for us

	//no need to worry about deleting it - once a function that has a unique_ptr exits, it'll be removed from memory for use (as long as no live reference pointing to it)

	display_account(a);
	display_account_val(std::move(a));		//when passing by value (copy created implies owner change) - must use std::move() to change ownership of a from main to display_account_val
											//							copy is created in the heap

	unique_ptr<BankAccount> a1 = get_account();
	*/

	//examples on REFERENCES, POINTERS, and DYNAMIC MEMORY with the NEW keyword are in 02_shapes module


	/*	//LECTURE 6.25.2020		INHERITANCE--------------------------------------------------------------------------------
	CheckingAccount c(1000);
	cout<<c<<"\n";		//it has inherited the properties/members of BankAccount
	CheckingAccount c1;
	cout<<c1<<"\n";

	SavingsAccount s;
	cout<<s<<"\n";
	SavingsAccount s1(100);
	cout<<s1<<"\n";			//base class get_balance (due to cin operator)
	cout<<s1.get_balance()<<"\n";	//SavingsAccount overrided get_balance
	----------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 6.25.2020		EXPLICIT CONSTRUCTORS-----------------------------------------------------------------
	//BankAccount account = 900;	an explicit constructor wouldn't allow this
	BankAccount account(900);		//would only allow object instantiation through this
	cout<<account;
	------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 6.25.2020 	FRIEND FUNCTIONS and OPERATOR OVERLOADING---------------------------------------------
	BankAccount account;
	BranchBank bank(10000);
	bank.update_balance(500);

	cout<<account;		//operator overloading allows you to treat a class object like a native type (cout<<object, cin>>object, object1 + object2 - instead of member functions)
	//cin>>account; 	  works, but relies on the option class member variable, which is only set in ATM - don't use without ATM
	
	cout<<account.get_bank_balance()<<"\n";
	cout<<bank.get_branch_balance()<<"\n";
	-----------------------------------------------------------------------------------------------------------		*/


	/* //LECTURE 6.25.2020		ATM CLASS-------------------------------------------------------------------------
	ATM atm;
	atm.run();
	//-------------------------------------------------------------------------------------------------------		*/


	/*	//LECTURE 6.23.2020 + 6.25.2020		ASSIGNMENT OF AN OBJECT TO BE AN OBJECT--------------------------------
	BankAccount& account = get_account(1);	//uncomment get_account in bank_account.cpp to use
	//		   ^ even if the function returns a reference to the function, it needs to be a reference here as well (&) to modify the original
	ATM atm(account);

	atm.run();

	BankAccount account1 = account;		//can create another object from an object (except not in dynamic memory)
	cout<<account1.get_balance()<<"\n";

	account.deposit(50);
	cout<<"Account: "<<account.get_balance()<<"\n";
	cout<<"Account1: "<<account1.get_balance()<<"\n";

	for (int i = 0; i < 3; ++i)
	{
		BankAccount a = get_account[i];
		cout<<a.get_balance();
	}
	----------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 6.23.2020		UI WITH FREE FUNCTIONS----------------------------------------------------------------
	int choice;

	BankAccount account = get_account(1);
	//cout<<account.get_balance()<<"\n";

	do
	{
		display_menu();
		choice = get_choice();
		handle_transaction(account, choice);
	} while (choice != 4);
	--------------------------------------------------------------------------------------------------------------	*/


	/*	//LECTURE 6.18.2020		BANKACCOUNT CLASS---------------------------------------------------------------
	BankAccount account;	//create an instance/variable of class in stack memory
	
	int balance = account.get_balance();
	cout<<"Balance: "<<balance<<"\n";

	int deposit;
	cout<<"Enter Deposit Amount: ";
	cin>>deposit;
	account.deposit(deposit);
	cout<<"Balance: "<<account.get_balance()<<"\n";

	int withdraw;
	cout<<"Enter Withdraw Amount: ";
	cin>>withdraw;
	account.withdraw(withdraw);
	cout<<"Balance: "<<account.get_balance()<<"\n";
	-----------------------------------------------------------------------------------------------------	*/

	return 0;
}
