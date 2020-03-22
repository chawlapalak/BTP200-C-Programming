/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms3
email : pchawla5@myseneca.ca
24 March 2019*/

#include<iostream>
#include<cstring>
#include"ErrorState.h"

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

namespace ama 
{


	void ErrorState::safeEmpty()
	{
		msg = nullptr;
		
	}

	ErrorState::ErrorState(const char * errorMessage)
	{
		if (errorMessage == nullptr || errorMessage[0] == '\0') 
		{
			safeEmpty();
		}
		else
		{
			msg = new char[strlen(errorMessage)+1];
			strcpy(msg, errorMessage);
		}
	}

	ErrorState::~ErrorState()
	{
		delete[] msg;
		msg = nullptr;
	}

	ErrorState::operator bool() const
	{
		if (msg != nullptr)
		{
			return true;
		}
		return false;
	}

	ErrorState & ErrorState::operator=(const char * pText)
	{
		message(pText);
		return *this;
	}

	void ErrorState::message(const char * pText)
	{
		delete[] msg;
		msg = nullptr;
		if (pText == nullptr || pText[0] == '\0')
		{
			safeEmpty();
		}
		else
		{
			msg = new char[strlen(pText) + 1];
			strcpy(msg, pText);
		}

	}

	const char * ErrorState::message() const
	{
		if (msg == nullptr) 
		{
			return nullptr;
		}
		return msg;
			
	}
	std::ostream & operator<<(std::ostream & os, const ErrorState & e)
	{
		if (e)
		{
			os <<e.message();
		}
		return os;

	}
}