//Palak Chawla
// 118834175
//BTP200SAA
//18 March 2018


#include <iostream>
#include <iomanip> 
#include "Contact.h"
#include <cstring>

using namespace std;
namespace sict{
	void Contact::set_safe_empty()
	{
		//Safe Empty State 
		name[0] = '\0';
		phoneNo = nullptr;
		num_of_phoneNo = 0;
	}
	Contact::Contact()
	{
		set_safe_empty();
	}

	Contact::Contact(const char *customer_name, long long *customer_phone_nos, int num)
	{
		//Safe Empty State
		set_safe_empty();
		
		int country_code;
		int area_code;
		int phone_number;
		int j = 0;

		if (customer_phone_nos != nullptr && customer_phone_nos[0] != '\0') {
			phoneNo = new long long[num];
		}

		//validate name
		if (customer_name != nullptr && customer_name[0] != '\0') {
			strncpy(name, customer_name, 19);
			name[19] = '\0'; 
		}

		//Phone number validate
		for (int i = 0; i < num; i++) {
			
			if (customer_phone_nos[i] > 10000000000 && customer_phone_nos[i] < 999999999999) 
			{
				country_code = (customer_phone_nos[i] / 10000000000);
				area_code = ((customer_phone_nos[i] % 10000000000) / 10000000);
				phone_number = customer_phone_nos[i] % 10000000;
				
				if (country_code > 0 && country_code <= 99 &&
					area_code > 0 && area_code < 999 &&
					phone_number >= 1000000 && phone_number <= 99999999) {
					phoneNo[j] = customer_phone_nos[i];
					j++;
					num_of_phoneNo++;
				}
			}
			num_of_phoneNo = j;
		}

	}

	Contact::Contact(const Contact & rhs)
	{
		set_safe_empty();
		
		//copy name
		strncpy(name, rhs.name, 19);
		name[19] = '\0';
		
		//copy no of phoneNo
		num_of_phoneNo = rhs.num_of_phoneNo;

		//copy phoneNo
		if (rhs.phoneNo != nullptr && rhs.phoneNo[0] != '\0') {
			phoneNo = new long long[num_of_phoneNo];
			for (int i = 0; i < num_of_phoneNo; i ++) {
					phoneNo[i] = rhs.phoneNo[i];
			}
		}
	}

	Contact & Contact::operator=(const Contact & rhs)
	{
		if (this != &rhs)
		{
			//assign name
			strncpy(name, rhs.name, 19);
			name[19] = '\0';
			
			//assign no of phoneNo
			num_of_phoneNo = rhs.num_of_phoneNo;
			
			//clear existing phone Nos
			delete[] phoneNo;
			phoneNo = nullptr;
			
			//copy phone nos from rhs
			if (rhs.phoneNo != nullptr)
			 {

				phoneNo = new long long[num_of_phoneNo];

				for (int i = 0; i < num_of_phoneNo; i++)
					phoneNo[i] = rhs.phoneNo[i];
			}
			
		}
		return *this;
	}

	Contact & Contact::operator+=(long long phoneNumber)
	{
		if (name != nullptr && name[0] != '\0')
		{
			int country_code;
			int area_code;
			int phone_number;


			if (phoneNumber > 10000000000 && phoneNumber < 999999999999)
			{
				country_code = (phoneNumber / 10000000000);
				area_code = ((phoneNumber % 10000000000) / 10000000);
				phone_number = phoneNumber % 10000000;

				if (country_code > 0 && country_code <= 19 &&
					area_code > 0 && area_code < 999 &&
					phone_number >= 1000000 && phone_number <= 99999999)
				{
					num_of_phoneNo += 1;
					long long* tmp = new long long[num_of_phoneNo];
					for (int i = 0; i < num_of_phoneNo - 1; i++) {
						tmp[i] = phoneNo[i];
					}
					//cout << phoneNumber << endl;
					tmp[num_of_phoneNo - 1] = phoneNumber;
					//cout << tmp[num_of_phoneNo - 1];
					
					delete[] phoneNo;
					phoneNo = nullptr;

					phoneNo = new long long[num_of_phoneNo];

					
					for (int i = 0; i < num_of_phoneNo; i += 1) {
						phoneNo[i] = tmp[i];
					}

					/*for (int i = 0; i < num_of_phoneNo; i += 1) {
						cout << phoneNo[i] << endl;
					}*/
					delete[] tmp;
					tmp = nullptr;

					//total = num_of_phoneNo;
				}

			}
		}
			return *this;
	}

	Contact::~Contact()
	{
		delete[] phoneNo;
	}

	bool Contact::isEmpty() const
	{
		if (name[0] == '\0' && phoneNo == nullptr && num_of_phoneNo == 0)
		{
			return true;
		}
		return false;
	}

	void Contact::display()
	{
		int country_code;
		int area_code;
		int phone_number;
		
		int Part1_of_Phone_number;
		int Part2_of_Phone_number;

		if (isEmpty()) 
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			
			cout << name << endl;
			if (phoneNo != nullptr && phoneNo[0] != '\0') {
				for (int j = 0; j < num_of_phoneNo; j++) {

					country_code = (phoneNo[j] / 10000000000);
					area_code = ((phoneNo[j] % 10000000000) / 10000000);
					phone_number = phoneNo[j] % 10000000;

					//formatting phone_number
					Part1_of_Phone_number = phone_number / 10000;
					Part2_of_Phone_number = phone_number % 10000;
					cout << "(+" << country_code << ") " << area_code << " " << setfill('0') << setw(3)<< Part1_of_Phone_number << "-" << setfill('0') << setw(4)<< Part2_of_Phone_number << endl;
				}
			}
		}         
	}

}



