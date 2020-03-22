
/*
// Workshop 3: Classes and Privacy
// w3_at_home.cpp
// Version 2.1
// 2018/02/13
// Palak Chawla
*/
#include <iostream>
#include "CRA_Account.h"
#include<cstring>
#include<iomanip>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {


	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		
		if (m_sin <= max_sin && m_sin >= min_sin && m_familyName[0] != 0 && m_givenName[0] != 0)
		{
			int Total = 0;
			int TotalEven = 0;
			int TotalOdd = 0;
			int _sin = sin;

			for (int i = 0; i < 4; i++)
			{
				int X = (_sin / 10) % 10;
				TotalEven += X;
				_sin = _sin / 100;
			
				TotalOdd += X;
				_sin = _sin / 100;
			}

			Total = TotalEven + TotalOdd;
			if ((Total % 10 + _sin % 10) % 10 != 0)
			{
				strncpy(m_familyName, familyName, max_name_length + 1);
				m_familyName[max_name_length] = '\0';
				strncpy(m_givenName, givenName, max_name_length + 1);
				m_givenName[max_name_length] = '\0';
				m_sin = sin;
				m_year = 0;
			}
			else
			{
				m_familyName[0] = 0;
				m_givenName[0] = 0;
				m_sin = 0;
				m_year = 0;
			}
		}
	}
	
	void CRA_Account::set(int year, double balance)
	{
		if ( m_year < max_yrs)
		{
			m_Tyears[m_year] = year;
			m_balRef[m_year] = balance;
			m_year++;

		}
	}

	bool CRA_Account::isEmpty() const
	{
		if (m_sin <= max_sin || m_sin >= min_sin || m_familyName[0] != 0 || m_givenName[0] != 0)
		{
			return true;
		}
		else
		{
			return false;

		}
	}

	void CRA_Account::display() const
	{
		if (!isEmpty())
		{
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
			cout << fixed << setprecision(2);

			for (int i = 0; i < max_yrs; i++)
			{
				cout << "Year (" << m_Tyears[i] << ") ";
				if (m_balRef[i] > 2.00)
				{
					cout << "balance owing: " << m_balRef[i] << endl;

				}
				else
					if (m_balRef[i] < -2.00)
					{
						cout << "refund due: " << m_balRef[i] << endl;
					}
					else
					{
						cout << "No balance owing or refund due!" << endl;

					}
			}
		}

		else
		{
		cout << "Account object is empty!" << endl;
		
		}
		
	}
	}


