#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<Windows.h>
#include<sstream>
using namespace std;
string path4="C:/PHONEBOOK/selection.csv",number="99839879378";
int PresenceInSelect(string no)
{
    ifstream file0(path4);
    int x=0;
    string junk,sr;
    getline(file0,junk,'\n');
    while(!file0.eof())
    {
        string number,junk;
        getline(file0,sr,',');
        getline(file0,number,',');
        getline(file0,junk,'\n');
        if(no==number)
        x=1;
        break;
    }
    file0.close();
    return x;
}
int main()
{
    cout<<PresenceInSelect(number);
    //string p="finaledit.cpp",q="FINALEDIT.cpp";
    //int xb=rename("C:/VISUAL STUDIO/CPPfiles/projects/Phonebook/accounts.txt","C:/PHONEBOOK/accounts.txt");
    /*if(system("cd cheatcode")==1)
    cout<<"c++";*/
    //int xb=rename(q.c_str(),p.c_str());
}