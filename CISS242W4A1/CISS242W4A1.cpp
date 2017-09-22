//Created by Jared Alwyn, 9/18/2017
//Corporate Sales Data

#include "stdafx.h"
#include <iostream>;
#include <string>;
#include <iomanip>;
using namespace std;

//Struct that holds values for corporate sales data.
struct Division {
	string div_name;		//String to hold the name of the division.
	double sales[4];		//Array that holds four variables for quarter sales.
	double annual_sales,	//Holds total annual sales from the quarters.
		qtr_average;		//Holds value for average sales over quarters. 
};

//Function prototypes.
void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south);
void FindTotalAndAverageSales(Division& div);
void GetDivisionSales(Division& div);

int main() {
	//Four variables(instances) of Division structure.
	Division east = { "East Division" };
	Division west = { "West Division" };
	Division north = { "North Division" };
	Division south = { "South Division" };

	//Start of program and get sales information from user. 
	cout << "\t\t---Welcome to the Corporate Sales Data Program!---\n\n"
		<< "Enter the quarterly sales for the East Division:\n";
	GetDivisionSales(east);
	cout << "Enter the quarterly sales for the West Division:\n";
	GetDivisionSales(west);
	cout << "Enter the quarterly sales for the North Division:\n";
	GetDivisionSales(north);
	cout << "Enter the quarterly sales for the South Division:\n";
	GetDivisionSales(south);

	//Calculate total annual sales and quarterly average. 
	FindTotalAndAverageSales(east);
	FindTotalAndAverageSales(west);
	FindTotalAndAverageSales(north);
	FindTotalAndAverageSales(south);

	//Display Total annual sales, and average quarterly sales.
	cout << "\n\n\t\t---Division Sales Results---\n\n";
	DisplayCorpInformation(east, west, north, south);

	//Holds the system open and exits program.
	system("Pause");
	return 0;
}

//***************************************************
//This is a function that will display the annual	*
// sales for each division, along with the quarterly*
// sales of each division.							*	
//***************************************************
void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south) {
	cout << fixed << showpoint << setprecision(2);
	cout << "Total Annual Sales:\n"
		<< "\tEast Division: $" << east.annual_sales << "\n"
		<< "\tWest Division: $" << west.annual_sales << "\n"
		<< "\tNorth Division: $" << north.annual_sales << "\n"
		<< "\tSouth Division: $" << south.annual_sales << "\n"
		<< "Average Quarterly Sales:\n"
		<< "\tEast Division: $" << east.qtr_average << "\n"
		<< "\tWest Division: $" << west.qtr_average << "\n"
		<< "\tNorth Division: $" << north.qtr_average << "\n"
		<< "\tSouth Division: $" << south.qtr_average << endl;
}

//***************************************************
//This is a function to calculate the total annual	*
// sales for each division, along with the quarter	*
// average for each division.						*	
//***************************************************
void FindTotalAndAverageSales(Division& div) {
	for (int index = 0; index < 4; index++) {
		div.annual_sales += div.sales[index];
	}
	div.qtr_average = (div.annual_sales / 4);
}

//***************************************************
//This is a function that will get all the			*
// information that is needed in the Division		*
// struct.											*	
//***************************************************
void GetDivisionSales(Division& div) {
	for (int index = 0; index < 4; index++) {
		cout << "Enter sales for quarter " << (index + 1) << ": ";
		cin >> div.sales[index];
	}
}