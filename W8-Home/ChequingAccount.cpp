// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////
#include <iomanip>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double funds, double transactFee , double mnthEndFee):Account(funds)
	{
		if (transactFee > 0)
		{
			transactionFee = transactFee;
		}
		else
		{
			transactionFee = 0.0;
		}

		if (mnthEndFee > 0)
		{
			monthEndFee = mnthEndFee;
		}
		else
		{
			monthEndFee = 0.0;
		}
	}



	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double amount)
	{
		bool status=false;
		status = Account::credit(amount);
		Account::debit(transactionFee);
		return status;
	}


	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double amount)
	{
		bool status = false;
		status = Account::debit(amount+transactionFee);
		return status;
	}




	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd()
	{
		Account::debit(monthEndFee+transactionFee);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream & ostr) const
	{
		ostr << fixed;
		ostr << std::setprecision(2) << "Account type: Chequing" << endl;
		ostr << std::setprecision(2) << "Balance: $" << balance() << endl;
		ostr << std::setprecision(2) << "Per Transaction Fee: " << transactionFee << endl;
		ostr << std::setprecision(2) << "Monthly Fee: " << monthEndFee << endl;


	}




	
	
	
	

	
}