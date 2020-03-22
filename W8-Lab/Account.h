/* Name : Palak chawla
Student id : 118834175
Sec : BTP200SAA
Date : 29 March 2018
Email : pchawla5@myseneca.ca*/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount
	{
	private:
		double bal;

	protected:
		double balance() const;

	public:
		
		void set_safe_empty();
		Account();
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
	};


}
#endif
