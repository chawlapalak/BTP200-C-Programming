/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

// File" Product.cpp
// Description: Product class header
#include <iostream>
#include<cstring>
#include<iomanip>
#include "Product.h"
using namespace std;
namespace AMA {

	void Product::name(const char * name_of_product)
	{
		if (name_of_product != nullptr)
		{
			if (productName != nullptr)
			{
				delete[] productName;
			}
			int len = strlen(name_of_product);
			productName = new char[len + 1];
			strncpy(productName, name_of_product, len + 1);

		}
		else
		{
			delete[] productName;
			productName = nullptr;
			return;
		}
	}

	const char* Product::name() const
	{
		if (productName[0] != '\0')
		{
			return productName;
		}
		return nullptr;
	}

	const char* Product::sku() const
	{
		return productSKU;
	}

	const char * Product::unit() const
	{
		return productUnit;
	}

	bool Product::taxed() const
	{
		return taxableStatus;
	}

	double Product::price() const
	{
		return price_exclTax;
	}

	double Product::cost() const
	{
		return price_exclTax + (price_exclTax * CURR_TAX_RATE);
	}

	void Product::message(const char *msg)
	{
		err.message(msg);
	}

	bool Product::isClear() const
	{
		if (err.isClear())
			return true;
		else
			return false;
	}

	Product::Product(char type)
	{
		productType = type;
		productSKU[0] = '\0';
		productUnit[0] = '\0';
		productName = nullptr;
		curr_productQuantity = 0;
		productNeeded = 0;
		price_exclTax = 0;
		taxableStatus = true;
		err.clear();
	}


	Product::Product(const char * sku, const char * name_of_product, const char * unit, int qntity, bool taxbl, double price_ex_Tax, int qty_needed)
	{
		strncpy(productSKU, sku, max_sku_length);
		productName = nullptr;
		name(name_of_product);
		strncpy(productUnit, unit, max_unit_length);
		curr_productQuantity = qntity;
		taxableStatus = taxbl;
		price_exclTax = price_ex_Tax;
		productNeeded = qty_needed;
		err.clear();
	}

	Product::Product(const Product & rhs)
	{
		productType = rhs.productType;
		strncpy(productSKU, rhs.productSKU, max_sku_length);
		productName = nullptr;
		name(rhs.productName);
		strncpy(productUnit, rhs.productUnit, max_unit_length);
		curr_productQuantity = rhs.curr_productQuantity;
		taxableStatus = rhs.taxableStatus;
		price_exclTax = rhs.price_exclTax;
		productNeeded = rhs.productNeeded;
		if (!rhs.isClear())
		{
			err.message(rhs.err.message());
		}
	}

	Product & Product::operator=(const Product & rhs)
	{
		if (this != &rhs)
		{
			productType = rhs.productType;
			strncpy(productSKU, rhs.productSKU, max_sku_length);
			productName = nullptr;
			name(rhs.productName);
			strncpy(productUnit, rhs.productUnit, max_unit_length);
			curr_productQuantity = rhs.curr_productQuantity;
			taxableStatus = rhs.taxableStatus;
			price_exclTax = rhs.price_exclTax;
			productNeeded = rhs.productNeeded;
			if (!rhs.isClear())
			{
				err.message(rhs.err.message());
			}
		}
		return *this;
	}

	Product::~Product()
	{
		delete[] productName;
		productName = nullptr;
		err.clear();
	}

	std::fstream & Product::store(std::fstream & file, bool newLine) const
	{
		if (file.is_open())
			file << productType << ',' << productSKU << ',' << productName << ',' << productUnit;
		file << ',' << taxableStatus << ',' << price_exclTax << ',' << curr_productQuantity << ',' << productNeeded;
		if (newLine)
			file << endl;
		return file;
	}

	std::fstream & Product::load(std::fstream & file)
	{
		//Product rhs;
		//rhs.productName= new char[max_name_length + 1];
		char tempSku[max_sku_length];
		char tempName[max_name_length+1];
		char tempUnit[max_unit_length];
		double tempPrice;
		bool tempTax;
		int tempQuant;
		int tempQuantneeded;

		file.getline(tempSku, max_sku_length, ',');
		file.getline(tempName, max_name_length+1, ',');
		file.getline(tempUnit, max_unit_length, ',');
		file >> tempTax;
		file.ignore(1, ',');
		file >> tempPrice;
		file.ignore(1, ',');
		file >> tempQuant;
		file.ignore(1, ',');
		file >> tempQuantneeded;
		Product rhs(tempSku, tempName, tempUnit, tempQuant, tempTax, tempPrice, tempQuantneeded);
		*this = rhs;
		return file;
	}

	std::ostream & Product::write(std::ostream & os, bool linear) const
	{
		if (!isClear()) {
			os << err.message();
		}
		else {

			if (linear)
			{
				os << left << setw(max_sku_length)<< setfill(' ') << productSKU << '|';
				os << left << setw(20) << productName << '|';
				if (taxableStatus)
				{
					os << right << setw(7) << fixed << setprecision(2) << price_exclTax * (1 + CURR_TAX_RATE) << '|';
				}
				else
				{
					os << right << setw(7) << fixed << setprecision(2) << price_exclTax << '|';
				}
				os << right<< setw(4) << curr_productQuantity << '|';
				os << left << setw(10) << productUnit << '|';
				os << right << setw(4) << productNeeded << '|';
			}
			else
			{
				os << " Sku: " << productSKU <<endl;
				os << " Name (no spaces): " << productName << endl;
				os << " Price: " << price_exclTax <<endl;
				if (taxableStatus)
				{
					os << " Price after tax: " << price_exclTax * (1 + CURR_TAX_RATE) << endl;
				}
				else
				{
					os << " Price after tax: "<< "N/A" << endl;
				}
				os << " Quantity on Hand: " << curr_productQuantity <<" " <<productUnit << endl
					<< " Quantity needed: " << productNeeded;
			}
		}
		return os;
	}

	std::istream & Product::read(std::istream & is)
	{
		char sku[max_sku_length + 1];
		char* productNm;
		char unit[max_unit_length + 1];
		int quantity;
		int quantityNeeded;
		double price;
		char taxable[2];

		productNm = new char[max_name_length + 1];

		cout << " Sku: ";
		is >> sku;
		cout << " Name (no spaces): ";
		is >> productNm;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> taxable;
		if (taxable[0] == 'Y' || taxable[0] == 'y' || taxable[0] == 'N' || taxable[0] == 'n') {
			err.clear();
			if (taxable[0] == 'Y' || taxable[0] == 'y')
			{
				taxableStatus = true;
			}
			else
			{
				taxableStatus = false;
			}
			cout << " Price: ";
			is >> price;
			if (is.fail()) {
				err.message("Invalid Price Entry");
			}
			else
			{
				price_exclTax = price;
				cout << " Quantity on hand: ";
				is >> quantity;
				if (is.fail())
				{
					err.message("Invalid Quantity Entry");
				}
				else
				{
					curr_productQuantity = quantity;
					cout << " Quantity needed: ";
					is >> quantityNeeded;
					if (is.fail())
					{
						err.message("Invalid Quantity Needed Entry");
					}
					else
					{
						productNeeded = quantityNeeded;
					}
				}
			}
		}
		else {
			err.message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
		}

		if (isClear())
		{
			strncpy(productSKU, sku, max_sku_length);
			name(productNm);
			strncpy(productUnit, unit, max_unit_length);

		}

		delete[] productNm;
		is.ignore(2000, '\n');
		return is;
	}

	bool Product::operator==(const char * sku) const
	{
		if (strcmp(productSKU, sku) == 0)
			return true;
		return false;
	}

	double Product::total_cost() const
	{
		if (taxableStatus == true)
		{
			return static_cast<double>(curr_productQuantity) * price_exclTax * (1 + CURR_TAX_RATE);
		}
		else
		{
			return static_cast<double>(curr_productQuantity) * price_exclTax;
		}
	}

	void Product::quantity(int qtyonHand)
	{
		curr_productQuantity = qtyonHand;
	}

	bool Product::isEmpty() const
	{
		if (productUnit == nullptr)
			return true;
		return false;
	}

	int Product::qtyNeeded() const
	{
		return productNeeded;
	}

	int Product::quantity() const
	{
		return curr_productQuantity;
	}

	bool Product::operator>(const char *sku) const
	{
		if (strcmp(productSKU, sku) > 0)
			return true;
		else
			return false;
	}

	bool Product::operator>(const iProduct &rhs) const
	{
		if (strcmp(productName, rhs.name()) > 0)
			return true;
		else
			return false;
	}

	int Product::operator+=(int unitsTobeAdded)
	{
		if (unitsTobeAdded > 0)
		{
			curr_productQuantity += unitsTobeAdded;
			return curr_productQuantity;
		}
		else
		{
			return curr_productQuantity;
		}
	}

	std::ostream & operator<<(std::ostream & os, const iProduct & rhs)
	{
		return rhs.write(os, true);
	}


	std::istream & operator>>(std::istream & is, iProduct & rhs)
	{
		rhs.read(is);
		return is;
	}

	double operator+=(double & dl, const iProduct & rhs)
	{
		dl += rhs.total_cost();
		return dl;
	}
}