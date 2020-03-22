/*
Name: Palak Chawla
Student ID : 118834175
Date : 29 Jan 2018
Workshop1 :  At home
Email : pchawla5@myseneca.ca
*/
#ifndef NAMESPACE_TOOLS_H
#define NAMESPACE_TOOLS_H

/*This is a header file tools.h used to declare the prototype including the compilation safe guards */
#pragma once
#include <iostream>
using namespace std;

namespace sict
{
	// Performs a fool-proof integer entry
	int getInt(int min, int max);
	// Displays the user interface menu
	int menu();
}
#endif