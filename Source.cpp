//
//  main.cpp
//  term project
//
//  Created by Raushan Khullar on 3/11/20.
//  Copyright © 2020 Raushan Khullar. All rights reserved.
//

//
//  main.cpp
//  term project
//
//  Created by Raushan Khullar on 3/11/20.
//  Copyright © 2020 Raushan Khullar. All rights reserved.
//
//
//  main.cpp
//  Project
//
//  Created by Raushan Khullar on 2/22/20.
//  Copyright © 2020 Raushan Khullar. All rights reserved.
//
#include"Timer.h"
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include"Users_Database.h"
#include"stdlib.h"
//
//  main.cpp
//  Project
//
//  Created by Raushan Khullar on 2/22/20.
//  Copyright © 2020 Raushan Khullar. All rights reserved.
//
#include<string>
#include<vector>
#include"Users_Database.h"
using namespace std;
#include<iostream>

int main()

{
    Users_Database *s1;
    s1 = Users_Database::GetInstance();int choice=0;
    do
    {
       
        // displaying menu
        
        cout<<"**************************************\n";
        cout<<" WELCOME TO THE LAUNDRY BOOKING APP\n";
        cout<<"**************************************\n";
        cout<<endl;
        cout<<" 1)  Create new user"<<endl;
        cout<<" 2)  Login "<<endl;
        cout<<" 3)  Exit"<<endl;
        cout<<endl;
        
    
        
        int choice;
        
        cout<<" 1- To Create new user\n\n 2-To login.\n\n 3-To exit "<<endl;
        cin>>choice;
        // accepting users choice
        
        //checking if input is valid
        while(!cin)
        {
            cout << "That was no integer! Please enter an integer:\n ";
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        
        
        
        string NetID; string Password;
        if (choice==1)
            //creating a new user
        {   cout<<" To create new user: \n";
            cout<<" Enter NetID\n";
            cin>>NetID;
            cout<<" Enter password\n";
            cin>>Password;
            
            //creating a new user
            s1->CreateNewUser( NetID , Password);
            //
            cout<<" Please login now:\n";
            cout<<" Enter NetID\n";
            cin>>NetID;
            cout<<" Enter password\n";
            cin>>Password;
            // Logging user in
            if(s1->Login( NetID,  Password)==true)
            {
                bool flag2=true;
                int building_num2;
                do
                {
                    flag2=true;
                    cout<<" 0)  Go back to previous page"<<endl;
                    cout<<" 1)  A1"<<endl;
                   
                    
                    
                    int building_num=0;
                    cin>>building_num;
                    //validating input
                    while(!cin)
                    {
                        cout << "That was no integer! Please enter an integer:\n ";
                        cin.clear();
                        cin.ignore();
                        cin >> building_num;
                    }
                    
                    if ( building_num==0)
                        
                    {
                        break;
                    }
                    else if ( building_num==1)
                        
                    {flag2=true;
                        bool flag=false;
                        while(flag==false)
                        {
                            cout<<" 1)   A1A"<<endl;
                           
                            
                            cin>>building_num2;
                            //validating input
                            while(!cin)
                            {
                                cout << "That was no integer! Please enter an integer:\n ";
                                cin.clear();
                                cin.ignore();
                                cin >> building_num2;
                            }
                            if (building_num2==1)
                            {
                                flag=true;
                                bool flag3=false;
                                while(flag3==false)
                                {
                                    
                                    cout<<" Washing machine program settings:\n";
                                    cout<<" Program 1: 10 minutes\n";
                                    cout<<" Program 2: 20 minutes\n";
                                    cout<<" Program 1: 25 minutes\n";
                                    cout<<" Program 1: 30 minutes\n";
                                    cout<<" Program 1: 50 minutes\n";
                                    cout<<endl;
                                    cout<<" Drying machine program settings:\n";
                                    cout<<" Program 1: 5 minutes\n";
                                    cout<<" Program 2: 10 minutes\n";
                                    cout<<" Program 1: 15 minutes\n";
                                    cout<<" Program 1: 20 minutes\n";
                                    cout<<" Program 1: 30 minutes\n";
                                    cout<<endl;
                                    cout<<" Washing machines"<<endl;
                                    
                                    //Displaying the status of machines
                                    cout<<" 1)  Washing machine 1: ";
                                    if(s1->checkwashingmachinestatus("WM1")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 2)  Washing machine 2: ";
                                    if(s1->checkwashingmachinestatus("WM2")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 3)  Washing machine 3: ";
                                    if(s1->checkwashingmachinestatus("WM3")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 4)  Washing machine 4: ";
                                    if(s1->checkwashingmachinestatus("WM4")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 5)  Washing machine 5: ";
                                    if(s1->checkwashingmachinestatus("WM5")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n\n";
                                    
                                    
                                    
                                    cout<<" Drying machines"<<endl;
                                    cout<<" 6)  Drying Machine 1: ";
                                    if(s1->checkdryingmachinestatus("DM1")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 7)  Drying Machine 2: ";
                                    if(s1->checkdryingmachinestatus("DM2")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 8)  Drying Machine 3: ";
                                    if(s1->checkdryingmachinestatus("DM3")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 9)  Drying Machine 4: ";
                                    if(s1->checkdryingmachinestatus("DM4")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 10) Drying Machine 5: ";
                                    if(s1->checkdryingmachinestatus("DM5")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    
                                    cout<<endl;
                                    cout<<" Please enter 1-5 for a washing machine, 6-10 for a dryer\n";
                                    int num=NULL;
                                    cin>>num;
                                    while(!cin)
                                    {
                                        
                                        cout << "That was no integer! Please enter an integer:\n ";
                                        cin.clear();
                                        cin.ignore();
                                        cin >> num;
                                    }
                                    while (num<=0||num>10)
                                    {
                                        cout<<" Please enter 1-5 for a washing machine, 6-10 for a dryer\n";
                                        cin.clear();
                                        cin.ignore();
                                        cin >> num;
                                    }
                                    
                                    if (num==1&& s1->checkwashingmachinestatus("WM1")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM1",mode);
                                                
                                            }
                                            else
                                                
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==1&&s1->checkwashingmachinestatus("WM1")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    
                                    if (num==2&& s1->checkwashingmachinestatus("WM2")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM2",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==2&&s1->checkwashingmachinestatus("WM2")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==3&& s1->checkwashingmachinestatus("WM3")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM3",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==3&&s1->checkwashingmachinestatus("WM3")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==4&& s1->checkwashingmachinestatus("WM4")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM4",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==4&&s1->checkwashingmachinestatus("WM4")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==5&& s1->checkwashingmachinestatus("WM5")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM5",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==5&&s1->checkwashingmachinestatus("WM5")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==6&& s1->checkdryingmachinestatus("DM1")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changedryingmachinestatus("DM1",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==6&&s1->checkdryingmachinestatus("DM1")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==7&& s1->checkdryingmachinestatus("DM2")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changedryingmachinestatus("DM2",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==7&&s1->checkdryingmachinestatus("DM2")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==8&& s1->checkdryingmachinestatus("DM3")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changedryingmachinestatus("DM3",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==8&&s1->checkdryingmachinestatus("DM3")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==9&& s1->checkdryingmachinestatus("DM4")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=false;
                                                s1->changedryingmachinestatus("DM4",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==9&&s1->checkdryingmachinestatus("DM4")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==10&& s1->checkdryingmachinestatus("DM5")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changedryingmachinestatus("DM5",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==10&&s1->checkdryingmachinestatus("DM5")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if(num==0)
                                    {
                                        cout<<"invalid input\n";
                                    }
                                    
                                    
                                }
                            }
                            
                            else
                            {
                                flag=false;
                                cout<<" Invalid input! Please try again\n";
                            }
                        }
                        
                    }
                    else
                    { flag2=false;
                        cout<<" Invalid entry! Please try again"<<endl;
                    }
                    
                    
                }
                while(flag2==false);
            }
        }
        
        
        else if (choice==2)
        {
            cout<<" Please Login now ";
            cout<<" Enter NetID\n";
            cin>>NetID;
            cout<<" Enter password\n";
            cin>>Password;
            if(s1->Login( NetID,  Password)==true)
            {
                bool flag2=true;
                int building_num2;
                do
                {
                    flag2=true;
                    cout<<" 0)    Go back to previous page"<<endl;
                    cout<<" 1)  A1"<<endl;
                    //   cout<<"2. A2"<<endl;
                    //  cout<<"3. A5"<<endl;
                    //  cout<<"4. A6"<<endl;
                    
                    
                    int building_num=0;
                    cin>>building_num;
                    while(!cin)
                    {
                        cout << "That was no integer! Please enter an integer:\n ";
                        cin.clear();
                        cin.ignore();
                        cin >> building_num;
                    }
                    //int building_num2;
                    if ( building_num==0)
                        
                    {
                        break;
                    }
                    else if ( building_num==1)
                        
                    {
                        bool flag=false;
                        while(flag==false)
                        {
                            
                            cout<<" 1)   A1A"<<endl;
                            // cout<<"2.A1B"<<endl;
                            //  cout<<"3.A1C"<<endl;
                            
                            cin>>building_num2;
                            while(!cin)
                            {
                                cout << "That was no integer! Please enter an integer:\n ";
                                cin.clear();
                                cin.ignore();
                                cin >> building_num2;
                            }
                            if (building_num2==1)
                            {
                                flag=true;
                                bool flag3=false;
                                while(flag3==false)
                                {
                                    
                                    cout<<" Washing machine program settings:\n";
                                    cout<<" Program 1: 10 minutes\n";
                                    cout<<" Program 2: 20 minutes\n";
                                    cout<<" Program 1: 25 minutes\n";
                                    cout<<" Program 1: 30 minutes\n";
                                    cout<<" Program 1: 50 minutes\n";
                                    cout<<endl;
                                    cout<<" Drying machine program settings:\n";
                                    cout<<" Program 1: 5 minutes\n";
                                    cout<<" Program 2: 10 minutes\n";
                                    cout<<" Program 1: 15 minutes\n";
                                    cout<<" Program 1: 20 minutes\n";
                                    cout<<" Program 1: 30 minutes\n";
                                    cout<<endl;
                                    
                                    cout<<" Washing machines"<<endl;
                                    cout<<" 1)  Washing machine 1: ";
                                    if(s1->checkwashingmachinestatus("WM1")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 2)  Washing machine 2: ";
                                    if(s1->checkwashingmachinestatus("WM2")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 3)  Washing machine 3: ";
                                    if(s1->checkwashingmachinestatus("WM3")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 4)  Washing machine 4: ";
                                    if(s1->checkwashingmachinestatus("WM4")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 5)  Washing machine 5: ";
                                    if(s1->checkwashingmachinestatus("WM5")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n\n";
                                    
                                    
                                    
                                    cout<<" Drying machines"<<endl;
                                    cout<<" 6)  Drying Machine 1: ";
                                    if(s1->checkdryingmachinestatus("DM1")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 7)  Drying Machine 2: ";
                                    if(s1->checkdryingmachinestatus("DM2")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 8)  Drying Machine 3: ";
                                    if(s1->checkdryingmachinestatus("DM3")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 9)  Drying Machine 4: ";
                                    if(s1->checkdryingmachinestatus("DM4")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    cout<<" 10) Drying Machine 5: ";
                                    if(s1->checkdryingmachinestatus("DM5")==0)
                                        cout<<" Available\n";
                                    else
                                        cout<<" Occupied\n";
                                    
                                    cout<<endl;
                                    cout<<" Please enter 1-5 for a washing machine, 6-10 for a dryer\n";
                                    int num=NULL;
                                    cin>>num;
                                    while(!cin)
                                    {
                                        
                                        cout << "That was no integer! Please enter an integer:\n ";
                                        cin.clear();
                                        cin.ignore();
                                        cin >> num;
                                    }
                                    while (num<=0||num>10)
                                    {
                                        cout<<" Please enter 1-5 for a washing machine, 6-10 for a dryer\n";
                                        cin.clear();
                                        cin.ignore();
                                        cin >> num;
                                    }
                                    
                                    if (num==1&& s1->checkwashingmachinestatus("WM1")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM1",mode);
                                                
                                            }
                                            else
                                                
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==1&&s1->checkwashingmachinestatus("WM1")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    
                                    if (num==2&& s1->checkwashingmachinestatus("WM2")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM2",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==2&&s1->checkwashingmachinestatus("WM2")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==3&& s1->checkwashingmachinestatus("WM3")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM3",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==3&&s1->checkwashingmachinestatus("WM3")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==4&& s1->checkwashingmachinestatus("WM4")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM4",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==4&&s1->checkwashingmachinestatus("WM4")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==5&& s1->checkwashingmachinestatus("WM5")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changewashingmachinestatus("WM5",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==5&&s1->checkwashingmachinestatus("WM5")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==6&& s1->checkdryingmachinestatus("DM1")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changedryingmachinestatus("DM1",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==6&&s1->checkdryingmachinestatus("DM1")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==7&& s1->checkdryingmachinestatus("DM2")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changedryingmachinestatus("DM2",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==7&&s1->checkdryingmachinestatus("DM2")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==8&& s1->checkdryingmachinestatus("DM3")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changedryingmachinestatus("DM3",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==8&&s1->checkdryingmachinestatus("DM3")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==9&& s1->checkdryingmachinestatus("DM4")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=false;
                                                s1->changedryingmachinestatus("DM4",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==9&&s1->checkdryingmachinestatus("DM4")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if (num==10&& s1->checkdryingmachinestatus("DM5")==false)
                                    {
                                        flag2=true;
                                        bool chk=false;
                                        while (chk==false)
                                        {
                                            cout<<" Enter Mode Number (1-5) \n";
                                            int mode=NULL;
                                            cin>>mode;
                                            while(!cin)
                                            {
                                                
                                                cout << "That was no integer! Please enter an integer:\n ";
                                                cin.clear();
                                                cin.ignore();
                                                cin >> mode;
                                            }
                                            if (mode>0&&mode<6)
                                            {
                                                chk=true;
                                                flag3=true;
                                                s1->changedryingmachinestatus("DM5",mode);
                                            }
                                            else
                                                cout<<" Invalid input , please try again"<<endl;
                                        }
                                    }
                                    else if(num==10&&s1->checkdryingmachinestatus("DM5")==true)
                                    {cout<<" Machine in use!, please make another selection \n ";
                                        continue;
                                    }
                                    if(num==0)
                                    {
                                        cout<<"invalid input\n";
                                    }
                                    
                                    
                                }
                            }
                            else if (building_num2==0)
                                break;
                            else
                            {
                                flag=false;
                                cout<<" Invalid input! Please try again\n";
                            }
                        }
                    }
                    else
                    { flag2=false;
                        cout<<" Invalid entry! Please try again"<<endl;
                    }
                    
                    
                }
                while(flag2==false);
            }
        }
        
        
        
        
        
        
        else if (choice==3)
        {
            delete s1;
            exit(0);
        }
        
        else
        {
            
            cout<<" Invalid input!, Please try again"<<endl;
            continue;
        }
        
    }
    
    while(choice!=3);
}





