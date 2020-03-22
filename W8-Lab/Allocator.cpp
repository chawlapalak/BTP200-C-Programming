/* Name : Palak chawla
Student id : 118834175
Sec : BTP200SAA
Date : 29 March 2018
Email : pchawla5@myseneca.ca*/

#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double interest_rate = 0.05;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type_of_account, double initialBalance)
	{ 
		iAccount * iaccnt = nullptr;
		if (type_of_account[0] == 'S')
		{
			iaccnt = new SavingsAccount(initialBalance, interest_rate);
			
		}
		return iaccnt;
	}







}
