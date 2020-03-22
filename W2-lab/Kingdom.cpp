/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 1 Feb 2018
// Author Palak Chawla	
// Description 
// This source file will display the input entered by the user.
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
// TODO: the sict namespace
using namespace std;
namespace sict
{
	// TODO:definition for display(...) 
	void display(const Kingdom &pKingdom)
	{
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}
}