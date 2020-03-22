/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 5 Feb 2018
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
	void display(const Kingdom& pKingdom)
	{
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}
	void display(Kingdom pKingdomN[], int Size)
	{

		int PT = 0;
		cout << "------------------------------\n";
		cout << "Kingdoms are\n";
		cout << "------------------------------" << endl;

		for (int i = 0; i < Size ; i++)
		{
			cout << (i + 1) << ". ";
			display(pKingdomN[i]);
			PT = PT + pKingdomN[i].m_population;
		}

		PT = pKingdomN[0].m_population + pKingdomN[1].m_population + pKingdomN[2].m_population;

		cout<< "------------------------------\n"
			<< "Total population of all Kingdoms: " << PT
			<< "\n------------------------------\n" << endl;


	}
}