/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms3
email : pchawla5@myseneca.ca
24 March 2019*/

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include<iostream>

namespace ama
{
	class ErrorState 
	{
	private:
		char* msg;
		void safeEmpty();

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		~ErrorState();
		operator bool() const;
		ErrorState& operator=(const char* pText);
		void message(const char* pText);
		const char* message() const;
		};
	std::ostream& operator<<(std::ostream& os, const ErrorState & e);

}
#endif