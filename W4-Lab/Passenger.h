// TODO: add file header comments here
/* Name : Palak Chawla
	Student id : 118834175
	BTP200SAA
	Date : 15 Feb 2018
	Email : pchawla5@myseneca.ca
	Description : This is a header file having a class with a private and public class with declarations and constructors.
	*/
// TODO: add header file guard here
#ifndef SICT_PASSENGER_H_
#define SICT_PASSENGER_H_
// TODO: declare your namespace here
namespace sict {
	const int Max_size = 32;
	// TODO: define the Passenger class here
	class Passenger {
		// TODO: add the class the attributes,
	private:
		char Passenger_name[Max_size];
		char Passenger_destination[Max_size];
	public:
		
		Passenger();
		Passenger(const char* passngr_Name, const char* passngr_Destination);
		bool isEmpty() const;
		void display() const;
	};
}
#endif