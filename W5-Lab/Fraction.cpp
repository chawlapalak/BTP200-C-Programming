/*
Name : Palak Chawla
Section : BTP200SAA
Date : 22 Feb 2018
Student ID: 118834175
Email : pchawla5@myseneca.ca
Lab 5 : In Lab
*/
// TODO: insert header files
#include<iostream>
#include<cstring>
#include"Fraction.h"
using namespace std;

// TODO: continue the namespace
namespace sict
{
	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		denominator = 0;              // safe empty state
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int denum)
	{
		if (num >= 0 && denum >= 0)
		{
			numerator = num;
			denominator = denum;
			reduce();
		}
		else
			denominator = 0;    // safe empty state 
	}
	// TODO: implement the max query
	int Fraction::max() const
	{
		if (numerator >= denominator)
		{
			return numerator;
	}
		else
		{
			return denominator;
		}
	}
	// TODO: implement the min query
	int Fraction::min() const
	{
		if (numerator <= denominator)
		{
			return numerator;
		}
		else
		{
			return denominator;
		}
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const
	{
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) 
		{ // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) 
			{
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() 
	{
		int tmp = gcd();
		numerator /= tmp;
		denominator /= tmp;

	}
	// TODO: implement the display query

	void Fraction::display() const
	{
		if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else 
			if (denominator == 1)
			{
				cout << numerator;
			}
			else
			{
				cout << numerator << "/" << denominator ;
			}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		if (denominator == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const
	{
		Fraction newObj;

		if (isEmpty() || rhs.isEmpty())
		{
			newObj.denominator = 0;
		}

		if (!isEmpty() && !rhs.isEmpty()) 
		{
			newObj.denominator = denominator * rhs.denominator;
			newObj.numerator = (numerator*rhs.denominator) + (rhs.numerator*denominator);
			newObj.reduce();
		}
		return newObj;
	}
}