#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

#ifndef STATE_H
#define STATE_H


// Class definition for a U.S. State
class State {

//private data not accessed by user. this stores the data found in the file
private:
	string stateAbrv;
	string stateName;
	string capital;
	int population;
	int year;
	int numCongress;


public:
	//default constructor
	State();
	//setting the strings and ints(DATA)
	void setStateAbrv(string);
	void setStateName(string);
	void setCapital(string);
	void setPopulation(int);
	void setYear(int);
	void setNumCongress(int);

	//getting the strings and ints(DATA)
	string getStateAbrv();
	string getStateName();
	string getCapital();
	int getPopulation();
	int getYear();
	int getNumCongress();

	// Computes population per representative
	int computeResidentsPerRep();
	// Displays data in table format
	void displayStateInfo();

};

#endif 

