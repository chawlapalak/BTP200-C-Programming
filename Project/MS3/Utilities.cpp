/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms3
email : pchawla5@myseneca.ca
24 March 2019*/

#include"Utilities.h"

using namespace std;

namespace ama
{
	double & operator+=(double & total, const Product & prod)
	{	
		total = total + prod.total_cost();
		return total;
	}
	ostream & operator<<(ostream & out, const Product & prod)
	{
		return prod.write(out, 2);
	}
	istream & operator>>(istream & in, Product & prod)
	{
		prod.read(in, true);
		return in;
	}
}