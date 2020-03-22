/* Name : Palak chawla
Student id : 118834175
Sec : BTP200SAA
Date : 29 March 2018
Email : pchawla5@myseneca.ca*/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount :public Account
	{
	private:
		double interest_rate;
	
	public:
		SavingsAccount();
			// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

			// TODO: perform month end transactions
		void monthEnd();

			// TODO: display inserts the account information into an ostream			
		void display(std::ostream&) const;
	};
}
#endif
