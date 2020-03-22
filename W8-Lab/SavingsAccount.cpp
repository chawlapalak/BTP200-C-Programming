/* Name : Palak chawla
Student id : 118834175
Sec : BTP200SAA
Date : 29 March 2018
Email : pchawla5@myseneca.ca*/

#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount() : Account() {
		interest_rate = 0;
	}

	SavingsAccount::SavingsAccount(double funds, double interest_rt) : Account(funds) {
		if (interest_rt > 0) {
			interest_rate = interest_rt;
		}
		else {
			interest_rate = 0; 
		}
	}

	void SavingsAccount::monthEnd()
	{
		double intr = Account::balance() * interest_rate;
		credit(intr);
			
	}

	void SavingsAccount::display(std::ostream &ostr) const
	{
		ostr << fixed;
		ostr << std::setprecision(2) << "Account type: Savings" << "\n";
		ostr << std::setprecision(2) << "Balance: $" << balance() << "\n";
		ostr << std::setprecision(2) << "Interest Rate (%): " << interest_rate * 100 << "\n";
	}
}

