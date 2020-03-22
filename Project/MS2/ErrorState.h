// Final Project Milestone 2
//
// Version 1.0
// 
// 
// Name : Palak Chawla
//ID: 118834175
//email : pchawla5@myseneca.ca
//Sub: BTP200SAA
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>
namespace AMA {

	class ErrorState {
	private:
		char* msg;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);

		ErrorState(const ErrorState& em) = delete;

		ErrorState& operator=(const ErrorState& em) = delete;

		virtual ~ErrorState();

		void clear();

		bool isClear() const;

		void message(const char* str);

		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& ostr, const ErrorState& es);
}
#endif
