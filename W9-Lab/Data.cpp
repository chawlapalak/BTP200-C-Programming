/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

#include <iostream>
#include<iomanip>
#include "Data.h"
using namespace std;
namespace sict {

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int population_growth = population[n - 1] - population[0];
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is "
			<<fixed << setprecision(2) << static_cast<double>(population_growth) / 1000000 << " million" << endl;




		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		auto violentCrime_intial = violentCrime[0];
		auto violentCrime_end = violentCrime[n - 1];
		const char *trend =  nullptr;
		if (violentCrime_intial < violentCrime_end)
		{
			trend = "up";
		}  
		else
		{
			trend = "down";
		}
		cout << "Violent Crime trend is " << trend << endl;





		// Q3 print the GTA number accurate to 0 decimal places
		double gta = 0; 
		gta = average(grandTheftAuto, n);
		cout << "There are " << fixed << setprecision(2) << gta/1000000 << " million Grand Theft Auto incidents on average a year" << endl;



		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;


	}
}