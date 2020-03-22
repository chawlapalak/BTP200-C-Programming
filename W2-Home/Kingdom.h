/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 5 Feb 2018
// Author Palak Chawla
// Description
// This is a header file for function prototypes
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H


// TODO: sict namespace
namespace sict
{
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		char m_name[33];
		int m_population;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom &pKingdom);

	void display( Kingdom pKingdomN[], int Size);

}

#endif