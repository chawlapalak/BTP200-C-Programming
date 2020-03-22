
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account 
	{
	private:
		int m_sin;
		char m_familyName[max_name_length + 1];
		char m_givenName[max_name_length + 1];
		int  m_Tyears[max_yrs];
		double m_balRef[max_yrs];
		int  m_year;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
	};

}
#endif