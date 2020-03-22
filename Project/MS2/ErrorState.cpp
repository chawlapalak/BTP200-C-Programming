// Final Project Milestone 2
//
//Name : Palak Chawla
//ID: 118834175
//email : pchawla5@myseneca.ca
//Sub: BTP200SAA
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;

namespace AMA {
	ErrorState::ErrorState(const char * errorMessage)
	{
		if (errorMessage != nullptr && errorMessage[0] != 0)
		{
			msg = nullptr;
			message(errorMessage);
		}
		else
		{
			msg = nullptr;
		}
	}

	void ErrorState::clear()
	{
		delete[] msg;
		msg = nullptr;
	}

	bool ErrorState::isClear() const
	{
		if (msg == nullptr)
			return true;
		return false;
	}

	void ErrorState::message(const char * str)
	{
		clear();
		msg = new char[strlen(str) + 1];
		strcpy(msg, str);
	}

	const char * ErrorState::message() const
	{
		return msg;
	}

	std::ostream & operator<<(std::ostream & ostr, const ErrorState & es)
	{
		if (!es.isClear()) {
			ostr << es.message();
		}
		return ostr;
	}

	ErrorState::~ErrorState()
	{
		delete[]msg;
	}

}

