#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict
{
	class Contact
	{
	public:
		Contact();
		Contact(const char* cname , const long long* number,int );
		~Contact();
		bool isEmpty() const;
		void display() const;

	private:
		char name[20];
		long long* number;
		int size;
		int total;
	};

}
#endif // !SICT_CONTACT_H
