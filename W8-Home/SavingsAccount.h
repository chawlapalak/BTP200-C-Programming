/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

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
