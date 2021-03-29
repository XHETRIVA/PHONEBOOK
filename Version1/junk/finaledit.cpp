#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<Windows.h>
#include<sstream>
using namespace std;
void Colour(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
string Clr(int c)
{
    string x="";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
    return x;
}
void settings()
{
    system("cls");
    cout<<Clr(159)<<"\n\n======================================================== "<<Clr(154)<<"SETTINGS "<<Clr(159)<<"========================================================";
    cout<<Clr(7)<<"\n                                                                                                                        "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n";
    cout<<Clr(143)<<"PRESS:"<<Clr(7)<<"                                                                                                                  "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n                                                                                                                        "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n1: Change PASSWORD                                                                                                      "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n2: Change USER ID                                                                                                       "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n3: Master delete(delete all data)                                                                                       "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n4: Delete Phonebook account                                                                                             "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n5: Logout                                                                                                               "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\nOR TYPE:                                                                                                                "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n\"exit\": To Return To Main Menu.                                                                                         "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n                                                                                                                        "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n"<<Clr(159)<<"==========================================================================================================================\n";
    cout<<Clr(78)<<"ENTER HERE:"<<Clr(7)<<"  ";
}

void Option()
{
    cout<<Clr(159)<<"\n\n======================================================= "<<Clr(144)<<"MAIN MENU "<<Clr(159)<<"========================================================";
    cout<<Clr(7)<<"\n                                                                                                                        "<<Clr(159)<<"||"<<Clr(7)<<"\n";
    cout<<Clr(143)<<"PRESS:"<<Clr(7)<<"                                                                                                                  "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n                                                                                                                        "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n1: All Contacts (Displays all contacts)                                                                                 "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n2: Add A New Contact                                                                                                    "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n3: Delete A Contact                                                                                                     "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n4: Edit A Contact                                                                                                       "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n5: Add A Contact To Quick Access (The contacts you add here will appear first without having you to search for it)      "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n6: Remove From Quick Access                                                                                             "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n7: Dialpad(Search a contact with name, number, address, email etc.)                                                     "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n8: Select Multiple Contacts(To perform one operation on multiple contacts simultaneously)                               "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n9: Settings                                                                                                             "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n                                                                                                                        "<<Clr(159)<<"||";
    cout<<Clr(7)<<"\n"<<Clr(159)<<"==========================================================================================================================\n";
    cout<<Clr(78)<<"ENTER HERE:"<<Clr(7)<<"  ";
}
void cheatcode()
{
    cheat:
    system("cls");
    cout<<"ENTER THE DRIVE IN WHICH YOU WANT TO STORE\nOR TYPE\n\"default\": TO CONTINUE WITH DEFAUT WINDOWS DRIVE(C)";
    string drive;
    getline(cin,drive);
    string d=drive;
    drive="cd \""+drive+":/\"";
    if(system(drive.c_str())==0)
    cout<<"DRIVE EXISTS!";
    else
    goto cheat;
}
int main()
{
    //string c="cd \"E:/\"";
    //cout<<system(c.c_str());
    cout<<system("cd HELLO");
}