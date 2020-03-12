#pragma once

#include "Machine.h"
#include "Users.h"
#include "Timer.h"
#include<string>
#include<map>
#include<fstream>
#include<iostream>
using namespace std;

//Users_Database is a slight misnomer - this class creates a singleton overhead object that manages the entire database
class Users_Database
{
private:
	//Users_Database pointer, which stores the location of the database object
	static Users_Database *instance;

	//Stores the currently logged in user's name
	string currentuser;

	//Default constructor, called through GetInstance public function
	Users_Database()
	{
		currentuser = "";

		//Opens memory files, "usersmemory.txt", "washingmachinesmemory.txt", "dryingmachinesmemory.txt"
		//and attempts to take information stored within
		//The program currently is UNABLE to handle corrupted data (i.e. incomplete information)
		//However it is self-sufficient in that it will handle saving and loading memory safely if there is no corruption
		ifstream inFileBuffer("usersmemory.txt");
		if (inFileBuffer.fail())
		{
			cerr << "ERROR OPENING MEMORY. Please check that memory files are not corrupted. (USERSMEMORY)";
		}

		string newnetID;
		string newpassword;
		bool newstatus;

		while (!inFileBuffer.eof())
		{
			inFileBuffer >> newnetID >> newpassword >> newstatus;
			User* userptr;
			userptr = new User(newnetID, newpassword, newstatus);
			Table.emplace(newnetID, userptr);
		}
		inFileBuffer.close();

		ifstream inFileBuffer2("washingmachinesmemory.txt");
		if (inFileBuffer2.fail())
		{
			cerr << "ERROR OPENING MEMORY. Please check that memory files are not corrupted. (WASHINGMACHINESMEMORY)";
		}

		string newname2;
		bool newstatus2;
		int newfunction2;
		int newtime2;

		while (!inFileBuffer2.eof())
		{
			inFileBuffer2 >> newname2 >> newstatus2 >> newfunction2 >> newtime2;
			WashingMachine* wmachineptr;
			wmachineptr = new WashingMachine(newname2, newstatus2, newfunction2, newtime2);
			WashingTable.emplace(newname2, wmachineptr);
		}
		inFileBuffer2.close();

		ifstream inFileBuffer3("dryingmachinesmemory.txt");
		if (inFileBuffer3.fail())
		{
			cerr << "ERROR OPENING MEMORY. Please check that memory files are not corrupted. (DRYINGMACHINESMEMORY)";
		}

		string newname3;
		bool newstatus3;
		int newfunction3;
		int newtime3;

		while (!inFileBuffer3.eof())
		{
			inFileBuffer3 >> newname3 >> newstatus3 >> newfunction3 >> newtime3;
			DryingMachine* dmachineptr;
			dmachineptr = new DryingMachine(newname3, newstatus3, newfunction3, newtime3);
			DryingTable.emplace(newname3, dmachineptr);
		}
		inFileBuffer3.close();
	}
	//FOR REFERENCE
	//usersmemory.txt stores username, password (NOT HASHED BUT IN PLAINTEXT, SECURITY ISSUE), and number of machines used
	//washingmachinesmemory.txt stores machine name, it's availability, it's current function, and the time left of its operation
	//dryingmachinesmemory.txt stores machine name, it's availability, it's current function, and the time left of its operation

	//Three maps stores the data from the memory - the keys are the names, and the second elements are pointers to objects
	//that has been dynamically assigned to memory spaces
	map<string, User*> Table;
	map<string, WashingMachine*> WashingTable;
	map<string, DryingMachine*> DryingTable;

public:
	//Singleton construction call
	static Users_Database* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Users_Database();
		}
		return instance;
	}
	

	//Default destructor, essential for storing the session information properly back into the memory files
	~Users_Database()
	{
		ofstream outFileBuffer("usersmemory.txt");
		if (outFileBuffer.fail())
		{
			cerr << "ERROR SAVING TO MEMORY. Warning! No changes to users were saved!";
		}
		else
		{
			map<string, User*>::iterator it;
			for (it = Table.begin(); it != Table.end(); it++)
			{
				outFileBuffer << it->first << " ";
				outFileBuffer << it->second->getPass() << " ";
				outFileBuffer << it->second->getStatus() << endl;
			}

		}
		outFileBuffer.close();

		ofstream outFileBuffer2("washingmachinesmemory.txt");
		if (outFileBuffer2.fail())
		{
			cerr << "ERROR SAVING TO MEMORY. Warning! No changes to machines were saved!";
		}
		else
		{
			//write a loop function that scans through all machines and saves all private data onto the txt file
			map<string, WashingMachine*>::iterator it;
			for (it = WashingTable.begin(); it != WashingTable.end(); it++)
			{
				outFileBuffer2 << it->first << " ";
				outFileBuffer2 << it->second-> getstatus()<< " ";
				outFileBuffer2 << it->second-> getcurrentfunction() << " ";
				outFileBuffer2 << it->second-> getoperations() << endl;
			}
		}
		outFileBuffer2.close();

		ofstream outFileBuffer3("dryingmachinesmemory.txt");
		if (outFileBuffer3.fail())
		{
			cerr << "ERROR SAVING TO MEMORY. Warning! No changes to machines were saved!";
		}
		else
		{
			//write a loop function that scans through all machines and saves all private data onto the txt file
			map<string, DryingMachine*>::iterator it;
			for (it = DryingTable.begin(); it != DryingTable.end(); it++)
			{
				outFileBuffer3 << it->first << " ";
				outFileBuffer3 << it->second->getstatus() << " ";
				outFileBuffer3 << it->second->getcurrentfunction() << " ";
				outFileBuffer3 << it->second->getoperations() << endl;
			}
		}
		outFileBuffer3.close();

		Table.clear();
		WashingTable.clear();
		DryingTable.clear();
		currentuser = "";
		instance = nullptr;
	}

	//Function that takes in user's name and designated password and checks if the credentials are correct
	//If so, the program will move on to next functionalities and will set the session to the inputID
	bool Login(string inputnetID, string &inputpassword)
	{
		map<string, User*>::iterator it;
		it = Table.find(inputnetID);
		if (it == Table.end())
		{
			cout << "Error! No user exists with the given netID.";
			return false;
		}
		
		if (it->second->checkPassword(inputpassword) == false)
		{
			cout << "Error! Incorrect password!";
			return false;
		}
		return true;
		currentuser = inputnetID;
	}
	
	//Function that is called to create a new user by taking in a new ID and password and creates a new object of a user
	//It then stores the pointer to this this newly created user into the Users map
	//If the user already exists, it simply throws an error and does not store the new information
	bool CreateNewUser(string &newnetID, string &newpassword)
	{
		map<string, User*>::iterator it;
		it = Table.find(newnetID);
		if (it != Table.end())
		{
			cout << "Error! This user already exists, please try to log in.";
			return false;
		}
		else
		{
			User* userptr;
			userptr = new User(newnetID, newpassword);
			Table.emplace(newnetID,userptr);
			return true;
		}
	};

	//Function which takes in userid and password and first attempts to login, and if successful
	//it will delete the user from the map of the users
	bool DeleteNewUser(string &newnetID, string &newpassword)
	{
		if (Login(newnetID, newpassword) != true)
		{
			cout << "You cannot delete this user without proper credentials.";
			return false;
		}
		else
		{
			map<string, User*>::iterator it;
			it = Table.find(newnetID);
			Table.erase(newnetID);
			cout << "User removed successfully.";
			return true;
		}
	};

	//Logout function that clears the name of the current session user
	//THIS FUNCTIONALITY IS UNUSED BUT IS PROGRAMMED IN TO ANTICIPATE THE PROGRAM BEING INITIATED IN MULTIPLE SEPARATE INSTANCES
	void logout()
	{
		currentuser = "";
	}

	//A function that checks the status of the machine given
	//This function is identical to checkdryingmachinestatus
	//Whilst it is possible to have a general checkmachinestatus (this is actually done elsewhere)
	//The way the main calls on this function allows this function to have a limited scope
	bool checkwashingmachinestatus(string machinename)
	{
		map<string, WashingMachine*>::iterator it;
		it = WashingTable.find(machinename);
		return (it->second->getstatus());
	}
	//Identical to checkwashingmachinestatus, but for drying machines
	bool checkdryingmachinestatus(string machinename)
	{
		map<string, DryingMachine*>::iterator it;
		it = DryingTable.find(machinename);
		return (it->second->getstatus());
	}

	//Changes washing machine status based on the chosen machine functionality
	//Prints out a message to confirm that the machine is now in use
	//It also calls the timer function
	void changewashingmachinestatus(string machinename, int newsetting)
	{
		map<string, WashingMachine*>::iterator it;
		it = WashingTable.find(machinename);
		it->second->changestatus(newsetting);
		cout << "You have chosen option " << newsetting << ". The machine is now in use.";
		cout << "Time left: " << it->second->getminutes(newsetting) << " minutes.";
		it->second->starttimer(it->second->getminutes(newsetting),machinename);
	}

	//Changes drying machine status based on the chosen machine functionality
	//Prints out a message to confirm that the machine is now in use
	//It also calls the timer function
	void changedryingmachinestatus(string machinename, int newsetting)
	{
		map<string, DryingMachine*>::iterator it;
		it = DryingTable.find(machinename);
		it->second->changestatus(newsetting);
		cout << "You have chosen option " << newsetting << ". The machine is now in use.";
		cout << "Time left: " << it->second->getminutes(newsetting) << " minutes.";
		it->second->starttimer(it->second->getminutes(newsetting),machinename);
	}

	//General function call to turn off the machine (set its functionality to -1 and mark it as available to use
	//Shows the simple if-else statement that could have been implemented in the 'check' and 'change' functions
	void turnoffmachine(string machinename)
	{
		map<string, DryingMachine*>::iterator it;
		it = DryingTable.find(machinename);
		if (it == DryingTable.end())
		{
			map<string, WashingMachine*>::iterator it2;
			it2 = WashingTable.find(machinename);
			it2->second->changestatus(-1);
		}
		else
		{
			it->second->changestatus(-1);
		}
	}
};

//Initates the static pointer for the singleton
Users_Database* Users_Database::instance = nullptr;
