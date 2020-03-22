/*
Name : Palak Chawla
Section : BTP200SAA
Date : 22 Feb 2018
Student ID: 118834175
Email : pchawla5@myseneca.ca
Lab 5 : In Lab
*/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace

namespace sict
{
	// TODO: define the Fraction class
	class Fraction 
	{
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
		bool isEmpty() const;
		void display() const;
		Fraction();
		Fraction(int num, int denum);
	
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;

	};
}
#endif