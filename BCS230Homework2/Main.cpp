//****************************************************
// File: Main.cpp
//
// Purpose: Generates a sales report.
//
// Written By: Samantha Smith	
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
//
// 
//****************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "SalesFunctions.h"

using namespace std;

//****************************************************
// Function: main()
//
// Purpose: Entry point for program
//
// Update Information
// ------------------
// 
//
//****************************************************
int main() {
	
	//Arrays
	string firstNames[5];
	string lastNames[5];
	double sales[5];

	//Variables
	string inputFileName;
	string outputFileName;

	//Gets the file names
	cout << "Please enter the name of the input file with the extention.";
	cin >> inputFileName;
	cout << "Please enter the name of the output file that you would like the report to go to with the extension.";
	cin >> outputFileName;

	//Calls function that reads the information from the file that is entered by the user
	ReadSalesFromFile(inputFileName, firstNames, lastNames, sales);
	//Calls the function that prints out the sales report to a file that the user specifies
	SalesReport(outputFileName, firstNames, lastNames, sales, 5);

	return 0;
}