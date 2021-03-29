#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
void correction(string filename);
int checkunino(string num,string &pname,string filename);
void checkno(string num,int &flag);
void showdata(string filename);
string stoupper(string s);
void searchn(int &h,string sname,int q);
int strtoint(string a);
void calc();
void sort();
int noline=0,nodata=0,alphaN=0;
const int size=nodata;
struct contacts
{
    string name,number,email,ad,dob,doa,notes,rel,label,qa;
};
string path1="C:/PHONEBOOK/phonebook.csv",path2="C:/PHONEBOOK/junk.csv",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv";
int main()
{
    int x=1;
    searchn(x,"NULL",0);
}
int comparestring(string a,string b)
{
    int x=a.size(),y=b.size(),flag=0;
    if(x<=y)
    {
        for(int j=0;a[j]!='\0';j++)
        {
            if(b[j]==a[j])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
    }
    else 
    flag=0;
    return flag;
}
void searchn(int &h,string sname,int q)
{
    string junk;
    s:
    if(sname=="NULL")
    {
        cout<<"Enter the name/number/email/address/dob/doa/relation to be searched:\t";
        if(q==0)
        cout<<"\nor type \"exit\" to exit search\n\nYOUR CHOICE:\t";
        getline(cin,sname);
    }
    sname=stoupper(sname);
    int x,y,f=0;
    x=sname.size();
    if(sname!="EXIT")
    {
        ifstream search;
        ofstream searchr;
        search.open(path1);
        searchr.open(path3);
        getline(search,junk,'\n');
        searchr<<"SR. NO.,PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
        while(!search.eof())
        {
            string name, number, email, address, dob, doa, notes, relation,label,qa,temp,temp1,temp2,temp3,temp4,temp5,temp6;
            getline(search,number,',');
            getline(search,name,',');
            getline(search,email,',');
            getline(search,address,',');
            getline(search,dob,',');
            getline(search,doa,',');
            getline(search,notes,',');
            getline(search,relation,',');
            getline(search,label,',');
            getline(search,qa,'\n');
            temp1=stoupper(name);
            temp2=stoupper(email);
            temp3=stoupper(address);
            temp4=stoupper(relation);
            temp5=stoupper(doa);
            temp6=stoupper(dob);
            int flag=0;
            if(comparestring(sname,temp1)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp2)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp3)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp4)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp5)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp6)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,number)==1)
            {
                flag=1;
                goto idharaa;
            }
            idharaa:
            if(flag==1)
            {
                searchr<<'\n'<<h<<","<<number<<","<<name<<","<<email<<","<<address<<","<<dob<<","<<doa<<','<<notes<<","<<relation<<","<<label<<","<<qa;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14 | FOREGROUND_INTENSITY);
        	    cout<<"\n\n"<<h<<". NAME: "<<left<<name<<"\nPHONE NUMBER: "<<number<<"\nDATE OF BIRTH: ";
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
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                h++;
                f=1;
            }    
        }
        h=1;
        if(f==0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 | FOREGROUND_INTENSITY);
            cout<<"NO RESULTS FOUND!\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            h=1;
            if(q==1||q==2)
            {
                int k;
                cout<<"Do you want to search again to ";
                if(q==1)
                cout<<"edit?";
                else if(q==2)
                cout<<"delete?";
                else if(q==3)
                cout<<"add to quick access?";
                cout<<"\nPRESS:\n1:YES\n2:NO(default)\nYOUR CHOICE: ";
                cin>>k;
                if(k==1)
                {
                    search.close();
                    searchr.close();
                    sname="NULL";
                    goto s;
                }
                else
                {
                    search.close();
                    searchr.close();
                    h=-187928;
                    q=0;
                    sname="EXIT";
                    goto s;
                }
            }
        }
        search.close();
        searchr.close();
        if(q==0)
        {
            sname="NULL";
            goto s;
        }
    }
    else
    cout<<"\nEXITING SEARCH\n";
}
string stoupper(string s)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            s[i]-=32;
        }
        i++;
    }
    return s;
}
void showdata(string filename)
{
    ifstream search(filename.c_str());
    string junk;
    getline(search,junk,'\n');
    while(!search.eof())
    {
        string name, number, email, address, dob, doa, notes, relation,label,qa;
        getline(search,number,',');
        getline(search,name,',');
        getline(search,email,',');
        getline(search,address,',');
        getline(search,dob,',');
        getline(search,doa,',');
        getline(search,notes,',');
        getline(search,relation,',');
        getline(search,label,',');
        getline(search,qa,'\n');
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14 | FOREGROUND_INTENSITY);
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    }
    search.close();
}