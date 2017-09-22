//Created by Jared Alwyn, 9/18/2017
//Corporate Sales Data

#include "stdafx.h"
#include <iostream>;
#include <string>;
#include <iomanip>;
using namespace std;

struct Division
{
	string div_name;
	double qtr1_sales,
		qtr2_sales,
		qtr3_sales,
		qtr4_sales,
		annual_sales,
		qtr_average;
};

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
	div.annual_sales = (div.qtr1_sales + div.qtr2_sales + div.qtr3_sales + div.qtr4_sales);
	div.qtr_average = (div.annual_sales / 4);
}

//***************************************************
//This is a function that will get all the			*
// information that is needed in the Division		*
// struct.											*	
//***************************************************
void GetDivisionSales(Division& div) {
	cout << "\tFirst quarter: ";
	cin >> div.qtr1_sales;
	while (div.qtr1_sales < 0) {
		cout << "The sales data can't be a negative number.\n"
			<< "Re-enter the sales data for the first quarter: ";
		cin >> div.qtr1_sales;
	}
	cout << "\tSecond quarter: ";
	cin >> div.qtr2_sales;
	while (div.qtr2_sales < 0) {
		cout << "The sales data can't be a negative number.\n"
			<< "Re-enter the sales data for the second quarter: ";
		cin >> div.qtr2_sales;
	}
	cout << "\tThird quarter: ";
	cin >> div.qtr3_sales;
	while (div.qtr3_sales < 0) {
		cout << "The sales data can't be a negative number.\n"
			<< "Re-enter the sales data for the third quarter: ";
		cin >> div.qtr3_sales;
	}
	cout << "\tFourth quarter: ";
	cin >> div.qtr4_sales;
	while (div.qtr4_sales < 0) {
		cout << "The sales data can't be a negative number.\n"
			<< "Re-enter the sales data for the fourth quarter: ";
		cin >> div.qtr4_sales;
	}
}