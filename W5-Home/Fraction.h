// TODO: header file guard
#ifndef SICT_Fraction_H__
#define SICT_Fraction_H__

#include <iostream>


// TODO: create namespace
using namespace std;

namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
	private:
		int numerator;
		int denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;


	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int num, int denum);
		void display();
		bool isEmpty() const;
		bool isValid(const Fraction & rhs)const;
		bool bothValid(const Fraction & rhs)const;

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction & rhs);

		// TODO: declare the * operator overload
		Fraction operator*(const Fraction & rhs) ;
		
		// TODO: declare the == operator overload
		bool operator==(const Fraction & rhs) const;

		// TODO: declare the != operator overload
		bool operator!=(const Fraction & rhs) const;

		// TODO: declare the += operator overload
		Fraction& operator+=(const Fraction & rhs);

	};
}
#endif