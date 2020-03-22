// TODO: add file header comments here
/* Name : Palak Chawla
Student id : 118834175
BTP200SAA
Date : 19 Feb 2018
Email : pchawla5@myseneca.ca
Description : This is a header file declaring the class and its constructors ,member functions and their definitions.
*/
// TODO: add header file guard here
#ifndef SICT_PASSENGER_H_
#define SICT_PASSENGER_H_
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		// TODO: add the class the attributes,
	private:
		char Passenger_name[32];
		char Passenger_destination[32];
		int Passenger_departYear;
		int Passenger_departMonth;
		int Passenger_departDay;
		void Construct();
	public:
		
		Passenger();
		Passenger(const char* passngr_Name, const char* passngr_Destination);
		Passenger(const char* passngr_Name, const char* passngr_Destination,const int passngr_Year, const int passngr_Month, const int passngr_Day);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;

	};
}
#endif