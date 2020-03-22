
/* Name : Palak chawla
Student id : 118834175
Sec : BTP200SAA
Date : 29 March 2018
Email : pchawla5@myseneca.ca*/

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
