#include "state.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Default constructor
State::State()
{

}

// Sets the state abbreviation
void State::setStateAbrv(string abrv)
{
	stateAbrv = abrv;
}

// Sets the full state name
void State::setStateName(string sName)
{
	stateName = sName;

}
// Sets the capital city
void State::setCapital(string cap)
{
	capital = cap;

}
// Sets the population
void State::setPopulation(int pop)
{
	population = pop;

}
// Sets the year of statehood
void State::setYear(int y)
{
	year = y;

}
// Sets the number of congressional representatives
void State::setNumCongress(int num)
{
	numCongress = num;

}

// Returns the abbreviation
string State::getStateAbrv()
{
	return stateAbrv;

}

// Returns the full name
string State::getStateName()
{
	return stateName;

}

// Returns the state capital
string State::getCapital()
{
	return capital;

}

// Returns the population
int State::getPopulation()
{
	return population;

}


// Returns the year of statehood
int State::getYear()
{
	return year;

}

// Returns the number of congressional representatives
int State::getNumCongress()
{
	return numCongress;

}

// Computes and returns population per representative
int State::computeResidentsPerRep()
{
	if (numCongress == 0)
	{
		return 0;   // avoid division by zero
	}
	return population / numCongress;
}

// Displays data
void State::displayStateInfo()
{
	cout << right << setw(20) << stateAbrv
		<< setw(20) << stateName
		<< setw(20) << capital
		<< setw(20) << population
		<< setw(11) << year
		<< setw(15) << numCongress << endl;

}

