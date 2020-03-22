/*
Name: Palak Chawla
Student ID : 118834175
Date : 29 Jan 2018
Workshop1 : At home
Email : pchawla5@myseneca.ca
*/

/*This is a header file graph.h used to declare the prototype including the compilation safe guards */
#ifndef NAMESPACE_GRAPH_H
#define NAMESPACE_GRAPH_H
#pragma once

#include <iostream>
using namespace std;
namespace sict
{

	// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20
// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);

	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70. 
	int findMax(int samples[], int noOfSamples);

	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);

	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples);
}
#endif