//****************************************************
// File: SalesFunctions.cpp
//
// Purpose: The definitions of all of the functions used by the program to create a sales report
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

#include "SalesFunctions.h"

//****************************************************
// Function: void ReadSalesFromFile(string inputFileName, char first[], char last[], double sales[])
//
// Purpose: reads the input information from the input file that is a parameter and stores all of the information 
//				in the appropriate array
//
// Update Information
// ------------------
// 
//
//****************************************************
void ReadSalesFromFile(string fileName, string first[], string last[], double sales[]) {
	//Opens the file
	ifstream file;
	file.open(fileName);

	int i = 0;
	//Loops through to read the data from the file into the appropriate array until the end of the file is reached
	while (i < 5) {
		file >> first[i];
		file >> last[i];
		file >> sales[i];
		i++;
	}
}

//****************************************************
// Function: void SalesReport(string file, string first[], string last[], double sales[], int index)
//
// Purpose: writes the sales report to the file that the user entered. It also calls a bunch of different functions within it
//
// Update Information
// ------------------
// 
//
//****************************************************
void SalesReport(string file, string first[], string last[], double sales[], int index) {
	//Variables
	double average;
	double total;
	double max;
	double min;
	int maxIndex;
	int minIndex;

	//Sets the max and min equal to a value in the sales array
	max = sales[0];
	min = sales[0];

	//Opens the file
	ofstream oFileName;
	oFileName.open(file); 

	oFileName << "Sales Report" << endl;
	oFileName << "------------" << endl;
	oFileName << setw(15) << "First" << setw(15) << "Last" << setw(10) << "Sales" << endl;
	oFileName << setw(15) << "-----" << setw(15) << "----" << setw(10) << "-----" << endl;

	//Writes the data in the arrays to the file
	for (int index = 0; index < 5; index++) {
		oFileName << setw(15) << first[index];
		oFileName << setw(15) << last[index];
		oFileName << setw(10) << setprecision(2) << fixed << sales[index] << endl;
	}
	
	//Values that are calculated in other functions that will be printed onto the report
	average = CalculateAvgSales(sales, 5);
	total = CalculateTotalSales(sales, 5);
	maxIndex = FindMaxSalesIndex(sales, 5, max); 
	minIndex = FindMinSalesIndex(sales, 5, min);
	
	//Writes this all to the file as well for the report
	oFileName << endl;
	oFileName << "Average Sales : " << setprecision(2) << fixed << average << endl;
	oFileName << "Total Sales : " << setprecision(2) << fixed << total << endl;
	oFileName << endl;
	oFileName << "Max Sales Name : " << first[maxIndex] << " " << last[maxIndex] << endl;
	oFileName << "Max Sales Amount : " << setprecision(2) << fixed << max << endl;
	oFileName << endl;
	oFileName << "Min Sales Name : " << first[minIndex] << " " << last[minIndex] << endl;
	oFileName << "Min Sales Amount : " << setprecision(2) << fixed << min << endl;
}

//****************************************************
// Function: double CalculateAvgSales(double sales[], int numElements)
//
// Purpose: calculates the average sales
//
// Update Information
// ------------------
// 
//
//****************************************************
double CalculateAvgSales(double sales[], int numElements) {
	//Variables
	double total;
	double avg;

	//Gets the total from the total sales function
	total = CalculateTotalSales(sales, 5);

	//Calculates the average
	avg = total / 5;

	return avg;
}

//****************************************************
// Function: double CalculateTotalSales(double sales[], int numElements)
//
// Purpose: calculates the total sales
//
// Update Information
// ------------------
// 
//
//****************************************************
double CalculateTotalSales(double sales[], int numElements) {
	//Variables
	double total;

	total = 0;

	//Adds the sale at that index to the total
	for (int i = 0; i < 5; i++) {
		total = total + sales[i];
	}

	return total;
}

//****************************************************
// Function: int FindMaxSalesIndex(double sales[], int numElements, double & maximum)
//
// Purpose: finds the maximum sale which is passed by reference and returns the index at which the highest sale is at
//
// Update Information
// ------------------
// 
//
//****************************************************
int FindMaxSalesIndex(double sales[], int numElements, double & maximum) {
	//Variables
	int index;		//index of the highest sale

	index = 0;

	for (int i = 0; i < 5; i++) {
		//Checks to see if the sale is greater than the maximum that was previously set. 
		//If it is greater, it updates the index that the max value is at as well as the max.
		if (sales[i] > maximum) {
			index = i;
			maximum = sales[i];
		}
	}
	return index;
}

//****************************************************
// Function: int FindMinSalesIndex(double sales[], int numElements, double & minimum)
//
// Purpose: finds the minimum sale which is passed by reference and returns the index at which the lowest sale is at
//
// Update Information
// ------------------
// 
//
//****************************************************
int FindMinSalesIndex(double sales[], int numElements, double & minimum) {
	//Variables
	int index;		//index of the lowest sale

	index = 0;

	for (int i = 0; i < 5; i++) {
		//Checks to see if the sale is less than the minimum that was previously set. 
		//If it is less, it updates the index that the min value is at as well as the min.
		if (sales[i] <= minimum) {
			index = i;
			minimum = sales[i];
		}
	}
	return index;
}