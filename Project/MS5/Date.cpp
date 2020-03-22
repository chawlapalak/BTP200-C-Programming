// Final Project Milestone 1
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
#include<iomanip>
#include<iostream>
#include "Date.h"

namespace AMA {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

  void Date::errCode(int errorCode)
  {
	  error_state = errorCode;
  }

  void Date::set_safe_empty()
  {
	  year = 0;
	  mon = 0;
	  day = 0;
	  value = 0;
  }

  Date::Date()
  {
	  set_safe_empty();
	  error_state = NO_ERROR;
  }

  Date::Date(int yr, int mn, int dy)
  {
	  if (yr < min_year || yr > max_year) {
		  set_safe_empty();
		  error_state = YEAR_ERROR;
	  }
	  else if (mn < 1 || mn > 12) {
		  set_safe_empty();
		  error_state = MON_ERROR;
	  }
	  else if (dy < 1 || dy > mdays(mn,yr)) {
		  set_safe_empty();
		  error_state = DAY_ERROR;
	  }
	  else
	  {
		  year = yr;
		  mon = mn;
		  day = dy;
		  value = year * 372 + mon * 13 + day;
		  error_state = NO_ERROR;
	  }
	  
  }

  bool Date::operator==(const Date & rhs) const
  {
	  if (value == rhs.value)
		  return true;
	  return false;
  }

  bool Date::operator!=(const Date & rhs) const
  {
	  if (value != rhs.value)
		  return true;
	  return false;
  }

  bool Date::operator<(const Date & rhs) const
  {
	  if (value < rhs.value)
		  return true;
	  return false;
  }

  bool Date::operator>(const Date & rhs) const
  {
	  if (value > rhs.value)
		  return true;
	  return false;
  }

  bool Date::operator<=(const Date & rhs) const
  {
	  if (value <= rhs.value)
		  return true;
	  return false;
  }

  bool Date::operator>=(const Date & rhs) const
  {
	  if (value >= rhs.value)
		  return true;
	  return false;
  }

  int Date::errCode() const
  {
	  return error_state;
  }

  bool Date::bad() const
  {
	  if (error_state != 0)
		  return true;
	  return false;
  }

  std::istream & Date::read(std::istream & istr)
  {
	  istr >> year;
	  if (istr.get() != '/') {
		  error_state = CIN_FAILED;
		  return istr;
	  }
	  istr >> mon;
	  if (istr.get() != '/') {
		  error_state = CIN_FAILED;
		  return istr;
	  }
	  istr >> day; 

	  if (year < min_year || year > max_year) {
		  error_state = YEAR_ERROR;
	  }
	  else if (mon < 1 || mon > 12) {
		  error_state = MON_ERROR;
	  }
	  else if (day < 1 || day > mdays(mon,year)) {
		  error_state = DAY_ERROR;
	  }
	  return istr;
  }

  std::ostream & Date::write(std::ostream & ostr) const
  {
	 
	  ostr << std::setw(1) << std::setfill('0') << year << "/"
		  << std::setw(2) << std::setfill('0') << mon << "/"
		  << std::setw(2) << std::setfill('0') << day;

	  return ostr;
  }



  std::istream & operator>>(std::istream & istr, Date & Dt)
  {
	  return Dt.read(istr);
  }

  std::ostream & operator<<(std::ostream & ostr, const Date & Dt)
  {
	  return Dt.write(ostr);
  }

}
