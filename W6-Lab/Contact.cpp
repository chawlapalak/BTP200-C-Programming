#include<iostream>
#include<cstring>
#include"Contact.h"
#include<iomanip>

using namespace std;

namespace sict

{

	Contact::Contact()
	{
		name[0] = '\0';
		number = nullptr;
		size = 0; //safe-empty state
	}

	Contact::Contact(const char* Cname, const long long* Cnumber, int csize)
	{
		int country_code;
		int area_code;
		int main_no;
		int j = 0;

		name[0] = '\0';
		number = nullptr;
		size = 0; //safe-empty state

		//Allocate memory for phone no array
		if (Cnumber != nullptr && Cnumber[0] != '0')
		{
			number = new long long[csize];
		}

		//validate name
		if (Cname != nullptr && Cname[0] != '\0') {
			strncpy(name, Cname, 19);
			name[19] = '\0';
		}

		//Phone number validate
		for (int i = 0; i < csize; i++) {

			if (Cnumber[i] > 10000000000 && Cnumber[i] < 999999999999)
			{
				country_code = (Cnumber[i] / 10000000000);

				area_code = ((Cnumber[i] % 10000000000) / 10000000);

				main_no = Cnumber[i] % 10000000;


				if (country_code > 0 && country_code <= 19 &&
					area_code > 0 && area_code < 999 &&
					main_no >= 1000000 && main_no <= 99999999) {
					number[j] = Cnumber[i];
					j++;
				}
			}
			total = j;
		}

	}

	Contact::~Contact()
	{
		delete[] number;
	}

	bool Contact::isEmpty() const
	{
		if (name[0] == '\0' && number == nullptr && size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	void Contact::display() const

	{
		int country_code;
		int area_code;
		int main_no;
		int Part1_number;
		int Part2_number;

		if (isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << name << endl;
			if (number != nullptr && number[0] != '\0')
			{
				for (int j = 0; j < total; j++)
				{
					country_code = (number[j] / 10000000000);
					area_code = ((number[j] % 10000000000) / 10000000);
					main_no = number[j] % 10000000;

					//formatting phone_number
					Part1_number = main_no / 10000;
					Part2_number = main_no % 10000;
					cout << "(+" << country_code << ") " << area_code << " "
						<< setfill('0') << setw(3) << Part1_number << "-"
						<< setfill('0') << setw(4) << Part2_number << endl;
				}
				}
		}
	}
}