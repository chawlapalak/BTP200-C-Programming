/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms3
email : pchawla5@myseneca.ca
24 March 2019*/

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H
#include "Product.h"
using namespace std;
namespace ama
{
	double& operator+=(double& total, const Product& prod);
	ostream& operator<<(ostream& out, const Product& prod); 
	istream& operator>>(istream& in, Product& prod); 
}
#endif

