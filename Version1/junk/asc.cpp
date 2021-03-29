#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>
#include<sstream>
using namespace std;
void correction(string filename);
int checkunino(string num,string &pname,string filename);
void checkno(string num,int &flag);
void showdata(string filename);
int strtoint(string a);
void calc();
void sort();
int noline=0,nodata=0,alphaN=0;
const int size=nodata;
struct contacts
{
    string name,number,junk;
};
string path1="C:/PHONEBOOK/phonebook.csv",path2="C:/PHONEBOOK/junk.csv",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv";
int main()
{
    correction(path2);
    correction(path1);
    calc();
    ofstream file(path2.c_str(),ios::app);
    string name,no,email="",ad="",dob="",doa="",notes="",rel="",label="",qa="0";
    if(noline>0&&alphaN==0)
    file<<"PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
    reno:
    int l=1,flag=0;
    cout<<"Enter the phone number: ";
    getline(cin,no);
    checkno(no,flag);
    if(flag==1)
    {
        cout<<"ERROR:: Wrong format for phone number!\n";
        goto reno;
    }
    int c=checkunino(no,name,path2);
    if(c==0)
    {
        cout<<"ERROR:Two person cannot have same phone number.\nThe phone number "<<no<<" already belongs to "<<name<<"\nPRESS:\n1:To re-enter phone number\n2:To skip adding(default)\n\nYOUR CHOICE: ";
        cin>>l;
        cin.ignore(1,'\n');
        if(l==1)
        goto reno;
    }
    if(l==1)
    {
        cout<<"Do you want to enter the name?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        string a;
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the name: ";
            getline(cin,name);
        }
        else
        {
            name=no;
        }
        cout<<"\nDo you want to enter the e-mail?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the e-mail: ";
            getline(cin,email);
        }
        cout<<"\nDo you want to enter the address?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the address: ";
            getline(cin,ad);
        }
        cout<<"\nDo you want to enter the date of birth?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the date of birth: ";
            getline(cin,dob);
        }
        cout<<"\nDo you want to enter the date of anniversary?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the date of anniversary: ";
            getline(cin,dob);
        }
        cout<<"\nDo you want to enter any notes?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the notes: ";
            getline(cin,notes);
        }
        cout<<"\nDo you want to enter the relation?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the relation: ";
            getline(cin,rel);
        }
        cout<<"\nDo you want to enter any label?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the label: ";
            getline(cin,label);
        }
        file<<'\n'<<no<<","<<name<<","<<email<<","<<ad<<","<<dob<<","<<doa<<','<<notes<<","<<rel<<","<<label<<","<<qa;
    }
    file.close();
    calc();
    showdata(path2);
    sort();
    showdata(path1);
}
void showdata(string filename)
{
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
    csvi.close();
}
int checkunino(string num,string &pname,string filename)
{
    int flag=1;
    ifstream check;
    check.open(filename.c_str());
    while(!check.eof())
    {
        string number,name,junk;
        getline(check,number,',');
        getline(check,name,',');
        getline(check,junk,'\n');
        if(number==num)
        {
            flag=0;
            pname=name;
            break;
        }
        else
        {
            flag=1;
            pname="";
        }
    }
    check.close();
    return flag;
}
void correction(string filename)
{
    ofstream checked(filename,ios::app);
    checked.close();
    ifstream correct;
    correct.open(filename.c_str());
    string corrected="",junk="";
    getline(correct,junk,'\n');
    corrected=corrected+junk;
    while(!correct.eof())
    {
        getline(correct,junk,'\n');
        if(junk!="")
        corrected=corrected+'\n'+junk;
    }
    correct.close();
    ofstream crcting;
    crcting.open(filename.c_str());
    crcting<<corrected;
    crcting.close();
}
void checkno(string num,int &flag)
{
    char x;
    for(int i=0;num[i]!='\0';i++)
    {
        x=num[0];
        if(x=='+'||isdigit(num[i]));
        else
        {
            flag=1;
            break;
        }
    }
}
int strtoint(string a)
{
    int x=0;
    stringstream as(a);
    as>>x;
    return x;
}
void sort()
{
    contacts temp,obj[1000];
    int i=0,j;
    ifstream please(path2);
    string junk;
    getline(please,junk,'\n');
    while(!please.eof())
    {
            getline(please,obj[i].number,',');
            getline(please,obj[i].name,',');
            getline(please,obj[i].junk,'\n');
            cout<<"\n"<<obj[i].number<<" "<<obj[i].name<<","<<obj[i].junk;
            ++i;
    }
    for(i=0;i<nodata-1;i++)
    {
        for(j=0;j<nodata-i-1;j++)
        if(obj[j].name>obj[j+1].name)
        {
            temp.number=obj[j].number;
            temp.name=obj[j].name;
            temp.junk=obj[j].junk;
            obj[j].number=obj[j+1].number;
            obj[j].name=obj[j+1].name;
            obj[j].junk=obj[j+1].junk;
            obj[j+1].number=temp.number;
            obj[j+1].name=temp.name;
            obj[j+1].junk=temp.junk;
        }
    }
    for(i=0;i<nodata;i++)
    {
        cout<<obj[i].number<<" "<<obj[i].name<<" "<<obj[i].junk<<"\n";
    }
    please.close();
    ofstream fil(path1);
    fil<<junk;
    for(i=0;i<nodata;i++)
    {
        fil<<'\n'<<obj[i].number<<','<<obj[i].name<<','<<obj[i].junk;
    }
    fil.close();
}
void calc()
{
    string cd,junk;
    ifstream csvr(path2.c_str());
    while(!csvr.eof())
    {
        getline(csvr,cd,',');
        getline(csvr,junk,'\n');
        if(isdigit(cd[0])||cd[0]=='+')
        nodata++;
        if(cd[0]=='P')
        alphaN=1;
        noline++;
    }
    csvr.close();
}