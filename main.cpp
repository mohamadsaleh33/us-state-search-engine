/*
author: Mohamad saleh
creation date: 11/5/2025
modification date:10/9/2025
Purpose: This program loads U.S. state data from a file into a vector of State objects
	and allows the user to search by state abbreviation or year of statehood.
	It displays the matching state information in a formatted table.
*/


#include "state.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>


using namespace std;

//prototypes
void readStateInfo(ifstream& , vector<State>& );
void searchByStatehood(vector <State>& , int , int& );
int searchByAbrv(vector <State>& , string );
void displayMenu();
void displayTableHeader();

int main()
{
	// Create a vector to store all State objects
	vector <State> stateVec;
	ifstream ifs;

	//open file
	ifs.open("usstates_lab11.txt");
	// Check if the file failed to open
	if (!ifs.is_open())
	{
		cout << "Error: could not open usstates_lab11.txt" << endl;
		return 1;
	}

	// Read all state information from the file into the vector
	readStateInfo(ifs, stateVec);
	ifs.close();

	// Variable to store the user's menu choice
	int choice = 0;

	// Main menu loop
	do
	{
		// Display the menu options to the user
		displayMenu();
		cin >> choice;

		// OPTION 1: Search by state abbreviation
		if (choice == 1)
		{
			// Variable to hold abbreviation input by user
			string abrv;
			cout << "Enter state abbreviation (e.g. MI): ";
			cin >> abrv;

			// Convert to uppercase to match file format
			for (size_t i = 0; i < abrv.size(); i++)
			{
				abrv[i] = toupper(abrv[i]);
			}

			// Perform the search and get the index
			int index = searchByAbrv(stateVec, abrv);

			// If no state was found
			if (index == -1)
			{
				cout << "No state exists with this information." << endl;
			}
			else
			{
				// Display table header and the matching state
				displayTableHeader();
				stateVec[index].displayStateInfo();
				cout << endl;
			}
		}
		// OPTION 2: Search by year of statehood
		else if (choice == 2)
		{
			// Search by year of statehood
			int year;
			cout << "Enter year of statehood (e.g. 1788): ";
			cin >> year;

			// Start searching from index 0
			int startIndex = 0;

			// Find first match
			searchByStatehood(stateVec, year, startIndex);

			// If no match is found
			if (startIndex == -1)
			{
				cout << "No state exists with this information." << endl;
			}
			else
			{
				// Display all matching states
				displayTableHeader();

				// Continue finding matching states until search stops
				while (startIndex != -1)
				{
					// Display the matched state's information
					stateVec[startIndex].displayStateInfo();
					// Move to the next index
					startIndex++;      
					// Search again starting from new index
					searchByStatehood(stateVec, year, startIndex); 
				}
				cout << endl;
			}
		}
		// OPTION 3: Exit program
		else if (choice == 3)
		{
			cout << "Exiting program" << endl;
		}
		// INVALID MENU OPTION
		else
		{
			cout << "Invalid choice. Please enter 1-3." << endl;
		}

	} while (choice != 3); // Repeat until user chooses to exit

	system("pause");
	return 0;

}

// Displays the formatted table header for state information.
void displayTableHeader()
{

	cout << endl;

	// Print table headings with alignment
	cout << right << setw(20) << "State Abr." << setw(20) << "Name" << setw(20) << "Capital"
		<< setw(20) << "Population" << setw(11) << "Year" << setw(15) << "#Congress" << endl;

	cout << endl;

}

// Reads state information from the file using getline.
// Stores each record into a State object and pushes it into the vector.
void readStateInfo(ifstream& ifs, vector<State>& stateVec)
{
	State tmpState;

	// String temp variables for getline
	string abrv;
	string sName;
	string cap;
	string popTemp;
	string yearTemp;
	string congressTemp;

	// int variables
	int popStr;
	int yearStr;
	int congressStr;

	// Loop until end of file is reached
	while (!ifs.eof()) {
		// Read remaining fields using getline
		getline(ifs, abrv, ',');
		getline(ifs, sName, ',');
		getline(ifs, cap, ',');
		getline(ifs, popTemp, ',');
		getline(ifs, yearTemp, ',');
		getline(ifs, congressTemp);   // read until end of line

		// Convert popTemp to popStr(int) 
		{
			stringstream ss(popTemp);
			ss >> popStr;
		}

		//  Convert yearTemp to yearStr(int)
		{
			stringstream ss(yearTemp);
			ss >> yearStr;
		}

		//  Convert congressTemp to congressStr(int) 
		{
			stringstream ss(congressTemp);
			ss >> congressStr;
		}

		// Load data into State object
		tmpState.setStateAbrv(abrv);
		tmpState.setStateName(sName);
		tmpState.setCapital(cap);
		tmpState.setPopulation(popStr);
		tmpState.setYear(yearStr);
		tmpState.setNumCongress(congressStr);

		// Add object to vector
		stateVec.push_back(tmpState);
	}
}

// Searches for a state in the vector by its abbreviation.
int searchByAbrv(vector <State>& stVec, string abrv)
{
	// Loop through all stored states
	for (int i = 0; i < stVec.size(); i++)
	{
		// Check if abbreviation matches
		if (stVec[i].getStateAbrv() == abrv)
		{
			return i;
		}
	}

	return -1;

}

// Searches for a state by its year of statehood.
void searchByStatehood(vector <State>& stVec, int year, int& startIndex)
{
	// Loop from the given starting index to the end of the list
	for (int i = startIndex; i < stVec.size(); i++)
	{
		// Check if the state's year matches
		if (stVec[i].getYear() == year)
		{
			startIndex = i;
			return;
		}
	}
	startIndex = -1; // no more matches


}
// Displays the menu options for the user.
void displayMenu()
{
	cout << "US States Database Menu" << endl;
	cout << "1. Search by state abbreviation" << endl;
	cout << "2. Search by year of statehood" << endl;
	cout << "3. Exit program" << endl;
	cout << "Please enter your choice (1-3): ";

}