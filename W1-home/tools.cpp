/*
Name: Palak Chawla
Student ID : 118834175
Date : 29 Jan 2018
Workshop1 :  At home
Email : pchawla5@myseneca.ca
*/ 

#include <iostream>
#include"graph.h"
#include"tools.h"

/* This is a cpp file used to display the menu and check that user enters a valid input*/
using namespace std;
namespace sict
{
	// displays the user interface menu
	int menu() {
		cout << "1- Number of Samples" << endl;
		cout << "2- Sample Entry" << endl;
		cout << "3- Draw Graph" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";
		return getInt(0, 3);
	}

	// Performs a fool-proof integer entry
	int getInt(int min, int max) {
		int val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Integer, try again: ";
			}
			else {
				if (val < min || val > max) {
					cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}
}