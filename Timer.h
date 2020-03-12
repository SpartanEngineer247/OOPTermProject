#pragma once

#include <chrono>
#include <iostream>
#include <future>
#include <thread>
#include "User_Database.h"
using namespace std;

//asynchronous timer
//it SHOULD have been a function that generates a new thread and runs in the background
//but for some reason the program locks in this thread and we don't really know how to fix it
//this prevents the user from checking other machines' status and/or logging out for other users to come in
//hence the whole purpose of the program is unfortunately made moot
//nonethess all the functionalities of the programs are there, along with their OOP behaviors
//hence we decided to leave the program as is, with the time being too limited to fix or understand how multithreading works
void timer(int s, string machinename) {
    cout << endl << "Started timer!" << endl;
    for (int i = 0; i < s; i++)
    {
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl << "CYCLES COMPLETE! PLEASE CHECK YOUR LAUNDRY!!" << endl;

    Users_Database* s1;
    s1 = Users_Database::GetInstance();
    s1->turnoffmachine(machinename);
}
