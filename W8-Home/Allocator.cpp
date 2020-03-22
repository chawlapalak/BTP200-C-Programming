/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

#include "SavingsAccount.h" 
#include "ChequingAccount.h" 

namespace sict {

	// define interest rate
	//
	const double interest_rate = 0.05;
	const double transaction_fee = 0.50;
	const double monthly_fee = 2.00;


	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type_of_account, double initialBalance)
	{ 
		iAccount * iaccnt = nullptr;
		if (type_of_account[0] == 'S')
		{
			iaccnt = new SavingsAccount(initialBalance, interest_rate);
			
		}
		else if (type_of_account[0] == 'C') {
			iaccnt = new ChequingAccount(initialBalance, transaction_fee, monthly_fee);
		}

		return iaccnt;
	}







}
