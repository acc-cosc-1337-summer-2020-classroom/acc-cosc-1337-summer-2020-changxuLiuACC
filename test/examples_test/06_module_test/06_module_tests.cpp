#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include<memory>
#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"

using std::unique_ptr;	using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

/*
TEST_CASE("Verify bank account default constructor")
{
	BankAccount account;

	REQUIRE(account.get_balance() == 500);
}
*/

/*	//ALL OF THESE ARE BROKEN NOW THAT BankAccount IS AN ABSTRACT CLASS		-----------------------------------------------------------

TEST_CASE("Verify bank account constructor")
{
	BankAccount account(1000);
	REQUIRE(account.get_balance() == 1000);
}

TEST_CASE("Verify bank account deposit")
{
	BankAccount account(100);
	REQUIRE(account.get_balance() == 100);

	account.deposit(50);
	REQUIRE(account.get_balance() == 150);

	account.deposit(-50);
	REQUIRE(account.get_balance() == 150);

}

TEST_CASE("Verify bank account withdraw")
{
	BankAccount account(100);
	REQUIRE(account.get_balance() == 100);

	account.withdraw(25);
	REQUIRE(account.get_balance() == 75);

	account.withdraw(-25);
	REQUIRE(account.get_balance() == 75);
}

TEST_CASE("Test bank account deposit and withdraws")
{
    BankAccount account(100);
    REQUIRE(account.get_balance() == 100);

    account.deposit(25);
    REQUIRE(account.get_balance() == 125);

    account.withdraw(50);
    REQUIRE(account.get_balance() == 75);
}
-----------------------------------------------------------------------------------------------------------------------------	*/

TEST_CASE("Verify bank account default constructor")
{
	unique_ptr<BankAccount> account = make_unique<CheckingAccount>(500);

	REQUIRE(account->get_balance() == 500);
}

TEST_CASE("Verify bank account constructor")
{
	unique_ptr<BankAccount> account = make_unique<CheckingAccount>(1000);

	REQUIRE(account->get_balance() == 1000);
}

TEST_CASE("Verify bank account deposit")
{
	unique_ptr<BankAccount> account = make_unique<CheckingAccount>(100);

	REQUIRE(account->get_balance() == 100);

	account->deposit(50);
	REQUIRE(account->get_balance() == 150);

	account->deposit(-50);
	REQUIRE(account->get_balance() == 150);

}

TEST_CASE("Verify bank account withdraw")
{
	unique_ptr<BankAccount> account = make_unique<CheckingAccount>(100);

	REQUIRE(account->get_balance() == 100);

	account->withdraw(25);
	REQUIRE(account->get_balance() == 75);

	account->withdraw(-25);
	REQUIRE(account->get_balance() == 75);
}

TEST_CASE("Test bank account deposit and withdraws")
{
    unique_ptr<BankAccount> account = make_unique<CheckingAccount>(100);

    REQUIRE(account->get_balance() == 100);

    account->deposit(25);
    REQUIRE(account->get_balance() == 125);

    account->withdraw(50);
    REQUIRE(account->get_balance() == 75);
}
