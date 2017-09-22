/*Write a program that determines if the user is a winner in the lottery game.
A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit “lucky” combinations.
The program will initialize an array with these numbers and then lets the player enter this week’s winning 5-digit number.
The program should perform both a linear search and a binary search through the list of player’s numbers 
and report whether or not one of the tickets is a winner this week. 
Here are the numbers, and the array must be created with the values in this order: 
13579, 62483, 26791, 77777, 26792, 79422, 33445, 85647, 55555, 93121. 
NOTE: The numbers are not in order, they must start this way.
*/

#include "stdafx.h"
#include <iostream>;
#include <algorithm>;
#include <iomanip>;
#include <algorithm>;
using namespace std;

//Funtion prototypes.
void sort		(int[], int);
void show_array (const int[], int);
void get_input	(int[], int);
int compare		(int[], int[], int);

int main(){
	//Global const.
	const int		  max_numbers = 5;								//Value for max numbers allowed on ticket.
	//Defined integers.
	int sort_ticket1 [max_numbers]  =  { 1,3,5,7,9 };				//Array to hold tickets 1-10.
	int sort_ticket2 [max_numbers]  =  { 6,2,4,8,3 };
	int sort_ticket3 [max_numbers]  =  { 2,6,7,9,1 };
	int sort_ticket4 [max_numbers]  =  { 7,7,7,7,7 };
	int sort_ticket5 [max_numbers]  =  { 2,6,7,9,2 };
	int sort_ticket6 [max_numbers]  =  { 7,9,4,2,2 };
	int sort_ticket7 [max_numbers]  =  { 3,3,4,4,5 };
	int sort_ticket8 [max_numbers]  =  { 8,5,6,4,7 };
	int sort_ticket9 [max_numbers]  =  { 5,5,5,5,5 };
	int sort_ticket10[max_numbers]  =  { 9,3,1,2,1 };				//End of array holding tickets 1-10.
	int user_input	 [max_numbers]	=  { 0,0,0,0,0 };				//Array to hold winning numbers.
	int yes;
	//Title for user and
	// initialization of arrays.
	cout << "\t\t---Lottery Game---\n\n" << endl;
	sort(sort_ticket1,  max_numbers);
	sort(sort_ticket2,  max_numbers);
	sort(sort_ticket3,  max_numbers);
	sort(sort_ticket4,  max_numbers);
	sort(sort_ticket5,  max_numbers);
	sort(sort_ticket6,  max_numbers);
	sort(sort_ticket7,  max_numbers);
	sort(sort_ticket8,  max_numbers);
	sort(sort_ticket9,  max_numbers);
	sort(sort_ticket10, max_numbers);

	//Prompt user for input of the weeks
	// winning number.
	cout << "Thank you for playing this weeks lottery!\n\n"
		 << "Enter the winning five digit number\n"
		 << "one digit at a time. \n" << endl;
	get_input(user_input, max_numbers);

	//Sort user input.
	sort(user_input, max_numbers);
	
	//Compare values in the array.
		

	//Display if one of the tickets is a winner.
	system("PAUSE");
    return 0;
}

/*******************************
something for now
********************************/
void sort(int array[], int size) {
	int start_scan, min_index, min_value;

	for (start_scan = 0; start_scan < (size - 1); start_scan++)
	{
		min_index = start_scan;
		min_value = array[start_scan];
		for (int index = start_scan + 1; index < size; index++)
		{
			if (array[index] < min_value)
			{
				min_value = array[index];
				min_index = index;
			}
		}
		array[min_index] = array[start_scan];
		array[start_scan] = min_value;
	}
}

/*******************************
something for now
********************************/
void show_array(const int array[], int size) {
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;
}


void get_input(int user_input[], int size) {
		for (int c = 0; c < size; c++)
	{
		cout << "Enter a number for diget " << (c + 1) << ": ";
		cin >> user_input[c];
		while (user_input[c] < 0 | user_input[c] > 9)
		{
			cout << "Invalid number.\n"
				<< "Enter a number 0-9: ";
			cin >> user_input[c];
		}
	}
}

/*******************************
something for now
********************************/

