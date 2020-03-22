/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

// File" Product.cpp
// Description: Perishable class header
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Perishable.h"
using namespace std;
namespace AMA {
	Perishable::Perishable() : Product('P')
	{
		expiry_date = Date();
	}
	std::fstream & Perishable::store(std::fstream & file, bool newLine) const
	{
		Product::store(file, false);
		file << "," << expiry_date;
		if (newLine) 
		{ 
			file << endl; 
		}
		return file;
	}
	std::fstream & Perishable::load(std::fstream & file)
	{
		 
		Product::load(file);
		file.ignore(1);
		expiry_date.read(file);
		return file;
	}
	std::ostream & Perishable::write(std::ostream & os, bool linear) const
	{
		Product::write(os, linear);
		if (isClear()) {
			if (linear) {
				expiry_date.write(os);
			}
			else {
				os << endl;
				os << " Expiry date: ";
				expiry_date.write(os);
			}
		}
		return os;
	}
	std::istream & Perishable::read(std::istream & is)
	{
		Product::read(is);
		if (isClear()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			Date temp;
			temp.read(is);

			if (temp.errCode() == CIN_FAILED) {
				message("Invalid Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == YEAR_ERROR) {
				message("Invalid Year in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == MON_ERROR) {
				message("Invalid Month in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == DAY_ERROR) {
				message("Invalid Day in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else { expiry_date = temp; }
		}
		return is;
	}
	const Date & Perishable::expiry() const
	{
		return expiry_date;
	}
}