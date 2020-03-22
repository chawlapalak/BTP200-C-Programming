#include <iostream>
#include "CRA_Account.h"
#include<cstring>

using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		if (sin <= max_sin && sin >= min_sin)
		{
			strncpy(m_familyName, familyName, max_name_length + 1);
			m_familyName[max_name_length] = '\0';
			strncpy(m_givenName, givenName, max_name_length + 1);
			m_givenName[max_name_length] = '\0';
			m_sin = sin;
		}
		else
		{
			m_familyName[0] = 0;
			m_givenName[0] = 0;
			m_sin = 0;
		}

	}

	bool CRA_Account::isEmpty() const
	{
		return m_sin == 0;

	}

	void CRA_Account::display() const
	{
		if (!isEmpty())
		{
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
			
		}
		else
		{
			cout << "Account object is empty!" << endl;

		}
	}


	
}