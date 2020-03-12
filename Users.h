#pragma once

#include <string>
#include <future>
#include <thread>
#include <chrono>
#include "Timer.h"

using namespace std;

//Class which defines the User object class, which stores the netID and password of the user
//Quite a simple object, really, with two currently redundant data: NetID and Status
//These private data will be useful if the program goes online and users begin interacting with one another
//But as of now the program does not have that functionality
class User
{
private:
    string NetID;
    string password;
    bool status;

public:
    //Default constructor - unnecessary but placed as precaution
    User()
    {
        NetID = "NA";
        password = "NA";
        status = false;
    }
    //Partial constructor, generates an object of User based on given inputs, with default status of false
    User(string inputNetID, string inputpassword)
    {
        NetID = inputNetID;
        password = inputpassword;
        status = false;
    }
    //Preferred constructor, generates an object of User based on given inputs
    User(string inputNetID, string inputpassword, bool newstatus)
    {
        NetID = inputNetID;
        password = inputpassword;
        status = newstatus;
    }

    //Destructor, not really necessary as there is no memory deallocation within the object but placed here for consistency
    ~User()
    {
        NetID = "-1";
        password = "-1";
        status = false;
    }

    //Getter functions
    //NOTE: GET PASS SHOULD IDEALLY BE IMPLEMENTED AS A HASH FUNCTION
    string getPass()
    {
        return password;
    }
    bool getStatus()
    {
        return status;
    }

    //Check password function: like getPass it should ideally have been implemented as a hash function
    bool checkPassword(string& passwordtry)
    {
        if (passwordtry == password)
        {
            return true;
        }
        else { return false; }
    }
};
