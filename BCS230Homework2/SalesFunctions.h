//****************************************************
// File: SalesFunctions.h
//
// Purpose: Stores the prototypes for all of the functions used for this program
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
#include <iomanip>

using namespace std;

void ReadSalesFromFile(string inputFileName, string first[], string last[], double sales[]);

void SalesReport(string outputfilename, string first[], string last[], double sales[], int numElements);

double CalculateAvgSales(double sales[], int numElements);

double CalculateTotalSales(double sales[], int numElements);

int FindMaxSalesIndex(double sales[], int numElements, double & maximum);

int FindMinSalesIndex(double sales[], int numElements, double & minimum);