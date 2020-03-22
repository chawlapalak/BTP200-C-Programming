/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms3
email : pchawla5@myseneca.ca
24 March 2019*/

#include<iomanip>
#include "Product.h"
#include"ErrorState.h"

using namespace std;

namespace ama {

    void ama::Product::setSafeEmpty()
	{
		prSKU[0] = '\0';
		prUnit[0] = '\0';
		prName = nullptr;
		quantityOnHand = 0;
		quantityNeeded = 0;
		prodPriceBeforeTax = 0;
		taxStatus = true;
	}
	void ama::Product::message(const char * pText)
	{
		es.message(pText);
	}

	bool ama::Product::isClear() const
	{
		return es;
	}

	Product::Product(const char ptype ):type(ptype)
	{
        setSafeEmpty();
	}

	Product::Product(const char * sku, const char * name, const char * unit, double priceBeforeTax, int qtyNeeded, int qtyOnHand, bool taxable):Product()
	{
        if (name != nullptr)
		{
            setName(name);
            strncpy(prSKU, sku, max_length_sku);
            prSKU[max_length_sku] = '\0';
            strncpy(prUnit, unit, max_length_unit);
            prUnit[max_length_unit] = '\0';
            quantityNeeded = qtyNeeded;
            quantityOnHand = qtyOnHand;
            prodPriceBeforeTax = priceBeforeTax;
            taxStatus= taxable;
		}
        
	}

	Product::Product(const Product & other)
	{
		
		if (!other.isEmpty())
		{
            type = other.type;
            strncpy(prSKU, other.prSKU, max_length_sku);
            prSKU[max_length_sku] = '\0';
            strncpy(prUnit, other.prUnit, max_length_unit);
            prUnit[max_length_unit] = '\0';
            quantityOnHand = other.quantityOnHand;
            quantityNeeded = other.quantityNeeded;
            prodPriceBeforeTax = other.prodPriceBeforeTax;
            taxStatus= other.taxStatus;
            int length = strlen(other.prName);    
            setName(other.prName);
		}
		else
		{
			prName = nullptr;
            setSafeEmpty();
		}
	}

	ama::Product::~Product()
	{
      delete [] prName;
      prName = nullptr;
	}

	Product & ama::Product::operator=(const Product & other)
	{
		if (this != &other)
		{
            type = other.type;
            
            delete[] prName;
			if (other.prName != nullptr)
			{
                strncpy(prSKU, other.prSKU, max_length_sku);
                strncpy(prUnit, other.prUnit, max_length_unit);
                quantityOnHand = other.quantityOnHand;
                quantityNeeded = other.quantityNeeded;
                prodPriceBeforeTax = other.prodPriceBeforeTax;
                taxStatus= other.taxStatus;
                setName(other.prName);
			}
			else
			{
                prName = nullptr;
                setSafeEmpty();
			}
		}

		return *this;
	}

	int ama::Product::operator+=(int cnt)
	{
        if(cnt>0){
			quantityOnHand = quantityOnHand + cnt;
				return quantityOnHand;
        }
		return quantityOnHand;
	}

	bool ama::Product::operator==(const char * sku) const
	{
		return strcmp(sku, prSKU) == 0;
	}

	bool ama::Product::operator>(const char * sku) const
	{
		if(strcmp(prSKU, sku) > 0)
            return true;
        return false;
	}

	bool ama::Product::operator>(const Product & other) const
	{
		if(strcmp(prName, other.prName) > 0)
            return true;
        return false;
	}

	int ama::Product::qtyAvailable() const
	{
		return quantityOnHand;
	}

	int ama::Product::qtyNeeded() const
	{
		return quantityNeeded;
	}

	double ama::Product::total_cost() const
	{	
		if (taxStatus) {
			double tax = prodPriceBeforeTax * tax_rate;
			double priceWithTax = prodPriceBeforeTax + tax;
			return static_cast<double>(quantityOnHand * priceWithTax);
		}
		return static_cast<double>(quantityOnHand * prodPriceBeforeTax);
	}

	double ama::Product::cost_with_tax() const
	{
		if (taxStatus) {
			double tax = prodPriceBeforeTax * tax_rate;
			double priceWithTax = prodPriceBeforeTax + tax;
			return static_cast<double>(priceWithTax);
		}
		return static_cast<double>(prodPriceBeforeTax);
	}

	bool ama::Product::isEmpty() const
	{
		if(prName==nullptr)
            return true;
        return false;
	}

	std::istream & ama::Product::read(std::istream & in, bool interractive)
	{
		char sku[max_length_sku + 1];
		char *name = new char[max_length_name + 1];
		char unit[max_length_unit + 1];
		int qtOnHand;
		int qtNeeded;
		double priceBeforeTax;
		char tax;
		bool taxable;
		ErrorState error;

		if (!interractive) {
			char ch=',';
			in.getline(prSKU, max_length_sku, ch);
			in.getline(name, max_length_name, ch);
			setName(name);
			in.getline(prUnit, max_length_unit, ch);
			in >> prodPriceBeforeTax;
			in.ignore(); 
			in >> tax;
			if (tax == '1')
				taxStatus= true;
			else if (tax == '0')
				taxStatus = false;
			in.ignore();
			in >> quantityOnHand;
			in.ignore();
			in >> quantityNeeded;
			in.ignore();
		}
		else {
			cout << setw(max_length_label) << right << " Sku: ";
			in >> sku;
			cout << setw(max_length_label) << right << " Name (no spaces): ";
			in >> name;
			cout << setw(max_length_label) << right << " Unit: ";
			in >> unit;
			cout << setw(max_length_label) << right << " Taxed? (y/n): ";
			in >> tax;

			if (tax == 'Y' || tax == 'y')
			{
				taxable = true;
			}
			else if (tax == 'N' || tax == 'n')
			{
				taxable = false;
			}
			else
			{
				in.setstate(std::ios::failbit);
				es.message("Only (Y)es or (N)o are acceptable!");
			}

			if (!in.fail())
			{
				cout << setw(max_length_label) << right<< " Price: ";
				in >> priceBeforeTax;
				if (in.fail()) {
					in.setstate(std::ios::failbit);
					es.message("Invalid Price Entry!");
				}
					
			}

			if (!in.fail())
			{
				cout << setw(max_length_label) << right <<" Quantity on hand: ";
				in >> qtOnHand;
				if (in.fail()) {
					in.setstate(std::ios::failbit);
					es.message("Invalid Quantity Available Entry!");
				}
					
			}

			if (!in.fail())
			{
				cout << setw(max_length_label) << right<<" Quantity needed: ";
				in >> qtNeeded;
				if (in.fail()) {
					in.setstate(std::ios::failbit);
					es.message("Invalid Quantity Needed Entry!");
				}
					
			}
			if (!in.fail())
			{
				Product temp = Product(sku, name, unit,priceBeforeTax , qtNeeded, qtOnHand, true);
				*this = temp;
			}
		}
		
		delete[] name;
		name = nullptr;
		return in;
	}

	std::ostream & ama::Product::write(std::ostream & out, int writeMode) const
	{
		if (!isEmpty()) {
				if (writeMode == 0) {
					out << type << ',' << prSKU << ',' << prName << ',' << prUnit << ',' << prodPriceBeforeTax << "," << taxStatus << "," << quantityOnHand << "," << quantityNeeded;
				}
				else if (writeMode == 1) {
					char *name;
					out << " " << setw(max_length_sku) << right << prSKU << " " << '|';
						if (strlen(prName) > 16) {
                            char *name = new char[13];
                            strncpy(name, prName, 13);
                            name[13] = '\0';
							out << " " << setw(13) << left << name << "... "<< '|';
						}
						else {
							out << " " << setw(16) << left << prName <<" " << '|';
						}
						out << " " << setw(10) << left << prUnit << " " << '|'
						<< " " << setw(7) << right << fixed << setprecision(2) << prodPriceBeforeTax << " " << '|';
					if (taxStatus)
					{
						out << " " << setw(3) << right << "yes" << " " << '|';
					}
					else
					{
						out << " " << setw(3) << right << "no" << " " << '|';
					}
					out << " " << setw(6) << right << quantityOnHand << " " << '|'
						<< " " << setw(6) << right << quantityNeeded << " " << '|';
				}
				else {
					out << setw(max_length_label) << right << "Sku: " << prSKU << endl;
					out << setw(max_length_label) << right << "Name: " << prName << endl;
					out << setw(max_length_label) << right << setprecision(2) << fixed << "Price: " << prodPriceBeforeTax << endl;
					out << setw(max_length_label) << right << setprecision(2) << fixed << "Price after Tax: " << cost_with_tax() << endl;
					out << setw(max_length_label) << right << "Quantity Available: " << quantityOnHand << " " << prUnit << endl;
					out << setw(max_length_label) << right << "Quantity Needed: " << quantityNeeded << " " << prUnit << endl;
				}
			
		}
		else {
			if (es) {
				out << es.message();
			}
		}
		return out;
	}

	void Product::setName(const char *name)
	{
		if (name != nullptr)
		{
			int length = strlen(name);
			prName = new char[length];
			strncpy(prName,name, length);
			prName[length] = '\0';
		}
	}
}