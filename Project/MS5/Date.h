// Final Project Milestone 1
//
/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include<iostream>
#define NO_ERROR   0  //-- No error - the date is valid
#define CIN_FAILED 1  //--istream failed on information entry
#define YEAR_ERROR 2  //--Year value is invalid
#define MON_ERROR  3  //--Month value is invalid
#define DAY_ERROR  4  //--Day value is invalid

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;


  class Date {

  private:
	  int year; 
	  int mon;
	  int day;
	  int value;
	  int error_state;

     int mdays(int, int)const;
	 void errCode(int errorCode);
	 void set_safe_empty();

 
  public:

	  //Constructor

	  Date();
	  Date(int year, int mon, int day);

	  //Operator overloading

	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;

	  //Queries and modifier
	  int errCode() const;
	  bool bad() const;

	  //Read & Write methods istream  and ostream 

	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;


 
  };

  // Helper functions 
  std::istream& operator>>(std::istream& is, Date& D);
  std::ostream& operator<<(std::ostream& ostr, const Date& D);




}
#endif