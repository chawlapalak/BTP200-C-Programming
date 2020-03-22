// TODO: add file header comments here
/* Name : Palak Chawla
Student id : 118834175
BTP200SAA
Date : 19 Feb 2018
Email : pchawla5@myseneca.ca
Description : This is a source file checking the constructors ,member functions and their definitions.
*/
// TODO: add your headers here

#include <iostream>
#include <cstring>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;
namespace sict {
	void Passenger::Construct()
	{
		Passenger_name[0] = '\0';
		Passenger_destination[0] = '\0';
		Passenger_departYear = 0;
		Passenger_departMonth = 0;
		Passenger_departDay = 0;
	}
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		//safe empty state
		Construct();
		
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* passngr_Name, const char* passngr_Destination) {

		//validation for non-empty string
		if (passngr_Name != nullptr && passngr_Destination != nullptr && passngr_Name[0] != 0 && passngr_Destination[0] != 0)
		{
			//safe empty state
			strcpy(Passenger_name, passngr_Name);
			strcpy(Passenger_destination, passngr_Destination);
			Passenger_departYear = 2017;
			Passenger_departMonth = 07;
			Passenger_departDay = 1;


		}
		else
		{
			//safe empty state
			Construct();
		}
	}

	Passenger::Passenger(const char * passngr_Name, const char * passngr_Destination, const int passngr_Year, const int passngr_Month, const int passngr_Day)
	{
		

		//validation for non empty string and departure date
		if (passngr_Name != nullptr && passngr_Destination != nullptr && passngr_Name[0] != 0 && passngr_Destination[0] != 0 && passngr_Year >= 2017 && passngr_Year <= 2020 && passngr_Month >= 1 && passngr_Month <= 12 && passngr_Day >= 1 && passngr_Day <= 31)
		{
			//safe empty state
			strcpy(Passenger_name, passngr_Name);
			strcpy(Passenger_destination, passngr_Destination);
			Passenger_departYear = passngr_Year;
			Passenger_departMonth = passngr_Month;
			Passenger_departDay = passngr_Day;


		}
		else
		{
			Construct();
		}
	}



    // TODO: implement isEmpty query here

	bool Passenger::isEmpty() const {
		
		if (Passenger_name[0] == '\0' &&
			Passenger_destination[0] == '\0') {
			 return true;
		}
		else {
			return false;
		}
		
	}

    // TODO: implement display query here

	void Passenger::display() const {

		if (this->isEmpty())
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << this->Passenger_name;
			cout << " - ";
			cout << this->Passenger_destination;
			cout << " on ";
			cout << this->Passenger_departYear;
			cout << "/0";
			cout << this->Passenger_departMonth;
			cout << "/";
			cout << this->Passenger_departDay<< endl;
			

		}


	}

	const char * Passenger::name() const
	{
		return this->Passenger_name;
	}

	bool Passenger::canTravelWith(const Passenger & other_Passenger) const
	{
		if (Passenger_departYear == other_Passenger.Passenger_departYear && Passenger_departMonth == other_Passenger.Passenger_departMonth && Passenger_departDay == other_Passenger.Passenger_departDay && strcmp(Passenger_destination, other_Passenger.Passenger_destination) == 0) {
			return true;
		}
		else {
			return false;
		}
		
	}

}