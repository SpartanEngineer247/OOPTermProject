#pragma once

#include<string>
#include<thread>
#include "User_Database.h"
#include "Users.h"
#include "Timer.h"
#include<iostream>
using namespace std;

//Base class for the Machine objects
class Machine
{
protected:
	string name;	//name of machine
	bool status;	//availability of machine - if false, machine is available to use
	//setting to the 'minutes of operation' the machine is operating with right now. Is -1 if the machine is not operating, -2 if broken
	int currentfunction; //The functionality of the machine itself (how many minutes of operation,etc...)
	int time; //Time left of the machine's operation - this isn't used properly as the asynchronous timer is currently not fully functional
public:
	//default constructor, not necessary but placed just in case it throws errors
	Machine()
	{
		name = "NA";
		status = false;
		currentfunction = -1;
		time = 0;
	}
	//preferred constructor - the inputs are ideally taken from the memory file
	Machine(string newname, bool currentstatus, int newop, int newtime)
	{
		name = newname;
		status = currentstatus;
		currentfunction = newop;
		time = newtime;
	}

	//getters
	string getname()
	{
		return name;
	}
	bool getstatus()
	{
		return status;
	}
	int getoperations()
	{
		return time;
	}

	int getcurrentfunction()
	{
		return currentfunction;
	}

	//simple change status function, flips the status on or off - has a 'dummy' input for later polymorphism
	virtual void changestatus(int setting)
	{
		status = !status;
	}

	//abstract function, should print out the operational information of the machine
	virtual void printoperation() = 0;

	//Function which calls the asynchronous timer block and stores it into an 'auto' a variable
	void starttimer(int s, string machinename)
	{
		auto a = async(timer, s, machinename);
	}
};

class WashingMachine : public Machine
{
private:
	//hardcoded some 'minutes of operation' of a washing machine - this may be updated later to be able to read from file
	//While throughout the code it is written as 'minutes' for demonstration purposes these numbers serve as seconds
	int machinefunction[5] = { 10, 20, 25, 30, 50 };
public:
	//constructors
	WashingMachine() :Machine() { currentfunction = -1; }
	WashingMachine(string inname, bool currentstatus, int currentsetting, int newtime) :Machine(inname, currentstatus, currentsetting, newtime){}

	//change status now depends on which setting the machine is set to... -1 means its empty and available, anything else
	//and it is currently in operation
	void changestatus(int setting)
	{
		if (setting == -1)
		{
			status = false;
		}
		else
		{
			status = true;
			currentfunction = setting;
		}
	}

	//prints the operating status of the machine right now
	//this is not fully implemented as the timer function locks the program out of further operation
	void printoperation()
	{
		cout << endl << "Washing Machine " << name;
		cout << endl << "Current status: ";
		if (status == false)
		{
			cout << "AVAILABLE";
		}
		else
		{
			cout << "IN OPERATION.";
			cout << endl << "Current Cycle Setting: " << machinefunction[currentfunction] << " minutes";
			//Time left?
		}
	}

	//function that returns the number of minutes the setting indicates (i.e. setting 3 desires 25 minutes)
	//This function is shared in terms of functionality with dryingmachine but are implemented separately because
	//Each machine type has unique functionality settings - this was a behavior of the program that hasn't been fully realized
	int getminutes(int setting)
	{
		return machinefunction[setting];
	}
};

class DryingMachine : public Machine
{
private:
	int machinefunction[5] = { 5, 10, 15, 20, 30 };
	bool needcleaning;
public:
	//constructors, easy enough
	DryingMachine() :Machine() { currentfunction = -1; needcleaning = true; }
	DryingMachine(string inname, bool currentstatus, int currentsetting, int newtime) :Machine(inname, currentstatus, currentsetting, newtime)
	{
		currentfunction = currentsetting;
		needcleaning = true;
	}

	//again the drying machine status is dependent on its current function, but if it's empty it will mark as being needed to clean
	void changestatus(int setting)
	{
		if (setting == -1)
		{
			status = false;
			needcleaning = true;
		}
		else
		{
			status = true;
			currentfunction = setting;
		}
	}

	//a function which changes the status of the machine to having been cleaned
	void cleaned()
	{
		needcleaning = false;
	}

	//prints the operating status of the machine right now
	void printoperation()
	{
		cout << endl << "Drying Machine " << name;
		cout << endl << "Current status: ";
		if (status == false)
		{
			cout << "AVAILABLE";
		}
		else
		{
			cout << "IN OPERATION.";
			cout << endl << "Current Cycle Setting: " << machinefunction[currentfunction] << " minutes";
			//Time left?
		}
		if (needcleaning == true)
		{
			cout << endl << "PLEASE CLEAN THE MACHINE'S FILTER AND EMPTY ITS WATER BUCKET!";
		}
	}

	//getter for bolean
	bool getneedcleaning()
	{
		return needcleaning;
	}

	//same function as getminutes in washingmachines class
	int getminutes(int setting)
	{
		return machinefunction[setting];
	}
};
