#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<Windows.h>
#include<sstream>
using namespace std;
void colour(int c);
void correction(string filename);
int checkunino(string num,string &pname,string filename);
void checkno(string num,int &flag);
string inttostr(int x);
void showdata(string filename);
string stoupper(string s);
void searchn(int &h,string sname,int q);
void showqa();
void qa();
void edit();
int strtoint(string a);
void addcontacts();
void calc();
void sort();
string returnnumber(string sr);
int noline=0,nodata=0,alphaN=0;
struct contacts
{
    string name,number,email,ad,dob,doa,notes,rel,label,qa,temp;
};
string path1="C:/PHONEBOOK/phonebook.csv",path2="C:/PHONEBOOK/junk.csv",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv",path6="C:/PHONEBOOK/accounts.txt",path7="C:/PHONEBOOK/accountchecker.txt";
int main()
{
    showdata(path1);
}
void showdata(string filename) //displays the data in a file
{
    colour(14);
    ifstream csvi(filename.c_str());
    string junk;
    getline(csvi,junk,'\n');
    while(!csvi.eof())
    {
        string name, number, email, address, dob, doa, notes, relation,label,qa;
        getline(csvi,number,',');
        getline(csvi,name,',');
        getline(csvi,email,',');
        getline(csvi,address,',');
        getline(csvi,dob,',');
        getline(csvi,doa,',');
        getline(csvi,notes,',');
        getline(csvi,relation,',');
        getline(csvi,label,',');
        getline(csvi,qa,'\n');
        cout<<"\n\nNAME: "<<left<<name<<"\nPHONE NUMBER: "<<number<<"\nDATE OF BIRTH: ";
        if(dob=="")
        cout<<" - ";
        cout<<dob<<"\nDATE OF ANNIVERSARY: ";
        if(doa=="")
        cout<<" - ";
        cout<<doa<<"\nRELATION: ";
        if(relation=="")
        cout<<" - ";
        cout<<relation<<"\nLABEL: ";
        if(label=="")
        cout<<" - ";
        cout<<label<<"\nNOTES: ";
        if(notes=="")
        cout<<" - ";
        cout<<notes<<"\nEMAIL: ";
        if(email=="")
        cout<<" - ";
        cout<<email<<"\nADDRESS: ";
        if(address=="")
        cout<<" - ";
        cout<<address<<"\n";
    }
    csvi.close();
    colour(7);
}
void colour(int c) //add colour
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}