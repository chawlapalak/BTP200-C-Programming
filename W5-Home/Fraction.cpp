// TODO: insert header files
#include "Fraction.h"

// TODO: continue the namespace
using namespace std;
namespace sict {

// TODO: implement the default constructor
	Fraction::Fraction() {
		denominator = 0;              // safe empty state
	}

// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int denum) 
	{
		if (num >= 0 && denum > 0) {
			numerator = num;
			denominator = denum;
			reduce();
		}
		else
			denominator = 0;    // safe empty state         
	}
	
// TODO: implement the max query
	int Fraction::max()const
	{
		if (numerator >= denominator)
			return numerator;
		else
			return denominator;
	}

// TODO: implement the min query
	int Fraction::min()const
	{
		if (numerator >= denominator)
			return denominator;
		else
			return numerator;
	}

// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}


// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int temp = gcd();
		numerator = numerator / temp;
		denominator = denominator / temp;
	}

// TODO: implement the display query
	void Fraction::display()
	{
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (denominator == 1) {
			cout << numerator;
		}
		else {
			cout << numerator << "/" << denominator;
		}
	}

// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		
		if (denominator == 0)
	 {
			return true;
		}
		else {
			return false;
		}
		
	}

	bool Fraction::isValid(const Fraction & rhs) const
	{
		if (isEmpty() || rhs.isEmpty())
			return true;
		return false;
	}

	bool Fraction::bothValid(const Fraction & rhs) const
	{
		if (!isEmpty() && !rhs.isEmpty())
			return true;
		return false;
	}

// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction & rhs) 
	{
		Fraction newObj;

		if (isValid(rhs)) 
		{
			newObj.denominator = 0;
		}

		if (bothValid(rhs))
		{
			newObj.denominator = denominator * rhs.denominator;
			newObj.numerator = (numerator*rhs.denominator) + (rhs.numerator*denominator);
			newObj.reduce();
		}
		return newObj;
	}

	Fraction Fraction::operator*(const Fraction & rhs) 
	{
		Fraction newObj;
		if (isValid(rhs))
		{
			newObj.denominator = 0;
		}
		if (bothValid(rhs))
		{
			newObj.numerator = numerator * rhs.numerator;
			newObj.denominator = denominator * rhs.denominator;
		}
		return newObj;
	}

	bool Fraction::operator==(const Fraction & rhs) const
	{
		bool temp = false;

		if (isValid(rhs)) 
		{
			temp = false;
		}
		if (bothValid(rhs))
		{
			if (numerator*rhs.denominator == rhs.numerator*denominator) 
			{
				temp = true;
			}
		}
		return temp;
	}

	bool Fraction::operator!=(const Fraction & rhs) const
	{
		bool temp = false;

		if (isValid(rhs)) 
		{
			temp = false;
		}
		if (bothValid(rhs))
		{
			if (*this == rhs) 
			{
				temp = false;
			}
			else
			{
				temp = true;
			}
		}
		return temp;
	}

	Fraction& Fraction::operator+=(const Fraction & rhs) 
	{	

		if (isValid(rhs)) 
		{
			this->denominator = 0;
		}
		if (bothValid(rhs)) {
			
			numerator = (numerator * (rhs.denominator)) + ((rhs.numerator) * denominator);
			denominator = denominator * rhs.denominator;
			reduce();
		}
		return *this;
	}

}