// TODO: add file header comments here
/* Name : Palak Chawla
Student id : 118834175
BTP200SAA
Date : 15 Feb 2018
Email : pchawla5@myseneca.ca
Description : This is a source file checking the constructors ,member functions and their definitions.
*/
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include"Passenger.h"


// TODO: continue your namespace here
using namespace std;
namespace sict {

    // TODO: implement the default constructor here
	Passenger::Passenger() {
		//safe empty state
		Passenger_name[0] = '\0';
		Passenger_destination[0] = '\0';
		
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* passngr_Name, const char* passngr_Destination)
	{
		//safe empty state
		Passenger_name[0] = '\0';
		Passenger_destination[0] = '\0';
		//validation for non-empty string
		if (passngr_Name != nullptr && passngr_Destination != nullptr && passngr_Name[0] != 0 && passngr_Destination[0] != 0)
		{
			strcpy(Passenger_name, passngr_Name);
			strcpy(Passenger_destination, passngr_Destination);
		}
	}



    // TODO: implement isEmpty query here

	bool Passenger::isEmpty() const 
	{
		
		if (Passenger_name[0] == '\0' && Passenger_destination[0] == '\0')
		{
			 return true;
		}
		else 
		{
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
			cout << this->Passenger_destination << endl;

		}


	}

}