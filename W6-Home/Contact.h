#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H

namespace sict {
class Contact
 {
	private:
		char name[21];
		long long* phoneNo;
		int num_of_phoneNo;
		//int total;
		void set_safe_empty();
	public:
		Contact();
		Contact(const char*, long long*, int);
		Contact(const Contact& rhs);
		Contact& operator=(const Contact& rhs);
		Contact& operator+=(long long phoneNumber);
		~Contact();
		bool isEmpty() const;
		void display();
 };
}





















#endif