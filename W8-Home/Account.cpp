/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

#include "Account.h"

using namespace std;

namespace sict 
{

	void Account::set_safe_empty()
	{
		bal = 0;
	}

	Account::Account()
	{
		set_safe_empty();
	}

	Account::Account(double funds)
	{
		if (funds > 0)
		{
			bal = funds;
		}
		else
		{
			set_safe_empty();
		}
	}

	double Account::balance() const
	{
		return bal;
	}

	bool Account::credit(double amount)
	{
		if (amount > 0)
		{
			bal += amount;
			return true;
		}
		return false;
	}

	bool Account::debit(double amount)
	{
		if (amount > 0)
		{
			bal -= amount;
			return true;
		}
		return false;
	}

}
